.set MAGIC,    0x1BADB002
.set FLAGS,    0
.set CHECKSUM, -(MAGIC + FLAGS)
# Magic number, flags and checksum defined

.section .multiboot
# Multiboot enabled

.long MAGIC
.long FLAGS
.long CHECKSUM
# Define type to long for each data defined as above


stack_bottom:
# Stack bottom 

.skip 1024
# Maximum stack size


stack_top:
# Stack top

.section .text
.global _start
.type _start, @function


_start:
	mov $stack_top, %esp
	call __kernel_init
	cli


loop:
# Infinite loop

	hlt
	jmp loop

.size _start, . - _start
