(define (problem p-nballs2-capacity2)
  (:domain domain-nballs2-capacity2)
  (:init (inA) (have0) (nballs-at-A-0)
         (oneof (nballs-at-B-1) (nballs-at-B-2))
  )
  (:goal (all-balls-at-A))
)