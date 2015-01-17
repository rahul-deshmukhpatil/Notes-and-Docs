# program for chapt 1 to 5
from sys import argv 
print "Argument parsing and input"

program, first, second, third = argv

print """
	Program : %s
	first	: %s
	second	: %s
	third	: %s
""" % (program, first, second, third)

prompt = ">> "
firstAns = raw_input(first)
secondAns = raw_input(second)
thirdAns = raw_input(third)

pair = "%s:%s"
print pair %(first, firstAns)
print pair %(second, secondAns)
print pair %(third, thirdAns)



