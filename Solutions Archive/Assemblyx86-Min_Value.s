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
 .long 213,23,35,56,24,23,123,32,12,1,6,3,255

.section .text

.globl _start
 
_start:
 movl $0, %edi
 movl data_items(,%edi,4), %eax
 movl %eax, %ebx

start_loop:
 cmpl $255, %eax
 je end_loop
 incl %edi
 movl data_items(,%edi,4), %eax
 cmpl %ebx, %eax
 jge start_loop
 movl %eax, %ebx
 jmp start_loop

end_loop:
 movl $1, %eax
 int $0x80
 
