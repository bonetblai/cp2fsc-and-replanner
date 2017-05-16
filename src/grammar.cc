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
#line 85 "grammar_tmp.cc"
#define YY_PDDL_Parser_ERROR  log_error
#define YY_PDDL_Parser_ERROR_BODY  = 0
#define YY_PDDL_Parser_ERROR_VERBOSE  1
#define YY_PDDL_Parser_LEX  next_token
#define YY_PDDL_Parser_LEX_BODY  = 0
#define YY_PDDL_Parser_DEBUG  1
#define YY_PDDL_Parser_INHERIT  : public PDDL_Base
#define YY_PDDL_Parser_CONSTRUCTOR_PARAM  StringTable &parser_symbol_table, int type, const Options::Mode &options
#define YY_PDDL_Parser_CONSTRUCTOR_INIT  : PDDL_Base(parser_symbol_table, options), error_flag_(false), type_(type), effect_vec_ptr_(0)
#define YY_PDDL_Parser_MEMBERS  \
  public: \
    typedef enum { replanner, cp2fsc, lw1 } Type; \
    virtual ~PDDL_Parser() { } \
    virtual std::ostream& syntax_errors() = 0; \
    bool error_flag_; \
    int type_; \
  private: \
    std::vector<Schema*> schema_; \
    std::vector<std::unique_ptr<Schema> > owned_schema_; \
    std::vector<bool> using_owned_schema_; \
    effect_vec *effect_vec_ptr_;
#line 43 "ppddl.y"

#include <stdlib.h>
#include <string.h>
#include <list>
#include <string>
#include "base.h"
#include "utils.h"

#pragma GCC diagnostic ignored "-Wpragmas"
#pragma GCC diagnostic ignored "-Wchar-subscripts"
#pragma GCC diagnostic ignored "-Wc++11-compat-deprecated-writable-strings"
//#pragma GCC diagnostic ignored "-Wdeprecated-writable-strings"
//#pragma GCC diagnostic ignored "-Wwrite-strings"
//#pragma GCC diagnostic ignored "-Wuninitialized"
//#pragma GCC diagnostic ignored "-Wsign-compare"

#line 60 "ppddl.y"
typedef union {
    StringTable::Cell                         *sym;
    PDDL_Base::VariableSymbol                 *vsym;
    PDDL_Base::Atom                           *atom;
    PDDL_Base::symbol_vec                     *param;
    PDDL_Base::var_symbol_vec                 *vparam;
    PDDL_Base::condition_vec                  *condition_vec;
    PDDL_Base::effect_vec                     *effect_vec;
    const PDDL_Base::Condition                *condition;
    const PDDL_Base::Effect                   *effect;
    const PDDL_Base::Invariant                *invariant;
    const PDDL_Base::Clause                   *clause;
    const PDDL_Base::Oneof                    *oneof;
    const PDDL_Base::Unknown                  *unknown;
#ifdef SMART
    const PDDL_Base::owned_init_element_vec         *ilist;
#else
    const PDDL_Base::init_element_vec         *ilist;
#endif
    const PDDL_Base::InitElement              *ielem;
    const PDDL_Base::SensingModel             *sensing_model;
    const PDDL_Base::SensingProxy             *sensing_proxy;
    const PDDL_Base::sensing_proxy_vec        *sensing_proxy_list;
    const PDDL_Base::StateVariableList        *state_variable_list;
    const PDDL_Base::state_variable_list_vec  *state_variable_list_vec;
    int                                       ival;
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
#line 201 "grammar_tmp.cc"

#line 117 "/usr/local/lib/bison.cc"
/*  YY_PDDL_Parser_PURE */
#endif

/* section apres lecture def, avant lecture grammaire S2 */

/* #line 121 "/usr/local/lib/bison.cc" */
#line 210 "grammar_tmp.cc"

#line 121 "/usr/local/lib/bison.cc"
/* prefix */
#ifndef YY_PDDL_Parser_DEBUG

/* #line 123 "/usr/local/lib/bison.cc" */
#line 217 "grammar_tmp.cc"

#line 123 "/usr/local/lib/bison.cc"
/* YY_PDDL_Parser_DEBUG */
#endif


#ifndef YY_PDDL_Parser_LSP_NEEDED

/* #line 128 "/usr/local/lib/bison.cc" */
#line 227 "grammar_tmp.cc"

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
#line 340 "grammar_tmp.cc"
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
#define	KW_EXPLICIT_INITIAL_STATE	304
#define	KW_SENSOR	305
#define	KW_SENSE	306
#define	KW_OBSERVE	307
#define	KW_AXIOM	308
#define	KW_COND	309
#define	KW_OBSERVABLE	310
#define	KW_BODY	311
#define	KW_HEAD	312
#define	KW_STICKY	313
#define	KW_FLUENTS	314
#define	KW_HIDDEN	315
#define	KW_INVARIANT	316
#define	KW_AT_LEAST_ONE	317
#define	KW_AT_MOST_ONE	318
#define	KW_EXACTLY_ONE	319
#define	KW_VARIABLE	320
#define	KW_OBS_VARIABLE	321
#define	KW_VGROUP	322
#define	KW_SENSING	323
#define	KW_DEFAULT_SENSING	324
#define	KW_MODEL_FOR	325


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
#line 458 "grammar_tmp.cc"
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
static const int KW_EXPLICIT_INITIAL_STATE;
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
static const int KW_VGROUP;
static const int KW_SENSING;
static const int KW_DEFAULT_SENSING;
static const int KW_MODEL_FOR;


#line 280 "/usr/local/lib/bison.cc"
 /* decl const */
#else
enum YY_PDDL_Parser_ENUM_TOKEN { YY_PDDL_Parser_NULL_TOKEN=0

/* #line 283 "/usr/local/lib/bison.cc" */
#line 535 "grammar_tmp.cc"
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
	,KW_EXPLICIT_INITIAL_STATE=304
	,KW_SENSOR=305
	,KW_SENSE=306
	,KW_OBSERVE=307
	,KW_AXIOM=308
	,KW_COND=309
	,KW_OBSERVABLE=310
	,KW_BODY=311
	,KW_HEAD=312
	,KW_STICKY=313
	,KW_FLUENTS=314
	,KW_HIDDEN=315
	,KW_INVARIANT=316
	,KW_AT_LEAST_ONE=317
	,KW_AT_MOST_ONE=318
	,KW_EXACTLY_ONE=319
	,KW_VARIABLE=320
	,KW_OBS_VARIABLE=321
	,KW_VGROUP=322
	,KW_SENSING=323
	,KW_DEFAULT_SENSING=324
	,KW_MODEL_FOR=325


#line 283 "/usr/local/lib/bison.cc"
 /* enum token */
     }; /* end of enum declaration */
#endif
public:
 int YY_PDDL_Parser_PARSE (YY_PDDL_Parser_PARSE_PARAM);
 virtual void YY_PDDL_Parser_ERROR(const char *msg) YY_PDDL_Parser_ERROR_BODY;
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
#line 640 "grammar_tmp.cc"
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
const int YY_PDDL_Parser_CLASS::KW_EXPLICIT_INITIAL_STATE=304;
const int YY_PDDL_Parser_CLASS::KW_SENSOR=305;
const int YY_PDDL_Parser_CLASS::KW_SENSE=306;
const int YY_PDDL_Parser_CLASS::KW_OBSERVE=307;
const int YY_PDDL_Parser_CLASS::KW_AXIOM=308;
const int YY_PDDL_Parser_CLASS::KW_COND=309;
const int YY_PDDL_Parser_CLASS::KW_OBSERVABLE=310;
const int YY_PDDL_Parser_CLASS::KW_BODY=311;
const int YY_PDDL_Parser_CLASS::KW_HEAD=312;
const int YY_PDDL_Parser_CLASS::KW_STICKY=313;
const int YY_PDDL_Parser_CLASS::KW_FLUENTS=314;
const int YY_PDDL_Parser_CLASS::KW_HIDDEN=315;
const int YY_PDDL_Parser_CLASS::KW_INVARIANT=316;
const int YY_PDDL_Parser_CLASS::KW_AT_LEAST_ONE=317;
const int YY_PDDL_Parser_CLASS::KW_AT_MOST_ONE=318;
const int YY_PDDL_Parser_CLASS::KW_EXACTLY_ONE=319;
const int YY_PDDL_Parser_CLASS::KW_VARIABLE=320;
const int YY_PDDL_Parser_CLASS::KW_OBS_VARIABLE=321;
const int YY_PDDL_Parser_CLASS::KW_VGROUP=322;
const int YY_PDDL_Parser_CLASS::KW_SENSING=323;
const int YY_PDDL_Parser_CLASS::KW_DEFAULT_SENSING=324;
const int YY_PDDL_Parser_CLASS::KW_MODEL_FOR=325;


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
#line 725 "grammar_tmp.cc"


#define	YYFINAL		424
#define	YYFLAG		-32768
#define	YYNTBASE	71

#define YYTRANSLATE(x) ((unsigned)(x) <= 325 ? yytranslate[x] : 182)

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
    66,    67,    68,    69,    70
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
   208,   210,   212,   214,   216,   218,   219,   226,   231,   237,
   241,   245,   249,   253,   254,   256,   258,   260,   262,   264,
   266,   268,   270,   272,   274,   276,   281,   286,   291,   294,
   297,   298,   303,   308,   309,   310,   320,   321,   322,   332,
   335,   337,   340,   342,   344,   349,   352,   354,   356,   358,
   360,   366,   367,   368,   379,   382,   383,   388,   390,   393,
   395,   398,   400,   402,   404,   406,   407,   410,   412,   414,
   416,   417,   418,   429,   436,   446,   451,   459,   464,   469,
   470,   477,   482,   488,   492,   496,   497,   498,   505,   510,
   516,   520,   524,   525,   526,   532,   537,   540,   542,   544,
   546,   547,   553,   558,   559,   566,   567,   568,   580,   585,
   587,   589,   590,   597,   598,   599,   611,   616,   619,   622,
   623,   625,   630,   631,   632,   643,   648,   649,   659,   666,
   672,   675,   678,   681,   684,   687,   688,   692,   697,   705,
   707,   709,   712,   714,   716,   718,   720,   722,   724,   729,
   734,   739,   744,   746,   748,   750,   755,   760,   765,   770,
   774,   779,   782,   784,   786
};

static const short yyrhs[] = {    72,
    71,     0,   166,    71,     0,     0,     3,    27,    74,    73,
     4,     0,     3,    27,    74,     1,     4,     0,    73,    79,
     0,    73,    89,     0,    73,    93,     0,    73,    81,     0,
    73,    98,     0,    73,   165,     0,     0,     3,    28,    75,
     4,     0,     9,     0,    10,     0,    11,     0,    12,     0,
    13,     0,    14,     0,    15,     0,    16,     0,    17,     0,
     9,     0,    14,     0,     9,     0,    16,     0,     9,     0,
    15,     0,     3,    22,    80,     4,     0,     3,    22,     1,
     4,     0,    80,    23,     0,    80,    18,     0,     0,     3,
    25,    82,     4,     0,     3,    25,     1,     4,     0,    82,
    83,     0,    83,     0,     3,     9,    84,     4,     0,     3,
     1,     4,     0,    85,     0,    86,     0,     0,    87,     0,
    87,     8,    11,    86,     0,    87,     8,    11,     0,    88,
    87,     0,    88,     0,    19,     0,    13,     0,     3,    26,
    91,     4,     0,     3,    26,    90,     4,     0,    91,     8,
    11,    90,     0,    91,     8,     9,    90,     0,     0,    91,
    92,     0,    92,     0,    11,     0,     9,     0,     3,    24,
    94,     4,     0,     3,    46,    94,     4,     0,     3,    24,
    96,     4,     0,     3,    46,    96,     4,     0,     0,    97,
     8,    11,    95,    94,     0,     0,    97,     0,    97,     9,
     0,     9,     0,    99,     0,   139,     0,   142,     0,   145,
     0,   149,     0,   151,     0,   156,     0,     0,     3,    29,
    76,   100,   101,     4,     0,     3,    29,     1,     4,     0,
   101,    30,     3,    84,     4,     0,   101,    31,   102,     0,
   101,    32,   119,     0,   101,    52,   129,     0,   101,    68,
   132,     0,     0,   103,     0,   104,     0,   109,     0,   110,
     0,   111,     0,   114,     0,    34,     0,    35,     0,   105,
     0,   106,     0,   107,     0,     3,    12,   108,     4,     0,
     3,     7,   108,     4,     0,     3,    40,   106,     4,     0,
   108,    13,     0,   108,    10,     0,     0,     3,    33,   118,
     4,     0,     3,    36,   118,     4,     0,     0,     0,     3,
    38,     3,   112,    84,     4,   113,   102,     4,     0,     0,
     0,     3,    37,     3,   115,    84,     4,   116,   102,     4,
     0,   117,   104,     0,   104,     0,   118,   102,     0,   102,
     0,   121,     0,     3,    33,   120,     4,     0,   120,   121,
     0,   121,     0,   130,     0,   122,     0,   123,     0,     3,
    41,   102,   127,     4,     0,     0,     0,     3,    38,     3,
   124,    84,     4,   125,   126,   119,     4,     0,    39,   102,
     0,     0,     3,    33,   128,     4,     0,   130,     0,   128,
   130,     0,   130,     0,   129,   131,     0,   131,     0,   105,
     0,   106,     0,   133,     0,     0,   133,   134,     0,   134,
     0,   138,     0,   135,     0,     0,     0,     3,    38,     3,
   136,    84,     4,   137,   126,   133,     4,     0,     3,    70,
    20,   105,   102,     4,     0,     3,    70,     3,    20,   108,
     4,   105,   102,     4,     0,     3,    65,    20,     4,     0,
     3,    65,     3,    20,   108,     4,     4,     0,     3,    65,
     1,     4,     0,     3,    70,     1,     4,     0,     0,     3,
    53,    78,   140,   141,     4,     0,     3,    53,     1,     4,
     0,   141,    30,     3,    84,     4,     0,   141,    56,   102,
     0,   141,    57,   127,     0,     0,     0,     3,    50,    77,
   143,   144,     4,     0,     3,    50,     1,     4,     0,   144,
    30,     3,    84,     4,     0,   144,    54,   102,     0,   144,
    51,   129,     0,     0,     0,     3,    55,   146,   147,     4,
     0,     3,    55,     1,     4,     0,   147,   148,     0,   148,
     0,   131,     0,   123,     0,     0,     3,    58,   150,   147,
     4,     0,     3,    58,     1,     4,     0,     0,     3,   155,
     9,   152,   147,     4,     0,     0,     0,     3,   155,     3,
     9,   153,    84,     4,   154,   126,   147,     4,     0,     3,
    65,     1,     4,     0,    65,     0,    66,     0,     0,     3,
    67,     9,   157,   160,     4,     0,     0,     0,     3,    67,
     3,     9,   158,    84,     4,   159,   126,   160,     4,     0,
     3,    67,     1,     4,     0,   160,   161,     0,   160,   162,
     0,     0,    20,     0,     3,    20,   108,     4,     0,     0,
     0,     3,    38,     3,   163,    84,     4,   164,   126,   160,
     4,     0,     3,    69,   132,     4,     0,     0,     3,    27,
     3,    44,    75,     4,   167,   168,     4,     0,     3,    27,
     3,    44,     1,     4,     0,   168,     3,    45,    75,     4,
     0,   168,    79,     0,   168,    93,     0,   168,   169,     0,
   168,   180,     0,   168,   181,     0,     0,     3,   170,     4,
     0,     3,   170,   171,     4,     0,     3,   170,     3,    33,
   171,     4,     4,     0,    47,     0,    49,     0,   171,   172,
     0,   172,     0,   105,     0,   176,     0,   177,     0,   178,
     0,   179,     0,     3,    61,   117,     4,     0,     3,    62,
   117,     4,     0,     3,    63,   117,     4,     0,     3,    64,
   117,     4,     0,   173,     0,   174,     0,   175,     0,     3,
    36,   117,     4,     0,     3,    42,   117,     4,     0,     3,
    43,   106,     4,     0,     3,    60,   171,     4,     0,     3,
    60,     4,     0,     3,    48,   102,     4,     0,     0,     0,
     0,     0,     0,   106,     0,   107,     0
};

#endif

#if YY_PDDL_Parser_DEBUG != 0
static const short yyrline[] = { 0,
   147,   149,   150,   153,   155,   161,   163,   164,   165,   166,
   167,   168,   171,   177,   179,   180,   181,   182,   183,   184,
   185,   186,   189,   191,   194,   196,   199,   201,   206,   208,
   214,   216,   217,   222,   224,   230,   232,   235,   244,   250,
   252,   259,   262,   269,   276,   282,   287,   290,   296,   307,
   309,   314,   318,   326,   329,   331,   334,   336,   344,   346,
   347,   348,   351,   356,   356,   359,   365,   370,   378,   380,
   386,   392,   398,   404,   411,   417,   427,   435,   441,   446,
   447,   448,   453,   457,   460,   462,   463,   464,   465,   466,
   469,   471,   474,   485,   487,   490,   502,   513,   520,   528,
   532,   535,   542,   549,   554,   558,   569,   574,   578,   589,
   594,   601,   606,   613,   615,   621,   626,   632,   634,   635,
   638,   642,   647,   651,   662,   677,   680,   685,   688,   693,
   699,   704,   710,   714,   718,   720,   723,   729,   736,   738,
   741,   746,   750,   762,   775,   790,   796,   805,   809,   815,
   825,   833,   839,   844,   845,   846,   849,   859,   867,   873,
   878,   881,   885,   888,   900,   901,   907,   911,   916,   918,
   921,   933,   934,   940,   960,   967,   988,   996,  1017,  1023,
  1025,  1028,  1038,  1042,  1053,  1061,  1084,  1090,  1097,  1103,
  1106,  1115,  1128,  1133,  1137,  1152,  1162,  1166,  1167,  1173,
  1175,  1176,  1177,  1178,  1179,  1180,  1183,  1193,  1214,  1237,
  1239,  1242,  1253,  1265,  1269,  1280,  1291,  1302,  1312,  1318,
  1325,  1333,  1340,  1342,  1343,  1346,  1353,  1360,  1367,  1383,
  1397,  1403,  1408,  1415,  1417
};

static const char * const yytname[] = {   "$","error","$illegal.","TK_OPEN",
"TK_CLOSE","TK_OPEN_SQ","TK_CLOSE_SQ","TK_EQ","TK_HYPHEN","TK_NEW_SYMBOL","TK_OBJ_SYMBOL",
"TK_TYPE_SYMBOL","TK_PRED_SYMBOL","TK_VAR_SYMBOL","TK_ACTION_SYMBOL","TK_AXIOM_SYMBOL",
"TK_SENSOR_SYMBOL","TK_MISC_SYMBOL","TK_KEYWORD","TK_NEW_VAR_SYMBOL","TK_VARNAME_SYMBOL",
"TK_INT","KW_REQS","KW_TRANSLATION","KW_CONSTANTS","KW_PREDS","KW_TYPES","KW_DEFINE",
"KW_DOMAIN","KW_ACTION","KW_ARGS","KW_PRE","KW_EFFECT","KW_AND","KW_TRUE","KW_FALSE",
"KW_OR","KW_EXISTS","KW_FORALL","KW_SUCH_THAT","KW_NOT","KW_WHEN","KW_ONEOF",
"KW_UNKNOWN","KW_PROBLEM","KW_FORDOMAIN","KW_OBJECTS","KW_INIT","KW_GOAL","KW_EXPLICIT_INITIAL_STATE",
"KW_SENSOR","KW_SENSE","KW_OBSERVE","KW_AXIOM","KW_COND","KW_OBSERVABLE","KW_BODY",
"KW_HEAD","KW_STICKY","KW_FLUENTS","KW_HIDDEN","KW_INVARIANT","KW_AT_LEAST_ONE",
"KW_AT_MOST_ONE","KW_EXACTLY_ONE","KW_VARIABLE","KW_OBS_VARIABLE","KW_VGROUP",
"KW_SENSING","KW_DEFAULT_SENSING","KW_MODEL_FOR","pddl_decls","pddl_domain",
"domain_elements","domain_name","any_symbol","action_symbol","sensor_symbol",
"axiom_symbol","domain_requires","require_list","domain_predicates","predicate_list",
"predicate_decl","param_list","untyped_param_list","typed_param_list","param_sym_list",
"new_var_symbol","domain_types","typed_type_list","primitive_type_list","primitive_type",
"domain_constants","typed_constant_list","@1","untyped_constant_list","constant_sym_list",
"domain_schemas","action_decl","@2","action_elements","condition","constant_condition",
"single_condition","literal","positive_literal","negative_literal","argument_list",
"and_condition","or_condition","forall_condition","@3","@4","exists_condition",
"@5","@6","single_condition_list","condition_list","action_effect","action_effect_list",
"single_action_effect","conditional_effect","forall_effect","@7","@8","optional_such_that",
"atomic_effect_kw_list","atomic_effect_list","positive_atomic_effect_list","atomic_effect",
"positive_atomic_effect","sensing","sensing_decl_list","sensing_decl","forall_sensing",
"@9","@10","sensing_model","axiom_decl","@11","axiom_elements","sensor_decl",
"@12","sensor_elements","observable_decl","@13","fluent_list_decl","fluent_decl",
"sticky_decl","@14","simple_variable_decl","@15","@16","@17","variable_type",
"variable_group_decl","@18","@19","@20","state_variable_list_decl","state_variable",
"forall_state_variable_list_decl","@21","@22","domain_default_sensing","pddl_problem",
"@23","problem_elements","initial_state","initial_state_keyword","init_elements",
"single_init_element","at_least_one_invariant","at_most_one_invariant","exactly_one_invariant",
"invariant","clause","oneof","unknown","hidden_state","goal_spec","goal_list"
};
#endif

static const short yyr1[] = {     0,
    71,    71,    71,    72,    72,    73,    73,    73,    73,    73,
    73,    73,    74,    75,    75,    75,    75,    75,    75,    75,
    75,    75,    76,    76,    77,    77,    78,    78,    79,    79,
    80,    80,    80,    81,    81,    82,    82,    83,    83,    84,
    84,    84,    85,    86,    86,    87,    87,    88,    88,    89,
    89,    90,    90,    90,    91,    91,    92,    92,    93,    93,
    93,    93,    95,    94,    94,    96,    97,    97,    98,    98,
    98,    98,    98,    98,    98,   100,    99,    99,   101,   101,
   101,   101,   101,   101,   102,   102,   102,   102,   102,   102,
   103,   103,   104,   105,   105,   106,   106,   107,   108,   108,
   108,   109,   110,   112,   113,   111,   115,   116,   114,   117,
   117,   118,   118,   119,   119,   120,   120,   121,   121,   121,
   122,   124,   125,   123,   126,   126,   127,   127,   128,   128,
   129,   129,   130,   131,   132,   132,   133,   133,   134,   134,
   136,   137,   135,   138,   138,   138,   138,   138,   138,   140,
   139,   139,   141,   141,   141,   141,   143,   142,   142,   144,
   144,   144,   144,   146,   145,   145,   147,   147,   148,   148,
   150,   149,   149,   152,   151,   153,   154,   151,   151,   155,
   155,   157,   156,   158,   159,   156,   156,   160,   160,   160,
   161,   161,   163,   164,   162,   165,   167,   166,   166,   168,
   168,   168,   168,   168,   168,   168,   169,   169,   169,   170,
   170,   171,   171,   172,   172,   172,   172,   172,   173,   173,
   174,   175,   176,   176,   176,   177,   178,   179,   180,   180,
   181,    -1,    -1,    -1,    -1
};

static const short yyr2[] = {     0,
     2,     2,     0,     5,     5,     2,     2,     2,     2,     2,
     2,     0,     4,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     4,     4,
     2,     2,     0,     4,     4,     2,     1,     4,     3,     1,
     1,     0,     1,     4,     3,     2,     1,     1,     1,     4,
     4,     4,     4,     0,     2,     1,     1,     1,     4,     4,
     4,     4,     0,     5,     0,     1,     2,     1,     1,     1,
     1,     1,     1,     1,     1,     0,     6,     4,     5,     3,
     3,     3,     3,     0,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     4,     4,     4,     2,     2,
     0,     4,     4,     0,     0,     9,     0,     0,     9,     2,
     1,     2,     1,     1,     4,     2,     1,     1,     1,     1,
     5,     0,     0,    10,     2,     0,     4,     1,     2,     1,
     2,     1,     1,     1,     1,     0,     2,     1,     1,     1,
     0,     0,    10,     6,     9,     4,     7,     4,     4,     0,
     6,     4,     5,     3,     3,     0,     0,     6,     4,     5,
     3,     3,     0,     0,     5,     4,     2,     1,     1,     1,
     0,     5,     4,     0,     6,     0,     0,    11,     4,     1,
     1,     0,     6,     0,     0,    11,     4,     2,     2,     0,
     1,     4,     0,     0,    10,     4,     0,     9,     6,     5,
     2,     2,     2,     2,     2,     0,     3,     4,     7,     1,
     1,     2,     1,     1,     1,     1,     1,     1,     4,     4,
     4,     4,     1,     1,     1,     4,     4,     4,     4,     3,
     4,     2,     1,     1,     1
};

static const short yydefact[] = {     3,
     0,     3,     3,     0,     1,     2,     0,     0,     0,     0,
     0,     0,    14,    15,    16,    17,    18,    19,    20,    21,
    22,     0,     0,     0,     5,     0,     4,     6,     9,     7,
     8,    10,    69,    70,    71,    72,    73,    74,    75,    11,
    13,   199,   197,     0,    65,     0,    54,     0,    65,     0,
     0,     0,     0,     0,   181,     0,   136,     0,   206,     0,
     0,    68,     0,     0,    66,     0,     0,     0,    37,    58,
    57,     0,     0,    56,     0,    23,    24,    76,     0,     0,
     0,    25,    26,   157,     0,    27,    28,   150,     0,     0,
     0,     0,     0,     0,     0,   182,     0,     0,   135,   138,
   140,   139,     0,   174,     0,    30,    29,    32,    31,    59,
    61,     0,    67,    35,     0,    42,    34,    36,    51,    50,
     0,    55,    78,    84,    60,    62,   159,   163,   152,   156,
   166,     0,   134,   170,   169,     0,   168,   173,     0,   179,
   187,   184,   190,     0,     0,     0,   196,   137,   176,     0,
     0,   198,   201,   202,   203,   204,   205,    63,    39,    49,
    48,     0,    40,    41,    43,    47,    54,    54,     0,     0,
     0,   101,   101,     0,   165,   167,   172,    42,     0,   141,
     0,     0,     0,     0,     0,     0,    42,     0,     0,   210,
     0,   211,     0,     0,    65,    38,     0,    46,    53,     0,
    52,    77,     0,     0,     0,     0,   136,   158,     0,     0,
     0,   151,     0,     0,     0,     0,     0,   122,     0,     0,
   183,   191,   188,   189,    42,   148,   101,   146,   149,   101,
     0,     0,    94,    95,     0,   175,     0,     0,    91,    92,
     0,    85,    86,    93,    87,    88,    89,    90,     0,   230,
   214,     0,   213,   223,   224,   225,   215,   216,   217,   218,
     0,   207,     0,    64,     0,    45,    42,    80,     0,   133,
    81,   114,   119,   120,   118,     0,    82,   132,    83,    42,
   162,   161,    42,   154,     0,   155,   128,    97,   100,    99,
    96,    42,   185,   101,     0,     0,     0,     0,     0,     0,
   177,   200,     0,     0,     0,     0,   231,     0,     0,     0,
     0,     0,     0,     0,   229,   212,     0,   208,    44,     0,
     0,     0,     0,   131,     0,     0,     0,     0,   126,     0,
   193,   142,     0,     0,     0,   144,   126,   113,     0,     0,
   107,   104,   111,     0,     0,     0,     0,     0,     0,     0,
     0,    79,     0,     0,   117,     0,   160,   153,     0,   130,
   123,     0,   190,   192,    42,   126,   147,     0,    98,     0,
   102,   112,   103,    42,    42,   226,   110,   227,   228,   219,
   220,   221,   222,     0,   115,   116,     0,   127,   129,   126,
   125,     0,     0,     0,     0,     0,     0,     0,   209,   121,
     0,   186,   194,     0,   145,   178,   108,   105,     0,   126,
   143,     0,     0,   124,   190,     0,     0,     0,   109,   106,
   195,     0,     0,     0
};

static const short yydefgoto[] = {     5,
     2,    12,     8,    22,    78,    84,    88,    28,    61,    29,
    68,    69,   162,   163,   164,   165,   166,    30,    72,   200,
    74,    31,    63,   195,    64,    65,    32,    33,   124,   169,
   338,   242,   243,   244,   233,   234,   216,   245,   246,   247,
   375,   413,   248,   374,   412,   344,   339,   271,   354,   272,
   273,   134,   292,   390,   363,   286,   359,   277,   275,   135,
    98,    99,   100,   101,   225,   366,   102,    34,   130,   171,
    35,   128,   170,    36,    90,   136,   137,    37,    92,    38,
   150,   187,   337,    58,    39,   143,   178,   329,   179,   223,
   224,   365,   410,    40,     3,    59,   105,   155,   194,   252,
   253,   254,   255,   256,   257,   258,   259,   260,   156,   157
};

static const short yypact[] = {    50,
     7,    50,    50,   110,-32768,-32768,    10,   252,   324,   300,
   123,    27,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,   148,   156,   159,-32768,   219,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,   170,   163,   122,   142,   221,   163,   197,
   317,   183,   294,    42,-32768,   320,   172,   216,-32768,   178,
   181,-32768,   191,   203,    78,   220,    87,    38,-32768,-32768,
-32768,   233,   139,-32768,   238,-32768,-32768,-32768,   259,   271,
   279,-32768,-32768,-32768,   295,-32768,-32768,-32768,   303,   319,
   316,   319,   323,   327,   342,-32768,   -15,   387,   172,-32768,
-32768,-32768,   383,-32768,   230,-32768,-32768,-32768,-32768,-32768,
-32768,   189,-32768,-32768,   389,   311,-32768,-32768,-32768,-32768,
   333,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,    99,-32768,-32768,-32768,   350,-32768,-32768,   352,-32768,
-32768,-32768,-32768,   391,   121,   211,-32768,-32768,-32768,   319,
   244,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,   392,-32768,-32768,   390,   311,   142,   142,    31,    28,
    36,-32768,-32768,   394,-32768,-32768,-32768,   311,   258,-32768,
   395,   375,   396,   397,   385,   399,   311,   354,   324,-32768,
    33,-32768,   356,   358,   163,-32768,   393,-32768,-32768,   341,
-32768,-32768,   400,    33,   403,   404,   172,-32768,   405,   404,
    33,-32768,   406,    33,   407,   236,   263,-32768,   408,    80,
-32768,-32768,-32768,-32768,   311,-32768,-32768,-32768,-32768,-32768,
    96,    33,-32768,-32768,   409,-32768,   410,   214,-32768,-32768,
   411,-32768,-32768,-32768,-32768,-32768,-32768,-32768,   154,-32768,
-32768,   360,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
   196,-32768,   362,-32768,    78,   311,   311,-32768,    32,-32768,
-32768,-32768,-32768,-32768,-32768,    77,   404,-32768,-32768,   311,
   404,-32768,   311,-32768,    57,-32768,-32768,-32768,-32768,-32768,
-32768,   311,-32768,-32768,   413,   414,   290,   292,   404,   415,
-32768,-32768,    33,    33,   417,   418,-32768,   399,   399,   404,
   399,   399,   399,   399,-32768,-32768,   419,-32768,-32768,   390,
   420,   422,    33,-32768,   423,   424,   399,   425,   398,   315,
-32768,-32768,   426,   399,   427,-32768,   398,-32768,   111,   176,
-32768,-32768,-32768,   364,   366,   428,   368,   370,   372,   374,
   376,-32768,    64,   378,-32768,   407,-32768,-32768,   380,-32768,
-32768,    33,-32768,-32768,   311,   398,-32768,    33,-32768,   319,
-32768,-32768,-32768,   311,   311,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,   429,-32768,-32768,   430,-32768,-32768,   398,
-32768,   267,   431,   172,   432,   382,   434,   435,-32768,-32768,
   403,-32768,-32768,   384,-32768,-32768,-32768,-32768,   436,   398,
-32768,    33,    33,-32768,-32768,   437,   438,   278,-32768,-32768,
-32768,   443,   444,-32768
};

static const short yypgoto[] = {   109,
-32768,-32768,-32768,     0,-32768,-32768,-32768,   306,-32768,-32768,
-32768,   349,  -173,-32768,   157,  -149,-32768,-32768,   222,   379,
   -60,   340,   -38,-32768,   401,   251,-32768,-32768,-32768,-32768,
  -185,-32768,  -180,  -178,   -90,-32768,  -152,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,    34,   143,    47,-32768,  -274,
-32768,  -196,-32768,-32768,  -309,    93,-32768,   241,  -197,  -186,
   245,    59,   -96,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,   -91,  -132,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,  -338,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,  -182,
  -230,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768
};


#define	YYLAST		453


static const short yytable[] = {   133,
   139,   133,   148,   176,   219,   241,   176,   232,   274,    24,
    79,   263,   122,   235,   251,   251,   198,   287,   268,   278,
   217,   316,   144,   278,   392,   282,   270,   370,   284,    26,
    27,   208,   316,     4,   202,   238,   270,     9,   172,   212,
    67,   117,    93,   173,  -180,   133,   300,   355,   133,   145,
  -180,   296,     1,    10,   146,   176,   394,   209,   188,   133,
   203,   204,   205,   172,   322,   213,   239,   240,   173,   174,
   172,   299,   323,   251,   297,   173,   418,   298,   210,   386,
   401,   211,   206,   172,   251,   112,   113,   115,   173,   327,
   324,   214,   215,   321,   324,   116,   299,   133,   207,   294,
   415,   174,   172,   299,   323,   172,   325,   173,   422,   326,
   173,     6,     7,   238,   371,   133,   320,   295,   328,   133,
   316,   181,    66,   182,    67,   274,    25,   343,   343,   360,
   343,   343,   343,   343,   351,   299,   174,   356,   251,   122,
   183,   330,   120,   270,   239,   240,   121,    70,   270,    71,
    70,    41,    71,   372,   372,   368,   264,   274,   287,    42,
   172,   389,    43,   377,   377,   173,   377,   377,   377,   377,
    60,    62,   251,   -33,    97,   270,   391,   270,   238,   373,
   270,   106,   395,    89,   107,  -164,   133,   -33,   237,   308,
   133,   393,   -33,   299,   110,   309,   310,    81,   108,   158,
   397,   398,   172,   109,   274,    82,   111,   173,   335,   239,
   240,   184,    83,   185,   311,   312,   313,   314,   103,   346,
   172,    75,   270,   114,   104,   173,   416,   417,   317,    76,
   186,   308,   151,   152,    77,   299,   119,   309,   310,   288,
    44,   123,    45,    46,    47,   289,   303,    48,   290,   304,
   305,   306,    11,   299,   -12,   -12,   311,   312,   313,   314,
   220,   221,   125,   176,    49,    44,   291,    45,    50,   220,
   402,    51,   289,    52,   126,   290,    53,   222,   396,   133,
   220,   421,   127,    54,    55,    56,   222,    57,   189,    49,
   190,   191,   192,   333,    91,   334,  -171,   222,   129,   289,
    23,   289,   290,   193,   290,   133,   131,   148,    13,    14,
    15,    16,    17,    18,    19,    20,    21,    85,   364,   138,
    94,   132,    95,   160,   289,    86,   140,   290,    96,   161,
   141,    87,    13,    14,    15,    16,    17,    18,    19,    20,
    21,   167,   345,   168,   347,   348,   349,   350,   121,    70,
   142,    71,   132,   175,   132,   177,   132,   236,   249,   250,
   261,   262,   249,   315,   249,   318,   231,   376,   231,   378,
   231,   380,   231,   381,   231,   382,   231,   383,   249,   384,
   353,   385,   231,   388,   132,   406,    97,   411,   199,   201,
   147,   149,   159,   180,   227,   196,   218,   197,   226,   228,
   229,   231,   267,   266,   230,   269,   276,   280,   283,   285,
   153,   293,   301,   302,   307,   331,   118,   332,   336,   341,
   342,   249,   319,   352,   353,    73,   357,   358,   361,   367,
   369,   379,   399,   400,   403,   405,   362,   407,   408,   414,
   419,   420,   423,   424,   154,   265,   340,   409,   387,    80,
   281,   279,   404
};

static const short yycheck[] = {    90,
    92,    92,    99,   136,   178,   191,   139,   186,   205,    10,
    49,   194,    73,   187,   193,   194,   166,   215,   204,   206,
   173,   252,    38,   210,   363,   211,   205,   337,   214,     3,
     4,     4,   263,    27,     4,     3,   215,    28,     7,     4,
     3,     4,     1,    12,     3,   136,   232,   322,   139,    65,
     9,   225,     3,    44,    70,   188,   366,    30,   150,   150,
    30,    31,    32,     7,    33,    30,    34,    35,    12,    38,
     7,    40,    41,   252,   227,    12,   415,   230,    51,   354,
   390,    54,    52,     7,   263,     8,     9,     1,    12,    33,
   277,    56,    57,   267,   281,     9,    40,   188,    68,    20,
   410,    38,     7,    40,    41,     7,   280,    12,     0,   283,
    12,     3,     3,     3,     4,   206,   266,    38,   292,   210,
   351,     1,     1,     3,     3,   322,     4,   308,   309,   327,
   311,   312,   313,   314,   317,    40,    38,   323,   317,   200,
    20,   294,     4,   322,    34,    35,     8,     9,   327,    11,
     9,     4,    11,   339,   340,   334,   195,   354,   356,     4,
     7,   359,     4,   344,   345,    12,   347,   348,   349,   350,
     1,     9,   351,     4,     3,   354,   362,   356,     3,     4,
   359,     4,   368,     1,     4,     3,   277,    18,   189,    36,
   281,   365,    23,    40,     4,    42,    43,     1,    18,    11,
   374,   375,     7,    23,   401,     9,     4,    12,   299,    34,
    35,     1,    16,     3,    61,    62,    63,    64,     3,   310,
     7,     1,   401,     4,     9,    12,   412,   413,    33,     9,
    20,    36,     3,     4,    14,    40,     4,    42,    43,     4,
    22,     4,    24,    25,    26,    10,    33,    29,    13,    36,
    37,    38,     1,    40,     3,     4,    61,    62,    63,    64,
     3,     4,     4,   396,    46,    22,     4,    24,    50,     3,
     4,    53,    10,    55,     4,    13,    58,    20,   370,   370,
     3,     4,     4,    65,    66,    67,    20,    69,    45,    46,
    47,    48,    49,     4,     1,     4,     3,    20,     4,    10,
     1,    10,    13,    60,    13,   396,     4,   404,     9,    10,
    11,    12,    13,    14,    15,    16,    17,     1,     4,     4,
     1,     3,     3,    13,    10,     9,     4,    13,     9,    19,
     4,    15,     9,    10,    11,    12,    13,    14,    15,    16,
    17,     9,   309,    11,   311,   312,   313,   314,     8,     9,
     9,    11,     3,     4,     3,     4,     3,     4,     3,     4,
     3,     4,     3,     4,     3,     4,     3,     4,     3,     4,
     3,     4,     3,     4,     3,     4,     3,     4,     3,     4,
     3,     4,     3,     4,     3,     4,     3,     4,   167,   168,
     4,     9,     4,     3,    20,     4,     3,     8,     4,     4,
     4,     3,     3,    11,    20,     3,     3,     3,     3,     3,
   105,     4,     4,     4,     4,     3,    68,     4,     4,     3,
     3,     3,   266,     4,     3,    47,     4,     4,     4,     4,
     4,     4,     4,     4,     4,     4,    39,     4,     4,     4,
     4,     4,     0,     0,   105,   195,   304,   401,   356,    49,
   210,   207,   394
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
  char *f = from;
  char *t = to;
  int i = count;

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
  int yystate;
  int yyn;
  short *yyssp;
  YY_PDDL_Parser_STYPE *yyvsp;
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
#line 1710 "grammar_tmp.cc"

  switch (yyn) {

case 5:
#line 155 "ppddl.y"
{
          log_error((char*)"syntax error in domain");
          yyerrok;
      ;
    break;}
case 13:
#line 172 "ppddl.y"
{ domain_name_ = std::string(yyvsp[-1].sym->text_); ;
    break;}
case 14:
#line 178 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 15:
#line 179 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 16:
#line 180 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 17:
#line 181 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 18:
#line 182 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 19:
#line 183 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 20:
#line 184 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 21:
#line 185 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 22:
#line 186 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 23:
#line 190 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 24:
#line 191 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 25:
#line 195 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 26:
#line 196 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 27:
#line 200 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 28:
#line 201 "ppddl.y"
{ yyval.sym = yyvsp[0].sym; ;
    break;}
case 30:
#line 208 "ppddl.y"
{
          log_error((char*)"syntax error in requirements declaration.");
          yyerrok;
      ;
    break;}
case 31:
#line 215 "ppddl.y"
{ declare_lw1_translation(); ;
    break;}
case 35:
#line 224 "ppddl.y"
{
          log_error((char*)"syntax error in (:predicates ...)");
          yyerrok;
      ;
    break;}
case 38:
#line 236 "ppddl.y"
{
          PredicateSymbol *p = new PredicateSymbol(yyvsp[-2].sym->text_);
          dom_predicates_.push_back(p);
          p->param_ = *yyvsp[-1].vparam;
          delete yyvsp[-1].vparam;
          clear_param(p->param_);
          yyvsp[-2].sym->value_ = p;
      ;
    break;}
case 39:
#line 244 "ppddl.y"
{
          log_error((char*)"syntax error in predicate declaration");
          yyerrok;
      ;
    break;}
case 41:
#line 252 "ppddl.y"
{
          // must reverse parameter list
          var_symbol_vec tmp_list(*yyvsp[0].vparam);
          yyvsp[0].vparam->clear();
          yyvsp[0].vparam->insert(yyvsp[0].vparam->end(), tmp_list.rbegin(), tmp_list.rend());
          yyval.vparam = yyvsp[0].vparam;
      ;
    break;}
case 42:
#line 259 "ppddl.y"
{ yyval.vparam = new var_symbol_vec; ;
    break;}
case 43:
#line 263 "ppddl.y"
{
          set_variable_type(*yyvsp[0].vparam, yyvsp[0].vparam->size(), dom_top_type_);
          yyval.vparam = yyvsp[0].vparam;
      ;
    break;}
case 44:
#line 270 "ppddl.y"
{
          set_variable_type(*yyvsp[-3].vparam, yyvsp[-3].vparam->size(), static_cast<TypeSymbol*>(yyvsp[-1].sym->value_));
          yyvsp[0].vparam->insert(yyvsp[0].vparam->end(), yyvsp[-3].vparam->begin(), yyvsp[-3].vparam->end());
          delete yyvsp[-3].vparam;
          yyval.vparam = yyvsp[0].vparam;
      ;
    break;}
case 45:
#line 276 "ppddl.y"
{
          set_variable_type(*yyvsp[-2].vparam, yyvsp[-2].vparam->size(), static_cast<TypeSymbol*>(yyvsp[0].sym->value_));
          yyval.vparam = yyvsp[-2].vparam;
      ;
    break;}
case 46:
#line 283 "ppddl.y"
{
          yyvsp[0].vparam->push_back(static_cast<VariableSymbol*>(yyvsp[-1].vsym));
          yyval.vparam = yyvsp[0].vparam;
      ;
    break;}
case 47:
#line 287 "ppddl.y"
{ yyval.vparam = new var_symbol_vec; yyval.vparam->push_back(yyvsp[0].vsym); ;
    break;}
case 48:
#line 291 "ppddl.y"
{
          VariableSymbol *var = new VariableSymbol(yyvsp[0].sym->text_);
          yyvsp[0].sym->value_ = var;
          yyval.vsym = var;
      ;
    break;}
case 49:
#line 296 "ppddl.y"
{
          std::string msg("variable '");
          msg += yyvsp[0].sym->text_;
          msg += "' shadows variable in outer scope: this is not supported!";
          log_error((char*)msg.c_str());
          yyerrok;
      ;
    break;}
case 51:
#line 309 "ppddl.y"
{
          set_type_type(dom_types_, dom_types_.size(), dom_top_type_);
      ;
    break;}
case 52:
#line 315 "ppddl.y"
{
          set_type_type(dom_types_, dom_types_.size(), static_cast<TypeSymbol*>(yyvsp[-1].sym->value_));
      ;
    break;}
case 53:
#line 318 "ppddl.y"
{
          yyvsp[-1].sym->value_ = new TypeSymbol(yyvsp[-1].sym->text_);
          if( write_warnings_ )
              std::cout << Utils::warning() << "assuming " << yyvsp[-1].sym->text_ << " - object" << std::endl;
          static_cast<TypeSymbol*>(yyvsp[-1].sym->value_)->sym_type_ = dom_top_type_;
          set_type_type(dom_types_, dom_types_.size(), static_cast<TypeSymbol*>(yyvsp[-1].sym->value_));
          dom_types_.push_back(static_cast<TypeSymbol*>(yyvsp[-1].sym->value_));
      ;
    break;}
case 56:
#line 331 "ppddl.y"
{ ;
    break;}
case 58:
#line 336 "ppddl.y"
{
          yyvsp[0].sym->value_ = new TypeSymbol(yyvsp[0].sym->text_);
          dom_types_.push_back(static_cast<TypeSymbol*>(yyvsp[0].sym->value_));
      ;
    break;}
case 63:
#line 352 "ppddl.y"
{
          set_constant_type(dom_constants_, dom_constants_.size(), static_cast<TypeSymbol*>(yyvsp[0].sym->value_));
      ;
    break;}
case 66:
#line 360 "ppddl.y"
{
          set_constant_type(dom_constants_, dom_constants_.size(), dom_top_type_);
      ;
    break;}
case 67:
#line 366 "ppddl.y"
{
          yyvsp[0].sym->value_ = new Symbol(yyvsp[0].sym->text_);
          dom_constants_.push_back(static_cast<Symbol*>(yyvsp[0].sym->value_));
      ;
    break;}
case 68:
#line 370 "ppddl.y"
{
          yyvsp[0].sym->value_ = new Symbol(yyvsp[0].sym->text_);
          dom_constants_.push_back(static_cast<Symbol*>(yyvsp[0].sym->value_));
      ;
    break;}
case 70:
#line 380 "ppddl.y"
{
          if( type_ == PDDL_Parser::replanner ) {
              log_error((char*)"':axiom' is not a valid element in k-replanner.");
              yyerrok;
          }
      ;
    break;}
case 71:
#line 386 "ppddl.y"
{
          if( type_ == PDDL_Parser::cp2fsc ) {
              log_error((char*)"':sensor' is not a valid element in cp2fsc.");
              yyerrok;
          }
      ;
    break;}
case 72:
#line 392 "ppddl.y"
{
          if( type_ == PDDL_Parser::replanner ) {
              log_error((char*)"':observable' is not a valid element in k-replanner.");
              yyerrok;
          }
      ;
    break;}
case 73:
#line 398 "ppddl.y"
{
          if( type_ == PDDL_Parser::replanner ) {
              log_error((char*)"':sticky' is not a valid element in k-replanner.");
              yyerrok;
          }
      ;
    break;}
case 74:
#line 404 "ppddl.y"
{
          declare_lw1_translation();
          if( type_ == PDDL_Parser::cp2fsc ) {
              log_error((char*)"':sensor' is not a valid element in cp2fsc.");
              yyerrok;
          }
      ;
    break;}
case 75:
#line 411 "ppddl.y"
{ ;
    break;}
case 76:
#line 418 "ppddl.y"
{
#ifdef SMART
          std::unique_ptr<Action> na = std::make_unique<Action>(yyvsp[0].sym->text_);
          dom_actions_.emplace_back(std::move(na));
#else
          Action *na = new Action(yyvsp[0].sym->text_);
          dom_actions_.push_back(na);
#endif
      ;
    break;}
case 77:
#line 427 "ppddl.y"
{
          clear_param(dom_actions_.back()->param_);
#ifdef SMART
          yyvsp[-3].sym->value_ = dom_actions_.back().get();
#else
          yyvsp[-3].sym->value_ = dom_actions_.back();
#endif
      ;
    break;}
case 78:
#line 435 "ppddl.y"
{
          log_error((char*)"syntax error in action declaration");
          yyerrok;
      ;
    break;}
case 79:
#line 442 "ppddl.y"
{
          dom_actions_.back()->param_ = *yyvsp[-1].vparam;
          delete yyvsp[-1].vparam;
      ;
    break;}
case 80:
#line 446 "ppddl.y"
{ dom_actions_.back()->precondition_ = yyvsp[0].condition; ;
    break;}
case 81:
#line 447 "ppddl.y"
{ dom_actions_.back()->effect_ = yyvsp[0].effect; ;
    break;}
case 82:
#line 448 "ppddl.y"
{
          declare_clg_translation();
          dom_actions_.back()->observe_ = new AndEffect(*yyvsp[0].effect_vec);
          delete yyvsp[0].effect_vec;
      ;
    break;}
case 83:
#line 453 "ppddl.y"
{
          declare_lw1_translation();
          dom_actions_.back()->sensing_proxy_ = yyvsp[0].sensing_proxy_list;
      ;
    break;}
case 91:
#line 470 "ppddl.y"
{ yyval.condition = new Constant(true); ;
    break;}
case 92:
#line 471 "ppddl.y"
{ yyval.condition = new Constant(false); ;
    break;}
case 93:
#line 475 "ppddl.y"
{
          // if literal is for equality, construct EQ
          if( yyvsp[0].atom->pred_ == dom_eq_pred_ )
              yyval.condition = new EQ(dynamic_cast<VariableSymbol*>(yyvsp[0].atom->param_[0]), dynamic_cast<VariableSymbol*>(yyvsp[0].atom->param_[1]), yyvsp[0].atom->negated_);
          else
              yyval.condition = new Literal(*yyvsp[0].atom);
          delete yyvsp[0].atom;
      ;
    break;}
case 96:
#line 491 "ppddl.y"
{
          PredicateSymbol* p = static_cast<PredicateSymbol*>(yyvsp[-2].sym->value_);
          if( p->param_.size() != yyvsp[-1].param->size() ) {
              std::string msg = std::string("wrong number of arguments for predicate '") + p->print_name_ + "'";
              log_error(const_cast<char*>(msg.c_str()));
          } else {
              yyval.atom = new Atom(p);
              yyval.atom->param_ = *yyvsp[-1].param;
              delete yyvsp[-1].param;
          }
      ;
    break;}
case 97:
#line 502 "ppddl.y"
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
case 98:
#line 514 "ppddl.y"
{
          const_cast<Literal*>(static_cast<const Literal*>(yyvsp[-1].atom))->negated_ = true;
          yyval.atom = yyvsp[-1].atom;
      ;
    break;}
case 99:
#line 521 "ppddl.y"
{
          if( yyvsp[0].sym->value_ == 0 )
              log_error((char*)"undeclared variable in atom args list");
          else
              yyvsp[-1].param->push_back(static_cast<VariableSymbol*>(yyvsp[0].sym->value_));
          yyval.param = yyvsp[-1].param;
      ;
    break;}
case 100:
#line 528 "ppddl.y"
{
          yyvsp[-1].param->push_back(static_cast<Symbol*>(yyvsp[0].sym->value_));
          yyval.param = yyvsp[-1].param;
      ;
    break;}
case 101:
#line 532 "ppddl.y"
{ yyval.param = new symbol_vec; ;
    break;}
case 102:
#line 536 "ppddl.y"
{
          yyval.condition = new And(*yyvsp[-1].condition_vec);
          delete yyvsp[-1].condition_vec;
      ;
    break;}
case 103:
#line 543 "ppddl.y"
{
          yyval.condition = new Or(*yyvsp[-1].condition_vec);
          delete yyvsp[-1].condition_vec;
      ;
    break;}
case 104:
#line 550 "ppddl.y"
{
          schema_.push_back(new ForallCondition);
          using_owned_schema_.push_back(false);
      ;
    break;}
case 105:
#line 554 "ppddl.y"
{
          schema_.back()->param_ = *yyvsp[-1].vparam;
          delete yyvsp[-1].vparam;
      ;
    break;}
case 106:
#line 558 "ppddl.y"
{
          assert(dynamic_cast<ForallCondition*>(schema_.back()) != 0);
          ForallCondition *forall_condition = static_cast<ForallCondition*>(schema_.back());
          schema_.pop_back();
          using_owned_schema_.pop_back();
          forall_condition->condition_ = yyvsp[-1].condition;
          clear_param(forall_condition->param_);
          yyval.condition = forall_condition;
      ;
    break;}
case 107:
#line 570 "ppddl.y"
{
          schema_.push_back(new ExistsCondition);
          using_owned_schema_.push_back(false);
      ;
    break;}
case 108:
#line 574 "ppddl.y"
{
          schema_.back()->param_ = *yyvsp[-1].vparam;
          delete yyvsp[-1].vparam;
      ;
    break;}
case 109:
#line 578 "ppddl.y"
{
          assert(dynamic_cast<ExistsCondition*>(schema_.back()) != 0);
          ExistsCondition *exists_condition = static_cast<ExistsCondition*>(schema_.back());
          schema_.pop_back();
          using_owned_schema_.pop_back();
          exists_condition->condition_ = yyvsp[-1].condition;
          clear_param(exists_condition->param_);
          yyval.condition = exists_condition;
      ;
    break;}
case 110:
#line 590 "ppddl.y"
{
          yyvsp[-1].condition_vec->push_back(yyvsp[0].condition);
          yyval.condition_vec = yyvsp[-1].condition_vec;
      ;
    break;}
case 111:
#line 594 "ppddl.y"
{
          condition_vec *cond_vec = new condition_vec;
          cond_vec->push_back(yyvsp[0].condition);
          yyval.condition_vec = cond_vec;
      ;
    break;}
case 112:
#line 602 "ppddl.y"
{
          yyvsp[-1].condition_vec->push_back(yyvsp[0].condition);
          yyval.condition_vec = yyvsp[-1].condition_vec;
      ;
    break;}
case 113:
#line 606 "ppddl.y"
{
          condition_vec *cond_vec = new condition_vec;
          cond_vec->push_back(yyvsp[0].condition);
          yyval.condition_vec = cond_vec;
      ;
    break;}
case 115:
#line 615 "ppddl.y"
{
          yyval.effect = new AndEffect(*yyvsp[-1].effect_vec);
          delete yyvsp[-1].effect_vec;
      ;
    break;}
case 116:
#line 622 "ppddl.y"
{
          yyvsp[-1].effect_vec->push_back(yyvsp[0].effect);
          yyval.effect_vec = yyvsp[-1].effect_vec;
      ;
    break;}
case 117:
#line 626 "ppddl.y"
{
          yyval.effect_vec = new effect_vec;
          yyval.effect_vec->push_back(yyvsp[0].effect);
      ;
    break;}
case 121:
#line 639 "ppddl.y"
{ yyval.effect = new ConditionalEffect(yyvsp[-2].condition, yyvsp[-1].effect); ;
    break;}
case 122:
#line 643 "ppddl.y"
{
          schema_.push_back(new ForallEffect);
          using_owned_schema_.push_back(false);
      ;
    break;}
case 123:
#line 647 "ppddl.y"
{
          schema_.back()->param_ = *yyvsp[-1].vparam;
          delete yyvsp[-1].vparam;
      ;
    break;}
case 124:
#line 651 "ppddl.y"
{
          assert(dynamic_cast<ForallEffect*>(schema_.back()) != 0);
          ForallEffect *forall_effect = static_cast<ForallEffect*>(schema_.back());
          schema_.pop_back();
          using_owned_schema_.pop_back();
          forall_effect->effect_ = yyvsp[-1].effect;
          clear_param(forall_effect->param_);
          yyval.effect = forall_effect;
      ;
    break;}
case 125:
#line 663 "ppddl.y"
{
#ifdef SMART
          if( using_owned_schema_.back() ) {
              assert(!owned_schema_.empty());
              owned_schema_.back()->such_that_ = yyvsp[0].condition;
          } else {
              assert(!schema_.empty());
              schema_.back()->such_that_ = yyvsp[0].condition;
          }
#else
          assert(!schema_.empty());
          schema_.back()->such_that_ = yyvsp[0].condition;
#endif
      ;
    break;}
case 127:
#line 681 "ppddl.y"
{
          yyval.effect = new AndEffect(*yyvsp[-1].effect_vec);
          delete yyvsp[-1].effect_vec;
      ;
    break;}
case 129:
#line 689 "ppddl.y"
{
          yyvsp[-1].effect_vec->push_back(yyvsp[0].effect);
          yyval.effect_vec = yyvsp[-1].effect_vec;
      ;
    break;}
case 130:
#line 693 "ppddl.y"
{
          yyval.effect_vec = new effect_vec;
          yyval.effect_vec->push_back(yyvsp[0].effect);
      ;
    break;}
case 131:
#line 700 "ppddl.y"
{
          yyvsp[-1].effect_vec->push_back(yyvsp[0].effect);
          yyval.effect_vec = yyvsp[-1].effect_vec;
      ;
    break;}
case 132:
#line 704 "ppddl.y"
{
          yyval.effect_vec = new effect_vec;
          yyval.effect_vec->push_back(yyvsp[0].effect);
      ;
    break;}
case 133:
#line 711 "ppddl.y"
{ yyval.effect = new AtomicEffect(*yyvsp[0].atom); delete yyvsp[0].atom; ;
    break;}
case 134:
#line 715 "ppddl.y"
{ yyval.effect = new AtomicEffect(*yyvsp[0].atom); delete yyvsp[0].atom; ;
    break;}
case 136:
#line 720 "ppddl.y"
{ yyval.sensing_proxy_list = 0; ;
    break;}
case 137:
#line 724 "ppddl.y"
{
          sensing_proxy_vec *list_sensing_proxy = const_cast<sensing_proxy_vec*>(yyvsp[-1].sensing_proxy_list);
          list_sensing_proxy->push_back(yyvsp[0].sensing_proxy);
          yyval.sensing_proxy_list = list_sensing_proxy;
      ;
    break;}
case 138:
#line 729 "ppddl.y"
{
          sensing_proxy_vec *list_sensing_proxy = new sensing_proxy_vec;
          list_sensing_proxy->push_back(yyvsp[0].sensing_proxy);
          yyval.sensing_proxy_list = list_sensing_proxy;
      ;
    break;}
case 139:
#line 737 "ppddl.y"
{ yyval.sensing_proxy = new BasicSensingModel(yyvsp[0].sensing_model); ;
    break;}
case 141:
#line 742 "ppddl.y"
{
          schema_.push_back(new ForallSensing);
          using_owned_schema_.push_back(false);
      ;
    break;}
case 142:
#line 746 "ppddl.y"
{
          schema_.back()->param_ = *yyvsp[-1].vparam;
          delete yyvsp[-1].vparam;
      ;
    break;}
case 143:
#line 750 "ppddl.y"
{
          assert(dynamic_cast<ForallSensing*>(schema_.back()) != 0);
          ForallSensing *forall_sensing = static_cast<ForallSensing*>(schema_.back());
          schema_.pop_back();
          using_owned_schema_.pop_back();
          forall_sensing->sensing_ = *yyvsp[-1].sensing_proxy_list;
          delete yyvsp[-1].sensing_proxy_list;
          clear_param(forall_sensing->param_);
          yyval.sensing_proxy = forall_sensing;
      ;
    break;}
case 144:
#line 763 "ppddl.y"
{
          assert(static_cast<Symbol*>(yyvsp[-3].sym->value_)->sym_class_ == sym_varname);
          const Variable *variable = static_cast<Variable*>(yyvsp[-3].sym->value_);
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
case 145:
#line 775 "ppddl.y"
{
          assert(static_cast<Symbol*>(yyvsp[-5].sym->value_)->sym_class_ == sym_varname);
          const Variable *variable = static_cast<Variable*>(yyvsp[-5].sym->value_);
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
case 146:
#line 790 "ppddl.y"
{
          assert(static_cast<Symbol*>(yyvsp[-1].sym->value_)->sym_class_ == sym_varname);
          const Variable *variable = static_cast<Variable*>(yyvsp[-1].sym->value_);
          assert(dynamic_cast<const StateVariable*>(variable) != 0);
          yyval.sensing_model = new SensingModelForStateVariable(static_cast<const StateVariable*>(variable));
      ;
    break;}
case 147:
#line 796 "ppddl.y"
{
          assert(static_cast<Symbol*>(yyvsp[-3].sym->value_)->sym_class_ == sym_varname);
          const Variable *variable = static_cast<Variable*>(yyvsp[-3].sym->value_);
          assert(dynamic_cast<const StateVariable*>(variable) != 0);
          SensingModelForStateVariable *model = new SensingModelForStateVariable(static_cast<const StateVariable*>(variable));
          model->param_ = *yyvsp[-2].param;
          delete yyvsp[-2].param;
          yyval.sensing_model = model;
      ;
    break;}
case 148:
#line 805 "ppddl.y"
{
          log_error((char*)"syntax error in sensing declaration for ':variable'");
          yyerrok;
      ;
    break;}
case 149:
#line 809 "ppddl.y"
{
          log_error((char*)"syntax error in sensing declaration for ':model-for'");
          yyerrok;
      ;
    break;}
case 150:
#line 816 "ppddl.y"
{
#ifdef SMART
          std::unique_ptr<Axiom> nr = std::make_unique<Axiom>(yyvsp[0].sym->text_);
          dom_axioms_.emplace_back(std::move(nr));
#else
          Axiom *nr = new Axiom(yyvsp[0].sym->text_);
          dom_axioms_.push_back(nr);
#endif
      ;
    break;}
case 151:
#line 825 "ppddl.y"
{
          clear_param(dom_axioms_.back()->param_);
#ifdef SMART
          yyvsp[-3].sym->value_ = dom_axioms_.back().get();
#else
          yyvsp[-3].sym->value_ = dom_axioms_.back();
#endif
      ;
    break;}
case 152:
#line 833 "ppddl.y"
{
          log_error((char*)"syntax error in axiom declaration");
          yyerrok;
      ;
    break;}
case 153:
#line 840 "ppddl.y"
{
          dom_axioms_.back()->param_ = *yyvsp[-1].vparam;
          delete yyvsp[-1].vparam;
      ;
    break;}
case 154:
#line 844 "ppddl.y"
{ dom_axioms_.back()->body_ = yyvsp[0].condition; ;
    break;}
case 155:
#line 845 "ppddl.y"
{ dom_axioms_.back()->head_ = yyvsp[0].effect; ;
    break;}
case 157:
#line 850 "ppddl.y"
{
#ifdef SMART
          std::unique_ptr<Sensor> nr = std::make_unique<Sensor>(yyvsp[0].sym->text_);
          dom_sensors_.emplace_back(std::move(nr));
#else
          Sensor *nr = new Sensor(yyvsp[0].sym->text_);
          dom_sensors_.push_back(nr);
#endif
      ;
    break;}
case 158:
#line 859 "ppddl.y"
{
          clear_param(dom_sensors_.back()->param_);
#ifdef SMART
          yyvsp[-3].sym->value_ = dom_sensors_.back().get();
#else
          yyvsp[-3].sym->value_ = dom_sensors_.back();
#endif
      ;
    break;}
case 159:
#line 867 "ppddl.y"
{
          log_error((char*)"syntax error in sensor declaration");
          yyerrok;
      ;
    break;}
case 160:
#line 874 "ppddl.y"
{
          dom_sensors_.back()->param_ = *yyvsp[-1].vparam;
          delete yyvsp[-1].vparam;
      ;
    break;}
case 161:
#line 878 "ppddl.y"
{
          dom_sensors_.back()->condition_ = yyvsp[0].condition;
      ;
    break;}
case 162:
#line 881 "ppddl.y"
{
          dom_sensors_.back()->sense_ = new AndEffect(*yyvsp[0].effect_vec);
          delete yyvsp[0].effect_vec;
      ;
    break;}
case 164:
#line 889 "ppddl.y"
{
#ifdef SMART
          std::unique_ptr<Observable> obs = std::make_unique<Observable>();
          effect_vec_ptr_ = &obs->observables_;
          dom_observables_.emplace_back(std::move(obs));
#else
          Observable *obs = new Observable;
          dom_observables_.push_back(obs);
          effect_vec_ptr_ = &obs->observables_;
#endif
      ;
    break;}
case 166:
#line 901 "ppddl.y"
{
          log_error((char*)"syntax error in observable declaration");
          yyerrok;
      ;
    break;}
case 167:
#line 908 "ppddl.y"
{
          effect_vec_ptr_->push_back(yyvsp[0].effect);
      ;
    break;}
case 168:
#line 911 "ppddl.y"
{
          effect_vec_ptr_->push_back(yyvsp[0].effect);
      ;
    break;}
case 171:
#line 922 "ppddl.y"
{
#ifdef SMART
          std::unique_ptr<Sticky> sticky = std::make_unique<Sticky>();
          effect_vec_ptr_ = &sticky->stickies_;
          dom_stickies_.emplace_back(std::move(sticky));
#else
          Sticky *sticky = new Sticky;
          dom_stickies_.push_back(sticky);
          effect_vec_ptr_ = &sticky->stickies_;
#endif
      ;
    break;}
case 173:
#line 934 "ppddl.y"
{
          log_error((char*)"syntax error in sticky declaration");
          yyerrok;
      ;
    break;}
case 174:
#line 941 "ppddl.y"
{
#ifdef SMART
          std::unique_ptr<Variable> var;
          if( yyvsp[-1].ival == 0 )
              var = std::make_unique<StateVariable>(yyvsp[0].sym->text_);
          else
              var = std::make_unique<ObsVariable>(yyvsp[0].sym->text_);
          effect_vec_ptr_ = &var->domain_;
          lw1_uninstantiated_variables_.emplace_back(std::move(var));
#else
          Variable *var = 0;
          if( yyvsp[-1].ival == 0 )
              var = new StateVariable(yyvsp[0].sym->text_);
          else
              var = new ObsVariable(yyvsp[0].sym->text_);
          lw1_uninstantiated_variables_.push_back(var);
          effect_vec_ptr_ = &var->domain_;
#endif
      ;
    break;}
case 175:
#line 960 "ppddl.y"
{
#ifdef SMART
          yyvsp[-3].sym->value_ = lw1_uninstantiated_variables_.back().get();
#else
          yyvsp[-3].sym->value_ = lw1_uninstantiated_variables_.back();
#endif
      ;
    break;}
case 176:
#line 967 "ppddl.y"
{
#ifdef SMART
          std::unique_ptr<Variable> var;
          if( yyvsp[-2].ival == 0 )
              var = std::make_unique<StateVariable>(yyvsp[0].sym->text_);
          else
              var = std::make_unique<ObsVariable>(yyvsp[0].sym->text_);
          effect_vec_ptr_ = &var->domain_;
          owned_schema_.emplace_back(std::move(var));
          using_owned_schema_.push_back(true);
#else
          Variable *var = 0;
          if( yyvsp[-2].ival == 0 )
              var = new StateVariable(yyvsp[0].sym->text_);
          else
              var = new ObsVariable(yyvsp[0].sym->text_);
          effect_vec_ptr_ = &var->domain_;
          schema_.push_back(var);
          using_owned_schema_.push_back(false);
#endif
      ;
    break;}
case 177:
#line 988 "ppddl.y"
{
#ifdef SMART
          owned_schema_.back()->param_ = *yyvsp[-1].vparam;
#else
          schema_.back()->param_ = *yyvsp[-1].vparam;
#endif
          delete yyvsp[-1].vparam;
      ;
    break;}
case 178:
#line 996 "ppddl.y"
{
#ifdef SMART
          assert(dynamic_cast<Variable*>(owned_schema_.back().get()) != 0);
          std::unique_ptr<Variable> variable(static_cast<Variable*>(owned_schema_.back().release()));
          owned_schema_.pop_back();
          using_owned_schema_.pop_back();
#else
          assert(dynamic_cast<Variable*>(schema_.back()) != 0);
          Variable *variable = static_cast<Variable*>(schema_.back());
          schema_.pop_back();
          using_owned_schema_.pop_back();
#endif
          clear_param(variable->param_);
#ifdef SMART
          yyvsp[-7].sym->value_ = variable.get();
          lw1_uninstantiated_variables_.emplace_back(std::move(variable));
#else
          yyvsp[-7].sym->value_ = variable;
          lw1_uninstantiated_variables_.push_back(variable);
#endif
      ;
    break;}
case 179:
#line 1017 "ppddl.y"
{
          log_error((char*)"syntax error in state variable declaration");
          yyerrok;
      ;
    break;}
case 180:
#line 1024 "ppddl.y"
{ yyval.ival = 0; ;
    break;}
case 181:
#line 1025 "ppddl.y"
{ yyval.ival = 1; ;
    break;}
case 182:
#line 1029 "ppddl.y"
{
#ifdef SMART
          std::unique_ptr<VariableGroup> group = std::make_unique<VariableGroup>(yyvsp[0].sym->text_);
          lw1_uninstantiated_variable_groups_.emplace_back(std::move(group));
#else
          VariableGroup *group = new VariableGroup(yyvsp[0].sym->text_);
          lw1_uninstantiated_variable_groups_.push_back(group);
#endif
      ;
    break;}
case 183:
#line 1038 "ppddl.y"
{
          lw1_uninstantiated_variable_groups_.back()->group_ = *yyvsp[-1].state_variable_list_vec;
          delete yyvsp[-1].state_variable_list_vec;
      ;
    break;}
case 184:
#line 1042 "ppddl.y"
{
#ifdef SMART
          std::unique_ptr<VariableGroup> group = std::make_unique<VariableGroup>(yyvsp[0].sym->text_);
          owned_schema_.emplace_back(std::move(group));
          using_owned_schema_.push_back(true);
#else
          VariableGroup *group = new VariableGroup(yyvsp[0].sym->text_);
          schema_.push_back(group);
          using_owned_schema_.push_back(false);
#endif
      ;
    break;}
case 185:
#line 1053 "ppddl.y"
{
#ifdef SMART
          owned_schema_.back()->param_ = *yyvsp[-1].vparam;
#else
          schema_.back()->param_ = *yyvsp[-1].vparam;
#endif
          delete yyvsp[-1].vparam;
      ;
    break;}
case 186:
#line 1061 "ppddl.y"
{
#ifdef SMART
          assert(dynamic_cast<VariableGroup*>(owned_schema_.back().get()) != 0);
          std::unique_ptr<VariableGroup> group(static_cast<VariableGroup*>(owned_schema_.back().release()));
          owned_schema_.pop_back();
          using_owned_schema_.pop_back();
#else
          assert(dynamic_cast<VariableGroup*>(schema_.back()) != 0);
          VariableGroup *group = static_cast<VariableGroup*>(schema_.back());
          schema_.pop_back();
          using_owned_schema_.pop_back();
#endif
          group->group_ = *yyvsp[-1].state_variable_list_vec;
          delete yyvsp[-1].state_variable_list_vec;
          clear_param(group->param_);
#ifdef SMART
          yyvsp[-7].sym->value_ = group.get();
          lw1_uninstantiated_variable_groups_.emplace_back(std::move(group));
#else
          yyvsp[-7].sym->value_ = group;
          lw1_uninstantiated_variable_groups_.push_back(group);
#endif
      ;
    break;}
case 187:
#line 1084 "ppddl.y"
{
          log_error((char*)"syntax error in variable group declaration");
          yyerrok;
      ;
    break;}
case 188:
#line 1091 "ppddl.y"
{
          state_variable_list_vec *varlist = const_cast<state_variable_list_vec*>(yyvsp[-1].state_variable_list_vec);
          assert(dynamic_cast<const SingleStateVariableList*>(yyvsp[0].state_variable_list) != 0);
          varlist->push_back(const_cast<StateVariableList*>(yyvsp[0].state_variable_list));
          yyval.state_variable_list_vec = varlist;
      ;
    break;}
case 189:
#line 1097 "ppddl.y"
{
          state_variable_list_vec *varlist = const_cast<state_variable_list_vec*>(yyvsp[-1].state_variable_list_vec);
          assert(dynamic_cast<const ForallStateVariableList*>(yyvsp[0].state_variable_list) != 0);
          varlist->push_back(const_cast<StateVariableList*>(yyvsp[0].state_variable_list));
          yyval.state_variable_list_vec = varlist;
      ;
    break;}
case 190:
#line 1103 "ppddl.y"
{ yyval.state_variable_list_vec = new state_variable_list_vec; ;
    break;}
case 191:
#line 1107 "ppddl.y"
{
          assert(static_cast<Symbol*>(yyvsp[0].sym->value_)->sym_class_ == sym_varname);
          const Variable *var = static_cast<Variable*>(yyvsp[0].sym->value_);
          if( dynamic_cast<const StateVariable*>(var) == 0 ) {
              std::cout << Utils::error() << "only state variables can be grouped together" << std::endl;
          }
          yyval.state_variable_list = new SingleStateVariableList(var->print_name_);
      ;
    break;}
case 192:
#line 1115 "ppddl.y"
{
          assert(static_cast<Symbol*>(yyvsp[-2].sym->value_)->sym_class_ == sym_varname);
          const Variable *var = static_cast<Variable*>(yyvsp[-2].sym->value_);
          if( dynamic_cast<const StateVariable*>(var) == 0 ) {
              std::cout << Utils::error() << "only state variables can be grouped together" << std::endl;
          }
          SingleStateVariableList *single = new SingleStateVariableList(var->print_name_);
          single->param_ = *yyvsp[-1].param;
          delete yyvsp[-1].param;
          yyval.state_variable_list = single;
      ;
    break;}
case 193:
#line 1129 "ppddl.y"
{
          schema_.push_back(new ForallStateVariableList);
          using_owned_schema_.push_back(false);
      ;
    break;}
case 194:
#line 1133 "ppddl.y"
{
          schema_.back()->param_ = *yyvsp[-1].vparam;
          delete yyvsp[-1].vparam;
      ;
    break;}
case 195:
#line 1137 "ppddl.y"
{
          assert(dynamic_cast<ForallStateVariableList*>(schema_.back()) != 0);
          ForallStateVariableList *forall_state_variable_list = static_cast<ForallStateVariableList*>(schema_.back());
          schema_.pop_back();
          using_owned_schema_.pop_back();
          forall_state_variable_list->group_ = *yyvsp[-1].state_variable_list_vec;
          delete yyvsp[-1].state_variable_list_vec;
          clear_param(forall_state_variable_list->param_);
          yyval.state_variable_list = forall_state_variable_list;
      ;
    break;}
case 196:
#line 1153 "ppddl.y"
{
          declare_lw1_translation();
          lw1_default_sensing_proxy_ = yyvsp[-1].sensing_proxy_list;
      ;
    break;}
case 197:
#line 1163 "ppddl.y"
{
          problem_name_ = std::string(yyvsp[-1].sym->text_);
      ;
    break;}
case 199:
#line 1167 "ppddl.y"
{
          log_error((char*)"syntax error in problem definition.");
          yyerrok;
      ;
    break;}
case 207:
#line 1184 "ppddl.y"
{
          if( yyvsp[-1].ival == KW_EXPLICIT_INITIAL_STATE ) {
#ifdef SMART
              dom_explicit_initial_states_.push_back(owned_init_element_vec());
#else
              dom_explicit_initial_states_.push_back(init_element_vec());
#endif
          }
    ;
    break;}
case 208:
#line 1193 "ppddl.y"
{
          if( yyvsp[-2].ival == KW_INIT ) {
              dom_init_.clear();
#ifdef SMART
              for( owned_init_element_vec::iterator it = const_cast<owned_init_element_vec*>(yyvsp[-1].ilist)->begin(); it != const_cast<owned_init_element_vec*>(yyvsp[-1].ilist)->end(); ++it )
                  dom_init_.emplace_back(it->release());
#else
              dom_init_ = *yyvsp[-1].ilist;
#endif
          } else {
              assert(yyvsp[-2].ival == KW_EXPLICIT_INITIAL_STATE);
#ifdef SMART
              dom_explicit_initial_states_.push_back(owned_init_element_vec());
              for( owned_init_element_vec::iterator it = const_cast<owned_init_element_vec*>(yyvsp[-1].ilist)->begin(); it != const_cast<owned_init_element_vec*>(yyvsp[-1].ilist)->end(); ++it )
                  dom_explicit_initial_states_.back().emplace_back(it->release());
#else
              dom_explicit_initial_states_.push_back(*yyvsp[-1].ilist);
#endif
          }
          delete yyvsp[-1].ilist;
      ;
    break;}
case 209:
#line 1214 "ppddl.y"
{
          if( yyvsp[-5].ival == KW_INIT ) {
              dom_init_.clear();
#ifdef SMART
              for( owned_init_element_vec::iterator it = const_cast<owned_init_element_vec*>(yyvsp[-2].ilist)->begin(); it != const_cast<owned_init_element_vec*>(yyvsp[-2].ilist)->end(); ++it )
                  dom_init_.emplace_back(it->release());
#else
              dom_init_ = *yyvsp[-2].ilist;
#endif
          } else {
              assert(yyvsp[-5].ival == KW_EXPLICIT_INITIAL_STATE);
#ifdef SMART
              dom_explicit_initial_states_.push_back(owned_init_element_vec());
              for( owned_init_element_vec::iterator it = const_cast<owned_init_element_vec*>(yyvsp[-2].ilist)->begin(); it != const_cast<owned_init_element_vec*>(yyvsp[-2].ilist)->end(); ++it )
                  dom_explicit_initial_states_.back().emplace_back(it->release());
#else
              dom_explicit_initial_states_.push_back(*yyvsp[-2].ilist);
#endif
          }
          delete yyvsp[-2].ilist;
      ;
    break;}
case 210:
#line 1238 "ppddl.y"
{ yyval.ival = KW_INIT; ;
    break;}
case 211:
#line 1239 "ppddl.y"
{ yyval.ival = KW_EXPLICIT_INITIAL_STATE; ;
    break;}
case 212:
#line 1243 "ppddl.y"
{
#ifdef SMART
          owned_init_element_vec *ilist = const_cast<owned_init_element_vec*>(yyvsp[-1].ilist);
          if( yyvsp[0].ielem != 0 ) ilist->emplace_back(std::unique_ptr<InitElement>(const_cast<InitElement*>(yyvsp[0].ielem)));
#else
          init_element_vec *ilist = const_cast<init_element_vec*>(yyvsp[-1].ilist);
          if( yyvsp[0].ielem != 0 ) ilist->push_back(const_cast<InitElement*>(yyvsp[0].ielem));
#endif
          yyval.ilist = ilist;
      ;
    break;}
case 213:
#line 1253 "ppddl.y"
{
#ifdef SMART
          owned_init_element_vec *ilist = new owned_init_element_vec;
          if( yyvsp[0].ielem != 0 ) ilist->emplace_back(std::unique_ptr<InitElement>(const_cast<InitElement*>(yyvsp[0].ielem)));
#else
          init_element_vec *ilist = new init_element_vec;
          if( yyvsp[0].ielem != 0 ) ilist->push_back(const_cast<InitElement*>(yyvsp[0].ielem));
#endif
          yyval.ilist = ilist;
      ;
    break;}
case 214:
#line 1266 "ppddl.y"
{
          yyval.ielem = new InitLiteral(*yyvsp[0].atom);
      ;
    break;}
case 215:
#line 1269 "ppddl.y"
{
          if( type_ == PDDL_Parser::cp2fsc ) {
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
case 216:
#line 1280 "ppddl.y"
{
          if( type_ == PDDL_Parser::replanner ) {
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
case 217:
#line 1291 "ppddl.y"
{
          if( type_ == PDDL_Parser::replanner ) {
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
case 218:
#line 1302 "ppddl.y"
{
          yyval.ielem = 0; // when fixing this, remove condition '$2 != 0' and '$1 != 0' above (in single_init_element)
          std::cout << Utils::warning()
                    << Utils::magenta() << "(clg) ignoring '" << yyvsp[0].unknown->to_string() << "'"
                    << Utils::normal() << std::endl;
          //$$ = new InitUnknown(*$1);
          delete yyvsp[0].unknown;
      ;
    break;}
case 219:
#line 1313 "ppddl.y"
{
          //$$ = new Invariant(Invariant::AT_LEAST_ONE, *static_cast<const And*>($3));
          yyval.invariant = new Invariant(Invariant::AT_LEAST_ONE, *yyvsp[-1].condition_vec);
          delete yyvsp[-1].condition_vec;
      ;
    break;}
case 220:
#line 1318 "ppddl.y"
{
          //$$ = new Invariant(Invariant::AT_LEAST_ONE, *static_cast<const And*>($3));
          yyval.invariant = new Invariant(Invariant::AT_LEAST_ONE, *yyvsp[-1].condition_vec);
          delete yyvsp[-1].condition_vec;
      ;
    break;}
case 221:
#line 1326 "ppddl.y"
{
          //$$ = new Invariant(Invariant::AT_MOST_ONE, *static_cast<const And*>($3));
          yyval.invariant = new Invariant(Invariant::AT_MOST_ONE, *yyvsp[-1].condition_vec);
          delete yyvsp[-1].condition_vec;
      ;
    break;}
case 222:
#line 1334 "ppddl.y"
{
          yyval.invariant = new Invariant(Invariant::EXACTLY_ONE, *yyvsp[-1].condition_vec);
          delete yyvsp[-1].condition_vec;
      ;
    break;}
case 226:
#line 1347 "ppddl.y"
{
          yyval.clause = new Clause(*yyvsp[-1].condition_vec);
          delete yyvsp[-1].condition_vec;
      ;
    break;}
case 227:
#line 1354 "ppddl.y"
{
          yyval.oneof = new Oneof(*yyvsp[-1].condition_vec);
          delete yyvsp[-1].condition_vec;
      ;
    break;}
case 228:
#line 1361 "ppddl.y"
{
          yyval.unknown = new Unknown(*yyvsp[-1].atom);
          delete yyvsp[-1].atom;
      ;
    break;}
case 229:
#line 1368 "ppddl.y"
{
          if( type_ == PDDL_Parser::cp2fsc ) {
              log_error((char*)"':hidden' is not a valid element in cp2fsc.");
              yyerrok;
          } else {
#ifdef SMART
              dom_hidden_.push_back(owned_init_element_vec());
              for( owned_init_element_vec::iterator it = const_cast<owned_init_element_vec*>(yyvsp[-1].ilist)->begin(); it != const_cast<owned_init_element_vec*>(yyvsp[-1].ilist)->end(); ++it )
                  dom_hidden_.back().emplace_back(it->release());
#else
              dom_hidden_.push_back(*yyvsp[-1].ilist);
#endif
              delete yyvsp[-1].ilist;
          }
      ;
    break;}
case 230:
#line 1383 "ppddl.y"
{
          if( type_ == PDDL_Parser::cp2fsc ) {
              log_error((char*)"':hidden' is not a valid element in cp2fsc.");
              yyerrok;
          } else {
#ifdef SMART
              dom_hidden_.push_back(owned_init_element_vec());
#else
              dom_hidden_.push_back(init_element_vec());
#endif
          }
      ;
    break;}
case 231:
#line 1398 "ppddl.y"
{ dom_goal_ = yyvsp[-1].condition; ;
    break;}
case 232:
#line 1404 "ppddl.y"
{
          const_cast<And*>(static_cast<const And*>(yyvsp[-1].condition))->push_back(yyvsp[0].condition);
          yyval.condition = yyvsp[-1].condition;
      ;
    break;}
case 233:
#line 1408 "ppddl.y"
{
          And *cond = new And;
          cond->push_back(yyvsp[0].condition);
          yyval.condition = cond;
      ;
    break;}
case 234:
#line 1416 "ppddl.y"
{ yyval.condition = new Literal(*yyvsp[0].atom); delete yyvsp[0].atom; ;
    break;}
case 235:
#line 1417 "ppddl.y"
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
#line 3351 "grammar_tmp.cc"
#line 1420 "ppddl.y"


