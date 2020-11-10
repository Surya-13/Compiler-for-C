/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "a1.y" /* yacc.c:339  */

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	void yyerror(char *);
	int yylex(void);
	extern char *yytext;
	extern FILE * yyin;
	int global_dec=0;
	int func_def=0;
	int int_cons=0;
	int pnt_dec=0;
	int if_noelse=0;
	int ifelse_depth=0;
	
	int line_number=1;
	
	int error=0;
	int temp_depth=0;
	int in_if=0;


#line 89 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IF = 258,
    ELSE = 259,
    RETURN = 260,
    DO = 261,
    WHILE = 262,
    FOR = 263,
    SWITCH = 264,
    BREAK = 265,
    CONTINUE = 266,
    EQ = 267,
    EOL = 268,
    EXTERN = 269,
    STRUCT = 270,
    CASE = 271,
    DEFAULT = 272,
    INT = 273,
    LONG = 274,
    SHORT = 275,
    FLOAT = 276,
    DOUBLE = 277,
    CHAR = 278,
    VOID = 279,
    STRING = 280,
    SIZE_OF = 281,
    LESS_OR_EQUAL = 282,
    GREATER_OR_EQUAL = 283,
    EQUAL = 284,
    NOT_EQUAL = 285,
    INC_OP = 286,
    DEC_OP = 287,
    AND_OP = 288,
    OR_OP = 289,
    THREE_WAY_OP = 290,
    ID = 291,
    INT_NUMBER = 292,
    HEX = 293
  };
#endif
/* Tokens.  */
#define IF 258
#define ELSE 259
#define RETURN 260
#define DO 261
#define WHILE 262
#define FOR 263
#define SWITCH 264
#define BREAK 265
#define CONTINUE 266
#define EQ 267
#define EOL 268
#define EXTERN 269
#define STRUCT 270
#define CASE 271
#define DEFAULT 272
#define INT 273
#define LONG 274
#define SHORT 275
#define FLOAT 276
#define DOUBLE 277
#define CHAR 278
#define VOID 279
#define STRING 280
#define SIZE_OF 281
#define LESS_OR_EQUAL 282
#define GREATER_OR_EQUAL 283
#define EQUAL 284
#define NOT_EQUAL 285
#define INC_OP 286
#define DEC_OP 287
#define AND_OP 288
#define OR_OP 289
#define THREE_WAY_OP 290
#define ID 291
#define INT_NUMBER 292
#define HEX 293

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 216 "y.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  20
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1510

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  51
/* YYNRULES -- Number of rules.  */
#define YYNRULES  204
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  388

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   293

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    55,     2,     2,     2,    57,    53,     2,
      46,    47,    41,    39,    45,    40,    59,    42,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    50,     2,
      51,     2,    52,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    43,     2,    44,    58,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    48,    56,    49,    54,     2,     2,     2,
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
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    38,    38,    42,    43,    47,    48,    49,    50,    54,
      58,    59,    60,    61,    62,    63,    64,    65,    69,    70,
      74,    75,    76,    77,    78,    79,    80,    81,    85,    86,
      90,    91,    94,    97,    99,   100,   103,   106,   111,   112,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   135,   136,   140,   141,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   163,   167,   168,   172,   173,
     177,   181,   182,   183,   184,   188,   192,   193,   194,   195,
     199,   200,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   216,   217,   218,   219,   220,   221,   222,   226,   227,
     231,   235,   238,   241,   242,   243,   244,   249,   253,   257,
     258,   262,   263,   264,   268,   269,   273,   274,   278,   282,
     283,   284,   285,   286,   290,   294,   295,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   314,
     315,   319,   320,   324,   325,   326,   327,   328,   329,   330,
     331,   332,   336,   337,   338,   339,   340,   344,   345,   346,
     347,   348,   352,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   366,   367,   371,   372,   376,   377,   381,
     382,   383,   384,   388,   389,   390,   391,   392,   393,   394,
     395,   399,   400,   401,   402
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "ELSE", "RETURN", "DO", "WHILE",
  "FOR", "SWITCH", "BREAK", "CONTINUE", "EQ", "EOL", "EXTERN", "STRUCT",
  "CASE", "DEFAULT", "INT", "LONG", "SHORT", "FLOAT", "DOUBLE", "CHAR",
  "VOID", "STRING", "SIZE_OF", "LESS_OR_EQUAL", "GREATER_OR_EQUAL",
  "EQUAL", "NOT_EQUAL", "INC_OP", "DEC_OP", "AND_OP", "OR_OP",
  "THREE_WAY_OP", "ID", "INT_NUMBER", "HEX", "'+'", "'-'", "'*'", "'/'",
  "'['", "']'", "','", "'('", "')'", "'{'", "'}'", "':'", "'<'", "'>'",
  "'&'", "'~'", "'!'", "'|'", "'%'", "'^'", "'.'", "$accept", "program",
  "lines", "line", "var_dec", "var_assign", "array", "assign_var",
  "extend_var_dec", "func_dec", "args_ornot", "args_id", "statements",
  "one_or_more_statement", "statement", "func_call",
  "zeroormore_func_call_list", "func_call_list", "struct_dec", "members",
  "struct_var", "struct_var_assign", "extend_struct_var", "struct_names",
  "struct_assign", "extend_struct_assign", "var_struct", "if_statement",
  "set_if_1", "set_if_0", "for_loop", "first_for", "while_loop",
  "do_while", "switch_statement", "case_statement", "return_statement",
  "pointer", "expression", "conditional_expr", "string", "cond_op",
  "un_op", "operational_expr", "bin_op", "num_ornot", "size_of",
  "typecast", "mul_type", "type", "number", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,    43,
      45,    42,    47,    91,    93,    44,    40,    41,   123,   125,
      58,    60,    62,    38,   126,    33,   124,    37,    94,    46
};
# endif

#define YYPACT_NINF -284

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-284)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1462,  -284,     6,  -284,  -284,  -284,  -284,  -284,  -284,  -284,
      75,  -284,  1462,  -284,  -284,  -284,  -284,    66,  1475,  1368,
    -284,  -284,    76,    44,    91,   109,   129,  -284,    97,  1486,
     160,   143,  -284,  1301,  1301,   100,  1475,    78,  -284,  -284,
    -284,   106,  1475,  1301,   120,  1475,   137,  -284,   151,   147,
    1486,  1486,   154,  -284,   125,   193,   176,  1301,  1301,   182,
     173,   201,  -284,  -284,  1301,  1276,  -284,  -284,  -284,   204,
    -284,   699,  -284,  -284,  1301,  -284,  -284,  1301,  -284,  1230,
     200,    16,  -284,   213,   198,  -284,   140,  1301,  -284,  1301,
    1475,   127,  -284,   733,   132,  -284,   214,   205,  -284,  1451,
     158,  -284,  -284,    53,   240,   219,  1301,  1475,   137,  -284,
    -284,  1475,  1230,  1230,  1301,   220,  -284,  1401,   767,   211,
     -25,  -284,  -284,  -284,  -284,  -284,  -284,  -284,  -284,  -284,
    -284,  -284,  -284,   208,  -284,  -284,  1301,  -284,  -284,  -284,
    -284,  -284,  -284,  -284,  -284,  1301,  1301,  1230,  1230,   221,
     148,    -5,   163,  1475,   217,   -30,   699,   699,   216,  1301,
    -284,  -284,   168,    -2,   184,   253,   231,   154,   223,  -284,
    -284,    53,   733,   222,  -284,    23,   227,  -284,   800,  -284,
    -284,  -284,  -284,   233,  -284,   834,  1230,  1230,  -284,  -284,
     666,  1475,   225,  -284,  1475,   188,  1475,   238,  -284,  -284,
      10,   699,  -284,   666,   158,   242,  -284,   194,  -284,  -284,
     223,  -284,  -284,    14,  -284,   241,  -284,  1301,  -284,  -284,
     239,  1301,   336,   243,   244,   249,   283,   285,  -284,   264,
     146,  1326,  -284,  -284,   252,  -284,   666,   290,  -284,  -284,
    -284,  -284,  -284,  -284,  -284,  -284,   269,   867,   100,  -284,
    1475,  -284,  1475,   261,  -284,  1475,  -284,   666,  -284,   258,
    -284,   158,   158,   266,  -284,  -284,   666,  -284,  -284,  1301,
     299,   666,   307,  1301,  1427,  1301,  -284,  -284,  1379,  1301,
    -284,     7,  -284,  -284,  -284,    17,  -284,  -284,  -284,  1475,
    -284,   267,  -284,  -284,  -284,   158,   268,   900,  -284,   271,
     272,   933,  -284,  -284,   309,  1301,   966,   999,  1301,  -284,
    1301,  -284,   197,  -284,  -284,  -284,  -284,   391,   316,  1301,
     446,  -284,   313,   280,  -284,  1032,  1065,  1301,  -284,   666,
     326,   286,  1098,   666,  -284,  1301,    19,  -284,  -284,  1131,
     284,  -284,  1301,   321,   287,   288,  1301,   298,   291,  -284,
     348,   501,  1164,  -284,  -284,   556,  1197,   666,  -284,  -284,
     666,  -284,   340,   666,  -284,   666,   353,   611,   315,  -284,
    -284,   317,   209,   352,   666,  -284,  -284,  -284,   356,  -284,
    -284,   322,  -284,  -284,    19,  -284,  -284,  -284
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   200,     0,   193,   194,   195,   196,   197,   198,   199,
       0,     2,     3,     5,     6,     7,     8,     0,   190,   107,
       1,     4,    29,   135,     0,     0,     0,   191,   109,     0,
       0,     0,   192,     0,   184,     0,    39,    29,    20,   136,
       9,    29,   189,     0,   107,    39,   109,   101,     0,     0,
      81,    83,     0,   110,   109,   151,     0,     0,     0,   148,
     201,     0,   162,   163,     0,     0,   164,   165,   166,     0,
     145,    29,   138,   147,     0,   143,   140,     0,   146,   183,
       0,    29,    28,     0,     0,    38,    40,     0,    21,     0,
      39,    29,    24,   109,   109,   108,     0,     0,   105,   107,
     100,    82,    84,    91,     0,     0,     0,    39,   109,   103,
     152,     0,   169,   171,    77,     0,   204,   141,     0,   138,
       0,   202,   182,   153,   154,   155,   156,   168,   170,   157,
     158,   159,   172,   173,   174,   175,     0,   160,   161,   176,
     177,   178,   179,   180,    22,     0,     0,   139,   142,    18,
      29,     0,    41,     0,    48,    42,    29,    29,     0,     0,
      25,   102,   109,     0,    92,     0,     0,     0,    91,    86,
      85,    91,   109,     0,   106,     0,     0,    76,    78,   203,
     137,   150,   187,     0,   181,     0,   149,   167,    19,    30,
      57,     0,    49,    44,     0,    43,     0,    50,    23,    26,
       0,    29,    34,    57,   100,    96,    80,    93,    90,    87,
      91,    88,   104,     0,   185,     0,    75,     0,   188,   144,
       0,   184,     0,     0,     0,     0,     0,     0,    74,     0,
     148,     0,    60,    61,     0,    56,    58,   145,    63,    64,
      65,    66,    67,    68,    69,    71,     0,     0,     0,    45,
       0,    52,     0,    51,    46,     0,    32,    57,    27,     0,
      94,   100,   100,    97,    89,    36,    57,   186,    79,     0,
       0,    57,     0,     0,     0,     0,    73,    72,   107,     0,
      10,     0,    31,    59,    62,     0,    70,    53,    47,     0,
      54,     0,    35,    98,    95,   100,     0,     0,   134,     0,
       0,     0,   123,   121,     0,   184,     0,     0,     0,    11,
       0,    14,     0,    55,    33,    99,    37,     0,     0,     0,
       0,   122,     0,     0,    12,     0,     0,     0,    15,    57,
     116,     0,     0,    57,   125,   184,   133,    13,    16,     0,
       0,   117,     0,     0,     0,     0,     0,     0,     0,    17,
     111,     0,     0,   127,   124,     0,     0,    57,   128,   117,
      57,   118,     0,    57,   120,    57,   131,     0,     0,   115,
     126,     0,   133,     0,    57,   118,   118,   119,     0,   129,
     132,     0,   113,   114,   133,   118,   130,   112
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -284,  -284,   358,  -284,     5,  -284,    52,   -31,   -23,  -284,
     -38,   -86,  -109,   142,  -220,   -36,  -284,   162,    83,    28,
    -284,   218,  -159,  -170,   337,    -9,    26,  -284,    24,  -261,
    -284,  -284,  -284,  -284,  -284,  -283,  -284,    30,   -33,   323,
     325,  -284,  -284,  -284,  -284,  -218,  -284,  -284,    21,  -284,
    -284
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    10,    11,    12,   232,   233,    37,    24,    38,    14,
      84,    85,   234,   235,   236,    70,   176,   177,   238,    49,
      50,   104,   169,   165,    30,    47,   239,   240,   351,   369,
     241,   305,   242,   243,   244,   348,   245,   246,   247,    72,
      73,   145,    74,    75,   146,    80,    76,    77,   248,    18,
      78
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
      71,    79,   272,   270,    82,    13,   195,    97,   189,   209,
      93,   202,   211,    34,    88,   196,    23,    13,    92,   308,
     309,    17,   182,   256,   112,   113,    16,   265,    33,   310,
     311,   117,   118,    17,   260,   346,   347,    98,    16,    27,
      32,   147,    19,   190,   148,   109,   203,    25,   144,    31,
      52,   264,   158,    39,   156,    51,   157,    86,   257,    34,
      34,    35,   266,    32,    23,    83,    86,   193,   160,   173,
     214,    52,    52,   172,    96,    20,    51,    51,   101,   102,
      46,   178,   105,    15,   161,    23,   120,   322,    33,   379,
      87,   293,   294,    91,   259,    15,    34,   330,   167,   174,
     334,   386,    22,   185,    40,   249,   108,    23,   251,    43,
     254,    86,   186,   187,   382,   383,   155,   345,    89,    34,
      32,    35,    36,    35,   387,   315,   201,    92,    86,    96,
     166,   361,   175,   198,   199,   364,    81,   106,   154,   159,
      34,    23,    44,    45,    43,    41,    46,   375,   291,    34,
     183,    35,    90,   109,   237,   168,    94,   296,   279,   280,
      89,    23,   299,   212,   287,    42,   288,   237,    34,   290,
      44,   107,    35,    53,    86,    34,   152,    44,   258,    54,
     106,    23,    44,    34,   178,   153,   237,    99,    79,    34,
     103,    34,   114,    35,   164,    23,   100,   105,   117,    23,
     237,   188,    91,   313,   192,   215,    34,   197,   191,   327,
     328,    34,    86,    44,   108,    86,   205,    86,    55,   378,
     340,   237,   111,   210,   344,   346,   347,    34,   114,   204,
     237,    34,   115,   252,   166,   237,   297,    34,   116,   262,
     301,   121,   306,   304,   149,   151,   307,   253,   366,   150,
     162,   368,   163,   170,   371,   171,   372,   179,   181,   263,
     184,    39,   194,   200,    34,   381,   206,   207,   167,   213,
     250,    86,    79,    86,   216,   325,    86,   326,    83,   303,
     218,   237,   281,   255,   237,   269,   332,   261,   267,   273,
     274,   166,   166,   237,   339,   275,   276,   237,   277,    32,
     278,   282,    79,   284,    83,   285,   289,   292,    96,   352,
      86,   295,   298,   356,   300,   237,   314,   316,   319,   237,
     318,   237,   321,   331,   237,   166,   335,   237,   336,   237,
     341,   237,   342,   350,   353,   355,   354,   312,   237,   220,
     358,   221,   222,   223,   224,   225,   226,   227,   357,   228,
       1,   229,   359,   370,     3,     4,     5,     6,     7,     8,
       9,    55,    56,   373,   376,   380,   377,    57,    58,   384,
      21,   385,   230,    60,    61,    62,    63,   231,   283,   268,
     110,    95,    65,   367,   271,   208,     0,     0,   119,    66,
      67,    68,     0,     0,   220,    69,   221,   222,   223,   224,
     225,   226,   227,     0,   228,     1,   229,     0,     0,     3,
       4,     5,     6,     7,     8,     9,    55,    56,     0,     0,
       0,     0,    57,    58,     0,     0,     0,   230,    60,    61,
      62,    63,   231,     0,     0,     0,     0,    65,     0,   329,
       0,     0,     0,     0,    66,    67,    68,     0,     0,   220,
      69,   221,   222,   223,   224,   225,   226,   227,     0,   228,
       1,   229,     0,     0,     3,     4,     5,     6,     7,     8,
       9,    55,    56,     0,     0,     0,     0,    57,    58,     0,
       0,     0,   230,    60,    61,    62,    63,   231,     0,     0,
       0,     0,    65,     0,   333,     0,     0,     0,     0,    66,
      67,    68,     0,     0,   220,    69,   221,   222,   223,   224,
     225,   226,   227,     0,   228,     1,   229,     0,     0,     3,
       4,     5,     6,     7,     8,     9,    55,    56,     0,     0,
       0,     0,    57,    58,     0,     0,     0,   230,    60,    61,
      62,    63,   231,     0,     0,     0,     0,    65,     0,   360,
       0,     0,     0,     0,    66,    67,    68,     0,     0,   220,
      69,   221,   222,   223,   224,   225,   226,   227,     0,   228,
       1,   229,     0,     0,     3,     4,     5,     6,     7,     8,
       9,    55,    56,     0,     0,     0,     0,    57,    58,     0,
       0,     0,   230,    60,    61,    62,    63,   231,     0,     0,
       0,     0,    65,     0,   363,     0,     0,     0,     0,    66,
      67,    68,     0,     0,   220,    69,   221,   222,   223,   224,
     225,   226,   227,     0,   228,     1,   229,     0,     0,     3,
       4,     5,     6,     7,     8,     9,    55,    56,     0,     0,
       0,     0,    57,    58,     0,     0,     0,   230,    60,    61,
      62,    63,   231,     0,     0,     0,     0,    65,     0,   374,
       0,     0,     0,     0,    66,    67,    68,     0,     0,   220,
      69,   221,   222,   223,   224,   225,   226,   227,     0,   228,
       1,   229,     0,     0,     3,     4,     5,     6,     7,     8,
       9,    55,    56,     0,     0,     0,     0,    57,    58,     0,
       0,     0,   230,    60,    61,    62,    63,   231,     0,     0,
       0,   122,    65,     0,     0,     0,     0,     0,     0,    66,
      67,    68,     0,     0,     0,    69,   123,   124,   125,   126,
     127,   128,   129,   130,   131,     0,     0,     0,   132,   133,
     134,   135,   136,     0,    35,   122,     0,     0,     0,     0,
     137,   138,   139,     0,     0,   140,   141,   142,   143,     0,
     123,   124,   125,   126,   127,   128,   129,   130,   131,     0,
       0,     0,   132,   133,   134,   135,   136,     0,    44,   122,
       0,     0,     0,     0,   137,   138,   139,     0,     0,   140,
     141,   142,   143,     0,   123,   124,   125,   126,   127,   128,
     129,   130,   131,     0,     0,     0,   132,   133,   134,   135,
     136,     0,   122,     0,   180,     0,     0,     0,   137,   138,
     139,     0,     0,   140,   141,   142,   143,   123,   124,   125,
     126,   127,   128,   129,   130,   131,     0,     0,     0,   132,
     133,   134,   135,   136,     0,   217,   122,     0,     0,     0,
       0,   137,   138,   139,     0,     0,   140,   141,   142,   143,
       0,   123,   124,   125,   126,   127,   128,   129,   130,   131,
       0,     0,     0,   132,   133,   134,   135,   136,   219,   122,
     286,     0,     0,     0,     0,   137,   138,   139,     0,     0,
     140,   141,   142,   143,   123,   124,   125,   126,   127,   128,
     129,   130,   131,     0,     0,     0,   132,   133,   134,   135,
     136,     0,   122,     0,     0,     0,     0,     0,   137,   138,
     139,     0,     0,   140,   141,   142,   143,   123,   124,   125,
     126,   127,   128,   129,   130,   131,     0,     0,     0,   132,
     133,   134,   135,   136,     0,   122,     0,   317,     0,     0,
       0,   137,   138,   139,     0,     0,   140,   141,   142,   143,
     123,   124,   125,   126,   127,   128,   129,   130,   131,     0,
       0,     0,   132,   133,   134,   135,   136,     0,   122,     0,
     320,     0,     0,     0,   137,   138,   139,     0,     0,   140,
     141,   142,   143,   123,   124,   125,   126,   127,   128,   129,
     130,   131,     0,     0,     0,   132,   133,   134,   135,   136,
       0,   122,   324,   323,     0,     0,     0,   137,   138,   139,
       0,     0,   140,   141,   142,   143,   123,   124,   125,   126,
     127,   128,   129,   130,   131,     0,     0,     0,   132,   133,
     134,   135,   136,     0,   122,   337,     0,     0,     0,     0,
     137,   138,   139,     0,     0,   140,   141,   142,   143,   123,
     124,   125,   126,   127,   128,   129,   130,   131,     0,     0,
       0,   132,   133,   134,   135,   136,     0,   122,   338,     0,
       0,     0,     0,   137,   138,   139,     0,     0,   140,   141,
     142,   143,   123,   124,   125,   126,   127,   128,   129,   130,
     131,     0,     0,     0,   132,   133,   134,   135,   136,     0,
     122,     0,     0,     0,     0,     0,   137,   138,   139,     0,
       0,   140,   141,   142,   143,   123,   124,   125,   126,   127,
     128,   129,   130,   131,     0,     0,     0,   132,   133,   134,
     135,   136,     0,   122,   349,   343,     0,     0,     0,   137,
     138,   139,     0,     0,   140,   141,   142,   143,   123,   124,
     125,   126,   127,   128,   129,   130,   131,     0,     0,     0,
     132,   133,   134,   135,   136,     0,   122,     0,     0,     0,
       0,     0,   137,   138,   139,     0,     0,   140,   141,   142,
     143,   123,   124,   125,   126,   127,   128,   129,   130,   131,
       0,     0,     0,   132,   133,   134,   135,   136,     0,   122,
       0,   362,     0,     0,     0,   137,   138,   139,     0,     0,
     140,   141,   142,   143,   123,   124,   125,   126,   127,   128,
     129,   130,   131,     0,     0,     0,   132,   133,   134,   135,
     136,     0,   122,     0,     0,     0,     0,   365,   137,   138,
     139,     0,     0,   140,   141,   142,   143,   123,   124,   125,
     126,   127,   128,   129,   130,   131,     0,     0,     0,   132,
     133,   134,   135,   136,     0,     0,     0,     0,     0,     0,
       0,   137,   138,   139,     0,     0,   140,   141,   142,   143,
       1,    26,     0,     0,     3,     4,     5,     6,     7,     8,
       9,    55,    56,     0,     0,     0,     0,    57,    58,     0,
       0,     0,    59,    60,    61,    62,    63,    64,     0,     0,
       0,     0,    65,     0,     0,     0,    55,    56,     0,    66,
      67,    68,    57,    58,     0,    69,     0,    59,    60,    61,
      62,    63,    64,     0,     0,     0,     0,    65,     0,     0,
       0,    55,    56,     0,    66,    67,    68,    57,    58,     0,
      69,     0,    59,    60,    61,    62,    63,   231,     0,     0,
       0,     0,    65,     0,     0,     0,     0,     0,     0,    66,
      67,    68,     1,    26,     0,    69,     3,     4,     5,     6,
       7,     8,     9,     1,    26,     0,     0,     3,     4,     5,
       6,     7,     8,     9,    28,     0,     0,     0,     0,    23,
       0,     0,     0,     0,     0,    94,    29,     0,     0,     0,
      23,     0,     0,     0,     0,     0,     0,    29,   123,   124,
     125,   126,   127,   128,   129,   130,   131,     0,     0,     0,
     302,     1,    26,     0,   136,     3,     4,     5,     6,     7,
       8,     9,   137,   138,   139,     0,     0,   140,   141,   142,
     143,     0,     0,    81,     0,     1,    26,     0,    23,     3,
       4,     5,     6,     7,     8,     9,     1,     2,     0,     0,
       3,     4,     5,     6,     7,     8,     9,    94,     0,     1,
      26,     0,    23,     3,     4,     5,     6,     7,     8,     9,
       1,    48,     0,     0,     3,     4,     5,     6,     7,     8,
       9
};

static const yytype_int16 yycheck[] =
{
      33,    34,   222,   221,    35,     0,    36,    45,    13,   168,
      43,    13,   171,    43,    37,    45,    41,    12,    41,    12,
      13,     0,    47,    13,    57,    58,     0,    13,    12,    12,
      13,    64,    65,    12,   204,    16,    17,    46,    12,    18,
      19,    74,    36,    48,    77,    54,    48,    17,    71,    19,
      29,   210,    90,    23,    87,    29,    89,    36,    48,    43,
      43,    45,    48,    42,    41,    35,    45,   153,    91,   107,
      47,    50,    51,   106,    44,     0,    50,    51,    50,    51,
      28,   114,    52,     0,    93,    41,    65,   305,    12,   372,
      12,   261,   262,    41,   203,    12,    43,   317,    45,   108,
     320,   384,    36,   136,    13,   191,    54,    41,   194,    12,
     196,    90,   145,   146,   375,   376,    86,   335,    12,    43,
      99,    45,    46,    45,   385,   295,   159,   150,   107,    99,
     100,   351,   111,   156,   157,   355,    36,    12,    86,    12,
      43,    41,    45,    46,    12,    36,    94,   367,   257,    43,
     120,    45,    46,   162,   190,   103,    36,   266,    12,    13,
      12,    41,   271,   172,   250,    36,   252,   203,    43,   255,
      45,    46,    45,    13,   153,    43,    36,    45,   201,    36,
      12,    41,    45,    43,   217,    45,   222,    36,   221,    43,
      36,    43,    46,    45,    36,    41,    49,   167,   231,    41,
     236,   149,   150,   289,   152,   175,    43,   155,    45,    12,
      13,    43,   191,    45,   162,   194,   164,   196,    25,    10,
     329,   257,    46,   171,   333,    16,    17,    43,    46,    45,
     266,    43,    59,    45,   204,   271,   269,    43,    37,    45,
     273,    37,   275,   274,    44,    47,   279,   195,   357,    36,
      36,   360,    47,    13,   363,    36,   365,    37,    47,   207,
      52,   231,    45,    47,    43,   374,    13,    36,    45,    47,
      45,   250,   305,   252,    47,   308,   255,   310,   248,   274,
      47,   317,   230,    45,   320,    46,   319,    45,    47,    46,
      46,   261,   262,   329,   327,    46,    13,   333,    13,   278,
      36,    49,   335,    13,   274,    36,    45,    49,   278,   342,
     289,    45,    13,   346,     7,   351,    49,    49,    46,   355,
      49,   357,    13,     7,   360,   295,    13,   363,    48,   365,
       4,   367,    46,    49,    13,    47,    49,   285,   374,     3,
      49,     5,     6,     7,     8,     9,    10,    11,    50,    13,
      14,    15,     4,    13,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    10,    49,    13,    49,    31,    32,    13,
      12,    49,    36,    37,    38,    39,    40,    41,   236,   217,
      55,    44,    46,   359,    48,   167,    -1,    -1,    65,    53,
      54,    55,    -1,    -1,     3,    59,     5,     6,     7,     8,
       9,    10,    11,    -1,    13,    14,    15,    -1,    -1,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    -1,    -1,
      -1,    -1,    31,    32,    -1,    -1,    -1,    36,    37,    38,
      39,    40,    41,    -1,    -1,    -1,    -1,    46,    -1,    48,
      -1,    -1,    -1,    -1,    53,    54,    55,    -1,    -1,     3,
      59,     5,     6,     7,     8,     9,    10,    11,    -1,    13,
      14,    15,    -1,    -1,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    -1,    -1,    -1,    -1,    31,    32,    -1,
      -1,    -1,    36,    37,    38,    39,    40,    41,    -1,    -1,
      -1,    -1,    46,    -1,    48,    -1,    -1,    -1,    -1,    53,
      54,    55,    -1,    -1,     3,    59,     5,     6,     7,     8,
       9,    10,    11,    -1,    13,    14,    15,    -1,    -1,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    -1,    -1,
      -1,    -1,    31,    32,    -1,    -1,    -1,    36,    37,    38,
      39,    40,    41,    -1,    -1,    -1,    -1,    46,    -1,    48,
      -1,    -1,    -1,    -1,    53,    54,    55,    -1,    -1,     3,
      59,     5,     6,     7,     8,     9,    10,    11,    -1,    13,
      14,    15,    -1,    -1,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    -1,    -1,    -1,    -1,    31,    32,    -1,
      -1,    -1,    36,    37,    38,    39,    40,    41,    -1,    -1,
      -1,    -1,    46,    -1,    48,    -1,    -1,    -1,    -1,    53,
      54,    55,    -1,    -1,     3,    59,     5,     6,     7,     8,
       9,    10,    11,    -1,    13,    14,    15,    -1,    -1,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    -1,    -1,
      -1,    -1,    31,    32,    -1,    -1,    -1,    36,    37,    38,
      39,    40,    41,    -1,    -1,    -1,    -1,    46,    -1,    48,
      -1,    -1,    -1,    -1,    53,    54,    55,    -1,    -1,     3,
      59,     5,     6,     7,     8,     9,    10,    11,    -1,    13,
      14,    15,    -1,    -1,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    -1,    -1,    -1,    -1,    31,    32,    -1,
      -1,    -1,    36,    37,    38,    39,    40,    41,    -1,    -1,
      -1,    12,    46,    -1,    -1,    -1,    -1,    -1,    -1,    53,
      54,    55,    -1,    -1,    -1,    59,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    -1,    -1,    -1,    39,    40,
      41,    42,    43,    -1,    45,    12,    -1,    -1,    -1,    -1,
      51,    52,    53,    -1,    -1,    56,    57,    58,    59,    -1,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    -1,
      -1,    -1,    39,    40,    41,    42,    43,    -1,    45,    12,
      -1,    -1,    -1,    -1,    51,    52,    53,    -1,    -1,    56,
      57,    58,    59,    -1,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    -1,    -1,    -1,    39,    40,    41,    42,
      43,    -1,    12,    -1,    47,    -1,    -1,    -1,    51,    52,
      53,    -1,    -1,    56,    57,    58,    59,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    -1,    -1,    -1,    39,
      40,    41,    42,    43,    -1,    45,    12,    -1,    -1,    -1,
      -1,    51,    52,    53,    -1,    -1,    56,    57,    58,    59,
      -1,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      -1,    -1,    -1,    39,    40,    41,    42,    43,    44,    12,
      13,    -1,    -1,    -1,    -1,    51,    52,    53,    -1,    -1,
      56,    57,    58,    59,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    -1,    -1,    -1,    39,    40,    41,    42,
      43,    -1,    12,    -1,    -1,    -1,    -1,    -1,    51,    52,
      53,    -1,    -1,    56,    57,    58,    59,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    -1,    -1,    -1,    39,
      40,    41,    42,    43,    -1,    12,    -1,    47,    -1,    -1,
      -1,    51,    52,    53,    -1,    -1,    56,    57,    58,    59,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    -1,
      -1,    -1,    39,    40,    41,    42,    43,    -1,    12,    -1,
      47,    -1,    -1,    -1,    51,    52,    53,    -1,    -1,    56,
      57,    58,    59,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    -1,    -1,    -1,    39,    40,    41,    42,    43,
      -1,    12,    13,    47,    -1,    -1,    -1,    51,    52,    53,
      -1,    -1,    56,    57,    58,    59,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    -1,    -1,    -1,    39,    40,
      41,    42,    43,    -1,    12,    13,    -1,    -1,    -1,    -1,
      51,    52,    53,    -1,    -1,    56,    57,    58,    59,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    -1,    -1,
      -1,    39,    40,    41,    42,    43,    -1,    12,    13,    -1,
      -1,    -1,    -1,    51,    52,    53,    -1,    -1,    56,    57,
      58,    59,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    -1,    -1,    -1,    39,    40,    41,    42,    43,    -1,
      12,    -1,    -1,    -1,    -1,    -1,    51,    52,    53,    -1,
      -1,    56,    57,    58,    59,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    -1,    -1,    -1,    39,    40,    41,
      42,    43,    -1,    12,    13,    47,    -1,    -1,    -1,    51,
      52,    53,    -1,    -1,    56,    57,    58,    59,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    -1,    -1,    -1,
      39,    40,    41,    42,    43,    -1,    12,    -1,    -1,    -1,
      -1,    -1,    51,    52,    53,    -1,    -1,    56,    57,    58,
      59,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      -1,    -1,    -1,    39,    40,    41,    42,    43,    -1,    12,
      -1,    47,    -1,    -1,    -1,    51,    52,    53,    -1,    -1,
      56,    57,    58,    59,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    -1,    -1,    -1,    39,    40,    41,    42,
      43,    -1,    12,    -1,    -1,    -1,    -1,    50,    51,    52,
      53,    -1,    -1,    56,    57,    58,    59,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    -1,    -1,    -1,    39,
      40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    51,    52,    53,    -1,    -1,    56,    57,    58,    59,
      14,    15,    -1,    -1,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    -1,    -1,    -1,    -1,    31,    32,    -1,
      -1,    -1,    36,    37,    38,    39,    40,    41,    -1,    -1,
      -1,    -1,    46,    -1,    -1,    -1,    25,    26,    -1,    53,
      54,    55,    31,    32,    -1,    59,    -1,    36,    37,    38,
      39,    40,    41,    -1,    -1,    -1,    -1,    46,    -1,    -1,
      -1,    25,    26,    -1,    53,    54,    55,    31,    32,    -1,
      59,    -1,    36,    37,    38,    39,    40,    41,    -1,    -1,
      -1,    -1,    46,    -1,    -1,    -1,    -1,    -1,    -1,    53,
      54,    55,    14,    15,    -1,    59,    18,    19,    20,    21,
      22,    23,    24,    14,    15,    -1,    -1,    18,    19,    20,
      21,    22,    23,    24,    36,    -1,    -1,    -1,    -1,    41,
      -1,    -1,    -1,    -1,    -1,    36,    48,    -1,    -1,    -1,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    48,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    -1,    -1,    -1,
      13,    14,    15,    -1,    43,    18,    19,    20,    21,    22,
      23,    24,    51,    52,    53,    -1,    -1,    56,    57,    58,
      59,    -1,    -1,    36,    -1,    14,    15,    -1,    41,    18,
      19,    20,    21,    22,    23,    24,    14,    15,    -1,    -1,
      18,    19,    20,    21,    22,    23,    24,    36,    -1,    14,
      15,    -1,    41,    18,    19,    20,    21,    22,    23,    24,
      14,    15,    -1,    -1,    18,    19,    20,    21,    22,    23,
      24
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    14,    15,    18,    19,    20,    21,    22,    23,    24,
      61,    62,    63,    64,    69,    78,    86,   108,   109,    36,
       0,    62,    36,    41,    67,    97,    15,   108,    36,    48,
      84,    97,   108,    12,    43,    45,    46,    66,    68,    97,
      13,    36,    36,    12,    45,    46,    66,    85,    15,    79,
      80,    86,   108,    13,    36,    25,    26,    31,    32,    36,
      37,    38,    39,    40,    41,    46,    53,    54,    55,    59,
      75,    98,    99,   100,   102,   103,   106,   107,   110,    98,
     105,    36,    67,    97,    70,    71,   108,    12,    68,    12,
      46,    66,    68,    98,    36,    84,    97,    70,    85,    36,
      49,    79,    79,    36,    81,    97,    12,    46,    66,    85,
     100,    46,    98,    98,    46,    59,    37,    98,    98,    99,
     108,    37,    12,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    39,    40,    41,    42,    43,    51,    52,    53,
      56,    57,    58,    59,    68,   101,   104,    98,    98,    44,
      36,    47,    36,    45,    66,    97,    98,    98,    70,    12,
      68,    85,    36,    47,    36,    83,    97,    45,    66,    82,
      13,    36,    98,    70,    85,   108,    76,    77,    98,    37,
      47,    47,    47,    97,    52,    98,    98,    98,    66,    13,
      48,    45,    66,    71,    45,    36,    45,    66,    68,    68,
      47,    98,    13,    48,    45,    66,    13,    36,    81,    82,
      66,    82,    85,    47,    47,    97,    47,    45,    47,    44,
       3,     5,     6,     7,     8,     9,    10,    11,    13,    15,
      36,    41,    64,    65,    72,    73,    74,    75,    78,    86,
      87,    90,    92,    93,    94,    96,    97,    98,   108,    71,
      45,    71,    45,    66,    71,    45,    13,    48,    68,    72,
      83,    45,    45,    66,    82,    13,    48,    47,    77,    46,
     105,    48,    74,    46,    46,    46,    13,    13,    36,    12,
      13,    66,    49,    73,    13,    36,    13,    71,    71,    45,
      71,    72,    49,    83,    83,    45,    72,    98,    13,    72,
       7,    98,    13,    64,    67,    91,    98,    98,    12,    13,
      12,    13,    66,    71,    49,    83,    49,    47,    49,    46,
      47,    13,   105,    47,    13,    98,    98,    12,    13,    48,
      74,     7,    98,    48,    74,    13,    48,    13,    13,    98,
      72,     4,    46,    47,    72,   105,    16,    17,    95,    13,
      49,    88,    98,    13,    49,    47,    98,    50,    49,     4,
      48,    74,    47,    48,    74,    50,    72,    88,    72,    89,
      13,    72,    72,    10,    48,    74,    49,    49,    10,    95,
      13,    72,    89,    89,    13,    49,    95,    89
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    60,    61,    62,    62,    63,    63,    63,    63,    64,
      65,    65,    65,    65,    65,    65,    65,    65,    66,    66,
      67,    67,    67,    67,    67,    67,    67,    67,    68,    68,
      69,    69,    69,    69,    69,    69,    69,    69,    70,    70,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    72,    72,    73,    73,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    75,    76,    76,    77,    77,
      78,    79,    79,    79,    79,    80,    81,    81,    81,    81,
      82,    82,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    84,    84,    84,    84,    84,    84,    84,    85,    85,
      86,    87,    87,    87,    87,    87,    87,    88,    89,    90,
      90,    91,    91,    91,    92,    92,    93,    93,    94,    95,
      95,    95,    95,    95,    96,    97,    97,    98,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    99,
      99,   100,   100,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   102,   102,   102,   102,   102,   103,   103,   103,
     103,   103,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   105,   105,   106,   106,   107,   107,   108,
     108,   108,   108,   109,   109,   109,   109,   109,   109,   109,
     109,   110,   110,   110,   110
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     3,
       2,     3,     4,     5,     3,     4,     5,     6,     3,     4,
       2,     3,     4,     5,     3,     4,     5,     6,     2,     0,
       6,     8,     7,     9,     7,     9,     8,    10,     1,     0,
       1,     2,     2,     3,     3,     4,     4,     5,     2,     3,
       3,     4,     4,     5,     5,     6,     1,     0,     1,     2,
       1,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     2,     2,     1,     4,     1,     0,     1,     3,
       7,     1,     2,     1,     2,     3,     2,     3,     3,     4,
       2,     0,     1,     2,     3,     4,     2,     3,     4,     5,
       0,     2,     4,     3,     5,     3,     4,     0,     2,     0,
       4,     7,    13,    11,    11,     9,     5,     0,     0,    10,
       8,     1,     2,     1,     7,     5,     9,     7,     7,     5,
       7,     3,     5,     0,     3,     1,     2,     3,     1,     2,
       1,     2,     2,     1,     4,     1,     1,     1,     1,     3,
       3,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     2,     2,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     1,     0,     4,     5,     3,     4,     2,
       1,     2,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     3,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

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
#line 47 "a1.y" /* yacc.c:1646  */
    {global_dec++;}
#line 1793 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 48 "a1.y" /* yacc.c:1646  */
    {global_dec++;}
#line 1799 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 49 "a1.y" /* yacc.c:1646  */
    {global_dec++;}
#line 1805 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 50 "a1.y" /* yacc.c:1646  */
    {global_dec++;}
#line 1811 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 78 "a1.y" /* yacc.c:1646  */
    {pnt_dec++;}
#line 1817 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 79 "a1.y" /* yacc.c:1646  */
    {pnt_dec++;}
#line 1823 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 80 "a1.y" /* yacc.c:1646  */
    {pnt_dec++;}
#line 1829 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 81 "a1.y" /* yacc.c:1646  */
    {pnt_dec++;}
#line 1835 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 92 "a1.y" /* yacc.c:1646  */
    {func_def++;}
#line 1841 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 95 "a1.y" /* yacc.c:1646  */
    {pnt_dec++;}
#line 1847 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 98 "a1.y" /* yacc.c:1646  */
    {pnt_dec++;func_def++;}
#line 1853 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 101 "a1.y" /* yacc.c:1646  */
    {func_def++;}
#line 1859 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 104 "a1.y" /* yacc.c:1646  */
    {pnt_dec++;}
#line 1865 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 107 "a1.y" /* yacc.c:1646  */
    {pnt_dec++;func_def++;}
#line 1871 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 119 "a1.y" /* yacc.c:1646  */
    {pnt_dec++;}
#line 1877 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 123 "a1.y" /* yacc.c:1646  */
    {pnt_dec++;}
#line 1883 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 127 "a1.y" /* yacc.c:1646  */
    {pnt_dec++;}
#line 1889 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 131 "a1.y" /* yacc.c:1646  */
    {pnt_dec++;}
#line 1895 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 194 "a1.y" /* yacc.c:1646  */
    {pnt_dec++;}
#line 1901 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 195 "a1.y" /* yacc.c:1646  */
    {pnt_dec++;}
#line 1907 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 205 "a1.y" /* yacc.c:1646  */
    {pnt_dec++;}
#line 1913 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 207 "a1.y" /* yacc.c:1646  */
    {pnt_dec++;}
#line 1919 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 209 "a1.y" /* yacc.c:1646  */
    {pnt_dec++;}
#line 1925 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 211 "a1.y" /* yacc.c:1646  */
    {pnt_dec++;}
#line 1931 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 218 "a1.y" /* yacc.c:1646  */
    {pnt_dec++;}
#line 1937 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 219 "a1.y" /* yacc.c:1646  */
    {pnt_dec++;}
#line 1943 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 221 "a1.y" /* yacc.c:1646  */
    {pnt_dec++;}
#line 1949 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 236 "a1.y" /* yacc.c:1646  */
    {if_noelse++;}
#line 1955 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 239 "a1.y" /* yacc.c:1646  */
    {if(in_if>0){temp_depth++;}}
#line 1961 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 245 "a1.y" /* yacc.c:1646  */
    {if_noelse++;}
#line 1967 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 249 "a1.y" /* yacc.c:1646  */
    {in_if+=1;if(ifelse_depth<in_if)ifelse_depth=in_if;}
#line 1973 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 253 "a1.y" /* yacc.c:1646  */
    {in_if-=1;}
#line 1979 "y.tab.c" /* yacc.c:1646  */
    break;

  case 201:
#line 399 "a1.y" /* yacc.c:1646  */
    {int_cons++;}
#line 1985 "y.tab.c" /* yacc.c:1646  */
    break;

  case 204:
#line 402 "a1.y" /* yacc.c:1646  */
    {int_cons++;}
#line 1991 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1995 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 405 "a1.y" /* yacc.c:1906  */


void yyerror(char *s) {
	error=1;
    //printf("ERROR:- %s near line no: %d, last token read is: %s\n",s,line_number,pres);
    if(strcmp(s,"syntax error")==0){
    	printf("***parsing terminated*** [syntax error]\n");
    }
    else{
    	printf("%s\n", s);
    }
}

int main(int argc,char* argv[]){
	if(argc != 2){
	   	printf("***process terminated*** [input error]: invalid number of command-line argumnets\n");
		return 0;
    }
    FILE *file_open = fopen( argv[1] , "r" );
    if (!file_open) {
		printf("***process terminated*** [input error]: no such file %s exists\n",argv[1]);
		return 0;
    } 
    yyin = file_open;
	yyparse();
   	if(error==0){
	    printf("***parsing successful***\n");
		printf("#global_declarations = %d\n",global_dec);
		printf("#function_definitions = %d\n",func_def);
		printf("#integer_constants = %d\n",int_cons);
		printf("#pointers_declarations = %d\n",pnt_dec);
		printf("#ifs_without_else = %d\n",if_noelse);
		printf("if-else max-depth = %d\n",ifelse_depth);
	}
	fclose(file_open);
    return 0;
}

