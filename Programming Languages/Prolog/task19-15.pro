sum2(N, N, I, R, R)  :- !.
sum2(N, J, I, R, R1) :- J2 is J + 1
                      , R2 is R1 + I ^ J - I
                      , sum2(N, J2, I, R, R2).

sum1(N, N, R, R)  :- !.
sum1(N, I, R, R1) :- sum2(N, 1, I, R3, 0)
                    , I2 is I + 1
                    , R2 is R1 + R3
                    , sum1(N, I2, R, R2).

y(N) :- N1 is N + 1, sum1(N1, 1, R, 0), write(R).