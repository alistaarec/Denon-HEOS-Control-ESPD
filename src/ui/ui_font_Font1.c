/*******************************************************************************
 * Size: 20 px
 * Bpp: 2
 * Opts: --bpp 2 --size 20 --font C:/Users/alanh/SquareLine/assets/Arcade.ttf -o C:/Users/alanh/SquareLine/assets\ui_font_Font1.c --format lvgl -r 0x20-0x7f --symbols 123456789:./ --no-compress --no-prefilter
 ******************************************************************************/

#include "ui.h"

#ifndef UI_FONT_FONT1
#define UI_FONT_FONT1 1
#endif

#if UI_FONT_FONT1

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */

    /* U+0021 "!" */
    0x0, 0x7, 0xc0, 0x0, 0x0, 0x0, 0x2f, 0xc0,
    0xf, 0xfc, 0x0, 0x0, 0x0, 0x7f, 0x40, 0x2f,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xf, 0x40,
    0x0,

    /* U+0022 "\"" */
    0xf4, 0xf4, 0x0, 0xf, 0x4f, 0x49, 0x9, 0x0,
    0x0,

    /* U+0023 "#" */
    0x2f, 0x2e, 0x0, 0x0, 0x0, 0x2e, 0x2e, 0xf,
    0xff, 0xfc, 0x0, 0x0, 0x2, 0xe2, 0xe0, 0xff,
    0xff, 0xc2, 0xf2, 0xe0, 0x0, 0x0, 0x2, 0xf2,
    0xe0,

    /* U+0024 "$" */
    0x7, 0x0, 0x0, 0x2f, 0xcc, 0x0, 0x0, 0xf,
    0xe0, 0x0, 0xcf, 0xe0, 0x0, 0x0, 0x70,

    /* U+0025 "%" */
    0xf4, 0x2e, 0xf4, 0xf4, 0x7, 0xc0, 0x0, 0x0,
    0x2f, 0x2e, 0xf4, 0x2e, 0x0, 0x0,

    /* U+0026 "&" */
    0x2f, 0x0, 0x0, 0xc, 0xc, 0x31, 0xc0, 0x0,
    0x0, 0x90, 0xc, 0x72, 0x70, 0x30, 0x0, 0x0,
    0xbc, 0x90,

    /* U+0027 "'" */
    0xf4, 0xf, 0x49, 0x0,

    /* U+0028 "(" */
    0x7, 0xc0, 0x0, 0x2e, 0xf, 0x40, 0x0, 0xf,
    0x40, 0xf4, 0x2, 0xe0, 0x0, 0x0, 0x7c,

    /* U+0029 ")" */
    0xf4, 0x0, 0x0, 0x2e, 0x0, 0x7c, 0x0, 0x0,
    0x7c, 0x7, 0xc2, 0xf0, 0x0, 0xf, 0x40,

    /* U+002A "*" */
    0x93, 0x6, 0x0, 0x2, 0x4c, 0x0, 0x0,

    /* U+002B "+" */
    0x7, 0xc0, 0x7, 0xc0, 0xff, 0xfe, 0x0, 0x0,
    0x7, 0xc0, 0x7, 0xc0, 0x0, 0x0,

    /* U+002C "," */
    0x0, 0xb, 0xc0, 0x2, 0xf0,

    /* U+002D "-" */
    0xff, 0xf4, 0x0, 0x0,

    /* U+002E "." */
    0x0, 0x7c, 0x7c, 0x0,

    /* U+002F "/" */
    0x0, 0x6, 0x0, 0x0, 0x0, 0x2e, 0x0, 0xf4,
    0x0, 0x0, 0x7, 0xc0, 0x7, 0xc0, 0x2f, 0x0,
    0x0, 0x0, 0xf4, 0x0,

    /* U+0030 "0" */
    0x2f, 0xf4, 0x0, 0x0, 0xf4, 0x2e, 0xf4, 0x2e,
    0x0, 0x0, 0xf4, 0x2e, 0xf4, 0x2e, 0xf4, 0x2e,
    0x0, 0x0, 0x2f, 0xf4,

    /* U+0031 "1" */
    0x7, 0xc0, 0x0, 0x0, 0x2f, 0xc0, 0x7, 0xc0,
    0x0, 0x0, 0x7, 0xc0, 0x7, 0xc0, 0x7, 0xc0,
    0x0, 0x40, 0xff, 0xfe,

    /* U+0032 "2" */
    0x2f, 0xfe, 0x0, 0x0, 0x0, 0xf4, 0x7, 0xc0,
    0x2, 0xe0, 0x0, 0x0, 0x0, 0x7f, 0x40, 0x2f,
    0x0, 0xf, 0x40, 0x0, 0x40, 0x0, 0xf, 0xff,
    0xfc,

    /* U+0033 "3" */
    0x2f, 0xfe, 0x0, 0x0, 0x0, 0xf4, 0x7, 0xc0,
    0x0, 0x7c, 0x0, 0x0, 0x0, 0xf, 0xe0, 0x0,
    0x7, 0xcf, 0x40, 0x7c, 0x0, 0x0, 0x2, 0xff,
    0xe0,

    /* U+0034 "4" */
    0x0, 0xfe, 0x0, 0x0, 0x0, 0x7, 0xfe, 0x2,
    0xf2, 0xe0, 0x0, 0x0, 0xf, 0x42, 0xe0, 0xff,
    0xff, 0xc0, 0x2, 0xe0, 0x0, 0x0, 0x0, 0x2,
    0xe0,

    /* U+0035 "5" */
    0xff, 0xfe, 0x0, 0x0, 0x0, 0xf4, 0x0, 0xf,
    0xff, 0xe0, 0x0, 0x0, 0x0, 0x0, 0x7c, 0x0,
    0x7, 0xcf, 0x40, 0x7c, 0x0, 0x0, 0x2, 0xff,
    0xe0,

    /* U+0036 "6" */
    0x2f, 0xfe, 0x0, 0x0, 0x0, 0xf4, 0x7, 0xcf,
    0x40, 0x0, 0x0, 0x0, 0xf, 0xff, 0xe0, 0xf4,
    0x7, 0xcf, 0x40, 0x7c, 0x0, 0x0, 0x2, 0xff,
    0xe0,

    /* U+0037 "7" */
    0xff, 0xff, 0xc0, 0x0, 0x0, 0x0, 0x2e, 0x0,
    0xf, 0x40, 0x0, 0x0, 0x0, 0x7c, 0x0, 0x7,
    0xc0, 0x0, 0x7c, 0x0, 0x0, 0x40, 0x0, 0x7c,
    0x0,

    /* U+0038 "8" */
    0x2f, 0xfe, 0x0, 0x0, 0x0, 0xf4, 0x7, 0xcf,
    0x40, 0x7c, 0x0, 0x0, 0x2, 0xff, 0xe0, 0xf4,
    0x7, 0xcf, 0x40, 0x7c, 0x0, 0x0, 0x2, 0xff,
    0xe0,

    /* U+0039 "9" */
    0x2f, 0xfe, 0x0, 0x0, 0x0, 0xf4, 0x7, 0xcf,
    0x40, 0x7c, 0x0, 0x0, 0x2, 0xff, 0xfc, 0x0,
    0x7, 0xc0, 0x2, 0xe0, 0x0, 0x0, 0x0, 0x7f,
    0x40,

    /* U+003A ":" */
    0xf7, 0xd0, 0x0, 0xf7, 0xd0, 0x0,

    /* U+003B ";" */
    0xf7, 0xd0, 0x0, 0xf7, 0xd0, 0x9,

    /* U+003C "<" */
    0x7, 0xc2, 0xf0, 0xf8, 0x0, 0x0, 0x2f, 0x0,
    0x7c, 0x0, 0x0,

    /* U+003D "=" */
    0xff, 0xf4, 0x0, 0x0, 0x0, 0x3f, 0xfd, 0x0,
    0x0,

    /* U+003E ">" */
    0xf4, 0x2, 0xf0, 0x7, 0xc0, 0x0, 0x2f, 0xf,
    0x40, 0x0, 0x0,

    /* U+003F "?" */
    0x2f, 0xf4, 0x0, 0x0, 0xf4, 0x2e, 0x0, 0xf4,
    0x0, 0x0, 0x7, 0xc0, 0x0, 0x0, 0x7, 0xc0,
    0x0, 0x40, 0x7, 0xc0,

    /* U+0040 "@" */
    0x2f, 0xfe, 0x0, 0x0, 0x0, 0xc0, 0x0, 0xcc,
    0x7f, 0x4c, 0x0, 0x0, 0xc, 0x62, 0x4c, 0xc7,
    0xc7, 0xcc, 0x0, 0x0, 0x0, 0x0, 0x2, 0xff,
    0xfc,

    /* U+0041 "A" */
    0x7, 0xf4, 0x0, 0x0, 0x0, 0x2e, 0x2e, 0xf,
    0x40, 0x7c, 0x0, 0x0, 0xf, 0x40, 0x7c, 0xff,
    0xff, 0xcf, 0x40, 0x7c, 0x40, 0x0, 0x4f, 0x40,
    0x7c,

    /* U+0042 "B" */
    0xff, 0xfe, 0x0, 0x0, 0x0, 0xf4, 0x7, 0xcf,
    0x40, 0x7c, 0x0, 0x0, 0xf, 0xff, 0xe0, 0xf4,
    0x7, 0xcf, 0x40, 0x7c, 0x40, 0x0, 0xf, 0xff,
    0xe0,

    /* U+0043 "C" */
    0x2f, 0xfe, 0x0, 0x0, 0x0, 0xf4, 0x7, 0xcf,
    0x40, 0x0, 0x0, 0x0, 0xf, 0x40, 0x0, 0xf4,
    0x0, 0xf, 0x40, 0x7c, 0x0, 0x0, 0x2, 0xff,
    0xe0,

    /* U+0044 "D" */
    0xff, 0xfe, 0x0, 0x0, 0x0, 0xf4, 0x7, 0xcf,
    0x40, 0x7c, 0x0, 0x0, 0xf, 0x40, 0x7c, 0xf4,
    0x7, 0xcf, 0x40, 0x7c, 0x40, 0x0, 0xf, 0xff,
    0xe0,

    /* U+0045 "E" */
    0xff, 0xff, 0xc0, 0x0, 0x0, 0xf4, 0x0, 0xf,
    0x40, 0x0, 0x0, 0x0, 0xf, 0xff, 0xe0, 0xf4,
    0x0, 0xf, 0x40, 0x0, 0x40, 0x0, 0xf, 0xff,
    0xfc,

    /* U+0046 "F" */
    0xff, 0xff, 0xc0, 0x0, 0x0, 0xf4, 0x0, 0xf,
    0x40, 0x0, 0x0, 0x0, 0xf, 0xff, 0xe0, 0xf4,
    0x0, 0xf, 0x40, 0x0, 0x40, 0x0, 0xf, 0x40,
    0x0,

    /* U+0047 "G" */
    0x2f, 0xfe, 0x0, 0x0, 0x0, 0xf4, 0x7, 0xcf,
    0x40, 0x0, 0x0, 0x0, 0xf, 0x42, 0xfc, 0xf4,
    0x7, 0xcf, 0x40, 0x7c, 0x0, 0x0, 0x2, 0xff,
    0xe0,

    /* U+0048 "H" */
    0xf4, 0x7, 0xc0, 0x0, 0x0, 0xf4, 0x7, 0xcf,
    0x40, 0x7c, 0x0, 0x0, 0xf, 0xff, 0xfc, 0xf4,
    0x7, 0xcf, 0x40, 0x7c, 0x40, 0x0, 0x4f, 0x40,
    0x7c,

    /* U+0049 "I" */
    0xff, 0xfe, 0x0, 0x0, 0x7, 0xc0, 0x7, 0xc0,
    0x0, 0x0, 0x7, 0xc0, 0x7, 0xc0, 0x7, 0xc0,
    0x0, 0x40, 0xff, 0xfe,

    /* U+004A "J" */
    0x7, 0xff, 0xc0, 0x0, 0x0, 0x0, 0x2e, 0x0,
    0x2, 0xe0, 0x0, 0x0, 0x0, 0x2, 0xe0, 0x0,
    0x2e, 0xf, 0x42, 0xe0, 0x0, 0x0, 0x2, 0xff,
    0x40,

    /* U+004B "K" */
    0xf4, 0x7, 0xc0, 0x0, 0x0, 0xf4, 0x2e, 0xf,
    0x4f, 0x40, 0x0, 0x0, 0xf, 0xfc, 0x0, 0xff,
    0xf4, 0xf, 0x4f, 0xe0, 0x40, 0x0, 0xf, 0x40,
    0x7c,

    /* U+004C "L" */
    0xf4, 0x0, 0x0, 0x0, 0x0, 0xf4, 0x0, 0xf,
    0x40, 0x0, 0x0, 0x0, 0xf, 0x40, 0x0, 0xf4,
    0x0, 0xf, 0x40, 0x0, 0x40, 0x0, 0xf, 0xff,
    0xfc,

    /* U+004D "M" */
    0xc0, 0x0, 0xc0, 0x0, 0x0, 0xf4, 0x7, 0xcf,
    0xf2, 0xfc, 0x0, 0x0, 0xf, 0xff, 0xfc, 0xf4,
    0xc7, 0xcf, 0x40, 0x7c, 0x40, 0x0, 0x4f, 0x40,
    0x7c,

    /* U+004E "N" */
    0xf4, 0x7, 0xc0, 0x0, 0x0, 0xfe, 0x7, 0xcf,
    0xfc, 0x7c, 0x0, 0x0, 0xf, 0x4f, 0xfc, 0xf4,
    0x2f, 0xcf, 0x40, 0x7c, 0x40, 0x0, 0x4f, 0x40,
    0x7c,

    /* U+004F "O" */
    0x2f, 0xfe, 0x0, 0x0, 0x0, 0xf4, 0x7, 0xcf,
    0x40, 0x7c, 0x0, 0x0, 0xf, 0x40, 0x7c, 0xf4,
    0x7, 0xcf, 0x40, 0x7c, 0x0, 0x0, 0x2, 0xff,
    0xe0,

    /* U+0050 "P" */
    0xff, 0xfe, 0x0, 0x0, 0x0, 0xf4, 0x7, 0xcf,
    0x40, 0x7c, 0x0, 0x0, 0xf, 0xff, 0xe0, 0xf4,
    0x0, 0xf, 0x40, 0x0, 0x40, 0x0, 0xf, 0x40,
    0x0,

    /* U+0051 "Q" */
    0x2f, 0xfe, 0x0, 0x0, 0x0, 0xf4, 0x7, 0xcf,
    0x40, 0x7c, 0x0, 0x0, 0xf, 0x40, 0x7c, 0xf4,
    0xff, 0xcf, 0x42, 0xe0, 0x0, 0x0, 0x2, 0xfc,
    0x7c,

    /* U+0052 "R" */
    0xff, 0xfe, 0x0, 0x0, 0x0, 0xf4, 0x7, 0xcf,
    0x40, 0x7c, 0x0, 0x0, 0xf, 0xff, 0xe0, 0xf4,
    0xf4, 0xf, 0x42, 0xe0, 0x40, 0x0, 0xf, 0x40,
    0x7c,

    /* U+0053 "S" */
    0x2f, 0xfe, 0x0, 0x0, 0x0, 0xf4, 0x7, 0xcf,
    0x40, 0x0, 0x0, 0x0, 0x2, 0xff, 0xe0, 0x0,
    0x7, 0xcf, 0x40, 0x7c, 0x0, 0x0, 0x2, 0xff,
    0xe0,

    /* U+0054 "T" */
    0xff, 0xfe, 0x0, 0x0, 0x7, 0xc0, 0x7, 0xc0,
    0x0, 0x0, 0x7, 0xc0, 0x7, 0xc0, 0x7, 0xc0,
    0x0, 0x40, 0x7, 0xc0,

    /* U+0055 "U" */
    0xf4, 0x7, 0xc0, 0x0, 0x0, 0xf4, 0x7, 0xcf,
    0x40, 0x7c, 0x0, 0x0, 0xf, 0x40, 0x7c, 0xf4,
    0x7, 0xcf, 0x40, 0x7c, 0x0, 0x0, 0x2, 0xff,
    0xe0,

    /* U+0056 "V" */
    0xf4, 0x7, 0xc0, 0x0, 0x0, 0xf4, 0x7, 0xcf,
    0x40, 0x7c, 0x0, 0x0, 0xf, 0x40, 0x7c, 0xf4,
    0x7, 0xc2, 0xe2, 0xe0, 0x0, 0x0, 0x0, 0x7f,
    0x40,

    /* U+0057 "W" */
    0xf4, 0x7, 0xc0, 0x0, 0x0, 0xf4, 0x7, 0xcf,
    0x40, 0x7c, 0x0, 0x0, 0xf, 0x40, 0x7c, 0xf4,
    0xc7, 0xcf, 0xff, 0xfc, 0x0, 0x0, 0x2, 0xf2,
    0xe0,

    /* U+0058 "X" */
    0xf4, 0x7, 0xc0, 0x0, 0x0, 0x2e, 0x2e, 0x0,
    0x7f, 0x40, 0x0, 0x0, 0x0, 0x7f, 0x40, 0x2f,
    0x2e, 0xf, 0x40, 0x7c, 0x40, 0x0, 0x4c, 0x0,
    0xc,

    /* U+0059 "Y" */
    0xf4, 0x2e, 0x0, 0x0, 0xf4, 0x2e, 0xf4, 0x2e,
    0x0, 0x0, 0x2f, 0xf4, 0x7, 0xc0, 0x7, 0xc0,
    0x0, 0x40, 0x7, 0xc0,

    /* U+005A "Z" */
    0xff, 0xff, 0xc0, 0x0, 0x0, 0x0, 0x2e, 0x0,
    0xf, 0x40, 0x0, 0x0, 0x0, 0x7c, 0x0, 0x2f,
    0x0, 0xf, 0x40, 0x0, 0x40, 0x0, 0xf, 0xff,
    0xfc,

    /* U+005B "[" */
    0xff, 0x0, 0xf4, 0xf4, 0x0, 0xf4, 0xf4, 0xf4,
    0x40, 0xff,

    /* U+005C "\\" */
    0xf4, 0x0, 0x0, 0x0, 0x0, 0x2e, 0x0, 0x0,
    0x7c, 0x0, 0x0, 0x0, 0x0, 0xf, 0x40, 0x0,
    0x2e, 0x0, 0x0, 0x7c, 0x0, 0x0, 0x40, 0x0,
    0xc,

    /* U+005D "]" */
    0xff, 0x0, 0x2e, 0x2f, 0x0, 0x2e, 0x2f, 0x2f,
    0x0, 0xff,

    /* U+0061 "a" */
    0x2f, 0xfe, 0x0, 0x0, 0x0, 0x0, 0x7, 0xc2,
    0xff, 0xfc, 0xf4, 0x7, 0xc0, 0x0, 0x4, 0x2f,
    0xff, 0xc0,

    /* U+0062 "b" */
    0xf4, 0x0, 0x0, 0x0, 0x0, 0xf4, 0x0, 0xf,
    0xff, 0xe0, 0x0, 0x0, 0xf, 0x40, 0x7c, 0xf4,
    0x7, 0xcf, 0x40, 0x7c, 0x40, 0x0, 0xf, 0xff,
    0xe0,

    /* U+0063 "c" */
    0x2f, 0xfe, 0x0, 0x0, 0x0, 0xf4, 0x7, 0xcf,
    0x40, 0x0, 0xf4, 0x7, 0xc0, 0x0, 0x0, 0x2f,
    0xfe, 0x0,

    /* U+0064 "d" */
    0x0, 0x7, 0xc0, 0x0, 0x0, 0x0, 0x7, 0xc2,
    0xff, 0xfc, 0x0, 0x0, 0xf, 0x40, 0x7c, 0xf4,
    0x7, 0xcf, 0x40, 0x7c, 0x0, 0x0, 0x42, 0xff,
    0xfc,

    /* U+0065 "e" */
    0x2f, 0xfe, 0x0, 0x0, 0x0, 0xf4, 0x7, 0xcf,
    0xff, 0xfc, 0xf4, 0x0, 0x0, 0x0, 0x0, 0x2f,
    0xfe, 0x0,

    /* U+0066 "f" */
    0x7, 0xf4, 0x0, 0x2, 0xe0, 0x3f, 0xf0, 0x0,
    0x0, 0xb8, 0x2, 0xf0, 0xb, 0xc0, 0x0, 0x0,
    0xbc, 0x0,

    /* U+0067 "g" */
    0x2f, 0xfe, 0xf, 0x80, 0x7c, 0xf4, 0x7, 0xc0,
    0x0, 0x0, 0xf4, 0x7, 0xc0, 0x0, 0x4, 0x2f,
    0xff, 0xc0, 0x0, 0x0, 0x2f, 0xfe, 0x0,

    /* U+0068 "h" */
    0xf4, 0x0, 0x0, 0x0, 0x0, 0xf4, 0x0, 0xf,
    0xff, 0xe0, 0x0, 0x0, 0xf, 0x40, 0x7c, 0xf4,
    0x7, 0xcf, 0x40, 0x7c, 0x40, 0x0, 0x4f, 0x40,
    0x7c,

    /* U+0069 "i" */
    0xf4, 0x0, 0x3d, 0x3, 0xdf, 0x7d, 0x43, 0xd0,

    /* U+006A "j" */
    0x7, 0xc0, 0x0, 0x0, 0x2, 0xfc, 0x7, 0xc0,
    0x7c, 0x0, 0x0, 0x7c, 0x0, 0x40, 0xbc, 0x0,
    0xf, 0xf0,

    /* U+006B "k" */
    0xf4, 0x0, 0x0, 0x0, 0xf4, 0x0, 0xf4, 0x2e,
    0x0, 0x0, 0xf4, 0xf4, 0xff, 0xc0, 0xf4, 0xf4,
    0x40, 0x0, 0xf4, 0x2e,

    /* U+006C "l" */
    0xf4, 0xf, 0x7d, 0x3, 0xdf, 0x7d, 0x43, 0xd0,

    /* U+006D "m" */
    0xff, 0x2e, 0x0, 0x0, 0x0, 0xf4, 0xc7, 0xcf,
    0x4c, 0x7c, 0xf4, 0xc7, 0xc4, 0x4, 0x4, 0xf4,
    0xc7, 0xc0,

    /* U+006E "n" */
    0xff, 0xf4, 0x0, 0x0, 0xf4, 0x2e, 0xf4, 0x2e,
    0xf4, 0x2e, 0x40, 0x0, 0xf4, 0x2e,

    /* U+006F "o" */
    0x2f, 0xfe, 0x0, 0x0, 0x0, 0xf4, 0x7, 0xcf,
    0x40, 0x7c, 0xf4, 0x7, 0xc0, 0x0, 0x0, 0x2f,
    0xfe, 0x0,

    /* U+0070 "p" */
    0xff, 0xfe, 0xf, 0x80, 0x7c, 0xf4, 0x7, 0xc0,
    0x0, 0x0, 0xf4, 0x7, 0xc4, 0x0, 0x0, 0xff,
    0xfe, 0x5, 0x0, 0x0, 0xf4, 0x0, 0x0,

    /* U+0071 "q" */
    0x2f, 0xff, 0xcf, 0x80, 0x7c, 0xf4, 0x7, 0xc0,
    0x0, 0x0, 0xf4, 0x7, 0xc0, 0x0, 0x4, 0x2f,
    0xff, 0xc0, 0x0, 0x4, 0x0, 0x7, 0xc0,

    /* U+0072 "r" */
    0xf4, 0xf4, 0x0, 0xf, 0xe0, 0x3d, 0x0, 0xf4,
    0x1, 0x0, 0xf, 0x40, 0x0,

    /* U+0073 "s" */
    0x2f, 0xfe, 0x0, 0x0, 0x0, 0xf4, 0x0, 0x2,
    0xff, 0xe0, 0x0, 0x7, 0xc0, 0x0, 0x0, 0x2f,
    0xfe, 0x0,

    /* U+0074 "t" */
    0x2f, 0x0, 0x0, 0x2, 0xe0, 0x3f, 0xf0, 0x0,
    0x0, 0xb8, 0x2, 0xf0, 0xb, 0xc0, 0x0, 0x0,
    0x1f, 0xd0,

    /* U+0075 "u" */
    0xf4, 0x7, 0xc0, 0x0, 0x0, 0xf4, 0x7, 0xcf,
    0x40, 0x7c, 0xf4, 0x7, 0xc0, 0x0, 0x4, 0x2f,
    0xff, 0xc0,

    /* U+0076 "v" */
    0xf4, 0x7, 0xc0, 0x0, 0x0, 0xf4, 0x7, 0xcf,
    0x40, 0x7c, 0x2e, 0x2e, 0x0, 0x0, 0x0, 0x7,
    0xf4, 0x0,

    /* U+0077 "w" */
    0xf4, 0x7, 0xc0, 0x0, 0x0, 0xf4, 0x7, 0xcf,
    0x40, 0x7c, 0xf4, 0xc7, 0xc0, 0x0, 0x0, 0x2f,
    0x2e, 0x0,

    /* U+0078 "x" */
    0xf4, 0x7, 0xc0, 0x0, 0x0, 0x2e, 0x2e, 0x0,
    0x7f, 0x40, 0x2f, 0x2e, 0x0, 0x0, 0x0, 0xf4,
    0x7, 0xc0,

    /* U+0079 "y" */
    0xf4, 0x7, 0xcf, 0x40, 0x7c, 0xf4, 0x7, 0xc0,
    0x0, 0x0, 0xf4, 0x7, 0xc0, 0x0, 0x4, 0x2f,
    0xff, 0xc0, 0x0, 0x0, 0x2f, 0xfe, 0x0,

    /* U+007A "z" */
    0xff, 0xff, 0xc0, 0x0, 0x0, 0x0, 0x2e, 0x0,
    0x7f, 0x40, 0x2f, 0x0, 0x0, 0x0, 0x0, 0xff,
    0xff, 0xc0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 166, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 0, .adv_w = 166, .box_w = 10, .box_h = 10, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 25, .adv_w = 166, .box_w = 7, .box_h = 5, .ofs_x = 0, .ofs_y = 9},
    {.bitmap_index = 34, .adv_w = 166, .box_w = 10, .box_h = 10, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 59, .adv_w = 166, .box_w = 6, .box_h = 10, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 74, .adv_w = 166, .box_w = 8, .box_h = 7, .ofs_x = 0, .ofs_y = 5},
    {.bitmap_index = 88, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 106, .adv_w = 111, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = 9},
    {.bitmap_index = 110, .adv_w = 166, .box_w = 6, .box_h = 10, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 125, .adv_w = 166, .box_w = 6, .box_h = 10, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 140, .adv_w = 166, .box_w = 5, .box_h = 5, .ofs_x = 1, .ofs_y = 6},
    {.bitmap_index = 147, .adv_w = 145, .box_w = 8, .box_h = 7, .ofs_x = 0, .ofs_y = 5},
    {.bitmap_index = 161, .adv_w = 103, .box_w = 5, .box_h = 4, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 166, .adv_w = 127, .box_w = 7, .box_h = 2, .ofs_x = 0, .ofs_y = 8},
    {.bitmap_index = 170, .adv_w = 103, .box_w = 4, .box_h = 4, .ofs_x = 2, .ofs_y = 2},
    {.bitmap_index = 174, .adv_w = 166, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 194, .adv_w = 145, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 214, .adv_w = 145, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 234, .adv_w = 166, .box_w = 10, .box_h = 10, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 259, .adv_w = 166, .box_w = 10, .box_h = 10, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 284, .adv_w = 166, .box_w = 10, .box_h = 10, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 309, .adv_w = 166, .box_w = 10, .box_h = 10, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 334, .adv_w = 166, .box_w = 10, .box_h = 10, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 359, .adv_w = 166, .box_w = 10, .box_h = 10, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 384, .adv_w = 166, .box_w = 10, .box_h = 10, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 409, .adv_w = 166, .box_w = 10, .box_h = 10, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 434, .adv_w = 64, .box_w = 3, .box_h = 7, .ofs_x = 0, .ofs_y = 5},
    {.bitmap_index = 440, .adv_w = 63, .box_w = 3, .box_h = 8, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 446, .adv_w = 166, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 5},
    {.bitmap_index = 457, .adv_w = 128, .box_w = 7, .box_h = 5, .ofs_x = 0, .ofs_y = 6},
    {.bitmap_index = 466, .adv_w = 166, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 5},
    {.bitmap_index = 477, .adv_w = 166, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 497, .adv_w = 166, .box_w = 10, .box_h = 10, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 522, .adv_w = 166, .box_w = 10, .box_h = 10, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 547, .adv_w = 166, .box_w = 10, .box_h = 10, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 572, .adv_w = 166, .box_w = 10, .box_h = 10, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 597, .adv_w = 166, .box_w = 10, .box_h = 10, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 622, .adv_w = 166, .box_w = 10, .box_h = 10, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 647, .adv_w = 166, .box_w = 10, .box_h = 10, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 672, .adv_w = 166, .box_w = 10, .box_h = 10, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 697, .adv_w = 166, .box_w = 10, .box_h = 10, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 722, .adv_w = 166, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 742, .adv_w = 166, .box_w = 10, .box_h = 10, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 767, .adv_w = 166, .box_w = 10, .box_h = 10, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 792, .adv_w = 166, .box_w = 10, .box_h = 10, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 817, .adv_w = 166, .box_w = 10, .box_h = 10, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 842, .adv_w = 166, .box_w = 10, .box_h = 10, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 867, .adv_w = 166, .box_w = 10, .box_h = 10, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 892, .adv_w = 166, .box_w = 10, .box_h = 10, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 917, .adv_w = 166, .box_w = 10, .box_h = 10, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 942, .adv_w = 166, .box_w = 10, .box_h = 10, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 967, .adv_w = 166, .box_w = 10, .box_h = 10, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 992, .adv_w = 166, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 1012, .adv_w = 166, .box_w = 10, .box_h = 10, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 1037, .adv_w = 166, .box_w = 10, .box_h = 10, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 1062, .adv_w = 166, .box_w = 10, .box_h = 10, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 1087, .adv_w = 166, .box_w = 10, .box_h = 10, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 1112, .adv_w = 166, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 1132, .adv_w = 166, .box_w = 10, .box_h = 10, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 1157, .adv_w = 97, .box_w = 4, .box_h = 10, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 1167, .adv_w = 166, .box_w = 10, .box_h = 10, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 1192, .adv_w = 102, .box_w = 4, .box_h = 10, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 1202, .adv_w = 166, .box_w = 10, .box_h = 7, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 1220, .adv_w = 166, .box_w = 10, .box_h = 10, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 1245, .adv_w = 166, .box_w = 10, .box_h = 7, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 1263, .adv_w = 166, .box_w = 10, .box_h = 10, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 1288, .adv_w = 166, .box_w = 10, .box_h = 7, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 1306, .adv_w = 125, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 1324, .adv_w = 166, .box_w = 10, .box_h = 9, .ofs_x = 0, .ofs_y = 2},
    {.bitmap_index = 1347, .adv_w = 166, .box_w = 10, .box_h = 10, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 1372, .adv_w = 60, .box_w = 3, .box_h = 10, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 1380, .adv_w = 103, .box_w = 6, .box_h = 12, .ofs_x = 0, .ofs_y = 2},
    {.bitmap_index = 1398, .adv_w = 166, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 1418, .adv_w = 60, .box_w = 3, .box_h = 10, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 1426, .adv_w = 166, .box_w = 10, .box_h = 7, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 1444, .adv_w = 145, .box_w = 8, .box_h = 7, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 1458, .adv_w = 166, .box_w = 10, .box_h = 7, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 1476, .adv_w = 166, .box_w = 10, .box_h = 9, .ofs_x = 0, .ofs_y = 2},
    {.bitmap_index = 1499, .adv_w = 166, .box_w = 10, .box_h = 9, .ofs_x = 0, .ofs_y = 2},
    {.bitmap_index = 1522, .adv_w = 124, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 1535, .adv_w = 166, .box_w = 10, .box_h = 7, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 1553, .adv_w = 124, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 1571, .adv_w = 166, .box_w = 10, .box_h = 7, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 1589, .adv_w = 166, .box_w = 10, .box_h = 7, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 1607, .adv_w = 166, .box_w = 10, .box_h = 7, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 1625, .adv_w = 166, .box_w = 10, .box_h = 7, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 1643, .adv_w = 166, .box_w = 10, .box_h = 9, .ofs_x = 0, .ofs_y = 2},
    {.bitmap_index = 1666, .adv_w = 166, .box_w = 10, .box_h = 7, .ofs_x = 0, .ofs_y = 4}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/



/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 62, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 97, .range_length = 26, .glyph_id_start = 63,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR == 8
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
#endif

#if LVGL_VERSION_MAJOR >= 8
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 2,
    .bpp = 2,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache
#endif
};



/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t ui_font_Font1 = {
#else
lv_font_t ui_font_Font1 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 14,          /*The maximum line height required by the font*/
    .base_line = 0,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -3,
    .underline_thickness = 0,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = NULL,
#endif
    .user_data = NULL,
};



#endif /*#if UI_FONT_FONT1*/
