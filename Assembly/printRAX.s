	section	.data
__negsign:	 db '-'
	
	section .text
	extern	printDigit
	global	printRAX
printRAX:
	push	rax
	push	rbx
	push	rcx
	push	rdx


	cmp	rax, 0
	jge	printPos

	;;  if number is negative, print - sign and negate number
	push 	rax
	
	mov	rax, 4
	mov 	rbx, 1
	mov	rcx, __negsign
	mov	rdx, 1
	int 	0x80

	pop	rax
	neg 	rax

	
printPos:	
	mov	rcx, 0		; no digits seen yet
doDigit:	
	mov	rbx, 0xa	;0xa = 10
	mov	rdx, 0x0	;make sure rdx is empty before division
	div	rbx		;divide rax by 10 ... remainder is in rdx

	mov	rsi,rax	; backup number we are working with ...
	mov	al, dl		; dl is "lowest" byte of rdx
	push	rax		; save digit to print later
	
	mov	rax,rsi	; restore number we are working with ... 

	inc	rcx     ;  add 1 to count of digits seen
	
	cmp	rax, 0
	jne	doDigit

nextDigit:	
	pop 	rax
	call 	printDigit

	dec	rcx
	cmp	rcx, 0
	jne	nextDigit


	
	pop	rdx
	pop	rcx
	pop	rbx
	pop	rax
	
	ret
