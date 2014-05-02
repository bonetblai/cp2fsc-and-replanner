#include "lwaptk_planner.h"
#include "utils.h"
#include <action.hxx>
#include <cassert>
#include <algorithm>

	Lwaptk_Planner::Lwaptk_Planner( const char* name, const KP_Instance &instance, const char *tmpfile_path)
      	: ClassicalPlanner(name, tmpfile_path, "", "", instance), m_task( instance.name_->to_string(), "call" ) {
		if (  kp_instance_.options_.is_enabled( "planner:print:statistics" )  )
			m_task.set_verbose(true);
		make_kp_fluents_and_actions();
		if ( kp_instance_.options_.is_enabled( "planner:print:statistics" ) ) 
			std::cout << "[lwaptk]: K(P) instance loaded, " << m_task.fluents().size() << " fluents and " << m_task.actions().size() << " actions" << std::endl;
	}

	Lwaptk_Planner::~Lwaptk_Planner() {
	}

	int
	Lwaptk_Planner::get_raw_plan(const State &state, Instance::Plan &raw_plan) const {

		std::cout << "calling " << name() << " (n=" << 1+n_calls() << ", acc-time=" << get_time() << ")..." << std::endl;
	
		float start_time = Utils::read_time_in_seconds();
		++n_calls_;
	
		raw_plan.clear();
		update_initial_state( state );
		make_kp_goal();


		int result = classical_planner( state, raw_plan );

		total_time_ += Utils::read_time_in_seconds() - start_time;

		return result;
	}

	void
	Lwaptk_Planner::make_kp_fluents() {
		for ( size_t k = 0; k < kp_instance_.n_atoms(); k++ )
			STRIPS_Problem::add_fluent( m_task, kp_instance_.atoms_[k]->name_->to_string() );
	}
	void
	Lwaptk_Planner::handle_effect_literal( int p, aptk::Fluent_Vec& pos, aptk::Fluent_Vec& neg ) {
		bool negated = p < 0;
		unsigned index = ( p < 0 ? -p : p ) - 1;
		
		if ( m_negated[ index ] == nullptr ) {
			if ( negated )
				neg.push_back( index );
			else
				pos.push_back( index );
			return;
		}

		unsigned neg_index = m_negated[ index ]->index();
		
		if ( negated ) {
			pos.push_back( neg_index );
			neg.push_back( index );
			return;
		}

		neg.push_back( neg_index );
		pos.push_back( index );
	}

	void
	Lwaptk_Planner::make_kp_action( const Instance::Action& act ) {
		std::string name;

		name = act.name_->to_string();
		
		aptk::Fluent_Vec prec;
		
		for ( auto p : act.precondition_ ) {
			if ( p > 0 ) {
				unsigned index = p - 1;
				prec.push_back( index );
				continue;
			}
			unsigned index = (-p)-1;
			assert( index < m_negated.size() );
			index = m_negated[index]->index();
			prec.push_back( index );
		}

		aptk::Fluent_Vec adds;
		aptk::Fluent_Vec dels;

		for ( auto p : act.effect_ )
			handle_effect_literal( p, adds, dels );

		aptk::Conditional_Effect_Vec ceffs;

		for ( size_t i = 0; i < act.when_.size(); i++ ) {
			const Instance::When& w = act.when_[i];

			aptk::Fluent_Vec	cond;

			for ( auto p : w.condition_ ) {
				if ( p > 0 ) {
					unsigned index = p - 1;
					cond.push_back( index );
					continue;
				}
				unsigned index = (-p)-1;
				assert( index < m_negated.size() );
				index = m_negated[index]->index();
				cond.push_back( index );
			}

			aptk::Fluent_Vec	cond_adds;
			aptk::Fluent_Vec	cond_dels;

			
			for ( auto p : w.effect_ ) 
				handle_effect_literal( p, cond_adds, cond_dels );

			aptk::Conditional_Effect* cond_eff = new aptk::Conditional_Effect( m_task );
			cond_eff->define( cond, cond_adds, cond_dels );
			ceffs.push_back( cond_eff );
			m_task.notify_cond_eff_in_action();
		}

		STRIPS_Problem::add_action( m_task, name, prec, adds, dels, ceffs );
	}

	void
	Lwaptk_Planner::handle_negated_conditions() {
		for ( size_t k = 0; k < kp_instance_.n_actions(); k++ ) {
			const Instance::Action& act = *kp_instance_.actions_[k];
			for ( auto p : act.precondition_ ) {
				if ( p < 0 )
					m_negated_conditions.insert( (-p)-1 );


			}
			for ( size_t i = 0; i < act.when_.size(); i++ ) {
				const Instance::When& w = act.when_[i];
				for ( auto p : w.condition_ ) {
					if ( p < 0 )
						m_negated_conditions.insert( (-p)-1 );

				}
			}

		}

		m_negated.resize( m_task.num_fluents() );
		unsigned count = 0;
		for ( auto fl_idx : m_negated_conditions ) {
			aptk::Fluent* fl = m_task.fluents()[fl_idx];
			assert( fl != nullptr );
			std::string negated_signature = "(not " + fl->signature() + ")";
			unsigned neg_fl_idx = aptk::STRIPS_Problem::add_fluent( m_task, negated_signature );
			m_negated.at( fl_idx ) = m_task.fluents()[neg_fl_idx];
			count++;
		}
		if ( kp_instance_.options_.is_enabled( "planner:print:statistics" ) ) 
			std::cout << count << " negated fluents created" << std::endl;

	}

	void
	Lwaptk_Planner::make_kp_fluents_and_actions() {
		make_kp_fluents();
	
		handle_negated_conditions();
	
		for ( size_t k = 0; k < kp_instance_.n_actions(); k++ ) {
			const Instance::Action& act = *kp_instance_.actions_[k];
			make_kp_action( act );
		}	
		
		make_kp_goal();
		
		m_task.make_action_tables();
	}

	void
	Lwaptk_Planner::make_kp_goal() const {
		aptk::Fluent_Vec G;
		for ( auto g : kp_instance_.goal_literals_ ) {
			int fl_index = g > 0 ? g-1 : -g-1;
			bool negated = g < 0;
			if ( negated )
				fl_index = m_negated[fl_index]->index();
			G.push_back( fl_index );
		}
		STRIPS_Problem::set_goal( m_task, G );
	}

	void
	Lwaptk_Planner::update_initial_state( const State& s ) const {
		aptk::Fluent_Vec I;
		for ( auto i : s ) {
			assert( i < m_task.num_fluents() );
			I.push_back( i );
		}
		for ( unsigned p = 0; p < m_task.num_fluents(); p++ ) {
			if ( p >= m_negated.size() ) continue; // p is a negated fluent
			if ( std::find( I.begin(), I.end(), p ) != I.end() )
				continue;
			if ( m_negated.at(p) )
				I.push_back( m_negated[p]->index() );
		}
		STRIPS_Problem::set_init( m_task, I );

	}

