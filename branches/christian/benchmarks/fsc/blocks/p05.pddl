(define (problem p05)
  (:domain blocks)
  (:objects b1 b2 b3 b4 b5 - block)
  (:init (clear b1) (ontable b5)
         (on b1 b2) (on b2 b3) (on b3 b4) (on b4 b5)
         (empty)
         (oneof (green b1) (green b2) (green b3) (green b4) (green b5))
  )
  (:goal (got-it))
)

