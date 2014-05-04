#!/usr/bin/python
import os, sys, glob

class Problem_Statistics :

	def __init__(self) :
		self.filename = None
		self.domain = None
		self.instance = None

def main() :
	
	if len( sys.argv ) < 2 :
		print >> sys.stderr, "No input folder was specified!"
		sys.exit(1)
	
	input_dir = sys.argv[1]

	result_files_list = glob.glob( os.path.join( input_dir, '*.log' ) )
	print >> sys.stdout, len(result_files_list), "result files found"

	

if __name__ == '__main__' :
	main()
