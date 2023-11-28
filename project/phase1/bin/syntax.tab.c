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
#line 1 "syntax.y" /* yacc.c:339  */

    #include<unistd.h>
    #include<stdio.h>   
    #include "structure.h"
    int yylex();

#line 73 "syntax.tab.c" /* yacc.c:339  */

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
   by #include "syntax.tab.h".  */
#ifndef YY_YY_SYNTAX_TAB_H_INCLUDED
# define YY_YY_SYNTAX_TAB_H_INCLUDED
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
    INT = 258,
    FLOAT = 259,
    CHAR = 260,
    ID = 261,
    TYPE = 262,
    STRUCT = 263,
    RETURN = 264,
    IF = 265,
    ELSE = 266,
    WHILE = 267,
    FOR = 268,
    COMMENT = 269,
    SPACE = 270,
    SEMI = 271,
    COMMA = 272,
    ASSIGN = 273,
    PLUS = 274,
    MINUS = 275,
    MUL = 276,
    DIV = 277,
    AND = 278,
    OR = 279,
    DOT = 280,
    NOT = 281,
    LP = 282,
    RP = 283,
    LB = 284,
    RB = 285,
    LC = 286,
    RC = 287,
    AERROR = 288,
    LT = 289,
    LE = 290,
    GT = 291,
    GE = 292,
    NE = 293,
    EQ = 294,
    EOL = 295,
    LOWER_THAN_ELSE = 296
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 8 "syntax.y" /* yacc.c:355  */

    nodePointer type;

#line 159 "syntax.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SYNTAX_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 176 "syntax.tab.c" /* yacc.c:358  */

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
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   767

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  108
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  198

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
static const yytype_uint8 yyrline[] =
{
       0,    33,    33,    39,    40,    42,    43,    44,    45,    46,
      47,    50,    51,    52,    53,    56,    57,    59,    60,    64,
      65,    66,    70,    71,    72,    73,    75,    76,    78,    79,
      80,    83,    86,    87,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   111,   112,   114,   115,   116,
     118,   119,   122,   123,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   168,   170,   171,   172
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "FLOAT", "CHAR", "ID", "TYPE",
  "STRUCT", "RETURN", "IF", "ELSE", "WHILE", "FOR", "COMMENT", "SPACE",
  "SEMI", "COMMA", "ASSIGN", "PLUS", "MINUS", "MUL", "DIV", "AND", "OR",
  "DOT", "NOT", "LP", "RP", "LB", "RB", "LC", "RC", "AERROR", "LT", "LE",
  "GT", "GE", "NE", "EQ", "EOL", "LOWER_THAN_ELSE", "$accept", "Program",
  "ExtDefList", "ExtDef", "ExtDecList", "Specifier", "StructSpecifier",
  "VarDec", "FunDec", "VarList", "ParamDec", "CompSt", "StmtList", "Stmt",
  "DefList", "Def", "DecList", "Dec", "Exp", "Args", YY_NULLPTR
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
     295,   296
};
# endif

#define YYPACT_NINF -107

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-107)))

#define YYTABLE_NINF -57

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     513,    58,  -107,    -4,     8,  -107,   513,    92,  -107,  -107,
      58,    10,    43,    19,  -107,  -107,  -107,    69,  -107,    12,
      54,  -107,  -107,    58,    24,    16,    62,  -107,  -107,   269,
    -107,  -107,     0,    94,    94,    70,   269,    94,  -107,   114,
      50,    93,   299,  -107,  -107,    66,   101,   116,    46,  -107,
    -107,    89,  -107,    89,  -107,  -107,   106,  -107,  -107,  -107,
     108,   524,   110,   111,   118,  -107,   524,   524,   524,  -107,
     104,   299,   105,   524,  -107,    94,  -107,  -107,    94,  -107,
     317,   130,   524,    77,   255,   306,    42,   155,  -107,  -107,
    -107,  -107,   287,   335,   345,   353,   363,   381,   390,   141,
     524,   399,   408,   417,   426,   435,   444,   675,  -107,  -107,
     498,  -107,   565,    64,  -107,  -107,   180,   299,   205,   372,
     142,  -107,  -107,  -107,   675,  -107,   306,  -107,   306,  -107,
      42,  -107,    42,  -107,   717,  -107,   696,  -107,   230,  -107,
     738,  -107,   738,  -107,   738,  -107,   738,  -107,   738,  -107,
     738,  -107,   498,  -107,  -107,   299,   299,  -107,   299,   299,
     453,   518,   506,  -107,  -107,  -107,   146,   149,  -107,  -107,
     299,   587,   462,   471,   542,   299,   299,  -107,   299,   299,
     609,   299,   631,   480,  -107,  -107,  -107,  -107,   299,  -107,
     299,   299,   653,  -107,  -107,  -107,   299,  -107
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    15,     0,     0,     2,     0,     0,    16,    19,
       0,     0,    11,    18,     1,     3,     8,    19,     7,     0,
       0,    13,    10,    14,     0,     0,     0,     6,     5,     0,
       9,    12,     0,     0,     0,     0,     0,    25,    23,     0,
       0,    27,    33,    21,    20,    62,     0,    60,     0,    17,
      55,    29,    30,    28,    24,    22,     0,   102,   103,   104,
     101,     0,     0,     0,     0,    34,     0,     0,     0,    37,
       0,    33,     0,     0,    58,     0,    59,    57,     0,    26,
       0,     0,     0,     0,     0,    92,    93,     0,    31,    32,
      36,    35,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    63,    61,    97,
       0,    96,   108,     0,    39,    38,     0,     0,     0,     0,
       0,    91,    90,    77,    64,    86,    73,    87,    74,    88,
      75,    89,    76,    78,    65,    79,    66,   100,     0,    80,
      67,    81,    68,    82,    69,    83,    70,    84,    71,    85,
      72,   106,   107,    95,    94,     0,     0,    44,     0,     0,
       0,     0,     0,    99,    98,   105,    41,    40,    46,    43,
       0,     0,     0,     0,     0,     0,     0,    54,     0,     0,
       0,     0,     0,     0,    45,    42,    51,    52,     0,    53,
       0,     0,     0,    48,    49,    50,     0,    47
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -107,  -107,   156,  -107,   109,     3,  -107,   -23,  -107,   -18,
    -107,   143,    90,  -102,   -11,  -107,   -14,  -107,   -61,  -106
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,    11,    34,     8,    12,    20,    40,
      41,    69,    70,    71,    35,    36,    46,    47,    72,   113
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      81,    43,    13,     7,   151,    85,    86,    87,    14,     7,
      45,    45,   107,    27,    51,   157,    53,    33,    42,   112,
      48,   116,   118,     2,     3,    50,    22,    32,    28,    39,
      44,   124,   126,   128,   130,   132,   134,   136,    79,   138,
     140,   142,   144,   146,   148,   150,   165,    76,   -56,   112,
      25,    54,    45,   166,   167,    51,   168,   169,   161,    39,
      23,   108,    77,    37,     9,   153,   120,    99,   177,     2,
       3,   100,    24,   184,   185,    10,   186,   187,    55,   189,
      57,    58,    59,    60,    73,    29,   193,    39,   194,   195,
      38,   112,   154,    16,   197,    24,    26,    66,    17,   171,
       9,   174,    49,    67,    68,   117,    90,    78,    18,    10,
      56,   180,   182,     2,     3,    52,    19,    74,    24,    21,
       9,    91,   192,    92,    93,    94,    95,    96,    97,    98,
      99,   114,    31,    75,   100,    80,    88,    82,    83,   101,
     102,   103,   104,   105,   106,    84,   115,   137,    92,    93,
      94,    95,    96,    97,    98,    99,   121,   175,   162,   100,
     176,    89,    15,    30,   101,   102,   103,   104,   105,   106,
       0,     0,     0,    92,    93,    94,    95,    96,    97,    98,
      99,   155,     0,   122,   100,     0,     0,     0,     0,   101,
     102,   103,   104,   105,   106,     0,     0,     0,    92,    93,
      94,    95,    96,    97,    98,    99,   158,     0,   156,   100,
       0,     0,     0,     0,   101,   102,   103,   104,   105,   106,
       0,     0,     0,    92,    93,    94,    95,    96,    97,    98,
      99,   163,     0,   159,   100,     0,     0,     0,     0,   101,
     102,   103,   104,   105,   106,     0,     0,     0,    92,    93,
      94,    95,    96,    97,    98,    99,    78,     0,     0,   100,
     164,     0,     2,     3,   101,   102,   103,   104,   105,   106,
      33,   119,   -56,   -56,   -56,   -56,     2,     3,   -56,   -56,
       0,   -56,   -56,     0,     0,   -56,     0,     0,   123,   -56,
      57,    58,    59,    60,     0,   -56,   -56,     0,     0,     0,
     -56,   -56,    57,    58,    59,    60,     0,    66,    61,    62,
       0,    63,    64,    67,    68,    65,     0,     0,   109,    66,
      57,    58,    59,    60,     0,    67,    68,    95,    96,     0,
      29,    99,     0,     0,   110,   100,   125,    66,    57,    58,
      59,    60,     0,    67,    68,   111,   127,     0,    57,    58,
      59,    60,     0,     0,   129,    66,    57,    58,    59,    60,
       0,    67,    68,     0,   131,    66,    57,    58,    59,    60,
       0,    67,    68,    66,     0,    57,    58,    59,    60,    67,
      68,     0,   133,    66,    57,    58,    59,    60,   160,    67,
      68,   135,    66,    57,    58,    59,    60,     0,    67,    68,
     139,    66,    57,    58,    59,    60,     0,    67,    68,   141,
      66,    57,    58,    59,    60,     0,    67,    68,   143,    66,
      57,    58,    59,    60,     0,    67,    68,   145,    66,    57,
      58,    59,    60,     0,    67,    68,   147,    66,    57,    58,
      59,    60,     0,    67,    68,   149,    66,    57,    58,    59,
      60,     0,    67,    68,     0,    66,    57,    58,    59,    60,
       0,    67,    68,     0,    66,    57,    58,    59,    60,     0,
      67,    68,     0,    66,    57,    58,    59,    60,     0,    67,
      68,   170,    66,    57,    58,    59,    60,     0,    67,    68,
     179,    66,     0,     0,     0,     0,     0,    67,    68,   181,
      66,    57,    58,    59,    60,     0,    67,    68,   191,    57,
      58,    59,    60,    -4,     1,   110,     0,     0,    66,     0,
       2,     3,   173,     0,    67,    68,    66,    57,    58,    59,
      60,     0,    67,    68,   172,     0,    92,    93,    94,    95,
      96,    97,    98,    99,    66,     0,     0,   100,     0,     0,
      67,    68,   101,   102,   103,   104,   105,   106,   183,     0,
      92,    93,    94,    95,    96,    97,    98,    99,     0,     0,
       0,   100,     0,     0,     0,     0,   101,   102,   103,   104,
     105,   106,   152,    92,    93,    94,    95,    96,    97,    98,
      99,     0,     0,     0,   100,     0,     0,     0,     0,   101,
     102,   103,   104,   105,   106,    92,    93,    94,    95,    96,
      97,    98,    99,     0,     0,   178,   100,     0,     0,     0,
       0,   101,   102,   103,   104,   105,   106,    92,    93,    94,
      95,    96,    97,    98,    99,     0,     0,   188,   100,     0,
       0,     0,     0,   101,   102,   103,   104,   105,   106,    92,
      93,    94,    95,    96,    97,    98,    99,     0,     0,   190,
     100,     0,     0,     0,     0,   101,   102,   103,   104,   105,
     106,    92,    93,    94,    95,    96,    97,    98,    99,     0,
       0,   196,   100,     0,     0,     0,     0,   101,   102,   103,
     104,   105,   106,    92,    93,    94,    95,    96,    97,    98,
      99,     0,     0,     0,   100,     0,     0,     0,     0,   101,
     102,   103,   104,   105,   106,    93,    94,    95,    96,    97,
       0,    99,     0,     0,     0,   100,     0,     0,     0,     0,
     101,   102,   103,   104,   105,   106,    93,    94,    95,    96,
       0,     0,    99,     0,     0,     0,   100,     0,     0,     0,
       0,   101,   102,   103,   104,   105,   106,    93,    94,    95,
      96,     0,     0,    99,     0,     0,     0,   100
};

static const yytype_int16 yycheck[] =
{
      61,     1,     6,     0,   110,    66,    67,    68,     0,     6,
      33,    34,    73,     1,    37,   117,    39,     1,    29,    80,
      34,    82,    83,     7,     8,    36,    16,     3,    16,    26,
      30,    92,    93,    94,    95,    96,    97,    98,    56,   100,
     101,   102,   103,   104,   105,   106,   152,     1,    32,   110,
      31,     1,    75,   155,   156,    78,   158,   159,   119,    56,
      17,    75,    16,     1,     6,     1,    84,    25,   170,     7,
       8,    29,    29,   175,   176,    17,   178,   179,    28,   181,
       3,     4,     5,     6,    18,    31,   188,    84,   190,   191,
      28,   152,    28,     1,   196,    29,    27,    20,     6,   160,
       6,   162,    32,    26,    27,    28,     1,     1,    16,    17,
      17,   172,   173,     7,     8,     1,     7,    16,    29,    10,
       6,    16,   183,    18,    19,    20,    21,    22,    23,    24,
      25,     1,    23,    17,    29,    27,    32,    27,    27,    34,
      35,    36,    37,    38,    39,    27,    16,     6,    18,    19,
      20,    21,    22,    23,    24,    25,     1,    11,    16,    29,
      11,    71,     6,    20,    34,    35,    36,    37,    38,    39,
      -1,    -1,    -1,    18,    19,    20,    21,    22,    23,    24,
      25,     1,    -1,    28,    29,    -1,    -1,    -1,    -1,    34,
      35,    36,    37,    38,    39,    -1,    -1,    -1,    18,    19,
      20,    21,    22,    23,    24,    25,     1,    -1,    28,    29,
      -1,    -1,    -1,    -1,    34,    35,    36,    37,    38,    39,
      -1,    -1,    -1,    18,    19,    20,    21,    22,    23,    24,
      25,     1,    -1,    28,    29,    -1,    -1,    -1,    -1,    34,
      35,    36,    37,    38,    39,    -1,    -1,    -1,    18,    19,
      20,    21,    22,    23,    24,    25,     1,    -1,    -1,    29,
      30,    -1,     7,     8,    34,    35,    36,    37,    38,    39,
       1,    16,     3,     4,     5,     6,     7,     8,     9,    10,
      -1,    12,    13,    -1,    -1,    16,    -1,    -1,     1,    20,
       3,     4,     5,     6,    -1,    26,    27,    -1,    -1,    -1,
      31,    32,     3,     4,     5,     6,    -1,    20,     9,    10,
      -1,    12,    13,    26,    27,    16,    -1,    -1,     1,    20,
       3,     4,     5,     6,    -1,    26,    27,    21,    22,    -1,
      31,    25,    -1,    -1,    17,    29,     1,    20,     3,     4,
       5,     6,    -1,    26,    27,    28,     1,    -1,     3,     4,
       5,     6,    -1,    -1,     1,    20,     3,     4,     5,     6,
      -1,    26,    27,    -1,     1,    20,     3,     4,     5,     6,
      -1,    26,    27,    20,    -1,     3,     4,     5,     6,    26,
      27,    -1,     1,    20,     3,     4,     5,     6,    16,    26,
      27,     1,    20,     3,     4,     5,     6,    -1,    26,    27,
       1,    20,     3,     4,     5,     6,    -1,    26,    27,     1,
      20,     3,     4,     5,     6,    -1,    26,    27,     1,    20,
       3,     4,     5,     6,    -1,    26,    27,     1,    20,     3,
       4,     5,     6,    -1,    26,    27,     1,    20,     3,     4,
       5,     6,    -1,    26,    27,     1,    20,     3,     4,     5,
       6,    -1,    26,    27,    -1,    20,     3,     4,     5,     6,
      -1,    26,    27,    -1,    20,     3,     4,     5,     6,    -1,
      26,    27,    -1,    20,     3,     4,     5,     6,    -1,    26,
      27,    28,    20,     3,     4,     5,     6,    -1,    26,    27,
      28,    20,    -1,    -1,    -1,    -1,    -1,    26,    27,    28,
      20,     3,     4,     5,     6,    -1,    26,    27,    28,     3,
       4,     5,     6,     0,     1,    17,    -1,    -1,    20,    -1,
       7,     8,    16,    -1,    26,    27,    20,     3,     4,     5,
       6,    -1,    26,    27,    16,    -1,    18,    19,    20,    21,
      22,    23,    24,    25,    20,    -1,    -1,    29,    -1,    -1,
      26,    27,    34,    35,    36,    37,    38,    39,    16,    -1,
      18,    19,    20,    21,    22,    23,    24,    25,    -1,    -1,
      -1,    29,    -1,    -1,    -1,    -1,    34,    35,    36,    37,
      38,    39,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    34,
      35,    36,    37,    38,    39,    18,    19,    20,    21,    22,
      23,    24,    25,    -1,    -1,    28,    29,    -1,    -1,    -1,
      -1,    34,    35,    36,    37,    38,    39,    18,    19,    20,
      21,    22,    23,    24,    25,    -1,    -1,    28,    29,    -1,
      -1,    -1,    -1,    34,    35,    36,    37,    38,    39,    18,
      19,    20,    21,    22,    23,    24,    25,    -1,    -1,    28,
      29,    -1,    -1,    -1,    -1,    34,    35,    36,    37,    38,
      39,    18,    19,    20,    21,    22,    23,    24,    25,    -1,
      -1,    28,    29,    -1,    -1,    -1,    -1,    34,    35,    36,
      37,    38,    39,    18,    19,    20,    21,    22,    23,    24,
      25,    -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    34,
      35,    36,    37,    38,    39,    19,    20,    21,    22,    23,
      -1,    25,    -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,
      34,    35,    36,    37,    38,    39,    19,    20,    21,    22,
      -1,    -1,    25,    -1,    -1,    -1,    29,    -1,    -1,    -1,
      -1,    34,    35,    36,    37,    38,    39,    19,    20,    21,
      22,    -1,    -1,    25,    -1,    -1,    -1,    29
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     7,     8,    43,    44,    45,    47,    48,     6,
      17,    46,    49,     6,     0,    44,     1,     6,    16,    46,
      50,    46,    16,    17,    29,    31,    27,     1,    16,    31,
      53,    46,     3,     1,    47,    56,    57,     1,    28,    47,
      51,    52,    56,     1,    30,    49,    58,    59,    58,    32,
      56,    49,     1,    49,     1,    28,    17,     3,     4,     5,
       6,     9,    10,    12,    13,    16,    20,    26,    27,    53,
      54,    55,    60,    18,    16,    17,     1,    16,     1,    51,
      27,    60,    27,    27,    27,    60,    60,    60,    32,    54,
       1,    16,    18,    19,    20,    21,    22,    23,    24,    25,
      29,    34,    35,    36,    37,    38,    39,    60,    58,     1,
      17,    28,    60,    61,     1,    16,    60,    28,    60,    16,
      51,     1,    28,     1,    60,     1,    60,     1,    60,     1,
      60,     1,    60,     1,    60,     1,    60,     6,    60,     1,
      60,     1,    60,     1,    60,     1,    60,     1,    60,     1,
      60,    61,    17,     1,    28,     1,    28,    55,     1,    28,
      16,    60,    16,     1,    30,    61,    55,    55,    55,    55,
      28,    60,    16,    16,    60,    11,    11,    55,    28,    28,
      60,    28,    60,    16,    55,    55,    55,    55,    28,    55,
      28,    28,    60,    55,    55,    55,    28,    55
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    43,    44,    44,    45,    45,    45,    45,    45,
      45,    46,    46,    46,    46,    47,    47,    48,    48,    49,
      49,    49,    50,    50,    50,    50,    51,    51,    52,    52,
      52,    53,    54,    54,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    56,    56,    57,    57,    57,
      58,    58,    59,    59,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    61,    61,    61,    61
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     3,     3,     2,     2,     3,
       3,     1,     3,     2,     2,     1,     1,     5,     2,     1,
       4,     4,     4,     3,     4,     3,     3,     1,     2,     2,
       2,     4,     2,     0,     1,     2,     2,     1,     3,     3,
       5,     5,     7,     5,     4,     7,     5,     9,     8,     8,
       8,     7,     7,     7,     6,     2,     0,     3,     3,     3,
       1,     3,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     2,     4,     4,     3,     3,     4,     4,
       3,     1,     1,     1,     1,     3,     2,     2,     1
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
#line 33 "syntax.y" /* yacc.c:1646  */
    {
    (yyval.type) = getNode("Program", 1, (yyvsp[0].type));
    if(!hasError)
        writeNode((yyval.type), 0);
    }
#line 1500 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 39 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("ExtDefList", 2, (yyvsp[-1].type), (yyvsp[0].type));}
#line 1506 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 40 "syntax.y" /* yacc.c:1646  */
    {(yyval.type)=getTerminalNode("ExtDefList", -1);}
#line 1512 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 42 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("ExtDef", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1518 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 43 "syntax.y" /* yacc.c:1646  */
    {error_type = 1;yyerror("Missing semicolon ';'");}
#line 1524 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 44 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("ExtDef", 2, (yyvsp[-1].type), (yyvsp[0].type));}
#line 1530 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 45 "syntax.y" /* yacc.c:1646  */
    {error_type = 1;yyerror("Missing semicolon ';'");}
#line 1536 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 46 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("ExtDef", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1542 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 47 "syntax.y" /* yacc.c:1646  */
    {error_type = 1; yyerror("Missing specifier");}
#line 1548 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 50 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("ExtDecList", 1, (yyvsp[0].type));}
#line 1554 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 51 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("ExtDecList", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1560 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 52 "syntax.y" /* yacc.c:1646  */
    {error_type = 1;yyerror("Unexpected ','");}
#line 1566 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 53 "syntax.y" /* yacc.c:1646  */
    {error_type = 1;yyerror("Unexpected ','");}
#line 1572 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 56 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Specifier", 1, (yyvsp[0].type));}
#line 1578 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 57 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Specifier", 1, (yyvsp[0].type));}
#line 1584 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 59 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("StructSpecifier", 5, (yyvsp[-4].type), (yyvsp[-3].type), (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1590 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 60 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("StructSpecifier", 2, (yyvsp[-1].type), (yyvsp[0].type));}
#line 1596 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 64 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("VarDec", 1, (yyvsp[0].type));}
#line 1602 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 65 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("VarDec", 4, (yyvsp[-3].type), (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1608 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 66 "syntax.y" /* yacc.c:1646  */
    {error_type = 1;yyerror("Missing closing symbol ']'");}
#line 1614 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 70 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("FunDec", 4, (yyvsp[-3].type), (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1620 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 71 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("FunDec", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1626 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 72 "syntax.y" /* yacc.c:1646  */
    {error_type = 1;yyerror("Missing closing symbol ')'");}
#line 1632 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 73 "syntax.y" /* yacc.c:1646  */
    {error_type = 1;yyerror("Missing closing symbol ')'");}
#line 1638 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 75 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("VarList", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1644 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 76 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("VarList", 1, (yyvsp[0].type));}
#line 1650 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 78 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("ParamDec", 2, (yyvsp[-1].type), (yyvsp[0].type));}
#line 1656 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 79 "syntax.y" /* yacc.c:1646  */
    {error_type = 1;yyerror("Missing specifier");}
#line 1662 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 80 "syntax.y" /* yacc.c:1646  */
    {error_type = 1;yyerror("Missing variable name");}
#line 1668 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 83 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("CompSt", 4, (yyvsp[-3].type), (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1674 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 86 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("StmtList", 2, (yyvsp[-1].type), (yyvsp[0].type));}
#line 1680 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 87 "syntax.y" /* yacc.c:1646  */
    {(yyval.type)=getTerminalNode("StmtList", -1);}
#line 1686 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 89 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Stmt", 1, (yyvsp[0].type));}
#line 1692 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 90 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Stmt", 2, (yyvsp[-1].type), (yyvsp[0].type));}
#line 1698 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 91 "syntax.y" /* yacc.c:1646  */
    {error_type = 1;yyerror("Missing semicolon ';'");}
#line 1704 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 92 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Stmt", 1, (yyvsp[0].type));}
#line 1710 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 93 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Stmt", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1716 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 94 "syntax.y" /* yacc.c:1646  */
    {error_type = 1;yyerror("Missing semicolon ';'");}
#line 1722 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 95 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Stmt", 5, (yyvsp[-4].type), (yyvsp[-3].type), (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1728 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 96 "syntax.y" /* yacc.c:1646  */
    {error_type = 1;yyerror("This if function miss closing symbol ')'");}
#line 1734 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 97 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Stmt", 7, (yyvsp[-6].type), (yyvsp[-5].type), (yyvsp[-4].type), (yyvsp[-3].type), (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1740 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 98 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Stmt", 5, (yyvsp[-4].type), (yyvsp[-3].type), (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1746 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 99 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Stmt", 4, (yyvsp[-3].type), (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1752 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 100 "syntax.y" /* yacc.c:1646  */
    {error_type = 1;yyerror("This if function miss closing symbol ')'");}
#line 1758 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 101 "syntax.y" /* yacc.c:1646  */
    {error_type = 1;yyerror("Missing closing symbol ')'");}
#line 1764 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 102 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Stmt", 9, (yyvsp[-8].type), (yyvsp[-7].type), (yyvsp[-6].type), (yyvsp[-5].type), (yyvsp[-4].type), (yyvsp[-3].type), (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1770 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 103 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Stmt", 8, (yyvsp[-7].type), (yyvsp[-6].type), (yyvsp[-5].type), (yyvsp[-4].type), (yyvsp[-3].type), (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1776 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 104 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Stmt", 8, (yyvsp[-7].type), (yyvsp[-6].type), (yyvsp[-5].type), (yyvsp[-4].type), (yyvsp[-3].type), (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1782 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 105 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Stmt", 8, (yyvsp[-7].type), (yyvsp[-6].type), (yyvsp[-5].type), (yyvsp[-4].type), (yyvsp[-3].type), (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1788 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 106 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Stmt", 7, (yyvsp[-6].type), (yyvsp[-5].type), (yyvsp[-4].type), (yyvsp[-3].type), (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1794 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 107 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Stmt", 7, (yyvsp[-6].type), (yyvsp[-5].type), (yyvsp[-4].type), (yyvsp[-3].type), (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1800 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 108 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Stmt", 7, (yyvsp[-6].type), (yyvsp[-5].type), (yyvsp[-4].type), (yyvsp[-3].type), (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1806 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 109 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Stmt", 6, (yyvsp[-5].type), (yyvsp[-4].type), (yyvsp[-3].type), (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1812 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 111 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("DefList", 2, (yyvsp[-1].type), (yyvsp[0].type));}
#line 1818 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 112 "syntax.y" /* yacc.c:1646  */
    {(yyval.type)=getTerminalNode("DefList", -1);}
#line 1824 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 114 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Def", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1830 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 115 "syntax.y" /* yacc.c:1646  */
    {error_type = 1; yyerror("Missing specifier");}
#line 1836 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 116 "syntax.y" /* yacc.c:1646  */
    {error_type = 1; yyerror("Missing semicolon ';'");}
#line 1842 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 118 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("DecList", 1, (yyvsp[0].type));}
#line 1848 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 119 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("DecList", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1854 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 122 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Dec", 1, (yyvsp[0].type));}
#line 1860 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 123 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Dec", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1866 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 126 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Exp", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1872 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 127 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Exp", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1878 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 128 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Exp", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1884 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 129 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Exp", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1890 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 130 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Exp", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1896 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 131 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Exp", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1902 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 132 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Exp", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1908 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 133 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Exp", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1914 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 134 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Exp", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1920 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 135 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Exp", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1926 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 136 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Exp", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1932 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 137 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Exp", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1938 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 138 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Exp", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1944 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 139 "syntax.y" /* yacc.c:1646  */
    {error_type = 1; yyerror("Expect expression after '='");}
#line 1950 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 140 "syntax.y" /* yacc.c:1646  */
    {error_type = 1; yyerror("Expect expression after 'ans'");}
#line 1956 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 141 "syntax.y" /* yacc.c:1646  */
    {error_type = 1; yyerror("Expect expression after 'or'");}
#line 1962 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 142 "syntax.y" /* yacc.c:1646  */
    {error_type = 1; yyerror("Expect expression after '<'");}
#line 1968 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 143 "syntax.y" /* yacc.c:1646  */
    {error_type = 1; yyerror("Expect expression after '<='");}
#line 1974 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 144 "syntax.y" /* yacc.c:1646  */
    {error_type = 1; yyerror("Expect expression after '>'");}
#line 1980 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 145 "syntax.y" /* yacc.c:1646  */
    {error_type = 1; yyerror("Expect expression after '>=");}
#line 1986 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 146 "syntax.y" /* yacc.c:1646  */
    {error_type = 1; yyerror("Expect expression after '!='");}
#line 1992 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 147 "syntax.y" /* yacc.c:1646  */
    {error_type = 1; yyerror("Expect expression after '=='");}
#line 1998 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 148 "syntax.y" /* yacc.c:1646  */
    {error_type = 1; yyerror("Expect expression after '+'");}
#line 2004 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 149 "syntax.y" /* yacc.c:1646  */
    {error_type = 1; yyerror("Expect expression after '-'");}
#line 2010 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 150 "syntax.y" /* yacc.c:1646  */
    {error_type = 1; yyerror("Expect expression after '*'");}
#line 2016 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 151 "syntax.y" /* yacc.c:1646  */
    {error_type = 1; yyerror("Expect expression after '/'");}
#line 2022 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 152 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Exp", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 2028 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 153 "syntax.y" /* yacc.c:1646  */
    {error_type = 1;yyerror("Missing closing symbol ')'");}
#line 2034 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 154 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Exp", 2, (yyvsp[-1].type), (yyvsp[0].type));}
#line 2040 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 155 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Exp", 2, (yyvsp[-1].type), (yyvsp[0].type));}
#line 2046 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 156 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Exp", 4, (yyvsp[-3].type), (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 2052 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 157 "syntax.y" /* yacc.c:1646  */
    {error_type = 1;yyerror("Missing closing symbol ')'");}
#line 2058 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 158 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Exp", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 2064 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 159 "syntax.y" /* yacc.c:1646  */
    {error_type = 1;yyerror("Missing closing symbol ')'");}
#line 2070 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 160 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Exp", 4, (yyvsp[-3].type), (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 2076 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 161 "syntax.y" /* yacc.c:1646  */
    {error_type = 1;yyerror("Missing closing symbol ']'");}
#line 2082 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 162 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Exp", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 2088 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 163 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Exp", 1, (yyvsp[0].type));}
#line 2094 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 164 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Exp", 1, (yyvsp[0].type));}
#line 2100 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 165 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Exp", 1, (yyvsp[0].type));}
#line 2106 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 166 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Exp", 1, (yyvsp[0].type));}
#line 2112 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 168 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Args", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 2118 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 170 "syntax.y" /* yacc.c:1646  */
    {error_type = 1;yyerror("Unexpected ','");}
#line 2124 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 171 "syntax.y" /* yacc.c:1646  */
    {error_type = 1;yyerror("Expected another parenthesis after ','");}
#line 2130 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 172 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Args", 1, (yyvsp[0].type));}
#line 2136 "syntax.tab.c" /* yacc.c:1646  */
    break;


#line 2140 "syntax.tab.c" /* yacc.c:1646  */
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
#line 175 "syntax.y" /* yacc.c:1906  */
