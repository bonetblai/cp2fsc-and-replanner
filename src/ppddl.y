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

%name PDDL_Parser
%define ERROR log_error
%define ERROR_BODY = 0
%define ERROR_VERBOSE 1
%define LEX next_token
%define LEX_BODY = 0
%define DEBUG 1

%define INHERIT : public PDDL_Base
%define CONSTRUCTOR_PARAM StringTable &parser_symbol_table, int type, const Options::Mode &options
%define CONSTRUCTOR_INIT : PDDL_Base(parser_symbol_table, options), error_flag_(false), type_(type), effect_vec_ptr_(0)
%define MEMBERS \
  public: \
    typedef enum { replanner, cp2fsc } Type; \
    virtual ~PDDL_Parser() { } \
    virtual std::ostream& syntax_errors() = 0; \
    bool error_flag_; \
    int type_; \
  private: \
    std::vector<Schema*> schema_; \
    std::vector<std::unique_ptr<Schema> > owned_schema_; \
    std::vector<bool> using_owned_schema_; \
    effect_vec *effect_vec_ptr_;

%header{
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
%}

%union {
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
}

%token                        TK_OPEN TK_CLOSE TK_OPEN_SQ TK_CLOSE_SQ TK_EQ TK_HYPHEN

%token <sym>                  TK_NEW_SYMBOL TK_OBJ_SYMBOL TK_TYPE_SYMBOL TK_PRED_SYMBOL
                              TK_VAR_SYMBOL TK_ACTION_SYMBOL TK_AXIOM_SYMBOL TK_SENSOR_SYMBOL
                              TK_MISC_SYMBOL TK_KEYWORD TK_NEW_VAR_SYMBOL
                              TK_VARNAME_SYMBOL

%token <ival>                 TK_INT

%token                        KW_REQS KW_TRANSLATION
                              KW_CONSTANTS KW_PREDS KW_TYPES KW_DEFINE KW_DOMAIN
                              KW_ACTION KW_ARGS KW_PRE KW_EFFECT KW_AND KW_TRUE KW_FALSE
                              KW_OR KW_EXISTS KW_FORALL KW_SUCH_THAT KW_NOT KW_WHEN KW_ONEOF KW_UNKNOWN
                              KW_PROBLEM KW_FORDOMAIN KW_OBJECTS KW_INIT KW_GOAL KW_EXPLICIT_INITIAL_STATE
                              KW_SENSOR KW_SENSE KW_OBSERVE KW_AXIOM KW_COND KW_OBSERVABLE
                              KW_BODY KW_HEAD KW_STICKY KW_FLUENTS KW_HIDDEN
                              KW_INVARIANT KW_AT_LEAST_ONE KW_AT_MOST_ONE KW_EXACTLY_ONE

%token                        KW_TRANSLATION
                              KW_VARIABLE KW_OBS_VARIABLE KW_VGROUP
                              KW_SENSING KW_DEFAULT_SENSING KW_MODEL_FOR

%type <vsym>                  new_var_symbol
%type <sym>                   action_symbol any_symbol sensor_symbol axiom_symbol
%type <param>                 argument_list
%type <vparam>                param_list typed_param_list untyped_param_list param_sym_list

%type <sym>                   primitive_type
%type <atom>                  positive_literal negative_literal literal
%type <condition_vec>         single_condition_list condition_list
%type <condition>             condition constant_condition single_condition and_condition or_condition
%type <condition>             forall_condition exists_condition
%type <condition>             goal_list single_goal
%type <invariant>             invariant at_least_one_invariant at_most_one_invariant exactly_one_invariant
%type <clause>                clause
%type <oneof>                 oneof
%type <unknown>               unknown
%type <effect_vec>            positive_atomic_effect_list atomic_effect_list action_effect_list
%type <effect>                atomic_effect positive_atomic_effect
%type <effect>                action_effect single_action_effect conditional_effect forall_effect
%type <effect>                atomic_effect_kw_list
%type <effect>                fluent_decl
%type <ilist>                 init_elements
%type <ielem>                 single_init_element
%type <ival>                  initial_state_keyword

%type <sensing_proxy_list>    sensing sensing_decl_list
%type <sensing_proxy>         sensing_decl forall_sensing
%type <sensing_model>         sensing_model

%type <state_variable_list>       state_variable forall_state_variable_list_decl
%type <state_variable_list_vec>   state_variable_list_decl

%type <ival>                  variable_type

%start pddl_decls

%%

pddl_decls:
      pddl_domain pddl_decls
    | pddl_problem pddl_decls
    | /* empty */
    ;

pddl_domain:
      TK_OPEN KW_DEFINE domain_name domain_elements TK_CLOSE
    | TK_OPEN KW_DEFINE domain_name error TK_CLOSE {
          log_error((char*)"syntax error in domain");
          yyerrok;
      }
    ;

domain_elements:
      domain_elements domain_requires
    | domain_elements domain_types
    | domain_elements domain_constants
    | domain_elements domain_predicates
    | domain_elements domain_schemas
    | domain_elements domain_default_sensing
    | /* empty */
    ;

domain_name:
      TK_OPEN KW_DOMAIN any_symbol TK_CLOSE { domain_name_ = std::string($3->text_); }
    ;

// symbols

any_symbol:
      TK_NEW_SYMBOL { $$ = $1; }
    | TK_OBJ_SYMBOL { $$ = $1; }
    | TK_TYPE_SYMBOL { $$ = $1; }
    | TK_PRED_SYMBOL { $$ = $1; }
    | TK_VAR_SYMBOL { $$ = $1; }
    | TK_ACTION_SYMBOL { $$ = $1; }
    | TK_AXIOM_SYMBOL { $$ = $1; }
    | TK_SENSOR_SYMBOL { $$ = $1; }
    | TK_MISC_SYMBOL { $$ = $1; }
    ;

action_symbol:
      TK_NEW_SYMBOL { $$ = $1; }
    | TK_ACTION_SYMBOL { $$ = $1; }
    ;

sensor_symbol:
      TK_NEW_SYMBOL { $$ = $1; }
    | TK_SENSOR_SYMBOL { $$ = $1; }
    ;

axiom_symbol:
      TK_NEW_SYMBOL { $$ = $1; }
    | TK_AXIOM_SYMBOL { $$ = $1; }
    ;

// requirement declarations

domain_requires:
      TK_OPEN KW_REQS require_list TK_CLOSE
    | TK_OPEN KW_REQS error TK_CLOSE {
          log_error((char*)"syntax error in requirements declaration.");
          yyerrok;
      }
    ;

require_list:
      require_list KW_TRANSLATION { declare_lw1_translation(); }
    | require_list TK_KEYWORD
    | /* empty */
    ;

// predicate declarations

domain_predicates:
      TK_OPEN KW_PREDS predicate_list TK_CLOSE
    | TK_OPEN KW_PREDS error TK_CLOSE {
          log_error((char*)"syntax error in (:predicates ...)");
          yyerrok;
      }
    ;

predicate_list:
      predicate_list predicate_decl
    | predicate_decl
    ;

predicate_decl:
      TK_OPEN TK_NEW_SYMBOL param_list TK_CLOSE {
          PredicateSymbol *p = new PredicateSymbol($2->text_);
          dom_predicates_.push_back(p);
          p->param_ = *$3;
          delete $3;
          clear_param(p->param_);
          $2->value_ = p;
      }
    | TK_OPEN error TK_CLOSE {
          log_error((char*)"syntax error in predicate declaration");
          yyerrok;
      }
    ;

param_list:
      untyped_param_list
    | typed_param_list {
          // must reverse parameter list
          var_symbol_vec tmp_list(*$1);
          $1->clear();
          $1->insert($1->end(), tmp_list.rbegin(), tmp_list.rend());
          $$ = $1;
      }
    | /* empty */ { $$ = new var_symbol_vec; }
    ;

untyped_param_list:
      param_sym_list {
          set_variable_type(*$1, $1->size(), dom_top_type_);
          $$ = $1;
      }
    ;

typed_param_list:
      param_sym_list TK_HYPHEN TK_TYPE_SYMBOL typed_param_list {
          set_variable_type(*$1, $1->size(), static_cast<TypeSymbol*>($3->value_));
          $4->insert($4->end(), $1->begin(), $1->end());
          delete $1;
          $$ = $4;
      }
    | param_sym_list TK_HYPHEN TK_TYPE_SYMBOL {
          set_variable_type(*$1, $1->size(), static_cast<TypeSymbol*>($3->value_));
          $$ = $1;
      }
    ;

param_sym_list:
      new_var_symbol param_sym_list {
          $2->push_back(static_cast<VariableSymbol*>($1));
          $$ = $2;
      }
    | new_var_symbol { $$ = new var_symbol_vec; $$->push_back($1); }
    ;

new_var_symbol:
      TK_NEW_VAR_SYMBOL {
          VariableSymbol *var = new VariableSymbol($1->text_);
          $1->value_ = var;
          $$ = var;
      }
    | TK_VAR_SYMBOL {
          std::string msg("variable '");
          msg += $1->text_;
          msg += "' shadows variable in outer scope: this is not supported!";
          log_error((char*)msg.c_str());
          yyerrok;
      }
    ;

// type declarations

domain_types:
      TK_OPEN KW_TYPES primitive_type_list TK_CLOSE
    | TK_OPEN KW_TYPES typed_type_list TK_CLOSE {
          set_type_type(dom_types_, dom_types_.size(), dom_top_type_);
      }
    ;

typed_type_list:
      primitive_type_list TK_HYPHEN TK_TYPE_SYMBOL typed_type_list {
          set_type_type(dom_types_, dom_types_.size(), static_cast<TypeSymbol*>($3->value_));
      }
    | primitive_type_list TK_HYPHEN TK_NEW_SYMBOL typed_type_list {
          $3->value_ = new TypeSymbol($3->text_);
          if( write_warnings_ )
              std::cout << Utils::warning() << "assuming " << $3->text_ << " - object" << std::endl;
          static_cast<TypeSymbol*>($3->value_)->sym_type_ = dom_top_type_;
          set_type_type(dom_types_, dom_types_.size(), static_cast<TypeSymbol*>($3->value_));
          dom_types_.push_back(static_cast<TypeSymbol*>($3->value_));
      }
    | /* empty */
    ;

primitive_type_list:
      primitive_type_list primitive_type
    | primitive_type { }
    ;

primitive_type:
      TK_TYPE_SYMBOL
    | TK_NEW_SYMBOL {
          $1->value_ = new TypeSymbol($1->text_);
          dom_types_.push_back(static_cast<TypeSymbol*>($1->value_));
      }
    ;

// constant declarations

domain_constants:
      TK_OPEN KW_CONSTANTS typed_constant_list TK_CLOSE
    | TK_OPEN KW_OBJECTS typed_constant_list TK_CLOSE
    | TK_OPEN KW_CONSTANTS untyped_constant_list TK_CLOSE
    | TK_OPEN KW_OBJECTS untyped_constant_list TK_CLOSE
    ;

typed_constant_list:
      constant_sym_list TK_HYPHEN TK_TYPE_SYMBOL {
          set_constant_type(dom_constants_, dom_constants_.size(), static_cast<TypeSymbol*>($3->value_));
      }
      typed_constant_list
    | /* empty */
    ;

untyped_constant_list:
      constant_sym_list {
          set_constant_type(dom_constants_, dom_constants_.size(), dom_top_type_);
      }
    ;

constant_sym_list:
      constant_sym_list TK_NEW_SYMBOL {
          $2->value_ = new Symbol($2->text_);
          dom_constants_.push_back(static_cast<Symbol*>($2->value_));
      }
    | TK_NEW_SYMBOL {
          $1->value_ = new Symbol($1->text_);
          dom_constants_.push_back(static_cast<Symbol*>($1->value_));
      }
    ;

// structure declarations

domain_schemas:
      action_decl
    | axiom_decl {
          if( type_ == replanner ) {
              log_error((char*)"':axiom' is not a valid element in k-replanner.");
              yyerrok;
          }
      }
    | sensor_decl {
          if( type_ == cp2fsc ) {
              log_error((char*)"':sensor' is not a valid element in cp2fsc.");
              yyerrok;
          }
      }
    | observable_decl {
          if( type_ == replanner ) {
              log_error((char*)"':observable' is not a valid element in k-replanner.");
              yyerrok;
          }
      }
    | sticky_decl {
          if( type_ == replanner ) {
              log_error((char*)"':sticky' is not a valid element in k-replanner.");
              yyerrok;
          }
      }
    | simple_variable_decl {
          declare_lw1_translation();
          if( type_ == cp2fsc ) {
              log_error((char*)"':sensor' is not a valid element in cp2fsc.");
              yyerrok;
          }
      }
    | variable_group_decl { }
    ;


// structure declarations

action_decl:
      TK_OPEN KW_ACTION action_symbol {
#ifdef SMART
          std::unique_ptr<Action> na = std::make_unique<Action>($3->text_);
          dom_actions_.emplace_back(std::move(na));
#else
          Action *na = new Action($3->text_);
          dom_actions_.push_back(na);
#endif
      }
      action_elements TK_CLOSE {
          clear_param(dom_actions_.back()->param_);
#ifdef SMART
          $3->value_ = dom_actions_.back().get();
#else
          $3->value_ = dom_actions_.back();
#endif
      }
    | TK_OPEN KW_ACTION error TK_CLOSE {
          log_error((char*)"syntax error in action declaration");
          yyerrok;
      }
    ;

action_elements:
      action_elements KW_ARGS TK_OPEN param_list TK_CLOSE {
          dom_actions_.back()->param_ = *$4;
          delete $4;
      }
    | action_elements KW_PRE condition { dom_actions_.back()->precondition_ = $3; }
    | action_elements KW_EFFECT action_effect { dom_actions_.back()->effect_ = $3; }
    | action_elements KW_OBSERVE positive_atomic_effect_list {
          declare_clg_translation();
          dom_actions_.back()->observe_ = new AndEffect(*$3);
          delete $3;
      }
    | action_elements KW_SENSING sensing {
          declare_lw1_translation();
          dom_actions_.back()->sensing_proxy_ = $3;
      }
    | /* empty */
    ;

condition:
      constant_condition
    | single_condition
    | and_condition
    | or_condition
    | forall_condition
    | exists_condition
    ;

constant_condition:
      KW_TRUE { $$ = new Constant(true); }
    | KW_FALSE { $$ = new Constant(false); }
    ;

single_condition:
      literal {
          // if literal is for equality, construct EQ
          if( $1->pred_ == dom_eq_pred_ )
              $$ = new EQ(dynamic_cast<VariableSymbol*>($1->param_[0]), dynamic_cast<VariableSymbol*>($1->param_[1]), $1->negated_);
          else
              $$ = new Literal(*$1);
          delete $1;
      }
    ;

literal:
      positive_literal
    | negative_literal
    ;

positive_literal:
      TK_OPEN TK_PRED_SYMBOL argument_list TK_CLOSE {
          PredicateSymbol* p = static_cast<PredicateSymbol*>($2->value_);
          if( p->param_.size() != $3->size() ) {
              std::string msg = std::string("wrong number of arguments for predicate '") + p->print_name_ + "'";
              log_error(const_cast<char*>(msg.c_str()));
          } else {
              $$ = new Atom(p);
              $$->param_ = *$3;
              delete $3;
          }
      }
    | TK_OPEN TK_EQ argument_list TK_CLOSE {
          if( $3->size() != 2 ) {
              log_error((char*)"wrong number of arguments for equality");
          } else {
              $$ = new Atom(dom_eq_pred_);
              $$->param_ = *$3;
              delete $3;
          }
      }
    ;

negative_literal:
      TK_OPEN KW_NOT positive_literal TK_CLOSE {
          const_cast<Literal*>(static_cast<const Literal*>($3))->negated_ = true;
          $$ = $3;
      }
    ;

argument_list:
      argument_list TK_VAR_SYMBOL {
          if( $2->value_ == 0 )
              log_error((char*)"undeclared variable in atom args list");
          else
              $1->push_back(static_cast<VariableSymbol*>($2->value_));
          $$ = $1;
      }
    | argument_list TK_OBJ_SYMBOL {
          $1->push_back(static_cast<Symbol*>($2->value_));
          $$ = $1;
      }
    | /* empty */ { $$ = new symbol_vec; }
    ;

and_condition:
      TK_OPEN KW_AND condition_list TK_CLOSE {
          $$ = new And(*$3);
          delete $3;
      }
    ;

or_condition:
      TK_OPEN KW_OR condition_list TK_CLOSE {
          $$ = new Or(*$3);
          delete $3;
      }
    ;

forall_condition:
      TK_OPEN KW_FORALL TK_OPEN {
          schema_.push_back(new ForallCondition);
          using_owned_schema_.push_back(false);
      }
      param_list TK_CLOSE {
          schema_.back()->param_ = *$5;
          delete $5;
      }
      condition TK_CLOSE {
          assert(dynamic_cast<ForallCondition*>(schema_.back()) != 0);
          ForallCondition *forall_condition = static_cast<ForallCondition*>(schema_.back());
          schema_.pop_back();
          using_owned_schema_.pop_back();
          forall_condition->condition_ = $8;
          clear_param(forall_condition->param_);
          $$ = forall_condition;
      }
    ;

exists_condition:
      TK_OPEN KW_EXISTS TK_OPEN {
          schema_.push_back(new ExistsCondition);
          using_owned_schema_.push_back(false);
      }
      param_list TK_CLOSE {
          schema_.back()->param_ = *$5;
          delete $5;
      }
      condition TK_CLOSE {
          assert(dynamic_cast<ExistsCondition*>(schema_.back()) != 0);
          ExistsCondition *exists_condition = static_cast<ExistsCondition*>(schema_.back());
          schema_.pop_back();
          using_owned_schema_.pop_back();
          exists_condition->condition_ = $8;
          clear_param(exists_condition->param_);
          $$ = exists_condition;
      }
    ;

single_condition_list:
      single_condition_list single_condition {
          $1->push_back($2);
          $$ = $1;
      }
    | single_condition {
          condition_vec *cond_vec = new condition_vec;
          cond_vec->push_back($1);
          $$ = cond_vec;
      }
    ;

condition_list:
      condition_list condition {
          $1->push_back($2);
          $$ = $1;
      }
    | condition {
          condition_vec *cond_vec = new condition_vec;
          cond_vec->push_back($1);
          $$ = cond_vec;
      }
    ;

action_effect:
      single_action_effect
    | TK_OPEN KW_AND action_effect_list TK_CLOSE {
          $$ = new AndEffect(*$3);
          delete $3;
      }
    ;

action_effect_list:
      action_effect_list single_action_effect {
          $1->push_back($2);
          $$ = $1;
      }
    | single_action_effect {
          $$ = new effect_vec;
          $$->push_back($1);
      }
    ;

single_action_effect:
      atomic_effect
    | conditional_effect
    | forall_effect
    ;

conditional_effect:
      TK_OPEN KW_WHEN condition atomic_effect_kw_list TK_CLOSE { $$ = new ConditionalEffect($3, $4); }
    ;

forall_effect:
      TK_OPEN KW_FORALL TK_OPEN {
          schema_.push_back(new ForallEffect);
          using_owned_schema_.push_back(false);
      }
      param_list TK_CLOSE {
          schema_.back()->param_ = *$5;
          delete $5;
      }
      optional_such_that action_effect TK_CLOSE {
          assert(dynamic_cast<ForallEffect*>(schema_.back()) != 0);
          ForallEffect *forall_effect = static_cast<ForallEffect*>(schema_.back());
          schema_.pop_back();
          using_owned_schema_.pop_back();
          forall_effect->effect_ = $9;
          clear_param(forall_effect->param_);
          $$ = forall_effect;
      }
    ;

optional_such_that:
      KW_SUCH_THAT condition {
#ifdef SMART
          if( using_owned_schema_.back() ) {
              assert(!owned_schema_.empty());
              owned_schema_.back()->such_that_ = $2;
          } else {
              assert(!schema_.empty());
              schema_.back()->such_that_ = $2;
          }
#else
          assert(!schema_.empty());
          schema_.back()->such_that_ = $2;
#endif
      }
    | /* empty */
    ;

atomic_effect_kw_list:
      TK_OPEN KW_AND atomic_effect_list TK_CLOSE {
          $$ = new AndEffect(*$3);
          delete $3;
      }
    | atomic_effect
    ;

atomic_effect_list:
      atomic_effect_list atomic_effect {
          $1->push_back($2);
          $$ = $1;
      }
    | atomic_effect {
          $$ = new effect_vec;
          $$->push_back($1);
      }
    ;

positive_atomic_effect_list:
      positive_atomic_effect_list positive_atomic_effect {
          $1->push_back($2);
          $$ = $1;
      }
    | positive_atomic_effect {
          $$ = new effect_vec;
          $$->push_back($1);
      }
    ;

atomic_effect:
      literal { $$ = new AtomicEffect(*$1); delete $1; }
    ;

positive_atomic_effect:
      positive_literal { $$ = new AtomicEffect(*$1); delete $1; }
    ;

sensing:
      sensing_decl_list
    | /* empty */ { $$ = 0; }
    ;

sensing_decl_list:
      sensing_decl_list sensing_decl {
          sensing_proxy_vec *list_sensing_proxy = const_cast<sensing_proxy_vec*>($1);
          list_sensing_proxy->push_back($2);
          $$ = list_sensing_proxy;
      }
    | sensing_decl {
          sensing_proxy_vec *list_sensing_proxy = new sensing_proxy_vec;
          list_sensing_proxy->push_back($1);
          $$ = list_sensing_proxy;
      }
    ;

sensing_decl:
      sensing_model { $$ = new BasicSensingModel($1); }
    | forall_sensing
    ;

forall_sensing:
      TK_OPEN KW_FORALL TK_OPEN {
          schema_.push_back(new ForallSensing);
          using_owned_schema_.push_back(false);
      }
      param_list TK_CLOSE {
          schema_.back()->param_ = *$5;
          delete $5;
      }
      optional_such_that sensing_decl_list TK_CLOSE {
          assert(dynamic_cast<ForallSensing*>(schema_.back()) != 0);
          ForallSensing *forall_sensing = static_cast<ForallSensing*>(schema_.back());
          schema_.pop_back();
          using_owned_schema_.pop_back();
          forall_sensing->sensing_ = *$9;
          delete $9;
          clear_param(forall_sensing->param_);
          $$ = forall_sensing;
      }
    ;

sensing_model:
      TK_OPEN KW_MODEL_FOR TK_VARNAME_SYMBOL literal condition TK_CLOSE {
          assert(static_cast<Symbol*>($3->value_)->sym_class_ == sym_varname);
          const Variable *variable = static_cast<Variable*>($3->value_);
          if( dynamic_cast<const ObsVariable*>(variable) == 0 ) {
              std::cout << Utils::error() << "sensing model can only be specified for observable variable" << std::endl;
              $$ = 0;
          } else {
              const ObsVariable *obs_variable = static_cast<const ObsVariable*>(variable);
              assert(dynamic_cast<const ObsVariable*>(variable) != 0);
              $$ = new SensingModelForObservableVariable(obs_variable, new Literal(*$4), $5);
          }
      }
    | TK_OPEN KW_MODEL_FOR TK_OPEN TK_VARNAME_SYMBOL argument_list TK_CLOSE literal condition TK_CLOSE {
          assert(static_cast<Symbol*>($4->value_)->sym_class_ == sym_varname);
          const Variable *variable = static_cast<Variable*>($4->value_);
          if( dynamic_cast<const ObsVariable*>(variable) == 0 ) {
              std::cout << Utils::error() << "sensing model can only be specified for observable variable" << std::endl;
              $$ = 0;
          } else {
              const ObsVariable *obs_variable = static_cast<const ObsVariable*>(variable);
              assert(dynamic_cast<const ObsVariable*>(variable) != 0);
              SensingModelForObservableVariable *model = new SensingModelForObservableVariable(obs_variable, new Literal(*$7), $8);
              model->param_ = *$5;
              delete $5;
              $$ = model;
          }
      }
    | TK_OPEN KW_VARIABLE TK_VARNAME_SYMBOL TK_CLOSE {
          assert(static_cast<Symbol*>($3->value_)->sym_class_ == sym_varname);
          const Variable *variable = static_cast<Variable*>($3->value_);
          assert(dynamic_cast<const StateVariable*>(variable) != 0);
          $$ = new SensingModelForStateVariable(static_cast<const StateVariable*>(variable));
      }
    | TK_OPEN KW_VARIABLE TK_OPEN TK_VARNAME_SYMBOL argument_list TK_CLOSE TK_CLOSE {
          assert(static_cast<Symbol*>($4->value_)->sym_class_ == sym_varname);
          const Variable *variable = static_cast<Variable*>($4->value_);
          assert(dynamic_cast<const StateVariable*>(variable) != 0);
          SensingModelForStateVariable *model = new SensingModelForStateVariable(static_cast<const StateVariable*>(variable));
          model->param_ = *$5;
          delete $5;
          $$ = model;
      }
    | TK_OPEN KW_VARIABLE error TK_CLOSE {
          log_error((char*)"syntax error in sensing declaration for ':variable'");
          yyerrok;
      }
    | TK_OPEN KW_MODEL_FOR error TK_CLOSE {
          log_error((char*)"syntax error in sensing declaration for ':model-for'");
          yyerrok;
      }
    ;

axiom_decl:
      TK_OPEN KW_AXIOM axiom_symbol {
#ifdef SMART
          std::unique_ptr<Axiom> nr = std::make_unique<Axiom>($3->text_);
          dom_axioms_.emplace_back(std::move(nr));
#else
          Axiom *nr = new Axiom($3->text_);
          dom_axioms_.push_back(nr);
#endif
      }
      axiom_elements TK_CLOSE {
          clear_param(dom_axioms_.back()->param_);
#ifdef SMART
          $3->value_ = dom_axioms_.back().get();
#else
          $3->value_ = dom_axioms_.back();
#endif
      }
    | TK_OPEN KW_AXIOM error TK_CLOSE {
          log_error((char*)"syntax error in axiom declaration");
          yyerrok;
      }
    ;

axiom_elements:
      axiom_elements KW_ARGS TK_OPEN param_list TK_CLOSE {
          dom_axioms_.back()->param_ = *$4;
          delete $4;
      }
    | axiom_elements KW_BODY condition { dom_axioms_.back()->body_ = $3; }
    | axiom_elements KW_HEAD atomic_effect_kw_list { dom_axioms_.back()->head_ = $3; }
    | /* empty */
    ;

sensor_decl:
      TK_OPEN KW_SENSOR sensor_symbol {
#ifdef SMART
          std::unique_ptr<Sensor> nr = std::make_unique<Sensor>($3->text_);
          dom_sensors_.emplace_back(std::move(nr));
#else
          Sensor *nr = new Sensor($3->text_);
          dom_sensors_.push_back(nr);
#endif
      }
      sensor_elements TK_CLOSE {
          clear_param(dom_sensors_.back()->param_);
#ifdef SMART
          $3->value_ = dom_sensors_.back().get();
#else
          $3->value_ = dom_sensors_.back();
#endif
      }
    | TK_OPEN KW_SENSOR error TK_CLOSE {
          log_error((char*)"syntax error in sensor declaration");
          yyerrok;
      }
    ;

sensor_elements:
      sensor_elements KW_ARGS TK_OPEN param_list TK_CLOSE {
          dom_sensors_.back()->param_ = *$4;
          delete $4;
      }
    | sensor_elements KW_COND condition {
          dom_sensors_.back()->condition_ = $3;
      }
    | sensor_elements KW_SENSE positive_atomic_effect_list {
          dom_sensors_.back()->sense_ = new AndEffect(*$3);
          delete $3;
      }
    | /* empty */
    ;

observable_decl:
      TK_OPEN KW_OBSERVABLE {
#ifdef SMART
          std::unique_ptr<Observable> obs = std::make_unique<Observable>();
          effect_vec_ptr_ = &obs->observables_;
          dom_observables_.emplace_back(std::move(obs));
#else
          Observable *obs = new Observable;
          dom_observables_.push_back(obs);
          effect_vec_ptr_ = &obs->observables_;
#endif
      }
      fluent_list_decl TK_CLOSE
    | TK_OPEN KW_OBSERVABLE error TK_CLOSE {
          log_error((char*)"syntax error in observable declaration");
          yyerrok;
      }
    ;

fluent_list_decl:
      fluent_list_decl fluent_decl {
          effect_vec_ptr_->push_back($2);
      }
    | fluent_decl {
          effect_vec_ptr_->push_back($1);
      }
    ;

fluent_decl:
      positive_atomic_effect
    | forall_effect
    ;

sticky_decl:
      TK_OPEN KW_STICKY {
#ifdef SMART
          std::unique_ptr<Sticky> sticky = std::make_unique<Sticky>();
          effect_vec_ptr_ = &sticky->stickies_;
          dom_stickies_.emplace_back(std::move(sticky));
#else
          Sticky *sticky = new Sticky;
          dom_stickies_.push_back(sticky);
          effect_vec_ptr_ = &sticky->stickies_;
#endif
      }
      fluent_list_decl TK_CLOSE
    | TK_OPEN KW_STICKY error TK_CLOSE {
          log_error((char*)"syntax error in sticky declaration");
          yyerrok;
      }
    ;

simple_variable_decl:
      TK_OPEN variable_type TK_NEW_SYMBOL {
#ifdef SMART
          std::unique_ptr<Variable> var;
          if( $2 == 0 )
              var = std::make_unique<StateVariable>($3->text_);
          else
              var = std::make_unique<ObsVariable>($3->text_);
          effect_vec_ptr_ = &var->domain_;
          lw1_uninstantiated_variables_.emplace_back(std::move(var));
#else
          Variable *var = 0;
          if( $2 == 0 )
              var = new StateVariable($3->text_);
          else
              var = new ObsVariable($3->text_);
          lw1_uninstantiated_variables_.push_back(var);
          effect_vec_ptr_ = &var->domain_;
#endif
      }
      fluent_list_decl TK_CLOSE {
#ifdef SMART
          $3->value_ = lw1_uninstantiated_variables_.back().get();
#else
          $3->value_ = lw1_uninstantiated_variables_.back();
#endif
      }
    | TK_OPEN variable_type TK_OPEN TK_NEW_SYMBOL {
#ifdef SMART
          std::unique_ptr<Variable> var;
          if( $2 == 0 )
              var = std::make_unique<StateVariable>($4->text_);
          else
              var = std::make_unique<ObsVariable>($4->text_);
          effect_vec_ptr_ = &var->domain_;
          owned_schema_.emplace_back(std::move(var));
          using_owned_schema_.push_back(true);
#else
          Variable *var = 0;
          if( $2 == 0 )
              var = new StateVariable($4->text_);
          else
              var = new ObsVariable($4->text_);
          effect_vec_ptr_ = &var->domain_;
          schema_.push_back(var);
          using_owned_schema_.push_back(false);
#endif
      }
      param_list TK_CLOSE {
#ifdef SMART
          owned_schema_.back()->param_ = *$6;
#else
          schema_.back()->param_ = *$6;
#endif
          delete $6;
      }
      optional_such_that fluent_list_decl TK_CLOSE {
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
          $4->value_ = variable.get();
          lw1_uninstantiated_variables_.emplace_back(std::move(variable));
#else
          $4->value_ = variable;
          lw1_uninstantiated_variables_.push_back(variable);
#endif
      }
    | TK_OPEN KW_VARIABLE error TK_CLOSE {
          log_error((char*)"syntax error in state variable declaration");
          yyerrok;
      }
    ;

variable_type:
      KW_VARIABLE { $$ = 0; }
    | KW_OBS_VARIABLE { $$ = 1; }
    ;

variable_group_decl:
      TK_OPEN KW_VGROUP TK_NEW_SYMBOL {
#ifdef SMART
          std::unique_ptr<VariableGroup> group = std::make_unique<VariableGroup>($3->text_);
          lw1_uninstantiated_variable_groups_.emplace_back(std::move(group));
#else
          VariableGroup *group = new VariableGroup($3->text_);
          lw1_uninstantiated_variable_groups_.push_back(group);
#endif
      }
      state_variable_list_decl TK_CLOSE {
          lw1_uninstantiated_variable_groups_.back()->group_ = *$5;
          delete $5;
      }
    | TK_OPEN KW_VGROUP TK_OPEN TK_NEW_SYMBOL {
#ifdef SMART
          std::unique_ptr<VariableGroup> group = std::make_unique<VariableGroup>($4->text_);
          owned_schema_.emplace_back(std::move(group));
          using_owned_schema_.push_back(true);
#else
          VariableGroup *group = new VariableGroup($4->text_);
          schema_.push_back(group);
          using_owned_schema_.push_back(false);
#endif
      }
      param_list TK_CLOSE {
#ifdef SMART
          owned_schema_.back()->param_ = *$6;
#else
          schema_.back()->param_ = *$6;
#endif
          delete $6;
      }
      optional_such_that state_variable_list_decl TK_CLOSE {
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
          group->group_ = *$10;
          delete $10;
          clear_param(group->param_);
#ifdef SMART
          $4->value_ = group.get();
          lw1_uninstantiated_variable_groups_.emplace_back(std::move(group));
#else
          $4->value_ = group;
          lw1_uninstantiated_variable_groups_.push_back(group);
#endif
      }
    | TK_OPEN KW_VGROUP error TK_CLOSE {
          log_error((char*)"syntax error in variable group declaration");
          yyerrok;
      }
    ;

state_variable_list_decl:
      state_variable_list_decl state_variable {
          state_variable_list_vec *varlist = const_cast<state_variable_list_vec*>($1);
          assert(dynamic_cast<const SingleStateVariableList*>($2) != 0);
          varlist->push_back(const_cast<StateVariableList*>($2));
          $$ = varlist;
      }
    | state_variable_list_decl forall_state_variable_list_decl {
          state_variable_list_vec *varlist = const_cast<state_variable_list_vec*>($1);
          assert(dynamic_cast<const ForallStateVariableList*>($2) != 0);
          varlist->push_back(const_cast<StateVariableList*>($2));
          $$ = varlist;
      }
    | /* empty */ { $$ = new state_variable_list_vec; }
    ;

state_variable:
      TK_VARNAME_SYMBOL {
          assert(static_cast<Symbol*>($1->value_)->sym_class_ == sym_varname);
          const Variable *var = static_cast<Variable*>($1->value_);
          if( dynamic_cast<const StateVariable*>(var) == 0 ) {
              std::cout << Utils::error() << "only state variables can be grouped together" << std::endl;
          }
          $$ = new SingleStateVariableList(var->print_name_);
      }
    | TK_OPEN TK_VARNAME_SYMBOL argument_list TK_CLOSE {
          assert(static_cast<Symbol*>($2->value_)->sym_class_ == sym_varname);
          const Variable *var = static_cast<Variable*>($2->value_);
          if( dynamic_cast<const StateVariable*>(var) == 0 ) {
              std::cout << Utils::error() << "only state variables can be grouped together" << std::endl;
          }
          SingleStateVariableList *single = new SingleStateVariableList(var->print_name_);
          single->param_ = *$3;
          delete $3;
          $$ = single;
      }
    ;

forall_state_variable_list_decl:
      TK_OPEN KW_FORALL TK_OPEN {
          schema_.push_back(new ForallStateVariableList);
          using_owned_schema_.push_back(false);
      }
      param_list TK_CLOSE {
          schema_.back()->param_ = *$5;
          delete $5;
      }
      optional_such_that state_variable_list_decl TK_CLOSE {
          assert(dynamic_cast<ForallStateVariableList*>(schema_.back()) != 0);
          ForallStateVariableList *forall_state_variable_list = static_cast<ForallStateVariableList*>(schema_.back());
          schema_.pop_back();
          using_owned_schema_.pop_back();
          forall_state_variable_list->group_ = *$9;
          delete $9;
          clear_param(forall_state_variable_list->param_);
          $$ = forall_state_variable_list;
      }
    ;


// default sensing declaration

domain_default_sensing:
      TK_OPEN KW_DEFAULT_SENSING sensing TK_CLOSE {
          declare_lw1_translation();
          lw1_default_sensing_proxy_ = $3;
      }
    ;


// problem definition

pddl_problem:
      TK_OPEN KW_DEFINE TK_OPEN KW_PROBLEM any_symbol TK_CLOSE {
          problem_name_ = std::string($5->text_);
      }
      problem_elements TK_CLOSE
    | TK_OPEN KW_DEFINE TK_OPEN KW_PROBLEM error TK_CLOSE {
          log_error((char*)"syntax error in problem definition.");
          yyerrok;
      }
    ;

problem_elements:
      problem_elements TK_OPEN KW_FORDOMAIN any_symbol TK_CLOSE
    | problem_elements domain_requires
    | problem_elements domain_constants
    | problem_elements initial_state
    | problem_elements hidden_state
    | problem_elements goal_spec
    | /* empty */
    ;

initial_state:
      TK_OPEN initial_state_keyword TK_CLOSE {
          if( $2 == KW_EXPLICIT_INITIAL_STATE ) {
#ifdef SMART
              dom_explicit_initial_states_.push_back(owned_init_element_vec());
#else
              dom_explicit_initial_states_.push_back(init_element_vec());
#endif
          }
    }
    | TK_OPEN initial_state_keyword init_elements TK_CLOSE {
          if( $2 == KW_INIT ) {
              dom_init_.clear();
#ifdef SMART
              for( owned_init_element_vec::iterator it = const_cast<owned_init_element_vec*>($3)->begin(); it != const_cast<owned_init_element_vec*>($3)->end(); ++it )
                  dom_init_.emplace_back(it->release());
#else
              dom_init_ = *$3;
#endif
          } else {
              assert($2 == KW_EXPLICIT_INITIAL_STATE);
#ifdef SMART
              dom_explicit_initial_states_.push_back(owned_init_element_vec());
              for( owned_init_element_vec::iterator it = const_cast<owned_init_element_vec*>($3)->begin(); it != const_cast<owned_init_element_vec*>($3)->end(); ++it )
                  dom_explicit_initial_states_.back().emplace_back(it->release());
#else
              dom_explicit_initial_states_.push_back(*$3);
#endif
          }
          delete $3;
      }
    | TK_OPEN initial_state_keyword TK_OPEN KW_AND init_elements TK_CLOSE TK_CLOSE {
          if( $2 == KW_INIT ) {
              dom_init_.clear();
#ifdef SMART
              for( owned_init_element_vec::iterator it = const_cast<owned_init_element_vec*>($5)->begin(); it != const_cast<owned_init_element_vec*>($5)->end(); ++it )
                  dom_init_.emplace_back(it->release());
#else
              dom_init_ = *$5;
#endif
          } else {
              assert($2 == KW_EXPLICIT_INITIAL_STATE);
#ifdef SMART
              dom_explicit_initial_states_.push_back(owned_init_element_vec());
              for( owned_init_element_vec::iterator it = const_cast<owned_init_element_vec*>($5)->begin(); it != const_cast<owned_init_element_vec*>($5)->end(); ++it )
                  dom_explicit_initial_states_.back().emplace_back(it->release());
#else
              dom_explicit_initial_states_.push_back(*$5);
#endif
          }
          delete $5;
      }
    ;

initial_state_keyword:
      KW_INIT { $$ = KW_INIT; }
    | KW_EXPLICIT_INITIAL_STATE { $$ = KW_EXPLICIT_INITIAL_STATE; }
    ;

init_elements:
      init_elements single_init_element {
#ifdef SMART
          owned_init_element_vec *ilist = const_cast<owned_init_element_vec*>($1);
          if( $2 != 0 ) ilist->emplace_back(std::unique_ptr<InitElement>(const_cast<InitElement*>($2)));
#else
          init_element_vec *ilist = const_cast<init_element_vec*>($1);
          if( $2 != 0 ) ilist->push_back(const_cast<InitElement*>($2));
#endif
          $$ = ilist;
      }
    | single_init_element {
#ifdef SMART
          owned_init_element_vec *ilist = new owned_init_element_vec;
          if( $1 != 0 ) ilist->emplace_back(std::unique_ptr<InitElement>(const_cast<InitElement*>($1)));
#else
          init_element_vec *ilist = new init_element_vec;
          if( $1 != 0 ) ilist->push_back(const_cast<InitElement*>($1));
#endif
          $$ = ilist;
      }
    ;

single_init_element:
      literal {
          $$ = new InitLiteral(*$1);
      }
    | invariant {
          if( type_ == cp2fsc ) {
              log_error((char*)"'invariant' is not a valid element in cp2fsc.");
              delete $1;
              yyerrok;
          } else {
              $$ = new InitInvariant(*$1);
              const_cast<Invariant*>($1)->clear();
              delete $1;
          }
      }
    | clause {
          if( type_ == replanner ) {
              // We let oneofs pass in k-replanner as they are later mapped
              // into invariants of type at-least-one. This is to support
              // CLG compatibility mode.
              declare_clg_translation();
          }
          $$ = new InitClause(*$1);
          const_cast<Clause*>($1)->clear();
          delete $1;
      }
    | oneof {
          if( type_ == replanner ) {
              // We let oneofs pass in k-replanner as they are later mapped
              // into invariants of type exactly-one. This is to support
              // CLG compatibility mode.
              declare_clg_translation();
          }
          $$ = new InitOneof(*$1);
          const_cast<Oneof*>($1)->clear();
          delete $1;
      }
    | unknown {
          $$ = 0; // when fixing this, remove condition '$2 != 0' and '$1 != 0' above (in single_init_element)
          std::cout << Utils::warning()
                    << Utils::magenta() << "(clg) ignoring '" << $1->to_string() << "'"
                    << Utils::normal() << std::endl;
          //$$ = new InitUnknown(*$1);
          delete $1;
      }
    ;

at_least_one_invariant:
      TK_OPEN KW_INVARIANT single_condition_list TK_CLOSE {
          //$$ = new Invariant(Invariant::AT_LEAST_ONE, *static_cast<const And*>($3));
          $$ = new Invariant(Invariant::AT_LEAST_ONE, *$3);
          delete $3;
      }
    | TK_OPEN KW_AT_LEAST_ONE single_condition_list TK_CLOSE {
          //$$ = new Invariant(Invariant::AT_LEAST_ONE, *static_cast<const And*>($3));
          $$ = new Invariant(Invariant::AT_LEAST_ONE, *$3);
          delete $3;
      }
    ;

at_most_one_invariant:
      TK_OPEN KW_AT_MOST_ONE single_condition_list TK_CLOSE {
          //$$ = new Invariant(Invariant::AT_MOST_ONE, *static_cast<const And*>($3));
          $$ = new Invariant(Invariant::AT_MOST_ONE, *$3);
          delete $3;
      }
    ;

exactly_one_invariant:
      TK_OPEN KW_EXACTLY_ONE single_condition_list TK_CLOSE {
          $$ = new Invariant(Invariant::EXACTLY_ONE, *$3);
          delete $3;
      }
    ;

invariant:
      at_least_one_invariant
    | at_most_one_invariant
    | exactly_one_invariant
    ;

clause:
      TK_OPEN KW_OR single_condition_list TK_CLOSE {
          $$ = new Clause(*$3);
          delete $3;
      }
    ;

oneof:
      TK_OPEN KW_ONEOF single_condition_list TK_CLOSE {
          $$ = new Oneof(*$3);
          delete $3;
      }
    ;

unknown:
      TK_OPEN KW_UNKNOWN positive_literal TK_CLOSE {
          $$ = new Unknown(*$3);
          delete $3;
      }
    ;

hidden_state:
      TK_OPEN KW_HIDDEN init_elements TK_CLOSE {
          if( type_ == cp2fsc ) {
              log_error((char*)"':hidden' is not a valid element in cp2fsc.");
              yyerrok;
          } else {
#ifdef SMART
              dom_hidden_.push_back(owned_init_element_vec());
              for( owned_init_element_vec::iterator it = const_cast<owned_init_element_vec*>($3)->begin(); it != const_cast<owned_init_element_vec*>($3)->end(); ++it )
                  dom_hidden_.back().emplace_back(it->release());
#else
              dom_hidden_.push_back(*$3);
#endif
              delete $3;
          }
      }
    | TK_OPEN KW_HIDDEN TK_CLOSE {
          if( type_ == cp2fsc ) {
              log_error((char*)"':hidden' is not a valid element in cp2fsc.");
              yyerrok;
          } else {
#ifdef SMART
              dom_hidden_.push_back(owned_init_element_vec());
#else
              dom_hidden_.push_back(init_element_vec());
#endif
          }
      }
    ;

goal_spec:
      TK_OPEN KW_GOAL condition TK_CLOSE { dom_goal_ = $3; }
/*  | TK_OPEN KW_GOAL single_goal TK_CLOSE { dom_goal_ = $3; } */
/*  | TK_OPEN KW_GOAL TK_OPEN KW_AND goal_list TK_CLOSE TK_CLOSE { dom_goal_ = $5; } */
    ;

goal_list:
      goal_list single_goal {
          const_cast<And*>(static_cast<const And*>($1))->push_back($2);
          $$ = $1;
      }
    | single_goal {
          And *cond = new And;
          cond->push_back($1);
          $$ = cond;
      }
    ;

single_goal:
      positive_literal { $$ = new Literal(*$1); delete $1; }
    | negative_literal { $$ = new Literal(*$1); delete $1; }
    ;

%%

