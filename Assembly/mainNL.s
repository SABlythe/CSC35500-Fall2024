	section 	.text
	global		_start
	extern		printNL

_start:
	mov	rcx, 3
myloop:	
	call	printNL

	dec	rcx
	cmp 	rcx, 0
	jne	myloop
	
	mov	rax, 1
	mov	rbx, 0
	int 	0x80
