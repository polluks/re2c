/* Generated by re2c */
#line 1 "conditions/condition_11.cg.re"

#line 5 "conditions/condition_11.cg.c"
{
	YYCTYPE yych;
	static void *yyctable[3] = {
		&&yyc_0,
		&&yyc_r1,
		&&yyc_r2,
	};
	goto *yyctable[YYGETCONDITION()];
/* *********************************** */
yyc_0:
	YYSETCONDITION(yycr1);
#line 3 "conditions/condition_11.cg.re"
	{ return NULL; }
#line 19 "conditions/condition_11.cg.c"
/* *********************************** */
yyc_r1:
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= '2') {
		if (yych <= '0') goto yy6;
		if (yych <= '1') goto yy7;
		goto yy9;
	} else {
		if (yych <= '`') goto yy6;
		if (yych <= 'a') goto yy11;
		if (yych <= 'b') goto yy13;
	}
yy6:
yy7:
	++YYCURSOR;
#line 4 "conditions/condition_11.cg.re"
	{ return "1"; }
#line 38 "conditions/condition_11.cg.c"
yy9:
	++YYCURSOR;
#line 5 "conditions/condition_11.cg.re"
	{ return "2"; }
#line 43 "conditions/condition_11.cg.c"
yy11:
	++YYCURSOR;
	YYSETCONDITION(yycr2);
#line 6 "conditions/condition_11.cg.re"
	{ return "a"; }
#line 49 "conditions/condition_11.cg.c"
yy13:
	++YYCURSOR;
	YYSETCONDITION(yycr2);
#line 7 "conditions/condition_11.cg.re"
	{ return "b"; }
#line 55 "conditions/condition_11.cg.c"
/* *********************************** */
yyc_r2:
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= '2') {
		if (yych <= '0') goto yy17;
		if (yych <= '1') goto yy18;
		goto yy20;
	} else {
		if (yych == 'b') goto yy22;
	}
yy17:
yy18:
	++YYCURSOR;
	YYSETCONDITION(yycr1);
#line 4 "conditions/condition_11.cg.re"
	{ return "1"; }
#line 73 "conditions/condition_11.cg.c"
yy20:
	++YYCURSOR;
	YYSETCONDITION(yycr1);
#line 5 "conditions/condition_11.cg.re"
	{ return "2"; }
#line 79 "conditions/condition_11.cg.c"
yy22:
	++YYCURSOR;
#line 7 "conditions/condition_11.cg.re"
	{ return "b"; }
#line 84 "conditions/condition_11.cg.c"
}
#line 9 "conditions/condition_11.cg.re"

conditions/condition_11.cg.re:9:2: warning: control flow in condition 'r1' is undefined for strings that match '[\x0-\x30\x33-\x60\x63-\xFF]', use default rule '*' [-Wundefined-control-flow]
conditions/condition_11.cg.re:9:2: warning: control flow in condition 'r2' is undefined for strings that match '[\x0-\x30\x33-\x61\x63-\xFF]', use default rule '*' [-Wundefined-control-flow]
conditions/condition_11.cg.re:9:2: warning: looks like you use hardcoded numbers instead of autogenerated condition names: better add '/*!types:re2c*/' directive or '-t, --type-header' option and don't rely on fixed condition order. [-Wcondition-order]
