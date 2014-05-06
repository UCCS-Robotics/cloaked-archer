#
#Obstacle Definitions
#
#Obstacles are approximations for plausible obstacles during
#intended operation.

class Wall:
	"""Standard Wall Object"""
	def __init__(self, arg):
		super(Wall, self).__init__()
		self.arg = arg

class Cyllinder:
	"""Standard Cyllinder Object"""
	def __init__(self, arg):
		super(Cyllinder, self).__init__()
		self.arg = arg
		
class Sphere:
	"""Standard Sphere Object"""
	def __init__(self, arg):
		super(Sphere, self).__init__()
		self.arg = arg
		
class Box:
	"""Standard Box Object"""
	def __init__(self, arg):
		super(Box, self).__init__()
		self.arg = arg
		