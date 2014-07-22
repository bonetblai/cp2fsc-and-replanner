#include "ff_lwaptk_planner.h"
#include "utils.h"

#include <aptk/open_list.hxx>
#include <fwd_search_prob.hxx>
#include <strips_state.hxx>
#include <landmark_graph.hxx>
#include <landmark_graph_generator.hxx>
#include <h_1.hxx>
//#include "h_1_cl.hxx"
#include <layered_h_max.hxx>
#include "ff_ehc.h"
#include "ff_gbfs.h"
#include "ff_rp_heuristic.h"

using aptk::agnostic::Fwd_Search_Problem;
using aptk::agnostic::H1_Heuristic;
//using aptk::agnostic::H1_CL_Heuristic;
using aptk::agnostic::H_Add_Evaluation_Function;
using aptk::agnostic::H_Max_Evaluation_Function;
using aptk::agnostic::Layered_H_Max;
using aptk::agnostic::FF_Relaxed_Plan_Heuristic;
using aptk::agnostic::Landmarks_Graph_Generator;
using aptk::agnostic::Landmarks_Graph;

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
//typedef H1_CL_Heuristic< Fwd_Search_Problem, H_Add_Evaluation_Function >	H_Add_Fwd_2;
//typedef H1_CL_Heuristic< Fwd_Search_Problem, H_Max_Evaluation_Function >	H_Max_Fwd_2;
//typedef FF_Relaxed_Plan_Heuristic< Fwd_Search_Problem, H_Add_Fwd_2 > 		FF_H_Add_Rp_Fwd_2;
//typedef FF_Relaxed_Plan_Heuristic< Fwd_Search_Problem, H_Max_Fwd_2 >		FF_H_Max_Rp_Fwd_2;
typedef Layered_H_Max< Fwd_Search_Problem >					Alt_H_Max;
typedef FF_Relaxed_Plan_Heuristic< Fwd_Search_Problem, Alt_H_Max, unsigned >	Classic_FF_H_Max;

// MRJ: Goal ordering
typedef Landmarks_Graph_Generator<Fwd_Search_Problem>     	Gen_Lms_Fwd;

// MRJ: Search engines
//typedef FF_GBFS< Fwd_Search_Problem, FF_H_Add_Rp_Fwd_2, FF_Open_List >	FF_GBFS_H_Add;
//typedef FF_GBFS< Fwd_Search_Problem, FF_H_Max_Rp_Fwd_2, FF_Open_List >	FF_GBFS_H_Max;
//typedef FF_EHC< Fwd_Search_Problem, FF_H_Add_Rp_Fwd_2 >			FF_EHC_H_Add;
//typedef FF_EHC< Fwd_Search_Problem, FF_H_Max_Rp_Fwd_2 >			FF_EHC_H_Max;
typedef FF_GBFS< Fwd_Search_Problem, Classic_FF_H_Max, FF_Open_List >		Classic_FF_GBFS;
typedef FF_EHC< Fwd_Search_Problem, Classic_FF_H_Max >				Classic_FF_EHC;

FF2_Planner::FF2_Planner( const KP_Instance& instance, const char* tmpfile_path )
	: Lwaptk_Planner( "ff2", instance, tmpfile_path ) {
}

FF2_Planner::~FF2_Planner() {
}

int
FF2_Planner::classical_planner( const  State& state, Instance::Plan &raw_plan) const {

	Fwd_Search_Problem	search_prob( &m_task );


	float	ff_t;

	std::vector< aptk::Action_Idx > plan;
	unsigned			cost;
	int 				result = ERROR;

	/*
	Gen_Lms_Fwd    gen_lms( search_prob );

	if ( !kp_instance_.options_.is_enabled( "planner:print:statistics" ) )
		gen_lms.set_verbose( false );

	Landmarks_Graph graph( m_task );

	gen_lms.set_only_goals( true );
	gen_lms.compute_lm_graph_set_additive( graph );

	if ( kp_instance_.options_.is_enabled( "planner:print:statistics" ) ) {
		std::cout << "Landmarks found: " << graph.num_landmarks() << std::endl;
		graph.print( std::cout );
	}
	*/
	Classic_FF_EHC ehc_engine( search_prob );
	ehc_engine.start();

	float	ref = Utils::read_time_in_seconds();
	bool solved = ehc_engine.find_solution( cost, plan );
	ff_t = Utils::read_time_in_seconds() - ref;
	total_search_time_ += ff_t;

	if ( solved  ) {
		std::cout << "Cost of plan: " << cost << ", time: " << ff_t << " secs" << std::endl;
		for ( unsigned k = 0; k < plan.size(); k++ ) {
			const aptk::Action& a = *(m_task.actions()[ plan[k] ]);
			std::map<std::string, size_t>::const_iterator it = action_map_.find(a.signature());
			assert(it != action_map_.end());
			raw_plan.push_back(it->second);
		}
		result = SOLVED;
	
		if ( kp_instance_.options_.is_enabled( "planner:print:statistics" ) ) {
	
			std::cout << "Total time: " << ff_t << std::endl;
			std::cout << "Solved by: EHC" << std::endl;
			std::cout << "Nodes generated during search: " << ehc_engine.generated() << std::endl;
			std::cout << "Nodes expanded during search: " << ehc_engine.expanded() << std::endl;
		}

		return result;
	} 

	Classic_FF_GBFS		bfs_engine( search_prob );
	bfs_engine.start();

	ref = Utils::read_time_in_seconds();
	solved = bfs_engine.find_solution( cost, plan );
	ff_t = Utils::read_time_in_seconds() - ref;
	total_search_time_ += ff_t;

	if ( solved ) {
		std::cout << "Cost of plan: " << cost << ", time: " << ff_t << " secs" << std::endl;
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

	if ( kp_instance_.options_.is_enabled( "planner:print:statistics" ) ) {

		std::cout << "Total time: " << ff_t << std::endl;
		std::cout << "Solved by: BFS" << std::endl;
		std::cout << "Nodes generated during search: " << bfs_engine.generated() << std::endl;
		std::cout << "Nodes expanded during search: " << bfs_engine.expanded() << std::endl;
	}

	return result;
	
}
