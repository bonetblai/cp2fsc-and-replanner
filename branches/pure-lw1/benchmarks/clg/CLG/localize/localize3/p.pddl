(define (problem sliding-doors-3)
(:domain sliding-doors)

   (:init
    (and
     (oneof
      (at p2-1)
      (at p2-3)
      (at p1-2) 
      (at p3-2) 
      (at p1-3)
      (at p3-3)
      (at p3-1)
      (at p1-1) )
  )
 )
(:hidden (at p1-1) )
    (:goal  (at p3-3)))
