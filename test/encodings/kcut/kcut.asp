
%big graph, select three connected nodes

out(X) :- node(X), not in(X).
in(X) :- node(X), not out(X).

cut(X,Y) :- in(X), out(Y), edge(X,Y).

cut(Y,X) :- in(X), out(Y), edge(X,Y).

uncut(X,Y) :- edge(X,Y), not cut(X,Y).

%:~ uncut(X,Y). [1@1,X,Y]

%:- cut_size(N), #count{X,Y : cut(X,Y)} < N.


