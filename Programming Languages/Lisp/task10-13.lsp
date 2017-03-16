(print
  (let ((3rd (cons 'C
                   (cons (cons 'D
                               (cons 'E ()))
                         (cons (cons 'F 
                                     (cons () 
                                           (cons (cons 'X ())
                                                 (cons 'G ())))) ())))))
    (cons 'A 
          (cons 'B
                (cons 3rd
                      (cons 'H ()))))))