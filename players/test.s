.name "TEST"
.comment "ceci est un test"

start:
start2:
		ld		%0,		r15
		zjmp		%:label
		zjmp		%:start
		ld		%5,		r5
		ld	%5,		r5
		ld	%5,		r5
		ld		%4,		r4

label:
label2:
label3:
