(define (problem n5-b7)
    (:domain balls)
    (:objects
        p1 p2 p3 p4 p5 - pos
        b1 b2 b3 b4 b5 b6 b7 - ball)
    (:init
        (suc p1 p2) (suc p2 p3) (suc p3 p4) (suc p4 p5)
        (at p1 p1)
        (not (ball-in-bag b1))
        (not (ball-in-bag b2))
        (not (ball-in-bag b3))
        (not (ball-in-bag b4))
        (not (ball-in-bag b5))
        (not (ball-in-bag b6))
        (not (ball-in-bag b7))
        (invariant (ball-in-bag b1)
                   (ball-at b1 p1 p1) (ball-at b1 p1 p2) (ball-at b1 p1 p3) (ball-at b1 p1 p4) (ball-at b1 p1 p5)
                   (ball-at b1 p2 p1) (ball-at b1 p2 p2) (ball-at b1 p2 p3) (ball-at b1 p2 p4) (ball-at b1 p2 p5)
                   (ball-at b1 p3 p1) (ball-at b1 p3 p2) (ball-at b1 p3 p3) (ball-at b1 p3 p4) (ball-at b1 p3 p5)
                   (ball-at b1 p4 p1) (ball-at b1 p4 p2) (ball-at b1 p4 p3) (ball-at b1 p4 p4) (ball-at b1 p4 p5)
                   (ball-at b1 p5 p1) (ball-at b1 p5 p2) (ball-at b1 p5 p3) (ball-at b1 p5 p4) (ball-at b1 p5 p5))
        (invariant (ball-in-bag b2)
                   (ball-at b2 p1 p1) (ball-at b2 p1 p2) (ball-at b2 p1 p3) (ball-at b2 p1 p4) (ball-at b2 p1 p5)
                   (ball-at b2 p2 p1) (ball-at b2 p2 p2) (ball-at b2 p2 p3) (ball-at b2 p2 p4) (ball-at b2 p2 p5)
                   (ball-at b2 p3 p1) (ball-at b2 p3 p2) (ball-at b2 p3 p3) (ball-at b2 p3 p4) (ball-at b2 p3 p5)
                   (ball-at b2 p4 p1) (ball-at b2 p4 p2) (ball-at b2 p4 p3) (ball-at b2 p4 p4) (ball-at b2 p4 p5)
                   (ball-at b2 p5 p1) (ball-at b2 p5 p2) (ball-at b2 p5 p3) (ball-at b2 p5 p4) (ball-at b2 p5 p5))
        (invariant (ball-in-bag b3)
                   (ball-at b3 p1 p1) (ball-at b3 p1 p2) (ball-at b3 p1 p3) (ball-at b3 p1 p4) (ball-at b3 p1 p5)
                   (ball-at b3 p2 p1) (ball-at b3 p2 p2) (ball-at b3 p2 p3) (ball-at b3 p2 p4) (ball-at b3 p2 p5)
                   (ball-at b3 p3 p1) (ball-at b3 p3 p2) (ball-at b3 p3 p3) (ball-at b3 p3 p4) (ball-at b3 p3 p5)
                   (ball-at b3 p4 p1) (ball-at b3 p4 p2) (ball-at b3 p4 p3) (ball-at b3 p4 p4) (ball-at b3 p4 p5)
                   (ball-at b3 p5 p1) (ball-at b3 p5 p2) (ball-at b3 p5 p3) (ball-at b3 p5 p4) (ball-at b3 p5 p5))
        (invariant (ball-in-bag b4)
                   (ball-at b4 p1 p1) (ball-at b4 p1 p2) (ball-at b4 p1 p3) (ball-at b4 p1 p4) (ball-at b4 p1 p5)
                   (ball-at b4 p2 p1) (ball-at b4 p2 p2) (ball-at b4 p2 p3) (ball-at b4 p2 p4) (ball-at b4 p2 p5)
                   (ball-at b4 p3 p1) (ball-at b4 p3 p2) (ball-at b4 p3 p3) (ball-at b4 p3 p4) (ball-at b4 p3 p5)
                   (ball-at b4 p4 p1) (ball-at b4 p4 p2) (ball-at b4 p4 p3) (ball-at b4 p4 p4) (ball-at b4 p4 p5)
                   (ball-at b4 p5 p1) (ball-at b4 p5 p2) (ball-at b4 p5 p3) (ball-at b4 p5 p4) (ball-at b4 p5 p5))
        (invariant (ball-in-bag b5)
                   (ball-at b5 p1 p1) (ball-at b5 p1 p2) (ball-at b5 p1 p3) (ball-at b5 p1 p4) (ball-at b5 p1 p5)
                   (ball-at b5 p2 p1) (ball-at b5 p2 p2) (ball-at b5 p2 p3) (ball-at b5 p2 p4) (ball-at b5 p2 p5)
                   (ball-at b5 p3 p1) (ball-at b5 p3 p2) (ball-at b5 p3 p3) (ball-at b5 p3 p4) (ball-at b5 p3 p5)
                   (ball-at b5 p4 p1) (ball-at b5 p4 p2) (ball-at b5 p4 p3) (ball-at b5 p4 p4) (ball-at b5 p4 p5)
                   (ball-at b5 p5 p1) (ball-at b5 p5 p2) (ball-at b5 p5 p3) (ball-at b5 p5 p4) (ball-at b5 p5 p5))
        (invariant (ball-in-bag b6)
                   (ball-at b6 p1 p1) (ball-at b6 p1 p2) (ball-at b6 p1 p3) (ball-at b6 p1 p4) (ball-at b6 p1 p5)
                   (ball-at b6 p2 p1) (ball-at b6 p2 p2) (ball-at b6 p2 p3) (ball-at b6 p2 p4) (ball-at b6 p2 p5)
                   (ball-at b6 p3 p1) (ball-at b6 p3 p2) (ball-at b6 p3 p3) (ball-at b6 p3 p4) (ball-at b6 p3 p5)
                   (ball-at b6 p4 p1) (ball-at b6 p4 p2) (ball-at b6 p4 p3) (ball-at b6 p4 p4) (ball-at b6 p4 p5)
                   (ball-at b6 p5 p1) (ball-at b6 p5 p2) (ball-at b6 p5 p3) (ball-at b6 p5 p4) (ball-at b6 p5 p5))
        (invariant (ball-in-bag b7)
                   (ball-at b7 p1 p1) (ball-at b7 p1 p2) (ball-at b7 p1 p3) (ball-at b7 p1 p4) (ball-at b7 p1 p5)
                   (ball-at b7 p2 p1) (ball-at b7 p2 p2) (ball-at b7 p2 p3) (ball-at b7 p2 p4) (ball-at b7 p2 p5)
                   (ball-at b7 p3 p1) (ball-at b7 p3 p2) (ball-at b7 p3 p3) (ball-at b7 p3 p4) (ball-at b7 p3 p5)
                   (ball-at b7 p4 p1) (ball-at b7 p4 p2) (ball-at b7 p4 p3) (ball-at b7 p4 p4) (ball-at b7 p4 p5)
                   (ball-at b7 p5 p1) (ball-at b7 p5 p2) (ball-at b7 p5 p3) (ball-at b7 p5 p4) (ball-at b7 p5 p5))
    )
    (:hidden (ball-at b1 p2 p1) (ball-at b2 p5 p1) (ball-at b3 p3 p2) (ball-at b4 p3 p5) (ball-at b5 p4 p1) (ball-at b6 p3 p3) (ball-at b7 p3 p5))
    (:goal (and (ball-in-bag b1) (ball-in-bag b2) (ball-in-bag b3) (ball-in-bag b4) (ball-in-bag b5) (ball-in-bag b6) (ball-in-bag b7)))
)
