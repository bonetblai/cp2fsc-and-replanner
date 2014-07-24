#include "bfs_f_planner.h"
#include "utils.h"
#include <fwd_search_prob.hxx>
#include <novelty_partition.hxx>
#include <lm_cut_heuristic.hxx>
#include <landmark_graph.hxx>
#include <landmark_graph_generator.hxx>
#include <landmark_graph_manager.hxx>
#include <landmark_count.hxx>
#include <h_2.hxx>
#include <h_1.hxx>
#include <rp_heuristic.hxx>
#include <layered_h_max.hxx>
#include <ff_rp_heuristic.hxx>
#include <count_heuristic.hxx>

#include <aptk/open_list.hxx>

#include "bfs_f_variations.hxx"


using	aptk::agnostic::Fwd_Search_Problem;
using	aptk::Action;

using 	aptk::agnostic::Landmarks_Graph;
using 	aptk::agnostic::Landmarks_Graph_Generator;
using   aptk::agnostic::Landmarks_Graph_Manager;
using 	aptk::agnostic::Landmarks_Count_Heuristic;
using 	aptk::agnostic::LM_Cut_Heuristic;
using 	aptk::agnostic::H2_Heuristic;
using 	aptk::agnostic::H1_Heuristic;
using	aptk::agnostic::H_Add_Evaluation_Function;
using   aptk::agnostic::Count_Heuristic;
using	aptk::agnostic::Relaxed_Plan_Heuristic;
using 	aptk::agnostic::Novelty_Partition;

using   aptk::agnostic::Layered_H_Max;
using   aptk::agnostic::FF_Relaxed_Plan_Heuristic;


using 	aptk::search::Open_List;
using	aptk::search::bfs_f_variations::Node_Comparer_3H;
using	aptk::search::bfs_f_variations::BFS_f_VARIATIONS;

typedef         H2_Heuristic<Fwd_Search_Problem>                  H2_Fwd;
typedef         Landmarks_Graph_Generator<Fwd_Search_Problem>     Gen_Lms_Fwd;
typedef         LM_Cut_Heuristic<Fwd_Search_Problem>              H_Lmcut_Fwd;
typedef         Landmarks_Count_Heuristic<Fwd_Search_Problem>     H_Lmcount_Fwd;
typedef         Landmarks_Graph_Manager<Fwd_Search_Problem>       Land_Graph_Man;
typedef         Count_Heuristic<Fwd_Search_Problem>               H_count_Fwd;


// MRJ: We start defining the type of nodes for our planner
typedef		aptk::search::bfs_f_variations::Node< Fwd_Search_Problem, aptk::State >	Search_Node;
typedef         Novelty_Partition<Fwd_Search_Problem, Search_Node>              H_Novel_Fwd;

// MRJ: Then we define the type of the tie-breaking algorithm
// for the open list we are going to use
typedef		Node_Comparer_3H< Search_Node >					Tie_Breaking_Algorithm;

// MRJ: Now we define the Open List type by combining the types we have defined before
typedef		Open_List< Tie_Breaking_Algorithm, Search_Node >		BFS_Open_List;

// MRJ: Now we define the heuristics
typedef		H1_Heuristic<Fwd_Search_Problem, H_Add_Evaluation_Function>	H_Add_Fwd; //, aptk::agnostic::H1_Cost_Function::Ignore_Costs
typedef		Relaxed_Plan_Heuristic< Fwd_Search_Problem, H_Add_Fwd >		H_Add_Rp_Fwd;

typedef         Layered_H_Max< Fwd_Search_Problem >				      Alt_H_Max;
typedef         FF_Relaxed_Plan_Heuristic< Fwd_Search_Problem, Alt_H_Max, unsigned >     Classic_FF_H_Max;


// MRJ: Now we're ready to define the BFS algorithm we're going to use
typedef		BFS_f_VARIATIONS< Fwd_Search_Problem, H_Novel_Fwd, H_count_Fwd, Classic_FF_H_Max, BFS_Open_List >    Anytime_GBFS_FF_Rp_Fwd;



BFS_f_Planner::BFS_f_Planner( const KP_Instance& instance, const char* tmpfile_path )
	: Lwaptk_Planner( "bfs(f)", instance, tmpfile_path ), m_max_novelty( 1 ), m_one_ha_per_fluent( true ) {

}

BFS_f_Planner::~BFS_f_Planner() {
}

int
BFS_f_Planner::classical_planner(const State &state, Instance::Plan &raw_plan) const {
	

	float t0, tf;

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
	//m_task.compute_edeletes();
	if ( kp_instance_.options_.is_enabled( "planner:print:statistics" ) ) {
		tf = Utils::read_time_in_seconds() - t0;
		std::cout << "E-deletes computation.... (" << tf << " secs)" << std::endl;
	}

	if ( kp_instance_.options_.is_enabled( "planner:print:statistics" ) )
		t0 = Utils::read_time_in_seconds();

	// Gen_Lms_Fwd    gen_lms( search_prob );
	
	// if ( !kp_instance_.options_.is_enabled( "planner:print:statistics" ) )
	// 	gen_lms.set_verbose( false );

	// Landmarks_Graph graph( m_task );
	// gen_lms.compute_lm_graph_set_additive( graph );

	// if ( kp_instance_.options_.is_enabled( "planner:print:statistics" ) ) {
	// 	std::cout << "Landmarks found: " << graph.num_landmarks() << std::endl;
	// 	graph.print( std::cout );
	
	// 	tf = Utils::read_time_in_seconds() - t0;
	// 	std::cout << "Landmark graph construction.... (" << tf << " secs)" << std::endl;
	// }

	if ( kp_instance_.options_.is_enabled( "planner:print:statistics" ) )
		t0 = Utils::read_time_in_seconds();

	//Anytime_GBFS_H_Add_Rp_Fwd bfs_engine( search_prob );
	Anytime_GBFS_FF_Rp_Fwd bfs_engine( search_prob );		
	

	// MRJ: Setting "one h.a. per fluent" flag
	bfs_engine.h3().set_one_HA_per_fluent( m_one_ha_per_fluent );
	
	// NIR: Set K-fluents for counting how knowledge increases
	bfs_engine.h2().set_fluents( Lwaptk_Planner::epistemic_fluents() );

	if ( !kp_instance_.options_.is_enabled( "planner:print:statistics" ) ) {
		bfs_engine.set_verbose(false);
		bfs_engine.h1().set_verbose( false );
	}

	if ( kp_instance_.options_.is_enabled( "planner:print:statistics" ) ) {

		tf = Utils::read_time_in_seconds() - t0;
		std::cout << "Search engine construction.... (" << tf << " secs)" << std::endl;

		t0 = Utils::read_time_in_seconds();
	}

	//Land_Graph_Man lgm( search_prob, &graph);

	if ( kp_instance_.options_.is_enabled( "planner:print:statistics" ) ) {
		tf = Utils::read_time_in_seconds() - t0;
		std::cout << "Landmarks manager initialization.... (" << tf << " secs)" << std::endl;
	}

	//bfs_engine.use_land_graph_manager( &lgm );
	//bfs_engine.set_arity( m_max_novelty, graph.num_landmarks_and_edges() );
	bfs_engine.set_arity( m_max_novelty, 0 );
	bfs_engine.set_bound(m_max_novelty);
	bfs_engine.h3().ignore_rp_h_value(false);
	bfs_engine.start();

	std::vector< aptk::Action_Idx > plan;
	float				cost;
	int				result = ERROR;

	float ref = Utils::read_time_in_seconds();

	if ( bfs_engine.find_solution( cost, plan ) ) {
		for ( unsigned k = 0; k < plan.size(); k++ ) {
			const aptk::Action& a = *(m_task.actions()[ plan[k] ]);
			std::map<std::string, size_t>::const_iterator it = action_map_.find(a.signature());
			//std::cout << k << " - " << a.signature() << std::endl;
			assert(it != action_map_.end());
			raw_plan.push_back(it->second);
		}
		result = SOLVED;
	}
	else
		result = NO_SOLUTION;

 	float call_time = Utils::read_time_in_seconds() - ref;
	total_search_time_ += call_time;
	//if ( kp_instance_.options_.is_enabled( "planner:print:statistics" ) ) {
		std::cout << "Total time: " << call_time << std::endl;
		std::cout << "Nodes generated during search: " << bfs_engine.generated() << std::endl;
		std::cout << "Nodes expanded during search: " << bfs_engine.expanded() << std::endl;
		//}

	return result;
}
