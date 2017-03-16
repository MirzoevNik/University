(print
  (let ((L '(A (B (C D (X E)) F G) H)))
    (car
      (caddr
        (cadr
          (cadr L))))))