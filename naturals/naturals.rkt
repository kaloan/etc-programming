#lang racket
(define zero '())
(define one (cons 'suc zero))
(define two (cons 'suc one))

zero
one
two

(define (plusOne nat)
  (cons 'suc nat)
)

(define (eq nat1 nat2)
  (cond
   ((null? nat1) (null? nat2))
   ((null? nat2) #f)
   (else (eq (cdr nat1) (cdr nat2))))
)

(format "1 = 1 ? ~S" (eq one one))
(format "2 = 1 ? ~S" (eq two one))

(define (leq nat1 nat2)
  (cond  
   ((null? nat1) #t)
   ((null? nat2) #f)
   (else (leq (cdr nat1) (cdr nat2))))
)

(format "0 <= 1 ? ~S" (leq zero one))
(format "2 <= 1 ? ~S" (leq two one))

(define (add nat1 nat2)
  (if
   (null? nat1) nat2
   (add (cdr nat1) (plusOne nat2)))
)

(format "1 + 1 = ~S" (add one one))
(format "2 + 2 = ~S" (add two two))

(define (mult nat1 nat2)
  (if
   (null? nat1) zero
   (add nat2 (mult (cdr nat1) nat2)))
)

(format "2 * (2 + 1) = ~S" (mult two (plusOne two)))
