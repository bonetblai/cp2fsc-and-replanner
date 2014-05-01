%name PDDL_Parser
%define ERROR log_error
%define ERROR_BODY = 0
%define ERROR_VERBOSE 1
%define LEX next_token
%define LEX_BODY = 0
%define DEBUG 1

%define INHERIT : public PDDL_Base
%define CONSTRUCTOR_PARAM StringTable& t, int type, const Options::Mode &options
%define CONSTRUCTOR_INIT : PDDL_Base(t, options), error_flag_(false), type_(type)
%define MEMBERS \
  public: \
    typedef enum { replanner, cp2fsc } Type; \
    virtual ~PDDL_Parser() { } \
    virtual std::ostream& syntax_errors() = 0; \
    bool error_flag_; \
    int type_; \
  private: \
    std::vector<ForallEffect*> forall_effects_; \
    std::vector<ForallCondition*> forall_conditions_; \
    std::vector<ExistsCondition*> exists_conditions_; \
    effect_vec *effect_vec_ptr_;

%header{
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
%}

%union {
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
}

%token                  TK_OPEN TK_CLOSE TK_OPEN_SQ TK_CLOSE_SQ TK_EQ TK_HYPHEN

%token <sym>            TK_NEW_SYMBOL TK_OBJ_SYMBOL TK_TYPE_SYMBOL TK_PRED_SYMBOL
                        TK_VAR_SYMBOL TK_ACTION_SYMBOL TK_AXIOM_SYMBOL TK_SENSOR_SYMBOL
                        TK_MISC_SYMBOL TK_KEYWORD TK_NEW_VAR_SYMBOL
                        TK_VARNAME_SYMBOL

%token <ival>           TK_INT

%token                  KW_REQS KW_TRANSLATION
                        KW_CONSTANTS KW_PREDS KW_TYPES KW_DEFINE KW_DOMAIN
                        KW_ACTION KW_ARGS KW_PRE KW_EFFECT KW_AND
                        KW_OR KW_EXISTS KW_FORALL KW_NOT KW_WHEN KW_ONEOF KW_UNKNOWN
                        KW_PROBLEM KW_FORDOMAIN KW_OBJECTS KW_INIT KW_GOAL
                        KW_SENSOR KW_SENSE KW_OBSERVE KW_AXIOM KW_COND KW_OBSERVABLE
                        KW_BODY KW_HEAD KW_STICKY KW_FLUENTS KW_HIDDEN
                        KW_INVARIANT KW_AT_LEAST_ONE KW_AT_MOST_ONE KW_EXACTLY_ONE

%token                  KW_TRANSLATION
                        KW_VARIABLE KW_OBS_VARIABLE KW_VALUES
                        KW_SENSING_MODEL KW_DEFAULT_SENSING_MODEL

%type <vsym>            new_var_symbol
%type <sym>             action_symbol any_symbol sensor_symbol axiom_symbol variable_symbol
%type <param>           argument_list
%type <vparam>          param_list typed_param_list untyped_param_list param_sym_list

%type <sym>             primitive_type
%type <atom>            positive_literal negative_literal literal
%type <condition_vec>   single_condition_list condition_list
%type <condition>       condition single_condition and_condition or_condition
%type <condition>       forall_condition exists_condition
%type <condition>       goal_list single_goal
%type <invariant>       invariant at_least_one_invariant at_most_one_invariant exactly_one_invariant
%type <clause>          clause
%type <oneof>           oneof
%type <unknown>         unknown
%type <effect_vec>      positive_atomic_effect_list atomic_effect_list action_effect_list
%type <effect>          atomic_effect positive_atomic_effect
%type <effect>          action_effect single_action_effect conditional_effect forall_effect
%type <effect>          atomic_effect_kw_list
%type <effect>          sensing_model fluent_decl
%type <ilist>           init_elements
%type <ielem>           single_init_element

%type <ival>            multivalued_variable_type

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
    | domain_elements domain_default_sensing_model
    | /* empty */
    ;
 
domain_name:
      TK_OPEN KW_DOMAIN any_symbol TK_CLOSE { domain_name_ = $3->text; }
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

variable_symbol:
      TK_NEW_SYMBOL { $$ = $1; }
    | TK_VARNAME_SYMBOL { $$ = $1; }
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
      require_list KW_TRANSLATION { declare_multivalued_variable_translation(); }
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
          PredicateSymbol *p = new PredicateSymbol($2->text);
          dom_predicates_.push_back(p);
          p->param_ = *$3;
          delete $3;
          clear_param(p->param_);
          $2->val = p;
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
          set_variable_type(*$1, $1->size(), static_cast<TypeSymbol*>($3->val));
          $4->insert($4->end(), $1->begin(), $1->end());
          delete $1;
          $$ = $4;
      }
    | param_sym_list TK_HYPHEN TK_TYPE_SYMBOL {
          set_variable_type(*$1, $1->size(), static_cast<TypeSymbol*>($3->val));
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
          VariableSymbol *var = new VariableSymbol($1->text);
          $1->val = var;
          $$ = var;
      }
    | TK_VAR_SYMBOL {
          std::string msg("variable '");
          msg += $1->text;
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
          set_type_type(dom_types_, dom_types_.size(), static_cast<TypeSymbol*>($3->val));
      }
    | primitive_type_list TK_HYPHEN TK_NEW_SYMBOL typed_type_list {
          $3->val = new TypeSymbol($3->text);
          if( write_warnings_ )
              std::cout << Utils::warning() << "assuming " << $3->text << " - object" << std::endl;
          static_cast<TypeSymbol*>($3->val)->sym_type_ = dom_top_type_;
          set_type_type(dom_types_, dom_types_.size(), static_cast<TypeSymbol*>($3->val));
          dom_types_.push_back(static_cast<TypeSymbol*>($3->val));
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
          $1->val = new TypeSymbol($1->text);
          dom_types_.push_back(static_cast<TypeSymbol*>($1->val));
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
          set_constant_type(dom_constants_, dom_constants_.size(), static_cast<TypeSymbol*>($3->val));
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
          $2->val = new Symbol($2->text);
          dom_constants_.push_back(static_cast<Symbol*>($2->val));
      }
    | TK_NEW_SYMBOL {
          $1->val = new Symbol($1->text);
          dom_constants_.push_back(static_cast<Symbol*>($1->val));
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
    | multivalued_variable_decl {
          //declare_multivalued_variable_translation();
          if( type_ == cp2fsc ) {
              log_error((char*)"':sensor' is not a valid element in cp2fsc.");
              yyerrok;
          }
      }
    ;

// structure declarations

action_decl:
      TK_OPEN KW_ACTION action_symbol {
          Action *na = new Action($3->text);
          dom_actions_.push_back(na);
      }
      action_elements TK_CLOSE {
          clear_param(dom_actions_.back()->param_);
          $3->val = dom_actions_.back();
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
    | action_elements KW_SENSING_MODEL sensing_model {
          declare_multivalued_variable_translation();
          dom_actions_.back()->sensing_model_ = $3;
      }
    | /* empty */
    ;

condition:
      single_condition
    | and_condition
    | or_condition
    | forall_condition
    | exists_condition
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
          PredicateSymbol* p = static_cast<PredicateSymbol*>($2->val);
          if( p->param_.size() != $3->size() ) {
              std::ostringstream msg;
              msg << "wrong number of arguments for predicate '" << p->print_name_ << "'";
              log_error(const_cast<char*>(msg.str().c_str()));
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
          if( $2->val == 0 )
              log_error((char*)"undeclared variable in atom args list");
          else
              $1->push_back(static_cast<VariableSymbol*>($2->val));
          $$ = $1;
      }
    | argument_list TK_OBJ_SYMBOL {
          $1->push_back(static_cast<Symbol*>($2->val));
          $$ = $1;
      }
    | /* empty */ { $$ = new PDDL_Base::symbol_vec; }
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
          forall_conditions_.push_back(new ForallCondition);
      }
      param_list TK_CLOSE {
          forall_conditions_.back()->param_ = *$5;
          delete $5;
      }
      condition TK_CLOSE {
          forall_conditions_.back()->condition_ = $8;
          clear_param(forall_conditions_.back()->param_);
          $$ = forall_conditions_.back();
          forall_conditions_.pop_back();
      }
    ;

exists_condition:
      TK_OPEN KW_EXISTS TK_OPEN {
          exists_conditions_.push_back(new ExistsCondition);
      }
      param_list TK_CLOSE {
          exists_conditions_.back()->param_ = *$5;
          delete $5;
      }
      condition TK_CLOSE {
          exists_conditions_.back()->condition_ = $8;
          clear_param(exists_conditions_.back()->param_);
          $$ = exists_conditions_.back();
          exists_conditions_.pop_back();
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
          forall_effects_.push_back(new ForallEffect);
      }
      param_list TK_CLOSE {
          forall_effects_.back()->param_ = *$5;
          delete $5;
      }
      action_effect TK_CLOSE {
          forall_effects_.back()->effect_ = $8;
          clear_param(forall_effects_.back()->param_);
          $$ = forall_effects_.back();
          forall_effects_.pop_back();
      }
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

sensing_model:
      action_effect
    | /* empty */ { $$ = 0; }
    ;

axiom_decl:
      TK_OPEN KW_AXIOM axiom_symbol {
          Axiom *nr = new Axiom($3->text);
          dom_axioms_.push_back(nr);
      }
      axiom_elements TK_CLOSE {
          clear_param(dom_axioms_.back()->param_);
          $3->val = dom_axioms_.back();
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
          Sensor *nr = new Sensor($3->text);
          dom_sensors_.push_back(nr);
      }
      sensor_elements TK_CLOSE {
          clear_param(dom_sensors_.back()->param_);
          $3->val = dom_sensors_.back();
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
          Observable *obs = new Observable;
          dom_observables_.push_back(obs);
          effect_vec_ptr_ = &obs->observables_;
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
          Sticky *sticky = new Sticky;
          dom_stickies_.push_back(sticky);
          effect_vec_ptr_ = &sticky->stickies_;
      }
      fluent_list_decl TK_CLOSE
    | TK_OPEN KW_STICKY error TK_CLOSE {
          log_error((char*)"syntax error in sticky declaration");
          yyerrok;
      }
    ;

multivalued_variable_decl:
      TK_OPEN multivalued_variable_type variable_symbol {
          Variable *var = 0;
          if( $2 == 0 )
              var = new StateVariable($3->text);
          else
              var = new ObsVariable($3->text);
          multivalued_variables_.push_back(var);
          effect_vec_ptr_ = &var->values_;
      }
      /*optional_variable_parameters fluent_list_decl rest_variable_decl TK_CLOSE*/
      fluent_list_decl TK_CLOSE {
          $3->val = multivalued_variables_.back();
      }
    | TK_OPEN multivalued_variable_type TK_OPEN variable_symbol param_list TK_CLOSE {
          Variable *var = 0;
          if( $2 == 0 )
              var = new StateVariable($4->text);
          else
              var = new ObsVariable($4->text);
          var->param_ = *$5;
          delete $5;
          multivalued_variables_.push_back(var);
          effect_vec_ptr_ = &var->values_;
      }
      /*fluent_list_decl rest_variable_decl TK_CLOSE*/
      fluent_list_decl TK_CLOSE {
          clear_param(multivalued_variables_.back()->param_);
          $4->val = multivalued_variables_.back();
      }
    | TK_OPEN KW_VARIABLE error TK_CLOSE {
          log_error((char*)"syntax error in state variable declaration");
          yyerrok;
      }
    ;

multivalued_variable_type:
      KW_VARIABLE { $$ = 0; }
    | KW_OBS_VARIABLE { $$ = 1; }
    ;

optional_variable_parameters:
      KW_ARGS TK_OPEN param_list TK_CLOSE {
          multivalued_variables_.back()->param_ = *$3;
          delete $3;
      }
    | /* empty */
    ;

rest_variable_decl:
      KW_OBSERVABLE {
          assert(dynamic_cast<StateVariable*>(multivalued_variables_.back()) != 0);
          dynamic_cast<StateVariable*>(multivalued_variables_.back())->is_observable_ = true;
      }
    | /* empty */
    ;

// default sensing declaration

domain_default_sensing_model:
      TK_OPEN KW_DEFAULT_SENSING_MODEL sensing_model TK_CLOSE {
          declare_multivalued_variable_translation();
          default_sensing_model_ = $3;
      }
    ;


// problem definition

pddl_problem:
      TK_OPEN KW_DEFINE TK_OPEN KW_PROBLEM any_symbol TK_CLOSE {
          problem_name_ = $5->text;
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
      TK_OPEN KW_INIT TK_CLOSE
    | TK_OPEN KW_INIT init_elements TK_CLOSE { dom_init_ = *$3; delete $3; }
    | TK_OPEN KW_INIT TK_OPEN KW_AND init_elements TK_CLOSE TK_CLOSE { dom_init_ = *$5; delete $5; }
    ;

init_elements:
      init_elements single_init_element {
          init_element_vec *ilist = const_cast<init_element_vec*>($1);
          if( $2 != 0 ) ilist->push_back(const_cast<InitElement*>($2));
          $$ = ilist;
      }
    | single_init_element {
          init_element_vec *ilist = new init_element_vec;
          if( $1 != 0 ) ilist->push_back(const_cast<InitElement*>($1));
          $$ = ilist;
      }
    ;

single_init_element:
      literal { $$ = new InitLiteral(*$1); }
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
              dom_hidden_.push_back(*$3);
              delete $3;
          }
      }
    | TK_OPEN KW_HIDDEN TK_CLOSE {
          if( type_ == cp2fsc ) {
              log_error((char*)"':hidden' is not a valid element in cp2fsc.");
              yyerrok;
          } else {
              init_element_vec hidden;
              dom_hidden_.push_back(hidden);
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

