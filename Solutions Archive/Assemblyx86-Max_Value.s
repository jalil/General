#PURPOSE: This program fins the maximum number of a set of data items
#
#Variables:
# %edi contains the index of the data item being examined
# %eax contains the current data item being inspected
# %ebx contains the current highest data item
#
# The following memory locations are used:
#
# data_items - contains the item data. A 0 is used to terminate the data
#
#

 .section .data
data_items: 				#The following are the data items
 .long 3,67,34,222,45,75,54,34,44,33,22,11,66,0
 
 .section .text

 .globl _start
_start:
 movl $0, %edi				#Initializing the %edi register with a value of index = 0
 movl data_items(,%edi, 4), %eax	#Load the first byte of data
 movl %eax, %ebx			#Since the first item will be the highest thus far, it will be current 
					#highest as well
start_loop:
 cmpl $0, %eax				#Check to see if we have reached the end of the list
 je loop_exit
 incl %edi				#Load next value
 movl data_items(,%edi, 4), %eax
 cmpl %ebx, %eax			#Compare the values
 jle start_loop				#jump to loop beginning if the new one isn't bigger
 movl %eax, %ebx 			#move the value as the largest
 jmp start_loop				#jump to loop beginning

loop_exit:
 					#%ebx is the status code for the exit syscall and it contains the max number
 movl $1, %eax				#1 is the Linux exit() syscall
 int $0x80				#Interrupt
