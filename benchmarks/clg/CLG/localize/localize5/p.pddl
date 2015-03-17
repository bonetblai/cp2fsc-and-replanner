(define (problem sliding-doors-5)
(:domain sliding-doors)

   (:init
    (and
     (oneof
      (at p2-1)
      (at p3-1)
      (at p4-1)
      (at p2-3)
      (at p3-3)
      (at p4-3)
      (at p2-5)
      (at p3-5)
      (at p4-5)
      (at p1-2) 
      (at p5-2) 
      (at p1-3)
       (at p5-3)
      (at p1-4) 
      (at p5-4) 
      (at p1-5)
      (at p5-5)
      (at p5-1)
      (at p1-1) )

  )
 )
    (:goal  (at p5-5)))
