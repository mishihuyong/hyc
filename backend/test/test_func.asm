;int main() {
;    int a, b, c, d

;    c = 2;
;    d = c * 2;

;    a = sum(c, d);
;    b = sum(a, d);
;    print("c = %d, d = %d", c, d);
;    print("a = sum(c, d) = %d, b = sum(a, d) = %d", a, b);

;    return b;
;}

;int sum(int m, int n) {
;    int c1, d1;
;    return a + b;
;}

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

;push c
;push d
;print "c = %d, d = %d"

;push a
;push b
;print "a = sum(c, d) = %d, b = sum(a, d) = %d"

push b
ret ~

ENDFUNC

FUNC @sum:
sum.arg m, n

sum.var c1, d1

push m
push n
add
ret ~

ENDFUNC