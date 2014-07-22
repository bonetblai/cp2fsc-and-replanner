#ifndef __EPISTEMIC_SIW_PLANNER__
#define __EPISTEMIC_SIW_PLANNER__

#include "lwaptk_planner.h"

class Epistemic_SIW_Planner : public Lwaptk_Planner {

public:

	Epistemic_SIW_Planner( const KP_Instance& instance, const char* tmpfile_path );
	virtual ~Epistemic_SIW_Planner();

	virtual int classical_planner(const State &state, Instance::Plan &raw_plan) const;

	void	set_classical_width_initial_bound( unsigned v ) { m_iw_bound = v; }

protected:
	
	// MRJ: Maximum width to be considered before aborting (default is 4)
	unsigned 	m_iw_bound;

};

#endif // siw_planner.h
