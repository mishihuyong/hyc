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
#line 1 "parser.y"


#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

void init_parser(int argc, char *argv[]);
void quit_parser();

extern FILE* yyin;
FILE *asmfile, *incfile;
#define BUFSIZE 256

#define out_asm(fmt, ...) \
    {fprintf(asmfile, fmt, ##__VA_ARGS__); fprintf(asmfile, "\n");}

#define out_inc(fmt, ...) \
    {fprintf(incfile, fmt, ##__VA_ARGS__); fprintf(incfile, "\n");}

void file_error(char *msg);

int ii = 0, itop = -1, istack[100];
int ww = 0, wtop = -1, wstack[100];

#define _BEG_IF     (istack[++itop] = ++ii)
#define _END_IF     (itop--)
#define _i          (istack[itop])

#define _BEG_WHILE  (wstack[++wtop] = ++ww)
#define _END_WHILE  (wtop--)
#define _w          (wstack[wtop])

int argc = 0, varc = 0;
char *cur_func_name, *args[128], *vars[128];
void write_func_head();
void write_func_tail();

#define _BEG_FUNCDEF(name)  (cur_func_name = (name))
#define _APPEND_ARG(arg)    (args[argc++] = (arg))
#define _APPEND_VAR(var)    (vars[varc++] = (var))
#define _WRITE_FUNCHEAD     write_func_head
#define _END_FUNCDEF        write_func_tail

#define YYSTYPE char *


#line 119 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    T_Void = 258,                  /* T_Void  */
    T_Int = 259,                   /* T_Int  */
    T_While = 260,                 /* T_While  */
    T_If = 261,                    /* T_If  */
    T_Else = 262,                  /* T_Else  */
    T_Return = 263,                /* T_Return  */
    T_Break = 264,                 /* T_Break  */
    T_Continue = 265,              /* T_Continue  */
    T_Print = 266,                 /* T_Print  */
    T_ReadInt = 267,               /* T_ReadInt  */
    T_Le = 268,                    /* T_Le  */
    T_Ge = 269,                    /* T_Ge  */
    T_Eq = 270,                    /* T_Eq  */
    T_Ne = 271,                    /* T_Ne  */
    T_And = 272,                   /* T_And  */
    T_Or = 273,                    /* T_Or  */
    T_IntConstant = 274,           /* T_IntConstant  */
    T_StringConstant = 275,        /* T_StringConstant  */
    T_Identifier = 276             /* T_Identifier  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define T_Void 258
#define T_Int 259
#define T_While 260
#define T_If 261
#define T_Else 262
#define T_Return 263
#define T_Break 264
#define T_Continue 265
#define T_Print 266
#define T_ReadInt 267
#define T_Le 268
#define T_Ge 269
#define T_Eq 270
#define T_Ne 271
#define T_And 272
#define T_Or 273
#define T_IntConstant 274
#define T_StringConstant 275
#define T_Identifier 276

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_T_Void = 3,                     /* T_Void  */
  YYSYMBOL_T_Int = 4,                      /* T_Int  */
  YYSYMBOL_T_While = 5,                    /* T_While  */
  YYSYMBOL_T_If = 6,                       /* T_If  */
  YYSYMBOL_T_Else = 7,                     /* T_Else  */
  YYSYMBOL_T_Return = 8,                   /* T_Return  */
  YYSYMBOL_T_Break = 9,                    /* T_Break  */
  YYSYMBOL_T_Continue = 10,                /* T_Continue  */
  YYSYMBOL_T_Print = 11,                   /* T_Print  */
  YYSYMBOL_T_ReadInt = 12,                 /* T_ReadInt  */
  YYSYMBOL_T_Le = 13,                      /* T_Le  */
  YYSYMBOL_T_Ge = 14,                      /* T_Ge  */
  YYSYMBOL_T_Eq = 15,                      /* T_Eq  */
  YYSYMBOL_T_Ne = 16,                      /* T_Ne  */
  YYSYMBOL_T_And = 17,                     /* T_And  */
  YYSYMBOL_T_Or = 18,                      /* T_Or  */
  YYSYMBOL_T_IntConstant = 19,             /* T_IntConstant  */
  YYSYMBOL_T_StringConstant = 20,          /* T_StringConstant  */
  YYSYMBOL_T_Identifier = 21,              /* T_Identifier  */
  YYSYMBOL_22_ = 22,                       /* '='  */
  YYSYMBOL_23_ = 23,                       /* '<'  */
  YYSYMBOL_24_ = 24,                       /* '>'  */
  YYSYMBOL_25_ = 25,                       /* '+'  */
  YYSYMBOL_26_ = 26,                       /* '-'  */
  YYSYMBOL_27_ = 27,                       /* '*'  */
  YYSYMBOL_28_ = 28,                       /* '/'  */
  YYSYMBOL_29_ = 29,                       /* '%'  */
  YYSYMBOL_30_ = 30,                       /* '!'  */
  YYSYMBOL_31_ = 31,                       /* '('  */
  YYSYMBOL_32_ = 32,                       /* ')'  */
  YYSYMBOL_33_ = 33,                       /* ','  */
  YYSYMBOL_34_ = 34,                       /* '{'  */
  YYSYMBOL_35_ = 35,                       /* ';'  */
  YYSYMBOL_36_ = 36,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 37,                  /* $accept  */
  YYSYMBOL_Start = 38,                     /* Start  */
  YYSYMBOL_Program = 39,                   /* Program  */
  YYSYMBOL_FuncDef = 40,                   /* FuncDef  */
  YYSYMBOL_FuncName = 41,                  /* FuncName  */
  YYSYMBOL_Args = 42,                      /* Args  */
  YYSYMBOL__Args = 43,                     /* _Args  */
  YYSYMBOL_Vars = 44,                      /* Vars  */
  YYSYMBOL__Vars = 45,                     /* _Vars  */
  YYSYMBOL_Var = 46,                       /* Var  */
  YYSYMBOL_Stmts = 47,                     /* Stmts  */
  YYSYMBOL_EndFuncDef = 48,                /* EndFuncDef  */
  YYSYMBOL_Stmt = 49,                      /* Stmt  */
  YYSYMBOL_AssignStmt = 50,                /* AssignStmt  */
  YYSYMBOL_CallStmt = 51,                  /* CallStmt  */
  YYSYMBOL_IfStmt = 52,                    /* IfStmt  */
  YYSYMBOL_If = 53,                        /* If  */
  YYSYMBOL_Then = 54,                      /* Then  */
  YYSYMBOL_EndThen = 55,                   /* EndThen  */
  YYSYMBOL_EndIf = 56,                     /* EndIf  */
  YYSYMBOL_WhileStmt = 57,                 /* WhileStmt  */
  YYSYMBOL_While = 58,                     /* While  */
  YYSYMBOL_Do = 59,                        /* Do  */
  YYSYMBOL_EndWhile = 60,                  /* EndWhile  */
  YYSYMBOL_BreakStmt = 61,                 /* BreakStmt  */
  YYSYMBOL_ContinueStmt = 62,              /* ContinueStmt  */
  YYSYMBOL_ReturnStmt = 63,                /* ReturnStmt  */
  YYSYMBOL_PrintStmt = 64,                 /* PrintStmt  */
  YYSYMBOL_PrintIntArgs = 65,              /* PrintIntArgs  */
  YYSYMBOL_Expr = 66,                      /* Expr  */
  YYSYMBOL_ReadInt = 67,                   /* ReadInt  */
  YYSYMBOL_CallExpr = 68,                  /* CallExpr  */
  YYSYMBOL_Actuals = 69,                   /* Actuals  */
  YYSYMBOL__Actuals = 70                   /* _Actuals  */
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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   312

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  72
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  142

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   276


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
       2,     2,     2,    30,     2,     2,     2,    29,     2,     2,
      31,    32,    27,    25,    33,    26,     2,    28,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    35,
      23,    22,    24,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    34,     2,    36,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    65,    65,    69,    70,    74,    75,    79,    83,    84,
      88,    89,    93,    97,    98,   102,   103,   107,   108,   112,
     116,   117,   118,   119,   120,   121,   122,   123,   127,   131,
     135,   137,   142,   146,   150,   154,   158,   163,   167,   171,
     176,   180,   184,   185,   189,   194,   195,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   222,   227,   232,
     233,   237,   238
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
  "\"end of file\"", "error", "\"invalid token\"", "T_Void", "T_Int",
  "T_While", "T_If", "T_Else", "T_Return", "T_Break", "T_Continue",
  "T_Print", "T_ReadInt", "T_Le", "T_Ge", "T_Eq", "T_Ne", "T_And", "T_Or",
  "T_IntConstant", "T_StringConstant", "T_Identifier", "'='", "'<'", "'>'",
  "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "'('", "')'", "','", "'{'",
  "';'", "'}'", "$accept", "Start", "Program", "FuncDef", "FuncName",
  "Args", "_Args", "Vars", "_Vars", "Var", "Stmts", "EndFuncDef", "Stmt",
  "AssignStmt", "CallStmt", "IfStmt", "If", "Then", "EndThen", "EndIf",
  "WhileStmt", "While", "Do", "EndWhile", "BreakStmt", "ContinueStmt",
  "ReturnStmt", "PrintStmt", "PrintIntArgs", "Expr", "ReadInt", "CallExpr",
  "Actuals", "_Actuals", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-57)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -57,    10,    13,   -57,    17,    17,   -57,   -57,    14,    14,
       3,   -21,   -21,    29,   -57,    30,   -57,   -57,    60,   -57,
     -57,   -57,    64,    31,    58,   -29,    31,    61,   -57,   -57,
      96,    52,    62,    63,   -13,   -57,   -57,   -57,   -57,   -57,
     -57,    68,   -57,    69,   -57,   -57,   -57,   -57,    66,   -57,
      72,   -57,   -57,   -57,    71,   -57,    73,   223,   223,   223,
     -57,   119,   -57,   -57,   -57,   -57,    78,   223,    39,   -57,
     223,   223,   -57,   -57,    85,   -57,   -57,   165,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   -57,   -57,   142,   -57,   242,    57,   185,   205,    74,
     -57,    28,    28,   283,   283,   276,   259,    28,    28,    -8,
      -8,   -57,   -57,   -57,    59,   -57,   -57,   223,   -57,   -57,
     -57,    79,   223,   242,    82,    84,   -57,   242,   -57,   -57,
      38,    67,   -57,   -57,    88,   -57,    86,   -57,   -57,    75,
     -57,   -57
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     2,     1,     0,     0,     4,     7,     0,     0,
       0,     0,     0,     0,     8,     0,    13,    17,    12,    17,
      10,     9,     0,     0,     0,     0,     0,     0,    37,    32,
       0,     0,     0,     0,     0,    19,     6,    18,    20,    21,
      22,     0,    23,     0,    24,    25,    26,    27,     0,    15,
       0,    14,     5,    11,     0,    47,    48,     0,     0,     0,
      42,     0,    64,    65,    40,    41,     0,     0,     0,    68,
       0,     0,    29,    16,     0,    62,    63,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    43,    45,     0,    69,    71,     0,     0,     0,     0,
      66,    57,    56,    58,    59,    61,    60,    55,    54,    49,
      50,    51,    52,    53,     0,    28,    70,     0,    33,    38,
      67,     0,     0,    72,     0,     0,    44,    46,    17,    17,
       0,     0,    34,    39,    35,    36,     0,    30,    17,     0,
      35,    31
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -57,   -57,   -57,   -57,   102,   114,   -57,   112,   -57,   -57,
     -19,    99,   -57,   -57,   -57,   -57,   -57,   -57,   -57,   -12,
     -57,   -57,   -57,   -57,   -57,   -57,   -57,   -57,   -57,   -56,
     -57,   -18,   -57,   -57
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     6,     8,    11,    15,    17,    18,    25,
      23,    36,    37,    38,    39,    40,    41,   124,   134,   137,
      42,    43,   125,   135,    44,    45,    46,    47,   114,    61,
      62,    63,    69,    96
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      26,    75,    76,    77,    50,    48,    51,    13,    48,    67,
       3,    93,    95,    16,    97,    98,     4,     5,    68,    88,
      89,    90,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,    14,    28,    29,     7,    30,
      31,    32,    33,    28,    29,    10,    30,    31,    32,    33,
      20,    54,    34,    86,    87,    88,    89,    90,    55,    34,
      56,   123,    21,    22,    24,    57,   127,    35,    27,    58,
      59,    94,    28,    29,   132,    30,    31,    32,    33,    49,
      28,    29,    53,    30,    31,    32,    33,    64,    34,   116,
     117,   121,   122,    73,    66,   136,    34,    65,    92,    70,
      71,    72,    74,   133,    68,    99,   120,     9,    54,   130,
     131,   140,    48,    48,   126,    55,   128,    56,   129,   139,
     138,    48,    57,    12,    19,    52,    58,    59,   141,     0,
       0,    60,    78,    79,    80,    81,    82,    83,     0,     0,
       0,     0,    84,    85,    86,    87,    88,    89,    90,     0,
       0,     0,     0,     0,    91,    78,    79,    80,    81,    82,
      83,     0,     0,     0,     0,    84,    85,    86,    87,    88,
      89,    90,     0,     0,     0,     0,     0,   115,    78,    79,
      80,    81,    82,    83,     0,     0,     0,     0,    84,    85,
      86,    87,    88,    89,    90,     0,     0,   100,    78,    79,
      80,    81,    82,    83,     0,     0,     0,     0,    84,    85,
      86,    87,    88,    89,    90,     0,     0,   118,    78,    79,
      80,    81,    82,    83,     0,     0,     0,     0,    84,    85,
      86,    87,    88,    89,    90,    54,     0,   119,     0,     0,
       0,     0,    55,     0,    56,     0,     0,     0,     0,    57,
       0,     0,     0,    58,    59,    78,    79,    80,    81,    82,
      83,     0,     0,     0,     0,    84,    85,    86,    87,    88,
      89,    90,    78,    79,    80,    81,    82,     0,     0,     0,
       0,     0,    84,    85,    86,    87,    88,    89,    90,    78,
      79,    80,    81,     0,     0,     0,    78,    79,     0,    84,
      85,    86,    87,    88,    89,    90,    84,    85,    86,    87,
      88,    89,    90
};

static const yytype_int16 yycheck[] =
{
      19,    57,    58,    59,    33,    23,    35,     4,    26,    22,
       0,    67,    68,    34,    70,    71,     3,     4,    31,    27,
      28,    29,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    32,     5,     6,    21,     8,
       9,    10,    11,     5,     6,    31,     8,     9,    10,    11,
      21,    12,    21,    25,    26,    27,    28,    29,    19,    21,
      21,   117,    32,    33,     4,    26,   122,    36,     4,    30,
      31,    32,     5,     6,    36,     8,     9,    10,    11,    21,
       5,     6,    21,     8,     9,    10,    11,    35,    21,    32,
      33,    32,    33,    21,    31,     7,    21,    35,    20,    31,
      31,    35,    31,    36,    31,    20,    32,     5,    12,   128,
     129,    36,   130,   131,    35,    19,    34,    21,    34,   138,
      34,   139,    26,     9,    12,    26,    30,    31,   140,    -1,
      -1,    35,    13,    14,    15,    16,    17,    18,    -1,    -1,
      -1,    -1,    23,    24,    25,    26,    27,    28,    29,    -1,
      -1,    -1,    -1,    -1,    35,    13,    14,    15,    16,    17,
      18,    -1,    -1,    -1,    -1,    23,    24,    25,    26,    27,
      28,    29,    -1,    -1,    -1,    -1,    -1,    35,    13,    14,
      15,    16,    17,    18,    -1,    -1,    -1,    -1,    23,    24,
      25,    26,    27,    28,    29,    -1,    -1,    32,    13,    14,
      15,    16,    17,    18,    -1,    -1,    -1,    -1,    23,    24,
      25,    26,    27,    28,    29,    -1,    -1,    32,    13,    14,
      15,    16,    17,    18,    -1,    -1,    -1,    -1,    23,    24,
      25,    26,    27,    28,    29,    12,    -1,    32,    -1,    -1,
      -1,    -1,    19,    -1,    21,    -1,    -1,    -1,    -1,    26,
      -1,    -1,    -1,    30,    31,    13,    14,    15,    16,    17,
      18,    -1,    -1,    -1,    -1,    23,    24,    25,    26,    27,
      28,    29,    13,    14,    15,    16,    17,    -1,    -1,    -1,
      -1,    -1,    23,    24,    25,    26,    27,    28,    29,    13,
      14,    15,    16,    -1,    -1,    -1,    13,    14,    -1,    23,
      24,    25,    26,    27,    28,    29,    23,    24,    25,    26,
      27,    28,    29
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    38,    39,     0,     3,     4,    40,    21,    41,    41,
      31,    42,    42,     4,    32,    43,    34,    44,    45,    44,
      21,    32,    33,    47,     4,    46,    47,     4,     5,     6,
       8,     9,    10,    11,    21,    36,    48,    49,    50,    51,
      52,    53,    57,    58,    61,    62,    63,    64,    68,    21,
      33,    35,    48,    21,    12,    19,    21,    26,    30,    31,
      35,    66,    67,    68,    35,    35,    31,    22,    31,    69,
      31,    31,    35,    21,    31,    66,    66,    66,    13,    14,
      15,    16,    17,    18,    23,    24,    25,    26,    27,    28,
      29,    35,    20,    66,    32,    66,    70,    66,    66,    20,
      32,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    65,    35,    32,    33,    32,    32,
      32,    32,    33,    66,    54,    59,    35,    66,    34,    34,
      47,    47,    36,    36,    55,    60,     7,    56,    34,    47,
      36,    56
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    38,    39,    39,    40,    40,    41,    42,    42,
      43,    43,    44,    45,    45,    46,    46,    47,    47,    48,
      49,    49,    49,    49,    49,    49,    49,    49,    50,    51,
      52,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    63,    64,    65,    65,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    67,    68,    69,
      69,    70,    70
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     6,     6,     1,     2,     3,
       2,     4,     1,     1,     3,     2,     3,     0,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     2,
      10,    14,     1,     0,     0,     0,     9,     1,     0,     0,
       2,     2,     2,     3,     6,     0,     3,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     2,     1,     1,     3,     4,     2,     2,
       3,     1,     3
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
  case 2: /* Start: Program  */
#line 65 "parser.y"
                                    { /* empty */ }
#line 1386 "y.tab.c"
    break;

  case 3: /* Program: %empty  */
#line 69 "parser.y"
                                    { /* empty */ }
#line 1392 "y.tab.c"
    break;

  case 4: /* Program: Program FuncDef  */
#line 70 "parser.y"
                                    { /* empty */ }
#line 1398 "y.tab.c"
    break;

  case 7: /* FuncName: T_Identifier  */
#line 79 "parser.y"
                                    { _BEG_FUNCDEF(yyvsp[0]); }
#line 1404 "y.tab.c"
    break;

  case 8: /* Args: '(' ')'  */
#line 83 "parser.y"
                                    { /* empty */ }
#line 1410 "y.tab.c"
    break;

  case 9: /* Args: '(' _Args ')'  */
#line 84 "parser.y"
                                    { /* empty */ }
#line 1416 "y.tab.c"
    break;

  case 10: /* _Args: T_Int T_Identifier  */
#line 88 "parser.y"
                                    { _APPEND_ARG(yyvsp[0]); }
#line 1422 "y.tab.c"
    break;

  case 11: /* _Args: _Args ',' T_Int T_Identifier  */
#line 89 "parser.y"
                                    { _APPEND_ARG(yyvsp[0]); }
#line 1428 "y.tab.c"
    break;

  case 12: /* Vars: _Vars  */
#line 93 "parser.y"
                                    { _WRITE_FUNCHEAD(); }
#line 1434 "y.tab.c"
    break;

  case 13: /* _Vars: '{'  */
#line 97 "parser.y"
                                    { /* empty */ }
#line 1440 "y.tab.c"
    break;

  case 14: /* _Vars: _Vars Var ';'  */
#line 98 "parser.y"
                                    { /* empty */ }
#line 1446 "y.tab.c"
    break;

  case 15: /* Var: T_Int T_Identifier  */
#line 102 "parser.y"
                                    { _APPEND_VAR(yyvsp[0]); }
#line 1452 "y.tab.c"
    break;

  case 16: /* Var: Var ',' T_Identifier  */
#line 103 "parser.y"
                                    { _APPEND_VAR(yyvsp[0]); }
#line 1458 "y.tab.c"
    break;

  case 17: /* Stmts: %empty  */
#line 107 "parser.y"
                                    { /* empty */ }
#line 1464 "y.tab.c"
    break;

  case 18: /* Stmts: Stmts Stmt  */
#line 108 "parser.y"
                                    { /* empty */ }
#line 1470 "y.tab.c"
    break;

  case 19: /* EndFuncDef: '}'  */
#line 112 "parser.y"
                                    { _END_FUNCDEF(); }
#line 1476 "y.tab.c"
    break;

  case 20: /* Stmt: AssignStmt  */
#line 116 "parser.y"
                                    { /* empty */ }
#line 1482 "y.tab.c"
    break;

  case 21: /* Stmt: CallStmt  */
#line 117 "parser.y"
                                    { /* empty */ }
#line 1488 "y.tab.c"
    break;

  case 22: /* Stmt: IfStmt  */
#line 118 "parser.y"
                                    { /* empty */ }
#line 1494 "y.tab.c"
    break;

  case 23: /* Stmt: WhileStmt  */
#line 119 "parser.y"
                                    { /* empty */ }
#line 1500 "y.tab.c"
    break;

  case 24: /* Stmt: BreakStmt  */
#line 120 "parser.y"
                                    { /* empty */ }
#line 1506 "y.tab.c"
    break;

  case 25: /* Stmt: ContinueStmt  */
#line 121 "parser.y"
                                    { /* empty */ }
#line 1512 "y.tab.c"
    break;

  case 26: /* Stmt: ReturnStmt  */
#line 122 "parser.y"
                                    { /* empty */ }
#line 1518 "y.tab.c"
    break;

  case 27: /* Stmt: PrintStmt  */
#line 123 "parser.y"
                                    { /* empty */ }
#line 1524 "y.tab.c"
    break;

  case 28: /* AssignStmt: T_Identifier '=' Expr ';'  */
#line 127 "parser.y"
                                    { out_asm("\tpop %s", yyvsp[-3]); }
#line 1530 "y.tab.c"
    break;

  case 29: /* CallStmt: CallExpr ';'  */
#line 131 "parser.y"
                                    { out_asm("\tpop"); }
#line 1536 "y.tab.c"
    break;

  case 30: /* IfStmt: If '(' Expr ')' Then '{' Stmts '}' EndThen EndIf  */
#line 136 "parser.y"
                                    { /* empty */ }
#line 1542 "y.tab.c"
    break;

  case 31: /* IfStmt: If '(' Expr ')' Then '{' Stmts '}' EndThen T_Else '{' Stmts '}' EndIf  */
#line 138 "parser.y"
                                    { /* empty */ }
#line 1548 "y.tab.c"
    break;

  case 32: /* If: T_If  */
#line 142 "parser.y"
                    { _BEG_IF; out_asm("_begIf_%d:", _i); }
#line 1554 "y.tab.c"
    break;

  case 33: /* Then: %empty  */
#line 146 "parser.y"
                    { out_asm("\tjz _elIf_%d", _i); }
#line 1560 "y.tab.c"
    break;

  case 34: /* EndThen: %empty  */
#line 150 "parser.y"
                    { out_asm("\tjmp _endIf_%d\n_elIf_%d:", _i, _i); }
#line 1566 "y.tab.c"
    break;

  case 35: /* EndIf: %empty  */
#line 154 "parser.y"
                    { out_asm("_endIf_%d:", _i); _END_IF; }
#line 1572 "y.tab.c"
    break;

  case 36: /* WhileStmt: While '(' Expr ')' Do '{' Stmts '}' EndWhile  */
#line 159 "parser.y"
                    { /* empty */ }
#line 1578 "y.tab.c"
    break;

  case 37: /* While: T_While  */
#line 163 "parser.y"
                    { _BEG_WHILE; out_asm("_begWhile_%d:", _w); }
#line 1584 "y.tab.c"
    break;

  case 38: /* Do: %empty  */
#line 167 "parser.y"
                    { out_asm("\tjz _endWhile_%d", _w); }
#line 1590 "y.tab.c"
    break;

  case 39: /* EndWhile: %empty  */
#line 171 "parser.y"
                    { out_asm("\tjmp _begWhile_%d\n_endWhile_%d:", 
                                                _w, _w); _END_WHILE; }
#line 1597 "y.tab.c"
    break;

  case 40: /* BreakStmt: T_Break ';'  */
#line 176 "parser.y"
                    { out_asm("\tjmp _endWhile_%d", _w); }
#line 1603 "y.tab.c"
    break;

  case 41: /* ContinueStmt: T_Continue ';'  */
#line 180 "parser.y"
                    { out_asm("\tjmp _begWhile_%d", _w); }
#line 1609 "y.tab.c"
    break;

  case 42: /* ReturnStmt: T_Return ';'  */
#line 184 "parser.y"
                            { out_asm("\tret"); }
#line 1615 "y.tab.c"
    break;

  case 43: /* ReturnStmt: T_Return Expr ';'  */
#line 185 "parser.y"
                            { out_asm("\tret ~"); }
#line 1621 "y.tab.c"
    break;

  case 44: /* PrintStmt: T_Print '(' T_StringConstant PrintIntArgs ')' ';'  */
#line 190 "parser.y"
                            { out_asm("\tprint %s", yyvsp[-3]); }
#line 1627 "y.tab.c"
    break;

  case 45: /* PrintIntArgs: %empty  */
#line 194 "parser.y"
                            { /* empty */ }
#line 1633 "y.tab.c"
    break;

  case 46: /* PrintIntArgs: PrintIntArgs ',' Expr  */
#line 195 "parser.y"
                            { /* empty */ }
#line 1639 "y.tab.c"
    break;

  case 47: /* Expr: T_IntConstant  */
#line 199 "parser.y"
                            { out_asm("\tpush %s", yyvsp[0]); }
#line 1645 "y.tab.c"
    break;

  case 48: /* Expr: T_Identifier  */
#line 200 "parser.y"
                            { out_asm("\tpush %s", yyvsp[0]); }
#line 1651 "y.tab.c"
    break;

  case 49: /* Expr: Expr '+' Expr  */
#line 201 "parser.y"
                            { out_asm("\tadd"); }
#line 1657 "y.tab.c"
    break;

  case 50: /* Expr: Expr '-' Expr  */
#line 202 "parser.y"
                            { out_asm("\tsub"); }
#line 1663 "y.tab.c"
    break;

  case 51: /* Expr: Expr '*' Expr  */
#line 203 "parser.y"
                            { out_asm("\tmul"); }
#line 1669 "y.tab.c"
    break;

  case 52: /* Expr: Expr '/' Expr  */
#line 204 "parser.y"
                            { out_asm("\tdiv"); }
#line 1675 "y.tab.c"
    break;

  case 53: /* Expr: Expr '%' Expr  */
#line 205 "parser.y"
                            { out_asm("\tmod"); }
#line 1681 "y.tab.c"
    break;

  case 54: /* Expr: Expr '>' Expr  */
#line 206 "parser.y"
                            { out_asm("\tcmpgt"); }
#line 1687 "y.tab.c"
    break;

  case 55: /* Expr: Expr '<' Expr  */
#line 207 "parser.y"
                            { out_asm("\tcmplt"); }
#line 1693 "y.tab.c"
    break;

  case 56: /* Expr: Expr T_Ge Expr  */
#line 208 "parser.y"
                            { out_asm("\tcmpge"); }
#line 1699 "y.tab.c"
    break;

  case 57: /* Expr: Expr T_Le Expr  */
#line 209 "parser.y"
                            { out_asm("\tcmple"); }
#line 1705 "y.tab.c"
    break;

  case 58: /* Expr: Expr T_Eq Expr  */
#line 210 "parser.y"
                            { out_asm("\tcmpeq"); }
#line 1711 "y.tab.c"
    break;

  case 59: /* Expr: Expr T_Ne Expr  */
#line 211 "parser.y"
                            { out_asm("\tcmpne"); }
#line 1717 "y.tab.c"
    break;

  case 60: /* Expr: Expr T_Or Expr  */
#line 212 "parser.y"
                            { out_asm("\tor"); }
#line 1723 "y.tab.c"
    break;

  case 61: /* Expr: Expr T_And Expr  */
#line 213 "parser.y"
                            { out_asm("\tand"); }
#line 1729 "y.tab.c"
    break;

  case 62: /* Expr: '-' Expr  */
#line 214 "parser.y"
                            { out_asm("\tneg"); }
#line 1735 "y.tab.c"
    break;

  case 63: /* Expr: '!' Expr  */
#line 215 "parser.y"
                            { out_asm("\tnot"); }
#line 1741 "y.tab.c"
    break;

  case 64: /* Expr: ReadInt  */
#line 216 "parser.y"
                            { /* empty */ }
#line 1747 "y.tab.c"
    break;

  case 65: /* Expr: CallExpr  */
#line 217 "parser.y"
                            { /* empty */ }
#line 1753 "y.tab.c"
    break;

  case 66: /* Expr: '(' Expr ')'  */
#line 218 "parser.y"
                            { /* empty */ }
#line 1759 "y.tab.c"
    break;

  case 67: /* ReadInt: T_ReadInt '(' T_StringConstant ')'  */
#line 223 "parser.y"
                            { out_asm("\treadint %s", yyvsp[-1]); }
#line 1765 "y.tab.c"
    break;

  case 68: /* CallExpr: T_Identifier Actuals  */
#line 228 "parser.y"
                            { out_asm("\tcall %s", yyvsp[-1]); }
#line 1771 "y.tab.c"
    break;


#line 1775 "y.tab.c"

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

#line 241 "parser.y"


int main(int argc, char *argv[]) {
    init_parser(argc, argv);
    yyparse();
    quit_parser();
}

void init_parser(int argc, char *argv[]) {
    if (argc < 2) {
        file_error("Must provide an input source file!");
    }

    if (argc > 2) {
        file_error("Too much command line arguments!");
    }

    char *in_file_name = argv[1];
    int len = strlen(in_file_name);

    if (len <= 2 || in_file_name[len-1] != 'c' \
            || in_file_name[len-2] != '.') {
        file_error("Must provide an '.c' source file!");
    }

    if (!(yyin = fopen(in_file_name, "r"))) {
        file_error("Input file open error");
    }

    char out_file_name[BUFSIZE];
    strcpy(out_file_name, in_file_name);

    out_file_name[len-1] = 'a';
    out_file_name[len]   = 's';
    out_file_name[len+1] = 'm';
    out_file_name[len+2] = '\0';
    if (!(asmfile = fopen(out_file_name, "w"))) {
        file_error("Output 'asm' file open error");
    }

    out_file_name[len-1] = 'i';
    out_file_name[len]   = 'n';
    out_file_name[len+1] = 'c';
    if (!(incfile = fopen(out_file_name, "w"))) {
        file_error("Output 'inc' file open error");
    }
}

void file_error(char *msg) {
    printf("\n*** Error ***\n\t%s\n", msg);
    puts("");
    exit(-1);
}

char *cat_strs(char *buf, char *strs[], int strc) {
    int i;
    strcpy(buf, strs[0]);
    for (i = 1; i < strc; i++) {
        strcat(strcat(buf, ", "), strs[i]);
    }
    return buf;
}

#define _fn (cur_func_name)

void write_func_head() {
    char buf[BUFSIZE];
    int i;

    out_asm("FUNC @%s:", _fn);
    if (argc > 0) {
        out_asm("\t%s.arg %s", _fn, cat_strs(buf, args, argc));
    }
    if (varc > 0) {
        out_asm("\t%s.var %s", _fn, cat_strs(buf, vars, varc));
    }

    out_inc("; ==== begin function `%s` ====", _fn);
    out_inc("%%define %s.argc %d", _fn, argc);
    out_inc("\n%%MACRO $%s 0\n"
            "   CALL @%s\n"
            "   ADD ESP, 4*%s.argc\n"
            "   PUSH EAX\n"
            "%%ENDMACRO",
            _fn, _fn, _fn);
    if (argc) {
        out_inc("\n%%MACRO %s.arg %s.argc", _fn, _fn);
        for (i = 0; i < argc; i++) {
            out_inc("\t%%define %s [EBP + 8 + 4*%s.argc - 4*%d]",
                        args[i], _fn, i+1);
        }
        out_inc("%%ENDMACRO");
    }
    if (varc) {
        out_inc("\n%%define %s.varc %d", _fn, varc);
        out_inc("\n%%MACRO %s.var %s.varc", _fn, _fn);
        for (i = 0; i < varc; i++) {
            out_inc("\t%%define %s [EBP - 4*%d]",
                        vars[i], i+1);
        }
        out_inc("\tSUB ESP, 4*%s.varc", _fn);
        out_inc("%%ENDMACRO");
    }
}

void write_func_tail() {
    int i;

    out_asm("ENDFUNC@%s\n", _fn);

    out_inc("\n%%MACRO ENDFUNC@%s 0\n\tLEAVE\n\tRET", _fn);
    for (i = 0; i < argc; i++) {
        out_inc("\t%%undef %s", args[i]);
    }
    for (i = 0; i < varc; i++) {
        out_inc("\t%%undef %s", vars[i]);
    }
    out_inc("%%ENDMACRO");
    out_inc("; ==== end function `%s`   ====\n", _fn);

    argc = 0;
    varc = 0;
}

void quit_parser() {
    fclose(yyin); fclose(asmfile); fclose(incfile);
}
