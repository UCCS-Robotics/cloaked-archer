#Unified Simulation 

#Base sensor object classes

class _sensor:
	"""Linear Sensor Root Object"""
	def __init__(self, arg):
		super(_sensor, self).__init__()
		self.arg = arg

	#Take sensor reading within current simulation environment
	def takeReading(self):
		pass

	#Convert sensor reading from voltage to sensor metric unit
	#Linear Metric Version
	def LinearMetric(self):
		pass

class _sensor_NL:
	"""Nonlinear Sensor Root Object"""
	def __init__(self, arg):
		super(_sensor_NL, self).__init__()
		self.arg = arg
		
	#Take sensor reading within current simulation environment
	def takeReading(self):
		pass

	#Convert sensor reading from voltage to sensor metric unit
	#Nonlinear Metric Version
	def NonLinearMetric(self):
		pass

#Linear Sensor Profiles

class USSensor(_sensor):
	"""Linear Ultrasonic Sensor Profile"""
	def __init__(self, arg):
		super(USSensor, self).__init__()
		self.arg = arg
	
	def LinearMetric(self):
		pass

class IRSensor(_sensor):
	"""Linear Infrared Sensor Profile"""
	def __init__(self, arg):
		super(IRSensor, self).__init__()
		self.arg = arg
	
	def LinearMetric(self):
		pass

class GyroSensor(_sensor):
	"""Linear Gyroscope Sensor Profile"""
	def __init__(self, arg):
		super(GyroSensor, self).__init__()
		self.arg = arg
		
	def takeReading(self):
		pass

	def LinearMetric(self):
		pass

class GPSSensor(_sensor):
	"""Linear GPS Sensor Profile"""
	def __init__(self,arg):
		super(GPSSensor, self).__init__()
		self.arg = arg

	def takeReading(self):
		pass

	def LinearMetric(self):
		pass

class CompassSensor(_sensor):
	"""Linear Compass Sensor Profile"""
	def __init__(self, arg):
		super(CompassSensor, self).__init__()
		self.arg = arg

	def takeReading(self):
		pass

	def LinearMetric(self):
		pass

class AltimeterSensor(_sensor):
	"""Linear Altimeter Sensor Profile"""
	def __init__(self, arg):
		super(AltimeterSensor, self).__init__()
		self.arg = arg
		
	def takeReading(self):
		pass

	def LinearMetric(self):
		pass

class AccelSensor(_sensor_NL):
	"""Linear Accelerometer Sensor Profile"""
	def __init__(self, arg):
		super(AccelSensor, self).__init__()
		self.arg = arg
		
	def takeReading(self):
		pass

	def LinearMetric(self):
		pass

#Nonlinear Sensor Profiles
#Only use when operating in a nonlinear region

class USSensor_NL(_sensor_NL):
	"""Nonlinear Ultrasonic Sensor Profile"""
	def __init__(self, arg):
		super(USSensor_NL, self).__init__()
		self.arg = arg
		
	def NonLinearMetric(self):
		pass

class IRSensor_NL(_sensor_NL):
	"""Nonlinear Infrared Sensor Profile"""
	def __init__(self, arg):
		super(IRSensor_NL, self).__init__()
		self.arg = arg
		
	def NonLinearMetric(self):
		pass

class GyroSensor_NL(_sensor_NL):
	"""Nonlinear Gyroscope Sensor Profile"""
	def __init__(self, arg):
		super(GyroSensor, self).__init__()
		self.arg = arg

	def takeReading(self):
		pass

	def NonLinearMetric(self):
		pass
		
class GPSSensor_NL(_sensor_NL):
	"""Nonlinear GPS Sensor Profile"""
	def __init__(self,arg):
		super(GPSSensor, self).__init__()
		self.arg = arg

	def takeReading(self):
		pass

	def NonLinearMetric(self):
		pass

class CompassSensor_NL(_sensor_NL):
	"""Nonlinear Compass Sensor Profile"""
	def __init__(self, arg):
		super(CompassSensor_NL, self).__init__()
		self.arg = arg

	def takeReading(self):
		pass

	def NonLinearMetric(self):
		pass

class AltimeterSensor_NL(_sensor_NL):
	"""Nonlinear Altimeter Sensor Profile"""
	def __init__(self, arg):
		super(AltimeterSensor_NL, self).__init__()
		self.arg = arg

	def takeReading(self):
		pass

	def NonLinearMetric(self):
		pass
	
class AccelSensor_NL(_sensor_NL):
	"""Nonlinear Accelerometer Sensor Profile"""
	def __init__(self, arg):
		super(AccelSensor_NL, self).__init__()
		self.arg = arg
		
	def takeReading(self):
		pass

	def NonLinearMetric(self):
		pass