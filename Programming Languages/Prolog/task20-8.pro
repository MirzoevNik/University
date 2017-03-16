reduction([], _, []).
reduction([X | XS], N, [X1 | R]) :- X1 is X - N
                                  , reduction(XS, N, R).

reduction(X, N) :- reduction(X, N, Res), write(Res).

?- reduction([ 111, 111, 111, 2, 2, 2, 2
                 , 3, 3, 3, 2, 2, 2, 1
                 , 1, 1, 2, 3, 3, 43, 4
                 , 5, 6, 6, 6, 6, 4, 4, 4
                 , 4, 4, 4, 3, 3, 3, 2], 2).