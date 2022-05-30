(define times-four
    (lambda (lis)
      (map (lambda (x) (* x 4)) lis)))

(define (get-even list)
    (if (null? list)
        '()
        (let ((x (car list)))
          ((if (even? x)
               (lambda (y) (cons x y))
               (lambda (y) y))
           (get-even (cdr list))))))


(define (remove-element elem list)
    (if (null? list)
        '()
        (let ((x (car list)))
          ((if (eq? elem x)
               (lambda (y) y)
               (lambda (y) (cons x y)))
           (remove-element elem (cdr list))))))
