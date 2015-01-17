# program for chapt 1 to 5
from sys import argv 
from os.path import exists  

def fileCopy(srcFile, *destFiles):
	if exists(srcFile):
		print "srcFile: %s exists proceeding further with copy" %(srcFile)
	else:
		print "srcFile: %s doesnt exists !!!" %(srcFile)
		return -1
	for destFileName in destFiles: 
		open(destFileName,'w').write(open(srcFile).read())
	


print "Functions and file proecssing"
program, first, second = argv

print """
	Program : %s
	SrcFile : %s
	Dest File: %s
""" % (program, first, second)

if exists(first):
	print "srcFile: %s exists proceeding further with copy" %(first)
else:
	print "srcFile: %s doesnt exists !!!" %(first)
	exit()

ip = open(first, 'r')
ipContent = ip.read(); 
print "First file contents are \n %s" %(ipContent)
fileCopy(first, second, "temp/2", "temp/3")

 


