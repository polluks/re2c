/* Generated by re2c */

#include <stddef.h> /* size_t */
#include <stdio.h>
#include <stdlib.h> /* malloc, free */
#include <string.h> /* memcpy */

static void *read_file
    ( const char *fname
    , size_t unit
    , size_t padding
    , size_t *pfsize
    )
{
    void *buffer = NULL;
    size_t fsize = 0;

    /* open file */
    FILE *f = fopen(fname, "rb");
    if(f == NULL) {
        goto error;
    }

    /* get file size */
    fseek(f, 0, SEEK_END);
    fsize = (size_t) ftell(f) / unit;
    fseek(f, 0, SEEK_SET);

    /* allocate memory for file and padding */
    buffer = malloc(unit * (fsize + padding));
    if (buffer == NULL) {
        goto error;
    }

    /* read the whole file in memory */
    if (fread(buffer, unit, fsize, f) != fsize) {
        goto error;
    }

    fclose(f);
    *pfsize = fsize;
    return buffer;

error:
    fprintf(stderr, "error: cannot read file '%s'\n", fname);
    free(buffer);
    if (f != NULL) {
        fclose(f);
    }
    return NULL;
}

#define YYCTYPE unsigned char
#define YYKEYTYPE unsigned char
#define YYPEEK() *cursor
#define YYSKIP() ++cursor
#define YYBACKUP() marker = cursor
#define YYRESTORE() cursor = marker
#define YYLESSTHAN(n) (limit - cursor) < n
#define YYFILL(n) { break; }

static int action_line108
    ( unsigned *pkix
    , const YYKEYTYPE *keys
    , const YYCTYPE *start
    , const YYCTYPE *token
    , const YYCTYPE **cursor
    , YYKEYTYPE rule_act
    )
{
    const unsigned kix = *pkix;
    const long pos = token - start;
    const long len_act = *cursor - token;
    const long len_exp = (long) keys[kix + 1];
    const YYKEYTYPE rule_exp = keys[kix + 2];
    *pkix = kix + 3;
    if (rule_exp == 255) {
        fprintf
            ( stderr
            , "warning: lex_line108: control flow is undefined for input"
                " at position %ld, rerun re2c with '-W'\n"
            , pos
            );
    }
    if (len_act == len_exp && rule_act == rule_exp) {
        const YYKEYTYPE offset = keys[kix];
        *cursor = token + offset;
        return 0;
    } else {
        fprintf
            ( stderr
            , "error: lex_line108: at position %ld (key %u):\n"
                "\texpected: match length %ld, rule %u\n"
                "\tactual:   match length %ld, rule %u\n"
            , pos
            , kix
            , len_exp
            , rule_exp
            , len_act
            , rule_act
            );
        return 1;
    }
}

static int check_key_count_line108(unsigned have, unsigned used, unsigned need)
{
    if (used + need <= have) return 0;
    fprintf(stderr, "error: lex_line108: not enough keys\n");
    return 1;
}

int lex_line108()
{
    const size_t padding = 4; /* YYMAXFILL */
    int status = 0;
    size_t input_len = 0;
    size_t keys_count = 0;
    YYCTYPE *input = NULL;
    YYKEYTYPE *keys = NULL;
    const YYCTYPE *cursor = NULL;
    const YYCTYPE *limit = NULL;
    const YYCTYPE *token = NULL;
    const YYCTYPE *eof = NULL;
    unsigned int i = 0;

    input = (YYCTYPE *) read_file
        ("php/php20150211_phar_path_check.ig--skeleton.c.line108.input"
        , sizeof (YYCTYPE)
        , padding
        , &input_len
        );
    if (input == NULL) {
        status = 1;
        goto end;
    }

    keys = (YYKEYTYPE *) read_file
        ("php/php20150211_phar_path_check.ig--skeleton.c.line108.keys"
        , sizeof (YYKEYTYPE)
        , 0
        , &keys_count
        );
    if (keys == NULL) {
        status = 1;
        goto end;
    }

    cursor = input;
    limit = input + input_len + padding;
    eof = input + input_len;

    for (i = 0; status == 0 && cursor < eof && i < keys_count;) {
        token = cursor;
        const YYCTYPE *marker = NULL;
        YYCTYPE yych;
        unsigned int yyaccept = 0;

        if (YYLESSTHAN (4)) YYFILL(4);
        yych = YYPEEK ();
        {
            static void *yytarget[256] = {
                &&yy3,  &&yy5,  &&yy5,  &&yy5,  &&yy5,  &&yy5,  &&yy5,  &&yy5,
                &&yy5,  &&yy5,  &&yy2,  &&yy5,  &&yy5,  &&yy5,  &&yy5,  &&yy5,
                &&yy5,  &&yy5,  &&yy5,  &&yy5,  &&yy5,  &&yy5,  &&yy5,  &&yy5,
                &&yy5,  &&yy5,  &&yy7,  &&yy7,  &&yy7,  &&yy7,  &&yy7,  &&yy7,
                &&yy7,  &&yy7,  &&yy7,  &&yy7,  &&yy7,  &&yy7,  &&yy7,  &&yy7,
                &&yy7,  &&yy7,  &&yy9,  &&yy7,  &&yy7,  &&yy7,  &&yy7,  &&yy11,
                &&yy7,  &&yy7,  &&yy7,  &&yy7,  &&yy7,  &&yy7,  &&yy7,  &&yy7,
                &&yy7,  &&yy7,  &&yy7,  &&yy7,  &&yy7,  &&yy7,  &&yy7,  &&yy12,
                &&yy7,  &&yy7,  &&yy7,  &&yy7,  &&yy7,  &&yy7,  &&yy7,  &&yy7,
                &&yy7,  &&yy7,  &&yy7,  &&yy7,  &&yy7,  &&yy7,  &&yy7,  &&yy7,
                &&yy7,  &&yy7,  &&yy7,  &&yy7,  &&yy7,  &&yy7,  &&yy7,  &&yy7,
                &&yy7,  &&yy7,  &&yy7,  &&yy7,  &&yy14, &&yy7,  &&yy7,  &&yy7,
                &&yy7,  &&yy7,  &&yy7,  &&yy7,  &&yy7,  &&yy7,  &&yy7,  &&yy7,
                &&yy7,  &&yy7,  &&yy7,  &&yy7,  &&yy7,  &&yy7,  &&yy7,  &&yy7,
                &&yy7,  &&yy7,  &&yy7,  &&yy7,  &&yy7,  &&yy7,  &&yy7,  &&yy7,
                &&yy7,  &&yy7,  &&yy7,  &&yy7,  &&yy7,  &&yy7,  &&yy7,  &&yy7,
                &&yy5,  &&yy5,  &&yy5,  &&yy5,  &&yy5,  &&yy5,  &&yy5,  &&yy5,
                &&yy5,  &&yy5,  &&yy5,  &&yy5,  &&yy5,  &&yy5,  &&yy5,  &&yy5,
                &&yy5,  &&yy5,  &&yy5,  &&yy5,  &&yy5,  &&yy5,  &&yy5,  &&yy5,
                &&yy5,  &&yy5,  &&yy5,  &&yy5,  &&yy5,  &&yy5,  &&yy5,  &&yy5,
                &&yy5,  &&yy5,  &&yy5,  &&yy5,  &&yy5,  &&yy5,  &&yy5,  &&yy5,
                &&yy5,  &&yy5,  &&yy5,  &&yy5,  &&yy5,  &&yy5,  &&yy5,  &&yy5,
                &&yy5,  &&yy5,  &&yy5,  &&yy5,  &&yy5,  &&yy5,  &&yy5,  &&yy5,
                &&yy5,  &&yy5,  &&yy5,  &&yy5,  &&yy5,  &&yy5,  &&yy5,  &&yy5,
                &&yy5,  &&yy5,  &&yy16, &&yy16, &&yy16, &&yy16, &&yy16, &&yy16,
                &&yy16, &&yy16, &&yy16, &&yy16, &&yy16, &&yy16, &&yy16, &&yy16,
                &&yy16, &&yy16, &&yy16, &&yy16, &&yy16, &&yy16, &&yy16, &&yy16,
                &&yy16, &&yy16, &&yy16, &&yy16, &&yy16, &&yy16, &&yy16, &&yy16,
                &&yy17, &&yy18, &&yy18, &&yy18, &&yy18, &&yy18, &&yy18, &&yy18,
                &&yy18, &&yy18, &&yy18, &&yy18, &&yy18, &&yy19, &&yy18, &&yy18,
                &&yy20, &&yy21, &&yy21, &&yy21, &&yy22, &&yy5,  &&yy5,  &&yy5,
                &&yy5,  &&yy5,  &&yy5,  &&yy5,  &&yy5,  &&yy5,  &&yy5,  &&yy5
            };
            goto *yytarget[yych];
        }
yy2:
        YYRESTORE ();
        if (yyaccept == 0) {
            goto yy8;
        } else {
            goto yy6;
        }
yy3:
        YYSKIP ();
        status = check_key_count_line108(keys_count, i, 3)
             || action_line108(&i, keys, input, token, &cursor, 7);
        continue;
yy5:
        YYSKIP ();
yy6:
        status = check_key_count_line108(keys_count, i, 3)
             || action_line108(&i, keys, input, token, &cursor, 8);
        continue;
yy7:
        YYSKIP ();
yy8:
        status = check_key_count_line108(keys_count, i, 3)
             || action_line108(&i, keys, input, token, &cursor, 6);
        continue;
yy9:
        YYSKIP ();
        status = check_key_count_line108(keys_count, i, 3)
             || action_line108(&i, keys, input, token, &cursor, 4);
        continue;
yy11:
        yyaccept = 0;
        YYSKIP ();
        YYBACKUP ();
        yych = YYPEEK ();
        if (yych <= '-') goto yy8;
        if (yych <= '.') goto yy23;
        if (yych <= '/') goto yy24;
        goto yy8;
yy12:
        YYSKIP ();
        status = check_key_count_line108(keys_count, i, 3)
             || action_line108(&i, keys, input, token, &cursor, 5);
        continue;
yy14:
        YYSKIP ();
        status = check_key_count_line108(keys_count, i, 3)
             || action_line108(&i, keys, input, token, &cursor, 3);
        continue;
yy16:
        YYSKIP ();
        yych = YYPEEK ();
        if (yych <= 0x7F) goto yy6;
        if (yych <= 0xBF) goto yy7;
        goto yy6;
yy17:
        yyaccept = 1;
        YYSKIP ();
        YYBACKUP ();
        yych = YYPEEK ();
        if (yych <= 0x9F) goto yy6;
        if (yych <= 0xBF) goto yy26;
        goto yy6;
yy18:
        yyaccept = 1;
        YYSKIP ();
        YYBACKUP ();
        yych = YYPEEK ();
        if (yych <= 0x7F) goto yy6;
        if (yych <= 0xBF) goto yy26;
        goto yy6;
yy19:
        yyaccept = 1;
        YYSKIP ();
        YYBACKUP ();
        yych = YYPEEK ();
        if (yych <= 0x7F) goto yy6;
        if (yych <= 0x9F) goto yy26;
        goto yy6;
yy20:
        yyaccept = 1;
        YYSKIP ();
        YYBACKUP ();
        yych = YYPEEK ();
        if (yych <= 0x8F) goto yy6;
        if (yych <= 0xBF) goto yy27;
        goto yy6;
yy21:
        yyaccept = 1;
        YYSKIP ();
        YYBACKUP ();
        yych = YYPEEK ();
        if (yych <= 0x7F) goto yy6;
        if (yych <= 0xBF) goto yy27;
        goto yy6;
yy22:
        yyaccept = 1;
        YYSKIP ();
        YYBACKUP ();
        yych = YYPEEK ();
        if (yych <= 0x7F) goto yy6;
        if (yych <= 0x8F) goto yy27;
        goto yy6;
yy23:
        YYSKIP ();
        yych = YYPEEK ();
        if (yych <= 0x00) goto yy28;
        if (yych <= '-') goto yy2;
        if (yych <= '.') goto yy30;
        if (yych <= '/') goto yy28;
        goto yy2;
yy24:
        YYSKIP ();
        status = check_key_count_line108(keys_count, i, 3)
             || action_line108(&i, keys, input, token, &cursor, 0);
        continue;
yy26:
        YYSKIP ();
        yych = YYPEEK ();
        if (yych <= 0x7F) goto yy2;
        if (yych <= 0xBF) goto yy7;
        goto yy2;
yy27:
        YYSKIP ();
        yych = YYPEEK ();
        if (yych <= 0x7F) goto yy2;
        if (yych <= 0xBF) goto yy26;
        goto yy2;
yy28:
        YYSKIP ();
        status = check_key_count_line108(keys_count, i, 3)
             || action_line108(&i, keys, input, token, &cursor, 2);
        continue;
yy30:
        YYSKIP ();
        yych = YYPEEK ();
        if (yych <= 0x00) goto yy31;
        if (yych != '/') goto yy2;
yy31:
        YYSKIP ();
        status = check_key_count_line108(keys_count, i, 3)
             || action_line108(&i, keys, input, token, &cursor, 1);
        continue;

    }
    if (status == 0) {
        if (cursor != eof) {
            status = 1;
            const long pos = token - input;
            fprintf(stderr, "error: lex_line108: unused input strings left at position %ld\n", pos);
        }
        if (i != keys_count) {
            status = 1;
            fprintf(stderr, "error: lex_line108: unused keys left after %u keys\n", i);
        }
    }

end:
    free(input);
    free(keys);

    return status;
}

#undef YYCTYPE
#undef YYKEYTYPE
#undef YYPEEK
#undef YYSKIP
#undef YYBACKUP
#undef YYRESTORE
#undef YYLESSTHAN
#undef YYFILL

int main()
{
    if(lex_line108() != 0) {
        return 1;
    }
    return 0;
}
 	����������������������������������������������������������������������������� !"#$%&'()+,-.0123456789:;<=>@ABCDEFGHIJKLMNOPQRSTUVWXYZ[]^_`abcdefghijklmnopqrstuvwxyz{|}~*/. /.//.. /..//../../../../../../../../..	/..
/../../../../../../../../../../../../../../../../../../../../../.. /..!/.."/..#/..$/..%/..&/..'/..(/..)/..*/..+/..,/..-/.../..0/..1/..2/..3/..4/..5/..6/..7/..8/..9/..:/..;/..</..=/..>/..?/..@/..A/..B/..C/..D/..E/..F/..G/..H/..I/..J/..K/..L/..M/..N/..O/..P/..Q/..R/..S/..T/..U/..V/..W/..X/..Y/..Z/..[/..\/..]/..^/.._/..`/..a/..b/..c/..d/..e/..f/..g/..h/..i/..j/..k/..l/..m/..n/..o/..p/..q/..r/..s/..t/..u/..v/..w/..x/..y/..z/..{/..|/..}/..~/../..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/..�/././././././././.	/.
/./././././././././././././././././././././. /.!/."/.#/.$/.%/.&/.'/.(/.)/.*/.+/.,/.-/.0/.1/.2/.3/.4/.5/.6/.7/.8/.9/.:/.;/.</.=/.>/.?/.@/.A/.B/.C/.D/.E/.F/.G/.H/.I/.J/.K/.L/.M/.N/.O/.P/.Q/.R/.S/.T/.U/.V/.W/.X/.Y/.Z/.[/.\/.]/.^/._/.`/.a/.b/.c/.d/.e/.f/.g/.h/.i/.j/.k/.l/.m/.n/.o/.p/.q/.r/.s/.t/.u/.v/.w/.x/.y/.z/.{/.|/.}/.~/./.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/.�/// /////////	/
////////////////////// /!/"/#/$/%/&/'/(/)/*/+/,/-/0/1/2/3/4/5/6/7/8/9/:/;/</=/>/?/@/A/B/C/D/E/F/G/H/I/J/K/L/M/N/O/P/Q/R/S/T/U/V/W/X/Y/Z/[/\/]/^/_/`/a/b/c/d/e/f/g/h/i/j/k/l/m/n/o/p/q/r/s/t/u/v/w/x/y/z/{/|/}/~//�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�/�?\ÁĂŃƄǅȆɇʈˉ̊͋ΌύЎяҐӑԒՓ֔וؖٗژۙܚݛޜߝßĠšƢǣȤɥʦ˧̨ͩΪϫЬѭҮӯ԰ձֲ׳شٵڶ۷ܸݹ޺߻¼ýľſ� ���������	�
���������������������� �!�"�#�$�%�&�'�(�)�*�+�,�-�.�/�0�1�2�3�4�5�6�7�8�9�:�;�<�=�>�?�@�A�B�C�D�E�F�G�H�I�J�K�L�M�N�O�P�Q�R�S�T�U�V�W�X�Y�Z�[�\�]�^�_�`�a�b�c�d�e�f�g�h�i�j�k�l�m�n�o�p�q�r�s�t�u�v�w�x�y�z�{�|�}�~���������������������������������������������������������������������������������������������������������������������������������ࠀࡁࢂࣃऄॅআেਈ੉ઊોଌ୍எ௏ఐ౑ಒ೓ഔൕඖ෗ธ๙ບ໛༜ཝྞ࿟ࠠࡡࢢࣣत॥দ১ਨ੩પ૫ବ୭ம௯ర౱ಲೳഴ൵බ෷ุ๹຺໻༼ཽ྾࿿� ���������	�
���������������������� �!�"�#�$�%�&�'�(�)�*�+�,�-�.�/�0�1�2�3�4�5�6�7�8�9�:�;�<�=�>�?�@�A�B�C�D�E�F�G�H�I�J�K�L�M�N�O�P�Q�R�S�T�U�V�W�X�Y�Z�[�\�]�^�_�`�a�b�c�d�e�f�g�h�i�j�k�l�m�n�o�p�q�r�s�t�u�v�w�x�y�z�{�|�}�~���������������������������������������������������������������������������������������������������������������������������������� ���������	�
���������������������� �!�"�#�$�%�&�'�(�)�*�+�,�-�.�/�0�1�2�3�4�5�6�7�8�9�:�;�<�=�>�?�@�A�B�C�D�E�F�G�H�I�J�K�L�M�N�O�P�Q�R�S�T�U�V�W�X�Y�Z�[�\�]�^�_�`�a�b�c�d�e�f�g�h�i�j�k�l�m�n�o�p�q�r�s�t�u�v�w�x�y�z�{�|�}�~�������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������က⁁も䃃億慅熆臇鈈ꉉ늊싋ጌ⍍㎎䏏吐摑璒蓓锔ꕕ떖엗ᘘ♙㚚䛛圜杝瞞蟟頠ꡡ뢢죣ᤤ⥥㦦䧧娨橩窪諫鬬꭭뮮쯯ᰰⱱ㲲䳳崴浵綶跷鸸깹뺺컻Ἴ⽽㾾俿� ���������	�
���������������������� �!�"�#�$�%�&�'�(�)�*�+�,�-�.�/�0�1�2�3�4�5�6�7�8�9�:�;�<�=�>�?�@�A�B�C�D�E�F�G�H�I�J�K�L�M�N�O�P�Q�R�S�T�U�V�W�X�Y�Z�[�\�]�^�_�`�a�b�c�d�e�f�g�h�i�j�k�l�m�n�o�p�q�r�s�t�u�v�w�x�y�z�{�|�}�~���������������������������������������������������������������������������������������������������������������������������������� ���������	�
���������������������� �!�"�#�$�%�&�'�(�)�*�+�,�-�.�/�0�1�2�3�4�5�6�7�8�9�:�;�<�=�>�?�@�A�B�C�D�E�F�G�H�I�J�K�L�M�N�O�P�Q�R�S�T�U�V�W�X�Y�Z�[�\�]�^�_�`�a�b�c�d�e�f�g�h�i�j�k�l�m�n�o�p�q�r�s�t�u�v�w�x�y�z�{�|�}�~���������������������������������������������������������������������������������������������������������������������������������퀀큁킂탃턄텅톆퇇툈퉉튊틋파퍍펎폏퐐푑풒퓓픔핕햖헗혘홙횚훛휜흝힞ퟟ퀠큡킢탣턤텥톦퇧툨퉩튪틫팬퍭펮폯퐰푱풲퓳픴핵햶헷호홹횺훻휼흽ힾ퟿� ���������	�
���������������������� �!�"�#�$�%�&�'�(�)�*�+�,�-�.�/�0�1�2�3�4�5�6�7�8�9�:�;�<�=�>�?�@�A�B�C�D�E�F�G�H�I�J�K�L�M�N�O�P�Q�R�S�T�U�V�W�X�Y�Z�[�\�]�^�_�`�a�b�c�d�e�f�g�h�i�j�k�l�m�n�o�p�q�r�s�t�u�v�w�x�y�z�{�|�}�~���������������������������������������������������������������������������������������������������������������������������������� ���������	�
���������������������� �!�"�#�$�%�&�'�(�)�*�+�,�-�.�/�0�1�2�3�4�5�6�7�8�9�:�;�<�=�>�?�@�A�B�C�D�E�F�G�H�I�J�K�L�M�N�O�P�Q�R�S�T�U�V�W�X�Y�Z�[�\�]�^�_�`�a�b�c�d�e�f�g�h�i�j�k�l�m�n�o�p�q�r�s�t�u�v�w�x�y�z�{�|�}�~�������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������便裏響﫫ﭭﯯﱱﳳﵵﷷﹹﻻｽ￿� ���������	�
���������������������� �!�"�#�$�%�&�'�(�)�*�+�,�-�.�/�0�1�2�3�4�5�6�7�8�9�:�;�<�=�>�?�@�A�B�C�D�E�F�G�H�I�J�K�L�M�N�O�P�Q�R�S�T�U�V�W�X�Y�Z�[�\�]�^�_�`�a�b�c�d�e�f�g�h�i�j�k�l�m�n�o�p�q�r�s�t�u�v�w�x�y�z�{�|�}�~���������������������������������������������������������������������������������������������������������������������������������� ���������	�
���������������������� �!�"�#�$�%�&�'�(�)�*�+�,�-�.�/�0�1�2�3�4�5�6�7�8�9�:�;�<�=�>�?�@�A�B�C�D�E�F�G�H�I�J�K�L�M�N�O�P�Q�R�S�T�U�V�W�X�Y�Z�[�\�]�^�_�`�a�b�c�d�e�f�g�h�i�j�k�l�m�n�o�p�q�r�s�t�u�v�w�x�y�z�{�|�}�~���������������������������������������������������������������������������������������������������������������������������������𐀀𑁁𒂂𓃃𔄄𕅅𖆆𗇇𘈈𙉉𚊊𛋋𜌌𝍍𞎎🏏𠐐𡑑𢒒𣓓𤔔𥕕𦖖𧗗𨘘𩙙𪚚𫛛𬜜𭝝𮞞𯟟𰠠𱡡𲢢𳣣𴤤𵥥𶦦𷧧𸨨𹩩𺪪𻫫𼬬𽭭𾮮𿯯𐰰𑱱𒲲𓳳𔴴𕵵𖶶𗷷𘸸𙹹𚺺𛻻𜼼𝽽𞾾🿿� ���������	�
���������������������� �!�"�#�$�%�&�'�(�)�*�+�,�-�.�/�0�1�2�3�4�5�6�7�8�9�:�;�<�=�>�?�@�A�B�C�D�E�F�G�H�I�J�K�L�M�N�O�P�Q�R�S�T�U�V�W�X�Y�Z�[�\�]�^�_�`�a�b�c�d�e�f�g�h�i�j�k�l�m�n�o�p�q�r�s�t�u�v�w�x�y�z�{�|�}�~���������������������������������������������������������������������������������������������������������������������������������� ���������	�
���������������������� �!�"�#�$�%�&�'�(�)�*�+�,�-�.�/�0�1�2�3�4�5�6�7�8�9�:�;�<�=�>�?�@�A�B�C�D�E�F�G�H�I�J�K�L�M�N�O�P�Q�R�S�T�U�V�W�X�Y�Z�[�\�]�^�_�`�a�b�c�d�e�f�g�h�i�j�k�l�m�n�o�p�q�r�s�t�u�v�w�x�y�z�{�|�}�~���������������������������������������������������������������������������������������������������������������������������������� ���������	�
���������������������� �!�"�#�$�%�&�'�(�)�*�+�,�-�.�/�0�1�2�3�4�5�6�7�8�9�:�;�<�=�>�?�@�A�B�C�D�E�F�G�H�I�J�K�L�M�N�O�P�Q�R�S�T�U�V�W�X�Y�Z�[�\�]�^�_�`�a�b�c�d�e�f�g�h�i�j�k�l�m�n�o�p�q�r�s�t�u�v�w�x�y�z�{�|�}�~�����������������������������������������������������������������������������������������������������������������������������������������������������������������񀀀򁁁󂂂񃃃򄄄󅅅񆆆򇇇󈈈񉉉򊊊󋋋񌌌򍍍󎎎񏏏򐐐󑑑񒒒򓓓󔔔񕕕򖖖󗗗񘘘򙙙󚚚񛛛򜜜󝝝񞞞򟟟󠠠񡡡򢢢󣣣񤤤򥥥󦦦񧧧򨨨󩩩񪪪򫫫󬬬񭭭򮮮󯯯񰰰򱱱󲲲񳳳򴴴󵵵񶶶򷷷󸸸񹹹򺺺󻻻񼼼򽽽󾾾񿿿� ���������	�
���������������������� �!�"�#�$�%�&�'�(�)�*�+�,�-�.�/�0�1�2�3�4�5�6�7�8�9�:�;�<�=�>�?�@�A�B�C�D�E�F�G�H�I�J�K�L�M�N�O�P�Q�R�S�T�U�V�W�X�Y�Z�[�\�]�^�_�`�a�b�c�d�e�f�g�h�i�j�k�l�m�n�o�p�q�r�s�t�u�v�w�x�y�z�{�|�}�~���������������������������������������������������������������������������������������������������������������������������������� ���������	�
���������������������� �!�"�#�$�%�&�'�(�)�*�+�,�-�.�/�0�1�2�3�4�5�6�7�8�9�:�;�<�=�>�?�@�A�B�C�D�E�F�G�H�I�J�K�L�M�N�O�P�Q�R�S�T�U�V�W�X�Y�Z�[�\�]�^�_�`�a�b�c�d�e�f�g�h�i�j�k�l�m�n�o�p�q�r�s�t�u�v�w�x�y�z�{�|�}�~���������������������������������������������������������������������������������������������������������������������������������� ���������	�
���������������������� �!�"�#�$�%�&�'�(�)�*�+�,�-�.�/�0�1�2�3�4�5�6�7�8�9�:�;�<�=�>�?�@�A�B�C�D�E�F�G�H�I�J�K�L�M�N�O�P�Q�R�S�T�U�V�W�X�Y�Z�[�\�]�^�_�`�a�b�c�d�e�f�g�h�i�j�k�l�m�n�o�p�q�r�s�t�u�v�w�x�y�z�{�|�}�~���������������������������������������������������������������������������������������������������������������������������������􀀀􁁁􂂂􃃃􄄄􅅅􆆆􇇇􈈈􉉉􊊊􋋋􌌌􍍍􎎎􏏏􀐐􁑑􂒒􃓓􄔔􅕕􆖖􇗗􈘘􉙙􊚚􋛛􌜜􍝝􎞞􏟟􀠠􁡡􂢢􃣣􄤤􅥥􆦦􇧧􈨨􉩩􊪪􋫫􌬬􍭭􎮮􏯯􀰰􁱱􂲲􃳳􄴴􅵵􆶶􇷷􈸸􉹹􊺺􋻻􌼼􍽽􎾾􏿿� ���������	�
���������������������� �!�"�#�$�%�&�'�(�)�*�+�,�-�.�/�0�1�2�3�4�5�6�7�8�9�:�;�<�=�>�?�@�A�B�C�D�E�F�G�H�I�J�K�L�M�N�O�P�Q�R�S�T�U�V�W�X�Y�Z�[�\�]�^�_�`�a�b�c�d�e�f�g�h�i�j�k�l�m�n�o�p�q�r�s�t�u�v�w�x�y�z�{�|�}�~���������������������������������������������������������������������������������������������������������������������������������� ���������	�
���������������������� �!�"�#�$�%�&�'�(�)�*�+�,�-�.�/�0�1�2�3�4�5�6�7�8�9�:�;�<�=�>�?�@�A�B�C�D�E�F�G�H�I�J�K�L�M�N�O�P�Q�R�S�T�U�V�W�X�Y�Z�[�\�]�^�_�`�a�b�c�d�e�f�g�h�i�j�k�l�m�n�o�p�q�r�s�t�u�v�w�x�y�z�{�|�}�~���������������������������������������������������������������������������������������������������������������������������������� ���������	�
���������������������� �!�"�#�$�%�&�'�(�)�*�+�,�-�.�/�0�1�2�3�4�5�6�7�8�9�:�;�<�=�>�?�@�A�B�C�D�E�F�G�H�I�J�K�L�M�N�O�P�Q�R�S�T�U�V�W�X�Y�Z�[�\�]�^�_�`�a�b�c�d�e�f�g�h�i�j�k�l�m�n�o�p�q�r�s�t�u�v�w�x�y�z�{�|�}�~���������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������
  �php/php20150211_phar_path_check.ig--skeleton.re:108:2: warning: control flow is undefined for strings that match '\xA', use default rule '*' [-Wundefined-control-flow]
