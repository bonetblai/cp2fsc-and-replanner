(define (problem wumpus-5)
(:domain wumpus)


   (:init
    (and
     (at p1-1)
     (alive)
     (adj p1-1 p2-1)
     (adj p2-1 p1-1)
     (adj p1-2 p2-2)
     (adj p2-2 p1-2)
     (adj p1-3 p2-3)
     (adj p2-3 p1-3)
     (adj p1-4 p2-4)
     (adj p2-4 p1-4)
     (adj p1-5 p2-5)
     (adj p2-5 p1-5)
     (adj p2-1 p3-1)
     (adj p3-1 p2-1)
     (adj p2-2 p3-2)
     (adj p3-2 p2-2)
     (adj p2-3 p3-3)
     (adj p3-3 p2-3)
     (adj p2-4 p3-4)
     (adj p3-4 p2-4)
     (adj p2-5 p3-5)
     (adj p3-5 p2-5)
     (adj p3-1 p4-1)
     (adj p4-1 p3-1)
     (adj p3-2 p4-2)
     (adj p4-2 p3-2)
     (adj p3-3 p4-3)
     (adj p4-3 p3-3)
     (adj p3-4 p4-4)
     (adj p4-4 p3-4)
     (adj p3-5 p4-5)
     (adj p4-5 p3-5)
     (adj p4-1 p5-1)
     (adj p5-1 p4-1)
     (adj p4-2 p5-2)
     (adj p5-2 p4-2)
     (adj p4-3 p5-3)
     (adj p5-3 p4-3)
     (adj p4-4 p5-4)
     (adj p5-4 p4-4)
     (adj p4-5 p5-5)
     (adj p5-5 p4-5)
     (adj p1-1 p1-2)
     (adj p1-2 p1-1)
     (adj p2-1 p2-2)
     (adj p2-2 p2-1)
     (adj p3-1 p3-2)
     (adj p3-2 p3-1)
     (adj p4-1 p4-2)
     (adj p4-2 p4-1)
     (adj p5-1 p5-2)
     (adj p5-2 p5-1)
     (adj p1-2 p1-3)
     (adj p1-3 p1-2)
     (adj p2-2 p2-3)
     (adj p2-3 p2-2)
     (adj p3-2 p3-3)
     (adj p3-3 p3-2)
     (adj p4-2 p4-3)
     (adj p4-3 p4-2)
     (adj p5-2 p5-3)
     (adj p5-3 p5-2)
     (adj p1-3 p1-4)
     (adj p1-4 p1-3)
     (adj p2-3 p2-4)
     (adj p2-4 p2-3)
     (adj p3-3 p3-4)
     (adj p3-4 p3-3)
     (adj p4-3 p4-4)
     (adj p4-4 p4-3)
     (adj p5-3 p5-4)
     (adj p5-4 p5-3)
     (adj p1-4 p1-5)
     (adj p1-5 p1-4)
     (adj p2-4 p2-5)
     (adj p2-5 p2-4)
     (adj p3-4 p3-5)
     (adj p3-5 p3-4)
     (adj p4-4 p4-5)
     (adj p4-5 p4-4)
     (adj p5-4 p5-5)
     (adj p5-5 p5-4)

     (gold-at p5-5)

     (safe p1-1)
     (safe p2-1)
     (safe p3-1)
     (safe p4-1)
     (safe p5-1)
     (safe p1-2)
     (safe p1-3)
     (safe p1-4)
     (safe p1-5)
     (safe p2-2)
     (safe p2-4)
     (safe p2-5)
     (oneof
       (safe p2-3)
       (safe p3-2)
     )
     (safe p3-3)
     (safe p3-5)
     (safe p4-2)
     (oneof
       (safe p3-4)
       (safe p4-3)
     )
     (safe p4-4)
     (safe p5-2)
     (safe p5-3)
     (oneof
       (safe p4-5)
       (safe p5-4)
     )
     (safe p5-5)


 ;;; Safes

(invariant (not (safe p2-3)) (not (wumpus-at p2-3)))
(invariant (not (safe p2-3)) (not (pit-at p2-3)) )
(invariant (safe p2-3) (wumpus-at p2-3) (pit-at p2-3) )

(invariant (not (safe p3-2)) (not (wumpus-at p3-2)))
(invariant (not (safe p3-2)) (not (pit-at p3-2)) )
(invariant (safe p3-2) (wumpus-at p3-2) (pit-at p3-2) )

(invariant (not (safe p3-4)) (not (wumpus-at p3-4)))
(invariant (not (safe p3-4)) (not (pit-at p3-4)) )
(invariant (safe p3-4) (wumpus-at p3-4) (pit-at p3-4) )

(invariant (not (safe p4-3)) (not (wumpus-at p4-3)))
(invariant (not (safe p4-3)) (not (pit-at p4-3)) )
(invariant (safe p4-3) (wumpus-at p4-3) (pit-at p4-3) )

(invariant (not (safe p4-5)) (not (wumpus-at p4-5)))
(invariant (not (safe p4-5)) (not (pit-at p4-5)) )
(invariant (safe p4-5) (wumpus-at p4-5) (pit-at p4-5) )

(invariant (not (safe p5-4)) (not (wumpus-at p5-4)))
(invariant (not (safe p5-4)) (not (pit-at p5-4)) )
(invariant (safe p5-4) (wumpus-at p5-4) (pit-at p5-4) )


 ;;; Wumpuses
(invariant (stench p1-3) (not (wumpus-at p2-3)))
(invariant (not (stench p1-3))  (wumpus-at p2-3))

(invariant (stench p3-1) (not (wumpus-at p3-2)))
(invariant (not (stench p3-1))  (wumpus-at p3-2))

(invariant (not (stench p2-2)) (wumpus-at p3-2) (wumpus-at p2-3))
(invariant (stench p2-2) (not (wumpus-at p3-2)))
(invariant (stench p2-2) (not (wumpus-at p2-3)))

(invariant (not (stench p2-4)) (wumpus-at p2-3)(wumpus-at p3-4) )
(invariant (stench p2-4) (not (wumpus-at p2-3)))
(invariant (stench p2-4) (not (wumpus-at p3-4)))

(invariant (not (stench p4-2)) (wumpus-at p4-3)(wumpus-at p3-2) )
(invariant (stench p4-2) (not (wumpus-at p4-3)))
(invariant (stench p4-2) (not (wumpus-at p3-2)))

(invariant (not (stench p3-3)) (wumpus-at p4-3) (wumpus-at p3-2)(wumpus-at p2-3) (wumpus-at p3-4) )
(invariant (stench p3-3) (not (wumpus-at p4-3)))
(invariant (stench p3-3) (not (wumpus-at p3-2)))
(invariant (stench p3-3) (not (wumpus-at p2-3)))
(invariant (stench p3-3) (not (wumpus-at p3-4)))

(invariant (not (stench p3-5)) (wumpus-at p3-4)(wumpus-at p4-5) )
(invariant (stench p3-5) (not (wumpus-at p3-4)))
(invariant (stench p3-5) (not (wumpus-at p4-5)))

(invariant (not (stench p5-3)) (wumpus-at p5-4)(wumpus-at p4-3) )
(invariant (stench p5-3) (not (wumpus-at p5-4)))
(invariant (stench p5-3) (not (wumpus-at p4-3)))

(invariant (not (stench p4-4)) (wumpus-at p5-4) (wumpus-at p4-3)(wumpus-at p3-4) (wumpus-at p4-5) )
(invariant (stench p4-4) (not (wumpus-at p5-4)))
(invariant (stench p4-4) (not (wumpus-at p4-3)))
(invariant (stench p4-4) (not (wumpus-at p3-4)))
(invariant (stench p4-4) (not (wumpus-at p4-5)))

(invariant (not (stench p5-5)) (wumpus-at p4-5)(wumpus-at p5-4) )
(invariant (stench p5-5) (not (wumpus-at p4-5)))
(invariant (stench p5-5) (not (wumpus-at p5-4)))


 ;;; Pits
(invariant (breeze p1-3) (not (pit-at p2-3)))
(invariant (not (breeze p1-3))  (pit-at p2-3))

(invariant (breeze p3-1) (not (pit-at p3-2)))
(invariant (not (breeze p3-1))  (pit-at p3-2))

(invariant (not (breeze p2-2)) (pit-at p3-2) (pit-at p2-3))
(invariant (breeze p2-2) (not (pit-at p3-2)))
(invariant (breeze p2-2) (not (pit-at p2-3)))

(invariant (not (breeze p2-4)) (pit-at p2-3)(pit-at p3-4) )
(invariant (breeze p2-4) (not (pit-at p2-3)))
(invariant (breeze p2-4) (not (pit-at p3-4)))

(invariant (not (breeze p4-2)) (pit-at p4-3)(pit-at p3-2) )
(invariant (breeze p4-2) (not (pit-at p4-3)))
(invariant (breeze p4-2) (not (pit-at p3-2)))

(invariant (not (breeze p3-3)) (pit-at p4-3) (pit-at p3-2)(pit-at p2-3) (pit-at p3-4) )
(invariant (breeze p3-3) (not (pit-at p4-3)))
(invariant (breeze p3-3) (not (pit-at p3-2)))
(invariant (breeze p3-3) (not (pit-at p2-3)))
(invariant (breeze p3-3) (not (pit-at p3-4)))

(invariant (not (breeze p3-5)) (pit-at p3-4)(pit-at p4-5) )
(invariant (breeze p3-5) (not (pit-at p3-4)))
(invariant (breeze p3-5) (not (pit-at p4-5)))

(invariant (not (breeze p5-3)) (pit-at p5-4)(pit-at p4-3) )
(invariant (breeze p5-3) (not (pit-at p5-4)))
(invariant (breeze p5-3) (not (pit-at p4-3)))

(invariant (not (breeze p4-4)) (pit-at p5-4) (pit-at p4-3)(pit-at p3-4) (pit-at p4-5) )
(invariant (breeze p4-4) (not (pit-at p5-4)))
(invariant (breeze p4-4) (not (pit-at p4-3)))
(invariant (breeze p4-4) (not (pit-at p3-4)))
(invariant (breeze p4-4) (not (pit-at p4-5)))

(invariant (not (breeze p5-5)) (pit-at p4-5)(pit-at p5-4) )
(invariant (breeze p5-5) (not (pit-at p4-5)))
(invariant (breeze p5-5) (not (pit-at p5-4)))

     )
    )
      (:goal (and (got-the-treasure) (alive)) )
) 
