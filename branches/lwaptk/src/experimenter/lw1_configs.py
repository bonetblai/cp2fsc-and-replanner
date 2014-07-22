
class FF :
	
	def __init__(self ) :
		self.planner = 'ff'
		self.planner_path = '.'

	def get_flags( self ) :
		return "--planner %s --planner-path %s"%(self.planner, self.planner_path)

	def get_random_flags( self, N, seed ) :
		return "--random --num-samples %s --seed %s --planner %s --planner-path %s"%(N, seed, self.planner, self.planner_path)

class FF2 :
	
	def __init__(self ) :
		self.planner = 'ff2'
		self.planner_path = '.'

	def get_flags( self ) :
		return "--planner %s"%self.planner

	def get_random_flags( self, N, seed ) :
		return "--random --num-samples %s --seed %s --planner %s"%(N, seed, self.planner)


class BFS_f :
	
	def __init__(self ) :
		self.planner = 'bfs_f'

	def get_flags( self ) :
		return "--planner %s "%self.planner

	def get_random_flags( self, N, seed ) :
		return "--random --num-samples %s --seed %s --planner %s"%(N, seed, self.planner)

class SIW :
	
	def __init__(self ) :
		self.planner = 'siw'

	def get_flags( self ) :
		return "--planner %s "%self.planner
	
	def get_random_flags( self, N, seed ) :
		return "--random --num-samples %s --seed %s --planner %s"%(N, seed, self.planner)

class Epistemic_SIW :
	
	def __init__(self ) :
		self.planner = 'epistemic_siw'

	def get_flags( self ) :
		return "--planner %s "%self.planner
	
	def get_random_flags( self, N, seed ) :
		return "--random --num-samples %s --seed %s --planner %s"%(N, seed, self.planner)

class DFS_RPIW :
	
	def __init__(self ) :
		self.planner = 'dfs_rpiw'

	def get_flags( self ) :
		return "--planner %s "%self.planner
	
	def get_random_flags( self, N, seed ) :
		return "--random --num-samples %s --seed %s --planner %s"%(N, seed, self.planner)

