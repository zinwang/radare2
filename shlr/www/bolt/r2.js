var r2={},backward=!1,next_curoff=0,next_lastoff=0,prev_curoff=0,prev_lastoff=0,hascmd=!1,r2_root=self.location.pathname.split("/").slice(0,-2).join("/");function isFirefoxOS(){return"undefined"!=typeof locationbar&&!locationbar.visible&&-1<navigator.userAgent.indexOf("Firefox")&&-1<navigator.userAgent.indexOf("Mobile")&&"mozApps"in navigator}function asyncLoop(n,r,e){var t=0,o=!1,i={next:function(){o||(t<n?(t++,r(i)):(o=!0,e()))},iteration:function(){return t-1},break:function(){o=!0,e()}};return i.next(),i}r2.asyncMode="sync",r2.err=null,isFirefoxOS()?r2.root="http://cloud.radare.org":r2.root=r2_root,"undefined"!=typeof module&&(module.exports=function(n){return hascmd="function"==typeof n?n:n.cmd,r2}),r2.project_name="",r2.plugin=function(){console.error("r2.plugin is not available in this environment")};try{r2plugin&&(r2.plugin=r2plugin)}catch(n){}function dump(n){var r,e="";for(r in n)e+=r+"\n";alert(e)}function objtostr(n){var r,e="";for(r in n)e+=r+": "+n[r]+",\n";return e}r2.root=r2_root,r2.analAll=function(){r2.cmd("aa",function(){})},r2.analOp=function(n,e){r2.cmd("aoj 1 @ "+n,function(r){try{e(JSON.parse(r)[0])}catch(n){console.error(n),e(r)}})},r2.varMap=[];var ajax_in_process=!(r2.argMap=[]);function Ajax(n,r,e,t,o){if("undefined"==typeof XMLHttpRequest)return!1;if("fake"==r2.asyncMode)return t&&t("{}"),!0;if("sasync"==r2.asyncMode&&(console.log("async waiting"),ajax_in_process))return setTimeout(function(){Ajax(n,r,e,t)},100),!1;var i=void 0;if(!(i=isFirefoxOS()?new XMLHttpRequest({mozSystem:!0}):new XMLHttpRequest))return!1;ajax_in_process=!0,"sync"==r2.asyncMode?i.open(n,r,!1):i.open(n,r,!0),i.setRequestHeader("Accept","text/plain"),i.setRequestHeader("Content-Type","application/x-ww-form-urlencoded; charset=UTF-8"),i.onreadystatechange=function(){ajax_in_process=!1,200==i.status?i.readyState<4||(t?t(i.responseText):console.error("missing ajax callback")):((o||r2.err)("connection refused"),console.error("ajax "+i.status))};try{i.send(e)}catch(n){"NetworkError"==n.name&&(o||r2.err)("connection error")}return!0}function _internal_cmd(n,r,e){if(hascmd="undefined"!=typeof r2cmd?r2cmd:hascmd)return"undefined"!=typeof r2plugin?r(r2cmd(n)):hascmd(n,r);Ajax("GET",r2.root+"/cmd/"+encodeURI(n),"",function(n){r&&r(n)},e)}r2.assemble=function(n,r,e){r2.cmd('"pa '+r+'"'+(n?"@"+n:""),e)},r2.disassemble=function(n,r,e){r2.cmd("pi @b:"+r+(n?"@"+n:""),e)},r2.get_hexdump=function(n,r,e){r2.cmd("px "+r+"@"+n,e)},r2.get_disasm=function(n,r,e){r2.cmd("pD "+r+"@"+n,e)},r2.get_disasm_before=function(n,r,e){var t=[];r2.cmd("pdj -"+r+"@"+n+"|",function(n){t=JSON.parse(n)}),e(t)},r2.get_disasm_after=function(n,r,e){var t=[];r2.cmd("pdj "+r+"@"+n+"|",function(n){t=JSON.parse(n)}),e(t)},r2.get_disasm_before_after=function(n,r,e,t){var o=[],i=[];r2.cmd("pdj "+r+" @"+n+"|",function(n){o=JSON.parse(n)}),r2.cmd("pdj "+e+"@"+n+"|",function(n){i=JSON.parse(n)}),t(o.concat(i))},r2.Config=function(n,r,e){return"function"!=typeof r&&r?r2.cmd("e "+n+"="+r,e):r2.cmd("e "+n+"|",e||r),r2},r2.sections={},r2.load_mmap=function(){r2.cmdj("iSj|",function(n){null!=n&&(r2.sections=n)})},r2.get_address_type=function(n){var r,e=parseInt(n,16);for(r in r2.sections)if(e>=r2.sections[r].addr&&e<r2.sections[r].addr+r2.sections[r].size)return-1<r2.sections[r].flags.indexOf("x")?"instruction":"memory";return""},r2.settings={},r2.load_settings=function(){r2.cmd("e asm.arch",function(n){r2.settings["asm.arch"]=n.trim()}),r2.cmd("e asm.bits",function(n){r2.settings["asm.bits"]=n.trim()}),r2.cmd("e asm.bytes",function(n){r2.settings["asm.bytes"]=toBoolean(n.trim())}),r2.cmd("e asm.flags",function(n){r2.settings["asm.flags"]=toBoolean(n.trim())}),r2.cmd("e asm.offset",function(n){r2.settings["asm.offset"]=toBoolean(n.trim())}),r2.cmd("e asm.lines",function(n){r2.settings["asm.lines"]=toBoolean(n.trim())}),r2.cmd("e asm.xrefs",function(n){r2.settings["asm.xrefs"]=toBoolean(n.trim())}),r2.cmd("e asm.cmtright",function(n){r2.settings["asm.cmtright"]=toBoolean(n.trim())}),r2.cmd("e asm.pseudo",function(n){r2.settings["asm.pseudo"]=toBoolean(n.trim())})},r2.flags={},r2.update_flags=function(){r2.cmd("fs *;fj|",function(n){var r=JSON.parse(n);if(null!=r)for(var e in r2.flags={},r){var t,o="0x"+r[e].offset.toString(16);(o=address_canonicalize(o))in r2.flags?((t=r2.flags[o])[t.length]={name:r[e].name,size:r[e].size},r2.flags[o]=t):r2.flags[o]=[{name:r[e].name,size:r[e].size}]}})},r2.get_flag_address=function(n){for(var r in r2.flags)for(var e in r2.flags[r])if(n==r2.flags[r][e].name)return r;return null},r2.get_flag_names=function(n){var r,e=[];for(r in r2.flags[n])e[e.length]=r2.flags[n][r].name;return e},r2.set_flag_space=function(n,r){r2.cmd("fs "+n,r)},r2.get_flags=function(r){r2.cmd("fj|",function(n){r(n?JSON.parse(n):[])})},r2.get_opcodes=function(n,r,e){r2.cmd("pdj @"+n+"!"+r+"|",function(n){e(JSON.parse(n))})},r2.get_bytes=function(n,r,e){r2.cmd("pcj @"+n+"!"+r+"|",function(n){e(JSON.parse(n))})},r2.asm_config={},r2.store_asm_config=function(){config={},r2.cmd("e",function(n){for(var r in conf=n.split("\n"))3==(r=conf[r].split(" ")).length&&0==r[0].trim().indexOf("asm.")&&(config[r[0].trim()]=r[2].trim());r2.asm_config=config})},r2.restore_asm_config=function(){for(var n in cmd="",r2.asm_config)cmd+="e "+n+"="+r2.asm_config[n]+";";r2.cmd(cmd,function(){})},r2.get_info=function(r){r2.cmd("ij|",function(n){r(JSON.parse(n))})},r2.bin_relocs=function(r){r2.cmd("irj|",function(n){r(JSON.parse(n))})},r2.bin_imports=function(r){r2.cmd("iij|",function(n){r(JSON.parse(n))})},r2.bin_symbols=function(r){r2.cmd("isj|",function(n){r(JSON.parse(n))})},r2.bin_sections=function(r){r2.cmd("iSj|",function(n){r(JSON.parse(n))})},r2.cmds=function(r,e){var t;0!=r.length&&(t=r[0],r=r.splice(1),r2.cmd(t,function n(){null!=t&&0!=r.length&&(t=r[0],r=r.splice(1),r2.cmd(t,n),e&&e())}))},r2.cmd=function(n,r,e){var t,o;Array.isArray(n)?(t=[],o=0,asyncLoop(n.length,function(r){_internal_cmd(n[o],function(n){o=r.iteration(),t[o]=n.replace(/\n$/,""),o++,r.next()},e)},function(){r(t)})):_internal_cmd(n,r,e)},r2.cmdj=function(n,r){r2.cmd(n,function(n){try{r(JSON.parse(n))}catch(n){r(null)}})},r2.alive=function(r){r2.cmd("b",function(n){n&&n.length(),r&&r(n)})},r2.getTextLogger=function(o){return(o="object"!=typeof o?{}:o).last=0,o.events={},o.interval=null,r2.cmd("Tl",function(n){o.last=+n}),o.load=function(r){r2.cmd('"Tj '+(o.last+1)+'"',function(n){r&&r(JSON.parse(n))})},o.clear=function(n){r2.cmd("T-",n)},o.send=function(n,r){r2.cmd('"T '+n+'"',r)},o.refresh=function(t){o.load(function(n){for(var r=0;r<n.length;r++){var e=n[r];o.events.message({id:e[0],text:e[1]}),e[0]>o.last&&(o.last=e[0])}t&&t()})},o.autorefresh=function(r){r?o.interval=setTimeout(function n(){return o.refresh(function(){}),"Logs"===r2ui.selected_panel?setTimeout(n,1e3*r):console.log("Not in logs :("),!0},1e3*r):o.interval&&o.interval.stop()},o.on=function(n,r){return o.events[n]=r,o},o},r2.filter_asm=function(n,r){var e=backward?prev_curoff:next_curoff,t=backward?prev_lastoff:next_lastoff,o=n.split(/\n/g);r2.cmd("s",function(n){e=n});for(var i=o.length-1;0<i;i--){var a=o[i].match(/0x([a-fA-F0-9]+)/);if(a&&0<a.length){t=a[0].replace(/:/g,"");break}}if("afl"==r){for(var c="",i=0;i<o.length;i++)c+=(s=o[i].replace(/\ +/g," ").split(/ /g))[0]+"  "+s[3]+"\n";n=c}else if("f"==r[0]){if("s"==r[1]){for(c="",i=0;i<o.length;i++){var s,f="*"==(s=o[i].replace(/\ +/g," ").split(/ /g))[1]?"*":" ",u=s[2]||s[1];u&&(c+=s[0]+" "+f+" <a href=\"javascript:runcmd('fs "+u+"')\">"+u+"</a>\n")}n=c}}else if("i"==r[0]&&r[1]){for(c="",i=0;i<o.length;i++){for(var l=o[i].split(/ /g),m="",d="",p=0;p<l.length;p++){var g=l[p].split(/=/);"addr"==g[0]&&(d=g[1]),"name"==g[0]&&(m=g[1]),"string"==g[0]&&(m=g[1])}c+=d+"  "+m+"\n"}n=c}return n=(n="p"==r[0]&&"d"==r[1]||-1!=r.indexOf(";pd")?n.replace(/(reloc|class|method|var|sym|fcn|str|imp|loc)\.([^:<(\\\/ \|\])\->]+)/g,"<a href='javascript:r2ui.seek(\"$1.$2\")'>$1.$2</a>"):n).replace(/0x([a-zA-Z0-9]+)/g,"<a href='javascript:r2ui.seek(\"0x$1\")'>0x$1</a>"),backward?(prev_curoff=e,prev_lastoff=t):(next_curoff=e,next_lastoff=t,prev_curoff=prev_curoff||next_curoff),n};