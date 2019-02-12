/* Generated by re2c */
#line 1 "bug57.re"
#include <stdio.h>

int scan(const char *p)
{
#define YYCTYPE char
    const char *YYCURSOR = p;
    const char *YYMARKER;


#line 13 "bug57.c"
{
	YYCTYPE yych;
	unsigned int yyaccept = 0;
	yych = *YYCURSOR;
	switch (yych) {
	case '\n':	goto yy2;
	case '<':	goto yy5;
	case '\\':	goto yy6;
	case 'a':	goto yy7;
	default:	goto yy3;
	}
yy2:
#line 15 "bug57.re"
	{ return YYCURSOR - p; }
#line 28 "bug57.c"
yy3:
	++YYCURSOR;
yy4:
#line 16 "bug57.re"
	{ return 0; }
#line 34 "bug57.c"
yy5:
	yyaccept = 0;
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case '>':	goto yy9;
	case '\\':	goto yy11;
	case 'x':
	case 'y':	goto yy13;
	default:	goto yy4;
	}
yy6:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'b':	goto yy7;
	default:	goto yy4;
	}
yy7:
	yyaccept = 1;
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case '\\':	goto yy15;
	case 'a':	goto yy7;
	default:	goto yy2;
	}
yy9:
	++YYCURSOR;
#line 14 "bug57.re"
	{ return YYCURSOR - p; }
#line 63 "bug57.c"
yy11:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'b':	goto yy13;
	default:	goto yy12;
	}
yy12:
	YYCURSOR = YYMARKER;
	if (yyaccept == 0) {
		goto yy4;
	} else {
		goto yy2;
	}
yy13:
	yych = *++YYCURSOR;
	switch (yych) {
	case '>':	goto yy9;
	case '\\':	goto yy11;
	case 'x':
	case 'y':	goto yy13;
	default:	goto yy12;
	}
yy15:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'b':	goto yy7;
	default:	goto yy12;
	}
}
#line 17 "bug57.re"

}

int main()
{
    const char *str = "aaa\\baaa";
    int res = scan(str);
    printf("%d: %s\n", res, str + res);
    return 0;
}

bug57.re:15:26: warning: rule matches empty string [-Wmatch-empty-string]
