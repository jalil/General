import math

def coolerMaths(float1, float2):
	print 'Given the %.3f and %.2f we have some cooler computations:' %(float1, float2)
	print '    Square Root: math.sqrt(%.3f) = %.3f' %(float1, math.sqrt(float1))
	print '    Natural Log: math.log(%.2f) = %.2f' %(float2, math.log(float2))
	print '    Constants: math.pi = %.5f and math.e = %.5f' %(math.pi, math.e)
	print '    Trig: math.sin(%.3f) = %.3f and math.cos(%.2f) = %.2f' %(float1, math.sin(float1), float2, math.cos(float2))

def main():
	coolerMaths(0.357, 0.44)

if __name__ == '__main__':
	main()
