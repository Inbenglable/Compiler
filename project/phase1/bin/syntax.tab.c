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
    #include <string.h>
    #include<stdio.h>   
    #include "structure.h"
    #include "symbol_table.h"
    int yylex();

#line 80 "syntax.tab.c"

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
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   543

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  100
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  167

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
static const yytype_int16 yyrline[] =
{
       0,    35,    35,    41,    42,    44,    52,    53,    54,    55,
      64,    68,    72,    77,    78,    81,    85,    90,    98,   107,
     111,   116,   120,   128,   132,   133,   135,   140,   145,   150,
     151,   154,   157,   158,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   182,   187,   189,
     198,   199,   201,   205,   212,   216,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   273,   274,   275,   277,   279,   280,
     281
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

#define YYPACT_NINF (-104)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-49)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     518,   103,  -104,    -4,     3,  -104,   518,   260,  -104,  -104,
     103,     6,    77,    14,  -104,  -104,  -104,    32,  -104,     7,
      37,  -104,  -104,   103,    81,   204,    57,  -104,  -104,   218,
    -104,  -104,    16,   101,   101,    99,   218,   101,  -104,    61,
      35,    69,   248,  -104,  -104,    92,    95,   117,    80,  -104,
    -104,   106,  -104,   106,  -104,  -104,    18,  -104,  -104,  -104,
     109,   321,   110,   118,  -104,   321,   321,   321,  -104,   112,
     248,    54,   321,  -104,   101,  -104,  -104,   101,  -104,   266,
      79,   321,   402,   514,    -1,   104,  -104,  -104,  -104,  -104,
     236,   284,   294,   302,   312,   330,   339,   140,   321,   348,
     357,   366,   375,   384,   393,   453,  -104,  -104,   420,  -104,
     431,    43,  -104,  -104,   129,   248,   154,  -104,  -104,  -104,
     453,  -104,   514,  -104,   514,  -104,    -1,  -104,    -1,  -104,
     495,  -104,   474,  -104,   179,  -104,   413,  -104,   413,  -104,
     413,  -104,   413,  -104,   413,  -104,   413,  -104,   420,  -104,
    -104,   248,   248,  -104,   248,   248,  -104,  -104,  -104,   145,
     148,  -104,  -104,   248,   248,  -104,  -104
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    15,     0,     0,     2,     0,     0,    16,    19,
       0,     0,    11,    18,     1,     3,     8,    19,     7,     0,
       0,    13,    10,    14,     0,     0,     0,     6,     5,     0,
       9,    12,     0,     0,     0,     0,     0,    25,    23,     0,
       0,    27,    33,    21,    20,    54,     0,    52,     0,    17,
      47,    29,    30,    28,    24,    22,     0,    94,    95,    96,
      93,     0,     0,     0,    34,     0,     0,     0,    37,     0,
      33,     0,     0,    50,     0,    51,    49,     0,    26,     0,
       0,     0,     0,    84,    85,     0,    31,    32,    36,    35,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    55,    53,    89,     0,    88,
     100,     0,    39,    38,     0,     0,     0,    83,    82,    69,
      56,    78,    65,    79,    66,    80,    67,    81,    68,    70,
      57,    71,    58,    92,     0,    72,    59,    73,    60,    74,
      61,    75,    62,    76,    63,    77,    64,    98,    99,    87,
      86,     0,     0,    44,     0,     0,    91,    90,    97,    41,
      40,    46,    43,     0,     0,    45,    42
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -104,  -104,   155,  -104,    59,     1,  -104,   -24,  -104,   113,
    -104,   142,    90,  -103,    83,  -104,   -20,  -104,   -61,   -92
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     4,     5,     6,    11,    34,     8,    12,    20,    40,
      41,    68,    69,    70,    35,    36,    46,    47,    71,   111
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      80,     7,    13,    14,    83,    84,    85,     7,    27,    45,
      45,   105,   153,    51,    48,    53,   147,    43,   110,    77,
     114,   116,    22,    28,    97,     2,     3,    39,    98,   120,
     122,   124,   126,   128,   130,   132,    54,   134,   136,   138,
     140,   142,   144,   146,   149,    25,    44,   110,   159,   160,
      45,   161,   162,    51,   106,    88,   158,    39,    37,    26,
     165,   166,    52,    55,     2,     3,    19,     9,    29,    21,
      89,   150,    90,    91,    92,    93,    94,    95,    96,    97,
     112,    75,    31,    98,    32,    38,    56,   110,    99,   100,
     101,   102,   103,   104,    23,   113,    76,    90,    91,    92,
      93,    94,    95,    96,    97,   117,    24,     9,    98,     9,
      72,    73,    42,    99,   100,   101,   102,   103,   104,    50,
      10,    24,    90,    91,    92,    93,    94,    95,    96,    97,
     151,    49,   118,    98,    74,    24,    79,    81,    99,   100,
     101,   102,   103,   104,    86,    82,   133,    90,    91,    92,
      93,    94,    95,    96,    97,   154,   163,   152,    98,   164,
      87,    15,    30,    99,   100,   101,   102,   103,   104,    78,
       0,     0,    90,    91,    92,    93,    94,    95,    96,    97,
     156,     0,   155,    98,     0,     0,     0,     0,    99,   100,
     101,   102,   103,   104,     0,     0,     0,    90,    91,    92,
      93,    94,    95,    96,    97,    33,     0,     0,    98,   157,
       0,     2,     3,    99,   100,   101,   102,   103,   104,    33,
       0,   -48,   -48,   -48,   -48,     2,     3,   -48,   -48,     0,
     -48,     0,     0,     0,   -48,     0,   -48,   119,   -48,    57,
      58,    59,    60,     0,   -48,   -48,     0,     0,     0,   -48,
     -48,    57,    58,    59,    60,     0,    65,    61,    62,     0,
      63,    16,    66,    67,    64,     0,    17,   107,    65,    57,
      58,    59,    60,     0,    66,    67,    18,    10,     0,    29,
       0,     0,     0,   108,     0,   121,    65,    57,    58,    59,
      60,     0,    66,    67,   109,   123,     0,    57,    58,    59,
      60,     0,     0,   125,    65,    57,    58,    59,    60,     0,
      66,    67,     0,   127,    65,    57,    58,    59,    60,     0,
      66,    67,    65,     0,    57,    58,    59,    60,    66,    67,
       0,   129,    65,    57,    58,    59,    60,     0,    66,    67,
     131,    65,    57,    58,    59,    60,     0,    66,    67,   135,
      65,    57,    58,    59,    60,     0,    66,    67,   137,    65,
      57,    58,    59,    60,     0,    66,    67,   139,    65,    57,
      58,    59,    60,     0,    66,    67,   141,    65,    57,    58,
      59,    60,     0,    66,    67,   143,    65,    57,    58,    59,
      60,     0,    66,    67,   145,    65,    57,    58,    59,    60,
       0,    66,    67,     0,    65,    57,    58,    59,    60,     0,
      66,    67,     0,    65,     0,     0,     0,     0,     0,    66,
      67,     0,    65,    57,    58,    59,    60,     0,    66,    67,
     115,     0,    91,    92,    93,    94,     0,   108,    97,     0,
      65,     0,    98,     0,     0,     0,    66,    67,   148,    90,
      91,    92,    93,    94,    95,    96,    97,     0,     0,     0,
      98,     0,     0,     0,     0,    99,   100,   101,   102,   103,
     104,    90,    91,    92,    93,    94,    95,    96,    97,     0,
       0,     0,    98,     0,     0,     0,     0,    99,   100,   101,
     102,   103,   104,    91,    92,    93,    94,    95,     0,    97,
       0,     0,     0,    98,     0,     0,     0,     0,    99,   100,
     101,   102,   103,   104,    91,    92,    93,    94,    -4,     1,
      97,     0,     0,     0,    98,     2,     3,     0,     0,    99,
     100,   101,   102,   103,   104,    93,    94,     0,     0,    97,
       0,     0,     0,    98
};

static const yytype_int16 yycheck[] =
{
      61,     0,     6,     0,    65,    66,    67,     6,     1,    33,
      34,    72,   115,    37,    34,    39,   108,     1,    79,     1,
      81,    82,    16,    16,    25,     7,     8,    26,    29,    90,
      91,    92,    93,    94,    95,    96,     1,    98,    99,   100,
     101,   102,   103,   104,     1,    31,    30,   108,   151,   152,
      74,   154,   155,    77,    74,     1,   148,    56,     1,    27,
     163,   164,     1,    28,     7,     8,     7,     6,    31,    10,
      16,    28,    18,    19,    20,    21,    22,    23,    24,    25,
       1,     1,    23,    29,     3,    28,    17,   148,    34,    35,
      36,    37,    38,    39,    17,    16,    16,    18,    19,    20,
      21,    22,    23,    24,    25,     1,    29,     6,    29,     6,
      18,    16,    29,    34,    35,    36,    37,    38,    39,    36,
      17,    29,    18,    19,    20,    21,    22,    23,    24,    25,
       1,    32,    28,    29,    17,    29,    27,    27,    34,    35,
      36,    37,    38,    39,    32,    27,     6,    18,    19,    20,
      21,    22,    23,    24,    25,     1,    11,    28,    29,    11,
      70,     6,    20,    34,    35,    36,    37,    38,    39,    56,
      -1,    -1,    18,    19,    20,    21,    22,    23,    24,    25,
       1,    -1,    28,    29,    -1,    -1,    -1,    -1,    34,    35,
      36,    37,    38,    39,    -1,    -1,    -1,    18,    19,    20,
      21,    22,    23,    24,    25,     1,    -1,    -1,    29,    30,
      -1,     7,     8,    34,    35,    36,    37,    38,    39,     1,
      -1,     3,     4,     5,     6,     7,     8,     9,    10,    -1,
      12,    -1,    -1,    -1,    16,    -1,    32,     1,    20,     3,
       4,     5,     6,    -1,    26,    27,    -1,    -1,    -1,    31,
      32,     3,     4,     5,     6,    -1,    20,     9,    10,    -1,
      12,     1,    26,    27,    16,    -1,     6,     1,    20,     3,
       4,     5,     6,    -1,    26,    27,    16,    17,    -1,    31,
      -1,    -1,    -1,    17,    -1,     1,    20,     3,     4,     5,
       6,    -1,    26,    27,    28,     1,    -1,     3,     4,     5,
       6,    -1,    -1,     1,    20,     3,     4,     5,     6,    -1,
      26,    27,    -1,     1,    20,     3,     4,     5,     6,    -1,
      26,    27,    20,    -1,     3,     4,     5,     6,    26,    27,
      -1,     1,    20,     3,     4,     5,     6,    -1,    26,    27,
       1,    20,     3,     4,     5,     6,    -1,    26,    27,     1,
      20,     3,     4,     5,     6,    -1,    26,    27,     1,    20,
       3,     4,     5,     6,    -1,    26,    27,     1,    20,     3,
       4,     5,     6,    -1,    26,    27,     1,    20,     3,     4,
       5,     6,    -1,    26,    27,     1,    20,     3,     4,     5,
       6,    -1,    26,    27,     1,    20,     3,     4,     5,     6,
      -1,    26,    27,    -1,    20,     3,     4,     5,     6,    -1,
      26,    27,    -1,    20,    -1,    -1,    -1,    -1,    -1,    26,
      27,    -1,    20,     3,     4,     5,     6,    -1,    26,    27,
      28,    -1,    19,    20,    21,    22,    -1,    17,    25,    -1,
      20,    -1,    29,    -1,    -1,    -1,    26,    27,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    -1,    -1,    -1,
      29,    -1,    -1,    -1,    -1,    34,    35,    36,    37,    38,
      39,    18,    19,    20,    21,    22,    23,    24,    25,    -1,
      -1,    -1,    29,    -1,    -1,    -1,    -1,    34,    35,    36,
      37,    38,    39,    19,    20,    21,    22,    23,    -1,    25,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    34,    35,
      36,    37,    38,    39,    19,    20,    21,    22,     0,     1,
      25,    -1,    -1,    -1,    29,     7,     8,    -1,    -1,    34,
      35,    36,    37,    38,    39,    21,    22,    -1,    -1,    25,
      -1,    -1,    -1,    29
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     7,     8,    43,    44,    45,    47,    48,     6,
      17,    46,    49,     6,     0,    44,     1,     6,    16,    46,
      50,    46,    16,    17,    29,    31,    27,     1,    16,    31,
      53,    46,     3,     1,    47,    56,    57,     1,    28,    47,
      51,    52,    56,     1,    30,    49,    58,    59,    58,    32,
      56,    49,     1,    49,     1,    28,    17,     3,     4,     5,
       6,     9,    10,    12,    16,    20,    26,    27,    53,    54,
      55,    60,    18,    16,    17,     1,    16,     1,    51,    27,
      60,    27,    27,    60,    60,    60,    32,    54,     1,    16,
      18,    19,    20,    21,    22,    23,    24,    25,    29,    34,
      35,    36,    37,    38,    39,    60,    58,     1,    17,    28,
      60,    61,     1,    16,    60,    28,    60,     1,    28,     1,
      60,     1,    60,     1,    60,     1,    60,     1,    60,     1,
      60,     1,    60,     6,    60,     1,    60,     1,    60,     1,
      60,     1,    60,     1,    60,     1,    60,    61,    17,     1,
      28,     1,    28,    55,     1,    28,     1,    30,    61,    55,
      55,    55,    55,    11,    11,    55,    55
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    44,    44,    45,    45,    45,    45,    45,
      45,    46,    46,    46,    46,    47,    47,    48,    48,    49,
      49,    49,    50,    50,    50,    50,    51,    51,    52,    52,
      52,    53,    54,    54,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    56,    56,    57,
      57,    57,    58,    58,    59,    59,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    61,    61,    61,
      61
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     3,     3,     2,     2,     3,
       3,     1,     3,     2,     2,     1,     1,     5,     2,     1,
       4,     4,     4,     3,     4,     3,     3,     1,     2,     2,
       2,     4,     2,     0,     1,     2,     2,     1,     3,     3,
       5,     5,     7,     5,     4,     7,     5,     2,     0,     3,
       3,     3,     1,     3,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     4,     4,     3,     3,
       4,     4,     3,     1,     1,     1,     1,     3,     2,     2,
       1
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
#line 35 "syntax.y"
                    {
    (yyval.type) = getNode("Program", 1, (yyvsp[0].type));
    if(!hasError)
        writeNode((yyval.type), 0);
    }
#line 1316 "syntax.tab.c"
    break;

  case 3: /* ExtDefList: ExtDef ExtDefList  */
#line 41 "syntax.y"
                              {(yyval.type) = getNode("ExtDefList", 2, (yyvsp[-1].type), (yyvsp[0].type));}
#line 1322 "syntax.tab.c"
    break;

  case 4: /* ExtDefList: %empty  */
#line 42 "syntax.y"
            {(yyval.type)=getTerminalNode("ExtDefList", -1);}
#line 1328 "syntax.tab.c"
    break;

  case 5: /* ExtDef: Specifier ExtDecList SEMI  */
#line 44 "syntax.y"
                                  {
            (yyval.type) = getNode("ExtDef", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));
            assign_type((yyvsp[-2].type), (yyvsp[-1].type));
            if(push_var((yyvsp[-1].type))!=0){// == 0 : acc , == x : error in line x 
                error_type = 3;
                yyerror("Variable aready exists");
            }
        }
#line 1341 "syntax.tab.c"
    break;

  case 6: /* ExtDef: Specifier ExtDecList error  */
#line 52 "syntax.y"
                                   {error_type = 1;yyerror("Missing semicolon ';'");}
#line 1347 "syntax.tab.c"
    break;

  case 7: /* ExtDef: Specifier SEMI  */
#line 53 "syntax.y"
                       {(yyval.type) = getNode("ExtDef", 2, (yyvsp[-1].type), (yyvsp[0].type));}
#line 1353 "syntax.tab.c"
    break;

  case 8: /* ExtDef: Specifier error  */
#line 54 "syntax.y"
                        {error_type = 1;yyerror("Missing semicolon ';'");}
#line 1359 "syntax.tab.c"
    break;

  case 9: /* ExtDef: Specifier FunDec CompSt  */
#line 55 "syntax.y"
                                {
            (yyval.type) = getNode("ExtDef", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));
            assign_funtype((yyvsp[-1].type), (yyvsp[-2].type));
            pop_scope();
            if(push_fun((yyvsp[-1].type))!=0){// == 0 : acc , == x : error in line x 
                error_type = 3;
                yyerror("Function name aready exists");
            }
        }
#line 1373 "syntax.tab.c"
    break;

  case 10: /* ExtDef: error ExtDecList SEMI  */
#line 64 "syntax.y"
                               {error_type = 1; yyerror("Missing specifier");}
#line 1379 "syntax.tab.c"
    break;

  case 11: /* ExtDecList: VarDec  */
#line 68 "syntax.y"
                   {
                (yyval.type) = getNode("ExtDecList", 1, (yyvsp[0].type));
                extend_var((yyval.type), (yyvsp[0].type));    
            }
#line 1388 "syntax.tab.c"
    break;

  case 12: /* ExtDecList: VarDec COMMA ExtDecList  */
#line 72 "syntax.y"
                                    {
                (yyval.type) = getNode("ExtDecList", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));
                connect_var((yyvsp[-2].type), (yyvsp[0].type));
                extend_var((yyval.type), (yyvsp[-2].type));
            }
#line 1398 "syntax.tab.c"
    break;

  case 13: /* ExtDecList: COMMA ExtDecList  */
#line 77 "syntax.y"
                             {error_type = 1;yyerror("Unexpected ','");}
#line 1404 "syntax.tab.c"
    break;

  case 14: /* ExtDecList: VarDec COMMA  */
#line 78 "syntax.y"
                         {error_type = 1;yyerror("Unexpected ','");}
#line 1410 "syntax.tab.c"
    break;

  case 15: /* Specifier: TYPE  */
#line 81 "syntax.y"
                {
                (yyval.type) = getNode("Specifier", 1, (yyvsp[0].type));
                extend_type((yyval.type), (yyvsp[0].type));
            }
#line 1419 "syntax.tab.c"
    break;

  case 16: /* Specifier: StructSpecifier  */
#line 85 "syntax.y"
                           {
                (yyval.type) = getNode("Specifier", 1, (yyvsp[0].type));
                extend_type((yyval.type), (yyvsp[0].type));
            }
#line 1428 "syntax.tab.c"
    break;

  case 17: /* StructSpecifier: STRUCT ID LC DefList RC  */
#line 90 "syntax.y"
                                         {
                    (yyval.type) = getNode("StructSpecifier", 5, (yyvsp[-4].type), (yyvsp[-3].type), (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));
                    newStructType((yyval.type), (yyvsp[-3].type), (yyvsp[-1].type));
                    if(push_type((yyval.type))!=0){// == 0 : acc , == x : error in line x 
                        error_type = 3;
                        yyerror("Struct name aready exists");
                    }
                }
#line 1441 "syntax.tab.c"
    break;

  case 18: /* StructSpecifier: STRUCT ID  */
#line 98 "syntax.y"
                          {(yyval.type) = getNode("StructSpecifier", 2, (yyvsp[-1].type), (yyvsp[0].type));
                    if(!getStruct((yyval.type), (yyvsp[-1].type))){
                        error_type = 3;
                        yyerror("Undefined structer");
                    }
              }
#line 1452 "syntax.tab.c"
    break;

  case 19: /* VarDec: ID  */
#line 107 "syntax.y"
           {
            (yyval.type) = getNode("VarDec", 1, (yyvsp[0].type));
            extend_var((yyval.type), (yyvsp[0].type));
        }
#line 1461 "syntax.tab.c"
    break;

  case 20: /* VarDec: VarDec LB INT RB  */
#line 111 "syntax.y"
                         {
        (yyval.type) = getNode("VarDec", 4, (yyvsp[-3].type), (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));
        extend_dim((yyvsp[-3].type));
        extend_var((yyval.type), (yyvsp[-3].type));
      }
#line 1471 "syntax.tab.c"
    break;

  case 21: /* VarDec: VarDec LB INT error  */
#line 116 "syntax.y"
                            {error_type = 1;yyerror("Missing closing symbol ']'");}
#line 1477 "syntax.tab.c"
    break;

  case 22: /* FunDec: ID LP VarList RP  */
#line 120 "syntax.y"
                         {(yyval.type) = getNode("FunDec", 4, (yyvsp[-3].type), (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));
            new_scope();
            if(push_var((yyvsp[-2].type))!=0){// == 0 : acc , == x : error in line x 
                error_type = 3;
                yyerror("Variable aready exists");
            }
            newFuntype((yyval.type), (yyvsp[-3].type), (yyvsp[-1].type));
        }
#line 1490 "syntax.tab.c"
    break;

  case 23: /* FunDec: ID LP RP  */
#line 128 "syntax.y"
                 {(yyval.type) = getNode("FunDec", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));
            new_scope();
            newFuntype((yyval.type), (yyvsp[-2].type), NULL);
        }
#line 1499 "syntax.tab.c"
    break;

  case 24: /* FunDec: ID LP VarList error  */
#line 132 "syntax.y"
                            {error_type = 1;yyerror("Missing closing symbol ')'");}
#line 1505 "syntax.tab.c"
    break;

  case 25: /* FunDec: ID LP error  */
#line 133 "syntax.y"
                    {error_type = 1;yyerror("Missing closing symbol ')'");}
#line 1511 "syntax.tab.c"
    break;

  case 26: /* VarList: ParamDec COMMA VarList  */
#line 135 "syntax.y"
                                {
            (yyval.type) = getNode("VarList", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));
            connect_var((yyvsp[-2].type), (yyvsp[0].type));
            extend_var((yyval.type), (yyvsp[0].type));    
        }
#line 1521 "syntax.tab.c"
    break;

  case 27: /* VarList: ParamDec  */
#line 140 "syntax.y"
                  {
            (yyval.type) = getNode("VarList", 1, (yyvsp[0].type));
            extend_var((yyval.type), (yyvsp[0].type));
        }
#line 1530 "syntax.tab.c"
    break;

  case 28: /* ParamDec: Specifier VarDec  */
#line 145 "syntax.y"
                           {
            (yyval.type) = getNode("ParamDec", 2, (yyvsp[-1].type), (yyvsp[0].type));
            assign_type((yyvsp[-1].type), (yyvsp[0].type));
            extend_var((yyval.type), (yyvsp[0].type));   
        }
#line 1540 "syntax.tab.c"
    break;

  case 29: /* ParamDec: error VarDec  */
#line 150 "syntax.y"
                       {error_type = 1;yyerror("Missing specifier");}
#line 1546 "syntax.tab.c"
    break;

  case 30: /* ParamDec: Specifier error  */
#line 151 "syntax.y"
                          {error_type = 1;yyerror("Missing variable name");}
#line 1552 "syntax.tab.c"
    break;

  case 31: /* CompSt: LC DefList StmtList RC  */
#line 154 "syntax.y"
                               {(yyval.type) = getNode("CompSt", 4, (yyvsp[-3].type), (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1558 "syntax.tab.c"
    break;

  case 32: /* StmtList: Stmt StmtList  */
#line 157 "syntax.y"
                        {(yyval.type) = getNode("StmtList", 2, (yyvsp[-1].type), (yyvsp[0].type));}
#line 1564 "syntax.tab.c"
    break;

  case 33: /* StmtList: %empty  */
#line 158 "syntax.y"
         {(yyval.type)=getTerminalNode("StmtList", -1);}
#line 1570 "syntax.tab.c"
    break;

  case 34: /* Stmt: SEMI  */
#line 160 "syntax.y"
           {(yyval.type) = getNode("Stmt", 1, (yyvsp[0].type));}
#line 1576 "syntax.tab.c"
    break;

  case 35: /* Stmt: Exp SEMI  */
#line 161 "syntax.y"
               {(yyval.type) = getNode("Stmt", 2, (yyvsp[-1].type), (yyvsp[0].type));}
#line 1582 "syntax.tab.c"
    break;

  case 36: /* Stmt: Exp error  */
#line 162 "syntax.y"
                {error_type = 1;yyerror("Missing semicolon ';'");}
#line 1588 "syntax.tab.c"
    break;

  case 37: /* Stmt: CompSt  */
#line 163 "syntax.y"
             {(yyval.type) = getNode("Stmt", 1, (yyvsp[0].type));}
#line 1594 "syntax.tab.c"
    break;

  case 38: /* Stmt: RETURN Exp SEMI  */
#line 164 "syntax.y"
                      {(yyval.type) = getNode("Stmt", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1600 "syntax.tab.c"
    break;

  case 39: /* Stmt: RETURN Exp error  */
#line 165 "syntax.y"
                       {error_type = 1;yyerror("Missing semicolon ';'");}
#line 1606 "syntax.tab.c"
    break;

  case 40: /* Stmt: IF LP Exp RP Stmt  */
#line 166 "syntax.y"
                                              {(yyval.type) = getNode("Stmt", 5, (yyvsp[-4].type), (yyvsp[-3].type), (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1612 "syntax.tab.c"
    break;

  case 41: /* Stmt: IF LP Exp error Stmt  */
#line 167 "syntax.y"
                                                 {error_type = 1;yyerror("This if function miss closing symbol ')'");}
#line 1618 "syntax.tab.c"
    break;

  case 42: /* Stmt: IF LP Exp RP Stmt ELSE Stmt  */
#line 168 "syntax.y"
                                  {(yyval.type) = getNode("Stmt", 7, (yyvsp[-6].type), (yyvsp[-5].type), (yyvsp[-4].type), (yyvsp[-3].type), (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1624 "syntax.tab.c"
    break;

  case 43: /* Stmt: WHILE LP Exp RP Stmt  */
#line 169 "syntax.y"
                           {(yyval.type) = getNode("Stmt", 5, (yyvsp[-4].type), (yyvsp[-3].type), (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1630 "syntax.tab.c"
    break;

  case 44: /* Stmt: WHILE LP RP Stmt  */
#line 170 "syntax.y"
                       {(yyval.type) = getNode("Stmt", 4, (yyvsp[-3].type), (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1636 "syntax.tab.c"
    break;

  case 45: /* Stmt: IF LP Exp error Stmt ELSE Stmt  */
#line 171 "syntax.y"
                                     {error_type = 1;yyerror("This if function miss closing symbol ')'");}
#line 1642 "syntax.tab.c"
    break;

  case 46: /* Stmt: WHILE LP Exp error Stmt  */
#line 172 "syntax.y"
                              {error_type = 1;yyerror("Missing closing symbol ')'");}
#line 1648 "syntax.tab.c"
    break;

  case 47: /* DefList: Def DefList  */
#line 182 "syntax.y"
                     {
            (yyval.type) = getNode("DefList", 2, (yyvsp[-1].type), (yyvsp[0].type));
            connect_var((yyvsp[-1].type), (yyvsp[0].type));
            extend_var((yyval.type), (yyvsp[-1].type));
        }
#line 1658 "syntax.tab.c"
    break;

  case 48: /* DefList: %empty  */
#line 187 "syntax.y"
         {(yyval.type)=getTerminalNode("DefList", -1);}
#line 1664 "syntax.tab.c"
    break;

  case 49: /* Def: Specifier DecList SEMI  */
#line 189 "syntax.y"
                            {
        (yyval.type) = getNode("Def", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));
        assign_type((yyvsp[-2].type), (yyvsp[-1].type));
        extend_var((yyval.type), (yyvsp[-1].type));
        if(push_var((yyvsp[-1].type))!=0){// == 0 : acc , == x : error in line x 
            error_type = 3;
            yyerror("Variable aready exists");
        }
    }
#line 1678 "syntax.tab.c"
    break;

  case 50: /* Def: error DecList SEMI  */
#line 198 "syntax.y"
                       {error_type = 1; yyerror("Missing specifier");}
#line 1684 "syntax.tab.c"
    break;

  case 51: /* Def: Specifier DecList error  */
#line 199 "syntax.y"
                            {error_type = 1; yyerror("Missing semicolon ';'");}
#line 1690 "syntax.tab.c"
    break;

  case 52: /* DecList: Dec  */
#line 201 "syntax.y"
             {
            (yyval.type) = getNode("DecList", 1, (yyvsp[0].type));
            extend_var((yyval.type), (yyvsp[0].type));
        }
#line 1699 "syntax.tab.c"
    break;

  case 53: /* DecList: Dec COMMA DecList  */
#line 205 "syntax.y"
                            {
            (yyval.type) = getNode("DecList", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));
            connect_var((yyvsp[-2].type), (yyvsp[0].type));
            extend_var((yyval.type), (yyvsp[-2].type));
        }
#line 1709 "syntax.tab.c"
    break;

  case 54: /* Dec: VarDec  */
#line 212 "syntax.y"
            {
        (yyval.type) = getNode("Dec", 1, (yyvsp[0].type));
        extend_var((yyval.type), (yyvsp[0].type));
        }
#line 1718 "syntax.tab.c"
    break;

  case 55: /* Dec: VarDec ASSIGN Exp  */
#line 216 "syntax.y"
                        {
        (yyval.type) = getNode("Dec", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));
        extend_var((yyval.type), (yyvsp[-2].type));
    }
#line 1727 "syntax.tab.c"
    break;

  case 56: /* Exp: Exp ASSIGN Exp  */
#line 222 "syntax.y"
                    {(yyval.type) = getNode("Exp", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1733 "syntax.tab.c"
    break;

  case 57: /* Exp: Exp AND Exp  */
#line 223 "syntax.y"
                  {(yyval.type) = getNode("Exp", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1739 "syntax.tab.c"
    break;

  case 58: /* Exp: Exp OR Exp  */
#line 224 "syntax.y"
                 {(yyval.type) = getNode("Exp", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1745 "syntax.tab.c"
    break;

  case 59: /* Exp: Exp LT Exp  */
#line 225 "syntax.y"
                 {(yyval.type) = getNode("Exp", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1751 "syntax.tab.c"
    break;

  case 60: /* Exp: Exp LE Exp  */
#line 226 "syntax.y"
                 {(yyval.type) = getNode("Exp", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1757 "syntax.tab.c"
    break;

  case 61: /* Exp: Exp GT Exp  */
#line 227 "syntax.y"
                 {(yyval.type) = getNode("Exp", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1763 "syntax.tab.c"
    break;

  case 62: /* Exp: Exp GE Exp  */
#line 228 "syntax.y"
                 {(yyval.type) = getNode("Exp", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1769 "syntax.tab.c"
    break;

  case 63: /* Exp: Exp NE Exp  */
#line 229 "syntax.y"
                 {(yyval.type) = getNode("Exp", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1775 "syntax.tab.c"
    break;

  case 64: /* Exp: Exp EQ Exp  */
#line 230 "syntax.y"
                 {(yyval.type) = getNode("Exp", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1781 "syntax.tab.c"
    break;

  case 65: /* Exp: Exp PLUS Exp  */
#line 231 "syntax.y"
                   {(yyval.type) = getNode("Exp", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1787 "syntax.tab.c"
    break;

  case 66: /* Exp: Exp MINUS Exp  */
#line 232 "syntax.y"
                    {(yyval.type) = getNode("Exp", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1793 "syntax.tab.c"
    break;

  case 67: /* Exp: Exp MUL Exp  */
#line 233 "syntax.y"
                  {(yyval.type) = getNode("Exp", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1799 "syntax.tab.c"
    break;

  case 68: /* Exp: Exp DIV Exp  */
#line 234 "syntax.y"
                  {(yyval.type) = getNode("Exp", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1805 "syntax.tab.c"
    break;

  case 69: /* Exp: Exp ASSIGN error  */
#line 235 "syntax.y"
                       {error_type = 1; yyerror("Expect expression after '='");}
#line 1811 "syntax.tab.c"
    break;

  case 70: /* Exp: Exp AND error  */
#line 236 "syntax.y"
                    {error_type = 1; yyerror("Expect expression after 'ans'");}
#line 1817 "syntax.tab.c"
    break;

  case 71: /* Exp: Exp OR error  */
#line 237 "syntax.y"
                   {error_type = 1; yyerror("Expect expression after 'or'");}
#line 1823 "syntax.tab.c"
    break;

  case 72: /* Exp: Exp LT error  */
#line 238 "syntax.y"
                   {error_type = 1; yyerror("Expect expression after '<'");}
#line 1829 "syntax.tab.c"
    break;

  case 73: /* Exp: Exp LE error  */
#line 239 "syntax.y"
                   {error_type = 1; yyerror("Expect expression after '<='");}
#line 1835 "syntax.tab.c"
    break;

  case 74: /* Exp: Exp GT error  */
#line 240 "syntax.y"
                   {error_type = 1; yyerror("Expect expression after '>'");}
#line 1841 "syntax.tab.c"
    break;

  case 75: /* Exp: Exp GE error  */
#line 241 "syntax.y"
                   {error_type = 1; yyerror("Expect expression after '>=");}
#line 1847 "syntax.tab.c"
    break;

  case 76: /* Exp: Exp NE error  */
#line 242 "syntax.y"
                   {error_type = 1; yyerror("Expect expression after '!='");}
#line 1853 "syntax.tab.c"
    break;

  case 77: /* Exp: Exp EQ error  */
#line 243 "syntax.y"
                   {error_type = 1; yyerror("Expect expression after '=='");}
#line 1859 "syntax.tab.c"
    break;

  case 78: /* Exp: Exp PLUS error  */
#line 244 "syntax.y"
                     {error_type = 1; yyerror("Expect expression after '+'");}
#line 1865 "syntax.tab.c"
    break;

  case 79: /* Exp: Exp MINUS error  */
#line 245 "syntax.y"
                      {error_type = 1; yyerror("Expect expression after '-'");}
#line 1871 "syntax.tab.c"
    break;

  case 80: /* Exp: Exp MUL error  */
#line 246 "syntax.y"
                    {error_type = 1; yyerror("Expect expression after '*'");}
#line 1877 "syntax.tab.c"
    break;

  case 81: /* Exp: Exp DIV error  */
#line 247 "syntax.y"
                    {error_type = 1; yyerror("Expect expression after '/'");}
#line 1883 "syntax.tab.c"
    break;

  case 82: /* Exp: LP Exp RP  */
#line 248 "syntax.y"
                {(yyval.type) = getNode("Exp", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1889 "syntax.tab.c"
    break;

  case 83: /* Exp: LP Exp error  */
#line 249 "syntax.y"
                   {error_type = 1;yyerror("Missing closing symbol ')'");}
#line 1895 "syntax.tab.c"
    break;

  case 84: /* Exp: MINUS Exp  */
#line 250 "syntax.y"
                {(yyval.type) = getNode("Exp", 2, (yyvsp[-1].type), (yyvsp[0].type));}
#line 1901 "syntax.tab.c"
    break;

  case 85: /* Exp: NOT Exp  */
#line 251 "syntax.y"
              {(yyval.type) = getNode("Exp", 2, (yyvsp[-1].type), (yyvsp[0].type));}
#line 1907 "syntax.tab.c"
    break;

  case 86: /* Exp: ID LP Args RP  */
#line 252 "syntax.y"
                    {(yyval.type) = getNode("Exp", 4, (yyvsp[-3].type), (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1913 "syntax.tab.c"
    break;

  case 87: /* Exp: ID LP Args error  */
#line 253 "syntax.y"
                       {error_type = 1;yyerror("Missing closing symbol ')'");}
#line 1919 "syntax.tab.c"
    break;

  case 88: /* Exp: ID LP RP  */
#line 254 "syntax.y"
               {(yyval.type) = getNode("Exp", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1925 "syntax.tab.c"
    break;

  case 89: /* Exp: ID LP error  */
#line 255 "syntax.y"
                  {error_type = 1;yyerror("Missing closing symbol ')'");}
#line 1931 "syntax.tab.c"
    break;

  case 90: /* Exp: Exp LB Exp RB  */
#line 256 "syntax.y"
                    {(yyval.type) = getNode("Exp", 4, (yyvsp[-3].type), (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1937 "syntax.tab.c"
    break;

  case 91: /* Exp: Exp LB Exp error  */
#line 257 "syntax.y"
                       {error_type = 1;yyerror("Missing closing symbol ']'");}
#line 1943 "syntax.tab.c"
    break;

  case 92: /* Exp: Exp DOT ID  */
#line 258 "syntax.y"
                 {(yyval.type) = getNode("Exp", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1949 "syntax.tab.c"
    break;

  case 93: /* Exp: ID  */
#line 259 "syntax.y"
         {
        (yyval.type) = getNode("Exp", 1, (yyvsp[0].type));
        if(check_ID_def((yyvsp[0].type)) == 0){
            error_type = 10;
            char* name = (yyvsp[0].type)->value;
            char* msg = (char*)malloc(sizeof(name)+sizeof(char)*100);
            memset(msg, 0,sizeof(msg));
            strcat(msg, "\"");
            strcat(msg, name);
            strcat(msg, "\" is used without a definition");
            yyerror(msg);
            free(msg);
        }
    }
#line 1968 "syntax.tab.c"
    break;

  case 94: /* Exp: INT  */
#line 273 "syntax.y"
          {(yyval.type) = getNode("Exp", 1, (yyvsp[0].type));}
#line 1974 "syntax.tab.c"
    break;

  case 95: /* Exp: FLOAT  */
#line 274 "syntax.y"
            {(yyval.type) = getNode("Exp", 1, (yyvsp[0].type));}
#line 1980 "syntax.tab.c"
    break;

  case 96: /* Exp: CHAR  */
#line 275 "syntax.y"
           {(yyval.type) = getNode("Exp", 1, (yyvsp[0].type));}
#line 1986 "syntax.tab.c"
    break;

  case 97: /* Args: Exp COMMA Args  */
#line 277 "syntax.y"
                     {(yyval.type) = getNode("Args", 3, (yyvsp[-2].type), (yyvsp[-1].type), (yyvsp[0].type));}
#line 1992 "syntax.tab.c"
    break;

  case 98: /* Args: COMMA Args  */
#line 279 "syntax.y"
                 {error_type = 1;yyerror("Unexpected ','");}
#line 1998 "syntax.tab.c"
    break;

  case 99: /* Args: Exp COMMA  */
#line 280 "syntax.y"
                {error_type = 1;yyerror("Expected another parenthesis after ','");}
#line 2004 "syntax.tab.c"
    break;

  case 100: /* Args: Exp  */
#line 281 "syntax.y"
          {(yyval.type) = getNode("Args", 1, (yyvsp[0].type));}
#line 2010 "syntax.tab.c"
    break;


#line 2014 "syntax.tab.c"

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

#line 284 "syntax.y"
