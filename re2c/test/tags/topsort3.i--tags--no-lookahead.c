/* Generated by re2c */

{
	YYCTYPE yych;
	yyt2 = YYCURSOR;
	if ((YYLIMIT - YYCURSOR) < 3) YYFILL(3);
	yych = *(YYMARKER = YYCURSOR++);
	yyt1 = NULL;
	switch (yych) {
	case 'a':	goto yy4;
	case 'b':	goto yy6;
	default:	goto yy3;
	}
yy2:
	{}
yy3:
	yych = *YYCURSOR++;
	switch (yych) {
	case 'a':	goto yy9;
	case 'b':	goto yy10;
	default:	goto yy8;
	}
yy4:
	yych = *YYCURSOR;
	switch (yych) {
	case 'a':	goto yy5;
	default:
		++YYCURSOR;
		goto yy10;
	}
yy5:
	YYCURSOR = YYMARKER;
	goto yy2;
yy6:
	yych = *YYCURSOR;
	switch (yych) {
	case 'b':	goto yy7;
	default:
		++YYCURSOR;
		goto yy9;
	}
yy7:
	c = yyt1;
	{}
yy8:
	yych = *YYCURSOR;
	switch (yych) {
	case 'b':
		yyt1 = yyt2;
		goto yy7;
	default:
		++YYCURSOR;
		yyt2 = yyt1;
		goto yy9;
	}
yy9:
	yyt1 = yyt2;
	goto yy7;
yy10:
	yych = *YYCURSOR;
	switch (yych) {
	case 'b':	goto yy5;
	default:
		++YYCURSOR;
		yyt2 = yyt1;
		goto yy9;
	}
}

tags/topsort3.i--tags--no-lookahead.re:4:3: warning: rule matches empty string [-Wmatch-empty-string]
tags/topsort3.i--tags--no-lookahead.re:3:29: warning: tag 'c' has 2nd degree of nondeterminism [-Wnondeterministic-tags]
