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
		dpeg.insert(0, x)
		
		self.print_pegs()
	def print_pegs(self):
		print "Peg 0 %s" % self.peg0
		print "Peg 1 %s" % self.peg1 
		print "Peg 2 %s" % self.peg2
		print ""

h = Hanoi(4)
def check_spare(src,dst):
	lstPegs = [0, 1, 2]
	lsthave = [src, dst]
	for element in lstPegs:
		if element not in lsthave:
			return element

#print check_spare(1,2)
#print check_spare(0,1)
#print check_spare(0,2)

def hanoi(num, src, dst, h):
	if num == 1:
		h.move(src, dst)
		h.print_pegs()
	else:
		spare = check_spare(src, dst) # other peg besides src and dst
		hanoi(num-1,src,spare, h)
		
		hanoi(1,src,dst, h)
		
		hanoi(num - 1, spare, dst, h)
	
hanoi(4,0,2, h)
