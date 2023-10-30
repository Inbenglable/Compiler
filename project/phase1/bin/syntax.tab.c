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
    double d;

#line 160 "syntax.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SYNTAX_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 177 "syntax.tab.c" /* yacc.c:358  */

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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   755

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  103
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  190

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
       0,    34,    34,    40,    41,    43,    44,    45,    46,    47,
      51,    52,    53,    54,    57,    58,    60,    61,    65,    66,
      67,    71,    72,    73,    74,    76,    77,    79,    82,    85,
      86,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   110,   111,   113,   114,   116,   117,   120,   121,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     165,   167,   168,   169
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

#define YYPACT_NINF -103

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-103)))

#define YYTABLE_NINF -54

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      97,  -103,    16,     4,  -103,    97,    58,  -103,    -6,  -103,
    -103,  -103,    46,  -103,     7,    78,   -15,    52,    69,    54,
    -103,  -103,  -103,  -103,     7,    94,   266,  -103,   101,   101,
      68,   266,  -103,  -103,   101,     0,    93,  -103,    20,   296,
      -2,    95,    98,   100,  -103,  -103,    85,  -103,  -103,    97,
    -103,  -103,  -103,  -103,  -103,    90,   512,   105,   106,   107,
    -103,   512,   512,   512,  -103,   103,   296,   102,   512,  -103,
     101,  -103,  -103,   314,   127,   512,   432,    77,   303,    70,
     152,  -103,  -103,  -103,  -103,   512,    86,   284,   332,   342,
     350,   360,   123,   512,   378,   387,   396,   405,   414,   423,
     663,  -103,  -103,   486,  -103,   553,    35,  -103,  -103,   177,
     296,   202,   369,   126,  -103,  -103,   663,  -103,   303,  -103,
     303,  -103,    70,  -103,    70,  -103,   705,  -103,   684,  -103,
     227,  -103,   726,  -103,   726,  -103,   726,  -103,   726,  -103,
     726,  -103,   726,  -103,   486,  -103,  -103,   296,   296,  -103,
     296,   296,   441,   506,   494,  -103,  -103,  -103,   133,   143,
    -103,  -103,   296,   575,   450,   459,   530,   296,   296,  -103,
     296,   296,   597,   296,   619,   468,  -103,  -103,  -103,  -103,
     296,  -103,   296,   296,   641,  -103,  -103,  -103,   296,  -103
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,    14,     0,     0,     2,     4,     0,    15,    17,     1,
       3,     8,    18,     7,     0,     0,    10,     0,     0,     0,
      18,    12,     6,     5,    13,     0,     0,     9,     0,     0,
       0,     0,    24,    22,     0,     0,    26,    11,     0,    30,
      58,     0,    56,     0,    16,    52,    27,    23,    21,     0,
      20,    19,    97,    98,    99,    96,     0,     0,     0,     0,
      31,     0,     0,     0,    34,     0,    30,     0,     0,    55,
       0,    54,    25,     0,     0,     0,     0,     0,    87,    88,
       0,    28,    29,    33,    32,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      59,    57,    92,     0,    91,   103,     0,    36,    35,     0,
       0,     0,     0,     0,    86,    85,    60,    81,    69,    82,
      70,    83,    71,    84,    72,    73,    61,    74,    62,    95,
       0,    75,    63,    76,    64,    77,    65,    78,    66,    79,
      67,    80,    68,   101,   102,    90,    89,     0,     0,    41,
       0,     0,     0,     0,     0,    94,    93,   100,    38,    37,
      43,    40,     0,     0,     0,     0,     0,     0,     0,    51,
       0,     0,     0,     0,     0,     0,    42,    39,    48,    49,
       0,    50,     0,     0,     0,    45,    46,    47,     0,    44
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -103,  -103,   150,  -103,    43,    53,  -103,   -19,  -103,   -23,
    -103,   140,    92,  -102,    -8,  -103,   -26,  -103,   -56,   -92
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     5,    15,    29,     7,    16,    17,    35,
      36,    64,    65,    66,    30,    31,    41,    42,    67,   106
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      74,    47,    24,    43,     9,    78,    79,    80,   149,    40,
      40,   143,   100,    20,    25,    46,    68,   105,    39,   109,
     111,    50,     8,    45,    14,    18,    72,    25,    48,   116,
     118,   120,   122,   124,   126,   128,   145,   130,   132,   134,
     136,   138,   140,   142,   101,   158,   159,   105,   160,   161,
      51,    40,   157,     6,   113,    32,   153,    21,     6,    11,
     169,     1,     2,   146,    12,   176,   177,    37,   178,   179,
      28,   181,    34,    19,    13,    14,     1,     2,   185,    22,
     186,   187,    33,    26,     1,     2,   189,   117,   105,    52,
      53,    54,    55,   112,    23,    92,   163,    38,   166,    93,
      44,   -53,    34,    83,     1,     2,    61,    20,   172,   174,
      49,    69,    62,    63,    25,    70,    71,    73,    84,   184,
      85,    86,    87,    88,    89,    90,    91,    92,   107,   129,
      34,    93,    75,    76,    77,    81,    94,    95,    96,    97,
      98,    99,   154,   108,   167,    85,    86,    87,    88,    89,
      90,    91,    92,   114,   168,    10,    93,    27,    82,     0,
       0,    94,    95,    96,    97,    98,    99,     0,     0,     0,
      85,    86,    87,    88,    89,    90,    91,    92,   147,     0,
     115,    93,     0,     0,     0,     0,    94,    95,    96,    97,
      98,    99,     0,     0,     0,    85,    86,    87,    88,    89,
      90,    91,    92,   150,     0,   148,    93,     0,     0,     0,
       0,    94,    95,    96,    97,    98,    99,     0,     0,     0,
      85,    86,    87,    88,    89,    90,    91,    92,   155,     0,
     151,    93,     0,     0,     0,     0,    94,    95,    96,    97,
      98,    99,     0,     0,     0,    85,    86,    87,    88,    89,
      90,    91,    92,     0,     0,     0,    93,   156,     0,     0,
       0,    94,    95,    96,    97,    98,    99,    28,     0,   -53,
     -53,   -53,   -53,     1,     2,   -53,   -53,     0,   -53,   -53,
       0,     0,   -53,     0,     0,   119,   -53,    52,    53,    54,
      55,     0,   -53,   -53,     0,     0,     0,   -53,   -53,    52,
      53,    54,    55,     0,    61,    56,    57,     0,    58,    59,
      62,    63,    60,     0,     0,   102,    61,    52,    53,    54,
      55,     0,    62,    63,    88,    89,     0,    26,    92,     0,
       0,   103,    93,   121,    61,    52,    53,    54,    55,     0,
      62,    63,   104,   123,     0,    52,    53,    54,    55,     0,
       0,   125,    61,    52,    53,    54,    55,     0,    62,    63,
       0,   127,    61,    52,    53,    54,    55,     0,    62,    63,
      61,     0,    52,    53,    54,    55,    62,    63,     0,   131,
      61,    52,    53,    54,    55,   152,    62,    63,   133,    61,
      52,    53,    54,    55,     0,    62,    63,   135,    61,    52,
      53,    54,    55,     0,    62,    63,   137,    61,    52,    53,
      54,    55,     0,    62,    63,   139,    61,    52,    53,    54,
      55,     0,    62,    63,   141,    61,    52,    53,    54,    55,
       0,    62,    63,     0,    61,    52,    53,    54,    55,     0,
      62,    63,     0,    61,    52,    53,    54,    55,     0,    62,
      63,     0,    61,    52,    53,    54,    55,     0,    62,    63,
     110,    61,    52,    53,    54,    55,     0,    62,    63,   162,
      61,    52,    53,    54,    55,     0,    62,    63,   171,    61,
       0,     0,     0,     0,     0,    62,    63,   173,    61,    52,
      53,    54,    55,     0,    62,    63,   183,    52,    53,    54,
      55,     0,     0,   103,     0,     0,    61,     0,     0,     0,
     165,     0,    62,    63,    61,    52,    53,    54,    55,     0,
      62,    63,   164,     0,    85,    86,    87,    88,    89,    90,
      91,    92,    61,     0,     0,    93,     0,     0,    62,    63,
      94,    95,    96,    97,    98,    99,   175,     0,    85,    86,
      87,    88,    89,    90,    91,    92,     0,     0,     0,    93,
       0,     0,     0,     0,    94,    95,    96,    97,    98,    99,
     144,    85,    86,    87,    88,    89,    90,    91,    92,     0,
       0,     0,    93,     0,     0,     0,     0,    94,    95,    96,
      97,    98,    99,    85,    86,    87,    88,    89,    90,    91,
      92,     0,     0,   170,    93,     0,     0,     0,     0,    94,
      95,    96,    97,    98,    99,    85,    86,    87,    88,    89,
      90,    91,    92,     0,     0,   180,    93,     0,     0,     0,
       0,    94,    95,    96,    97,    98,    99,    85,    86,    87,
      88,    89,    90,    91,    92,     0,     0,   182,    93,     0,
       0,     0,     0,    94,    95,    96,    97,    98,    99,    85,
      86,    87,    88,    89,    90,    91,    92,     0,     0,   188,
      93,     0,     0,     0,     0,    94,    95,    96,    97,    98,
      99,    85,    86,    87,    88,    89,    90,    91,    92,     0,
       0,     0,    93,     0,     0,     0,     0,    94,    95,    96,
      97,    98,    99,    86,    87,    88,    89,    90,     0,    92,
       0,     0,     0,    93,     0,     0,     0,     0,    94,    95,
      96,    97,    98,    99,    86,    87,    88,    89,     0,     0,
      92,     0,     0,     0,    93,     0,     0,     0,     0,    94,
      95,    96,    97,    98,    99,    86,    87,    88,    89,     0,
       0,    92,     0,     0,     0,    93
};

static const yytype_int16 yycheck[] =
{
      56,     1,    17,    29,     0,    61,    62,    63,   110,    28,
      29,   103,    68,     6,    29,    34,    18,    73,    26,    75,
      76,     1,     6,    31,    17,    31,    49,    29,    28,    85,
      86,    87,    88,    89,    90,    91,     1,    93,    94,    95,
      96,    97,    98,    99,    70,   147,   148,   103,   150,   151,
      30,    70,   144,     0,    77,     1,   112,    14,     5,     1,
     162,     7,     8,    28,     6,   167,   168,    24,   170,   171,
       1,   173,    19,    27,    16,    17,     7,     8,   180,     1,
     182,   183,    28,    31,     7,     8,   188,     1,   144,     3,
       4,     5,     6,    16,    16,    25,   152,     3,   154,    29,
      32,    32,    49,     1,     7,     8,    20,     6,   164,   165,
      17,    16,    26,    27,    29,    17,    16,    27,    16,   175,
      18,    19,    20,    21,    22,    23,    24,    25,     1,     6,
      77,    29,    27,    27,    27,    32,    34,    35,    36,    37,
      38,    39,    16,    16,    11,    18,    19,    20,    21,    22,
      23,    24,    25,     1,    11,     5,    29,    17,    66,    -1,
      -1,    34,    35,    36,    37,    38,    39,    -1,    -1,    -1,
      18,    19,    20,    21,    22,    23,    24,    25,     1,    -1,
      28,    29,    -1,    -1,    -1,    -1,    34,    35,    36,    37,
      38,    39,    -1,    -1,    -1,    18,    19,    20,    21,    22,
      23,    24,    25,     1,    -1,    28,    29,    -1,    -1,    -1,
      -1,    34,    35,    36,    37,    38,    39,    -1,    -1,    -1,
      18,    19,    20,    21,    22,    23,    24,    25,     1,    -1,
      28,    29,    -1,    -1,    -1,    -1,    34,    35,    36,    37,
      38,    39,    -1,    -1,    -1,    18,    19,    20,    21,    22,
      23,    24,    25,    -1,    -1,    -1,    29,    30,    -1,    -1,
      -1,    34,    35,    36,    37,    38,    39,     1,    -1,     3,
       4,     5,     6,     7,     8,     9,    10,    -1,    12,    13,
      -1,    -1,    16,    -1,    -1,     1,    20,     3,     4,     5,
       6,    -1,    26,    27,    -1,    -1,    -1,    31,    32,     3,
       4,     5,     6,    -1,    20,     9,    10,    -1,    12,    13,
      26,    27,    16,    -1,    -1,     1,    20,     3,     4,     5,
       6,    -1,    26,    27,    21,    22,    -1,    31,    25,    -1,
      -1,    17,    29,     1,    20,     3,     4,     5,     6,    -1,
      26,    27,    28,     1,    -1,     3,     4,     5,     6,    -1,
      -1,     1,    20,     3,     4,     5,     6,    -1,    26,    27,
      -1,     1,    20,     3,     4,     5,     6,    -1,    26,    27,
      20,    -1,     3,     4,     5,     6,    26,    27,    -1,     1,
      20,     3,     4,     5,     6,    16,    26,    27,     1,    20,
       3,     4,     5,     6,    -1,    26,    27,     1,    20,     3,
       4,     5,     6,    -1,    26,    27,     1,    20,     3,     4,
       5,     6,    -1,    26,    27,     1,    20,     3,     4,     5,
       6,    -1,    26,    27,     1,    20,     3,     4,     5,     6,
      -1,    26,    27,    -1,    20,     3,     4,     5,     6,    -1,
      26,    27,    -1,    20,     3,     4,     5,     6,    -1,    26,
      27,    -1,    20,     3,     4,     5,     6,    -1,    26,    27,
      28,    20,     3,     4,     5,     6,    -1,    26,    27,    28,
      20,     3,     4,     5,     6,    -1,    26,    27,    28,    20,
      -1,    -1,    -1,    -1,    -1,    26,    27,    28,    20,     3,
       4,     5,     6,    -1,    26,    27,    28,     3,     4,     5,
       6,    -1,    -1,    17,    -1,    -1,    20,    -1,    -1,    -1,
      16,    -1,    26,    27,    20,     3,     4,     5,     6,    -1,
      26,    27,    16,    -1,    18,    19,    20,    21,    22,    23,
      24,    25,    20,    -1,    -1,    29,    -1,    -1,    26,    27,
      34,    35,    36,    37,    38,    39,    16,    -1,    18,    19,
      20,    21,    22,    23,    24,    25,    -1,    -1,    -1,    29,
      -1,    -1,    -1,    -1,    34,    35,    36,    37,    38,    39,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    -1,
      -1,    -1,    29,    -1,    -1,    -1,    -1,    34,    35,    36,
      37,    38,    39,    18,    19,    20,    21,    22,    23,    24,
      25,    -1,    -1,    28,    29,    -1,    -1,    -1,    -1,    34,
      35,    36,    37,    38,    39,    18,    19,    20,    21,    22,
      23,    24,    25,    -1,    -1,    28,    29,    -1,    -1,    -1,
      -1,    34,    35,    36,    37,    38,    39,    18,    19,    20,
      21,    22,    23,    24,    25,    -1,    -1,    28,    29,    -1,
      -1,    -1,    -1,    34,    35,    36,    37,    38,    39,    18,
      19,    20,    21,    22,    23,    24,    25,    -1,    -1,    28,
      29,    -1,    -1,    -1,    -1,    34,    35,    36,    37,    38,
      39,    18,    19,    20,    21,    22,    23,    24,    25,    -1,
      -1,    -1,    29,    -1,    -1,    -1,    -1,    34,    35,    36,
      37,    38,    39,    19,    20,    21,    22,    23,    -1,    25,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    34,    35,
      36,    37,    38,    39,    19,    20,    21,    22,    -1,    -1,
      25,    -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    34,
      35,    36,    37,    38,    39,    19,    20,    21,    22,    -1,
      -1,    25,    -1,    -1,    -1,    29
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,     8,    43,    44,    45,    47,    48,     6,     0,
      44,     1,     6,    16,    17,    46,    49,    50,    31,    27,
       6,    46,     1,    16,    17,    29,    31,    53,     1,    47,
      56,    57,     1,    28,    47,    51,    52,    46,     3,    56,
      49,    58,    59,    58,    32,    56,    49,     1,    28,    17,
       1,    30,     3,     4,     5,     6,     9,    10,    12,    13,
      16,    20,    26,    27,    53,    54,    55,    60,    18,    16,
      17,    16,    51,    27,    60,    27,    27,    27,    60,    60,
      60,    32,    54,     1,    16,    18,    19,    20,    21,    22,
      23,    24,    25,    29,    34,    35,    36,    37,    38,    39,
      60,    58,     1,    17,    28,    60,    61,     1,    16,    60,
      28,    60,    16,    51,     1,    28,    60,     1,    60,     1,
      60,     1,    60,     1,    60,     1,    60,     1,    60,     6,
      60,     1,    60,     1,    60,     1,    60,     1,    60,     1,
      60,     1,    60,    61,    17,     1,    28,     1,    28,    55,
       1,    28,    16,    60,    16,     1,    30,    61,    55,    55,
      55,    55,    28,    60,    16,    16,    60,    11,    11,    55,
      28,    28,    60,    28,    60,    16,    55,    55,    55,    55,
      28,    55,    28,    28,    60,    55,    55,    55,    28,    55
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    43,    44,    44,    45,    45,    45,    45,    45,
      46,    46,    46,    46,    47,    47,    48,    48,    49,    49,
      49,    50,    50,    50,    50,    51,    51,    52,    53,    54,
      54,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    56,    56,    57,    57,    58,    58,    59,    59,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      61,    61,    61,    61
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     3,     3,     2,     2,     3,
       1,     3,     2,     2,     1,     1,     5,     2,     1,     4,
       4,     4,     3,     4,     3,     3,     1,     2,     4,     2,
       0,     1,     2,     2,     1,     3,     3,     5,     5,     7,
       5,     4,     7,     5,     9,     8,     8,     8,     7,     7,
       7,     6,     2,     0,     3,     3,     1,     3,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     4,
       4,     3,     3,     4,     4,     3,     1,     1,     1,     1,
       3,     2,     2,     1
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
#line 34 "syntax.y" /* yacc.c:1646  */
    {
    (yyval.type) = getNode("Program", 1, (yyvsp[0].type));
    if(!hasError)
        writeNode((yyval.type), 0);
    }
#line 1496 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 40 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("ExtDefList", 2, (yyvsp[-1].type), (yyvsp[0].type));}
#line 1502 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 41 "syntax.y" /* yacc.c:1646  */
    {(yyval.type)=getTerminalNode("ExtDefList", -1);}
#line 1508 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 43 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("ExtDef", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1514 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 44 "syntax.y" /* yacc.c:1646  */
    {error_type = 1;yyerror("Missing semicolon ';'");}
#line 1520 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 45 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("ExtDef", 2, (yyvsp[-1].type), (yyvsp[0].type));}
#line 1526 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 46 "syntax.y" /* yacc.c:1646  */
    {error_type = 1;yyerror("Missing semicolon ';'");}
#line 1532 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 47 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("ExtDef", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1538 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 51 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("ExtDecList", 1, (yyvsp[0].type));}
#line 1544 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 52 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("ExtDecList", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1550 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 53 "syntax.y" /* yacc.c:1646  */
    {error_type = 1;yyerror("Unexpected ','");}
#line 1556 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 54 "syntax.y" /* yacc.c:1646  */
    {error_type = 1;yyerror("Unexpected ','");}
#line 1562 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 57 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Specifier", 1, (yyvsp[0].type));}
#line 1568 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 58 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Specifier", 1, (yyvsp[0].type));}
#line 1574 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 60 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("StructSpecifier", 5, (yyvsp[-4].type), (yyvsp[-3].type), (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1580 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 61 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("StructSpecifier", 2, (yyvsp[-1].type), (yyvsp[0].type));}
#line 1586 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 65 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("VarDec", 1, (yyvsp[0].type));}
#line 1592 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 66 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("VarDec", 4, (yyvsp[-3].type), (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1598 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 67 "syntax.y" /* yacc.c:1646  */
    {error_type = 1;yyerror("Missing closing symbol ']'");}
#line 1604 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 71 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("FunDec", 4, (yyvsp[-3].type), (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1610 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 72 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("FunDec", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1616 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 73 "syntax.y" /* yacc.c:1646  */
    {error_type = 1;yyerror("Missing closing symbol ')'");}
#line 1622 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 74 "syntax.y" /* yacc.c:1646  */
    {error_type = 1;yyerror("Missing closing symbol ')'");}
#line 1628 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 76 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("VarList", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1634 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 77 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("VarList", 1, (yyvsp[0].type));}
#line 1640 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 79 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("ParamDec", 2, (yyvsp[-1].type), (yyvsp[0].type));}
#line 1646 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 82 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("CompSt", 4, (yyvsp[-3].type), (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1652 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 85 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("StmtList", 2, (yyvsp[-1].type), (yyvsp[0].type));}
#line 1658 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 86 "syntax.y" /* yacc.c:1646  */
    {(yyval.type)=getTerminalNode("StmtList", -1);}
#line 1664 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 88 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Stmt", 1, (yyvsp[0].type));}
#line 1670 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 89 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Stmt", 2, (yyvsp[-1].type), (yyvsp[0].type));}
#line 1676 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 90 "syntax.y" /* yacc.c:1646  */
    {error_type = 1;yyerror("Missing semicolon ';'");}
#line 1682 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 91 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Stmt", 1, (yyvsp[0].type));}
#line 1688 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 92 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Stmt", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1694 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 93 "syntax.y" /* yacc.c:1646  */
    {error_type = 1;yyerror("Missing semicolon ';'");}
#line 1700 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 94 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Stmt", 5, (yyvsp[-4].type), (yyvsp[-3].type), (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1706 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 95 "syntax.y" /* yacc.c:1646  */
    {error_type = 1;yyerror("This if function miss closing symbol ')'");}
#line 1712 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 96 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Stmt", 7, (yyvsp[-6].type), (yyvsp[-5].type), (yyvsp[-4].type), (yyvsp[-3].type), (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1718 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 97 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Stmt", 5, (yyvsp[-4].type), (yyvsp[-3].type), (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1724 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 98 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Stmt", 4, (yyvsp[-3].type), (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1730 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 99 "syntax.y" /* yacc.c:1646  */
    {error_type = 1;yyerror("This if function miss closing symbol ')'");}
#line 1736 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 100 "syntax.y" /* yacc.c:1646  */
    {error_type = 1;yyerror("Missing closing symbol ')'");}
#line 1742 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 101 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Stmt", 9, (yyvsp[-8].type), (yyvsp[-7].type), (yyvsp[-6].type), (yyvsp[-5].type), (yyvsp[-4].type), (yyvsp[-3].type), (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1748 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 102 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Stmt", 8, (yyvsp[-7].type), (yyvsp[-6].type), (yyvsp[-5].type), (yyvsp[-4].type), (yyvsp[-3].type), (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1754 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 103 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Stmt", 8, (yyvsp[-7].type), (yyvsp[-6].type), (yyvsp[-5].type), (yyvsp[-4].type), (yyvsp[-3].type), (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1760 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 104 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Stmt", 8, (yyvsp[-7].type), (yyvsp[-6].type), (yyvsp[-5].type), (yyvsp[-4].type), (yyvsp[-3].type), (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1766 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 105 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Stmt", 7, (yyvsp[-6].type), (yyvsp[-5].type), (yyvsp[-4].type), (yyvsp[-3].type), (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1772 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 106 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Stmt", 7, (yyvsp[-6].type), (yyvsp[-5].type), (yyvsp[-4].type), (yyvsp[-3].type), (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1778 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 107 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Stmt", 7, (yyvsp[-6].type), (yyvsp[-5].type), (yyvsp[-4].type), (yyvsp[-3].type), (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1784 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 108 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Stmt", 6, (yyvsp[-5].type), (yyvsp[-4].type), (yyvsp[-3].type), (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1790 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 110 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("DefList", 2, (yyvsp[-1].type), (yyvsp[0].type));}
#line 1796 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 111 "syntax.y" /* yacc.c:1646  */
    {(yyval.type)=getTerminalNode("DefList", -1);}
#line 1802 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 113 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Def", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1808 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 114 "syntax.y" /* yacc.c:1646  */
    {error_type = 1; yyerror("Missing specifier");}
#line 1814 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 116 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("DecList", 1, (yyvsp[0].type));}
#line 1820 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 117 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("DecList", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1826 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 120 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Dec", 1, (yyvsp[0].type));}
#line 1832 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 121 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Dec", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1838 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 124 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Exp", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1844 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 125 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Exp", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1850 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 126 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Exp", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1856 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 127 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Exp", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1862 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 128 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Exp", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1868 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 129 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Exp", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1874 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 130 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Exp", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1880 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 131 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Exp", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1886 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 132 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Exp", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1892 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 133 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Exp", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1898 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 134 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Exp", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1904 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 135 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Exp", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1910 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 136 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Exp", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1916 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 137 "syntax.y" /* yacc.c:1646  */
    {error_type = 1; yyerror("Expect expression after 'ans'");}
#line 1922 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 138 "syntax.y" /* yacc.c:1646  */
    {error_type = 1; yyerror("Expect expression after 'or'");}
#line 1928 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 139 "syntax.y" /* yacc.c:1646  */
    {error_type = 1; yyerror("Expect expression after '<'");}
#line 1934 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 140 "syntax.y" /* yacc.c:1646  */
    {error_type = 1; yyerror("Expect expression after '<='");}
#line 1940 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 141 "syntax.y" /* yacc.c:1646  */
    {error_type = 1; yyerror("Expect expression after '>'");}
#line 1946 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 142 "syntax.y" /* yacc.c:1646  */
    {error_type = 1; yyerror("Expect expression after '>=");}
#line 1952 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 143 "syntax.y" /* yacc.c:1646  */
    {error_type = 1; yyerror("Expect expression after '!='");}
#line 1958 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 144 "syntax.y" /* yacc.c:1646  */
    {error_type = 1; yyerror("Expect expression after '=='");}
#line 1964 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 145 "syntax.y" /* yacc.c:1646  */
    {error_type = 1; yyerror("Expect expression after '+'");}
#line 1970 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 146 "syntax.y" /* yacc.c:1646  */
    {error_type = 1; yyerror("Expect expression after '-'");}
#line 1976 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 147 "syntax.y" /* yacc.c:1646  */
    {error_type = 1; yyerror("Expect expression after '*'");}
#line 1982 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 148 "syntax.y" /* yacc.c:1646  */
    {error_type = 1; yyerror("Expect expression after '/'");}
#line 1988 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 149 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Exp", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1994 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 150 "syntax.y" /* yacc.c:1646  */
    {error_type = 1;yyerror("Missing closing symbol ')'");}
#line 2000 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 151 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Exp", 2, (yyvsp[-1].type), (yyvsp[0].type));}
#line 2006 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 152 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Exp", 2, (yyvsp[-1].type), (yyvsp[0].type));}
#line 2012 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 153 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Exp", 4, (yyvsp[-3].type), (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 2018 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 154 "syntax.y" /* yacc.c:1646  */
    {error_type = 1;yyerror("Missing closing symbol ')'");}
#line 2024 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 155 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Exp", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 2030 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 156 "syntax.y" /* yacc.c:1646  */
    {error_type = 1;yyerror("Missing closing symbol ')'");}
#line 2036 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 157 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Exp", 4, (yyvsp[-3].type), (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 2042 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 158 "syntax.y" /* yacc.c:1646  */
    {error_type = 1;yyerror("Missing closing symbol ']'");}
#line 2048 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 159 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Exp", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 2054 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 160 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Exp", 1, (yyvsp[0].type));}
#line 2060 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 161 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Exp", 1, (yyvsp[0].type));}
#line 2066 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 162 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Exp", 1, (yyvsp[0].type));}
#line 2072 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 163 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Exp", 1, (yyvsp[0].type));}
#line 2078 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 165 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Args", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 2084 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 167 "syntax.y" /* yacc.c:1646  */
    {error_type = 1;yyerror("Unexpected ','");}
#line 2090 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 168 "syntax.y" /* yacc.c:1646  */
    {error_type = 1;yyerror("Expected another parenthesis after ','");}
#line 2096 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 169 "syntax.y" /* yacc.c:1646  */
    {(yyval.type) = getNode("Args", 1, (yyvsp[0].type));}
#line 2102 "syntax.tab.c" /* yacc.c:1646  */
    break;


#line 2106 "syntax.tab.c" /* yacc.c:1646  */
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
#line 172 "syntax.y" /* yacc.c:1906  */
