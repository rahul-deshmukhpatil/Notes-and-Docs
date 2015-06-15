#
#	Programs to show usage of dict DS in python
#
##################################################


"""
	LPHW-39
	Dicts
"""

#define a dict
states={'Maharashtra':'MH', 'Karnataka':'KA', 'Madhya Pradesh':'MP'}

#print all states are
def printStates(states):
	print "States are"
	i = 0
	for state,abbr in  states.items():
		print "%d> %s:%s" %(i, state, abbr)
		i+=1
	print

printStates(states)

states['Andhra Pradesh']='AP'

printStates(states)

abbr = states.get('Karnataka', None)
print "Abbr for Karnataka : %s" %(abbr)

if(abbr == None):
	print "No Abbr for Karnataka"


