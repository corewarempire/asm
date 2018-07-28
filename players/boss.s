.name "boss"
.comment "be humble"

wall:
		ld		%0,		r2
		st		r2,		-64
		st		r2,		-73
		st		r2,		-82
		st		r2,		-91
		st		r2,		-100
		st		r2,		-109
		st		r2,		-118
		st		r2,		-127
		st		r2,		-136
		st		r2,		-145
		st		r2,		-154
		st		r2,		-163
		st		r2,		-170
		zjmp	%:wall

#start:
#		sti		r1,		%:pos1,		%1
#		sti		r1,		%:pos2,		%1
#		sti		r1,		%:pos3,		%1
#		sti		r1,		%:pos4,		%1
#		sti		r1,		%:pos5,		%1

#pos1:
#		live	%0

#pos2:
#		live	%0

#pos3:
#		live	%0

#pos4:
#		live	%0

#pos5:
#		live	%0
