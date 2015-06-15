#
# program for list, loop and if-else logic
# e.g
# 		 python2.7 LPHW-26-34.py
#
############################################
fruites = ['mango', 'banana', 'pinaple']

i = 0

for fruite in fruites:
	print "%d %s" %(i, fruite)
	i += 1

newFr = raw_input("Enter new fruit : ")

if newFr == "strawberry":
	print "%s is strawberry" %(newFr)
else:
	print "%s is not strawberry" %(newFr)

fruites.append(newFr);

i = 0
while i  < len(fruites):
	print "%d %s" %(i, fruites[i])
	i += 1
