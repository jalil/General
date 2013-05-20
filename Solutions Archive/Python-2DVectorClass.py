class TwoDimVector:
	def __init__(self, x, y):
		self.x = x
		self.y = y

	def __add__(self, otherVec):
		return TwoDimVector(self.x + otherVec.x, self.y + otherVec.y)

	def __sub__(self, otherVec):
		return TwoDimVector(self.x - otherVec.x, self.y - otherVec.y)
	
	def __str__(self):
		return "<" + str(self.x) + ", " + str(self.y) + ">"

def main():
	print "Initialization of the  2D Vectors:"
	x1 = int(raw_input("Give me the x-coordinate of the first vector: "))
	y1 = int(raw_input("Give me the y-coordinate of the first vector: "))
	x2 = int(raw_input("Give me the x-coordinate of the second vector: "))
	y2 = int(raw_input("Give me the y-coordinate of the second vector: "))

	a = TwoDimVector(x1, y1)
	b = TwoDimVector(x2, y2)
	
	print "\nThe vectors are:\n Vector A -- " + str(a) + "\n Vector B -- " + str(b)
	print "\nComputations:\nVector A + Vector B = " + str(a + b) + "\nVector A - Vector B = " + str(a - b)

main()
