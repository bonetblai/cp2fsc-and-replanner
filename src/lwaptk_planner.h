#ifndef __LWAPTK_PLANNER__
#define __LWAPTK_PLANNER__

#include "classical_planner.h"
#include <strips_prob.hxx>  // lwaptk class for STRIPS problems

using aptk::STRIPS_Problem;

class Lwaptk_Planner : public ClassicalPlanner {

public:

	Lwaptk_Planner(const char* name, const KP_Instance &instance, const char *tmpfile_path);

    	virtual ~Lwaptk_Planner();

    	virtual int get_raw_plan(const State &state, Instance::Plan &raw_plan) const;

protected:
	
	void	make_kp_fluents_and_actions();
	void	make_kp_fluents();
	void	make_kp_action( const Instance::Action& act );
	void	make_kp_goal( ) const;
	void	update_initial_state( const State &state ) const;
	void	handle_negated_conditions();
	void	handle_effect_literal( int p, aptk::Fluent_Vec& pos, aptk::Fluent_Vec& neg );

protected:

	mutable STRIPS_Problem		m_task;

private:

	std::set<int>			m_negated_conditions;
	aptk::Fluent_Ptr_Vec		m_negated;
};

#endif // lwaptk_planner.h
