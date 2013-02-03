def evenFibSum(intUpperBound):
	accumulator = 0
	intLLTerm = 0
	intLastTerm = 1
	while intTerm < intUpperBound:
		intTerm = intLastTerm + intLLTerm
		if intTerm % 2 == 0:
			accumulator += intTerm
		intLLTerm = intLastTerm
		intLastTerm = intTerm
	return accumulator

print evenFibSum(4000000)
