FUNC @main:
main.var a, b, c, d

push 2
pop c

push c
push 2
mul
pop d

push c
push d
call sum
pop a

push a
push d
call sum
pop b

push c
push d
;print "c = %d, d = %d"

push a
push b
;print "a = sum(c, d) = %d, b = sum(a, d) = %d"

push 0
ret ~

ENDFUNC

FUNC @sum:
sum.arg a, b

sum.var c, d

push a
push b
add
ret ~

ENDFUNC