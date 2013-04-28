import os

lst = os.listdir(".")
#print lst

lstlinesums = []

for tfile in lst:
	if tfile[0] == 'O':
		f = open('./' + tfile, 'r')
		l = f.readlines()
		lstlinesums.append(len(l))
		f.close()

print "The number of files in the directory is " + str(len(lst))
asum = 0
for val in lstlinesums:
	asum += val

ave = asum / float(len(lstlinesums))

print "The average number of lines is " + str(ave) 
print "The total number of lines is " + str(asum)
