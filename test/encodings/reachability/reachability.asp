reach(X, Y) :- arc(X, Y).
reach(X, Z) :- reach(X, Y), arc(Y, Z).
