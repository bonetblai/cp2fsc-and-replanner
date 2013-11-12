#define YY_PDDL_Parser_h_included

/*  A Bison++ parser, made from ppddl.y  */

 /* with Bison++ version bison++ Version 1.21-8, adapted from GNU bison by coetmeur@icdc.fr
  */


#line 1 "/home/bonet/space/software/bison++-1.21-8/lib/bison.cc"
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

/* #line 73 "/home/bonet/space/software/bison++-1.21-8/lib/bison.cc" */
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
    PDDL_Base::Atom                   *atom;
    PDDL_Base::symbol_vec             *param;
    PDDL_Base::variable_vec           *vparam;
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

#line 73 "/home/bonet/space/software/bison++-1.21-8/lib/bison.cc"
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

/* #line 117 "/home/bonet/space/software/bison++-1.21-8/lib/bison.cc" */
#line 176 "grammar.cc"

#line 117 "/home/bonet/space/software/bison++-1.21-8/lib/bison.cc"
/*  YY_PDDL_Parser_PURE */
#endif

/* section apres lecture def, avant lecture grammaire S2 */

/* #line 121 "/home/bonet/space/software/bison++-1.21-8/lib/bison.cc" */
#line 185 "grammar.cc"

#line 121 "/home/bonet/space/software/bison++-1.21-8/lib/bison.cc"
/* prefix */
#ifndef YY_PDDL_Parser_DEBUG

/* #line 123 "/home/bonet/space/software/bison++-1.21-8/lib/bison.cc" */
#line 192 "grammar.cc"

#line 123 "/home/bonet/space/software/bison++-1.21-8/lib/bison.cc"
/* YY_PDDL_Parser_DEBUG */
#endif


#ifndef YY_PDDL_Parser_LSP_NEEDED

/* #line 128 "/home/bonet/space/software/bison++-1.21-8/lib/bison.cc" */
#line 202 "grammar.cc"

#line 128 "/home/bonet/space/software/bison++-1.21-8/lib/bison.cc"
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

/* #line 236 "/home/bonet/space/software/bison++-1.21-8/lib/bison.cc" */
#line 315 "grammar.cc"
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
#define	TK_INT	275
#define	KW_REQS	276
#define	KW_CONSTANTS	277
#define	KW_PREDS	278
#define	KW_TYPES	279
#define	KW_DEFINE	280
#define	KW_DOMAIN	281
#define	KW_ACTION	282
#define	KW_ARGS	283
#define	KW_PRE	284
#define	KW_EFFECT	285
#define	KW_AND	286
#define	KW_OR	287
#define	KW_EXISTS	288
#define	KW_FORALL	289
#define	KW_NOT	290
#define	KW_WHEN	291
#define	KW_ONEOF	292
#define	KW_PROBLEM	293
#define	KW_FORDOMAIN	294
#define	KW_OBJECTS	295
#define	KW_INIT	296
#define	KW_GOAL	297
#define	KW_SENSOR	298
#define	KW_SENSE	299
#define	KW_OBSERVE	300
#define	KW_AXIOM	301
#define	KW_COND	302
#define	KW_OBSERVABLE	303
#define	KW_BODY	304
#define	KW_HEAD	305
#define	KW_STICKY	306
#define	KW_FLUENTS	307
#define	KW_HIDDEN	308
#define	KW_INVARIANT	309
#define	KW_AT_LEAST_ONE	310
#define	KW_AT_MOST_ONE	311
#define	KW_EXACTLY_ONE	312


#line 236 "/home/bonet/space/software/bison++-1.21-8/lib/bison.cc"
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

/* #line 280 "/home/bonet/space/software/bison++-1.21-8/lib/bison.cc" */
#line 420 "grammar.cc"
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
static const int TK_INT;
static const int KW_REQS;
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


#line 280 "/home/bonet/space/software/bison++-1.21-8/lib/bison.cc"
 /* decl const */
#else
enum YY_PDDL_Parser_ENUM_TOKEN { YY_PDDL_Parser_NULL_TOKEN=0

/* #line 283 "/home/bonet/space/software/bison++-1.21-8/lib/bison.cc" */
#line 484 "grammar.cc"
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
	,TK_INT=275
	,KW_REQS=276
	,KW_CONSTANTS=277
	,KW_PREDS=278
	,KW_TYPES=279
	,KW_DEFINE=280
	,KW_DOMAIN=281
	,KW_ACTION=282
	,KW_ARGS=283
	,KW_PRE=284
	,KW_EFFECT=285
	,KW_AND=286
	,KW_OR=287
	,KW_EXISTS=288
	,KW_FORALL=289
	,KW_NOT=290
	,KW_WHEN=291
	,KW_ONEOF=292
	,KW_PROBLEM=293
	,KW_FORDOMAIN=294
	,KW_OBJECTS=295
	,KW_INIT=296
	,KW_GOAL=297
	,KW_SENSOR=298
	,KW_SENSE=299
	,KW_OBSERVE=300
	,KW_AXIOM=301
	,KW_COND=302
	,KW_OBSERVABLE=303
	,KW_BODY=304
	,KW_HEAD=305
	,KW_STICKY=306
	,KW_FLUENTS=307
	,KW_HIDDEN=308
	,KW_INVARIANT=309
	,KW_AT_LEAST_ONE=310
	,KW_AT_MOST_ONE=311
	,KW_EXACTLY_ONE=312


#line 283 "/home/bonet/space/software/bison++-1.21-8/lib/bison.cc"
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

/* #line 314 "/home/bonet/space/software/bison++-1.21-8/lib/bison.cc" */
#line 576 "grammar.cc"
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
const int YY_PDDL_Parser_CLASS::TK_INT=275;
const int YY_PDDL_Parser_CLASS::KW_REQS=276;
const int YY_PDDL_Parser_CLASS::KW_CONSTANTS=277;
const int YY_PDDL_Parser_CLASS::KW_PREDS=278;
const int YY_PDDL_Parser_CLASS::KW_TYPES=279;
const int YY_PDDL_Parser_CLASS::KW_DEFINE=280;
const int YY_PDDL_Parser_CLASS::KW_DOMAIN=281;
const int YY_PDDL_Parser_CLASS::KW_ACTION=282;
const int YY_PDDL_Parser_CLASS::KW_ARGS=283;
const int YY_PDDL_Parser_CLASS::KW_PRE=284;
const int YY_PDDL_Parser_CLASS::KW_EFFECT=285;
const int YY_PDDL_Parser_CLASS::KW_AND=286;
const int YY_PDDL_Parser_CLASS::KW_OR=287;
const int YY_PDDL_Parser_CLASS::KW_EXISTS=288;
const int YY_PDDL_Parser_CLASS::KW_FORALL=289;
const int YY_PDDL_Parser_CLASS::KW_NOT=290;
const int YY_PDDL_Parser_CLASS::KW_WHEN=291;
const int YY_PDDL_Parser_CLASS::KW_ONEOF=292;
const int YY_PDDL_Parser_CLASS::KW_PROBLEM=293;
const int YY_PDDL_Parser_CLASS::KW_FORDOMAIN=294;
const int YY_PDDL_Parser_CLASS::KW_OBJECTS=295;
const int YY_PDDL_Parser_CLASS::KW_INIT=296;
const int YY_PDDL_Parser_CLASS::KW_GOAL=297;
const int YY_PDDL_Parser_CLASS::KW_SENSOR=298;
const int YY_PDDL_Parser_CLASS::KW_SENSE=299;
const int YY_PDDL_Parser_CLASS::KW_OBSERVE=300;
const int YY_PDDL_Parser_CLASS::KW_AXIOM=301;
const int YY_PDDL_Parser_CLASS::KW_COND=302;
const int YY_PDDL_Parser_CLASS::KW_OBSERVABLE=303;
const int YY_PDDL_Parser_CLASS::KW_BODY=304;
const int YY_PDDL_Parser_CLASS::KW_HEAD=305;
const int YY_PDDL_Parser_CLASS::KW_STICKY=306;
const int YY_PDDL_Parser_CLASS::KW_FLUENTS=307;
const int YY_PDDL_Parser_CLASS::KW_HIDDEN=308;
const int YY_PDDL_Parser_CLASS::KW_INVARIANT=309;
const int YY_PDDL_Parser_CLASS::KW_AT_LEAST_ONE=310;
const int YY_PDDL_Parser_CLASS::KW_AT_MOST_ONE=311;
const int YY_PDDL_Parser_CLASS::KW_EXACTLY_ONE=312;


#line 314 "/home/bonet/space/software/bison++-1.21-8/lib/bison.cc"
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

/* #line 325 "/home/bonet/space/software/bison++-1.21-8/lib/bison.cc" */
#line 648 "grammar.cc"


#define	YYFINAL		290
#define	YYFLAG		-32768
#define	YYNTBASE	58

#define YYTRANSLATE(x) ((unsigned)(x) <= 312 ? yytranslate[x] : 130)

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
    56,    57
};

#if YY_PDDL_Parser_DEBUG != 0
static const short yyprhs[] = {     0,
     0,     3,     6,     7,    13,    19,    22,    25,    28,    31,
    34,    35,    40,    42,    44,    46,    48,    50,    52,    54,
    56,    58,    60,    62,    64,    66,    68,    70,    75,    80,
    83,    86,    87,    92,    97,   100,   102,   107,   111,   116,
   119,   120,   123,   124,   129,   134,   139,   142,   143,   146,
   149,   150,   155,   160,   165,   168,   169,   172,   174,   176,
   178,   180,   182,   184,   185,   192,   197,   203,   207,   211,
   215,   216,   218,   223,   226,   228,   230,   232,   234,   239,
   244,   249,   252,   255,   256,   258,   263,   266,   268,   270,
   272,   274,   280,   281,   282,   292,   297,   299,   302,   304,
   307,   309,   311,   313,   318,   323,   328,   333,   335,   337,
   339,   344,   349,   350,   357,   362,   368,   372,   376,   377,
   378,   385,   390,   396,   400,   404,   405,   406,   412,   417,
   423,   427,   428,   429,   435,   440,   446,   450,   451,   452,
   462,   469,   475,   478,   481,   484,   487,   490,   491,   495,
   500,   508,   511,   513,   515,   517,   519,   521,   526,   531,
   539,   542,   544,   546
};

static const short yyrhs[] = {    59,
    58,     0,   120,    58,     0,     0,     3,    25,    61,    60,
     4,     0,     3,    25,    61,     1,     4,     0,    66,    60,
     0,    73,    60,     0,    76,    60,     0,    68,    60,     0,
    79,    60,     0,     0,     3,    26,    62,     4,     0,     9,
     0,    10,     0,    11,     0,    12,     0,    13,     0,    14,
     0,    15,     0,    16,     0,    17,     0,     9,     0,    14,
     0,     9,     0,    16,     0,     9,     0,    15,     0,     3,
    21,    67,     4,     0,     3,    21,     1,     4,     0,    67,
    24,     0,    67,    18,     0,     0,     3,    23,    69,     4,
     0,     3,    23,     1,     4,     0,    69,    70,     0,    70,
     0,     3,     9,    71,     4,     0,     3,     1,     4,     0,
    71,    72,     8,    11,     0,    71,    72,     0,     0,    72,
    19,     0,     0,     3,    24,    74,     4,     0,    74,    75,
     8,    11,     0,    74,    75,     8,     9,     0,    74,    75,
     0,     0,    75,    11,     0,    75,     9,     0,     0,     3,
    22,    77,     4,     0,     3,    40,    77,     4,     0,    77,
    78,     8,    11,     0,    77,    78,     0,     0,    78,     9,
     0,     9,     0,    80,     0,   108,     0,   111,     0,   114,
     0,   117,     0,     0,     3,    27,    63,    81,    82,     4,
     0,     3,    27,     1,     4,     0,    82,    28,     3,    71,
     4,     0,    82,    29,    83,     0,    82,    30,    90,     0,
    82,    45,    90,     0,     0,    85,     0,     3,    31,    84,
     4,     0,    84,    85,     0,    85,     0,    86,     0,    87,
     0,    88,     0,     3,    12,    89,     4,     0,     3,     7,
    89,     4,     0,     3,    35,    87,     4,     0,    89,    13,
     0,    89,    10,     0,     0,    92,     0,     3,    31,    91,
     4,     0,    91,    92,     0,    92,     0,   100,     0,    93,
     0,    94,     0,     3,    36,    83,    97,     4,     0,     0,
     0,     3,    34,     3,    95,    71,     4,    96,    90,     4,
     0,     3,    31,    98,     4,     0,   100,     0,    98,   100,
     0,   100,     0,    99,   101,     0,   101,     0,    86,     0,
    87,     0,     3,    54,    84,     4,     0,     3,    55,    84,
     4,     0,     3,    56,    84,     4,     0,     3,    57,    84,
     4,     0,   102,     0,   103,     0,   104,     0,     3,    32,
    84,     4,     0,     3,    37,    84,     4,     0,     0,     3,
    46,    65,   109,   110,     4,     0,     3,    46,     1,     4,
     0,   110,    28,     3,    71,     4,     0,   110,    49,    83,
     0,   110,    50,    97,     0,     0,     0,     3,    43,    64,
   112,   113,     4,     0,     3,    43,     1,     4,     0,   113,
    28,     3,    71,     4,     0,   113,    47,    83,     0,   113,
    44,    99,     0,     0,     0,     3,    48,   115,   116,     4,
     0,     3,    48,     1,     4,     0,   116,    28,     3,    71,
     4,     0,   116,    52,    99,     0,     0,     0,     3,    51,
   118,   119,     4,     0,     3,    51,     1,     4,     0,   119,
    28,     3,    71,     4,     0,   119,    52,    99,     0,     0,
     0,     3,    25,     3,    38,    62,     4,   121,   122,     4,
     0,     3,    25,     3,    38,     1,     4,     0,   122,     3,
    39,    62,     4,     0,   122,    66,     0,   122,    76,     0,
   122,   123,     0,   122,   126,     0,   122,   127,     0,     0,
     3,    41,     4,     0,     3,    41,   124,     4,     0,     3,
    41,     3,    31,   124,     4,     4,     0,   124,   125,     0,
   125,     0,    86,     0,   105,     0,   106,     0,   107,     0,
     3,    53,   124,     4,     0,     3,    42,   129,     4,     0,
     3,    42,     3,    31,   128,     4,     4,     0,   128,   129,
     0,   129,     0,    87,     0,    88,     0
};

#endif

#if YY_PDDL_Parser_DEBUG != 0
static const short yyrline[] = { 0,
    80,    82,    83,    86,    88,    94,    96,    97,    98,    99,
   100,   103,   109,   111,   112,   113,   114,   115,   116,   117,
   118,   121,   123,   126,   128,   131,   133,   138,   140,   146,
   148,   149,   154,   156,   162,   164,   167,   176,   182,   189,
   195,   198,   205,   210,   214,   218,   226,   229,   232,   236,
   240,   245,   247,   250,   254,   257,   260,   265,   273,   275,
   281,   287,   293,   303,   308,   312,   318,   323,   324,   325,
   326,   329,   331,   334,   339,   346,   350,   352,   355,   367,
   379,   386,   394,   398,   401,   403,   406,   411,   418,   420,
   421,   424,   428,   432,   436,   451,   453,   456,   461,   468,
   473,   480,   484,   488,   494,   501,   509,   517,   519,   520,
   523,   531,   539,   544,   548,   554,   559,   560,   561,   564,
   569,   573,   579,   584,   585,   586,   589,   593,   596,   602,
   607,   610,   613,   617,   620,   626,   631,   634,   639,   643,
   644,   650,   652,   653,   654,   655,   656,   657,   660,   662,
   663,   666,   672,   679,   681,   692,   703,   715,   727,   729,
   732,   737,   745,   747
};

static const char * const yytname[] = {   "$","error","$illegal.","TK_OPEN",
"TK_CLOSE","TK_OPEN_SQ","TK_CLOSE_SQ","TK_EQ","TK_HYPHEN","TK_NEW_SYMBOL","TK_OBJ_SYMBOL",
"TK_TYPE_SYMBOL","TK_PRED_SYMBOL","TK_VAR_SYMBOL","TK_ACTION_SYMBOL","TK_AXIOM_SYMBOL",
"TK_SENSOR_SYMBOL","TK_MISC_SYMBOL","TK_KEYWORD","TK_NEW_VAR_SYMBOL","TK_INT",
"KW_REQS","KW_CONSTANTS","KW_PREDS","KW_TYPES","KW_DEFINE","KW_DOMAIN","KW_ACTION",
"KW_ARGS","KW_PRE","KW_EFFECT","KW_AND","KW_OR","KW_EXISTS","KW_FORALL","KW_NOT",
"KW_WHEN","KW_ONEOF","KW_PROBLEM","KW_FORDOMAIN","KW_OBJECTS","KW_INIT","KW_GOAL",
"KW_SENSOR","KW_SENSE","KW_OBSERVE","KW_AXIOM","KW_COND","KW_OBSERVABLE","KW_BODY",
"KW_HEAD","KW_STICKY","KW_FLUENTS","KW_HIDDEN","KW_INVARIANT","KW_AT_LEAST_ONE",
"KW_AT_MOST_ONE","KW_EXACTLY_ONE","pddl_declarations","pddl_domain","domain_elements",
"domain_name","any_symbol","action_symbol","sensor_symbol","axiom_symbol","domain_requires",
"require_list","domain_predicates","predicate_list","predicate_decl","typed_param_list",
"typed_param_sym_list","domain_types","typed_type_list","primitive_type_list",
"domain_constants","typed_constant_list","ne_constant_sym_list","domain_structure",
"action_declaration","@1","action_elements","condition","condition_list","single_condition",
"literal","positive_literal","negative_literal","atom_argument_list","action_effect",
"action_effect_list","single_action_effect","conditional_effect","forall_effect",
"@2","@3","atomic_effect_kw_list","atomic_effect_list","positive_atomic_effect_list",
"atomic_effect","positive_atomic_effect","at_least_one_invariant","at_most_one_invariant",
"exactly_one_invariant","invariant","clause","oneof","axiom_declaration","@4",
"axiom_elements","sensor_declaration","@5","sensor_elements","observable_declaration",
"@6","observable_elements","sticky_declaration","@7","sticky_elements","pddl_problem",
"@8","problem_elements","initial_state","init_elements","single_init_element",
"hidden_state","goal_spec","goal_list","single_goal",""
};
#endif

static const short yyr1[] = {     0,
    58,    58,    58,    59,    59,    60,    60,    60,    60,    60,
    60,    61,    62,    62,    62,    62,    62,    62,    62,    62,
    62,    63,    63,    64,    64,    65,    65,    66,    66,    67,
    67,    67,    68,    68,    69,    69,    70,    70,    71,    71,
    71,    72,    72,    73,    74,    74,    74,    74,    75,    75,
    75,    76,    76,    77,    77,    77,    78,    78,    79,    79,
    79,    79,    79,    81,    80,    80,    82,    82,    82,    82,
    82,    83,    83,    84,    84,    85,    86,    86,    87,    87,
    88,    89,    89,    89,    90,    90,    91,    91,    92,    92,
    92,    93,    95,    96,    94,    97,    97,    98,    98,    99,
    99,   100,   101,   102,   102,   103,   104,   105,   105,   105,
   106,   107,   109,   108,   108,   110,   110,   110,   110,   112,
   111,   111,   113,   113,   113,   113,   115,   114,   114,   116,
   116,   116,   118,   117,   117,   119,   119,   119,   121,   120,
   120,   122,   122,   122,   122,   122,   122,   122,   123,   123,
   123,   124,   124,   125,   125,   125,   125,   126,   127,   127,
   128,   128,   129,   129
};

static const short yyr2[] = {     0,
     2,     2,     0,     5,     5,     2,     2,     2,     2,     2,
     0,     4,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     4,     4,     2,
     2,     0,     4,     4,     2,     1,     4,     3,     4,     2,
     0,     2,     0,     4,     4,     4,     2,     0,     2,     2,
     0,     4,     4,     4,     2,     0,     2,     1,     1,     1,
     1,     1,     1,     0,     6,     4,     5,     3,     3,     3,
     0,     1,     4,     2,     1,     1,     1,     1,     4,     4,
     4,     2,     2,     0,     1,     4,     2,     1,     1,     1,
     1,     5,     0,     0,     9,     4,     1,     2,     1,     2,
     1,     1,     1,     4,     4,     4,     4,     1,     1,     1,
     4,     4,     0,     6,     4,     5,     3,     3,     0,     0,
     6,     4,     5,     3,     3,     0,     0,     5,     4,     5,
     3,     0,     0,     5,     4,     5,     3,     0,     0,     9,
     6,     5,     2,     2,     2,     2,     2,     0,     3,     4,
     7,     2,     1,     1,     1,     1,     1,     4,     4,     7,
     2,     1,     1,     1
};

static const short yydefact[] = {     3,
     0,     3,     3,     0,     1,     2,     0,     0,     0,     0,
     0,     0,     0,    11,    11,    11,    11,    11,    59,    60,
    61,    62,    63,    13,    14,    15,    16,    17,    18,    19,
    20,    21,     0,     0,     0,     5,     0,    56,     0,    48,
     0,    56,     0,     0,     0,     0,     4,     6,     9,     7,
     8,    10,    12,   141,   139,     0,     0,     0,     0,     0,
     0,    36,    51,     0,    22,    23,    64,     0,     0,    24,
    25,   120,     0,    26,    27,   113,     0,   132,     0,   138,
   148,    29,    28,    31,    30,    52,    58,    55,    34,     0,
    41,    33,    35,    44,    47,    66,    71,    53,   122,   126,
   115,   119,   129,     0,   135,     0,     0,     0,    57,    38,
    43,     0,    50,    49,     0,     0,     0,   128,     0,     0,
   134,     0,     0,     0,   140,   143,   144,   145,   146,   147,
    54,    37,    40,    46,    45,    65,     0,     0,     0,     0,
   121,     0,     0,     0,   114,     0,     0,     0,    41,     0,
   103,   131,   101,    41,   137,     0,     0,     0,     0,     0,
    42,    41,     0,    68,    72,    76,    77,    78,     0,   102,
    69,    85,    90,    91,    89,    70,    41,   125,   124,    41,
   117,     0,   118,    97,    43,    84,    84,   100,    43,     0,
     0,   149,   154,   108,   109,   110,   155,   156,   157,     0,
   153,     0,   163,   164,     0,     0,     0,    39,    43,     0,
     0,     0,     0,     0,    43,    43,     0,   130,     0,     0,
   136,   142,     0,     0,     0,     0,     0,     0,     0,   150,
   152,     0,   159,   158,    67,     0,     0,    75,     0,     0,
     0,    88,    93,     0,   123,   116,     0,    99,    80,    83,
    82,    79,     0,     0,     0,     0,     0,     0,     0,     0,
   162,    73,    74,    81,    86,    87,    41,     0,    96,    98,
     0,   111,   112,   104,   105,   106,   107,     0,   161,    43,
    92,   151,   160,    94,     0,     0,    95,     0,     0,     0
};

static const short yydefgoto[] = {     5,
     2,    13,     8,    33,    67,    72,    76,    14,    57,    15,
    61,    62,   111,   133,    16,    63,    95,    17,    58,    88,
    18,    19,    97,   115,   164,   237,   238,   166,   167,   168,
   219,   171,   241,   172,   173,   174,   267,   285,   183,   247,
   152,   175,   153,   194,   195,   196,   197,   198,   199,    20,
   102,   117,    21,   100,   116,    22,    78,   104,    23,    80,
   106,     3,    81,   107,   128,   200,   201,   129,   130,   260,
   205
};

static const short yypact[] = {    18,
    23,    18,    18,    62,-32768,-32768,    55,   149,   227,   218,
    75,   167,    91,   109,   109,   109,   109,   109,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,   116,   139,   147,-32768,    85,-32768,   128,-32768,
   197,-32768,   121,   153,    22,    28,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,   161,   199,   200,   198,   110,
    48,-32768,   201,   204,-32768,-32768,-32768,   217,   208,-32768,
-32768,-32768,   210,-32768,-32768,-32768,   282,-32768,   283,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,   216,-32768,   284,
-32768,-32768,-32768,-32768,   246,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,     2,-32768,     6,   249,   122,-32768,-32768,
   285,   184,-32768,-32768,    71,    43,    27,-32768,   219,   287,
-32768,   288,   287,   134,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,    38,-32768,-32768,-32768,   289,   290,   291,   291,
-32768,   292,   287,   290,-32768,   293,   290,   294,-32768,   244,
-32768,   287,-32768,-32768,   287,   227,   255,   295,   296,   297,
-32768,-32768,    29,-32768,-32768,-32768,-32768,-32768,   165,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,   287,-32768,-32768,
-32768,   132,-32768,-32768,   298,-32768,-32768,-32768,   299,   300,
   103,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,   257,
-32768,   185,-32768,-32768,   301,   129,   259,-32768,   302,   304,
   287,   306,   307,   290,   308,   309,   304,-32768,    84,    94,
-32768,-32768,   296,   304,   304,   304,   304,   304,   304,-32768,
-32768,   304,-32768,-32768,-32768,    37,   261,-32768,   310,   135,
   263,-32768,-32768,   294,-32768,-32768,   265,-32768,-32768,-32768,
-32768,-32768,   267,   269,   271,   273,   275,   277,   279,   281,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,   311,-32768,-32768,
   312,-32768,-32768,-32768,-32768,-32768,-32768,   313,-32768,   314,
-32768,-32768,-32768,-32768,   291,   315,-32768,   320,   321,-32768
};

static const short yypgoto[] = {    35,
-32768,   164,-32768,    -8,-32768,-32768,-32768,   193,-32768,-32768,
-32768,   240,  -135,-32768,-32768,-32768,-32768,   215,   286,-32768,
-32768,-32768,-32768,-32768,  -132,    21,  -131,  -139,  -115,  -147,
   124,  -136,-32768,  -179,-32768,-32768,-32768,-32768,    79,-32768,
   -84,  -126,   -86,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,  -156,  -183,-32768,-32768,-32768,
  -207
};


#define	YYLAST		328


static const short yytable[] = {   170,
   170,    35,   207,   176,   151,   118,   165,   151,   170,   121,
   204,   179,   165,   185,   181,   165,   231,   193,   189,   193,
     1,   184,    77,   231,   261,  -127,   209,   151,    79,   119,
   145,  -133,   242,   122,   288,   186,   151,     6,   155,   151,
   187,   215,   203,   186,   216,   160,   141,     4,   187,  -127,
    60,    92,   279,   120,   146,  -133,   161,   123,   178,   210,
   193,   266,   151,   211,     7,   188,   253,   193,   188,   231,
   142,   211,   170,  -127,   136,   147,   148,   170,    36,  -133,
     9,   244,   165,   193,   204,    56,   143,   249,   -32,   144,
   248,   188,    10,   250,    47,   239,   251,   252,   137,   138,
   139,   170,   -32,   250,   170,   263,   251,   170,   -32,   186,
    90,    12,   204,   193,   187,   140,   203,   184,    91,    53,
   270,    69,   263,   263,   263,   263,   263,   263,    59,    70,
    60,   280,   131,   223,   224,   186,    71,   211,   186,   225,
   187,   186,    54,   187,   203,   170,   187,   190,   286,    11,
    55,    12,   -11,    73,    37,    38,   226,   227,   228,   229,
   224,    74,   217,   211,    82,   225,   211,    75,   213,   211,
   214,   186,   156,    42,   157,   158,   187,    48,    49,    50,
    51,    52,   226,   227,   228,   229,   159,    37,    38,    39,
    40,   186,   134,    41,   135,   212,   187,    64,   213,   211,
   214,    89,    83,    86,    94,    65,    42,    96,    87,    43,
    66,    99,    44,   101,    45,   232,    84,    46,    34,   211,
    98,   149,    85,   108,   109,    87,    24,    25,    26,    27,
    28,    29,    30,    31,    32,    24,    25,    26,    27,    28,
    29,    30,    31,    32,   254,   255,   256,   257,   258,   259,
   186,   124,   125,   112,   113,   187,   114,   191,   192,   206,
   230,   206,   234,   236,   262,   240,   265,   236,   269,   206,
   271,   236,   272,   236,   273,   236,   274,   236,   275,   236,
   276,   236,   277,   236,   278,   103,   105,   110,   132,   150,
   154,   162,   163,   169,   177,   180,   182,   202,   206,   126,
    93,   218,   221,   222,   233,   235,   236,   208,   240,   243,
   220,   245,   246,   264,   281,   282,   283,   284,   287,   289,
   290,   127,   268,     0,     0,     0,     0,    68
};

static const short yycheck[] = {   139,
   140,    10,   159,   140,   120,     4,   138,   123,   148,     4,
   158,   144,   144,   149,   147,   147,   200,   157,   154,   159,
     3,   148,     1,   207,   232,     4,   162,   143,     1,    28,
     4,     4,   212,    28,     0,     7,   152,     3,   123,   155,
    12,   177,   158,     7,   180,     8,     4,    25,    12,    28,
     3,     4,   260,    52,    28,    28,    19,    52,   143,    31,
   200,   241,   178,    35,     3,   152,   223,   207,   155,   253,
    28,    35,   212,    52,     4,    49,    50,   217,     4,    52,
    26,   214,   214,   223,   232,     1,    44,     4,     4,    47,
   217,   178,    38,    10,     4,   211,    13,     4,    28,    29,
    30,   241,    18,    10,   244,   237,    13,   247,    24,     7,
     1,     3,   260,   253,    12,    45,   232,   244,     9,     4,
   247,     1,   254,   255,   256,   257,   258,   259,     1,     9,
     3,   267,    11,    31,    32,     7,    16,    35,     7,    37,
    12,     7,     4,    12,   260,   285,    12,   156,   285,     1,
     4,     3,     4,     1,    21,    22,    54,    55,    56,    57,
    32,     9,    31,    35,     4,    37,    35,    15,    34,    35,
    36,     7,    39,    40,    41,    42,    12,    14,    15,    16,
    17,    18,    54,    55,    56,    57,    53,    21,    22,    23,
    24,     7,     9,    27,    11,    31,    12,     1,    34,    35,
    36,     4,     4,     4,     4,     9,    40,     4,     9,    43,
    14,     4,    46,     4,    48,    31,    18,    51,     1,    35,
     4,     3,    24,     8,     9,     9,     9,    10,    11,    12,
    13,    14,    15,    16,    17,     9,    10,    11,    12,    13,
    14,    15,    16,    17,   224,   225,   226,   227,   228,   229,
     7,     3,     4,     8,     9,    12,    11,     3,     4,     3,
     4,     3,     4,     3,     4,     3,     4,     3,     4,     3,
     4,     3,     4,     3,     4,     3,     4,     3,     4,     3,
     4,     3,     4,     3,     4,     4,     4,     4,     4,     3,
     3,     3,     3,     3,     3,     3,     3,     3,     3,   107,
    61,     4,     4,     4,     4,     4,     3,    11,     3,     3,
   187,     4,     4,     4,     4,     4,     4,     4,     4,     0,
     0,   107,   244,    -1,    -1,    -1,    -1,    42
};

#line 325 "/home/bonet/space/software/bison++-1.21-8/lib/bison.cc"
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


/* #line 811 "/home/bonet/space/software/bison++-1.21-8/lib/bison.cc" */
#line 1512 "grammar.cc"

  switch (yyn) {

case 5:
#line 88 "ppddl.y"
{
          log_error((char*)"syntax error in domain");
          yyerrok;
      ;
    break;}
case 12:
#line 104 "ppddl.y"
{ domain_name = yyvsp[-1].sym->text; ;
    break;}
case 13:
#line 110 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 14:
#line 111 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 15:
#line 112 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 16:
#line 113 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 17:
#line 114 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 18:
#line 115 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 19:
#line 116 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 20:
#line 117 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 21:
#line 118 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 22:
#line 122 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 23:
#line 123 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 24:
#line 127 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 25:
#line 128 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 26:
#line 132 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 27:
#line 133 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 29:
#line 140 "ppddl.y"
{
          log_error((char*)"syntax error in requirements declaration.");
          yyerrok;
      ;
    break;}
case 34:
#line 156 "ppddl.y"
{
          log_error((char*)"syntax error in (:predicates ...)");
          yyerrok;
      ;
    break;}
case 37:
#line 168 "ppddl.y"
{
          PredicateSymbol *p = new PredicateSymbol(yyvsp[-2].sym->text);
          dom_predicates.push_back(p);
          p->param = *yyvsp[-1].vparam;
          delete yyvsp[-1].vparam;
          clear_param(p->param);
          yyvsp[-2].sym->val = p;
      ;
    break;}
case 38:
#line 176 "ppddl.y"
{
          log_error((char*)"syntax error in predicate declaration");
          yyerrok;
      ;
    break;}
case 39:
#line 183 "ppddl.y"
{
          set_variable_type(*yyvsp[-2].vparam, yyvsp[-2].vparam->size(), (TypeSymbol*)yyvsp[0].sym->val);
          yyvsp[-3].vparam->insert(yyvsp[-3].vparam->end(), yyvsp[-2].vparam->begin(), yyvsp[-2].vparam->end());
          delete yyvsp[-2].vparam;
          yyval.vparam = yyvsp[-3].vparam;
      ;
    break;}
case 40:
#line 189 "ppddl.y"
{
          set_variable_type(*yyvsp[-1].vparam, yyvsp[-1].vparam->size(), dom_top_type);
          yyvsp[-1].vparam->insert(yyvsp[-1].vparam->end(), yyvsp[0].vparam->begin(), yyvsp[0].vparam->end());
          delete yyvsp[0].vparam;
          yyval.vparam = yyvsp[-1].vparam;
      ;
    break;}
case 41:
#line 195 "ppddl.y"
{ yyval.vparam = new variable_vec; ;
    break;}
case 42:
#line 199 "ppddl.y"
{
          VariableSymbol *var = new VariableSymbol(yyvsp[0].sym->text);
          yyvsp[0].sym->val = var;
          yyvsp[-1].vparam->push_back(var);
          yyval.vparam = yyvsp[-1].vparam;
      ;
    break;}
case 43:
#line 205 "ppddl.y"
{ yyval.vparam = new variable_vec; ;
    break;}
case 45:
#line 215 "ppddl.y"
{
          set_type_type(dom_types, dom_types.size(), (TypeSymbol*)yyvsp[0].sym->val);
      ;
    break;}
case 46:
#line 218 "ppddl.y"
{
          yyvsp[0].sym->val = new TypeSymbol(yyvsp[0].sym->text);
          if( write_warnings )
              std::cerr << "warning: assuming " << yyvsp[0].sym->text << " - object" << std::endl;
          ((TypeSymbol*)yyvsp[0].sym->val)->sym_type = dom_top_type;
          set_type_type(dom_types, dom_types.size(), (TypeSymbol*)yyvsp[0].sym->val);
          dom_types.push_back((TypeSymbol*)yyvsp[0].sym->val);
      ;
    break;}
case 47:
#line 226 "ppddl.y"
{
          set_type_type(dom_types, dom_types.size(), dom_top_type);
      ;
    break;}
case 49:
#line 233 "ppddl.y"
{
          /* the type is already (implicitly) declared */
      ;
    break;}
case 50:
#line 236 "ppddl.y"
{
          yyvsp[0].sym->val = new TypeSymbol(yyvsp[0].sym->text);
          dom_types.push_back((TypeSymbol*)yyvsp[0].sym->val);
      ;
    break;}
case 54:
#line 251 "ppddl.y"
{
          set_constant_type(dom_constants, dom_constants.size(), (TypeSymbol*)yyvsp[0].sym->val);
      ;
    break;}
case 55:
#line 254 "ppddl.y"
{
          set_constant_type(dom_constants, dom_constants.size(), dom_top_type);
      ;
    break;}
case 57:
#line 261 "ppddl.y"
{
          yyvsp[0].sym->val = new Symbol(yyvsp[0].sym->text);
          dom_constants.push_back((Symbol*)yyvsp[0].sym->val);
      ;
    break;}
case 58:
#line 265 "ppddl.y"
{
          yyvsp[0].sym->val = new Symbol(yyvsp[0].sym->text);
          dom_constants.push_back((Symbol*)yyvsp[0].sym->val);
      ;
    break;}
case 60:
#line 275 "ppddl.y"
{
         if( type_ == replanner ) {
             log_error((char*)"':axiom' is not a valid element in k-replanner.");
             yyerrok;
         }
      ;
    break;}
case 61:
#line 281 "ppddl.y"
{
         if( type_ == cp2fsc ) {
             log_error((char*)"':sensor' is not a valid element in cp2fsc.");
             yyerrok;
         }
      ;
    break;}
case 62:
#line 287 "ppddl.y"
{
         if( type_ == replanner ) {
             log_error((char*)"':observable' is not a valid element in k-replanner.");
             yyerrok;
         }
      ;
    break;}
case 63:
#line 293 "ppddl.y"
{
         if( type_ == replanner ) {
             log_error((char*)"':sticky' is not a valid element in k-replanner.");
             yyerrok;
         }
      ;
    break;}
case 64:
#line 304 "ppddl.y"
{
          Action *na = new Action(yyvsp[0].sym->text);
          dom_actions.push_back(na);
      ;
    break;}
case 65:
#line 308 "ppddl.y"
{
          clear_param(dom_actions.back()->param);
          yyvsp[-3].sym->val = dom_actions.back();
      ;
    break;}
case 66:
#line 312 "ppddl.y"
{
          log_error((char*)"syntax error in action declaration");
          yyerrok;
      ;
    break;}
case 67:
#line 319 "ppddl.y"
{
          dom_actions.back()->param = *yyvsp[-1].vparam;
          delete yyvsp[-1].vparam;
      ;
    break;}
case 68:
#line 323 "ppddl.y"
{ dom_actions.back()->precondition = yyvsp[0].condition; ;
    break;}
case 69:
#line 324 "ppddl.y"
{ dom_actions.back()->effect = yyvsp[0].effect; ;
    break;}
case 70:
#line 325 "ppddl.y"
{ dom_actions.back()->observe = yyvsp[0].effect; ;
    break;}
case 73:
#line 331 "ppddl.y"
{ yyval.condition = yyvsp[-1].condition; ;
    break;}
case 74:
#line 335 "ppddl.y"
{
          const_cast<And*>(static_cast<const And*>(yyvsp[-1].condition))->push_back(yyvsp[0].condition);
          yyval.condition = yyvsp[-1].condition;
      ;
    break;}
case 75:
#line 339 "ppddl.y"
{
          And *cond = new And();
          cond->push_back(yyvsp[0].condition);
          yyval.condition = cond;
      ;
    break;}
case 76:
#line 347 "ppddl.y"
{ yyval.condition = new Literal(*yyvsp[0].atom); delete yyvsp[0].atom; ;
    break;}
case 79:
#line 356 "ppddl.y"
{
          PredicateSymbol* p = (PredicateSymbol*)yyvsp[-2].sym->val;
          yyval.atom = new Atom(p);
          yyval.atom->param = *yyvsp[-1].param;
          delete yyvsp[-1].param;
          if( p->param.size() != yyval.atom->param.size() ) {
              std::ostringstream msg;
              msg << "wrong number of arguments for predicate '" << p->print_name << "'";
              log_error(const_cast<char*>(msg.str().c_str()));
          }
      ;
    break;}
case 80:
#line 367 "ppddl.y"
{
          yyval.atom = new Atom(dom_eq_pred);
          yyval.atom->param = *yyvsp[-1].param;
          delete yyvsp[-1].param;
          if( yyval.atom->param.size() != 2 ) {
              log_error((char*)"wrong number of arguments for equality");
          }
          assert(0); // TODO: remove this assertion which is here
                     // because (probably) the code for '=' is broken...
      ;
    break;}
case 81:
#line 380 "ppddl.y"
{
          const_cast<Literal*>(static_cast<const Literal*>(yyvsp[-1].atom))->neg = true;
          yyval.atom = yyvsp[-1].atom;
      ;
    break;}
case 82:
#line 387 "ppddl.y"
{
          if( yyvsp[0].sym->val == 0 )
              log_error((char*)"undeclared variable in atom args list");
          else
              yyvsp[-1].param->push_back((VariableSymbol*)yyvsp[0].sym->val);
          yyval.param = yyvsp[-1].param;
      ;
    break;}
case 83:
#line 394 "ppddl.y"
{
          yyvsp[-1].param->push_back((Symbol*)yyvsp[0].sym->val);
          yyval.param = yyvsp[-1].param;
      ;
    break;}
case 84:
#line 398 "ppddl.y"
{ yyval.param = new PDDL_Base::symbol_vec; ;
    break;}
case 86:
#line 403 "ppddl.y"
{ yyval.effect = yyvsp[-1].effect; ;
    break;}
case 87:
#line 407 "ppddl.y"
{
          const_cast<AndEffect*>(static_cast<const AndEffect*>(yyvsp[-1].effect))->push_back(yyvsp[0].effect);
          yyval.effect = yyvsp[-1].effect;
      ;
    break;}
case 88:
#line 411 "ppddl.y"
{
          AndEffect *eff = new AndEffect;
          eff->push_back(yyvsp[0].effect);
          yyval.effect = eff;
      ;
    break;}
case 92:
#line 425 "ppddl.y"
{ yyval.effect = new ConditionalEffect(yyvsp[-2].condition, yyvsp[-1].effect); ;
    break;}
case 93:
#line 429 "ppddl.y"
{
          forall_effects.push_back(new ForallEffect);
      ;
    break;}
case 94:
#line 432 "ppddl.y"
{
          forall_effects.back()->param = *yyvsp[-1].vparam;
          delete yyvsp[-1].vparam;
      ;
    break;}
case 95:
#line 436 "ppddl.y"
{
          forall_effects.back()->effect = yyvsp[-1].effect;
          clear_param(forall_effects.back()->param);
          yyval.effect = forall_effects.back();
          forall_effects.pop_back();
      ;
    break;}
case 96:
#line 452 "ppddl.y"
{ yyval.effect = yyvsp[-1].effect; ;
    break;}
case 98:
#line 457 "ppddl.y"
{
          const_cast<AndEffect*>(static_cast<const AndEffect*>(yyvsp[-1].effect))->push_back(yyvsp[0].effect);
          yyval.effect = yyvsp[-1].effect;
      ;
    break;}
case 99:
#line 461 "ppddl.y"
{
          AndEffect *eff = new AndEffect;
          eff->push_back(yyvsp[0].effect);
          yyval.effect = eff;
      ;
    break;}
case 100:
#line 469 "ppddl.y"
{
          const_cast<AndEffect*>(static_cast<const AndEffect*>(yyvsp[-1].effect))->push_back(yyvsp[0].effect);
          yyval.effect = yyvsp[-1].effect;
      ;
    break;}
case 101:
#line 473 "ppddl.y"
{
          AndEffect *eff = new AndEffect;
          eff->push_back(yyvsp[0].effect);
          yyval.effect = eff;
      ;
    break;}
case 102:
#line 481 "ppddl.y"
{ yyval.effect = new AtomicEffect(*yyvsp[0].atom); delete yyvsp[0].atom; ;
    break;}
case 103:
#line 485 "ppddl.y"
{ yyval.effect = new AtomicEffect(*yyvsp[0].atom); delete yyvsp[0].atom; ;
    break;}
case 104:
#line 489 "ppddl.y"
{
          yyval.invariant = new Invariant(Invariant::AT_LEAST_ONE, *static_cast<const And*>(yyvsp[-1].condition));
          const_cast<And*>(static_cast<const And*>(yyvsp[-1].condition))->clear();
          delete yyvsp[-1].condition;
      ;
    break;}
case 105:
#line 494 "ppddl.y"
{
          yyval.invariant = new Invariant(Invariant::AT_LEAST_ONE, *static_cast<const And*>(yyvsp[-1].condition));
          const_cast<And*>(static_cast<const And*>(yyvsp[-1].condition))->clear();
          delete yyvsp[-1].condition;
      ;
    break;}
case 106:
#line 502 "ppddl.y"
{
          yyval.invariant = new Invariant(Invariant::AT_MOST_ONE, *static_cast<const And*>(yyvsp[-1].condition));
          const_cast<And*>(static_cast<const And*>(yyvsp[-1].condition))->clear();
          delete yyvsp[-1].condition;
      ;
    break;}
case 107:
#line 510 "ppddl.y"
{
          yyval.invariant = new Invariant(Invariant::EXACTLY_ONE, *static_cast<const And*>(yyvsp[-1].condition));
          const_cast<And*>(static_cast<const And*>(yyvsp[-1].condition))->clear();
          delete yyvsp[-1].condition;
      ;
    break;}
case 111:
#line 524 "ppddl.y"
{
          yyval.clause = new Clause(*static_cast<const And*>(yyvsp[-1].condition));
          const_cast<And*>(static_cast<const And*>(yyvsp[-1].condition))->clear();
          delete yyvsp[-1].condition;
      ;
    break;}
case 112:
#line 532 "ppddl.y"
{
          yyval.oneof = new Oneof(*static_cast<const And*>(yyvsp[-1].condition));
          const_cast<And*>(static_cast<const And*>(yyvsp[-1].condition))->clear();
          delete yyvsp[-1].condition;
      ;
    break;}
case 113:
#line 540 "ppddl.y"
{
          Axiom *nr = new Axiom(yyvsp[0].sym->text);
          dom_axioms.push_back(nr);
      ;
    break;}
case 114:
#line 544 "ppddl.y"
{
          clear_param(dom_axioms.back()->param);
          yyvsp[-3].sym->val = dom_axioms.back();
      ;
    break;}
case 115:
#line 548 "ppddl.y"
{
          log_error((char*)"syntax error in axiom declaration");
          yyerrok;
      ;
    break;}
case 116:
#line 555 "ppddl.y"
{
          dom_axioms.back()->param = *yyvsp[-1].vparam;
          delete yyvsp[-1].vparam;
      ;
    break;}
case 117:
#line 559 "ppddl.y"
{ dom_axioms.back()->body = yyvsp[0].condition; ;
    break;}
case 118:
#line 560 "ppddl.y"
{ dom_axioms.back()->head = yyvsp[0].effect; ;
    break;}
case 120:
#line 565 "ppddl.y"
{
          Sensor *nr = new Sensor(yyvsp[0].sym->text);
          dom_sensors.push_back(nr);
      ;
    break;}
case 121:
#line 569 "ppddl.y"
{
          clear_param(dom_sensors.back()->param);
          yyvsp[-3].sym->val = dom_sensors.back();
      ;
    break;}
case 122:
#line 573 "ppddl.y"
{
          log_error((char*)"syntax error in sensor declaration");
          yyerrok;
      ;
    break;}
case 123:
#line 580 "ppddl.y"
{
          dom_sensors.back()->param = *yyvsp[-1].vparam;
          delete yyvsp[-1].vparam;
      ;
    break;}
case 124:
#line 584 "ppddl.y"
{ dom_sensors.back()->condition = yyvsp[0].condition; ;
    break;}
case 125:
#line 585 "ppddl.y"
{ dom_sensors.back()->sense = yyvsp[0].effect; ;
    break;}
case 127:
#line 590 "ppddl.y"
{
          Observable *obs = new Observable;
          dom_observables.push_back(obs);
      ;
    break;}
case 128:
#line 593 "ppddl.y"
{
          clear_param(dom_observables.back()->param);
      ;
    break;}
case 129:
#line 596 "ppddl.y"
{
          log_error((char*)"syntax error in observable declaration");
          yyerrok;
      ;
    break;}
case 130:
#line 603 "ppddl.y"
{
          dom_observables.back()->param = *yyvsp[-1].vparam;
          delete yyvsp[-1].vparam;
      ;
    break;}
case 131:
#line 607 "ppddl.y"
{
          dom_observables.back()->observables = yyvsp[0].effect;
      ;
    break;}
case 133:
#line 614 "ppddl.y"
{
          Sticky *stk = new Sticky;
          dom_stickies.push_back(stk);
      ;
    break;}
case 134:
#line 617 "ppddl.y"
{
          clear_param(dom_stickies.back()->param);
      ;
    break;}
case 135:
#line 620 "ppddl.y"
{
          log_error((char*)"syntax error in sticky declaration");
          yyerrok;
      ;
    break;}
case 136:
#line 627 "ppddl.y"
{
          dom_stickies.back()->param = *yyvsp[-1].vparam;
          delete yyvsp[-1].vparam;
      ;
    break;}
case 137:
#line 631 "ppddl.y"
{
          dom_stickies.back()->stickies = yyvsp[0].effect;
      ;
    break;}
case 139:
#line 640 "ppddl.y"
{
          problem_name = yyvsp[-1].sym->text;
      ;
    break;}
case 141:
#line 644 "ppddl.y"
{
          log_error((char*)"syntax error in problem definition.");
          yyerrok;
      ;
    break;}
case 150:
#line 662 "ppddl.y"
{ dom_init = *yyvsp[-1].ilist; delete yyvsp[-1].ilist; ;
    break;}
case 151:
#line 663 "ppddl.y"
{ dom_init = *yyvsp[-2].ilist; delete yyvsp[-2].ilist; ;
    break;}
case 152:
#line 667 "ppddl.y"
{
          init_element_vec *ilist = const_cast<init_element_vec*>(yyvsp[-1].ilist);
          ilist->push_back(const_cast<InitElement*>(yyvsp[0].ielem));
          yyval.ilist = ilist;
      ;
    break;}
case 153:
#line 672 "ppddl.y"
{
          init_element_vec *ilist = new init_element_vec;
          ilist->push_back(const_cast<InitElement*>(yyvsp[0].ielem));
          yyval.ilist = ilist;
      ;
    break;}
case 154:
#line 680 "ppddl.y"
{ yyval.ielem = new InitLiteral(*yyvsp[0].atom); ;
    break;}
case 155:
#line 681 "ppddl.y"
{
          if( type_ == cp2fsc ) {
              log_error((char*)"'invariant' is not a valid element in cp2fsc.");
              delete yyvsp[0].invariant;
              yyerrok;
          } else {
              yyval.ielem = new InitInvariant(*yyvsp[0].invariant);
              const_cast<Invariant*>(dynamic_cast<const Invariant*>(yyvsp[0].invariant))->clear();
              delete yyvsp[0].invariant;
          }
      ;
    break;}
case 156:
#line 692 "ppddl.y"
{
          if( type_ == replanner ) {
              log_error((char*)"'clause' is not a valid element in k-replanner.");
              delete yyvsp[0].clause;
              yyerrok;
          } else {
              yyval.ielem = new InitClause(*yyvsp[0].clause);
              const_cast<Clause*>(dynamic_cast<const Clause*>(yyvsp[0].clause))->clear();
              delete yyvsp[0].clause;
          }
      ;
    break;}
case 157:
#line 703 "ppddl.y"
{
          if( type_ == replanner ) {
              // We let oneofs pass in k-replanner as they are later mapped 
              // into invariants of type exactly-one. This is to support
              // CLG compatibility mode.
          }
          yyval.ielem = new InitOneof(*yyvsp[0].oneof);
          const_cast<Oneof*>(dynamic_cast<const Oneof*>(yyvsp[0].oneof))->clear();
          delete yyvsp[0].oneof;
      ;
    break;}
case 158:
#line 716 "ppddl.y"
{
          if( type_ == cp2fsc ) {
              log_error((char*)"':hidden' is not a valid element in cp2fsc.");
              yyerrok;
          } else {
              dom_hidden = *yyvsp[-1].ilist;
              delete yyvsp[-1].ilist;
          }
      ;
    break;}
case 159:
#line 728 "ppddl.y"
{ dom_goal = yyvsp[-1].condition; ;
    break;}
case 160:
#line 729 "ppddl.y"
{ dom_goal = yyvsp[-2].condition; ;
    break;}
case 161:
#line 733 "ppddl.y"
{
          const_cast<And*>(static_cast<const And*>(yyvsp[-1].condition))->push_back(yyvsp[0].condition);
          yyval.condition = yyvsp[-1].condition;
      ;
    break;}
case 162:
#line 737 "ppddl.y"
{
          And *cond = new And;
          cond->push_back(yyvsp[0].condition);
          yyval.condition = cond;
      ;
    break;}
case 163:
#line 746 "ppddl.y"
{ yyval.condition = new Literal(*yyvsp[0].atom); delete yyvsp[0].atom; ;
    break;}
case 164:
#line 747 "ppddl.y"
{ yyval.condition = new Literal(*yyvsp[0].atom); delete yyvsp[0].atom; ;
    break;}
}

#line 811 "/home/bonet/space/software/bison++-1.21-8/lib/bison.cc"
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

/* #line 1010 "/home/bonet/space/software/bison++-1.21-8/lib/bison.cc" */
#line 2472 "grammar.cc"
#line 750 "ppddl.y"


