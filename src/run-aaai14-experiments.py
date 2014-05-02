#!/usr/bin/python
import os
import glob

from experimenter import benchmark
from experimenter.lw1_configs import BFS_f, SIW


def main() :

	localize = [	['localize', 'p15'], ['localize','p17'] ]

	aaai14_benchmark = 	[
				['clog', 'p7'],
			 	['clog', 'ph'],
				['colorballs', 'p09-5'],
				['colorballs', 'p09-7'],
				['doors', 'p17'],
				['doors', 'p19'],
				['ebtcs', 'p50'],
				['ebtcs', 'p70'],
				['elog', 'p5'],
				['elog', 'p7'],
				['localize', 'p15'],
				['localize', 'p17'],
				['medpks', 'p150'],
				['medpks', 'p199'],
				['rocksample', 'p8-12'],
				['rocksample', 'p8-14'],
				['unix', 'p3'],
				['unix', 'p4'],
				['wumpus', 'p05d'],
				['wumpus', 'p10d'],
				['wumpus', 'p15d'],
				['wumpus', 'p20d'],
				['wumpus', 'p25d']
			]

	planners = [ SIW(), BFS_f() ]

	benchmarks_base_dir = '../benchmarks/lw1'
	max_time = 7200 # 4 hours
	max_mem = 4096 # 4 Gigabytes

	for planner in planners :
		for domain, instance in aaai14_benchmark :
			instance_base_dir = os.path.join( benchmarks_base_dir, domain )
			instance_base_dir = os.path.join( instance_base_dir, 'mvv' )
			instance_base_dir = os.path.join( instance_base_dir, instance )
			
			pddl_inputs = glob.glob( os.path.join(instance_base_dir, '*.pddl') )

			domain = None
			problem = None
			hidden = None

			for filename in pddl_inputs :
				if os.path.split(filename)[-1][0] == 'd' :
					domain = filename
				if os.path.split(filename)[-1][0] == 'p' :
					problem = filename
				if os.path.split(filename)[-1][0] == 'h' :
					hidden = filename
				

			command = './lw1-lwaptk %s %s %s %s'%( planner.get_flags(), domain, problem, hidden )
			log_filename = '%s-%s-%s.log'%(planner.planner, domain, instance)
			log = benchmark.Log( log_filename )

			rv, time = benchmark.run( command, max_time, max_mem, log )	

if __name__ == '__main__' :
	main()
