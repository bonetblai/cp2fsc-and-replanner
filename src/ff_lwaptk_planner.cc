#include "ff_lwaptk_planner.h"
#include "utils.h"

#include <aptk/open_list.hxx>
#include <fwd_search_prob.hxx>
#include <strips_state.hxx>
#include <h_1.hxx>
#include "ff_ehc.h"
#include "ff_gbfs.h"
#include "ff_rp_heuristic.h"

using aptk::agnostic::Fwd_Search_Problem;
using aptk::agnostic::H1_Heuristic;
using aptk::agnostic::H_Add_Evaluation_Function;
using aptk::agnostic::H_Max_Evaluation_Function;
using aptk::agnostic::FF_Relaxed_Plan_Heuristic;
using aptk::search::FF_GBFS;
using aptk::search::Node_Comparer_HA;
using aptk::search::Open_List;
using aptk::search::FF_EHC;

// MRJ: Search node
typedef aptk::search::FF_GBFS_Node< aptk::State >	FF_Search_Node;

// MRJ: Tie breaking and best-node selection function
typedef Node_Comparer_HA< FF_Search_Node >		FF_Tie_Breaking;

// MRJ: Open List
typedef Open_List< FF_Tie_Breaking, FF_Search_Node >	FF_Open_List;

// MRJ: Heuristics
typedef H1_Heuristic< Fwd_Search_Problem, H_Add_Evaluation_Function >	H_Add_Fwd;
typedef H1_Heuristic< Fwd_Search_Problem, H_Max_Evaluation_Function >	H_Max_Fwd;
typedef FF_Relaxed_Plan_Heuristic< Fwd_Search_Problem, H_Add_Fwd > 	FF_H_Add_Rp_Fwd;
typedef FF_Relaxed_Plan_Heuristic< Fwd_Search_Problem, H_Max_Fwd >	FF_H_Max_Rp_Fwd;

// MRJ: Search engines
typedef FF_GBFS< Fwd_Search_Problem, FF_H_Add_Rp_Fwd, FF_Open_List >	FF_GBFS_H_Add;
typedef FF_GBFS< Fwd_Search_Problem, FF_H_Max_Rp_Fwd, FF_Open_List >	FF_GBFS_H_Max;
typedef FF_EHC< Fwd_Search_Problem, FF_H_Add_Rp_Fwd >			FF_EHC_H_Add;
typedef FF_EHC< Fwd_Search_Problem, FF_H_Max_Rp_Fwd >			FF_EHC_H_Max;

FF2_Planner::FF2_Planner( const KP_Instance& instance, const char* tmpfile_path )
	: Lwaptk_Planner( "ff2", instance, tmpfile_path ) {
}

FF2_Planner::~FF2_Planner() {
}

int
FF2_Planner::classical_planner( const  State& state, Instance::Plan &raw_plan) const {

	Fwd_Search_Problem	search_prob( &m_task );


	float	ff_t;
	float	ref = Utils::read_time_in_seconds();

	std::vector< aptk::Action_Idx > plan;
	float				cost;
	int 				result = ERROR;

	FF_EHC_H_Add ehc_engine( search_prob );
	ehc_engine.start();

	if ( ehc_engine.find_solution( cost, plan ) ) {
		for ( unsigned k = 0; k < plan.size(); k++ ) {
			const aptk::Action& a = *(m_task.actions()[ plan[k] ]);
			std::map<std::string, size_t>::const_iterator it = action_map_.find(a.signature());
			assert(it != action_map_.end());
			raw_plan.push_back(it->second);
		}
		result = SOLVED;
		ff_t = Utils::read_time_in_seconds() - ref;
	
		total_search_time_ += ff_t;
	
		if ( kp_instance_.options_.is_enabled( "planner:print:statistics" ) ) {
	
			std::cout << "Total time: " << ff_t << std::endl;
			std::cout << "Solved by: EHC" << std::endl;
			std::cout << "Nodes generated during search: " << ehc_engine.generated() << std::endl;
			std::cout << "Nodes expanded during search: " << ehc_engine.expanded() << std::endl;
		}

		return result;
	} 

	FF_GBFS_H_Add	bfs_engine( search_prob );
	bfs_engine.start();

	if ( bfs_engine.find_solution( cost, plan ) ) {
		for ( unsigned k = 0; k < plan.size(); k++ ) {
			const aptk::Action& a = *(m_task.actions()[ plan[k] ]);
			std::map<std::string, size_t>::const_iterator it = action_map_.find(a.signature());
			assert(it != action_map_.end());
			raw_plan.push_back(it->second);
		}
		result = SOLVED;
	} else {
		result = NO_SOLUTION;
		if ( kp_instance_.options_.is_enabled( "planner:print:statistics" ) )
			std::cout << ";; UNSOLVABLE ;;" << std::endl;
		
	}

	ff_t = Utils::read_time_in_seconds() - ref;
	
	total_search_time_ += ff_t;

	if ( kp_instance_.options_.is_enabled( "planner:print:statistics" ) ) {

		std::cout << "Total time: " << ff_t << std::endl;
		std::cout << "Solved by: BFS" << std::endl;
		std::cout << "Nodes generated during search: " << bfs_engine.generated() << std::endl;
		std::cout << "Nodes expanded during search: " << bfs_engine.expanded() << std::endl;
	}

	return result;
	
}
