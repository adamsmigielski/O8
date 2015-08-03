class Indent :
	def __init__(self) :
		self.char = ' ';
		self.level = 0;
		self.size = 4;
		
	def decrease(self):
		if (0 != self.level):
			self.level -= 1;
		
	def increase(self):
		self.level += 1;
		
	def get(self):
		length = self.level * self.size;
		return self.char * length;