FUNC @main:
	main.var a, b, c
	push 2
	pop a
	push 1
	pop b
_begIf_1:
	push a
	push 0
	cmpgt
	jz _elIf_1
_begIf_2:
	push b
	push 0
	cmplt
	jz _elIf_2
	push 1
	pop c
	jmp _endIf_2
_elIf_2:
	push 2
	pop c
_endIf_2:
	jmp _endIf_1
_elIf_1:
_begIf_3:
	push b
	push 0
	cmplt
	jz _elIf_3
	push 3
	pop c
	jmp _endIf_3
_elIf_3:
	push 4
	pop c
_endIf_3:
_endIf_1:
	push c
	ret ~
ENDFUNC@main

