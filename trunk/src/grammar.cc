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
#define YY_PDDL_Parser_CONSTRUCTOR_PARAM  StringTable& t, int type
#define YY_PDDL_Parser_CONSTRUCTOR_INIT  : PDDL_Base(t), type_(type), error_flag_(false)
#define YY_PDDL_Parser_MEMBERS  \
  public: \
    typedef enum { replanner, cp2fsc } Type; \
    virtual ~PDDL_Parser() { } \
    virtual std::ostream& syntax_errors() = 0; \
    bool error_flag_; \
    int type_; \
  private: \
    std::vector<ForallEffect*> forall_effects;
#line 22 "ppddl.y"

#include <stdlib.h>
#include <string.h>
#include <list>
#include <sstream>
#include "base.h"

#line 30 "ppddl.y"
typedef union {
    StringTable::Cell                 *sym;
    PDDL_Base::VariableSymbol         *vsym;
    PDDL_Base::Atom                   *atom;
    PDDL_Base::symbol_vec             *param;
    PDDL_Base::var_symbol_vec         *vparam;
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
#line 177 "grammar.cc"

#line 117 "/usr/local/lib/bison.cc"
/*  YY_PDDL_Parser_PURE */
#endif

/* section apres lecture def, avant lecture grammaire S2 */

/* #line 121 "/usr/local/lib/bison.cc" */
#line 186 "grammar.cc"

#line 121 "/usr/local/lib/bison.cc"
/* prefix */
#ifndef YY_PDDL_Parser_DEBUG

/* #line 123 "/usr/local/lib/bison.cc" */
#line 193 "grammar.cc"

#line 123 "/usr/local/lib/bison.cc"
/* YY_PDDL_Parser_DEBUG */
#endif


#ifndef YY_PDDL_Parser_LSP_NEEDED

/* #line 128 "/usr/local/lib/bison.cc" */
#line 203 "grammar.cc"

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
#line 316 "grammar.cc"
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
#line 428 "grammar.cc"
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


#line 280 "/usr/local/lib/bison.cc"
 /* decl const */
#else
enum YY_PDDL_Parser_ENUM_TOKEN { YY_PDDL_Parser_NULL_TOKEN=0

/* #line 283 "/usr/local/lib/bison.cc" */
#line 499 "grammar.cc"
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
#line 598 "grammar.cc"
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
const int YY_PDDL_Parser_CLASS::KW_PROBLEM=295;
const int YY_PDDL_Parser_CLASS::KW_FORDOMAIN=296;
const int YY_PDDL_Parser_CLASS::KW_OBJECTS=297;
const int YY_PDDL_Parser_CLASS::KW_INIT=298;
const int YY_PDDL_Parser_CLASS::KW_GOAL=299;
const int YY_PDDL_Parser_CLASS::KW_SENSOR=300;
const int YY_PDDL_Parser_CLASS::KW_SENSE=301;
const int YY_PDDL_Parser_CLASS::KW_OBSERVE=302;
const int YY_PDDL_Parser_CLASS::KW_AXIOM=303;
const int YY_PDDL_Parser_CLASS::KW_COND=304;
const int YY_PDDL_Parser_CLASS::KW_OBSERVABLE=305;
const int YY_PDDL_Parser_CLASS::KW_BODY=306;
const int YY_PDDL_Parser_CLASS::KW_HEAD=307;
const int YY_PDDL_Parser_CLASS::KW_STICKY=308;
const int YY_PDDL_Parser_CLASS::KW_FLUENTS=309;
const int YY_PDDL_Parser_CLASS::KW_HIDDEN=310;
const int YY_PDDL_Parser_CLASS::KW_INVARIANT=311;
const int YY_PDDL_Parser_CLASS::KW_AT_LEAST_ONE=312;
const int YY_PDDL_Parser_CLASS::KW_AT_MOST_ONE=313;
const int YY_PDDL_Parser_CLASS::KW_EXACTLY_ONE=314;
const int YY_PDDL_Parser_CLASS::KW_VARIABLE=315;
const int YY_PDDL_Parser_CLASS::KW_OBS_VARIABLE=316;
const int YY_PDDL_Parser_CLASS::KW_VALUES=317;
const int YY_PDDL_Parser_CLASS::KW_SENSING_MODEL=318;
const int YY_PDDL_Parser_CLASS::KW_DEFAULT_SENSING_MODEL=319;


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
#line 677 "grammar.cc"


#define	YYFINAL		331
#define	YYFLAG		-32768
#define	YYNTBASE	65

#define YYTRANSLATE(x) ((unsigned)(x) <= 319 ? yytranslate[x] : 152)

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
    56,    57,    58,    59,    60,    61,    62,    63,    64
};

#if YY_PDDL_Parser_DEBUG != 0
static const short yyprhs[] = {     0,
     0,     3,     6,     7,    13,    19,    22,    25,    28,    31,
    34,    37,    38,    43,    45,    47,    49,    51,    53,    55,
    57,    59,    61,    63,    65,    67,    69,    71,    73,    75,
    77,    82,    87,    90,    93,    94,    99,   104,   107,   109,
   114,   118,   120,   122,   123,   125,   130,   134,   137,   139,
   141,   146,   151,   156,   161,   162,   165,   167,   169,   171,
   176,   181,   186,   191,   192,   198,   199,   201,   204,   206,
   208,   210,   212,   214,   216,   218,   219,   226,   231,   237,
   241,   245,   249,   253,   254,   256,   261,   264,   266,   268,
   270,   272,   277,   282,   287,   290,   293,   294,   296,   301,
   304,   306,   308,   310,   312,   318,   319,   320,   330,   335,
   337,   340,   342,   345,   347,   349,   351,   353,   354,   355,
   362,   367,   373,   377,   381,   382,   383,   390,   395,   401,
   405,   409,   410,   411,   417,   422,   425,   427,   429,   431,
   432,   438,   443,   444,   453,   454,   465,   470,   472,   474,
   479,   480,   482,   483,   488,   489,   499,   506,   512,   515,
   518,   521,   524,   527,   528,   532,   537,   545,   548,   550,
   552,   554,   556,   558,   563,   568,   573,   578,   580,   582,
   584,   589,   594,   599,   604,   612,   615,   617,   619
};

static const short yyrhs[] = {    66,
    65,     0,   136,    65,     0,     0,     3,    27,    68,    67,
     4,     0,     3,    27,    68,     1,     4,     0,    67,    74,
     0,    67,    84,     0,    67,    88,     0,    67,    76,     0,
    67,    93,     0,    67,   135,     0,     0,     3,    28,    69,
     4,     0,     9,     0,    10,     0,    11,     0,    12,     0,
    13,     0,    14,     0,    15,     0,    16,     0,    17,     0,
     9,     0,    20,     0,     9,     0,    14,     0,     9,     0,
    16,     0,     9,     0,    15,     0,     3,    22,    75,     4,
     0,     3,    22,     1,     4,     0,    75,    23,     0,    75,
    18,     0,     0,     3,    25,    77,     4,     0,     3,    25,
     1,     4,     0,    77,    78,     0,    78,     0,     3,     9,
    79,     4,     0,     3,     1,     4,     0,    80,     0,    81,
     0,     0,    82,     0,    82,     8,    11,    81,     0,    82,
     8,    11,     0,    82,    83,     0,    83,     0,    19,     0,
     3,    26,    86,     4,     0,     3,    26,    85,     4,     0,
    86,     8,    11,    85,     0,    86,     8,     9,    85,     0,
     0,    86,    87,     0,    87,     0,    11,     0,     9,     0,
     3,    24,    89,     4,     0,     3,    42,    89,     4,     0,
     3,    24,    91,     4,     0,     3,    42,    91,     4,     0,
     0,    92,     8,    11,    90,    89,     0,     0,    92,     0,
    92,     9,     0,     9,     0,    94,     0,   117,     0,   120,
     0,   123,     0,   127,     0,   129,     0,     0,     3,    29,
    71,    95,    96,     4,     0,     3,    29,     1,     4,     0,
    96,    30,     3,    79,     4,     0,    96,    31,    97,     0,
    96,    32,   104,     0,    96,    47,   113,     0,    96,    63,
   116,     0,     0,    99,     0,     3,    33,    98,     4,     0,
    98,    99,     0,    99,     0,   100,     0,   101,     0,   102,
     0,     3,    12,   103,     4,     0,     3,     7,   103,     4,
     0,     3,    37,   101,     4,     0,   103,    13,     0,   103,
    10,     0,     0,   106,     0,     3,    33,   105,     4,     0,
   105,   106,     0,   106,     0,   114,     0,   107,     0,   108,
     0,     3,    38,    97,   111,     4,     0,     0,     0,     3,
    36,     3,   109,    79,     4,   110,   104,     4,     0,     3,
    33,   112,     4,     0,   114,     0,   112,   114,     0,   114,
     0,   113,   115,     0,   115,     0,   100,     0,   101,     0,
   104,     0,     0,     0,     3,    48,    73,   118,   119,     4,
     0,     3,    48,     1,     4,     0,   119,    30,     3,    79,
     4,     0,   119,    51,    97,     0,   119,    52,   111,     0,
     0,     0,     3,    45,    72,   121,   122,     4,     0,     3,
    45,     1,     4,     0,   122,    30,     3,    79,     4,     0,
   122,    49,    97,     0,   122,    46,   113,     0,     0,     0,
     3,    50,   124,   125,     4,     0,     3,    50,     1,     4,
     0,   125,   126,     0,   126,     0,   115,     0,   108,     0,
     0,     3,    53,   128,   125,     4,     0,     3,    53,     1,
     4,     0,     0,     3,   132,    70,   130,   133,   125,   134,
     4,     0,     0,     3,   132,     3,    70,    79,     4,   131,
   125,   134,     4,     0,     3,    60,     1,     4,     0,    60,
     0,    61,     0,    30,     3,    79,     4,     0,     0,    50,
     0,     0,     3,    64,   116,     4,     0,     0,     3,    27,
     3,    40,    69,     4,   137,   138,     4,     0,     3,    27,
     3,    40,     1,     4,     0,   138,     3,    41,    69,     4,
     0,   138,    74,     0,   138,    88,     0,   138,   139,     0,
   138,   148,     0,   138,   149,     0,     0,     3,    43,     4,
     0,     3,    43,   140,     4,     0,     3,    43,     3,    33,
   140,     4,     4,     0,   140,   141,     0,   141,     0,   100,
     0,   145,     0,   146,     0,   147,     0,     3,    56,    98,
     4,     0,     3,    57,    98,     4,     0,     3,    58,    98,
     4,     0,     3,    59,    98,     4,     0,   142,     0,   143,
     0,   144,     0,     3,    34,    98,     4,     0,     3,    39,
    98,     4,     0,     3,    55,   140,     4,     0,     3,    44,
   151,     4,     0,     3,    44,     3,    33,   150,     4,     4,
     0,   150,   151,     0,   151,     0,   101,     0,   102,     0
};

#endif

#if YY_PDDL_Parser_DEBUG != 0
static const short yyrline[] = { 0,
    93,    95,    96,    99,   101,   107,   109,   110,   111,   112,
   113,   114,   117,   123,   125,   126,   127,   128,   129,   130,
   131,   132,   135,   137,   140,   142,   145,   147,   150,   152,
   157,   159,   165,   167,   168,   173,   175,   181,   183,   186,
   195,   201,   203,   210,   213,   220,   227,   233,   238,   241,
   251,   253,   258,   262,   270,   273,   275,   278,   280,   288,
   290,   291,   292,   295,   300,   300,   303,   309,   314,   322,
   324,   330,   336,   342,   348,   359,   364,   368,   374,   379,
   380,   381,   385,   389,   392,   394,   397,   402,   409,   420,
   422,   425,   438,   449,   456,   464,   468,   471,   473,   476,
   481,   488,   490,   491,   494,   498,   502,   506,   514,   516,
   519,   524,   531,   536,   543,   547,   551,   553,   556,   561,
   565,   571,   576,   577,   578,   581,   586,   590,   596,   601,
   602,   603,   606,   612,   613,   619,   623,   628,   630,   633,
   639,   640,   646,   656,   659,   670,   674,   680,   682,   685,
   690,   693,   698,   703,   713,   717,   718,   724,   726,   727,
   728,   729,   730,   731,   734,   736,   737,   740,   746,   753,
   755,   766,   777,   790,   796,   803,   811,   819,   821,   822,
   825,   833,   841,   853,   855,   858,   863,   871,   873
};

static const char * const yytname[] = {   "$","error","$illegal.","TK_OPEN",
"TK_CLOSE","TK_OPEN_SQ","TK_CLOSE_SQ","TK_EQ","TK_HYPHEN","TK_NEW_SYMBOL","TK_OBJ_SYMBOL",
"TK_TYPE_SYMBOL","TK_PRED_SYMBOL","TK_VAR_SYMBOL","TK_ACTION_SYMBOL","TK_AXIOM_SYMBOL",
"TK_SENSOR_SYMBOL","TK_MISC_SYMBOL","TK_KEYWORD","TK_NEW_VAR_SYMBOL","TK_VARNAME_SYMBOL",
"TK_INT","KW_REQS","KW_TRANSLATION","KW_CONSTANTS","KW_PREDS","KW_TYPES","KW_DEFINE",
"KW_DOMAIN","KW_ACTION","KW_ARGS","KW_PRE","KW_EFFECT","KW_AND","KW_OR","KW_EXISTS",
"KW_FORALL","KW_NOT","KW_WHEN","KW_ONEOF","KW_PROBLEM","KW_FORDOMAIN","KW_OBJECTS",
"KW_INIT","KW_GOAL","KW_SENSOR","KW_SENSE","KW_OBSERVE","KW_AXIOM","KW_COND",
"KW_OBSERVABLE","KW_BODY","KW_HEAD","KW_STICKY","KW_FLUENTS","KW_HIDDEN","KW_INVARIANT",
"KW_AT_LEAST_ONE","KW_AT_MOST_ONE","KW_EXACTLY_ONE","KW_VARIABLE","KW_OBS_VARIABLE",
"KW_VALUES","KW_SENSING_MODEL","KW_DEFAULT_SENSING_MODEL","pddl_decls","pddl_domain",
"domain_elements","domain_name","any_symbol","variable_symbol","action_symbol",
"sensor_symbol","axiom_symbol","domain_requires","require_list","domain_predicates",
"predicate_list","predicate_decl","param_list","untyped_param_list","typed_param_list",
"param_sym_list","new_var_symbol","domain_types","typed_type_list","primitive_type_list",
"primitive_type","domain_constants","typed_constant_list","@1","untyped_constant_list",
"constant_sym_list","domain_schemas","action_decl","@2","action_elements","condition",
"condition_list","single_condition","literal","positive_literal","negative_literal",
"argument_list","action_effect","action_effect_list","single_action_effect",
"conditional_effect","forall_effect","@3","@4","atomic_effect_kw_list","atomic_effect_list",
"positive_atomic_effect_list","atomic_effect","positive_atomic_effect","sensing_model",
"axiom_decl","@5","axiom_elements","sensor_decl","@6","sensor_elements","observable_decl",
"@7","fluent_list_decl","fluent_decl","sticky_decl","@8","multivalued_variable_decl",
"@9","@10","multivalued_variable_type","optional_variable_parameters","rest_variable_decl",
"domain_default_sensing_model","pddl_problem","@11","problem_elements","initial_state",
"init_elements","single_init_element","at_least_one_invariant","at_most_one_invariant",
"exactly_one_invariant","invariant","clause","oneof","hidden_state","goal_spec",
"goal_list","single_goal",""
};
#endif

static const short yyr1[] = {     0,
    65,    65,    65,    66,    66,    67,    67,    67,    67,    67,
    67,    67,    68,    69,    69,    69,    69,    69,    69,    69,
    69,    69,    70,    70,    71,    71,    72,    72,    73,    73,
    74,    74,    75,    75,    75,    76,    76,    77,    77,    78,
    78,    79,    79,    79,    80,    81,    81,    82,    82,    83,
    84,    84,    85,    85,    85,    86,    86,    87,    87,    88,
    88,    88,    88,    90,    89,    89,    91,    92,    92,    93,
    93,    93,    93,    93,    93,    95,    94,    94,    96,    96,
    96,    96,    96,    96,    97,    97,    98,    98,    99,   100,
   100,   101,   101,   102,   103,   103,   103,   104,   104,   105,
   105,   106,   106,   106,   107,   109,   110,   108,   111,   111,
   112,   112,   113,   113,   114,   115,   116,   116,   118,   117,
   117,   119,   119,   119,   119,   121,   120,   120,   122,   122,
   122,   122,   124,   123,   123,   125,   125,   126,   126,   128,
   127,   127,   130,   129,   131,   129,   129,   132,   132,   133,
   133,   134,   134,   135,   137,   136,   136,   138,   138,   138,
   138,   138,   138,   138,   139,   139,   139,   140,   140,   141,
   141,   141,   141,   142,   142,   143,   144,   145,   145,   145,
   146,   147,   148,   149,   149,   150,   150,   151,   151
};

static const short yyr2[] = {     0,
     2,     2,     0,     5,     5,     2,     2,     2,     2,     2,
     2,     0,     4,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     4,     4,     2,     2,     0,     4,     4,     2,     1,     4,
     3,     1,     1,     0,     1,     4,     3,     2,     1,     1,
     4,     4,     4,     4,     0,     2,     1,     1,     1,     4,
     4,     4,     4,     0,     5,     0,     1,     2,     1,     1,
     1,     1,     1,     1,     1,     0,     6,     4,     5,     3,
     3,     3,     3,     0,     1,     4,     2,     1,     1,     1,
     1,     4,     4,     4,     2,     2,     0,     1,     4,     2,
     1,     1,     1,     1,     5,     0,     0,     9,     4,     1,
     2,     1,     2,     1,     1,     1,     1,     0,     0,     6,
     4,     5,     3,     3,     0,     0,     6,     4,     5,     3,
     3,     0,     0,     5,     4,     2,     1,     1,     1,     0,
     5,     4,     0,     8,     0,    10,     4,     1,     1,     4,
     0,     1,     0,     4,     0,     9,     6,     5,     2,     2,
     2,     2,     2,     0,     3,     4,     7,     2,     1,     1,
     1,     1,     1,     4,     4,     4,     4,     1,     1,     1,
     4,     4,     4,     4,     7,     2,     1,     1,     1
};

static const short yydefact[] = {     3,
     0,     3,     3,     0,     1,     2,     0,     0,     0,     0,
     0,     0,    14,    15,    16,    17,    18,    19,    20,    21,
    22,     0,     0,     0,     5,     0,     4,     6,     9,     7,
     8,    10,    70,    71,    72,    73,    74,    75,    11,    13,
   157,   155,     0,    66,     0,    55,     0,    66,     0,     0,
     0,     0,     0,   149,   118,     0,   164,     0,     0,    69,
     0,     0,    67,     0,     0,     0,    39,    59,    58,     0,
     0,    57,     0,    25,    26,    76,     0,     0,     0,    27,
    28,   126,     0,    29,    30,   119,     0,     0,     0,     0,
     0,     0,   115,    90,    91,   117,    98,   103,   104,   102,
     0,     0,    23,    24,   143,     0,    32,    31,    34,    33,
    60,    62,     0,    68,    37,     0,    44,    36,    38,    52,
    51,     0,    56,    78,    84,    61,    63,   128,   132,   121,
   125,   135,     0,   116,   139,   138,     0,   137,   142,     0,
   147,    97,    97,     0,     0,     0,     0,   154,    44,   151,
     0,   156,   159,   160,   161,   162,   163,    64,    41,    50,
     0,    42,    43,    45,    49,    55,    55,     0,     0,     0,
   134,   136,   141,     0,     0,     0,     0,   101,   106,     0,
     0,     0,     0,    85,    89,     0,     0,     0,     0,     0,
     0,     0,    66,    40,     0,    48,    54,     0,    53,    77,
     0,     0,     0,     0,   118,   127,     0,     0,     0,   120,
     0,     0,     0,    93,    96,    95,    92,    99,   100,    44,
    94,     0,     0,     0,   110,   145,    44,   153,     0,     0,
   165,   170,     0,   169,   178,   179,   180,   171,   172,   173,
     0,   188,   189,     0,     0,     0,    65,     0,    47,    44,
    80,    81,    82,   114,    83,    44,   131,   130,    44,   123,
   124,     0,     0,     0,    88,     0,   105,     0,     0,   152,
     0,   158,     0,     0,     0,     0,     0,     0,     0,   166,
   168,     0,   184,   183,    46,     0,     0,   113,     0,     0,
   107,    86,    87,     0,   112,   153,   150,   144,     0,     0,
     0,     0,     0,     0,     0,     0,   187,    79,   129,   122,
     0,   109,   111,     0,     0,   181,   182,   174,   175,   176,
   177,     0,   186,     0,   146,   167,   185,   108,     0,     0,
     0
};

static const short yydefgoto[] = {     5,
     2,    12,     8,    22,   105,    76,    82,    86,    28,    59,
    29,    66,    67,   161,   162,   163,   164,   165,    30,    70,
   198,    72,    31,    61,   193,    62,    63,    32,    33,   125,
   168,   183,   264,   265,   185,    94,    95,   174,    96,   177,
    97,    98,   135,   220,   311,   224,   294,   253,   100,   136,
   101,    34,   131,   170,    35,   129,   169,    36,    88,   137,
   138,    37,    90,    38,   150,   268,    56,   188,   271,    39,
     3,    57,   106,   155,   233,   234,   235,   236,   237,   238,
   239,   240,   156,   157,   306,   244
};

static const short yypact[] = {    14,
    -4,    14,    14,    37,-32768,-32768,     5,    90,   276,   257,
    50,    27,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,   111,   128,   142,-32768,   201,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,   215,    67,   176,   197,   171,    67,   166,   132,
   212,   239,   151,-32768,   183,    19,-32768,   188,    96,-32768,
   193,   205,    52,   213,   109,   136,-32768,-32768,-32768,   216,
   244,-32768,   228,-32768,-32768,-32768,   233,   241,   290,-32768,
-32768,-32768,   321,-32768,-32768,-32768,   322,   324,   325,   324,
   326,   198,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
   327,    18,-32768,-32768,-32768,   153,-32768,-32768,-32768,-32768,
-32768,-32768,   317,-32768,-32768,   328,   315,-32768,-32768,-32768,
-32768,   269,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,    63,-32768,-32768,-32768,   158,-32768,-32768,   225,
-32768,-32768,-32768,   330,   332,   333,   334,-32768,   315,   309,
   152,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
   336,-32768,-32768,   108,-32768,   197,   197,    17,    28,    20,
-32768,-32768,-32768,   237,   271,    45,   256,-32768,-32768,   105,
   337,    22,   335,-32768,-32768,   338,   340,   324,   276,   260,
   341,   342,    67,-32768,   339,-32768,-32768,   268,-32768,-32768,
   343,   334,   183,   333,   183,-32768,   344,   333,   334,-32768,
   345,   334,   335,-32768,-32768,-32768,-32768,-32768,-32768,   315,
-32768,   346,    72,   347,-32768,-32768,   315,    23,   348,   131,
-32768,-32768,   279,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
   122,-32768,-32768,   349,    29,   298,-32768,    52,   315,   315,
-32768,-32768,   333,-32768,-32768,   315,   333,-32768,   315,-32768,
-32768,   350,    30,   300,-32768,   346,-32768,   324,   351,-32768,
   352,-32768,   342,   346,   346,   346,   346,   346,   346,-32768,
-32768,   346,-32768,-32768,-32768,   108,   353,-32768,   354,   355,
-32768,-32768,-32768,   302,-32768,    23,-32768,-32768,   304,   306,
   308,   310,   312,   314,   316,   318,-32768,-32768,-32768,-32768,
   183,-32768,-32768,   356,   357,-32768,-32768,-32768,-32768,-32768,
-32768,   358,-32768,   359,-32768,-32768,-32768,-32768,   364,   365,
-32768
};

static const short yypgoto[] = {    92,
-32768,-32768,-32768,    -8,   264,-32768,-32768,-32768,   261,-32768,
-32768,-32768,   303,  -114,-32768,   119,   121,  -155,-32768,   157,
   329,   -68,   265,   -40,-32768,   331,   179,-32768,-32768,-32768,
-32768,    12,    21,  -101,   -55,   -84,  -180,   230,  -190,-32768,
  -126,-32768,   -54,-32768,-32768,   161,-32768,   168,  -169,  -188,
   172,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,   -85,
  -130,-32768,-32768,-32768,-32768,-32768,-32768,-32768,    82,-32768,
-32768,-32768,-32768,-32768,  -177,  -221,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,  -263
};


#define	YYLAST		379


static const short yytable[] = {    93,
    99,    24,   123,   134,   140,   134,   172,    77,   196,   172,
   243,   281,   252,   225,   246,   254,     1,   178,   307,   254,
   200,   102,     4,   210,   281,   133,   103,   103,   142,    26,
    27,   206,     9,   143,   186,   142,   142,   104,   104,     7,
   143,   143,   323,   225,    10,   184,   201,   202,   203,   211,
   219,   142,   134,    25,   222,   134,   143,   207,   146,   113,
   114,   181,   274,   204,   288,   146,   146,   275,   288,   142,
   212,   213,   270,   208,   143,    60,   209,   281,   142,   205,
   145,   146,   147,   143,   276,   277,   278,   279,    93,    99,
    11,   329,   -12,   -12,     6,   299,   295,   172,   145,   108,
   184,   243,   228,   134,   266,   262,   242,   184,   146,   116,
   184,   142,   269,   109,    40,   195,   143,   117,   110,   134,
   324,    93,    99,   134,   313,   243,   160,    93,   142,   123,
   196,    41,    83,   143,   232,   287,   232,   142,    65,   118,
    84,   289,   143,   134,   290,    42,    85,    93,    99,    93,
    99,    91,   247,  -148,   282,   151,   152,    93,   146,  -148,
   133,   171,   293,   273,   274,   172,    79,   146,   134,   275,
  -148,    73,   134,    43,    80,    44,    64,   232,    65,    74,
   229,    81,   296,   134,    75,    92,   276,   277,   278,   279,
   232,   107,   189,    48,   190,   191,   111,   242,   293,   293,
   293,   293,   293,   293,   142,    68,   192,    69,   112,   143,
    93,   134,    87,   251,  -133,    58,   115,   232,   -35,   120,
   258,   242,    43,   260,    44,    45,    46,   133,   173,    47,
   144,   124,   -35,   145,   146,   147,   126,   -35,    93,    89,
   214,  -140,    48,   232,   127,    49,   215,   121,    50,   216,
    51,   122,    68,    52,    69,    93,    99,    23,   176,   218,
    53,    54,   230,   231,    55,    13,    14,    15,    16,    17,
    18,    19,    20,    21,   217,   122,    68,   166,    69,   167,
   215,   245,   280,   216,    13,    14,    15,    16,    17,    18,
    19,    20,    21,   128,   300,   301,   302,   303,   304,   305,
   245,   284,   263,   292,   263,   312,   245,   315,   263,   316,
   263,   317,   263,   318,   263,   319,   263,   320,   263,   321,
   263,   322,   197,   199,   130,   132,   133,   158,   139,   141,
   148,   159,   176,   160,   179,   180,   182,   223,   187,   194,
   221,   226,   227,   241,   245,   250,   256,   259,   263,   249,
   267,   272,   283,   291,   297,   298,   308,   309,   310,   325,
   326,   327,   328,   330,   331,   149,   153,   285,   119,   286,
   154,   248,   175,   261,    71,   257,   255,   314,    78
};

static const short yycheck[] = {    55,
    55,    10,    71,    88,    90,    90,   137,    48,   164,   140,
   191,   233,   203,   183,   192,   204,     3,   144,   282,   208,
     4,     3,    27,     4,   246,     3,     9,     9,     7,     3,
     4,     4,    28,    12,   149,     7,     7,    20,    20,     3,
    12,    12,   306,   213,    40,   147,    30,    31,    32,    30,
   177,     7,   137,     4,    33,   140,    12,    30,    37,     8,
     9,   146,    34,    47,   253,    37,    37,    39,   257,     7,
    51,    52,    50,    46,    12,     9,    49,   299,     7,    63,
    36,    37,    38,    12,    56,    57,    58,    59,   144,   144,
     1,     0,     3,     4,     3,   273,   266,   228,    36,     4,
   202,   282,   188,   188,    33,   220,   191,   209,    37,     1,
   212,     7,   227,    18,     4,     8,    12,     9,    23,   204,
   311,   177,   177,   208,   294,   306,    19,   183,     7,   198,
   286,     4,     1,    12,   190,   250,   192,     7,     3,     4,
     9,   256,    12,   228,   259,     4,    15,   203,   203,   205,
   205,     1,   193,     3,    33,     3,     4,   213,    37,     9,
     3,     4,   264,    33,    34,   296,     1,    37,   253,    39,
    20,     1,   257,    22,     9,    24,     1,   233,     3,     9,
   189,    16,   268,   268,    14,     3,    56,    57,    58,    59,
   246,     4,    41,    42,    43,    44,     4,   282,   300,   301,
   302,   303,   304,   305,     7,     9,    55,    11,     4,    12,
   266,   296,     1,   202,     3,     1,     4,   273,     4,     4,
   209,   306,    22,   212,    24,    25,    26,     3,     4,    29,
    33,     4,    18,    36,    37,    38,     4,    23,   294,     1,
     4,     3,    42,   299,     4,    45,    10,     4,    48,    13,
    50,     8,     9,    53,    11,   311,   311,     1,     3,     4,
    60,    61,     3,     4,    64,     9,    10,    11,    12,    13,
    14,    15,    16,    17,     4,     8,     9,     9,    11,    11,
    10,     3,     4,    13,     9,    10,    11,    12,    13,    14,
    15,    16,    17,     4,   274,   275,   276,   277,   278,   279,
     3,     4,     3,     4,     3,     4,     3,     4,     3,     4,
     3,     4,     3,     4,     3,     4,     3,     4,     3,     4,
     3,     4,   166,   167,     4,     4,     3,    11,     4,     4,
     4,     4,     3,    19,     3,     3,     3,     3,    30,     4,
     4,     4,     3,     3,     3,     3,     3,     3,     3,    11,
     4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
     4,     4,     4,     0,     0,   102,   106,   249,    66,   249,
   106,   193,   143,   213,    46,   208,   205,   296,    48
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
#line 1582 "grammar.cc"

  switch (yyn) {

case 5:
#line 101 "ppddl.y"
{
          log_error((char*)"syntax error in domain");
          yyerrok;
      ;
    break;}
case 13:
#line 118 "ppddl.y"
{ domain_name_ = yyvsp[-1].sym->text; ;
    break;}
case 14:
#line 124 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 15:
#line 125 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 16:
#line 126 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 17:
#line 127 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 18:
#line 128 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 19:
#line 129 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 20:
#line 130 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 21:
#line 131 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 22:
#line 132 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 23:
#line 136 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 24:
#line 137 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 25:
#line 141 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 26:
#line 142 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 27:
#line 146 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 28:
#line 147 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 29:
#line 151 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 30:
#line 152 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 32:
#line 159 "ppddl.y"
{
          log_error((char*)"syntax error in requirements declaration.");
          yyerrok;
      ;
    break;}
case 33:
#line 166 "ppddl.y"
{ declare_multivalued_variable_translation(); ;
    break;}
case 37:
#line 175 "ppddl.y"
{
          log_error((char*)"syntax error in (:predicates ...)");
          yyerrok;
      ;
    break;}
case 40:
#line 187 "ppddl.y"
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
#line 195 "ppddl.y"
{
          log_error((char*)"syntax error in predicate declaration");
          yyerrok;
      ;
    break;}
case 43:
#line 203 "ppddl.y"
{
          // must reverse parameter list
          var_symbol_vec tmp_list(*yyvsp[0].vparam);
          yyvsp[0].vparam->clear();
          yyvsp[0].vparam->insert(yyvsp[0].vparam->end(), tmp_list.rbegin(), tmp_list.rend());
          yyval.vparam = yyvsp[0].vparam;
      ;
    break;}
case 44:
#line 210 "ppddl.y"
{ yyval.vparam = new var_symbol_vec; ;
    break;}
case 45:
#line 214 "ppddl.y"
{
          set_variable_type(*yyvsp[0].vparam, yyvsp[0].vparam->size(), dom_top_type_);
          yyval.vparam = yyvsp[0].vparam;
      ;
    break;}
case 46:
#line 221 "ppddl.y"
{
          set_variable_type(*yyvsp[-3].vparam, yyvsp[-3].vparam->size(), static_cast<TypeSymbol*>(yyvsp[-1].sym->val));
          yyvsp[0].vparam->insert(yyvsp[0].vparam->end(), yyvsp[-3].vparam->rbegin(), yyvsp[-3].vparam->rend());
          delete yyvsp[-3].vparam;
          yyval.vparam = yyvsp[0].vparam;
      ;
    break;}
case 47:
#line 227 "ppddl.y"
{
          set_variable_type(*yyvsp[-2].vparam, yyvsp[-2].vparam->size(), static_cast<TypeSymbol*>(yyvsp[0].sym->val));
          yyval.vparam = yyvsp[-2].vparam;
      ;
    break;}
case 48:
#line 234 "ppddl.y"
{
          yyvsp[-1].vparam->push_back(static_cast<VariableSymbol*>(yyvsp[0].vsym));
          yyval.vparam = yyvsp[-1].vparam;
      ;
    break;}
case 49:
#line 238 "ppddl.y"
{ yyval.vparam = new var_symbol_vec; yyval.vparam->push_back(yyvsp[0].vsym); ;
    break;}
case 50:
#line 242 "ppddl.y"
{
          VariableSymbol *var = new VariableSymbol(yyvsp[0].sym->text);
          yyvsp[0].sym->val = var;
          yyval.vsym = var;
      ;
    break;}
case 52:
#line 253 "ppddl.y"
{
          set_type_type(dom_types_, dom_types_.size(), dom_top_type_);
      ;
    break;}
case 53:
#line 259 "ppddl.y"
{
          set_type_type(dom_types_, dom_types_.size(), static_cast<TypeSymbol*>(yyvsp[-1].sym->val));
      ;
    break;}
case 54:
#line 262 "ppddl.y"
{
          yyvsp[-1].sym->val = new TypeSymbol(yyvsp[-1].sym->text);
          if( write_warnings_ )
              std::cerr << "warning: assuming " << yyvsp[-1].sym->text << " - object" << std::endl;
          static_cast<TypeSymbol*>(yyvsp[-1].sym->val)->sym_type_ = dom_top_type_;
          set_type_type(dom_types_, dom_types_.size(), static_cast<TypeSymbol*>(yyvsp[-1].sym->val));
          dom_types_.push_back(static_cast<TypeSymbol*>(yyvsp[-1].sym->val));
      ;
    break;}
case 57:
#line 275 "ppddl.y"
{ ;
    break;}
case 59:
#line 280 "ppddl.y"
{
          yyvsp[0].sym->val = new TypeSymbol(yyvsp[0].sym->text);
          dom_types_.push_back(static_cast<TypeSymbol*>(yyvsp[0].sym->val));
      ;
    break;}
case 64:
#line 296 "ppddl.y"
{
          set_constant_type(dom_constants_, dom_constants_.size(), static_cast<TypeSymbol*>(yyvsp[0].sym->val));
      ;
    break;}
case 67:
#line 304 "ppddl.y"
{
          set_constant_type(dom_constants_, dom_constants_.size(), dom_top_type_);
      ;
    break;}
case 68:
#line 310 "ppddl.y"
{
          yyvsp[0].sym->val = new Symbol(yyvsp[0].sym->text);
          dom_constants_.push_back(static_cast<Symbol*>(yyvsp[0].sym->val));
      ;
    break;}
case 69:
#line 314 "ppddl.y"
{
          yyvsp[0].sym->val = new Symbol(yyvsp[0].sym->text);
          dom_constants_.push_back(static_cast<Symbol*>(yyvsp[0].sym->val));
      ;
    break;}
case 71:
#line 324 "ppddl.y"
{
          if( type_ == replanner ) {
              log_error((char*)"':axiom' is not a valid element in k-replanner.");
              yyerrok;
          }
      ;
    break;}
case 72:
#line 330 "ppddl.y"
{
          if( type_ == cp2fsc ) {
              log_error((char*)"':sensor' is not a valid element in cp2fsc.");
              yyerrok;
          }
      ;
    break;}
case 73:
#line 336 "ppddl.y"
{
          if( type_ == replanner ) {
              log_error((char*)"':observable' is not a valid element in k-replanner.");
              yyerrok;
          }
      ;
    break;}
case 74:
#line 342 "ppddl.y"
{
          if( type_ == replanner ) {
              log_error((char*)"':sticky' is not a valid element in k-replanner.");
              yyerrok;
          }
      ;
    break;}
case 75:
#line 348 "ppddl.y"
{
          //declare_multivalued_variable_translation();
          if( type_ == cp2fsc ) {
              log_error((char*)"':sensor' is not a valid element in cp2fsc.");
              yyerrok;
          }
      ;
    break;}
case 76:
#line 360 "ppddl.y"
{
          Action *na = new Action(yyvsp[0].sym->text);
          dom_actions_.push_back(na);
      ;
    break;}
case 77:
#line 364 "ppddl.y"
{
          clear_param(dom_actions_.back()->param_);
          yyvsp[-3].sym->val = dom_actions_.back();
      ;
    break;}
case 78:
#line 368 "ppddl.y"
{
          log_error((char*)"syntax error in action declaration");
          yyerrok;
      ;
    break;}
case 79:
#line 375 "ppddl.y"
{
          dom_actions_.back()->param_ = *yyvsp[-1].vparam;
          delete yyvsp[-1].vparam;
      ;
    break;}
case 80:
#line 379 "ppddl.y"
{ dom_actions_.back()->precondition_ = yyvsp[0].condition; ;
    break;}
case 81:
#line 380 "ppddl.y"
{ dom_actions_.back()->effect_ = yyvsp[0].effect; ;
    break;}
case 82:
#line 381 "ppddl.y"
{
          declare_clg_translation();
          dom_actions_.back()->observe_ = yyvsp[0].effect;
      ;
    break;}
case 83:
#line 385 "ppddl.y"
{
          declare_multivalued_variable_translation();
          dom_actions_.back()->sensing_model_ = yyvsp[0].effect;
      ;
    break;}
case 86:
#line 394 "ppddl.y"
{ yyval.condition = yyvsp[-1].condition; ;
    break;}
case 87:
#line 398 "ppddl.y"
{
          const_cast<And*>(static_cast<const And*>(yyvsp[-1].condition))->push_back(yyvsp[0].condition);
          yyval.condition = yyvsp[-1].condition;
      ;
    break;}
case 88:
#line 402 "ppddl.y"
{
          And *cond = new And();
          cond->push_back(yyvsp[0].condition);
          yyval.condition = cond;
      ;
    break;}
case 89:
#line 410 "ppddl.y"
{
          // if literal is for equality, construct EQ
          if( yyvsp[0].atom->pred_ == dom_eq_pred_ )
              yyval.condition = new EQ(static_cast<VariableSymbol*>(yyvsp[0].atom->param_[0]), static_cast<VariableSymbol*>(yyvsp[0].atom->param_[1]), yyvsp[0].atom->negated_);
          else
              yyval.condition = new Literal(*yyvsp[0].atom);
          delete yyvsp[0].atom;
      ;
    break;}
case 92:
#line 426 "ppddl.y"
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
#line 438 "ppddl.y"
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
#line 450 "ppddl.y"
{
          const_cast<Literal*>(static_cast<const Literal*>(yyvsp[-1].atom))->negated_ = true;
          yyval.atom = yyvsp[-1].atom;
      ;
    break;}
case 95:
#line 457 "ppddl.y"
{
          if( yyvsp[0].sym->val == 0 )
              log_error((char*)"undeclared variable in atom args list");
          else
              yyvsp[-1].param->push_back(static_cast<VariableSymbol*>(yyvsp[0].sym->val));
          yyval.param = yyvsp[-1].param;
      ;
    break;}
case 96:
#line 464 "ppddl.y"
{
          yyvsp[-1].param->push_back(static_cast<Symbol*>(yyvsp[0].sym->val));
          yyval.param = yyvsp[-1].param;
      ;
    break;}
case 97:
#line 468 "ppddl.y"
{ yyval.param = new PDDL_Base::symbol_vec; ;
    break;}
case 99:
#line 473 "ppddl.y"
{ yyval.effect = yyvsp[-1].effect; ;
    break;}
case 100:
#line 477 "ppddl.y"
{
          const_cast<AndEffect*>(static_cast<const AndEffect*>(yyvsp[-1].effect))->push_back(yyvsp[0].effect);
          yyval.effect = yyvsp[-1].effect;
      ;
    break;}
case 101:
#line 481 "ppddl.y"
{
          AndEffect *eff = new AndEffect;
          eff->push_back(yyvsp[0].effect);
          yyval.effect = eff;
      ;
    break;}
case 105:
#line 495 "ppddl.y"
{ yyval.effect = new ConditionalEffect(yyvsp[-2].condition, yyvsp[-1].effect); ;
    break;}
case 106:
#line 499 "ppddl.y"
{
          forall_effects.push_back(new ForallEffect);
      ;
    break;}
case 107:
#line 502 "ppddl.y"
{
          forall_effects.back()->param_ = *yyvsp[-1].vparam;
          delete yyvsp[-1].vparam;
      ;
    break;}
case 108:
#line 506 "ppddl.y"
{
          forall_effects.back()->effect_ = yyvsp[-1].effect;
          clear_param(forall_effects.back()->param_);
          yyval.effect = forall_effects.back();
          forall_effects.pop_back();
      ;
    break;}
case 109:
#line 515 "ppddl.y"
{ yyval.effect = yyvsp[-1].effect; ;
    break;}
case 111:
#line 520 "ppddl.y"
{
          const_cast<AndEffect*>(static_cast<const AndEffect*>(yyvsp[-1].effect))->push_back(yyvsp[0].effect);
          yyval.effect = yyvsp[-1].effect;
      ;
    break;}
case 112:
#line 524 "ppddl.y"
{
          AndEffect *eff = new AndEffect;
          eff->push_back(yyvsp[0].effect);
          yyval.effect = eff;
      ;
    break;}
case 113:
#line 532 "ppddl.y"
{
          const_cast<AndEffect*>(static_cast<const AndEffect*>(yyvsp[-1].effect))->push_back(yyvsp[0].effect);
          yyval.effect = yyvsp[-1].effect;
      ;
    break;}
case 114:
#line 536 "ppddl.y"
{
          AndEffect *eff = new AndEffect;
          eff->push_back(yyvsp[0].effect);
          yyval.effect = eff;
      ;
    break;}
case 115:
#line 544 "ppddl.y"
{ yyval.effect = new AtomicEffect(*yyvsp[0].atom); delete yyvsp[0].atom; ;
    break;}
case 116:
#line 548 "ppddl.y"
{ yyval.effect = new AtomicEffect(*yyvsp[0].atom); delete yyvsp[0].atom; ;
    break;}
case 118:
#line 553 "ppddl.y"
{ yyval.effect = 0; ;
    break;}
case 119:
#line 557 "ppddl.y"
{
          Axiom *nr = new Axiom(yyvsp[0].sym->text);
          dom_axioms_.push_back(nr);
      ;
    break;}
case 120:
#line 561 "ppddl.y"
{
          clear_param(dom_axioms_.back()->param_);
          yyvsp[-3].sym->val = dom_axioms_.back();
      ;
    break;}
case 121:
#line 565 "ppddl.y"
{
          log_error((char*)"syntax error in axiom declaration");
          yyerrok;
      ;
    break;}
case 122:
#line 572 "ppddl.y"
{
          dom_axioms_.back()->param_ = *yyvsp[-1].vparam;
          delete yyvsp[-1].vparam;
      ;
    break;}
case 123:
#line 576 "ppddl.y"
{ dom_axioms_.back()->body_ = yyvsp[0].condition; ;
    break;}
case 124:
#line 577 "ppddl.y"
{ dom_axioms_.back()->head_ = yyvsp[0].effect; ;
    break;}
case 126:
#line 582 "ppddl.y"
{
          Sensor *nr = new Sensor(yyvsp[0].sym->text);
          dom_sensors_.push_back(nr);
      ;
    break;}
case 127:
#line 586 "ppddl.y"
{
          clear_param(dom_sensors_.back()->param_);
          yyvsp[-3].sym->val = dom_sensors_.back();
      ;
    break;}
case 128:
#line 590 "ppddl.y"
{
          log_error((char*)"syntax error in sensor declaration");
          yyerrok;
      ;
    break;}
case 129:
#line 597 "ppddl.y"
{
          dom_sensors_.back()->param_ = *yyvsp[-1].vparam;
          delete yyvsp[-1].vparam;
      ;
    break;}
case 130:
#line 601 "ppddl.y"
{ dom_sensors_.back()->condition_ = yyvsp[0].condition; ;
    break;}
case 131:
#line 602 "ppddl.y"
{ dom_sensors_.back()->sense_ = yyvsp[0].effect; ;
    break;}
case 133:
#line 607 "ppddl.y"
{
          Observable *obs = new Observable;
          dom_observables_.push_back(obs);
          tmp_effect_vec_ptr_ = &obs->observables_;
      ;
    break;}
case 135:
#line 613 "ppddl.y"
{
          log_error((char*)"syntax error in observable declaration");
          yyerrok;
      ;
    break;}
case 136:
#line 620 "ppddl.y"
{
          tmp_effect_vec_ptr_->push_back(yyvsp[0].effect);
      ;
    break;}
case 137:
#line 623 "ppddl.y"
{
          tmp_effect_vec_ptr_->push_back(yyvsp[0].effect);
      ;
    break;}
case 140:
#line 634 "ppddl.y"
{
          Sticky *sticky = new Sticky;
          dom_stickies_.push_back(sticky);
          tmp_effect_vec_ptr_ = &sticky->stickies_;
      ;
    break;}
case 142:
#line 640 "ppddl.y"
{
          log_error((char*)"syntax error in sticky declaration");
          yyerrok;
      ;
    break;}
case 143:
#line 647 "ppddl.y"
{
          Variable *var = 0;
          if( yyvsp[-1].ival == 0 )
              var = new StateVariable(yyvsp[0].sym->text);
          else
              var = new ObsVariable(yyvsp[0].sym->text);
          multivalued_variables_.push_back(var);
          tmp_effect_vec_ptr_ = &var->values_;
      ;
    break;}
case 144:
#line 656 "ppddl.y"
{
          yyvsp[-5].sym->val = multivalued_variables_.back();
      ;
    break;}
case 145:
#line 659 "ppddl.y"
{
          Variable *var = 0;
          if( yyvsp[-4].ival == 0 )
              var = new StateVariable(yyvsp[-2].sym->text);
          else
              var = new ObsVariable(yyvsp[-2].sym->text);
          var->param_ = *yyvsp[-1].vparam;
          delete yyvsp[-1].vparam;
          multivalued_variables_.push_back(var);
          tmp_effect_vec_ptr_ = &var->values_;
      ;
    break;}
case 146:
#line 670 "ppddl.y"
{
          clear_param(multivalued_variables_.back()->param_);
          yyvsp[-6].sym->val = multivalued_variables_.back();
      ;
    break;}
case 147:
#line 674 "ppddl.y"
{
          log_error((char*)"syntax error in state variable declaration");
          yyerrok;
      ;
    break;}
case 148:
#line 681 "ppddl.y"
{ yyval.ival = 0; ;
    break;}
case 149:
#line 682 "ppddl.y"
{ yyval.ival = 1; ;
    break;}
case 150:
#line 686 "ppddl.y"
{
          multivalued_variables_.back()->param_ = *yyvsp[-1].vparam;
          delete yyvsp[-1].vparam;
      ;
    break;}
case 152:
#line 694 "ppddl.y"
{
          assert(dynamic_cast<StateVariable*>(multivalued_variables_.back()) != 0);
          dynamic_cast<StateVariable*>(multivalued_variables_.back())->is_observable_ = true;
      ;
    break;}
case 154:
#line 704 "ppddl.y"
{
          declare_multivalued_variable_translation();
          default_sensing_model_ = yyvsp[-1].effect;
      ;
    break;}
case 155:
#line 714 "ppddl.y"
{
          problem_name_ = yyvsp[-1].sym->text;
      ;
    break;}
case 157:
#line 718 "ppddl.y"
{
          log_error((char*)"syntax error in problem definition.");
          yyerrok;
      ;
    break;}
case 166:
#line 736 "ppddl.y"
{ dom_init_ = *yyvsp[-1].ilist; delete yyvsp[-1].ilist; ;
    break;}
case 167:
#line 737 "ppddl.y"
{ dom_init_ = *yyvsp[-2].ilist; delete yyvsp[-2].ilist; ;
    break;}
case 168:
#line 741 "ppddl.y"
{
          init_element_vec *ilist = const_cast<init_element_vec*>(yyvsp[-1].ilist);
          ilist->push_back(const_cast<InitElement*>(yyvsp[0].ielem));
          yyval.ilist = ilist;
      ;
    break;}
case 169:
#line 746 "ppddl.y"
{
          init_element_vec *ilist = new init_element_vec;
          ilist->push_back(const_cast<InitElement*>(yyvsp[0].ielem));
          yyval.ilist = ilist;
      ;
    break;}
case 170:
#line 754 "ppddl.y"
{ yyval.ielem = new InitLiteral(*yyvsp[0].atom); ;
    break;}
case 171:
#line 755 "ppddl.y"
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
case 172:
#line 766 "ppddl.y"
{
          if( type_ == replanner ) {
              log_error((char*)"'clause' is not a valid element in k-replanner.");
              delete yyvsp[0].clause;
              yyerrok;
          } else {
              yyval.ielem = new InitClause(*yyvsp[0].clause);
              const_cast<Clause*>(yyvsp[0].clause)->clear();
              delete yyvsp[0].clause;
          }
      ;
    break;}
case 173:
#line 777 "ppddl.y"
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
case 174:
#line 791 "ppddl.y"
{
          yyval.invariant = new Invariant(Invariant::AT_LEAST_ONE, *static_cast<const And*>(yyvsp[-1].condition));
          const_cast<And*>(static_cast<const And*>(yyvsp[-1].condition))->clear();
          delete yyvsp[-1].condition;
      ;
    break;}
case 175:
#line 796 "ppddl.y"
{
          yyval.invariant = new Invariant(Invariant::AT_LEAST_ONE, *static_cast<const And*>(yyvsp[-1].condition));
          const_cast<And*>(static_cast<const And*>(yyvsp[-1].condition))->clear();
          delete yyvsp[-1].condition;
      ;
    break;}
case 176:
#line 804 "ppddl.y"
{
          yyval.invariant = new Invariant(Invariant::AT_MOST_ONE, *static_cast<const And*>(yyvsp[-1].condition));
          const_cast<And*>(static_cast<const And*>(yyvsp[-1].condition))->clear();
          delete yyvsp[-1].condition;
      ;
    break;}
case 177:
#line 812 "ppddl.y"
{
          yyval.invariant = new Invariant(Invariant::EXACTLY_ONE, *static_cast<const And*>(yyvsp[-1].condition));
          const_cast<And*>(static_cast<const And*>(yyvsp[-1].condition))->clear();
          delete yyvsp[-1].condition;
      ;
    break;}
case 181:
#line 826 "ppddl.y"
{
          yyval.clause = new Clause(*static_cast<const And*>(yyvsp[-1].condition));
          const_cast<And*>(static_cast<const And*>(yyvsp[-1].condition))->clear();
          delete yyvsp[-1].condition;
      ;
    break;}
case 182:
#line 834 "ppddl.y"
{
          yyval.oneof = new Oneof(*static_cast<const And*>(yyvsp[-1].condition));
          const_cast<And*>(static_cast<const And*>(yyvsp[-1].condition))->clear();
          delete yyvsp[-1].condition;
      ;
    break;}
case 183:
#line 842 "ppddl.y"
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
case 184:
#line 854 "ppddl.y"
{ dom_goal_ = yyvsp[-1].condition; ;
    break;}
case 185:
#line 855 "ppddl.y"
{ dom_goal_ = yyvsp[-2].condition; ;
    break;}
case 186:
#line 859 "ppddl.y"
{
          const_cast<And*>(static_cast<const And*>(yyvsp[-1].condition))->push_back(yyvsp[0].condition);
          yyval.condition = yyvsp[-1].condition;
      ;
    break;}
case 187:
#line 863 "ppddl.y"
{
          And *cond = new And;
          cond->push_back(yyvsp[0].condition);
          yyval.condition = cond;
      ;
    break;}
case 188:
#line 872 "ppddl.y"
{ yyval.condition = new Literal(*yyvsp[0].atom); delete yyvsp[0].atom; ;
    break;}
case 189:
#line 873 "ppddl.y"
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
#line 2656 "grammar.cc"
#line 876 "ppddl.y"


