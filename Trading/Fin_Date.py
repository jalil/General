class Fin_Date(object):
	def __init__(self, s):
		self.year = 0
		self.day = 0
		self.month = 0
		self.to_date(s)

	def __str__(self):
		return "%i-%i-%i" %(self.year, self.month, self.day)
		
	def to_date(self, s):
		d = []
		for v in range(2):
			k = s.index('-')
			d.append(int(s[:k]))
			s = s[k + 1:]
		
		self.year = d[0]
		self.month = d[1]
		self.day = int(s)
		

