(defmacro repeat ((&body body) condition)
  (let ((func-name (gensym)))
    `(labels ((,func-name ()
                (let ((new-body (progn ,@body)))
                  (if ,condition
                      new-body
                      (,func-name)))))
      (,func-name))))

;; variant 14 from task 2
(defun y (N)
  (let ((i 1)
        (j 1)
        (s 0))
    (labels ((lg (x)
                (/ (log x) (log 10))))
      (repeat
        ((setf j 1)
         (repeat
           ((incf s (+ (lg i) (/ i j)))
            (incf j))
           (> j N))
         (incf i))
        (> i N))
      s)))

;; tests
(print (y 1))
(print (y 2))
(print (y 3))
(print (y 5))
(print (y 10))
(print (y 100))