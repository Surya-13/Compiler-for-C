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
#line 1 "file.y" /* yacc.c:339  */

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	typedef struct container{
		int len;
		int val;
	}container;
	typedef struct Node{
		container node;
		int sz;
		struct Node* children[10];
	}Node;
	void yyerror(char *);
	int yylex(void);
	extern char *yytext;
	int in_main=0;
	int line_number=1;
	char temp[100];
	int long_all=0;
	int long_if=0;
	int long_while=0;
	int long_switch=0;
	int long_main=0;
	int error=0;
	int max(int i,int j){
		if(i<j)return j;
		return i;
	}
	void update(Node* root){
		if(root->sz==0)return;
		if(root->sz==1){
			long_all = max(long_all,root->children[0]->node.len+1);
			root->node.len = root->children[0]->node.len+1;
			root->node.val = max(root->node.val,root->children[0]->node.len+1);
		}
		else{
			int max1=-1;
			int max2=-1;
			for(int i=0;i<root->sz;i++){
				if(max1<root->children[i]->node.len){
					max2=max1;
					max1=root->children[i]->node.len;
				}
				else if(max2<root->children[i]->node.len){
					max2=root->children[i]->node.len;
				}
				root->node.val = max(root->node.val,root->children[i]->node.val);
			}
			long_all = max(max1+max2+1,long_all);
			root->node.len=max1+1;
			root->node.val = max(root->node.val,max1+max2+1);
		}
	}
	void evt1(Node *root,Node *c1){
		root->children[0]=c1;
		root->sz=1;
		update(root);
	}
	void evt2(Node *root,Node *c1,Node *c2){
		root->children[0]=c1;
		root->children[1]=c2;
		root->sz=2;
		update(root);
	}
	void evt3(Node *root,Node *c1,Node *c2,Node *c3){
		//printf("eval3 %d,%d,%d\n",c1->node.len,c2->node.len,c3->node.len);
		root->children[0]=c1;
		root->children[1]=c2;
		root->children[2]=c3;
		root->sz=3;
		update(root);
	}
	void evt4(Node *root,Node *c1,Node *c2,Node *c3,Node* c4){
		//printf("eval4 %d,%d,%d,%d",c1->node.len,c2->node.len,c3->node.len,c4->node.len);
		root->children[0]=c1;
		root->children[1]=c2;
		root->children[2]=c3;
		root->children[3]=c4;
		root->sz=4;
		update(root);
	}
	#define YYSTYPE Node

#line 151 "y.tab.c" /* yacc.c:339  */

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
    PRINTF = 291,
    ARROW = 292,
    FORMAT_SPEC = 293,
    ID = 294,
    INT_NUMBER = 295,
    HEX = 296
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
#define PRINTF 291
#define ARROW 292
#define FORMAT_SPEC 293
#define ID 294
#define INT_NUMBER 295
#define HEX 296

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

#line 284 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   270

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  106
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  224

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   296

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    58,     2,     2,     2,    57,    59,     2,
      48,    49,    47,    54,    44,    55,    51,    56,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    50,     2,
      52,     2,    53,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    45,     2,    46,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    42,     2,    43,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    97,    97,   100,   101,   104,   105,   106,   109,   112,
     113,   114,   115,   118,   119,   120,   121,   122,   123,   124,
     125,   128,   129,   132,   136,   137,   140,   141,   144,   145,
     148,   149,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   166,   170,   173,   176,   179,   182,
     183,   186,   187,   190,   191,   194,   195,   198,   201,   204,
     208,   209,   212,   215,   218,   219,   220,   221,   224,   227,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   256,   257,   258,   259,   262,   263,
     266,   267,   270,   274,   275,   278,   279
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
  "THREE_WAY_OP", "PRINTF", "ARROW", "FORMAT_SPEC", "ID", "INT_NUMBER",
  "HEX", "'{'", "'}'", "','", "'['", "']'", "'*'", "'('", "')'", "':'",
  "'.'", "'<'", "'>'", "'+'", "'-'", "'/'", "'%'", "'!'", "'&'", "$accept",
  "program", "decl_list", "decl", "struct_decl", "var_decl", "type_spec",
  "extern_spec", "func_decl", "params", "param_list", "param", "stmt_list",
  "stmt", "while_stmt", "dowhile_stmt", "print_stmt", "format_specifier",
  "compound_stmt", "local_decs", "local_decl", "if_stmt", "return_stmt",
  "break_stmt", "continue_stmt", "switch_stmt", "compound_case",
  "single_case", "default_case", "assign_stmt", "incr_stmt", "decr_stmt",
  "expr", "Pexpr", "integerLit", "floatLit", "identifier", "arg_list",
  "args", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   123,   125,    44,    91,    93,    42,    40,    41,
      58,    46,    60,    62,    43,    45,    47,    37,    33,    38
};
# endif

#define YYPACT_NINF -105

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-105)))

#define YYTABLE_NINF -51

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       4,  -105,   -32,    20,    15,  -105,  -105,  -105,   -32,    88,
    -105,  -105,    47,  -105,  -105,     0,    25,    27,    48,   -10,
    -105,  -105,   100,    21,     2,  -105,  -105,  -105,   -32,   -32,
      54,    61,  -105,   -32,  -105,  -105,    59,   -32,    58,    72,
    -105,    84,    -4,   119,  -105,    11,     8,    92,    91,   100,
    -105,    87,  -105,  -105,   100,    93,    61,  -105,  -105,    95,
      96,   130,    87,   109,   130,   130,   130,   130,   104,   213,
    -105,  -105,    63,  -105,  -105,    60,   130,   111,  -105,  -105,
     105,  -105,  -105,  -105,  -105,  -105,   142,   130,   130,   130,
     130,   130,   130,   130,   130,   130,   130,   130,   130,   130,
     130,   130,    87,    87,   108,    -1,    60,   110,   112,   144,
     152,   124,    81,  -105,  -105,  -105,  -105,  -105,  -105,  -105,
    -105,  -105,  -105,  -105,  -105,  -105,    -9,   125,  -105,  -105,
    -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,
    -105,  -105,  -105,  -105,  -105,  -105,   127,  -105,   132,   128,
      87,  -105,   166,   173,    87,    87,  -105,  -105,   148,  -105,
    -105,    87,   175,   177,   -32,    87,   -32,  -105,  -105,    87,
    -105,   143,  -105,   145,   146,   147,  -105,   150,   184,  -105,
    -105,   189,   160,   195,  -105,    60,    87,    60,   167,   -32,
    -105,    87,   196,    87,   206,   162,  -105,   197,   163,   202,
      87,   203,    60,   209,    21,   207,   197,   210,  -105,   231,
    -105,  -105,  -105,   169,   199,   208,  -105,  -105,  -105,    60,
      60,  -105,    60,    60
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      22,    21,     0,     0,    22,     3,     7,     5,     0,     0,
       6,   102,    19,     1,     4,     0,    14,    15,    13,    22,
      20,     9,    22,     0,    22,    17,    18,    16,     0,     0,
       0,    50,    10,     0,    98,    99,     0,     0,     0,    24,
      26,    19,     0,     0,    49,     0,     0,    28,     0,    22,
      51,     0,     8,    11,    22,     0,    50,    23,    27,     0,
      98,     0,     0,     0,     0,     0,     0,     0,     0,    91,
      94,    95,    96,    12,    29,     0,     0,     0,    89,    96,
       0,   101,    88,    87,    86,    90,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   106,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    30,    35,    40,    41,    33,    34,    37,
      38,    39,    36,    32,    42,    43,     0,     0,   100,    97,
      52,    72,    73,    76,    77,    79,    74,    78,    80,    83,
      70,    71,    81,    82,    84,    85,     0,   103,   105,     0,
       0,    55,     0,     0,     0,     0,    57,    58,     0,    48,
      31,     0,     0,     0,     0,     0,     0,    75,    93,     0,
      92,     0,    56,     0,     0,     0,    47,     0,     0,    68,
      69,     0,     0,     0,   104,     0,     0,     0,     0,     0,
      64,     0,     0,     0,    53,     0,    44,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    60,     0,    66,     0,
      67,    54,    45,     0,     0,     0,    61,    46,    65,     0,
       0,    59,    62,    63
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -105,  -105,  -105,   241,  -105,   -11,    10,  -105,  -105,  -105,
    -105,   204,   -98,  -104,  -105,  -105,  -105,  -105,   211,    37,
    -105,  -105,  -105,  -105,  -105,  -105,    46,  -105,  -105,  -105,
    -105,  -105,   -25,   138,   -22,  -105,    -2,  -105,  -105
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,     6,     7,    29,     9,    10,    38,
      39,    40,   112,   113,   114,   115,   116,   177,   117,    30,
      31,   118,   119,   120,   121,   122,   205,   206,   215,   123,
     124,   125,    68,    69,    70,    71,    79,   148,   149
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      12,    36,   153,   161,     1,    28,    15,    11,   160,    50,
       8,    32,   151,    21,     8,    -2,     1,    28,     1,     2,
      13,    53,   162,   163,    21,    59,    41,    42,   164,     1,
       2,    45,    33,   -50,    37,    47,   165,    80,    11,    60,
      35,    51,   166,    73,    22,    23,    61,    62,    24,    72,
      63,   -25,    54,    64,    65,    22,    23,    66,    67,    37,
      72,    34,    35,   104,    33,   105,   106,   107,    44,   108,
     109,   110,    25,   126,    26,     1,    28,   146,   147,   -22,
     152,   194,   -22,   196,   104,   -22,   105,   106,   107,    19,
     108,   109,   110,    75,    20,    27,   111,    43,   211,    11,
      72,    72,    56,    72,   126,    46,    16,    48,   102,    17,
     126,   103,    18,    59,     1,    28,    49,   111,   160,   160,
      11,   222,   223,    56,   159,   171,    11,    60,    35,   174,
     175,    20,    52,    56,    61,    62,   178,    55,    63,    74,
     182,    64,    65,    76,   184,    66,    67,    77,    72,    81,
      86,   128,    72,    72,   129,   130,   150,   156,   154,    72,
     155,   195,   181,    72,   183,   157,   199,    72,   201,    11,
      60,    35,   158,   168,   167,   209,   169,   170,    62,   172,
     173,    63,   213,   126,    72,   126,   176,   198,   179,    72,
     180,    72,   185,   186,   189,   187,   188,   190,    72,    78,
     126,   191,    82,    83,    84,    85,   192,   193,   200,   197,
     202,   203,   207,   204,   127,   208,   210,   126,   126,   219,
     126,   126,   212,   217,   214,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
      87,    88,    89,    90,   218,    14,    91,    92,    93,   220,
      94,   221,   216,    58,     0,     0,     0,     0,     0,    57,
      95,     0,     0,     0,     0,    96,    97,    98,    99,   100,
     101
};

static const yytype_int16 yycheck[] =
{
       2,    23,   106,    12,    14,    15,     8,    39,   112,    13,
       0,    22,    13,    13,     4,     0,    14,    15,    14,    15,
       0,    13,    31,    32,    13,    26,    28,    29,    37,    14,
      15,    33,    22,    43,    24,    37,    45,    62,    39,    40,
      41,    45,    51,    54,    44,    45,    47,    48,    48,    51,
      51,    49,    44,    54,    55,    44,    45,    58,    59,    49,
      62,    40,    41,     3,    54,     5,     6,     7,    31,     9,
      10,    11,    47,    75,    47,    14,    15,   102,   103,    18,
     105,   185,    21,   187,     3,    24,     5,     6,     7,    42,
       9,    10,    11,    56,    47,    47,    36,    43,   202,    39,
     102,   103,    42,   105,   106,    46,    18,    49,    45,    21,
     112,    48,    24,    26,    14,    15,    44,    36,   222,   223,
      39,   219,   220,    42,    43,   150,    39,    40,    41,   154,
     155,    47,    13,    42,    47,    48,   161,    45,    51,    46,
     165,    54,    55,    48,   169,    58,    59,    51,   150,    40,
      46,    40,   154,   155,    49,    13,    48,    13,    48,   161,
      48,   186,   164,   165,   166,    13,   191,   169,   193,    39,
      40,    41,    48,    46,    49,   200,    44,    49,    48,    13,
       7,    51,   204,   185,   186,   187,    38,   189,    13,   191,
      13,   193,    49,    48,    44,    49,    49,    13,   200,    61,
     202,    12,    64,    65,    66,    67,    46,    12,    12,    42,
       4,    49,    49,    16,    76,    13,    13,   219,   220,    50,
     222,   223,    13,    13,    17,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
      27,    28,    29,    30,    13,     4,    33,    34,    35,    50,
      37,    43,   206,    49,    -1,    -1,    -1,    -1,    -1,    48,
      47,    -1,    -1,    -1,    -1,    52,    53,    54,    55,    56,
      57
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    14,    15,    61,    62,    63,    64,    65,    66,    67,
      68,    39,    96,     0,    63,    96,    18,    21,    24,    42,
      47,    13,    44,    45,    48,    47,    47,    47,    15,    66,
      79,    80,    65,    66,    40,    41,    94,    66,    69,    70,
      71,    96,    96,    43,    79,    96,    46,    96,    49,    44,
      13,    45,    13,    13,    44,    45,    42,    78,    71,    26,
      40,    47,    48,    51,    54,    55,    58,    59,    92,    93,
      94,    95,    96,    65,    46,    79,    48,    51,    93,    96,
      92,    40,    93,    93,    93,    93,    46,    27,    28,    29,
      30,    33,    34,    35,    37,    47,    52,    53,    54,    55,
      56,    57,    45,    48,     3,     5,     6,     7,     9,    10,
      11,    36,    72,    73,    74,    75,    76,    78,    81,    82,
      83,    84,    85,    89,    90,    91,    96,    93,    40,    49,
      13,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    92,    92,    97,    98,
      48,    13,    92,    73,    48,    48,    13,    13,    48,    43,
      73,    12,    31,    32,    37,    45,    51,    49,    46,    44,
      49,    92,    13,     7,    92,    92,    38,    77,    92,    13,
      13,    96,    92,    96,    92,    49,    48,    49,    49,    44,
      13,    12,    46,    12,    73,    92,    73,    42,    96,    92,
      12,    92,     4,    49,    16,    86,    87,    49,    13,    92,
      13,    73,    13,    94,    17,    88,    86,    13,    13,    50,
      50,    43,    72,    72
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    60,    61,    62,    62,    63,    63,    63,    64,    65,
      65,    65,    65,    66,    66,    66,    66,    66,    66,    66,
      66,    67,    67,    68,    69,    69,    70,    70,    71,    71,
      72,    72,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    74,    75,    76,    77,    78,    79,
      79,    80,    80,    81,    81,    82,    82,    83,    84,    85,
      86,    86,    87,    88,    89,    89,    89,    89,    90,    91,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    93,    93,    93,    93,    94,    94,
      95,    95,    96,    97,    97,    98,    98
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     6,     3,
       4,     6,     7,     2,     2,     2,     3,     3,     3,     2,
       3,     1,     0,     6,     1,     0,     1,     3,     2,     4,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     5,     7,     7,     1,     4,     2,
       0,     3,     6,     5,     7,     2,     3,     2,     2,     8,
       1,     2,     4,     3,     4,     7,     6,     6,     3,     3,
       3,     3,     3,     3,     3,     4,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     2,     2,     2,
       2,     1,     4,     4,     1,     1,     1,     3,     1,     1,
       3,     2,     1,     1,     3,     1,     0
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
        case 2:
#line 97 "file.y" /* yacc.c:1646  */
    {evt1(&(yyval),&(yyvsp[0]));}
#line 1528 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 100 "file.y" /* yacc.c:1646  */
    {evt1(&(yyval),&(yyvsp[0]));}
#line 1534 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 101 "file.y" /* yacc.c:1646  */
    {evt2(&(yyval),&(yyvsp[-1]),&(yyvsp[0]));}
#line 1540 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 104 "file.y" /* yacc.c:1646  */
    {evt1(&(yyval),&(yyvsp[0]));}
#line 1546 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 105 "file.y" /* yacc.c:1646  */
    {evt1(&(yyval),&(yyvsp[0]));}
#line 1552 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 106 "file.y" /* yacc.c:1646  */
    {evt1(&(yyval),&(yyvsp[0]));}
#line 1558 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 109 "file.y" /* yacc.c:1646  */
    {evt2(&(yyval),&(yyvsp[-4]),&(yyvsp[-2]));}
#line 1564 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 112 "file.y" /* yacc.c:1646  */
    {evt2(&(yyval),&(yyvsp[-2]),&(yyvsp[-1]));}
#line 1570 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 113 "file.y" /* yacc.c:1646  */
    {evt3(&(yyval),&(yyvsp[-3]),&(yyvsp[-2]),&(yyvsp[0]));}
#line 1576 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 114 "file.y" /* yacc.c:1646  */
    {evt3(&(yyval),&(yyvsp[-5]),&(yyvsp[-4]),&(yyvsp[-2]));}
#line 1582 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 115 "file.y" /* yacc.c:1646  */
    {evt4(&(yyval),&(yyvsp[-6]),&(yyvsp[-5]),&(yyvsp[-3]),&(yyvsp[0]));}
#line 1588 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 118 "file.y" /* yacc.c:1646  */
    {evt1(&(yyval),&(yyvsp[-1]));}
#line 1594 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 119 "file.y" /* yacc.c:1646  */
    {evt1(&(yyval),&(yyvsp[-1]));}
#line 1600 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 120 "file.y" /* yacc.c:1646  */
    {evt1(&(yyval),&(yyvsp[-1]));}
#line 1606 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 121 "file.y" /* yacc.c:1646  */
    {evt1(&(yyval),&(yyvsp[-2]));}
#line 1612 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 122 "file.y" /* yacc.c:1646  */
    {evt1(&(yyval),&(yyvsp[-2]));}
#line 1618 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 123 "file.y" /* yacc.c:1646  */
    {evt1(&(yyval),&(yyvsp[-2]));}
#line 1624 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 124 "file.y" /* yacc.c:1646  */
    {evt1(&(yyval),&(yyvsp[0]));}
#line 1630 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 125 "file.y" /* yacc.c:1646  */
    {evt1(&(yyval),&(yyvsp[-1]));}
#line 1636 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 128 "file.y" /* yacc.c:1646  */
    {(yyval).node = (container){2,2};(yyval).sz=1;}
#line 1642 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 129 "file.y" /* yacc.c:1646  */
    {(yyval).node = (container){2,2};(yyval).sz=1;}
#line 1648 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 133 "file.y" /* yacc.c:1646  */
    {evt4(&(yyval),&(yyvsp[-5]),&(yyvsp[-4]),&(yyvsp[-2]),&(yyvsp[0]));if(in_main){long_main=max(long_main,(yyval).node.val);in_main-=1;}}
#line 1654 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 136 "file.y" /* yacc.c:1646  */
    {evt1(&(yyval),&(yyvsp[0]));}
#line 1660 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 137 "file.y" /* yacc.c:1646  */
    {(yyval).node = (container){2,2};(yyval).sz=1;}
#line 1666 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 140 "file.y" /* yacc.c:1646  */
    {evt1(&(yyval),&(yyvsp[0]));}
#line 1672 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 141 "file.y" /* yacc.c:1646  */
    {evt2(&(yyval),&(yyvsp[-2]),&(yyvsp[0]));}
#line 1678 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 144 "file.y" /* yacc.c:1646  */
    {evt2(&(yyval),&(yyvsp[-1]),&(yyvsp[0]));}
#line 1684 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 145 "file.y" /* yacc.c:1646  */
    {evt2(&(yyval),&(yyvsp[-3]),&(yyvsp[-2]));}
#line 1690 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 148 "file.y" /* yacc.c:1646  */
    {evt1(&(yyval),&(yyvsp[0]));}
#line 1696 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 149 "file.y" /* yacc.c:1646  */
    {evt2(&(yyval),&(yyvsp[-1]),&(yyvsp[0]));}
#line 1702 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 152 "file.y" /* yacc.c:1646  */
    {evt1(&(yyval),&(yyvsp[0]));}
#line 1708 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 153 "file.y" /* yacc.c:1646  */
    {evt1(&(yyval),&(yyvsp[0]));}
#line 1714 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 154 "file.y" /* yacc.c:1646  */
    {evt1(&(yyval),&(yyvsp[0]));}
#line 1720 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 155 "file.y" /* yacc.c:1646  */
    {evt1(&(yyval),&(yyvsp[0]));}
#line 1726 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 156 "file.y" /* yacc.c:1646  */
    {evt1(&(yyval),&(yyvsp[0]));}
#line 1732 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 157 "file.y" /* yacc.c:1646  */
    {evt1(&(yyval),&(yyvsp[0]));}
#line 1738 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 158 "file.y" /* yacc.c:1646  */
    {evt1(&(yyval),&(yyvsp[0]));}
#line 1744 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 159 "file.y" /* yacc.c:1646  */
    {evt1(&(yyval),&(yyvsp[0]));}
#line 1750 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 160 "file.y" /* yacc.c:1646  */
    {evt1(&(yyval),&(yyvsp[0]));}
#line 1756 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 161 "file.y" /* yacc.c:1646  */
    {evt1(&(yyval),&(yyvsp[0]));}
#line 1762 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 162 "file.y" /* yacc.c:1646  */
    {evt1(&(yyval),&(yyvsp[0]));}
#line 1768 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 163 "file.y" /* yacc.c:1646  */
    {evt1(&(yyval),&(yyvsp[0]));}
#line 1774 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 167 "file.y" /* yacc.c:1646  */
    {evt2(&(yyval),&(yyvsp[-2]),&(yyvsp[0]));long_while=max(long_while,(yyval).node.val);}
#line 1780 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 170 "file.y" /* yacc.c:1646  */
    {evt2(&(yyval),&(yyvsp[-5]),&(yyvsp[-2]));}
#line 1786 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 173 "file.y" /* yacc.c:1646  */
    {evt2(&(yyval),&(yyvsp[-4]),&(yyvsp[-2]));}
#line 1792 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 176 "file.y" /* yacc.c:1646  */
    {(yyval).node = (container){2,2};(yyval).sz=1;}
#line 1798 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 179 "file.y" /* yacc.c:1646  */
    {evt2(&(yyval),&(yyvsp[-2]),&(yyvsp[-1]));}
#line 1804 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 182 "file.y" /* yacc.c:1646  */
    {evt2(&(yyval),&(yyvsp[-1]),&(yyvsp[0]));}
#line 1810 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 183 "file.y" /* yacc.c:1646  */
    {(yyval).node = (container){2,2};(yyval).sz=1;}
#line 1816 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 186 "file.y" /* yacc.c:1646  */
    {evt2(&(yyval),&(yyvsp[-2]),&(yyvsp[-1]));}
#line 1822 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 187 "file.y" /* yacc.c:1646  */
    {evt3(&(yyval),&(yyvsp[-5]),&(yyvsp[-4]),&(yyvsp[-2]));}
#line 1828 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 190 "file.y" /* yacc.c:1646  */
    {evt2(&(yyval),&(yyvsp[-2]),&(yyvsp[0]));long_if=max(long_if,(yyval).node.val);}
#line 1834 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 191 "file.y" /* yacc.c:1646  */
    {evt3(&(yyval),&(yyvsp[-4]),&(yyvsp[-2]),&(yyvsp[0]));long_if=max(long_if,(yyval).node.val);}
#line 1840 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 194 "file.y" /* yacc.c:1646  */
    {(yyval).node = (container){2,2};(yyval).sz=1;}
#line 1846 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 195 "file.y" /* yacc.c:1646  */
    {evt1(&(yyval),&(yyvsp[-1]));}
#line 1852 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 198 "file.y" /* yacc.c:1646  */
    {(yyval).node = (container){2,2};(yyval).sz=1;}
#line 1858 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 201 "file.y" /* yacc.c:1646  */
    {(yyval).node = (container){2,2};(yyval).sz=1;}
#line 1864 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 205 "file.y" /* yacc.c:1646  */
    {evt3(&(yyval),&(yyvsp[-5]),&(yyvsp[-2]),&(yyvsp[-1]));long_switch=max(long_switch,(yyval).node.val);}
#line 1870 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 208 "file.y" /* yacc.c:1646  */
    {evt1(&(yyval),&(yyvsp[0]));}
#line 1876 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 209 "file.y" /* yacc.c:1646  */
    {evt2(&(yyval),&(yyvsp[-1]),&(yyvsp[0]));}
#line 1882 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 212 "file.y" /* yacc.c:1646  */
    {evt2(&(yyval),&(yyvsp[-2]),&(yyvsp[0]));}
#line 1888 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 215 "file.y" /* yacc.c:1646  */
    {evt1(&(yyval),&(yyvsp[0]));}
#line 1894 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 218 "file.y" /* yacc.c:1646  */
    {evt2(&(yyvsp[-2]),&(yyvsp[-3]),&(yyvsp[-1]));evt1(&(yyval),&(yyvsp[-2]));}
#line 1900 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 219 "file.y" /* yacc.c:1646  */
    {evt3(&(yyvsp[-2]),&(yyvsp[-6]),&(yyvsp[-4]),&(yyvsp[-1]));evt1(&(yyval),&(yyvsp[-2]));}
#line 1906 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 220 "file.y" /* yacc.c:1646  */
    {evt3(&(yyvsp[-2]),&(yyvsp[-5]),&(yyvsp[-3]),&(yyvsp[-1]));evt1(&(yyval),&(yyvsp[-2]));}
#line 1912 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 221 "file.y" /* yacc.c:1646  */
    {evt3(&(yyvsp[-2]),&(yyvsp[-5]),&(yyvsp[-3]),&(yyvsp[-1]));evt1(&(yyval),&(yyvsp[-2]));}
#line 1918 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 224 "file.y" /* yacc.c:1646  */
    {evt1(&(yyval),&(yyvsp[-2]));}
#line 1924 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 227 "file.y" /* yacc.c:1646  */
    {evt1(&(yyval),&(yyvsp[-2]));}
#line 1930 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 230 "file.y" /* yacc.c:1646  */
    {evt2(&(yyvsp[-1]),&(yyvsp[-2]),&(yyvsp[0]));evt1(&(yyval),&(yyvsp[-1]));}
#line 1936 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 231 "file.y" /* yacc.c:1646  */
    {evt2(&(yyvsp[-1]),&(yyvsp[-2]),&(yyvsp[0]));evt1(&(yyval),&(yyvsp[-1]));}
#line 1942 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 232 "file.y" /* yacc.c:1646  */
    {evt2(&(yyvsp[-1]),&(yyvsp[-2]),&(yyvsp[0]));evt1(&(yyval),&(yyvsp[-1]));}
#line 1948 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 233 "file.y" /* yacc.c:1646  */
    {evt2(&(yyvsp[-1]),&(yyvsp[-2]),&(yyvsp[0]));evt1(&(yyval),&(yyvsp[-1]));}
#line 1954 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 234 "file.y" /* yacc.c:1646  */
    {evt2(&(yyvsp[-1]),&(yyvsp[-2]),&(yyvsp[0]));evt1(&(yyval),&(yyvsp[-1]));}
#line 1960 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 235 "file.y" /* yacc.c:1646  */
    {evt1(&(yyval),&(yyvsp[-1]));}
#line 1966 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 236 "file.y" /* yacc.c:1646  */
    {evt2(&(yyvsp[-1]),&(yyvsp[-2]),&(yyvsp[0]));evt1(&(yyval),&(yyvsp[-1]));}
#line 1972 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 237 "file.y" /* yacc.c:1646  */
    {evt2(&(yyvsp[-1]),&(yyvsp[-2]),&(yyvsp[0]));evt1(&(yyval),&(yyvsp[-1]));}
#line 1978 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 238 "file.y" /* yacc.c:1646  */
    {evt2(&(yyvsp[-1]),&(yyvsp[-2]),&(yyvsp[0]));evt1(&(yyval),&(yyvsp[-1]));}
#line 1984 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 239 "file.y" /* yacc.c:1646  */
    {evt2(&(yyvsp[-1]),&(yyvsp[-2]),&(yyvsp[0]));evt1(&(yyval),&(yyvsp[-1]));}
#line 1990 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 240 "file.y" /* yacc.c:1646  */
    {evt2(&(yyvsp[-1]),&(yyvsp[-2]),&(yyvsp[0]));evt1(&(yyval),&(yyvsp[-1]));}
#line 1996 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 241 "file.y" /* yacc.c:1646  */
    {evt2(&(yyvsp[-1]),&(yyvsp[-2]),&(yyvsp[0]));evt1(&(yyval),&(yyvsp[-1]));}
#line 2002 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 242 "file.y" /* yacc.c:1646  */
    {evt2(&(yyvsp[-1]),&(yyvsp[-2]),&(yyvsp[0]));evt1(&(yyval),&(yyvsp[-1]));}
#line 2008 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 243 "file.y" /* yacc.c:1646  */
    {evt2(&(yyvsp[-1]),&(yyvsp[-2]),&(yyvsp[0]));evt1(&(yyval),&(yyvsp[-1]));}
#line 2014 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 244 "file.y" /* yacc.c:1646  */
    {evt2(&(yyvsp[-1]),&(yyvsp[-2]),&(yyvsp[0]));evt1(&(yyval),&(yyvsp[-1]));}
#line 2020 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 245 "file.y" /* yacc.c:1646  */
    {evt2(&(yyvsp[-1]),&(yyvsp[-2]),&(yyvsp[0]));evt1(&(yyval),&(yyvsp[-1]));}
#line 2026 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 246 "file.y" /* yacc.c:1646  */
    {evt1(&(yyval),&(yyvsp[0]));}
#line 2032 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 247 "file.y" /* yacc.c:1646  */
    {evt1(&(yyval),&(yyvsp[0]));}
#line 2038 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 248 "file.y" /* yacc.c:1646  */
    {evt1(&(yyval),&(yyvsp[0]));}
#line 2044 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 249 "file.y" /* yacc.c:1646  */
    {evt1(&(yyval),&(yyvsp[0]));}
#line 2050 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 250 "file.y" /* yacc.c:1646  */
    {evt1(&(yyval),&(yyvsp[0]));}
#line 2056 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 251 "file.y" /* yacc.c:1646  */
    {evt1(&(yyval),&(yyvsp[0]));}
#line 2062 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 252 "file.y" /* yacc.c:1646  */
    {evt2(&(yyval),&(yyvsp[-3]),&(yyvsp[-1]));}
#line 2068 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 253 "file.y" /* yacc.c:1646  */
    {evt2(&(yyval),&(yyvsp[-3]),&(yyvsp[-1]));}
#line 2074 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 256 "file.y" /* yacc.c:1646  */
    {evt1(&(yyval),&(yyvsp[0]));}
#line 2080 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 257 "file.y" /* yacc.c:1646  */
    {evt1(&(yyval),&(yyvsp[0]));}
#line 2086 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 258 "file.y" /* yacc.c:1646  */
    {evt1(&(yyval),&(yyvsp[0]));}
#line 2092 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 259 "file.y" /* yacc.c:1646  */
    {evt1(&(yyval),&(yyvsp[-1]));}
#line 2098 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 262 "file.y" /* yacc.c:1646  */
    {(yyval).node = (container){2,2};(yyval).sz=1;}
#line 2104 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 263 "file.y" /* yacc.c:1646  */
    {(yyval).node = (container){2,2};(yyval).sz=1;}
#line 2110 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 266 "file.y" /* yacc.c:1646  */
    {(yyval).node = (container){2,2};(yyval).sz=1;}
#line 2116 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 267 "file.y" /* yacc.c:1646  */
    {(yyval).node = (container){2,2};(yyval).sz=1;}
#line 2122 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 271 "file.y" /* yacc.c:1646  */
    {(yyval).node = (container){2,2};(yyval).sz=1;if(strcmp(temp,"main")==0){in_main+=1;}}
#line 2128 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 274 "file.y" /* yacc.c:1646  */
    {evt1(&(yyval),&(yyvsp[0]));}
#line 2134 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 275 "file.y" /* yacc.c:1646  */
    {evt2(&(yyval),&(yyvsp[-2]),&(yyvsp[0]));}
#line 2140 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 278 "file.y" /* yacc.c:1646  */
    {evt1(&(yyval),&(yyvsp[0]));}
#line 2146 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 279 "file.y" /* yacc.c:1646  */
    {(yyval).node = (container){2,2};(yyval).sz=1;}
#line 2152 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2156 "y.tab.c" /* yacc.c:1646  */
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
#line 281 "file.y" /* yacc.c:1906  */



void yyerror(char *s) {
	printf("syntax error\n");
	exit(1);
}

int main(){
	yyparse();
    printf("%d\n",long_all);
   	printf("%d\n",long_if);
   	printf("%d\n",long_while);
   	printf("%d\n",long_switch);
   	printf("%d\n",long_main);
    return 0;
}
