#ifndef __SIW_PLUS_PLANNER__
#define __SIW_PLUS_PLANNER__

#include "lwaptk_planner.h"

class SIW_plus_Planner : public Lwaptk_Planner {

public:

	SIW_plus_Planner( const KP_Instance& instance, const char* tmpfile_path );
	virtual ~SIW_plus_Planner();

	virtual int classical_planner(const State &state, Instance::Plan &raw_plan) const;

	void	set_classical_width_initial_bound( unsigned v ) { m_iw_bound = v; }

protected:
	
	// MRJ: Maximum width to be considered before aborting (default is 4)
	unsigned 	m_iw_bound;

};

#endif // siw_planner.h
