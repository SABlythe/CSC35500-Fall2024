	section 	.text
	global		_start
	extern		printRAX, printNL

_start:
	mov	rax, -123
	call	printRAX

	call 	printNL
	
	mov	rax, 1
	mov	rbx, 0
	int 	0x80
