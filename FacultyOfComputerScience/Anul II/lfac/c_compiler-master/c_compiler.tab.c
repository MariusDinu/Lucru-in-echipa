/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "c_compiler.y"

int yylex();
void yyerror(const char *s);
char *id[100];
char *type[100];
#include "hashing.c"
#include<stdio.h>
#include<stdlib.h>
#define SYMTABSIZE	997
#define IDLENGTH	15
#define NOTHING		struct value temp;temp.use="none";
#define INDENTOFFSET	2

enum ParseTreeNodeType {UNARY_OPERATOR,UNARY_EXPRESSION,TYPE_SPECIFIER,TYPE_QUALIFIER_LIST,TYPE_QUALIFIER,TYPE_NAME,TRANSLATION_UNIT,STRUCT_DECLARATOR,STRUCT_DECLARATOR_LIST,SPECIFIER_QUALIFIER_LIST,STRUCT_DECLARATION,STRUCT_DECLARATION_LIST,STRUCT_OR_UNION,STRUCT_OR_UNION_SPECIFIER,STORAGE_CLASS_SPECIFIER,STATEMENT,STATIC_ASSERT_DECLARATION,SHIFT_EXPRESSION,STRING,SELECTION_STATEMENT,RELATIONAL_EXPRESSION,PROGRAM,PRIMARY_EXPRESSION,POSTFIX_EXPRESSION,POINTER,PARAMETER_DECLARATION,PARAMETER_LIST,PARAMETER_TYPE_LIST,MULTIPLICATIVE_EXPRESSION,LOGICAL_OR_EXPRESSION,LOGICAL_AND_EXPRESSION,LABELED_STATEMENT,JUMP_STATEMENT,ITERATION_STATEMENT,INITIALIZER_LIST,INITIALIZER,INIT_DECLARATOR,INIT_DECLARATOR_LIST,INCLUSIVE_OR_EXPRESSION,IDENTIFIER_LIST,GENERIC_ASSOCIATION,GENERIC_ASSOC_LIST,GENERIC_SELECTION,FUNCTION_SPECIFIER,FUNCTION_DEFINITION,EXTERNAL_DECLARATION,EXPRESSION_STATEMENT,EXPRESSION,EXCLUSIVE_OR_EXPRESSION,EQUALITY_EXPRESSION,ENUMERATOR,ENUMERATOR_LIST,ENUM_SPECIFIER,DIRECT_ABSTRACT_DECLARATOR,DIRECT_DECLARATOR,DESIGNATOR,DESIGNATOR_LIST,DESIGNATION,DECLARATION_LIST,DECLARATOR,DECLARATION_SPECIFIERS,DECLARATION,CONSTANT_EXPRESSION,CONSTANT,CONDITIONAL_EXPRESSION,COMPOUND_STATEMENT,CAST_EXPRESSION,BLOCK_ITEM,BLOCK_ITEM_LIST,ASSIGNMENT_OPERATOR,ASSIGNMENT_EXPRESSION,ARGUMENT_EXPRESSION_LIST,AND_EXPRESSION,ALIGNMENT_SPECIFIER,ADDITIVE_EXPRESSION,ABSTRACT_DECLARATOR};

const char* labels[] = {"UNARY_OPERATOR","UNARY_EXPRESSION","TYPE_SPECIFIER","TYPE_QUALIFIER_LIST","TYPE_QUALIFIER","TYPE_NAME","TRANSLATION_UNIT","STRUCT_DECLARATOR","STRUCT_DECLARATOR_LIST","SPECIFIER_QUALIFIER_LIST","STRUCT_DECLARATION","STRUCT_DECLARATION_LIST","STRUCT_OR_UNION","STRUCT_OR_UNION_SPECIFIER","STORAGE_CLASS_SPECIFIER","STATEMENT","STATIC_ASSERT_DECLARATION","SHIFT_EXPRESSION","STRING","SELECTION_STATEMENT","RELATIONAL_EXPRESSION","PROGRAM","PRIMARY_EXPRESSION","POSTFIX_EXPRESSION","POINTER","PARAMETER_DECLARATION","PARAMETER_LIST","PARAMETER_TYPE_LIST","MULTIPLICATIVE_EXPRESSION","LOGICAL_OR_EXPRESSION","LOGICAL_AND_EXPRESSION","LABELED_STATEMENT","JUMP_STATEMENT","ITERATION_STATEMENT","INITIALIZER_LIST","INITIALIZER","INIT_DECLARATOR","INIT_DECLARATOR_LIST","INCLUSIVE_OR_EXPRESSION","IDENTIFIER_LIST","GENERIC_ASSOCIATION","GENERIC_ASSOC_LIST","GENERIC_SELECTION","FUNCTION_SPECIFIER","FUNCTION_DEFINITION","EXTERNAL_DECLARATION","EXPRESSION_STATEMENT","EXPRESSION","EXCLUSIVE_OR_EXPRESSION","EQUALITY_EXPRESSION","ENUMERATOR","ENUMERATOR_LIST","ENUM_SPECIFIER","DIRECT_ABSTRACT_DECLARATOR","DIRECT_DECLARATOR","DESIGNATOR","DESIGNATOR_LIST","DESIGNATION","DECLARATION_LIST","DECLARATOR","DECLARATION_SPECIFIERS","DECLARATION","CONSTANT_EXPRESSION","CONSTANT","CONDITIONAL_EXPRESSION","COMPOUND_STATEMENT","CAST_EXPRESSION","BLOCK_ITEM","BLOCK_ITEM_LIST","ASSIGNMENT_OPERATOR","ASSIGNMENT_EXPRESSION","ARGUMENT_EXPRESSION_LIST","AND_EXPRESSION","ALIGNMENT_SPECIFIER","ADDITIVE_EXPRESSION","ABSTRACT_DECLARATOR"};
#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef NULL
#define NULL 0
#endif
/*-------------Parse tree------------*/
/*struct value{
	union {
		int i;
		int f;
		char *s;
	} v;
	char *use;
};*/
struct treeNode {
	struct value{
		union {
			int i;
			float f;
			char *s;
		} v;
		char *use;
	} val;
	int nodeIdentifier;
	struct treeNode *first;
	struct treeNode *second;
	struct treeNode *third;
	struct treeNode *fourth;
};
typedef struct treeNode TREE_NODE;
typedef TREE_NODE *BINARY_TREE;
BINARY_TREE create_node(struct value,int,BINARY_TREE,BINARY_TREE,BINARY_TREE,BINARY_TREE);

/*-------------Symbol Table----------*/
struct symTabNode {
	char identifier[IDLENGTH];
	char type[100];
};
typedef struct symTabNode SYMTABNODE;
typedef SYMTABNODE *SYMTABNODEPTR;

SYMTABNODEPTR symTab[SYMTABSIZE];

int currentSymTabSize=0;
void PrintTree(BINARY_TREE);

/* Line 371 of yacc.c  */
#line 137 "c_compiler.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENTIFIER = 258,
     I_CONSTANT = 259,
     F_CONSTANT = 260,
     STRING_LITERAL = 261,
     FUNC_NAME = 262,
     SIZEOF = 263,
     PTR_OP = 264,
     INC_OP = 265,
     DEC_OP = 266,
     LEFT_OP = 267,
     RIGHT_OP = 268,
     LE_OP = 269,
     GE_OP = 270,
     EQ_OP = 271,
     NE_OP = 272,
     AND_OP = 273,
     OR_OP = 274,
     MUL_ASSIGN = 275,
     DIV_ASSIGN = 276,
     MOD_ASSIGN = 277,
     ADD_ASSIGN = 278,
     SUB_ASSIGN = 279,
     LEFT_ASSIGN = 280,
     RIGHT_ASSIGN = 281,
     AND_ASSIGN = 282,
     XOR_ASSIGN = 283,
     OR_ASSIGN = 284,
     TYPEDEF_NAME = 285,
     ENUMERATION_CONSTANT = 286,
     TYPEDEF = 287,
     EXTERN = 288,
     STATIC = 289,
     AUTO = 290,
     REGISTER = 291,
     INLINE = 292,
     CONST = 293,
     RESTRICT = 294,
     VOLATILE = 295,
     BOOL = 296,
     CHAR = 297,
     SHORT = 298,
     INT = 299,
     LONG = 300,
     SIGNED = 301,
     UNSIGNED = 302,
     FLOAT = 303,
     DOUBLE = 304,
     VOID = 305,
     COMPLEX = 306,
     IMAGINARY = 307,
     STRUCT = 308,
     UNION = 309,
     ENUM = 310,
     ELLIPSIS = 311,
     CASE = 312,
     DEFAULT = 313,
     IF = 314,
     ELSE = 315,
     SWITCH = 316,
     WHILE = 317,
     DO = 318,
     FOR = 319,
     GOTO = 320,
     CONTINUE = 321,
     BREAK = 322,
     RETURN = 323,
     ALIGNAS = 324,
     ALIGNOF = 325,
     ATOMIC = 326,
     GENERIC = 327,
     NORETURN = 328,
     STATIC_ASSERT = 329,
     THREAD_LOCAL = 330
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 69 "c_compiler.y"

	int iVal;
	float fVal;
	char *sVal;
	BINARY_TREE tVal;


/* Line 387 of yacc.c  */
#line 260 "c_compiler.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

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



/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 288 "c_compiler.tab.c"

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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
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

# define YYCOPY_NEEDED 1

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
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  60
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2310

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  101
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  80
/* YYNRULES -- Number of rules.  */
#define YYNRULES  275
/* YYNRULES -- Number of states.  */
#define YYNSTATES  477

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   331

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   100,     2,     2,     2,    96,    80,     2,
      78,    79,    92,    76,    81,    77,    91,    95,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    86,    87,
      97,    88,    98,    85,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    89,     2,    90,    93,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    83,    94,    84,    99,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    82
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     8,    10,    12,    16,    20,    25,
      30,    32,    36,    38,    42,    44,    48,    50,    52,    54,
      56,    58,    60,    62,    64,    66,    68,    70,    72,    75,
      77,    79,    81,    86,    89,    90,    95,    97,   103,   105,
     107,   109,   111,   114,   118,   120,   123,   125,   128,   130,
     133,   135,   138,   140,   143,   145,   148,   150,   152,   155,
     158,   160,   163,   167,   170,   172,   176,   180,   185,   192,
     198,   204,   211,   217,   222,   227,   232,   236,   241,   245,
     248,   252,   258,   263,   269,   274,   278,   282,   286,   291,
     298,   304,   310,   317,   322,   327,   330,   331,   336,   340,
     345,   350,   356,   362,   369,   372,   374,   378,   382,   384,
     386,   388,   392,   396,   398,   402,   404,   408,   410,   413,
     415,   417,   422,   426,   428,   430,   437,   439,   443,   447,
     451,   453,   457,   459,   463,   465,   469,   473,   475,   479,
     484,   486,   489,   491,   496,   500,   506,   514,   521,   529,
     536,   544,   548,   551,   554,   557,   561,   565,   570,   574,
     576,   580,   582,   586,   588,   592,   596,   600,   604,   606,
     608,   612,   615,   618,   620,   624,   627,   630,   632,   634,
     639,   643,   648,   652,   656,   659,   662,   669,   677,   679,
     681,   683,   687,   689,   691,   693,   697,   701,   705,   709,
     717,   723,   729,   731,   733,   735,   739,   743,   751,   753,
     755,   757,   759,   761,   763,   765,   767,   769,   771,   773,
     775,   780,   786,   789,   791,   793,   795,   798,   801,   805,
     807,   810,   812,   815,   817,   819,   823,   826,   830,   832,
     834,   837,   840,   842,   844,   846,   848,   850,   853,   855,
     857,   859,   861,   863,   865,   867,   869,   871,   873,   875,
     877,   879,   881,   883,   885,   888,   891,   894,   897,   902,
     907,   909,   911,   913,   915,   917
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     159,     0,    -1,   156,   125,    -1,   156,    -1,   125,    -1,
     152,    -1,   103,    76,   152,    -1,   103,    77,   152,    -1,
      69,    78,   175,    79,    -1,    69,    78,   116,    79,    -1,
     131,    -1,   105,    80,   131,    -1,   107,    -1,   106,    81,
     107,    -1,   114,    -1,   179,   108,   107,    -1,    82,    -1,
      20,    -1,    21,    -1,    22,    -1,    23,    -1,    24,    -1,
      25,    -1,    26,    -1,    27,    -1,    28,    -1,    29,    -1,
     110,    -1,   109,   110,    -1,   117,    -1,   165,    -1,   179,
      -1,    78,   175,    79,   111,    -1,    83,    84,    -1,    -1,
      83,   109,    84,   113,    -1,   151,    -1,   151,    85,   133,
      86,   114,    -1,     4,    -1,     5,    -1,    31,    -1,   114,
      -1,   118,    87,    -1,   118,   143,    87,    -1,   164,    -1,
     166,   118,    -1,   166,    -1,   178,   118,    -1,   178,    -1,
     176,   118,    -1,   176,    -1,   137,   118,    -1,   137,    -1,
     104,   118,    -1,   104,    -1,   156,   124,    -1,   124,    -1,
     117,    -1,   120,   117,    -1,   122,    88,    -1,   123,    -1,
     122,   123,    -1,    89,   116,    90,    -1,    91,     3,    -1,
       3,    -1,    78,   119,    79,    -1,   124,    89,    90,    -1,
     124,    89,    92,    90,    -1,   124,    89,    34,   177,   107,
      90,    -1,   124,    89,    34,   107,    90,    -1,   124,    89,
     177,    92,    90,    -1,   124,    89,   177,    34,   107,    90,
      -1,   124,    89,   177,   107,    90,    -1,   124,    89,   177,
      90,    -1,   124,    89,   107,    90,    -1,   124,    78,   153,
      79,    -1,   124,    78,    79,    -1,   124,    78,   141,    79,
      -1,    78,   102,    79,    -1,    89,    90,    -1,    89,    92,
      90,    -1,    89,    34,   177,   107,    90,    -1,    89,    34,
     107,    90,    -1,    89,   177,    34,   107,    90,    -1,    89,
     177,   107,    90,    -1,    89,   177,    90,    -1,    89,   107,
      90,    -1,   125,    89,    90,    -1,   125,    89,    92,    90,
      -1,   125,    89,    34,   177,   107,    90,    -1,   125,    89,
      34,   107,    90,    -1,   125,    89,   177,   107,    90,    -1,
     125,    89,   177,    34,   107,    90,    -1,   125,    89,   177,
      90,    -1,   125,    89,   107,    90,    -1,    78,    79,    -1,
      -1,    78,   153,    79,   126,    -1,   125,    78,    79,    -1,
     125,    78,   153,    79,    -1,    55,    83,   128,    84,    -1,
      55,    83,   128,    81,    84,    -1,    55,     3,    83,   128,
      84,    -1,    55,     3,    83,   128,    81,    84,    -1,    55,
       3,    -1,   129,    -1,   128,    81,   129,    -1,   130,    88,
     116,    -1,   130,    -1,     3,    -1,   160,    -1,   131,    16,
     160,    -1,   131,    17,   160,    -1,   105,    -1,   132,    93,
     105,    -1,   107,    -1,   133,    81,   107,    -1,    87,    -1,
     133,    87,    -1,   136,    -1,   117,    -1,   118,   119,   120,
     112,    -1,   118,   119,   112,    -1,    37,    -1,    73,    -1,
      72,    78,   107,    81,   139,    79,    -1,   140,    -1,   139,
      81,   140,    -1,   175,    86,   107,    -1,    58,    86,   107,
      -1,     3,    -1,   141,    81,     3,    -1,   132,    -1,   142,
      94,   132,    -1,   144,    -1,   143,    81,   144,    -1,   119,
      88,   145,    -1,   119,    -1,    83,   146,    84,    -1,    83,
     146,    81,    84,    -1,   107,    -1,   121,   145,    -1,   145,
      -1,   146,    81,   121,   145,    -1,   146,    81,   145,    -1,
      62,    78,   133,    79,   165,    -1,    63,   165,    62,    78,
     133,    79,    87,    -1,    64,    78,   134,   134,    79,   165,
      -1,    64,    78,   134,   134,   133,    79,   165,    -1,    64,
      78,   117,   134,    79,   165,    -1,    64,    78,   117,   134,
     133,    79,   165,    -1,    65,     3,    87,    -1,    66,    87,
      -1,    67,    87,    -1,    68,    87,    -1,    68,   133,    87,
      -1,     3,    86,   165,    -1,    57,   116,    86,   165,    -1,
      58,    86,   165,    -1,   142,    -1,   150,    18,   142,    -1,
     150,    -1,   151,    19,   150,    -1,   111,    -1,   152,    92,
     111,    -1,   152,    95,   111,    -1,   152,    96,   111,    -1,
     154,    81,    56,    -1,   154,    -1,   155,    -1,   154,    81,
     155,    -1,   118,   119,    -1,   118,   102,    -1,   118,    -1,
      92,   177,   156,    -1,    92,   177,    -1,    92,   156,    -1,
      92,    -1,   158,    -1,   157,    89,   133,    90,    -1,   157,
      78,    79,    -1,   157,    78,   106,    79,    -1,   157,    91,
       3,    -1,   157,     9,     3,    -1,   157,    10,    -1,   157,
      11,    -1,    78,   175,    79,    83,   146,    84,    -1,    78,
     175,    79,    83,   146,    81,    84,    -1,     3,    -1,   115,
      -1,   162,    -1,    78,   133,    79,    -1,   138,    -1,   174,
      -1,   163,    -1,   160,    97,   163,    -1,   160,    98,   163,
      -1,   160,    14,   163,    -1,   160,    15,   163,    -1,    59,
      78,   133,    79,   165,    60,   165,    -1,    59,    78,   133,
      79,   165,    -1,    61,    78,   133,    79,   165,    -1,     6,
      -1,     7,    -1,   103,    -1,   163,    12,   103,    -1,   163,
      13,   103,    -1,    74,    78,   116,    81,     6,    79,    87,
      -1,   149,    -1,   112,    -1,   134,    -1,   161,    -1,   147,
      -1,   148,    -1,    32,    -1,    33,    -1,    34,    -1,    75,
      -1,    35,    -1,    36,    -1,   168,    83,   169,    84,    -1,
     168,     3,    83,   169,    84,    -1,   168,     3,    -1,    53,
      -1,    54,    -1,   170,    -1,   169,   170,    -1,   171,    87,
      -1,   171,   172,    87,    -1,   164,    -1,   178,   171,    -1,
     178,    -1,   176,   171,    -1,   176,    -1,   173,    -1,   172,
      81,   173,    -1,    86,   116,    -1,   119,    86,   116,    -1,
     119,    -1,   135,    -1,   174,   135,    -1,   171,   102,    -1,
     171,    -1,    38,    -1,    39,    -1,    40,    -1,   176,    -1,
     177,   176,    -1,    50,    -1,    42,    -1,    43,    -1,    44,
      -1,    45,    -1,    48,    -1,    49,    -1,    46,    -1,    47,
      -1,    41,    -1,    51,    -1,    52,    -1,   167,    -1,   127,
      -1,    30,    -1,   157,    -1,    10,   179,    -1,    11,   179,
      -1,   180,   111,    -1,     8,   179,    -1,     8,    78,   175,
      79,    -1,    70,    78,   175,    79,    -1,    80,    -1,    92,
      -1,    76,    -1,    77,    -1,    99,    -1,   100,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   102,   102,   106,   110,   117,   121,   125,   133,   139,
     149,   153,   160,   164,   171,   175,   182,   189,   196,   203,
     210,   217,   224,   231,   238,   245,   252,   264,   270,   279,
     283,   289,   293,   300,   301,   301,   310,   314,   322,   330,
     337,   344,   353,   357,   379,   386,   390,   394,   398,   402,
     406,   410,   414,   418,   422,   428,   432,   439,   443,   449,
     456,   460,   467,   471,   480,   487,   491,   495,   499,   503,
     507,   511,   515,   519,   523,   527,   531,   535,   543,   547,
     548,   549,   553,   557,   561,   565,   569,   573,   577,   581,
     585,   589,   593,   597,   601,   605,   606,   606,   610,   614,
     622,   626,   630,   637,   644,   654,   658,   665,   669,   676,
     686,   690,   695,   702,   706,   714,   718,   726,   727,   734,
     738,   746,   750,   757,   763,   773,   780,   784,   791,   795,
     804,   811,   821,   825,   832,   836,   843,   850,   857,   861,
     865,   872,   876,   880,   884,   890,   894,   898,   902,   906,
     910,   917,   924,   928,   932,   936,   943,   950,   954,   961,
     965,   972,   976,   983,   987,   991,   995,  1003,  1007,  1014,
    1018,  1025,  1047,  1051,  1058,  1062,  1066,  1070,  1075,  1079,
    1083,  1088,  1093,  1101,  1109,  1114,  1119,  1124,  1131,  1138,
    1142,  1146,  1150,  1156,  1167,  1171,  1175,  1179,  1183,  1191,
    1195,  1200,  1208,  1212,  1219,  1223,  1227,  1234,  1241,  1245,
    1249,  1253,  1257,  1261,  1268,  1274,  1280,  1286,  1292,  1298,
    1308,  1312,  1319,  1329,  1335,  1344,  1348,  1355,  1359,  1363,
    1370,  1374,  1378,  1382,  1389,  1393,  1400,  1404,  1408,  1416,
    1420,  1427,  1431,  1438,  1444,  1450,  1459,  1463,  1471,  1477,
    1483,  1489,  1495,  1501,  1507,  1513,  1519,  1525,  1531,  1537,
    1543,  1547,  1553,  1562,  1567,  1572,  1577,  1582,  1587,  1592,
    1600,  1601,  1602,  1603,  1604,  1605
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "I_CONSTANT", "F_CONSTANT",
  "STRING_LITERAL", "FUNC_NAME", "SIZEOF", "PTR_OP", "INC_OP", "DEC_OP",
  "LEFT_OP", "RIGHT_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "AND_OP",
  "OR_OP", "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "ADD_ASSIGN",
  "SUB_ASSIGN", "LEFT_ASSIGN", "RIGHT_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN",
  "OR_ASSIGN", "TYPEDEF_NAME", "ENUMERATION_CONSTANT", "TYPEDEF", "EXTERN",
  "STATIC", "AUTO", "REGISTER", "INLINE", "CONST", "RESTRICT", "VOLATILE",
  "BOOL", "CHAR", "SHORT", "INT", "LONG", "SIGNED", "UNSIGNED", "FLOAT",
  "DOUBLE", "VOID", "COMPLEX", "IMAGINARY", "STRUCT", "UNION", "ENUM",
  "ELLIPSIS", "CASE", "DEFAULT", "IF", "ELSE", "SWITCH", "WHILE", "DO",
  "FOR", "GOTO", "CONTINUE", "BREAK", "RETURN", "ALIGNAS", "ALIGNOF",
  "ATOMIC", "GENERIC", "NORETURN", "STATIC_ASSERT", "THREAD_LOCAL", "'+'",
  "'-'", "'('", "')'", "'&'", "','", "\"=\"", "'{'", "'}'", "'?'", "':'",
  "';'", "'='", "'['", "']'", "'.'", "'*'", "'^'", "'|'", "'/'", "'%'",
  "'<'", "'>'", "'~'", "'!'", "$accept", "abstract_declarator",
  "additive_expression", "alignment_specifier", "and_expression",
  "argument_expression_list", "assignment_expression",
  "assignment_operator", "block_item_list", "block_item",
  "cast_expression", "compound_statement", "$@1", "conditional_expression",
  "constant", "constant_expression", "declaration",
  "declaration_specifiers", "declarator", "declaration_list",
  "designation", "designator_list", "designator", "direct_declarator",
  "direct_abstract_declarator", "$@2", "enum_specifier", "enumerator_list",
  "enumerator", "enumeration_constant", "equality_expression",
  "exclusive_or_expression", "expression", "expression_statement",
  "external_declaration", "function_definition", "function_specifier",
  "generic_selection", "generic_assoc_list", "generic_association",
  "identifier_list", "inclusive_or_expression", "init_declarator_list",
  "init_declarator", "initializer", "initializer_list",
  "iteration_statement", "jump_statement", "labeled_statement",
  "logical_and_expression", "logical_or_expression",
  "multiplicative_expression", "parameter_type_list", "parameter_list",
  "parameter_declaration", "pointer", "postfix_expression",
  "primary_expression", "program", "relational_expression",
  "selection_statement", "string", "shift_expression",
  "static_assert_declaration", "statement", "storage_class_specifier",
  "struct_or_union_specifier", "struct_or_union",
  "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "translation_unit", "type_name", "type_qualifier",
  "type_qualifier_list", "type_specifier", "unary_expression",
  "unary_operator", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,    43,    45,    40,    41,
      38,    44,   331,   123,   125,    63,    58,    59,    61,    91,
      93,    46,    42,    94,   124,    47,    37,    60,    62,   126,
      33
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   101,   102,   102,   102,   103,   103,   103,   104,   104,
     105,   105,   106,   106,   107,   107,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   109,   109,   110,
     110,   111,   111,   112,   113,   112,   114,   114,   115,   115,
     115,   116,   117,   117,   117,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   119,   119,   120,   120,   121,
     122,   122,   123,   123,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   126,   125,   125,   125,
     127,   127,   127,   127,   127,   128,   128,   129,   129,   130,
     131,   131,   131,   132,   132,   133,   133,   134,   134,   135,
     135,   136,   136,   137,   137,   138,   139,   139,   140,   140,
     141,   141,   142,   142,   143,   143,   144,   144,   145,   145,
     145,   146,   146,   146,   146,   147,   147,   147,   147,   147,
     147,   148,   148,   148,   148,   148,   149,   149,   149,   150,
     150,   151,   151,   152,   152,   152,   152,   153,   153,   154,
     154,   155,   155,   155,   156,   156,   156,   156,   157,   157,
     157,   157,   157,   157,   157,   157,   157,   157,   158,   158,
     158,   158,   158,   159,   160,   160,   160,   160,   160,   161,
     161,   161,   162,   162,   163,   163,   163,   164,   165,   165,
     165,   165,   165,   165,   166,   166,   166,   166,   166,   166,
     167,   167,   167,   168,   168,   169,   169,   170,   170,   170,
     171,   171,   171,   171,   172,   172,   173,   173,   173,   174,
     174,   175,   175,   176,   176,   176,   177,   177,   178,   178,
     178,   178,   178,   178,   178,   178,   178,   178,   178,   178,
     178,   178,   178,   179,   179,   179,   179,   179,   179,   179,
     180,   180,   180,   180,   180,   180
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     3,     3,     4,     4,
       1,     3,     1,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       1,     1,     4,     2,     0,     4,     1,     5,     1,     1,
       1,     1,     2,     3,     1,     2,     1,     2,     1,     2,
       1,     2,     1,     2,     1,     2,     1,     1,     2,     2,
       1,     2,     3,     2,     1,     3,     3,     4,     6,     5,
       5,     6,     5,     4,     4,     4,     3,     4,     3,     2,
       3,     5,     4,     5,     4,     3,     3,     3,     4,     6,
       5,     5,     6,     4,     4,     2,     0,     4,     3,     4,
       4,     5,     5,     6,     2,     1,     3,     3,     1,     1,
       1,     3,     3,     1,     3,     1,     3,     1,     2,     1,
       1,     4,     3,     1,     1,     6,     1,     3,     3,     3,
       1,     3,     1,     3,     1,     3,     3,     1,     3,     4,
       1,     2,     1,     4,     3,     5,     7,     6,     7,     6,
       7,     3,     2,     2,     2,     3,     3,     4,     3,     1,
       3,     1,     3,     1,     3,     3,     3,     3,     1,     1,
       3,     2,     2,     1,     3,     2,     2,     1,     1,     4,
       3,     4,     3,     3,     2,     2,     6,     7,     1,     1,
       1,     3,     1,     1,     1,     3,     3,     3,     3,     7,
       5,     5,     1,     1,     1,     3,     3,     7,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     5,     2,     1,     1,     1,     2,     2,     3,     1,
       2,     1,     2,     1,     1,     3,     2,     3,     1,     1,
       2,     2,     1,     1,     1,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     2,     2,     4,     4,
       1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,   262,   214,   215,   216,   218,   219,   123,   243,   244,
     245,   257,   249,   250,   251,   252,   255,   256,   253,   254,
     248,   258,   259,   223,   224,     0,     0,   124,     0,   217,
      54,   120,     0,   261,   239,   119,    52,     0,    44,    46,
     260,     0,   193,    50,    48,   104,     0,     0,     0,    53,
      64,     0,    42,   177,   137,    56,     0,   134,     0,    51,
       1,    45,   222,     0,   240,    49,    47,     0,   109,     0,
     105,   108,   188,    38,    39,   202,   203,     0,     0,     0,
      40,     0,     0,   272,   273,     0,   270,   271,   274,   275,
     204,   113,   163,    41,   189,     0,    10,   132,   192,   159,
     161,    36,     5,   263,   178,   110,   190,   194,   242,     0,
     233,   231,    31,     0,     0,     0,   176,   246,   175,     0,
       0,   122,    57,     0,     0,     0,     0,     0,    43,    55,
       0,   229,     0,   225,     0,     0,     0,   100,     0,     0,
     267,     0,   264,   265,     0,     0,   115,    14,     0,     0,
      31,     0,     0,     0,     9,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   184,   185,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   241,
       4,     3,     8,   232,   230,   266,     0,    65,   174,   247,
     188,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    33,   117,     0,    27,   209,    29,     0,   210,
     212,   213,   208,   211,    30,     0,   140,   136,   137,   121,
      58,   130,    76,   173,     0,     0,   168,   169,     0,    66,
     271,     0,     0,   135,     0,   220,   226,     0,   227,   238,
       0,   234,     0,   102,   101,   106,   107,     0,     0,     0,
       0,   191,     0,     0,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    16,     0,     6,     7,    11,   111,
     112,   114,   133,   160,   162,     0,   164,   165,   166,   183,
     180,     0,    12,     0,   182,   197,   198,   195,   196,   205,
     206,    95,     0,     0,     0,    79,   271,     0,     0,     0,
       0,     2,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   152,   153,   154,     0,    34,    28,   118,     0,
       0,     0,     0,    60,   142,     0,     0,   172,   171,     3,
      77,     0,    75,     0,     0,     0,    67,    74,     0,    73,
     271,     0,   221,   236,     0,     0,   228,   103,   268,     0,
     269,     0,   116,     0,    32,    15,     0,   181,     0,   179,
      78,    96,     0,     0,    80,    86,     0,    85,     0,    98,
       0,     0,    87,   271,     0,     0,     0,   156,     0,   158,
       0,     0,     0,     0,     0,     0,   151,   155,    35,     0,
      63,   141,    59,    61,     0,   138,   131,   167,   170,    69,
       0,     0,    70,    72,   237,   235,     0,     0,   126,     0,
       0,    37,    13,    97,    82,     0,     0,    84,    99,     0,
       0,    88,    94,     0,    93,     0,   207,   157,     0,     0,
       0,     0,     0,     0,    62,   139,     0,   144,    68,    71,
       0,   125,     0,     0,     0,   186,    81,    83,    90,     0,
       0,    91,   200,   201,   145,     0,     0,     0,     0,     0,
     143,   129,   127,   128,   187,    89,    92,     0,     0,   149,
       0,   147,     0,   199,   146,   150,   148
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   292,    90,    30,    91,   281,   146,   265,   204,   205,
      92,   206,   388,   147,    94,    95,    31,   123,   115,   124,
     321,   322,   323,    55,   180,   413,    33,    69,    70,    71,
      96,    97,   208,   209,    34,    35,    36,    98,   407,   408,
     224,    99,    56,    57,   324,   325,   210,   211,   212,   100,
     101,   102,   293,   226,   227,    58,   103,   104,    37,   105,
     213,   106,   107,    38,   214,    39,    40,    41,   132,   133,
     108,   240,   241,    42,   409,    43,   118,    44,   150,   113
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -376
static const yytype_int16 yypact[] =
{
    2108,  -376,  -376,  -376,  -376,  -376,  -376,  -376,  -376,  -376,
    -376,  -376,  -376,  -376,  -376,  -376,  -376,  -376,  -376,  -376,
    -376,  -376,  -376,  -376,  -376,    12,   -69,  -376,   -61,  -376,
    2198,  -376,    15,  -376,  -376,  -376,  2198,    29,  -376,  2198,
    -376,    36,  2108,  2198,  2198,   -50,    45,   710,  1644,  -376,
    -376,    31,  -376,   128,  1904,    83,    75,  -376,    72,  -376,
    -376,  -376,   -26,  2236,  -376,  -376,  -376,    45,  -376,   -32,
    -376,   -12,  -376,  -376,  -376,  -376,  -376,  1653,  1662,  1662,
    -376,    63,    79,  -376,  -376,   710,  -376,  -376,  -376,  -376,
      52,   109,  -376,  -376,  -376,   114,   218,   125,  -376,   113,
     196,    54,   -15,   253,  -376,    39,  -376,   248,   -42,   143,
     875,   875,  -376,  1644,   146,   151,  -376,  -376,   128,   431,
    1355,  -376,  -376,    15,  2008,  1795,   861,    31,  -376,    83,
    2236,  -376,  1241,  -376,    67,     7,    19,  -376,  1644,   710,
    -376,   710,  -376,  -376,   875,  1644,  -376,  -376,    95,   159,
     364,  1644,  1644,  1644,  -376,  1644,  1644,  1644,  1644,  1644,
    1644,  1644,  1644,  1644,  1644,   240,  -376,  -376,  1386,  1644,
     246,  1644,  1644,  1644,  1644,  1644,  1644,  1843,   872,  -376,
      91,    97,  -376,  -376,  -376,  -376,   264,  -376,  -376,  -376,
     187,  1644,   189,   198,   199,   209,   763,   211,   287,   204,
     206,  1397,  -376,  -376,   534,  -376,  -376,  -376,   103,  -376,
    -376,  -376,  -376,  -376,  -376,  1246,  -376,  -376,   208,  -376,
    -376,  -376,  -376,    71,   130,   215,   221,  -376,  1344,  -376,
     213,   220,   970,  -376,  1955,  -376,  -376,  1644,  -376,   219,
     107,  -376,    38,  -376,  -376,  -376,  -376,   233,   234,   235,
     238,  -376,  1644,  1495,  -376,  -376,  -376,  -376,  -376,  -376,
    -376,  -376,  -376,  -376,  -376,  1644,   -15,   -15,   218,    39,
      39,   109,   125,   113,   196,   -56,  -376,  -376,  -376,  -376,
    -376,   134,  -376,   -58,  -376,   248,   248,   248,   248,    52,
      52,  -376,   243,   251,  1344,  -376,   247,   249,   981,  2060,
    1079,    91,   257,   763,   239,   763,  1644,  1644,  1644,   237,
     632,   254,  -376,  -376,  -376,   111,  -376,  -376,  -376,  1644,
     337,  1355,   108,  -376,  -376,   119,  1734,  -376,  -376,    21,
    -376,   344,  -376,  2154,   262,  1344,  -376,  -376,  1644,  -376,
     263,   266,  -376,  -376,  1644,    87,  -376,  -376,   271,   271,
    -376,  1657,  -376,  1246,  -376,  -376,  1644,  -376,  1644,  -376,
    -376,  -376,   267,  1344,  -376,  -376,  1644,  -376,   278,  -376,
     282,  1344,  -376,   285,   286,  1090,   290,  -376,   763,  -376,
     140,   147,   152,   294,  1504,  1504,  -376,  -376,  -376,   304,
    -376,  -376,  -376,  -376,  1130,  -376,  -376,  -376,  -376,  -376,
     306,   307,  -376,  -376,  -376,  -376,   315,   165,  -376,   316,
     121,  -376,  -376,  -376,  -376,   314,   317,  -376,  -376,   318,
    1344,  -376,  -376,  1644,  -376,   319,  -376,  -376,   763,   763,
     763,  1644,  1535,  1546,  -376,  -376,  1355,  -376,  -376,  -376,
    1644,  -376,  1657,  1644,  1228,  -376,  -376,  -376,  -376,   320,
     321,  -376,   345,  -376,  -376,   171,   763,   177,   763,   178,
    -376,  -376,  -376,  -376,  -376,  -376,  -376,   763,   325,  -376,
     763,  -376,   763,  -376,  -376,  -376,  -376
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -376,   -96,    90,  -376,   256,  -376,   -20,  -376,  -376,   202,
    -102,    28,  -376,   -21,  -376,   -27,    -3,     1,   -19,  -376,
    -375,  -376,    92,   -48,  -174,  -376,  -376,   348,  -122,  -376,
     265,   259,   -83,  -238,   377,  -376,  -376,  -376,  -376,   -17,
    -376,   268,  -376,   295,  -115,    73,  -376,  -376,  -376,   261,
    -376,   120,  -117,  -376,    96,     6,  -376,  -376,  -376,   127,
    -376,  -376,    68,     3,  -161,  -376,  -376,  -376,   298,  -104,
       2,  -376,    85,  -376,    -1,   -47,  -123,   -43,   207,  -376
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     110,    32,   148,   232,   111,   217,   117,   301,   225,    47,
     129,   185,   179,    54,   245,    45,   110,    48,    50,   436,
     111,   114,    68,   252,    50,   252,    93,    93,   236,    60,
     356,    49,   359,    67,    50,   309,   177,    59,   110,    62,
      61,    68,   111,    32,    65,    66,   109,   178,    68,   136,
      53,   122,   137,   171,   172,   298,   148,   130,   148,   116,
     276,   277,   278,   110,   110,   134,   131,   111,   111,   436,
      50,   189,   385,   160,    50,    50,   138,   162,   275,   117,
     163,   164,   121,   110,   149,   110,   283,   111,   242,   111,
      50,   243,   110,    51,   110,    46,   111,   110,   111,   326,
     216,   111,    52,   244,   218,   335,   231,    53,   218,    51,
     178,   246,   183,   184,   181,   239,   207,    93,   315,    63,
     245,   220,   347,    53,   188,   250,   223,   327,   151,   152,
     236,   117,   134,   131,   134,   131,   173,   174,   247,   161,
     248,   144,   377,   249,   379,    51,   432,   433,   282,   326,
      51,   354,   219,   237,   238,   301,   127,   145,   297,    53,
     178,   125,   128,    53,   304,    51,     8,     9,    10,   299,
      93,   363,   126,   237,   251,   177,   252,   375,   223,    53,
     300,   117,   370,   181,   252,   189,   178,   110,   345,   153,
     318,   111,   252,   154,   346,   216,   392,   319,   387,   320,
     394,   207,   444,   395,   328,   445,   391,   158,   334,   330,
     343,   331,   341,   357,   159,   358,    93,   427,   157,   428,
      53,   252,   182,   380,   381,   382,   429,   186,   252,   329,
     187,   430,   352,   252,   155,   156,   134,   131,   253,   285,
     286,   287,   288,   279,   441,   355,   442,   117,   420,   284,
     468,   189,   252,   117,   112,   112,   470,   472,   252,   252,
     175,   176,   165,   166,   167,   289,   290,   452,   453,   454,
     302,   266,   267,   303,   362,   305,   306,   307,   368,   437,
     374,   129,   269,   270,   140,   142,   143,   308,   189,   310,
     311,   312,   389,   313,   332,   469,   120,   471,    93,   383,
     223,   216,   333,   336,   110,   344,   473,   384,   111,   475,
     337,   476,   348,   349,   350,   400,   189,   404,   401,   351,
     112,   460,   360,    93,   117,   378,   239,   223,   189,   437,
     361,   168,   329,   216,   223,   411,   376,   364,   412,   365,
     390,   386,   169,   415,   170,   112,   416,   396,   455,   457,
     459,   419,   399,   402,   353,   425,   403,   414,   112,   112,
     112,   418,   112,   112,   112,   112,   112,   112,   417,   112,
     112,   112,   431,   189,   216,   421,   422,   426,   112,   112,
     112,   112,   112,   112,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   434,   110,   438,   439,   112,   111,
     449,   440,   443,   450,   446,   467,   317,   447,   448,   451,
     465,   466,   474,   271,   393,   135,   216,   272,   268,    64,
     461,   274,   233,   463,   216,   462,   410,   273,   234,   398,
     405,     0,     0,     0,   190,    73,    74,    75,    76,    77,
       0,    78,    79,     0,   112,     0,   264,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     112,     1,    80,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,     0,   191,   192,
     193,     0,   194,   195,   196,   197,   198,   199,   200,   201,
      26,    81,     0,    82,    27,    28,    29,    83,    84,    85,
       0,    86,     0,     0,   119,   202,     0,     0,   203,     0,
       0,     0,     0,    87,     0,     0,   112,     0,     0,     0,
      88,    89,     0,     0,     0,     0,     0,   190,    73,    74,
      75,    76,    77,     0,    78,    79,     0,     0,     0,     0,
       0,   112,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   112,     1,    80,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
       0,   191,   192,   193,     0,   194,   195,   196,   197,   198,
     199,   200,   201,    26,    81,     0,    82,    27,    28,    29,
      83,    84,    85,     0,    86,     0,     0,   119,   316,     0,
       0,   203,     0,     0,     0,     0,    87,     0,     0,     0,
       0,     0,     0,    88,    89,    72,    73,    74,    75,    76,
      77,     0,    78,    79,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     1,    80,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    26,    81,     0,    82,    27,    28,    29,    83,    84,
      85,     0,    86,    72,    73,    74,    75,    76,    77,   203,
      78,    79,     0,     0,    87,     0,     0,     0,     0,     0,
       0,    88,    89,     0,     0,     0,     0,     0,     0,     0,
       1,    80,     0,     0,     0,     0,     0,     0,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,   190,    73,    74,    75,
      76,    77,     0,    78,    79,     0,     0,     0,     0,     0,
      81,     0,    82,     0,     0,     0,    83,    84,    85,     0,
      86,     0,     0,     0,    80,     0,     0,     0,     0,     0,
       0,     0,    87,     0,     0,     0,     0,     0,     0,    88,
      89,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     191,   192,   193,     0,   194,   195,   196,   197,   198,   199,
     200,   201,     0,    81,     0,    82,     0,     0,     0,    83,
      84,    85,     0,    86,     0,     0,   119,     0,     0,     0,
     203,     0,     0,     0,     0,    87,     0,     0,     0,     0,
       0,     0,    88,    89,    72,    73,    74,    75,    76,    77,
       0,    78,    79,     0,     0,    72,    73,    74,    75,    76,
      77,     0,    78,    79,     0,     0,     0,     0,     0,     0,
       0,     0,    80,     0,     0,   228,     0,     0,     0,     8,
       9,    10,     0,    80,     0,     1,   294,     0,     0,     0,
       8,     9,    10,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    81,     0,    82,     0,     0,     0,    83,    84,    85,
       0,    86,    81,     0,    82,     0,     0,     0,    83,    84,
      85,   229,    86,   230,     0,     0,     0,     0,     0,     0,
      88,    89,   295,     0,   296,     0,     0,     0,     0,     0,
       0,    88,    89,    72,    73,    74,    75,    76,    77,     0,
      78,    79,     0,     0,    72,    73,    74,    75,    76,    77,
       0,    78,    79,     0,     0,     0,     0,     0,     0,     0,
       0,    80,     0,     0,   338,     0,     0,     0,     8,     9,
      10,     0,    80,     0,     0,   366,     0,     0,     0,     8,
       9,    10,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      81,     0,    82,     0,     0,     0,    83,    84,    85,     0,
      86,    81,     0,    82,     0,     0,     0,    83,    84,    85,
     339,    86,   340,     0,     0,     0,     0,     0,     0,    88,
      89,   367,     0,    87,     0,     0,     0,     0,     0,     0,
      88,    89,    72,    73,    74,    75,    76,    77,     0,    78,
      79,     0,     0,    72,    73,    74,    75,    76,    77,     0,
      78,    79,     0,     0,     0,     0,     0,     0,     0,     0,
      80,     0,     0,   371,     0,     0,     0,     8,     9,    10,
       0,    80,     0,     0,   423,     0,     0,     0,     8,     9,
      10,     0,     0,    72,    73,    74,    75,    76,    77,     0,
      78,    79,     0,     0,     0,     0,     0,     0,     0,    81,
       0,    82,     0,     0,     0,    83,    84,    85,     0,    86,
      81,    80,    82,     0,     0,     0,    83,    84,    85,   372,
      86,   373,     0,     0,     0,     0,     0,     0,    88,    89,
     424,     0,    87,     0,     0,     0,     0,     0,     0,    88,
      89,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      81,     0,    82,     0,     0,     0,    83,    84,    85,     0,
      86,     0,     0,   215,   435,     0,     0,     0,     0,   319,
       0,   320,    87,     0,     0,     0,     0,     0,     0,    88,
      89,    72,    73,    74,    75,    76,    77,     0,    78,    79,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    72,
      73,    74,    75,    76,    77,     0,    78,    79,     0,    80,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,     0,     0,     0,     0,     0,    80,     0,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,     0,    81,     0,
      82,     0,     0,     0,    83,    84,    85,     0,    86,     0,
       0,   215,   464,     0,     0,    28,    81,   319,    82,   320,
      87,     0,    83,    84,    85,   235,    86,    88,    89,   215,
       0,     0,     0,     0,     0,   319,     0,   320,    87,     0,
       0,     0,     0,     0,     0,    88,    89,    72,    73,    74,
      75,    76,    77,     0,    78,    79,     0,     0,    72,    73,
      74,    75,    76,    77,     0,    78,    79,     0,     0,     0,
       0,     0,     0,     0,     0,    80,     0,     0,     0,     0,
       0,     0,     8,     9,    10,     0,    80,     0,     0,    72,
      73,    74,    75,    76,    77,     0,    78,    79,     0,     0,
      72,    73,    74,    75,    76,    77,     0,    78,    79,     0,
       0,     0,     0,     0,    81,     0,    82,    80,     0,     0,
      83,    84,    85,     0,    86,    81,     0,    82,    80,     0,
       0,    83,    84,    85,     0,    86,    87,     0,   215,     0,
       0,     0,     0,    88,    89,     0,     0,    87,     0,     0,
       0,     0,     0,     0,    88,    89,    81,     0,    82,     0,
       0,     0,    83,    84,    85,   280,    86,    81,     0,    82,
       0,     0,     0,    83,    84,    85,     0,    86,    87,     0,
       0,     0,     0,     0,   314,    88,    89,     0,     0,    87,
       0,     0,     0,     0,     0,     0,    88,    89,    72,    73,
      74,    75,    76,    77,     0,    78,    79,    72,    73,    74,
      75,    76,    77,     0,    78,    79,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    80,     0,     0,     0,
       0,     0,     0,     0,     0,    80,     0,     0,    72,    73,
      74,    75,    76,    77,     0,    78,    79,     0,     0,    72,
      73,    74,    75,    76,    77,     0,    78,    79,     0,     0,
       0,     0,     0,     0,     0,    81,    80,    82,     0,     0,
       0,    83,    84,    85,    81,    86,    82,    80,   353,     0,
      83,    84,    85,     0,    86,     0,     0,    87,     0,     0,
       0,   203,     0,     0,    88,    89,    87,     0,     0,     0,
       0,     0,     0,    88,    89,    81,     0,    82,     0,     0,
       0,    83,    84,    85,   456,    86,    81,     0,    82,     0,
       0,     0,    83,    84,    85,   458,    86,    87,     0,     0,
       0,     0,     0,     0,    88,    89,     0,     0,    87,     0,
       0,     0,     0,     0,     0,    88,    89,    72,    73,    74,
      75,    76,    77,     0,    78,    79,    72,    73,    74,    75,
      76,    77,     0,    78,    79,    72,    73,    74,    75,    76,
      77,     0,    78,    79,     0,    80,     0,     0,     0,     0,
       0,     0,     0,     0,    80,     0,     0,     1,     0,     0,
       0,     0,     0,    80,     0,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,     0,    81,   406,    82,     0,     0,     0,
      83,    84,    85,    81,    86,    82,     0,     0,     0,    83,
      84,   139,    81,    86,    82,     0,    87,    50,    83,    84,
     141,     0,    86,    88,    89,    87,     0,     0,     0,     0,
       0,     0,    88,    89,    87,     0,     0,     0,     0,     0,
       0,    88,    89,     0,     1,     0,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
       0,     0,     0,     0,     0,     0,     0,     0,   221,     0,
       0,     0,     0,    26,     0,     0,     0,    27,     0,    29,
       0,     0,   326,   291,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   178,     0,     1,    53,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    26,     0,     0,     0,    27,     0,
      29,     0,     0,     1,   222,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    26,     0,     0,     0,    27,     0,    29,     0,
       0,   177,   291,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   178,     0,     1,    53,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    26,     0,     0,     0,    27,    28,    29,
       0,     0,     0,     0,     0,     1,     0,   119,     0,     0,
       0,     0,   120,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    28,
       0,     0,     0,     0,     0,     0,     0,     0,     1,   342,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    26,     0,     0,
       0,    27,    28,    29,     0,     0,     0,     0,     0,     0,
       1,   119,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    26,
       0,     0,     0,    27,     0,    29,     0,     0,     1,   369,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    26,     0,     0,
       0,    27,    28,    29,     1,     0,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
     397,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    26,     0,     0,     0,    27,     1,    29,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     1,    26,     0,     0,
       0,    27,     0,    29,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      28
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-376)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      47,     0,    85,   126,    47,   120,    53,   181,   125,    78,
      58,   113,   108,    32,   136,     3,    63,    78,     3,   394,
      63,    48,     3,    81,     3,    81,    47,    48,   132,     0,
      86,    30,    90,    83,     3,   196,    78,    36,    85,     3,
      39,     3,    85,    42,    43,    44,    47,    89,     3,    81,
      92,    54,    84,    14,    15,   178,   139,    83,   141,    53,
     162,   163,   164,   110,   111,    63,    63,   110,   111,   444,
       3,   118,   310,    19,     3,     3,    88,    92,   161,   126,
      95,    96,    54,   130,    85,   132,   169,   130,    81,   132,
       3,    84,   139,    78,   141,    83,   139,   144,   141,    78,
     120,   144,    87,    84,   123,   228,   126,    92,   127,    78,
      89,   138,   110,   111,   108,   134,   119,   138,   201,    83,
     242,   124,    84,    92,   118,   145,   125,   223,    76,    77,
     234,   178,   130,   130,   132,   132,    97,    98,   139,    85,
     141,    78,   303,   144,   305,    78,   384,   385,   168,    78,
      78,   253,   124,    86,    87,   329,    81,    78,   178,    92,
      89,    78,    87,    92,   191,    78,    38,    39,    40,    78,
     191,   294,    89,    86,    79,    78,    81,   300,   177,    92,
      89,   228,   299,   177,    81,   232,    89,   234,    81,    80,
      87,   234,    81,    79,    87,   215,    88,    89,    87,    91,
      81,   204,    81,    84,   223,    84,   321,    94,   228,    79,
     237,    81,   232,    79,    18,    81,   237,   378,    93,    79,
      92,    81,    79,   306,   307,   308,    79,    81,    81,   223,
      79,    79,   252,    81,    16,    17,   234,   234,    79,   171,
     172,   173,   174,     3,    79,   265,    81,   294,   371,     3,
      79,   298,    81,   300,    47,    48,    79,    79,    81,    81,
      12,    13,     9,    10,    11,   175,   176,   428,   429,   430,
       6,   151,   152,    86,   294,    86,    78,    78,   298,   394,
     300,   329,   155,   156,    77,    78,    79,    78,   335,    78,
       3,    87,   319,    87,    79,   456,    88,   458,   319,    62,
     299,   321,    81,    90,   351,    86,   467,   310,   351,   470,
      90,   472,    79,    79,    79,   335,   363,   344,   338,    81,
     113,   436,    79,   344,   371,    86,   345,   326,   375,   444,
      79,    78,   326,   353,   333,   356,    79,    90,   358,    90,
       3,    87,    89,   363,    91,   138,   366,     3,   431,   432,
     433,   371,    90,    90,    83,   375,    90,    90,   151,   152,
     153,    79,   155,   156,   157,   158,   159,   160,    90,   162,
     163,   164,    78,   420,   394,    90,    90,    87,   171,   172,
     173,   174,   175,   176,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    90,   442,    90,    90,   191,   442,
     420,    86,    86,   423,    90,    60,   204,    90,    90,    90,
      90,    90,    87,   157,   322,    67,   436,   158,   153,    42,
     440,   160,   127,   443,   444,   442,   353,   159,   130,   333,
     345,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
      -1,    10,    11,    -1,   237,    -1,    82,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     253,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    57,    58,
      59,    -1,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    -1,    72,    73,    74,    75,    76,    77,    78,
      -1,    80,    -1,    -1,    83,    84,    -1,    -1,    87,    -1,
      -1,    -1,    -1,    92,    -1,    -1,   319,    -1,    -1,    -1,
      99,   100,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,
      -1,   344,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   356,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    57,    58,    59,    -1,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    -1,    72,    73,    74,    75,
      76,    77,    78,    -1,    80,    -1,    -1,    83,    84,    -1,
      -1,    87,    -1,    -1,    -1,    -1,    92,    -1,    -1,    -1,
      -1,    -1,    -1,    99,   100,     3,     4,     5,     6,     7,
       8,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    69,    70,    -1,    72,    73,    74,    75,    76,    77,
      78,    -1,    80,     3,     4,     5,     6,     7,     8,    87,
      10,    11,    -1,    -1,    92,    -1,    -1,    -1,    -1,    -1,
      -1,    99,   100,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,     3,     4,     5,     6,
       7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,
      70,    -1,    72,    -1,    -1,    -1,    76,    77,    78,    -1,
      80,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,    99,
     100,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      57,    58,    59,    -1,    61,    62,    63,    64,    65,    66,
      67,    68,    -1,    70,    -1,    72,    -1,    -1,    -1,    76,
      77,    78,    -1,    80,    -1,    -1,    83,    -1,    -1,    -1,
      87,    -1,    -1,    -1,    -1,    92,    -1,    -1,    -1,    -1,
      -1,    -1,    99,   100,     3,     4,     5,     6,     7,     8,
      -1,    10,    11,    -1,    -1,     3,     4,     5,     6,     7,
       8,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    -1,    -1,    34,    -1,    -1,    -1,    38,
      39,    40,    -1,    31,    -1,    30,    34,    -1,    -1,    -1,
      38,    39,    40,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    70,    -1,    72,    -1,    -1,    -1,    76,    77,    78,
      -1,    80,    70,    -1,    72,    -1,    -1,    -1,    76,    77,
      78,    90,    80,    92,    -1,    -1,    -1,    -1,    -1,    -1,
      99,   100,    90,    -1,    92,    -1,    -1,    -1,    -1,    -1,
      -1,    99,   100,     3,     4,     5,     6,     7,     8,    -1,
      10,    11,    -1,    -1,     3,     4,     5,     6,     7,     8,
      -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    -1,    -1,    34,    -1,    -1,    -1,    38,    39,
      40,    -1,    31,    -1,    -1,    34,    -1,    -1,    -1,    38,
      39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    -1,    72,    -1,    -1,    -1,    76,    77,    78,    -1,
      80,    70,    -1,    72,    -1,    -1,    -1,    76,    77,    78,
      90,    80,    92,    -1,    -1,    -1,    -1,    -1,    -1,    99,
     100,    90,    -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,
      99,   100,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    -1,    -1,     3,     4,     5,     6,     7,     8,    -1,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    -1,    -1,    34,    -1,    -1,    -1,    38,    39,    40,
      -1,    31,    -1,    -1,    34,    -1,    -1,    -1,    38,    39,
      40,    -1,    -1,     3,     4,     5,     6,     7,     8,    -1,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      -1,    72,    -1,    -1,    -1,    76,    77,    78,    -1,    80,
      70,    31,    72,    -1,    -1,    -1,    76,    77,    78,    90,
      80,    92,    -1,    -1,    -1,    -1,    -1,    -1,    99,   100,
      90,    -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,    99,
     100,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    -1,    72,    -1,    -1,    -1,    76,    77,    78,    -1,
      80,    -1,    -1,    83,    84,    -1,    -1,    -1,    -1,    89,
      -1,    91,    92,    -1,    -1,    -1,    -1,    -1,    -1,    99,
     100,     3,     4,     5,     6,     7,     8,    -1,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,     7,     8,    -1,    10,    11,    -1,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    -1,    -1,    -1,    -1,    -1,    31,    -1,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    70,    -1,
      72,    -1,    -1,    -1,    76,    77,    78,    -1,    80,    -1,
      -1,    83,    84,    -1,    -1,    74,    70,    89,    72,    91,
      92,    -1,    76,    77,    78,    84,    80,    99,   100,    83,
      -1,    -1,    -1,    -1,    -1,    89,    -1,    91,    92,    -1,
      -1,    -1,    -1,    -1,    -1,    99,   100,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    -1,    -1,     3,     4,
       5,     6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    39,    40,    -1,    31,    -1,    -1,     3,
       4,     5,     6,     7,     8,    -1,    10,    11,    -1,    -1,
       3,     4,     5,     6,     7,     8,    -1,    10,    11,    -1,
      -1,    -1,    -1,    -1,    70,    -1,    72,    31,    -1,    -1,
      76,    77,    78,    -1,    80,    70,    -1,    72,    31,    -1,
      -1,    76,    77,    78,    -1,    80,    92,    -1,    83,    -1,
      -1,    -1,    -1,    99,   100,    -1,    -1,    92,    -1,    -1,
      -1,    -1,    -1,    -1,    99,   100,    70,    -1,    72,    -1,
      -1,    -1,    76,    77,    78,    79,    80,    70,    -1,    72,
      -1,    -1,    -1,    76,    77,    78,    -1,    80,    92,    -1,
      -1,    -1,    -1,    -1,    87,    99,   100,    -1,    -1,    92,
      -1,    -1,    -1,    -1,    -1,    -1,    99,   100,     3,     4,
       5,     6,     7,     8,    -1,    10,    11,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,     3,     4,
       5,     6,     7,     8,    -1,    10,    11,    -1,    -1,     3,
       4,     5,     6,     7,     8,    -1,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    31,    72,    -1,    -1,
      -1,    76,    77,    78,    70,    80,    72,    31,    83,    -1,
      76,    77,    78,    -1,    80,    -1,    -1,    92,    -1,    -1,
      -1,    87,    -1,    -1,    99,   100,    92,    -1,    -1,    -1,
      -1,    -1,    -1,    99,   100,    70,    -1,    72,    -1,    -1,
      -1,    76,    77,    78,    79,    80,    70,    -1,    72,    -1,
      -1,    -1,    76,    77,    78,    79,    80,    92,    -1,    -1,
      -1,    -1,    -1,    -1,    99,   100,    -1,    -1,    92,    -1,
      -1,    -1,    -1,    -1,    -1,    99,   100,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,     3,     4,     5,     6,
       7,     8,    -1,    10,    11,     3,     4,     5,     6,     7,
       8,    -1,    10,    11,    -1,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    -1,    -1,    30,    -1,    -1,
      -1,    -1,    -1,    31,    -1,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    70,    58,    72,    -1,    -1,    -1,
      76,    77,    78,    70,    80,    72,    -1,    -1,    -1,    76,
      77,    78,    70,    80,    72,    -1,    92,     3,    76,    77,
      78,    -1,    80,    99,   100,    92,    -1,    -1,    -1,    -1,
      -1,    -1,    99,   100,    92,    -1,    -1,    -1,    -1,    -1,
      -1,    99,   100,    -1,    30,    -1,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,
      -1,    -1,    -1,    69,    -1,    -1,    -1,    73,    -1,    75,
      -1,    -1,    78,    79,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    89,    -1,    30,    92,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    69,    -1,    -1,    -1,    73,    -1,
      75,    -1,    -1,    30,    79,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    69,    -1,    -1,    -1,    73,    -1,    75,    -1,
      -1,    78,    79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    89,    -1,    30,    92,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    69,    -1,    -1,    -1,    73,    74,    75,
      -1,    -1,    -1,    -1,    -1,    30,    -1,    83,    -1,    -1,
      -1,    -1,    88,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    74,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    84,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,    -1,
      -1,    73,    74,    75,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    83,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      -1,    -1,    -1,    73,    -1,    75,    -1,    -1,    30,    79,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,    -1,
      -1,    73,    74,    75,    30,    -1,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    69,    -1,    -1,    -1,    73,    30,    75,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    69,    -1,    -1,
      -1,    73,    -1,    75,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      74
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    30,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    69,    73,    74,    75,
     104,   117,   118,   127,   135,   136,   137,   159,   164,   166,
     167,   168,   174,   176,   178,     3,    83,    78,    78,   118,
       3,    78,    87,    92,   119,   124,   143,   144,   156,   118,
       0,   118,     3,    83,   135,   118,   118,    83,     3,   128,
     129,   130,     3,     4,     5,     6,     7,     8,    10,    11,
      31,    70,    72,    76,    77,    78,    80,    92,    99,   100,
     103,   105,   111,   114,   115,   116,   131,   132,   138,   142,
     150,   151,   152,   157,   158,   160,   162,   163,   171,   175,
     176,   178,   179,   180,   116,   119,   156,   176,   177,    83,
      88,   112,   117,   118,   120,    78,    89,    81,    87,   124,
      83,   164,   169,   170,   171,   128,    81,    84,    88,    78,
     179,    78,   179,   179,    78,    78,   107,   114,   133,   175,
     179,    76,    77,    80,    79,    16,    17,    93,    94,    18,
      19,    85,    92,    95,    96,     9,    10,    11,    78,    89,
      91,    14,    15,    97,    98,    12,    13,    78,    89,   102,
     125,   156,    79,   171,   171,   111,    81,    79,   156,   176,
       3,    57,    58,    59,    61,    62,    63,    64,    65,    66,
      67,    68,    84,    87,   109,   110,   112,   117,   133,   134,
     147,   148,   149,   161,   165,    83,   107,   145,   119,   112,
     117,     3,    79,   118,   141,   153,   154,   155,    34,    90,
      92,   107,   177,   144,   169,    84,   170,    86,    87,   119,
     172,   173,    81,    84,    84,   129,   116,   175,   175,   175,
     107,    79,    81,    79,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    82,   108,   152,   152,   131,   160,
     160,   105,   132,   142,   150,   133,   111,   111,   111,     3,
      79,   106,   107,   133,     3,   163,   163,   163,   163,   103,
     103,    79,   102,   153,    34,    90,    92,   107,   177,    78,
      89,   125,     6,    86,   116,    86,    78,    78,    78,   165,
      78,     3,    87,    87,    87,   133,    84,   110,    87,    89,
      91,   121,   122,   123,   145,   146,    78,   102,   119,   156,
      79,    81,    79,    81,   107,   177,    90,    90,    34,    90,
      92,   107,    84,   116,    86,    81,    87,    84,    79,    79,
      79,    81,   107,    83,   111,   107,    86,    79,    81,    90,
      79,    79,   107,   177,    90,    90,    34,    90,   107,    79,
     153,    34,    90,    92,   107,   177,    79,   165,    86,   165,
     133,   133,   133,    62,   117,   134,    87,    87,   113,   116,
       3,   145,    88,   123,    81,    84,     3,    56,   155,    90,
     107,   107,    90,    90,   116,   173,    58,   139,   140,   175,
     146,   114,   107,   126,    90,   107,   107,    90,    79,   107,
     177,    90,    90,    34,    90,   107,    87,   165,    79,    79,
      79,    78,   134,   134,    90,    84,   121,   145,    90,    90,
      86,    79,    81,    86,    81,    84,    90,    90,    90,   107,
     107,    90,   165,   165,   165,   133,    79,   133,    79,   133,
     145,   107,   140,   107,    84,    90,    90,    60,    79,   165,
      79,   165,    79,   165,    87,   165,   165
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
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
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
  FILE *yyo = yyoutput;
  YYUSE (yyo);
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
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




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

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
        case 2:
/* Line 1792 of yacc.c  */
#line 103 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,ABSTRACT_DECLARATOR,(yyvsp[(1) - (2)].tVal),(yyvsp[(2) - (2)].tVal),NULL,NULL);
	}
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 107 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,ABSTRACT_DECLARATOR,(yyvsp[(1) - (1)].tVal),NULL,NULL,NULL);
	}
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 111 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,ABSTRACT_DECLARATOR,(yyvsp[(1) - (1)].tVal),NULL,NULL,NULL);
	}
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 118 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,ADDITIVE_EXPRESSION,(yyvsp[(1) - (1)].tVal),NULL,NULL,NULL);
	}
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 122 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,ADDITIVE_EXPRESSION,(yyvsp[(1) - (3)].tVal),(yyvsp[(3) - (3)].tVal),NULL,NULL);
	}
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 126 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,ADDITIVE_EXPRESSION,(yyvsp[(1) - (3)].tVal),(yyvsp[(3) - (3)].tVal),NULL,NULL);
	}
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 134 "c_compiler.y"
    {	struct value temp;
		temp.v.s = "=";
		temp.use = "alignas";
		(yyval.tVal) = create_node(temp,ALIGNMENT_SPECIFIER,(yyvsp[(3) - (4)].tVal),NULL,NULL,NULL);
	}
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 140 "c_compiler.y"
    {	struct value temp;
		temp.v.s = "alignas";
		temp.use = "string";
		(yyval.tVal) = create_node(temp,ALIGNMENT_SPECIFIER,(yyvsp[(3) - (4)].tVal),NULL,NULL,NULL);
	}
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 150 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,AND_EXPRESSION,(yyvsp[(1) - (1)].tVal),NULL,NULL,NULL);
	}
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 154 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,AND_EXPRESSION,(yyvsp[(1) - (3)].tVal),(yyvsp[(3) - (3)].tVal),NULL,NULL);
	}
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 161 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,ARGUMENT_EXPRESSION_LIST,(yyvsp[(1) - (1)].tVal),NULL,NULL,NULL);
	}
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 165 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,ARGUMENT_EXPRESSION_LIST,(yyvsp[(1) - (3)].tVal),(yyvsp[(3) - (3)].tVal),NULL,NULL);
	}
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 172 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,ASSIGNMENT_EXPRESSION,(yyvsp[(1) - (1)].tVal),NULL,NULL,NULL);
	}
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 176 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,ASSIGNMENT_EXPRESSION,(yyvsp[(1) - (3)].tVal),(yyvsp[(2) - (3)].tVal),(yyvsp[(3) - (3)].tVal),NULL);
	}
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 183 "c_compiler.y"
    {
		struct value temp;
		temp.v.s = "=";
		temp.use = "string";
		(yyval.tVal) = create_node(temp,ASSIGNMENT_OPERATOR,NULL,NULL,NULL,NULL);;
	}
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 190 "c_compiler.y"
    {
		struct value temp;
		temp.v.s = "*=";
		temp.use = "string";
		(yyval.tVal) = create_node(temp,ASSIGNMENT_OPERATOR,NULL,NULL,NULL,NULL);;
	}
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 197 "c_compiler.y"
    {
		struct value temp;
		temp.v.s = "/=";
		temp.use = "string";
		(yyval.tVal) = create_node(temp,ASSIGNMENT_OPERATOR,NULL,NULL,NULL,NULL);;
	}
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 204 "c_compiler.y"
    {
		struct value temp;
		temp.v.s = "%=";
		temp.use = "string";
		(yyval.tVal) = create_node(temp,ASSIGNMENT_OPERATOR,NULL,NULL,NULL,NULL);;
	}
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 211 "c_compiler.y"
    {
		struct value temp;
		temp.v.s = "+=";
		temp.use = "string";
		(yyval.tVal) = create_node(temp,ASSIGNMENT_OPERATOR,NULL,NULL,NULL,NULL);;
	}
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 218 "c_compiler.y"
    {
		struct value temp;
		temp.v.s = "-=";
		temp.use = "string";
		(yyval.tVal) = create_node(temp,ASSIGNMENT_OPERATOR,NULL,NULL,NULL,NULL);;
	}
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 225 "c_compiler.y"
    {
		struct value temp;
		temp.v.s = "<<=";
		temp.use = "string";
		(yyval.tVal) = create_node(temp,ASSIGNMENT_OPERATOR,NULL,NULL,NULL,NULL);;
	}
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 232 "c_compiler.y"
    {
		struct value temp;
		temp.v.s = ">>=";
		temp.use = "string";
		(yyval.tVal) = create_node(temp,ASSIGNMENT_OPERATOR,NULL,NULL,NULL,NULL);;
	}
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 239 "c_compiler.y"
    {
		struct value temp;
		temp.v.s = "&=";
		temp.use = "string";
		(yyval.tVal) = create_node(temp,ASSIGNMENT_OPERATOR,NULL,NULL,NULL,NULL);;
	}
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 246 "c_compiler.y"
    {
		struct value temp;
		temp.v.s = "^=";
		temp.use = "string";
		(yyval.tVal) = create_node(temp,ASSIGNMENT_OPERATOR,NULL,NULL,NULL,NULL);;
	}
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 253 "c_compiler.y"
    {
		struct value temp;
		temp.v.s = "|=";
		temp.use = "string";
		(yyval.tVal) = create_node(temp,ASSIGNMENT_OPERATOR,NULL,NULL,NULL,NULL);;
	}
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 265 "c_compiler.y"
    {
		struct value temp;
		temp.use="none";
		(yyval.tVal) = create_node(temp,BLOCK_ITEM_LIST,(yyvsp[(1) - (1)].tVal),NULL,NULL,NULL);
	}
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 271 "c_compiler.y"
    {
		struct value temp;
		temp.use="none";
		(yyval.tVal) = create_node(temp,BLOCK_ITEM_LIST,(yyvsp[(1) - (2)].tVal),(yyvsp[(2) - (2)].tVal),NULL,NULL);
	}
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 280 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,BLOCK_ITEM,(yyvsp[(1) - (1)].tVal),NULL,NULL,NULL);
	}
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 284 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,BLOCK_ITEM,(yyvsp[(1) - (1)].tVal),NULL,NULL,NULL);
	}
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 290 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,CAST_EXPRESSION,(yyvsp[(1) - (1)].tVal),NULL,NULL,NULL);
	}
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 294 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,CAST_EXPRESSION,(yyvsp[(2) - (4)].tVal),(yyvsp[(4) - (4)].tVal),NULL,NULL);
	}
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 300 "c_compiler.y"
    {}
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 301 "c_compiler.y"
    {}
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 302 "c_compiler.y"
    {
		struct value temp;
		temp.use="none";
		(yyval.tVal) = create_node(temp,COMPOUND_STATEMENT,(yyvsp[(2) - (4)].tVal),NULL,NULL,NULL);
	}
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 311 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,CONDITIONAL_EXPRESSION,(yyvsp[(1) - (1)].tVal),NULL,NULL,NULL);
	}
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 315 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,CONDITIONAL_EXPRESSION,(yyvsp[(1) - (5)].tVal),(yyvsp[(3) - (5)].tVal),(yyvsp[(5) - (5)].tVal),NULL);
	}
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 323 "c_compiler.y"
    {
		struct value temp;
		temp.v.i = yylval.iVal;
		temp.use = "integer";
		//printf("%s\n",temp.use);
		(yyval.tVal) = create_node(temp,CONSTANT,NULL,NULL,NULL,NULL);
	}
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 331 "c_compiler.y"
    {
		struct value temp;
		temp.v.f = yylval.fVal;
		temp.use = "float";
		(yyval.tVal) = create_node(temp,CONSTANT,NULL,NULL,NULL,NULL);
	}
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 338 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,CONSTANT,NULL,NULL,NULL,NULL);
	}
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 345 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,CONSTANT_EXPRESSION,(yyvsp[(1) - (1)].tVal),NULL,NULL,NULL);
	}
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 354 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,DECLARATION,(yyvsp[(1) - (2)].tVal),NULL,NULL,NULL);
	}
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 358 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,DECLARATION,(yyvsp[(1) - (3)].tVal),(yyvsp[(2) - (3)].tVal),NULL,NULL);
		int i,j,ti=0,ii=0;
		for(i=0;i<100;i++) {
			id[i] = (char *)malloc(IDLENGTH*sizeof(char));
			strcpy(id[i],"NIL");
			type[i] = (char *)malloc(10*sizeof(char));
			strcpy(type[i],"NIL");
		}
		ti=find_usage((yyvsp[(1) - (3)].tVal),type,ti,"string");
		ii=find_usage((yyvsp[(2) - (3)].tVal),id,ii,"identifier");
		for(i=0;i<ii;i++) {
			for(j=1;j<ti;j++) {
				if(strcmp(type[j],"NIL")!=0) {
					strcat(type[0]," ");
					strcat(type[0],type[j]);
				}
			}
			hash_insert(id[i],type[0]);
		}
	}
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 380 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,DECLARATION,(yyvsp[(1) - (1)].tVal),NULL,NULL,NULL);
	}
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 387 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,DECLARATION_SPECIFIERS,(yyvsp[(1) - (2)].tVal),(yyvsp[(2) - (2)].tVal),NULL,NULL);
	}
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 391 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,DECLARATION_SPECIFIERS,(yyvsp[(1) - (1)].tVal),NULL,NULL,NULL);
	}
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 395 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,DECLARATION_SPECIFIERS,(yyvsp[(1) - (2)].tVal),(yyvsp[(2) - (2)].tVal),NULL,NULL);
	}
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 399 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,DECLARATION_SPECIFIERS,(yyvsp[(1) - (1)].tVal),NULL,NULL,NULL);
	}
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 403 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,DECLARATION_SPECIFIERS,(yyvsp[(1) - (2)].tVal),(yyvsp[(2) - (2)].tVal),NULL,NULL);
	}
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 407 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,DECLARATION_SPECIFIERS,(yyvsp[(1) - (1)].tVal),NULL,NULL,NULL);
	}
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 411 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,DECLARATION_SPECIFIERS,(yyvsp[(1) - (2)].tVal),(yyvsp[(2) - (2)].tVal),NULL,NULL);
	}
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 415 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,DECLARATION_SPECIFIERS,(yyvsp[(1) - (1)].tVal),NULL,NULL,NULL);
	}
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 419 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,DECLARATION_SPECIFIERS,(yyvsp[(1) - (2)].tVal),(yyvsp[(2) - (2)].tVal),NULL,NULL);
	}
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 423 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,DECLARATION_SPECIFIERS,(yyvsp[(1) - (1)].tVal),NULL,NULL,NULL);
	}
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 429 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,DECLARATOR,(yyvsp[(1) - (2)].tVal),(yyvsp[(2) - (2)].tVal),NULL,NULL);
	}
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 433 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,DECLARATOR,(yyvsp[(1) - (1)].tVal),NULL,NULL,NULL);
	}
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 440 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,DECLARATION_LIST,(yyvsp[(1) - (1)].tVal),NULL,NULL,NULL);
	}
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 444 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,DECLARATION_LIST,(yyvsp[(1) - (2)].tVal),(yyvsp[(2) - (2)].tVal),NULL,NULL);
	}
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 450 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,DESIGNATION,(yyvsp[(1) - (2)].tVal),NULL,NULL,NULL);
	}
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 457 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,DESIGNATOR_LIST,(yyvsp[(1) - (1)].tVal),NULL,NULL,NULL);
	}
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 461 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,DESIGNATOR_LIST,(yyvsp[(1) - (2)].tVal),(yyvsp[(2) - (2)].tVal),NULL,NULL);
	}
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 468 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,DESIGNATOR,(yyvsp[(2) - (3)].tVal),NULL,NULL,NULL);
	}
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 472 "c_compiler.y"
    {
		struct value temp;
		temp.v.s = yylval.sVal;
		temp.use = "identifier";
		(yyval.tVal) = create_node(temp,CONSTANT,NULL,NULL,NULL,NULL);
	}
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 481 "c_compiler.y"
    {
		struct value temp;
		temp.v.s = yylval.sVal;
		temp.use = "identifier";
		(yyval.tVal) = create_node(temp,DIRECT_DECLARATOR,NULL,NULL,NULL,NULL);
	}
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 488 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,DIRECT_DECLARATOR,(yyvsp[(2) - (3)].tVal),NULL,NULL,NULL);
	}
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 492 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,DIRECT_DECLARATOR,(yyvsp[(1) - (3)].tVal),NULL,NULL,NULL);
	}
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 496 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,DIRECT_DECLARATOR,(yyvsp[(1) - (4)].tVal),NULL,NULL,NULL);
	}
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 500 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,DIRECT_DECLARATOR,(yyvsp[(1) - (6)].tVal),(yyvsp[(4) - (6)].tVal),(yyvsp[(5) - (6)].tVal),NULL);
	}
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 504 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,DIRECT_DECLARATOR,(yyvsp[(1) - (5)].tVal),(yyvsp[(4) - (5)].tVal),NULL,NULL);
	}
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 508 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,DIRECT_DECLARATOR,(yyvsp[(1) - (5)].tVal),(yyvsp[(3) - (5)].tVal),NULL,NULL);
	}
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 512 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,DIRECT_DECLARATOR,(yyvsp[(1) - (6)].tVal),(yyvsp[(3) - (6)].tVal),(yyvsp[(5) - (6)].tVal),NULL);
	}
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 516 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,DIRECT_DECLARATOR,(yyvsp[(1) - (5)].tVal),(yyvsp[(3) - (5)].tVal),(yyvsp[(4) - (5)].tVal),NULL);
	}
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 520 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,DIRECT_DECLARATOR,(yyvsp[(1) - (4)].tVal),(yyvsp[(3) - (4)].tVal),NULL,NULL);
	}
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 524 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,DIRECT_DECLARATOR,(yyvsp[(1) - (4)].tVal),(yyvsp[(3) - (4)].tVal),NULL,NULL);
	}
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 528 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,DIRECT_DECLARATOR,(yyvsp[(1) - (4)].tVal),(yyvsp[(3) - (4)].tVal),NULL,NULL);
	}
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 532 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,DIRECT_DECLARATOR,(yyvsp[(1) - (3)].tVal),NULL,NULL,NULL);
	}
    break;

  case 77:
/* Line 1792 of yacc.c  */
#line 536 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,DIRECT_DECLARATOR,(yyvsp[(1) - (4)].tVal),(yyvsp[(3) - (4)].tVal),NULL,NULL);
	}
    break;

  case 78:
/* Line 1792 of yacc.c  */
#line 544 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,DIRECT_ABSTRACT_DECLARATOR,(yyvsp[(2) - (3)].tVal),NULL,NULL,NULL);
	}
    break;

  case 79:
/* Line 1792 of yacc.c  */
#line 547 "c_compiler.y"
    {}
    break;

  case 80:
/* Line 1792 of yacc.c  */
#line 548 "c_compiler.y"
    {}
    break;

  case 81:
/* Line 1792 of yacc.c  */
#line 550 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,DIRECT_ABSTRACT_DECLARATOR,(yyvsp[(3) - (5)].tVal),(yyvsp[(4) - (5)].tVal),NULL,NULL);
	}
    break;

  case 82:
/* Line 1792 of yacc.c  */
#line 554 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,DIRECT_ABSTRACT_DECLARATOR,(yyvsp[(3) - (4)].tVal),NULL,NULL,NULL);
	}
    break;

  case 83:
/* Line 1792 of yacc.c  */
#line 558 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,DIRECT_ABSTRACT_DECLARATOR,(yyvsp[(2) - (5)].tVal),(yyvsp[(4) - (5)].tVal),NULL,NULL);
	}
    break;

  case 84:
/* Line 1792 of yacc.c  */
#line 562 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,DIRECT_ABSTRACT_DECLARATOR,(yyvsp[(2) - (4)].tVal),(yyvsp[(3) - (4)].tVal),NULL,NULL);
	}
    break;

  case 85:
/* Line 1792 of yacc.c  */
#line 566 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,DIRECT_ABSTRACT_DECLARATOR,(yyvsp[(2) - (3)].tVal),NULL,NULL,NULL);
	}
    break;

  case 86:
/* Line 1792 of yacc.c  */
#line 570 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,DIRECT_ABSTRACT_DECLARATOR,(yyvsp[(2) - (3)].tVal),NULL,NULL,NULL);
	}
    break;

  case 87:
/* Line 1792 of yacc.c  */
#line 574 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,DIRECT_ABSTRACT_DECLARATOR,(yyvsp[(1) - (3)].tVal),NULL,NULL,NULL);
	}
    break;

  case 88:
/* Line 1792 of yacc.c  */
#line 578 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,DIRECT_ABSTRACT_DECLARATOR,(yyvsp[(1) - (4)].tVal),NULL,NULL,NULL);
	}
    break;

  case 89:
/* Line 1792 of yacc.c  */
#line 582 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,DIRECT_ABSTRACT_DECLARATOR,(yyvsp[(1) - (6)].tVal),(yyvsp[(4) - (6)].tVal),(yyvsp[(5) - (6)].tVal),NULL);
	}
    break;

  case 90:
/* Line 1792 of yacc.c  */
#line 586 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,DIRECT_ABSTRACT_DECLARATOR,(yyvsp[(1) - (5)].tVal),(yyvsp[(4) - (5)].tVal),NULL,NULL);
	}
    break;

  case 91:
/* Line 1792 of yacc.c  */
#line 590 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,DIRECT_ABSTRACT_DECLARATOR,(yyvsp[(1) - (5)].tVal),(yyvsp[(3) - (5)].tVal),NULL,NULL);
	}
    break;

  case 92:
/* Line 1792 of yacc.c  */
#line 594 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,DIRECT_ABSTRACT_DECLARATOR,(yyvsp[(1) - (6)].tVal),(yyvsp[(3) - (6)].tVal),(yyvsp[(5) - (6)].tVal),NULL);
	}
    break;

  case 93:
/* Line 1792 of yacc.c  */
#line 598 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,DIRECT_ABSTRACT_DECLARATOR,(yyvsp[(1) - (4)].tVal),(yyvsp[(3) - (4)].tVal),NULL,NULL);
	}
    break;

  case 94:
/* Line 1792 of yacc.c  */
#line 602 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,DIRECT_ABSTRACT_DECLARATOR,(yyvsp[(1) - (4)].tVal),(yyvsp[(3) - (4)].tVal),NULL,NULL);
	}
    break;

  case 95:
/* Line 1792 of yacc.c  */
#line 605 "c_compiler.y"
    {}
    break;

  case 96:
/* Line 1792 of yacc.c  */
#line 606 "c_compiler.y"
    {}
    break;

  case 97:
/* Line 1792 of yacc.c  */
#line 607 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,DIRECT_ABSTRACT_DECLARATOR,(yyvsp[(2) - (4)].tVal),NULL,NULL,NULL);
	}
    break;

  case 98:
/* Line 1792 of yacc.c  */
#line 611 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,DIRECT_ABSTRACT_DECLARATOR,(yyvsp[(1) - (3)].tVal),NULL,NULL,NULL);
	}
    break;

  case 99:
/* Line 1792 of yacc.c  */
#line 615 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,DIRECT_ABSTRACT_DECLARATOR,(yyvsp[(1) - (4)].tVal),(yyvsp[(3) - (4)].tVal),NULL,NULL);
	}
    break;

  case 100:
/* Line 1792 of yacc.c  */
#line 623 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,ENUM_SPECIFIER,(yyvsp[(3) - (4)].tVal),NULL,NULL,NULL);
	}
    break;

  case 101:
/* Line 1792 of yacc.c  */
#line 627 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,ENUM_SPECIFIER,(yyvsp[(3) - (5)].tVal),NULL,NULL,NULL);
	}
    break;

  case 102:
/* Line 1792 of yacc.c  */
#line 631 "c_compiler.y"
    {
		struct value temp;
		temp.v.s = yylval.sVal;
		temp.use = "identifier";
		(yyval.tVal) = create_node(temp,ENUM_SPECIFIER,NULL,NULL,NULL,NULL);
	}
    break;

  case 103:
/* Line 1792 of yacc.c  */
#line 638 "c_compiler.y"
    {
		struct value temp;
		temp.v.s = yylval.sVal;
		temp.use = "identifier";
		(yyval.tVal) = create_node(temp,ENUM_SPECIFIER,NULL,NULL,NULL,NULL);
	}
    break;

  case 104:
/* Line 1792 of yacc.c  */
#line 645 "c_compiler.y"
    {
		struct value temp;
		temp.v.s = yylval.sVal;
		temp.use = "identifier";
		(yyval.tVal) = create_node(temp,ENUM_SPECIFIER,NULL,NULL,NULL,NULL);
	}
    break;

  case 105:
/* Line 1792 of yacc.c  */
#line 655 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,ENUMERATOR_LIST,(yyvsp[(1) - (1)].tVal),NULL,NULL,NULL);
	}
    break;

  case 106:
/* Line 1792 of yacc.c  */
#line 659 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,ENUMERATOR_LIST,(yyvsp[(1) - (3)].tVal),(yyvsp[(3) - (3)].tVal),NULL,NULL);
	}
    break;

  case 107:
/* Line 1792 of yacc.c  */
#line 666 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,ENUMERATOR,(yyvsp[(1) - (3)].tVal),(yyvsp[(3) - (3)].tVal),NULL,NULL);
	}
    break;

  case 108:
/* Line 1792 of yacc.c  */
#line 670 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,ENUMERATOR,(yyvsp[(1) - (1)].tVal),NULL,NULL,NULL);
	}
    break;

  case 109:
/* Line 1792 of yacc.c  */
#line 677 "c_compiler.y"
    {
		struct value temp;
		temp.v.s = yylval.sVal;
		temp.use = "identifier";
		(yyval.tVal) = create_node(temp,ENUMERATION_CONSTANT,NULL,NULL,NULL,NULL);
	}
    break;

  case 110:
/* Line 1792 of yacc.c  */
#line 687 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,EQUALITY_EXPRESSION,(yyvsp[(1) - (1)].tVal),NULL,NULL,NULL);
	}
    break;

  case 111:
/* Line 1792 of yacc.c  */
#line 691 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,EQUALITY_EXPRESSION,(yyvsp[(1) - (3)].tVal),(yyvsp[(3) - (3)].tVal),NULL,NULL);
	}
    break;

  case 112:
/* Line 1792 of yacc.c  */
#line 696 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,EQUALITY_EXPRESSION,(yyvsp[(1) - (3)].tVal),(yyvsp[(3) - (3)].tVal),NULL,NULL);
	}
    break;

  case 113:
/* Line 1792 of yacc.c  */
#line 703 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,EXCLUSIVE_OR_EXPRESSION,(yyvsp[(1) - (1)].tVal),NULL,NULL,NULL);
	}
    break;

  case 114:
/* Line 1792 of yacc.c  */
#line 707 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,EXCLUSIVE_OR_EXPRESSION,(yyvsp[(1) - (3)].tVal),(yyvsp[(3) - (3)].tVal),NULL,NULL);
	}
    break;

  case 115:
/* Line 1792 of yacc.c  */
#line 715 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,EXPRESSION,(yyvsp[(1) - (1)].tVal),NULL,NULL,NULL);
	}
    break;

  case 116:
/* Line 1792 of yacc.c  */
#line 719 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,EXPRESSION,(yyvsp[(1) - (3)].tVal),(yyvsp[(3) - (3)].tVal),NULL,NULL);
	}
    break;

  case 117:
/* Line 1792 of yacc.c  */
#line 726 "c_compiler.y"
    {}
    break;

  case 118:
/* Line 1792 of yacc.c  */
#line 728 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,EXPRESSION_STATEMENT,(yyvsp[(1) - (2)].tVal),NULL,NULL,NULL);
	}
    break;

  case 119:
/* Line 1792 of yacc.c  */
#line 735 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,EXTERNAL_DECLARATION,(yyvsp[(1) - (1)].tVal),NULL,NULL,NULL);
	}
    break;

  case 120:
/* Line 1792 of yacc.c  */
#line 739 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,EXTERNAL_DECLARATION,(yyvsp[(1) - (1)].tVal),NULL,NULL,NULL);
	}
    break;

  case 121:
/* Line 1792 of yacc.c  */
#line 747 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,FUNCTION_DEFINITION,(yyvsp[(1) - (4)].tVal),(yyvsp[(2) - (4)].tVal),(yyvsp[(3) - (4)].tVal),(yyvsp[(4) - (4)].tVal));
	}
    break;

  case 122:
/* Line 1792 of yacc.c  */
#line 751 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,FUNCTION_DEFINITION,(yyvsp[(1) - (3)].tVal),(yyvsp[(2) - (3)].tVal),(yyvsp[(3) - (3)].tVal),NULL);
	}
    break;

  case 123:
/* Line 1792 of yacc.c  */
#line 758 "c_compiler.y"
    {	struct value temp;
		temp.v.s = "inline";
		temp.use = "string";
		(yyval.tVal) = create_node(temp,FUNCTION_SPECIFIER,NULL,NULL,NULL,NULL);
	}
    break;

  case 124:
/* Line 1792 of yacc.c  */
#line 764 "c_compiler.y"
    {	struct value temp;
		temp.v.s = "noreturn";
		temp.use = "string";
		(yyval.tVal) = create_node(temp,FUNCTION_SPECIFIER,NULL,NULL,NULL,NULL);
	}
    break;

  case 125:
/* Line 1792 of yacc.c  */
#line 774 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,GENERIC_SELECTION,(yyvsp[(3) - (6)].tVal),(yyvsp[(5) - (6)].tVal),NULL,NULL);
	}
    break;

  case 126:
/* Line 1792 of yacc.c  */
#line 781 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,GENERIC_ASSOC_LIST,(yyvsp[(1) - (1)].tVal),NULL,NULL,NULL);
	}
    break;

  case 127:
/* Line 1792 of yacc.c  */
#line 785 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,GENERIC_ASSOC_LIST,(yyvsp[(1) - (3)].tVal),(yyvsp[(3) - (3)].tVal),NULL,NULL);
	}
    break;

  case 128:
/* Line 1792 of yacc.c  */
#line 792 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,GENERIC_ASSOCIATION,(yyvsp[(1) - (3)].tVal),(yyvsp[(3) - (3)].tVal),NULL,NULL);
	}
    break;

  case 129:
/* Line 1792 of yacc.c  */
#line 796 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,GENERIC_ASSOCIATION,(yyvsp[(3) - (3)].tVal),NULL,NULL,NULL);
	}
    break;

  case 130:
/* Line 1792 of yacc.c  */
#line 805 "c_compiler.y"
    {
		struct value temp;
		temp.v.s = yylval.sVal;
		temp.use = "identifier";
		(yyval.tVal) = create_node(temp,IDENTIFIER_LIST,NULL,NULL,NULL,NULL);
	}
    break;

  case 131:
/* Line 1792 of yacc.c  */
#line 812 "c_compiler.y"
    {
		struct value temp;
		temp.v.s = yylval.sVal;
		temp.use = "identifier";
		(yyval.tVal) = create_node(temp,IDENTIFIER_LIST,(yyvsp[(1) - (3)].tVal),NULL,NULL,NULL);
	}
    break;

  case 132:
/* Line 1792 of yacc.c  */
#line 822 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,INCLUSIVE_OR_EXPRESSION,(yyvsp[(1) - (1)].tVal),NULL,NULL,NULL);
	}
    break;

  case 133:
/* Line 1792 of yacc.c  */
#line 826 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,INCLUSIVE_OR_EXPRESSION,(yyvsp[(1) - (3)].tVal),(yyvsp[(3) - (3)].tVal),NULL,NULL);
	}
    break;

  case 134:
/* Line 1792 of yacc.c  */
#line 833 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,INIT_DECLARATOR_LIST,(yyvsp[(1) - (1)].tVal),NULL,NULL,NULL);
	}
    break;

  case 135:
/* Line 1792 of yacc.c  */
#line 837 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,INIT_DECLARATOR_LIST,(yyvsp[(1) - (3)].tVal),(yyvsp[(3) - (3)].tVal),NULL,NULL);
	}
    break;

  case 136:
/* Line 1792 of yacc.c  */
#line 844 "c_compiler.y"
    {
		struct value temp;
		temp.v.s = "=";
		temp.use = "string";
		(yyval.tVal) = create_node(temp,INIT_DECLARATOR,(yyvsp[(1) - (3)].tVal),(yyvsp[(3) - (3)].tVal),NULL,NULL);
	}
    break;

  case 137:
/* Line 1792 of yacc.c  */
#line 851 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,INIT_DECLARATOR,(yyvsp[(1) - (1)].tVal),NULL,NULL,NULL);
	}
    break;

  case 138:
/* Line 1792 of yacc.c  */
#line 858 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,INITIALIZER,(yyvsp[(2) - (3)].tVal),NULL,NULL,NULL);
	}
    break;

  case 139:
/* Line 1792 of yacc.c  */
#line 862 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,INITIALIZER,(yyvsp[(2) - (4)].tVal),NULL,NULL,NULL);
	}
    break;

  case 140:
/* Line 1792 of yacc.c  */
#line 866 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,INITIALIZER,(yyvsp[(1) - (1)].tVal),NULL,NULL,NULL);
	}
    break;

  case 141:
/* Line 1792 of yacc.c  */
#line 873 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,INITIALIZER_LIST,(yyvsp[(1) - (2)].tVal),NULL,NULL,NULL);
	}
    break;

  case 142:
/* Line 1792 of yacc.c  */
#line 877 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,INITIALIZER_LIST,(yyvsp[(1) - (1)].tVal),NULL,NULL,NULL);
	}
    break;

  case 143:
/* Line 1792 of yacc.c  */
#line 881 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,INITIALIZER_LIST,(yyvsp[(1) - (4)].tVal),(yyvsp[(3) - (4)].tVal),NULL,NULL);
	}
    break;

  case 144:
/* Line 1792 of yacc.c  */
#line 885 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,INITIALIZER_LIST,(yyvsp[(1) - (3)].tVal),(yyvsp[(3) - (3)].tVal),NULL,NULL);
	}
    break;

  case 145:
/* Line 1792 of yacc.c  */
#line 891 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,ITERATION_STATEMENT,(yyvsp[(3) - (5)].tVal),(yyvsp[(5) - (5)].tVal),NULL,NULL);
	}
    break;

  case 146:
/* Line 1792 of yacc.c  */
#line 895 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,ITERATION_STATEMENT,(yyvsp[(2) - (7)].tVal),(yyvsp[(5) - (7)].tVal),NULL,NULL);
	}
    break;

  case 147:
/* Line 1792 of yacc.c  */
#line 899 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,ITERATION_STATEMENT,(yyvsp[(3) - (6)].tVal),(yyvsp[(4) - (6)].tVal),(yyvsp[(6) - (6)].tVal),NULL);
	}
    break;

  case 148:
/* Line 1792 of yacc.c  */
#line 903 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,ITERATION_STATEMENT,(yyvsp[(3) - (7)].tVal),(yyvsp[(4) - (7)].tVal),(yyvsp[(5) - (7)].tVal),(yyvsp[(7) - (7)].tVal));
	}
    break;

  case 149:
/* Line 1792 of yacc.c  */
#line 907 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,ITERATION_STATEMENT,(yyvsp[(3) - (6)].tVal),(yyvsp[(4) - (6)].tVal),(yyvsp[(6) - (6)].tVal),NULL);
	}
    break;

  case 150:
/* Line 1792 of yacc.c  */
#line 911 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,ITERATION_STATEMENT,(yyvsp[(3) - (7)].tVal),(yyvsp[(4) - (7)].tVal),(yyvsp[(5) - (7)].tVal),(yyvsp[(7) - (7)].tVal));
	}
    break;

  case 151:
/* Line 1792 of yacc.c  */
#line 918 "c_compiler.y"
    {
		struct value temp;
		temp.v.s = yylval.sVal;
		temp.use = "identifier";
		(yyval.tVal) = create_node(temp,JUMP_STATEMENT,NULL,NULL,NULL,NULL);
	}
    break;

  case 152:
/* Line 1792 of yacc.c  */
#line 925 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,JUMP_STATEMENT,NULL,NULL,NULL,NULL);
	}
    break;

  case 153:
/* Line 1792 of yacc.c  */
#line 929 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,JUMP_STATEMENT,NULL,NULL,NULL,NULL);
	}
    break;

  case 154:
/* Line 1792 of yacc.c  */
#line 933 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,JUMP_STATEMENT,NULL,NULL,NULL,NULL);
	}
    break;

  case 155:
/* Line 1792 of yacc.c  */
#line 937 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,JUMP_STATEMENT,(yyvsp[(2) - (3)].tVal),NULL,NULL,NULL);
	}
    break;

  case 156:
/* Line 1792 of yacc.c  */
#line 944 "c_compiler.y"
    {
		struct value temp;
		temp.v.s = yylval.sVal;
		temp.use = "identifier";
		(yyval.tVal) = create_node(temp,LABELED_STATEMENT,(yyvsp[(3) - (3)].tVal),NULL,NULL,NULL);
	}
    break;

  case 157:
/* Line 1792 of yacc.c  */
#line 951 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,LABELED_STATEMENT,(yyvsp[(2) - (4)].tVal),(yyvsp[(4) - (4)].tVal),NULL,NULL);
	}
    break;

  case 158:
/* Line 1792 of yacc.c  */
#line 955 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,LABELED_STATEMENT,(yyvsp[(3) - (3)].tVal),NULL,NULL,NULL);
	}
    break;

  case 159:
/* Line 1792 of yacc.c  */
#line 962 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,LOGICAL_AND_EXPRESSION,(yyvsp[(1) - (1)].tVal),NULL,NULL,NULL);
	}
    break;

  case 160:
/* Line 1792 of yacc.c  */
#line 966 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,LOGICAL_AND_EXPRESSION,(yyvsp[(1) - (3)].tVal),(yyvsp[(3) - (3)].tVal),NULL,NULL);
	}
    break;

  case 161:
/* Line 1792 of yacc.c  */
#line 973 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,LOGICAL_OR_EXPRESSION,(yyvsp[(1) - (1)].tVal),NULL,NULL,NULL);
	}
    break;

  case 162:
/* Line 1792 of yacc.c  */
#line 977 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,LOGICAL_OR_EXPRESSION,(yyvsp[(1) - (3)].tVal),(yyvsp[(3) - (3)].tVal),NULL,NULL);
	}
    break;

  case 163:
/* Line 1792 of yacc.c  */
#line 984 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,MULTIPLICATIVE_EXPRESSION,(yyvsp[(1) - (1)].tVal),NULL,NULL,NULL);
	}
    break;

  case 164:
/* Line 1792 of yacc.c  */
#line 988 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,MULTIPLICATIVE_EXPRESSION,(yyvsp[(1) - (3)].tVal),(yyvsp[(3) - (3)].tVal),NULL,NULL);
	}
    break;

  case 165:
/* Line 1792 of yacc.c  */
#line 992 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,MULTIPLICATIVE_EXPRESSION,(yyvsp[(1) - (3)].tVal),(yyvsp[(3) - (3)].tVal),NULL,NULL);
	}
    break;

  case 166:
/* Line 1792 of yacc.c  */
#line 996 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,MULTIPLICATIVE_EXPRESSION,(yyvsp[(1) - (3)].tVal),(yyvsp[(3) - (3)].tVal),NULL,NULL);
	}
    break;

  case 167:
/* Line 1792 of yacc.c  */
#line 1004 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,PARAMETER_TYPE_LIST,(yyvsp[(1) - (3)].tVal),NULL,NULL,NULL);
	}
    break;

  case 168:
/* Line 1792 of yacc.c  */
#line 1008 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,PARAMETER_TYPE_LIST,(yyvsp[(1) - (1)].tVal),NULL,NULL,NULL);
	}
    break;

  case 169:
/* Line 1792 of yacc.c  */
#line 1015 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,PARAMETER_LIST,(yyvsp[(1) - (1)].tVal),NULL,NULL,NULL);
	}
    break;

  case 170:
/* Line 1792 of yacc.c  */
#line 1019 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,PARAMETER_LIST,(yyvsp[(1) - (3)].tVal),(yyvsp[(3) - (3)].tVal),NULL,NULL);
	}
    break;

  case 171:
/* Line 1792 of yacc.c  */
#line 1026 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,PARAMETER_DECLARATION,(yyvsp[(1) - (2)].tVal),(yyvsp[(2) - (2)].tVal),NULL,NULL);
		int i,j,ti=0,ii=0;
		for(i=0;i<100;i++) {
			id[i] = (char *)malloc(IDLENGTH*sizeof(char));
			strcpy(id[i],"NIL");
			type[i] = (char *)malloc(10*sizeof(char));
			strcpy(type[i],"NIL");
		}
		ti=find_usage((yyvsp[(1) - (2)].tVal),type,ti,"string");
		ii=find_usage((yyvsp[(2) - (2)].tVal),id,ii,"identifier");
		for(i=0;i<ii;i++) {
			for(j=1;j<ti;j++) {
				if(strcmp(type[j],"NIL")!=0) {
					strcat(type[0]," ");
					strcat(type[0],type[j]);
				}
			}
			hash_insert(id[i],type[0]);
		}
	}
    break;

  case 172:
/* Line 1792 of yacc.c  */
#line 1048 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,PARAMETER_DECLARATION,(yyvsp[(1) - (2)].tVal),(yyvsp[(2) - (2)].tVal),NULL,NULL);
	}
    break;

  case 173:
/* Line 1792 of yacc.c  */
#line 1052 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,PARAMETER_DECLARATION,(yyvsp[(1) - (1)].tVal),NULL,NULL,NULL);
	}
    break;

  case 174:
/* Line 1792 of yacc.c  */
#line 1059 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,POINTER,(yyvsp[(2) - (3)].tVal),(yyvsp[(3) - (3)].tVal),NULL,NULL);
	}
    break;

  case 175:
/* Line 1792 of yacc.c  */
#line 1063 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,POINTER,(yyvsp[(2) - (2)].tVal),NULL,NULL,NULL);
	}
    break;

  case 176:
/* Line 1792 of yacc.c  */
#line 1067 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,POINTER,(yyvsp[(2) - (2)].tVal),NULL,NULL,NULL);
	}
    break;

  case 177:
/* Line 1792 of yacc.c  */
#line 1070 "c_compiler.y"
    {}
    break;

  case 178:
/* Line 1792 of yacc.c  */
#line 1076 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,POSTFIX_EXPRESSION,(yyvsp[(1) - (1)].tVal),NULL,NULL,NULL);
	}
    break;

  case 179:
/* Line 1792 of yacc.c  */
#line 1080 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,POSTFIX_EXPRESSION,(yyvsp[(1) - (4)].tVal),(yyvsp[(3) - (4)].tVal),NULL,NULL);
	}
    break;

  case 180:
/* Line 1792 of yacc.c  */
#line 1085 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,POSTFIX_EXPRESSION,(yyvsp[(1) - (3)].tVal),NULL,NULL,NULL);
	}
    break;

  case 181:
/* Line 1792 of yacc.c  */
#line 1090 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,POSTFIX_EXPRESSION,(yyvsp[(1) - (4)].tVal),(yyvsp[(3) - (4)].tVal),NULL,NULL);
	}
    break;

  case 182:
/* Line 1792 of yacc.c  */
#line 1095 "c_compiler.y"
    {
		struct value temp;
		temp.v.s = yylval.sVal;
		temp.use = "identifier";
		(yyval.tVal) = create_node(temp,POSTFIX_EXPRESSION,(yyvsp[(1) - (3)].tVal),NULL,NULL,NULL);
	}
    break;

  case 183:
/* Line 1792 of yacc.c  */
#line 1103 "c_compiler.y"
    {
		struct value temp;
		temp.v.s = yylval.sVal;
		temp.use = "identifier";
		(yyval.tVal) = create_node(temp,POSTFIX_EXPRESSION,(yyvsp[(1) - (3)].tVal),NULL,NULL,NULL);
	}
    break;

  case 184:
/* Line 1792 of yacc.c  */
#line 1111 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,POSTFIX_EXPRESSION,(yyvsp[(1) - (2)].tVal),NULL,NULL,NULL);
	}
    break;

  case 185:
/* Line 1792 of yacc.c  */
#line 1116 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,POSTFIX_EXPRESSION,(yyvsp[(1) - (2)].tVal),NULL,NULL,NULL);
	}
    break;

  case 186:
/* Line 1792 of yacc.c  */
#line 1121 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,POSTFIX_EXPRESSION,(yyvsp[(2) - (6)].tVal),(yyvsp[(5) - (6)].tVal),NULL,NULL);
	}
    break;

  case 187:
/* Line 1792 of yacc.c  */
#line 1125 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,POSTFIX_EXPRESSION,(yyvsp[(2) - (7)].tVal),(yyvsp[(5) - (7)].tVal),NULL,NULL);
	}
    break;

  case 188:
/* Line 1792 of yacc.c  */
#line 1132 "c_compiler.y"
    {
		struct value temp;
		temp.v.s = yylval.sVal;
		temp.use = "identifier";
		(yyval.tVal) = create_node(temp,PRIMARY_EXPRESSION,NULL,NULL,NULL,NULL);
	}
    break;

  case 189:
/* Line 1792 of yacc.c  */
#line 1139 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,PRIMARY_EXPRESSION,(yyvsp[(1) - (1)].tVal),NULL,NULL,NULL);
	}
    break;

  case 190:
/* Line 1792 of yacc.c  */
#line 1143 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,PRIMARY_EXPRESSION,(yyvsp[(1) - (1)].tVal),NULL,NULL,NULL);
	}
    break;

  case 191:
/* Line 1792 of yacc.c  */
#line 1147 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,PRIMARY_EXPRESSION,(yyvsp[(2) - (3)].tVal),NULL,NULL,NULL);
	}
    break;

  case 192:
/* Line 1792 of yacc.c  */
#line 1151 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,PRIMARY_EXPRESSION,(yyvsp[(1) - (1)].tVal),NULL,NULL,NULL);
	}
    break;

  case 193:
/* Line 1792 of yacc.c  */
#line 1157 "c_compiler.y"
    { 	BINARY_TREE ParseTree;
		struct value temp;
		temp.use="none";
		ParseTree = create_node(temp,PROGRAM,(yyvsp[(1) - (1)].tVal),NULL,NULL,NULL);
		PrintTree(ParseTree);
		print_table();
	}
    break;

  case 194:
/* Line 1792 of yacc.c  */
#line 1168 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,RELATIONAL_EXPRESSION,(yyvsp[(1) - (1)].tVal),NULL,NULL,NULL);
	}
    break;

  case 195:
/* Line 1792 of yacc.c  */
#line 1172 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,RELATIONAL_EXPRESSION,(yyvsp[(1) - (3)].tVal),(yyvsp[(3) - (3)].tVal),NULL,NULL);
	}
    break;

  case 196:
/* Line 1792 of yacc.c  */
#line 1176 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,RELATIONAL_EXPRESSION,(yyvsp[(1) - (3)].tVal),(yyvsp[(3) - (3)].tVal),NULL,NULL);
	}
    break;

  case 197:
/* Line 1792 of yacc.c  */
#line 1180 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,RELATIONAL_EXPRESSION,(yyvsp[(1) - (3)].tVal),(yyvsp[(3) - (3)].tVal),NULL,NULL);
	}
    break;

  case 198:
/* Line 1792 of yacc.c  */
#line 1184 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,RELATIONAL_EXPRESSION,(yyvsp[(1) - (3)].tVal),(yyvsp[(3) - (3)].tVal),NULL,NULL);
	}
    break;

  case 199:
/* Line 1792 of yacc.c  */
#line 1192 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,SELECTION_STATEMENT,(yyvsp[(3) - (7)].tVal),(yyvsp[(5) - (7)].tVal),(yyvsp[(7) - (7)].tVal),NULL);
	}
    break;

  case 200:
/* Line 1792 of yacc.c  */
#line 1197 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,SELECTION_STATEMENT,(yyvsp[(3) - (5)].tVal),(yyvsp[(5) - (5)].tVal),NULL,NULL);
	}
    break;

  case 201:
/* Line 1792 of yacc.c  */
#line 1202 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,SELECTION_STATEMENT,(yyvsp[(3) - (5)].tVal),(yyvsp[(5) - (5)].tVal),NULL,NULL);
	}
    break;

  case 202:
/* Line 1792 of yacc.c  */
#line 1209 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,STRING,NULL,NULL,NULL,NULL);
	}
    break;

  case 203:
/* Line 1792 of yacc.c  */
#line 1213 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,STRING,NULL,NULL,NULL,NULL);
	}
    break;

  case 204:
/* Line 1792 of yacc.c  */
#line 1220 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,SHIFT_EXPRESSION,(yyvsp[(1) - (1)].tVal),NULL,NULL,NULL);
	}
    break;

  case 205:
/* Line 1792 of yacc.c  */
#line 1224 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,SHIFT_EXPRESSION,(yyvsp[(1) - (3)].tVal),(yyvsp[(3) - (3)].tVal),NULL,NULL);
	}
    break;

  case 206:
/* Line 1792 of yacc.c  */
#line 1228 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,SHIFT_EXPRESSION,(yyvsp[(1) - (3)].tVal),(yyvsp[(3) - (3)].tVal),NULL,NULL);
	}
    break;

  case 207:
/* Line 1792 of yacc.c  */
#line 1235 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,STATIC_ASSERT_DECLARATION,NULL,(yyvsp[(3) - (7)].tVal),NULL,NULL);
	}
    break;

  case 208:
/* Line 1792 of yacc.c  */
#line 1242 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,STATEMENT,(yyvsp[(1) - (1)].tVal),NULL,NULL,NULL);
	}
    break;

  case 209:
/* Line 1792 of yacc.c  */
#line 1246 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,STATEMENT,(yyvsp[(1) - (1)].tVal),NULL,NULL,NULL);
	}
    break;

  case 210:
/* Line 1792 of yacc.c  */
#line 1250 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,STATEMENT,(yyvsp[(1) - (1)].tVal),NULL,NULL,NULL);
	}
    break;

  case 211:
/* Line 1792 of yacc.c  */
#line 1254 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,STATEMENT,(yyvsp[(1) - (1)].tVal),NULL,NULL,NULL);
	}
    break;

  case 212:
/* Line 1792 of yacc.c  */
#line 1258 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,STATEMENT,(yyvsp[(1) - (1)].tVal),NULL,NULL,NULL);
	}
    break;

  case 213:
/* Line 1792 of yacc.c  */
#line 1262 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,STATEMENT,(yyvsp[(1) - (1)].tVal),NULL,NULL,NULL);
	}
    break;

  case 214:
/* Line 1792 of yacc.c  */
#line 1269 "c_compiler.y"
    {	struct value temp;
		temp.v.s = "typedef";
		temp.use = "string";
		(yyval.tVal) = create_node(temp,STORAGE_CLASS_SPECIFIER,NULL,NULL,NULL,NULL);
	}
    break;

  case 215:
/* Line 1792 of yacc.c  */
#line 1275 "c_compiler.y"
    {	struct value temp;
		temp.v.s = "extern";
		temp.use = "string";
		(yyval.tVal) = create_node(temp,STORAGE_CLASS_SPECIFIER,NULL,NULL,NULL,NULL);
	}
    break;

  case 216:
/* Line 1792 of yacc.c  */
#line 1281 "c_compiler.y"
    {	struct value temp;
		temp.v.s = "static";
		temp.use = "string";
		(yyval.tVal) = create_node(temp,STORAGE_CLASS_SPECIFIER,NULL,NULL,NULL,NULL);
	}
    break;

  case 217:
/* Line 1792 of yacc.c  */
#line 1287 "c_compiler.y"
    {	struct value temp;
		temp.v.s = "thread_local";
		temp.use = "string";
		(yyval.tVal) = create_node(temp,STORAGE_CLASS_SPECIFIER,NULL,NULL,NULL,NULL);
	}
    break;

  case 218:
/* Line 1792 of yacc.c  */
#line 1293 "c_compiler.y"
    {	struct value temp;
		temp.v.s = "auto";
		temp.use = "string";
		(yyval.tVal) = create_node(temp,STORAGE_CLASS_SPECIFIER,NULL,NULL,NULL,NULL);
	}
    break;

  case 219:
/* Line 1792 of yacc.c  */
#line 1299 "c_compiler.y"
    {	struct value temp;
		temp.v.s = "register";
		temp.use = "string";
		(yyval.tVal) = create_node(temp,STORAGE_CLASS_SPECIFIER,NULL,NULL,NULL,NULL);
	}
    break;

  case 220:
/* Line 1792 of yacc.c  */
#line 1309 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,STRUCT_OR_UNION_SPECIFIER,(yyvsp[(1) - (4)].tVal),(yyvsp[(3) - (4)].tVal),NULL,NULL);
	}
    break;

  case 221:
/* Line 1792 of yacc.c  */
#line 1313 "c_compiler.y"
    {
		struct value temp;
		temp.v.s = yylval.sVal;
		temp.use = "identifier";
		(yyval.tVal) = create_node(temp,STRUCT_OR_UNION_SPECIFIER,(yyvsp[(1) - (5)].tVal),(yyvsp[(4) - (5)].tVal),NULL,NULL);
	}
    break;

  case 222:
/* Line 1792 of yacc.c  */
#line 1320 "c_compiler.y"
    {
		struct value temp;
		temp.v.s = yylval.sVal;
		temp.use = "identifier";
		(yyval.tVal) = create_node(temp,STRUCT_OR_UNION_SPECIFIER,(yyvsp[(1) - (2)].tVal),NULL,NULL,NULL);
	}
    break;

  case 223:
/* Line 1792 of yacc.c  */
#line 1330 "c_compiler.y"
    {	struct value temp;
		temp.v.s = "struct";
		temp.use = "string";
		(yyval.tVal) = create_node(temp,STRUCT_OR_UNION,NULL,NULL,NULL,NULL);
	}
    break;

  case 224:
/* Line 1792 of yacc.c  */
#line 1336 "c_compiler.y"
    {	struct value temp;
		temp.v.s = "union";
		temp.use = "string";
		(yyval.tVal) = create_node(temp,STRUCT_OR_UNION,NULL,NULL,NULL,NULL);
	}
    break;

  case 225:
/* Line 1792 of yacc.c  */
#line 1345 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,STRUCT_DECLARATION_LIST,(yyvsp[(1) - (1)].tVal),NULL,NULL,NULL);
	}
    break;

  case 226:
/* Line 1792 of yacc.c  */
#line 1349 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,STRUCT_DECLARATION_LIST,(yyvsp[(1) - (2)].tVal),(yyvsp[(2) - (2)].tVal),NULL,NULL);
	}
    break;

  case 227:
/* Line 1792 of yacc.c  */
#line 1356 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,STRUCT_DECLARATION,(yyvsp[(1) - (2)].tVal),NULL,NULL,NULL);
	}
    break;

  case 228:
/* Line 1792 of yacc.c  */
#line 1360 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,STRUCT_DECLARATION,(yyvsp[(1) - (3)].tVal),(yyvsp[(2) - (3)].tVal),NULL,NULL);
	}
    break;

  case 229:
/* Line 1792 of yacc.c  */
#line 1364 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,STRUCT_DECLARATION,(yyvsp[(1) - (1)].tVal),NULL,NULL,NULL);
	}
    break;

  case 230:
/* Line 1792 of yacc.c  */
#line 1371 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,SPECIFIER_QUALIFIER_LIST,(yyvsp[(1) - (2)].tVal),(yyvsp[(2) - (2)].tVal),NULL,NULL);
	}
    break;

  case 231:
/* Line 1792 of yacc.c  */
#line 1375 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,SPECIFIER_QUALIFIER_LIST,(yyvsp[(1) - (1)].tVal),NULL,NULL,NULL);
	}
    break;

  case 232:
/* Line 1792 of yacc.c  */
#line 1379 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,SPECIFIER_QUALIFIER_LIST,(yyvsp[(1) - (2)].tVal),(yyvsp[(2) - (2)].tVal),NULL,NULL);
	}
    break;

  case 233:
/* Line 1792 of yacc.c  */
#line 1383 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,SPECIFIER_QUALIFIER_LIST,(yyvsp[(1) - (1)].tVal),NULL,NULL,NULL);
	}
    break;

  case 234:
/* Line 1792 of yacc.c  */
#line 1390 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,STRUCT_DECLARATOR_LIST,(yyvsp[(1) - (1)].tVal),NULL,NULL,NULL);
	}
    break;

  case 235:
/* Line 1792 of yacc.c  */
#line 1394 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,STRUCT_DECLARATOR_LIST,(yyvsp[(1) - (3)].tVal),(yyvsp[(3) - (3)].tVal),NULL,NULL);
	}
    break;

  case 236:
/* Line 1792 of yacc.c  */
#line 1401 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,STRUCT_DECLARATOR,(yyvsp[(2) - (2)].tVal),NULL,NULL,NULL);
	}
    break;

  case 237:
/* Line 1792 of yacc.c  */
#line 1405 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,STRUCT_DECLARATOR,(yyvsp[(1) - (3)].tVal),(yyvsp[(3) - (3)].tVal),NULL,NULL);
	}
    break;

  case 238:
/* Line 1792 of yacc.c  */
#line 1409 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,STRUCT_DECLARATOR,(yyvsp[(1) - (1)].tVal),NULL,NULL,NULL);
	}
    break;

  case 239:
/* Line 1792 of yacc.c  */
#line 1417 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,TRANSLATION_UNIT,(yyvsp[(1) - (1)].tVal),NULL,NULL,NULL);
	}
    break;

  case 240:
/* Line 1792 of yacc.c  */
#line 1421 "c_compiler.y"
    {NOTHING 	
		(yyval.tVal) = create_node(temp,TRANSLATION_UNIT,(yyvsp[(1) - (2)].tVal),(yyvsp[(2) - (2)].tVal),NULL,NULL);
	}
    break;

  case 241:
/* Line 1792 of yacc.c  */
#line 1428 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,TYPE_NAME,(yyvsp[(1) - (2)].tVal),(yyvsp[(2) - (2)].tVal),NULL,NULL);
	}
    break;

  case 242:
/* Line 1792 of yacc.c  */
#line 1432 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,TYPE_NAME,(yyvsp[(1) - (1)].tVal),NULL,NULL,NULL);
	}
    break;

  case 243:
/* Line 1792 of yacc.c  */
#line 1439 "c_compiler.y"
    {	struct value temp;
		temp.v.s = "const";
		temp.use = "string";
		(yyval.tVal) = create_node(temp,TYPE_QUALIFIER,NULL,NULL,NULL,NULL);
	}
    break;

  case 244:
/* Line 1792 of yacc.c  */
#line 1445 "c_compiler.y"
    {	struct value temp;
		temp.v.s = "restrict";
		temp.use = "string";
		(yyval.tVal) = create_node(temp,TYPE_QUALIFIER,NULL,NULL,NULL,NULL);
	}
    break;

  case 245:
/* Line 1792 of yacc.c  */
#line 1451 "c_compiler.y"
    {	struct value temp;
		temp.v.s = "volatile";
		temp.use = "string";
		(yyval.tVal) = create_node(temp,TYPE_QUALIFIER,NULL,NULL,NULL,NULL);
	}
    break;

  case 246:
/* Line 1792 of yacc.c  */
#line 1460 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,TYPE_QUALIFIER_LIST,(yyvsp[(1) - (1)].tVal),NULL,NULL,NULL);
	}
    break;

  case 247:
/* Line 1792 of yacc.c  */
#line 1464 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,TYPE_QUALIFIER_LIST,(yyvsp[(1) - (2)].tVal),(yyvsp[(2) - (2)].tVal),NULL,NULL);
	}
    break;

  case 248:
/* Line 1792 of yacc.c  */
#line 1472 "c_compiler.y"
    {	struct value temp;
		temp.v.s = "void";
		temp.use = "string";
		(yyval.tVal) = create_node(temp,TYPE_SPECIFIER,NULL,NULL,NULL,NULL);
	}
    break;

  case 249:
/* Line 1792 of yacc.c  */
#line 1478 "c_compiler.y"
    {	struct value temp;
		temp.v.s = "char";
		temp.use = "string";
		(yyval.tVal) = create_node(temp,TYPE_SPECIFIER,NULL,NULL,NULL,NULL);
	}
    break;

  case 250:
/* Line 1792 of yacc.c  */
#line 1484 "c_compiler.y"
    {	struct value temp;
		temp.v.s = "short";
		temp.use = "string";
		(yyval.tVal) = create_node(temp,TYPE_SPECIFIER,NULL,NULL,NULL,NULL);
	}
    break;

  case 251:
/* Line 1792 of yacc.c  */
#line 1490 "c_compiler.y"
    {	struct value temp;
		temp.v.s = "int";
		temp.use = "string";
		(yyval.tVal) = create_node(temp,TYPE_SPECIFIER,NULL,NULL,NULL,NULL);
	}
    break;

  case 252:
/* Line 1792 of yacc.c  */
#line 1496 "c_compiler.y"
    {	struct value temp;
		temp.v.s = "long";
		temp.use = "string";
		(yyval.tVal) = create_node(temp,TYPE_SPECIFIER,NULL,NULL,NULL,NULL);
	}
    break;

  case 253:
/* Line 1792 of yacc.c  */
#line 1502 "c_compiler.y"
    {	struct value temp;
		temp.v.s = "float";
		temp.use = "string";
		(yyval.tVal) = create_node(temp,TYPE_SPECIFIER,NULL,NULL,NULL,NULL);
	}
    break;

  case 254:
/* Line 1792 of yacc.c  */
#line 1508 "c_compiler.y"
    {	struct value temp;
		temp.v.s = "double";
		temp.use = "string";
		(yyval.tVal) = create_node(temp,TYPE_SPECIFIER,NULL,NULL,NULL,NULL);
	}
    break;

  case 255:
/* Line 1792 of yacc.c  */
#line 1514 "c_compiler.y"
    {	struct value temp;
		temp.v.s = "signed";
		temp.use = "string";
		(yyval.tVal) = create_node(temp,TYPE_SPECIFIER,NULL,NULL,NULL,NULL);
	}
    break;

  case 256:
/* Line 1792 of yacc.c  */
#line 1520 "c_compiler.y"
    {	struct value temp;
		temp.v.s = "unsigned";
		temp.use = "string";
		(yyval.tVal) = create_node(temp,TYPE_SPECIFIER,NULL,NULL,NULL,NULL);
	}
    break;

  case 257:
/* Line 1792 of yacc.c  */
#line 1526 "c_compiler.y"
    {	struct value temp;
		temp.v.s = "bool";
		temp.use = "string";
		(yyval.tVal) = create_node(temp,TYPE_SPECIFIER,NULL,NULL,NULL,NULL);
	}
    break;

  case 258:
/* Line 1792 of yacc.c  */
#line 1532 "c_compiler.y"
    {	struct value temp;
		temp.v.s = "complex";
		temp.use = "string";
		(yyval.tVal) = create_node(temp,TYPE_SPECIFIER,NULL,NULL,NULL,NULL);
	}
    break;

  case 259:
/* Line 1792 of yacc.c  */
#line 1538 "c_compiler.y"
    {	struct value temp;
		temp.v.s = "imaginary";
		temp.use = "string";
		(yyval.tVal) = create_node(temp,TYPE_SPECIFIER,NULL,NULL,NULL,NULL);
	}
    break;

  case 260:
/* Line 1792 of yacc.c  */
#line 1544 "c_compiler.y"
    {NOTHING
		(yyval.tVal) = create_node(temp,TYPE_SPECIFIER,(yyvsp[(1) - (1)].tVal),NULL,NULL,NULL);
	}
    break;

  case 261:
/* Line 1792 of yacc.c  */
#line 1548 "c_compiler.y"
    {	struct value temp;
		temp.v.s = "enum";
		temp.use = "string";
		(yyval.tVal) = create_node(temp,TYPE_SPECIFIER,(yyvsp[(1) - (1)].tVal),NULL,NULL,NULL);
	}
    break;

  case 262:
/* Line 1792 of yacc.c  */
#line 1554 "c_compiler.y"
    {	struct value temp;
		temp.v.s = "typedef_name";
		temp.use = "string";
		(yyval.tVal) = create_node(temp,TYPE_SPECIFIER,NULL,NULL,NULL,NULL);
	}
    break;

  case 263:
/* Line 1792 of yacc.c  */
#line 1563 "c_compiler.y"
    {	struct value temp;
		temp.use="none";
		(yyval.tVal) = create_node(temp,UNARY_EXPRESSION,(yyvsp[(1) - (1)].tVal),NULL,NULL,NULL);
	}
    break;

  case 264:
/* Line 1792 of yacc.c  */
#line 1568 "c_compiler.y"
    {	struct value temp;
		temp.use="none";
		(yyval.tVal) = create_node(temp,UNARY_EXPRESSION,(yyvsp[(2) - (2)].tVal),NULL,NULL,NULL);
	}
    break;

  case 265:
/* Line 1792 of yacc.c  */
#line 1573 "c_compiler.y"
    {	struct value temp;
		temp.use="none";
		(yyval.tVal) = create_node(temp,UNARY_EXPRESSION,(yyvsp[(2) - (2)].tVal),NULL,NULL,NULL);
	}
    break;

  case 266:
/* Line 1792 of yacc.c  */
#line 1578 "c_compiler.y"
    {	struct value temp;
		temp.use="none";
		(yyval.tVal) = create_node(temp,UNARY_EXPRESSION,(yyvsp[(1) - (2)].tVal),(yyvsp[(2) - (2)].tVal),NULL,NULL);
	}
    break;

  case 267:
/* Line 1792 of yacc.c  */
#line 1583 "c_compiler.y"
    {	struct value temp;
		temp.use="none";
		(yyval.tVal) = create_node(temp,UNARY_EXPRESSION,(yyvsp[(2) - (2)].tVal),NULL,NULL,NULL);
	}
    break;

  case 268:
/* Line 1792 of yacc.c  */
#line 1588 "c_compiler.y"
    {	struct value temp;
		temp.use="none";
		(yyval.tVal) = create_node(temp,UNARY_EXPRESSION,(yyvsp[(3) - (4)].tVal),NULL,NULL,NULL);
	}
    break;

  case 269:
/* Line 1792 of yacc.c  */
#line 1593 "c_compiler.y"
    {	struct value temp;
		temp.use="none";
		(yyval.tVal) = create_node(temp,UNARY_EXPRESSION,(yyvsp[(3) - (4)].tVal),NULL,NULL,NULL);
	}
    break;

  case 270:
/* Line 1792 of yacc.c  */
#line 1600 "c_compiler.y"
    {}
    break;

  case 271:
/* Line 1792 of yacc.c  */
#line 1601 "c_compiler.y"
    {}
    break;

  case 272:
/* Line 1792 of yacc.c  */
#line 1602 "c_compiler.y"
    {}
    break;

  case 273:
/* Line 1792 of yacc.c  */
#line 1603 "c_compiler.y"
    {}
    break;

  case 274:
/* Line 1792 of yacc.c  */
#line 1604 "c_compiler.y"
    {}
    break;

  case 275:
/* Line 1792 of yacc.c  */
#line 1605 "c_compiler.y"
    {}
    break;


/* Line 1792 of yacc.c  */
#line 4700 "c_compiler.tab.c"
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


/* Line 2055 of yacc.c  */
#line 1609 "c_compiler.y"

#include <stdio.h>

void yyerror(const char *s)
{
	fflush(stdout);
	fprintf(stderr, "*** %s\n", s);
}
BINARY_TREE create_node(struct value val,int case_identifier,BINARY_TREE p1,BINARY_TREE p2,BINARY_TREE p3,BINARY_TREE p4) {
	BINARY_TREE t;
	t= (BINARY_TREE)malloc(sizeof(TREE_NODE));
	t->val = val;
	t->nodeIdentifier = case_identifier;
	t->first = p1;
	t->second = p2;
	t->third = p3;
	t->fourth = p4;
	return (t);
}
void PrintTree(BINARY_TREE t) {
	if(t==NULL)
		return; 
	if(strcmp(t->val.use,"string")==0)
		printf("Value: %s ",t->val.v.s);
	if(strcmp(t->val.use,"identifier")==0)
		printf("Value: %s ",t->val.v.s);
	else if(strcmp(t->val.use,"float")==0)
		printf("Value: %f ",t->val.v.f);
	else if(strcmp(t->val.use,"integer")==0)
		printf("Value: %d ",t->val.v.i);
	else 
		printf("Value: ");

	printf("Label: %s\n",labels[(t->nodeIdentifier)]);
	//if(t->first!=NULL) printf("Going from %s to %s\n",labels[t->nodeIdentifier],labels[t->first->nodeIdentifier]);
	PrintTree(t->first);
	//if(t->second!=NULL) printf("Going from %s to %s\n",labels[t->nodeIdentifier],labels[t->second->nodeIdentifier]);
	PrintTree(t->second);
	//if(t->third!=NULL) printf("Going from %s to %s\n",labels[t->nodeIdentifier],labels[t->third->nodeIdentifier]);
	PrintTree(t->third);
	//if(t->fourth!=NULL) printf("Going from %s to %s\n",labels[t->nodeIdentifier],labels[t->fourth->nodeIdentifier]);
	PrintTree(t->fourth);
}
int find_usage(BINARY_TREE p,char *type[100],int i,char *u) {
if(p==NULL)
	return i;
if(strcmp(p->val.use,u)==0) {
	strcpy(type[i],p->val.v.s);
	i++;
}
i=find_usage(p->first,type,i,u);
i=find_usage(p->second,type,i,u);
i=find_usage(p->third,type,i,u);
i=find_usage(p->fourth,type,i,u);
return i;
}

