def sumMultiples(intUpperBound):
	accumulator = 0
	for idx in range(0, intUpperBound):
		if idx % 3 == 0 or idx % 5 == 0:
			accumulator += idx
	return accumulator


print sumMultiples(1000)
