	section	.text
	global	_start
_start:
	mov	rax, 0x1122334455667788
	mov	ax, 8
	mov	ah, 9
	mov	al, 10
	
	mov	eax, 1
	mov	ebx, 0
	int	0x80
