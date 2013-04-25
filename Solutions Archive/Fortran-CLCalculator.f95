program calculator
implicit none
real :: a,b,c
integer :: option

print *, 'Choose and option by typing in the corresponding number:'
print *, 'Addition       --> 1'
print *, 'Subtraction    --> 2'
print *, 'Multiplication --> 3'
print *, 'Division       --> 4'
print *, 'Type in the operation number you want:'
read *, option

print *, 'Give me the first value:'
read *, a
print *, 'Give me the second value:'
read *, b

if (option == 1) then
c = a + b
else if (option == 2) then
c = a - b
else if (option == 3) then
c = a * b
else if (option == 4) then
c = a / b
endif

print *, 'The result of your selected operation is:',c

end program calculator
