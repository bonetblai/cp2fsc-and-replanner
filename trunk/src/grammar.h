#ifndef YY_PDDL_Parser_h_included
#define YY_PDDL_Parser_h_included

#line 1 "/home/bonet/space/software/bison++-1.21-8/lib/bison.h"
/* before anything */
#ifdef c_plusplus
#ifndef __cplusplus
#define __cplusplus
#endif
#endif
#ifdef __cplusplus
#ifndef YY_USE_CLASS
#define YY_USE_CLASS
#endif
#else
#endif
#include <stdio.h>

/* #line 14 "/home/bonet/space/software/bison++-1.21-8/lib/bison.h" */
#line 21 "grammar.h"
#define YY_PDDL_Parser_ERROR  log_error
#define YY_PDDL_Parser_ERROR_BODY  = 0
#define YY_PDDL_Parser_ERROR_VERBOSE  1
#define YY_PDDL_Parser_LEX  next_token
#define YY_PDDL_Parser_LEX_BODY  = 0
#define YY_PDDL_Parser_DEBUG  1
#define YY_PDDL_Parser_INHERIT  : public PDDL_Base
#define YY_PDDL_Parser_CONSTRUCTOR_PARAM  StringTable& t, int type, const Options::Mode &options
#define YY_PDDL_Parser_CONSTRUCTOR_INIT  : PDDL_Base(t, options), error_flag_(false), type_(type)
#define YY_PDDL_Parser_MEMBERS  \
  public: \
    typedef enum { replanner, cp2fsc } Type; \
    virtual ~PDDL_Parser() { } \
    virtual std::ostream& syntax_errors() = 0; \
    bool error_flag_; \
    int type_; \
  private: \
    std::vector<ForallEffect*> forall_effects_; \
    std::vector<ForallCondition*> forall_conditions_; \
    effect_vec *effect_vec_ptr_;
#line 24 "ppddl.y"

#include <stdlib.h>
#include <string.h>
#include <list>
#include <sstream>
#include "base.h"

#line 32 "ppddl.y"
typedef union {
    StringTable::Cell                 *sym;
    PDDL_Base::VariableSymbol         *vsym;
    PDDL_Base::Atom                   *atom;
    PDDL_Base::symbol_vec             *param;
    PDDL_Base::var_symbol_vec         *vparam;
    PDDL_Base::condition_vec          *condition_vec;
    PDDL_Base::effect_vec             *effect_vec;
    const PDDL_Base::Condition        *condition;
    const PDDL_Base::Effect           *effect;
    const PDDL_Base::Invariant        *invariant;
    const PDDL_Base::Clause           *clause;
    const PDDL_Base::Oneof            *oneof;
    const PDDL_Base::init_element_vec *ilist;
    const PDDL_Base::InitElement      *ielem;
    int                               ival;
} yy_PDDL_Parser_stype;
#define YY_PDDL_Parser_STYPE yy_PDDL_Parser_stype

#line 14 "/home/bonet/space/software/bison++-1.21-8/lib/bison.h"
 /* %{ and %header{ and %union, during decl */
#ifndef YY_PDDL_Parser_COMPATIBILITY
#ifndef YY_USE_CLASS
#define  YY_PDDL_Parser_COMPATIBILITY 1
#else
#define  YY_PDDL_Parser_COMPATIBILITY 0
#endif
#endif

#if YY_PDDL_Parser_COMPATIBILITY != 0
/* backward compatibility */
#ifdef YYLTYPE
#ifndef YY_PDDL_Parser_LTYPE
#define YY_PDDL_Parser_LTYPE YYLTYPE
/* WARNING obsolete !!! user defined YYLTYPE not reported into generated header */
/* use %define LTYPE */
#endif
#endif
#ifdef YYSTYPE
#ifndef YY_PDDL_Parser_STYPE 
#define YY_PDDL_Parser_STYPE YYSTYPE
/* WARNING obsolete !!! user defined YYSTYPE not reported into generated header */
/* use %define STYPE */
#endif
#endif
#ifdef YYDEBUG
#ifndef YY_PDDL_Parser_DEBUG
#define  YY_PDDL_Parser_DEBUG YYDEBUG
/* WARNING obsolete !!! user defined YYDEBUG not reported into generated header */
/* use %define DEBUG */
#endif
#endif
#ifdef YY_PDDL_Parser_STYPE
#ifndef yystype
#define yystype YY_PDDL_Parser_STYPE
#endif
#endif
/* use goto to be compatible */
#ifndef YY_PDDL_Parser_USE_GOTO
#define YY_PDDL_Parser_USE_GOTO 1
#endif
#endif

/* use no goto to be clean in C++ */
#ifndef YY_PDDL_Parser_USE_GOTO
#define YY_PDDL_Parser_USE_GOTO 0
#endif

#ifndef YY_PDDL_Parser_PURE

/* #line 63 "/home/bonet/space/software/bison++-1.21-8/lib/bison.h" */
#line 122 "grammar.h"

#line 63 "/home/bonet/space/software/bison++-1.21-8/lib/bison.h"
/* YY_PDDL_Parser_PURE */
#endif

/* #line 65 "/home/bonet/space/software/bison++-1.21-8/lib/bison.h" */
#line 129 "grammar.h"

#line 65 "/home/bonet/space/software/bison++-1.21-8/lib/bison.h"
/* prefix */
#ifndef YY_PDDL_Parser_DEBUG

/* #line 67 "/home/bonet/space/software/bison++-1.21-8/lib/bison.h" */
#line 136 "grammar.h"

#line 67 "/home/bonet/space/software/bison++-1.21-8/lib/bison.h"
/* YY_PDDL_Parser_DEBUG */
#endif
#ifndef YY_PDDL_Parser_LSP_NEEDED

/* #line 70 "/home/bonet/space/software/bison++-1.21-8/lib/bison.h" */
#line 144 "grammar.h"

#line 70 "/home/bonet/space/software/bison++-1.21-8/lib/bison.h"
 /* YY_PDDL_Parser_LSP_NEEDED*/
#endif
/* DEFAULT LTYPE*/
#ifdef YY_PDDL_Parser_LSP_NEEDED
#ifndef YY_PDDL_Parser_LTYPE
typedef
  struct yyltype
    {
      int timestamp;
      int first_line;
      int first_column;
      int last_line;
      int last_column;
      char *text;
   }
  yyltype;

#define YY_PDDL_Parser_LTYPE yyltype
#endif
#endif
/* DEFAULT STYPE*/
#ifndef YY_PDDL_Parser_STYPE
#define YY_PDDL_Parser_STYPE int
#endif
/* DEFAULT MISCELANEOUS */
#ifndef YY_PDDL_Parser_PARSE
#define YY_PDDL_Parser_PARSE yyparse
#endif
#ifndef YY_PDDL_Parser_LEX
#define YY_PDDL_Parser_LEX yylex
#endif
#ifndef YY_PDDL_Parser_LVAL
#define YY_PDDL_Parser_LVAL yylval
#endif
#ifndef YY_PDDL_Parser_LLOC
#define YY_PDDL_Parser_LLOC yylloc
#endif
#ifndef YY_PDDL_Parser_CHAR
#define YY_PDDL_Parser_CHAR yychar
#endif
#ifndef YY_PDDL_Parser_NERRS
#define YY_PDDL_Parser_NERRS yynerrs
#endif
#ifndef YY_PDDL_Parser_DEBUG_FLAG
#define YY_PDDL_Parser_DEBUG_FLAG yydebug
#endif
#ifndef YY_PDDL_Parser_ERROR
#define YY_PDDL_Parser_ERROR yyerror
#endif

#ifndef YY_PDDL_Parser_PARSE_PARAM
#ifndef __STDC__
#ifndef __cplusplus
#ifndef YY_USE_CLASS
#define YY_PDDL_Parser_PARSE_PARAM
#ifndef YY_PDDL_Parser_PARSE_PARAM_DEF
#define YY_PDDL_Parser_PARSE_PARAM_DEF
#endif
#endif
#endif
#endif
#ifndef YY_PDDL_Parser_PARSE_PARAM
#define YY_PDDL_Parser_PARSE_PARAM void
#endif
#endif

/* TOKEN C */
#ifndef YY_USE_CLASS

#ifndef YY_PDDL_Parser_PURE
extern YY_PDDL_Parser_STYPE YY_PDDL_Parser_LVAL;
#endif


/* #line 143 "/home/bonet/space/software/bison++-1.21-8/lib/bison.h" */
#line 222 "grammar.h"
#define	TK_OPEN	258
#define	TK_CLOSE	259
#define	TK_OPEN_SQ	260
#define	TK_CLOSE_SQ	261
#define	TK_EQ	262
#define	TK_HYPHEN	263
#define	TK_NEW_SYMBOL	264
#define	TK_OBJ_SYMBOL	265
#define	TK_TYPE_SYMBOL	266
#define	TK_PRED_SYMBOL	267
#define	TK_VAR_SYMBOL	268
#define	TK_ACTION_SYMBOL	269
#define	TK_AXIOM_SYMBOL	270
#define	TK_SENSOR_SYMBOL	271
#define	TK_MISC_SYMBOL	272
#define	TK_KEYWORD	273
#define	TK_NEW_VAR_SYMBOL	274
#define	TK_VARNAME_SYMBOL	275
#define	TK_INT	276
#define	KW_REQS	277
#define	KW_TRANSLATION	278
#define	KW_CONSTANTS	279
#define	KW_PREDS	280
#define	KW_TYPES	281
#define	KW_DEFINE	282
#define	KW_DOMAIN	283
#define	KW_ACTION	284
#define	KW_ARGS	285
#define	KW_PRE	286
#define	KW_EFFECT	287
#define	KW_AND	288
#define	KW_OR	289
#define	KW_EXISTS	290
#define	KW_FORALL	291
#define	KW_NOT	292
#define	KW_WHEN	293
#define	KW_ONEOF	294
#define	KW_PROBLEM	295
#define	KW_FORDOMAIN	296
#define	KW_OBJECTS	297
#define	KW_INIT	298
#define	KW_GOAL	299
#define	KW_SENSOR	300
#define	KW_SENSE	301
#define	KW_OBSERVE	302
#define	KW_AXIOM	303
#define	KW_COND	304
#define	KW_OBSERVABLE	305
#define	KW_BODY	306
#define	KW_HEAD	307
#define	KW_STICKY	308
#define	KW_FLUENTS	309
#define	KW_HIDDEN	310
#define	KW_INVARIANT	311
#define	KW_AT_LEAST_ONE	312
#define	KW_AT_MOST_ONE	313
#define	KW_EXACTLY_ONE	314
#define	KW_VARIABLE	315
#define	KW_OBS_VARIABLE	316
#define	KW_VALUES	317
#define	KW_SENSING_MODEL	318
#define	KW_DEFAULT_SENSING_MODEL	319


#line 143 "/home/bonet/space/software/bison++-1.21-8/lib/bison.h"
 /* #defines token */
/* after #define tokens, before const tokens S5*/
#else
#ifndef YY_PDDL_Parser_CLASS
#define YY_PDDL_Parser_CLASS PDDL_Parser
#endif

#ifndef YY_PDDL_Parser_INHERIT
#define YY_PDDL_Parser_INHERIT
#endif
#ifndef YY_PDDL_Parser_MEMBERS
#define YY_PDDL_Parser_MEMBERS 
#endif
#ifndef YY_PDDL_Parser_LEX_BODY
#define YY_PDDL_Parser_LEX_BODY  
#endif
#ifndef YY_PDDL_Parser_ERROR_BODY
#define YY_PDDL_Parser_ERROR_BODY  
#endif
#ifndef YY_PDDL_Parser_CONSTRUCTOR_PARAM
#define YY_PDDL_Parser_CONSTRUCTOR_PARAM
#endif
/* choose between enum and const */
#ifndef YY_PDDL_Parser_USE_CONST_TOKEN
#define YY_PDDL_Parser_USE_CONST_TOKEN 0
/* yes enum is more compatible with flex,  */
/* so by default we use it */ 
#endif
#if YY_PDDL_Parser_USE_CONST_TOKEN != 0
#ifndef YY_PDDL_Parser_ENUM_TOKEN
#define YY_PDDL_Parser_ENUM_TOKEN yy_PDDL_Parser_enum_token
#endif
#endif

class YY_PDDL_Parser_CLASS YY_PDDL_Parser_INHERIT
{
public: 
#if YY_PDDL_Parser_USE_CONST_TOKEN != 0
/* static const int token ... */

/* #line 182 "/home/bonet/space/software/bison++-1.21-8/lib/bison.h" */
#line 329 "grammar.h"
static const int TK_OPEN;
static const int TK_CLOSE;
static const int TK_OPEN_SQ;
static const int TK_CLOSE_SQ;
static const int TK_EQ;
static const int TK_HYPHEN;
static const int TK_NEW_SYMBOL;
static const int TK_OBJ_SYMBOL;
static const int TK_TYPE_SYMBOL;
static const int TK_PRED_SYMBOL;
static const int TK_VAR_SYMBOL;
static const int TK_ACTION_SYMBOL;
static const int TK_AXIOM_SYMBOL;
static const int TK_SENSOR_SYMBOL;
static const int TK_MISC_SYMBOL;
static const int TK_KEYWORD;
static const int TK_NEW_VAR_SYMBOL;
static const int TK_VARNAME_SYMBOL;
static const int TK_INT;
static const int KW_REQS;
static const int KW_TRANSLATION;
static const int KW_CONSTANTS;
static const int KW_PREDS;
static const int KW_TYPES;
static const int KW_DEFINE;
static const int KW_DOMAIN;
static const int KW_ACTION;
static const int KW_ARGS;
static const int KW_PRE;
static const int KW_EFFECT;
static const int KW_AND;
static const int KW_OR;
static const int KW_EXISTS;
static const int KW_FORALL;
static const int KW_NOT;
static const int KW_WHEN;
static const int KW_ONEOF;
static const int KW_PROBLEM;
static const int KW_FORDOMAIN;
static const int KW_OBJECTS;
static const int KW_INIT;
static const int KW_GOAL;
static const int KW_SENSOR;
static const int KW_SENSE;
static const int KW_OBSERVE;
static const int KW_AXIOM;
static const int KW_COND;
static const int KW_OBSERVABLE;
static const int KW_BODY;
static const int KW_HEAD;
static const int KW_STICKY;
static const int KW_FLUENTS;
static const int KW_HIDDEN;
static const int KW_INVARIANT;
static const int KW_AT_LEAST_ONE;
static const int KW_AT_MOST_ONE;
static const int KW_EXACTLY_ONE;
static const int KW_VARIABLE;
static const int KW_OBS_VARIABLE;
static const int KW_VALUES;
static const int KW_SENSING_MODEL;
static const int KW_DEFAULT_SENSING_MODEL;


#line 182 "/home/bonet/space/software/bison++-1.21-8/lib/bison.h"
 /* decl const */
#else
enum YY_PDDL_Parser_ENUM_TOKEN { YY_PDDL_Parser_NULL_TOKEN=0

/* #line 185 "/home/bonet/space/software/bison++-1.21-8/lib/bison.h" */
#line 400 "grammar.h"
	,TK_OPEN=258
	,TK_CLOSE=259
	,TK_OPEN_SQ=260
	,TK_CLOSE_SQ=261
	,TK_EQ=262
	,TK_HYPHEN=263
	,TK_NEW_SYMBOL=264
	,TK_OBJ_SYMBOL=265
	,TK_TYPE_SYMBOL=266
	,TK_PRED_SYMBOL=267
	,TK_VAR_SYMBOL=268
	,TK_ACTION_SYMBOL=269
	,TK_AXIOM_SYMBOL=270
	,TK_SENSOR_SYMBOL=271
	,TK_MISC_SYMBOL=272
	,TK_KEYWORD=273
	,TK_NEW_VAR_SYMBOL=274
	,TK_VARNAME_SYMBOL=275
	,TK_INT=276
	,KW_REQS=277
	,KW_TRANSLATION=278
	,KW_CONSTANTS=279
	,KW_PREDS=280
	,KW_TYPES=281
	,KW_DEFINE=282
	,KW_DOMAIN=283
	,KW_ACTION=284
	,KW_ARGS=285
	,KW_PRE=286
	,KW_EFFECT=287
	,KW_AND=288
	,KW_OR=289
	,KW_EXISTS=290
	,KW_FORALL=291
	,KW_NOT=292
	,KW_WHEN=293
	,KW_ONEOF=294
	,KW_PROBLEM=295
	,KW_FORDOMAIN=296
	,KW_OBJECTS=297
	,KW_INIT=298
	,KW_GOAL=299
	,KW_SENSOR=300
	,KW_SENSE=301
	,KW_OBSERVE=302
	,KW_AXIOM=303
	,KW_COND=304
	,KW_OBSERVABLE=305
	,KW_BODY=306
	,KW_HEAD=307
	,KW_STICKY=308
	,KW_FLUENTS=309
	,KW_HIDDEN=310
	,KW_INVARIANT=311
	,KW_AT_LEAST_ONE=312
	,KW_AT_MOST_ONE=313
	,KW_EXACTLY_ONE=314
	,KW_VARIABLE=315
	,KW_OBS_VARIABLE=316
	,KW_VALUES=317
	,KW_SENSING_MODEL=318
	,KW_DEFAULT_SENSING_MODEL=319


#line 185 "/home/bonet/space/software/bison++-1.21-8/lib/bison.h"
 /* enum token */
     }; /* end of enum declaration */
#endif
public:
 int YY_PDDL_Parser_PARSE(YY_PDDL_Parser_PARSE_PARAM);
 virtual void YY_PDDL_Parser_ERROR(char *msg) YY_PDDL_Parser_ERROR_BODY;
#ifdef YY_PDDL_Parser_PURE
#ifdef YY_PDDL_Parser_LSP_NEEDED
 virtual int  YY_PDDL_Parser_LEX(YY_PDDL_Parser_STYPE *YY_PDDL_Parser_LVAL,YY_PDDL_Parser_LTYPE *YY_PDDL_Parser_LLOC) YY_PDDL_Parser_LEX_BODY;
#else
 virtual int  YY_PDDL_Parser_LEX(YY_PDDL_Parser_STYPE *YY_PDDL_Parser_LVAL) YY_PDDL_Parser_LEX_BODY;
#endif
#else
 virtual int YY_PDDL_Parser_LEX() YY_PDDL_Parser_LEX_BODY;
 YY_PDDL_Parser_STYPE YY_PDDL_Parser_LVAL;
#ifdef YY_PDDL_Parser_LSP_NEEDED
 YY_PDDL_Parser_LTYPE YY_PDDL_Parser_LLOC;
#endif
 int YY_PDDL_Parser_NERRS;
 int YY_PDDL_Parser_CHAR;
#endif
#if YY_PDDL_Parser_DEBUG != 0
public:
 int YY_PDDL_Parser_DEBUG_FLAG;	/*  nonzero means print parse trace	*/
#endif
public:
 YY_PDDL_Parser_CLASS(YY_PDDL_Parser_CONSTRUCTOR_PARAM);
public:
 YY_PDDL_Parser_MEMBERS 
};
/* other declare folow */
#endif


#if YY_PDDL_Parser_COMPATIBILITY != 0
/* backward compatibility */
#ifndef YYSTYPE
#define YYSTYPE YY_PDDL_Parser_STYPE
#endif

#ifndef YYLTYPE
#define YYLTYPE YY_PDDL_Parser_LTYPE
#endif
#ifndef YYDEBUG
#ifdef YY_PDDL_Parser_DEBUG 
#define YYDEBUG YY_PDDL_Parser_DEBUG
#endif
#endif

#endif
/* END */

/* #line 236 "/home/bonet/space/software/bison++-1.21-8/lib/bison.h" */
#line 519 "grammar.h"
#endif
