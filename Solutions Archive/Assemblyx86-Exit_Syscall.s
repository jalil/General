#Purpose: Simple program that exits and returns a status code back to the Linux kernel
#
#
#Input: none
#
#Output: returns a status code. This can be viewed by typing "echo $?" after running the program
#
#
#Variables: 
# %eax holds the system call number
# %ebx holds the return status
.section .data

.section .text

.globl _start
_start:
movl $1, %eax #this is the linux kernel command number (syscall) for exiting a program
movl $0, %ebx #this is the status number we will return the OS. Change these around later to see what happens
int $0x80 #this wakes up the kernel to run the exit command


