/* A Bison parser, made by GNU Bison 2.4.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006,
   2009, 2010 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */



#include "src/util/c99_stdint.h"
#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include <limits>
#include <list>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

#include "src/codegen/output.h"
#include "src/conf/opt.h"
#include "src/globals.h"
#include "src/ir/compile.h"
#include "src/ir/adfa/adfa.h"
#include "src/ir/regexp/encoding/enc.h"
#include "src/ir/regexp/encoding/range_suffix.h"
#include "src/ir/regexp/regexp.h"
#include "src/ir/skeleton/skeleton.h"
#include "src/parse/code.h"
#include "src/parse/extop.h"
#include "src/parse/loc.h"
#include "src/parse/parser.h"
#include "src/parse/scanner.h"
#include "src/parse/spec.h"
#include "src/util/free_list.h"
#include "src/util/range.h"
#include "src/util/smart_ptr.h"

#define YYMALLOC malloc
#define YYFREE free

using namespace re2c;

extern "C"
{
int yylex();
void yyerror(const char*);
}

static std::vector<std::string> condnames;
static re2c::SpecMap  specMap;
static Spec spec;
static RegExpRule *specNone = NULL;
static Spec specStar;
static Scanner          *in = NULL;
static Scanner::ParseMode  parseMode;
static SetupMap            ruleSetupMap;
static bool                foundRules;
static symbol_table_t symbol_table;

/* Bison version 1.875 emits a definition that is not working
 * with several g++ version. Hence we disable it here.
 */
#if defined(__GNUC__)
#define __attribute__(x)
#endif

void context_check(CondList *clist)
{
	if (!opts->cFlag)
	{
		delete clist;
		in->fatal("conditions are only allowed when using -c switch");
	}
}

void context_rule(
	CondList *clist,
	const Loc &loc,
	RegExpRule *rule,
	const Code *code,
	const std::string *newcond)
{
	context_check(clist);
	rule->info = new RuleInfo(loc, code, newcond);
	for(CondList::const_iterator i = clist->begin(); i != clist->end(); ++i) {
		const std::string &cond = *i;
		if (specMap.find(cond) == specMap.end()) {
			condnames.push_back(cond);
		}
		specMap[cond].add(rule);
	}
	delete clist;
	delete newcond;
}

void setup_rule(CondList *clist, const Code * code)
{
	assert(clist);
	assert(code);
	context_check(clist);
	for(CondList::const_iterator it = clist->begin(); it != clist->end(); ++it)
	{
		if (ruleSetupMap.find(*it) != ruleSetupMap.end())
		{
			in->fatalf_at(code->loc.line, "code to setup rule '%s' is already defined", it->c_str());
		}
		ruleSetupMap[*it] = std::make_pair(code->loc.line, code->text);
	}
	delete clist;
}

void default_rule(CondList *clist, RegExpRule *rule)
{
	context_check(clist);
	for (CondList::const_iterator i = clist->begin(); i != clist->end(); ++i) {
		if (!specMap[*i].add_def(rule)) {
			in->fatalf_at(rule->info->loc.line,
				"code to default rule '%s' is already defined",
				i->c_str());
		}
	}
	delete clist;
}




/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TOKEN_CLOSE = 258,
     TOKEN_CLOSESIZE = 259,
     TOKEN_CODE = 260,
     TOKEN_CONF = 261,
     TOKEN_CTX = 262,
     TOKEN_ID = 263,
     TOKEN_FID = 264,
     TOKEN_FID_END = 265,
     TOKEN_NOCOND = 266,
     TOKEN_REGEXP = 267,
     TOKEN_SETUP = 268,
     TOKEN_STAR = 269
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{


	const re2c::RegExp * regexp;
	const re2c::Code * code;
	char op;
	re2c::ExtOp extop;
	std::string * str;
	re2c::CondList * clist;
	re2c::RegExpRule *rule;



} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */



#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   82

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  26
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  51
/* YYNRULES -- Number of states.  */
#define YYNSTATES  85

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   269

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      24,    25,     2,     2,    21,     2,     2,    17,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    20,    16,
      18,    15,    19,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,    23,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    22,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     4,     7,    10,    13,    17,    21,    24,
      26,    28,    30,    32,    34,    37,    40,    47,    54,    60,
      67,    74,    80,    84,    88,    93,    98,    99,   101,   103,
     107,   108,   112,   114,   118,   120,   124,   126,   130,   132,
     136,   138,   141,   143,   146,   149,   151,   153,   156,   159,
     161,   163
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      27,     0,    -1,    -1,    27,     6,    -1,    27,    28,    -1,
      27,    32,    -1,    29,    38,    30,    -1,    29,    38,    31,
      -1,     8,    15,    -1,     9,    -1,    16,    -1,    10,    -1,
      17,    -1,     7,    -1,    36,     5,    -1,    14,     5,    -1,
      18,    33,    19,    36,    35,     5,    -1,    18,    33,    19,
      36,    20,    35,    -1,    18,    33,    19,    14,     5,    -1,
      18,    14,    19,    36,    35,     5,    -1,    18,    14,    19,
      36,    20,    35,    -1,    18,    14,    19,    14,     5,    -1,
      11,    35,     5,    -1,    11,    20,    35,    -1,    13,    14,
      19,     5,    -1,    13,    33,    19,     5,    -1,    -1,    34,
      -1,     8,    -1,    34,    21,     8,    -1,    -1,    15,    19,
       8,    -1,    37,    -1,    37,    17,    38,    -1,    38,    -1,
      37,     7,    38,    -1,    39,    -1,    38,    22,    39,    -1,
      40,    -1,    39,    23,    40,    -1,    41,    -1,    40,    41,
      -1,    43,    -1,    43,    42,    -1,    43,     4,    -1,     3,
      -1,    14,    -1,    42,     3,    -1,    42,    14,    -1,     8,
      -1,    12,    -1,    24,    38,    25,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   158,   158,   160,   161,   162,   167,   174,   179,   182,
     186,   186,   188,   188,   191,   200,   211,   215,   221,   227,
     234,   243,   251,   261,   272,   278,   284,   287,   294,   300,
     310,   313,   320,   324,   332,   336,   348,   352,   359,   363,
     370,   374,   381,   385,   400,   419,   423,   427,   431,   438,
     448,   452
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOKEN_CLOSE", "TOKEN_CLOSESIZE",
  "TOKEN_CODE", "TOKEN_CONF", "TOKEN_CTX", "TOKEN_ID", "TOKEN_FID",
  "TOKEN_FID_END", "TOKEN_NOCOND", "TOKEN_REGEXP", "TOKEN_SETUP",
  "TOKEN_STAR", "'='", "';'", "'/'", "'<'", "'>'", "':'", "','", "'|'",
  "'\\\\'", "'('", "')'", "$accept", "spec", "def", "name", "enddef",
  "ctx", "rule", "cond", "clist", "newcond", "trailexpr", "ctxexpr",
  "expr", "diff", "term", "factor", "close", "primary", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,    61,    59,    47,    60,    62,
      58,    44,   124,    92,    40,    41
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    26,    27,    27,    27,    27,    28,    28,    29,    29,
      30,    30,    31,    31,    32,    32,    32,    32,    32,    32,
      32,    32,    32,    32,    32,    32,    33,    33,    34,    34,
      35,    35,    36,    36,    37,    37,    38,    38,    39,    39,
      40,    40,    41,    41,    41,    42,    42,    42,    42,    43,
      43,    43
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     2,     2,     3,     3,     2,     1,
       1,     1,     1,     1,     2,     2,     6,     6,     5,     6,
       6,     5,     3,     3,     4,     4,     0,     1,     1,     3,
       0,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     2,     1,     2,     2,     1,     1,     2,     2,     1,
       1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     3,    49,     9,    30,    50,    26,     0,
      26,     0,     4,     0,     5,     0,    32,    34,    36,    38,
      40,    42,     8,     0,    30,     0,    28,     0,     0,    27,
      15,     0,     0,    49,     0,     0,    14,     0,     0,     0,
       0,    41,    45,    44,    46,    43,     0,    23,    22,     0,
       0,     0,     0,     0,    51,    13,    11,    10,    12,     6,
       7,    35,    33,    37,    39,    47,    48,    31,    24,    25,
      29,     0,    30,     0,    30,    21,    30,     0,    18,    30,
       0,    20,    19,    17,    16
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,    12,    13,    59,    60,    14,    28,    29,    25,
      15,    16,    17,    18,    19,    20,    45,    21
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -25
static const yytype_int8 yypact[] =
{
     -25,     3,   -25,   -25,    -7,   -25,   -10,   -25,    -1,     1,
      43,    18,   -25,    18,   -25,    51,    32,    38,    39,    18,
     -25,    29,   -25,    44,    49,    60,   -25,    47,    48,    50,
     -25,    53,    54,   -25,    36,    37,   -25,    18,    18,    18,
      18,   -25,   -25,   -25,   -25,    17,    61,   -25,   -25,    63,
      65,    66,    10,    11,   -25,   -25,   -25,   -25,   -25,   -25,
     -25,    38,    38,    39,    18,   -25,   -25,   -25,   -25,   -25,
     -25,    70,    21,    71,    25,   -25,    49,    72,   -25,    49,
      73,   -25,   -25,   -25,   -25
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -25,   -25,   -25,   -25,   -25,   -25,   -25,    69,   -25,   -24,
     -15,   -25,    -9,    41,    42,   -18,   -25,   -25
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      47,    41,    34,     2,    35,    23,    30,    26,    22,     3,
      24,     4,     5,    27,     6,     7,     8,     9,    33,    33,
      65,    10,     7,     7,    71,    73,    33,    11,    61,    62,
       7,    66,    42,    43,    11,    11,    23,    72,    74,    37,
      23,    76,    11,    44,    55,    79,    41,    56,    77,    38,
      80,    26,    81,    57,    58,    83,    36,    31,    39,    39,
      39,    54,    40,    46,    23,    48,    49,    50,    68,    67,
      69,    51,    52,    53,    70,    75,    78,    82,    84,    32,
      63,     0,    64
};

static const yytype_int8 yycheck[] =
{
      24,    19,    11,     0,    13,    15,     5,     8,    15,     6,
      20,     8,     9,    14,    11,    12,    13,    14,     8,     8,
       3,    18,    12,    12,    14,    14,     8,    24,    37,    38,
      12,    14,     3,     4,    24,    24,    15,    52,    53,     7,
      15,    20,    24,    14,     7,    20,    64,    10,    72,    17,
      74,     8,    76,    16,    17,    79,     5,    14,    22,    22,
      22,    25,    23,    19,    15,     5,    19,    19,     5,     8,
       5,    21,    19,    19,     8,     5,     5,     5,     5,    10,
      39,    -1,    40
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    27,     0,     6,     8,     9,    11,    12,    13,    14,
      18,    24,    28,    29,    32,    36,    37,    38,    39,    40,
      41,    43,    15,    15,    20,    35,     8,    14,    33,    34,
       5,    14,    33,     8,    38,    38,     5,     7,    17,    22,
      23,    41,     3,     4,    14,    42,    19,    35,     5,    19,
      19,    21,    19,    19,    25,     7,    10,    16,    17,    30,
      31,    38,    38,    39,    40,     3,    14,     8,     5,     5,
       8,    14,    36,    14,    36,     5,    20,    35,     5,    20,
      35,    35,     5,    35,     5
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 5:

    {
		foundRules = true;
	;}
    break;

  case 6:

    {
		if (!symbol_table.insert(std::make_pair(*(yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].regexp))).second) {
			in->fatal("sym already defined");
		}
		delete (yyvsp[(1) - (3)].str);
	;}
    break;

  case 7:

    {
		in->fatal("contexts are not allowed in named definitions");
	;}
    break;

  case 8:

    {
		(yyval.str) = (yyvsp[(1) - (2)].str);
	;}
    break;

  case 9:

    {
		(yyval.str) = (yyvsp[(1) - (1)].str);
	;}
    break;

  case 14:

    {
		if (opts->cFlag) {
			in->fatal("condition or '<*>' required when using -c switch");
		}
		(yyvsp[(1) - (2)].rule)->info = new RuleInfo((yyvsp[(2) - (2)].code)->loc, (yyvsp[(2) - (2)].code), NULL);
		spec.add((yyvsp[(1) - (2)].rule));
	;}
    break;

  case 15:

    {
		if (opts->cFlag) {
			in->fatal("condition or '<*>' required when using -c switch");
		}
		RegExpRule *def = new RegExpRule(in->mkDefault());
		def->info = new RuleInfo((yyvsp[(2) - (2)].code)->loc, (yyvsp[(2) - (2)].code), NULL);
		if (!spec.add_def(def)) {
			in->fatal("code to default rule is already defined");
		}
	;}
    break;

  case 16:

    {
		context_rule((yyvsp[(2) - (6)].clist), (yyvsp[(6) - (6)].code)->loc, (yyvsp[(4) - (6)].rule), (yyvsp[(6) - (6)].code), (yyvsp[(5) - (6)].str));
	;}
    break;

  case 17:

    {
		Loc loc(in->get_fname(), in->get_cline());
		context_rule((yyvsp[(2) - (6)].clist), loc, (yyvsp[(4) - (6)].rule), NULL, (yyvsp[(6) - (6)].str));
	;}
    break;

  case 18:

    {
		RegExpRule *def = new RegExpRule(in->mkDefault());
		def->info = new RuleInfo((yyvsp[(5) - (5)].code)->loc, (yyvsp[(5) - (5)].code), NULL);
		default_rule((yyvsp[(2) - (5)].clist), def);
	;}
    break;

  case 19:

    {
		context_check(NULL);
		(yyvsp[(4) - (6)].rule)->info = new RuleInfo((yyvsp[(6) - (6)].code)->loc, (yyvsp[(6) - (6)].code), (yyvsp[(5) - (6)].str));
		specStar.add((yyvsp[(4) - (6)].rule));
		delete (yyvsp[(5) - (6)].str);
	;}
    break;

  case 20:

    {
		context_check(NULL);
		Loc loc(in->get_fname(), in->get_cline());
		(yyvsp[(4) - (6)].rule)->info = new RuleInfo(loc, NULL, (yyvsp[(6) - (6)].str));
		specStar.add((yyvsp[(4) - (6)].rule));
		delete (yyvsp[(6) - (6)].str);
	;}
    break;

  case 21:

    {
		RegExpRule *def = new RegExpRule(in->mkDefault());
		def->info = new RuleInfo((yyvsp[(5) - (5)].code)->loc, (yyvsp[(5) - (5)].code), NULL);
		if (!specStar.add_def(def)) {
			in->fatal("code to default rule '*' is already defined");
		}
	;}
    break;

  case 22:

    {
		context_check(NULL);
		if (specNone) {
			in->fatal("code to handle illegal condition already defined");
		}
		specNone = new RegExpRule(RegExp::nil());
		specNone->info = new RuleInfo((yyvsp[(3) - (3)].code)->loc, (yyvsp[(3) - (3)].code), (yyvsp[(2) - (3)].str));
		delete (yyvsp[(2) - (3)].str);
	;}
    break;

  case 23:

    {
		context_check(NULL);
		if (specNone) {
			in->fatal("code to handle illegal condition already defined");
		}
		Loc loc(in->get_fname(), in->get_cline());
		specNone = new RegExpRule(RegExp::nil());
		specNone->info = new RuleInfo(loc, NULL, (yyvsp[(3) - (3)].str));
		delete (yyvsp[(3) - (3)].str);
	;}
    break;

  case 24:

    {
		CondList *clist = new CondList;
		clist->insert("*");
		setup_rule(clist, (yyvsp[(4) - (4)].code));
	;}
    break;

  case 25:

    {
		setup_rule((yyvsp[(2) - (4)].clist), (yyvsp[(4) - (4)].code));
	;}
    break;

  case 26:

    {
			in->fatal("unnamed condition not supported");
		;}
    break;

  case 27:

    {
			(yyval.clist) = (yyvsp[(1) - (1)].clist);
		;}
    break;

  case 28:

    {
			(yyval.clist) = new CondList();
			(yyval.clist)->insert(* (yyvsp[(1) - (1)].str));
			delete (yyvsp[(1) - (1)].str);
		;}
    break;

  case 29:

    {
			(yyvsp[(1) - (3)].clist)->insert(* (yyvsp[(3) - (3)].str));
			delete (yyvsp[(3) - (3)].str);
			(yyval.clist) = (yyvsp[(1) - (3)].clist);
		;}
    break;

  case 30:

    {
			(yyval.str) = NULL;
		;}
    break;

  case 31:

    {
			(yyval.str) = (yyvsp[(3) - (3)].str);
		;}
    break;

  case 32:

    {
		(yyval.rule) = (yyvsp[(1) - (1)].rule);
	;}
    break;

  case 33:

    {
		// multiple trailing contexts on the same rule are not allowed
		(yyval.rule) = (yyvsp[(1) - (3)].rule);
		(yyval.rule)->regexps.push_back((yyvsp[(3) - (3)].regexp));
		(yyval.rule)->ctxnames.push_back(NULL);
	;}
    break;

  case 34:

    {
		(yyval.rule) = new RegExpRule((yyvsp[(1) - (1)].regexp));
	;}
    break;

  case 35:

    {
		if (!opts->contexts) {
			delete (yyvsp[(2) - (3)].str);
			in->fatal("non-trailing contexts are only allowed"
				" with '-C, --contexts' option");
		}
		(yyval.rule) = (yyvsp[(1) - (3)].rule);
		(yyval.rule)->regexps.push_back((yyvsp[(3) - (3)].regexp));
		(yyval.rule)->ctxnames.push_back((yyvsp[(2) - (3)].str));
	;}
    break;

  case 36:

    {
			(yyval.regexp) = (yyvsp[(1) - (1)].regexp);
		;}
    break;

  case 37:

    {
			(yyval.regexp) = mkAlt((yyvsp[(1) - (3)].regexp), (yyvsp[(3) - (3)].regexp));
		;}
    break;

  case 38:

    {
			(yyval.regexp) = (yyvsp[(1) - (1)].regexp);
		;}
    break;

  case 39:

    {
			(yyval.regexp) = in->mkDiff((yyvsp[(1) - (3)].regexp), (yyvsp[(3) - (3)].regexp));
		;}
    break;

  case 40:

    {
			(yyval.regexp) = (yyvsp[(1) - (1)].regexp);
		;}
    break;

  case 41:

    {
			(yyval.regexp) = RegExp::cat((yyvsp[(1) - (2)].regexp), (yyvsp[(2) - (2)].regexp));
		;}
    break;

  case 42:

    {
			(yyval.regexp) = (yyvsp[(1) - (1)].regexp);
		;}
    break;

  case 43:

    {
			switch((yyvsp[(2) - (2)].op))
			{
			case '*':
				(yyval.regexp) = RegExp::iter((yyvsp[(1) - (2)].regexp));
				break;
			case '+':
				(yyval.regexp) = RegExp::cat(RegExp::iter((yyvsp[(1) - (2)].regexp)), (yyvsp[(1) - (2)].regexp));
				break;
			case '?':
				(yyval.regexp) = mkAlt((yyvsp[(1) - (2)].regexp), RegExp::nil());
				break;
			}
		;}
    break;

  case 44:

    {
			if ((yyvsp[(2) - (2)].extop).max == std::numeric_limits<uint32_t>::max())
			{
				(yyval.regexp) = repeat_from ((yyvsp[(1) - (2)].regexp), (yyvsp[(2) - (2)].extop).min);
			}
			else if ((yyvsp[(2) - (2)].extop).min == (yyvsp[(2) - (2)].extop).max)
			{
				(yyval.regexp) = repeat ((yyvsp[(1) - (2)].regexp), (yyvsp[(2) - (2)].extop).min);
			}
			else
			{
				(yyval.regexp) = repeat_from_to ((yyvsp[(1) - (2)].regexp), (yyvsp[(2) - (2)].extop).min, (yyvsp[(2) - (2)].extop).max);
			}
			(yyval.regexp) = (yyval.regexp) ? (yyval.regexp) : RegExp::nil();
		;}
    break;

  case 45:

    {
			(yyval.op) = (yyvsp[(1) - (1)].op);
		;}
    break;

  case 46:

    {
			(yyval.op) = (yyvsp[(1) - (1)].op);
		;}
    break;

  case 47:

    {
			(yyval.op) = ((yyvsp[(1) - (2)].op) == (yyvsp[(2) - (2)].op)) ? (yyvsp[(1) - (2)].op) : '*';
		;}
    break;

  case 48:

    {
			(yyval.op) = ((yyvsp[(1) - (2)].op) == (yyvsp[(2) - (2)].op)) ? (yyvsp[(1) - (2)].op) : '*';
		;}
    break;

  case 49:

    {
			symbol_table_t::iterator i = symbol_table.find (* (yyvsp[(1) - (1)].str));
			delete (yyvsp[(1) - (1)].str);
			if (i == symbol_table.end ())
			{
				in->fatal("can't find symbol");
			}
			(yyval.regexp) = i->second;
		;}
    break;

  case 50:

    {
			(yyval.regexp) = (yyvsp[(1) - (1)].regexp);
		;}
    break;

  case 51:

    {
			(yyval.regexp) = (yyvsp[(2) - (3)].regexp);
		;}
    break;



      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}





extern "C" {
void yyerror(const char* s)
{
	in->fatal(s);
}

int yylex(){
	return in ? in->scan() : 0;
}
} // end extern "C"

namespace re2c
{

void parse(Scanner& i, Output & o)
{
	std::map<std::string, smart_ptr<DFA> >  dfa_map;
	ScannerState rules_state;

	in = &i;

	o.source.wversion_time ()
		.wline_info (in->get_cline (), in->get_fname ().c_str ());
	if (opts->target == opt_t::SKELETON)
	{
		emit_prolog (o.source);
	}

	Enc encodingOld = opts->encoding;
	
	while ((parseMode = i.echo()) != Scanner::Stop)
	{
		o.source.new_block ();
		bool bPrologBrace = false;
		ScannerState curr_state;

		i.save_state(curr_state);
		foundRules = false;

		if (opts->rFlag && parseMode == Scanner::Rules && dfa_map.size())
		{
			in->fatal("cannot have a second 'rules:re2c' block");
		}
		if (parseMode == Scanner::Reuse)
		{
			if (dfa_map.empty())
			{
				in->fatal("got 'use:re2c' without 'rules:re2c'");
			}
		}
		else if (parseMode == Scanner::Rules)
		{
			i.save_state(rules_state);
		}
		else
		{
			dfa_map.clear();
		}
		spec.clear ();
		in->set_in_parse(true);
		yyparse();
		in->set_in_parse(false);
		if (opts->rFlag && parseMode == Scanner::Reuse)
		{
			if (foundRules || opts->encoding != encodingOld)
			{
				// Re-parse rules
				parseMode = Scanner::Parse;
				i.restore_state(rules_state);
				i.reuse();
				dfa_map.clear();
				parse_cleanup();
				spec.clear ();
				in->set_in_parse(true);
				yyparse();
				in->set_in_parse(false);

				// Now append potential new rules
				i.restore_state(curr_state);
				parseMode = Scanner::Parse;
				in->set_in_parse(true);
				yyparse();
				in->set_in_parse(false);
			}
			encodingOld = opts->encoding;
		}
		o.source.set_block_line (in->get_cline ());
		uint32_t ind = opts->topIndent;
		if (opts->cFlag)
		{
			SpecMap::iterator it;
			SetupMap::const_iterator itRuleSetup;

			if (parseMode != Scanner::Reuse)
			{
				// merge <*> rules to all conditions with lowest priority
				for (it = specMap.begin(); it != specMap.end(); ++it)
				{
					for (size_t j = 0; j < specStar.res.size(); ++j) {
						it->second.add(specStar.res[j]);
					}
					if (specStar.def) {
						// ignore possible failure
						it->second.add_def(specStar.def);
					}
				}

				if (specNone)
				{
					specMap["0"].add (specNone);
					// Note that "0" inserts first, which is important.
					condnames.insert (condnames.begin (), "0");
				}
				o.types = condnames;
			}

			size_t nCount = specMap.size();

			for (it = specMap.begin(); it != specMap.end(); ++it)
			{
				if (parseMode != Scanner::Reuse)
				{
					itRuleSetup = ruleSetupMap.find(it->first);				
					if (itRuleSetup != ruleSetupMap.end())
					{
						yySetupRule = itRuleSetup->second.second;
					}
					else
					{
						itRuleSetup = ruleSetupMap.find("*");
						if (itRuleSetup != ruleSetupMap.end())
						{
							yySetupRule = itRuleSetup->second.second;
						}
						else
						{
							yySetupRule = "";
						}
					}

					dfa_map[it->first] = compile(it->second, o, it->first, opts->encoding.nCodeUnits ());
				}
				if (parseMode != Scanner::Rules && dfa_map.find(it->first) != dfa_map.end())
				{
					dfa_map[it->first]->emit(o, ind, !--nCount, bPrologBrace);
				}
			}
		}
		else
		{
			if (!spec.res.empty() || spec.def || !dfa_map.empty())
			{
				if (parseMode != Scanner::Reuse)
				{
					dfa_map[""] = compile(spec, o, "", opts->encoding.nCodeUnits ());
				}
				if (parseMode != Scanner::Rules && dfa_map.find("") != dfa_map.end())
				{
					dfa_map[""]->emit(o, ind, 0, bPrologBrace);
				}
			}
		}
		o.source.wline_info (in->get_cline (), in->get_fname ().c_str ());
		/* restore original char handling mode*/
		opts.reset_encoding (encodingOld);
	}

	if (opts->cFlag)
	{
		SetupMap::const_iterator itRuleSetup;
		for (itRuleSetup = ruleSetupMap.begin(); itRuleSetup != ruleSetupMap.end(); ++itRuleSetup)
		{
			if (itRuleSetup->first != "*" && specMap.find(itRuleSetup->first) == specMap.end())
			{
				in->fatalf_at(itRuleSetup->second.first, "setup for non existing rule '%s' found", itRuleSetup->first.c_str());
			}
		}
		if (specMap.size() < ruleSetupMap.size())
		{
			uint32_t line = in->get_cline();
			itRuleSetup = ruleSetupMap.find("*");
			if (itRuleSetup != ruleSetupMap.end())
			{
				line = itRuleSetup->second.first;
			}
			in->fatalf_at(line, "setup for all rules with '*' not possible when all rules are setup explicitly");
		}
	}

	if (opts->target == opt_t::SKELETON)
	{
		emit_epilog (o.source, o.skeletons);
	}

	parse_cleanup();
	in = NULL;
}

void parse_cleanup()
{
	RegExp::flist.clear();
	Range::vFreeList.clear();
	RangeSuffix::freeList.clear();
	Code::freelist.clear();
	symbol_table.clear ();
	condnames.clear ();
	specMap.clear();
	specStar.clear();
	specNone = NULL;
}

} // end namespace re2c
