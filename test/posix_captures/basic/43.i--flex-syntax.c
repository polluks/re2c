/* Generated by re2c */

{
	YYCTYPE yych;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *(YYMARKER = YYCURSOR);
	switch (yych) {
	case 'a':
	case 'c':
		yyt1 = yyt4 = YYCURSOR;
		goto yy3;
	case 'b':
		yyt2 = yyt3 = NULL;
		yyt1 = yyt4 = YYCURSOR;
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
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
	case 'a':
	case 'c':
		yyt4 = YYCURSOR;
		goto yy3;
	case 'b':
		yyt2 = yyt4;
		yyt3 = yyt4 = YYCURSOR;
		goto yy6;
	default:	goto yy5;
	}
yy5:
	YYCURSOR = YYMARKER;
	goto yy2;
yy6:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
	case 'a':
		yyt4 = YYCURSOR;
		goto yy3;
	case 'b':
		yyt2 = yyt4;
		yyt3 = yyt4 = YYCURSOR;
		goto yy6;
	case 'c':
		yyt4 = YYCURSOR;
		goto yy8;
	default:	goto yy5;
	}
yy8:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
	case 'a':
	case 'c':
		yyt4 = YYCURSOR;
		goto yy3;
	case 'b':
		yyt2 = yyt4;
		yyt3 = yyt4 = YYCURSOR;
		goto yy6;
	case 'd':	goto yy9;
	default:	goto yy5;
	}
yy9:
	++YYCURSOR;
	yynmatch = 2;
	yypmatch[0] = yyt1;
	yypmatch[2] = yyt2;
	yypmatch[3] = yyt3;
	yypmatch[1] = YYCURSOR;
	{}
}

posix_captures/basic/43.i--flex-syntax.re:6:7: warning: rule matches empty string [-Wmatch-empty-string]
