from  arithmatic import add, multiply
from  string import strlen, mystring


print """
	LPHW-40: Importing modules and functions and classes
	Imported add and multiply from arithmatic
	Imported  string module
"""
a = 10
b = 20
print "Add %d %d = %d" %(a, b, add(10, 20))
print "Multiply %d %d = %d" %(a, b, multiply(10, 20))

a="rahul.deshmukhpatil"
print "stren '%s': %d" %(a, strlen(a))

name = mystring("rahul")
name.printString()
name.strlen()

