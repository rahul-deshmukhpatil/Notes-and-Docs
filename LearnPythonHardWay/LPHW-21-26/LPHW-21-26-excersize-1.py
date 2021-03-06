#
#	Prints the path given as arguments
#	e.g
# 		python2.7 LPHW-21-26-excersize-1.py  /home/rahul/upsc
#
##################################################################
from sys import argv
from sys import exit 

if len(argv) <= 1:
	print("%s :: needs more argument " %(argv[0]))
	print("usage %s filePath [filePath1[...]]" %(argv[0]))
	print("Prints all the files under the path[s] provided as argument")
	exit(-1)

#extract the list of the files from paths provided.
import glob
f=[]
for path in argv[1:3]:
	print("Extracting Path : %s" %(path))
	f = f + glob.glob(path)


if len(f) >= 1:
	print("Some Files Found are : ")
else:
	print("No File Found under any path !!!")

i=1
for fileName in f:
	print("%d : %s" %(i, fileName))
	i += 1;

