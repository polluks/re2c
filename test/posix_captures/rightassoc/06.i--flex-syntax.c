/* Generated by re2c */

{
	YYCTYPE yych;
	if ((YYLIMIT - YYCURSOR) < 2) YYFILL(2);
	yych = *(YYMARKER = YYCURSOR);
	switch (yych) {
	case 'a':
		yyt1 = YYCURSOR;
		goto yy3;
	case 'b':
		yyt1 = yyt3 = YYCURSOR;
		goto yy6;
	default:	goto yy2;
	}
yy2:
	yynmatch = 1;
	yypmatch[0] = YYCURSOR;
	yypmatch[1] = YYCURSOR;
	{}
yy3:
	++YYCURSOR;
	if ((YYLIMIT - YYCURSOR) < 2) YYFILL(2);
	yych = *YYCURSOR;
	switch (yych) {
	case 'a':	goto yy3;
	case 'b':
		yyt3 = YYCURSOR;
		goto yy6;
	default:	goto yy5;
	}
yy5:
	YYCURSOR = YYMARKER;
	goto yy2;
yy6:
	yych = *++YYCURSOR;
	yyt2 = YYCURSOR;
	goto yy9;
yy7:
	yynmatch = 4;
	yypmatch[2] = yyt1;
	yypmatch[4] = yyt3;
	yypmatch[6] = yyt2;
	yypmatch[0] = yyt1;
	yypmatch[1] = YYCURSOR;
	yypmatch[3] = yyt3;
	yypmatch[5] = yyt2;
	yypmatch[7] = YYCURSOR;
	{}
yy8:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
yy9:
	switch (yych) {
	case 'c':	goto yy8;
	default:	goto yy7;
	}
}

posix_captures/rightassoc/06.i--flex-syntax.re:6:7: warning: rule matches empty string [-Wmatch-empty-string]
