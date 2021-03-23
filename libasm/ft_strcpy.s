global _ft_strcpy

section .text
_ft_strcpy:
		xor		rax, rax
.while:
		cmp		byte[rsi + rax], 0
		jz		.return
		mov		rdx, [rsi + rax]
		mov		[rdi + rax], rdx
		inc		rax
		jmp		.while
.return:
		mov		byte[rdi + rax], 0
		mov		rax, rdi
		ret