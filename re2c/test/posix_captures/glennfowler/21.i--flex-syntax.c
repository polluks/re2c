/* Generated by re2c */

{
	YYCTYPE yych;
	if ((YYLIMIT - YYCURSOR) < 4) YYFILL(4);
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
	case 'a':
		yyt2 = YYCURSOR;
		goto yy5;
	case 'b':	goto yy7;
	default:	goto yy4;
	}
yy4:
	YYCURSOR = YYMARKER;
	goto yy2;
yy5:
	++YYCURSOR;
	yynmatch = 3;
	yypmatch[2] = yyt1;
	yypmatch[4] = yyt2;
	yypmatch[0] = yyt1;
	yypmatch[1] = YYCURSOR;
	yypmatch[3] = yyt2;
	yypmatch[5] = YYCURSOR;
	{}
yy7:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'a':
		yyt2 = YYCURSOR;
		goto yy5;
	case 'b':
		yyt2 = YYCURSOR;
		goto yy8;
	default:	goto yy4;
	}
yy8:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'a':	goto yy5;
	default:	goto yy4;
	}
}

posix_captures/glennfowler/21.i--flex-syntax.re:6:7: warning: rule matches empty string [-Wmatch-empty-string]
