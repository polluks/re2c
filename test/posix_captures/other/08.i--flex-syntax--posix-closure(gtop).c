/* Generated by re2c */

{
	YYCTYPE yych;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
	case 'a':
		yyt1 = yyt2 = YYCURSOR;
		goto yy3;
	default:
		yyt2 = yyt3 = NULL;
		yyt1 = YYCURSOR;
		goto yy2;
	}
yy2:
	yynmatch = 2;
	yypmatch[0] = yyt1;
	yypmatch[2] = yyt2;
	yypmatch[3] = yyt3;
	yypmatch[1] = YYCURSOR;
	{}
yy3:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
	case 'a':	goto yy4;
	default:
		yyt3 = YYCURSOR;
		goto yy2;
	}
yy4:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
	case 'a':
		yyt2 = YYCURSOR;
		goto yy3;
	default:
		yyt3 = YYCURSOR;
		goto yy2;
	}
}

posix_captures/other/08.i--flex-syntax--posix-closure(gtop).re:5:4: warning: rule matches empty string [-Wmatch-empty-string]
posix_captures/other/08.i--flex-syntax--posix-closure(gtop).re:6:7: warning: rule matches empty string [-Wmatch-empty-string]
posix_captures/other/08.i--flex-syntax--posix-closure(gtop).re:6:7: warning: unreachable rule (shadowed by rule at line 5) [-Wunreachable-rules]
