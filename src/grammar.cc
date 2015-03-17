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
#define	KW_TRUE	289
#define	KW_FALSE	290
#define	KW_OR	291
#define	KW_EXISTS	292
#define	KW_FORALL	293
#define	KW_SUCH_THAT	294
#define	KW_NOT	295
#define	KW_WHEN	296
#define	KW_ONEOF	297
#define	KW_UNKNOWN	298
#define	KW_PROBLEM	299
#define	KW_FORDOMAIN	300
#define	KW_OBJECTS	301
#define	KW_INIT	302
#define	KW_GOAL	303
#define	KW_SENSOR	304
#define	KW_SENSE	305
#define	KW_OBSERVE	306
#define	KW_AXIOM	307
#define	KW_COND	308
#define	KW_OBSERVABLE	309
#define	KW_BODY	310
#define	KW_HEAD	311
#define	KW_STICKY	312
#define	KW_FLUENTS	313
#define	KW_HIDDEN	314
#define	KW_INVARIANT	315
#define	KW_AT_LEAST_ONE	316
#define	KW_AT_MOST_ONE	317
#define	KW_EXACTLY_ONE	318
#define	KW_VARIABLE	319
#define	KW_OBS_VARIABLE	320
#define	KW_VALUES	321
#define	KW_SENSING	322
#define	KW_DEFAULT_SENSING	323
#define	KW_MODEL_FOR	324


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
#line 452 "grammar.cc"
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
static const int KW_TRUE;
static const int KW_FALSE;
static const int KW_OR;
static const int KW_EXISTS;
static const int KW_FORALL;
static const int KW_SUCH_THAT;
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
#line 528 "grammar.cc"
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
	,KW_TRUE=289
	,KW_FALSE=290
	,KW_OR=291
	,KW_EXISTS=292
	,KW_FORALL=293
	,KW_SUCH_THAT=294
	,KW_NOT=295
	,KW_WHEN=296
	,KW_ONEOF=297
	,KW_UNKNOWN=298
	,KW_PROBLEM=299
	,KW_FORDOMAIN=300
	,KW_OBJECTS=301
	,KW_INIT=302
	,KW_GOAL=303
	,KW_SENSOR=304
	,KW_SENSE=305
	,KW_OBSERVE=306
	,KW_AXIOM=307
	,KW_COND=308
	,KW_OBSERVABLE=309
	,KW_BODY=310
	,KW_HEAD=311
	,KW_STICKY=312
	,KW_FLUENTS=313
	,KW_HIDDEN=314
	,KW_INVARIANT=315
	,KW_AT_LEAST_ONE=316
	,KW_AT_MOST_ONE=317
	,KW_EXACTLY_ONE=318
	,KW_VARIABLE=319
	,KW_OBS_VARIABLE=320
	,KW_VALUES=321
	,KW_SENSING=322
	,KW_DEFAULT_SENSING=323
	,KW_MODEL_FOR=324


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
#line 632 "grammar.cc"
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
const int YY_PDDL_Parser_CLASS::KW_TRUE=289;
const int YY_PDDL_Parser_CLASS::KW_FALSE=290;
const int YY_PDDL_Parser_CLASS::KW_OR=291;
const int YY_PDDL_Parser_CLASS::KW_EXISTS=292;
const int YY_PDDL_Parser_CLASS::KW_FORALL=293;
const int YY_PDDL_Parser_CLASS::KW_SUCH_THAT=294;
const int YY_PDDL_Parser_CLASS::KW_NOT=295;
const int YY_PDDL_Parser_CLASS::KW_WHEN=296;
const int YY_PDDL_Parser_CLASS::KW_ONEOF=297;
const int YY_PDDL_Parser_CLASS::KW_UNKNOWN=298;
const int YY_PDDL_Parser_CLASS::KW_PROBLEM=299;
const int YY_PDDL_Parser_CLASS::KW_FORDOMAIN=300;
const int YY_PDDL_Parser_CLASS::KW_OBJECTS=301;
const int YY_PDDL_Parser_CLASS::KW_INIT=302;
const int YY_PDDL_Parser_CLASS::KW_GOAL=303;
const int YY_PDDL_Parser_CLASS::KW_SENSOR=304;
const int YY_PDDL_Parser_CLASS::KW_SENSE=305;
const int YY_PDDL_Parser_CLASS::KW_OBSERVE=306;
const int YY_PDDL_Parser_CLASS::KW_AXIOM=307;
const int YY_PDDL_Parser_CLASS::KW_COND=308;
const int YY_PDDL_Parser_CLASS::KW_OBSERVABLE=309;
const int YY_PDDL_Parser_CLASS::KW_BODY=310;
const int YY_PDDL_Parser_CLASS::KW_HEAD=311;
const int YY_PDDL_Parser_CLASS::KW_STICKY=312;
const int YY_PDDL_Parser_CLASS::KW_FLUENTS=313;
const int YY_PDDL_Parser_CLASS::KW_HIDDEN=314;
const int YY_PDDL_Parser_CLASS::KW_INVARIANT=315;
const int YY_PDDL_Parser_CLASS::KW_AT_LEAST_ONE=316;
const int YY_PDDL_Parser_CLASS::KW_AT_MOST_ONE=317;
const int YY_PDDL_Parser_CLASS::KW_EXACTLY_ONE=318;
const int YY_PDDL_Parser_CLASS::KW_VARIABLE=319;
const int YY_PDDL_Parser_CLASS::KW_OBS_VARIABLE=320;
const int YY_PDDL_Parser_CLASS::KW_VALUES=321;
const int YY_PDDL_Parser_CLASS::KW_SENSING=322;
const int YY_PDDL_Parser_CLASS::KW_DEFAULT_SENSING=323;
const int YY_PDDL_Parser_CLASS::KW_MODEL_FOR=324;


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
#line 716 "grammar.cc"


#define	YYFINAL		388
#define	YYFLAG		-32768
#define	YYNTBASE	70

#define YYTRANSLATE(x) ((unsigned)(x) <= 324 ? yytranslate[x] : 170)

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
    66,    67,    68,    69
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
   266,   268,   270,   272,   274,   279,   284,   289,   292,   295,
   296,   301,   306,   307,   308,   318,   319,   320,   330,   333,
   335,   338,   340,   342,   347,   350,   352,   354,   356,   358,
   364,   365,   366,   376,   381,   383,   386,   388,   391,   393,
   395,   397,   399,   400,   403,   405,   407,   409,   411,   412,
   413,   423,   429,   436,   446,   451,   459,   464,   469,   470,
   477,   482,   488,   492,   496,   497,   498,   505,   510,   516,
   520,   524,   525,   526,   532,   537,   540,   542,   544,   546,
   547,   553,   558,   559,   566,   567,   577,   582,   584,   586,
   591,   592,   602,   609,   615,   618,   621,   624,   627,   630,
   631,   635,   640,   648,   651,   653,   655,   657,   659,   661,
   663,   668,   673,   678,   683,   685,   687,   689,   694,   699,
   704,   709,   713,   718,   721,   723,   725
};

static const short yyrhs[] = {    71,
    70,     0,   155,    70,     0,     0,     3,    27,    73,    72,
     4,     0,     3,    27,    73,     1,     4,     0,    72,    78,
     0,    72,    88,     0,    72,    92,     0,    72,    80,     0,
    72,    97,     0,    72,   154,     0,     0,     3,    28,    74,
     4,     0,     9,     0,    10,     0,    11,     0,    12,     0,
    13,     0,    14,     0,    15,     0,    16,     0,    17,     0,
     9,     0,    14,     0,     9,     0,    16,     0,     9,     0,
    15,     0,     3,    22,    79,     4,     0,     3,    22,     1,
     4,     0,    79,    23,     0,    79,    18,     0,     0,     3,
    25,    81,     4,     0,     3,    25,     1,     4,     0,    81,
    82,     0,    82,     0,     3,     9,    83,     4,     0,     3,
     1,     4,     0,    84,     0,    85,     0,     0,    86,     0,
    86,     8,    11,    85,     0,    86,     8,    11,     0,    87,
    86,     0,    87,     0,    19,     0,    13,     0,     3,    26,
    90,     4,     0,     3,    26,    89,     4,     0,    90,     8,
    11,    89,     0,    90,     8,     9,    89,     0,     0,    90,
    91,     0,    91,     0,    11,     0,     9,     0,     3,    24,
    93,     4,     0,     3,    46,    93,     4,     0,     3,    24,
    95,     4,     0,     3,    46,    95,     4,     0,     0,    96,
     8,    11,    94,    93,     0,     0,    96,     0,    96,     9,
     0,     9,     0,    98,     0,   138,     0,   141,     0,   144,
     0,   148,     0,   150,     0,     0,     3,    29,    75,    99,
   100,     4,     0,     3,    29,     1,     4,     0,   100,    30,
     3,    83,     4,     0,   100,    31,   101,     0,   100,    32,
   118,     0,   100,    51,   127,     0,   100,    67,   130,     0,
     0,   102,     0,   103,     0,   108,     0,   109,     0,   110,
     0,   113,     0,    34,     0,    35,     0,   104,     0,   105,
     0,   106,     0,     3,    12,   107,     4,     0,     3,     7,
   107,     4,     0,     3,    40,   105,     4,     0,   107,    13,
     0,   107,    10,     0,     0,     3,    33,   117,     4,     0,
     3,    36,   117,     4,     0,     0,     0,     3,    38,     3,
   111,    83,     4,   112,   101,     4,     0,     0,     0,     3,
    37,     3,   114,    83,     4,   115,   101,     4,     0,   116,
   103,     0,   103,     0,   117,   101,     0,   101,     0,   120,
     0,     3,    33,   119,     4,     0,   119,   120,     0,   120,
     0,   128,     0,   121,     0,   122,     0,     3,    41,   101,
   125,     4,     0,     0,     0,     3,    38,     3,   123,    83,
     4,   124,   118,     4,     0,     3,    33,   126,     4,     0,
   128,     0,   126,   128,     0,   128,     0,   127,   129,     0,
   129,     0,   104,     0,   105,     0,   131,     0,     0,   131,
   132,     0,   132,     0,   137,     0,   133,     0,   136,     0,
     0,     0,     3,    38,     3,   134,    83,     4,   135,   131,
     4,     0,     3,    39,   101,   131,     4,     0,     3,    69,
    20,   104,   101,     4,     0,     3,    69,     3,    20,   107,
     4,   104,   101,     4,     0,     3,    64,    20,     4,     0,
     3,    64,     3,    20,   107,     4,     4,     0,     3,    64,
     1,     4,     0,     3,    69,     1,     4,     0,     0,     3,
    52,    77,   139,   140,     4,     0,     3,    52,     1,     4,
     0,   140,    30,     3,    83,     4,     0,   140,    55,   101,
     0,   140,    56,   125,     0,     0,     0,     3,    49,    76,
   142,   143,     4,     0,     3,    49,     1,     4,     0,   143,
    30,     3,    83,     4,     0,   143,    53,   101,     0,   143,
    50,   127,     0,     0,     0,     3,    54,   145,   146,     4,
     0,     3,    54,     1,     4,     0,   146,   147,     0,   147,
     0,   129,     0,   122,     0,     0,     3,    57,   149,   146,
     4,     0,     3,    57,     1,     4,     0,     0,     3,   153,
     9,   151,   146,     4,     0,     0,     3,   153,     3,     9,
    83,     4,   152,   146,     4,     0,     3,    64,     1,     4,
     0,    64,     0,    65,     0,     3,    68,   130,     4,     0,
     0,     3,    27,     3,    44,    74,     4,   156,   157,     4,
     0,     3,    27,     3,    44,     1,     4,     0,   157,     3,
    45,    74,     4,     0,   157,    78,     0,   157,    92,     0,
   157,   158,     0,   157,   168,     0,   157,   169,     0,     0,
     3,    47,     4,     0,     3,    47,   159,     4,     0,     3,
    47,     3,    33,   159,     4,     4,     0,   159,   160,     0,
   160,     0,   104,     0,   164,     0,   165,     0,   166,     0,
   167,     0,     3,    60,   116,     4,     0,     3,    61,   116,
     4,     0,     3,    62,   116,     4,     0,     3,    63,   116,
     4,     0,   161,     0,   162,     0,   163,     0,     3,    36,
   116,     4,     0,     3,    42,   116,     4,     0,     3,    43,
   105,     4,     0,     3,    59,   159,     4,     0,     3,    59,
     4,     0,     3,    48,   101,     4,     0,     0,     0,     0,
     0,     0,   105,     0,   106,     0
};

#endif

#if YY_PDDL_Parser_DEBUG != 0
static const short yyrline[] = { 0,
   120,   122,   123,   126,   128,   134,   136,   137,   138,   139,
   140,   141,   144,   150,   152,   153,   154,   155,   156,   157,
   158,   159,   162,   164,   167,   169,   172,   174,   179,   181,
   187,   189,   190,   195,   197,   203,   205,   208,   217,   223,
   225,   232,   235,   242,   249,   255,   260,   263,   269,   280,
   282,   287,   291,   299,   302,   304,   307,   309,   317,   319,
   320,   321,   324,   329,   329,   332,   338,   343,   351,   353,
   359,   365,   371,   377,   388,   393,   397,   403,   408,   409,
   410,   415,   419,   422,   424,   425,   426,   427,   428,   431,
   433,   436,   447,   449,   452,   465,   476,   483,   491,   495,
   498,   505,   512,   516,   520,   528,   532,   536,   544,   549,
   556,   561,   568,   570,   576,   581,   587,   589,   590,   593,
   597,   601,   605,   613,   618,   621,   626,   632,   637,   643,
   647,   651,   653,   656,   662,   669,   671,   672,   675,   679,
   683,   692,   701,   714,   729,   735,   744,   748,   754,   759,
   763,   769,   774,   775,   776,   779,   784,   788,   794,   799,
   802,   806,   809,   815,   816,   822,   826,   831,   833,   836,
   842,   843,   849,   859,   862,   873,   877,   883,   885,   890,
   900,   904,   905,   911,   913,   914,   915,   916,   917,   918,
   921,   923,   924,   927,   933,   940,   942,   953,   964,   975,
   985,   991,   998,  1006,  1013,  1015,  1016,  1019,  1026,  1033,
  1040,  1050,  1061,  1067,  1072,  1080,  1082
};

static const char * const yytname[] = {   "$","error","$illegal.","TK_OPEN",
"TK_CLOSE","TK_OPEN_SQ","TK_CLOSE_SQ","TK_EQ","TK_HYPHEN","TK_NEW_SYMBOL","TK_OBJ_SYMBOL",
"TK_TYPE_SYMBOL","TK_PRED_SYMBOL","TK_VAR_SYMBOL","TK_ACTION_SYMBOL","TK_AXIOM_SYMBOL",
"TK_SENSOR_SYMBOL","TK_MISC_SYMBOL","TK_KEYWORD","TK_NEW_VAR_SYMBOL","TK_VARNAME_SYMBOL",
"TK_INT","KW_REQS","KW_TRANSLATION","KW_CONSTANTS","KW_PREDS","KW_TYPES","KW_DEFINE",
"KW_DOMAIN","KW_ACTION","KW_ARGS","KW_PRE","KW_EFFECT","KW_AND","KW_TRUE","KW_FALSE",
"KW_OR","KW_EXISTS","KW_FORALL","KW_SUCH_THAT","KW_NOT","KW_WHEN","KW_ONEOF",
"KW_UNKNOWN","KW_PROBLEM","KW_FORDOMAIN","KW_OBJECTS","KW_INIT","KW_GOAL","KW_SENSOR",
"KW_SENSE","KW_OBSERVE","KW_AXIOM","KW_COND","KW_OBSERVABLE","KW_BODY","KW_HEAD",
"KW_STICKY","KW_FLUENTS","KW_HIDDEN","KW_INVARIANT","KW_AT_LEAST_ONE","KW_AT_MOST_ONE",
"KW_EXACTLY_ONE","KW_VARIABLE","KW_OBS_VARIABLE","KW_VALUES","KW_SENSING","KW_DEFAULT_SENSING",
"KW_MODEL_FOR","pddl_decls","pddl_domain","domain_elements","domain_name","any_symbol",
"action_symbol","sensor_symbol","axiom_symbol","domain_requires","require_list",
"domain_predicates","predicate_list","predicate_decl","param_list","untyped_param_list",
"typed_param_list","param_sym_list","new_var_symbol","domain_types","typed_type_list",
"primitive_type_list","primitive_type","domain_constants","typed_constant_list",
"@1","untyped_constant_list","constant_sym_list","domain_schemas","action_decl",
"@2","action_elements","condition","constant_condition","single_condition","literal",
"positive_literal","negative_literal","argument_list","and_condition","or_condition",
"forall_condition","@3","@4","exists_condition","@5","@6","single_condition_list",
"condition_list","action_effect","action_effect_list","single_action_effect",
"conditional_effect","forall_effect","@7","@8","atomic_effect_kw_list","atomic_effect_list",
"positive_atomic_effect_list","atomic_effect","positive_atomic_effect","sensing",
"sensing_decl_list","sensing_decl","forall_sensing","@9","@10","such_that_sensing",
"sensing_model","axiom_decl","@11","axiom_elements","sensor_decl","@12","sensor_elements",
"observable_decl","@13","fluent_list_decl","fluent_decl","sticky_decl","@14",
"multivalued_variable_decl","@15","@16","multivalued_variable_type","domain_default_sensing",
"pddl_problem","@17","problem_elements","initial_state","init_elements","single_init_element",
"at_least_one_invariant","at_most_one_invariant","exactly_one_invariant","invariant",
"clause","oneof","unknown","hidden_state","goal_spec",""
};
#endif

static const short yyr1[] = {     0,
    70,    70,    70,    71,    71,    72,    72,    72,    72,    72,
    72,    72,    73,    74,    74,    74,    74,    74,    74,    74,
    74,    74,    75,    75,    76,    76,    77,    77,    78,    78,
    79,    79,    79,    80,    80,    81,    81,    82,    82,    83,
    83,    83,    84,    85,    85,    86,    86,    87,    87,    88,
    88,    89,    89,    89,    90,    90,    91,    91,    92,    92,
    92,    92,    94,    93,    93,    95,    96,    96,    97,    97,
    97,    97,    97,    97,    99,    98,    98,   100,   100,   100,
   100,   100,   100,   101,   101,   101,   101,   101,   101,   102,
   102,   103,   104,   104,   105,   105,   106,   107,   107,   107,
   108,   109,   111,   112,   110,   114,   115,   113,   116,   116,
   117,   117,   118,   118,   119,   119,   120,   120,   120,   121,
   123,   124,   122,   125,   125,   126,   126,   127,   127,   128,
   129,   130,   130,   131,   131,   132,   132,   132,   134,   135,
   133,   136,   137,   137,   137,   137,   137,   137,   139,   138,
   138,   140,   140,   140,   140,   142,   141,   141,   143,   143,
   143,   143,   145,   144,   144,   146,   146,   147,   147,   149,
   148,   148,   151,   150,   152,   150,   150,   153,   153,   154,
   156,   155,   155,   157,   157,   157,   157,   157,   157,   157,
   158,   158,   158,   159,   159,   160,   160,   160,   160,   160,
   161,   161,   162,   163,   164,   164,   164,   165,   166,   167,
   168,   168,   169,    -1,    -1,    -1,    -1
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
     1,     1,     1,     1,     4,     4,     4,     2,     2,     0,
     4,     4,     0,     0,     9,     0,     0,     9,     2,     1,
     2,     1,     1,     4,     2,     1,     1,     1,     1,     5,
     0,     0,     9,     4,     1,     2,     1,     2,     1,     1,
     1,     1,     0,     2,     1,     1,     1,     1,     0,     0,
     9,     5,     6,     9,     4,     7,     4,     4,     0,     6,
     4,     5,     3,     3,     0,     0,     6,     4,     5,     3,
     3,     0,     0,     5,     4,     2,     1,     1,     1,     0,
     5,     4,     0,     6,     0,     9,     4,     1,     1,     4,
     0,     9,     6,     5,     2,     2,     2,     2,     2,     0,
     3,     4,     7,     2,     1,     1,     1,     1,     1,     1,
     4,     4,     4,     4,     1,     1,     1,     4,     4,     4,
     4,     3,     4,     2,     1,     1,     1
};

static const short yydefact[] = {     3,
     0,     3,     3,     0,     1,     2,     0,     0,     0,     0,
     0,     0,    14,    15,    16,    17,    18,    19,    20,    21,
    22,     0,     0,     0,     5,     0,     4,     6,     9,     7,
     8,    10,    69,    70,    71,    72,    73,    74,    11,    13,
   183,   181,     0,    65,     0,    54,     0,    65,     0,     0,
     0,     0,     0,   179,   133,     0,   190,     0,     0,    68,
     0,     0,    66,     0,     0,     0,    37,    58,    57,     0,
     0,    56,     0,    23,    24,    75,     0,     0,     0,    25,
    26,   156,     0,    27,    28,   149,     0,     0,     0,     0,
     0,     0,     0,   132,   135,   137,   138,   136,     0,   173,
     0,    30,    29,    32,    31,    59,    61,     0,    67,    35,
     0,    42,    34,    36,    51,    50,     0,    55,    77,    83,
    60,    62,   158,   162,   151,   155,   165,     0,   131,   169,
   168,     0,   167,   172,     0,   177,     0,     0,     0,     0,
   180,   134,    42,     0,     0,   182,   185,   186,   187,   188,
   189,    63,    39,    49,    48,     0,    40,    41,    43,    47,
    54,    54,     0,     0,     0,   100,   100,     0,   164,   166,
   171,   139,     0,    90,    91,     0,    84,    85,    92,    93,
    94,    86,    87,    88,    89,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,    65,    38,     0,
    46,    53,     0,    52,    76,     0,     0,     0,     0,   133,
   157,     0,     0,     0,   150,     0,     0,     0,     0,     0,
   121,    42,     0,     0,     0,     0,     0,     0,   147,   100,
   145,   148,   100,     0,     0,   175,   174,     0,     0,   191,
   196,     0,   195,   205,   206,   207,   197,   198,   199,   200,
     0,     0,   212,     0,    64,     0,    45,    42,    79,     0,
   130,    80,   113,   118,   119,   117,     0,    81,   129,    82,
    42,   161,   160,    42,   153,     0,   154,   125,    96,    99,
    98,    95,    42,     0,   112,     0,     0,   106,   103,     0,
   142,     0,     0,     0,     0,   184,     0,     0,     0,     0,
     0,     0,     0,     0,   192,   194,   213,   211,    44,     0,
     0,     0,     0,   128,     0,     0,     0,     0,   140,   101,
   111,   102,    42,    42,    97,     0,     0,   143,     0,     0,
   110,     0,     0,     0,     0,     0,     0,     0,    78,     0,
     0,   116,     0,   159,   152,     0,   127,   122,     0,     0,
     0,   146,     0,   176,     0,   208,   109,   209,   210,   201,
   202,   203,   204,   114,   115,     0,   124,   126,     0,     0,
   107,   104,     0,   193,   120,     0,   141,     0,     0,   144,
   123,     0,     0,   108,   105,     0,     0,     0
};

static const short yydefgoto[] = {     5,
     2,    12,     8,    22,    76,    82,    86,    28,    59,    29,
    66,    67,   156,   157,   158,   159,   160,    30,    70,   203,
    72,    31,    61,   198,    62,    63,    32,    33,   120,   163,
   285,   177,   178,   179,   180,   181,   219,   182,   183,   184,
   324,   379,   185,   323,   378,   332,   286,   262,   341,   263,
   264,   130,   283,   369,   277,   346,   268,   266,   131,    93,
    94,    95,    96,   222,   349,    97,    98,    34,   126,   165,
    35,   124,   164,    36,    88,   132,   133,    37,    90,    38,
   144,   295,    56,    39,     3,    57,   101,   149,   242,   243,
   244,   245,   246,   247,   248,   249,   250,   150,   151
};

static const short yypact[] = {    21,
   -10,    21,    21,    41,-32768,-32768,    10,   208,   284,   246,
    71,   146,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,    83,    87,   103,-32768,   175,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,    18,   112,   134,   187,   209,   112,   265,    96,
   251,   302,   301,-32768,   180,    34,-32768,   168,    17,-32768,
   188,   218,   229,   222,    46,   287,-32768,-32768,-32768,   237,
   303,-32768,   244,-32768,-32768,-32768,   268,   271,   305,-32768,
-32768,-32768,   357,-32768,-32768,-32768,   358,   360,   361,   360,
   362,    26,   363,   180,-32768,-32768,-32768,-32768,   355,-32768,
   316,-32768,-32768,-32768,-32768,-32768,-32768,   359,-32768,-32768,
   364,   157,-32768,-32768,-32768,-32768,   297,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,   120,-32768,-32768,
-32768,   318,-32768,-32768,   320,-32768,   366,   171,   127,   164,
-32768,-32768,   157,   360,   169,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,   367,-32768,-32768,   365,   157,
   187,   187,    19,    29,    16,-32768,-32768,   369,-32768,-32768,
-32768,-32768,   213,-32768,-32768,   180,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,   370,   356,   371,   373,   368,
   375,   376,   322,   284,   324,   171,   326,   112,-32768,   372,
-32768,-32768,   277,-32768,-32768,   378,   171,   379,   381,   180,
-32768,   382,   381,   171,-32768,   383,   171,   384,   267,   269,
-32768,   157,   171,   171,   386,   387,   381,   328,-32768,-32768,
-32768,-32768,-32768,    27,   171,-32768,-32768,   388,   126,-32768,
-32768,   330,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
   389,    56,-32768,   332,-32768,   229,   157,   157,-32768,    20,
-32768,-32768,-32768,-32768,-32768,-32768,   166,   381,-32768,-32768,
   157,   381,-32768,   157,-32768,   108,-32768,-32768,-32768,-32768,
-32768,-32768,   157,   390,-32768,    74,   121,-32768,-32768,   391,
-32768,   274,   279,   392,   360,-32768,   394,   375,   375,   381,
   375,   375,   375,   375,-32768,-32768,-32768,-32768,-32768,   365,
   395,   397,   171,-32768,   398,   399,   375,   400,-32768,-32768,
-32768,-32768,   157,   157,-32768,   401,   375,-32768,   334,   336,
-32768,   338,   340,   402,   342,   344,   346,   348,-32768,    62,
   350,-32768,   384,-32768,-32768,   352,-32768,-32768,   180,   403,
   404,-32768,   171,-32768,   405,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,   406,-32768,-32768,   379,   354,
-32768,-32768,   407,-32768,-32768,   408,-32768,   171,   171,-32768,
-32768,   409,   410,-32768,-32768,   415,   416,-32768
};

static const short yypgoto[] = {   160,
-32768,-32768,-32768,    -4,-32768,-32768,-32768,   278,-32768,-32768,
-32768,   325,  -129,-32768,   141,  -145,-32768,-32768,   198,   374,
   -59,   300,   -41,-32768,   377,   219,-32768,-32768,-32768,-32768,
  -134,-32768,   -68,  -166,   -87,-32768,  -149,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,    14,   194,    50,-32768,  -218,
-32768,  -198,-32768,-32768,    78,-32768,   210,  -207,  -183,   212,
  -167,   -94,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,   -88,  -127,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,  -184,  -226,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768
};


#define	YYLAST		425


static const short yytable[] = {   142,
   129,   135,   129,   176,   170,    24,    77,   170,   228,   265,
   278,   118,   254,   192,   201,   306,     4,   220,    58,   215,
   103,   -33,   205,     1,   235,   269,   166,   306,   241,   269,
   241,   167,   211,   166,   104,   -33,    99,     9,   167,   105,
   -33,   261,   100,     7,   129,   216,   111,   129,   206,   207,
   208,   261,   312,    10,   112,   193,   129,   168,   212,   227,
   313,   251,   166,   137,   138,   170,   227,   167,   166,   209,
   217,   218,   259,   167,    25,   241,   173,   320,   213,   273,
   292,   214,   275,   293,   314,   210,    40,   241,   314,   139,
    41,   298,   284,   342,   140,   227,    83,   299,   300,   168,
   294,   227,   313,   306,    84,   129,    42,   174,   175,   347,
    85,   310,   330,   265,   166,   301,   302,   303,   304,   167,
    60,   129,   365,   173,   322,   129,   166,   186,   311,   187,
   241,   167,   166,   142,    64,   278,    65,   167,   368,   290,
   317,   315,   265,   118,   316,   261,   188,   227,    26,    27,
   261,   321,   321,   318,   174,   175,   255,   168,   297,   386,
   353,   298,     6,   241,   189,   227,   190,   299,   300,   154,
   265,   102,   166,   173,   261,   155,   261,   167,   343,   261,
   129,   370,    92,   191,   129,   301,   302,   303,   304,   238,
    43,   106,    44,   350,   351,    68,    43,    69,    44,    45,
    46,   170,   261,    47,   174,   175,   329,   129,    11,    73,
   -12,   -12,   334,   194,    48,   195,   196,    74,   373,   166,
    48,   107,    75,    49,   167,   110,    50,   197,    51,   331,
   331,    52,   331,   331,   331,   331,   108,   109,    53,    54,
   115,   129,    55,   382,   383,   223,    23,   119,   224,   225,
   226,    87,   227,  -163,    13,    14,    15,    16,    17,    18,
    19,    20,    21,   357,   357,    79,   357,   357,   357,   357,
   279,   121,   282,    80,   122,   142,   280,   326,   280,   281,
    81,   281,   327,   280,   117,    68,   281,    69,   280,    65,
   113,   281,    13,    14,    15,    16,    17,    18,    19,    20,
    21,    91,    89,  -178,  -170,   161,   116,   162,   123,  -178,
   117,    68,   333,    69,   335,   336,   337,   338,   145,   146,
   128,   169,   128,   171,   128,   237,   239,   240,   252,   253,
    92,   291,   252,   305,   252,   308,   128,   354,   252,   355,
   234,   356,   234,   358,   234,   360,   234,   361,   234,   362,
   234,   363,   340,   364,   234,   367,    92,   377,   202,   204,
   125,   127,   128,   143,   134,   136,   141,   153,   172,   152,
   199,   221,   200,   229,   231,   230,   232,   234,   147,   236,
   258,   260,   257,   267,   271,   274,   276,   233,   288,   289,
   114,   296,   307,   319,   325,   328,   252,   309,   339,   340,
   148,   344,   345,   348,   352,   359,   371,   372,   374,   375,
   380,   381,   384,   385,   387,   388,   256,   287,   376,    71,
   366,   270,   272,     0,    78
};

static const short yycheck[] = {    94,
    88,    90,    90,   138,   132,    10,    48,   135,   176,   208,
   218,    71,   197,   143,   160,   242,    27,   167,     1,     4,
     4,     4,     4,     3,   191,   209,     7,   254,   195,   213,
   197,    12,     4,     7,    18,    18,     3,    28,    12,    23,
    23,   208,     9,     3,   132,    30,     1,   135,    30,    31,
    32,   218,    33,    44,     9,   144,   144,    38,    30,    40,
    41,   196,     7,    38,    39,   193,    40,    12,     7,    51,
    55,    56,   207,    12,     4,   242,     3,     4,    50,   214,
   230,    53,   217,   233,   268,    67,     4,   254,   272,    64,
     4,    36,   222,   312,    69,    40,     1,    42,    43,    38,
   235,    40,    41,   330,     9,   193,     4,    34,    35,   317,
    15,   257,   297,   312,     7,    60,    61,    62,    63,    12,
     9,   209,   341,     3,     4,   213,     7,     1,   258,     3,
   297,    12,     7,   228,     1,   343,     3,    12,   346,   227,
    33,   271,   341,   203,   274,   312,    20,    40,     3,     4,
   317,   286,   287,   283,    34,    35,   198,    38,    33,     0,
   327,    36,     3,   330,     1,    40,     3,    42,    43,    13,
   369,     4,     7,     3,   341,    19,   343,    12,   313,   346,
   268,   349,     3,    20,   272,    60,    61,    62,    63,   194,
    22,     4,    24,   323,   324,     9,    22,    11,    24,    25,
    26,   329,   369,    29,    34,    35,   295,   295,     1,     1,
     3,     4,   300,    45,    46,    47,    48,     9,   353,     7,
    46,     4,    14,    49,    12,     4,    52,    59,    54,   298,
   299,    57,   301,   302,   303,   304,     8,     9,    64,    65,
     4,   329,    68,   378,   379,    33,     1,     4,    36,    37,
    38,     1,    40,     3,     9,    10,    11,    12,    13,    14,
    15,    16,    17,   332,   333,     1,   335,   336,   337,   338,
     4,     4,     4,     9,     4,   370,    10,     4,    10,    13,
    16,    13,     4,    10,     8,     9,    13,    11,    10,     3,
     4,    13,     9,    10,    11,    12,    13,    14,    15,    16,
    17,     1,     1,     3,     3,     9,     4,    11,     4,     9,
     8,     9,   299,    11,   301,   302,   303,   304,     3,     4,
     3,     4,     3,     4,     3,     4,     3,     4,     3,     4,
     3,     4,     3,     4,     3,     4,     3,     4,     3,     4,
     3,     4,     3,     4,     3,     4,     3,     4,     3,     4,
     3,     4,     3,     4,     3,     4,     3,     4,   161,   162,
     4,     4,     3,     9,     4,     4,     4,     4,     3,    11,
     4,     3,     8,     4,     4,    20,     4,     3,   101,     4,
     3,     3,    11,     3,     3,     3,     3,    20,     3,     3,
    66,     4,     4,     4,     4,     4,     3,   257,     4,     3,
   101,     4,     4,     4,     4,     4,     4,     4,     4,     4,
     4,     4,     4,     4,     0,     0,   198,   224,   369,    46,
   343,   210,   213,    -1,    48
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
#line 1669 "grammar.cc"

  switch (yyn) {

case 5:
#line 128 "ppddl.y"
{
          log_error((char*)"syntax error in domain");
          yyerrok;
      ;
    break;}
case 13:
#line 145 "ppddl.y"
{ domain_name_ = yyvsp[-1].sym->text; ;
    break;}
case 14:
#line 151 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 15:
#line 152 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 16:
#line 153 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 17:
#line 154 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 18:
#line 155 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 19:
#line 156 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 20:
#line 157 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 21:
#line 158 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 22:
#line 159 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 23:
#line 163 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 24:
#line 164 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 25:
#line 168 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 26:
#line 169 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 27:
#line 173 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 28:
#line 174 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 30:
#line 181 "ppddl.y"
{
          log_error((char*)"syntax error in requirements declaration.");
          yyerrok;
      ;
    break;}
case 31:
#line 188 "ppddl.y"
{ declare_lw1_translation(); ;
    break;}
case 35:
#line 197 "ppddl.y"
{
          log_error((char*)"syntax error in (:predicates ...)");
          yyerrok;
      ;
    break;}
case 38:
#line 209 "ppddl.y"
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
#line 217 "ppddl.y"
{
          log_error((char*)"syntax error in predicate declaration");
          yyerrok;
      ;
    break;}
case 41:
#line 225 "ppddl.y"
{
          // must reverse parameter list
          var_symbol_vec tmp_list(*yyvsp[0].vparam);
          yyvsp[0].vparam->clear();
          yyvsp[0].vparam->insert(yyvsp[0].vparam->end(), tmp_list.rbegin(), tmp_list.rend());
          yyval.vparam = yyvsp[0].vparam;
      ;
    break;}
case 42:
#line 232 "ppddl.y"
{ yyval.vparam = new var_symbol_vec; ;
    break;}
case 43:
#line 236 "ppddl.y"
{
          set_variable_type(*yyvsp[0].vparam, yyvsp[0].vparam->size(), dom_top_type_);
          yyval.vparam = yyvsp[0].vparam;
      ;
    break;}
case 44:
#line 243 "ppddl.y"
{
          set_variable_type(*yyvsp[-3].vparam, yyvsp[-3].vparam->size(), static_cast<TypeSymbol*>(yyvsp[-1].sym->val));
          yyvsp[0].vparam->insert(yyvsp[0].vparam->end(), yyvsp[-3].vparam->begin(), yyvsp[-3].vparam->end());
          delete yyvsp[-3].vparam;
          yyval.vparam = yyvsp[0].vparam;
      ;
    break;}
case 45:
#line 249 "ppddl.y"
{
          set_variable_type(*yyvsp[-2].vparam, yyvsp[-2].vparam->size(), static_cast<TypeSymbol*>(yyvsp[0].sym->val));
          yyval.vparam = yyvsp[-2].vparam;
      ;
    break;}
case 46:
#line 256 "ppddl.y"
{
          yyvsp[0].vparam->push_back(static_cast<VariableSymbol*>(yyvsp[-1].vsym));
          yyval.vparam = yyvsp[0].vparam;
      ;
    break;}
case 47:
#line 260 "ppddl.y"
{ yyval.vparam = new var_symbol_vec; yyval.vparam->push_back(yyvsp[0].vsym); ;
    break;}
case 48:
#line 264 "ppddl.y"
{
          VariableSymbol *var = new VariableSymbol(yyvsp[0].sym->text);
          yyvsp[0].sym->val = var;
          yyval.vsym = var;
      ;
    break;}
case 49:
#line 269 "ppddl.y"
{
          std::string msg("variable '");
          msg += yyvsp[0].sym->text;
          msg += "' shadows variable in outer scope: this is not supported!";
          log_error((char*)msg.c_str());
          yyerrok;
      ;
    break;}
case 51:
#line 282 "ppddl.y"
{
          set_type_type(dom_types_, dom_types_.size(), dom_top_type_);
      ;
    break;}
case 52:
#line 288 "ppddl.y"
{
          set_type_type(dom_types_, dom_types_.size(), static_cast<TypeSymbol*>(yyvsp[-1].sym->val));
      ;
    break;}
case 53:
#line 291 "ppddl.y"
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
#line 304 "ppddl.y"
{ ;
    break;}
case 58:
#line 309 "ppddl.y"
{
          yyvsp[0].sym->val = new TypeSymbol(yyvsp[0].sym->text);
          dom_types_.push_back(static_cast<TypeSymbol*>(yyvsp[0].sym->val));
      ;
    break;}
case 63:
#line 325 "ppddl.y"
{
          set_constant_type(dom_constants_, dom_constants_.size(), static_cast<TypeSymbol*>(yyvsp[0].sym->val));
      ;
    break;}
case 66:
#line 333 "ppddl.y"
{
          set_constant_type(dom_constants_, dom_constants_.size(), dom_top_type_);
      ;
    break;}
case 67:
#line 339 "ppddl.y"
{
          yyvsp[0].sym->val = new Symbol(yyvsp[0].sym->text);
          dom_constants_.push_back(static_cast<Symbol*>(yyvsp[0].sym->val));
      ;
    break;}
case 68:
#line 343 "ppddl.y"
{
          yyvsp[0].sym->val = new Symbol(yyvsp[0].sym->text);
          dom_constants_.push_back(static_cast<Symbol*>(yyvsp[0].sym->val));
      ;
    break;}
case 70:
#line 353 "ppddl.y"
{
          if( type_ == replanner ) {
              log_error((char*)"':axiom' is not a valid element in k-replanner.");
              yyerrok;
          }
      ;
    break;}
case 71:
#line 359 "ppddl.y"
{
          if( type_ == cp2fsc ) {
              log_error((char*)"':sensor' is not a valid element in cp2fsc.");
              yyerrok;
          }
      ;
    break;}
case 72:
#line 365 "ppddl.y"
{
          if( type_ == replanner ) {
              log_error((char*)"':observable' is not a valid element in k-replanner.");
              yyerrok;
          }
      ;
    break;}
case 73:
#line 371 "ppddl.y"
{
          if( type_ == replanner ) {
              log_error((char*)"':sticky' is not a valid element in k-replanner.");
              yyerrok;
          }
      ;
    break;}
case 74:
#line 377 "ppddl.y"
{
          declare_lw1_translation();
          if( type_ == cp2fsc ) {
              log_error((char*)"':sensor' is not a valid element in cp2fsc.");
              yyerrok;
          }
      ;
    break;}
case 75:
#line 389 "ppddl.y"
{
          Action *na = new Action(yyvsp[0].sym->text);
          dom_actions_.push_back(na);
      ;
    break;}
case 76:
#line 393 "ppddl.y"
{
          clear_param(dom_actions_.back()->param_);
          yyvsp[-3].sym->val = dom_actions_.back();
      ;
    break;}
case 77:
#line 397 "ppddl.y"
{
          log_error((char*)"syntax error in action declaration");
          yyerrok;
      ;
    break;}
case 78:
#line 404 "ppddl.y"
{
          dom_actions_.back()->param_ = *yyvsp[-1].vparam;
          delete yyvsp[-1].vparam;
      ;
    break;}
case 79:
#line 408 "ppddl.y"
{ dom_actions_.back()->precondition_ = yyvsp[0].condition; ;
    break;}
case 80:
#line 409 "ppddl.y"
{ dom_actions_.back()->effect_ = yyvsp[0].effect; ;
    break;}
case 81:
#line 410 "ppddl.y"
{
          declare_clg_translation();
          dom_actions_.back()->observe_ = new AndEffect(*yyvsp[0].effect_vec);
          delete yyvsp[0].effect_vec;
      ;
    break;}
case 82:
#line 415 "ppddl.y"
{
          declare_lw1_translation();
          dom_actions_.back()->sensing_proxy_ = yyvsp[0].sensing_proxy_list;
      ;
    break;}
case 90:
#line 432 "ppddl.y"
{ yyval.condition = new Constant(true); ;
    break;}
case 91:
#line 433 "ppddl.y"
{ yyval.condition = new Constant(false); ;
    break;}
case 92:
#line 437 "ppddl.y"
{
          // if literal is for equality, construct EQ
          if( yyvsp[0].atom->pred_ == dom_eq_pred_ )
              yyval.condition = new EQ(dynamic_cast<VariableSymbol*>(yyvsp[0].atom->param_[0]), dynamic_cast<VariableSymbol*>(yyvsp[0].atom->param_[1]), yyvsp[0].atom->negated_);
          else
              yyval.condition = new Literal(*yyvsp[0].atom);
          delete yyvsp[0].atom;
      ;
    break;}
case 95:
#line 453 "ppddl.y"
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
case 96:
#line 465 "ppddl.y"
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
case 97:
#line 477 "ppddl.y"
{
          const_cast<Literal*>(static_cast<const Literal*>(yyvsp[-1].atom))->negated_ = true;
          yyval.atom = yyvsp[-1].atom;
      ;
    break;}
case 98:
#line 484 "ppddl.y"
{
          if( yyvsp[0].sym->val == 0 )
              log_error((char*)"undeclared variable in atom args list");
          else
              yyvsp[-1].param->push_back(static_cast<VariableSymbol*>(yyvsp[0].sym->val));
          yyval.param = yyvsp[-1].param;
      ;
    break;}
case 99:
#line 491 "ppddl.y"
{
          yyvsp[-1].param->push_back(static_cast<Symbol*>(yyvsp[0].sym->val));
          yyval.param = yyvsp[-1].param;
      ;
    break;}
case 100:
#line 495 "ppddl.y"
{ yyval.param = new PDDL_Base::symbol_vec; ;
    break;}
case 101:
#line 499 "ppddl.y"
{
          yyval.condition = new And(*yyvsp[-1].condition_vec);
          delete yyvsp[-1].condition_vec;
      ;
    break;}
case 102:
#line 506 "ppddl.y"
{
          yyval.condition = new Or(*yyvsp[-1].condition_vec);
          delete yyvsp[-1].condition_vec;
      ;
    break;}
case 103:
#line 513 "ppddl.y"
{
          forall_conditions_.push_back(new ForallCondition);
      ;
    break;}
case 104:
#line 516 "ppddl.y"
{
          forall_conditions_.back()->param_ = *yyvsp[-1].vparam;
          delete yyvsp[-1].vparam;
      ;
    break;}
case 105:
#line 520 "ppddl.y"
{
          forall_conditions_.back()->condition_ = yyvsp[-1].condition;
          clear_param(forall_conditions_.back()->param_);
          yyval.condition = forall_conditions_.back();
          forall_conditions_.pop_back();
      ;
    break;}
case 106:
#line 529 "ppddl.y"
{
          exists_conditions_.push_back(new ExistsCondition);
      ;
    break;}
case 107:
#line 532 "ppddl.y"
{
          exists_conditions_.back()->param_ = *yyvsp[-1].vparam;
          delete yyvsp[-1].vparam;
      ;
    break;}
case 108:
#line 536 "ppddl.y"
{
          exists_conditions_.back()->condition_ = yyvsp[-1].condition;
          clear_param(exists_conditions_.back()->param_);
          yyval.condition = exists_conditions_.back();
          exists_conditions_.pop_back();
      ;
    break;}
case 109:
#line 545 "ppddl.y"
{
          yyvsp[-1].condition_vec->push_back(yyvsp[0].condition);
          yyval.condition_vec = yyvsp[-1].condition_vec;
      ;
    break;}
case 110:
#line 549 "ppddl.y"
{
          condition_vec *cond_vec = new condition_vec;
          cond_vec->push_back(yyvsp[0].condition);
          yyval.condition_vec = cond_vec;
      ;
    break;}
case 111:
#line 557 "ppddl.y"
{
          yyvsp[-1].condition_vec->push_back(yyvsp[0].condition);
          yyval.condition_vec = yyvsp[-1].condition_vec;
      ;
    break;}
case 112:
#line 561 "ppddl.y"
{
          condition_vec *cond_vec = new condition_vec;
          cond_vec->push_back(yyvsp[0].condition);
          yyval.condition_vec = cond_vec;
      ;
    break;}
case 114:
#line 570 "ppddl.y"
{
          yyval.effect = new AndEffect(*yyvsp[-1].effect_vec);
          delete yyvsp[-1].effect_vec;
      ;
    break;}
case 115:
#line 577 "ppddl.y"
{
          yyvsp[-1].effect_vec->push_back(yyvsp[0].effect);
          yyval.effect_vec = yyvsp[-1].effect_vec;
      ;
    break;}
case 116:
#line 581 "ppddl.y"
{
          yyval.effect_vec = new effect_vec;
          yyval.effect_vec->push_back(yyvsp[0].effect);
      ;
    break;}
case 120:
#line 594 "ppddl.y"
{ yyval.effect = new ConditionalEffect(yyvsp[-2].condition, yyvsp[-1].effect); ;
    break;}
case 121:
#line 598 "ppddl.y"
{
          forall_effects_.push_back(new ForallEffect);
      ;
    break;}
case 122:
#line 601 "ppddl.y"
{
          forall_effects_.back()->param_ = *yyvsp[-1].vparam;
          delete yyvsp[-1].vparam;
      ;
    break;}
case 123:
#line 605 "ppddl.y"
{
          forall_effects_.back()->effect_ = yyvsp[-1].effect;
          clear_param(forall_effects_.back()->param_);
          yyval.effect = forall_effects_.back();
          forall_effects_.pop_back();
      ;
    break;}
case 124:
#line 614 "ppddl.y"
{
          yyval.effect = new AndEffect(*yyvsp[-1].effect_vec);
          delete yyvsp[-1].effect_vec;
      ;
    break;}
case 126:
#line 622 "ppddl.y"
{
          yyvsp[-1].effect_vec->push_back(yyvsp[0].effect);
          yyval.effect_vec = yyvsp[-1].effect_vec;
      ;
    break;}
case 127:
#line 626 "ppddl.y"
{
          yyval.effect_vec = new effect_vec;
          yyval.effect_vec->push_back(yyvsp[0].effect);
      ;
    break;}
case 128:
#line 633 "ppddl.y"
{
          yyvsp[-1].effect_vec->push_back(yyvsp[0].effect);
          yyval.effect_vec = yyvsp[-1].effect_vec;
      ;
    break;}
case 129:
#line 637 "ppddl.y"
{
          yyval.effect_vec = new effect_vec;
          yyval.effect_vec->push_back(yyvsp[0].effect);
      ;
    break;}
case 130:
#line 644 "ppddl.y"
{ yyval.effect = new AtomicEffect(*yyvsp[0].atom); delete yyvsp[0].atom; ;
    break;}
case 131:
#line 648 "ppddl.y"
{ yyval.effect = new AtomicEffect(*yyvsp[0].atom); delete yyvsp[0].atom; ;
    break;}
case 133:
#line 653 "ppddl.y"
{ yyval.sensing_proxy_list = 0; ;
    break;}
case 134:
#line 657 "ppddl.y"
{
          sensing_proxy_vec *list_sensing_proxy = const_cast<sensing_proxy_vec*>(yyvsp[-1].sensing_proxy_list);
          list_sensing_proxy->push_back(yyvsp[0].sensing_proxy);
          yyval.sensing_proxy_list = list_sensing_proxy;
      ;
    break;}
case 135:
#line 662 "ppddl.y"
{
          sensing_proxy_vec *list_sensing_proxy = new sensing_proxy_vec;
          list_sensing_proxy->push_back(yyvsp[0].sensing_proxy);
          yyval.sensing_proxy_list = list_sensing_proxy;
      ;
    break;}
case 136:
#line 670 "ppddl.y"
{ yyval.sensing_proxy = new BasicSensingModel(yyvsp[0].sensing_model); ;
    break;}
case 139:
#line 676 "ppddl.y"
{
          forall_sensing_.push_back(new ForallSensing);
      ;
    break;}
case 140:
#line 679 "ppddl.y"
{
          forall_sensing_.back()->param_ = *yyvsp[-1].vparam;
          delete yyvsp[-1].vparam;
      ;
    break;}
case 141:
#line 683 "ppddl.y"
{
          forall_sensing_.back()->sensing_ = *yyvsp[-1].sensing_proxy_list;
          delete yyvsp[-1].sensing_proxy_list;
          clear_param(forall_sensing_.back()->param_);
          yyval.sensing_proxy = forall_sensing_.back();
          forall_sensing_.pop_back();
      ;
    break;}
case 142:
#line 693 "ppddl.y"
{
          SuchThatSensing *such_that_sensing = new SuchThatSensing(yyvsp[-2].condition);
          such_that_sensing->sensing_ = *yyvsp[-1].sensing_proxy_list;
          delete yyvsp[-1].sensing_proxy_list;
          yyval.sensing_proxy = such_that_sensing;
      ;
    break;}
case 143:
#line 702 "ppddl.y"
{
          assert(static_cast<Symbol*>(yyvsp[-3].sym->val)->sym_class_ == sym_varname);
          const Variable *variable = static_cast<Variable*>(yyvsp[-3].sym->val);
          if( dynamic_cast<const ObsVariable*>(variable) == 0 ) {
              std::cout << Utils::error() << "sensing model can only be specified for observable variable" << std::endl;
              yyval.sensing_model = 0;
          } else {
              const ObsVariable *obs_variable = static_cast<const ObsVariable*>(variable);
              assert(dynamic_cast<const ObsVariable*>(variable) != 0);
              yyval.sensing_model = new SensingModelForObservableVariable(obs_variable, new Literal(*yyvsp[-2].atom), yyvsp[-1].condition);
          }
      ;
    break;}
case 144:
#line 714 "ppddl.y"
{
          assert(static_cast<Symbol*>(yyvsp[-5].sym->val)->sym_class_ == sym_varname);
          const Variable *variable = static_cast<Variable*>(yyvsp[-5].sym->val);
          if( dynamic_cast<const ObsVariable*>(variable) == 0 ) {
              std::cout << Utils::error() << "sensing model can only be specified for observable variable" << std::endl;
              yyval.sensing_model = 0;
          } else {
              const ObsVariable *obs_variable = static_cast<const ObsVariable*>(variable);
              assert(dynamic_cast<const ObsVariable*>(variable) != 0);
              SensingModelForObservableVariable *model = new SensingModelForObservableVariable(obs_variable, new Literal(*yyvsp[-2].atom), yyvsp[-1].condition);
              model->param_ = *yyvsp[-4].param;
              delete yyvsp[-4].param;
              yyval.sensing_model = model;
          }
      ;
    break;}
case 145:
#line 729 "ppddl.y"
{
          assert(static_cast<Symbol*>(yyvsp[-1].sym->val)->sym_class_ == sym_varname);
          const Variable *variable = static_cast<Variable*>(yyvsp[-1].sym->val);
          assert(dynamic_cast<const StateVariable*>(variable) != 0);
          yyval.sensing_model = new SensingModelForStateVariable(static_cast<const StateVariable*>(variable));
      ;
    break;}
case 146:
#line 735 "ppddl.y"
{
          assert(static_cast<Symbol*>(yyvsp[-3].sym->val)->sym_class_ == sym_varname);
          const Variable *variable = static_cast<Variable*>(yyvsp[-3].sym->val);
          assert(dynamic_cast<const StateVariable*>(variable) != 0);
          SensingModelForStateVariable *model = new SensingModelForStateVariable(static_cast<const StateVariable*>(variable));
          model->param_ = *yyvsp[-2].param;
          delete yyvsp[-2].param;
          yyval.sensing_model = model;
      ;
    break;}
case 147:
#line 744 "ppddl.y"
{
          log_error((char*)"syntax error in sensing declaration for ':variable'");
          yyerrok;
      ;
    break;}
case 148:
#line 748 "ppddl.y"
{
          log_error((char*)"syntax error in sensing declaration for ':model-for'");
          yyerrok;
      ;
    break;}
case 149:
#line 755 "ppddl.y"
{
          Axiom *nr = new Axiom(yyvsp[0].sym->text);
          dom_axioms_.push_back(nr);
      ;
    break;}
case 150:
#line 759 "ppddl.y"
{
          clear_param(dom_axioms_.back()->param_);
          yyvsp[-3].sym->val = dom_axioms_.back();
      ;
    break;}
case 151:
#line 763 "ppddl.y"
{
          log_error((char*)"syntax error in axiom declaration");
          yyerrok;
      ;
    break;}
case 152:
#line 770 "ppddl.y"
{
          dom_axioms_.back()->param_ = *yyvsp[-1].vparam;
          delete yyvsp[-1].vparam;
      ;
    break;}
case 153:
#line 774 "ppddl.y"
{ dom_axioms_.back()->body_ = yyvsp[0].condition; ;
    break;}
case 154:
#line 775 "ppddl.y"
{ dom_axioms_.back()->head_ = yyvsp[0].effect; ;
    break;}
case 156:
#line 780 "ppddl.y"
{
          Sensor *nr = new Sensor(yyvsp[0].sym->text);
          dom_sensors_.push_back(nr);
      ;
    break;}
case 157:
#line 784 "ppddl.y"
{
          clear_param(dom_sensors_.back()->param_);
          yyvsp[-3].sym->val = dom_sensors_.back();
      ;
    break;}
case 158:
#line 788 "ppddl.y"
{
          log_error((char*)"syntax error in sensor declaration");
          yyerrok;
      ;
    break;}
case 159:
#line 795 "ppddl.y"
{
          dom_sensors_.back()->param_ = *yyvsp[-1].vparam;
          delete yyvsp[-1].vparam;
      ;
    break;}
case 160:
#line 799 "ppddl.y"
{
          dom_sensors_.back()->condition_ = yyvsp[0].condition;
      ;
    break;}
case 161:
#line 802 "ppddl.y"
{
          dom_sensors_.back()->sense_ = new AndEffect(*yyvsp[0].effect_vec);
          delete yyvsp[0].effect_vec;
      ;
    break;}
case 163:
#line 810 "ppddl.y"
{
          Observable *obs = new Observable;
          dom_observables_.push_back(obs);
          effect_vec_ptr_ = &obs->observables_;
      ;
    break;}
case 165:
#line 816 "ppddl.y"
{
          log_error((char*)"syntax error in observable declaration");
          yyerrok;
      ;
    break;}
case 166:
#line 823 "ppddl.y"
{
          effect_vec_ptr_->push_back(yyvsp[0].effect);
      ;
    break;}
case 167:
#line 826 "ppddl.y"
{
          effect_vec_ptr_->push_back(yyvsp[0].effect);
      ;
    break;}
case 170:
#line 837 "ppddl.y"
{
          Sticky *sticky = new Sticky;
          dom_stickies_.push_back(sticky);
          effect_vec_ptr_ = &sticky->stickies_;
      ;
    break;}
case 172:
#line 843 "ppddl.y"
{
          log_error((char*)"syntax error in sticky declaration");
          yyerrok;
      ;
    break;}
case 173:
#line 850 "ppddl.y"
{
          Variable *var = 0;
          if( yyvsp[-1].ival == 0 )
              var = new StateVariable(yyvsp[0].sym->text);
          else
              var = new ObsVariable(yyvsp[0].sym->text);
          multivalued_variables_.push_back(var);
          effect_vec_ptr_ = &var->domain_;
      ;
    break;}
case 174:
#line 859 "ppddl.y"
{
          yyvsp[-3].sym->val = multivalued_variables_.back();
      ;
    break;}
case 175:
#line 862 "ppddl.y"
{
          Variable *var = 0;
          if( yyvsp[-4].ival == 0 )
              var = new StateVariable(yyvsp[-2].sym->text);
          else
              var = new ObsVariable(yyvsp[-2].sym->text);
          var->param_ = *yyvsp[-1].vparam;
          delete yyvsp[-1].vparam;
          multivalued_variables_.push_back(var);
          effect_vec_ptr_ = &var->domain_;
      ;
    break;}
case 176:
#line 873 "ppddl.y"
{
          clear_param(multivalued_variables_.back()->param_);
          yyvsp[-5].sym->val = multivalued_variables_.back();
      ;
    break;}
case 177:
#line 877 "ppddl.y"
{
          log_error((char*)"syntax error in state variable declaration");
          yyerrok;
      ;
    break;}
case 178:
#line 884 "ppddl.y"
{ yyval.ival = 0; ;
    break;}
case 179:
#line 885 "ppddl.y"
{ yyval.ival = 1; ;
    break;}
case 180:
#line 891 "ppddl.y"
{
          declare_lw1_translation();
          default_sensing_proxy_ = yyvsp[-1].sensing_proxy_list;
      ;
    break;}
case 181:
#line 901 "ppddl.y"
{
          problem_name_ = yyvsp[-1].sym->text;
      ;
    break;}
case 183:
#line 905 "ppddl.y"
{
          log_error((char*)"syntax error in problem definition.");
          yyerrok;
      ;
    break;}
case 192:
#line 923 "ppddl.y"
{ dom_init_ = *yyvsp[-1].ilist; delete yyvsp[-1].ilist; ;
    break;}
case 193:
#line 924 "ppddl.y"
{ dom_init_ = *yyvsp[-2].ilist; delete yyvsp[-2].ilist; ;
    break;}
case 194:
#line 928 "ppddl.y"
{
          init_element_vec *ilist = const_cast<init_element_vec*>(yyvsp[-1].ilist);
          if( yyvsp[0].ielem != 0 ) ilist->push_back(const_cast<InitElement*>(yyvsp[0].ielem));
          yyval.ilist = ilist;
      ;
    break;}
case 195:
#line 933 "ppddl.y"
{
          init_element_vec *ilist = new init_element_vec;
          if( yyvsp[0].ielem != 0 ) ilist->push_back(const_cast<InitElement*>(yyvsp[0].ielem));
          yyval.ilist = ilist;
      ;
    break;}
case 196:
#line 941 "ppddl.y"
{ yyval.ielem = new InitLiteral(*yyvsp[0].atom); ;
    break;}
case 197:
#line 942 "ppddl.y"
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
case 198:
#line 953 "ppddl.y"
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
case 199:
#line 964 "ppddl.y"
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
case 200:
#line 975 "ppddl.y"
{
          yyval.ielem = 0; // when fixing this, remove condition '$2 != 0' and '$1 != 0' above (in single_init_element)
          std::cout << Utils::warning()
                    << Utils::magenta() << "(clg) ignoring '" << yyvsp[0].unknown->to_string() << "'"
                    << Utils::normal() << std::endl;
          //$$ = new InitUnknown(*$1);
          delete yyvsp[0].unknown;
      ;
    break;}
case 201:
#line 986 "ppddl.y"
{
          //$$ = new Invariant(Invariant::AT_LEAST_ONE, *static_cast<const And*>($3));
          yyval.invariant = new Invariant(Invariant::AT_LEAST_ONE, *yyvsp[-1].condition_vec);
          delete yyvsp[-1].condition_vec;
      ;
    break;}
case 202:
#line 991 "ppddl.y"
{
          //$$ = new Invariant(Invariant::AT_LEAST_ONE, *static_cast<const And*>($3));
          yyval.invariant = new Invariant(Invariant::AT_LEAST_ONE, *yyvsp[-1].condition_vec);
          delete yyvsp[-1].condition_vec;
      ;
    break;}
case 203:
#line 999 "ppddl.y"
{
          //$$ = new Invariant(Invariant::AT_MOST_ONE, *static_cast<const And*>($3));
          yyval.invariant = new Invariant(Invariant::AT_MOST_ONE, *yyvsp[-1].condition_vec);
          delete yyvsp[-1].condition_vec;
      ;
    break;}
case 204:
#line 1007 "ppddl.y"
{
          yyval.invariant = new Invariant(Invariant::EXACTLY_ONE, *yyvsp[-1].condition_vec);
          delete yyvsp[-1].condition_vec;
      ;
    break;}
case 208:
#line 1020 "ppddl.y"
{
          yyval.clause = new Clause(*yyvsp[-1].condition_vec);
          delete yyvsp[-1].condition_vec;
      ;
    break;}
case 209:
#line 1027 "ppddl.y"
{
          yyval.oneof = new Oneof(*yyvsp[-1].condition_vec);
          delete yyvsp[-1].condition_vec;
      ;
    break;}
case 210:
#line 1034 "ppddl.y"
{
          yyval.unknown = new Unknown(*yyvsp[-1].atom);
          delete yyvsp[-1].atom;
      ;
    break;}
case 211:
#line 1041 "ppddl.y"
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
case 212:
#line 1050 "ppddl.y"
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
case 213:
#line 1062 "ppddl.y"
{ dom_goal_ = yyvsp[-1].condition; ;
    break;}
case 214:
#line 1068 "ppddl.y"
{
          const_cast<And*>(static_cast<const And*>(yyvsp[-1].condition))->push_back(yyvsp[0].condition);
          yyval.condition = yyvsp[-1].condition;
      ;
    break;}
case 215:
#line 1072 "ppddl.y"
{
          And *cond = new And;
          cond->push_back(yyvsp[0].condition);
          yyval.condition = cond;
      ;
    break;}
case 216:
#line 1081 "ppddl.y"
{ yyval.condition = new Literal(*yyvsp[0].atom); delete yyvsp[0].atom; ;
    break;}
case 217:
#line 1082 "ppddl.y"
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
#line 2960 "grammar.cc"
#line 1085 "ppddl.y"


