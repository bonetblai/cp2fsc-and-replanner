/*
 *  Copyright (C) 2011 - <date> Blai Bonet, Universidad Simon Bolivar
 *
 *  Permission is hereby granted to distribute this software for
 *  non-commercial research purposes, provided that this copyright
 *  notice is included with any such distribution.
 *
 *  THIS SOFTWARE IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 *  EITHER EXPRESSED OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, THE
 *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 *  PURPOSE.  THE ENTIRE RISK AS TO THE QUALITY AND PERFORMANCE OF THE
 *  SOFTWARE IS WITH YOU.  SHOULD THE PROGRAM PROVE DEFECTIVE, YOU
 *  ASSUME THE COST OF ALL NECESSARY SERVICING, REPAIR OR CORRECTION.
 *
 *  Blai Bonet, bonet@ldc.usb.ve, bonetblai@gmail.com
 *
 */

%name PDDL_Scanner
%define LEX next_token
%define LEX_PARAM YY_PDDL_Parser_STYPE& val
%define DEBUG 1

%define MEMBERS \
  private: \
    StringTable& _tab; \
    bool  _reset; \
    char  *_filename; \
    int   _line_no; \
    bool  _trace_line; \
  public: \
    void  open_file(char *fname, bool trace); \
    void  open_file(bool trace); \
    void  close_file(); \
    char* current_file() const { return _filename; } \
    int   current_line() const { return _line_no; }

%define CONSTRUCTOR_PARAM StringTable& t
%define CONSTRUCTOR_INIT : _tab(t), _reset(false), _filename(0), _line_no(1), _trace_line(false)

%header{
#include <strings.h>
#include "string_table.h"
#include "grammar.h"
%}

CHAR [a-zA-Z_]
DIGIT [0-9]
INT -?{DIGIT}*
FLOAT -?{DIGIT}+(\.{DIGIT}*)?
STRING {CHAR}+(-|{CHAR}|{DIGIT})*
WHITESPACE [ \t]+
NL \n
COMMENT ;.*$

%%

[ \t]+                     ;
";".*\n                    { _line_no++;
                             if( _trace_line )
                                 cout << endl << "LINE: " << _line_no << endl;
                           }
{NL}                       { _line_no++;
                             if( _trace_line )
                                 cout << endl << "LINE: " << _line_no << endl;
                           }

"("                        { return PDDL_Parser::TK_OPEN; }
")"                        { return PDDL_Parser::TK_CLOSE; }
"["                        { return PDDL_Parser::TK_OPEN_SQ; }
"]"                        { return PDDL_Parser::TK_CLOSE_SQ; }
"-"                        { return PDDL_Parser::TK_HYPHEN; }
"="                        { return PDDL_Parser::TK_EQ; }

"define"                   { return PDDL_Parser::KW_DEFINE; }
"domain"                   { return PDDL_Parser::KW_DOMAIN; }
":requirements"            { return PDDL_Parser::KW_REQS; }
":types"                   { return PDDL_Parser::KW_TYPES; }
":constants"               { return PDDL_Parser::KW_CONSTANTS; }
":predicates"              { return PDDL_Parser::KW_PREDS; }
":observable"              { return PDDL_Parser::KW_OBSERVABLE; }
":sticky"                  { return PDDL_Parser::KW_STICKY; }
":fluents"                 { return PDDL_Parser::KW_FLUENTS; }
":action"                  { return PDDL_Parser::KW_ACTION; }
":axiom"                   { return PDDL_Parser::KW_AXIOM; }
":sensor"                  { return PDDL_Parser::KW_SENSOR; }
":parameters"              { return PDDL_Parser::KW_ARGS; }
":precondition"            { return PDDL_Parser::KW_PRE; }
":effect"                  { return PDDL_Parser::KW_EFFECT; }
":condition"               { return PDDL_Parser::KW_COND; }
":sense"                   { return PDDL_Parser::KW_SENSE; }
":observe"                 { return PDDL_Parser::KW_OBSERVE; }
":body"                    { return PDDL_Parser::KW_BODY; }
":head"                    { return PDDL_Parser::KW_HEAD; }
"true"                     { return PDDL_Parser::KW_TRUE; }
"false"                    { return PDDL_Parser::KW_FALSE; }
"and"                      { return PDDL_Parser::KW_AND; }
"exists"                   { return PDDL_Parser::KW_EXISTS; }
"forall"                   { return PDDL_Parser::KW_FORALL; }
"not"                      { return PDDL_Parser::KW_NOT; }
"when"                     { return PDDL_Parser::KW_WHEN; }
"invariant"                { return PDDL_Parser::KW_INVARIANT; }
"at-least-one"             { return PDDL_Parser::KW_AT_LEAST_ONE; }
"at-most-one"              { return PDDL_Parser::KW_AT_MOST_ONE; }
"exactly-one"              { return PDDL_Parser::KW_EXACTLY_ONE; }
"or"                       { return PDDL_Parser::KW_OR; }
"oneof"                    { return PDDL_Parser::KW_ONEOF; }
"unknown"                  { return PDDL_Parser::KW_UNKNOWN; }
"problem"                  { return PDDL_Parser::KW_PROBLEM; }
":domain"                  { return PDDL_Parser::KW_FORDOMAIN; }
":objects"                 { return PDDL_Parser::KW_OBJECTS; }
":init"                    { return PDDL_Parser::KW_INIT; }
":hidden"                  { return PDDL_Parser::KW_HIDDEN; }
":goal"                    { return PDDL_Parser::KW_GOAL; }
":explicit-initial-state"  { return PDDL_Parser::KW_EXPLICIT_INITIAL_STATE; }

":translation"             { return PDDL_Parser::KW_TRANSLATION; }
":variable"                { return PDDL_Parser::KW_VARIABLE; }
":obs-variable"            { return PDDL_Parser::KW_OBS_VARIABLE; }
":var-group"               { return PDDL_Parser::KW_VGROUP; }
":sensing"                 { return PDDL_Parser::KW_SENSING; }
":default-sensing"         { return PDDL_Parser::KW_DEFAULT_SENSING; }
"model-for"                { return PDDL_Parser::KW_MODEL_FOR; }
"such-that"                { return PDDL_Parser::KW_SUCH_THAT; }


\?{STRING} { val.sym = _tab.insert(yytext);
             if( val.sym->value_ == 0 )
                 return PDDL_Parser::TK_NEW_VAR_SYMBOL;
             if( static_cast<PDDL_Base::Symbol*>(val.sym->value_)->sym_class_ == PDDL_Base::sym_variable )
                 return PDDL_Parser::TK_VAR_SYMBOL;
             return PDDL_Parser::TK_NEW_VAR_SYMBOL;
           }

\:{STRING} { val.sym = _tab.insert(yytext);
             return PDDL_Parser::TK_KEYWORD;
           }

{STRING}   { val.sym = _tab.insert(yytext);
             if( val.sym->value_ == 0 ) {
                 return PDDL_Parser::TK_NEW_SYMBOL;
             } else {
                 switch( static_cast<PDDL_Base::Symbol*>(val.sym->value_)->sym_class_ ) {
                   case PDDL_Base::sym_object:
                     return PDDL_Parser::TK_OBJ_SYMBOL;
                   case PDDL_Base::sym_typename:
                     return PDDL_Parser::TK_TYPE_SYMBOL;
                   case PDDL_Base::sym_predicate:
                     return PDDL_Parser::TK_PRED_SYMBOL;
                   case PDDL_Base::sym_action:
                     return PDDL_Parser::TK_ACTION_SYMBOL;
                   case PDDL_Base::sym_sensor:
                     return PDDL_Parser::TK_SENSOR_SYMBOL;
                   case PDDL_Base::sym_axiom:
                     return PDDL_Parser::TK_AXIOM_SYMBOL;
                   case PDDL_Base::sym_varname:
                     return PDDL_Parser::TK_VARNAME_SYMBOL;
                   default:
                     return PDDL_Parser::TK_MISC_SYMBOL;
                 }
             }
           }

{INT}      { val.ival = atoi(yytext); return PDDL_Parser::TK_INT; }

%%

/*{FLOAT}    { val.rval = A_TO_NN(yytext); return PDDL_Parser::TK_FLOAT; }*/

int yywrap() {
    return 1;
}

void PDDL_Scanner::open_file(char* name, bool trace) {
    yyin = fopen(name, "r");
    if( !yyin ) {
        cout << Utils::error() << "can't open " << name << endl;
        exit(255);
    }
    _filename = name;
    if( _reset ) yy_init_buffer(YY_PDDL_Scanner_CURRENT_BUFFER, yyin);
    _reset = true;
    _line_no = 1;
    _trace_line = trace;
    yy_flex_debug = trace;
}

void PDDL_Scanner::open_file(bool trace) {
    yyin = stdin;
    _filename = strdup("<stdin>");
    if( _reset ) yy_init_buffer(YY_PDDL_Scanner_CURRENT_BUFFER, yyin);
    _reset = true;
    _line_no = 1;
    _trace_line = trace;
    yy_flex_debug = trace;
}

void PDDL_Scanner::close_file() {
    if( _filename != 0 ) {
        fclose(yyin);
        _filename = 0;
    }
}

