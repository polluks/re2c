/* Generated by re2c */

{
	YYCTYPE yych;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
	case 'a':
		YYMTAGP (yyt3);
		goto yy3;
	default:	goto yy2;
	}
yy2:
yy3:
	++YYCURSOR;
	YYMTAGP (yyt2);
	x = yyt3;
	y = yyt2;
	;
	*:=;
}
layout/013_04.i--tags.re:4:2: warning: control flow is undefined for strings that match '[\x0-\x60\x62-\xFF]', use default rule '*' [-Wundefined-control-flow]
