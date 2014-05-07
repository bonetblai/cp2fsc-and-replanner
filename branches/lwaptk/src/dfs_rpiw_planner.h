#ifndef __DFS_RPIW_PLANNER__
#define __DFS_RPIW_PLANNER__

#include "lwaptk_planner.h"

class DFS_RPIW_Planner : public Lwaptk_Planner {

public:

	DFS_RPIW_Planner( const KP_Instance& instance, const char* tmpfile_path );

	virtual ~DFS_RPIW_Planner();

	virtual int classical_planner(const State &state, Instance::Plan &raw_plan) const;

	void	set_novelty_bound( unsigned v ) { m_max_novelty = v; }

protected:
	// MRJ: Maximum width to be considered before aborting
	// by default it is 2
	unsigned m_max_novelty;
};

#endif // dfs_rpiw_planner.h
