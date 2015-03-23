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
    std::vector<Schema*> schema_; \
    effect_vec *effect_vec_ptr_;
#line 23 "ppddl.y"

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

#line 40 "ppddl.y"
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
#line 193 "grammar.cc"

#line 117 "/usr/local/lib/bison.cc"
/*  YY_PDDL_Parser_PURE */
#endif

/* section apres lecture def, avant lecture grammaire S2 */

/* #line 121 "/usr/local/lib/bison.cc" */
#line 202 "grammar.cc"

#line 121 "/usr/local/lib/bison.cc"
/* prefix */
#ifndef YY_PDDL_Parser_DEBUG

/* #line 123 "/usr/local/lib/bison.cc" */
#line 209 "grammar.cc"

#line 123 "/usr/local/lib/bison.cc"
/* YY_PDDL_Parser_DEBUG */
#endif


#ifndef YY_PDDL_Parser_LSP_NEEDED

/* #line 128 "/usr/local/lib/bison.cc" */
#line 219 "grammar.cc"

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
#line 332 "grammar.cc"
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
#line 525 "grammar.cc"
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
#line 629 "grammar.cc"
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
#line 713 "grammar.cc"


#define	YYFINAL		389
#define	YYFLAG		-32768
#define	YYNTBASE	70

#define YYTRANSLATE(x) ((unsigned)(x) <= 324 ? yytranslate[x] : 171)

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
   364,   365,   366,   377,   380,   381,   386,   388,   391,   393,
   396,   398,   400,   402,   404,   405,   408,   410,   412,   414,
   415,   416,   427,   434,   444,   449,   457,   462,   467,   468,
   475,   480,   486,   490,   494,   495,   496,   503,   508,   514,
   518,   522,   523,   524,   530,   535,   538,   540,   542,   544,
   545,   551,   556,   557,   564,   565,   566,   578,   583,   585,
   587,   592,   593,   603,   610,   616,   619,   622,   625,   628,
   631,   632,   636,   641,   649,   652,   654,   656,   658,   660,
   662,   664,   669,   674,   679,   684,   686,   688,   690,   695,
   700,   705,   710,   714,   719,   722,   724,   726
};

static const short yyrhs[] = {    71,
    70,     0,   156,    70,     0,     0,     3,    27,    73,    72,
     4,     0,     3,    27,    73,     1,     4,     0,    72,    78,
     0,    72,    88,     0,    72,    92,     0,    72,    80,     0,
    72,    97,     0,    72,   155,     0,     0,     3,    28,    74,
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
   118,     0,   100,    51,   128,     0,   100,    67,   131,     0,
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
     0,   129,     0,   121,     0,   122,     0,     3,    41,   101,
   126,     4,     0,     0,     0,     3,    38,     3,   123,    83,
     4,   124,   125,   118,     4,     0,    39,   101,     0,     0,
     3,    33,   127,     4,     0,   129,     0,   127,   129,     0,
   129,     0,   128,   130,     0,   130,     0,   104,     0,   105,
     0,   132,     0,     0,   132,   133,     0,   133,     0,   137,
     0,   134,     0,     0,     0,     3,    38,     3,   135,    83,
     4,   136,   125,   132,     4,     0,     3,    69,    20,   104,
   101,     4,     0,     3,    69,     3,    20,   107,     4,   104,
   101,     4,     0,     3,    64,    20,     4,     0,     3,    64,
     3,    20,   107,     4,     4,     0,     3,    64,     1,     4,
     0,     3,    69,     1,     4,     0,     0,     3,    52,    77,
   139,   140,     4,     0,     3,    52,     1,     4,     0,   140,
    30,     3,    83,     4,     0,   140,    55,   101,     0,   140,
    56,   126,     0,     0,     0,     3,    49,    76,   142,   143,
     4,     0,     3,    49,     1,     4,     0,   143,    30,     3,
    83,     4,     0,   143,    53,   101,     0,   143,    50,   128,
     0,     0,     0,     3,    54,   145,   146,     4,     0,     3,
    54,     1,     4,     0,   146,   147,     0,   147,     0,   130,
     0,   122,     0,     0,     3,    57,   149,   146,     4,     0,
     3,    57,     1,     4,     0,     0,     3,   154,     9,   151,
   146,     4,     0,     0,     0,     3,   154,     3,     9,   152,
    83,     4,   153,   125,   146,     4,     0,     3,    64,     1,
     4,     0,    64,     0,    65,     0,     3,    68,   131,     4,
     0,     0,     3,    27,     3,    44,    74,     4,   157,   158,
     4,     0,     3,    27,     3,    44,     1,     4,     0,   158,
     3,    45,    74,     4,     0,   158,    78,     0,   158,    92,
     0,   158,   159,     0,   158,   169,     0,   158,   170,     0,
     0,     3,    47,     4,     0,     3,    47,   160,     4,     0,
     3,    47,     3,    33,   160,     4,     4,     0,   160,   161,
     0,   161,     0,   104,     0,   165,     0,   166,     0,   167,
     0,   168,     0,     3,    60,   116,     4,     0,     3,    61,
   116,     4,     0,     3,    62,   116,     4,     0,     3,    63,
   116,     4,     0,   162,     0,   163,     0,   164,     0,     3,
    36,   116,     4,     0,     3,    42,   116,     4,     0,     3,
    43,   105,     4,     0,     3,    59,   160,     4,     0,     3,
    59,     4,     0,     3,    48,   101,     4,     0,     0,     0,
     0,     0,     0,   105,     0,   106,     0
};

#endif

#if YY_PDDL_Parser_DEBUG != 0
static const short yyrline[] = { 0,
   117,   119,   120,   123,   125,   131,   133,   134,   135,   136,
   137,   138,   141,   147,   149,   150,   151,   152,   153,   154,
   155,   156,   159,   161,   164,   166,   169,   171,   176,   178,
   184,   186,   187,   192,   194,   200,   202,   205,   214,   220,
   222,   229,   232,   239,   246,   252,   257,   260,   266,   277,
   279,   284,   288,   296,   299,   301,   304,   306,   314,   316,
   317,   318,   321,   326,   326,   329,   335,   340,   348,   350,
   356,   362,   368,   374,   385,   390,   394,   400,   405,   406,
   407,   412,   416,   419,   421,   422,   423,   424,   425,   428,
   430,   433,   444,   446,   449,   462,   473,   480,   488,   492,
   495,   502,   509,   513,   517,   527,   531,   535,   545,   550,
   557,   562,   569,   571,   577,   582,   588,   590,   591,   594,
   598,   602,   606,   616,   621,   624,   629,   632,   637,   643,
   648,   654,   658,   662,   664,   667,   673,   680,   682,   685,
   689,   693,   704,   717,   732,   738,   747,   751,   757,   762,
   766,   772,   777,   778,   779,   782,   787,   791,   797,   802,
   805,   809,   812,   818,   819,   825,   829,   834,   836,   839,
   845,   846,   852,   862,   865,   874,   878,   886,   892,   894,
   899,   909,   913,   914,   920,   922,   923,   924,   925,   926,
   927,   930,   932,   933,   936,   942,   949,   951,   962,   973,
   984,   994,  1000,  1007,  1015,  1022,  1024,  1025,  1028,  1035,
  1042,  1049,  1059,  1070,  1076,  1081,  1089,  1091
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
"conditional_effect","forall_effect","@7","@8","optional_such_that","atomic_effect_kw_list",
"atomic_effect_list","positive_atomic_effect_list","atomic_effect","positive_atomic_effect",
"sensing","sensing_decl_list","sensing_decl","forall_sensing","@9","@10","sensing_model",
"axiom_decl","@11","axiom_elements","sensor_decl","@12","sensor_elements","observable_decl",
"@13","fluent_list_decl","fluent_decl","sticky_decl","@14","simple_variable_decl",
"@15","@16","@17","variable_type","domain_default_sensing","pddl_problem","@18",
"problem_elements","initial_state","init_elements","single_init_element","at_least_one_invariant",
"at_most_one_invariant","exactly_one_invariant","invariant","clause","oneof",
"unknown","hidden_state","goal_spec",""
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
   128,   129,   130,   131,   131,   132,   132,   133,   133,   135,
   136,   134,   137,   137,   137,   137,   137,   137,   139,   138,
   138,   140,   140,   140,   140,   142,   141,   141,   143,   143,
   143,   143,   145,   144,   144,   146,   146,   147,   147,   149,
   148,   148,   151,   150,   152,   153,   150,   150,   154,   154,
   155,   157,   156,   156,   158,   158,   158,   158,   158,   158,
   158,   159,   159,   159,   160,   160,   161,   161,   161,   161,
   161,   162,   162,   163,   164,   165,   165,   165,   166,   167,
   168,   169,   169,   170,    -1,    -1,    -1,    -1
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
     0,     0,    10,     2,     0,     4,     1,     2,     1,     2,
     1,     1,     1,     1,     0,     2,     1,     1,     1,     0,
     0,    10,     6,     9,     4,     7,     4,     4,     0,     6,
     4,     5,     3,     3,     0,     0,     6,     4,     5,     3,
     3,     0,     0,     5,     4,     2,     1,     1,     1,     0,
     5,     4,     0,     6,     0,     0,    11,     4,     1,     1,
     4,     0,     9,     6,     5,     2,     2,     2,     2,     2,
     0,     3,     4,     7,     2,     1,     1,     1,     1,     1,
     1,     4,     4,     4,     4,     1,     1,     1,     4,     4,
     4,     4,     3,     4,     2,     1,     1,     1
};

static const short yydefact[] = {     3,
     0,     3,     3,     0,     1,     2,     0,     0,     0,     0,
     0,     0,    14,    15,    16,    17,    18,    19,    20,    21,
    22,     0,     0,     0,     5,     0,     4,     6,     9,     7,
     8,    10,    69,    70,    71,    72,    73,    74,    11,    13,
   184,   182,     0,    65,     0,    54,     0,    65,     0,     0,
     0,     0,     0,   180,   135,     0,   191,     0,     0,    68,
     0,     0,    66,     0,     0,     0,    37,    58,    57,     0,
     0,    56,     0,    23,    24,    75,     0,     0,     0,    25,
    26,   156,     0,    27,    28,   149,     0,     0,     0,     0,
     0,     0,     0,   134,   137,   139,   138,     0,   173,     0,
    30,    29,    32,    31,    59,    61,     0,    67,    35,     0,
    42,    34,    36,    51,    50,     0,    55,    77,    83,    60,
    62,   158,   162,   151,   155,   165,     0,   133,   169,   168,
     0,   167,   172,     0,   178,     0,     0,     0,   181,   136,
   175,     0,     0,   183,   186,   187,   188,   189,   190,    63,
    39,    49,    48,     0,    40,    41,    43,    47,    54,    54,
     0,     0,     0,   100,   100,     0,   164,   166,   171,   140,
     0,     0,     0,     0,     0,     0,    42,     0,     0,     0,
     0,     0,    65,    38,     0,    46,    53,     0,    52,    76,
     0,     0,     0,     0,   135,   157,     0,     0,     0,   150,
     0,     0,     0,     0,     0,   121,    42,   147,   100,   145,
   148,   100,     0,     0,    93,    94,     0,   174,     0,     0,
   192,   197,     0,   196,   206,   207,   208,   198,   199,   200,
   201,     0,    90,    91,     0,    84,    85,    92,    86,    87,
    88,    89,     0,   213,     0,    64,     0,    45,    42,    79,
     0,   132,    80,   113,   118,   119,   117,     0,    81,   131,
    82,    42,   161,   160,    42,   153,     0,   154,   127,    96,
    99,    98,    95,    42,     0,     0,     0,     0,     0,   176,
   185,     0,     0,     0,     0,     0,     0,     0,     0,   193,
   195,     0,     0,     0,     0,   214,   212,    44,     0,     0,
     0,     0,   130,     0,     0,     0,     0,   141,     0,     0,
     0,   143,   125,     0,   110,     0,     0,     0,     0,     0,
     0,     0,   112,     0,     0,   106,   103,    78,     0,     0,
   116,     0,   159,   152,     0,   129,   122,   125,   146,     0,
    97,     0,     0,     0,   209,   109,   210,   211,   202,   203,
   204,   205,   101,   111,   102,    42,    42,   114,   115,     0,
   126,   128,   125,     0,     0,   124,     0,   194,     0,     0,
   120,     0,     0,   144,   177,   107,   104,     0,   142,     0,
     0,   123,     0,     0,   108,   105,     0,     0,     0
};

static const short yydefgoto[] = {     5,
     2,    12,     8,    22,    76,    82,    86,    28,    59,    29,
    66,    67,   154,   155,   156,   157,   158,    30,    70,   188,
    72,    31,    61,   183,    62,    63,    32,    33,   119,   161,
   323,   236,   237,   238,   215,   216,   204,   239,   240,   241,
   357,   381,   242,   356,   380,   316,   324,   253,   330,   254,
   255,   129,   274,   363,   343,   268,   335,   259,   257,   130,
    93,    94,    95,    96,   207,   338,    97,    34,   125,   163,
    35,   123,   162,    36,    88,   131,   132,    37,    90,    38,
   142,   177,   313,    56,    39,     3,    57,   100,   147,   223,
   224,   225,   226,   227,   228,   229,   230,   231,   148,   149
};

static const short yypact[] = {    19,
    90,    19,    19,    38,-32768,-32768,    31,   259,   291,   272,
    77,   133,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,   140,   166,   169,-32768,   177,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,   226,   183,   181,   284,   250,   183,   209,    30,
   309,   314,    99,-32768,   197,    58,-32768,   224,    97,-32768,
   235,   253,   149,   263,    70,   208,-32768,-32768,-32768,   274,
   305,-32768,   307,-32768,-32768,-32768,   316,   352,   353,-32768,
-32768,-32768,   354,-32768,-32768,-32768,   355,   315,   356,   315,
   357,    54,   358,   197,-32768,-32768,-32768,   359,-32768,   217,
-32768,-32768,-32768,-32768,-32768,-32768,   360,-32768,-32768,   361,
   108,-32768,-32768,-32768,-32768,   310,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,   156,-32768,-32768,-32768,
   294,-32768,-32768,   319,-32768,   363,   121,   178,-32768,-32768,
-32768,   315,    50,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,   365,-32768,-32768,   362,   108,   284,   284,
    17,    23,    14,-32768,-32768,   364,-32768,-32768,-32768,-32768,
   368,   344,   369,   370,   366,   372,   108,   321,   291,   323,
    53,   325,   183,-32768,   367,-32768,-32768,   283,-32768,-32768,
   373,    53,   374,   376,   197,-32768,   377,   376,    53,-32768,
   378,    53,   379,   146,   170,-32768,   108,-32768,-32768,-32768,
-32768,-32768,    22,    53,-32768,-32768,   380,-32768,   381,    92,
-32768,-32768,   327,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,   210,-32768,-32768,   383,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,   153,-32768,   329,-32768,   149,   108,   108,-32768,
    25,-32768,-32768,-32768,-32768,-32768,-32768,   212,   376,-32768,
-32768,   108,   376,-32768,   108,-32768,   100,-32768,-32768,-32768,
-32768,-32768,-32768,   108,   384,   248,   286,   376,   385,-32768,
-32768,   387,   372,   372,   376,   372,   372,   372,   372,-32768,
-32768,    53,    53,   388,   389,-32768,-32768,-32768,   362,   390,
   392,    53,-32768,   393,   394,   372,   395,-32768,   396,   372,
   397,-32768,   324,   331,-32768,   333,   335,   398,   337,   339,
   341,   343,-32768,   127,   173,-32768,-32768,-32768,    45,   345,
-32768,   379,-32768,-32768,   347,-32768,-32768,   324,-32768,    53,
-32768,    53,   315,   399,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,   108,   108,-32768,-32768,   400,
-32768,-32768,   324,   197,   401,-32768,   349,-32768,   402,   403,
-32768,   374,   351,-32768,-32768,-32768,-32768,   404,-32768,    53,
    53,-32768,   405,   406,-32768,-32768,   411,   412,-32768
};

static const short yypgoto[] = {   188,
-32768,-32768,-32768,    -1,-32768,-32768,-32768,   293,-32768,-32768,
-32768,   317,  -171,-32768,   148,  -143,-32768,-32768,    94,   371,
   -59,   313,   -37,-32768,   375,   231,-32768,-32768,-32768,-32768,
  -176,-32768,   -51,  -163,   -88,-32768,  -132,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,   -12,   122,    44,-32768,  -266,
-32768,  -185,-32768,-32768,  -313,    86,-32768,   221,  -193,  -170,
   225,    57,   -93,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,   -87,  -127,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,  -168,
  -203,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768
};


#define	YYLAST		423


static const short yytable[] = {   128,
   140,   128,   134,   168,   235,   217,   168,   256,    24,   269,
    77,   117,   214,   245,   186,   250,   222,   200,   222,   291,
   190,     1,   264,   260,   364,   266,   196,   260,   164,   252,
    83,   164,   205,   165,   331,   275,   165,   279,    84,   252,
     7,   291,   128,   201,    85,   128,   191,   192,   193,   372,
   168,   164,   197,   128,   178,   232,   165,   301,     9,   222,
    98,   278,   166,   359,   278,   302,    99,   194,   202,   203,
   110,    43,   198,    44,    10,   199,   276,   300,   111,   277,
    25,   222,   166,   195,   278,   302,   233,   234,   303,   128,
   304,   136,   303,   305,   179,    48,   180,   181,   164,    91,
   102,  -179,   307,   165,   299,   128,   164,  -179,   182,   128,
   291,   165,   336,   314,   103,   256,     4,   137,   222,   104,
   152,   171,   138,   172,   282,   332,   153,   283,   117,   232,
   353,   278,   306,   284,   285,    26,    27,   252,   269,   278,
   173,   362,   252,    40,   256,   246,   340,   354,   354,   270,
   222,   286,   287,   288,   289,   271,   107,   108,   272,   164,
   233,   234,   164,   365,   165,   366,   252,   165,   252,    41,
   128,   252,    42,   273,   128,   232,   355,   219,   174,   271,
   175,    64,   272,    65,   369,   370,   256,   387,   283,   311,
     6,    60,   278,   166,   284,   285,   318,   176,    43,    92,
    44,    45,    46,   383,   384,    47,   233,   234,   252,    79,
    65,   112,   286,   287,   288,   289,   164,    80,   164,   143,
   144,   165,    48,   165,    81,    49,    58,   101,    50,   -33,
    51,   315,   315,    52,   315,   315,   315,   315,   105,   168,
    53,    54,   292,   -33,    55,   293,   294,   295,   -33,   278,
    73,   309,   187,   189,   128,   367,   106,   271,    74,    11,
   272,   -12,   -12,    75,   346,   346,   109,   346,   346,   346,
   346,   317,    23,   319,   320,   321,   322,   114,   128,   140,
    13,    14,    15,    16,    17,    18,    19,    20,    21,   310,
   116,    68,    68,    69,    69,   271,   127,   167,   272,    13,
    14,    15,    16,    17,    18,    19,    20,    21,   115,    87,
   118,  -163,   116,    68,    89,    69,  -170,   127,   159,   120,
   160,   127,   169,   127,   218,   220,   221,   243,   244,   243,
   290,   243,   297,   243,   344,   213,   345,   213,   347,   213,
   349,   213,   350,   213,   351,   213,   352,   329,   358,   213,
   361,   127,   375,    92,   379,   121,   122,   124,   126,   133,
   135,   139,   342,   209,   151,   170,   206,   141,   184,   185,
   150,   208,   210,   211,   213,   249,   251,   248,   258,   262,
   265,   267,   113,   280,   281,   212,   296,   308,   312,   243,
   326,   327,   145,   328,   329,   298,   333,   334,   337,   339,
   341,   348,   368,   371,   374,   376,   377,   382,   385,   386,
   388,   389,   146,   247,   325,   378,    71,   360,   263,   261,
   373,     0,    78
};

static const short yycheck[] = {    88,
    94,    90,    90,   131,   181,   177,   134,   193,    10,   203,
    48,    71,   176,   182,   158,   192,   180,     4,   182,   223,
     4,     3,   199,   194,   338,   202,     4,   198,     7,   193,
     1,     7,   165,    12,   301,   207,    12,   214,     9,   203,
     3,   245,   131,    30,    15,   134,    30,    31,    32,   363,
   178,     7,    30,   142,   142,     3,    12,    33,    28,   223,
     3,    40,    38,   330,    40,    41,     9,    51,    55,    56,
     1,    22,    50,    24,    44,    53,   209,   249,     9,   212,
     4,   245,    38,    67,    40,    41,    34,    35,   259,   178,
   262,    38,   263,   265,    45,    46,    47,    48,     7,     1,
     4,     3,   274,    12,   248,   194,     7,     9,    59,   198,
   314,    12,   306,   282,    18,   301,    27,    64,   282,    23,
    13,     1,    69,     3,    33,   302,    19,    36,   188,     3,
     4,    40,    33,    42,    43,     3,     4,   301,   332,    40,
    20,   335,   306,     4,   330,   183,   310,   324,   325,     4,
   314,    60,    61,    62,    63,    10,     8,     9,    13,     7,
    34,    35,     7,   340,    12,   342,   330,    12,   332,     4,
   259,   335,     4,     4,   263,     3,     4,   179,     1,    10,
     3,     1,    13,     3,   356,   357,   372,     0,    36,   278,
     3,     9,    40,    38,    42,    43,   285,    20,    22,     3,
    24,    25,    26,   380,   381,    29,    34,    35,   372,     1,
     3,     4,    60,    61,    62,    63,     7,     9,     7,     3,
     4,    12,    46,    12,    16,    49,     1,     4,    52,     4,
    54,   283,   284,    57,   286,   287,   288,   289,     4,   367,
    64,    65,    33,    18,    68,    36,    37,    38,    23,    40,
     1,     4,   159,   160,   343,   343,     4,    10,     9,     1,
    13,     3,     4,    14,   316,   317,     4,   319,   320,   321,
   322,   284,     1,   286,   287,   288,   289,     4,   367,   373,
     9,    10,    11,    12,    13,    14,    15,    16,    17,     4,
     8,     9,     9,    11,    11,    10,     3,     4,    13,     9,
    10,    11,    12,    13,    14,    15,    16,    17,     4,     1,
     4,     3,     8,     9,     1,    11,     3,     3,     9,     4,
    11,     3,     4,     3,     4,     3,     4,     3,     4,     3,
     4,     3,     4,     3,     4,     3,     4,     3,     4,     3,
     4,     3,     4,     3,     4,     3,     4,     3,     4,     3,
     4,     3,     4,     3,     4,     4,     4,     4,     4,     4,
     4,     4,    39,    20,     4,     3,     3,     9,     4,     8,
    11,     4,     4,     4,     3,     3,     3,    11,     3,     3,
     3,     3,    66,     4,     4,    20,     4,     4,     4,     3,
     3,     3,   100,     4,     3,   248,     4,     4,     4,     4,
     4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
     0,     0,   100,   183,   293,   372,    46,   332,   198,   195,
   364,    -1,    48
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
#line 1666 "grammar.cc"

  switch (yyn) {

case 5:
#line 125 "ppddl.y"
{
          log_error((char*)"syntax error in domain");
          yyerrok;
      ;
    break;}
case 13:
#line 142 "ppddl.y"
{ domain_name_ = yyvsp[-1].sym->text; ;
    break;}
case 14:
#line 148 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 15:
#line 149 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 16:
#line 150 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 17:
#line 151 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 18:
#line 152 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 19:
#line 153 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 20:
#line 154 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 21:
#line 155 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 22:
#line 156 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 23:
#line 160 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 24:
#line 161 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 25:
#line 165 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 26:
#line 166 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 27:
#line 170 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 28:
#line 171 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 30:
#line 178 "ppddl.y"
{
          log_error((char*)"syntax error in requirements declaration.");
          yyerrok;
      ;
    break;}
case 31:
#line 185 "ppddl.y"
{ declare_lw1_translation(); ;
    break;}
case 35:
#line 194 "ppddl.y"
{
          log_error((char*)"syntax error in (:predicates ...)");
          yyerrok;
      ;
    break;}
case 38:
#line 206 "ppddl.y"
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
#line 214 "ppddl.y"
{
          log_error((char*)"syntax error in predicate declaration");
          yyerrok;
      ;
    break;}
case 41:
#line 222 "ppddl.y"
{
          // must reverse parameter list
          var_symbol_vec tmp_list(*yyvsp[0].vparam);
          yyvsp[0].vparam->clear();
          yyvsp[0].vparam->insert(yyvsp[0].vparam->end(), tmp_list.rbegin(), tmp_list.rend());
          yyval.vparam = yyvsp[0].vparam;
      ;
    break;}
case 42:
#line 229 "ppddl.y"
{ yyval.vparam = new var_symbol_vec; ;
    break;}
case 43:
#line 233 "ppddl.y"
{
          set_variable_type(*yyvsp[0].vparam, yyvsp[0].vparam->size(), dom_top_type_);
          yyval.vparam = yyvsp[0].vparam;
      ;
    break;}
case 44:
#line 240 "ppddl.y"
{
          set_variable_type(*yyvsp[-3].vparam, yyvsp[-3].vparam->size(), static_cast<TypeSymbol*>(yyvsp[-1].sym->val));
          yyvsp[0].vparam->insert(yyvsp[0].vparam->end(), yyvsp[-3].vparam->begin(), yyvsp[-3].vparam->end());
          delete yyvsp[-3].vparam;
          yyval.vparam = yyvsp[0].vparam;
      ;
    break;}
case 45:
#line 246 "ppddl.y"
{
          set_variable_type(*yyvsp[-2].vparam, yyvsp[-2].vparam->size(), static_cast<TypeSymbol*>(yyvsp[0].sym->val));
          yyval.vparam = yyvsp[-2].vparam;
      ;
    break;}
case 46:
#line 253 "ppddl.y"
{
          yyvsp[0].vparam->push_back(static_cast<VariableSymbol*>(yyvsp[-1].vsym));
          yyval.vparam = yyvsp[0].vparam;
      ;
    break;}
case 47:
#line 257 "ppddl.y"
{ yyval.vparam = new var_symbol_vec; yyval.vparam->push_back(yyvsp[0].vsym); ;
    break;}
case 48:
#line 261 "ppddl.y"
{
          VariableSymbol *var = new VariableSymbol(yyvsp[0].sym->text);
          yyvsp[0].sym->val = var;
          yyval.vsym = var;
      ;
    break;}
case 49:
#line 266 "ppddl.y"
{
          std::string msg("variable '");
          msg += yyvsp[0].sym->text;
          msg += "' shadows variable in outer scope: this is not supported!";
          log_error((char*)msg.c_str());
          yyerrok;
      ;
    break;}
case 51:
#line 279 "ppddl.y"
{
          set_type_type(dom_types_, dom_types_.size(), dom_top_type_);
      ;
    break;}
case 52:
#line 285 "ppddl.y"
{
          set_type_type(dom_types_, dom_types_.size(), static_cast<TypeSymbol*>(yyvsp[-1].sym->val));
      ;
    break;}
case 53:
#line 288 "ppddl.y"
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
#line 301 "ppddl.y"
{ ;
    break;}
case 58:
#line 306 "ppddl.y"
{
          yyvsp[0].sym->val = new TypeSymbol(yyvsp[0].sym->text);
          dom_types_.push_back(static_cast<TypeSymbol*>(yyvsp[0].sym->val));
      ;
    break;}
case 63:
#line 322 "ppddl.y"
{
          set_constant_type(dom_constants_, dom_constants_.size(), static_cast<TypeSymbol*>(yyvsp[0].sym->val));
      ;
    break;}
case 66:
#line 330 "ppddl.y"
{
          set_constant_type(dom_constants_, dom_constants_.size(), dom_top_type_);
      ;
    break;}
case 67:
#line 336 "ppddl.y"
{
          yyvsp[0].sym->val = new Symbol(yyvsp[0].sym->text);
          dom_constants_.push_back(static_cast<Symbol*>(yyvsp[0].sym->val));
      ;
    break;}
case 68:
#line 340 "ppddl.y"
{
          yyvsp[0].sym->val = new Symbol(yyvsp[0].sym->text);
          dom_constants_.push_back(static_cast<Symbol*>(yyvsp[0].sym->val));
      ;
    break;}
case 70:
#line 350 "ppddl.y"
{
          if( type_ == replanner ) {
              log_error((char*)"':axiom' is not a valid element in k-replanner.");
              yyerrok;
          }
      ;
    break;}
case 71:
#line 356 "ppddl.y"
{
          if( type_ == cp2fsc ) {
              log_error((char*)"':sensor' is not a valid element in cp2fsc.");
              yyerrok;
          }
      ;
    break;}
case 72:
#line 362 "ppddl.y"
{
          if( type_ == replanner ) {
              log_error((char*)"':observable' is not a valid element in k-replanner.");
              yyerrok;
          }
      ;
    break;}
case 73:
#line 368 "ppddl.y"
{
          if( type_ == replanner ) {
              log_error((char*)"':sticky' is not a valid element in k-replanner.");
              yyerrok;
          }
      ;
    break;}
case 74:
#line 374 "ppddl.y"
{
          declare_lw1_translation();
          if( type_ == cp2fsc ) {
              log_error((char*)"':sensor' is not a valid element in cp2fsc.");
              yyerrok;
          }
      ;
    break;}
case 75:
#line 386 "ppddl.y"
{
          Action *na = new Action(yyvsp[0].sym->text);
          dom_actions_.push_back(na);
      ;
    break;}
case 76:
#line 390 "ppddl.y"
{
          clear_param(dom_actions_.back()->param_);
          yyvsp[-3].sym->val = dom_actions_.back();
      ;
    break;}
case 77:
#line 394 "ppddl.y"
{
          log_error((char*)"syntax error in action declaration");
          yyerrok;
      ;
    break;}
case 78:
#line 401 "ppddl.y"
{
          dom_actions_.back()->param_ = *yyvsp[-1].vparam;
          delete yyvsp[-1].vparam;
      ;
    break;}
case 79:
#line 405 "ppddl.y"
{ dom_actions_.back()->precondition_ = yyvsp[0].condition; ;
    break;}
case 80:
#line 406 "ppddl.y"
{ dom_actions_.back()->effect_ = yyvsp[0].effect; ;
    break;}
case 81:
#line 407 "ppddl.y"
{
          declare_clg_translation();
          dom_actions_.back()->observe_ = new AndEffect(*yyvsp[0].effect_vec);
          delete yyvsp[0].effect_vec;
      ;
    break;}
case 82:
#line 412 "ppddl.y"
{
          declare_lw1_translation();
          dom_actions_.back()->sensing_proxy_ = yyvsp[0].sensing_proxy_list;
      ;
    break;}
case 90:
#line 429 "ppddl.y"
{ yyval.condition = new Constant(true); ;
    break;}
case 91:
#line 430 "ppddl.y"
{ yyval.condition = new Constant(false); ;
    break;}
case 92:
#line 434 "ppddl.y"
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
#line 450 "ppddl.y"
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
#line 462 "ppddl.y"
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
#line 474 "ppddl.y"
{
          const_cast<Literal*>(static_cast<const Literal*>(yyvsp[-1].atom))->negated_ = true;
          yyval.atom = yyvsp[-1].atom;
      ;
    break;}
case 98:
#line 481 "ppddl.y"
{
          if( yyvsp[0].sym->val == 0 )
              log_error((char*)"undeclared variable in atom args list");
          else
              yyvsp[-1].param->push_back(static_cast<VariableSymbol*>(yyvsp[0].sym->val));
          yyval.param = yyvsp[-1].param;
      ;
    break;}
case 99:
#line 488 "ppddl.y"
{
          yyvsp[-1].param->push_back(static_cast<Symbol*>(yyvsp[0].sym->val));
          yyval.param = yyvsp[-1].param;
      ;
    break;}
case 100:
#line 492 "ppddl.y"
{ yyval.param = new PDDL_Base::symbol_vec; ;
    break;}
case 101:
#line 496 "ppddl.y"
{
          yyval.condition = new And(*yyvsp[-1].condition_vec);
          delete yyvsp[-1].condition_vec;
      ;
    break;}
case 102:
#line 503 "ppddl.y"
{
          yyval.condition = new Or(*yyvsp[-1].condition_vec);
          delete yyvsp[-1].condition_vec;
      ;
    break;}
case 103:
#line 510 "ppddl.y"
{
          schema_.push_back(new ForallCondition);
      ;
    break;}
case 104:
#line 513 "ppddl.y"
{
          schema_.back()->param_ = *yyvsp[-1].vparam;
          delete yyvsp[-1].vparam;
      ;
    break;}
case 105:
#line 517 "ppddl.y"
{
          assert(dynamic_cast<ForallCondition*>(schema_.back()) != 0);
          ForallCondition *forall_condition = static_cast<ForallCondition*>(schema_.back());
          schema_.pop_back();
          forall_condition->condition_ = yyvsp[-1].condition;
          clear_param(forall_condition->param_);
          yyval.condition = forall_condition;
      ;
    break;}
case 106:
#line 528 "ppddl.y"
{
          schema_.push_back(new ExistsCondition);
      ;
    break;}
case 107:
#line 531 "ppddl.y"
{
          schema_.back()->param_ = *yyvsp[-1].vparam;
          delete yyvsp[-1].vparam;
      ;
    break;}
case 108:
#line 535 "ppddl.y"
{
          assert(dynamic_cast<ExistsCondition*>(schema_.back()) != 0);
          ExistsCondition *exists_condition = static_cast<ExistsCondition*>(schema_.back());
          schema_.pop_back();
          exists_condition->condition_ = yyvsp[-1].condition;
          clear_param(exists_condition->param_);
          yyval.condition = exists_condition;
      ;
    break;}
case 109:
#line 546 "ppddl.y"
{
          yyvsp[-1].condition_vec->push_back(yyvsp[0].condition);
          yyval.condition_vec = yyvsp[-1].condition_vec;
      ;
    break;}
case 110:
#line 550 "ppddl.y"
{
          condition_vec *cond_vec = new condition_vec;
          cond_vec->push_back(yyvsp[0].condition);
          yyval.condition_vec = cond_vec;
      ;
    break;}
case 111:
#line 558 "ppddl.y"
{
          yyvsp[-1].condition_vec->push_back(yyvsp[0].condition);
          yyval.condition_vec = yyvsp[-1].condition_vec;
      ;
    break;}
case 112:
#line 562 "ppddl.y"
{
          condition_vec *cond_vec = new condition_vec;
          cond_vec->push_back(yyvsp[0].condition);
          yyval.condition_vec = cond_vec;
      ;
    break;}
case 114:
#line 571 "ppddl.y"
{
          yyval.effect = new AndEffect(*yyvsp[-1].effect_vec);
          delete yyvsp[-1].effect_vec;
      ;
    break;}
case 115:
#line 578 "ppddl.y"
{
          yyvsp[-1].effect_vec->push_back(yyvsp[0].effect);
          yyval.effect_vec = yyvsp[-1].effect_vec;
      ;
    break;}
case 116:
#line 582 "ppddl.y"
{
          yyval.effect_vec = new effect_vec;
          yyval.effect_vec->push_back(yyvsp[0].effect);
      ;
    break;}
case 120:
#line 595 "ppddl.y"
{ yyval.effect = new ConditionalEffect(yyvsp[-2].condition, yyvsp[-1].effect); ;
    break;}
case 121:
#line 599 "ppddl.y"
{
          schema_.push_back(new ForallEffect);
      ;
    break;}
case 122:
#line 602 "ppddl.y"
{
          schema_.back()->param_ = *yyvsp[-1].vparam;
          delete yyvsp[-1].vparam;
      ;
    break;}
case 123:
#line 606 "ppddl.y"
{
          assert(dynamic_cast<ForallEffect*>(schema_.back()) != 0);
          ForallEffect *forall_effect = static_cast<ForallEffect*>(schema_.back());
          schema_.pop_back();
          forall_effect->effect_ = yyvsp[-1].effect;
          clear_param(forall_effect->param_);
          yyval.effect = forall_effect;
      ;
    break;}
case 124:
#line 617 "ppddl.y"
{
          assert(!schema_.empty());
          schema_.back()->such_that_ = yyvsp[0].condition;
      ;
    break;}
case 126:
#line 625 "ppddl.y"
{
          yyval.effect = new AndEffect(*yyvsp[-1].effect_vec);
          delete yyvsp[-1].effect_vec;
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
{
          yyvsp[-1].effect_vec->push_back(yyvsp[0].effect);
          yyval.effect_vec = yyvsp[-1].effect_vec;
      ;
    break;}
case 131:
#line 648 "ppddl.y"
{
          yyval.effect_vec = new effect_vec;
          yyval.effect_vec->push_back(yyvsp[0].effect);
      ;
    break;}
case 132:
#line 655 "ppddl.y"
{ yyval.effect = new AtomicEffect(*yyvsp[0].atom); delete yyvsp[0].atom; ;
    break;}
case 133:
#line 659 "ppddl.y"
{ yyval.effect = new AtomicEffect(*yyvsp[0].atom); delete yyvsp[0].atom; ;
    break;}
case 135:
#line 664 "ppddl.y"
{ yyval.sensing_proxy_list = 0; ;
    break;}
case 136:
#line 668 "ppddl.y"
{
          sensing_proxy_vec *list_sensing_proxy = const_cast<sensing_proxy_vec*>(yyvsp[-1].sensing_proxy_list);
          list_sensing_proxy->push_back(yyvsp[0].sensing_proxy);
          yyval.sensing_proxy_list = list_sensing_proxy;
      ;
    break;}
case 137:
#line 673 "ppddl.y"
{
          sensing_proxy_vec *list_sensing_proxy = new sensing_proxy_vec;
          list_sensing_proxy->push_back(yyvsp[0].sensing_proxy);
          yyval.sensing_proxy_list = list_sensing_proxy;
      ;
    break;}
case 138:
#line 681 "ppddl.y"
{ yyval.sensing_proxy = new BasicSensingModel(yyvsp[0].sensing_model); ;
    break;}
case 140:
#line 686 "ppddl.y"
{
          schema_.push_back(new ForallSensing);
      ;
    break;}
case 141:
#line 689 "ppddl.y"
{
          schema_.back()->param_ = *yyvsp[-1].vparam;
          delete yyvsp[-1].vparam;
      ;
    break;}
case 142:
#line 693 "ppddl.y"
{
          assert(dynamic_cast<ForallSensing*>(schema_.back()) != 0);
          ForallSensing *forall_sensing = static_cast<ForallSensing*>(schema_.back());
          schema_.pop_back();
          forall_sensing->sensing_ = *yyvsp[-1].sensing_proxy_list;
          delete yyvsp[-1].sensing_proxy_list;
          clear_param(forall_sensing->param_);
          yyval.sensing_proxy = forall_sensing;
      ;
    break;}
case 143:
#line 705 "ppddl.y"
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
#line 717 "ppddl.y"
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
#line 732 "ppddl.y"
{
          assert(static_cast<Symbol*>(yyvsp[-1].sym->val)->sym_class_ == sym_varname);
          const Variable *variable = static_cast<Variable*>(yyvsp[-1].sym->val);
          assert(dynamic_cast<const StateVariable*>(variable) != 0);
          yyval.sensing_model = new SensingModelForStateVariable(static_cast<const StateVariable*>(variable));
      ;
    break;}
case 146:
#line 738 "ppddl.y"
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
#line 747 "ppddl.y"
{
          log_error((char*)"syntax error in sensing declaration for ':variable'");
          yyerrok;
      ;
    break;}
case 148:
#line 751 "ppddl.y"
{
          log_error((char*)"syntax error in sensing declaration for ':model-for'");
          yyerrok;
      ;
    break;}
case 149:
#line 758 "ppddl.y"
{
          Axiom *nr = new Axiom(yyvsp[0].sym->text);
          dom_axioms_.push_back(nr);
      ;
    break;}
case 150:
#line 762 "ppddl.y"
{
          clear_param(dom_axioms_.back()->param_);
          yyvsp[-3].sym->val = dom_axioms_.back();
      ;
    break;}
case 151:
#line 766 "ppddl.y"
{
          log_error((char*)"syntax error in axiom declaration");
          yyerrok;
      ;
    break;}
case 152:
#line 773 "ppddl.y"
{
          dom_axioms_.back()->param_ = *yyvsp[-1].vparam;
          delete yyvsp[-1].vparam;
      ;
    break;}
case 153:
#line 777 "ppddl.y"
{ dom_axioms_.back()->body_ = yyvsp[0].condition; ;
    break;}
case 154:
#line 778 "ppddl.y"
{ dom_axioms_.back()->head_ = yyvsp[0].effect; ;
    break;}
case 156:
#line 783 "ppddl.y"
{
          Sensor *nr = new Sensor(yyvsp[0].sym->text);
          dom_sensors_.push_back(nr);
      ;
    break;}
case 157:
#line 787 "ppddl.y"
{
          clear_param(dom_sensors_.back()->param_);
          yyvsp[-3].sym->val = dom_sensors_.back();
      ;
    break;}
case 158:
#line 791 "ppddl.y"
{
          log_error((char*)"syntax error in sensor declaration");
          yyerrok;
      ;
    break;}
case 159:
#line 798 "ppddl.y"
{
          dom_sensors_.back()->param_ = *yyvsp[-1].vparam;
          delete yyvsp[-1].vparam;
      ;
    break;}
case 160:
#line 802 "ppddl.y"
{
          dom_sensors_.back()->condition_ = yyvsp[0].condition;
      ;
    break;}
case 161:
#line 805 "ppddl.y"
{
          dom_sensors_.back()->sense_ = new AndEffect(*yyvsp[0].effect_vec);
          delete yyvsp[0].effect_vec;
      ;
    break;}
case 163:
#line 813 "ppddl.y"
{
          Observable *obs = new Observable;
          dom_observables_.push_back(obs);
          effect_vec_ptr_ = &obs->observables_;
      ;
    break;}
case 165:
#line 819 "ppddl.y"
{
          log_error((char*)"syntax error in observable declaration");
          yyerrok;
      ;
    break;}
case 166:
#line 826 "ppddl.y"
{
          effect_vec_ptr_->push_back(yyvsp[0].effect);
      ;
    break;}
case 167:
#line 829 "ppddl.y"
{
          effect_vec_ptr_->push_back(yyvsp[0].effect);
      ;
    break;}
case 170:
#line 840 "ppddl.y"
{
          Sticky *sticky = new Sticky;
          dom_stickies_.push_back(sticky);
          effect_vec_ptr_ = &sticky->stickies_;
      ;
    break;}
case 172:
#line 846 "ppddl.y"
{
          log_error((char*)"syntax error in sticky declaration");
          yyerrok;
      ;
    break;}
case 173:
#line 853 "ppddl.y"
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
#line 862 "ppddl.y"
{
          yyvsp[-3].sym->val = multivalued_variables_.back();
      ;
    break;}
case 175:
#line 865 "ppddl.y"
{
          Variable *var = 0;
          if( yyvsp[-2].ival == 0 )
              var = new StateVariable(yyvsp[0].sym->text);
          else
              var = new ObsVariable(yyvsp[0].sym->text);
          schema_.push_back(var);
          effect_vec_ptr_ = &var->domain_;
      ;
    break;}
case 176:
#line 874 "ppddl.y"
{
          schema_.back()->param_ = *yyvsp[-1].vparam;
          delete yyvsp[-1].vparam;
      ;
    break;}
case 177:
#line 878 "ppddl.y"
{
          assert(dynamic_cast<Variable*>(schema_.back()) != 0);
          Variable *variable = static_cast<Variable*>(schema_.back());
          schema_.pop_back();
          clear_param(variable->param_);
          yyvsp[-7].sym->val = variable;
          multivalued_variables_.push_back(variable);
      ;
    break;}
case 178:
#line 886 "ppddl.y"
{
          log_error((char*)"syntax error in state variable declaration");
          yyerrok;
      ;
    break;}
case 179:
#line 893 "ppddl.y"
{ yyval.ival = 0; ;
    break;}
case 180:
#line 894 "ppddl.y"
{ yyval.ival = 1; ;
    break;}
case 181:
#line 900 "ppddl.y"
{
          declare_lw1_translation();
          default_sensing_proxy_ = yyvsp[-1].sensing_proxy_list;
      ;
    break;}
case 182:
#line 910 "ppddl.y"
{
          problem_name_ = yyvsp[-1].sym->text;
      ;
    break;}
case 184:
#line 914 "ppddl.y"
{
          log_error((char*)"syntax error in problem definition.");
          yyerrok;
      ;
    break;}
case 193:
#line 932 "ppddl.y"
{ dom_init_ = *yyvsp[-1].ilist; delete yyvsp[-1].ilist; ;
    break;}
case 194:
#line 933 "ppddl.y"
{ dom_init_ = *yyvsp[-2].ilist; delete yyvsp[-2].ilist; ;
    break;}
case 195:
#line 937 "ppddl.y"
{
          init_element_vec *ilist = const_cast<init_element_vec*>(yyvsp[-1].ilist);
          if( yyvsp[0].ielem != 0 ) ilist->push_back(const_cast<InitElement*>(yyvsp[0].ielem));
          yyval.ilist = ilist;
      ;
    break;}
case 196:
#line 942 "ppddl.y"
{
          init_element_vec *ilist = new init_element_vec;
          if( yyvsp[0].ielem != 0 ) ilist->push_back(const_cast<InitElement*>(yyvsp[0].ielem));
          yyval.ilist = ilist;
      ;
    break;}
case 197:
#line 950 "ppddl.y"
{ yyval.ielem = new InitLiteral(*yyvsp[0].atom); ;
    break;}
case 198:
#line 951 "ppddl.y"
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
case 199:
#line 962 "ppddl.y"
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
case 200:
#line 973 "ppddl.y"
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
case 201:
#line 984 "ppddl.y"
{
          yyval.ielem = 0; // when fixing this, remove condition '$2 != 0' and '$1 != 0' above (in single_init_element)
          std::cout << Utils::warning()
                    << Utils::magenta() << "(clg) ignoring '" << yyvsp[0].unknown->to_string() << "'"
                    << Utils::normal() << std::endl;
          //$$ = new InitUnknown(*$1);
          delete yyvsp[0].unknown;
      ;
    break;}
case 202:
#line 995 "ppddl.y"
{
          //$$ = new Invariant(Invariant::AT_LEAST_ONE, *static_cast<const And*>($3));
          yyval.invariant = new Invariant(Invariant::AT_LEAST_ONE, *yyvsp[-1].condition_vec);
          delete yyvsp[-1].condition_vec;
      ;
    break;}
case 203:
#line 1000 "ppddl.y"
{
          //$$ = new Invariant(Invariant::AT_LEAST_ONE, *static_cast<const And*>($3));
          yyval.invariant = new Invariant(Invariant::AT_LEAST_ONE, *yyvsp[-1].condition_vec);
          delete yyvsp[-1].condition_vec;
      ;
    break;}
case 204:
#line 1008 "ppddl.y"
{
          //$$ = new Invariant(Invariant::AT_MOST_ONE, *static_cast<const And*>($3));
          yyval.invariant = new Invariant(Invariant::AT_MOST_ONE, *yyvsp[-1].condition_vec);
          delete yyvsp[-1].condition_vec;
      ;
    break;}
case 205:
#line 1016 "ppddl.y"
{
          yyval.invariant = new Invariant(Invariant::EXACTLY_ONE, *yyvsp[-1].condition_vec);
          delete yyvsp[-1].condition_vec;
      ;
    break;}
case 209:
#line 1029 "ppddl.y"
{
          yyval.clause = new Clause(*yyvsp[-1].condition_vec);
          delete yyvsp[-1].condition_vec;
      ;
    break;}
case 210:
#line 1036 "ppddl.y"
{
          yyval.oneof = new Oneof(*yyvsp[-1].condition_vec);
          delete yyvsp[-1].condition_vec;
      ;
    break;}
case 211:
#line 1043 "ppddl.y"
{
          yyval.unknown = new Unknown(*yyvsp[-1].atom);
          delete yyvsp[-1].atom;
      ;
    break;}
case 212:
#line 1050 "ppddl.y"
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
case 213:
#line 1059 "ppddl.y"
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
case 214:
#line 1071 "ppddl.y"
{ dom_goal_ = yyvsp[-1].condition; ;
    break;}
case 215:
#line 1077 "ppddl.y"
{
          const_cast<And*>(static_cast<const And*>(yyvsp[-1].condition))->push_back(yyvsp[0].condition);
          yyval.condition = yyvsp[-1].condition;
      ;
    break;}
case 216:
#line 1081 "ppddl.y"
{
          And *cond = new And;
          cond->push_back(yyvsp[0].condition);
          yyval.condition = cond;
      ;
    break;}
case 217:
#line 1090 "ppddl.y"
{ yyval.condition = new Literal(*yyvsp[0].atom); delete yyvsp[0].atom; ;
    break;}
case 218:
#line 1091 "ppddl.y"
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
#line 2972 "grammar.cc"
#line 1094 "ppddl.y"


