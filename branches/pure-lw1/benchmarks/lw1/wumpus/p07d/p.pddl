(define (problem wumpus7)
    (:domain diagonal-wumpus-7x7)
    (:init
        (adj p1-1 p2-1) (adj p2-1 p1-1)
        (adj p1-2 p2-2) (adj p2-2 p1-2) 
        (adj p1-3 p2-3) (adj p2-3 p1-3) 
        (adj p1-4 p2-4) (adj p2-4 p1-4) 
        (adj p1-5 p2-5) (adj p2-5 p1-5) 
        (adj p1-6 p2-6) (adj p2-6 p1-6) 
        (adj p1-7 p2-7) (adj p2-7 p1-7) 
        (adj p2-1 p3-1) (adj p3-1 p2-1) 
        (adj p2-2 p3-2) (adj p3-2 p2-2) 
        (adj p2-3 p3-3) (adj p3-3 p2-3) 
        (adj p2-4 p3-4) (adj p3-4 p2-4) 
        (adj p2-5 p3-5) (adj p3-5 p2-5) 
        (adj p2-6 p3-6) (adj p3-6 p2-6) 
        (adj p2-7 p3-7) (adj p3-7 p2-7) 
        (adj p3-1 p4-1) (adj p4-1 p3-1) 
        (adj p3-2 p4-2) (adj p4-2 p3-2) 
        (adj p3-3 p4-3) (adj p4-3 p3-3) 
        (adj p3-4 p4-4) (adj p4-4 p3-4) 
        (adj p3-5 p4-5) (adj p4-5 p3-5) 
        (adj p3-6 p4-6) (adj p4-6 p3-6) 
        (adj p3-7 p4-7) (adj p4-7 p3-7) 
        (adj p4-1 p5-1) (adj p5-1 p4-1) 
        (adj p4-2 p5-2) (adj p5-2 p4-2) 
        (adj p4-3 p5-3) (adj p5-3 p4-3) 
        (adj p4-4 p5-4) (adj p5-4 p4-4) 
        (adj p4-5 p5-5) (adj p5-5 p4-5) 
        (adj p4-6 p5-6) (adj p5-6 p4-6) 
        (adj p4-7 p5-7) (adj p5-7 p4-7) 
        (adj p5-1 p6-1) (adj p6-1 p5-1) 
        (adj p5-2 p6-2) (adj p6-2 p5-2) 
        (adj p5-3 p6-3) (adj p6-3 p5-3) 
        (adj p5-4 p6-4) (adj p6-4 p5-4) 
        (adj p5-5 p6-5) (adj p6-5 p5-5) 
        (adj p5-6 p6-6) (adj p6-6 p5-6) 
        (adj p5-7 p6-7) (adj p6-7 p5-7) 
        (adj p6-1 p7-1) (adj p7-1 p6-1) 
        (adj p6-2 p7-2) (adj p7-2 p6-2) 
        (adj p6-3 p7-3) (adj p7-3 p6-3) 
        (adj p6-4 p7-4) (adj p7-4 p6-4) 
        (adj p6-5 p7-5) (adj p7-5 p6-5) 
        (adj p6-6 p7-6) (adj p7-6 p6-6) 
        (adj p6-7 p7-7) (adj p7-7 p6-7) 
        (adj p1-1 p1-2) (adj p1-2 p1-1) 
        (adj p2-1 p2-2) (adj p2-2 p2-1) 
        (adj p3-1 p3-2) (adj p3-2 p3-1) 
        (adj p4-1 p4-2) (adj p4-2 p4-1) 
        (adj p5-1 p5-2) (adj p5-2 p5-1) 
        (adj p6-1 p6-2) (adj p6-2 p6-1) 
        (adj p7-1 p7-2) (adj p7-2 p7-1) 
        (adj p1-2 p1-3) (adj p1-3 p1-2) 
        (adj p2-2 p2-3) (adj p2-3 p2-2) 
        (adj p3-2 p3-3) (adj p3-3 p3-2) 
        (adj p4-2 p4-3) (adj p4-3 p4-2) 
        (adj p5-2 p5-3) (adj p5-3 p5-2) 
        (adj p6-2 p6-3) (adj p6-3 p6-2) 
        (adj p7-2 p7-3) (adj p7-3 p7-2) 
        (adj p1-3 p1-4) (adj p1-4 p1-3) 
        (adj p2-3 p2-4) (adj p2-4 p2-3) 
        (adj p3-3 p3-4) (adj p3-4 p3-3) 
        (adj p4-3 p4-4) (adj p4-4 p4-3) 
        (adj p5-3 p5-4) (adj p5-4 p5-3) 
        (adj p6-3 p6-4) (adj p6-4 p6-3) 
        (adj p7-3 p7-4) (adj p7-4 p7-3) 
        (adj p1-4 p1-5) (adj p1-5 p1-4) 
        (adj p2-4 p2-5) (adj p2-5 p2-4) 
        (adj p3-4 p3-5) (adj p3-5 p3-4) 
        (adj p4-4 p4-5) (adj p4-5 p4-4) 
        (adj p5-4 p5-5) (adj p5-5 p5-4) 
        (adj p6-4 p6-5) (adj p6-5 p6-4) 
        (adj p7-4 p7-5) (adj p7-5 p7-4) 
        (adj p1-5 p1-6) (adj p1-6 p1-5) 
        (adj p2-5 p2-6) (adj p2-6 p2-5) 
        (adj p3-5 p3-6) (adj p3-6 p3-5) 
        (adj p4-5 p4-6) (adj p4-6 p4-5) 
        (adj p5-5 p5-6) (adj p5-6 p5-5) 
        (adj p6-5 p6-6) (adj p6-6 p6-5) 
        (adj p7-5 p7-6) (adj p7-6 p7-5) 
        (adj p1-6 p1-7) (adj p1-7 p1-6) 
        (adj p2-6 p2-7) (adj p2-7 p2-6) 
        (adj p3-6 p3-7) (adj p3-7 p3-6) 
        (adj p4-6 p4-7) (adj p4-7 p4-6) 
        (adj p5-6 p5-7) (adj p5-7 p5-6) 
        (adj p6-6 p6-7) (adj p6-7 p6-6) 
        (adj p7-6 p7-7) (adj p7-7 p7-6)

        (need-start)
        (at p1-1)
        (gold-at p7-7)

        (not (wumpus-at p1-1))
        (not (wumpus-at p1-2))
        (not (wumpus-at p1-3))
        (not (wumpus-at p1-4))
        (not (wumpus-at p1-5))
        (not (wumpus-at p1-6))
        (not (wumpus-at p1-7))
        (not (wumpus-at p2-1))
        (not (wumpus-at p2-2))
        ;;;;;(not (wumpus-at p2-3))
        (not (wumpus-at p2-4))
        (not (wumpus-at p2-5))
        (not (wumpus-at p2-6))
        (not (wumpus-at p2-7))
        (not (wumpus-at p3-1))
        ;;;;;(not (wumpus-at p3-2))
        (not (wumpus-at p3-3))
        ;;;;;(not (wumpus-at p3-4))
        (not (wumpus-at p3-5))
        (not (wumpus-at p3-6))
        (not (wumpus-at p3-7))
        (not (wumpus-at p4-1))
        (not (wumpus-at p4-2))
        ;;;;;(not (wumpus-at p4-3))
        (not (wumpus-at p4-4))
        ;;;;;(not (wumpus-at p4-5))
        (not (wumpus-at p4-6))
        (not (wumpus-at p4-7))
        (not (wumpus-at p5-1))
        (not (wumpus-at p5-2))
        (not (wumpus-at p5-3))
        ;;;;;(not (wumpus-at p5-4))
        (not (wumpus-at p5-5))
        ;;;;;(not (wumpus-at p5-6))
        (not (wumpus-at p5-7))
        (not (wumpus-at p6-1))
        (not (wumpus-at p6-2))
        (not (wumpus-at p6-3))
        (not (wumpus-at p6-4))
        ;;;;;(not (wumpus-at p6-5))
        (not (wumpus-at p6-6))
        ;;;;;(not (wumpus-at p6-7))
        (not (wumpus-at p7-1))
        (not (wumpus-at p7-2))
        (not (wumpus-at p7-3))
        (not (wumpus-at p7-4))
        (not (wumpus-at p7-5))
        ;;;;;(not (wumpus-at p7-6))
        (not (wumpus-at p7-7))
    )
    (:goal (got-the-treasure))
)

