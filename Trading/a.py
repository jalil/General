class CSV_Reader(object):
	def __init__(self, path):
		self.f = open(path, 'r')
		


def main():
	with open('companylist.csv', 'r') as f:
		l = f.readlines()

	parsedList = []
	for i in l:
		inQuotes = False
		s = ''
		for idx in range(len(i)):
			if i[idx] == ',' and inQuotes:
				s += ' '
			elif i[idx] == '"' and inQuotes:
				inQuotes = False
			elif i[idx] == '"' and not inQuotes:
				inQuotes = True
			else:
				s += i[idx]
			
		parsedList.append(s.replace('"','').replace('\r\n', '').split(','))
		parsedList[-1].pop()
	x = [[x[0], x[6], x[7]] for x in parsedList]
	
	d1 = {}
	d2 = {}
	for y in x:
		if y[1] in d1:
			d1[y[1]] += 1
		else:
			d1[y[1]] = 1
	
		if y[2] in d2:
			d2[y[2]] += 1
		else:
			d2[y[2]] = 1

	print d1
	print d2

	with open('sectors.txt', 'w') as f:
		for k in d1:
			if  k != 'Sector':
				f.write('%s : %d\n' %(k, d1[k]))
	with open('industries.txt', 'w') as g:
		for k in d2:
			if k != 'Indusry':
				g.write('%s : %d\n' %(k, d2[k]))		

if __name__ == '__main__':
	main()	
