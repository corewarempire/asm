.name "boss"
.comment "be humble"

		fork	%:wall1
		st		r1,		6
		live	%0
		fork	%:wall2
		st		r1,		6
		live	%0
		fork	%:strike

wall1:
		st		r1,		6
		live	%0
		st		r16,	-100
		st		r16,	-110
		st		r16,	-120
		st		r16,	-130
		st		r16,	-140
		st		r16,	-150
		st		r16,	-160
		st		r16,	-170
		st		r16,	-180
		st		r16,	-190
		st		r16,	-200
		st		r16,	-210
		st		r16,	-220
		st		r16,	-230
		st		r16,	-240
		st		r16,	-250
		st		r16,	-260
		st		r16,	-270
		st		r16,	-280
		st		r16,	-290
		st		r16,	-300
		st		r16,	-310
		st		r16,	-320
		st		r16,	-330
		st		r16,	-340
		st		r16,	-350
		st		r16,	-360
		st		r16,	-370
		st		r16,	-380
		st		r16,	-390
		st		r16,	-400
		st		r16,	-410
		st		r16,	-420
		st		r16,	-430
		ld		%0,		r16
		zjmp	%:wall1

wall2:
		st		r1,		6
		live	%0
		st		r16,	250
		st		r16,	250
		st		r16,	250
		st		r16,	250
		st		r16,	250
		st		r16,	250
		st		r16,	250
		st		r16,	250
		st		r16,	250
		st		r16,	250
		st		r16,	250
		st		r16,	250
		st		r16,	250
		st		r16,	250
		st		r16,	250
		st		r16,	250
		st		r16,	250
		st		r16,	250
		st		r16,	250
		st		r16,	250
		st		r16,	250
		st		r16,	250
		st		r16,	250
		st		r16,	250
		st		r16,	250
		st		r16,	250
		st		r16,	250
		st		r16,	250
		st		r16,	250
		st		r16,	250
		st		r16,	250
		st		r16,	250
		st		r16,	250
		st		r16,	250
		st		r16,	250
		st		r16,	250
		ld		%0,		r16
		zjmp	%:wall2

strike:
		st		r1,		6
		live	%0
		fork	%180
		ld		%0,		r16
		zjmp	%:strike
