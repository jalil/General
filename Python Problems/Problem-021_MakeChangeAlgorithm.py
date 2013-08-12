def makeChange(chng):
	d = {25: None, 10: None, 5: None, 1: None}
	for denomination in sorted(d.keys(), reverse=True): d[denomination], chng = chng / denomination, chng % denomination
	return d


print makeChange(104)
