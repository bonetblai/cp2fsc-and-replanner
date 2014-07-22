#include "siw_plus_planner.h"
#include "utils.h"

#include <fwd_search_prob.hxx>
#include <novelty_partition.hxx>
#include <strips_state.hxx>
#include <landmark_graph.hxx>
#include <landmark_graph_generator.hxx>
#include <h_2.hxx>
#include <h_1.hxx>
#include <rp_heuristic.hxx>

#include <aptk/rp_iw.hxx>
#include <aptk/srpiw.hxx>
#include <aptk/serialized_search.hxx>
#include <aptk/string_conversions.hxx>

using	aptk::agnostic::Fwd_Search_Problem;
using 	aptk::agnostic::Landmarks_Graph_Generator;
using 	aptk::agnostic::Landmarks_Graph;
using 	aptk::agnostic::H2_Heuristic;
using 	aptk::agnostic::H1_Heuristic;
using	aptk::agnostic::H_Add_Evaluation_Function;
using	aptk::agnostic::Relaxed_Plan_Heuristic;

using 	aptk::agnostic::Novelty_Partition;
using	aptk::search::novelty_spaces::RP_IW;
using	aptk::search::novelty_spaces::SRPIW;
using	aptk::search::Serialized_Search;

typedef		aptk::search::novelty_spaces::Node< aptk::State >	          IW_Node;
typedef         Novelty_Partition<Fwd_Search_Problem, IW_Node>    H_Novel_Fwd;
typedef         H2_Heuristic<Fwd_Search_Problem>                  H2_Fwd;
typedef		H1_Heuristic<Fwd_Search_Problem, H_Add_Evaluation_Function>	H_Add_Fwd; 
typedef		Relaxed_Plan_Heuristic< Fwd_Search_Problem, H_Add_Fwd >		H_Add_Rp_Fwd;

typedef         Landmarks_Graph_Generator<Fwd_Search_Problem>     Gen_Lms_Fwd;
typedef		RP_IW< Fwd_Search_Problem, H_Novel_Fwd, H_Add_Rp_Fwd >	  RP_IW_Fwd;


typedef		SRPIW< Fwd_Search_Problem >        SIW_plus_Fwd;



SIW_plus_Planner::SIW_plus_Planner( const KP_Instance& instance, const char* tmpfile_path )
	: Lwaptk_Planner( "siw", instance, tmpfile_path ), m_iw_bound(4) {
}

SIW_plus_Planner::~SIW_plus_Planner() {
}

int 
SIW_plus_Planner::classical_planner( const State &state, Instance::Plan &raw_plan) const {

	Fwd_Search_Problem	search_prob( &m_task );

	//if ( !m_task.has_conditional_effects() ) {
	//	H2_Fwd    h2( search_prob );
	//	h2.compute_edeletes( m_task );
	//}
	//else 
		m_task.compute_edeletes();	

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
	
	SIW_plus_Fwd siw_engine( search_prob );

	if ( !kp_instance_.options_.is_enabled( "planner:print:statistics" ) )
		siw_engine.set_verbose(false);

	siw_engine.set_goal_agenda( &graph );
	
	float iw_t;
	siw_engine.set_bound(m_iw_bound);
	siw_engine.start();


	std::vector< aptk::Action_Idx > plan;
	float				cost;
	int 				result = ERROR;

	float ref = Utils::read_time_in_seconds();

	if ( siw_engine.find_solution( cost, plan ) ) {
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
			std::cout << ";; NOT I-REACHABLE ;;" << std::endl;
	}

 	iw_t =  Utils::read_time_in_seconds() - ref;

	total_search_time_ += iw_t;

	if ( kp_instance_.options_.is_enabled( "planner:print:statistics" ) ) {

		std::cout << "Total time: " << iw_t << std::endl;
		std::cout << "Nodes generated during search: " << siw_engine.generated() << std::endl;
		std::cout << "Nodes expanded during search: " << siw_engine.expanded() << std::endl;
		std::cout << "Nodes pruned by bound: " << siw_engine.sum_pruned_by_bound() << std::endl;
		std::cout << "Average ef. width: " << siw_engine.avg_B() << std::endl;
		std::cout << "Max ef. width: " << siw_engine.max_B() << std::endl;
	}

	return result;
}

