/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "syntax.y"

    #include<unistd.h>
    #include<stdio.h>   
    #include "structure.h"
    int yylex();

#line 78 "syntax.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "syntax.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INT = 3,                        /* INT  */
  YYSYMBOL_FLOAT = 4,                      /* FLOAT  */
  YYSYMBOL_CHAR = 5,                       /* CHAR  */
  YYSYMBOL_ID = 6,                         /* ID  */
  YYSYMBOL_TYPE = 7,                       /* TYPE  */
  YYSYMBOL_STRUCT = 8,                     /* STRUCT  */
  YYSYMBOL_RETURN = 9,                     /* RETURN  */
  YYSYMBOL_IF = 10,                        /* IF  */
  YYSYMBOL_ELSE = 11,                      /* ELSE  */
  YYSYMBOL_WHILE = 12,                     /* WHILE  */
  YYSYMBOL_FOR = 13,                       /* FOR  */
  YYSYMBOL_COMMENT = 14,                   /* COMMENT  */
  YYSYMBOL_SPACE = 15,                     /* SPACE  */
  YYSYMBOL_SEMI = 16,                      /* SEMI  */
  YYSYMBOL_COMMA = 17,                     /* COMMA  */
  YYSYMBOL_ASSIGN = 18,                    /* ASSIGN  */
  YYSYMBOL_PLUS = 19,                      /* PLUS  */
  YYSYMBOL_MINUS = 20,                     /* MINUS  */
  YYSYMBOL_MUL = 21,                       /* MUL  */
  YYSYMBOL_DIV = 22,                       /* DIV  */
  YYSYMBOL_AND = 23,                       /* AND  */
  YYSYMBOL_OR = 24,                        /* OR  */
  YYSYMBOL_DOT = 25,                       /* DOT  */
  YYSYMBOL_NOT = 26,                       /* NOT  */
  YYSYMBOL_LP = 27,                        /* LP  */
  YYSYMBOL_RP = 28,                        /* RP  */
  YYSYMBOL_LB = 29,                        /* LB  */
  YYSYMBOL_RB = 30,                        /* RB  */
  YYSYMBOL_LC = 31,                        /* LC  */
  YYSYMBOL_RC = 32,                        /* RC  */
  YYSYMBOL_AERROR = 33,                    /* AERROR  */
  YYSYMBOL_LT = 34,                        /* LT  */
  YYSYMBOL_LE = 35,                        /* LE  */
  YYSYMBOL_GT = 36,                        /* GT  */
  YYSYMBOL_GE = 37,                        /* GE  */
  YYSYMBOL_NE = 38,                        /* NE  */
  YYSYMBOL_EQ = 39,                        /* EQ  */
  YYSYMBOL_EOL = 40,                       /* EOL  */
  YYSYMBOL_LOWER_THAN_ELSE = 41,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_YYACCEPT = 42,                  /* $accept  */
  YYSYMBOL_Program = 43,                   /* Program  */
  YYSYMBOL_ExtDefList = 44,                /* ExtDefList  */
  YYSYMBOL_ExtDef = 45,                    /* ExtDef  */
  YYSYMBOL_ExtDecList = 46,                /* ExtDecList  */
  YYSYMBOL_Specifier = 47,                 /* Specifier  */
  YYSYMBOL_StructSpecifier = 48,           /* StructSpecifier  */
  YYSYMBOL_VarDec = 49,                    /* VarDec  */
  YYSYMBOL_FunDec = 50,                    /* FunDec  */
  YYSYMBOL_VarList = 51,                   /* VarList  */
  YYSYMBOL_ParamDec = 52,                  /* ParamDec  */
  YYSYMBOL_CompSt = 53,                    /* CompSt  */
  YYSYMBOL_StmtList = 54,                  /* StmtList  */
  YYSYMBOL_Stmt = 55,                      /* Stmt  */
  YYSYMBOL_DefList = 56,                   /* DefList  */
  YYSYMBOL_Def = 57,                       /* Def  */
  YYSYMBOL_DecList = 58,                   /* DecList  */
  YYSYMBOL_Dec = 59,                       /* Dec  */
  YYSYMBOL_Exp = 60,                       /* Exp  */
  YYSYMBOL_Args = 61                       /* Args  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
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
#define YYLAST   730

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  103
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  188

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   296


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      67,    71,    72,    73,    74,    76,    77,    79,    82,    83,
      85,    86,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   110,   111,   113,   116,   117,   120,   121,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     165,   167,   168,   169
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INT", "FLOAT", "CHAR",
  "ID", "TYPE", "STRUCT", "RETURN", "IF", "ELSE", "WHILE", "FOR",
  "COMMENT", "SPACE", "SEMI", "COMMA", "ASSIGN", "PLUS", "MINUS", "MUL",
  "DIV", "AND", "OR", "DOT", "NOT", "LP", "RP", "LB", "RB", "LC", "RC",
  "AERROR", "LT", "LE", "GT", "GE", "NE", "EQ", "EOL", "LOWER_THAN_ELSE",
  "$accept", "Program", "ExtDefList", "ExtDef", "ExtDecList", "Specifier",
  "StructSpecifier", "VarDec", "FunDec", "VarList", "ParamDec", "CompSt",
  "StmtList", "Stmt", "DefList", "Def", "DecList", "Dec", "Exp", "Args", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-101)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      82,  -101,    -2,    59,  -101,    82,     8,  -101,    36,  -101,
    -101,  -101,    58,  -101,    -4,    56,    41,    61,    82,    54,
    -101,  -101,  -101,  -101,    -4,    84,    82,  -101,    89,    67,
      82,  -101,  -101,    89,     0,    83,  -101,    22,   264,    45,
      86,    94,  -101,  -101,    87,  -101,  -101,    82,  -101,  -101,
    -101,  -101,  -101,    88,   498,    90,   103,   105,  -101,   498,
     498,   498,  -101,    19,   264,   102,   498,  -101,    89,  -101,
     282,   127,   498,   418,    68,    72,    48,   152,  -101,  -101,
    -101,  -101,  -101,   498,   300,   310,   318,   328,   346,   355,
     106,   498,   364,   373,   382,   391,   400,   409,   649,  -101,
    -101,   472,  -101,   539,    25,  -101,  -101,   177,   264,   202,
     337,    97,  -101,  -101,   649,  -101,    72,  -101,    72,  -101,
      48,  -101,    48,  -101,   691,  -101,   670,  -101,   227,  -101,
      85,  -101,    85,  -101,    85,  -101,    85,  -101,    85,  -101,
      85,  -101,   472,  -101,  -101,   264,   264,  -101,   264,   264,
     427,   492,   480,  -101,  -101,  -101,   118,   122,  -101,  -101,
     264,   561,   436,   445,   516,   264,   264,  -101,   264,   264,
     583,   264,   605,   454,  -101,  -101,  -101,  -101,   264,  -101,
     264,   264,   627,  -101,  -101,  -101,   264,  -101
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,    14,     0,     0,     2,     4,     0,    15,    17,     1,
       3,     8,    18,     7,     0,     0,    10,     0,    54,     0,
      18,    12,     6,     5,    13,     0,    54,     9,     0,     0,
      54,    24,    22,     0,     0,    26,    11,     0,    31,    58,
       0,    56,    16,    53,    27,    23,    21,     0,    20,    19,
      97,    98,    99,    96,     0,     0,     0,     0,    32,     0,
       0,     0,    35,     0,    31,     0,     0,    55,     0,    25,
       0,     0,     0,     0,     0,    87,    88,     0,    29,    28,
      30,    34,    33,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    59,    57,
      92,     0,    91,   103,     0,    37,    36,     0,     0,     0,
       0,     0,    86,    85,    60,    81,    69,    82,    70,    83,
      71,    84,    72,    73,    61,    74,    62,    95,     0,    75,
      63,    76,    64,    77,    65,    78,    66,    79,    67,    80,
      68,   101,   102,    90,    89,     0,     0,    42,     0,     0,
       0,     0,     0,    94,    93,   100,    39,    38,    44,    41,
       0,     0,     0,     0,     0,     0,     0,    52,     0,     0,
       0,     0,     0,     0,    43,    40,    49,    50,     0,    51,
       0,     0,     0,    46,    47,    48,     0,    45
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -101,  -101,   129,  -101,    -3,    17,  -101,   -18,  -101,   -20,
    -101,   125,    71,  -100,    53,  -101,    76,  -101,   -54,   -98
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     3,     4,     5,    15,    28,     7,    16,    17,    34,
      35,    62,    63,    64,    29,    30,    40,    41,    65,   104
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      71,    45,    20,   141,     8,    75,    76,    77,   147,    11,
      39,    21,    98,    14,    12,    44,   103,     6,   107,   109,
      78,    36,     6,    48,    13,    14,   143,    69,    46,   114,
     116,   118,   120,   122,   124,   126,    33,   128,   130,   132,
     134,   136,   138,   140,   155,   156,   157,   103,   158,   159,
      39,    79,    49,   144,   111,    31,   151,    22,    24,     9,
     167,     1,     2,    66,    33,   174,   175,    18,   176,   177,
      25,   179,    23,    90,    25,     1,     2,    91,   183,    38,
     184,   185,    32,    43,   110,    19,   187,    37,   103,     1,
       2,    33,    26,    86,    87,    20,   161,    90,   164,    42,
      47,    91,    67,    81,    84,    85,    86,    87,   170,   172,
      90,    68,   127,   152,    91,    70,    25,    72,    82,   182,
      83,    84,    85,    86,    87,    88,    89,    90,   105,   165,
      73,    91,    74,   166,    10,    80,    92,    93,    94,    95,
      96,    97,    27,   106,    99,    83,    84,    85,    86,    87,
      88,    89,    90,   112,     0,     0,    91,     0,     0,     0,
       0,    92,    93,    94,    95,    96,    97,     0,     0,     0,
      83,    84,    85,    86,    87,    88,    89,    90,   145,     0,
     113,    91,     0,     0,     0,     0,    92,    93,    94,    95,
      96,    97,     0,     0,     0,    83,    84,    85,    86,    87,
      88,    89,    90,   148,     0,   146,    91,     0,     0,     0,
       0,    92,    93,    94,    95,    96,    97,     0,     0,     0,
      83,    84,    85,    86,    87,    88,    89,    90,   153,     0,
     149,    91,     0,     0,     0,     0,    92,    93,    94,    95,
      96,    97,     0,     0,     0,    83,    84,    85,    86,    87,
      88,    89,    90,     0,     0,     0,    91,   154,     0,     0,
       0,    92,    93,    94,    95,    96,    97,    50,    51,    52,
      53,     0,     0,    54,    55,     0,    56,    57,     0,     0,
      58,     0,     0,   100,    59,    50,    51,    52,    53,     0,
      60,    61,     0,     0,     0,    26,     0,     0,     0,   101,
       0,   115,    59,    50,    51,    52,    53,     0,    60,    61,
     102,   117,     0,    50,    51,    52,    53,     0,     0,   119,
      59,    50,    51,    52,    53,     0,    60,    61,     0,   121,
      59,    50,    51,    52,    53,     0,    60,    61,    59,     0,
      50,    51,    52,    53,    60,    61,     0,   123,    59,    50,
      51,    52,    53,   150,    60,    61,   125,    59,    50,    51,
      52,    53,     0,    60,    61,   129,    59,    50,    51,    52,
      53,     0,    60,    61,   131,    59,    50,    51,    52,    53,
       0,    60,    61,   133,    59,    50,    51,    52,    53,     0,
      60,    61,   135,    59,    50,    51,    52,    53,     0,    60,
      61,   137,    59,    50,    51,    52,    53,     0,    60,    61,
     139,    59,    50,    51,    52,    53,     0,    60,    61,     0,
      59,    50,    51,    52,    53,     0,    60,    61,     0,    59,
      50,    51,    52,    53,     0,    60,    61,     0,    59,    50,
      51,    52,    53,     0,    60,    61,   108,    59,    50,    51,
      52,    53,     0,    60,    61,   160,    59,    50,    51,    52,
      53,     0,    60,    61,   169,    59,     0,     0,     0,     0,
       0,    60,    61,   171,    59,    50,    51,    52,    53,     0,
      60,    61,   181,    50,    51,    52,    53,     0,     0,   101,
       0,     0,    59,     0,     0,     0,   163,     0,    60,    61,
      59,    50,    51,    52,    53,     0,    60,    61,   162,     0,
      83,    84,    85,    86,    87,    88,    89,    90,    59,     0,
       0,    91,     0,     0,    60,    61,    92,    93,    94,    95,
      96,    97,   173,     0,    83,    84,    85,    86,    87,    88,
      89,    90,     0,     0,     0,    91,     0,     0,     0,     0,
      92,    93,    94,    95,    96,    97,   142,    83,    84,    85,
      86,    87,    88,    89,    90,     0,     0,     0,    91,     0,
       0,     0,     0,    92,    93,    94,    95,    96,    97,    83,
      84,    85,    86,    87,    88,    89,    90,     0,     0,   168,
      91,     0,     0,     0,     0,    92,    93,    94,    95,    96,
      97,    83,    84,    85,    86,    87,    88,    89,    90,     0,
       0,   178,    91,     0,     0,     0,     0,    92,    93,    94,
      95,    96,    97,    83,    84,    85,    86,    87,    88,    89,
      90,     0,     0,   180,    91,     0,     0,     0,     0,    92,
      93,    94,    95,    96,    97,    83,    84,    85,    86,    87,
      88,    89,    90,     0,     0,   186,    91,     0,     0,     0,
       0,    92,    93,    94,    95,    96,    97,    83,    84,    85,
      86,    87,    88,    89,    90,     0,     0,     0,    91,     0,
       0,     0,     0,    92,    93,    94,    95,    96,    97,    84,
      85,    86,    87,    88,     0,    90,     0,     0,     0,    91,
       0,     0,     0,     0,    92,    93,    94,    95,    96,    97,
      84,    85,    86,    87,     0,     0,    90,     0,     0,     0,
      91,     0,     0,     0,     0,    92,    93,    94,    95,    96,
      97
};

static const yytype_int16 yycheck[] =
{
      54,     1,     6,   101,     6,    59,    60,    61,   108,     1,
      28,    14,    66,    17,     6,    33,    70,     0,    72,    73,
       1,    24,     5,     1,    16,    17,     1,    47,    28,    83,
      84,    85,    86,    87,    88,    89,    19,    91,    92,    93,
      94,    95,    96,    97,   142,   145,   146,   101,   148,   149,
      68,    32,    30,    28,    74,     1,   110,     1,    17,     0,
     160,     7,     8,    18,    47,   165,   166,    31,   168,   169,
      29,   171,    16,    25,    29,     7,     8,    29,   178,    26,
     180,   181,    28,    30,    16,    27,   186,     3,   142,     7,
       8,    74,    31,    21,    22,     6,   150,    25,   152,    32,
      17,    29,    16,     1,    19,    20,    21,    22,   162,   163,
      25,    17,     6,    16,    29,    27,    29,    27,    16,   173,
      18,    19,    20,    21,    22,    23,    24,    25,     1,    11,
      27,    29,    27,    11,     5,    64,    34,    35,    36,    37,
      38,    39,    17,    16,    68,    18,    19,    20,    21,    22,
      23,    24,    25,     1,    -1,    -1,    29,    -1,    -1,    -1,
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
      -1,    34,    35,    36,    37,    38,    39,     3,     4,     5,
       6,    -1,    -1,     9,    10,    -1,    12,    13,    -1,    -1,
      16,    -1,    -1,     1,    20,     3,     4,     5,     6,    -1,
      26,    27,    -1,    -1,    -1,    31,    -1,    -1,    -1,    17,
      -1,     1,    20,     3,     4,     5,     6,    -1,    26,    27,
      28,     1,    -1,     3,     4,     5,     6,    -1,    -1,     1,
      20,     3,     4,     5,     6,    -1,    26,    27,    -1,     1,
      20,     3,     4,     5,     6,    -1,    26,    27,    20,    -1,
       3,     4,     5,     6,    26,    27,    -1,     1,    20,     3,
       4,     5,     6,    16,    26,    27,     1,    20,     3,     4,
       5,     6,    -1,    26,    27,     1,    20,     3,     4,     5,
       6,    -1,    26,    27,     1,    20,     3,     4,     5,     6,
      -1,    26,    27,     1,    20,     3,     4,     5,     6,    -1,
      26,    27,     1,    20,     3,     4,     5,     6,    -1,    26,
      27,     1,    20,     3,     4,     5,     6,    -1,    26,    27,
       1,    20,     3,     4,     5,     6,    -1,    26,    27,    -1,
      20,     3,     4,     5,     6,    -1,    26,    27,    -1,    20,
       3,     4,     5,     6,    -1,    26,    27,    -1,    20,     3,
       4,     5,     6,    -1,    26,    27,    28,    20,     3,     4,
       5,     6,    -1,    26,    27,    28,    20,     3,     4,     5,
       6,    -1,    26,    27,    28,    20,    -1,    -1,    -1,    -1,
      -1,    26,    27,    28,    20,     3,     4,     5,     6,    -1,
      26,    27,    28,     3,     4,     5,     6,    -1,    -1,    17,
      -1,    -1,    20,    -1,    -1,    -1,    16,    -1,    26,    27,
      20,     3,     4,     5,     6,    -1,    26,    27,    16,    -1,
      18,    19,    20,    21,    22,    23,    24,    25,    20,    -1,
      -1,    29,    -1,    -1,    26,    27,    34,    35,    36,    37,
      38,    39,    16,    -1,    18,    19,    20,    21,    22,    23,
      24,    25,    -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,
      34,    35,    36,    37,    38,    39,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    -1,    -1,    -1,    29,    -1,
      -1,    -1,    -1,    34,    35,    36,    37,    38,    39,    18,
      19,    20,    21,    22,    23,    24,    25,    -1,    -1,    28,
      29,    -1,    -1,    -1,    -1,    34,    35,    36,    37,    38,
      39,    18,    19,    20,    21,    22,    23,    24,    25,    -1,
      -1,    28,    29,    -1,    -1,    -1,    -1,    34,    35,    36,
      37,    38,    39,    18,    19,    20,    21,    22,    23,    24,
      25,    -1,    -1,    28,    29,    -1,    -1,    -1,    -1,    34,
      35,    36,    37,    38,    39,    18,    19,    20,    21,    22,
      23,    24,    25,    -1,    -1,    28,    29,    -1,    -1,    -1,
      -1,    34,    35,    36,    37,    38,    39,    18,    19,    20,
      21,    22,    23,    24,    25,    -1,    -1,    -1,    29,    -1,
      -1,    -1,    -1,    34,    35,    36,    37,    38,    39,    19,
      20,    21,    22,    23,    -1,    25,    -1,    -1,    -1,    29,
      -1,    -1,    -1,    -1,    34,    35,    36,    37,    38,    39,
      19,    20,    21,    22,    -1,    -1,    25,    -1,    -1,    -1,
      29,    -1,    -1,    -1,    -1,    34,    35,    36,    37,    38,
      39
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     7,     8,    43,    44,    45,    47,    48,     6,     0,
      44,     1,     6,    16,    17,    46,    49,    50,    31,    27,
       6,    46,     1,    16,    17,    29,    31,    53,    47,    56,
      57,     1,    28,    47,    51,    52,    46,     3,    56,    49,
      58,    59,    32,    56,    49,     1,    28,    17,     1,    30,
       3,     4,     5,     6,     9,    10,    12,    13,    16,    20,
      26,    27,    53,    54,    55,    60,    18,    16,    17,    51,
      27,    60,    27,    27,    27,    60,    60,    60,     1,    32,
      54,     1,    16,    18,    19,    20,    21,    22,    23,    24,
      25,    29,    34,    35,    36,    37,    38,    39,    60,    58,
       1,    17,    28,    60,    61,     1,    16,    60,    28,    60,
      16,    51,     1,    28,    60,     1,    60,     1,    60,     1,
      60,     1,    60,     1,    60,     1,    60,     6,    60,     1,
      60,     1,    60,     1,    60,     1,    60,     1,    60,     1,
      60,    61,    17,     1,    28,     1,    28,    55,     1,    28,
      16,    60,    16,     1,    30,    61,    55,    55,    55,    55,
      28,    60,    16,    16,    60,    11,    11,    55,    28,    28,
      60,    28,    60,    16,    55,    55,    55,    55,    28,    55,
      28,    28,    60,    55,    55,    55,    28,    55
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    44,    44,    45,    45,    45,    45,    45,
      46,    46,    46,    46,    47,    47,    48,    48,    49,    49,
      49,    50,    50,    50,    50,    51,    51,    52,    53,    53,
      54,    54,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    56,    56,    57,    58,    58,    59,    59,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      61,    61,    61,    61
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     3,     3,     2,     2,     3,
       1,     3,     2,     2,     1,     1,     5,     2,     1,     4,
       4,     4,     3,     4,     3,     3,     1,     2,     4,     4,
       2,     0,     1,     2,     2,     1,     3,     3,     5,     5,
       7,     5,     4,     7,     5,     9,     8,     8,     8,     7,
       7,     7,     6,     2,     0,     3,     1,     3,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     4,
       4,     3,     3,     4,     4,     3,     1,     1,     1,     1,
       3,     2,     2,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 2: /* Program: ExtDefList  */
#line 34 "syntax.y"
                    {
    (yyval.type) = getNode("Program", 1, (yyvsp[0].type));
    if(!hasError)
        writeNode((yyval.type), 0);
    }
#line 1358 "syntax.tab.c"
    break;

  case 3: /* ExtDefList: ExtDef ExtDefList  */
#line 40 "syntax.y"
                              {(yyval.type) = getNode("ExtDefList", 2, (yyvsp[-1].type), (yyvsp[0].type));}
#line 1364 "syntax.tab.c"
    break;

  case 4: /* ExtDefList: %empty  */
#line 41 "syntax.y"
            {(yyval.type)=getTerminalNode("ExtDefList", -1);}
#line 1370 "syntax.tab.c"
    break;

  case 5: /* ExtDef: Specifier ExtDecList SEMI  */
#line 43 "syntax.y"
                                  {(yyval.type) = getNode("ExtDef", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1376 "syntax.tab.c"
    break;

  case 6: /* ExtDef: Specifier ExtDecList error  */
#line 44 "syntax.y"
                                   {error_type = 1;yyerror("Missing semicolon ';'");}
#line 1382 "syntax.tab.c"
    break;

  case 7: /* ExtDef: Specifier SEMI  */
#line 45 "syntax.y"
                       {(yyval.type) = getNode("ExtDef", 2, (yyvsp[-1].type), (yyvsp[0].type));}
#line 1388 "syntax.tab.c"
    break;

  case 8: /* ExtDef: Specifier error  */
#line 46 "syntax.y"
                        {error_type = 1;yyerror("Missing semicolon ';'");}
#line 1394 "syntax.tab.c"
    break;

  case 9: /* ExtDef: Specifier FunDec CompSt  */
#line 47 "syntax.y"
                                {(yyval.type) = getNode("ExtDef", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1400 "syntax.tab.c"
    break;

  case 10: /* ExtDecList: VarDec  */
#line 51 "syntax.y"
                   {(yyval.type) = getNode("ExtDecList", 1, (yyvsp[0].type));}
#line 1406 "syntax.tab.c"
    break;

  case 11: /* ExtDecList: VarDec COMMA ExtDecList  */
#line 52 "syntax.y"
                                    {(yyval.type) = getNode("ExtDecList", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1412 "syntax.tab.c"
    break;

  case 12: /* ExtDecList: COMMA ExtDecList  */
#line 53 "syntax.y"
                             {error_type = 1;yyerror("Unexpected ','");}
#line 1418 "syntax.tab.c"
    break;

  case 13: /* ExtDecList: VarDec COMMA  */
#line 54 "syntax.y"
                         {error_type = 1;yyerror("Unexpected ','");}
#line 1424 "syntax.tab.c"
    break;

  case 14: /* Specifier: TYPE  */
#line 57 "syntax.y"
                {(yyval.type) = getNode("Specifier", 1, (yyvsp[0].type));}
#line 1430 "syntax.tab.c"
    break;

  case 15: /* Specifier: StructSpecifier  */
#line 58 "syntax.y"
                           {(yyval.type) = getNode("Specifier", 1, (yyvsp[0].type));}
#line 1436 "syntax.tab.c"
    break;

  case 16: /* StructSpecifier: STRUCT ID LC DefList RC  */
#line 60 "syntax.y"
                                         {(yyval.type) = getNode("StructSpecifier", 5, (yyvsp[-4].type), (yyvsp[-3].type), (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1442 "syntax.tab.c"
    break;

  case 17: /* StructSpecifier: STRUCT ID  */
#line 61 "syntax.y"
                          {(yyval.type) = getNode("StructSpecifier", 2, (yyvsp[-1].type), (yyvsp[0].type));}
#line 1448 "syntax.tab.c"
    break;

  case 18: /* VarDec: ID  */
#line 65 "syntax.y"
           {(yyval.type) = getNode("VarDec", 1, (yyvsp[0].type));}
#line 1454 "syntax.tab.c"
    break;

  case 19: /* VarDec: VarDec LB INT RB  */
#line 66 "syntax.y"
                         {(yyval.type) = getNode("VarDec", 4, (yyvsp[-3].type), (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1460 "syntax.tab.c"
    break;

  case 20: /* VarDec: VarDec LB INT error  */
#line 67 "syntax.y"
                            {error_type = 1;yyerror("Missing closing symbol ']'");}
#line 1466 "syntax.tab.c"
    break;

  case 21: /* FunDec: ID LP VarList RP  */
#line 71 "syntax.y"
                         {(yyval.type) = getNode("FunDec", 4, (yyvsp[-3].type), (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1472 "syntax.tab.c"
    break;

  case 22: /* FunDec: ID LP RP  */
#line 72 "syntax.y"
                 {(yyval.type) = getNode("FunDec", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1478 "syntax.tab.c"
    break;

  case 23: /* FunDec: ID LP VarList error  */
#line 73 "syntax.y"
                            {error_type = 1;yyerror("Missing closing symbol ')'");}
#line 1484 "syntax.tab.c"
    break;

  case 24: /* FunDec: ID LP error  */
#line 74 "syntax.y"
                    {error_type = 1;yyerror("Missing closing symbol ')'");}
#line 1490 "syntax.tab.c"
    break;

  case 25: /* VarList: ParamDec COMMA VarList  */
#line 76 "syntax.y"
                                {(yyval.type) = getNode("VarList", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1496 "syntax.tab.c"
    break;

  case 26: /* VarList: ParamDec  */
#line 77 "syntax.y"
                  {(yyval.type) = getNode("VarList", 1, (yyvsp[0].type));}
#line 1502 "syntax.tab.c"
    break;

  case 27: /* ParamDec: Specifier VarDec  */
#line 79 "syntax.y"
                           {(yyval.type) = getNode("ParamDec", 2, (yyvsp[-1].type), (yyvsp[0].type));}
#line 1508 "syntax.tab.c"
    break;

  case 28: /* CompSt: LC DefList StmtList RC  */
#line 82 "syntax.y"
                               {(yyval.type) = getNode("CompSt", 4, (yyvsp[-3].type), (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1514 "syntax.tab.c"
    break;

  case 29: /* CompSt: LC DefList StmtList error  */
#line 83 "syntax.y"
                                  {error_type = 1;yyerror("Missing closing symbol '}'");}
#line 1520 "syntax.tab.c"
    break;

  case 30: /* StmtList: Stmt StmtList  */
#line 85 "syntax.y"
                        {(yyval.type) = getNode("StmtList", 2, (yyvsp[-1].type), (yyvsp[0].type));}
#line 1526 "syntax.tab.c"
    break;

  case 31: /* StmtList: %empty  */
#line 86 "syntax.y"
         {(yyval.type)=getTerminalNode("StmtList", -1);}
#line 1532 "syntax.tab.c"
    break;

  case 32: /* Stmt: SEMI  */
#line 88 "syntax.y"
           {(yyval.type) = getNode("Stmt", 1, (yyvsp[0].type));}
#line 1538 "syntax.tab.c"
    break;

  case 33: /* Stmt: Exp SEMI  */
#line 89 "syntax.y"
               {(yyval.type) = getNode("Stmt", 2, (yyvsp[-1].type), (yyvsp[0].type));}
#line 1544 "syntax.tab.c"
    break;

  case 34: /* Stmt: Exp error  */
#line 90 "syntax.y"
                {error_type = 1;yyerror("Missing semicolon ';'");}
#line 1550 "syntax.tab.c"
    break;

  case 35: /* Stmt: CompSt  */
#line 91 "syntax.y"
             {(yyval.type) = getNode("Stmt", 1, (yyvsp[0].type));}
#line 1556 "syntax.tab.c"
    break;

  case 36: /* Stmt: RETURN Exp SEMI  */
#line 92 "syntax.y"
                      {(yyval.type) = getNode("Stmt", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1562 "syntax.tab.c"
    break;

  case 37: /* Stmt: RETURN Exp error  */
#line 93 "syntax.y"
                       {error_type = 1;yyerror("Missing semicolon ';'");}
#line 1568 "syntax.tab.c"
    break;

  case 38: /* Stmt: IF LP Exp RP Stmt  */
#line 94 "syntax.y"
                                              {(yyval.type) = getNode("Stmt", 5, (yyvsp[-4].type), (yyvsp[-3].type), (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1574 "syntax.tab.c"
    break;

  case 39: /* Stmt: IF LP Exp error Stmt  */
#line 95 "syntax.y"
                                                 {error_type = 1;yyerror("This if function miss closing symbol ')'");}
#line 1580 "syntax.tab.c"
    break;

  case 40: /* Stmt: IF LP Exp RP Stmt ELSE Stmt  */
#line 96 "syntax.y"
                                  {(yyval.type) = getNode("Stmt", 7, (yyvsp[-6].type), (yyvsp[-5].type), (yyvsp[-4].type), (yyvsp[-3].type), (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1586 "syntax.tab.c"
    break;

  case 41: /* Stmt: WHILE LP Exp RP Stmt  */
#line 97 "syntax.y"
                           {(yyval.type) = getNode("Stmt", 5, (yyvsp[-4].type), (yyvsp[-3].type), (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1592 "syntax.tab.c"
    break;

  case 42: /* Stmt: WHILE LP RP Stmt  */
#line 98 "syntax.y"
                       {(yyval.type) = getNode("Stmt", 4, (yyvsp[-3].type), (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1598 "syntax.tab.c"
    break;

  case 43: /* Stmt: IF LP Exp error Stmt ELSE Stmt  */
#line 99 "syntax.y"
                                     {error_type = 1;yyerror("This if function miss closing symbol ')'");}
#line 1604 "syntax.tab.c"
    break;

  case 44: /* Stmt: WHILE LP Exp error Stmt  */
#line 100 "syntax.y"
                              {error_type = 1;yyerror("Missing closing symbol ')'");}
#line 1610 "syntax.tab.c"
    break;

  case 45: /* Stmt: FOR LP VarList SEMI Exp SEMI Exp RP Stmt  */
#line 101 "syntax.y"
                                               {(yyval.type) = getNode("Stmt", 9, (yyvsp[-8].type), (yyvsp[-7].type), (yyvsp[-6].type), (yyvsp[-5].type), (yyvsp[-4].type), (yyvsp[-3].type), (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1616 "syntax.tab.c"
    break;

  case 46: /* Stmt: FOR LP SEMI Exp SEMI Exp RP Stmt  */
#line 102 "syntax.y"
                                       {(yyval.type) = getNode("Stmt", 8, (yyvsp[-7].type), (yyvsp[-6].type), (yyvsp[-5].type), (yyvsp[-4].type), (yyvsp[-3].type), (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1622 "syntax.tab.c"
    break;

  case 47: /* Stmt: FOR LP VarList SEMI SEMI Exp RP Stmt  */
#line 103 "syntax.y"
                                           {(yyval.type) = getNode("Stmt", 8, (yyvsp[-7].type), (yyvsp[-6].type), (yyvsp[-5].type), (yyvsp[-4].type), (yyvsp[-3].type), (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1628 "syntax.tab.c"
    break;

  case 48: /* Stmt: FOR LP VarList SEMI Exp SEMI RP Stmt  */
#line 104 "syntax.y"
                                           {(yyval.type) = getNode("Stmt", 8, (yyvsp[-7].type), (yyvsp[-6].type), (yyvsp[-5].type), (yyvsp[-4].type), (yyvsp[-3].type), (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1634 "syntax.tab.c"
    break;

  case 49: /* Stmt: FOR LP SEMI SEMI Exp RP Stmt  */
#line 105 "syntax.y"
                                   {(yyval.type) = getNode("Stmt", 7, (yyvsp[-6].type), (yyvsp[-5].type), (yyvsp[-4].type), (yyvsp[-3].type), (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1640 "syntax.tab.c"
    break;

  case 50: /* Stmt: FOR LP SEMI Exp SEMI RP Stmt  */
#line 106 "syntax.y"
                                   {(yyval.type) = getNode("Stmt", 7, (yyvsp[-6].type), (yyvsp[-5].type), (yyvsp[-4].type), (yyvsp[-3].type), (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1646 "syntax.tab.c"
    break;

  case 51: /* Stmt: FOR LP VarList SEMI SEMI RP Stmt  */
#line 107 "syntax.y"
                                       {(yyval.type) = getNode("Stmt", 7, (yyvsp[-6].type), (yyvsp[-5].type), (yyvsp[-4].type), (yyvsp[-3].type), (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1652 "syntax.tab.c"
    break;

  case 52: /* Stmt: FOR LP SEMI SEMI RP Stmt  */
#line 108 "syntax.y"
                               {(yyval.type) = getNode("Stmt", 6, (yyvsp[-5].type), (yyvsp[-4].type), (yyvsp[-3].type), (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1658 "syntax.tab.c"
    break;

  case 53: /* DefList: Def DefList  */
#line 110 "syntax.y"
                     {(yyval.type) = getNode("DefList", 2, (yyvsp[-1].type), (yyvsp[0].type));}
#line 1664 "syntax.tab.c"
    break;

  case 54: /* DefList: %empty  */
#line 111 "syntax.y"
         {(yyval.type)=getTerminalNode("DefList", -1);}
#line 1670 "syntax.tab.c"
    break;

  case 55: /* Def: Specifier DecList SEMI  */
#line 113 "syntax.y"
                            {(yyval.type) = getNode("Def", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1676 "syntax.tab.c"
    break;

  case 56: /* DecList: Dec  */
#line 116 "syntax.y"
             {(yyval.type) = getNode("DecList", 1, (yyvsp[0].type));}
#line 1682 "syntax.tab.c"
    break;

  case 57: /* DecList: Dec COMMA DecList  */
#line 117 "syntax.y"
                            {(yyval.type) = getNode("DecList", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1688 "syntax.tab.c"
    break;

  case 58: /* Dec: VarDec  */
#line 120 "syntax.y"
            {(yyval.type) = getNode("Dec", 1, (yyvsp[0].type));}
#line 1694 "syntax.tab.c"
    break;

  case 59: /* Dec: VarDec ASSIGN Exp  */
#line 121 "syntax.y"
                        {(yyval.type) = getNode("Dec", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1700 "syntax.tab.c"
    break;

  case 60: /* Exp: Exp ASSIGN Exp  */
#line 124 "syntax.y"
                    {(yyval.type) = getNode("Exp", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1706 "syntax.tab.c"
    break;

  case 61: /* Exp: Exp AND Exp  */
#line 125 "syntax.y"
                  {(yyval.type) = getNode("Exp", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1712 "syntax.tab.c"
    break;

  case 62: /* Exp: Exp OR Exp  */
#line 126 "syntax.y"
                 {(yyval.type) = getNode("Exp", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1718 "syntax.tab.c"
    break;

  case 63: /* Exp: Exp LT Exp  */
#line 127 "syntax.y"
                 {(yyval.type) = getNode("Exp", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1724 "syntax.tab.c"
    break;

  case 64: /* Exp: Exp LE Exp  */
#line 128 "syntax.y"
                 {(yyval.type) = getNode("Exp", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1730 "syntax.tab.c"
    break;

  case 65: /* Exp: Exp GT Exp  */
#line 129 "syntax.y"
                 {(yyval.type) = getNode("Exp", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1736 "syntax.tab.c"
    break;

  case 66: /* Exp: Exp GE Exp  */
#line 130 "syntax.y"
                 {(yyval.type) = getNode("Exp", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1742 "syntax.tab.c"
    break;

  case 67: /* Exp: Exp NE Exp  */
#line 131 "syntax.y"
                 {(yyval.type) = getNode("Exp", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1748 "syntax.tab.c"
    break;

  case 68: /* Exp: Exp EQ Exp  */
#line 132 "syntax.y"
                 {(yyval.type) = getNode("Exp", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1754 "syntax.tab.c"
    break;

  case 69: /* Exp: Exp PLUS Exp  */
#line 133 "syntax.y"
                   {(yyval.type) = getNode("Exp", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1760 "syntax.tab.c"
    break;

  case 70: /* Exp: Exp MINUS Exp  */
#line 134 "syntax.y"
                    {(yyval.type) = getNode("Exp", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1766 "syntax.tab.c"
    break;

  case 71: /* Exp: Exp MUL Exp  */
#line 135 "syntax.y"
                  {(yyval.type) = getNode("Exp", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1772 "syntax.tab.c"
    break;

  case 72: /* Exp: Exp DIV Exp  */
#line 136 "syntax.y"
                  {(yyval.type) = getNode("Exp", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1778 "syntax.tab.c"
    break;

  case 73: /* Exp: Exp AND error  */
#line 137 "syntax.y"
                    {error_type = 1; yyerror("Expect expression after 'ans'");}
#line 1784 "syntax.tab.c"
    break;

  case 74: /* Exp: Exp OR error  */
#line 138 "syntax.y"
                   {error_type = 1; yyerror("Expect expression after 'or'");}
#line 1790 "syntax.tab.c"
    break;

  case 75: /* Exp: Exp LT error  */
#line 139 "syntax.y"
                   {error_type = 1; yyerror("Expect expression after '<'");}
#line 1796 "syntax.tab.c"
    break;

  case 76: /* Exp: Exp LE error  */
#line 140 "syntax.y"
                   {error_type = 1; yyerror("Expect expression after '<='");}
#line 1802 "syntax.tab.c"
    break;

  case 77: /* Exp: Exp GT error  */
#line 141 "syntax.y"
                   {error_type = 1; yyerror("Expect expression after '>'");}
#line 1808 "syntax.tab.c"
    break;

  case 78: /* Exp: Exp GE error  */
#line 142 "syntax.y"
                   {error_type = 1; yyerror("Expect expression after '>=");}
#line 1814 "syntax.tab.c"
    break;

  case 79: /* Exp: Exp NE error  */
#line 143 "syntax.y"
                   {error_type = 1; yyerror("Expect expression after '!='");}
#line 1820 "syntax.tab.c"
    break;

  case 80: /* Exp: Exp EQ error  */
#line 144 "syntax.y"
                   {error_type = 1; yyerror("Expect expression after '=='");}
#line 1826 "syntax.tab.c"
    break;

  case 81: /* Exp: Exp PLUS error  */
#line 145 "syntax.y"
                     {error_type = 1; yyerror("Expect expression after '+'");}
#line 1832 "syntax.tab.c"
    break;

  case 82: /* Exp: Exp MINUS error  */
#line 146 "syntax.y"
                      {error_type = 1; yyerror("Expect expression after '-'");}
#line 1838 "syntax.tab.c"
    break;

  case 83: /* Exp: Exp MUL error  */
#line 147 "syntax.y"
                    {error_type = 1; yyerror("Expect expression after '*'");}
#line 1844 "syntax.tab.c"
    break;

  case 84: /* Exp: Exp DIV error  */
#line 148 "syntax.y"
                    {error_type = 1; yyerror("Expect expression after '/'");}
#line 1850 "syntax.tab.c"
    break;

  case 85: /* Exp: LP Exp RP  */
#line 149 "syntax.y"
                {(yyval.type) = getNode("Exp", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1856 "syntax.tab.c"
    break;

  case 86: /* Exp: LP Exp error  */
#line 150 "syntax.y"
                   {error_type = 1;yyerror("Missing closing symbol ')'");}
#line 1862 "syntax.tab.c"
    break;

  case 87: /* Exp: MINUS Exp  */
#line 151 "syntax.y"
                {(yyval.type) = getNode("Exp", 2, (yyvsp[-1].type), (yyvsp[0].type));}
#line 1868 "syntax.tab.c"
    break;

  case 88: /* Exp: NOT Exp  */
#line 152 "syntax.y"
              {(yyval.type) = getNode("Exp", 2, (yyvsp[-1].type), (yyvsp[0].type));}
#line 1874 "syntax.tab.c"
    break;

  case 89: /* Exp: ID LP Args RP  */
#line 153 "syntax.y"
                    {(yyval.type) = getNode("Exp", 4, (yyvsp[-3].type), (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1880 "syntax.tab.c"
    break;

  case 90: /* Exp: ID LP Args error  */
#line 154 "syntax.y"
                       {error_type = 1;yyerror("Missing closing symbol ')'");}
#line 1886 "syntax.tab.c"
    break;

  case 91: /* Exp: ID LP RP  */
#line 155 "syntax.y"
               {(yyval.type) = getNode("Exp", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1892 "syntax.tab.c"
    break;

  case 92: /* Exp: ID LP error  */
#line 156 "syntax.y"
                  {error_type = 1;yyerror("Missing closing symbol ')'");}
#line 1898 "syntax.tab.c"
    break;

  case 93: /* Exp: Exp LB Exp RB  */
#line 157 "syntax.y"
                    {(yyval.type) = getNode("Exp", 4, (yyvsp[-3].type), (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1904 "syntax.tab.c"
    break;

  case 94: /* Exp: Exp LB Exp error  */
#line 158 "syntax.y"
                       {error_type = 1;yyerror("Missing closing symbol ']'");}
#line 1910 "syntax.tab.c"
    break;

  case 95: /* Exp: Exp DOT ID  */
#line 159 "syntax.y"
                 {(yyval.type) = getNode("Exp", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1916 "syntax.tab.c"
    break;

  case 96: /* Exp: ID  */
#line 160 "syntax.y"
         {(yyval.type) = getNode("Exp", 1, (yyvsp[0].type));}
#line 1922 "syntax.tab.c"
    break;

  case 97: /* Exp: INT  */
#line 161 "syntax.y"
          {(yyval.type) = getNode("Exp", 1, (yyvsp[0].type));}
#line 1928 "syntax.tab.c"
    break;

  case 98: /* Exp: FLOAT  */
#line 162 "syntax.y"
            {(yyval.type) = getNode("Exp", 1, (yyvsp[0].type));}
#line 1934 "syntax.tab.c"
    break;

  case 99: /* Exp: CHAR  */
#line 163 "syntax.y"
           {(yyval.type) = getNode("Exp", 1, (yyvsp[0].type));}
#line 1940 "syntax.tab.c"
    break;

  case 100: /* Args: Exp COMMA Args  */
#line 165 "syntax.y"
                     {(yyval.type) = getNode("Args", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1946 "syntax.tab.c"
    break;

  case 101: /* Args: COMMA Args  */
#line 167 "syntax.y"
                 {error_type = 1;yyerror("Unexpected ','");}
#line 1952 "syntax.tab.c"
    break;

  case 102: /* Args: Exp COMMA  */
#line 168 "syntax.y"
                {error_type = 1;yyerror("Expected another parenthesis after ','");}
#line 1958 "syntax.tab.c"
    break;

  case 103: /* Args: Exp  */
#line 169 "syntax.y"
          {(yyval.type) = getNode("Args", 1, (yyvsp[0].type));}
#line 1964 "syntax.tab.c"
    break;


#line 1968 "syntax.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 172 "syntax.y"
