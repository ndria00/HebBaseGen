reach(X, Y) :- edge(X, Y).
reach(X, Z) :- reach(X, Y), edge(Y, Z).
notReach(X, Y):- node(X), node(Y), not reach(X, Y).