#Purpose: To find the minimum value in a list of values
#
#
#Variables:
# %eax will hold the current value
# %ebx will hold the minimum value so far
# %edi will hold the index value
#
#Memory locations:
#
# data_items will be used to hold the list of values
# A 255 will signify the end of the list

.section .data

data_items:
 .long 213,23,35,56,24,23,123,32,12,1,6,3,255		#Data items

.section .text

.globl _start
 
_start:
 movl $0, %edi						#Move the a literal 0 into the %edi register
 movl data_items(,%edi,4), %eax				#Use the %edi register as an index to access data_items
 movl %eax, %ebx					#Since this is the first execution, the first num will be min

start_loop:						
 cmpl $255, %eax					#If %eax == 255, then we quit execution
 je end_loop		
 incl %edi						#Increment index
 movl data_items(,%edi,4), %eax				#Retrieve the next element
 cmpl %ebx, %eax					#Compare the next element with current element
 jge start_loop						#If the next element is greater, loop
 movl %eax, %ebx					#Else, replace the max register wit next element
 jmp start_loop						#Unconditional loop


end_loop:
 movl $1, %eax						#Move syscall number into %eax
 int $0x80						#Interrupt
 
