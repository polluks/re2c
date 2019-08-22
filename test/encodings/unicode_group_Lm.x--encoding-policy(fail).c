/* Generated by re2c */
#line 1 "encodings/unicode_group_Lm.x--encoding-policy(fail).re"
#include <stdio.h>
#include "utf16.h"
#define YYCTYPE unsigned short
bool scan(const YYCTYPE * start, const YYCTYPE * const limit)
{
	__attribute__((unused)) const YYCTYPE * YYMARKER; // silence compiler warnings when YYMARKER is not used
#	define YYCURSOR start
Lm:
	
#line 13 "encodings/unicode_group_Lm.x--encoding-policy(fail).c"
{
	YYCTYPE yych;
	yych = *YYCURSOR;
	if (yych <= 0x207F) {
		if (yych <= 0x0824) {
			if (yych <= 0x037A) {
				if (yych <= 0x02EB) {
					if (yych <= 0x02C5) {
						if (yych <= 0x02AF) goto yy2;
						if (yych <= 0x02C1) goto yy4;
					} else {
						if (yych <= 0x02D1) goto yy4;
						if (yych <= 0x02DF) goto yy2;
						if (yych <= 0x02E4) goto yy4;
					}
				} else {
					if (yych <= 0x02EE) {
						if (yych != 0x02ED) goto yy4;
					} else {
						if (yych == 0x0374) goto yy4;
						if (yych >= 0x037A) goto yy4;
					}
				}
			} else {
				if (yych <= 0x07F3) {
					if (yych <= 0x063F) {
						if (yych == 0x0559) goto yy4;
					} else {
						if (yych <= 0x0640) goto yy4;
						if (yych <= 0x06E4) goto yy2;
						if (yych <= 0x06E6) goto yy4;
					}
				} else {
					if (yych <= 0x07FA) {
						if (yych <= 0x07F5) goto yy4;
						if (yych >= 0x07FA) goto yy4;
					} else {
						if (yych == 0x081A) goto yy4;
						if (yych >= 0x0824) goto yy4;
					}
				}
			}
		} else {
			if (yych <= 0x1843) {
				if (yych <= 0x0EC5) {
					if (yych <= 0x0970) {
						if (yych == 0x0828) goto yy4;
					} else {
						if (yych <= 0x0971) goto yy4;
						if (yych == 0x0E46) goto yy4;
					}
				} else {
					if (yych <= 0x10FC) {
						if (yych <= 0x0EC6) goto yy4;
						if (yych >= 0x10FC) goto yy4;
					} else {
						if (yych == 0x17D7) goto yy4;
						if (yych >= 0x1843) goto yy4;
					}
				}
			} else {
				if (yych <= 0x1D77) {
					if (yych <= 0x1C77) {
						if (yych == 0x1AA7) goto yy4;
					} else {
						if (yych <= 0x1C7D) goto yy4;
						if (yych <= 0x1D2B) goto yy2;
						if (yych <= 0x1D6A) goto yy4;
					}
				} else {
					if (yych <= 0x1DBF) {
						if (yych <= 0x1D78) goto yy4;
						if (yych >= 0x1D9B) goto yy4;
					} else {
						if (yych == 0x2071) goto yy4;
						if (yych >= 0x207F) goto yy4;
					}
				}
			}
		}
	} else {
		if (yych <= 0xA69D) {
			if (yych <= 0x303B) {
				if (yych <= 0x2E2E) {
					if (yych <= 0x2C7B) {
						if (yych <= 0x208F) goto yy2;
						if (yych <= 0x209C) goto yy4;
					} else {
						if (yych <= 0x2C7D) goto yy4;
						if (yych == 0x2D6F) goto yy4;
					}
				} else {
					if (yych <= 0x3005) {
						if (yych <= 0x2E2F) goto yy4;
						if (yych >= 0x3005) goto yy4;
					} else {
						if (yych <= 0x3030) goto yy2;
						if (yych <= 0x3035) goto yy4;
						if (yych >= 0x303B) goto yy4;
					}
				}
			} else {
				if (yych <= 0xA4F7) {
					if (yych <= 0x30FB) {
						if (yych <= 0x309C) goto yy2;
						if (yych <= 0x309E) goto yy4;
					} else {
						if (yych <= 0x30FE) goto yy4;
						if (yych == 0xA015) goto yy4;
					}
				} else {
					if (yych <= 0xA60C) {
						if (yych <= 0xA4FD) goto yy4;
						if (yych >= 0xA60C) goto yy4;
					} else {
						if (yych == 0xA67F) goto yy4;
						if (yych >= 0xA69C) goto yy4;
					}
				}
			}
		} else {
			if (yych <= 0xAA70) {
				if (yych <= 0xA7F7) {
					if (yych <= 0xA76F) {
						if (yych <= 0xA716) goto yy2;
						if (yych <= 0xA71F) goto yy4;
					} else {
						if (yych <= 0xA770) goto yy4;
						if (yych == 0xA788) goto yy4;
					}
				} else {
					if (yych <= 0xA9CF) {
						if (yych <= 0xA7F9) goto yy4;
						if (yych >= 0xA9CF) goto yy4;
					} else {
						if (yych == 0xA9E6) goto yy4;
						if (yych >= 0xAA70) goto yy4;
					}
				}
			} else {
				if (yych <= 0xD819) {
					if (yych <= 0xAAF2) {
						if (yych == 0xAADD) goto yy4;
					} else {
						if (yych <= 0xAAF4) goto yy4;
						if (yych <= 0xAB5B) goto yy2;
						if (yych <= 0xAB5F) goto yy4;
					}
				} else {
					if (yych <= 0xFF6F) {
						if (yych <= 0xD81A) goto yy6;
						if (yych <= 0xD81B) goto yy7;
					} else {
						if (yych <= 0xFF70) goto yy4;
						if (yych <= 0xFF9D) goto yy2;
						if (yych <= 0xFF9F) goto yy4;
					}
				}
			}
		}
	}
yy2:
	++YYCURSOR;
yy3:
#line 13 "encodings/unicode_group_Lm.x--encoding-policy(fail).re"
	{ return YYCURSOR == limit; }
#line 180 "encodings/unicode_group_Lm.x--encoding-policy(fail).c"
yy4:
	++YYCURSOR;
#line 12 "encodings/unicode_group_Lm.x--encoding-policy(fail).re"
	{ goto Lm; }
#line 185 "encodings/unicode_group_Lm.x--encoding-policy(fail).c"
yy6:
	yych = *++YYCURSOR;
	if (yych <= 0xDF3F) goto yy3;
	if (yych <= 0xDF43) goto yy4;
	goto yy3;
yy7:
	yych = *++YYCURSOR;
	if (yych <= 0xDF92) goto yy3;
	if (yych <= 0xDF9F) goto yy4;
	goto yy3;
}
#line 14 "encodings/unicode_group_Lm.x--encoding-policy(fail).re"

}
static const unsigned int chars_Lm [] = {0x2b0,0x2c1,  0x2c6,0x2d1,  0x2e0,0x2e4,  0x2ec,0x2ec,  0x2ee,0x2ee,  0x374,0x374,  0x37a,0x37a,  0x559,0x559,  0x640,0x640,  0x6e5,0x6e6,  0x7f4,0x7f5,  0x7fa,0x7fa,  0x81a,0x81a,  0x824,0x824,  0x828,0x828,  0x971,0x971,  0xe46,0xe46,  0xec6,0xec6,  0x10fc,0x10fc,  0x17d7,0x17d7,  0x1843,0x1843,  0x1aa7,0x1aa7,  0x1c78,0x1c7d,  0x1d2c,0x1d6a,  0x1d78,0x1d78,  0x1d9b,0x1dbf,  0x2071,0x2071,  0x207f,0x207f,  0x2090,0x209c,  0x2c7c,0x2c7d,  0x2d6f,0x2d6f,  0x2e2f,0x2e2f,  0x3005,0x3005,  0x3031,0x3035,  0x303b,0x303b,  0x309d,0x309e,  0x30fc,0x30fe,  0xa015,0xa015,  0xa4f8,0xa4fd,  0xa60c,0xa60c,  0xa67f,0xa67f,  0xa69c,0xa69d,  0xa717,0xa71f,  0xa770,0xa770,  0xa788,0xa788,  0xa7f8,0xa7f9,  0xa9cf,0xa9cf,  0xa9e6,0xa9e6,  0xaa70,0xaa70,  0xaadd,0xaadd,  0xaaf3,0xaaf4,  0xab5c,0xab5f,  0xff70,0xff70,  0xff9e,0xff9f,  0x16b40,0x16b43,  0x16f93,0x16f9f,  0x0,0x0};
static unsigned int encode_utf16 (const unsigned int * ranges, unsigned int ranges_count, unsigned int * s)
{
	unsigned int * const s_start = s;
	for (unsigned int i = 0; i < ranges_count; i += 2)
		for (unsigned int j = ranges[i]; j <= ranges[i + 1]; ++j)
		{
			if (j <= re2c::utf16::MAX_1WORD_RUNE)
				*s++ = j;
			else
			{
				*s++ = re2c::utf16::lead_surr(j);
				*s++ = re2c::utf16::trail_surr(j);
			}
		}
	return s - s_start;
}

int main ()
{
	unsigned int * buffer_Lm = new unsigned int [498];
	YYCTYPE * s = (YYCTYPE *) buffer_Lm;
	unsigned int buffer_len = encode_utf16 (chars_Lm, sizeof (chars_Lm) / sizeof (unsigned int), buffer_Lm);
	/* convert 32-bit code units to YYCTYPE; reuse the same buffer */
	for (unsigned int i = 0; i < buffer_len; ++i) s[i] = buffer_Lm[i];
	if (!scan (s, s + buffer_len))
		printf("test 'Lm' failed\n");
	delete [] buffer_Lm;
	return 0;
}
