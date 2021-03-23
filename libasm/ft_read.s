global _ft_read
extern ___error

section .text
_ft_read:
		mov		rax, 0x2000003
		syscall
		jc	.error
		ret
.error:
		mov r15, rax
		call ___error
		mov qword[rax], r15
		mov	rax, -1
		ret