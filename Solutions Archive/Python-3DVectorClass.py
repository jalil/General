class ThreeDimVector:
	def __init__(self, x, y, z):
		self.x = x
		self.y = y
		self.z = z

	def __add__(self, otherVec):
		return ThreeDimVector(self.x + otherVec.x, self.y + otherVec.y, self.z + otherVec.z)

	def __sub__(self, otherVec):
		return ThreeDimVector(self.x - otherVec.x, self.y - otherVec.y, self.z - otherVec.z)
	
	def __mul__(self, otherVec): #mul operator is the cross product 
		return ThreeDimVector((self.y * otherVec.z) - (self.z * otherVec.y), (self.x * otherVec.z) - (self.z * otherVec.x), (self.x * otherVec.y) - (self.y * otherVec.x)) 
	
	def __str__(self):
		return "<" + str(self.x) + ", " + str(self.y) + ", " + str(self.z) + ">"

	def dot(self, otherVec):
		return self.x * otherVec.x + self.y * otherVec.y + self.z * otherVec.z
def main():
	print "Initialization of the  3D Vectors:"
	x1 = int(raw_input("Give me the x-coordinate of the first vector: "))
	y1 = int(raw_input("Give me the y-coordinate of the first vector: "))
	z1 = int(raw_input("Give me the z-coordinate of the first vector: "))

	x2 = int(raw_input("Give me the x-coordinate of the second vector: "))
	y2 = int(raw_input("Give me the y-coordinate of the second vector: "))
	z2 = int(raw_input("Give me the z-coordainte of the second vector: "))	

	a = ThreeDimVector(x1, y1, z1)
	b = ThreeDimVector(x2, y2, z2)
	
	print "\nThe vectors are:\n Vector A -- " + str(a) + "\n Vector B -- " + str(b)
	print "\nComputations:"
	print " " + str(a) + " + " + str(b) + " = " + str(a + b)
	print " " + str(a) + " - " + str(b) + " = " + str(a - b)
	print " " + str(a) + " X " + str(b) + " = " + str(a * b)
	print " " + str(a) + " dot " + str(b) + " = " + str(a.dot(b))
	

main()
