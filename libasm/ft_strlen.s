; # **************************************************************************** #
; #                                                                              #
; #                                                         :::      ::::::::    #
; #    ft_strlen.s                                        :+:      :+:    :+:    #
; #                                                     +:+ +:+         +:+      #
; #    By: rjoella <marvin@42.fr>                     +#+  +:+       +#+         #
; #                                                 +#+#+#+#+#+   +#+            #
; #    Created: 2021/03/19 13:05:29 by rjoella           #+#    #+#              #
; #    Updated: 2021/03/19 13:06:04 by rjoella          ###   ########.fr        #
; #                                                                              #
; # **************************************************************************** #

global	_ft_strlen
section .text
_ft_strlen:
		xor		rax, rax
.while:
		cmp		byte[rdi], 0
		jz		.return
		inc		rax
		inc		rdi
		jmp		.while
.return:
		ret
