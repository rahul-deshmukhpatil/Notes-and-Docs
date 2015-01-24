def strlen(a):
	return len(a)

class mystring(object):
	def __init__(self, stringObj):
		self.localObj = stringObj

	def printString(self):
		print "mystring: %s" %(self.localObj)


	def strlen(self):
		length = len(self.localObj)
		print "%s:%d" %(self.localObj, length)



