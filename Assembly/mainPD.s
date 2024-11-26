	section 	.text
	global		_start
	extern		printNL, printDigit

_start:
	mov	al, 8
	call	printDigit

	call 	printNL
	
	mov	rax, 1
	mov	rbx, 0
	int 	0x80
