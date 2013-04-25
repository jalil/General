program TriangularNums
implicit none
integer :: idx, upper, accumulator = 0


print *, "What is the highest triangular number you want?"
read *, upper

print *,'    Triangle No.   Accumulator'
do idx=1, upper
	accumulator = accumulator + idx
	print *,idx, accumulator
end do
end program TriangularNums
