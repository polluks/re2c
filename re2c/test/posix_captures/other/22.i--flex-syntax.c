/* Generated by re2c */

{
	YYCTYPE yych;
	if ((YYLIMIT - YYCURSOR) < 3) YYFILL(3);
	yych = *YYCURSOR;
	switch (yych) {
	case 'y':
		yyt1 = yyt2 = yyt3 = YYCURSOR;
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
	case 'y':
		yyt3 = yyt4 = YYCURSOR;
		goto yy5;
	default:	goto yy4;
	}
yy4:
	yynmatch = 2;
	yypmatch[0] = yyt1;
	yypmatch[2] = yyt2;
	yypmatch[3] = yyt3;
	yypmatch[1] = YYCURSOR;
	{}
yy5:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'y':
		yyt3 = YYCURSOR;
		goto yy6;
	default:	goto yy4;
	}
yy6:
	++YYCURSOR;
	yyt2 = yyt4;
	goto yy4;
}

posix_captures/other/22.i--flex-syntax.re:6:7: warning: rule matches empty string [-Wmatch-empty-string]
