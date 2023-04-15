number(X)   :- size(X).
number(X1) :- number(X), 1 < X, X1=X-1.
cell(X,Y)   :- number(X), number(Y), not forbidden(X,Y).

hasx(X) :- cell(X,Y).
domx(X) :- hasx(X), hasx(XX), XX < X.
minx(X) :- hasx(X), not domx(X).

hasy(Y) :- cell(X,Y), hasx(X).
domy(Y) :- hasy(Y), hasy(YY), YY < Y.
miny(Y) :- hasy(Y), not domy(Y).

conn(X,Y,XDX,YDY) :- cell(X,Y), delta(DX,DY), XDX=X+DX,YDY=Y+DY, cell(XDX,YDY).

valid(X,Y,XX,YY) :- conn(X,Y,XX,YY).
valid(XX,YY,X,Y) :- conn(X,Y,XX,YY).

other(X,Y,XX,YY) :- valid(X,Y,XX,YY), move(A,B,XX,YY), X != A.
other(X,Y,XX,YY) :- valid(X,Y,XX,YY), move(X,B,XX,YY), Y != B.
other(X,Y,XX,YY) :- valid(X,Y,XX,YY), move(X,Y,A,BB), XX != A.
other(X,Y,XX,YY) :- valid(X,Y,XX,YY), move(X,Y,XX,B), YY != B.

move(X,Y,XX,YY) :- valid(X,Y,XX,YY), not other(X,Y,XX,YY).

from(X,Y) :- move(X,Y,XX,YY).

reach(X,Y)   :- minx(X), miny(Y).
reach(XX,YY) :- move(X,Y,XX,YY), reach(X,Y).