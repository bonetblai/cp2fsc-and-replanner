(define (problem p-nballs5-capacity3)
  (:domain domain-nballs5-capacity3)
  (:init (inA) (have0) (nballs-at-A-0)
         (oneof (nballs-at-B-1) (nballs-at-B-2) (nballs-at-B-3) (nballs-at-B-4) (nballs-at-B-5))
  )
  (:goal (all-balls-at-A))
)
