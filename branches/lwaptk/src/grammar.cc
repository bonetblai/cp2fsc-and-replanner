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
    effect_vec *effect_vec_ptr_;
#line 24 "ppddl.y"

#include <stdlib.h>
#include <string.h>
#include <list>
#include <sstream>
#include "base.h"
#include "utils.h"

#pragma GCC diagnostic ignored "-Wpragmas"
#pragma GCC diagnostic ignored "-Wdeprecated-writable-strings"
#pragma GCC diagnostic ignored "-Wchar-subscripts"
#pragma GCC diagnostic ignored "-Wwrite-strings"
#pragma GCC diagnostic ignored "-Wuninitialized"
#pragma GCC diagnostic ignored "-Wsign-compare"

#line 40 "ppddl.y"
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
    const PDDL_Base::Unknown          *unknown;
    const PDDL_Base::init_element_vec *ilist;
    const PDDL_Base::InitElement      *ielem;
    int                               ival;
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
#line 190 "grammar.cc"

#line 117 "/usr/local/lib/bison.cc"
/*  YY_PDDL_Parser_PURE */
#endif

/* section apres lecture def, avant lecture grammaire S2 */

/* #line 121 "/usr/local/lib/bison.cc" */
#line 199 "grammar.cc"

#line 121 "/usr/local/lib/bison.cc"
/* prefix */
#ifndef YY_PDDL_Parser_DEBUG

/* #line 123 "/usr/local/lib/bison.cc" */
#line 206 "grammar.cc"

#line 123 "/usr/local/lib/bison.cc"
/* YY_PDDL_Parser_DEBUG */
#endif


#ifndef YY_PDDL_Parser_LSP_NEEDED

/* #line 128 "/usr/local/lib/bison.cc" */
#line 216 "grammar.cc"

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
#line 329 "grammar.cc"
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
#define	KW_SENSING_MODEL	319
#define	KW_DEFAULT_SENSING_MODEL	320


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
#line 442 "grammar.cc"
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
static const int KW_SENSING_MODEL;
static const int KW_DEFAULT_SENSING_MODEL;


#line 280 "/usr/local/lib/bison.cc"
 /* decl const */
#else
enum YY_PDDL_Parser_ENUM_TOKEN { YY_PDDL_Parser_NULL_TOKEN=0

/* #line 283 "/usr/local/lib/bison.cc" */
#line 514 "grammar.cc"
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
	,KW_SENSING_MODEL=319
	,KW_DEFAULT_SENSING_MODEL=320


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
#line 614 "grammar.cc"
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
const int YY_PDDL_Parser_CLASS::KW_SENSING_MODEL=319;
const int YY_PDDL_Parser_CLASS::KW_DEFAULT_SENSING_MODEL=320;


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
#line 694 "grammar.cc"


#define	YYFINAL		345
#define	YYFLAG		-32768
#define	YYNTBASE	66

#define YYTRANSLATE(x) ((unsigned)(x) <= 320 ? yytranslate[x] : 158)

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
    56,    57,    58,    59,    60,    61,    62,    63,    64,    65
};

#if YY_PDDL_Parser_DEBUG != 0
static const short yyprhs[] = {     0,
     0,     3,     6,     7,    13,    19,    22,    25,    28,    31,
    34,    37,    38,    43,    45,    47,    49,    51,    53,    55,
    57,    59,    61,    63,    65,    67,    69,    71,    73,    75,
    77,    82,    87,    90,    93,    94,    99,   104,   107,   109,
   114,   118,   120,   122,   123,   125,   130,   134,   137,   139,
   141,   143,   148,   153,   158,   163,   164,   167,   169,   171,
   173,   178,   183,   188,   193,   194,   200,   201,   203,   206,
   208,   210,   212,   214,   216,   218,   220,   221,   228,   233,
   239,   243,   247,   251,   255,   256,   258,   260,   262,   264,
   266,   268,   270,   275,   280,   285,   288,   291,   292,   297,
   302,   303,   304,   314,   317,   319,   322,   324,   326,   331,
   334,   336,   338,   340,   342,   348,   349,   350,   360,   365,
   367,   370,   372,   375,   377,   379,   381,   383,   384,   385,
   392,   397,   403,   407,   411,   412,   413,   420,   425,   431,
   435,   439,   440,   441,   447,   452,   455,   457,   459,   461,
   462,   468,   473,   474,   481,   482,   492,   497,   499,   501,
   506,   507,   509,   510,   515,   516,   526,   533,   539,   542,
   545,   548,   551,   554,   555,   559,   564,   572,   575,   577,
   579,   581,   583,   585,   587,   592,   597,   602,   607,   609,
   611,   613,   618,   623,   628,   633,   637,   642,   650,   653,
   655,   657
};

static const short yyrhs[] = {    67,
    66,     0,   141,    66,     0,     0,     3,    27,    69,    68,
     4,     0,     3,    27,    69,     1,     4,     0,    68,    75,
     0,    68,    85,     0,    68,    89,     0,    68,    77,     0,
    68,    94,     0,    68,   140,     0,     0,     3,    28,    70,
     4,     0,     9,     0,    10,     0,    11,     0,    12,     0,
    13,     0,    14,     0,    15,     0,    16,     0,    17,     0,
     9,     0,    20,     0,     9,     0,    14,     0,     9,     0,
    16,     0,     9,     0,    15,     0,     3,    22,    76,     4,
     0,     3,    22,     1,     4,     0,    76,    23,     0,    76,
    18,     0,     0,     3,    25,    78,     4,     0,     3,    25,
     1,     4,     0,    78,    79,     0,    79,     0,     3,     9,
    80,     4,     0,     3,     1,     4,     0,    81,     0,    82,
     0,     0,    83,     0,    83,     8,    11,    82,     0,    83,
     8,    11,     0,    84,    83,     0,    84,     0,    19,     0,
    13,     0,     3,    26,    87,     4,     0,     3,    26,    86,
     4,     0,    87,     8,    11,    86,     0,    87,     8,     9,
    86,     0,     0,    87,    88,     0,    88,     0,    11,     0,
     9,     0,     3,    24,    90,     4,     0,     3,    43,    90,
     4,     0,     3,    24,    92,     4,     0,     3,    43,    92,
     4,     0,     0,    93,     8,    11,    91,    90,     0,     0,
    93,     0,    93,     9,     0,     9,     0,    95,     0,   124,
     0,   127,     0,   130,     0,   134,     0,   136,     0,     0,
     3,    29,    72,    96,    97,     4,     0,     3,    29,     1,
     4,     0,    97,    30,     3,    80,     4,     0,    97,    31,
    98,     0,    97,    32,   111,     0,    97,    48,   120,     0,
    97,    64,   123,     0,     0,    99,     0,   104,     0,   105,
     0,   106,     0,   100,     0,   101,     0,   102,     0,     3,
    12,   103,     4,     0,     3,     7,   103,     4,     0,     3,
    37,   101,     4,     0,   103,    13,     0,   103,    10,     0,
     0,     3,    33,   110,     4,     0,     3,    34,   110,     4,
     0,     0,     0,     3,    36,     3,   107,    80,     4,   108,
    98,     4,     0,   109,    99,     0,    99,     0,   110,    98,
     0,    98,     0,   113,     0,     3,    33,   112,     4,     0,
   112,   113,     0,   113,     0,   121,     0,   114,     0,   115,
     0,     3,    38,    98,   118,     4,     0,     0,     0,     3,
    36,     3,   116,    80,     4,   117,   111,     4,     0,     3,
    33,   119,     4,     0,   121,     0,   119,   121,     0,   121,
     0,   120,   122,     0,   122,     0,   100,     0,   101,     0,
   111,     0,     0,     0,     3,    49,    74,   125,   126,     4,
     0,     3,    49,     1,     4,     0,   126,    30,     3,    80,
     4,     0,   126,    52,    98,     0,   126,    53,   118,     0,
     0,     0,     3,    46,    73,   128,   129,     4,     0,     3,
    46,     1,     4,     0,   129,    30,     3,    80,     4,     0,
   129,    50,    98,     0,   129,    47,   120,     0,     0,     0,
     3,    51,   131,   132,     4,     0,     3,    51,     1,     4,
     0,   132,   133,     0,   133,     0,   122,     0,   115,     0,
     0,     3,    54,   135,   132,     4,     0,     3,    54,     1,
     4,     0,     0,     3,   139,    71,   137,   132,     4,     0,
     0,     3,   139,     3,    71,    80,     4,   138,   132,     4,
     0,     3,    61,     1,     4,     0,    61,     0,    62,     0,
    30,     3,    80,     4,     0,     0,    51,     0,     0,     3,
    65,   123,     4,     0,     0,     3,    27,     3,    41,    70,
     4,   142,   143,     4,     0,     3,    27,     3,    41,     1,
     4,     0,   143,     3,    42,    70,     4,     0,   143,    75,
     0,   143,    89,     0,   143,   144,     0,   143,   154,     0,
   143,   155,     0,     0,     3,    44,     4,     0,     3,    44,
   145,     4,     0,     3,    44,     3,    33,   145,     4,     4,
     0,   145,   146,     0,   146,     0,   100,     0,   150,     0,
   151,     0,   152,     0,   153,     0,     3,    57,   109,     4,
     0,     3,    58,   109,     4,     0,     3,    59,   109,     4,
     0,     3,    60,   109,     4,     0,   147,     0,   148,     0,
   149,     0,     3,    34,   109,     4,     0,     3,    39,   109,
     4,     0,     3,    40,   101,     4,     0,     3,    56,   145,
     4,     0,     3,    56,     4,     0,     3,    45,   157,     4,
     0,     3,    45,     3,    33,   156,     4,     4,     0,   156,
   157,     0,   157,     0,   101,     0,   102,     0
};

#endif

#if YY_PDDL_Parser_DEBUG != 0
static const short yyrline[] = { 0,
   109,   111,   112,   115,   117,   123,   125,   126,   127,   128,
   129,   130,   133,   139,   141,   142,   143,   144,   145,   146,
   147,   148,   151,   153,   156,   158,   161,   163,   166,   168,
   173,   175,   181,   183,   184,   189,   191,   197,   199,   202,
   211,   217,   219,   226,   229,   236,   243,   249,   254,   257,
   263,   274,   276,   281,   285,   293,   296,   298,   301,   303,
   311,   313,   314,   315,   318,   323,   323,   326,   332,   337,
   345,   347,   353,   359,   365,   371,   382,   387,   391,   397,
   402,   403,   404,   409,   413,   416,   418,   419,   420,   423,
   434,   436,   439,   452,   463,   470,   478,   482,   485,   492,
   499,   503,   507,   515,   520,   527,   532,   539,   541,   547,
   552,   558,   560,   561,   564,   568,   572,   576,   584,   589,
   592,   597,   603,   608,   614,   618,   622,   624,   627,   632,
   636,   642,   647,   648,   649,   652,   657,   661,   667,   672,
   675,   679,   682,   688,   689,   695,   699,   704,   706,   709,
   715,   716,   722,   733,   736,   748,   752,   758,   760,   763,
   768,   771,   776,   781,   791,   795,   796,   802,   804,   805,
   806,   807,   808,   809,   812,   814,   815,   818,   824,   831,
   833,   844,   855,   866,   876,   882,   889,   897,   904,   906,
   907,   910,   917,   924,   931,   941,   952,   954,   957,   962,
   970,   972
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
"KW_OBS_VARIABLE","KW_VALUES","KW_SENSING_MODEL","KW_DEFAULT_SENSING_MODEL",
"pddl_decls","pddl_domain","domain_elements","domain_name","any_symbol","variable_symbol",
"action_symbol","sensor_symbol","axiom_symbol","domain_requires","require_list",
"domain_predicates","predicate_list","predicate_decl","param_list","untyped_param_list",
"typed_param_list","param_sym_list","new_var_symbol","domain_types","typed_type_list",
"primitive_type_list","primitive_type","domain_constants","typed_constant_list",
"@1","untyped_constant_list","constant_sym_list","domain_schemas","action_decl",
"@2","action_elements","condition","single_condition","literal","positive_literal",
"negative_literal","argument_list","and_condition","or_condition","forall_condition",
"@3","@4","single_condition_list","condition_list","action_effect","action_effect_list",
"single_action_effect","conditional_effect","forall_effect","@5","@6","atomic_effect_kw_list",
"atomic_effect_list","positive_atomic_effect_list","atomic_effect","positive_atomic_effect",
"sensing_model","axiom_decl","@7","axiom_elements","sensor_decl","@8","sensor_elements",
"observable_decl","@9","fluent_list_decl","fluent_decl","sticky_decl","@10",
"multivalued_variable_decl","@11","@12","multivalued_variable_type","domain_default_sensing_model",
"pddl_problem","@13","problem_elements","initial_state","init_elements","single_init_element",
"at_least_one_invariant","at_most_one_invariant","exactly_one_invariant","invariant",
"clause","oneof","unknown","hidden_state","goal_spec","goal_list","single_goal",
"goal_list"
};
#endif

static const short yyr1[] = {     0,
    66,    66,    66,    67,    67,    68,    68,    68,    68,    68,
    68,    68,    69,    70,    70,    70,    70,    70,    70,    70,
    70,    70,    71,    71,    72,    72,    73,    73,    74,    74,
    75,    75,    76,    76,    76,    77,    77,    78,    78,    79,
    79,    80,    80,    80,    81,    82,    82,    83,    83,    84,
    84,    85,    85,    86,    86,    86,    87,    87,    88,    88,
    89,    89,    89,    89,    91,    90,    90,    92,    93,    93,
    94,    94,    94,    94,    94,    94,    96,    95,    95,    97,
    97,    97,    97,    97,    97,    98,    98,    98,    98,    99,
   100,   100,   101,   101,   102,   103,   103,   103,   104,   105,
   107,   108,   106,   109,   109,   110,   110,   111,   111,   112,
   112,   113,   113,   113,   114,   116,   117,   115,   118,   118,
   119,   119,   120,   120,   121,   122,   123,   123,   125,   124,
   124,   126,   126,   126,   126,   128,   127,   127,   129,   129,
   129,   129,   131,   130,   130,   132,   132,   133,   133,   135,
   134,   134,   137,   136,   138,   136,   136,   139,   139,    -1,
    -1,    -1,    -1,   140,   142,   141,   141,   143,   143,   143,
   143,   143,   143,   143,   144,   144,   144,   145,   145,   146,
   146,   146,   146,   146,   147,   147,   148,   149,   150,   150,
   150,   151,   152,   153,   154,   154,   155,   155,   156,   156,
   157,   157
};

static const short yyr2[] = {     0,
     2,     2,     0,     5,     5,     2,     2,     2,     2,     2,
     2,     0,     4,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     4,     4,     2,     2,     0,     4,     4,     2,     1,     4,
     3,     1,     1,     0,     1,     4,     3,     2,     1,     1,
     1,     4,     4,     4,     4,     0,     2,     1,     1,     1,
     4,     4,     4,     4,     0,     5,     0,     1,     2,     1,
     1,     1,     1,     1,     1,     1,     0,     6,     4,     5,
     3,     3,     3,     3,     0,     1,     1,     1,     1,     1,
     1,     1,     4,     4,     4,     2,     2,     0,     4,     4,
     0,     0,     9,     2,     1,     2,     1,     1,     4,     2,
     1,     1,     1,     1,     5,     0,     0,     9,     4,     1,
     2,     1,     2,     1,     1,     1,     1,     0,     0,     6,
     4,     5,     3,     3,     0,     0,     6,     4,     5,     3,
     3,     0,     0,     5,     4,     2,     1,     1,     1,     0,
     5,     4,     0,     6,     0,     9,     4,     1,     1,     4,
     0,     1,     0,     4,     0,     9,     6,     5,     2,     2,
     2,     2,     2,     0,     3,     4,     7,     2,     1,     1,
     1,     1,     1,     1,     4,     4,     4,     4,     1,     1,
     1,     4,     4,     4,     4,     3,     4,     7,     2,     1,
     1,     1
};

static const short yydefact[] = {     3,
     0,     3,     3,     0,     1,     2,     0,     0,     0,     0,
     0,     0,    14,    15,    16,    17,    18,    19,    20,    21,
    22,     0,     0,     0,     5,     0,     4,     6,     9,     7,
     8,    10,    71,    72,    73,    74,    75,    76,    11,    13,
   167,   165,     0,    67,     0,    56,     0,    67,     0,     0,
     0,     0,     0,   159,   128,     0,   174,     0,     0,    70,
     0,     0,    68,     0,     0,     0,    39,    60,    59,     0,
     0,    58,     0,    25,    26,    77,     0,     0,     0,    27,
    28,   136,     0,    29,    30,   129,     0,     0,     0,     0,
     0,     0,   125,    91,    92,   127,   108,   113,   114,   112,
     0,     0,    23,    24,   153,     0,    32,    31,    34,    33,
    61,    63,     0,    69,    37,     0,    44,    36,    38,    53,
    52,     0,    57,    79,    85,    62,    64,   138,   142,   131,
   135,   145,     0,   126,   149,   148,     0,   147,   152,     0,
   157,    98,    98,     0,     0,     0,     0,   164,    44,     0,
     0,   166,   169,   170,   171,   172,   173,    65,    41,    51,
    50,     0,    42,    43,    45,    49,    56,    56,     0,     0,
     0,   144,   146,   151,     0,     0,     0,     0,   111,   116,
     0,     0,     0,     0,    86,    90,    87,    88,    89,     0,
     0,     0,     0,     0,     0,    67,    40,     0,    48,    55,
     0,    54,    78,     0,     0,     0,     0,   128,   137,     0,
     0,     0,   130,     0,     0,     0,    94,    97,    96,    93,
   109,   110,    44,    95,     0,     0,     0,     0,     0,   120,
   155,   154,     0,     0,   175,   180,     0,   179,   189,   190,
   191,   181,   182,   183,   184,     0,   201,   202,     0,     0,
   196,     0,    66,     0,    47,    44,    81,    82,    83,   124,
    84,    44,   141,   140,    44,   133,   134,     0,   107,     0,
     0,   101,     0,   115,     0,   168,     0,     0,     0,     0,
     0,     0,     0,     0,   176,   178,     0,   197,   195,    46,
     0,     0,   123,     0,     0,   117,    99,   106,   100,    44,
     0,     0,   122,     0,     0,   105,     0,     0,     0,     0,
     0,     0,     0,     0,   200,    80,   139,   132,     0,     0,
   119,   121,   156,     0,   192,   104,   193,   194,   185,   186,
   187,   188,     0,   199,     0,   102,   177,   198,   118,     0,
     0,   103,     0,     0,     0
};

static const short yydefgoto[] = {     5,
     2,    12,     8,    22,   105,    76,    82,    86,    28,    59,
    29,    66,    67,   162,   163,   164,   165,   166,    30,    70,
   201,    72,    31,    61,   196,    62,    63,    32,    33,   125,
   169,   269,   185,   186,    94,    95,   175,   187,   188,   189,
   300,   340,   307,   270,    96,   178,    97,    98,   135,   223,
   319,   229,   302,   259,   100,   136,   101,    34,   131,   171,
    35,   129,   170,    36,    88,   137,   138,    37,    90,    38,
   150,   275,    56,    39,     3,    57,   106,   155,   237,   238,
   239,   240,   241,   242,   243,   244,   245,   156,   157,   314,
   249
};

static const short yypact[] = {    40,
    -8,    40,    40,    76,-32768,-32768,     3,   190,   268,   242,
    31,    91,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,   103,   116,   140,-32768,   174,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,    74,   147,   203,   215,   261,   147,   233,   259,
   260,   286,   161,-32768,   144,   218,-32768,   168,    22,-32768,
   184,   236,    92,   240,    32,   211,-32768,-32768,-32768,   262,
   282,-32768,   265,-32768,-32768,-32768,   267,   284,   295,-32768,
-32768,-32768,   339,-32768,-32768,-32768,   340,   162,   341,   162,
   342,    75,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
   343,    71,-32768,-32768,-32768,   298,-32768,-32768,-32768,-32768,
-32768,-32768,   197,-32768,-32768,   344,    23,-32768,-32768,-32768,
-32768,   289,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,    27,-32768,-32768,-32768,   300,-32768,-32768,   302,
-32768,-32768,-32768,   269,   346,   347,   348,-32768,    23,   162,
   115,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,   349,-32768,-32768,   350,    23,   215,   215,    19,    34,
    16,-32768,-32768,-32768,   179,   263,    98,   304,-32768,-32768,
    65,   351,    81,   353,-32768,-32768,-32768,-32768,-32768,   355,
   306,   268,   308,   354,   310,   147,-32768,   352,-32768,-32768,
   237,-32768,-32768,   357,   348,   144,   347,   144,-32768,   358,
   347,   348,-32768,   359,   348,   353,-32768,-32768,-32768,-32768,
-32768,-32768,    23,-32768,   348,   348,   361,   172,   362,-32768,
-32768,-32768,   363,   109,-32768,-32768,   312,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,   204,-32768,-32768,   364,   173,
-32768,   314,-32768,    92,    23,    23,-32768,-32768,   347,-32768,
-32768,    23,   347,-32768,    23,-32768,-32768,   365,-32768,   316,
   318,-32768,   367,-32768,   162,-32768,   368,   367,   367,   347,
   367,   367,   367,   367,-32768,-32768,   367,-32768,-32768,-32768,
   350,   369,-32768,   370,   371,-32768,-32768,-32768,-32768,    23,
   138,   320,-32768,   322,   324,-32768,   326,   328,   372,   330,
   332,   334,   336,   338,-32768,-32768,-32768,-32768,   144,   373,
-32768,-32768,-32768,   374,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,   375,-32768,   376,-32768,-32768,-32768,-32768,   348,
   377,-32768,   382,   383,-32768
};

static const short yypgoto[] = {    96,
-32768,-32768,-32768,    -6,   250,-32768,-32768,-32768,   248,-32768,
-32768,-32768,   299,  -137,-32768,   117,  -153,-32768,-32768,     9,
   345,   -60,   278,   -41,-32768,   337,   191,-32768,-32768,-32768,
-32768,  -139,  -254,   -55,   -85,  -184,   243,-32768,-32768,-32768,
-32768,-32768,    13,   163,  -192,-32768,  -107,-32768,   -54,-32768,
-32768,   176,-32768,   177,  -169,  -189,   182,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,   -88,  -131,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,  -179,  -220,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -266
};


#define	YYLAST		392


static const short yytable[] = {    93,
    99,   140,   134,    24,   134,   173,    77,   184,   173,   248,
   123,   190,   199,   258,   230,   252,   286,   260,     4,   213,
   315,   260,   203,   306,   306,   108,   306,   306,   306,   306,
     9,   286,   116,   142,    25,   160,   179,   209,   143,   109,
   117,   161,     1,    10,   110,   214,   230,   334,   204,   205,
   206,   134,   326,   326,   134,   326,   326,   326,   326,   173,
   182,   191,   145,   210,   134,   257,   207,   215,   216,   293,
   222,   142,   264,   293,    58,   266,   143,   -35,     7,   103,
   211,   142,   208,   212,   286,   268,   143,   142,    93,    99,
   104,   -35,   143,    26,    27,   343,   -35,   305,     6,   113,
   114,   291,   248,   303,   142,   134,    40,   144,   247,   143,
   145,   146,   147,   225,   226,   142,   227,   146,   292,    41,
   143,   134,    93,    99,   294,   134,   335,   295,    93,   248,
   298,   298,   322,   145,   146,   147,    43,   236,    44,   236,
   123,   277,   278,    42,   142,   146,    92,   279,   280,   143,
    93,    99,    93,    99,   253,    60,   192,    48,   193,   194,
    93,    91,   320,  -158,   133,   281,   282,   283,   284,  -158,
   195,   107,   173,   134,   146,   200,   202,   134,   142,   142,
  -158,   236,   217,   143,   143,   233,   304,   111,   218,   134,
    11,   219,   -12,   -12,   309,    43,   236,    44,    45,    46,
   341,   247,    47,    64,   273,    65,   278,   158,   146,   146,
   142,   279,   280,    65,   118,   143,    48,    93,   134,    49,
   102,   236,    50,    68,    51,    69,   103,    52,   247,   281,
   282,   283,   284,    79,    53,    54,   287,   104,    55,   112,
   146,    80,    23,   115,   122,    68,    93,    69,    81,   236,
    13,    14,    15,    16,    17,    18,    19,    20,    21,    83,
    87,    73,  -143,    93,    99,   120,   220,    84,   124,    74,
   126,   177,   218,    85,    75,   219,    13,    14,    15,    16,
    17,    18,    19,    20,    21,   121,    89,   127,  -150,   122,
    68,   308,    69,   310,   311,   312,   313,   167,   128,   168,
   151,   152,   133,   172,   133,   174,   177,   221,   133,   232,
   234,   235,   250,   251,   250,   285,   250,   289,   183,   297,
   183,   299,   301,   321,   133,   323,   250,   324,   301,   325,
   301,   327,   301,   329,   301,   330,   301,   331,   301,   332,
   301,   333,   130,   132,   139,   141,   148,   159,   180,   181,
   183,   149,   197,   153,   224,   228,   246,   198,   231,   256,
   262,   265,   255,   272,   119,   274,   276,   288,   296,   301,
   250,   290,   316,   317,   318,   328,   336,   337,   338,   339,
   342,   344,   345,   154,    78,   176,   254,   263,   271,   261,
    71,   267
};

static const short yycheck[] = {    55,
    55,    90,    88,    10,    90,   137,    48,   147,   140,   194,
    71,   149,   166,   206,   184,   195,   237,   207,    27,     4,
   287,   211,     4,   278,   279,     4,   281,   282,   283,   284,
    28,   252,     1,     7,     4,    13,   144,     4,    12,    18,
     9,    19,     3,    41,    23,    30,   216,   314,    30,    31,
    32,   137,   307,   308,   140,   310,   311,   312,   313,   191,
   146,   150,    36,    30,   150,   205,    48,    52,    53,   259,
   178,     7,   212,   263,     1,   215,    12,     4,     3,     9,
    47,     7,    64,    50,   305,   223,    12,     7,   144,   144,
    20,    18,    12,     3,     4,     0,    23,   277,     3,     8,
     9,   255,   287,   273,     7,   191,     4,    33,   194,    12,
    36,    37,    38,    33,    34,     7,    36,    37,   256,     4,
    12,   207,   178,   178,   262,   211,   319,   265,   184,   314,
   270,   271,   302,    36,    37,    38,    22,   193,    24,   195,
   201,    33,    34,     4,     7,    37,     3,    39,    40,    12,
   206,   206,   208,   208,   196,     9,    42,    43,    44,    45,
   216,     1,   300,     3,     3,    57,    58,    59,    60,     9,
    56,     4,   304,   259,    37,   167,   168,   263,     7,     7,
    20,   237,     4,    12,    12,   192,   275,     4,    10,   275,
     1,    13,     3,     4,   280,    22,   252,    24,    25,    26,
   340,   287,    29,     1,    33,     3,    34,    11,    37,    37,
     7,    39,    40,     3,     4,    12,    43,   273,   304,    46,
     3,   277,    49,     9,    51,    11,     9,    54,   314,    57,
    58,    59,    60,     1,    61,    62,    33,    20,    65,     4,
    37,     9,     1,     4,     8,     9,   302,    11,    16,   305,
     9,    10,    11,    12,    13,    14,    15,    16,    17,     1,
     1,     1,     3,   319,   319,     4,     4,     9,     4,     9,
     4,     3,    10,    15,    14,    13,     9,    10,    11,    12,
    13,    14,    15,    16,    17,     4,     1,     4,     3,     8,
     9,   279,    11,   281,   282,   283,   284,     9,     4,    11,
     3,     4,     3,     4,     3,     4,     3,     4,     3,     4,
     3,     4,     3,     4,     3,     4,     3,     4,     3,     4,
     3,     4,     3,     4,     3,     4,     3,     4,     3,     4,
     3,     4,     3,     4,     3,     4,     3,     4,     3,     4,
     3,     4,     4,     4,     4,     4,     4,     4,     3,     3,
     3,   102,     4,   106,     4,     3,     3,     8,     4,     3,
     3,     3,    11,     3,    66,     4,     4,     4,     4,     3,
     3,   255,     4,     4,     4,     4,     4,     4,     4,     4,
     4,     0,     0,   106,    48,   143,   196,   211,   226,   208,
    46,   216
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
#line 1620 "grammar.cc"

  switch (yyn) {

case 5:
#line 117 "ppddl.y"
{
          log_error((char*)"syntax error in domain");
          yyerrok;
      ;
    break;}
case 13:
#line 134 "ppddl.y"
{ domain_name_ = yyvsp[-1].sym->text; ;
    break;}
case 14:
#line 140 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 15:
#line 141 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 16:
#line 142 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 17:
#line 143 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 18:
#line 144 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 19:
#line 145 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 20:
#line 146 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 21:
#line 147 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 22:
#line 148 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 23:
#line 152 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 24:
#line 153 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 25:
#line 157 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 26:
#line 158 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 27:
#line 162 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 28:
#line 163 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 29:
#line 167 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 30:
#line 168 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 32:
#line 175 "ppddl.y"
{
          log_error((char*)"syntax error in requirements declaration.");
          yyerrok;
      ;
    break;}
case 33:
#line 182 "ppddl.y"
{ declare_multivalued_variable_translation(); ;
    break;}
case 37:
#line 191 "ppddl.y"
{
          log_error((char*)"syntax error in (:predicates ...)");
          yyerrok;
      ;
    break;}
case 40:
#line 203 "ppddl.y"
{
          PredicateSymbol *p = new PredicateSymbol(yyvsp[-2].sym->text);
          dom_predicates_.push_back(p);
          p->param_ = *yyvsp[-1].vparam;
          delete yyvsp[-1].vparam;
          clear_param(p->param_);
          yyvsp[-2].sym->val = p;
      ;
    break;}
case 41:
#line 211 "ppddl.y"
{
          log_error((char*)"syntax error in predicate declaration");
          yyerrok;
      ;
    break;}
case 43:
#line 219 "ppddl.y"
{
          // must reverse parameter list
          var_symbol_vec tmp_list(*yyvsp[0].vparam);
          yyvsp[0].vparam->clear();
          yyvsp[0].vparam->insert(yyvsp[0].vparam->end(), tmp_list.rbegin(), tmp_list.rend());
          yyval.vparam = yyvsp[0].vparam;
      ;
    break;}
case 44:
#line 226 "ppddl.y"
{ yyval.vparam = new var_symbol_vec; ;
    break;}
case 45:
#line 230 "ppddl.y"
{
          set_variable_type(*yyvsp[0].vparam, yyvsp[0].vparam->size(), dom_top_type_);
          yyval.vparam = yyvsp[0].vparam;
      ;
    break;}
case 46:
#line 237 "ppddl.y"
{
          set_variable_type(*yyvsp[-3].vparam, yyvsp[-3].vparam->size(), static_cast<TypeSymbol*>(yyvsp[-1].sym->val));
          yyvsp[0].vparam->insert(yyvsp[0].vparam->end(), yyvsp[-3].vparam->begin(), yyvsp[-3].vparam->end());
          delete yyvsp[-3].vparam;
          yyval.vparam = yyvsp[0].vparam;
      ;
    break;}
case 47:
#line 243 "ppddl.y"
{
          set_variable_type(*yyvsp[-2].vparam, yyvsp[-2].vparam->size(), static_cast<TypeSymbol*>(yyvsp[0].sym->val));
          yyval.vparam = yyvsp[-2].vparam;
      ;
    break;}
case 48:
#line 250 "ppddl.y"
{
          yyvsp[0].vparam->push_back(static_cast<VariableSymbol*>(yyvsp[-1].vsym));
          yyval.vparam = yyvsp[0].vparam;
      ;
    break;}
case 49:
#line 254 "ppddl.y"
{ yyval.vparam = new var_symbol_vec; yyval.vparam->push_back(yyvsp[0].vsym); ;
    break;}
case 50:
#line 258 "ppddl.y"
{
          VariableSymbol *var = new VariableSymbol(yyvsp[0].sym->text);
          yyvsp[0].sym->val = var;
          yyval.vsym = var;
      ;
    break;}
case 51:
#line 263 "ppddl.y"
{
          std::string msg("variable '");
          msg += yyvsp[0].sym->text;
          msg += "' shadows variable in outer scope: this is not supported!";
          log_error((char*)msg.c_str());
          yyerrok;
      ;
    break;}
case 53:
#line 276 "ppddl.y"
{
          set_type_type(dom_types_, dom_types_.size(), dom_top_type_);
      ;
    break;}
case 54:
#line 282 "ppddl.y"
{
          set_type_type(dom_types_, dom_types_.size(), static_cast<TypeSymbol*>(yyvsp[-1].sym->val));
      ;
    break;}
case 55:
#line 285 "ppddl.y"
{
          yyvsp[-1].sym->val = new TypeSymbol(yyvsp[-1].sym->text);
          if( write_warnings_ )
              std::cout << Utils::warning() << "assuming " << yyvsp[-1].sym->text << " - object" << std::endl;
          static_cast<TypeSymbol*>(yyvsp[-1].sym->val)->sym_type_ = dom_top_type_;
          set_type_type(dom_types_, dom_types_.size(), static_cast<TypeSymbol*>(yyvsp[-1].sym->val));
          dom_types_.push_back(static_cast<TypeSymbol*>(yyvsp[-1].sym->val));
      ;
    break;}
case 58:
#line 298 "ppddl.y"
{ ;
    break;}
case 60:
#line 303 "ppddl.y"
{
          yyvsp[0].sym->val = new TypeSymbol(yyvsp[0].sym->text);
          dom_types_.push_back(static_cast<TypeSymbol*>(yyvsp[0].sym->val));
      ;
    break;}
case 65:
#line 319 "ppddl.y"
{
          set_constant_type(dom_constants_, dom_constants_.size(), static_cast<TypeSymbol*>(yyvsp[0].sym->val));
      ;
    break;}
case 68:
#line 327 "ppddl.y"
{
          set_constant_type(dom_constants_, dom_constants_.size(), dom_top_type_);
      ;
    break;}
case 69:
#line 333 "ppddl.y"
{
          yyvsp[0].sym->val = new Symbol(yyvsp[0].sym->text);
          dom_constants_.push_back(static_cast<Symbol*>(yyvsp[0].sym->val));
      ;
    break;}
case 70:
#line 337 "ppddl.y"
{
          yyvsp[0].sym->val = new Symbol(yyvsp[0].sym->text);
          dom_constants_.push_back(static_cast<Symbol*>(yyvsp[0].sym->val));
      ;
    break;}
case 72:
#line 347 "ppddl.y"
{
          if( type_ == replanner ) {
              log_error((char*)"':axiom' is not a valid element in k-replanner.");
              yyerrok;
          }
      ;
    break;}
case 73:
#line 353 "ppddl.y"
{
          if( type_ == cp2fsc ) {
              log_error((char*)"':sensor' is not a valid element in cp2fsc.");
              yyerrok;
          }
      ;
    break;}
case 74:
#line 359 "ppddl.y"
{
          if( type_ == replanner ) {
              log_error((char*)"':observable' is not a valid element in k-replanner.");
              yyerrok;
          }
      ;
    break;}
case 75:
#line 365 "ppddl.y"
{
          if( type_ == replanner ) {
              log_error((char*)"':sticky' is not a valid element in k-replanner.");
              yyerrok;
          }
      ;
    break;}
case 76:
#line 371 "ppddl.y"
{
          //declare_multivalued_variable_translation();
          if( type_ == cp2fsc ) {
              log_error((char*)"':sensor' is not a valid element in cp2fsc.");
              yyerrok;
          }
      ;
    break;}
case 77:
#line 383 "ppddl.y"
{
          Action *na = new Action(yyvsp[0].sym->text);
          dom_actions_.push_back(na);
      ;
    break;}
case 78:
#line 387 "ppddl.y"
{
          clear_param(dom_actions_.back()->param_);
          yyvsp[-3].sym->val = dom_actions_.back();
      ;
    break;}
case 79:
#line 391 "ppddl.y"
{
          log_error((char*)"syntax error in action declaration");
          yyerrok;
      ;
    break;}
case 80:
#line 398 "ppddl.y"
{
          dom_actions_.back()->param_ = *yyvsp[-1].vparam;
          delete yyvsp[-1].vparam;
      ;
    break;}
case 81:
#line 402 "ppddl.y"
{ dom_actions_.back()->precondition_ = yyvsp[0].condition; ;
    break;}
case 82:
#line 403 "ppddl.y"
{ dom_actions_.back()->effect_ = yyvsp[0].effect; ;
    break;}
case 83:
#line 404 "ppddl.y"
{
          declare_clg_translation();
          dom_actions_.back()->observe_ = new AndEffect(*yyvsp[0].effect_vec);
          delete yyvsp[0].effect_vec;
      ;
    break;}
case 84:
#line 409 "ppddl.y"
{
          declare_multivalued_variable_translation();
          dom_actions_.back()->sensing_model_ = yyvsp[0].effect;
      ;
    break;}
case 90:
#line 424 "ppddl.y"
{
          // if literal is for equality, construct EQ
          if( yyvsp[0].atom->pred_ == dom_eq_pred_ )
              yyval.condition = new EQ(dynamic_cast<VariableSymbol*>(yyvsp[0].atom->param_[0]), dynamic_cast<VariableSymbol*>(yyvsp[0].atom->param_[1]), yyvsp[0].atom->negated_);
          else
              yyval.condition = new Literal(*yyvsp[0].atom);
          delete yyvsp[0].atom;
      ;
    break;}
case 93:
#line 440 "ppddl.y"
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
case 94:
#line 452 "ppddl.y"
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
case 95:
#line 464 "ppddl.y"
{
          const_cast<Literal*>(static_cast<const Literal*>(yyvsp[-1].atom))->negated_ = true;
          yyval.atom = yyvsp[-1].atom;
      ;
    break;}
case 96:
#line 471 "ppddl.y"
{
          if( yyvsp[0].sym->val == 0 )
              log_error((char*)"undeclared variable in atom args list");
          else
              yyvsp[-1].param->push_back(static_cast<VariableSymbol*>(yyvsp[0].sym->val));
          yyval.param = yyvsp[-1].param;
      ;
    break;}
case 97:
#line 478 "ppddl.y"
{
          yyvsp[-1].param->push_back(static_cast<Symbol*>(yyvsp[0].sym->val));
          yyval.param = yyvsp[-1].param;
      ;
    break;}
case 98:
#line 482 "ppddl.y"
{ yyval.param = new PDDL_Base::symbol_vec; ;
    break;}
case 99:
#line 486 "ppddl.y"
{
          yyval.condition = new And(*yyvsp[-1].condition_vec);
          delete yyvsp[-1].condition_vec;
      ;
    break;}
case 100:
#line 493 "ppddl.y"
{
          yyval.condition = new Or(*yyvsp[-1].condition_vec);
          delete yyvsp[-1].condition_vec;
      ;
    break;}
case 101:
#line 500 "ppddl.y"
{
          forall_conditions_.push_back(new ForallCondition);
      ;
    break;}
case 102:
#line 503 "ppddl.y"
{
          forall_conditions_.back()->param_ = *yyvsp[-1].vparam;
          delete yyvsp[-1].vparam;
      ;
    break;}
case 103:
#line 507 "ppddl.y"
{
          forall_conditions_.back()->condition_ = yyvsp[-1].condition;
          clear_param(forall_conditions_.back()->param_);
          yyval.condition = forall_conditions_.back();
          forall_conditions_.pop_back();
      ;
    break;}
case 104:
#line 516 "ppddl.y"
{
          yyvsp[-1].condition_vec->push_back(yyvsp[0].condition);
          yyval.condition_vec = yyvsp[-1].condition_vec;
      ;
    break;}
case 105:
#line 520 "ppddl.y"
{
          condition_vec *cond_vec = new condition_vec;
          cond_vec->push_back(yyvsp[0].condition);
          yyval.condition_vec = cond_vec;
      ;
    break;}
case 106:
#line 528 "ppddl.y"
{
          yyvsp[-1].condition_vec->push_back(yyvsp[0].condition);
          yyval.condition_vec = yyvsp[-1].condition_vec;
      ;
    break;}
case 107:
#line 532 "ppddl.y"
{
          condition_vec *cond_vec = new condition_vec;
          cond_vec->push_back(yyvsp[0].condition);
          yyval.condition_vec = cond_vec;
      ;
    break;}
case 109:
#line 541 "ppddl.y"
{
          yyval.effect = new AndEffect(*yyvsp[-1].effect_vec);
          delete yyvsp[-1].effect_vec;
      ;
    break;}
case 110:
#line 548 "ppddl.y"
{
          yyvsp[-1].effect_vec->push_back(yyvsp[0].effect);
          yyval.effect_vec = yyvsp[-1].effect_vec;
      ;
    break;}
case 111:
#line 552 "ppddl.y"
{
          yyval.effect_vec = new effect_vec;
          yyval.effect_vec->push_back(yyvsp[0].effect);
      ;
    break;}
case 115:
#line 565 "ppddl.y"
{ yyval.effect = new ConditionalEffect(yyvsp[-2].condition, yyvsp[-1].effect); ;
    break;}
case 116:
#line 569 "ppddl.y"
{
          forall_effects_.push_back(new ForallEffect);
      ;
    break;}
case 117:
#line 572 "ppddl.y"
{
          forall_effects_.back()->param_ = *yyvsp[-1].vparam;
          delete yyvsp[-1].vparam;
      ;
    break;}
case 118:
#line 576 "ppddl.y"
{
          forall_effects_.back()->effect_ = yyvsp[-1].effect;
          clear_param(forall_effects_.back()->param_);
          yyval.effect = forall_effects_.back();
          forall_effects_.pop_back();
      ;
    break;}
case 119:
#line 585 "ppddl.y"
{
          yyval.effect = new AndEffect(*yyvsp[-1].effect_vec);
          delete yyvsp[-1].effect_vec;
      ;
    break;}
case 121:
#line 593 "ppddl.y"
{
          yyvsp[-1].effect_vec->push_back(yyvsp[0].effect);
          yyval.effect_vec = yyvsp[-1].effect_vec;
      ;
    break;}
case 122:
#line 597 "ppddl.y"
{
          yyval.effect_vec = new effect_vec;
          yyval.effect_vec->push_back(yyvsp[0].effect);
      ;
    break;}
case 123:
#line 604 "ppddl.y"
{
          yyvsp[-1].effect_vec->push_back(yyvsp[0].effect);
          yyval.effect_vec = yyvsp[-1].effect_vec;
      ;
    break;}
case 124:
#line 608 "ppddl.y"
{
          yyval.effect_vec = new effect_vec;
          yyval.effect_vec->push_back(yyvsp[0].effect);
      ;
    break;}
case 125:
#line 615 "ppddl.y"
{ yyval.effect = new AtomicEffect(*yyvsp[0].atom); delete yyvsp[0].atom; ;
    break;}
case 126:
#line 619 "ppddl.y"
{ yyval.effect = new AtomicEffect(*yyvsp[0].atom); delete yyvsp[0].atom; ;
    break;}
case 128:
#line 624 "ppddl.y"
{ yyval.effect = 0; ;
    break;}
case 129:
#line 628 "ppddl.y"
{
          Axiom *nr = new Axiom(yyvsp[0].sym->text);
          dom_axioms_.push_back(nr);
      ;
    break;}
case 130:
#line 632 "ppddl.y"
{
          clear_param(dom_axioms_.back()->param_);
          yyvsp[-3].sym->val = dom_axioms_.back();
      ;
    break;}
case 131:
#line 636 "ppddl.y"
{
          log_error((char*)"syntax error in axiom declaration");
          yyerrok;
      ;
    break;}
case 132:
#line 643 "ppddl.y"
{
          dom_axioms_.back()->param_ = *yyvsp[-1].vparam;
          delete yyvsp[-1].vparam;
      ;
    break;}
case 133:
#line 647 "ppddl.y"
{ dom_axioms_.back()->body_ = yyvsp[0].condition; ;
    break;}
case 134:
#line 648 "ppddl.y"
{ dom_axioms_.back()->head_ = yyvsp[0].effect; ;
    break;}
case 136:
#line 653 "ppddl.y"
{
          Sensor *nr = new Sensor(yyvsp[0].sym->text);
          dom_sensors_.push_back(nr);
      ;
    break;}
case 137:
#line 657 "ppddl.y"
{
          clear_param(dom_sensors_.back()->param_);
          yyvsp[-3].sym->val = dom_sensors_.back();
      ;
    break;}
case 138:
#line 661 "ppddl.y"
{
          log_error((char*)"syntax error in sensor declaration");
          yyerrok;
      ;
    break;}
case 139:
#line 668 "ppddl.y"
{
          dom_sensors_.back()->param_ = *yyvsp[-1].vparam;
          delete yyvsp[-1].vparam;
      ;
    break;}
case 140:
#line 672 "ppddl.y"
{
          dom_sensors_.back()->condition_ = yyvsp[0].condition;
      ;
    break;}
case 141:
#line 675 "ppddl.y"
{
          dom_sensors_.back()->sense_ = new AndEffect(*yyvsp[0].effect_vec);
          delete yyvsp[0].effect_vec;
      ;
    break;}
case 143:
#line 683 "ppddl.y"
{
          Observable *obs = new Observable;
          dom_observables_.push_back(obs);
          effect_vec_ptr_ = &obs->observables_;
      ;
    break;}
case 145:
#line 689 "ppddl.y"
{
          log_error((char*)"syntax error in observable declaration");
          yyerrok;
      ;
    break;}
case 146:
#line 696 "ppddl.y"
{
          effect_vec_ptr_->push_back(yyvsp[0].effect);
      ;
    break;}
case 147:
#line 699 "ppddl.y"
{
          effect_vec_ptr_->push_back(yyvsp[0].effect);
      ;
    break;}
case 150:
#line 710 "ppddl.y"
{
          Sticky *sticky = new Sticky;
          dom_stickies_.push_back(sticky);
          effect_vec_ptr_ = &sticky->stickies_;
      ;
    break;}
case 152:
#line 716 "ppddl.y"
{
          log_error((char*)"syntax error in sticky declaration");
          yyerrok;
      ;
    break;}
case 153:
#line 723 "ppddl.y"
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
case 154:
#line 733 "ppddl.y"
{
          yyvsp[-3].sym->val = multivalued_variables_.back();
      ;
    break;}
case 155:
#line 736 "ppddl.y"
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
case 156:
#line 748 "ppddl.y"
{
          clear_param(multivalued_variables_.back()->param_);
          yyvsp[-5].sym->val = multivalued_variables_.back();
      ;
    break;}
case 157:
#line 752 "ppddl.y"
{
          log_error((char*)"syntax error in state variable declaration");
          yyerrok;
      ;
    break;}
case 158:
#line 759 "ppddl.y"
{ yyval.ival = 0; ;
    break;}
case 159:
#line 760 "ppddl.y"
{ yyval.ival = 1; ;
    break;}
case 160:
#line 764 "ppddl.y"
{
          multivalued_variables_.back()->param_ = *yyvsp[-1].vparam;
          delete yyvsp[-1].vparam;
      ;
    break;}
case 162:
#line 772 "ppddl.y"
{
          assert(dynamic_cast<StateVariable*>(multivalued_variables_.back()) != 0);
          dynamic_cast<StateVariable*>(multivalued_variables_.back())->is_observable_ = true;
      ;
    break;}
case 164:
#line 782 "ppddl.y"
{
          declare_multivalued_variable_translation();
          default_sensing_model_ = yyvsp[-1].effect;
      ;
    break;}
case 165:
#line 792 "ppddl.y"
{
          problem_name_ = yyvsp[-1].sym->text;
      ;
    break;}
case 167:
#line 796 "ppddl.y"
{
          log_error((char*)"syntax error in problem definition.");
          yyerrok;
      ;
    break;}
case 176:
#line 814 "ppddl.y"
{ dom_init_ = *yyvsp[-1].ilist; delete yyvsp[-1].ilist; ;
    break;}
case 177:
#line 815 "ppddl.y"
{ dom_init_ = *yyvsp[-2].ilist; delete yyvsp[-2].ilist; ;
    break;}
case 178:
#line 819 "ppddl.y"
{
          init_element_vec *ilist = const_cast<init_element_vec*>(yyvsp[-1].ilist);
          if( yyvsp[0].ielem != 0 ) ilist->push_back(const_cast<InitElement*>(yyvsp[0].ielem));
          yyval.ilist = ilist;
      ;
    break;}
case 179:
#line 824 "ppddl.y"
{
          init_element_vec *ilist = new init_element_vec;
          if( yyvsp[0].ielem != 0 ) ilist->push_back(const_cast<InitElement*>(yyvsp[0].ielem));
          yyval.ilist = ilist;
      ;
    break;}
case 180:
#line 832 "ppddl.y"
{ yyval.ielem = new InitLiteral(*yyvsp[0].atom); ;
    break;}
case 181:
#line 833 "ppddl.y"
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
case 182:
#line 844 "ppddl.y"
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
case 183:
#line 855 "ppddl.y"
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
case 184:
#line 866 "ppddl.y"
{
          yyval.ielem = 0; // when fixing this, remove condition '$2 != 0' and '$1 != 0' above (in single_init_element)
          std::cout << Utils::warning()
                    << Utils::magenta() << "(clg) ignoring '" << yyvsp[0].unknown->to_string() << "'"
                    << Utils::normal() << std::endl;
          //$$ = new InitUnknown(*$1);
          delete yyvsp[0].unknown;
      ;
    break;}
case 185:
#line 877 "ppddl.y"
{
          //$$ = new Invariant(Invariant::AT_LEAST_ONE, *static_cast<const And*>($3));
          yyval.invariant = new Invariant(Invariant::AT_LEAST_ONE, *yyvsp[-1].condition_vec);
          delete yyvsp[-1].condition_vec;
      ;
    break;}
case 186:
#line 882 "ppddl.y"
{
          //$$ = new Invariant(Invariant::AT_LEAST_ONE, *static_cast<const And*>($3));
          yyval.invariant = new Invariant(Invariant::AT_LEAST_ONE, *yyvsp[-1].condition_vec);
          delete yyvsp[-1].condition_vec;
      ;
    break;}
case 187:
#line 890 "ppddl.y"
{
          //$$ = new Invariant(Invariant::AT_MOST_ONE, *static_cast<const And*>($3));
          yyval.invariant = new Invariant(Invariant::AT_MOST_ONE, *yyvsp[-1].condition_vec);
          delete yyvsp[-1].condition_vec;
      ;
    break;}
case 188:
#line 898 "ppddl.y"
{
          yyval.invariant = new Invariant(Invariant::EXACTLY_ONE, *yyvsp[-1].condition_vec);
          delete yyvsp[-1].condition_vec;
      ;
    break;}
case 192:
#line 911 "ppddl.y"
{
          yyval.clause = new Clause(*yyvsp[-1].condition_vec);
          delete yyvsp[-1].condition_vec;
      ;
    break;}
case 193:
#line 918 "ppddl.y"
{
          yyval.oneof = new Oneof(*yyvsp[-1].condition_vec);
          delete yyvsp[-1].condition_vec;
      ;
    break;}
case 194:
#line 925 "ppddl.y"
{
          yyval.unknown = new Unknown(*yyvsp[-1].atom);
          delete yyvsp[-1].atom;
      ;
    break;}
case 195:
#line 932 "ppddl.y"
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
case 196:
#line 941 "ppddl.y"
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
case 197:
#line 953 "ppddl.y"
{ dom_goal_ = yyvsp[-1].condition; ;
    break;}
case 198:
#line 954 "ppddl.y"
{ dom_goal_ = yyvsp[-2].condition; ;
    break;}
case 199:
#line 958 "ppddl.y"
{
          const_cast<And*>(static_cast<const And*>(yyvsp[-1].condition))->push_back(yyvsp[0].condition);
          yyval.condition = yyvsp[-1].condition;
      ;
    break;}
case 200:
#line 962 "ppddl.y"
{
          And *cond = new And;
          cond->push_back(yyvsp[0].condition);
          yyval.condition = cond;
      ;
    break;}
case 201:
#line 971 "ppddl.y"
{ yyval.condition = new Literal(*yyvsp[0].atom); delete yyvsp[0].atom; ;
    break;}
case 202:
#line 972 "ppddl.y"
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
#line 2787 "grammar.cc"
#line 975 "ppddl.y"


