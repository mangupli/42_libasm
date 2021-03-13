; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strcpy.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: mspyke <marvin@42.fr>                      +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2021/03/09 11:46:52 by mspyke            #+#    #+#              ;
;    Updated: 2021/03/09 11:46:54 by mspyke           ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_strcpy

section .text
_ft_strcpy:
	push rdx		; for char c
	push rcx		; i
	cmp	rsi, 0
	jz is_null
	cmp rdi, 0
	jz is_null
	xor	rcx, rcx    ; i == 0
	jmp	copy

copy:
	mov dl, byte[rsi + rcx] ; c = src[i]
	mov byte [rdi + rcx], dl; dst[i] = c
	cmp byte [rsi + rcx], 0	; src[i] == ?
	je exit
	inc	rcx					; i++
	jmp	copy				

is_null:
	xor rax, rax
	pop	rdx
	pop rcx
	ret

exit:
	mov	rax, rdi
	pop	rdx
	pop rcx
	ret
