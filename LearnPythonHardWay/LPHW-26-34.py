
# program for list, loop and if-else logic

fruites = ['mango', 'banana', 'pinaple']

i = 0

for fruite in fruites:
	print "%d %s" %(i, fruite)
	i += 1

newFr = raw_input("Enter new fruit : ")

if newFr == "strawberry":
	print "Its strawberry"
else:
	print "Its not strawberry"

fruites.append(newFr);

i = 0
while i < 4:
	print "%d %s" %(i, fruites[i])
	i += 1
