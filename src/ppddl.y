%name PDDL_Parser
%define ERROR log_error
%define ERROR_BODY = 0
%define ERROR_VERBOSE 1
%define LEX next_token
%define LEX_BODY = 0
%define DEBUG 1

%define INHERIT : public PDDL_Base
%define CONSTRUCTOR_PARAM StringTable& t, int type
%define CONSTRUCTOR_INIT : PDDL_Base(t), type_(type), error_flag_(false)
%define MEMBERS \
  public: \
    typedef enum { replanner, cp2fsc } Type; \
    virtual ~PDDL_Parser() { } \
    virtual std::ostream& syntax_errors() = 0; \
    bool error_flag_; \
    int type_; \
  private: \
    std::vector<ForallEffect*> forall_effects;

%header{
#include <stdlib.h>
#include <string.h>
#include <list>
#include <sstream>
#include "base.h"
%}

%union {
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
    int                               ival;
}

%token             TK_OPEN TK_CLOSE TK_OPEN_SQ TK_CLOSE_SQ TK_EQ TK_HYPHEN

%token <sym>       TK_NEW_SYMBOL TK_OBJ_SYMBOL TK_TYPE_SYMBOL TK_PRED_SYMBOL
                   TK_VAR_SYMBOL TK_ACTION_SYMBOL TK_AXIOM_SYMBOL TK_SENSOR_SYMBOL
                   TK_MISC_SYMBOL TK_KEYWORD TK_NEW_VAR_SYMBOL
%token <ival>      TK_INT

%token             KW_REQS KW_CONSTANTS KW_PREDS KW_TYPES KW_DEFINE KW_DOMAIN
                   KW_ACTION KW_ARGS KW_PRE KW_EFFECT KW_AND
                   KW_OR KW_EXISTS KW_FORALL KW_NOT KW_WHEN KW_ONEOF
                   KW_PROBLEM KW_FORDOMAIN KW_OBJECTS KW_INIT KW_GOAL
                   KW_SENSOR KW_SENSED KW_AXIOM KW_COND KW_OBSERVABLE
                   KW_BODY KW_HEAD KW_STICKY KW_FLUENTS KW_HIDDEN
                   KW_INVARIANT KW_AT_LEAST_ONE KW_AT_MOST_ONE KW_EXACTLY_ONE

%type <sym>        action_symbol any_symbol sensor_symbol axiom_symbol
%type <param>      atom_argument_list
%type <vparam>     typed_param_list typed_param_sym_list

%type <atom>       positive_literal negative_literal literal
%type <condition>  condition single_condition condition_list
%type <condition>  goal_list single_goal
%type <invariant>  invariant at_least_one_invariant at_most_one_invariant exactly_one_invariant
%type <clause>     clause
%type <oneof>      oneof
%type <effect>     atomic_effect positive_atomic_effect positive_atomic_effect_list
%type <effect>     action_effect action_effect_list single_action_effect conditional_effect forall_effect
%type <effect>     atomic_effect_kw_list atomic_effect_list
%type <ilist>      init_elements

%start pddl_declarations

%%

pddl_declarations:
      pddl_domain pddl_declarations
    | pddl_problem pddl_declarations
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
      domain_requires domain_elements
    | domain_types domain_elements
    | domain_constants domain_elements
    | domain_predicates domain_elements
    | domain_structure domain_elements
    | /* empty */
    ;

domain_name:
      TK_OPEN KW_DOMAIN any_symbol TK_CLOSE { domain_name = $3->text; }
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
      require_list KW_TYPES
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
      TK_OPEN TK_NEW_SYMBOL typed_param_list TK_CLOSE {
          PredicateSymbol *p = new PredicateSymbol($2->text);
          dom_predicates.push_back(p);
          p->param = *$3;
          delete $3;
          clear_param(p->param);
          $2->val = p;
      }
    | TK_OPEN error TK_CLOSE {
          log_error((char*)"syntax error in predicate declaration");
          yyerrok;
      }
    ;

typed_param_list:
      typed_param_list typed_param_sym_list TK_HYPHEN TK_TYPE_SYMBOL {
          set_variable_type(*$2, $2->size(), (TypeSymbol*)$4->val);
          $1->insert($1->end(), $2->begin(), $2->end());
          delete $2;
          $$ = $1;
      }
    | typed_param_list typed_param_sym_list {
          set_variable_type(*$1, $1->size(), dom_top_type);
          $1->insert($1->end(), $2->begin(), $2->end());
          delete $2;
          $$ = $1;
      }
    | /* empty */ { $$ = new variable_vec; }
    ;

typed_param_sym_list:
      typed_param_sym_list TK_NEW_VAR_SYMBOL {
          VariableSymbol *var = new VariableSymbol($2->text);
          $2->val = var;
          $1->push_back(var);
          $$ = $1;
      }
    | /* empty */ { $$ = new variable_vec; }
    ;

// type declarations

domain_types:
      TK_OPEN KW_TYPES typed_type_list TK_CLOSE
    ;

typed_type_list:
      typed_type_list primitive_type_list TK_HYPHEN TK_TYPE_SYMBOL {
          set_type_type(dom_types, dom_types.size(), (TypeSymbol*)$4->val);
      }
    | typed_type_list primitive_type_list TK_HYPHEN TK_NEW_SYMBOL {
          $4->val = new TypeSymbol($4->text);
          if( write_warnings )
              std::cerr << "warning: assuming " << $4->text << " - object" << std::endl;
          ((TypeSymbol*)$4->val)->sym_type = dom_top_type;
          set_type_type(dom_types, dom_types.size(), (TypeSymbol*)$4->val);
          dom_types.push_back((TypeSymbol*)$4->val);
      }
    | typed_type_list primitive_type_list {
          set_type_type(dom_types, dom_types.size(), dom_top_type);
      }
    | /* empty */
    ;

primitive_type_list:
      primitive_type_list TK_TYPE_SYMBOL {
          /* the type is already (implicitly) declared */
      }
    | primitive_type_list TK_NEW_SYMBOL {
          $2->val = new TypeSymbol($2->text);
          dom_types.push_back((TypeSymbol*)$2->val);
      }
    | /* empty */
    ;

// constant declarations

domain_constants:
      TK_OPEN KW_CONSTANTS typed_constant_list TK_CLOSE
    | TK_OPEN KW_OBJECTS typed_constant_list TK_CLOSE
    ;

typed_constant_list:
      typed_constant_list ne_constant_sym_list TK_HYPHEN TK_TYPE_SYMBOL {
          set_constant_type(dom_constants, dom_constants.size(), (TypeSymbol*)$4->val);
      }
    | typed_constant_list ne_constant_sym_list {
          set_constant_type(dom_constants, dom_constants.size(), dom_top_type);
      }
    | /* empty */
    ;

ne_constant_sym_list:
      ne_constant_sym_list TK_NEW_SYMBOL {
          $2->val = new Symbol($2->text);
          dom_constants.push_back((Symbol*)$2->val);
      }
    | TK_NEW_SYMBOL {
          $1->val = new Symbol($1->text);
          dom_constants.push_back((Symbol*)$1->val);
      }
    ;

// structure declarations

domain_structure:
      action_declaration
    | axiom_declaration {
         if( type_ == replanner ) {
             log_error((char*)"':axiom' is not a valid element in k-replanner.");
             yyerrok; 
         }
      }
    | sensor_declaration {
         if( type_ == cp2fsc ) {
             log_error((char*)"':sensor' is not a valid element in cp2fsc.");
             yyerrok; 
         }
      }
    | observable_declaration {
         if( type_ == replanner ) {
             log_error((char*)"':observable' is not a valid element in k-replanner.");
             yyerrok; 
         }
      }
    | sticky_declaration {
         if( type_ == replanner ) {
             log_error((char*)"':sticky' is not a valid element in k-replanner.");
             yyerrok; 
         }
      }
    ;

// structure declarations

action_declaration:
      TK_OPEN KW_ACTION action_symbol {
          Action *na = new Action($3->text);
          dom_actions.push_back(na);
      }
      action_elements TK_CLOSE {
          clear_param(dom_actions.back()->param);
          $3->val = dom_actions.back();
      }
    | TK_OPEN KW_ACTION error TK_CLOSE {
          log_error((char*)"syntax error in action declaration");
          yyerrok; 
      }
    ;

action_elements:
      action_elements KW_ARGS TK_OPEN typed_param_list TK_CLOSE {
          dom_actions.back()->param = *$4;
          delete $4;
      }
    | action_elements KW_PRE condition { dom_actions.back()->precondition = $3; }
    | action_elements KW_EFFECT action_effect { dom_actions.back()->effect = $3; }
    | /* empty */
    ;

condition:
      single_condition
    | TK_OPEN KW_AND condition_list TK_CLOSE { $$ = $3; }
    ;

condition_list:
      condition_list single_condition {
          const_cast<And*>(static_cast<const And*>($1))->push_back($2);
          $$ = $1;
      }
    | single_condition {
          And *cond = new And();
          cond->push_back($1);
          $$ = cond;
      }
    ;

single_condition:
      literal { $$ = new Literal(*$1); delete $1; }
    ;

literal:
      positive_literal
    | negative_literal
    ;

positive_literal:
      TK_OPEN TK_PRED_SYMBOL atom_argument_list TK_CLOSE {
          PredicateSymbol* p = (PredicateSymbol*)$2->val;
          $$ = new Atom(p);
          $$->param = *$3;
          delete $3;
          if( p->param.size() != $$->param.size() ) {
              std::ostringstream msg;
              msg << "wrong number of arguments for predicate '" << p->print_name << "'";
              log_error(const_cast<char*>(msg.str().c_str()));
          }
      }
    | TK_OPEN TK_EQ atom_argument_list TK_CLOSE {
          $$ = new Atom(dom_eq_pred);
          $$->param = *$3;
          delete $3;
          if( $$->param.size() != 2 ) {
              log_error((char*)"wrong number of arguments for equality");
          }
          assert(0); // TODO: remove this assertion which is here
                     // because (probably) the code for '=' is broken...
    }
    ;

negative_literal:
      TK_OPEN KW_NOT positive_literal TK_CLOSE {
          const_cast<Literal*>(static_cast<const Literal*>($3))->neg = true;
          $$ = $3;
      }
    ;

atom_argument_list:
      atom_argument_list TK_VAR_SYMBOL {
          if( $2->val == 0 )
              log_error((char*)"undeclared variable in atom args list");
          else
              $1->push_back((VariableSymbol*)$2->val);
          $$ = $1;
      }
    | atom_argument_list TK_OBJ_SYMBOL {
          $1->push_back((Symbol*)$2->val);
          $$ = $1;
      }
    | /* empty */ { $$ = new PDDL_Base::symbol_vec; }
    ;

action_effect:
      single_action_effect
    | TK_OPEN KW_AND action_effect_list TK_CLOSE { $$ = $3; }
    ;

action_effect_list:
      action_effect_list single_action_effect {
          const_cast<AndEffect*>(static_cast<const AndEffect*>($1))->push_back($2);
          $$ = $1;
      }
    | single_action_effect {
          AndEffect *eff = new AndEffect;
          eff->push_back($1);
          $$ = eff;
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
          forall_effects.push_back(new ForallEffect);
      }
      typed_param_list TK_CLOSE {
          forall_effects.back()->param = *$5;
          delete $5;
      }
      action_effect TK_CLOSE {
          forall_effects.back()->effect = $8;
          clear_param(forall_effects.back()->param);
          $$ = forall_effects.back();
          forall_effects.pop_back();
      }
    ;

/*
quantified_effect_body:
      TK_OPEN KW_WHEN condition atomic_effect_kw_list TK_CLOSE
    | atomic_effect_kw_list
    ;
*/

atomic_effect_kw_list:
      TK_OPEN KW_AND atomic_effect_list TK_CLOSE { $$ = $3; }
    | atomic_effect
    ;

atomic_effect_list:
      atomic_effect_list atomic_effect {
          const_cast<AndEffect*>(static_cast<const AndEffect*>($1))->push_back($2);
          $$ = $1;
      }
    | atomic_effect {
          AndEffect *eff = new AndEffect;
          eff->push_back($1);
          $$ = eff;
      }
    ;

positive_atomic_effect_list:
      positive_atomic_effect_list positive_atomic_effect {
          const_cast<AndEffect*>(static_cast<const AndEffect*>($1))->push_back($2);
          $$ = $1;
      }
    | positive_atomic_effect {
          AndEffect *eff = new AndEffect;
          eff->push_back($1);
          $$ = eff;
      }
    ;

atomic_effect:
      literal { $$ = new AtomicEffect(*$1); delete $1; }
    ;

positive_atomic_effect:
      positive_literal { $$ = new AtomicEffect(*$1); delete $1; }
    ;

at_least_one_invariant:
      TK_OPEN KW_INVARIANT condition_list TK_CLOSE {
          $$ = new Invariant(Invariant::AT_LEAST_ONE, *static_cast<const And*>($3));
          const_cast<And*>(static_cast<const And*>($3))->clear(); delete $3;
      }
    | TK_OPEN KW_AT_LEAST_ONE condition_list TK_CLOSE {
          $$ = new Invariant(Invariant::AT_LEAST_ONE, *static_cast<const And*>($3));
          const_cast<And*>(static_cast<const And*>($3))->clear(); delete $3;
      }
    ;

at_most_one_invariant:
      TK_OPEN KW_AT_MOST_ONE condition_list TK_CLOSE {
          $$ = new Invariant(Invariant::AT_MOST_ONE, *static_cast<const And*>($3));
          const_cast<And*>(static_cast<const And*>($3))->clear(); delete $3;
      }
    ;

exactly_one_invariant:
      TK_OPEN KW_EXACTLY_ONE condition_list TK_CLOSE {
          $$ = new Invariant(Invariant::EXACTLY_ONE, *static_cast<const And*>($3));
          const_cast<And*>(static_cast<const And*>($3))->clear(); delete $3;
      }
    ;

invariant:
      at_least_one_invariant
    | at_most_one_invariant
    | exactly_one_invariant
    ;

clause:
      TK_OPEN KW_OR condition_list TK_CLOSE {
          $$ = new Clause(*static_cast<const And*>($3));
          const_cast<And*>(static_cast<const And*>($3))->clear(); delete $3;
      }
    ;

oneof:
      TK_OPEN KW_ONEOF condition_list TK_CLOSE {
          $$ = new Oneof(*static_cast<const And*>($3));
          const_cast<And*>(static_cast<const And*>($3))->clear(); delete $3;
      }
    ;

axiom_declaration:
      TK_OPEN KW_AXIOM axiom_symbol {
          Axiom *nr = new Axiom($3->text);
          dom_axioms.push_back(nr);
      }
      axiom_elements TK_CLOSE {
          clear_param(dom_axioms.back()->param);
          $3->val = dom_axioms.back();
      }
    | TK_OPEN KW_AXIOM error TK_CLOSE {
          log_error((char*)"syntax error in axiom declaration");
          yyerrok; 
      }
    ;

axiom_elements:
      axiom_elements KW_ARGS TK_OPEN typed_param_list TK_CLOSE {
          dom_axioms.back()->param = *$4;
          delete $4;
      }
    | axiom_elements KW_BODY condition { dom_axioms.back()->body = $3; }
    | axiom_elements KW_HEAD atomic_effect_kw_list { dom_axioms.back()->head = $3; }
    | /* empty */
    ;

sensor_declaration:
      TK_OPEN KW_SENSOR sensor_symbol {
          Sensor *nr = new Sensor($3->text);
          dom_sensors.push_back(nr);
      }
      sensor_elements TK_CLOSE {
          clear_param(dom_sensors.back()->param);
          $3->val = dom_sensors.back();
      }
    | TK_OPEN KW_SENSOR error TK_CLOSE {
          log_error((char*)"syntax error in sensor declaration");
          yyerrok; 
      }
    ;

sensor_elements:
      sensor_elements KW_ARGS TK_OPEN typed_param_list TK_CLOSE {
          dom_sensors.back()->param = *$4;
          delete $4;
      }
    | sensor_elements KW_COND condition { dom_sensors.back()->condition = $3; }
    | sensor_elements KW_SENSED positive_atomic_effect_list { dom_sensors.back()->sensed = $3; }
    | /* empty */
    ;

observable_declaration:
      TK_OPEN KW_OBSERVABLE {
          Observable *obs = new Observable;
          dom_observables.push_back(obs);
      } observable_elements TK_CLOSE {
          clear_param(dom_observables.back()->param);
      }
    | TK_OPEN KW_OBSERVABLE error TK_CLOSE {
          log_error((char*)"syntax error in observable declaration");
          yyerrok; 
      }
    ;

observable_elements:
      observable_elements KW_ARGS TK_OPEN typed_param_list TK_CLOSE {
          dom_observables.back()->param = *$4;
          delete $4;
      }
    | observable_elements KW_FLUENTS positive_atomic_effect_list {
          dom_observables.back()->observables = $3;
      }
    | /* empty */
    ;

sticky_declaration:
      TK_OPEN KW_STICKY {
          Sticky *stk = new Sticky;
          dom_stickies.push_back(stk);
      } sticky_elements TK_CLOSE {
          clear_param(dom_stickies.back()->param);
      }
    | TK_OPEN KW_STICKY error TK_CLOSE {
          log_error((char*)"syntax error in sticky declaration");
          yyerrok; 
      }
    ;

sticky_elements:
      sticky_elements KW_ARGS TK_OPEN typed_param_list TK_CLOSE {
          dom_stickies.back()->param = *$4;
          delete $4;
      }
    | sticky_elements KW_FLUENTS positive_atomic_effect_list {
          dom_stickies.back()->stickies = $3;
      }
    | /* empty */
    ;

// problem definition

pddl_problem:
      TK_OPEN KW_DEFINE TK_OPEN KW_PROBLEM any_symbol TK_CLOSE {
          problem_name = $5->text;
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
      TK_OPEN KW_INIT init_elements TK_CLOSE { dom_init = *$3; delete $3; }
    ;

init_elements:
      init_elements literal {
          init_element_vec *ilist = const_cast<init_element_vec*>($1);
          ilist->push_back(new InitLiteral(*$2));
          delete $2;
          $$ = ilist;
      }
    | init_elements invariant {
          if( type_ == cp2fsc ) {
              log_error((char*)"'invariant' is not a valid element in cp2fsc.");
              yyerrok; 
          } else {
              init_element_vec *ilist = const_cast<init_element_vec*>($1);
              ilist->push_back(new InitInvariant(*$2));
              const_cast<Invariant*>(dynamic_cast<const Invariant*>($2))->clear(); delete $2;
              $$ = ilist;
          }
      }
    | init_elements clause {
          if( type_ == replanner ) {
              log_error((char*)"'clause' is not a valid element in k-replanner.");
              yyerrok; 
          } else {
              init_element_vec *ilist = const_cast<init_element_vec*>($1);
              ilist->push_back(new InitClause(*$2));
              const_cast<Clause*>(dynamic_cast<const Clause*>($2))->clear(); delete $2;
              $$ = ilist;
          }
      }
    | init_elements oneof {
          if( type_ == replanner ) {
              log_error((char*)"'oneof' is not a valid element in k-replanner.");
              yyerrok; 
          } else {
              init_element_vec *ilist = const_cast<init_element_vec*>($1);
              ilist->push_back(new InitOneof(*$2));
              const_cast<Oneof*>(dynamic_cast<const Oneof*>($2))->clear(); delete $2;
              $$ = ilist;
          }
      }
    | /* empty */ { $$ = new init_element_vec; }
    ;

hidden_state:
      TK_OPEN KW_HIDDEN init_elements TK_CLOSE {
          if( type_ == cp2fsc ) {
              log_error((char*)"':hidden' is not a valid element in cp2fsc.");
              yyerrok; 
          } else {
              dom_hidden = *$3;
              delete $3;
          }
      }
    ;

goal_spec:
      TK_OPEN KW_GOAL single_goal TK_CLOSE { dom_goal = $3; }
    | TK_OPEN KW_GOAL TK_OPEN KW_AND goal_list TK_CLOSE TK_CLOSE { dom_goal = $5; }
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

