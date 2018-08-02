.name "TEST"
.comment "ceci est un test"

start:
		ld		%0,		r15
		zjmp		%:label
		zjmp		%:start
		ld		%5,		r5
		ld	%5,		r5
		ld	%5,		r5
		ld		%4,		r4

label:
