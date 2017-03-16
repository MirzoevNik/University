(defun entry (lst1 lst2)
  (labels 
    ((entry-iter (L curPos curDepth res)
      (if (null L)
        res
        (let* ((fstL (car L))
               (tailL (cdr L))
               (isFirstDepth (= curDepth 1))
               (nextPos (+ curPos 1))
               (nextDepth (+ curDepth 1))
               (newRes (append res (list (list curPos curDepth)))))
          (if (listp fstL)
            (if (equal fstL lst2)
              (if isFirstDepth 
                (entry-iter tailL nextPos curDepth newRes)
                (entry-iter tailL curPos curDepth newRes))
              (let ((newIter (entry-iter fstL curPos nextDepth res)))
                (if isFirstDepth
                  (entry-iter tailL nextPos curDepth newIter)
                  (entry-iter tailL curPos curDepth newIter))))
            (if isFirstDepth
              (entry-iter tailL nextPos curDepth res)
              (entry-iter tailL curPos curDepth res)))))))

    (entry-iter lst1 1 1 ())))

(print (entry '(() ()) '()))
(print (entry '((A ()) () B (()) ()) '()))
(print (entry '() '()))