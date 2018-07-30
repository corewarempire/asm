.name "TEST"
.comment "ceci est un test"

start:	ld		%5,		r5
		ld	%5,		r5
		ld	%5,		r5
		ld		%4,		r4
		zjmp		%:start

continue:		ld	%5,r4
		ld   %0,   r5
		ld   %0,   r5
		ld   %0,   r5
		ld   %0,   r5
		zjmp	%:continue

		ld	%-5,	r5
