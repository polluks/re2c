/* Generated by re2c */
char scan(const unsigned char *s)
{

{
	YYCTYPE yych;

	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
	case 0x07:	goto yy6;
	case 0x61:	goto yy4;
	case 0x7F:	goto yy2;
	default:	goto yy8;
	}
yy2:
	++YYCURSOR;
	{
		return '"';
	}
yy4:
	++YYCURSOR;
	{
		return '\x2F';
	}
yy6:
	++YYCURSOR;
	{
		return '\x7F';
	}
yy8:
	++YYCURSOR;
	{
		return '\0';
	}
}

}
