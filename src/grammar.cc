#define YY_PDDL_Parser_h_included

/*  A Bison++ parser, made from ppddl.y  */

 /* with Bison++ version bison++ Version 1.21-8, adapted from GNU bison by coetmeur@icdc.fr
  */


#line 1 "/usr/local/lib/bison.cc"
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Bob Corbett and Richard Stallman

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 1, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */

/* HEADER SECTION */
#if defined( _MSDOS ) || defined(MSDOS) || defined(__MSDOS__) 
#define __MSDOS_AND_ALIKE
#endif
#if defined(_WINDOWS) && defined(_MSC_VER)
#define __HAVE_NO_ALLOCA
#define __MSDOS_AND_ALIKE
#endif

#ifndef alloca
#if defined( __GNUC__)
#define alloca __builtin_alloca

#elif (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc)  || defined (__sgi)
#include <alloca.h>

#elif defined (__MSDOS_AND_ALIKE)
#include <malloc.h>
#ifndef __TURBOC__
/* MS C runtime lib */
#define alloca _alloca
#endif

#elif defined(_AIX)
#include <malloc.h>
#pragma alloca

#elif defined(__hpux)
#ifdef __cplusplus
extern "C" {
void *alloca (unsigned int);
};
#else /* not __cplusplus */
void *alloca ();
#endif /* not __cplusplus */

#endif /* not _AIX  not MSDOS, or __TURBOC__ or _AIX, not sparc.  */
#endif /* alloca not defined.  */
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
#ifndef __STDC__
#define const
#endif
#endif
#include <stdio.h>
#define YYBISON 1  

/* #line 73 "/usr/local/lib/bison.cc" */
#line 85 "grammar.cc"
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
    std::vector<ExistsCondition*> exists_conditions_; \
    std::vector<ForallSensing*> forall_sensing_; \
    effect_vec *effect_vec_ptr_;
#line 26 "ppddl.y"

#include <stdlib.h>
#include <string.h>
#include <list>
#include <sstream>
#include "base.h"
#include "utils.h"

#pragma GCC diagnostic ignored "-Wpragmas"
#pragma GCC diagnostic ignored "-Wchar-subscripts"
#pragma GCC diagnostic ignored "-Wc++11-compat-deprecated-writable-strings"
//#pragma GCC diagnostic ignored "-Wdeprecated-writable-strings"
//#pragma GCC diagnostic ignored "-Wwrite-strings"
//#pragma GCC diagnostic ignored "-Wuninitialized"
//#pragma GCC diagnostic ignored "-Wsign-compare"

#line 43 "ppddl.y"
typedef union {
    StringTable::Cell                  *sym;
    PDDL_Base::VariableSymbol          *vsym;
    PDDL_Base::Atom                    *atom;
    PDDL_Base::symbol_vec              *param;
    PDDL_Base::var_symbol_vec          *vparam;
    PDDL_Base::condition_vec           *condition_vec;
    PDDL_Base::effect_vec              *effect_vec;
    const PDDL_Base::Condition         *condition;
    const PDDL_Base::Effect            *effect;
    const PDDL_Base::Invariant         *invariant;
    const PDDL_Base::Clause            *clause;
    const PDDL_Base::Oneof             *oneof;
    const PDDL_Base::Unknown           *unknown;
    const PDDL_Base::init_element_vec  *ilist;
    const PDDL_Base::InitElement       *ielem;
    const PDDL_Base::SensingModel      *sensing_model;
    const PDDL_Base::SensingProxy      *sensing_proxy;
    const PDDL_Base::sensing_proxy_vec *sensing_proxy_list;
    int                                ival;
} yy_PDDL_Parser_stype;
#define YY_PDDL_Parser_STYPE yy_PDDL_Parser_stype

#line 73 "/usr/local/lib/bison.cc"
/* %{ and %header{ and %union, during decl */
#define YY_PDDL_Parser_BISON 1
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
#endif
#endif
#ifdef YYSTYPE
#ifndef YY_PDDL_Parser_STYPE 
#define YY_PDDL_Parser_STYPE YYSTYPE
#endif
#endif
#ifdef YYDEBUG
#ifndef YY_PDDL_Parser_DEBUG
#define  YY_PDDL_Parser_DEBUG YYDEBUG
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

/* #line 117 "/usr/local/lib/bison.cc" */
#line 196 "grammar.cc"

#line 117 "/usr/local/lib/bison.cc"
/*  YY_PDDL_Parser_PURE */
#endif

/* section apres lecture def, avant lecture grammaire S2 */

/* #line 121 "/usr/local/lib/bison.cc" */
#line 205 "grammar.cc"

#line 121 "/usr/local/lib/bison.cc"
/* prefix */
#ifndef YY_PDDL_Parser_DEBUG

/* #line 123 "/usr/local/lib/bison.cc" */
#line 212 "grammar.cc"

#line 123 "/usr/local/lib/bison.cc"
/* YY_PDDL_Parser_DEBUG */
#endif


#ifndef YY_PDDL_Parser_LSP_NEEDED

/* #line 128 "/usr/local/lib/bison.cc" */
#line 222 "grammar.cc"

#line 128 "/usr/local/lib/bison.cc"
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
      /* We used to use `unsigned long' as YY_PDDL_Parser_STYPE on MSDOS,
	 but it seems better to be consistent.
	 Most programs should declare their own type anyway.  */

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
#if YY_PDDL_Parser_COMPATIBILITY != 0
/* backward compatibility */
#ifdef YY_PDDL_Parser_LTYPE
#ifndef YYLTYPE
#define YYLTYPE YY_PDDL_Parser_LTYPE
#else
/* WARNING obsolete !!! user defined YYLTYPE not reported into generated header */
#endif
#endif
#ifndef YYSTYPE
#define YYSTYPE YY_PDDL_Parser_STYPE
#else
/* WARNING obsolete !!! user defined YYSTYPE not reported into generated header */
#endif
#ifdef YY_PDDL_Parser_PURE
#ifndef YYPURE
#define YYPURE YY_PDDL_Parser_PURE
#endif
#endif
#ifdef YY_PDDL_Parser_DEBUG
#ifndef YYDEBUG
#define YYDEBUG YY_PDDL_Parser_DEBUG 
#endif
#endif
#ifndef YY_PDDL_Parser_ERROR_VERBOSE
#ifdef YYERROR_VERBOSE
#define YY_PDDL_Parser_ERROR_VERBOSE YYERROR_VERBOSE
#endif
#endif
#ifndef YY_PDDL_Parser_LSP_NEEDED
#ifdef YYLSP_NEEDED
#define YY_PDDL_Parser_LSP_NEEDED YYLSP_NEEDED
#endif
#endif
#endif
#ifndef YY_USE_CLASS
/* TOKEN C */

/* #line 236 "/usr/local/lib/bison.cc" */
#line 335 "grammar.cc"
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
#define	KW_UNKNOWN	295
#define	KW_PROBLEM	296
#define	KW_FORDOMAIN	297
#define	KW_OBJECTS	298
#define	KW_INIT	299
#define	KW_GOAL	300
#define	KW_SENSOR	301
#define	KW_SENSE	302
#define	KW_OBSERVE	303
#define	KW_AXIOM	304
#define	KW_COND	305
#define	KW_OBSERVABLE	306
#define	KW_BODY	307
#define	KW_HEAD	308
#define	KW_STICKY	309
#define	KW_FLUENTS	310
#define	KW_HIDDEN	311
#define	KW_INVARIANT	312
#define	KW_AT_LEAST_ONE	313
#define	KW_AT_MOST_ONE	314
#define	KW_EXACTLY_ONE	315
#define	KW_VARIABLE	316
#define	KW_OBS_VARIABLE	317
#define	KW_VALUES	318
#define	KW_SENSING	319
#define	KW_DEFAULT_SENSING	320
#define	KW_MODEL_FOR	321


#line 236 "/usr/local/lib/bison.cc"
 /* #defines tokens */
#else
/* CLASS */
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
#ifndef YY_PDDL_Parser_CONSTRUCTOR_CODE
#define YY_PDDL_Parser_CONSTRUCTOR_CODE
#endif
#ifndef YY_PDDL_Parser_CONSTRUCTOR_INIT
#define YY_PDDL_Parser_CONSTRUCTOR_INIT
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

/* #line 280 "/usr/local/lib/bison.cc" */
#line 449 "grammar.cc"
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
static const int KW_UNKNOWN;
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
static const int KW_SENSING;
static const int KW_DEFAULT_SENSING;
static const int KW_MODEL_FOR;


#line 280 "/usr/local/lib/bison.cc"
 /* decl const */
#else
enum YY_PDDL_Parser_ENUM_TOKEN { YY_PDDL_Parser_NULL_TOKEN=0

/* #line 283 "/usr/local/lib/bison.cc" */
#line 522 "grammar.cc"
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
	,KW_UNKNOWN=295
	,KW_PROBLEM=296
	,KW_FORDOMAIN=297
	,KW_OBJECTS=298
	,KW_INIT=299
	,KW_GOAL=300
	,KW_SENSOR=301
	,KW_SENSE=302
	,KW_OBSERVE=303
	,KW_AXIOM=304
	,KW_COND=305
	,KW_OBSERVABLE=306
	,KW_BODY=307
	,KW_HEAD=308
	,KW_STICKY=309
	,KW_FLUENTS=310
	,KW_HIDDEN=311
	,KW_INVARIANT=312
	,KW_AT_LEAST_ONE=313
	,KW_AT_MOST_ONE=314
	,KW_EXACTLY_ONE=315
	,KW_VARIABLE=316
	,KW_OBS_VARIABLE=317
	,KW_VALUES=318
	,KW_SENSING=319
	,KW_DEFAULT_SENSING=320
	,KW_MODEL_FOR=321


#line 283 "/usr/local/lib/bison.cc"
 /* enum token */
     }; /* end of enum declaration */
#endif
public:
 int YY_PDDL_Parser_PARSE (YY_PDDL_Parser_PARSE_PARAM);
 virtual void YY_PDDL_Parser_ERROR(char *msg) YY_PDDL_Parser_ERROR_BODY;
#ifdef YY_PDDL_Parser_PURE
#ifdef YY_PDDL_Parser_LSP_NEEDED
 virtual int  YY_PDDL_Parser_LEX (YY_PDDL_Parser_STYPE *YY_PDDL_Parser_LVAL,YY_PDDL_Parser_LTYPE *YY_PDDL_Parser_LLOC) YY_PDDL_Parser_LEX_BODY;
#else
 virtual int  YY_PDDL_Parser_LEX (YY_PDDL_Parser_STYPE *YY_PDDL_Parser_LVAL) YY_PDDL_Parser_LEX_BODY;
#endif
#else
 virtual int YY_PDDL_Parser_LEX() YY_PDDL_Parser_LEX_BODY;
 YY_PDDL_Parser_STYPE YY_PDDL_Parser_LVAL;
#ifdef YY_PDDL_Parser_LSP_NEEDED
 YY_PDDL_Parser_LTYPE YY_PDDL_Parser_LLOC;
#endif
 int   YY_PDDL_Parser_NERRS;
 int    YY_PDDL_Parser_CHAR;
#endif
#if YY_PDDL_Parser_DEBUG != 0
 int YY_PDDL_Parser_DEBUG_FLAG;   /*  nonzero means print parse trace     */
#endif
public:
 YY_PDDL_Parser_CLASS(YY_PDDL_Parser_CONSTRUCTOR_PARAM);
public:
 YY_PDDL_Parser_MEMBERS 
};
/* other declare folow */
#if YY_PDDL_Parser_USE_CONST_TOKEN != 0

/* #line 314 "/usr/local/lib/bison.cc" */
#line 623 "grammar.cc"
const int YY_PDDL_Parser_CLASS::TK_OPEN=258;
const int YY_PDDL_Parser_CLASS::TK_CLOSE=259;
const int YY_PDDL_Parser_CLASS::TK_OPEN_SQ=260;
const int YY_PDDL_Parser_CLASS::TK_CLOSE_SQ=261;
const int YY_PDDL_Parser_CLASS::TK_EQ=262;
const int YY_PDDL_Parser_CLASS::TK_HYPHEN=263;
const int YY_PDDL_Parser_CLASS::TK_NEW_SYMBOL=264;
const int YY_PDDL_Parser_CLASS::TK_OBJ_SYMBOL=265;
const int YY_PDDL_Parser_CLASS::TK_TYPE_SYMBOL=266;
const int YY_PDDL_Parser_CLASS::TK_PRED_SYMBOL=267;
const int YY_PDDL_Parser_CLASS::TK_VAR_SYMBOL=268;
const int YY_PDDL_Parser_CLASS::TK_ACTION_SYMBOL=269;
const int YY_PDDL_Parser_CLASS::TK_AXIOM_SYMBOL=270;
const int YY_PDDL_Parser_CLASS::TK_SENSOR_SYMBOL=271;
const int YY_PDDL_Parser_CLASS::TK_MISC_SYMBOL=272;
const int YY_PDDL_Parser_CLASS::TK_KEYWORD=273;
const int YY_PDDL_Parser_CLASS::TK_NEW_VAR_SYMBOL=274;
const int YY_PDDL_Parser_CLASS::TK_VARNAME_SYMBOL=275;
const int YY_PDDL_Parser_CLASS::TK_INT=276;
const int YY_PDDL_Parser_CLASS::KW_REQS=277;
const int YY_PDDL_Parser_CLASS::KW_TRANSLATION=278;
const int YY_PDDL_Parser_CLASS::KW_CONSTANTS=279;
const int YY_PDDL_Parser_CLASS::KW_PREDS=280;
const int YY_PDDL_Parser_CLASS::KW_TYPES=281;
const int YY_PDDL_Parser_CLASS::KW_DEFINE=282;
const int YY_PDDL_Parser_CLASS::KW_DOMAIN=283;
const int YY_PDDL_Parser_CLASS::KW_ACTION=284;
const int YY_PDDL_Parser_CLASS::KW_ARGS=285;
const int YY_PDDL_Parser_CLASS::KW_PRE=286;
const int YY_PDDL_Parser_CLASS::KW_EFFECT=287;
const int YY_PDDL_Parser_CLASS::KW_AND=288;
const int YY_PDDL_Parser_CLASS::KW_OR=289;
const int YY_PDDL_Parser_CLASS::KW_EXISTS=290;
const int YY_PDDL_Parser_CLASS::KW_FORALL=291;
const int YY_PDDL_Parser_CLASS::KW_NOT=292;
const int YY_PDDL_Parser_CLASS::KW_WHEN=293;
const int YY_PDDL_Parser_CLASS::KW_ONEOF=294;
const int YY_PDDL_Parser_CLASS::KW_UNKNOWN=295;
const int YY_PDDL_Parser_CLASS::KW_PROBLEM=296;
const int YY_PDDL_Parser_CLASS::KW_FORDOMAIN=297;
const int YY_PDDL_Parser_CLASS::KW_OBJECTS=298;
const int YY_PDDL_Parser_CLASS::KW_INIT=299;
const int YY_PDDL_Parser_CLASS::KW_GOAL=300;
const int YY_PDDL_Parser_CLASS::KW_SENSOR=301;
const int YY_PDDL_Parser_CLASS::KW_SENSE=302;
const int YY_PDDL_Parser_CLASS::KW_OBSERVE=303;
const int YY_PDDL_Parser_CLASS::KW_AXIOM=304;
const int YY_PDDL_Parser_CLASS::KW_COND=305;
const int YY_PDDL_Parser_CLASS::KW_OBSERVABLE=306;
const int YY_PDDL_Parser_CLASS::KW_BODY=307;
const int YY_PDDL_Parser_CLASS::KW_HEAD=308;
const int YY_PDDL_Parser_CLASS::KW_STICKY=309;
const int YY_PDDL_Parser_CLASS::KW_FLUENTS=310;
const int YY_PDDL_Parser_CLASS::KW_HIDDEN=311;
const int YY_PDDL_Parser_CLASS::KW_INVARIANT=312;
const int YY_PDDL_Parser_CLASS::KW_AT_LEAST_ONE=313;
const int YY_PDDL_Parser_CLASS::KW_AT_MOST_ONE=314;
const int YY_PDDL_Parser_CLASS::KW_EXACTLY_ONE=315;
const int YY_PDDL_Parser_CLASS::KW_VARIABLE=316;
const int YY_PDDL_Parser_CLASS::KW_OBS_VARIABLE=317;
const int YY_PDDL_Parser_CLASS::KW_VALUES=318;
const int YY_PDDL_Parser_CLASS::KW_SENSING=319;
const int YY_PDDL_Parser_CLASS::KW_DEFAULT_SENSING=320;
const int YY_PDDL_Parser_CLASS::KW_MODEL_FOR=321;


#line 314 "/usr/local/lib/bison.cc"
 /* const YY_PDDL_Parser_CLASS::token */
#endif
/*apres const  */
YY_PDDL_Parser_CLASS::YY_PDDL_Parser_CLASS(YY_PDDL_Parser_CONSTRUCTOR_PARAM) YY_PDDL_Parser_CONSTRUCTOR_INIT
{
#if YY_PDDL_Parser_DEBUG != 0
YY_PDDL_Parser_DEBUG_FLAG=0;
#endif
YY_PDDL_Parser_CONSTRUCTOR_CODE;
};
#endif

/* #line 325 "/usr/local/lib/bison.cc" */
#line 704 "grammar.cc"


#define	YYFINAL		380
#define	YYFLAG		-32768
#define	YYNTBASE	67

#define YYTRANSLATE(x) ((unsigned)(x) <= 321 ? yytranslate[x] : 165)

static const char yytranslate[] = {     0,
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
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     1,     2,     3,     4,     5,
     6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
    16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
    26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
    36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
    46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
    56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
    66
};

#if YY_PDDL_Parser_DEBUG != 0
static const short yyprhs[] = {     0,
     0,     3,     6,     7,    13,    19,    22,    25,    28,    31,
    34,    37,    38,    43,    45,    47,    49,    51,    53,    55,
    57,    59,    61,    63,    65,    67,    69,    71,    73,    78,
    83,    86,    89,    90,    95,   100,   103,   105,   110,   114,
   116,   118,   119,   121,   126,   130,   133,   135,   137,   139,
   144,   149,   154,   159,   160,   163,   165,   167,   169,   174,
   179,   184,   189,   190,   196,   197,   199,   202,   204,   206,
   208,   210,   212,   214,   216,   217,   224,   229,   235,   239,
   243,   247,   251,   252,   254,   256,   258,   260,   262,   264,
   266,   268,   273,   278,   283,   286,   289,   290,   295,   300,
   301,   302,   312,   313,   314,   324,   327,   329,   332,   334,
   336,   341,   344,   346,   348,   350,   352,   358,   359,   360,
   370,   375,   377,   380,   382,   385,   387,   389,   391,   393,
   394,   397,   399,   401,   403,   404,   405,   415,   422,   432,
   437,   445,   450,   455,   456,   463,   468,   474,   478,   482,
   483,   484,   491,   496,   502,   506,   510,   511,   512,   518,
   523,   526,   528,   530,   532,   533,   539,   544,   545,   552,
   553,   563,   568,   570,   572,   577,   578,   588,   595,   601,
   604,   607,   610,   613,   616,   617,   621,   626,   634,   637,
   639,   641,   643,   645,   647,   649,   654,   659,   664,   669,
   671,   673,   675,   680,   685,   690,   695,   700,   704,   709,
   712,   714,   716
};

static const short yyrhs[] = {    68,
    67,     0,   150,    67,     0,     0,     3,    27,    70,    69,
     4,     0,     3,    27,    70,     1,     4,     0,    69,    75,
     0,    69,    85,     0,    69,    89,     0,    69,    77,     0,
    69,    94,     0,    69,   149,     0,     0,     3,    28,    71,
     4,     0,     9,     0,    10,     0,    11,     0,    12,     0,
    13,     0,    14,     0,    15,     0,    16,     0,    17,     0,
     9,     0,    14,     0,     9,     0,    16,     0,     9,     0,
    15,     0,     3,    22,    76,     4,     0,     3,    22,     1,
     4,     0,    76,    23,     0,    76,    18,     0,     0,     3,
    25,    78,     4,     0,     3,    25,     1,     4,     0,    78,
    79,     0,    79,     0,     3,     9,    80,     4,     0,     3,
     1,     4,     0,    81,     0,    82,     0,     0,    83,     0,
    83,     8,    11,    82,     0,    83,     8,    11,     0,    84,
    83,     0,    84,     0,    19,     0,    13,     0,     3,    26,
    87,     4,     0,     3,    26,    86,     4,     0,    87,     8,
    11,    86,     0,    87,     8,     9,    86,     0,     0,    87,
    88,     0,    88,     0,    11,     0,     9,     0,     3,    24,
    90,     4,     0,     3,    43,    90,     4,     0,     3,    24,
    92,     4,     0,     3,    43,    92,     4,     0,     0,    93,
     8,    11,    91,    90,     0,     0,    93,     0,    93,     9,
     0,     9,     0,    95,     0,   133,     0,   136,     0,   139,
     0,   143,     0,   145,     0,     0,     3,    29,    72,    96,
    97,     4,     0,     3,    29,     1,     4,     0,    97,    30,
     3,    80,     4,     0,    97,    31,    98,     0,    97,    32,
   114,     0,    97,    48,   123,     0,    97,    64,   126,     0,
     0,    99,     0,   104,     0,   105,     0,   106,     0,   109,
     0,   100,     0,   101,     0,   102,     0,     3,    12,   103,
     4,     0,     3,     7,   103,     4,     0,     3,    37,   101,
     4,     0,   103,    13,     0,   103,    10,     0,     0,     3,
    33,   113,     4,     0,     3,    34,   113,     4,     0,     0,
     0,     3,    36,     3,   107,    80,     4,   108,    98,     4,
     0,     0,     0,     3,    35,     3,   110,    80,     4,   111,
    98,     4,     0,   112,    99,     0,    99,     0,   113,    98,
     0,    98,     0,   116,     0,     3,    33,   115,     4,     0,
   115,   116,     0,   116,     0,   124,     0,   117,     0,   118,
     0,     3,    38,    98,   121,     4,     0,     0,     0,     3,
    36,     3,   119,    80,     4,   120,   114,     4,     0,     3,
    33,   122,     4,     0,   124,     0,   122,   124,     0,   124,
     0,   123,   125,     0,   125,     0,   100,     0,   101,     0,
   127,     0,     0,   127,   128,     0,   128,     0,   132,     0,
   129,     0,     0,     0,     3,    36,     3,   130,    80,     4,
   131,   127,     4,     0,     3,    66,    20,   100,    98,     4,
     0,     3,    66,     3,    20,   103,     4,   100,    98,     4,
     0,     3,    61,    20,     4,     0,     3,    61,     3,    20,
   103,     4,     4,     0,     3,    61,     1,     4,     0,     3,
    66,     1,     4,     0,     0,     3,    49,    74,   134,   135,
     4,     0,     3,    49,     1,     4,     0,   135,    30,     3,
    80,     4,     0,   135,    52,    98,     0,   135,    53,   121,
     0,     0,     0,     3,    46,    73,   137,   138,     4,     0,
     3,    46,     1,     4,     0,   138,    30,     3,    80,     4,
     0,   138,    50,    98,     0,   138,    47,   123,     0,     0,
     0,     3,    51,   140,   141,     4,     0,     3,    51,     1,
     4,     0,   141,   142,     0,   142,     0,   125,     0,   118,
     0,     0,     3,    54,   144,   141,     4,     0,     3,    54,
     1,     4,     0,     0,     3,   148,     9,   146,   141,     4,
     0,     0,     3,   148,     3,     9,    80,     4,   147,   141,
     4,     0,     3,    61,     1,     4,     0,    61,     0,    62,
     0,     3,    65,   126,     4,     0,     0,     3,    27,     3,
    41,    71,     4,   151,   152,     4,     0,     3,    27,     3,
    41,     1,     4,     0,   152,     3,    42,    71,     4,     0,
   152,    75,     0,   152,    89,     0,   152,   153,     0,   152,
   163,     0,   152,   164,     0,     0,     3,    44,     4,     0,
     3,    44,   154,     4,     0,     3,    44,     3,    33,   154,
     4,     4,     0,   154,   155,     0,   155,     0,   100,     0,
   159,     0,   160,     0,   161,     0,   162,     0,     3,    57,
   112,     4,     0,     3,    58,   112,     4,     0,     3,    59,
   112,     4,     0,     3,    60,   112,     4,     0,   156,     0,
   157,     0,   158,     0,     3,    34,   112,     4,     0,     3,
    33,   112,     4,     0,     3,    39,   112,     4,     0,     3,
    40,   101,     4,     0,     3,    56,   154,     4,     0,     3,
    56,     4,     0,     3,    45,    98,     4,     0,     0,     0,
     0,     0,     0,   101,     0,   102,     0
};

#endif

#if YY_PDDL_Parser_DEBUG != 0
static const short yyrline[] = { 0,
   121,   123,   124,   127,   129,   135,   137,   138,   139,   140,
   141,   142,   145,   151,   153,   154,   155,   156,   157,   158,
   159,   160,   163,   165,   168,   170,   173,   175,   180,   182,
   188,   190,   191,   196,   198,   204,   206,   209,   218,   224,
   226,   233,   236,   243,   250,   256,   261,   264,   270,   281,
   283,   288,   292,   300,   303,   305,   308,   310,   318,   320,
   321,   322,   325,   330,   330,   333,   339,   344,   352,   354,
   360,   366,   372,   378,   389,   394,   398,   404,   409,   410,
   411,   416,   420,   423,   425,   426,   427,   428,   431,   442,
   444,   447,   460,   471,   478,   486,   490,   493,   500,   507,
   511,   515,   523,   527,   531,   539,   544,   551,   556,   563,
   565,   571,   576,   582,   584,   585,   588,   592,   596,   600,
   608,   613,   616,   621,   627,   632,   638,   642,   646,   648,
   651,   657,   664,   666,   669,   673,   677,   685,   690,   694,
   700,   709,   713,   719,   724,   728,   734,   739,   740,   741,
   744,   749,   753,   759,   764,   767,   771,   774,   780,   781,
   787,   791,   796,   798,   801,   807,   808,   814,   824,   827,
   838,   842,   848,   850,   855,   865,   869,   870,   876,   878,
   879,   880,   881,   882,   883,   886,   888,   889,   892,   898,
   905,   907,   918,   929,   940,   950,   956,   963,   971,   978,
   980,   981,   984,   991,   998,  1005,  1012,  1022,  1033,  1039,
  1044,  1052,  1054
};

static const char * const yytname[] = {   "$","error","$illegal.","TK_OPEN",
"TK_CLOSE","TK_OPEN_SQ","TK_CLOSE_SQ","TK_EQ","TK_HYPHEN","TK_NEW_SYMBOL","TK_OBJ_SYMBOL",
"TK_TYPE_SYMBOL","TK_PRED_SYMBOL","TK_VAR_SYMBOL","TK_ACTION_SYMBOL","TK_AXIOM_SYMBOL",
"TK_SENSOR_SYMBOL","TK_MISC_SYMBOL","TK_KEYWORD","TK_NEW_VAR_SYMBOL","TK_VARNAME_SYMBOL",
"TK_INT","KW_REQS","KW_TRANSLATION","KW_CONSTANTS","KW_PREDS","KW_TYPES","KW_DEFINE",
"KW_DOMAIN","KW_ACTION","KW_ARGS","KW_PRE","KW_EFFECT","KW_AND","KW_OR","KW_EXISTS",
"KW_FORALL","KW_NOT","KW_WHEN","KW_ONEOF","KW_UNKNOWN","KW_PROBLEM","KW_FORDOMAIN",
"KW_OBJECTS","KW_INIT","KW_GOAL","KW_SENSOR","KW_SENSE","KW_OBSERVE","KW_AXIOM",
"KW_COND","KW_OBSERVABLE","KW_BODY","KW_HEAD","KW_STICKY","KW_FLUENTS","KW_HIDDEN",
"KW_INVARIANT","KW_AT_LEAST_ONE","KW_AT_MOST_ONE","KW_EXACTLY_ONE","KW_VARIABLE",
"KW_OBS_VARIABLE","KW_VALUES","KW_SENSING","KW_DEFAULT_SENSING","KW_MODEL_FOR",
"pddl_decls","pddl_domain","domain_elements","domain_name","any_symbol","action_symbol",
"sensor_symbol","axiom_symbol","domain_requires","require_list","domain_predicates",
"predicate_list","predicate_decl","param_list","untyped_param_list","typed_param_list",
"param_sym_list","new_var_symbol","domain_types","typed_type_list","primitive_type_list",
"primitive_type","domain_constants","typed_constant_list","@1","untyped_constant_list",
"constant_sym_list","domain_schemas","action_decl","@2","action_elements","condition",
"single_condition","literal","positive_literal","negative_literal","argument_list",
"and_condition","or_condition","forall_condition","@3","@4","exists_condition",
"@5","@6","single_condition_list","condition_list","action_effect","action_effect_list",
"single_action_effect","conditional_effect","forall_effect","@7","@8","atomic_effect_kw_list",
"atomic_effect_list","positive_atomic_effect_list","atomic_effect","positive_atomic_effect",
"sensing","sensing_decl_list","sensing_decl","forall_sensing","@9","@10","sensing_model",
"axiom_decl","@11","axiom_elements","sensor_decl","@12","sensor_elements","observable_decl",
"@13","fluent_list_decl","fluent_decl","sticky_decl","@14","multivalued_variable_decl",
"@15","@16","multivalued_variable_type","domain_default_sensing","pddl_problem",
"@17","problem_elements","initial_state","init_elements","single_init_element",
"at_least_one_invariant","at_most_one_invariant","exactly_one_invariant","invariant",
"clause","oneof","unknown","hidden_state","goal_spec","goal_spec"
};
#endif

static const short yyr1[] = {     0,
    67,    67,    67,    68,    68,    69,    69,    69,    69,    69,
    69,    69,    70,    71,    71,    71,    71,    71,    71,    71,
    71,    71,    72,    72,    73,    73,    74,    74,    75,    75,
    76,    76,    76,    77,    77,    78,    78,    79,    79,    80,
    80,    80,    81,    82,    82,    83,    83,    84,    84,    85,
    85,    86,    86,    86,    87,    87,    88,    88,    89,    89,
    89,    89,    91,    90,    90,    92,    93,    93,    94,    94,
    94,    94,    94,    94,    96,    95,    95,    97,    97,    97,
    97,    97,    97,    98,    98,    98,    98,    98,    99,   100,
   100,   101,   101,   102,   103,   103,   103,   104,   105,   107,
   108,   106,   110,   111,   109,   112,   112,   113,   113,   114,
   114,   115,   115,   116,   116,   116,   117,   119,   120,   118,
   121,   121,   122,   122,   123,   123,   124,   125,   126,   126,
   127,   127,   128,   128,   130,   131,   129,   132,   132,   132,
   132,   132,   132,   134,   133,   133,   135,   135,   135,   135,
   137,   136,   136,   138,   138,   138,   138,   140,   139,   139,
   141,   141,   142,   142,   144,   143,   143,   146,   145,   147,
   145,   145,   148,   148,   149,   151,   150,   150,   152,   152,
   152,   152,   152,   152,   152,   153,   153,   153,   154,   154,
   155,   155,   155,   155,   155,   156,   156,   157,   158,   159,
   159,   159,   160,    -1,   161,   162,   163,   163,   164,    -1,
    -1,    -1,    -1
};

static const short yyr2[] = {     0,
     2,     2,     0,     5,     5,     2,     2,     2,     2,     2,
     2,     0,     4,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     4,     4,
     2,     2,     0,     4,     4,     2,     1,     4,     3,     1,
     1,     0,     1,     4,     3,     2,     1,     1,     1,     4,
     4,     4,     4,     0,     2,     1,     1,     1,     4,     4,
     4,     4,     0,     5,     0,     1,     2,     1,     1,     1,
     1,     1,     1,     1,     0,     6,     4,     5,     3,     3,
     3,     3,     0,     1,     1,     1,     1,     1,     1,     1,
     1,     4,     4,     4,     2,     2,     0,     4,     4,     0,
     0,     9,     0,     0,     9,     2,     1,     2,     1,     1,
     4,     2,     1,     1,     1,     1,     5,     0,     0,     9,
     4,     1,     2,     1,     2,     1,     1,     1,     1,     0,
     2,     1,     1,     1,     0,     0,     9,     6,     9,     4,
     7,     4,     4,     0,     6,     4,     5,     3,     3,     0,
     0,     6,     4,     5,     3,     3,     0,     0,     5,     4,
     2,     1,     1,     1,     0,     5,     4,     0,     6,     0,
     9,     4,     1,     1,     4,     0,     9,     6,     5,     2,
     2,     2,     2,     2,     0,     3,     4,     7,     2,     1,
     1,     1,     1,     1,     1,     4,     4,     4,     4,     1,
     1,     1,     4,     4,     4,     4,     4,     3,     4,     2,
     1,     1,     1
};

static const short yydefact[] = {     3,
     0,     3,     3,     0,     1,     2,     0,     0,     0,     0,
     0,     0,    14,    15,    16,    17,    18,    19,    20,    21,
    22,     0,     0,     0,     5,     0,     4,     6,     9,     7,
     8,    10,    69,    70,    71,    72,    73,    74,    11,    13,
   178,   176,     0,    65,     0,    54,     0,    65,     0,     0,
     0,     0,     0,   174,   130,     0,   185,     0,     0,    68,
     0,     0,    66,     0,     0,     0,    37,    58,    57,     0,
     0,    56,     0,    23,    24,    75,     0,     0,     0,    25,
    26,   151,     0,    27,    28,   144,     0,     0,     0,     0,
     0,     0,     0,   129,   132,   134,   133,     0,   168,     0,
    30,    29,    32,    31,    59,    61,     0,    67,    35,     0,
    42,    34,    36,    51,    50,     0,    55,    77,    83,    60,
    62,   153,   157,   146,   150,   160,     0,   128,   164,   163,
     0,   162,   167,     0,   172,     0,     0,     0,   175,   131,
    42,     0,     0,   177,   180,   181,   182,   183,   184,    63,
    39,    49,    48,     0,    40,    41,    43,    47,    54,    54,
     0,     0,     0,    97,    97,     0,   159,   161,   166,   135,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,    65,    38,     0,    46,    53,     0,    52,    76,
     0,     0,     0,     0,   130,   152,     0,     0,     0,   145,
     0,     0,     0,     0,     0,   118,    42,   142,    97,   140,
   143,    97,     0,     0,    90,    91,   170,   169,     0,     0,
   186,   191,     0,   190,   200,   201,   202,   192,   193,   194,
   195,     0,     0,    84,    89,    85,    86,    87,    88,     0,
   208,     0,    64,     0,    45,    42,    79,     0,   127,    80,
   110,   115,   116,   114,     0,    81,   126,    82,    42,   156,
   155,    42,   148,     0,   149,   122,    93,    96,    95,    92,
    42,     0,     0,     0,     0,     0,     0,   179,     0,     0,
     0,     0,     0,     0,     0,     0,   187,   189,     0,     0,
     0,     0,   209,   207,    44,     0,     0,     0,     0,   125,
     0,     0,     0,     0,   136,     0,     0,     0,   138,     0,
     0,   107,     0,     0,     0,     0,     0,     0,     0,   109,
     0,     0,   103,   100,    78,     0,     0,   113,     0,   154,
   147,     0,   124,   119,     0,   141,     0,    94,   171,     0,
   203,   106,   205,   206,   196,   197,   198,   199,    98,   108,
    99,    42,    42,   111,   112,     0,   121,   123,     0,     0,
     0,   188,     0,     0,   117,     0,   137,   139,   104,   101,
   120,     0,     0,     0,     0,   105,   102,     0,     0,     0
};

static const short yydefgoto[] = {     5,
     2,    12,     8,    22,    76,    82,    86,    28,    59,    29,
    66,    67,   154,   155,   156,   157,   158,    30,    70,   188,
    72,    31,    61,   183,    62,    63,    32,    33,   119,   161,
   320,   234,   235,   215,   216,   204,   236,   237,   238,   353,
   373,   239,   352,   372,   313,   321,   250,   327,   251,   252,
   129,   271,   359,   265,   332,   256,   254,   130,    93,    94,
    95,    96,   207,   335,    97,    34,   125,   163,    35,   123,
   162,    36,    88,   131,   132,    37,    90,    38,   142,   277,
    56,    39,     3,    57,   100,   147,   223,   224,   225,   226,
   227,   228,   229,   230,   231,   148,   149
};

static const short yypact[] = {    39,
    -8,    39,    39,    46,-32768,-32768,    -1,   183,   278,   258,
    62,   251,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,    70,   111,   122,-32768,   195,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,   148,   124,    86,   161,   115,   124,   217,   159,
   188,   211,   295,-32768,   133,    58,-32768,   140,    11,-32768,
   163,   205,   297,   218,    37,   304,-32768,-32768,-32768,   221,
   254,-32768,   223,-32768,-32768,-32768,   228,   231,   233,-32768,
-32768,-32768,   235,-32768,-32768,-32768,   257,   261,   274,   261,
   299,     3,   349,   133,-32768,-32768,-32768,   273,-32768,   306,
-32768,-32768,-32768,-32768,-32768,-32768,   343,-32768,-32768,   351,
   134,-32768,-32768,-32768,-32768,   187,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,    87,-32768,-32768,-32768,
   308,-32768,-32768,   310,-32768,   353,    80,   136,-32768,-32768,
   134,   261,   157,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,   354,-32768,-32768,   352,   134,   161,   161,
    28,    32,    33,-32768,-32768,   356,-32768,-32768,-32768,-32768,
   357,   337,   358,   359,   345,   361,   362,   312,   278,   314,
   364,   316,   124,-32768,   360,-32768,-32768,   268,-32768,-32768,
   365,   364,   366,   367,   133,-32768,   369,   367,   364,-32768,
   370,   364,   371,   144,   193,-32768,   134,-32768,-32768,-32768,
-32768,-32768,    36,   364,-32768,-32768,-32768,-32768,   372,   171,
-32768,-32768,   318,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,   128,   373,-32768,-32768,-32768,-32768,-32768,-32768,    38,
-32768,   320,-32768,   297,   134,   134,-32768,    81,-32768,-32768,
-32768,-32768,-32768,-32768,    96,   367,-32768,-32768,   134,   367,
-32768,   134,-32768,    19,-32768,-32768,-32768,-32768,-32768,-32768,
   134,   374,   230,   232,   367,   375,   261,-32768,   377,   361,
   361,   367,   361,   361,   361,   361,-32768,-32768,   364,   364,
   378,   379,-32768,-32768,-32768,   352,   380,   382,   364,-32768,
   383,   384,   361,   385,-32768,   386,   361,   387,-32768,   322,
   324,-32768,   326,   328,   388,   330,   332,   334,   336,-32768,
   338,   340,-32768,-32768,-32768,    94,   342,-32768,   371,-32768,
-32768,   344,-32768,-32768,   133,-32768,   364,-32768,-32768,   389,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,   134,   134,-32768,-32768,   390,-32768,-32768,   366,   346,
   391,-32768,   392,   393,-32768,   394,-32768,-32768,-32768,-32768,
-32768,   364,   364,   395,   396,-32768,-32768,   401,   402,-32768
};

static const short yypgoto[] = {   110,
-32768,-32768,-32768,    -3,-32768,-32768,-32768,   275,-32768,-32768,
-32768,   317,  -137,-32768,   141,  -141,-32768,-32768,   192,   363,
   -60,   303,   -38,-32768,   368,   222,-32768,-32768,-32768,-32768,
  -179,   -33,  -152,   -87,-32768,  -144,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,    16,   114,    47,-32768,  -273,-32768,
  -177,-32768,-32768,    78,-32768,   210,  -191,  -176,   215,    76,
   -94,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,   -85,  -125,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,  -174,  -209,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768
};


#define	YYLAST		416


static const short yytable[] = {   140,
   128,   233,   128,   177,   134,   168,    24,   242,   168,    77,
   117,   266,   247,   288,   102,   253,   186,   257,     4,   261,
   205,   257,   263,   214,   328,   164,     9,   222,   103,   222,
   165,   190,   288,   104,   276,   196,   200,   110,   136,    10,
   249,     1,   164,   128,   164,   111,   128,   165,     7,   165,
   249,   303,   168,   355,   128,   275,   178,   191,   192,   193,
    98,   197,   201,   137,   273,    25,    99,   274,   138,   272,
   222,   280,   275,    40,   275,   194,   281,   282,   198,   300,
   171,   199,   172,   300,   202,   203,    64,   164,    65,   222,
   128,   195,   165,   164,   283,   284,   285,   286,   165,   173,
   164,   288,   164,   296,   311,   165,   128,   165,   297,   378,
   128,   333,     6,   298,    41,    73,   166,   275,   299,   329,
   253,   301,   166,    74,   302,    42,   222,   117,    75,   166,
   275,   299,    60,   304,   164,    92,   174,   266,   175,   165,
   358,   350,   350,   101,   243,   249,   152,   267,    58,   253,
   249,   -33,   153,   268,   337,   176,   269,   361,   222,    83,
   289,   290,   291,   292,   275,   -33,   105,    84,   128,    68,
   -33,    69,   128,    85,   249,   219,   249,   164,    43,   249,
    44,   253,   165,    11,   168,   -12,   -12,   308,    87,   128,
  -158,   310,   374,   375,   315,   159,   270,   160,   179,    48,
   180,   181,   268,   279,   280,   269,   249,   275,   106,   281,
   282,    89,   182,  -165,   363,   364,    43,    79,    44,    45,
    46,   109,   128,    47,   114,    80,   118,   283,   284,   285,
   286,   120,    81,   306,   121,   307,   122,    48,   124,   268,
    49,   268,   269,    50,   269,    51,   312,   312,    52,   312,
   312,   312,   312,    26,    27,    53,    54,   115,    23,    55,
   126,   116,    68,   127,    69,   140,    13,    14,    15,    16,
    17,    18,    19,    20,    21,   116,    68,   133,    69,   342,
   342,   141,   342,   342,   342,   342,    13,    14,    15,    16,
    17,    18,    19,    20,    21,    91,   314,  -173,   316,   317,
   318,   319,   135,  -173,   107,   108,    65,   112,   143,   144,
   127,   167,   127,   169,   127,   218,   220,   221,   240,   241,
   240,   287,   240,   294,   127,   339,   240,   340,   213,   341,
   213,   343,   213,   345,   213,   346,   213,   347,   213,   348,
   232,   349,   232,   351,   326,   354,   213,   357,    92,   367,
   187,   189,   139,   150,   151,   170,   209,   184,   206,   185,
   208,   210,   211,   213,   212,   217,   232,   246,   248,   255,
   245,   259,   262,   264,   145,   278,   293,   305,   309,   240,
   323,   324,   113,   325,   326,   295,   330,   331,   334,   336,
   338,   344,   362,   365,   368,   369,   370,   371,   376,   377,
   379,   380,   146,   322,   244,   366,   356,   260,    71,   258,
   360,     0,     0,     0,     0,    78
};

static const short yycheck[] = {    94,
    88,   181,    90,   141,    90,   131,    10,   182,   134,    48,
    71,   203,   192,   223,     4,   193,   158,   194,    27,   199,
   165,   198,   202,   176,   298,     7,    28,   180,    18,   182,
    12,     4,   242,    23,   214,     4,     4,     1,    36,    41,
   193,     3,     7,   131,     7,     9,   134,    12,     3,    12,
   203,    33,   178,   327,   142,    37,   142,    30,    31,    32,
     3,    30,    30,    61,   209,     4,     9,   212,    66,   207,
   223,    34,    37,     4,    37,    48,    39,    40,    47,   256,
     1,    50,     3,   260,    52,    53,     1,     7,     3,   242,
   178,    64,    12,     7,    57,    58,    59,    60,    12,    20,
     7,   311,     7,   245,   279,    12,   194,    12,   246,     0,
   198,   303,     3,    33,     4,     1,    36,    37,    38,   299,
   298,   259,    36,     9,   262,     4,   279,   188,    14,    36,
    37,    38,     9,   271,     7,     3,     1,   329,     3,    12,
   332,   321,   322,     4,   183,   298,    13,     4,     1,   327,
   303,     4,    19,    10,   307,    20,    13,   337,   311,     1,
    33,    34,    35,    36,    37,    18,     4,     9,   256,     9,
    23,    11,   260,    15,   327,   179,   329,     7,    22,   332,
    24,   359,    12,     1,   310,     3,     4,   275,     1,   277,
     3,   277,   372,   373,   282,     9,     4,    11,    42,    43,
    44,    45,    10,    33,    34,    13,   359,    37,     4,    39,
    40,     1,    56,     3,   352,   353,    22,     1,    24,    25,
    26,     4,   310,    29,     4,     9,     4,    57,    58,    59,
    60,     4,    16,     4,     4,     4,     4,    43,     4,    10,
    46,    10,    13,    49,    13,    51,   280,   281,    54,   283,
   284,   285,   286,     3,     4,    61,    62,     4,     1,    65,
     4,     8,     9,     3,    11,   360,     9,    10,    11,    12,
    13,    14,    15,    16,    17,     8,     9,     4,    11,   313,
   314,     9,   316,   317,   318,   319,     9,    10,    11,    12,
    13,    14,    15,    16,    17,     1,   281,     3,   283,   284,
   285,   286,     4,     9,     8,     9,     3,     4,     3,     4,
     3,     4,     3,     4,     3,     4,     3,     4,     3,     4,
     3,     4,     3,     4,     3,     4,     3,     4,     3,     4,
     3,     4,     3,     4,     3,     4,     3,     4,     3,     4,
     3,     4,     3,     4,     3,     4,     3,     4,     3,     4,
   159,   160,     4,    11,     4,     3,    20,     4,     3,     8,
     4,     4,     4,     3,    20,     4,     3,     3,     3,     3,
    11,     3,     3,     3,   100,     4,     4,     4,     4,     3,
     3,     3,    66,     4,     3,   245,     4,     4,     4,     4,
     4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
     0,     0,   100,   290,   183,   359,   329,   198,    46,   195,
   335,    -1,    -1,    -1,    -1,    48
};

#line 325 "/usr/local/lib/bison.cc"
 /* fattrs + tables */

/* parser code folow  */


/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

/* Note: dollar marks section change
   the next  is replaced by the list of actions, each action
   as one case of the switch.  */ 

#if YY_PDDL_Parser_USE_GOTO != 0
/* 
 SUPRESSION OF GOTO : on some C++ compiler (sun c++)
  the goto is strictly forbidden if any constructor/destructor
  is used in the whole function (very stupid isn't it ?)
 so goto are to be replaced with a 'while/switch/case construct'
 here are the macro to keep some apparent compatibility
*/
#define YYGOTO(lb) {yy_gotostate=lb;continue;}
#define YYBEGINGOTO  enum yy_labels yy_gotostate=yygotostart; \
                     for(;;) switch(yy_gotostate) { case yygotostart: {
#define YYLABEL(lb) } case lb: {
#define YYENDGOTO } } 
#define YYBEGINDECLARELABEL enum yy_labels {yygotostart
#define YYDECLARELABEL(lb) ,lb
#define YYENDDECLARELABEL  };
#else
/* macro to keep goto */
#define YYGOTO(lb) goto lb
#define YYBEGINGOTO 
#define YYLABEL(lb) lb:
#define YYENDGOTO
#define YYBEGINDECLARELABEL 
#define YYDECLARELABEL(lb)
#define YYENDDECLARELABEL 
#endif
/* LABEL DECLARATION */
YYBEGINDECLARELABEL
  YYDECLARELABEL(yynewstate)
  YYDECLARELABEL(yybackup)
/* YYDECLARELABEL(yyresume) */
  YYDECLARELABEL(yydefault)
  YYDECLARELABEL(yyreduce)
  YYDECLARELABEL(yyerrlab)   /* here on detecting error */
  YYDECLARELABEL(yyerrlab1)   /* here on error raised explicitly by an action */
  YYDECLARELABEL(yyerrdefault)  /* current state does not do anything special for the error token. */
  YYDECLARELABEL(yyerrpop)   /* pop the current state because it cannot handle the error token */
  YYDECLARELABEL(yyerrhandle)  
YYENDDECLARELABEL
/* ALLOCA SIMULATION */
/* __HAVE_NO_ALLOCA */
#ifdef __HAVE_NO_ALLOCA
int __alloca_free_ptr(char *ptr,char *ref)
{if(ptr!=ref) free(ptr);
 return 0;}

#define __ALLOCA_alloca(size) malloc(size)
#define __ALLOCA_free(ptr,ref) __alloca_free_ptr((char *)ptr,(char *)ref)

#ifdef YY_PDDL_Parser_LSP_NEEDED
#define __ALLOCA_return(num) \
            return( __ALLOCA_free(yyss,yyssa)+\
		    __ALLOCA_free(yyvs,yyvsa)+\
		    __ALLOCA_free(yyls,yylsa)+\
		   (num))
#else
#define __ALLOCA_return(num) \
            return( __ALLOCA_free(yyss,yyssa)+\
		    __ALLOCA_free(yyvs,yyvsa)+\
		   (num))
#endif
#else
#define __ALLOCA_return(num) return(num)
#define __ALLOCA_alloca(size) alloca(size)
#define __ALLOCA_free(ptr,ref) 
#endif

/* ENDALLOCA SIMULATION */

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (YY_PDDL_Parser_CHAR = YYEMPTY)
#define YYEMPTY         -2
#define YYEOF           0
#define YYACCEPT        __ALLOCA_return(0)
#define YYABORT         __ALLOCA_return(1)
#define YYERROR         YYGOTO(yyerrlab1)
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL          YYGOTO(yyerrlab)
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do                                                              \
  if (YY_PDDL_Parser_CHAR == YYEMPTY && yylen == 1)                               \
    { YY_PDDL_Parser_CHAR = (token), YY_PDDL_Parser_LVAL = (value);                 \
      yychar1 = YYTRANSLATE (YY_PDDL_Parser_CHAR);                                \
      YYPOPSTACK;                                               \
      YYGOTO(yybackup);                                            \
    }                                                           \
  else                                                          \
    { YY_PDDL_Parser_ERROR ("syntax error: cannot back up"); YYERROR; }   \
while (0)

#define YYTERROR        1
#define YYERRCODE       256

#ifndef YY_PDDL_Parser_PURE
/* UNPURE */
#define YYLEX           YY_PDDL_Parser_LEX()
#ifndef YY_USE_CLASS
/* If nonreentrant, and not class , generate the variables here */
int     YY_PDDL_Parser_CHAR;                      /*  the lookahead symbol        */
YY_PDDL_Parser_STYPE      YY_PDDL_Parser_LVAL;              /*  the semantic value of the */
				/*  lookahead symbol    */
int YY_PDDL_Parser_NERRS;                 /*  number of parse errors so far */
#ifdef YY_PDDL_Parser_LSP_NEEDED
YY_PDDL_Parser_LTYPE YY_PDDL_Parser_LLOC;   /*  location data for the lookahead     */
			/*  symbol                              */
#endif
#endif


#else
/* PURE */
#ifdef YY_PDDL_Parser_LSP_NEEDED
#define YYLEX           YY_PDDL_Parser_LEX(&YY_PDDL_Parser_LVAL, &YY_PDDL_Parser_LLOC)
#else
#define YYLEX           YY_PDDL_Parser_LEX(&YY_PDDL_Parser_LVAL)
#endif
#endif
#ifndef YY_USE_CLASS
#if YY_PDDL_Parser_DEBUG != 0
int YY_PDDL_Parser_DEBUG_FLAG;                    /*  nonzero means print parse trace     */
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif
#endif



/*  YYINITDEPTH indicates the initial size of the parser's stacks       */

#ifndef YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif


#if __GNUC__ > 1                /* GNU C and GNU C++ define this.  */
#define __yy_bcopy(FROM,TO,COUNT)       __builtin_memcpy(TO,FROM,COUNT)
#else                           /* not GNU C or C++ */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */

#ifdef __cplusplus
static void __yy_bcopy (char *from, char *to, int count)
#else
#ifdef __STDC__
static void __yy_bcopy (char *from, char *to, int count)
#else
static void __yy_bcopy (from, to, count)
     char *from;
     char *to;
     int count;
#endif
#endif
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}
#endif

int
#ifdef YY_USE_CLASS
 YY_PDDL_Parser_CLASS::
#endif
     YY_PDDL_Parser_PARSE(YY_PDDL_Parser_PARSE_PARAM)
#ifndef __STDC__
#ifndef __cplusplus
#ifndef YY_USE_CLASS
/* parameter definition without protypes */
YY_PDDL_Parser_PARSE_PARAM_DEF
#endif
#endif
#endif
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YY_PDDL_Parser_STYPE *yyvsp;
  int yyerrstatus;      /*  number of tokens to shift before error messages enabled */
  int yychar1=0;          /*  lookahead token as an internal (translated) token number */

  short yyssa[YYINITDEPTH];     /*  the state stack                     */
  YY_PDDL_Parser_STYPE yyvsa[YYINITDEPTH];        /*  the semantic value stack            */

  short *yyss = yyssa;          /*  refer to the stacks thru separate pointers */
  YY_PDDL_Parser_STYPE *yyvs = yyvsa;     /*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YY_PDDL_Parser_LSP_NEEDED
  YY_PDDL_Parser_LTYPE yylsa[YYINITDEPTH];        /*  the location stack                  */
  YY_PDDL_Parser_LTYPE *yyls = yylsa;
  YY_PDDL_Parser_LTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;

#ifdef YY_PDDL_Parser_PURE
  int YY_PDDL_Parser_CHAR;
  YY_PDDL_Parser_STYPE YY_PDDL_Parser_LVAL;
  int YY_PDDL_Parser_NERRS;
#ifdef YY_PDDL_Parser_LSP_NEEDED
  YY_PDDL_Parser_LTYPE YY_PDDL_Parser_LLOC;
#endif
#endif

  YY_PDDL_Parser_STYPE yyval;             /*  the variable used to return         */
				/*  semantic values from the action     */
				/*  routines                            */

  int yylen;
/* start loop, in which YYGOTO may be used. */
YYBEGINGOTO

#if YY_PDDL_Parser_DEBUG != 0
  if (YY_PDDL_Parser_DEBUG_FLAG)
    fprintf(stderr, "Starting parse\n");
#endif
  yystate = 0;
  yyerrstatus = 0;
  YY_PDDL_Parser_NERRS = 0;
  YY_PDDL_Parser_CHAR = YYEMPTY;          /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YY_PDDL_Parser_LSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
YYLABEL(yynewstate)

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YY_PDDL_Parser_STYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YY_PDDL_Parser_LSP_NEEDED
      YY_PDDL_Parser_LTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YY_PDDL_Parser_LSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YY_PDDL_Parser_LSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  YY_PDDL_Parser_ERROR("parser stack overflow");
	  __ALLOCA_return(2);
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
      yyss = (short *) __ALLOCA_alloca (yystacksize * sizeof (*yyssp));
      __yy_bcopy ((char *)yyss1, (char *)yyss, size * sizeof (*yyssp));
      __ALLOCA_free(yyss1,yyssa);
      yyvs = (YY_PDDL_Parser_STYPE *) __ALLOCA_alloca (yystacksize * sizeof (*yyvsp));
      __yy_bcopy ((char *)yyvs1, (char *)yyvs, size * sizeof (*yyvsp));
      __ALLOCA_free(yyvs1,yyvsa);
#ifdef YY_PDDL_Parser_LSP_NEEDED
      yyls = (YY_PDDL_Parser_LTYPE *) __ALLOCA_alloca (yystacksize * sizeof (*yylsp));
      __yy_bcopy ((char *)yyls1, (char *)yyls, size * sizeof (*yylsp));
      __ALLOCA_free(yyls1,yylsa);
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YY_PDDL_Parser_LSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YY_PDDL_Parser_DEBUG != 0
      if (YY_PDDL_Parser_DEBUG_FLAG)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YY_PDDL_Parser_DEBUG != 0
  if (YY_PDDL_Parser_DEBUG_FLAG)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  YYGOTO(yybackup);
YYLABEL(yybackup)

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* YYLABEL(yyresume) */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    YYGOTO(yydefault);

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (YY_PDDL_Parser_CHAR == YYEMPTY)
    {
#if YY_PDDL_Parser_DEBUG != 0
      if (YY_PDDL_Parser_DEBUG_FLAG)
	fprintf(stderr, "Reading a token: ");
#endif
      YY_PDDL_Parser_CHAR = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (YY_PDDL_Parser_CHAR <= 0)           /* This means end of input. */
    {
      yychar1 = 0;
      YY_PDDL_Parser_CHAR = YYEOF;                /* Don't call YYLEX any more */

#if YY_PDDL_Parser_DEBUG != 0
      if (YY_PDDL_Parser_DEBUG_FLAG)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(YY_PDDL_Parser_CHAR);

#if YY_PDDL_Parser_DEBUG != 0
      if (YY_PDDL_Parser_DEBUG_FLAG)
	{
	  fprintf (stderr, "Next token is %d (%s", YY_PDDL_Parser_CHAR, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, YY_PDDL_Parser_CHAR, YY_PDDL_Parser_LVAL);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    YYGOTO(yydefault);

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	YYGOTO(yyerrlab);
      yyn = -yyn;
      YYGOTO(yyreduce);
    }
  else if (yyn == 0)
    YYGOTO(yyerrlab);

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YY_PDDL_Parser_DEBUG != 0
  if (YY_PDDL_Parser_DEBUG_FLAG)
    fprintf(stderr, "Shifting token %d (%s), ", YY_PDDL_Parser_CHAR, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (YY_PDDL_Parser_CHAR != YYEOF)
    YY_PDDL_Parser_CHAR = YYEMPTY;

  *++yyvsp = YY_PDDL_Parser_LVAL;
#ifdef YY_PDDL_Parser_LSP_NEEDED
  *++yylsp = YY_PDDL_Parser_LLOC;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  YYGOTO(yynewstate);

/* Do the default action for the current state.  */
YYLABEL(yydefault)

  yyn = yydefact[yystate];
  if (yyn == 0)
    YYGOTO(yyerrlab);

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
YYLABEL(yyreduce)
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YY_PDDL_Parser_DEBUG != 0
  if (YY_PDDL_Parser_DEBUG_FLAG)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


/* #line 811 "/usr/local/lib/bison.cc" */
#line 1651 "grammar.cc"

  switch (yyn) {

case 5:
#line 129 "ppddl.y"
{
          log_error((char*)"syntax error in domain");
          yyerrok;
      ;
    break;}
case 13:
#line 146 "ppddl.y"
{ domain_name_ = yyvsp[-1].sym->text; ;
    break;}
case 14:
#line 152 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 15:
#line 153 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 16:
#line 154 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 17:
#line 155 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 18:
#line 156 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 19:
#line 157 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 20:
#line 158 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 21:
#line 159 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 22:
#line 160 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 23:
#line 164 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 24:
#line 165 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 25:
#line 169 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 26:
#line 170 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 27:
#line 174 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 28:
#line 175 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 30:
#line 182 "ppddl.y"
{
          log_error((char*)"syntax error in requirements declaration.");
          yyerrok;
      ;
    break;}
case 31:
#line 189 "ppddl.y"
{ declare_lw1_translation(); ;
    break;}
case 35:
#line 198 "ppddl.y"
{
          log_error((char*)"syntax error in (:predicates ...)");
          yyerrok;
      ;
    break;}
case 38:
#line 210 "ppddl.y"
{
          PredicateSymbol *p = new PredicateSymbol(yyvsp[-2].sym->text);
          dom_predicates_.push_back(p);
          p->param_ = *yyvsp[-1].vparam;
          delete yyvsp[-1].vparam;
          clear_param(p->param_);
          yyvsp[-2].sym->val = p;
      ;
    break;}
case 39:
#line 218 "ppddl.y"
{
          log_error((char*)"syntax error in predicate declaration");
          yyerrok;
      ;
    break;}
case 41:
#line 226 "ppddl.y"
{
          // must reverse parameter list
          var_symbol_vec tmp_list(*yyvsp[0].vparam);
          yyvsp[0].vparam->clear();
          yyvsp[0].vparam->insert(yyvsp[0].vparam->end(), tmp_list.rbegin(), tmp_list.rend());
          yyval.vparam = yyvsp[0].vparam;
      ;
    break;}
case 42:
#line 233 "ppddl.y"
{ yyval.vparam = new var_symbol_vec; ;
    break;}
case 43:
#line 237 "ppddl.y"
{
          set_variable_type(*yyvsp[0].vparam, yyvsp[0].vparam->size(), dom_top_type_);
          yyval.vparam = yyvsp[0].vparam;
      ;
    break;}
case 44:
#line 244 "ppddl.y"
{
          set_variable_type(*yyvsp[-3].vparam, yyvsp[-3].vparam->size(), static_cast<TypeSymbol*>(yyvsp[-1].sym->val));
          yyvsp[0].vparam->insert(yyvsp[0].vparam->end(), yyvsp[-3].vparam->begin(), yyvsp[-3].vparam->end());
          delete yyvsp[-3].vparam;
          yyval.vparam = yyvsp[0].vparam;
      ;
    break;}
case 45:
#line 250 "ppddl.y"
{
          set_variable_type(*yyvsp[-2].vparam, yyvsp[-2].vparam->size(), static_cast<TypeSymbol*>(yyvsp[0].sym->val));
          yyval.vparam = yyvsp[-2].vparam;
      ;
    break;}
case 46:
#line 257 "ppddl.y"
{
          yyvsp[0].vparam->push_back(static_cast<VariableSymbol*>(yyvsp[-1].vsym));
          yyval.vparam = yyvsp[0].vparam;
      ;
    break;}
case 47:
#line 261 "ppddl.y"
{ yyval.vparam = new var_symbol_vec; yyval.vparam->push_back(yyvsp[0].vsym); ;
    break;}
case 48:
#line 265 "ppddl.y"
{
          VariableSymbol *var = new VariableSymbol(yyvsp[0].sym->text);
          yyvsp[0].sym->val = var;
          yyval.vsym = var;
      ;
    break;}
case 49:
#line 270 "ppddl.y"
{
          std::string msg("variable '");
          msg += yyvsp[0].sym->text;
          msg += "' shadows variable in outer scope: this is not supported!";
          log_error((char*)msg.c_str());
          yyerrok;
      ;
    break;}
case 51:
#line 283 "ppddl.y"
{
          set_type_type(dom_types_, dom_types_.size(), dom_top_type_);
      ;
    break;}
case 52:
#line 289 "ppddl.y"
{
          set_type_type(dom_types_, dom_types_.size(), static_cast<TypeSymbol*>(yyvsp[-1].sym->val));
      ;
    break;}
case 53:
#line 292 "ppddl.y"
{
          yyvsp[-1].sym->val = new TypeSymbol(yyvsp[-1].sym->text);
          if( write_warnings_ )
              std::cout << Utils::warning() << "assuming " << yyvsp[-1].sym->text << " - object" << std::endl;
          static_cast<TypeSymbol*>(yyvsp[-1].sym->val)->sym_type_ = dom_top_type_;
          set_type_type(dom_types_, dom_types_.size(), static_cast<TypeSymbol*>(yyvsp[-1].sym->val));
          dom_types_.push_back(static_cast<TypeSymbol*>(yyvsp[-1].sym->val));
      ;
    break;}
case 56:
#line 305 "ppddl.y"
{ ;
    break;}
case 58:
#line 310 "ppddl.y"
{
          yyvsp[0].sym->val = new TypeSymbol(yyvsp[0].sym->text);
          dom_types_.push_back(static_cast<TypeSymbol*>(yyvsp[0].sym->val));
      ;
    break;}
case 63:
#line 326 "ppddl.y"
{
          set_constant_type(dom_constants_, dom_constants_.size(), static_cast<TypeSymbol*>(yyvsp[0].sym->val));
      ;
    break;}
case 66:
#line 334 "ppddl.y"
{
          set_constant_type(dom_constants_, dom_constants_.size(), dom_top_type_);
      ;
    break;}
case 67:
#line 340 "ppddl.y"
{
          yyvsp[0].sym->val = new Symbol(yyvsp[0].sym->text);
          dom_constants_.push_back(static_cast<Symbol*>(yyvsp[0].sym->val));
      ;
    break;}
case 68:
#line 344 "ppddl.y"
{
          yyvsp[0].sym->val = new Symbol(yyvsp[0].sym->text);
          dom_constants_.push_back(static_cast<Symbol*>(yyvsp[0].sym->val));
      ;
    break;}
case 70:
#line 354 "ppddl.y"
{
          if( type_ == replanner ) {
              log_error((char*)"':axiom' is not a valid element in k-replanner.");
              yyerrok;
          }
      ;
    break;}
case 71:
#line 360 "ppddl.y"
{
          if( type_ == cp2fsc ) {
              log_error((char*)"':sensor' is not a valid element in cp2fsc.");
              yyerrok;
          }
      ;
    break;}
case 72:
#line 366 "ppddl.y"
{
          if( type_ == replanner ) {
              log_error((char*)"':observable' is not a valid element in k-replanner.");
              yyerrok;
          }
      ;
    break;}
case 73:
#line 372 "ppddl.y"
{
          if( type_ == replanner ) {
              log_error((char*)"':sticky' is not a valid element in k-replanner.");
              yyerrok;
          }
      ;
    break;}
case 74:
#line 378 "ppddl.y"
{
          declare_lw1_translation();
          if( type_ == cp2fsc ) {
              log_error((char*)"':sensor' is not a valid element in cp2fsc.");
              yyerrok;
          }
      ;
    break;}
case 75:
#line 390 "ppddl.y"
{
          Action *na = new Action(yyvsp[0].sym->text);
          dom_actions_.push_back(na);
      ;
    break;}
case 76:
#line 394 "ppddl.y"
{
          clear_param(dom_actions_.back()->param_);
          yyvsp[-3].sym->val = dom_actions_.back();
      ;
    break;}
case 77:
#line 398 "ppddl.y"
{
          log_error((char*)"syntax error in action declaration");
          yyerrok;
      ;
    break;}
case 78:
#line 405 "ppddl.y"
{
          dom_actions_.back()->param_ = *yyvsp[-1].vparam;
          delete yyvsp[-1].vparam;
      ;
    break;}
case 79:
#line 409 "ppddl.y"
{ dom_actions_.back()->precondition_ = yyvsp[0].condition; ;
    break;}
case 80:
#line 410 "ppddl.y"
{ dom_actions_.back()->effect_ = yyvsp[0].effect; ;
    break;}
case 81:
#line 411 "ppddl.y"
{
          declare_clg_translation();
          dom_actions_.back()->observe_ = new AndEffect(*yyvsp[0].effect_vec);
          delete yyvsp[0].effect_vec;
      ;
    break;}
case 82:
#line 416 "ppddl.y"
{
          declare_lw1_translation();
          dom_actions_.back()->sensing_proxy_ = yyvsp[0].sensing_proxy_list;
      ;
    break;}
case 89:
#line 432 "ppddl.y"
{
          // if literal is for equality, construct EQ
          if( yyvsp[0].atom->pred_ == dom_eq_pred_ )
              yyval.condition = new EQ(dynamic_cast<VariableSymbol*>(yyvsp[0].atom->param_[0]), dynamic_cast<VariableSymbol*>(yyvsp[0].atom->param_[1]), yyvsp[0].atom->negated_);
          else
              yyval.condition = new Literal(*yyvsp[0].atom);
          delete yyvsp[0].atom;
      ;
    break;}
case 92:
#line 448 "ppddl.y"
{
          PredicateSymbol* p = static_cast<PredicateSymbol*>(yyvsp[-2].sym->val);
          if( p->param_.size() != yyvsp[-1].param->size() ) {
              std::ostringstream msg;
              msg << "wrong number of arguments for predicate '" << p->print_name_ << "'";
              log_error(const_cast<char*>(msg.str().c_str()));
          } else {
              yyval.atom = new Atom(p);
              yyval.atom->param_ = *yyvsp[-1].param;
              delete yyvsp[-1].param;
          }
      ;
    break;}
case 93:
#line 460 "ppddl.y"
{
          if( yyvsp[-1].param->size() != 2 ) {
              log_error((char*)"wrong number of arguments for equality");
          } else {
              yyval.atom = new Atom(dom_eq_pred_);
              yyval.atom->param_ = *yyvsp[-1].param;
              delete yyvsp[-1].param;
          }
      ;
    break;}
case 94:
#line 472 "ppddl.y"
{
          const_cast<Literal*>(static_cast<const Literal*>(yyvsp[-1].atom))->negated_ = true;
          yyval.atom = yyvsp[-1].atom;
      ;
    break;}
case 95:
#line 479 "ppddl.y"
{
          if( yyvsp[0].sym->val == 0 )
              log_error((char*)"undeclared variable in atom args list");
          else
              yyvsp[-1].param->push_back(static_cast<VariableSymbol*>(yyvsp[0].sym->val));
          yyval.param = yyvsp[-1].param;
      ;
    break;}
case 96:
#line 486 "ppddl.y"
{
          yyvsp[-1].param->push_back(static_cast<Symbol*>(yyvsp[0].sym->val));
          yyval.param = yyvsp[-1].param;
      ;
    break;}
case 97:
#line 490 "ppddl.y"
{ yyval.param = new PDDL_Base::symbol_vec; ;
    break;}
case 98:
#line 494 "ppddl.y"
{
          yyval.condition = new And(*yyvsp[-1].condition_vec);
          delete yyvsp[-1].condition_vec;
      ;
    break;}
case 99:
#line 501 "ppddl.y"
{
          yyval.condition = new Or(*yyvsp[-1].condition_vec);
          delete yyvsp[-1].condition_vec;
      ;
    break;}
case 100:
#line 508 "ppddl.y"
{
          forall_conditions_.push_back(new ForallCondition);
      ;
    break;}
case 101:
#line 511 "ppddl.y"
{
          forall_conditions_.back()->param_ = *yyvsp[-1].vparam;
          delete yyvsp[-1].vparam;
      ;
    break;}
case 102:
#line 515 "ppddl.y"
{
          forall_conditions_.back()->condition_ = yyvsp[-1].condition;
          clear_param(forall_conditions_.back()->param_);
          yyval.condition = forall_conditions_.back();
          forall_conditions_.pop_back();
      ;
    break;}
case 103:
#line 524 "ppddl.y"
{
          exists_conditions_.push_back(new ExistsCondition);
      ;
    break;}
case 104:
#line 527 "ppddl.y"
{
          exists_conditions_.back()->param_ = *yyvsp[-1].vparam;
          delete yyvsp[-1].vparam;
      ;
    break;}
case 105:
#line 531 "ppddl.y"
{
          exists_conditions_.back()->condition_ = yyvsp[-1].condition;
          clear_param(exists_conditions_.back()->param_);
          yyval.condition = exists_conditions_.back();
          exists_conditions_.pop_back();
      ;
    break;}
case 106:
#line 540 "ppddl.y"
{
          yyvsp[-1].condition_vec->push_back(yyvsp[0].condition);
          yyval.condition_vec = yyvsp[-1].condition_vec;
      ;
    break;}
case 107:
#line 544 "ppddl.y"
{
          condition_vec *cond_vec = new condition_vec;
          cond_vec->push_back(yyvsp[0].condition);
          yyval.condition_vec = cond_vec;
      ;
    break;}
case 108:
#line 552 "ppddl.y"
{
          yyvsp[-1].condition_vec->push_back(yyvsp[0].condition);
          yyval.condition_vec = yyvsp[-1].condition_vec;
      ;
    break;}
case 109:
#line 556 "ppddl.y"
{
          condition_vec *cond_vec = new condition_vec;
          cond_vec->push_back(yyvsp[0].condition);
          yyval.condition_vec = cond_vec;
      ;
    break;}
case 111:
#line 565 "ppddl.y"
{
          yyval.effect = new AndEffect(*yyvsp[-1].effect_vec);
          delete yyvsp[-1].effect_vec;
      ;
    break;}
case 112:
#line 572 "ppddl.y"
{
          yyvsp[-1].effect_vec->push_back(yyvsp[0].effect);
          yyval.effect_vec = yyvsp[-1].effect_vec;
      ;
    break;}
case 113:
#line 576 "ppddl.y"
{
          yyval.effect_vec = new effect_vec;
          yyval.effect_vec->push_back(yyvsp[0].effect);
      ;
    break;}
case 117:
#line 589 "ppddl.y"
{ yyval.effect = new ConditionalEffect(yyvsp[-2].condition, yyvsp[-1].effect); ;
    break;}
case 118:
#line 593 "ppddl.y"
{
          forall_effects_.push_back(new ForallEffect);
      ;
    break;}
case 119:
#line 596 "ppddl.y"
{
          forall_effects_.back()->param_ = *yyvsp[-1].vparam;
          delete yyvsp[-1].vparam;
      ;
    break;}
case 120:
#line 600 "ppddl.y"
{
          forall_effects_.back()->effect_ = yyvsp[-1].effect;
          clear_param(forall_effects_.back()->param_);
          yyval.effect = forall_effects_.back();
          forall_effects_.pop_back();
      ;
    break;}
case 121:
#line 609 "ppddl.y"
{
          yyval.effect = new AndEffect(*yyvsp[-1].effect_vec);
          delete yyvsp[-1].effect_vec;
      ;
    break;}
case 123:
#line 617 "ppddl.y"
{
          yyvsp[-1].effect_vec->push_back(yyvsp[0].effect);
          yyval.effect_vec = yyvsp[-1].effect_vec;
      ;
    break;}
case 124:
#line 621 "ppddl.y"
{
          yyval.effect_vec = new effect_vec;
          yyval.effect_vec->push_back(yyvsp[0].effect);
      ;
    break;}
case 125:
#line 628 "ppddl.y"
{
          yyvsp[-1].effect_vec->push_back(yyvsp[0].effect);
          yyval.effect_vec = yyvsp[-1].effect_vec;
      ;
    break;}
case 126:
#line 632 "ppddl.y"
{
          yyval.effect_vec = new effect_vec;
          yyval.effect_vec->push_back(yyvsp[0].effect);
      ;
    break;}
case 127:
#line 639 "ppddl.y"
{ yyval.effect = new AtomicEffect(*yyvsp[0].atom); delete yyvsp[0].atom; ;
    break;}
case 128:
#line 643 "ppddl.y"
{ yyval.effect = new AtomicEffect(*yyvsp[0].atom); delete yyvsp[0].atom; ;
    break;}
case 130:
#line 648 "ppddl.y"
{ yyval.sensing_proxy_list = 0; ;
    break;}
case 131:
#line 652 "ppddl.y"
{
          sensing_proxy_vec *list_sensing_proxy = const_cast<sensing_proxy_vec*>(yyvsp[-1].sensing_proxy_list);
          list_sensing_proxy->push_back(yyvsp[0].sensing_proxy);
          yyval.sensing_proxy_list = list_sensing_proxy;
      ;
    break;}
case 132:
#line 657 "ppddl.y"
{
          sensing_proxy_vec *list_sensing_proxy = new sensing_proxy_vec;
          list_sensing_proxy->push_back(yyvsp[0].sensing_proxy);
          yyval.sensing_proxy_list = list_sensing_proxy;
      ;
    break;}
case 133:
#line 665 "ppddl.y"
{ yyval.sensing_proxy = new BasicSensingModel(yyvsp[0].sensing_model); ;
    break;}
case 135:
#line 670 "ppddl.y"
{
          forall_sensing_.push_back(new ForallSensing);
      ;
    break;}
case 136:
#line 673 "ppddl.y"
{
          forall_sensing_.back()->param_ = *yyvsp[-1].vparam;
          delete yyvsp[-1].vparam;
      ;
    break;}
case 137:
#line 677 "ppddl.y"
{
          forall_sensing_.back()->sensing_ = *yyvsp[-1].sensing_proxy_list;
          clear_param(forall_sensing_.back()->param_);
          yyval.sensing_proxy = forall_sensing_.back();
          forall_sensing_.pop_back();
      ;
    break;}
case 138:
#line 686 "ppddl.y"
{
          /* NEW_SENSING: need to verify that literal is value of value */
          yyval.sensing_model = new SensingModelForObservableVariable(new Literal(*yyvsp[-2].atom), yyvsp[-1].condition);
      ;
    break;}
case 139:
#line 690 "ppddl.y"
{
          /* NEW_SENSING: need to verify that literal is value of value */
          yyval.sensing_model = new SensingModelForObservableVariable(new Literal(*yyvsp[-2].atom), yyvsp[-1].condition);
      ;
    break;}
case 140:
#line 694 "ppddl.y"
{
          assert(static_cast<Symbol*>(yyvsp[-1].sym->val)->sym_class_ == sym_varname);
          const Variable *variable = static_cast<Variable*>(yyvsp[-1].sym->val);
          assert(dynamic_cast<const StateVariable*>(variable) != 0);
          yyval.sensing_model = new SensingModelForStateVariable(static_cast<const StateVariable*>(variable));
      ;
    break;}
case 141:
#line 700 "ppddl.y"
{
          assert(static_cast<Symbol*>(yyvsp[-3].sym->val)->sym_class_ == sym_varname);
          const Variable *variable = static_cast<Variable*>(yyvsp[-3].sym->val);
          assert(dynamic_cast<const StateVariable*>(variable) != 0);
          SensingModelForStateVariable *sensing_model = new SensingModelForStateVariable(static_cast<const StateVariable*>(variable));
          sensing_model->param_ = *yyvsp[-2].param;
          delete yyvsp[-2].param;
          yyval.sensing_model = sensing_model;
      ;
    break;}
case 142:
#line 709 "ppddl.y"
{
          log_error((char*)"syntax error in sensing declaration for ':variable'");
          yyerrok;
      ;
    break;}
case 143:
#line 713 "ppddl.y"
{
          log_error((char*)"syntax error in sensing declaration for ':model-for'");
          yyerrok;
      ;
    break;}
case 144:
#line 720 "ppddl.y"
{
          Axiom *nr = new Axiom(yyvsp[0].sym->text);
          dom_axioms_.push_back(nr);
      ;
    break;}
case 145:
#line 724 "ppddl.y"
{
          clear_param(dom_axioms_.back()->param_);
          yyvsp[-3].sym->val = dom_axioms_.back();
      ;
    break;}
case 146:
#line 728 "ppddl.y"
{
          log_error((char*)"syntax error in axiom declaration");
          yyerrok;
      ;
    break;}
case 147:
#line 735 "ppddl.y"
{
          dom_axioms_.back()->param_ = *yyvsp[-1].vparam;
          delete yyvsp[-1].vparam;
      ;
    break;}
case 148:
#line 739 "ppddl.y"
{ dom_axioms_.back()->body_ = yyvsp[0].condition; ;
    break;}
case 149:
#line 740 "ppddl.y"
{ dom_axioms_.back()->head_ = yyvsp[0].effect; ;
    break;}
case 151:
#line 745 "ppddl.y"
{
          Sensor *nr = new Sensor(yyvsp[0].sym->text);
          dom_sensors_.push_back(nr);
      ;
    break;}
case 152:
#line 749 "ppddl.y"
{
          clear_param(dom_sensors_.back()->param_);
          yyvsp[-3].sym->val = dom_sensors_.back();
      ;
    break;}
case 153:
#line 753 "ppddl.y"
{
          log_error((char*)"syntax error in sensor declaration");
          yyerrok;
      ;
    break;}
case 154:
#line 760 "ppddl.y"
{
          dom_sensors_.back()->param_ = *yyvsp[-1].vparam;
          delete yyvsp[-1].vparam;
      ;
    break;}
case 155:
#line 764 "ppddl.y"
{
          dom_sensors_.back()->condition_ = yyvsp[0].condition;
      ;
    break;}
case 156:
#line 767 "ppddl.y"
{
          dom_sensors_.back()->sense_ = new AndEffect(*yyvsp[0].effect_vec);
          delete yyvsp[0].effect_vec;
      ;
    break;}
case 158:
#line 775 "ppddl.y"
{
          Observable *obs = new Observable;
          dom_observables_.push_back(obs);
          effect_vec_ptr_ = &obs->observables_;
      ;
    break;}
case 160:
#line 781 "ppddl.y"
{
          log_error((char*)"syntax error in observable declaration");
          yyerrok;
      ;
    break;}
case 161:
#line 788 "ppddl.y"
{
          effect_vec_ptr_->push_back(yyvsp[0].effect);
      ;
    break;}
case 162:
#line 791 "ppddl.y"
{
          effect_vec_ptr_->push_back(yyvsp[0].effect);
      ;
    break;}
case 165:
#line 802 "ppddl.y"
{
          Sticky *sticky = new Sticky;
          dom_stickies_.push_back(sticky);
          effect_vec_ptr_ = &sticky->stickies_;
      ;
    break;}
case 167:
#line 808 "ppddl.y"
{
          log_error((char*)"syntax error in sticky declaration");
          yyerrok;
      ;
    break;}
case 168:
#line 815 "ppddl.y"
{
          Variable *var = 0;
          if( yyvsp[-1].ival == 0 )
              var = new StateVariable(yyvsp[0].sym->text);
          else
              var = new ObsVariable(yyvsp[0].sym->text);
          multivalued_variables_.push_back(var);
          effect_vec_ptr_ = &var->values_;
      ;
    break;}
case 169:
#line 824 "ppddl.y"
{
          yyvsp[-3].sym->val = multivalued_variables_.back();
      ;
    break;}
case 170:
#line 827 "ppddl.y"
{
          Variable *var = 0;
          if( yyvsp[-4].ival == 0 )
              var = new StateVariable(yyvsp[-2].sym->text);
          else
              var = new ObsVariable(yyvsp[-2].sym->text);
          var->param_ = *yyvsp[-1].vparam;
          delete yyvsp[-1].vparam;
          multivalued_variables_.push_back(var);
          effect_vec_ptr_ = &var->values_;
      ;
    break;}
case 171:
#line 838 "ppddl.y"
{
          clear_param(multivalued_variables_.back()->param_);
          yyvsp[-5].sym->val = multivalued_variables_.back();
      ;
    break;}
case 172:
#line 842 "ppddl.y"
{
          log_error((char*)"syntax error in state variable declaration");
          yyerrok;
      ;
    break;}
case 173:
#line 849 "ppddl.y"
{ yyval.ival = 0; ;
    break;}
case 174:
#line 850 "ppddl.y"
{ yyval.ival = 1; ;
    break;}
case 175:
#line 856 "ppddl.y"
{
          declare_lw1_translation();
          default_sensing_proxy_ = yyvsp[-1].sensing_proxy_list;
      ;
    break;}
case 176:
#line 866 "ppddl.y"
{
          problem_name_ = yyvsp[-1].sym->text;
      ;
    break;}
case 178:
#line 870 "ppddl.y"
{
          log_error((char*)"syntax error in problem definition.");
          yyerrok;
      ;
    break;}
case 187:
#line 888 "ppddl.y"
{ dom_init_ = *yyvsp[-1].ilist; delete yyvsp[-1].ilist; ;
    break;}
case 188:
#line 889 "ppddl.y"
{ dom_init_ = *yyvsp[-2].ilist; delete yyvsp[-2].ilist; ;
    break;}
case 189:
#line 893 "ppddl.y"
{
          init_element_vec *ilist = const_cast<init_element_vec*>(yyvsp[-1].ilist);
          if( yyvsp[0].ielem != 0 ) ilist->push_back(const_cast<InitElement*>(yyvsp[0].ielem));
          yyval.ilist = ilist;
      ;
    break;}
case 190:
#line 898 "ppddl.y"
{
          init_element_vec *ilist = new init_element_vec;
          if( yyvsp[0].ielem != 0 ) ilist->push_back(const_cast<InitElement*>(yyvsp[0].ielem));
          yyval.ilist = ilist;
      ;
    break;}
case 191:
#line 906 "ppddl.y"
{ yyval.ielem = new InitLiteral(*yyvsp[0].atom); ;
    break;}
case 192:
#line 907 "ppddl.y"
{
          if( type_ == cp2fsc ) {
              log_error((char*)"'invariant' is not a valid element in cp2fsc.");
              delete yyvsp[0].invariant;
              yyerrok;
          } else {
              yyval.ielem = new InitInvariant(*yyvsp[0].invariant);
              const_cast<Invariant*>(yyvsp[0].invariant)->clear();
              delete yyvsp[0].invariant;
          }
      ;
    break;}
case 193:
#line 918 "ppddl.y"
{
          if( type_ == replanner ) {
              // We let oneofs pass in k-replanner as they are later mapped 
              // into invariants of type at-least-one. This is to support
              // CLG compatibility mode.
              declare_clg_translation();
          }
          yyval.ielem = new InitClause(*yyvsp[0].clause);
          const_cast<Clause*>(yyvsp[0].clause)->clear();
          delete yyvsp[0].clause;
      ;
    break;}
case 194:
#line 929 "ppddl.y"
{
          if( type_ == replanner ) {
              // We let oneofs pass in k-replanner as they are later mapped 
              // into invariants of type exactly-one. This is to support
              // CLG compatibility mode.
              declare_clg_translation();
          }
          yyval.ielem = new InitOneof(*yyvsp[0].oneof);
          const_cast<Oneof*>(yyvsp[0].oneof)->clear();
          delete yyvsp[0].oneof;
      ;
    break;}
case 195:
#line 940 "ppddl.y"
{
          yyval.ielem = 0; // when fixing this, remove condition '$2 != 0' and '$1 != 0' above (in single_init_element)
          std::cout << Utils::warning()
                    << Utils::magenta() << "(clg) ignoring '" << yyvsp[0].unknown->to_string() << "'"
                    << Utils::normal() << std::endl;
          //$$ = new InitUnknown(*$1);
          delete yyvsp[0].unknown;
      ;
    break;}
case 196:
#line 951 "ppddl.y"
{
          //$$ = new Invariant(Invariant::AT_LEAST_ONE, *static_cast<const And*>($3));
          yyval.invariant = new Invariant(Invariant::AT_LEAST_ONE, *yyvsp[-1].condition_vec);
          delete yyvsp[-1].condition_vec;
      ;
    break;}
case 197:
#line 956 "ppddl.y"
{
          //$$ = new Invariant(Invariant::AT_LEAST_ONE, *static_cast<const And*>($3));
          yyval.invariant = new Invariant(Invariant::AT_LEAST_ONE, *yyvsp[-1].condition_vec);
          delete yyvsp[-1].condition_vec;
      ;
    break;}
case 198:
#line 964 "ppddl.y"
{
          //$$ = new Invariant(Invariant::AT_MOST_ONE, *static_cast<const And*>($3));
          yyval.invariant = new Invariant(Invariant::AT_MOST_ONE, *yyvsp[-1].condition_vec);
          delete yyvsp[-1].condition_vec;
      ;
    break;}
case 199:
#line 972 "ppddl.y"
{
          yyval.invariant = new Invariant(Invariant::EXACTLY_ONE, *yyvsp[-1].condition_vec);
          delete yyvsp[-1].condition_vec;
      ;
    break;}
case 203:
#line 985 "ppddl.y"
{
          yyval.clause = new Clause(*yyvsp[-1].condition_vec);
          delete yyvsp[-1].condition_vec;
      ;
    break;}
case 204:
#line 992 "ppddl.y"
{
          yyval.condition = new And(*yyvsp[-1].condition_vec);
          delete yyvsp[-1].condition_vec;
      ;
    break;}
case 205:
#line 999 "ppddl.y"
{
          yyval.oneof = new Oneof(*yyvsp[-1].condition_vec);
          delete yyvsp[-1].condition_vec;
      ;
    break;}
case 206:
#line 1006 "ppddl.y"
{
          yyval.unknown = new Unknown(*yyvsp[-1].atom);
          delete yyvsp[-1].atom;
      ;
    break;}
case 207:
#line 1013 "ppddl.y"
{
          if( type_ == cp2fsc ) {
              log_error((char*)"':hidden' is not a valid element in cp2fsc.");
              yyerrok;
          } else {
              dom_hidden_.push_back(*yyvsp[-1].ilist);
              delete yyvsp[-1].ilist;
          }
      ;
    break;}
case 208:
#line 1022 "ppddl.y"
{
          if( type_ == cp2fsc ) {
              log_error((char*)"':hidden' is not a valid element in cp2fsc.");
              yyerrok;
          } else {
              init_element_vec hidden;
              dom_hidden_.push_back(hidden);
          }
      ;
    break;}
case 209:
#line 1034 "ppddl.y"
{ dom_goal_ = yyvsp[-1].condition; ;
    break;}
case 210:
#line 1040 "ppddl.y"
{
          const_cast<And*>(static_cast<const And*>(yyvsp[-1].condition))->push_back(yyvsp[0].condition);
          yyval.condition = yyvsp[-1].condition;
      ;
    break;}
case 211:
#line 1044 "ppddl.y"
{
          And *cond = new And;
          cond->push_back(yyvsp[0].condition);
          yyval.condition = cond;
      ;
    break;}
case 212:
#line 1053 "ppddl.y"
{ yyval.condition = new Literal(*yyvsp[0].atom); delete yyvsp[0].atom; ;
    break;}
case 213:
#line 1054 "ppddl.y"
{ yyval.condition = new Literal(*yyvsp[0].atom); delete yyvsp[0].atom; ;
    break;}
}

#line 811 "/usr/local/lib/bison.cc"
   /* the action file gets copied in in place of this dollarsign  */
  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YY_PDDL_Parser_LSP_NEEDED
  yylsp -= yylen;
#endif

#if YY_PDDL_Parser_DEBUG != 0
  if (YY_PDDL_Parser_DEBUG_FLAG)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YY_PDDL_Parser_LSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = YY_PDDL_Parser_LLOC.first_line;
      yylsp->first_column = YY_PDDL_Parser_LLOC.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  YYGOTO(yynewstate);

YYLABEL(yyerrlab)   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++YY_PDDL_Parser_NERRS;

#ifdef YY_PDDL_Parser_ERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      YY_PDDL_Parser_ERROR(msg);
	      free(msg);
	    }
	  else
	    YY_PDDL_Parser_ERROR ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YY_PDDL_Parser_ERROR_VERBOSE */
	YY_PDDL_Parser_ERROR("parse error");
    }

  YYGOTO(yyerrlab1);
YYLABEL(yyerrlab1)   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (YY_PDDL_Parser_CHAR == YYEOF)
	YYABORT;

#if YY_PDDL_Parser_DEBUG != 0
      if (YY_PDDL_Parser_DEBUG_FLAG)
	fprintf(stderr, "Discarding token %d (%s).\n", YY_PDDL_Parser_CHAR, yytname[yychar1]);
#endif

      YY_PDDL_Parser_CHAR = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;              /* Each real token shifted decrements this */

  YYGOTO(yyerrhandle);

YYLABEL(yyerrdefault)  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) YYGOTO(yydefault);
#endif

YYLABEL(yyerrpop)   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YY_PDDL_Parser_LSP_NEEDED
  yylsp--;
#endif

#if YY_PDDL_Parser_DEBUG != 0
  if (YY_PDDL_Parser_DEBUG_FLAG)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

YYLABEL(yyerrhandle)

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    YYGOTO(yyerrdefault);

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    YYGOTO(yyerrdefault);

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	YYGOTO(yyerrpop);
      yyn = -yyn;
      YYGOTO(yyreduce);
    }
  else if (yyn == 0)
    YYGOTO(yyerrpop);

  if (yyn == YYFINAL)
    YYACCEPT;

#if YY_PDDL_Parser_DEBUG != 0
  if (YY_PDDL_Parser_DEBUG_FLAG)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = YY_PDDL_Parser_LVAL;
#ifdef YY_PDDL_Parser_LSP_NEEDED
  *++yylsp = YY_PDDL_Parser_LLOC;
#endif

  yystate = yyn;
  YYGOTO(yynewstate);
/* end loop, in which YYGOTO may be used. */
  YYENDGOTO
}

/* END */

/* #line 1010 "/usr/local/lib/bison.cc" */
#line 2912 "grammar.cc"
#line 1057 "ppddl.y"


