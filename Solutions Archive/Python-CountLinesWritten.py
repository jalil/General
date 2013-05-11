import os
def summarizeFiles(fExt, path = "./"):
	root = os.listdir("./")
	lstlinesums = []

	for tfile in root:
		if tfile[len(tfile) - len(fExt):] == fExt:
			f = open('./' + tfile, 'r')
			l = f.readlines()
			lstlinesums.append(len(l))
			f.close()

	print "The number of files with the given file extension in the directory is " + str(len(lstlinesums))
	asum = 0
	for val in lstlinesums:
		asum += val

	ave = asum / float(len(lstlinesums))

	print "The average number of lines is " + str(ave) 
	print "The total number of lines is " + str(asum)
def main():
	print "\nYour summary of Python files is:"
	summarizeFiles(".py")
	
	print "\nYour summary of C++ files is:"
	summarizeFiles(".cpp")
	print "\nYour summary of Ruby files is:"
	summarizeFiles(".rb")

main()
