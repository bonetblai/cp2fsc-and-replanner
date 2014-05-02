#ifndef __BFS_F_PLANNER__
#define __BFS_F_PLANNER__

#include "lwaptk_planner.h"

class BFS_f_Planner : public Lwaptk_Planner {

public:
	
	BFS_f_Planner( const KP_Instance& instance, const char* tmpfile_path );
	
	virtual ~BFS_f_Planner();

	virtual int get_raw_plan(const State &state, Instance::Plan &raw_plan) const;

	void	set_novelty_bound( unsigned v ) { m_max_novelty = v; }
	void	allow_one_ha_per_fluent() { m_one_ha_per_fluent = true; }
	void	allow_several_ha_per_fluent() { m_one_ha_per_fluent = false; }

protected:

	// MRJ: Maximum width to be considered before aborting
	// by default it is 2
	unsigned	m_max_novelty;
	// MRJ: Flag to specify how many helpful actions are allowed
	// for any given precondition of the relaxed plan (by default
	// it is set to true)
	bool		m_one_ha_per_fluent;
	std::string	m_plan_filename;
	std::string	m_log_filename;
};

#endif // bfs_f_planner
