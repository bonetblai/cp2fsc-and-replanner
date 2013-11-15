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
#define	KW_SENSING_MODEL	317


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
#line 425 "grammar.cc"
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
static const int KW_SENSING_MODEL;


#line 280 "/home/bonet/space/software/bison++-1.21-8/lib/bison.cc"
 /* decl const */
#else
enum YY_PDDL_Parser_ENUM_TOKEN { YY_PDDL_Parser_NULL_TOKEN=0

/* #line 283 "/home/bonet/space/software/bison++-1.21-8/lib/bison.cc" */
#line 494 "grammar.cc"
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
	,KW_SENSING_MODEL=317


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
#line 591 "grammar.cc"
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
const int YY_PDDL_Parser_CLASS::KW_SENSING_MODEL=317;


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
#line 668 "grammar.cc"


#define	YYFINAL		307
#define	YYFLAG		-32768
#define	YYNTBASE	63

#define YYTRANSLATE(x) ((unsigned)(x) <= 317 ? yytranslate[x] : 143)

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
    56,    57,    58,    59,    60,    61,    62
};

#if YY_PDDL_Parser_DEBUG != 0
static const short yyprhs[] = {     0,
     0,     3,     6,     7,    13,    19,    22,    25,    28,    31,
    34,    35,    40,    42,    44,    46,    48,    50,    52,    54,
    56,    58,    60,    62,    64,    66,    68,    70,    72,    74,
    79,    84,    87,    90,    91,    96,   101,   104,   106,   111,
   115,   120,   123,   124,   127,   128,   133,   138,   143,   146,
   147,   150,   153,   154,   159,   164,   169,   172,   173,   176,
   178,   180,   182,   184,   186,   188,   190,   191,   198,   203,
   209,   213,   217,   221,   225,   226,   228,   233,   236,   238,
   240,   242,   244,   249,   254,   259,   262,   265,   266,   268,
   273,   276,   278,   280,   282,   284,   290,   291,   292,   302,
   307,   309,   312,   314,   317,   319,   321,   323,   325,   326,
   327,   334,   339,   345,   349,   353,   354,   355,   362,   367,
   373,   377,   381,   382,   383,   389,   394,   395,   398,   400,
   402,   404,   405,   411,   416,   418,   420,   421,   429,   434,
   436,   437,   438,   445,   450,   451,   461,   468,   474,   477,
   480,   483,   486,   489,   490,   494,   499,   507,   510,   512,
   514,   516,   518,   520,   525,   530,   535,   540,   542,   544,
   546,   551,   556,   561,   566,   574,   577,   579,   581
};

static const short yyrhs[] = {    64,
    63,     0,   127,    63,     0,     0,     3,    27,    66,    65,
     4,     0,     3,    27,    66,     1,     4,     0,    72,    65,
     0,    79,    65,     0,    82,    65,     0,    74,    65,     0,
    85,    65,     0,     0,     3,    28,    67,     4,     0,     9,
     0,    10,     0,    11,     0,    12,     0,    13,     0,    14,
     0,    15,     0,    16,     0,    17,     0,     9,     0,    20,
     0,     9,     0,    14,     0,     9,     0,    16,     0,     9,
     0,    15,     0,     3,    22,    73,     4,     0,     3,    22,
     1,     4,     0,    73,    23,     0,    73,    18,     0,     0,
     3,    25,    75,     4,     0,     3,    25,     1,     4,     0,
    75,    76,     0,    76,     0,     3,     9,    77,     4,     0,
     3,     1,     4,     0,    77,    78,     8,    11,     0,    77,
    78,     0,     0,    78,    19,     0,     0,     3,    26,    80,
     4,     0,    80,    81,     8,    11,     0,    80,    81,     8,
     9,     0,    80,    81,     0,     0,    81,    11,     0,    81,
     9,     0,     0,     3,    24,    83,     4,     0,     3,    42,
    83,     4,     0,    83,    84,     8,    11,     0,    83,    84,
     0,     0,    84,     9,     0,     9,     0,    86,     0,   109,
     0,   112,     0,   115,     0,   119,     0,   121,     0,     0,
     3,    29,    69,    87,    88,     4,     0,     3,    29,     1,
     4,     0,    88,    30,     3,    77,     4,     0,    88,    31,
    89,     0,    88,    32,    96,     0,    88,    47,   105,     0,
    88,    62,   108,     0,     0,    91,     0,     3,    33,    90,
     4,     0,    90,    91,     0,    91,     0,    92,     0,    93,
     0,    94,     0,     3,    12,    95,     4,     0,     3,     7,
    95,     4,     0,     3,    37,    93,     4,     0,    95,    13,
     0,    95,    10,     0,     0,    98,     0,     3,    33,    97,
     4,     0,    97,    98,     0,    98,     0,   106,     0,    99,
     0,   100,     0,     3,    38,    89,   103,     4,     0,     0,
     0,     3,    36,     3,   101,    77,     4,   102,    96,     4,
     0,     3,    33,   104,     4,     0,   106,     0,   104,   106,
     0,   106,     0,   105,   107,     0,   107,     0,    92,     0,
    93,     0,    96,     0,     0,     0,     3,    48,    71,   110,
   111,     4,     0,     3,    48,     1,     4,     0,   111,    30,
     3,    77,     4,     0,   111,    51,    89,     0,   111,    52,
   103,     0,     0,     0,     3,    45,    70,   113,   114,     4,
     0,     3,    45,     1,     4,     0,   114,    30,     3,    77,
     4,     0,   114,    49,    89,     0,   114,    46,   105,     0,
     0,     0,     3,    50,   116,   117,     4,     0,     3,    50,
     1,     4,     0,     0,   117,   118,     0,   118,     0,   107,
     0,   100,     0,     0,     3,    53,   120,   117,     4,     0,
     3,    53,     1,     4,     0,   122,     0,   125,     0,     0,
     3,    60,    68,   123,   117,   124,     4,     0,     3,    60,
     1,     4,     0,    50,     0,     0,     0,     3,    61,    68,
   126,   117,     4,     0,     3,    61,     1,     4,     0,     0,
     3,    27,     3,    40,    67,     4,   128,   129,     4,     0,
     3,    27,     3,    40,     1,     4,     0,   129,     3,    41,
    67,     4,     0,   129,    72,     0,   129,    82,     0,   129,
   130,     0,   129,   139,     0,   129,   140,     0,     0,     3,
    43,     4,     0,     3,    43,   131,     4,     0,     3,    43,
     3,    33,   131,     4,     4,     0,   131,   132,     0,   132,
     0,    92,     0,   136,     0,   137,     0,   138,     0,     3,
    56,    90,     4,     0,     3,    57,    90,     4,     0,     3,
    58,    90,     4,     0,     3,    59,    90,     4,     0,   133,
     0,   134,     0,   135,     0,     3,    34,    90,     4,     0,
     3,    39,    90,     4,     0,     3,    55,   131,     4,     0,
     3,    44,   142,     4,     0,     3,    44,     3,    33,   141,
     4,     4,     0,   141,   142,     0,   142,     0,    93,     0,
    94,     0
};

#endif

#if YY_PDDL_Parser_DEBUG != 0
static const short yyrline[] = { 0,
    88,    90,    91,    94,    96,   102,   104,   105,   106,   107,
   108,   111,   117,   119,   120,   121,   122,   123,   124,   125,
   126,   129,   131,   134,   136,   139,   141,   144,   146,   151,
   153,   159,   161,   162,   167,   169,   175,   177,   180,   189,
   195,   202,   208,   211,   218,   223,   227,   231,   239,   242,
   245,   249,   253,   258,   260,   263,   267,   270,   273,   278,
   286,   288,   294,   300,   306,   312,   322,   327,   331,   337,
   342,   343,   344,   348,   352,   355,   357,   360,   365,   372,
   383,   385,   388,   401,   412,   419,   427,   431,   434,   436,
   439,   444,   451,   453,   454,   457,   461,   465,   469,   477,
   479,   482,   487,   494,   499,   506,   510,   514,   516,   519,
   524,   528,   534,   539,   540,   541,   544,   549,   553,   559,
   564,   565,   566,   569,   574,   575,   581,   582,   585,   590,
   592,   595,   600,   601,   607,   609,   612,   618,   619,   625,
   629,   632,   638,   639,   648,   652,   653,   659,   661,   662,
   663,   664,   665,   666,   669,   671,   672,   675,   681,   688,
   690,   701,   712,   725,   731,   738,   746,   754,   756,   757,
   760,   768,   776,   788,   790,   793,   798,   806,   808
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
"KW_SENSING_MODEL","pddl_decls","pddl_domain","domain_elements","domain_name",
"any_symbol","variable_symbol","action_symbol","sensor_symbol","axiom_symbol",
"domain_requires","require_list","domain_predicates","predicate_list","predicate_decl",
"typed_param_list","typed_param_sym_list","domain_types","typed_type_list","primitive_type_list",
"domain_constants","typed_constant_list","ne_constant_sym_list","domain_structure",
"action_decl","@1","action_elements","condition","condition_list","single_condition",
"literal","positive_literal","negative_literal","argument_list","action_effect",
"action_effect_list","single_action_effect","conditional_effect","forall_effect",
"@2","@3","atomic_effect_kw_list","atomic_effect_list","positive_atomic_effect_list",
"atomic_effect","positive_atomic_effect","sensing_model","axiom_decl","@4","axiom_elements",
"sensor_decl","@5","sensor_elements","observable_decl","@6","fluent_list_decl",
"fluent_decl","sticky_decl","@7","multivalued_variable_decl","state_variable_decl",
"@8","rest_state_variable","observable_variable_decl","@9","pddl_problem","@10",
"problem_elements","initial_state","init_elements","single_init_element","at_least_one_invariant",
"at_most_one_invariant","exactly_one_invariant","invariant","clause","oneof",
"hidden_state","goal_spec","goal_list","single_goal",""
};
#endif

static const short yyr1[] = {     0,
    63,    63,    63,    64,    64,    65,    65,    65,    65,    65,
    65,    66,    67,    67,    67,    67,    67,    67,    67,    67,
    67,    68,    68,    69,    69,    70,    70,    71,    71,    72,
    72,    73,    73,    73,    74,    74,    75,    75,    76,    76,
    77,    77,    77,    78,    78,    79,    80,    80,    80,    80,
    81,    81,    81,    82,    82,    83,    83,    83,    84,    84,
    85,    85,    85,    85,    85,    85,    87,    86,    86,    88,
    88,    88,    88,    88,    88,    89,    89,    90,    90,    91,
    92,    92,    93,    93,    94,    95,    95,    95,    96,    96,
    97,    97,    98,    98,    98,    99,   101,   102,   100,   103,
   103,   104,   104,   105,   105,   106,   107,   108,   108,   110,
   109,   109,   111,   111,   111,   111,   113,   112,   112,   114,
   114,   114,   114,   116,   115,   115,   117,   117,   117,   118,
   118,   120,   119,   119,   121,   121,   123,   122,   122,   124,
   124,   126,   125,   125,   128,   127,   127,   129,   129,   129,
   129,   129,   129,   129,   130,   130,   130,   131,   131,   132,
   132,   132,   132,   133,   133,   134,   135,   136,   136,   136,
   137,   138,   139,   140,   140,   141,   141,   142,   142
};

static const short yyr2[] = {     0,
     2,     2,     0,     5,     5,     2,     2,     2,     2,     2,
     0,     4,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
     4,     2,     2,     0,     4,     4,     2,     1,     4,     3,
     4,     2,     0,     2,     0,     4,     4,     4,     2,     0,
     2,     2,     0,     4,     4,     4,     2,     0,     2,     1,
     1,     1,     1,     1,     1,     1,     0,     6,     4,     5,
     3,     3,     3,     3,     0,     1,     4,     2,     1,     1,
     1,     1,     4,     4,     4,     2,     2,     0,     1,     4,
     2,     1,     1,     1,     1,     5,     0,     0,     9,     4,
     1,     2,     1,     2,     1,     1,     1,     1,     0,     0,
     6,     4,     5,     3,     3,     0,     0,     6,     4,     5,
     3,     3,     0,     0,     5,     4,     0,     2,     1,     1,
     1,     0,     5,     4,     1,     1,     0,     7,     4,     1,
     0,     0,     6,     4,     0,     9,     6,     5,     2,     2,
     2,     2,     2,     0,     3,     4,     7,     2,     1,     1,
     1,     1,     1,     4,     4,     4,     4,     1,     1,     1,
     4,     4,     4,     4,     7,     2,     1,     1,     1
};

static const short yydefact[] = {     3,
     0,     3,     3,     0,     1,     2,     0,     0,     0,     0,
     0,     0,     0,    11,    11,    11,    11,    11,    61,    62,
    63,    64,    65,    66,   135,   136,    13,    14,    15,    16,
    17,    18,    19,    20,    21,     0,     0,     0,     5,     0,
    58,     0,    50,     0,    58,     0,     0,     0,     0,     0,
     0,     4,     6,     9,     7,     8,    10,    12,   147,   145,
     0,     0,     0,     0,     0,     0,    38,    53,     0,    24,
    25,    67,     0,     0,    26,    27,   117,     0,    28,    29,
   110,     0,   127,     0,   127,     0,    22,    23,   137,     0,
   142,   154,    31,    30,    33,    32,    54,    60,    57,    36,
     0,    43,    35,    37,    46,    49,    69,    75,    55,   119,
   123,   112,   116,   126,     0,   107,   131,   130,     0,   129,
   134,     0,   139,   127,   144,   127,     0,     0,    59,    40,
    45,     0,    52,    51,     0,     0,     0,    88,    88,     0,
   125,   128,   133,   141,     0,     0,   146,   149,   150,   151,
   152,   153,    56,    39,    42,    48,    47,    68,     0,     0,
     0,     0,   109,   118,     0,     0,     0,   111,     0,     0,
     0,     0,     0,    97,   140,     0,   143,     0,     0,     0,
     0,     0,    44,    43,     0,    71,    76,    80,    81,    82,
     0,   106,    72,    89,    94,    95,    93,     0,    73,   105,
   108,    74,    43,   122,   121,    43,   114,     0,   115,   101,
    84,    87,    86,    83,    43,   138,     0,     0,   155,   160,
     0,   159,   168,   169,   170,   161,   162,   163,     0,   178,
   179,     0,     0,     0,    41,    45,     0,     0,     0,     0,
   104,    45,    45,     0,    45,   148,     0,     0,     0,     0,
     0,     0,     0,   156,   158,     0,   174,   173,    70,     0,
     0,    79,     0,     0,     0,    92,     0,   120,   113,     0,
   103,    98,     0,     0,     0,     0,     0,     0,     0,     0,
   177,    77,    78,    85,    90,    91,     0,   100,   102,     0,
     0,   171,   172,   164,   165,   166,   167,     0,   176,    96,
     0,   157,   175,    99,     0,     0,     0
};

static const short yydefgoto[] = {     5,
     2,    13,     8,    36,    89,    72,    77,    81,    14,    62,
    15,    66,    67,   131,   155,    16,    68,   106,    17,    63,
    99,    18,    19,   108,   135,   186,   261,   262,   188,   189,
   190,   172,   193,   265,   194,   195,   117,   215,   290,   209,
   270,   199,   197,   118,   202,    20,   113,   137,    21,   111,
   136,    22,    83,   119,   120,    23,    85,    24,    25,   124,
   176,    26,   126,     3,    92,   127,   150,   221,   222,   223,
   224,   225,   226,   227,   228,   151,   152,   280,   232
};

static const short yypact[] = {    13,
    19,    13,    13,   128,-32768,-32768,    -2,   232,   237,   212,
   134,   146,   145,   147,   147,   147,   147,   147,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,   182,   189,   204,-32768,   194,
-32768,    74,-32768,    86,-32768,   229,    83,   240,   265,   191,
   200,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
   211,   133,   101,   228,   158,    28,-32768,   238,   305,-32768,
-32768,-32768,   230,   306,-32768,-32768,-32768,   307,-32768,-32768,
-32768,   308,   264,   309,   264,   310,-32768,-32768,-32768,   311,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,   168,-32768,
   312,-32768,-32768,-32768,-32768,   262,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,    84,-32768,-32768,-32768,   215,-32768,
-32768,   272,-32768,   264,-32768,   264,   274,   313,-32768,-32768,
   314,   263,-32768,-32768,    18,    21,     5,-32768,-32768,   316,
-32768,-32768,-32768,     8,   276,   161,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,    25,-32768,-32768,-32768,   317,   318,
   319,   320,   319,-32768,   322,   320,   318,-32768,   323,   318,
   324,   148,   227,-32768,-32768,   325,-32768,   237,   278,   327,
   328,   321,-32768,-32768,   110,-32768,-32768,-32768,-32768,-32768,
    66,-32768,-32768,-32768,-32768,-32768,-32768,    81,   320,-32768,
-32768,-32768,-32768,   320,-32768,-32768,-32768,   141,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,   329,   107,-32768,-32768,
   280,-32768,-32768,-32768,-32768,-32768,-32768,-32768,   177,-32768,
-32768,   330,   123,   282,-32768,   331,   333,   320,   334,   318,
-32768,   335,   336,   333,   337,-32768,   328,   333,   333,   333,
   333,   333,   333,-32768,-32768,   333,-32768,-32768,-32768,    35,
   284,-32768,   338,    17,   286,-32768,   324,-32768,-32768,   288,
-32768,-32768,   290,   292,   294,   296,   298,   300,   302,   304,
-32768,-32768,-32768,-32768,-32768,-32768,   339,-32768,-32768,   319,
   340,-32768,-32768,-32768,-32768,-32768,-32768,   341,-32768,-32768,
   342,-32768,-32768,-32768,   347,   348,-32768
};

static const short yypgoto[] = {   187,
-32768,   247,-32768,    -9,   266,-32768,-32768,-32768,   201,-32768,
-32768,-32768,   283,   -61,-32768,-32768,-32768,-32768,   223,   293,
-32768,-32768,-32768,-32768,-32768,  -155,     7,  -150,  -158,   -83,
  -162,   213,  -156,-32768,  -220,-32768,  -157,-32768,-32768,    87,
-32768,   185,  -131,   -98,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,   -55,   -85,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,  -173,  -207,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,  -228
};


#define	YYLAST		354


static const short yytable[] = {   116,
    38,   116,   192,   196,   192,   196,   201,   234,   168,   187,
   115,   205,   192,   255,   207,     1,   187,   231,   266,   187,
   220,   158,   220,   138,   164,     9,   255,   281,   139,   122,
    65,   103,   182,   142,   169,   116,   142,    10,   116,   210,
   116,   138,   116,   183,   286,     4,   139,   159,   160,   161,
   165,   299,   140,   238,   240,   170,   171,   175,   142,   142,
   116,   116,   220,   200,   162,   255,   166,   200,   144,   167,
   145,   238,   138,   273,    64,   220,    65,   139,   116,   163,
   192,   196,   116,    78,   267,   192,    69,   138,   220,   187,
   138,    79,   139,   231,    70,   139,   230,    80,   239,    71,
   241,   140,   238,   240,    97,   241,   192,   196,   192,    98,
   283,   192,   271,   138,   220,   116,   138,   231,   139,   140,
   116,   139,   236,   283,   283,   283,   283,   283,   283,   138,
     7,   192,   196,   301,   139,   210,    94,    39,   289,   247,
   248,   242,   237,   238,   243,   249,   238,   138,    52,    12,
    95,   211,   139,   245,   263,    96,   248,   212,   101,   238,
   213,   249,   250,   251,   252,   253,   102,    40,   217,    41,
    42,    43,   230,   244,    44,   128,   129,   238,   250,   251,
   252,   253,    40,   138,    41,    58,   305,    45,   139,     6,
    46,    86,    59,    47,    61,    48,   230,   -34,    49,    87,
    90,   178,    45,   179,   180,    50,    51,    60,    87,   256,
    88,   -34,    37,   238,    93,   181,   -34,   115,   141,    88,
    27,    28,    29,    30,    31,    32,    33,    34,    35,    74,
   214,   100,    11,   109,    12,   -11,   212,    75,    98,   213,
    82,   105,  -124,  -124,    76,    27,    28,    29,    30,    31,
    32,    33,    34,    35,   274,   275,   276,   277,   278,   279,
    53,    54,    55,    56,    57,    84,   115,  -132,  -132,   132,
   133,   156,   134,   157,   115,   143,   146,   147,   115,   177,
   218,   219,   233,   254,   233,   258,   260,   282,   264,   285,
   260,   288,   233,   291,   260,   292,   260,   293,   260,   294,
   260,   295,   260,   296,   260,   297,   260,   298,   107,   110,
   112,   114,   121,   123,   125,   130,    91,   154,   174,   184,
   185,   191,   198,   153,   203,   206,   208,   148,   216,   229,
   233,   235,   246,   257,   259,   260,   264,    73,   268,   269,
   272,   284,   300,   302,   303,   304,   306,   307,   104,   149,
   204,   173,     0,   287
};

static const short yycheck[] = {    83,
    10,    85,   161,   161,   163,   163,   163,   181,     4,   160,
     3,   167,   171,   221,   170,     3,   167,   180,   239,   170,
   179,     4,   181,     7,     4,    28,   234,   256,    12,    85,
     3,     4,     8,   119,    30,   119,   122,    40,   122,   171,
   124,     7,   126,    19,   265,    27,    12,    30,    31,    32,
    30,   280,    36,    37,    38,    51,    52,    50,   144,   145,
   144,   145,   221,   162,    47,   273,    46,   166,   124,    49,
   126,    37,     7,   247,     1,   234,     3,    12,   162,    62,
   239,   239,   166,     1,   240,   244,     1,     7,   247,   240,
     7,     9,    12,   256,     9,    12,   180,    15,    33,    14,
   199,    36,    37,    38,     4,   204,   265,   265,   267,     9,
   261,   270,   244,     7,   273,   199,     7,   280,    12,    36,
   204,    12,   184,   274,   275,   276,   277,   278,   279,     7,
     3,   290,   290,   290,    12,   267,     4,     4,   270,    33,
    34,   203,    33,    37,   206,    39,    37,     7,     4,     3,
    18,     4,    12,   215,   238,    23,    34,    10,     1,    37,
    13,    39,    56,    57,    58,    59,     9,    22,   178,    24,
    25,    26,   256,    33,    29,     8,     9,    37,    56,    57,
    58,    59,    22,     7,    24,     4,     0,    42,    12,     3,
    45,     1,     4,    48,     1,    50,   280,     4,    53,     9,
     1,    41,    42,    43,    44,    60,    61,     4,     9,    33,
    20,    18,     1,    37,     4,    55,    23,     3,     4,    20,
     9,    10,    11,    12,    13,    14,    15,    16,    17,     1,
     4,     4,     1,     4,     3,     4,    10,     9,     9,    13,
     1,     4,     3,     4,    16,     9,    10,    11,    12,    13,
    14,    15,    16,    17,   248,   249,   250,   251,   252,   253,
    14,    15,    16,    17,    18,     1,     3,     3,     4,     8,
     9,     9,    11,    11,     3,     4,     3,     4,     3,     4,
     3,     4,     3,     4,     3,     4,     3,     4,     3,     4,
     3,     4,     3,     4,     3,     4,     3,     4,     3,     4,
     3,     4,     3,     4,     3,     4,     3,     4,     4,     4,
     4,     4,     4,     4,     4,     4,    51,     4,     3,     3,
     3,     3,     3,    11,     3,     3,     3,   127,     4,     3,
     3,    11,     4,     4,     4,     3,     3,    45,     4,     4,
     4,     4,     4,     4,     4,     4,     0,     0,    66,   127,
   166,   139,    -1,   267
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
#line 1552 "grammar.cc"

  switch (yyn) {

case 5:
#line 96 "ppddl.y"
{
          log_error((char*)"syntax error in domain");
          yyerrok;
      ;
    break;}
case 12:
#line 112 "ppddl.y"
{ domain_name_ = yyvsp[-1].sym->text; ;
    break;}
case 13:
#line 118 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 14:
#line 119 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 15:
#line 120 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 16:
#line 121 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 17:
#line 122 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 18:
#line 123 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 19:
#line 124 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 20:
#line 125 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 21:
#line 126 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 22:
#line 130 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 23:
#line 131 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 24:
#line 135 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 25:
#line 136 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 26:
#line 140 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 27:
#line 141 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 28:
#line 145 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 29:
#line 146 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 31:
#line 153 "ppddl.y"
{
          log_error((char*)"syntax error in requirements declaration.");
          yyerrok;
      ;
    break;}
case 32:
#line 160 "ppddl.y"
{ declare_multivalued_variable_translation(); ;
    break;}
case 36:
#line 169 "ppddl.y"
{
          log_error((char*)"syntax error in (:predicates ...)");
          yyerrok;
      ;
    break;}
case 39:
#line 181 "ppddl.y"
{
          PredicateSymbol *p = new PredicateSymbol(yyvsp[-2].sym->text);
          dom_predicates_.push_back(p);
          p->param_ = *yyvsp[-1].vparam;
          delete yyvsp[-1].vparam;
          clear_param(p->param_);
          yyvsp[-2].sym->val = p;
      ;
    break;}
case 40:
#line 189 "ppddl.y"
{
          log_error((char*)"syntax error in predicate declaration");
          yyerrok;
      ;
    break;}
case 41:
#line 196 "ppddl.y"
{
          set_variable_type(*yyvsp[-2].vparam, yyvsp[-2].vparam->size(), static_cast<TypeSymbol*>(yyvsp[0].sym->val));
          yyvsp[-3].vparam->insert(yyvsp[-3].vparam->end(), yyvsp[-2].vparam->begin(), yyvsp[-2].vparam->end());
          delete yyvsp[-2].vparam;
          yyval.vparam = yyvsp[-3].vparam;
      ;
    break;}
case 42:
#line 202 "ppddl.y"
{
          set_variable_type(*yyvsp[-1].vparam, yyvsp[-1].vparam->size(), dom_top_type_);
          yyvsp[-1].vparam->insert(yyvsp[-1].vparam->end(), yyvsp[0].vparam->begin(), yyvsp[0].vparam->end());
          delete yyvsp[0].vparam;
          yyval.vparam = yyvsp[-1].vparam;
      ;
    break;}
case 43:
#line 208 "ppddl.y"
{ yyval.vparam = new var_symbol_vec; ;
    break;}
case 44:
#line 212 "ppddl.y"
{
          VariableSymbol *var = new VariableSymbol(yyvsp[0].sym->text);
          yyvsp[0].sym->val = var;
          yyvsp[-1].vparam->push_back(var);
          yyval.vparam = yyvsp[-1].vparam;
      ;
    break;}
case 45:
#line 218 "ppddl.y"
{ yyval.vparam = new var_symbol_vec; ;
    break;}
case 47:
#line 228 "ppddl.y"
{
          set_type_type(dom_types_, dom_types_.size(), static_cast<TypeSymbol*>(yyvsp[0].sym->val));
      ;
    break;}
case 48:
#line 231 "ppddl.y"
{
          yyvsp[0].sym->val = new TypeSymbol(yyvsp[0].sym->text);
          if( write_warnings_ )
              std::cerr << "warning: assuming " << yyvsp[0].sym->text << " - object" << std::endl;
          static_cast<TypeSymbol*>(yyvsp[0].sym->val)->sym_type_ = dom_top_type_;
          set_type_type(dom_types_, dom_types_.size(), static_cast<TypeSymbol*>(yyvsp[0].sym->val));
          dom_types_.push_back(static_cast<TypeSymbol*>(yyvsp[0].sym->val));
      ;
    break;}
case 49:
#line 239 "ppddl.y"
{
          set_type_type(dom_types_, dom_types_.size(), dom_top_type_);
      ;
    break;}
case 51:
#line 246 "ppddl.y"
{
          /* the type is already (implicitly) declared */
      ;
    break;}
case 52:
#line 249 "ppddl.y"
{
          yyvsp[0].sym->val = new TypeSymbol(yyvsp[0].sym->text);
          dom_types_.push_back(static_cast<TypeSymbol*>(yyvsp[0].sym->val));
      ;
    break;}
case 56:
#line 264 "ppddl.y"
{
          set_constant_type(dom_constants_, dom_constants_.size(), static_cast<TypeSymbol*>(yyvsp[0].sym->val));
      ;
    break;}
case 57:
#line 267 "ppddl.y"
{
          set_constant_type(dom_constants_, dom_constants_.size(), dom_top_type_);
      ;
    break;}
case 59:
#line 274 "ppddl.y"
{
          yyvsp[0].sym->val = new Symbol(yyvsp[0].sym->text);
          dom_constants_.push_back(static_cast<Symbol*>(yyvsp[0].sym->val));
      ;
    break;}
case 60:
#line 278 "ppddl.y"
{
          yyvsp[0].sym->val = new Symbol(yyvsp[0].sym->text);
          dom_constants_.push_back(static_cast<Symbol*>(yyvsp[0].sym->val));
      ;
    break;}
case 62:
#line 288 "ppddl.y"
{
         if( type_ == replanner ) {
             log_error((char*)"':axiom' is not a valid element in k-replanner.");
             yyerrok;
         }
      ;
    break;}
case 63:
#line 294 "ppddl.y"
{
         if( type_ == cp2fsc ) {
             log_error((char*)"':sensor' is not a valid element in cp2fsc.");
             yyerrok;
         }
      ;
    break;}
case 64:
#line 300 "ppddl.y"
{
         if( type_ == replanner ) {
             log_error((char*)"':observable' is not a valid element in k-replanner.");
             yyerrok;
         }
      ;
    break;}
case 65:
#line 306 "ppddl.y"
{
         if( type_ == replanner ) {
             log_error((char*)"':sticky' is not a valid element in k-replanner.");
             yyerrok;
         }
      ;
    break;}
case 66:
#line 312 "ppddl.y"
{
         if( type_ == cp2fsc ) {
             log_error((char*)"':sensor' is not a valid element in cp2fsc.");
             yyerrok;
         }
      ;
    break;}
case 67:
#line 323 "ppddl.y"
{
          Action *na = new Action(yyvsp[0].sym->text);
          dom_actions_.push_back(na);
      ;
    break;}
case 68:
#line 327 "ppddl.y"
{
          clear_param(dom_actions_.back()->param_);
          yyvsp[-3].sym->val = dom_actions_.back();
      ;
    break;}
case 69:
#line 331 "ppddl.y"
{
          log_error((char*)"syntax error in action declaration");
          yyerrok;
      ;
    break;}
case 70:
#line 338 "ppddl.y"
{
          dom_actions_.back()->param_ = *yyvsp[-1].vparam;
          delete yyvsp[-1].vparam;
      ;
    break;}
case 71:
#line 342 "ppddl.y"
{ dom_actions_.back()->precondition_ = yyvsp[0].condition; ;
    break;}
case 72:
#line 343 "ppddl.y"
{ dom_actions_.back()->effect_ = yyvsp[0].effect; ;
    break;}
case 73:
#line 344 "ppddl.y"
{
          declare_clg_translation();
          dom_actions_.back()->observe_ = yyvsp[0].effect;
      ;
    break;}
case 74:
#line 348 "ppddl.y"
{
          declare_multivalued_variable_translation();
          dom_actions_.back()->sensing_model_ = yyvsp[0].effect;
      ;
    break;}
case 77:
#line 357 "ppddl.y"
{ yyval.condition = yyvsp[-1].condition; ;
    break;}
case 78:
#line 361 "ppddl.y"
{
          const_cast<And*>(static_cast<const And*>(yyvsp[-1].condition))->push_back(yyvsp[0].condition);
          yyval.condition = yyvsp[-1].condition;
      ;
    break;}
case 79:
#line 365 "ppddl.y"
{
          And *cond = new And();
          cond->push_back(yyvsp[0].condition);
          yyval.condition = cond;
      ;
    break;}
case 80:
#line 373 "ppddl.y"
{
          // if literal is for equality, construct EQ
          if( yyvsp[0].atom->pred_ == dom_eq_pred_ )
              yyval.condition = new EQ(static_cast<VariableSymbol*>(yyvsp[0].atom->param_[0]), static_cast<VariableSymbol*>(yyvsp[0].atom->param_[1]), yyvsp[0].atom->negated_);
          else
              yyval.condition = new Literal(*yyvsp[0].atom);
          delete yyvsp[0].atom;
      ;
    break;}
case 83:
#line 389 "ppddl.y"
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
case 84:
#line 401 "ppddl.y"
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
case 85:
#line 413 "ppddl.y"
{
          const_cast<Literal*>(static_cast<const Literal*>(yyvsp[-1].atom))->negated_ = true;
          yyval.atom = yyvsp[-1].atom;
      ;
    break;}
case 86:
#line 420 "ppddl.y"
{
          if( yyvsp[0].sym->val == 0 )
              log_error((char*)"undeclared variable in atom args list");
          else
              yyvsp[-1].param->push_back(static_cast<VariableSymbol*>(yyvsp[0].sym->val));
          yyval.param = yyvsp[-1].param;
      ;
    break;}
case 87:
#line 427 "ppddl.y"
{
          yyvsp[-1].param->push_back(static_cast<Symbol*>(yyvsp[0].sym->val));
          yyval.param = yyvsp[-1].param;
      ;
    break;}
case 88:
#line 431 "ppddl.y"
{ yyval.param = new PDDL_Base::symbol_vec; ;
    break;}
case 90:
#line 436 "ppddl.y"
{ yyval.effect = yyvsp[-1].effect; ;
    break;}
case 91:
#line 440 "ppddl.y"
{
          const_cast<AndEffect*>(static_cast<const AndEffect*>(yyvsp[-1].effect))->push_back(yyvsp[0].effect);
          yyval.effect = yyvsp[-1].effect;
      ;
    break;}
case 92:
#line 444 "ppddl.y"
{
          AndEffect *eff = new AndEffect;
          eff->push_back(yyvsp[0].effect);
          yyval.effect = eff;
      ;
    break;}
case 96:
#line 458 "ppddl.y"
{ yyval.effect = new ConditionalEffect(yyvsp[-2].condition, yyvsp[-1].effect); ;
    break;}
case 97:
#line 462 "ppddl.y"
{
          forall_effects.push_back(new ForallEffect);
      ;
    break;}
case 98:
#line 465 "ppddl.y"
{
          forall_effects.back()->param_ = *yyvsp[-1].vparam;
          delete yyvsp[-1].vparam;
      ;
    break;}
case 99:
#line 469 "ppddl.y"
{
          forall_effects.back()->effect_ = yyvsp[-1].effect;
          clear_param(forall_effects.back()->param_);
          yyval.effect = forall_effects.back();
          forall_effects.pop_back();
      ;
    break;}
case 100:
#line 478 "ppddl.y"
{ yyval.effect = yyvsp[-1].effect; ;
    break;}
case 102:
#line 483 "ppddl.y"
{
          const_cast<AndEffect*>(static_cast<const AndEffect*>(yyvsp[-1].effect))->push_back(yyvsp[0].effect);
          yyval.effect = yyvsp[-1].effect;
      ;
    break;}
case 103:
#line 487 "ppddl.y"
{
          AndEffect *eff = new AndEffect;
          eff->push_back(yyvsp[0].effect);
          yyval.effect = eff;
      ;
    break;}
case 104:
#line 495 "ppddl.y"
{
          const_cast<AndEffect*>(static_cast<const AndEffect*>(yyvsp[-1].effect))->push_back(yyvsp[0].effect);
          yyval.effect = yyvsp[-1].effect;
      ;
    break;}
case 105:
#line 499 "ppddl.y"
{
          AndEffect *eff = new AndEffect;
          eff->push_back(yyvsp[0].effect);
          yyval.effect = eff;
      ;
    break;}
case 106:
#line 507 "ppddl.y"
{ yyval.effect = new AtomicEffect(*yyvsp[0].atom); delete yyvsp[0].atom; ;
    break;}
case 107:
#line 511 "ppddl.y"
{ yyval.effect = new AtomicEffect(*yyvsp[0].atom); delete yyvsp[0].atom; ;
    break;}
case 109:
#line 516 "ppddl.y"
{ yyval.effect = 0; ;
    break;}
case 110:
#line 520 "ppddl.y"
{
          Axiom *nr = new Axiom(yyvsp[0].sym->text);
          dom_axioms_.push_back(nr);
      ;
    break;}
case 111:
#line 524 "ppddl.y"
{
          clear_param(dom_axioms_.back()->param_);
          yyvsp[-3].sym->val = dom_axioms_.back();
      ;
    break;}
case 112:
#line 528 "ppddl.y"
{
          log_error((char*)"syntax error in axiom declaration");
          yyerrok;
      ;
    break;}
case 113:
#line 535 "ppddl.y"
{
          dom_axioms_.back()->param_ = *yyvsp[-1].vparam;
          delete yyvsp[-1].vparam;
      ;
    break;}
case 114:
#line 539 "ppddl.y"
{ dom_axioms_.back()->body_ = yyvsp[0].condition; ;
    break;}
case 115:
#line 540 "ppddl.y"
{ dom_axioms_.back()->head_ = yyvsp[0].effect; ;
    break;}
case 117:
#line 545 "ppddl.y"
{
          Sensor *nr = new Sensor(yyvsp[0].sym->text);
          dom_sensors_.push_back(nr);
      ;
    break;}
case 118:
#line 549 "ppddl.y"
{
          clear_param(dom_sensors_.back()->param_);
          yyvsp[-3].sym->val = dom_sensors_.back();
      ;
    break;}
case 119:
#line 553 "ppddl.y"
{
          log_error((char*)"syntax error in sensor declaration");
          yyerrok;
      ;
    break;}
case 120:
#line 560 "ppddl.y"
{
          dom_sensors_.back()->param_ = *yyvsp[-1].vparam;
          delete yyvsp[-1].vparam;
      ;
    break;}
case 121:
#line 564 "ppddl.y"
{ dom_sensors_.back()->condition_ = yyvsp[0].condition; ;
    break;}
case 122:
#line 565 "ppddl.y"
{ dom_sensors_.back()->sense_ = yyvsp[0].effect; ;
    break;}
case 124:
#line 570 "ppddl.y"
{
          Observable *obs = new Observable;
          dom_observables_.push_back(obs);
          tmp_effect_vec_ptr_ = &obs->observables_;
      ;
    break;}
case 126:
#line 575 "ppddl.y"
{
          log_error((char*)"syntax error in observable declaration");
          yyerrok;
      ;
    break;}
case 128:
#line 582 "ppddl.y"
{
          tmp_effect_vec_ptr_->push_back(yyvsp[0].effect);
      ;
    break;}
case 129:
#line 585 "ppddl.y"
{
          tmp_effect_vec_ptr_->push_back(yyvsp[0].effect);
      ;
    break;}
case 132:
#line 596 "ppddl.y"
{
          Sticky *sticky = new Sticky;
          dom_stickies_.push_back(sticky);
          tmp_effect_vec_ptr_ = &sticky->stickies_;
      ;
    break;}
case 134:
#line 601 "ppddl.y"
{
          log_error((char*)"syntax error in sticky declaration");
          yyerrok;
      ;
    break;}
case 137:
#line 613 "ppddl.y"
{
          StateVariable *var = new StateVariable(yyvsp[0].sym->text);
          multivalued_variables_.push_back(var);
          tmp_effect_vec_ptr_ = &var->values_;
      ;
    break;}
case 139:
#line 619 "ppddl.y"
{
          log_error((char*)"syntax error in state variable declaration");
          yyerrok;
      ;
    break;}
case 140:
#line 626 "ppddl.y"
{
          dynamic_cast<StateVariable*>(multivalued_variables_.back())->is_observable_ = true;
      ;
    break;}
case 142:
#line 633 "ppddl.y"
{
          ObsVariable *var = new ObsVariable(yyvsp[0].sym->text);
          multivalued_variables_.push_back(var);
          tmp_effect_vec_ptr_ = &var->values_;
      ;
    break;}
case 144:
#line 639 "ppddl.y"
{
          log_error((char*)"syntax error in observable variable declaration");
          yyerrok;
      ;
    break;}
case 145:
#line 649 "ppddl.y"
{
          problem_name_ = yyvsp[-1].sym->text;
      ;
    break;}
case 147:
#line 653 "ppddl.y"
{
          log_error((char*)"syntax error in problem definition.");
          yyerrok;
      ;
    break;}
case 156:
#line 671 "ppddl.y"
{ dom_init_ = *yyvsp[-1].ilist; delete yyvsp[-1].ilist; ;
    break;}
case 157:
#line 672 "ppddl.y"
{ dom_init_ = *yyvsp[-2].ilist; delete yyvsp[-2].ilist; ;
    break;}
case 158:
#line 676 "ppddl.y"
{
          init_element_vec *ilist = const_cast<init_element_vec*>(yyvsp[-1].ilist);
          ilist->push_back(const_cast<InitElement*>(yyvsp[0].ielem));
          yyval.ilist = ilist;
      ;
    break;}
case 159:
#line 681 "ppddl.y"
{
          init_element_vec *ilist = new init_element_vec;
          ilist->push_back(const_cast<InitElement*>(yyvsp[0].ielem));
          yyval.ilist = ilist;
      ;
    break;}
case 160:
#line 689 "ppddl.y"
{ yyval.ielem = new InitLiteral(*yyvsp[0].atom); ;
    break;}
case 161:
#line 690 "ppddl.y"
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
case 162:
#line 701 "ppddl.y"
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
case 163:
#line 712 "ppddl.y"
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
case 164:
#line 726 "ppddl.y"
{
          yyval.invariant = new Invariant(Invariant::AT_LEAST_ONE, *static_cast<const And*>(yyvsp[-1].condition));
          const_cast<And*>(static_cast<const And*>(yyvsp[-1].condition))->clear();
          delete yyvsp[-1].condition;
      ;
    break;}
case 165:
#line 731 "ppddl.y"
{
          yyval.invariant = new Invariant(Invariant::AT_LEAST_ONE, *static_cast<const And*>(yyvsp[-1].condition));
          const_cast<And*>(static_cast<const And*>(yyvsp[-1].condition))->clear();
          delete yyvsp[-1].condition;
      ;
    break;}
case 166:
#line 739 "ppddl.y"
{
          yyval.invariant = new Invariant(Invariant::AT_MOST_ONE, *static_cast<const And*>(yyvsp[-1].condition));
          const_cast<And*>(static_cast<const And*>(yyvsp[-1].condition))->clear();
          delete yyvsp[-1].condition;
      ;
    break;}
case 167:
#line 747 "ppddl.y"
{
          yyval.invariant = new Invariant(Invariant::EXACTLY_ONE, *static_cast<const And*>(yyvsp[-1].condition));
          const_cast<And*>(static_cast<const And*>(yyvsp[-1].condition))->clear();
          delete yyvsp[-1].condition;
      ;
    break;}
case 171:
#line 761 "ppddl.y"
{
          yyval.clause = new Clause(*static_cast<const And*>(yyvsp[-1].condition));
          const_cast<And*>(static_cast<const And*>(yyvsp[-1].condition))->clear();
          delete yyvsp[-1].condition;
      ;
    break;}
case 172:
#line 769 "ppddl.y"
{
          yyval.oneof = new Oneof(*static_cast<const And*>(yyvsp[-1].condition));
          const_cast<And*>(static_cast<const And*>(yyvsp[-1].condition))->clear();
          delete yyvsp[-1].condition;
      ;
    break;}
case 173:
#line 777 "ppddl.y"
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
case 174:
#line 789 "ppddl.y"
{ dom_goal_ = yyvsp[-1].condition; ;
    break;}
case 175:
#line 790 "ppddl.y"
{ dom_goal_ = yyvsp[-2].condition; ;
    break;}
case 176:
#line 794 "ppddl.y"
{
          const_cast<And*>(static_cast<const And*>(yyvsp[-1].condition))->push_back(yyvsp[0].condition);
          yyval.condition = yyvsp[-1].condition;
      ;
    break;}
case 177:
#line 798 "ppddl.y"
{
          And *cond = new And;
          cond->push_back(yyvsp[0].condition);
          yyval.condition = cond;
      ;
    break;}
case 178:
#line 807 "ppddl.y"
{ yyval.condition = new Literal(*yyvsp[0].atom); delete yyvsp[0].atom; ;
    break;}
case 179:
#line 808 "ppddl.y"
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
#line 2567 "grammar.cc"
#line 811 "ppddl.y"


