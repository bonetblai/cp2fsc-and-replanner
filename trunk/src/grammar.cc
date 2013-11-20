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
    std::vector<ForallEffect*> forall_effects; \
    std::vector<ForallCondition*> forall_conditions;
#line 23 "ppddl.y"

#include <stdlib.h>
#include <string.h>
#include <list>
#include <sstream>
#include "base.h"

#line 31 "ppddl.y"
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
#line 180 "grammar.cc"

#line 117 "/home/bonet/space/software/bison++-1.21-8/lib/bison.cc"
/*  YY_PDDL_Parser_PURE */
#endif

/* section apres lecture def, avant lecture grammaire S2 */

/* #line 121 "/home/bonet/space/software/bison++-1.21-8/lib/bison.cc" */
#line 189 "grammar.cc"

#line 121 "/home/bonet/space/software/bison++-1.21-8/lib/bison.cc"
/* prefix */
#ifndef YY_PDDL_Parser_DEBUG

/* #line 123 "/home/bonet/space/software/bison++-1.21-8/lib/bison.cc" */
#line 196 "grammar.cc"

#line 123 "/home/bonet/space/software/bison++-1.21-8/lib/bison.cc"
/* YY_PDDL_Parser_DEBUG */
#endif


#ifndef YY_PDDL_Parser_LSP_NEEDED

/* #line 128 "/home/bonet/space/software/bison++-1.21-8/lib/bison.cc" */
#line 206 "grammar.cc"

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
#line 319 "grammar.cc"
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
#line 431 "grammar.cc"
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


#line 280 "/home/bonet/space/software/bison++-1.21-8/lib/bison.cc"
 /* decl const */
#else
enum YY_PDDL_Parser_ENUM_TOKEN { YY_PDDL_Parser_NULL_TOKEN=0

/* #line 283 "/home/bonet/space/software/bison++-1.21-8/lib/bison.cc" */
#line 502 "grammar.cc"
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
#line 601 "grammar.cc"
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
#line 680 "grammar.cc"


#define	YYFINAL		347
#define	YYFLAG		-32768
#define	YYNTBASE	65

#define YYTRANSLATE(x) ((unsigned)(x) <= 319 ? yytranslate[x] : 158)

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
   241,   245,   249,   253,   254,   256,   258,   260,   262,   264,
   266,   268,   273,   278,   283,   286,   289,   290,   295,   300,
   301,   302,   312,   315,   317,   320,   322,   324,   329,   332,
   334,   336,   338,   340,   346,   347,   348,   358,   363,   365,
   368,   370,   373,   375,   377,   379,   381,   382,   383,   390,
   395,   401,   405,   409,   410,   411,   418,   423,   429,   433,
   437,   438,   439,   445,   450,   453,   455,   457,   459,   460,
   466,   471,   472,   481,   482,   493,   498,   500,   502,   507,
   508,   510,   511,   516,   517,   527,   534,   540,   543,   546,
   549,   552,   555,   556,   560,   565,   573,   576,   578,   580,
   582,   584,   586,   591,   596,   601,   606,   608,   610,   612,
   617,   622,   627,   632,   640,   643,   645,   647
};

static const short yyrhs[] = {    66,
    65,     0,   142,    65,     0,     0,     3,    27,    68,    67,
     4,     0,     3,    27,    68,     1,     4,     0,    67,    74,
     0,    67,    84,     0,    67,    88,     0,    67,    76,     0,
    67,    93,     0,    67,   141,     0,     0,     3,    28,    69,
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
    92,     9,     0,     9,     0,    94,     0,   123,     0,   126,
     0,   129,     0,   133,     0,   135,     0,     0,     3,    29,
    71,    95,    96,     4,     0,     3,    29,     1,     4,     0,
    96,    30,     3,    79,     4,     0,    96,    31,    97,     0,
    96,    32,   110,     0,    96,    47,   119,     0,    96,    63,
   122,     0,     0,    98,     0,   103,     0,   104,     0,   105,
     0,    99,     0,   100,     0,   101,     0,     3,    12,   102,
     4,     0,     3,     7,   102,     4,     0,     3,    37,   100,
     4,     0,   102,    13,     0,   102,    10,     0,     0,     3,
    33,   109,     4,     0,     3,    34,   109,     4,     0,     0,
     0,     3,    36,     3,   106,    79,     4,   107,    97,     4,
     0,   108,    98,     0,    98,     0,   109,    97,     0,    97,
     0,   112,     0,     3,    33,   111,     4,     0,   111,   112,
     0,   112,     0,   120,     0,   113,     0,   114,     0,     3,
    38,    97,   117,     4,     0,     0,     0,     3,    36,     3,
   115,    79,     4,   116,   110,     4,     0,     3,    33,   118,
     4,     0,   120,     0,   118,   120,     0,   120,     0,   119,
   121,     0,   121,     0,    99,     0,   100,     0,   110,     0,
     0,     0,     3,    48,    73,   124,   125,     4,     0,     3,
    48,     1,     4,     0,   125,    30,     3,    79,     4,     0,
   125,    51,    97,     0,   125,    52,   117,     0,     0,     0,
     3,    45,    72,   127,   128,     4,     0,     3,    45,     1,
     4,     0,   128,    30,     3,    79,     4,     0,   128,    49,
    97,     0,   128,    46,   119,     0,     0,     0,     3,    50,
   130,   131,     4,     0,     3,    50,     1,     4,     0,   131,
   132,     0,   132,     0,   121,     0,   114,     0,     0,     3,
    53,   134,   131,     4,     0,     3,    53,     1,     4,     0,
     0,     3,   138,    70,   136,   139,   131,   140,     4,     0,
     0,     3,   138,     3,    70,    79,     4,   137,   131,   140,
     4,     0,     3,    60,     1,     4,     0,    60,     0,    61,
     0,    30,     3,    79,     4,     0,     0,    50,     0,     0,
     3,    64,   122,     4,     0,     0,     3,    27,     3,    40,
    69,     4,   143,   144,     4,     0,     3,    27,     3,    40,
     1,     4,     0,   144,     3,    41,    69,     4,     0,   144,
    74,     0,   144,    88,     0,   144,   145,     0,   144,   154,
     0,   144,   155,     0,     0,     3,    43,     4,     0,     3,
    43,   146,     4,     0,     3,    43,     3,    33,   146,     4,
     4,     0,   146,   147,     0,   147,     0,    99,     0,   151,
     0,   152,     0,   153,     0,     3,    56,   108,     4,     0,
     3,    57,   108,     4,     0,     3,    58,   108,     4,     0,
     3,    59,   108,     4,     0,   148,     0,   149,     0,   150,
     0,     3,    34,   108,     4,     0,     3,    39,   108,     4,
     0,     3,    55,   146,     4,     0,     3,    44,   157,     4,
     0,     3,    44,     3,    33,   156,     4,     4,     0,   156,
   157,     0,   157,     0,   100,     0,   101,     0
};

#endif

#if YY_PDDL_Parser_DEBUG != 0
static const short yyrline[] = { 0,
    98,   100,   101,   104,   106,   112,   114,   115,   116,   117,
   118,   119,   122,   128,   130,   131,   132,   133,   134,   135,
   136,   137,   140,   142,   145,   147,   150,   152,   155,   157,
   162,   164,   170,   172,   173,   178,   180,   186,   188,   191,
   200,   206,   208,   215,   218,   225,   232,   238,   243,   246,
   256,   258,   263,   267,   275,   278,   280,   283,   285,   293,
   295,   296,   297,   300,   305,   305,   308,   314,   319,   327,
   329,   335,   341,   347,   353,   364,   369,   373,   379,   384,
   385,   386,   391,   395,   398,   400,   401,   402,   405,   416,
   418,   421,   434,   445,   452,   460,   464,   467,   474,   481,
   485,   489,   497,   502,   509,   514,   521,   523,   529,   534,
   540,   542,   543,   546,   550,   554,   558,   566,   571,   574,
   579,   585,   590,   596,   600,   604,   606,   609,   614,   618,
   624,   629,   630,   631,   634,   639,   643,   649,   654,   657,
   661,   664,   670,   671,   677,   681,   686,   688,   691,   697,
   698,   704,   714,   717,   728,   732,   738,   740,   743,   748,
   751,   756,   761,   771,   775,   776,   782,   784,   785,   786,
   787,   788,   789,   792,   794,   795,   798,   804,   811,   813,
   824,   835,   848,   854,   861,   869,   876,   878,   879,   882,
   889,   896,   908,   910,   913,   918,   926,   928
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
"single_condition","literal","positive_literal","negative_literal","argument_list",
"and_condition","or_condition","forall_condition","@3","@4","single_condition_list",
"condition_list","action_effect","action_effect_list","single_action_effect",
"conditional_effect","forall_effect","@5","@6","atomic_effect_kw_list","atomic_effect_list",
"positive_atomic_effect_list","atomic_effect","positive_atomic_effect","sensing_model",
"axiom_decl","@7","axiom_elements","sensor_decl","@8","sensor_elements","observable_decl",
"@9","fluent_list_decl","fluent_decl","sticky_decl","@10","multivalued_variable_decl",
"@11","@12","multivalued_variable_type","optional_variable_parameters","rest_variable_decl",
"domain_default_sensing_model","pddl_problem","@13","problem_elements","initial_state",
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
    96,    96,    96,    96,    97,    97,    97,    97,    98,    99,
    99,   100,   100,   101,   102,   102,   102,   103,   104,   106,
   107,   105,   108,   108,   109,   109,   110,   110,   111,   111,
   112,   112,   112,   113,   115,   116,   114,   117,   117,   118,
   118,   119,   119,   120,   121,   122,   122,   124,   123,   123,
   125,   125,   125,   125,   127,   126,   126,   128,   128,   128,
   128,   130,   129,   129,   131,   131,   132,   132,   134,   133,
   133,   136,   135,   137,   135,   135,   138,   138,   139,   139,
   140,   140,   141,   143,   142,   142,   144,   144,   144,   144,
   144,   144,   144,   145,   145,   145,   146,   146,   147,   147,
   147,   147,   148,   148,   149,   150,   151,   151,   151,   152,
   153,   154,   155,   155,   156,   156,   157,   157
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
     3,     3,     3,     0,     1,     1,     1,     1,     1,     1,
     1,     4,     4,     4,     2,     2,     0,     4,     4,     0,
     0,     9,     2,     1,     2,     1,     1,     4,     2,     1,
     1,     1,     1,     5,     0,     0,     9,     4,     1,     2,
     1,     2,     1,     1,     1,     1,     0,     0,     6,     4,
     5,     3,     3,     0,     0,     6,     4,     5,     3,     3,
     0,     0,     5,     4,     2,     1,     1,     1,     0,     5,
     4,     0,     8,     0,    10,     4,     1,     1,     4,     0,
     1,     0,     4,     0,     9,     6,     5,     2,     2,     2,
     2,     2,     0,     3,     4,     7,     2,     1,     1,     1,
     1,     1,     4,     4,     4,     4,     1,     1,     1,     4,
     4,     4,     4,     7,     2,     1,     1,     1
};

static const short yydefact[] = {     3,
     0,     3,     3,     0,     1,     2,     0,     0,     0,     0,
     0,     0,    14,    15,    16,    17,    18,    19,    20,    21,
    22,     0,     0,     0,     5,     0,     4,     6,     9,     7,
     8,    10,    70,    71,    72,    73,    74,    75,    11,    13,
   166,   164,     0,    66,     0,    55,     0,    66,     0,     0,
     0,     0,     0,   158,   127,     0,   173,     0,     0,    69,
     0,     0,    67,     0,     0,     0,    39,    59,    58,     0,
     0,    57,     0,    25,    26,    76,     0,     0,     0,    27,
    28,   135,     0,    29,    30,   128,     0,     0,     0,     0,
     0,     0,   124,    90,    91,   126,   107,   112,   113,   111,
     0,     0,    23,    24,   152,     0,    32,    31,    34,    33,
    60,    62,     0,    68,    37,     0,    44,    36,    38,    52,
    51,     0,    56,    78,    84,    61,    63,   137,   141,   130,
   134,   144,     0,   125,   148,   147,     0,   146,   151,     0,
   156,    97,    97,     0,     0,     0,     0,   163,    44,   160,
     0,   165,   168,   169,   170,   171,   172,    64,    41,    50,
     0,    42,    43,    45,    49,    55,    55,     0,     0,     0,
   143,   145,   150,     0,     0,     0,     0,   110,   115,     0,
     0,     0,     0,    85,    89,    86,    87,    88,     0,     0,
     0,     0,     0,     0,     0,    66,    40,     0,    48,    54,
     0,    53,    77,     0,     0,     0,     0,   127,   136,     0,
     0,     0,   129,     0,     0,     0,    93,    96,    95,    92,
   108,   109,    44,    94,     0,     0,     0,     0,     0,   119,
   154,    44,   162,     0,     0,   174,   179,     0,   178,   187,
   188,   189,   180,   181,   182,     0,   197,   198,     0,     0,
     0,    65,     0,    47,    44,    80,    81,    82,   123,    83,
    44,   140,   139,    44,   132,   133,     0,   106,     0,     0,
   100,     0,   114,     0,     0,   161,     0,   167,     0,     0,
     0,     0,     0,     0,     0,   175,   177,     0,   193,   192,
    46,     0,     0,   122,     0,     0,   116,    98,   105,    99,
    44,     0,     0,   121,   162,   159,   153,     0,   104,     0,
     0,     0,     0,     0,     0,     0,   196,    79,   138,   131,
     0,     0,   118,   120,     0,     0,   190,   103,   191,   183,
   184,   185,   186,     0,   195,     0,   101,   155,   176,   194,
   117,     0,     0,   102,     0,     0,     0
};

static const short yydefgoto[] = {     5,
     2,    12,     8,    22,   105,    76,    82,    86,    28,    59,
    29,    66,    67,   161,   162,   163,   164,   165,    30,    70,
   201,    72,    31,    61,   196,    62,    63,    32,    33,   125,
   168,   268,   184,   185,    94,    95,   174,   186,   187,   188,
   301,   342,   310,   269,    96,   177,    97,    98,   135,   223,
   321,   229,   303,   258,   100,   136,   101,    34,   131,   170,
    35,   129,   169,    36,    88,   137,   138,    37,    90,    38,
   150,   274,    56,   191,   277,    39,     3,    57,   106,   155,
   238,   239,   240,   241,   242,   243,   244,   245,   156,   157,
   316,   249
};

static const short yypact[] = {    16,
     1,    16,    16,    78,-32768,-32768,    69,    97,   295,   273,
   125,   206,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,   131,   142,   175,-32768,   196,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,   155,   177,   161,   197,    26,   177,    94,   190,
   225,   232,   191,-32768,   198,    21,-32768,   193,    64,-32768,
   212,   219,   158,   239,    36,   247,-32768,-32768,-32768,   241,
   223,-32768,   243,-32768,-32768,-32768,   248,   277,   293,-32768,
-32768,-32768,   329,-32768,-32768,-32768,   332,   226,   333,   226,
   334,   112,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
   335,    98,-32768,-32768,-32768,   251,-32768,-32768,-32768,-32768,
-32768,-32768,   330,-32768,-32768,   336,   323,-32768,-32768,-32768,
-32768,   231,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,    27,-32768,-32768,-32768,   255,-32768,-32768,   272,
-32768,-32768,-32768,   340,   341,   342,   343,-32768,   323,   317,
    72,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
   344,-32768,-32768,   118,-32768,   197,   197,    12,    28,    34,
-32768,-32768,-32768,   167,   194,    55,   274,-32768,-32768,   163,
   345,   148,   347,-32768,-32768,-32768,-32768,-32768,   348,   350,
   226,   295,   276,   351,   352,   177,-32768,   346,-32768,-32768,
   228,-32768,-32768,   353,   343,   198,   342,   198,-32768,   355,
   342,   343,-32768,   356,   343,   347,-32768,-32768,-32768,-32768,
-32768,-32768,   323,-32768,   343,   343,   357,    24,   358,-32768,
-32768,   323,    15,   359,    13,-32768,-32768,   288,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,   132,-32768,-32768,   360,   156,
   290,-32768,   158,   323,   323,-32768,-32768,   342,-32768,-32768,
   323,   342,-32768,   323,-32768,-32768,   361,-32768,   292,   310,
-32768,   363,-32768,   226,   364,-32768,   365,-32768,   352,   363,
   363,   363,   363,   363,   363,-32768,-32768,   363,-32768,-32768,
-32768,   118,   366,-32768,   367,   368,-32768,-32768,-32768,-32768,
   323,    41,   312,-32768,    15,-32768,-32768,   314,-32768,   316,
   318,   320,   322,   324,   326,   328,-32768,-32768,-32768,-32768,
   198,   369,-32768,-32768,   370,   371,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,   372,-32768,   373,-32768,-32768,-32768,-32768,
-32768,   343,   374,-32768,   379,   380,-32768
};

static const short yypgoto[] = {   133,
-32768,-32768,-32768,    -3,   249,-32768,-32768,-32768,   261,-32768,
-32768,-32768,   315,  -144,-32768,   107,   128,  -150,-32768,   168,
   337,   -60,   278,   -38,-32768,   338,   189,-32768,-32768,-32768,
-32768,  -139,   -12,   -55,   -86,  -182,   244,-32768,-32768,-32768,
-32768,-32768,   -20,   162,  -189,-32768,  -122,-32768,   -54,-32768,
-32768,   173,-32768,   179,  -160,  -178,   183,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,   -87,  -131,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,    87,-32768,-32768,-32768,-32768,-32768,
  -180,  -225,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,  -267
};


#define	YYLAST		392


static const short yytable[] = {    93,
    99,   134,   140,   134,   189,   172,    24,   183,   172,    77,
   123,   248,   287,   199,   251,   203,   257,   133,     1,   142,
   317,   178,   230,   102,   143,   287,    73,     4,   259,   103,
   142,   209,   259,   142,    74,   143,   116,   213,   143,    75,
   104,   204,   205,   206,   117,   279,   280,   142,   335,   146,
   134,   281,   143,   134,   222,   230,   272,   210,   207,   181,
   146,   142,   145,   214,   276,   256,   143,   108,   282,   283,
   284,   285,   263,   211,   208,   265,   212,   146,   267,   294,
     7,   109,   287,   294,   215,   216,   110,   275,    93,    99,
   145,   146,   147,    43,    79,    44,     9,    11,   308,   -12,
   -12,   172,    80,   233,   134,   248,   103,   247,    10,    81,
   293,   304,   192,    48,   193,   194,   295,   104,   142,   296,
   134,    93,    99,   143,   134,   198,   195,    93,    25,   299,
   299,   336,   345,   248,    40,     6,   160,   237,   142,   237,
   123,   199,   324,   143,   144,    41,   134,   145,   146,   147,
    93,    99,    93,    99,   142,    58,   322,   252,   -35,   143,
    93,    64,   142,    65,   288,   113,   114,   143,   146,   142,
   217,   134,   -35,   172,   143,   134,   218,   -35,    42,   219,
   225,   226,   237,   227,   146,    60,   305,   134,   234,   280,
    83,    91,   146,  -157,   281,   237,   107,   220,    84,  -157,
    92,   247,   343,   218,    85,    68,   219,    69,    26,    27,
  -157,   282,   283,   284,   285,   111,    93,    43,   134,    44,
    45,    46,   112,   237,    47,    87,   121,  -142,   133,   247,
   122,    68,    89,    69,  -149,   122,    68,    48,    69,   166,
    49,   167,   115,    50,   120,    51,   124,    93,    52,    65,
   118,   126,   237,   151,   152,    53,    54,   133,   171,    55,
   311,   312,   313,   314,   315,    93,    99,   309,   309,   309,
   309,   309,   309,    23,   133,   173,   176,   221,   235,   236,
   127,    13,    14,    15,    16,    17,    18,    19,    20,    21,
   250,   286,   250,   290,   182,   298,   128,   328,   328,   328,
   328,   328,   328,    13,    14,    15,    16,    17,    18,    19,
    20,    21,   182,   300,   302,   323,   250,   326,   302,   327,
   302,   329,   302,   330,   302,   331,   302,   332,   302,   333,
   302,   334,   130,   200,   202,   132,   139,   141,   148,   159,
   158,   160,   176,   179,   180,   182,   190,   197,   224,   228,
   149,   231,   232,   246,   250,   255,   254,   261,   264,   271,
   291,   273,   278,   289,   297,   302,   153,   306,   307,   318,
   319,   320,   337,   338,   339,   340,   341,   344,   346,   347,
   119,   292,    71,   154,   253,    78,   175,   270,   266,   262,
   260,   325
};

static const short yycheck[] = {    55,
    55,    88,    90,    90,   149,   137,    10,   147,   140,    48,
    71,   194,   238,   164,   195,     4,   206,     3,     3,     7,
   288,   144,   183,     3,    12,   251,     1,    27,   207,     9,
     7,     4,   211,     7,     9,    12,     1,     4,    12,    14,
    20,    30,    31,    32,     9,    33,    34,     7,   316,    37,
   137,    39,    12,   140,   177,   216,    33,    30,    47,   146,
    37,     7,    36,    30,    50,   205,    12,     4,    56,    57,
    58,    59,   212,    46,    63,   215,    49,    37,   223,   258,
     3,    18,   308,   262,    51,    52,    23,   232,   144,   144,
    36,    37,    38,    22,     1,    24,    28,     1,   279,     3,
     4,   233,     9,   191,   191,   288,     9,   194,    40,    16,
   255,   272,    41,    42,    43,    44,   261,    20,     7,   264,
   207,   177,   177,    12,   211,     8,    55,   183,     4,   269,
   270,   321,     0,   316,     4,     3,    19,   193,     7,   195,
   201,   292,   303,    12,    33,     4,   233,    36,    37,    38,
   206,   206,   208,   208,     7,     1,   301,   196,     4,    12,
   216,     1,     7,     3,    33,     8,     9,    12,    37,     7,
     4,   258,    18,   305,    12,   262,    10,    23,     4,    13,
    33,    34,   238,    36,    37,     9,   274,   274,   192,    34,
     1,     1,    37,     3,    39,   251,     4,     4,     9,     9,
     3,   288,   342,    10,    15,     9,    13,    11,     3,     4,
    20,    56,    57,    58,    59,     4,   272,    22,   305,    24,
    25,    26,     4,   279,    29,     1,     4,     3,     3,   316,
     8,     9,     1,    11,     3,     8,     9,    42,    11,     9,
    45,    11,     4,    48,     4,    50,     4,   303,    53,     3,
     4,     4,   308,     3,     4,    60,    61,     3,     4,    64,
   281,   282,   283,   284,   285,   321,   321,   280,   281,   282,
   283,   284,   285,     1,     3,     4,     3,     4,     3,     4,
     4,     9,    10,    11,    12,    13,    14,    15,    16,    17,
     3,     4,     3,     4,     3,     4,     4,   310,   311,   312,
   313,   314,   315,     9,    10,    11,    12,    13,    14,    15,
    16,    17,     3,     4,     3,     4,     3,     4,     3,     4,
     3,     4,     3,     4,     3,     4,     3,     4,     3,     4,
     3,     4,     4,   166,   167,     4,     4,     4,     4,     4,
    11,    19,     3,     3,     3,     3,    30,     4,     4,     3,
   102,     4,     3,     3,     3,     3,    11,     3,     3,     3,
   254,     4,     4,     4,     4,     3,   106,     4,     4,     4,
     4,     4,     4,     4,     4,     4,     4,     4,     0,     0,
    66,   254,    46,   106,   196,    48,   143,   226,   216,   211,
   208,   305
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
#line 1601 "grammar.cc"

  switch (yyn) {

case 5:
#line 106 "ppddl.y"
{
          log_error((char*)"syntax error in domain");
          yyerrok;
      ;
    break;}
case 13:
#line 123 "ppddl.y"
{ domain_name_ = yyvsp[-1].sym->text; ;
    break;}
case 14:
#line 129 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 15:
#line 130 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 16:
#line 131 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 17:
#line 132 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 18:
#line 133 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 19:
#line 134 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 20:
#line 135 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 21:
#line 136 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 22:
#line 137 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 23:
#line 141 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 24:
#line 142 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 25:
#line 146 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 26:
#line 147 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 27:
#line 151 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 28:
#line 152 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 29:
#line 156 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 30:
#line 157 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 32:
#line 164 "ppddl.y"
{
          log_error((char*)"syntax error in requirements declaration.");
          yyerrok;
      ;
    break;}
case 33:
#line 171 "ppddl.y"
{ declare_multivalued_variable_translation(); ;
    break;}
case 37:
#line 180 "ppddl.y"
{
          log_error((char*)"syntax error in (:predicates ...)");
          yyerrok;
      ;
    break;}
case 40:
#line 192 "ppddl.y"
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
#line 200 "ppddl.y"
{
          log_error((char*)"syntax error in predicate declaration");
          yyerrok;
      ;
    break;}
case 43:
#line 208 "ppddl.y"
{
          // must reverse parameter list
          var_symbol_vec tmp_list(*yyvsp[0].vparam);
          yyvsp[0].vparam->clear();
          yyvsp[0].vparam->insert(yyvsp[0].vparam->end(), tmp_list.rbegin(), tmp_list.rend());
          yyval.vparam = yyvsp[0].vparam;
      ;
    break;}
case 44:
#line 215 "ppddl.y"
{ yyval.vparam = new var_symbol_vec; ;
    break;}
case 45:
#line 219 "ppddl.y"
{
          set_variable_type(*yyvsp[0].vparam, yyvsp[0].vparam->size(), dom_top_type_);
          yyval.vparam = yyvsp[0].vparam;
      ;
    break;}
case 46:
#line 226 "ppddl.y"
{
          set_variable_type(*yyvsp[-3].vparam, yyvsp[-3].vparam->size(), static_cast<TypeSymbol*>(yyvsp[-1].sym->val));
          yyvsp[0].vparam->insert(yyvsp[0].vparam->end(), yyvsp[-3].vparam->rbegin(), yyvsp[-3].vparam->rend());
          delete yyvsp[-3].vparam;
          yyval.vparam = yyvsp[0].vparam;
      ;
    break;}
case 47:
#line 232 "ppddl.y"
{
          set_variable_type(*yyvsp[-2].vparam, yyvsp[-2].vparam->size(), static_cast<TypeSymbol*>(yyvsp[0].sym->val));
          yyval.vparam = yyvsp[-2].vparam;
      ;
    break;}
case 48:
#line 239 "ppddl.y"
{
          yyvsp[-1].vparam->push_back(static_cast<VariableSymbol*>(yyvsp[0].vsym));
          yyval.vparam = yyvsp[-1].vparam;
      ;
    break;}
case 49:
#line 243 "ppddl.y"
{ yyval.vparam = new var_symbol_vec; yyval.vparam->push_back(yyvsp[0].vsym); ;
    break;}
case 50:
#line 247 "ppddl.y"
{
          VariableSymbol *var = new VariableSymbol(yyvsp[0].sym->text);
          yyvsp[0].sym->val = var;
          yyval.vsym = var;
      ;
    break;}
case 52:
#line 258 "ppddl.y"
{
          set_type_type(dom_types_, dom_types_.size(), dom_top_type_);
      ;
    break;}
case 53:
#line 264 "ppddl.y"
{
          set_type_type(dom_types_, dom_types_.size(), static_cast<TypeSymbol*>(yyvsp[-1].sym->val));
      ;
    break;}
case 54:
#line 267 "ppddl.y"
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
#line 280 "ppddl.y"
{ ;
    break;}
case 59:
#line 285 "ppddl.y"
{
          yyvsp[0].sym->val = new TypeSymbol(yyvsp[0].sym->text);
          dom_types_.push_back(static_cast<TypeSymbol*>(yyvsp[0].sym->val));
      ;
    break;}
case 64:
#line 301 "ppddl.y"
{
          set_constant_type(dom_constants_, dom_constants_.size(), static_cast<TypeSymbol*>(yyvsp[0].sym->val));
      ;
    break;}
case 67:
#line 309 "ppddl.y"
{
          set_constant_type(dom_constants_, dom_constants_.size(), dom_top_type_);
      ;
    break;}
case 68:
#line 315 "ppddl.y"
{
          yyvsp[0].sym->val = new Symbol(yyvsp[0].sym->text);
          dom_constants_.push_back(static_cast<Symbol*>(yyvsp[0].sym->val));
      ;
    break;}
case 69:
#line 319 "ppddl.y"
{
          yyvsp[0].sym->val = new Symbol(yyvsp[0].sym->text);
          dom_constants_.push_back(static_cast<Symbol*>(yyvsp[0].sym->val));
      ;
    break;}
case 71:
#line 329 "ppddl.y"
{
          if( type_ == replanner ) {
              log_error((char*)"':axiom' is not a valid element in k-replanner.");
              yyerrok;
          }
      ;
    break;}
case 72:
#line 335 "ppddl.y"
{
          if( type_ == cp2fsc ) {
              log_error((char*)"':sensor' is not a valid element in cp2fsc.");
              yyerrok;
          }
      ;
    break;}
case 73:
#line 341 "ppddl.y"
{
          if( type_ == replanner ) {
              log_error((char*)"':observable' is not a valid element in k-replanner.");
              yyerrok;
          }
      ;
    break;}
case 74:
#line 347 "ppddl.y"
{
          if( type_ == replanner ) {
              log_error((char*)"':sticky' is not a valid element in k-replanner.");
              yyerrok;
          }
      ;
    break;}
case 75:
#line 353 "ppddl.y"
{
          //declare_multivalued_variable_translation();
          if( type_ == cp2fsc ) {
              log_error((char*)"':sensor' is not a valid element in cp2fsc.");
              yyerrok;
          }
      ;
    break;}
case 76:
#line 365 "ppddl.y"
{
          Action *na = new Action(yyvsp[0].sym->text);
          dom_actions_.push_back(na);
      ;
    break;}
case 77:
#line 369 "ppddl.y"
{
          clear_param(dom_actions_.back()->param_);
          yyvsp[-3].sym->val = dom_actions_.back();
      ;
    break;}
case 78:
#line 373 "ppddl.y"
{
          log_error((char*)"syntax error in action declaration");
          yyerrok;
      ;
    break;}
case 79:
#line 380 "ppddl.y"
{
          dom_actions_.back()->param_ = *yyvsp[-1].vparam;
          delete yyvsp[-1].vparam;
      ;
    break;}
case 80:
#line 384 "ppddl.y"
{ dom_actions_.back()->precondition_ = yyvsp[0].condition; ;
    break;}
case 81:
#line 385 "ppddl.y"
{ dom_actions_.back()->effect_ = yyvsp[0].effect; ;
    break;}
case 82:
#line 386 "ppddl.y"
{
          declare_clg_translation();
          dom_actions_.back()->observe_ = new AndEffect(*yyvsp[0].effect_vec);
          delete yyvsp[0].effect_vec;
      ;
    break;}
case 83:
#line 391 "ppddl.y"
{
          declare_multivalued_variable_translation();
          dom_actions_.back()->sensing_model_ = yyvsp[0].effect;
      ;
    break;}
case 89:
#line 406 "ppddl.y"
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
#line 422 "ppddl.y"
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
#line 434 "ppddl.y"
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
#line 446 "ppddl.y"
{
          const_cast<Literal*>(static_cast<const Literal*>(yyvsp[-1].atom))->negated_ = true;
          yyval.atom = yyvsp[-1].atom;
      ;
    break;}
case 95:
#line 453 "ppddl.y"
{
          if( yyvsp[0].sym->val == 0 )
              log_error((char*)"undeclared variable in atom args list");
          else
              yyvsp[-1].param->push_back(static_cast<VariableSymbol*>(yyvsp[0].sym->val));
          yyval.param = yyvsp[-1].param;
      ;
    break;}
case 96:
#line 460 "ppddl.y"
{
          yyvsp[-1].param->push_back(static_cast<Symbol*>(yyvsp[0].sym->val));
          yyval.param = yyvsp[-1].param;
      ;
    break;}
case 97:
#line 464 "ppddl.y"
{ yyval.param = new PDDL_Base::symbol_vec; ;
    break;}
case 98:
#line 468 "ppddl.y"
{
          yyval.condition = new And(*yyvsp[-1].condition_vec);
          delete yyvsp[-1].condition_vec;
      ;
    break;}
case 99:
#line 475 "ppddl.y"
{
          yyval.condition = new Or(*yyvsp[-1].condition_vec);
          delete yyvsp[-1].condition_vec;
      ;
    break;}
case 100:
#line 482 "ppddl.y"
{
          forall_conditions.push_back(new ForallCondition);
      ;
    break;}
case 101:
#line 485 "ppddl.y"
{
          forall_conditions.back()->param_ = *yyvsp[-1].vparam;
          delete yyvsp[-1].vparam;
      ;
    break;}
case 102:
#line 489 "ppddl.y"
{
          forall_conditions.back()->condition_ = yyvsp[-1].condition;
          clear_param(forall_conditions.back()->param_);
          yyval.condition = forall_conditions.back();
          forall_conditions.pop_back();
      ;
    break;}
case 103:
#line 498 "ppddl.y"
{
          yyvsp[-1].condition_vec->push_back(yyvsp[0].condition);
          yyval.condition_vec = yyvsp[-1].condition_vec;
      ;
    break;}
case 104:
#line 502 "ppddl.y"
{
          condition_vec *cond_vec = new condition_vec;
          cond_vec->push_back(yyvsp[0].condition);
          yyval.condition_vec = cond_vec;
      ;
    break;}
case 105:
#line 510 "ppddl.y"
{
          yyvsp[-1].condition_vec->push_back(yyvsp[0].condition);
          yyval.condition_vec = yyvsp[-1].condition_vec;
      ;
    break;}
case 106:
#line 514 "ppddl.y"
{
          condition_vec *cond_vec = new condition_vec;
          cond_vec->push_back(yyvsp[0].condition);
          yyval.condition_vec = cond_vec;
      ;
    break;}
case 108:
#line 523 "ppddl.y"
{
          yyval.effect = new AndEffect(*yyvsp[-1].effect_vec);
          delete yyvsp[-1].effect_vec;
      ;
    break;}
case 109:
#line 530 "ppddl.y"
{
          yyvsp[-1].effect_vec->push_back(yyvsp[0].effect);
          yyval.effect_vec = yyvsp[-1].effect_vec;
      ;
    break;}
case 110:
#line 534 "ppddl.y"
{
          yyval.effect_vec = new effect_vec;
          yyval.effect_vec->push_back(yyvsp[0].effect);
      ;
    break;}
case 114:
#line 547 "ppddl.y"
{ yyval.effect = new ConditionalEffect(yyvsp[-2].condition, yyvsp[-1].effect); ;
    break;}
case 115:
#line 551 "ppddl.y"
{
          forall_effects.push_back(new ForallEffect);
      ;
    break;}
case 116:
#line 554 "ppddl.y"
{
          forall_effects.back()->param_ = *yyvsp[-1].vparam;
          delete yyvsp[-1].vparam;
      ;
    break;}
case 117:
#line 558 "ppddl.y"
{
          forall_effects.back()->effect_ = yyvsp[-1].effect;
          clear_param(forall_effects.back()->param_);
          yyval.effect = forall_effects.back();
          forall_effects.pop_back();
      ;
    break;}
case 118:
#line 567 "ppddl.y"
{
          yyval.effect = new AndEffect(*yyvsp[-1].effect_vec);
          delete yyvsp[-1].effect_vec;
      ;
    break;}
case 120:
#line 575 "ppddl.y"
{
          yyvsp[-1].effect_vec->push_back(yyvsp[0].effect);
          yyval.effect_vec = yyvsp[-1].effect_vec;
      ;
    break;}
case 121:
#line 579 "ppddl.y"
{
          yyval.effect_vec = new effect_vec;
          yyval.effect_vec->push_back(yyvsp[0].effect);
      ;
    break;}
case 122:
#line 586 "ppddl.y"
{
          yyvsp[-1].effect_vec->push_back(yyvsp[0].effect);
          yyval.effect_vec = yyvsp[-1].effect_vec;
      ;
    break;}
case 123:
#line 590 "ppddl.y"
{
          yyval.effect_vec = new effect_vec;
          yyval.effect_vec->push_back(yyvsp[0].effect);
      ;
    break;}
case 124:
#line 597 "ppddl.y"
{ yyval.effect = new AtomicEffect(*yyvsp[0].atom); delete yyvsp[0].atom; ;
    break;}
case 125:
#line 601 "ppddl.y"
{ yyval.effect = new AtomicEffect(*yyvsp[0].atom); delete yyvsp[0].atom; ;
    break;}
case 127:
#line 606 "ppddl.y"
{ yyval.effect = 0; ;
    break;}
case 128:
#line 610 "ppddl.y"
{
          Axiom *nr = new Axiom(yyvsp[0].sym->text);
          dom_axioms_.push_back(nr);
      ;
    break;}
case 129:
#line 614 "ppddl.y"
{
          clear_param(dom_axioms_.back()->param_);
          yyvsp[-3].sym->val = dom_axioms_.back();
      ;
    break;}
case 130:
#line 618 "ppddl.y"
{
          log_error((char*)"syntax error in axiom declaration");
          yyerrok;
      ;
    break;}
case 131:
#line 625 "ppddl.y"
{
          dom_axioms_.back()->param_ = *yyvsp[-1].vparam;
          delete yyvsp[-1].vparam;
      ;
    break;}
case 132:
#line 629 "ppddl.y"
{ dom_axioms_.back()->body_ = yyvsp[0].condition; ;
    break;}
case 133:
#line 630 "ppddl.y"
{ dom_axioms_.back()->head_ = yyvsp[0].effect; ;
    break;}
case 135:
#line 635 "ppddl.y"
{
          Sensor *nr = new Sensor(yyvsp[0].sym->text);
          dom_sensors_.push_back(nr);
      ;
    break;}
case 136:
#line 639 "ppddl.y"
{
          clear_param(dom_sensors_.back()->param_);
          yyvsp[-3].sym->val = dom_sensors_.back();
      ;
    break;}
case 137:
#line 643 "ppddl.y"
{
          log_error((char*)"syntax error in sensor declaration");
          yyerrok;
      ;
    break;}
case 138:
#line 650 "ppddl.y"
{
          dom_sensors_.back()->param_ = *yyvsp[-1].vparam;
          delete yyvsp[-1].vparam;
      ;
    break;}
case 139:
#line 654 "ppddl.y"
{
          dom_sensors_.back()->condition_ = yyvsp[0].condition;
      ;
    break;}
case 140:
#line 657 "ppddl.y"
{
          dom_sensors_.back()->sense_ = new AndEffect(*yyvsp[0].effect_vec);
          delete yyvsp[0].effect_vec;
      ;
    break;}
case 142:
#line 665 "ppddl.y"
{
          Observable *obs = new Observable;
          dom_observables_.push_back(obs);
          tmp_effect_vec_ptr_ = &obs->observables_;
      ;
    break;}
case 144:
#line 671 "ppddl.y"
{
          log_error((char*)"syntax error in observable declaration");
          yyerrok;
      ;
    break;}
case 145:
#line 678 "ppddl.y"
{
          tmp_effect_vec_ptr_->push_back(yyvsp[0].effect);
      ;
    break;}
case 146:
#line 681 "ppddl.y"
{
          tmp_effect_vec_ptr_->push_back(yyvsp[0].effect);
      ;
    break;}
case 149:
#line 692 "ppddl.y"
{
          Sticky *sticky = new Sticky;
          dom_stickies_.push_back(sticky);
          tmp_effect_vec_ptr_ = &sticky->stickies_;
      ;
    break;}
case 151:
#line 698 "ppddl.y"
{
          log_error((char*)"syntax error in sticky declaration");
          yyerrok;
      ;
    break;}
case 152:
#line 705 "ppddl.y"
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
case 153:
#line 714 "ppddl.y"
{
          yyvsp[-5].sym->val = multivalued_variables_.back();
      ;
    break;}
case 154:
#line 717 "ppddl.y"
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
case 155:
#line 728 "ppddl.y"
{
          clear_param(multivalued_variables_.back()->param_);
          yyvsp[-6].sym->val = multivalued_variables_.back();
      ;
    break;}
case 156:
#line 732 "ppddl.y"
{
          log_error((char*)"syntax error in state variable declaration");
          yyerrok;
      ;
    break;}
case 157:
#line 739 "ppddl.y"
{ yyval.ival = 0; ;
    break;}
case 158:
#line 740 "ppddl.y"
{ yyval.ival = 1; ;
    break;}
case 159:
#line 744 "ppddl.y"
{
          multivalued_variables_.back()->param_ = *yyvsp[-1].vparam;
          delete yyvsp[-1].vparam;
      ;
    break;}
case 161:
#line 752 "ppddl.y"
{
          assert(dynamic_cast<StateVariable*>(multivalued_variables_.back()) != 0);
          dynamic_cast<StateVariable*>(multivalued_variables_.back())->is_observable_ = true;
      ;
    break;}
case 163:
#line 762 "ppddl.y"
{
          declare_multivalued_variable_translation();
          default_sensing_model_ = yyvsp[-1].effect;
      ;
    break;}
case 164:
#line 772 "ppddl.y"
{
          problem_name_ = yyvsp[-1].sym->text;
      ;
    break;}
case 166:
#line 776 "ppddl.y"
{
          log_error((char*)"syntax error in problem definition.");
          yyerrok;
      ;
    break;}
case 175:
#line 794 "ppddl.y"
{ dom_init_ = *yyvsp[-1].ilist; delete yyvsp[-1].ilist; ;
    break;}
case 176:
#line 795 "ppddl.y"
{ dom_init_ = *yyvsp[-2].ilist; delete yyvsp[-2].ilist; ;
    break;}
case 177:
#line 799 "ppddl.y"
{
          init_element_vec *ilist = const_cast<init_element_vec*>(yyvsp[-1].ilist);
          ilist->push_back(const_cast<InitElement*>(yyvsp[0].ielem));
          yyval.ilist = ilist;
      ;
    break;}
case 178:
#line 804 "ppddl.y"
{
          init_element_vec *ilist = new init_element_vec;
          ilist->push_back(const_cast<InitElement*>(yyvsp[0].ielem));
          yyval.ilist = ilist;
      ;
    break;}
case 179:
#line 812 "ppddl.y"
{ yyval.ielem = new InitLiteral(*yyvsp[0].atom); ;
    break;}
case 180:
#line 813 "ppddl.y"
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
case 181:
#line 824 "ppddl.y"
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
case 182:
#line 835 "ppddl.y"
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
case 183:
#line 849 "ppddl.y"
{
          //$$ = new Invariant(Invariant::AT_LEAST_ONE, *static_cast<const And*>($3));
          yyval.invariant = new Invariant(Invariant::AT_LEAST_ONE, *yyvsp[-1].condition_vec);
          delete yyvsp[-1].condition_vec;
      ;
    break;}
case 184:
#line 854 "ppddl.y"
{
          //$$ = new Invariant(Invariant::AT_LEAST_ONE, *static_cast<const And*>($3));
          yyval.invariant = new Invariant(Invariant::AT_LEAST_ONE, *yyvsp[-1].condition_vec);
          delete yyvsp[-1].condition_vec;
      ;
    break;}
case 185:
#line 862 "ppddl.y"
{
          //$$ = new Invariant(Invariant::AT_MOST_ONE, *static_cast<const And*>($3));
          yyval.invariant = new Invariant(Invariant::AT_MOST_ONE, *yyvsp[-1].condition_vec);
          delete yyvsp[-1].condition_vec;
      ;
    break;}
case 186:
#line 870 "ppddl.y"
{
          yyval.invariant = new Invariant(Invariant::EXACTLY_ONE, *yyvsp[-1].condition_vec);
          delete yyvsp[-1].condition_vec;
      ;
    break;}
case 190:
#line 883 "ppddl.y"
{
          yyval.clause = new Clause(*yyvsp[-1].condition_vec);
          delete yyvsp[-1].condition_vec;
      ;
    break;}
case 191:
#line 890 "ppddl.y"
{
          yyval.oneof = new Oneof(*yyvsp[-1].condition_vec);
          delete yyvsp[-1].condition_vec;
      ;
    break;}
case 192:
#line 897 "ppddl.y"
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
case 193:
#line 909 "ppddl.y"
{ dom_goal_ = yyvsp[-1].condition; ;
    break;}
case 194:
#line 910 "ppddl.y"
{ dom_goal_ = yyvsp[-2].condition; ;
    break;}
case 195:
#line 914 "ppddl.y"
{
          const_cast<And*>(static_cast<const And*>(yyvsp[-1].condition))->push_back(yyvsp[0].condition);
          yyval.condition = yyvsp[-1].condition;
      ;
    break;}
case 196:
#line 918 "ppddl.y"
{
          And *cond = new And;
          cond->push_back(yyvsp[0].condition);
          yyval.condition = cond;
      ;
    break;}
case 197:
#line 927 "ppddl.y"
{ yyval.condition = new Literal(*yyvsp[0].atom); delete yyvsp[0].atom; ;
    break;}
case 198:
#line 928 "ppddl.y"
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
#line 2728 "grammar.cc"
#line 931 "ppddl.y"


