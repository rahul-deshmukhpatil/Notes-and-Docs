from urllib import urlopen

words = []

for w in urlopen("http://learncodethehardway.org/words.txt").readlines():
	words.append(w)

for word in words:
	print "word : %s" %(word)
