/* Generated by re2c */

{
	YYCTYPE yych;
	unsigned int yyaccept = 0;
	if ((YYLIMIT - YYCURSOR) < 31) YYFILL(31);
	yych = *(YYMARKER = YYCURSOR);
	switch (yych) {
	case 'a':
		yyt1 = YYCURSOR;
		goto yy3;
	case 'b':
		yyt1 = YYCURSOR;
		goto yy5;
	case 'c':
		yyt1 = YYCURSOR;
		goto yy6;
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
		yyt4 = YYCURSOR;
		goto yy7;
	case 'b':
		yyt4 = YYCURSOR;
		goto yy9;
	case 'c':
		yyt4 = YYCURSOR;
		goto yy10;
	default:	goto yy4;
	}
yy4:
	YYCURSOR = YYMARKER;
	switch (yyaccept) {
	case 0: 	goto yy2;
	case 1: 
		yyt2 = yyt3 = YYCURSOR;
		goto yy8;
	case 2: 
		yyt4 = yyt2;
		yyt2 = yyt3 = YYCURSOR;
		goto yy8;
	default:
		yyt4 = yyt3;
		yyt2 = yyt3 = YYCURSOR;
		goto yy8;
	}
yy5:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'c':	goto yy11;
	default:	goto yy4;
	}
yy6:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'a':
		yyt4 = YYCURSOR;
		goto yy7;
	case 'b':
		yyt4 = YYCURSOR;
		goto yy12;
	case 'c':
		yyt4 = YYCURSOR;
		goto yy10;
	default:	goto yy4;
	}
yy7:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'a':
		yyt2 = YYCURSOR;
		goto yy13;
	case 'b':
		yyt2 = YYCURSOR;
		goto yy14;
	case 'c':
		yyt2 = YYCURSOR;
		goto yy15;
	case 'd':
		yyt2 = yyt3 = YYCURSOR;
		goto yy16;
	default:
		yyt2 = yyt3 = YYCURSOR;
		goto yy8;
	}
yy8:
	yynmatch = 3;
	yypmatch[0] = yyt1;
	yypmatch[2] = yyt4;
	yypmatch[3] = yyt2;
	yypmatch[4] = yyt3;
	yypmatch[1] = YYCURSOR;
	yypmatch[5] = YYCURSOR;
	{}
yy9:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'a':
		yyt4 = YYCURSOR;
		goto yy7;
	case 'b':
		yyt4 = YYCURSOR;
		goto yy12;
	case 'c':
		yyt3 = YYCURSOR;
		goto yy18;
	default:	goto yy4;
	}
yy10:
	yyaccept = 1;
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case 'a':
		yyt2 = YYCURSOR;
		goto yy13;
	case 'b':
		yyt2 = YYCURSOR;
		goto yy19;
	case 'c':
		yyt2 = YYCURSOR;
		goto yy15;
	case 'd':
		yyt2 = yyt3 = YYCURSOR;
		goto yy16;
	default:
		yyt2 = yyt3 = YYCURSOR;
		goto yy8;
	}
yy11:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'd':	goto yy6;
	default:	goto yy4;
	}
yy12:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'c':	goto yy20;
	default:	goto yy4;
	}
yy13:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'a':
		yyt4 = YYCURSOR;
		goto yy21;
	case 'b':
		yyt4 = YYCURSOR;
		goto yy22;
	case 'c':
		yyt4 = YYCURSOR;
		goto yy23;
	case 'd':
		yyt4 = yyt2;
		yyt2 = yyt3 = YYCURSOR;
		goto yy16;
	default:
		yyt4 = yyt2;
		yyt2 = yyt3 = YYCURSOR;
		goto yy8;
	}
yy14:
	yyaccept = 1;
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case 'a':
		yyt2 = YYCURSOR;
		goto yy13;
	case 'b':
		yyt2 = YYCURSOR;
		goto yy19;
	case 'c':
		yyt3 = YYCURSOR;
		goto yy24;
	case 'd':
		yyt2 = yyt3 = YYCURSOR;
		goto yy16;
	default:
		yyt2 = yyt3 = YYCURSOR;
		goto yy8;
	}
yy15:
	yyaccept = 2;
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case 'a':
		yyt4 = YYCURSOR;
		goto yy21;
	case 'b':
		yyt4 = YYCURSOR;
		goto yy25;
	case 'c':
		yyt4 = YYCURSOR;
		goto yy23;
	case 'd':
		yyt4 = yyt2;
		yyt2 = yyt3 = YYCURSOR;
		goto yy16;
	default:
		yyt4 = yyt2;
		yyt2 = yyt3 = YYCURSOR;
		goto yy8;
	}
yy16:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
yy17:
	switch (yych) {
	case 'd':	goto yy16;
	default:	goto yy8;
	}
yy18:
	yyaccept = 3;
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case 'a':
		yyt2 = YYCURSOR;
		goto yy13;
	case 'b':
		yyt2 = YYCURSOR;
		goto yy19;
	case 'c':
		yyt2 = YYCURSOR;
		goto yy15;
	case 'd':	goto yy10;
	default:
		yyt4 = yyt3;
		yyt2 = yyt3 = YYCURSOR;
		goto yy8;
	}
yy19:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'c':	goto yy26;
	default:	goto yy4;
	}
yy20:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'd':	goto yy10;
	default:	goto yy4;
	}
yy21:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'a':
		yyt2 = YYCURSOR;
		goto yy27;
	case 'b':
		yyt2 = YYCURSOR;
		goto yy28;
	case 'c':
		yyt2 = YYCURSOR;
		goto yy29;
	case 'd':
		yyt2 = yyt3 = YYCURSOR;
		goto yy16;
	default:
		yyt2 = yyt3 = YYCURSOR;
		goto yy8;
	}
yy22:
	yyaccept = 2;
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case 'a':
		yyt4 = YYCURSOR;
		goto yy21;
	case 'b':
		yyt4 = YYCURSOR;
		goto yy25;
	case 'c':
		yyt3 = YYCURSOR;
		goto yy30;
	case 'd':
		yyt4 = yyt2;
		yyt2 = yyt3 = YYCURSOR;
		goto yy16;
	default:
		yyt4 = yyt2;
		yyt2 = yyt3 = YYCURSOR;
		goto yy8;
	}
yy23:
	yyaccept = 1;
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case 'a':
		yyt2 = YYCURSOR;
		goto yy27;
	case 'b':
		yyt2 = YYCURSOR;
		goto yy31;
	case 'c':
		yyt2 = YYCURSOR;
		goto yy29;
	case 'd':
		yyt2 = yyt3 = YYCURSOR;
		goto yy16;
	default:
		yyt2 = yyt3 = YYCURSOR;
		goto yy8;
	}
yy24:
	yyaccept = 3;
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case 'a':
		yyt4 = YYCURSOR;
		goto yy21;
	case 'b':
		yyt4 = YYCURSOR;
		goto yy25;
	case 'c':
		yyt4 = YYCURSOR;
		goto yy23;
	case 'd':	goto yy15;
	default:
		yyt4 = yyt3;
		yyt2 = yyt3 = YYCURSOR;
		goto yy8;
	}
yy25:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'c':	goto yy32;
	default:	goto yy4;
	}
yy26:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'd':	goto yy15;
	default:	goto yy4;
	}
yy27:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'a':
		yyt4 = YYCURSOR;
		goto yy33;
	case 'b':
		yyt4 = YYCURSOR;
		goto yy34;
	case 'c':
		yyt4 = YYCURSOR;
		goto yy35;
	case 'd':
		yyt4 = yyt2;
		yyt2 = yyt3 = YYCURSOR;
		goto yy16;
	default:
		yyt4 = yyt2;
		yyt2 = yyt3 = YYCURSOR;
		goto yy8;
	}
yy28:
	yyaccept = 1;
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case 'a':
		yyt2 = YYCURSOR;
		goto yy27;
	case 'b':
		yyt2 = YYCURSOR;
		goto yy31;
	case 'c':
		yyt3 = YYCURSOR;
		goto yy36;
	case 'd':
		yyt2 = yyt3 = YYCURSOR;
		goto yy16;
	default:
		yyt2 = yyt3 = YYCURSOR;
		goto yy8;
	}
yy29:
	yyaccept = 2;
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case 'a':
		yyt4 = YYCURSOR;
		goto yy33;
	case 'b':
		yyt4 = YYCURSOR;
		goto yy37;
	case 'c':
		yyt4 = YYCURSOR;
		goto yy35;
	case 'd':
		yyt4 = yyt2;
		yyt2 = yyt3 = YYCURSOR;
		goto yy16;
	default:
		yyt4 = yyt2;
		yyt2 = yyt3 = YYCURSOR;
		goto yy8;
	}
yy30:
	yyaccept = 3;
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case 'a':
		yyt2 = YYCURSOR;
		goto yy27;
	case 'b':
		yyt2 = YYCURSOR;
		goto yy31;
	case 'c':
		yyt2 = YYCURSOR;
		goto yy29;
	case 'd':	goto yy23;
	default:
		yyt4 = yyt3;
		yyt2 = yyt3 = YYCURSOR;
		goto yy8;
	}
yy31:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'c':	goto yy38;
	default:	goto yy4;
	}
yy32:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'd':	goto yy23;
	default:	goto yy4;
	}
yy33:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'a':
		yyt2 = YYCURSOR;
		goto yy39;
	case 'b':
		yyt2 = YYCURSOR;
		goto yy40;
	case 'c':
		yyt2 = YYCURSOR;
		goto yy41;
	case 'd':
		yyt2 = yyt3 = YYCURSOR;
		goto yy16;
	default:
		yyt2 = yyt3 = YYCURSOR;
		goto yy8;
	}
yy34:
	yyaccept = 2;
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case 'a':
		yyt4 = YYCURSOR;
		goto yy33;
	case 'b':
		yyt4 = YYCURSOR;
		goto yy37;
	case 'c':
		yyt3 = YYCURSOR;
		goto yy42;
	case 'd':
		yyt4 = yyt2;
		yyt2 = yyt3 = YYCURSOR;
		goto yy16;
	default:
		yyt4 = yyt2;
		yyt2 = yyt3 = YYCURSOR;
		goto yy8;
	}
yy35:
	yyaccept = 1;
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case 'a':
		yyt2 = YYCURSOR;
		goto yy39;
	case 'b':
		yyt2 = YYCURSOR;
		goto yy43;
	case 'c':
		yyt2 = YYCURSOR;
		goto yy41;
	case 'd':
		yyt2 = yyt3 = YYCURSOR;
		goto yy16;
	default:
		yyt2 = yyt3 = YYCURSOR;
		goto yy8;
	}
yy36:
	yyaccept = 3;
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case 'a':
		yyt4 = YYCURSOR;
		goto yy33;
	case 'b':
		yyt4 = YYCURSOR;
		goto yy37;
	case 'c':
		yyt4 = YYCURSOR;
		goto yy35;
	case 'd':	goto yy29;
	default:
		yyt4 = yyt3;
		yyt2 = yyt3 = YYCURSOR;
		goto yy8;
	}
yy37:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'c':	goto yy44;
	default:	goto yy4;
	}
yy38:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'd':	goto yy29;
	default:	goto yy4;
	}
yy39:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'a':
		yyt4 = YYCURSOR;
		goto yy45;
	case 'b':
		yyt4 = YYCURSOR;
		goto yy46;
	case 'c':
		yyt4 = YYCURSOR;
		goto yy47;
	case 'd':
		yyt4 = yyt2;
		yyt2 = yyt3 = YYCURSOR;
		goto yy16;
	default:
		yyt4 = yyt2;
		yyt2 = yyt3 = YYCURSOR;
		goto yy8;
	}
yy40:
	yyaccept = 1;
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case 'a':
		yyt2 = YYCURSOR;
		goto yy39;
	case 'b':
		yyt2 = YYCURSOR;
		goto yy43;
	case 'c':
		yyt3 = YYCURSOR;
		goto yy48;
	case 'd':
		yyt2 = yyt3 = YYCURSOR;
		goto yy16;
	default:
		yyt2 = yyt3 = YYCURSOR;
		goto yy8;
	}
yy41:
	yyaccept = 2;
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case 'a':
		yyt4 = YYCURSOR;
		goto yy45;
	case 'b':
		yyt4 = YYCURSOR;
		goto yy49;
	case 'c':
		yyt4 = YYCURSOR;
		goto yy47;
	case 'd':
		yyt4 = yyt2;
		yyt2 = yyt3 = YYCURSOR;
		goto yy16;
	default:
		yyt4 = yyt2;
		yyt2 = yyt3 = YYCURSOR;
		goto yy8;
	}
yy42:
	yyaccept = 3;
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case 'a':
		yyt2 = YYCURSOR;
		goto yy39;
	case 'b':
		yyt2 = YYCURSOR;
		goto yy43;
	case 'c':
		yyt2 = YYCURSOR;
		goto yy41;
	case 'd':	goto yy35;
	default:
		yyt4 = yyt3;
		yyt2 = yyt3 = YYCURSOR;
		goto yy8;
	}
yy43:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'c':	goto yy50;
	default:	goto yy4;
	}
yy44:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'd':	goto yy35;
	default:	goto yy4;
	}
yy45:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'a':
		yyt2 = YYCURSOR;
		goto yy51;
	case 'b':
		yyt2 = YYCURSOR;
		goto yy52;
	case 'c':
		yyt2 = YYCURSOR;
		goto yy53;
	case 'd':
		yyt2 = yyt3 = YYCURSOR;
		goto yy16;
	default:
		yyt2 = yyt3 = YYCURSOR;
		goto yy8;
	}
yy46:
	yyaccept = 2;
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case 'a':
		yyt4 = YYCURSOR;
		goto yy45;
	case 'b':
		yyt4 = YYCURSOR;
		goto yy49;
	case 'c':
		yyt3 = YYCURSOR;
		goto yy54;
	case 'd':
		yyt4 = yyt2;
		yyt2 = yyt3 = YYCURSOR;
		goto yy16;
	default:
		yyt4 = yyt2;
		yyt2 = yyt3 = YYCURSOR;
		goto yy8;
	}
yy47:
	yyaccept = 1;
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case 'a':
		yyt2 = YYCURSOR;
		goto yy51;
	case 'b':
		yyt2 = YYCURSOR;
		goto yy55;
	case 'c':
		yyt2 = YYCURSOR;
		goto yy53;
	case 'd':
		yyt2 = yyt3 = YYCURSOR;
		goto yy16;
	default:
		yyt2 = yyt3 = YYCURSOR;
		goto yy8;
	}
yy48:
	yyaccept = 3;
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case 'a':
		yyt4 = YYCURSOR;
		goto yy45;
	case 'b':
		yyt4 = YYCURSOR;
		goto yy49;
	case 'c':
		yyt4 = YYCURSOR;
		goto yy47;
	case 'd':	goto yy41;
	default:
		yyt4 = yyt3;
		yyt2 = yyt3 = YYCURSOR;
		goto yy8;
	}
yy49:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'c':	goto yy56;
	default:	goto yy4;
	}
yy50:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'd':	goto yy41;
	default:	goto yy4;
	}
yy51:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'a':
		yyt4 = YYCURSOR;
		goto yy57;
	case 'b':
		yyt4 = YYCURSOR;
		goto yy58;
	case 'c':
		yyt4 = YYCURSOR;
		goto yy59;
	case 'd':
		yyt4 = yyt2;
		yyt2 = yyt3 = YYCURSOR;
		goto yy16;
	default:
		yyt4 = yyt2;
		yyt2 = yyt3 = YYCURSOR;
		goto yy8;
	}
yy52:
	yyaccept = 1;
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case 'a':
		yyt2 = YYCURSOR;
		goto yy51;
	case 'b':
		yyt2 = YYCURSOR;
		goto yy55;
	case 'c':
		yyt3 = YYCURSOR;
		goto yy60;
	case 'd':
		yyt2 = yyt3 = YYCURSOR;
		goto yy16;
	default:
		yyt2 = yyt3 = YYCURSOR;
		goto yy8;
	}
yy53:
	yyaccept = 2;
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case 'a':
		yyt4 = YYCURSOR;
		goto yy57;
	case 'b':
		yyt4 = YYCURSOR;
		goto yy61;
	case 'c':
		yyt4 = YYCURSOR;
		goto yy59;
	case 'd':
		yyt4 = yyt2;
		yyt2 = yyt3 = YYCURSOR;
		goto yy16;
	default:
		yyt4 = yyt2;
		yyt2 = yyt3 = YYCURSOR;
		goto yy8;
	}
yy54:
	yyaccept = 3;
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case 'a':
		yyt2 = YYCURSOR;
		goto yy51;
	case 'b':
		yyt2 = YYCURSOR;
		goto yy55;
	case 'c':
		yyt2 = YYCURSOR;
		goto yy53;
	case 'd':	goto yy47;
	default:
		yyt4 = yyt3;
		yyt2 = yyt3 = YYCURSOR;
		goto yy8;
	}
yy55:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'c':	goto yy62;
	default:	goto yy4;
	}
yy56:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'd':	goto yy47;
	default:	goto yy4;
	}
yy57:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'b':	goto yy59;
	case 'd':
		yyt2 = yyt3 = YYCURSOR;
		goto yy16;
	default:
		yyt2 = yyt3 = YYCURSOR;
		goto yy8;
	}
yy58:
	yyaccept = 2;
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case 'a':
		yyt4 = YYCURSOR;
		goto yy57;
	case 'b':
		yyt4 = YYCURSOR;
		goto yy61;
	case 'c':
		yyt2 = YYCURSOR;
		goto yy63;
	case 'd':
		yyt4 = yyt2;
		yyt2 = yyt3 = YYCURSOR;
		goto yy16;
	default:
		yyt4 = yyt2;
		yyt2 = yyt3 = YYCURSOR;
		goto yy8;
	}
yy59:
	yych = *++YYCURSOR;
	yyt2 = yyt3 = YYCURSOR;
	goto yy17;
yy60:
	yyaccept = 3;
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case 'a':
		yyt4 = YYCURSOR;
		goto yy57;
	case 'b':
		yyt4 = YYCURSOR;
		goto yy61;
	case 'c':
		yyt4 = YYCURSOR;
		goto yy59;
	case 'd':	goto yy53;
	default:
		yyt4 = yyt3;
		yyt2 = yyt3 = YYCURSOR;
		goto yy8;
	}
yy61:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'c':	goto yy64;
	default:	goto yy4;
	}
yy62:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'd':	goto yy53;
	default:	goto yy4;
	}
yy63:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'd':	goto yy59;
	default:
		yyt4 = yyt2;
		yyt2 = yyt3 = YYCURSOR;
		goto yy8;
	}
yy64:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'd':	goto yy59;
	default:	goto yy4;
	}
}

posix_captures/repetition/87.i--flex-syntax.re:6:7: warning: rule matches empty string [-Wmatch-empty-string]
