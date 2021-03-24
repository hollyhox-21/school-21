global _ft_strdup
extern _malloc
extern _ft_strlen
extern _ft_strcpy
extern ___error

section .text
_ft_strdup:
		xor		rax, rax
		push	rdi
		call	_ft_strlen
		mov		rdi ,rax
		inc		rdi
		call	_malloc
		cmp		rax, 0
		jz		.error
		pop		rsi
		mov		rdi, rax
		call	_ft_strcpy
		ret
.error:
		ret
