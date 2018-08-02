#bonojur
	.name		"TEST"
#bonjour

.comment " Proie"

start:				#46464
start2:ld %0,r15


label1:
label2:

label3:
zjmp		%:start

<<<<<<< HEAD
start:	ld		%5,		r5
		ld	%5,		r5
=======
>>>>>>> 178fb5aeef1301d0feff6bc308dd2726ac30a7ea
		zjmp		%:start
		ld	%5,		r5
		ld	%5,	r5

		ld	%5,						r5
		ld	%4,r4
		st 	r1,6

<<<<<<< HEAD
continue:
		ld   %0,   r5
		zjmp	%:continue
		ld	%-5,	r5
=======
label3:

label2:
label:
>>>>>>> 178fb5aeef1301d0feff6bc308dd2726ac30a7ea
