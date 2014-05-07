#!/usr/bin/python
import os, sys, glob, re

class Hidden_State_Statistics :

	def __init__( self, text ) :
		self.plan_length = None
		self.solved = False
		self.n_calls = None
		self.preprocess_time = None
		self.planner_time = None
		self.planner_search_time = None
		self.instance_time = None
		self.total_acc_time = None
		self.total_time = None
		self.prep_time = None
		self.exec_time = None
		self.load_data_from_text( text )

	def load_data_from_text( self, text ) :
		plan_len_re = re.compile( r'(-?\d+) \(plan-size\)' )
		n_calls_re = re.compile( r'(\d+) \(planner-calls\)' )
		pre_time_re = re.compile( r'(\d+\.?\d*) \(preprocessing-time\)')
		plan_time_re = re.compile( r'(\d+\.?\d*) \(planner-time\)')
		plan_search_re = re.compile( r'(\d+\.?\d*) \(planner-search-time\)')
		instance_time_re = re.compile( r'(\d+\.?\d*) \(instance-time\)' )
		total_time_re = re.compile( r'(\d+\.?\d*) \(total-acc-time\)' )

		try :
			self.plan_length = int(plan_len_re.search( text ).group(1))
			if self.plan_length >= 0 : self.solved = True
			self.n_calls = int(n_calls_re.search(text).group(1))
			self.preprocess_time = float( pre_time_re.search(text).group(1) )
			self.planner_time = float( plan_time_re.search(text).group(1))
			self.planner_search_time = float( plan_search_re.search(text).group(1))
			self.instance_time = float( instance_time_re.search(text).group(1))
			self.total_acc_time = float( total_time_re.search(text).group(1))
		except AttributeError, e :
			print >> sys.stdout, e
			print >> sys.stdout, text
			sys.exit(1)

		# derived values
		self.total_time = self.instance_time
		self.prep_time = self.planner_time - self.planner_search_time
		self.exec_time = self.instance_time - self.planner_time + self.planner_search_time

	def describe( self, stream, indent ) :
		values = [ str(self.plan_length), str(self.n_calls), str(self.total_time), str(self.prep_time), str(self.exec_time) ]
		print >> stream, "%s%s"%(indent, ",".join( values ) )

class Problem_Statistics :

	def __init__(self, filename) :
		self.filename = filename
		basename = os.path.split(self.filename)[-1]
		basename_no_ext = basename.replace( '.log', '' )
		tokens = basename_no_ext.split('-')
		self.planner = tokens[0]
		self.domain = tokens[1]
		self.instance = '-'.join( tokens[2:] )
		self.hidden_state_stats = []
		self.process_log_file()
		self.compute()

	def compute( self ) :
		self.n_solved = 0
		self.plan_len = 0.0
		self.n_calls = 0.0
		self.total_time = 0.0
		self.prep_time = 0.0
		self.exec_time = 0.0

		for h in self.hidden_state_stats :
			if not h.solved : continue
			self.n_solved += 1
			self.plan_len += h.plan_length
			self.n_calls += h.n_calls
			self.total_time += h.total_time
			self.prep_time += h.prep_time
			self.exec_time += h.exec_time

		if self.n_solved < 1 : 
			self.plan_len = 'n/a'
			self.n_calls = 'n/a'
			self.total_time = 'n/a'
			self.prep_time = 'n/a'
			self.exec_time = 'n/a'
			return

		self.plan_len /= self.n_solved
		self.n_calls /= self.n_solved
		self.total_time /= self.n_solved 
		self.prep_time /= self.n_solved
		self.exec_time /= self.n_solved

	def process_log_file( self ) :
		with open( self.filename ) as instream :
			for line in instream :
				if "stats:" in line :
					self.hidden_state_stats.append( Hidden_State_Statistics( line.strip() ) )
		
	def write( self, stream ) :
		values = [ 	self.planner, self.domain, self.instance, 
				str(len(self.hidden_state_stats)), str(self.n_solved), str(self.n_calls), 
				str(self.plan_len), str(self.total_time), str(self.prep_time), str(self.exec_time)]
		print >> stream, ",".join(values)


	def describe(self) :
		print >> sys.stdout, "Result:"
		print >> sys.stdout, "\t", self.planner
		print >> sys.stdout, "\t", self.domain
		print >> sys.stdout, "\t", self.instance
		print >> sys.stdout, "\t # Hidden states solved:", len( self.hidden_state_stats)
		for h in self.hidden_state_stats :
			h.describe( sys.stdout, "\t\t" )

def main() :
	
	if len( sys.argv ) < 2 :
		print >> sys.stderr, "No input folder was specified!"
		sys.exit(1)
	if len( sys.argv ) < 3 :
		print >> sys.stderr, "No output filename was specified!"
		sys.exit(1)

	input_dir = sys.argv[1]
	out_filename = sys.argv[2]

	result_files_list = glob.glob( os.path.join( input_dir, '*.log' ) )
	print >> sys.stdout, len(result_files_list), "result files found"

	problem_stats = []

	with open( out_filename, 'w' ) as output :

		for filename in result_files_list :
			stats = Problem_Statistics( filename )	
			stats.compute()
			stats.write( sys.stdout )
			stats.write( output )


if __name__ == '__main__' :
	main()
