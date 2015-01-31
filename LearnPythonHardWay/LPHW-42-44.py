
'''
	Program demonstraring the inheritance and composition
'''

'''
	class fruit , base of all fruites
'''
class fruit(object):
	def __init__(self, color, shape):
		self.color = color
		self.shape = shape
	
	def printColor(self):
		print "default fruit: %s" %(self.color)
	
	def printShape(self):
		print "default fruit: %s" %(self.shape)

'''
	class sellable could be selled
'''
class sellable(object):
	def __init__(self, price, quantity):
		self.price = price 
		self.quantity = quantity 

	def printPrice(self):
		print "default sellable: %s" %(self.price)
	
	def printQuantity(self):
		print "default sellable: %s" %(self.quantity)

'''
	Mango is inherited from fruit
	and is composed of sellable 
'''
class mango(fruit):
	def __init__(self, color, shape, price, quantity):
		self.sell = sellable(price, quantity)
		super(mango, self).__init__(color, shape)


alphanso = mango("red", "elliptical", 100.00, 12)
alphanso.printColor()
alphanso.printShape()
alphanso.sell.printPrice();
alphanso.sell.printQuantity();
	 


