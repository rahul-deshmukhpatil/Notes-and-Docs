#
# Program to demonstate list operations pop, join and append
#	e.g 
#
##########################################

"""
	Program for while loop and lists 
"""

listA = ['ram', 'sham', 'gyan']

listB = ['seeta', 'geeta', 'neeta', 'seema']

while (len(listA) < 6) and (len(listB) > 0): 
	lastElementOfB = listB.pop()
	print "removing %s from listB and adding to listA" %(lastElementOfB)
	listA.append(lastElementOfB);

print "List A is now: %s" %(listA)
print "List B is now: %s" %(listB)

print "ListA with intermittent #:%s" %('#'.join(listA))
print "first element of A:%s" %(listA[0])
print "last element of A:%s" %(listA[-1])


