/* Generated by re2c */

{
	YYCTYPE yych;
	if ((YYLIMIT - YYCURSOR) < 5) YYFILL(5);
	yych = *(YYMARKER = YYCURSOR);
	switch (yych) {
	case 'a':
		yyt1 = YYCURSOR;
		goto yy3;
	default:	goto yy2;
	}
yy2:
	yynmatch = 1;
	yypmatch[0] = YYCURSOR;
	yypmatch[1] = YYCURSOR;
	{}
yy3:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'b':
		yyt2 = YYCURSOR;
		goto yy5;
	case 'c':
		yyt2 = YYCURSOR;
		goto yy6;
	default:	goto yy4;
	}
yy4:
	YYCURSOR = YYMARKER;
	goto yy2;
yy5:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'b':
		yyt3 = YYCURSOR;
		goto yy8;
	case 'c':
		yyt3 = YYCURSOR;
		goto yy9;
	default:	goto yy4;
	}
yy6:
	++YYCURSOR;
yy7:
	yynmatch = 3;
	yypmatch[2] = yyt1;
	yypmatch[4] = yyt2;
	yypmatch[0] = yyt1;
	yypmatch[1] = YYCURSOR;
	yypmatch[3] = yyt2;
	yypmatch[5] = YYCURSOR;
	{}
yy8:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'c':	goto yy10;
	default:	goto yy4;
	}
yy9:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'd':	goto yy6;
	default:
		yyt2 = yyt3;
		goto yy7;
	}
yy10:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'd':
		yyt2 = yyt3;
		goto yy6;
	default:	goto yy4;
	}
}

posix_captures/forcedassoc/01.i--flex-syntax.re:6:7: warning: rule matches empty string [-Wmatch-empty-string]
