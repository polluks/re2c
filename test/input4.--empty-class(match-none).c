/* Generated by re2c */
#line 1 "input4.--empty-class(match-none).re"

#line 5 "input4.--empty-class(match-none).c"
{
	YYCTYPE yych;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR++;
#line 4 "input4.--empty-class(match-none).re"
	{ return 1; }
#line 12 "input4.--empty-class(match-none).c"
}
#line 7 "input4.--empty-class(match-none).re"

input4.--empty-class(match-none).re:3:0: warning: empty character class [-Wempty-character-class]
input4.--empty-class(match-none).re:3:5: warning: unreachable rule  [-Wunreachable-rules]
input4.--empty-class(match-none).re:5:12: warning: unreachable rule (shadowed by rule at line 4) [-Wunreachable-rules]
