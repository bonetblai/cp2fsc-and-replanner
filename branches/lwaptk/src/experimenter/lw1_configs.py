
class FF :
	
	def __init__(self ) :
		self.planner = 'ff'
		self.planner_path = '.'

	def get_flags( self ) :
		return "--planner %s --planner_path %s"%(self.planner, self.planner_path)

class BFS_f :
	
	def __init__(self ) :
		self.planner = 'bfs_f'

	def get_flags( self ) :
		return "--planner %s "%self.planner


class SIW :
	
	def __init__(self ) :
		self.planner = 'siw'

	def get_flags( self ) :
		return "--planner %s "%self.planner

