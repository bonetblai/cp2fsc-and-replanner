(define (problem wumpus5)
    (:domain wumpus)
    (:objects p1-1 p1-2 p1-3 p1-4 p1-5 p2-1 p2-2 p2-3 p2-4 p2-5 p3-1 p3-2 p3-3 p3-4 p3-5 p4-1 p4-2 p4-3 p4-4 p4-5 p5-1 p5-2 p5-3 p5-4 p5-5 - pos)
    (:init
        (need-start)
        (at p1-1)
        (alive)
        (gold-at p5-5)
        (adj p1-1 p2-1) (adj p2-1 p1-1)
        (adj p1-2 p2-2) (adj p2-2 p1-2)
        (adj p1-3 p2-3) (adj p2-3 p1-3)
        (adj p1-4 p2-4) (adj p2-4 p1-4)
        (adj p1-5 p2-5) (adj p2-5 p1-5)
        (adj p2-1 p3-1) (adj p3-1 p2-1)
        (adj p2-2 p3-2) (adj p3-2 p2-2)
        (adj p2-3 p3-3) (adj p3-3 p2-3)
        (adj p2-4 p3-4) (adj p3-4 p2-4)
        (adj p2-5 p3-5) (adj p3-5 p2-5)
        (adj p3-1 p4-1) (adj p4-1 p3-1)
        (adj p3-2 p4-2) (adj p4-2 p3-2)
        (adj p3-3 p4-3) (adj p4-3 p3-3)
        (adj p3-4 p4-4) (adj p4-4 p3-4)
        (adj p3-5 p4-5) (adj p4-5 p3-5)
        (adj p4-1 p5-1) (adj p5-1 p4-1)
        (adj p4-2 p5-2) (adj p5-2 p4-2)
        (adj p4-3 p5-3) (adj p5-3 p4-3)
        (adj p4-4 p5-4) (adj p5-4 p4-4)
        (adj p4-5 p5-5) (adj p5-5 p4-5)
        (adj p1-1 p1-2) (adj p1-2 p1-1)
        (adj p2-1 p2-2) (adj p2-2 p2-1)
        (adj p3-1 p3-2) (adj p3-2 p3-1)
        (adj p4-1 p4-2) (adj p4-2 p4-1)
        (adj p5-1 p5-2) (adj p5-2 p5-1)
        (adj p1-2 p1-3) (adj p1-3 p1-2)
        (adj p2-2 p2-3) (adj p2-3 p2-2)
        (adj p3-2 p3-3) (adj p3-3 p3-2)
        (adj p4-2 p4-3) (adj p4-3 p4-2)
        (adj p5-2 p5-3) (adj p5-3 p5-2)
        (adj p1-3 p1-4) (adj p1-4 p1-3)
        (adj p2-3 p2-4) (adj p2-4 p2-3)
        (adj p3-3 p3-4) (adj p3-4 p3-3)
        (adj p4-3 p4-4) (adj p4-4 p4-3)
        (adj p5-3 p5-4) (adj p5-4 p5-3)
        (adj p1-4 p1-5) (adj p1-5 p1-4)
        (adj p2-4 p2-5) (adj p2-5 p2-4)
        (adj p3-4 p3-5) (adj p3-5 p3-4)
        (adj p4-4 p4-5) (adj p4-5 p4-4)
        (adj p5-4 p5-5) (adj p5-5 p5-4)
    )
    (:hidden (wumpus-at p2-3) (wumpus-at p4-3) (wumpus-at p4-5))
    (:goal (and (got-the-treasure) (alive)))
) 

