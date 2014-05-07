#include "dfs_rpiw_planner.h"
#include "utils.h"
#include <fwd_search_prob.hxx>
#include <novelty.hxx>
#include <novelty_partition.hxx>
#include <landmark_graph.hxx>
#include <landmark_graph_generator.hxx>
#include <h_2.hxx>
#include <h_1.hxx>
#include <rp_heuristic.hxx>

#include <aptk/rp_iw.hxx>
#include <aptk/dfs_rpiw.hxx>
#include <aptk/serialized_search.hxx>

using	aptk::STRIPS_Problem;
using	aptk::agnostic::Fwd_Search_Problem;

using 	aptk::agnostic::Landmarks_Graph_Generator;
using 	aptk::agnostic::Landmarks_Graph;
using 	aptk::agnostic::H2_Heuristic;
using 	aptk::agnostic::H1_Heuristic;
using	aptk::agnostic::H_Add_Evaluation_Function;
using	aptk::agnostic::Relaxed_Plan_Heuristic;

using 	aptk::agnostic::Novelty;
using 	aptk::agnostic::Novelty_Partition;
using	aptk::search::Serialized_Search;
using	aptk::search::novelty_spaces::RP_IW;
using	aptk::search::novelty_spaces::DFS_RPIW;

typedef		aptk::search::novelty_spaces::Node< aptk::State > IW_Node;
typedef         Novelty_Partition<Fwd_Search_Problem, IW_Node>    H_Novel_Fwd;
typedef         H2_Heuristic<Fwd_Search_Problem>                  H2_Fwd;
typedef		H1_Heuristic<Fwd_Search_Problem, H_Add_Evaluation_Function>	H_Add_Fwd; 
typedef		Relaxed_Plan_Heuristic< Fwd_Search_Problem, H_Add_Fwd >		H_Add_Rp_Fwd;

typedef         Landmarks_Graph_Generator<Fwd_Search_Problem>     Gen_Lms_Fwd;
typedef		RP_IW< Fwd_Search_Problem, H_Novel_Fwd, H_Add_Rp_Fwd >	  RP_IW_Fwd;


typedef		DFS_RPIW< Fwd_Search_Problem, RP_IW_Fwd, IW_Node >        DFS_RPIW_Fwd;
//typedef		DFS_RPIW< Fwd_Search_Problem >        DFS_RPIW_Fwd;


DFS_RPIW_Planner::DFS_RPIW_Planner( const KP_Instance& instance, const char* tmpfile_path )
	: Lwaptk_Planner( "dfs_rpiw", instance, tmpfile_path ), m_max_novelty( 2 ){

}

DFS_RPIW_Planner::~DFS_RPIW_Planner() {
}

int
DFS_RPIW_Planner::classical_planner(const State &state, Instance::Plan &raw_plan) const {
	

	float t0 = 0.0f, tf;

	if ( kp_instance_.options_.is_enabled( "planner:print:statistics" ) )
		t0 = Utils::read_time_in_seconds();

	Fwd_Search_Problem	search_prob( &m_task );

	if ( kp_instance_.options_.is_enabled( "planner:print:statistics" ) ) {
		tf = Utils::read_time_in_seconds() - t0;
		std::cout << "Search problem construction.... (" << tf << " secs)" << std::endl;
	}

	if ( kp_instance_.options_.is_enabled( "planner:print:statistics" ) )
		t0 = Utils::read_time_in_seconds();
	
	//H2_Fwd    h2( search_prob );
	//h2.compute_edeletes_aij( m_task );
	m_task.compute_edeletes();
	
	if ( kp_instance_.options_.is_enabled( "planner:print:statistics" ) ) {
		tf = Utils::read_time_in_seconds() - t0;
		std::cout << "E-deletes computation.... (" << tf << " secs)" << std::endl;
	}

	if ( kp_instance_.options_.is_enabled( "planner:print:statistics" ) )
		t0 = Utils::read_time_in_seconds();

	Gen_Lms_Fwd    gen_lms( search_prob );
	
	if ( !kp_instance_.options_.is_enabled( "planner:print:statistics" ) )
		gen_lms.set_verbose( false );

	Landmarks_Graph graph( m_task );
	gen_lms.compute_lm_graph_set_additive( graph );

	if ( kp_instance_.options_.is_enabled( "planner:print:statistics" ) ) {
		std::cout << "Landmarks found: " << graph.num_landmarks() << std::endl;
		graph.print( std::cout );
	
		tf = Utils::read_time_in_seconds() - t0;
		std::cout << "Landmark graph construction.... (" << tf << " secs)" << std::endl;
	}

	if ( kp_instance_.options_.is_enabled( "planner:print:statistics" ) )
		t0 = Utils::read_time_in_seconds();

	DFS_RPIW_Fwd dfs_engine( search_prob );

	if ( !kp_instance_.options_.is_enabled( "planner:print:statistics" ) ) {
		//dfs_engine.set_verbose(false);
	}

	if ( kp_instance_.options_.is_enabled( "planner:print:statistics" ) ) {

		tf = Utils::read_time_in_seconds() - t0;
		std::cout << "Search engine construction.... (" << tf << " secs)" << std::endl;

		t0 = Utils::read_time_in_seconds();
	}

	dfs_engine.set_bound(m_max_novelty);
	dfs_engine.set_goal_agenda( &graph );
	dfs_engine.start();

	std::vector< aptk::Action_Idx > plan;
	float				cost;
	int				result = ERROR;

	float ref = Utils::read_time_in_seconds();

	if ( dfs_engine.find_solution( cost, plan ) ) {
		for ( unsigned k = 0; k < plan.size(); k++ ) {
			const aptk::Action& a = *(m_task.actions()[ plan[k] ]);
			std::map<std::string, size_t>::const_iterator it = action_map_.find(a.signature());
			assert(it != action_map_.end());
			raw_plan.push_back(it->second);
		}
		result = SOLVED;
	}
	else
		result = NO_SOLUTION;

 	float call_time = Utils::read_time_in_seconds() - ref;
	total_search_time_ += call_time;
	if ( kp_instance_.options_.is_enabled( "planner:print:statistics" ) ) {
		std::cout << "Total time: " << call_time << std::endl;
		std::cout << "Nodes generated during search: " << dfs_engine.generated() << std::endl;
		std::cout << "Nodes expanded during search: " << dfs_engine.expanded() << std::endl;
		std::cout << "Backtracks during search: " << dfs_engine.backtracks() << std::endl;
	}

	return result;
}
