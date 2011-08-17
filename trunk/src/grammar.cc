#define YY_PDDL_Parser_h_included

/*  A Bison++ parser, made from ppddl.y  */

 /* with Bison++ version bison++ Version 1.21-8, adapted from GNU bison by coetmeur@icdc.fr
  */


#line 1 "/opt/sfw/lib/bison.cc"
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

/* #line 73 "/opt/sfw/lib/bison.cc" */
#line 85 "grammar.cc"
#define YY_PDDL_Parser_ERROR  log_error
#define YY_PDDL_Parser_ERROR_BODY  = 0
#define YY_PDDL_Parser_ERROR_VERBOSE  1
#define YY_PDDL_Parser_LEX  next_token
#define YY_PDDL_Parser_LEX_BODY  = 0
#define YY_PDDL_Parser_DEBUG  1
#define YY_PDDL_Parser_INHERIT  : public PDDL_Base
#define YY_PDDL_Parser_CONSTRUCTOR_PARAM  StringTable& t
#define YY_PDDL_Parser_CONSTRUCTOR_INIT  : PDDL_Base(t), error_flag(false)
#define YY_PDDL_Parser_MEMBERS  \
  public: \
    virtual ~PDDL_Parser() { } \
    virtual std::ostream& syntax_errors() = 0; \
    bool error_flag; \
  private: \
    std::vector<ForallEffect*> forall_effects;
#line 20 "ppddl.y"

#include <stdlib.h>
#include <string.h>
#include <list>
#include <sstream>
#include "base.h"

#line 28 "ppddl.y"
typedef union {
    StringTable::Cell                 *sym;
    PDDL_Base::Atom                   *atom;
    PDDL_Base::symbol_vec             *param;
    PDDL_Base::variable_vec           *vparam;
    const PDDL_Base::Condition        *condition;
    const PDDL_Base::Effect           *effect;
    const PDDL_Base::init_element_vec *ilist;
    int                               ival;
} yy_PDDL_Parser_stype;
#define YY_PDDL_Parser_STYPE yy_PDDL_Parser_stype

#line 73 "/opt/sfw/lib/bison.cc"
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

/* #line 117 "/opt/sfw/lib/bison.cc" */
#line 170 "grammar.cc"

#line 117 "/opt/sfw/lib/bison.cc"
/*  YY_PDDL_Parser_PURE */
#endif

/* section apres lecture def, avant lecture grammaire S2 */

/* #line 121 "/opt/sfw/lib/bison.cc" */
#line 179 "grammar.cc"

#line 121 "/opt/sfw/lib/bison.cc"
/* prefix */
#ifndef YY_PDDL_Parser_DEBUG

/* #line 123 "/opt/sfw/lib/bison.cc" */
#line 186 "grammar.cc"

#line 123 "/opt/sfw/lib/bison.cc"
/* YY_PDDL_Parser_DEBUG */
#endif


#ifndef YY_PDDL_Parser_LSP_NEEDED

/* #line 128 "/opt/sfw/lib/bison.cc" */
#line 196 "grammar.cc"

#line 128 "/opt/sfw/lib/bison.cc"
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

/* #line 236 "/opt/sfw/lib/bison.cc" */
#line 309 "grammar.cc"
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
#define	KW_SENSED	299
#define	KW_AXIOM	300
#define	KW_COND	301
#define	KW_OBSERVABLE	302
#define	KW_BODY	303
#define	KW_HEAD	304
#define	KW_STICKY	305
#define	KW_FLUENTS	306
#define	KW_HIDDEN	307
#define	KW_INVARIANT	308


#line 236 "/opt/sfw/lib/bison.cc"
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

/* #line 280 "/opt/sfw/lib/bison.cc" */
#line 410 "grammar.cc"
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
static const int KW_SENSED;
static const int KW_AXIOM;
static const int KW_COND;
static const int KW_OBSERVABLE;
static const int KW_BODY;
static const int KW_HEAD;
static const int KW_STICKY;
static const int KW_FLUENTS;
static const int KW_HIDDEN;
static const int KW_INVARIANT;


#line 280 "/opt/sfw/lib/bison.cc"
 /* decl const */
#else
enum YY_PDDL_Parser_ENUM_TOKEN { YY_PDDL_Parser_NULL_TOKEN=0

/* #line 283 "/opt/sfw/lib/bison.cc" */
#line 470 "grammar.cc"
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
	,KW_SENSED=299
	,KW_AXIOM=300
	,KW_COND=301
	,KW_OBSERVABLE=302
	,KW_BODY=303
	,KW_HEAD=304
	,KW_STICKY=305
	,KW_FLUENTS=306
	,KW_HIDDEN=307
	,KW_INVARIANT=308


#line 283 "/opt/sfw/lib/bison.cc"
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

/* #line 314 "/opt/sfw/lib/bison.cc" */
#line 558 "grammar.cc"
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
const int YY_PDDL_Parser_CLASS::KW_SENSED=299;
const int YY_PDDL_Parser_CLASS::KW_AXIOM=300;
const int YY_PDDL_Parser_CLASS::KW_COND=301;
const int YY_PDDL_Parser_CLASS::KW_OBSERVABLE=302;
const int YY_PDDL_Parser_CLASS::KW_BODY=303;
const int YY_PDDL_Parser_CLASS::KW_HEAD=304;
const int YY_PDDL_Parser_CLASS::KW_STICKY=305;
const int YY_PDDL_Parser_CLASS::KW_FLUENTS=306;
const int YY_PDDL_Parser_CLASS::KW_HIDDEN=307;
const int YY_PDDL_Parser_CLASS::KW_INVARIANT=308;


#line 314 "/opt/sfw/lib/bison.cc"
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

/* #line 325 "/opt/sfw/lib/bison.cc" */
#line 626 "grammar.cc"


#define	YYFINAL		268
#define	YYFLAG		-32768
#define	YYNTBASE	54

#define YYTRANSLATE(x) ((unsigned)(x) <= 308 ? yytranslate[x] : 122)

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
    46,    47,    48,    49,    50,    51,    52,    53
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
   212,   214,   219,   222,   224,   226,   228,   230,   235,   240,
   245,   248,   251,   252,   254,   259,   262,   264,   266,   268,
   270,   276,   277,   278,   288,   293,   295,   298,   300,   303,
   305,   307,   309,   314,   319,   324,   325,   332,   337,   343,
   347,   351,   352,   353,   360,   365,   371,   375,   379,   380,
   381,   387,   392,   398,   402,   403,   404,   410,   415,   421,
   425,   426,   427,   437,   444,   450,   453,   456,   459,   462,
   465,   466,   471,   474,   477,   480,   483,   484,   489,   494,
   502,   505,   507,   509
};

static const short yyrhs[] = {    55,
    54,     0,   113,    54,     0,     0,     3,    25,    57,    56,
     4,     0,     3,    25,    57,     1,     4,     0,    62,    56,
     0,    69,    56,     0,    72,    56,     0,    64,    56,     0,
    75,    56,     0,     0,     3,    26,    58,     4,     0,     9,
     0,    10,     0,    11,     0,    12,     0,    13,     0,    14,
     0,    15,     0,    16,     0,    17,     0,     9,     0,    14,
     0,     9,     0,    16,     0,     9,     0,    15,     0,     3,
    21,    63,     4,     0,     3,    21,     1,     4,     0,    63,
    24,     0,    63,    18,     0,     0,     3,    23,    65,     4,
     0,     3,    23,     1,     4,     0,    65,    66,     0,    66,
     0,     3,     9,    67,     4,     0,     3,     1,     4,     0,
    67,    68,     8,    11,     0,    67,    68,     0,     0,    68,
    19,     0,     0,     3,    24,    70,     4,     0,    70,    71,
     8,    11,     0,    70,    71,     8,     9,     0,    70,    71,
     0,     0,    71,    11,     0,    71,     9,     0,     0,     3,
    22,    73,     4,     0,     3,    40,    73,     4,     0,    73,
    74,     8,    11,     0,    73,    74,     0,     0,    74,     9,
     0,     9,     0,    76,     0,   101,     0,   104,     0,   107,
     0,   110,     0,     0,     3,    27,    59,    77,    78,     4,
     0,     3,    27,     1,     4,     0,    78,    28,     3,    67,
     4,     0,    78,    29,    79,     0,    78,    30,    86,     0,
     0,    81,     0,     3,    31,    80,     4,     0,    80,    81,
     0,    81,     0,    82,     0,    83,     0,    84,     0,     3,
    12,    85,     4,     0,     3,     7,    85,     4,     0,     3,
    35,    83,     4,     0,    85,    13,     0,    85,    10,     0,
     0,    88,     0,     3,    31,    87,     4,     0,    87,    88,
     0,    88,     0,    96,     0,    89,     0,    90,     0,     3,
    36,    79,    93,     4,     0,     0,     0,     3,    34,     3,
    91,    67,     4,    92,    86,     4,     0,     3,    31,    94,
     4,     0,    96,     0,    94,    96,     0,    96,     0,    95,
    97,     0,    97,     0,    82,     0,    83,     0,     3,    53,
    80,     4,     0,     3,    32,    80,     4,     0,     3,    37,
    80,     4,     0,     0,     3,    45,    61,   102,   103,     4,
     0,     3,    45,     1,     4,     0,   103,    28,     3,    67,
     4,     0,   103,    48,    79,     0,   103,    49,    93,     0,
     0,     0,     3,    43,    60,   105,   106,     4,     0,     3,
    43,     1,     4,     0,   106,    28,     3,    67,     4,     0,
   106,    46,    79,     0,   106,    44,    95,     0,     0,     0,
     3,    47,   108,   109,     4,     0,     3,    47,     1,     4,
     0,   109,    28,     3,    67,     4,     0,   109,    51,    95,
     0,     0,     0,     3,    50,   111,   112,     4,     0,     3,
    50,     1,     4,     0,   112,    28,     3,    67,     4,     0,
   112,    51,    95,     0,     0,     0,     3,    25,     3,    38,
    58,     4,   114,   115,     4,     0,     3,    25,     3,    38,
     1,     4,     0,   115,     3,    39,    58,     4,     0,   115,
    62,     0,   115,    72,     0,   115,   116,     0,   115,   118,
     0,   115,   119,     0,     0,     3,    41,   117,     4,     0,
   117,    82,     0,   117,    98,     0,   117,    99,     0,   117,
   100,     0,     0,     3,    52,   117,     4,     0,     3,    42,
   121,     4,     0,     3,    42,     3,    31,   120,     4,     4,
     0,   120,   121,     0,   121,     0,    83,     0,    84,     0
};

#endif

#if YY_PDDL_Parser_DEBUG != 0
static const short yyrline[] = { 0,
    70,    72,    73,    76,    78,    84,    86,    87,    88,    89,
    90,    93,    99,   101,   102,   103,   104,   105,   106,   107,
   108,   111,   113,   116,   118,   121,   123,   128,   130,   136,
   138,   139,   144,   146,   152,   154,   157,   166,   172,   179,
   185,   188,   195,   200,   204,   208,   216,   219,   222,   226,
   230,   235,   237,   240,   244,   247,   250,   255,   263,   265,
   266,   267,   268,   273,   278,   282,   288,   293,   294,   295,
   298,   300,   303,   308,   315,   319,   321,   324,   336,   348,
   355,   363,   367,   370,   372,   375,   380,   387,   389,   390,
   393,   397,   401,   404,   419,   421,   424,   429,   436,   441,
   448,   452,   456,   460,   464,   468,   473,   477,   483,   488,
   489,   490,   493,   498,   502,   508,   513,   514,   515,   518,
   522,   525,   531,   536,   539,   542,   546,   549,   555,   560,
   563,   568,   572,   573,   579,   581,   582,   583,   584,   585,
   586,   589,   593,   599,   604,   609,   614,   617,   621,   623,
   626,   631,   639,   641
};

static const char * const yytname[] = {   "$","error","$illegal.","TK_OPEN",
"TK_CLOSE","TK_OPEN_SQ","TK_CLOSE_SQ","TK_EQ","TK_HYPHEN","TK_NEW_SYMBOL","TK_OBJ_SYMBOL",
"TK_TYPE_SYMBOL","TK_PRED_SYMBOL","TK_VAR_SYMBOL","TK_ACTION_SYMBOL","TK_AXIOM_SYMBOL",
"TK_SENSOR_SYMBOL","TK_MISC_SYMBOL","TK_KEYWORD","TK_NEW_VAR_SYMBOL","TK_INT",
"KW_REQS","KW_CONSTANTS","KW_PREDS","KW_TYPES","KW_DEFINE","KW_DOMAIN","KW_ACTION",
"KW_ARGS","KW_PRE","KW_EFFECT","KW_AND","KW_OR","KW_EXISTS","KW_FORALL","KW_NOT",
"KW_WHEN","KW_ONEOF","KW_PROBLEM","KW_FORDOMAIN","KW_OBJECTS","KW_INIT","KW_GOAL",
"KW_SENSOR","KW_SENSED","KW_AXIOM","KW_COND","KW_OBSERVABLE","KW_BODY","KW_HEAD",
"KW_STICKY","KW_FLUENTS","KW_HIDDEN","KW_INVARIANT","pddl_declarations","pddl_domain",
"domain_elements","domain_name","any_symbol","action_symbol","sensor_symbol",
"axiom_symbol","domain_requires","require_list","domain_predicates","predicate_list",
"predicate_decl","typed_param_list","typed_param_sym_list","domain_types","typed_type_list",
"primitive_type_list","domain_constants","typed_constant_list","ne_constant_sym_list",
"domain_structure","action_declaration","@1","action_elements","condition","condition_list",
"single_condition","literal","positive_literal","negative_literal","atom_argument_list",
"action_effect","action_effect_list","single_action_effect","conditional_effect",
"forall_effect","@2","@3","atomic_effect_kw_list","atomic_effect_list","positive_atomic_effect_list",
"atomic_effect","positive_atomic_effect","invariant","clause","oneof","axiom_declaration",
"@4","axiom_elements","sensor_declaration","@5","sensor_elements","observable_declaration",
"@6","observable_elements","sticky_declaration","@7","sticky_elements","pddl_problem",
"@8","problem_elements","initial_state","init_elements","hidden_state","goal_spec",
"goal_list","single_goal",""
};
#endif

static const short yyr1[] = {     0,
    54,    54,    54,    55,    55,    56,    56,    56,    56,    56,
    56,    57,    58,    58,    58,    58,    58,    58,    58,    58,
    58,    59,    59,    60,    60,    61,    61,    62,    62,    63,
    63,    63,    64,    64,    65,    65,    66,    66,    67,    67,
    67,    68,    68,    69,    70,    70,    70,    70,    71,    71,
    71,    72,    72,    73,    73,    73,    74,    74,    75,    75,
    75,    75,    75,    77,    76,    76,    78,    78,    78,    78,
    79,    79,    80,    80,    81,    82,    82,    83,    83,    84,
    85,    85,    85,    86,    86,    87,    87,    88,    88,    88,
    89,    91,    92,    90,    93,    93,    94,    94,    95,    95,
    96,    97,    98,    99,   100,   102,   101,   101,   103,   103,
   103,   103,   105,   104,   104,   106,   106,   106,   106,   108,
   107,   107,   109,   109,   109,   111,   110,   110,   112,   112,
   112,   114,   113,   113,   115,   115,   115,   115,   115,   115,
   115,   116,   117,   117,   117,   117,   117,   118,   119,   119,
   120,   120,   121,   121
};

static const short yyr2[] = {     0,
     2,     2,     0,     5,     5,     2,     2,     2,     2,     2,
     0,     4,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     4,     4,     2,
     2,     0,     4,     4,     2,     1,     4,     3,     4,     2,
     0,     2,     0,     4,     4,     4,     2,     0,     2,     2,
     0,     4,     4,     4,     2,     0,     2,     1,     1,     1,
     1,     1,     1,     0,     6,     4,     5,     3,     3,     0,
     1,     4,     2,     1,     1,     1,     1,     4,     4,     4,
     2,     2,     0,     1,     4,     2,     1,     1,     1,     1,
     5,     0,     0,     9,     4,     1,     2,     1,     2,     1,
     1,     1,     4,     4,     4,     0,     6,     4,     5,     3,
     3,     0,     0,     6,     4,     5,     3,     3,     0,     0,
     5,     4,     5,     3,     0,     0,     5,     4,     5,     3,
     0,     0,     9,     6,     5,     2,     2,     2,     2,     2,
     0,     4,     2,     2,     2,     2,     0,     4,     4,     7,
     2,     1,     1,     1
};

static const short yydefact[] = {     3,
     0,     3,     3,     0,     1,     2,     0,     0,     0,     0,
     0,     0,     0,    11,    11,    11,    11,    11,    59,    60,
    61,    62,    63,    13,    14,    15,    16,    17,    18,    19,
    20,    21,     0,     0,     0,     5,     0,    56,     0,    48,
     0,    56,     0,     0,     0,     0,     4,     6,     9,     7,
     8,    10,    12,   134,   132,     0,     0,     0,     0,     0,
     0,    36,    51,     0,    22,    23,    64,     0,     0,    24,
    25,   113,     0,    26,    27,   106,     0,   125,     0,   131,
   141,    29,    28,    31,    30,    52,    58,    55,    34,     0,
    41,    33,    35,    44,    47,    66,    70,    53,   115,   119,
   108,   112,   122,     0,   128,     0,     0,     0,    57,    38,
    43,     0,    50,    49,     0,     0,     0,   121,     0,     0,
   127,     0,     0,     0,   133,   136,   137,   138,   139,   140,
    54,    37,    40,    46,    45,    65,     0,     0,     0,   114,
     0,     0,     0,   107,     0,     0,     0,    41,     0,   102,
   124,   100,    41,   130,     0,   147,     0,   147,     0,    42,
    41,     0,    68,    71,    75,    76,    77,     0,   101,    69,
    84,    89,    90,    88,    41,   118,   117,    41,   110,     0,
   111,    96,    43,    83,    83,    99,    43,     0,     0,     0,
   153,   154,     0,     0,    39,    43,     0,     0,     0,     0,
     0,    43,    43,     0,   123,     0,     0,   129,   135,     0,
   142,   143,   144,   145,   146,     0,   149,   148,    67,     0,
     0,    74,     0,     0,     0,    87,    92,     0,   116,   109,
     0,    98,    79,    82,    81,    78,     0,     0,     0,     0,
   152,    72,    73,    80,    85,    86,    41,     0,    95,    97,
     0,     0,     0,     0,   151,    43,    91,   104,   105,   103,
   150,    93,     0,     0,    94,     0,     0,     0
};

static const short yydefgoto[] = {     5,
     2,    13,     8,    33,    67,    72,    76,    14,    57,    15,
    61,    62,   111,   133,    16,    63,    95,    17,    58,    88,
    18,    19,    97,   115,   163,   221,   164,   165,   166,   167,
   206,   170,   225,   171,   172,   173,   247,   263,   181,   231,
   151,   174,   152,   213,   214,   215,    20,   102,   117,    21,
   100,   116,    22,    78,   104,    23,    80,   106,     3,    81,
   107,   128,   189,   129,   130,   240,   193
};

static const short yypact[] = {    57,
    42,    57,    57,    78,-32768,-32768,    19,   169,   196,   170,
    73,   106,    90,   115,   115,   115,   115,   115,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,   117,   134,   144,-32768,    87,-32768,   221,-32768,
   189,-32768,   153,   187,    13,    21,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,   154,    99,    38,   185,    14,
    97,-32768,   219,   237,-32768,-32768,-32768,    39,   238,-32768,
-32768,-32768,   239,-32768,-32768,-32768,   240,-32768,   241,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,   101,-32768,   242,
-32768,-32768,-32768,-32768,   183,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,    12,-32768,    22,   138,   182,-32768,-32768,
   243,   188,-32768,-32768,   136,     0,    27,-32768,   197,   245,
-32768,   246,   245,    74,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,    89,-32768,-32768,-32768,   247,   248,   249,-32768,
   250,   245,   248,-32768,   251,   248,   252,-32768,   145,-32768,
   245,-32768,-32768,   245,   196,-32768,   253,-32768,   254,-32768,
-32768,    47,-32768,-32768,-32768,-32768,-32768,   100,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,   245,-32768,-32768,-32768,   112,
-32768,-32768,   255,-32768,-32768,-32768,   256,   257,   172,   132,
-32768,-32768,   258,   222,-32768,   259,   261,   245,   263,   264,
   248,   265,   266,   261,-32768,   164,   191,-32768,-32768,    67,
-32768,-32768,-32768,-32768,-32768,   261,-32768,-32768,-32768,   143,
   224,-32768,   267,   125,   226,-32768,-32768,   252,-32768,-32768,
   228,-32768,-32768,-32768,-32768,-32768,   261,   261,   261,   230,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,   268,-32768,-32768,
   232,   234,   236,   269,-32768,   270,-32768,-32768,-32768,-32768,
-32768,-32768,   249,   271,-32768,   276,   277,-32768
};

static const short yypgoto[] = {    18,
-32768,   200,-32768,   -10,-32768,-32768,-32768,   150,-32768,-32768,
-32768,   207,  -141,-32768,-32768,-32768,-32768,   151,   244,-32768,
-32768,-32768,-32768,-32768,  -133,   -18,  -168,  -138,  -118,  -154,
    93,    16,-32768,  -193,-32768,-32768,-32768,-32768,    52,-32768,
  -104,  -139,  -124,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,   123,-32768,-32768,-32768,  -205
};


#define	YYLAST		286


static const short yytable[] = {    35,
   169,   150,   192,   140,   150,   226,   183,   182,   169,   177,
   241,   187,   179,    77,    90,   118,  -120,   266,   154,   196,
     6,    79,    91,   150,  -126,   121,   186,   141,   222,   186,
   144,   246,   150,   202,   255,   150,   203,   176,   191,   119,
  -120,    86,    98,   142,     9,   143,    87,    87,  -126,   122,
   212,   186,   243,   184,   145,   212,    10,   150,   185,     1,
   169,   192,   120,  -120,   232,   169,     4,   228,   222,   222,
   222,  -126,   123,   184,   146,   147,    36,   197,   185,   223,
     7,   198,   243,   243,   243,   192,   169,    56,   182,   169,
   -32,   250,   169,    47,    37,    38,   159,   191,   237,    60,
    92,   198,    83,   238,   -32,   256,   184,   160,   108,   109,
   -32,   185,   155,    42,   156,   157,    84,    12,   184,   239,
    53,   191,    85,   185,   169,   158,    37,    38,    39,    40,
   199,   184,    41,   200,   198,   201,   185,    54,   184,   136,
   124,   125,   204,   185,   188,    42,   198,    55,    43,   184,
    44,   184,    45,    69,   185,    46,   185,    82,   200,   198,
   201,    70,   216,   137,   138,   139,   198,   233,    71,    11,
    34,    12,   -11,   234,   210,   211,   235,   198,    24,    25,
    26,    27,    28,    29,    30,    31,    32,    73,    89,    64,
   112,   113,   131,   114,   236,    74,   134,    65,   135,   148,
   234,    75,    66,   235,    24,    25,    26,    27,    28,    29,
    30,    31,    32,    48,    49,    50,    51,    52,   251,   252,
   253,    59,    94,    60,   210,   218,   220,   242,   224,   245,
   220,   249,   220,   254,   220,   258,   220,   259,   220,   260,
    96,    99,   101,   103,   105,   110,   132,   149,   153,   161,
   162,   168,   175,   178,   180,   190,   126,   127,   205,   208,
   209,   217,   219,   220,   195,   224,   227,    93,   229,   230,
   244,   257,   261,   262,   265,   267,   268,   207,   264,   248,
   194,     0,     0,     0,     0,    68
};

static const short yycheck[] = {    10,
   139,   120,   157,     4,   123,   199,   148,   147,   147,   143,
   216,   153,   146,     1,     1,     4,     4,     0,   123,   161,
     3,     1,     9,   142,     4,     4,   151,    28,   197,   154,
     4,   225,   151,   175,   240,   154,   178,   142,   157,    28,
    28,     4,     4,    44,    26,    46,     9,     9,    28,    28,
   189,   176,   221,     7,    28,   194,    38,   176,    12,     3,
   199,   216,    51,    51,   204,   204,    25,   201,   237,   238,
   239,    51,    51,     7,    48,    49,     4,    31,    12,   198,
     3,    35,   251,   252,   253,   240,   225,     1,   228,   228,
     4,   231,   231,     4,    21,    22,     8,   216,    32,     3,
     4,    35,     4,    37,    18,   247,     7,    19,     8,     9,
    24,    12,    39,    40,    41,    42,    18,     3,     7,    53,
     4,   240,    24,    12,   263,    52,    21,    22,    23,    24,
    31,     7,    27,    34,    35,    36,    12,     4,     7,     4,
     3,     4,    31,    12,   155,    40,    35,     4,    43,     7,
    45,     7,    47,     1,    12,    50,    12,     4,    34,    35,
    36,     9,    31,    28,    29,    30,    35,     4,    16,     1,
     1,     3,     4,    10,     3,     4,    13,    35,     9,    10,
    11,    12,    13,    14,    15,    16,    17,     1,     4,     1,
     8,     9,    11,    11,     4,     9,     9,     9,    11,     3,
    10,    15,    14,    13,     9,    10,    11,    12,    13,    14,
    15,    16,    17,    14,    15,    16,    17,    18,   237,   238,
   239,     1,     4,     3,     3,     4,     3,     4,     3,     4,
     3,     4,     3,     4,     3,     4,     3,     4,     3,     4,
     4,     4,     4,     4,     4,     4,     4,     3,     3,     3,
     3,     3,     3,     3,     3,     3,   107,   107,     4,     4,
     4,     4,     4,     3,    11,     3,     3,    61,     4,     4,
     4,     4,     4,     4,     4,     0,     0,   185,   263,   228,
   158,    -1,    -1,    -1,    -1,    42
};

#line 325 "/opt/sfw/lib/bison.cc"
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


/* #line 811 "/opt/sfw/lib/bison.cc" */
#line 1465 "grammar.cc"

  switch (yyn) {

case 5:
#line 78 "ppddl.y"
{
          log_error("syntax error in domain");
          yyerrok;
      ;
    break;}
case 12:
#line 94 "ppddl.y"
{ domain_name = yyvsp[-1].sym->text; ;
    break;}
case 13:
#line 100 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 14:
#line 101 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 15:
#line 102 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 16:
#line 103 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 17:
#line 104 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 18:
#line 105 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 19:
#line 106 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 20:
#line 107 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 21:
#line 108 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 22:
#line 112 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 23:
#line 113 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 24:
#line 117 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 25:
#line 118 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 26:
#line 122 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 27:
#line 123 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 29:
#line 130 "ppddl.y"
{
          log_error("syntax error in requirements declaration.");
          yyerrok; 
      ;
    break;}
case 34:
#line 146 "ppddl.y"
{
          log_error("syntax error in (:predicates ...)");
          yyerrok;
      ;
    break;}
case 37:
#line 158 "ppddl.y"
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
#line 166 "ppddl.y"
{
          log_error("syntax error in predicate declaration");
          yyerrok;
      ;
    break;}
case 39:
#line 173 "ppddl.y"
{
          set_variable_type(*yyvsp[-2].vparam, yyvsp[-2].vparam->size(), (TypeSymbol*)yyvsp[0].sym->val);
          yyvsp[-3].vparam->insert(yyvsp[-3].vparam->end(), yyvsp[-2].vparam->begin(), yyvsp[-2].vparam->end());
          delete yyvsp[-2].vparam;
          yyval.vparam = yyvsp[-3].vparam;
      ;
    break;}
case 40:
#line 179 "ppddl.y"
{
          set_variable_type(*yyvsp[-1].vparam, yyvsp[-1].vparam->size(), dom_top_type);
          yyvsp[-1].vparam->insert(yyvsp[-1].vparam->end(), yyvsp[0].vparam->begin(), yyvsp[0].vparam->end());
          delete yyvsp[0].vparam;
          yyval.vparam = yyvsp[-1].vparam;
      ;
    break;}
case 41:
#line 185 "ppddl.y"
{ yyval.vparam = new variable_vec; ;
    break;}
case 42:
#line 189 "ppddl.y"
{
          VariableSymbol *var = new VariableSymbol(yyvsp[0].sym->text);
          yyvsp[0].sym->val = var;
          yyvsp[-1].vparam->push_back(var);
          yyval.vparam = yyvsp[-1].vparam;
      ;
    break;}
case 43:
#line 195 "ppddl.y"
{ yyval.vparam = new variable_vec; ;
    break;}
case 45:
#line 205 "ppddl.y"
{
          set_type_type(dom_types, dom_types.size(), (TypeSymbol*)yyvsp[0].sym->val);
      ;
    break;}
case 46:
#line 208 "ppddl.y"
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
#line 216 "ppddl.y"
{
          set_type_type(dom_types, dom_types.size(), dom_top_type);
      ;
    break;}
case 49:
#line 223 "ppddl.y"
{
          /* the type is already (implicitly) declared */
      ;
    break;}
case 50:
#line 226 "ppddl.y"
{
          yyvsp[0].sym->val = new TypeSymbol(yyvsp[0].sym->text);
          dom_types.push_back((TypeSymbol*)yyvsp[0].sym->val);
      ;
    break;}
case 54:
#line 241 "ppddl.y"
{
          set_constant_type(dom_constants, dom_constants.size(), (TypeSymbol*)yyvsp[0].sym->val);
      ;
    break;}
case 55:
#line 244 "ppddl.y"
{
          set_constant_type(dom_constants, dom_constants.size(), dom_top_type);
      ;
    break;}
case 57:
#line 251 "ppddl.y"
{
          yyvsp[0].sym->val = new Symbol(yyvsp[0].sym->text);
          dom_constants.push_back((Symbol*)yyvsp[0].sym->val);
      ;
    break;}
case 58:
#line 255 "ppddl.y"
{
          yyvsp[0].sym->val = new Symbol(yyvsp[0].sym->text);
          dom_constants.push_back((Symbol*)yyvsp[0].sym->val);
      ;
    break;}
case 64:
#line 274 "ppddl.y"
{
          Action *na = new Action(yyvsp[0].sym->text);
          dom_actions.push_back(na);
      ;
    break;}
case 65:
#line 278 "ppddl.y"
{
          clear_param(dom_actions.back()->param);
          yyvsp[-3].sym->val = dom_actions.back();
      ;
    break;}
case 66:
#line 282 "ppddl.y"
{
          log_error("syntax error in action declaration");
          yyerrok; 
      ;
    break;}
case 67:
#line 289 "ppddl.y"
{
          dom_actions.back()->param = *yyvsp[-1].vparam;
          delete yyvsp[-1].vparam;
      ;
    break;}
case 68:
#line 293 "ppddl.y"
{ dom_actions.back()->precondition = yyvsp[0].condition; ;
    break;}
case 69:
#line 294 "ppddl.y"
{ dom_actions.back()->effect = yyvsp[0].effect; ;
    break;}
case 72:
#line 300 "ppddl.y"
{ yyval.condition = yyvsp[-1].condition; ;
    break;}
case 73:
#line 304 "ppddl.y"
{
          const_cast<And*>(static_cast<const And*>(yyvsp[-1].condition))->push_back(yyvsp[0].condition);
          yyval.condition = yyvsp[-1].condition;
      ;
    break;}
case 74:
#line 308 "ppddl.y"
{
          And *cond = new And();
          cond->push_back(yyvsp[0].condition);
          yyval.condition = cond;
      ;
    break;}
case 75:
#line 316 "ppddl.y"
{ yyval.condition = new Literal(*yyvsp[0].atom); ;
    break;}
case 78:
#line 325 "ppddl.y"
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
case 79:
#line 336 "ppddl.y"
{
          yyval.atom = new Atom(dom_eq_pred);
          yyval.atom->param = *yyvsp[-1].param;
          delete yyvsp[-1].param;
          if( yyval.atom->param.size() != 2 ) {
              log_error("wrong number of arguments for equality");
          }
          assert(0); // TODO: remove this assertion which is here
                     // because (probably) the code for '=' is broken...
    ;
    break;}
case 80:
#line 349 "ppddl.y"
{
          static_cast<const Literal*>(yyvsp[-1].atom)->neg = true;
          yyval.atom = yyvsp[-1].atom;
      ;
    break;}
case 81:
#line 356 "ppddl.y"
{
          if( yyvsp[0].sym->val == 0 )
              log_error("undeclared variable in atom args list");
          else
              yyvsp[-1].param->push_back((VariableSymbol*)yyvsp[0].sym->val);
          yyval.param = yyvsp[-1].param;
      ;
    break;}
case 82:
#line 363 "ppddl.y"
{
          yyvsp[-1].param->push_back((Symbol*)yyvsp[0].sym->val);
          yyval.param = yyvsp[-1].param;
      ;
    break;}
case 83:
#line 367 "ppddl.y"
{ yyval.param = new PDDL_Base::symbol_vec; ;
    break;}
case 85:
#line 372 "ppddl.y"
{ yyval.effect = yyvsp[-1].effect; ;
    break;}
case 86:
#line 376 "ppddl.y"
{
          const_cast<AndEffect*>(static_cast<const AndEffect*>(yyvsp[-1].effect))->push_back(yyvsp[0].effect);
          yyval.effect = yyvsp[-1].effect;
      ;
    break;}
case 87:
#line 380 "ppddl.y"
{
          AndEffect *eff = new AndEffect;
          eff->push_back(yyvsp[0].effect);
          yyval.effect = eff;
      ;
    break;}
case 91:
#line 394 "ppddl.y"
{ yyval.effect = new ConditionalEffect(yyvsp[-2].condition, yyvsp[-1].effect); ;
    break;}
case 92:
#line 398 "ppddl.y"
{
          forall_effects.push_back(new ForallEffect);
      ;
    break;}
case 93:
#line 401 "ppddl.y"
{
          forall_effects.back()->param = *yyvsp[-1].vparam;
      ;
    break;}
case 94:
#line 404 "ppddl.y"
{
          forall_effects.back()->effect = yyvsp[-1].effect;
          clear_param(forall_effects.back()->param);
          yyval.effect = forall_effects.back();
          forall_effects.pop_back();
      ;
    break;}
case 95:
#line 420 "ppddl.y"
{ yyval.effect = yyvsp[-1].effect; ;
    break;}
case 97:
#line 425 "ppddl.y"
{
          const_cast<AndEffect*>(static_cast<const AndEffect*>(yyvsp[-1].effect))->push_back(yyvsp[0].effect);
          yyval.effect = yyvsp[-1].effect;
      ;
    break;}
case 98:
#line 429 "ppddl.y"
{
          AndEffect *eff = new AndEffect;
          eff->push_back(yyvsp[0].effect);
          yyval.effect = eff;
      ;
    break;}
case 99:
#line 437 "ppddl.y"
{
          const_cast<AndEffect*>(static_cast<const AndEffect*>(yyvsp[-1].effect))->push_back(yyvsp[0].effect);
          yyval.effect = yyvsp[-1].effect;
      ;
    break;}
case 100:
#line 441 "ppddl.y"
{
          AndEffect *eff = new AndEffect;
          eff->push_back(yyvsp[0].effect);
          yyval.effect = eff;
      ;
    break;}
case 101:
#line 449 "ppddl.y"
{ yyval.effect = new AtomicEffect(*yyvsp[0].atom); ;
    break;}
case 102:
#line 453 "ppddl.y"
{ yyval.effect = new AtomicEffect(*yyvsp[0].atom); ;
    break;}
case 103:
#line 457 "ppddl.y"
{ yyval.condition = yyvsp[-1].condition; ;
    break;}
case 104:
#line 461 "ppddl.y"
{ yyval.condition = yyvsp[-1].condition; ;
    break;}
case 105:
#line 465 "ppddl.y"
{ yyval.condition = yyvsp[-1].condition; ;
    break;}
case 106:
#line 469 "ppddl.y"
{
          Axiom *nr = new Axiom(yyvsp[0].sym->text);
          dom_axioms.push_back(nr);
      ;
    break;}
case 107:
#line 473 "ppddl.y"
{
          clear_param(dom_axioms.back()->param);
          yyvsp[-3].sym->val = dom_axioms.back();
      ;
    break;}
case 108:
#line 477 "ppddl.y"
{
          log_error("syntax error in axiom declaration");
          yyerrok; 
      ;
    break;}
case 109:
#line 484 "ppddl.y"
{
          dom_axioms.back()->param = *yyvsp[-1].vparam;
          delete yyvsp[-1].vparam;
      ;
    break;}
case 110:
#line 488 "ppddl.y"
{ dom_axioms.back()->body = yyvsp[0].condition; ;
    break;}
case 111:
#line 489 "ppddl.y"
{ dom_axioms.back()->head = yyvsp[0].effect; ;
    break;}
case 113:
#line 494 "ppddl.y"
{
          Sensor *nr = new Sensor(yyvsp[0].sym->text);
          dom_sensors.push_back(nr);
      ;
    break;}
case 114:
#line 498 "ppddl.y"
{
          clear_param(dom_sensors.back()->param);
          yyvsp[-3].sym->val = dom_sensors.back();
      ;
    break;}
case 115:
#line 502 "ppddl.y"
{
          log_error("syntax error in sensor declaration");
          yyerrok; 
      ;
    break;}
case 116:
#line 509 "ppddl.y"
{
          dom_sensors.back()->param = *yyvsp[-1].vparam;
          delete yyvsp[-1].vparam;
      ;
    break;}
case 117:
#line 513 "ppddl.y"
{ dom_sensors.back()->condition = yyvsp[0].condition; ;
    break;}
case 118:
#line 514 "ppddl.y"
{ dom_sensors.back()->sensed = yyvsp[0].effect; ;
    break;}
case 120:
#line 519 "ppddl.y"
{
          Observable *obs = new Observable;
          dom_observables.push_back(obs);
      ;
    break;}
case 121:
#line 522 "ppddl.y"
{
          clear_param(dom_observables.back()->param);
      ;
    break;}
case 122:
#line 525 "ppddl.y"
{
          log_error("syntax error in observable declaration");
          yyerrok; 
      ;
    break;}
case 123:
#line 532 "ppddl.y"
{
          dom_observables.back()->param = *yyvsp[-1].vparam;
          delete yyvsp[-1].vparam;
      ;
    break;}
case 124:
#line 536 "ppddl.y"
{
          dom_observables.back()->observables = yyvsp[0].effect;
      ;
    break;}
case 126:
#line 543 "ppddl.y"
{
          Sticky *stk = new Sticky;
          dom_stickies.push_back(stk);
      ;
    break;}
case 127:
#line 546 "ppddl.y"
{
          clear_param(dom_stickies.back()->param);
      ;
    break;}
case 128:
#line 549 "ppddl.y"
{
          log_error("syntax error in sticky declaration");
          yyerrok; 
      ;
    break;}
case 129:
#line 556 "ppddl.y"
{
          dom_stickies.back()->param = *yyvsp[-1].vparam;
          delete yyvsp[-1].vparam;
      ;
    break;}
case 130:
#line 560 "ppddl.y"
{
          dom_stickies.back()->stickies = yyvsp[0].effect;
      ;
    break;}
case 132:
#line 569 "ppddl.y"
{
          problem_name = yyvsp[-1].sym->text;
      ;
    break;}
case 134:
#line 573 "ppddl.y"
{
          log_error("syntax error in problem definition.");
          yyerrok;
      ;
    break;}
case 142:
#line 590 "ppddl.y"
{ dom_init = *yyvsp[-1].ilist; delete yyvsp[-1].ilist; ;
    break;}
case 143:
#line 594 "ppddl.y"
{
          init_element_vec *ilist = const_cast<init_element_vec*>(yyvsp[-1].ilist);
          ilist->push_back(new InitLiteral(*yyvsp[0].atom));
          yyval.ilist = ilist;
      ;
    break;}
case 144:
#line 599 "ppddl.y"
{
          init_element_vec *ilist = const_cast<init_element_vec*>(yyvsp[-1].ilist);
          ilist->push_back(new InitInvariant(*static_cast<const And*>(yyvsp[0].condition)));
          yyval.ilist = ilist;
      ;
    break;}
case 145:
#line 604 "ppddl.y"
{
          init_element_vec *ilist = const_cast<init_element_vec*>(yyvsp[-1].ilist);
          ilist->push_back(new InitClause(*static_cast<const And*>(yyvsp[0].condition)));
          yyval.ilist = ilist;
      ;
    break;}
case 146:
#line 609 "ppddl.y"
{
          init_element_vec *ilist = const_cast<init_element_vec*>(yyvsp[-1].ilist);
          ilist->push_back(new InitOneof(*static_cast<const And*>(yyvsp[0].condition)));
          yyval.ilist = ilist;
      ;
    break;}
case 147:
#line 614 "ppddl.y"
{ yyval.ilist = new init_element_vec; ;
    break;}
case 148:
#line 618 "ppddl.y"
{ dom_hidden = *yyvsp[-1].ilist; delete yyvsp[-1].ilist; ;
    break;}
case 149:
#line 622 "ppddl.y"
{ dom_goal = yyvsp[-1].condition; ;
    break;}
case 150:
#line 623 "ppddl.y"
{ dom_goal = yyvsp[-2].condition; ;
    break;}
case 151:
#line 627 "ppddl.y"
{
          const_cast<And*>(static_cast<const And*>(yyvsp[-1].condition))->push_back(yyvsp[0].condition);
          yyval.condition = yyvsp[-1].condition;
      ;
    break;}
case 152:
#line 631 "ppddl.y"
{
          And *cond = new And;
          cond->push_back(yyvsp[0].condition);
          yyval.condition = cond;
      ;
    break;}
case 153:
#line 640 "ppddl.y"
{ yyval.condition = new Literal(*yyvsp[0].atom); ;
    break;}
case 154:
#line 641 "ppddl.y"
{ yyval.condition = new Literal(*yyvsp[0].atom); ;
    break;}
}

#line 811 "/opt/sfw/lib/bison.cc"
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
	       x < (int)(sizeof(yytname) / sizeof(char *)); x++)
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
		       x < (int)(sizeof(yytname) / sizeof(char *)); x++)
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

/* #line 1010 "/opt/sfw/lib/bison.cc" */
#line 2311 "grammar.cc"
#line 644 "ppddl.y"


