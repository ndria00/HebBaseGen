% guess matching
match(M,W) :- manAssignsScore(M,W,S), not nonMatch(M,W).
nonMatch(M,W) :- manAssignsScore(M,W,S), not match(M,W).

% strong stability condition
matched(m,M,S)   :- match(M,W), manAssignsScore(M,W,S).
matched(w,W,S1) :- S1=S-1, match(M,W), womanAssignsScore(W,M,S), 1 < S.
matched(T,P,S1) :- S1=S-1, matched(T,P,S), 1 < S.