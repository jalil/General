import functools

def addToDict(k,v,d):
	if k in d: d[k] += v
	else: d[k] = v

def mode(lst):
	dct = {}
	map(functools.partial(addToDict, v=1,d=dct),lst)
	return reduce(lambda k1,k2: k1 if dct[k1] >= dct[k2] else k2, dct.keys())

def main():
	myList= [1,1,1,1,2,5,2,1]
	expected = 1
	print 'The outcome of mode(%s) is %i and the expected outcome was %i.' %(myList, mode(myList), expected)
	print 'Given that our result is %s to our expected outcome we declare that our functions is %s!' % ('equal','correct') if expected == mode(myList) else ('not equal','incorrect')

if __name__ == '__main__':
	main()
