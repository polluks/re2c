/* Generated by re2c */
#line 1 "conditions/condtype.cstcondtype.cs.h.re"
int main ()
{
	YYCONDTYPE cond;
	char * YYCURSOR;
#define YYGETCONDITION() cond

#line 10 "conditions/condtype.cstcondtype.cs.h.c"
{
	unsigned char yych;
	if (YYGETCONDITION() < 1) {
		goto yyc_a;
	} else {
		goto yyc_b;
	}
/* *********************************** */
yyc_a:
	yych = *YYCURSOR;
	if (yych == 'a') goto yy4;
yy4:
	++YYCURSOR;
#line 9 "conditions/condtype.cstcondtype.cs.h.re"
	{}
#line 26 "conditions/condtype.cstcondtype.cs.h.c"
/* *********************************** */
yyc_b:
	yych = *YYCURSOR;
	if (yych == 'b') goto yy9;
yy9:
	++YYCURSOR;
#line 10 "conditions/condtype.cstcondtype.cs.h.re"
	{}
#line 35 "conditions/condtype.cstcondtype.cs.h.c"
}
#line 11 "conditions/condtype.cstcondtype.cs.h.re"

	return 0;
}
conditions/condtype.cstcondtype.cs.h.re:11:2: warning: control flow in condition 'a' is undefined for strings that match '[\x0-\x60\x62-\xFF]', use default rule '*' [-Wundefined-control-flow]
conditions/condtype.cstcondtype.cs.h.re:11:2: warning: control flow in condition 'b' is undefined for strings that match '[\x0-\x61\x63-\xFF]', use default rule '*' [-Wundefined-control-flow]
/* Generated by re2c */

enum YYCONDTYPE {
	yyca,
	yycb,
};
