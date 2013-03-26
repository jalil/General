class Hanoi:
	def __init__(self, n):
		self.peg0 = range(1, n+1)
		self.peg1 = []
		self.peg2 = []
		self.pegs = [self.peg0, self.peg1, self.peg2]
	def move(self,src, dst):
		speg = self.pegs[src]
		dpeg = self.pegs[dst]
		assert len(dpeg) == 0 or speg[0] < dpeg[0]
		x = speg.pop(0)
		dpeg.insert(0,x)	
		self.print_pegs()
	def print_pegs(self):
		print "Peg 0 %s" % self.peg0
		print "Peg 1 %s" % self.peg1 
		print "Peg 2 %s" % self.peg2
		print ""
	def spare(self, src, dst):
		return 3 - src - dst
h = Hanoi(4)

def hanoi(n, h):
	stack = [(n,0,2)]
	while len(stack) > 0:
		(i,s,d) = stack.pop()
		if i == 1:
			h.move(s,d)
			#move disk
		else:
			spare = h.spare(s,d)
			#add the last to do on the stack first
			stack.append((i-1, spare,d))
			stack.append((1, s, d))
			stack.append((i-1,s,spare))

hanoi(4,h)
