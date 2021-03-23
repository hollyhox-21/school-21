global _ft_strcmp

section .text
_ft_strcmp:
		xor		rax, rax
		xor		rcx, rcx
		xor		rdx, rdx
.while:
		mov		al, byte[rdi + rdx]
		mov		cl, byte[rsi + rdx]
		sub		rax, rcx
		cmp		rax, 0
		jnz		.return
		jz		.incriment
.incriment:
		cmp		byte[rdi + rdx], 0
		jz		.return
		inc		rdx
		jmp		.while
.return:
		ret