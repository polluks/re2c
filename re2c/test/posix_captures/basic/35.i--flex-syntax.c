/* Generated by re2c */

{
	YYCTYPE yych;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	yyt1 = YYCURSOR;
	switch (yych) {
	case 'a':	goto yy3;
	default:	goto yy2;
	}
yy2:
	yynmatch = 1;
	yypmatch[0] = yyt1;
	yypmatch[1] = YYCURSOR;
	{}
yy3:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
	case 'a':	goto yy3;
	default:	goto yy2;
	}
}

posix_captures/basic/35.i--flex-syntax.re:5:4: warning: rule matches empty string [-Wmatch-empty-string]
posix_captures/basic/35.i--flex-syntax.re:6:7: warning: rule matches empty string [-Wmatch-empty-string]
posix_captures/basic/35.i--flex-syntax.re:6:7: warning: unreachable rule (shadowed by rule at line 5) [-Wunreachable-rules]
