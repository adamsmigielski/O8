class Attribute :
	def __init__ (self):
		self.description = None;
		self.name = "";
		self.type = Type();
		
class Class :
	def __init__ (self) :
		self.attributes = [];
		self.description = None;
		self.methods = [];
		self.name = "";

class Interface :
	def __init__(self) :
		self.classes = [];
		self.name = "";
		self.routines = [];
		
class Method :
	def __init__ (self) :
		self.description = None
		self.name = "";
		self.parameters = [];
		self.rdescription = None
		self.result = None;
		
class Module :
	def __init__ (self) :
		self.name = None;
		self.namespace = None;
		self.interfaces = [];
		self.platforms = [];
		
class Namespace :
	def __init__(self) :
		self.name = None;
		self.child = None;
		
class Parameter :
	def __init__ (self) :
		self.name = "";
		self.type = Type();
		
class Platform :
	def __init__ (self) :
		self.name = "";
		self.size = "";
		self.type = "";
		
class Routine :
	def __init__ (self) :
		self.description = None
		self.name = "";
		self.parameters = [];
		self.rdescription = None
		self.result = None;
		
class Type :
	def __init__ (self) :
		self.constant = False;
		self.input = True;
		self.name = "";
		self.output = False;
		self.reference = False;
	
		