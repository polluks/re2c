/* Generated by re2c */
#line 1 "line-01.re"
const char* scan(unsigned char* in)
{

#line 7 "line-01.c"
{
	YYCTYPE yych;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
	case '\n':	goto yy2;
	case 'a':	goto yy5;
	case 'b':	goto yy7;
	case 'c':	goto yy9;
	case 'd':	goto yy11;
	default:	goto yy3;
	}
yy2:
yy3:
	++YYCURSOR;
#line 6 "d"
	{
		return ".";
	}
#line 27 "line-01.c"
yy5:
	++YYCURSOR;
#line 1 "a"
	{
		return "a";
	}
#line 34 "line-01.c"
yy7:
	++YYCURSOR;
#line 2 "b"
	{
		return "b";
	}
#line 41 "line-01.c"
yy9:
	++YYCURSOR;
#line 5 "b"
	{
		return "c";
	}
#line 48 "line-01.c"
yy11:
	++YYCURSOR;
#line 2 "d"
	{
		return "d";
	}
#line 55 "line-01.c"
}
#line 1 "e"

}
e:1:2: warning: control flow is undefined for strings that match '\xA', use default rule '*' [-Wundefined-control-flow]
