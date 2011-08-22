(define (problem n7-b13)
    (:domain balls)
    (:objects
        p1 p2 p3 p4 p5 p6 p7 - pos
        b1 b2 b3 b4 b5 b6 b7 b8 b9 b10 b11 b12 b13 - ball)
    (:init
        (suc p1 p2) (suc p2 p3) (suc p3 p4) (suc p4 p5) (suc p5 p6) (suc p6 p7)
        (at p1 p1)
        (not (ball-in-bag b1))
        (not (ball-in-bag b2))
        (not (ball-in-bag b3))
        (not (ball-in-bag b4))
        (not (ball-in-bag b5))
        (not (ball-in-bag b6))
        (not (ball-in-bag b7))
        (not (ball-in-bag b8))
        (not (ball-in-bag b9))
        (not (ball-in-bag b10))
        (not (ball-in-bag b11))
        (not (ball-in-bag b12))
        (not (ball-in-bag b13))
        (invariant (ball-in-bag b1)
                   (ball-at b1 p1 p1) (ball-at b1 p1 p2) (ball-at b1 p1 p3) (ball-at b1 p1 p4) (ball-at b1 p1 p5) (ball-at b1 p1 p6) (ball-at b1 p1 p7)
                   (ball-at b1 p2 p1) (ball-at b1 p2 p2) (ball-at b1 p2 p3) (ball-at b1 p2 p4) (ball-at b1 p2 p5) (ball-at b1 p2 p6) (ball-at b1 p2 p7)
                   (ball-at b1 p3 p1) (ball-at b1 p3 p2) (ball-at b1 p3 p3) (ball-at b1 p3 p4) (ball-at b1 p3 p5) (ball-at b1 p3 p6) (ball-at b1 p3 p7)
                   (ball-at b1 p4 p1) (ball-at b1 p4 p2) (ball-at b1 p4 p3) (ball-at b1 p4 p4) (ball-at b1 p4 p5) (ball-at b1 p4 p6) (ball-at b1 p4 p7)
                   (ball-at b1 p5 p1) (ball-at b1 p5 p2) (ball-at b1 p5 p3) (ball-at b1 p5 p4) (ball-at b1 p5 p5) (ball-at b1 p5 p6) (ball-at b1 p5 p7)
                   (ball-at b1 p6 p1) (ball-at b1 p6 p2) (ball-at b1 p6 p3) (ball-at b1 p6 p4) (ball-at b1 p6 p5) (ball-at b1 p6 p6) (ball-at b1 p6 p7)
                   (ball-at b1 p7 p1) (ball-at b1 p7 p2) (ball-at b1 p7 p3) (ball-at b1 p7 p4) (ball-at b1 p7 p5) (ball-at b1 p7 p6) (ball-at b1 p7 p7))
        (invariant (ball-in-bag b2)
                   (ball-at b2 p1 p1) (ball-at b2 p1 p2) (ball-at b2 p1 p3) (ball-at b2 p1 p4) (ball-at b2 p1 p5) (ball-at b2 p1 p6) (ball-at b2 p1 p7)
                   (ball-at b2 p2 p1) (ball-at b2 p2 p2) (ball-at b2 p2 p3) (ball-at b2 p2 p4) (ball-at b2 p2 p5) (ball-at b2 p2 p6) (ball-at b2 p2 p7)
                   (ball-at b2 p3 p1) (ball-at b2 p3 p2) (ball-at b2 p3 p3) (ball-at b2 p3 p4) (ball-at b2 p3 p5) (ball-at b2 p3 p6) (ball-at b2 p3 p7)
                   (ball-at b2 p4 p1) (ball-at b2 p4 p2) (ball-at b2 p4 p3) (ball-at b2 p4 p4) (ball-at b2 p4 p5) (ball-at b2 p4 p6) (ball-at b2 p4 p7)
                   (ball-at b2 p5 p1) (ball-at b2 p5 p2) (ball-at b2 p5 p3) (ball-at b2 p5 p4) (ball-at b2 p5 p5) (ball-at b2 p5 p6) (ball-at b2 p5 p7)
                   (ball-at b2 p6 p1) (ball-at b2 p6 p2) (ball-at b2 p6 p3) (ball-at b2 p6 p4) (ball-at b2 p6 p5) (ball-at b2 p6 p6) (ball-at b2 p6 p7)
                   (ball-at b2 p7 p1) (ball-at b2 p7 p2) (ball-at b2 p7 p3) (ball-at b2 p7 p4) (ball-at b2 p7 p5) (ball-at b2 p7 p6) (ball-at b2 p7 p7))
        (invariant (ball-in-bag b3)
                   (ball-at b3 p1 p1) (ball-at b3 p1 p2) (ball-at b3 p1 p3) (ball-at b3 p1 p4) (ball-at b3 p1 p5) (ball-at b3 p1 p6) (ball-at b3 p1 p7)
                   (ball-at b3 p2 p1) (ball-at b3 p2 p2) (ball-at b3 p2 p3) (ball-at b3 p2 p4) (ball-at b3 p2 p5) (ball-at b3 p2 p6) (ball-at b3 p2 p7)
                   (ball-at b3 p3 p1) (ball-at b3 p3 p2) (ball-at b3 p3 p3) (ball-at b3 p3 p4) (ball-at b3 p3 p5) (ball-at b3 p3 p6) (ball-at b3 p3 p7)
                   (ball-at b3 p4 p1) (ball-at b3 p4 p2) (ball-at b3 p4 p3) (ball-at b3 p4 p4) (ball-at b3 p4 p5) (ball-at b3 p4 p6) (ball-at b3 p4 p7)
                   (ball-at b3 p5 p1) (ball-at b3 p5 p2) (ball-at b3 p5 p3) (ball-at b3 p5 p4) (ball-at b3 p5 p5) (ball-at b3 p5 p6) (ball-at b3 p5 p7)
                   (ball-at b3 p6 p1) (ball-at b3 p6 p2) (ball-at b3 p6 p3) (ball-at b3 p6 p4) (ball-at b3 p6 p5) (ball-at b3 p6 p6) (ball-at b3 p6 p7)
                   (ball-at b3 p7 p1) (ball-at b3 p7 p2) (ball-at b3 p7 p3) (ball-at b3 p7 p4) (ball-at b3 p7 p5) (ball-at b3 p7 p6) (ball-at b3 p7 p7))
        (invariant (ball-in-bag b4)
                   (ball-at b4 p1 p1) (ball-at b4 p1 p2) (ball-at b4 p1 p3) (ball-at b4 p1 p4) (ball-at b4 p1 p5) (ball-at b4 p1 p6) (ball-at b4 p1 p7)
                   (ball-at b4 p2 p1) (ball-at b4 p2 p2) (ball-at b4 p2 p3) (ball-at b4 p2 p4) (ball-at b4 p2 p5) (ball-at b4 p2 p6) (ball-at b4 p2 p7)
                   (ball-at b4 p3 p1) (ball-at b4 p3 p2) (ball-at b4 p3 p3) (ball-at b4 p3 p4) (ball-at b4 p3 p5) (ball-at b4 p3 p6) (ball-at b4 p3 p7)
                   (ball-at b4 p4 p1) (ball-at b4 p4 p2) (ball-at b4 p4 p3) (ball-at b4 p4 p4) (ball-at b4 p4 p5) (ball-at b4 p4 p6) (ball-at b4 p4 p7)
                   (ball-at b4 p5 p1) (ball-at b4 p5 p2) (ball-at b4 p5 p3) (ball-at b4 p5 p4) (ball-at b4 p5 p5) (ball-at b4 p5 p6) (ball-at b4 p5 p7)
                   (ball-at b4 p6 p1) (ball-at b4 p6 p2) (ball-at b4 p6 p3) (ball-at b4 p6 p4) (ball-at b4 p6 p5) (ball-at b4 p6 p6) (ball-at b4 p6 p7)
                   (ball-at b4 p7 p1) (ball-at b4 p7 p2) (ball-at b4 p7 p3) (ball-at b4 p7 p4) (ball-at b4 p7 p5) (ball-at b4 p7 p6) (ball-at b4 p7 p7))
        (invariant (ball-in-bag b5)
                   (ball-at b5 p1 p1) (ball-at b5 p1 p2) (ball-at b5 p1 p3) (ball-at b5 p1 p4) (ball-at b5 p1 p5) (ball-at b5 p1 p6) (ball-at b5 p1 p7)
                   (ball-at b5 p2 p1) (ball-at b5 p2 p2) (ball-at b5 p2 p3) (ball-at b5 p2 p4) (ball-at b5 p2 p5) (ball-at b5 p2 p6) (ball-at b5 p2 p7)
                   (ball-at b5 p3 p1) (ball-at b5 p3 p2) (ball-at b5 p3 p3) (ball-at b5 p3 p4) (ball-at b5 p3 p5) (ball-at b5 p3 p6) (ball-at b5 p3 p7)
                   (ball-at b5 p4 p1) (ball-at b5 p4 p2) (ball-at b5 p4 p3) (ball-at b5 p4 p4) (ball-at b5 p4 p5) (ball-at b5 p4 p6) (ball-at b5 p4 p7)
                   (ball-at b5 p5 p1) (ball-at b5 p5 p2) (ball-at b5 p5 p3) (ball-at b5 p5 p4) (ball-at b5 p5 p5) (ball-at b5 p5 p6) (ball-at b5 p5 p7)
                   (ball-at b5 p6 p1) (ball-at b5 p6 p2) (ball-at b5 p6 p3) (ball-at b5 p6 p4) (ball-at b5 p6 p5) (ball-at b5 p6 p6) (ball-at b5 p6 p7)
                   (ball-at b5 p7 p1) (ball-at b5 p7 p2) (ball-at b5 p7 p3) (ball-at b5 p7 p4) (ball-at b5 p7 p5) (ball-at b5 p7 p6) (ball-at b5 p7 p7))
        (invariant (ball-in-bag b6)
                   (ball-at b6 p1 p1) (ball-at b6 p1 p2) (ball-at b6 p1 p3) (ball-at b6 p1 p4) (ball-at b6 p1 p5) (ball-at b6 p1 p6) (ball-at b6 p1 p7)
                   (ball-at b6 p2 p1) (ball-at b6 p2 p2) (ball-at b6 p2 p3) (ball-at b6 p2 p4) (ball-at b6 p2 p5) (ball-at b6 p2 p6) (ball-at b6 p2 p7)
                   (ball-at b6 p3 p1) (ball-at b6 p3 p2) (ball-at b6 p3 p3) (ball-at b6 p3 p4) (ball-at b6 p3 p5) (ball-at b6 p3 p6) (ball-at b6 p3 p7)
                   (ball-at b6 p4 p1) (ball-at b6 p4 p2) (ball-at b6 p4 p3) (ball-at b6 p4 p4) (ball-at b6 p4 p5) (ball-at b6 p4 p6) (ball-at b6 p4 p7)
                   (ball-at b6 p5 p1) (ball-at b6 p5 p2) (ball-at b6 p5 p3) (ball-at b6 p5 p4) (ball-at b6 p5 p5) (ball-at b6 p5 p6) (ball-at b6 p5 p7)
                   (ball-at b6 p6 p1) (ball-at b6 p6 p2) (ball-at b6 p6 p3) (ball-at b6 p6 p4) (ball-at b6 p6 p5) (ball-at b6 p6 p6) (ball-at b6 p6 p7)
                   (ball-at b6 p7 p1) (ball-at b6 p7 p2) (ball-at b6 p7 p3) (ball-at b6 p7 p4) (ball-at b6 p7 p5) (ball-at b6 p7 p6) (ball-at b6 p7 p7))
        (invariant (ball-in-bag b7)
                   (ball-at b7 p1 p1) (ball-at b7 p1 p2) (ball-at b7 p1 p3) (ball-at b7 p1 p4) (ball-at b7 p1 p5) (ball-at b7 p1 p6) (ball-at b7 p1 p7)
                   (ball-at b7 p2 p1) (ball-at b7 p2 p2) (ball-at b7 p2 p3) (ball-at b7 p2 p4) (ball-at b7 p2 p5) (ball-at b7 p2 p6) (ball-at b7 p2 p7)
                   (ball-at b7 p3 p1) (ball-at b7 p3 p2) (ball-at b7 p3 p3) (ball-at b7 p3 p4) (ball-at b7 p3 p5) (ball-at b7 p3 p6) (ball-at b7 p3 p7)
                   (ball-at b7 p4 p1) (ball-at b7 p4 p2) (ball-at b7 p4 p3) (ball-at b7 p4 p4) (ball-at b7 p4 p5) (ball-at b7 p4 p6) (ball-at b7 p4 p7)
                   (ball-at b7 p5 p1) (ball-at b7 p5 p2) (ball-at b7 p5 p3) (ball-at b7 p5 p4) (ball-at b7 p5 p5) (ball-at b7 p5 p6) (ball-at b7 p5 p7)
                   (ball-at b7 p6 p1) (ball-at b7 p6 p2) (ball-at b7 p6 p3) (ball-at b7 p6 p4) (ball-at b7 p6 p5) (ball-at b7 p6 p6) (ball-at b7 p6 p7)
                   (ball-at b7 p7 p1) (ball-at b7 p7 p2) (ball-at b7 p7 p3) (ball-at b7 p7 p4) (ball-at b7 p7 p5) (ball-at b7 p7 p6) (ball-at b7 p7 p7))
        (invariant (ball-in-bag b8)
                   (ball-at b8 p1 p1) (ball-at b8 p1 p2) (ball-at b8 p1 p3) (ball-at b8 p1 p4) (ball-at b8 p1 p5) (ball-at b8 p1 p6) (ball-at b8 p1 p7)
                   (ball-at b8 p2 p1) (ball-at b8 p2 p2) (ball-at b8 p2 p3) (ball-at b8 p2 p4) (ball-at b8 p2 p5) (ball-at b8 p2 p6) (ball-at b8 p2 p7)
                   (ball-at b8 p3 p1) (ball-at b8 p3 p2) (ball-at b8 p3 p3) (ball-at b8 p3 p4) (ball-at b8 p3 p5) (ball-at b8 p3 p6) (ball-at b8 p3 p7)
                   (ball-at b8 p4 p1) (ball-at b8 p4 p2) (ball-at b8 p4 p3) (ball-at b8 p4 p4) (ball-at b8 p4 p5) (ball-at b8 p4 p6) (ball-at b8 p4 p7)
                   (ball-at b8 p5 p1) (ball-at b8 p5 p2) (ball-at b8 p5 p3) (ball-at b8 p5 p4) (ball-at b8 p5 p5) (ball-at b8 p5 p6) (ball-at b8 p5 p7)
                   (ball-at b8 p6 p1) (ball-at b8 p6 p2) (ball-at b8 p6 p3) (ball-at b8 p6 p4) (ball-at b8 p6 p5) (ball-at b8 p6 p6) (ball-at b8 p6 p7)
                   (ball-at b8 p7 p1) (ball-at b8 p7 p2) (ball-at b8 p7 p3) (ball-at b8 p7 p4) (ball-at b8 p7 p5) (ball-at b8 p7 p6) (ball-at b8 p7 p7))
        (invariant (ball-in-bag b9)
                   (ball-at b9 p1 p1) (ball-at b9 p1 p2) (ball-at b9 p1 p3) (ball-at b9 p1 p4) (ball-at b9 p1 p5) (ball-at b9 p1 p6) (ball-at b9 p1 p7)
                   (ball-at b9 p2 p1) (ball-at b9 p2 p2) (ball-at b9 p2 p3) (ball-at b9 p2 p4) (ball-at b9 p2 p5) (ball-at b9 p2 p6) (ball-at b9 p2 p7)
                   (ball-at b9 p3 p1) (ball-at b9 p3 p2) (ball-at b9 p3 p3) (ball-at b9 p3 p4) (ball-at b9 p3 p5) (ball-at b9 p3 p6) (ball-at b9 p3 p7)
                   (ball-at b9 p4 p1) (ball-at b9 p4 p2) (ball-at b9 p4 p3) (ball-at b9 p4 p4) (ball-at b9 p4 p5) (ball-at b9 p4 p6) (ball-at b9 p4 p7)
                   (ball-at b9 p5 p1) (ball-at b9 p5 p2) (ball-at b9 p5 p3) (ball-at b9 p5 p4) (ball-at b9 p5 p5) (ball-at b9 p5 p6) (ball-at b9 p5 p7)
                   (ball-at b9 p6 p1) (ball-at b9 p6 p2) (ball-at b9 p6 p3) (ball-at b9 p6 p4) (ball-at b9 p6 p5) (ball-at b9 p6 p6) (ball-at b9 p6 p7)
                   (ball-at b9 p7 p1) (ball-at b9 p7 p2) (ball-at b9 p7 p3) (ball-at b9 p7 p4) (ball-at b9 p7 p5) (ball-at b9 p7 p6) (ball-at b9 p7 p7))
        (invariant (ball-in-bag b10)
                   (ball-at b10 p1 p1) (ball-at b10 p1 p2) (ball-at b10 p1 p3) (ball-at b10 p1 p4) (ball-at b10 p1 p5) (ball-at b10 p1 p6) (ball-at b10 p1 p7)
                   (ball-at b10 p2 p1) (ball-at b10 p2 p2) (ball-at b10 p2 p3) (ball-at b10 p2 p4) (ball-at b10 p2 p5) (ball-at b10 p2 p6) (ball-at b10 p2 p7)
                   (ball-at b10 p3 p1) (ball-at b10 p3 p2) (ball-at b10 p3 p3) (ball-at b10 p3 p4) (ball-at b10 p3 p5) (ball-at b10 p3 p6) (ball-at b10 p3 p7)
                   (ball-at b10 p4 p1) (ball-at b10 p4 p2) (ball-at b10 p4 p3) (ball-at b10 p4 p4) (ball-at b10 p4 p5) (ball-at b10 p4 p6) (ball-at b10 p4 p7)
                   (ball-at b10 p5 p1) (ball-at b10 p5 p2) (ball-at b10 p5 p3) (ball-at b10 p5 p4) (ball-at b10 p5 p5) (ball-at b10 p5 p6) (ball-at b10 p5 p7)
                   (ball-at b10 p6 p1) (ball-at b10 p6 p2) (ball-at b10 p6 p3) (ball-at b10 p6 p4) (ball-at b10 p6 p5) (ball-at b10 p6 p6) (ball-at b10 p6 p7)
                   (ball-at b10 p7 p1) (ball-at b10 p7 p2) (ball-at b10 p7 p3) (ball-at b10 p7 p4) (ball-at b10 p7 p5) (ball-at b10 p7 p6) (ball-at b10 p7 p7))
        (invariant (ball-in-bag b11)
                   (ball-at b11 p1 p1) (ball-at b11 p1 p2) (ball-at b11 p1 p3) (ball-at b11 p1 p4) (ball-at b11 p1 p5) (ball-at b11 p1 p6) (ball-at b11 p1 p7)
                   (ball-at b11 p2 p1) (ball-at b11 p2 p2) (ball-at b11 p2 p3) (ball-at b11 p2 p4) (ball-at b11 p2 p5) (ball-at b11 p2 p6) (ball-at b11 p2 p7)
                   (ball-at b11 p3 p1) (ball-at b11 p3 p2) (ball-at b11 p3 p3) (ball-at b11 p3 p4) (ball-at b11 p3 p5) (ball-at b11 p3 p6) (ball-at b11 p3 p7)
                   (ball-at b11 p4 p1) (ball-at b11 p4 p2) (ball-at b11 p4 p3) (ball-at b11 p4 p4) (ball-at b11 p4 p5) (ball-at b11 p4 p6) (ball-at b11 p4 p7)
                   (ball-at b11 p5 p1) (ball-at b11 p5 p2) (ball-at b11 p5 p3) (ball-at b11 p5 p4) (ball-at b11 p5 p5) (ball-at b11 p5 p6) (ball-at b11 p5 p7)
                   (ball-at b11 p6 p1) (ball-at b11 p6 p2) (ball-at b11 p6 p3) (ball-at b11 p6 p4) (ball-at b11 p6 p5) (ball-at b11 p6 p6) (ball-at b11 p6 p7)
                   (ball-at b11 p7 p1) (ball-at b11 p7 p2) (ball-at b11 p7 p3) (ball-at b11 p7 p4) (ball-at b11 p7 p5) (ball-at b11 p7 p6) (ball-at b11 p7 p7))
        (invariant (ball-in-bag b12)
                   (ball-at b12 p1 p1) (ball-at b12 p1 p2) (ball-at b12 p1 p3) (ball-at b12 p1 p4) (ball-at b12 p1 p5) (ball-at b12 p1 p6) (ball-at b12 p1 p7)
                   (ball-at b12 p2 p1) (ball-at b12 p2 p2) (ball-at b12 p2 p3) (ball-at b12 p2 p4) (ball-at b12 p2 p5) (ball-at b12 p2 p6) (ball-at b12 p2 p7)
                   (ball-at b12 p3 p1) (ball-at b12 p3 p2) (ball-at b12 p3 p3) (ball-at b12 p3 p4) (ball-at b12 p3 p5) (ball-at b12 p3 p6) (ball-at b12 p3 p7)
                   (ball-at b12 p4 p1) (ball-at b12 p4 p2) (ball-at b12 p4 p3) (ball-at b12 p4 p4) (ball-at b12 p4 p5) (ball-at b12 p4 p6) (ball-at b12 p4 p7)
                   (ball-at b12 p5 p1) (ball-at b12 p5 p2) (ball-at b12 p5 p3) (ball-at b12 p5 p4) (ball-at b12 p5 p5) (ball-at b12 p5 p6) (ball-at b12 p5 p7)
                   (ball-at b12 p6 p1) (ball-at b12 p6 p2) (ball-at b12 p6 p3) (ball-at b12 p6 p4) (ball-at b12 p6 p5) (ball-at b12 p6 p6) (ball-at b12 p6 p7)
                   (ball-at b12 p7 p1) (ball-at b12 p7 p2) (ball-at b12 p7 p3) (ball-at b12 p7 p4) (ball-at b12 p7 p5) (ball-at b12 p7 p6) (ball-at b12 p7 p7))
        (invariant (ball-in-bag b13)
                   (ball-at b13 p1 p1) (ball-at b13 p1 p2) (ball-at b13 p1 p3) (ball-at b13 p1 p4) (ball-at b13 p1 p5) (ball-at b13 p1 p6) (ball-at b13 p1 p7)
                   (ball-at b13 p2 p1) (ball-at b13 p2 p2) (ball-at b13 p2 p3) (ball-at b13 p2 p4) (ball-at b13 p2 p5) (ball-at b13 p2 p6) (ball-at b13 p2 p7)
                   (ball-at b13 p3 p1) (ball-at b13 p3 p2) (ball-at b13 p3 p3) (ball-at b13 p3 p4) (ball-at b13 p3 p5) (ball-at b13 p3 p6) (ball-at b13 p3 p7)
                   (ball-at b13 p4 p1) (ball-at b13 p4 p2) (ball-at b13 p4 p3) (ball-at b13 p4 p4) (ball-at b13 p4 p5) (ball-at b13 p4 p6) (ball-at b13 p4 p7)
                   (ball-at b13 p5 p1) (ball-at b13 p5 p2) (ball-at b13 p5 p3) (ball-at b13 p5 p4) (ball-at b13 p5 p5) (ball-at b13 p5 p6) (ball-at b13 p5 p7)
                   (ball-at b13 p6 p1) (ball-at b13 p6 p2) (ball-at b13 p6 p3) (ball-at b13 p6 p4) (ball-at b13 p6 p5) (ball-at b13 p6 p6) (ball-at b13 p6 p7)
                   (ball-at b13 p7 p1) (ball-at b13 p7 p2) (ball-at b13 p7 p3) (ball-at b13 p7 p4) (ball-at b13 p7 p5) (ball-at b13 p7 p6) (ball-at b13 p7 p7))
    )
    (:hidden (ball-at b1 p6 p1) (ball-at b2 p3 p1) (ball-at b3 p1 p5) (ball-at b4 p5 p2) (ball-at b5 p7 p3) (ball-at b6 p6 p6) (ball-at b7 p1 p3) (ball-at b8 p5 p2) (ball-at b9 p7 p1) (ball-at b10 p1 p3) (ball-at b11 p6 p1) (ball-at b12 p7 p2) (ball-at b13 p3 p6))
    (:goal (and (ball-in-bag b1) (ball-in-bag b2) (ball-in-bag b3) (ball-in-bag b4) (ball-in-bag b5) (ball-in-bag b6) (ball-in-bag b7) (ball-in-bag b8) (ball-in-bag b9) (ball-in-bag b10) (ball-in-bag b11) (ball-in-bag b12) (ball-in-bag b13)))
)
