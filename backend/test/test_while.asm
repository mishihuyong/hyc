FUNC @main:
	main.var a, b
	push 4
	pop a
_begWhile_1:
	push a
	push 0
	cmpgt
	jz _endWhile_1
_begIf_1:
	push a
	push 2
	cmpeq
	jz _elIf_1
	push 10
	pop b
	jmp _endWhile_1
	jmp _endIf_1
_elIf_1:
_endIf_1:
	push a
	push 1
	sub
	pop a
	jmp _begWhile_1
_endWhile_1:
_begWhile_2:
	push a
	push 1
	cmpgt
	jz _endWhile_2
_begIf_2:
	push b
	push 10
	cmpeq
	jz _elIf_2
	push b
	push 10
	add
	pop b
	jmp _begWhile_2
	jmp _endIf_2
_elIf_2:
_endIf_2:
	push b
	push 1
	sub
	pop b
	push a
	push 1
	sub
	pop a
	jmp _begWhile_2
_endWhile_2:
	push b
	ret ~
ENDFUNC@main

