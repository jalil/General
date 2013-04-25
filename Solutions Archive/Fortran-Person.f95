program Person
implicit none
character :: first_name*6,initial, last_name*4
integer :: age

print *, 'Hi! What is your first name?'
read *, first_name
print *, 'Cool,',first_name,', what is your middle initial?'
read *, initial
print *, 'Alright, so what is your last name?'
read *, last_name
print *, 'Nice to meet you,', first_name, initial, '. ', last_name, '. How old are you?'
read *, age
print *, 'Very cool. Your name is ', first_name, initial, '. ' , last_name, ' who is ', age, ' years old! Goodbye!'
end program Person
