program volDeltaSphere
implicit none

real :: rad1, rad2, vol1, vol2

print *, "Give me the radius of the first sphere:"
read *, rad1

print *, "Give me the radius of the second sphere:"
read *, rad2

call spherevol(rad1, vol1)
call spherevol(rad2, vol2)

print *, 'The volumetric difference between the first and second spheres is:', abs(vol1 - vol2)

end program volDeltaSphere

subroutine spherevol(radius, vol)
implicit none

real :: pi, radius, vol

pi = 4.0 * atan(1.0)

vol = (4.0 / 3.0) * (pi * radius ** 3)

end subroutine spherevol 
