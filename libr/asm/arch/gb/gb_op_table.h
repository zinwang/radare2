/* radare - GPL3 - 2013 condret@runas-racer.com */

#define GB_8BIT		1
#define	GB_16BIT	2
#define ARG_8		4
#define	ARG_16		8
#define GB_IO		16		/*	Most io (Joypad, Sound, Screen ...)
						TODO: auto-comment in gbdis.c --> 'ld a, [0xff00] ; JOYPAD' */


typedef struct{
	const char *name;
	const int type;
	void *op16;
} gb_opcode;


static gb_opcode cb[] = {
	{"rlc b"		,GB_16BIT,NULL},			//0xcb00
	{"rlc c"		,GB_16BIT,NULL},
	{"rlc d"		,GB_16BIT,NULL},
	{"rlc e"		,GB_16BIT,NULL},
	{"rlc h"		,GB_16BIT,NULL},
	{"rlc l"		,GB_16BIT,NULL},
	{"rlc [hl]"		,GB_16BIT,NULL},
	{"rlc a"		,GB_16BIT,NULL},

	{"rrc b"		,GB_16BIT,NULL},
	{"rrc c"		,GB_16BIT,NULL},
	{"rrc d"		,GB_16BIT,NULL},
	{"rrc e"		,GB_16BIT,NULL},
	{"rrc h"		,GB_16BIT,NULL},
	{"rrc l"		,GB_16BIT,NULL},
	{"rrc [hl]"		,GB_16BIT,NULL},
	{"rrc a"		,GB_16BIT,NULL},

	{"rl b"			,GB_16BIT,NULL},			//0xcb10
	{"rl c"			,GB_16BIT,NULL},
	{"rl d"			,GB_16BIT,NULL},
	{"rl e"			,GB_16BIT,NULL},
	{"rl h"			,GB_16BIT,NULL},
	{"rl l"			,GB_16BIT,NULL},
	{"rl [hl]"		,GB_16BIT,NULL},
	{"rl a"			,GB_16BIT,NULL},

	{"rr b"			,GB_16BIT,NULL},
	{"rr c"			,GB_16BIT,NULL},
	{"rr d"			,GB_16BIT,NULL},
	{"rr e"			,GB_16BIT,NULL},
	{"rr h"			,GB_16BIT,NULL},
	{"rr l"			,GB_16BIT,NULL},
	{"rr [hl]"		,GB_16BIT,NULL},
	{"rr a"			,GB_16BIT,NULL},

	{"sla b"		,GB_16BIT,NULL},			//0xcb20
	{"sla c"		,GB_16BIT,NULL},
	{"sla d"		,GB_16BIT,NULL},
	{"sla e"		,GB_16BIT,NULL},
	{"sla h"		,GB_16BIT,NULL},
	{"sla l"		,GB_16BIT,NULL},
	{"sla [hl]"		,GB_16BIT,NULL},
	{"sla a"		,GB_16BIT,NULL},

	{"sra b"		,GB_16BIT,NULL},
	{"sra c"		,GB_16BIT,NULL},
	{"sra d"		,GB_16BIT,NULL},
	{"sra e"		,GB_16BIT,NULL},
	{"sra h"		,GB_16BIT,NULL},
	{"sra l"		,GB_16BIT,NULL},
	{"sra [hl]"		,GB_16BIT,NULL},
	{"sra a"		,GB_16BIT,NULL},

	{"swap b"		,GB_16BIT,NULL},			//0xcb30
	{"swap c"		,GB_16BIT,NULL},
	{"swap d"		,GB_16BIT,NULL},
	{"swap e"		,GB_16BIT,NULL},
	{"swap h"		,GB_16BIT,NULL},
	{"swap l"		,GB_16BIT,NULL},
	{"swap [hl]"		,GB_16BIT,NULL},
	{"swap a"		,GB_16BIT,NULL},

	{"srl b"		,GB_16BIT,NULL},
	{"srl c"		,GB_16BIT,NULL},
	{"srl d"		,GB_16BIT,NULL},
	{"srl e"		,GB_16BIT,NULL},
	{"srl h"		,GB_16BIT,NULL},
	{"srl l"		,GB_16BIT,NULL},
	{"srl [hl]"		,GB_16BIT,NULL},
	{"srl a"		,GB_16BIT,NULL},

	{"bit 0, b"		,GB_16BIT,NULL},			//0xcb40
	{"bit 0, c"		,GB_16BIT,NULL},
	{"bit 0, d"		,GB_16BIT,NULL},
	{"bit 0, e"		,GB_16BIT,NULL},
	{"bit 0, l"		,GB_16BIT,NULL},
	{"bit 0, h"		,GB_16BIT,NULL},
	{"bit 0, [hl]"		,GB_16BIT,NULL},
	{"bit 0, a"		,GB_16BIT,NULL},
	{"bit 1, b"		,GB_16BIT,NULL},
	{"bit 1, c"		,GB_16BIT,NULL},
	{"bit 1, d"		,GB_16BIT,NULL},
	{"bit 1, e"		,GB_16BIT,NULL},
	{"bit 1, h"		,GB_16BIT,NULL},
	{"bit 1, l"		,GB_16BIT,NULL},
	{"bit 1, [hl]"		,GB_16BIT,NULL},
	{"bit 1, a"		,GB_16BIT,NULL},
	{"bit 2, b"		,GB_16BIT,NULL},			//0xcb50
	{"bit 2, c"		,GB_16BIT,NULL},
	{"bit 2, d"		,GB_16BIT,NULL},
	{"bit 2, e"		,GB_16BIT,NULL},
	{"bit 2, h"		,GB_16BIT,NULL},
	{"bit 2, l"		,GB_16BIT,NULL},
	{"bit 2, [hl]"		,GB_16BIT,NULL},
	{"bit 2, a"		,GB_16BIT,NULL},
	{"bit 3, b"		,GB_16BIT,NULL},
	{"bit 3, c"		,GB_16BIT,NULL},
	{"bit 3, d"		,GB_16BIT,NULL},
	{"bit 3, e"		,GB_16BIT,NULL},
	{"bit 3, h"		,GB_16BIT,NULL},
	{"bit 3, l"		,GB_16BIT,NULL},
	{"bit 3, [hl]"		,GB_16BIT,NULL},
	{"bit 3, a"		,GB_16BIT,NULL},
	{"bit 4, b"		,GB_16BIT,NULL},			//0xcb60
	{"bit 4, c"		,GB_16BIT,NULL},
	{"bit 4, d"		,GB_16BIT,NULL},
	{"bit 4, e"		,GB_16BIT,NULL},
	{"bit 4, h"		,GB_16BIT,NULL},
	{"bit 4, l"		,GB_16BIT,NULL},
	{"bit 4, [hl]"		,GB_16BIT,NULL},
	{"bit 4, a"		,GB_16BIT,NULL},
	{"bit 5, b"		,GB_16BIT,NULL},
	{"bit 5, c"		,GB_16BIT,NULL},
	{"bit 5, d"		,GB_16BIT,NULL},
	{"bit 5, e"		,GB_16BIT,NULL},
	{"bit 5, h"		,GB_16BIT,NULL},
	{"bit 5, l"		,GB_16BIT,NULL},
	{"bit 5, [hl]"		,GB_16BIT,NULL},
	{"bit 5, a"		,GB_16BIT,NULL},
	{"bit 6, b"		,GB_16BIT,NULL},			//0xcb70
	{"bit 6, c"		,GB_16BIT,NULL},
	{"bit 6, d"		,GB_16BIT,NULL},
	{"bit 6, e"		,GB_16BIT,NULL},
	{"bit 6, h"		,GB_16BIT,NULL},
	{"bit 6, l"		,GB_16BIT,NULL},
	{"bit 6, [hl]"		,GB_16BIT,NULL},
	{"bit 6, a"		,GB_16BIT,NULL},
	{"bit 7, b"		,GB_16BIT,NULL},
	{"bit 7, c"		,GB_16BIT,NULL},
	{"bit 7, d"		,GB_16BIT,NULL},
	{"bit 7, e"		,GB_16BIT,NULL},
	{"bit 7, h"		,GB_16BIT,NULL},
	{"bit 7, l"		,GB_16BIT,NULL},
	{"bit 7, [hl]"		,GB_16BIT,NULL},
	{"bit 7, a"		,GB_16BIT,NULL},

	{"res 0, b"		,GB_16BIT,NULL},			//0xcb80
	{"res 0, c"		,GB_16BIT,NULL},
	{"res 0, d"		,GB_16BIT,NULL},
	{"res 0, e"		,GB_16BIT,NULL},
	{"res 0, l"		,GB_16BIT,NULL},
	{"res 0, h"		,GB_16BIT,NULL},
	{"res 0, [hl]"		,GB_16BIT,NULL},
	{"res 0, a"		,GB_16BIT,NULL},
	{"res 1, b"		,GB_16BIT,NULL},
	{"res 1, c"		,GB_16BIT,NULL},
	{"res 1, d"		,GB_16BIT,NULL},
	{"res 1, e"		,GB_16BIT,NULL},
	{"res 1, h"		,GB_16BIT,NULL},
	{"res 1, l"		,GB_16BIT,NULL},
	{"res 1, [hl]"		,GB_16BIT,NULL},
	{"res 1, a"		,GB_16BIT,NULL},
	{"res 2, b"		,GB_16BIT,NULL},			//0xcb90
	{"res 2, c"		,GB_16BIT,NULL},
	{"res 2, d"		,GB_16BIT,NULL},
	{"res 2, e"		,GB_16BIT,NULL},
	{"res 2, h"		,GB_16BIT,NULL},
	{"res 2, l"		,GB_16BIT,NULL},
	{"res 2, [hl]"		,GB_16BIT,NULL},
	{"res 2, a"		,GB_16BIT,NULL},
	{"res 3, b"		,GB_16BIT,NULL},
	{"res 3, c"		,GB_16BIT,NULL},
	{"res 3, d"		,GB_16BIT,NULL},
	{"res 3, e"		,GB_16BIT,NULL},
	{"res 3, h"		,GB_16BIT,NULL},
	{"res 3, l"		,GB_16BIT,NULL},
	{"res 3, [hl]"		,GB_16BIT,NULL},
	{"res 3, a"		,GB_16BIT,NULL},
	{"res 4, b"		,GB_16BIT,NULL},			//0xcba0
	{"res 4, c"		,GB_16BIT,NULL},
	{"res 4, d"		,GB_16BIT,NULL},
	{"res 4, e"		,GB_16BIT,NULL},
	{"res 4, h"		,GB_16BIT,NULL},
	{"res 4, l"		,GB_16BIT,NULL},
	{"res 4, [hl]"		,GB_16BIT,NULL},
	{"res 4, a"		,GB_16BIT,NULL},
	{"res 5, b"		,GB_16BIT,NULL},
	{"res 5, c"		,GB_16BIT,NULL},
	{"res 5, d"		,GB_16BIT,NULL},
	{"res 5, e"		,GB_16BIT,NULL},
	{"res 5, h"		,GB_16BIT,NULL},
	{"res 5, l"		,GB_16BIT,NULL},
	{"res 5, [hl]"		,GB_16BIT,NULL},
	{"res 5, a"		,GB_16BIT,NULL},
	{"res 6, b"		,GB_16BIT,NULL},			//0xcbb0
	{"res 6, c"		,GB_16BIT,NULL},
	{"res 6, d"		,GB_16BIT,NULL},
	{"res 6, e"		,GB_16BIT,NULL},
	{"res 6, h"		,GB_16BIT,NULL},
	{"res 6, l"		,GB_16BIT,NULL},
	{"res 6, [hl]"		,GB_16BIT,NULL},
	{"res 6, a"		,GB_16BIT,NULL},
	{"res 7, b"		,GB_16BIT,NULL},
	{"res 7, c"		,GB_16BIT,NULL},
	{"res 7, d"		,GB_16BIT,NULL},
	{"res 7, e"		,GB_16BIT,NULL},
	{"res 7, h"		,GB_16BIT,NULL},
	{"res 7, l"		,GB_16BIT,NULL},
	{"res 7, [hl]"		,GB_16BIT,NULL},
	{"res 7, a"		,GB_16BIT,NULL},

	{"set 0, b"		,GB_16BIT,NULL},			//0xcbc0
	{"set 0, c"		,GB_16BIT,NULL},
	{"set 0, d"		,GB_16BIT,NULL},
	{"set 0, e"		,GB_16BIT,NULL},
	{"set 0, l"		,GB_16BIT,NULL},
	{"set 0, h"		,GB_16BIT,NULL},
	{"set 0, [hl]"		,GB_16BIT,NULL},
	{"set 0, a"		,GB_16BIT,NULL},
	{"set 1, b"		,GB_16BIT,NULL},
	{"set 1, c"		,GB_16BIT,NULL},
	{"set 1, d"		,GB_16BIT,NULL},
	{"set 1, e"		,GB_16BIT,NULL},
	{"set 1, h"		,GB_16BIT,NULL},
	{"set 1, l"		,GB_16BIT,NULL},
	{"set 1, [hl]"		,GB_16BIT,NULL},
	{"set 1, a"		,GB_16BIT,NULL},
	{"set 2, b"		,GB_16BIT,NULL},			//0xcbd0
	{"set 2, c"		,GB_16BIT,NULL},
	{"set 2, d"		,GB_16BIT,NULL},
	{"set 2, e"		,GB_16BIT,NULL},
	{"set 2, h"		,GB_16BIT,NULL},
	{"set 2, l"		,GB_16BIT,NULL},
	{"set 2, [hl]"		,GB_16BIT,NULL},
	{"set 2, a"		,GB_16BIT,NULL},
	{"set 3, b"		,GB_16BIT,NULL},
	{"set 3, c"		,GB_16BIT,NULL},
	{"set 3, d"		,GB_16BIT,NULL},
	{"set 3, e"		,GB_16BIT,NULL},
	{"set 3, h"		,GB_16BIT,NULL},
	{"set 3, l"		,GB_16BIT,NULL},
	{"set 3, [hl]"		,GB_16BIT,NULL},
	{"set 3, a"		,GB_16BIT,NULL},
	{"set 4, b"		,GB_16BIT,NULL},			//0xcbe0
	{"set 4, c"		,GB_16BIT,NULL},
	{"set 4, d"		,GB_16BIT,NULL},
	{"set 4, e"		,GB_16BIT,NULL},
	{"set 4, h"		,GB_16BIT,NULL},
	{"set 4, l"		,GB_16BIT,NULL},
	{"set 4, [hl]"		,GB_16BIT,NULL},
	{"set 4, a"		,GB_16BIT,NULL},
	{"set 5, b"		,GB_16BIT,NULL},
	{"set 5, c"		,GB_16BIT,NULL},
	{"set 5, d"		,GB_16BIT,NULL},
	{"set 5, e"		,GB_16BIT,NULL},
	{"set 5, h"		,GB_16BIT,NULL},
	{"set 5, l"		,GB_16BIT,NULL},
	{"set 5, [hl]"		,GB_16BIT,NULL},
	{"set 5, a"		,GB_16BIT,NULL},
	{"set 6, b"		,GB_16BIT,NULL},			//0xcbf0
	{"set 6, c"		,GB_16BIT,NULL},
	{"set 6, d"		,GB_16BIT,NULL},
	{"set 6, e"		,GB_16BIT,NULL},
	{"set 6, h"		,GB_16BIT,NULL},
	{"set 6, l"		,GB_16BIT,NULL},
	{"set 6, [hl]"		,GB_16BIT,NULL},
	{"set 6, a"		,GB_16BIT,NULL},
	{"set 7, b"		,GB_16BIT,NULL},
	{"set 7, c"		,GB_16BIT,NULL},
	{"set 7, d"		,GB_16BIT,NULL},
	{"set 7, e"		,GB_16BIT,NULL},
	{"set 7, h"		,GB_16BIT,NULL},
	{"set 7, l"		,GB_16BIT,NULL},
	{"set 7, [hl]"		,GB_16BIT,NULL},
	{"set 7, a"		,GB_16BIT,NULL},

};

static gb_opcode gb_op[] = {
	{"nop"			,GB_8BIT,NULL},			//0x00
	{"ld bc, 0x%04x"	,GB_8BIT+ARG_16,NULL},
	{"ld [bc], a"		,GB_8BIT,NULL},
	{"inc bc"		,GB_8BIT,NULL},
	{"inc b"		,GB_8BIT,NULL},
	{"dec b"		,GB_8BIT,NULL},
	{"ld b, 0x%02x"		,GB_8BIT+ARG_8,NULL},
	{"rlca"			,GB_8BIT,NULL},
	{"ld [0x%04x], sp"	,GB_8BIT+ARG_16,NULL},		//word or byte?
	{"add hl, bc"		,GB_8BIT,NULL},
	{"ld a, [bc]"		,GB_8BIT,NULL},
	{"dec bc"		,GB_8BIT,NULL},
	{"inc c"		,GB_8BIT,NULL},
	{"dec c"		,GB_8BIT,NULL},
	{"ld c, 0x%02x"		,GB_8BIT+ARG_8,NULL},
	{"rrca"			,GB_8BIT,NULL},

	{"stop"			,GB_8BIT,NULL},			//0x10
	{"ld de, 0x%04x"	,GB_8BIT+ARG_16,NULL},
	{"ld [de], a"		,GB_8BIT,NULL},
	{"inc de"		,GB_8BIT,NULL},
	{"inc d"		,GB_8BIT,NULL},
	{"dec d"		,GB_8BIT,NULL},
	{"ld d, 0x%02x"		,GB_8BIT+ARG_8,NULL},
	{"rla"			,GB_8BIT,NULL},
	{"jr 0x%02x"		,GB_8BIT+ARG_8,NULL},		//signed
	{"add hl, de"		,GB_8BIT,NULL},
	{"ld a, [de]"		,GB_8BIT,NULL},
	{"dec de"		,GB_8BIT,NULL},
	{"inc e"		,GB_8BIT,NULL},
	{"dec e"		,GB_8BIT,NULL},
	{"ld e, 0x%02x"		,GB_8BIT+ARG_8,NULL},
	{"rra"			,GB_8BIT,NULL},

	{"jr nz, 0x%02x"	,GB_8BIT+ARG_8,NULL},		//0x20 //signed
	{"ld hl, 0x%04x"	,GB_8BIT+ARG_16,NULL},
	{"ldi [hl], a"		,GB_8BIT,NULL},
	{"inc hl"		,GB_8BIT,NULL},
	{"inc h"		,GB_8BIT,NULL},
	{"dec h"		,GB_8BIT,NULL},
	{"ld h, 0x%02x"		,GB_8BIT+ARG_8,NULL},
	{"daa"			,GB_8BIT,NULL},
	{"jr z, 0x%02x"		,GB_8BIT+ARG_8,NULL},		//signed
	{"add hl, hl"		,GB_8BIT,NULL},
	{"ldi a, [hl]"		,GB_8BIT,NULL},
	{"dec hl"		,GB_8BIT,NULL},
	{"inc l"		,GB_8BIT,NULL},
	{"dec l"		,GB_8BIT,NULL},
	{"ld l, 0x%02x"		,GB_8BIT+ARG_8,NULL},
	{"cpl"			,GB_8BIT,NULL},

	{"jr nc, 0x%02x"	,GB_8BIT+ARG_8,NULL},		//0x30 //signed
	{"ld sp, 0x%02x"	,GB_8BIT+ARG_8,NULL},		//signed
	{"ldd [hl], a"		,GB_8BIT,NULL},
	{"inc sp"		,GB_8BIT,NULL},
	{"inc [hl]"		,GB_8BIT,NULL},
	{"dec [hl]"		,GB_8BIT,NULL},
	{"ld [hl], 0x%02x"	,GB_8BIT+ARG_8,NULL},
	{"scf"			,GB_8BIT,NULL},
	{"jr c, 0x%02x"		,GB_8BIT+ARG_8,NULL},		//signed
	{"add hl, sp"		,GB_8BIT,NULL},
	{"ldd a, [hl]"		,GB_8BIT,NULL},
	{"dec sp"		,GB_8BIT,NULL},
	{"inc a"		,GB_8BIT,NULL},
	{"dec a"		,GB_8BIT,NULL},
	{"ld a, 0x%02x"		,GB_8BIT+ARG_8,NULL},
	{"ccf"			,GB_8BIT,NULL},

	{"ld b, b"		,GB_8BIT,NULL},			//0x40
	{"ld b, c"		,GB_8BIT,NULL},
	{"ld b, d"		,GB_8BIT,NULL},
	{"ld b, e"		,GB_8BIT,NULL},
	{"ld b, h"		,GB_8BIT,NULL},
	{"ld b, l"		,GB_8BIT,NULL},
	{"ld b, [hl]"		,GB_8BIT,NULL},
	{"ld b, a"		,GB_8BIT,NULL},
	{"ld c, b"		,GB_8BIT,NULL},
	{"ld c, c"		,GB_8BIT,NULL},
	{"ld c, d"		,GB_8BIT,NULL},
	{"ld c, e"		,GB_8BIT,NULL},
	{"ld c, h"		,GB_8BIT,NULL},
	{"ld c, l"		,GB_8BIT,NULL},
	{"ld c, [hl]"		,GB_8BIT,NULL},
	{"ld c, a"		,GB_8BIT,NULL},

	{"ld d, b"		,GB_8BIT,NULL},			//0x50
	{"ld d, c"		,GB_8BIT,NULL},
	{"ld d, d"		,GB_8BIT,NULL},
	{"ld d, e"		,GB_8BIT,NULL},
	{"ld d, h"		,GB_8BIT,NULL},
	{"ld d, l"		,GB_8BIT,NULL},
	{"ld d, [hl]"		,GB_8BIT,NULL},
	{"ld d, a"		,GB_8BIT,NULL},
	{"ld e, b"		,GB_8BIT,NULL},
	{"ld e, c"		,GB_8BIT,NULL},
	{"ld e, d"		,GB_8BIT,NULL},
	{"ld e, e"		,GB_8BIT,NULL},
	{"ld e, h"		,GB_8BIT,NULL},
	{"ld e, l"		,GB_8BIT,NULL},
	{"ld e, [hl]"		,GB_8BIT,NULL},
	{"ld e, a"		,GB_8BIT,NULL},

	{"ld h, b"		,GB_8BIT,NULL},			//0x60
	{"ld h, c"		,GB_8BIT,NULL},
	{"ld h, d"		,GB_8BIT,NULL},
	{"ld h, e"		,GB_8BIT,NULL},
	{"ld h, h"		,GB_8BIT,NULL},
	{"ld h, l"		,GB_8BIT,NULL},
	{"ld h, [hl]"		,GB_8BIT,NULL},
	{"ld h, a"		,GB_8BIT,NULL},
	{"ld l, b"		,GB_8BIT,NULL},
	{"ld l, c"		,GB_8BIT,NULL},
	{"ld l, d"		,GB_8BIT,NULL},
	{"ld l, e"		,GB_8BIT,NULL},
	{"ld l, h"		,GB_8BIT,NULL},
	{"ld l, l"		,GB_8BIT,NULL},
	{"ld l, [hl]"		,GB_8BIT,NULL},
	{"ld l, a"		,GB_8BIT,NULL},

	{"ld [hl], b"		,GB_8BIT,NULL},			//0X70
	{"ld [hl], c"		,GB_8BIT,NULL},
	{"ld [hl], d"		,GB_8BIT,NULL},
	{"ld [hl], e"		,GB_8BIT,NULL},
	{"ld [hl], h"		,GB_8BIT,NULL},
	{"ld [hl], l"		,GB_8BIT,NULL},
	{"halt"			,GB_8BIT,NULL},
	{"ld [hl], a"		,GB_8BIT,NULL},
	{"ld a, b"		,GB_8BIT,NULL},
	{"ld a, c"		,GB_8BIT,NULL},
	{"ld a, d"		,GB_8BIT,NULL},
	{"ld a, e"		,GB_8BIT,NULL},
	{"ld a, h"		,GB_8BIT,NULL},
	{"ld a, l"		,GB_8BIT,NULL},
	{"ld a, [hl]"		,GB_8BIT,NULL},
	{"ld a, a"		,GB_8BIT,NULL},

	{"add b"		,GB_8BIT,NULL},			//0x80
	{"add c"		,GB_8BIT,NULL},
	{"add d"		,GB_8BIT,NULL},
	{"add e"		,GB_8BIT,NULL},
	{"add h"		,GB_8BIT,NULL},
	{"add l"		,GB_8BIT,NULL},
	{"add [hl]"		,GB_8BIT,NULL},
	{"add a"		,GB_8BIT,NULL},
	{"adc b"		,GB_8BIT,NULL},
	{"adc c"		,GB_8BIT,NULL},
	{"adc d"		,GB_8BIT,NULL},
	{"adc e"		,GB_8BIT,NULL},
	{"adc h"		,GB_8BIT,NULL},
	{"adc l"		,GB_8BIT,NULL},
	{"adc [hl]"		,GB_8BIT,NULL},
	{"adc a"		,GB_8BIT,NULL},

	{"sub b"		,GB_8BIT,NULL},			//0x90
	{"sub c"		,GB_8BIT,NULL},
	{"sub d"		,GB_8BIT,NULL},
	{"sub e"		,GB_8BIT,NULL},
	{"sub h"		,GB_8BIT,NULL},
	{"sub l"		,GB_8BIT,NULL},
	{"sub [hl]"		,GB_8BIT,NULL},
	{"sub a"		,GB_8BIT,NULL},
	{"sbc b"		,GB_8BIT,NULL},
	{"sbc c"		,GB_8BIT,NULL},
	{"sbc d"		,GB_8BIT,NULL},
	{"sbc e"		,GB_8BIT,NULL},
	{"sbc h"		,GB_8BIT,NULL},
	{"sbc l"		,GB_8BIT,NULL},
	{"sbc [hl]"		,GB_8BIT,NULL},
	{"sbc a"		,GB_8BIT,NULL},

	{"and b"		,GB_8BIT,NULL},			//0xa0
	{"and c"		,GB_8BIT,NULL},
	{"and d"		,GB_8BIT,NULL},
	{"and e"		,GB_8BIT,NULL},
	{"and h"		,GB_8BIT,NULL},
	{"and l"		,GB_8BIT,NULL},
	{"and [hl]"		,GB_8BIT,NULL},
	{"and a"		,GB_8BIT,NULL},
	{"xor b"		,GB_8BIT,NULL},
	{"xor c"		,GB_8BIT,NULL},
	{"xor d"		,GB_8BIT,NULL},
	{"xor e"		,GB_8BIT,NULL},
	{"xor h"		,GB_8BIT,NULL},
	{"xor l"		,GB_8BIT,NULL},
	{"xor [hl]"		,GB_8BIT,NULL},
	{"xor a"		,GB_8BIT,NULL},

	{"or b"			,GB_8BIT,NULL},			//0xb0
	{"or c"			,GB_8BIT,NULL},
	{"or d"			,GB_8BIT,NULL},
	{"or e"			,GB_8BIT,NULL},
	{"or h"			,GB_8BIT,NULL},
	{"or l"			,GB_8BIT,NULL},
	{"or [hl]"		,GB_8BIT,NULL},
	{"or a"			,GB_8BIT,NULL},
	{"cp b"			,GB_8BIT,NULL},
	{"cp c"			,GB_8BIT,NULL},
	{"cp d"			,GB_8BIT,NULL},
	{"cp e"			,GB_8BIT,NULL},
	{"cp h"			,GB_8BIT,NULL},
	{"cp l"			,GB_8BIT,NULL},
	{"cp [hl]"		,GB_8BIT,NULL},
	{"cp a"			,GB_8BIT,NULL},

	{"ret nz"		,GB_8BIT,NULL},			//0xc0
	{"pop bc"		,GB_8BIT,NULL},
	{"jp nz, 0x%04x"	,GB_8BIT+ARG_16,NULL},
	{"jp 0x%04x"		,GB_8BIT+ARG_16,NULL},
	{"call nz, 0x%04x"	,GB_8BIT+ARG_16,NULL},
	{"push bc"		,GB_8BIT,NULL},
	{"add 0x%02x"		,GB_8BIT+ARG_8,NULL},
	{"rst 0"		,GB_8BIT,NULL},
	{"ret z"		,GB_8BIT,NULL},
	{"ret"			,GB_8BIT,NULL},
	{"jp z, 0x%04x"		,GB_8BIT+ARG_16,NULL},
	{""			,GB_16BIT,cb},
	{"call z, 0x%04x"	,GB_8BIT+ARG_16,NULL},
	{"call 0x%04x"		,GB_8BIT+ARG_16,NULL},
	{"adc 0x%02x"		,GB_8BIT+ARG_8,NULL},
	{"rst 8"		,GB_8BIT,NULL},

	{"ret nc"		,GB_8BIT,NULL},			//0xd0
	{"pop de"		,GB_8BIT,NULL},
	{"jp nc, 0x%04x"	,GB_8BIT+ARG_16,NULL},
	{"invalid"		,GB_8BIT,NULL},
	{"call nc, 0x%04x"	,GB_8BIT+ARG_16,NULL},
	{"push de"		,GB_8BIT,NULL},
	{"sub 0x%02x"		,GB_8BIT+ARG_8,NULL},
	{"rst 16"		,GB_8BIT,NULL},
	{"ret c"		,GB_8BIT,NULL},
	{"reti"			,GB_8BIT,NULL},
	{"jp c, 0x%04x"		,GB_8BIT+ARG_16,NULL},
	{"invalid"		,GB_8BIT,NULL},
	{"call c, 0x%04x"	,GB_8BIT+ARG_16,NULL},
	{"invalid"		,GB_8BIT,NULL},
	{"sbc 0x%02x"		,GB_8BIT+ARG_8,NULL},
	{"rst 24"		,GB_8BIT,NULL},

	{"ld [0x%04x], a"	,GB_8BIT+ARG_8+GB_IO,NULL},	//0xe0
	{"pop hl"		,GB_8BIT,NULL},
	{"ld [0xff00 + c], a"	,GB_8BIT,NULL},
	{"invalid"		,GB_8BIT,NULL},
	{"invalid"		,GB_8BIT,NULL},
	{"push hl"		,GB_8BIT,NULL},
	{"and 0x%02x"		,GB_8BIT+ARG_8,NULL},
	{"rst 32"		,GB_8BIT,NULL},
	{"add sp, 0x%02x"	,GB_8BIT+ARG_8,NULL},		//signed
	{"jp hl"		,GB_8BIT,NULL},
	{"ld [0x%04x], a"	,GB_8BIT+ARG_16,NULL},		//signed
	{"invalid"		,GB_8BIT,NULL},
	{"invalid"		,GB_8BIT,NULL},
	{"invalid"		,GB_8BIT,NULL},
	{"xor 0x%02x"		,GB_8BIT+ARG_8,NULL},
	{"rst 40"		,GB_8BIT,NULL},

	{"ld a, [0x%04x]"	,GB_8BIT+ARG_8+GB_IO,NULL},	//0xf0
	{"pop af"		,GB_8BIT,NULL},
	{"ld a, [0xff00 + c]"	,GB_8BIT,NULL},
	{"di"			,GB_8BIT,NULL},
	{"invalid"		,GB_8BIT,NULL},
	{"push af"		,GB_8BIT,NULL},
	{"or 0x%02x"		,GB_8BIT+ARG_8,NULL},
	{"rst 48"		,GB_8BIT,NULL},
	{"ld hl, [sp + 0x%02x]"	,GB_8BIT+ARG_8,NULL},
	{"ld sp, hl"		,GB_8BIT,NULL},
	{"ld a, [0x%04x]"	,GB_8BIT+ARG_16,NULL},
	{"ei"			,GB_8BIT,NULL},
	{"invalid"		,GB_8BIT,NULL},
	{"invalid"		,GB_8BIT,NULL},
	{"cp 0x%02x"		,GB_8BIT+ARG_8,NULL},
	{"rst 56"		,GB_8BIT,NULL},
};
