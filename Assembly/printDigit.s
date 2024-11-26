	section .data
__buffer:	db	0x0

	section .text
	global	printDigit
printDigit:
	push	rax
	push	rbx
	push	rcx
	push	rdx

	add	al, '0'		; convert digit to ascii equivalent
	mov	[__buffer], al
	
	mov	rax, 4		; write a string
	mov	rbx, 1		; write to stdout
	mov	rcx, __buffer
	mov	rdx, 1
	int 	0x80

	pop	rdx
	pop	rcx
	pop	rbx
	pop	rax
	
	ret
