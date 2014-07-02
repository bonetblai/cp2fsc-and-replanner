#ifndef __FF_LWAPTK_PLANNER__
#define __FF_LWAPTK_PLANNER__

#include "lwaptk_planner.h"

class FF2_Planner : public Lwaptk_Planner {

public:

	FF2_Planner( const KP_Instance& instance, const char* tmpfile_path );
	virtual ~FF2_Planner();

	virtual int	classical_planner( const State& state, Instance::Plan& raw_plan ) const;

protected:

};


#endif // ff_lwaptk_planner.h
