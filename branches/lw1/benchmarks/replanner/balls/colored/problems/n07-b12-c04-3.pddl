(define (problem n7-b12-c4)
    (:domain colored-balls)
    (:objects
        p1 p2 p3 p4 p5 p6 p7 - pos
        b1 b2 b3 b4 b5 b6 b7 b8 b9 b10 b11 b12 - ball
        c1 c2 c3 c4 - color)
    (:init
        (suc p1 p2) (suc p2 p3) (suc p3 p4) (suc p4 p5) (suc p5 p6) (suc p6 p7)
        (at p1 p1)
        (empty-arm)
        (spot p2 p3 c1)
        (spot p6 p3 c2)
        (spot p1 p1 c3)
        (spot p1 p2 c4)
        (not (ball-at-spot b1))
        (not (ball-at-spot b2))
        (not (ball-at-spot b3))
        (not (ball-at-spot b4))
        (not (ball-at-spot b5))
        (not (ball-at-spot b6))
        (not (ball-at-spot b7))
        (not (ball-at-spot b8))
        (not (ball-at-spot b9))
        (not (ball-at-spot b10))
        (not (ball-at-spot b11))
        (not (ball-at-spot b12))
        (invariant (ball-color b1 c1) (ball-color b1 c2) (ball-color b1 c3) (ball-color b1 c4))
        (invariant (ball-color b2 c1) (ball-color b2 c2) (ball-color b2 c3) (ball-color b2 c4))
        (invariant (ball-color b3 c1) (ball-color b3 c2) (ball-color b3 c3) (ball-color b3 c4))
        (invariant (ball-color b4 c1) (ball-color b4 c2) (ball-color b4 c3) (ball-color b4 c4))
        (invariant (ball-color b5 c1) (ball-color b5 c2) (ball-color b5 c3) (ball-color b5 c4))
        (invariant (ball-color b6 c1) (ball-color b6 c2) (ball-color b6 c3) (ball-color b6 c4))
        (invariant (ball-color b7 c1) (ball-color b7 c2) (ball-color b7 c3) (ball-color b7 c4))
        (invariant (ball-color b8 c1) (ball-color b8 c2) (ball-color b8 c3) (ball-color b8 c4))
        (invariant (ball-color b9 c1) (ball-color b9 c2) (ball-color b9 c3) (ball-color b9 c4))
        (invariant (ball-color b10 c1) (ball-color b10 c2) (ball-color b10 c3) (ball-color b10 c4))
        (invariant (ball-color b11 c1) (ball-color b11 c2) (ball-color b11 c3) (ball-color b11 c4))
        (invariant (ball-color b12 c1) (ball-color b12 c2) (ball-color b12 c3) (ball-color b12 c4))
        (invariant (ball-at-spot b1)
                   (ball-pos b1 p1 p1) (ball-pos b1 p1 p2) (ball-pos b1 p1 p3) (ball-pos b1 p1 p4) (ball-pos b1 p1 p5) (ball-pos b1 p1 p6) (ball-pos b1 p1 p7)
                   (ball-pos b1 p2 p1) (ball-pos b1 p2 p2) (ball-pos b1 p2 p3) (ball-pos b1 p2 p4) (ball-pos b1 p2 p5) (ball-pos b1 p2 p6) (ball-pos b1 p2 p7)
                   (ball-pos b1 p3 p1) (ball-pos b1 p3 p2) (ball-pos b1 p3 p3) (ball-pos b1 p3 p4) (ball-pos b1 p3 p5) (ball-pos b1 p3 p6) (ball-pos b1 p3 p7)
                   (ball-pos b1 p4 p1) (ball-pos b1 p4 p2) (ball-pos b1 p4 p3) (ball-pos b1 p4 p4) (ball-pos b1 p4 p5) (ball-pos b1 p4 p6) (ball-pos b1 p4 p7)
                   (ball-pos b1 p5 p1) (ball-pos b1 p5 p2) (ball-pos b1 p5 p3) (ball-pos b1 p5 p4) (ball-pos b1 p5 p5) (ball-pos b1 p5 p6) (ball-pos b1 p5 p7)
                   (ball-pos b1 p6 p1) (ball-pos b1 p6 p2) (ball-pos b1 p6 p3) (ball-pos b1 p6 p4) (ball-pos b1 p6 p5) (ball-pos b1 p6 p6) (ball-pos b1 p6 p7)
                   (ball-pos b1 p7 p1) (ball-pos b1 p7 p2) (ball-pos b1 p7 p3) (ball-pos b1 p7 p4) (ball-pos b1 p7 p5) (ball-pos b1 p7 p6) (ball-pos b1 p7 p7))
        (invariant (ball-at-spot b2)
                   (ball-pos b2 p1 p1) (ball-pos b2 p1 p2) (ball-pos b2 p1 p3) (ball-pos b2 p1 p4) (ball-pos b2 p1 p5) (ball-pos b2 p1 p6) (ball-pos b2 p1 p7)
                   (ball-pos b2 p2 p1) (ball-pos b2 p2 p2) (ball-pos b2 p2 p3) (ball-pos b2 p2 p4) (ball-pos b2 p2 p5) (ball-pos b2 p2 p6) (ball-pos b2 p2 p7)
                   (ball-pos b2 p3 p1) (ball-pos b2 p3 p2) (ball-pos b2 p3 p3) (ball-pos b2 p3 p4) (ball-pos b2 p3 p5) (ball-pos b2 p3 p6) (ball-pos b2 p3 p7)
                   (ball-pos b2 p4 p1) (ball-pos b2 p4 p2) (ball-pos b2 p4 p3) (ball-pos b2 p4 p4) (ball-pos b2 p4 p5) (ball-pos b2 p4 p6) (ball-pos b2 p4 p7)
                   (ball-pos b2 p5 p1) (ball-pos b2 p5 p2) (ball-pos b2 p5 p3) (ball-pos b2 p5 p4) (ball-pos b2 p5 p5) (ball-pos b2 p5 p6) (ball-pos b2 p5 p7)
                   (ball-pos b2 p6 p1) (ball-pos b2 p6 p2) (ball-pos b2 p6 p3) (ball-pos b2 p6 p4) (ball-pos b2 p6 p5) (ball-pos b2 p6 p6) (ball-pos b2 p6 p7)
                   (ball-pos b2 p7 p1) (ball-pos b2 p7 p2) (ball-pos b2 p7 p3) (ball-pos b2 p7 p4) (ball-pos b2 p7 p5) (ball-pos b2 p7 p6) (ball-pos b2 p7 p7))
        (invariant (ball-at-spot b3)
                   (ball-pos b3 p1 p1) (ball-pos b3 p1 p2) (ball-pos b3 p1 p3) (ball-pos b3 p1 p4) (ball-pos b3 p1 p5) (ball-pos b3 p1 p6) (ball-pos b3 p1 p7)
                   (ball-pos b3 p2 p1) (ball-pos b3 p2 p2) (ball-pos b3 p2 p3) (ball-pos b3 p2 p4) (ball-pos b3 p2 p5) (ball-pos b3 p2 p6) (ball-pos b3 p2 p7)
                   (ball-pos b3 p3 p1) (ball-pos b3 p3 p2) (ball-pos b3 p3 p3) (ball-pos b3 p3 p4) (ball-pos b3 p3 p5) (ball-pos b3 p3 p6) (ball-pos b3 p3 p7)
                   (ball-pos b3 p4 p1) (ball-pos b3 p4 p2) (ball-pos b3 p4 p3) (ball-pos b3 p4 p4) (ball-pos b3 p4 p5) (ball-pos b3 p4 p6) (ball-pos b3 p4 p7)
                   (ball-pos b3 p5 p1) (ball-pos b3 p5 p2) (ball-pos b3 p5 p3) (ball-pos b3 p5 p4) (ball-pos b3 p5 p5) (ball-pos b3 p5 p6) (ball-pos b3 p5 p7)
                   (ball-pos b3 p6 p1) (ball-pos b3 p6 p2) (ball-pos b3 p6 p3) (ball-pos b3 p6 p4) (ball-pos b3 p6 p5) (ball-pos b3 p6 p6) (ball-pos b3 p6 p7)
                   (ball-pos b3 p7 p1) (ball-pos b3 p7 p2) (ball-pos b3 p7 p3) (ball-pos b3 p7 p4) (ball-pos b3 p7 p5) (ball-pos b3 p7 p6) (ball-pos b3 p7 p7))
        (invariant (ball-at-spot b4)
                   (ball-pos b4 p1 p1) (ball-pos b4 p1 p2) (ball-pos b4 p1 p3) (ball-pos b4 p1 p4) (ball-pos b4 p1 p5) (ball-pos b4 p1 p6) (ball-pos b4 p1 p7)
                   (ball-pos b4 p2 p1) (ball-pos b4 p2 p2) (ball-pos b4 p2 p3) (ball-pos b4 p2 p4) (ball-pos b4 p2 p5) (ball-pos b4 p2 p6) (ball-pos b4 p2 p7)
                   (ball-pos b4 p3 p1) (ball-pos b4 p3 p2) (ball-pos b4 p3 p3) (ball-pos b4 p3 p4) (ball-pos b4 p3 p5) (ball-pos b4 p3 p6) (ball-pos b4 p3 p7)
                   (ball-pos b4 p4 p1) (ball-pos b4 p4 p2) (ball-pos b4 p4 p3) (ball-pos b4 p4 p4) (ball-pos b4 p4 p5) (ball-pos b4 p4 p6) (ball-pos b4 p4 p7)
                   (ball-pos b4 p5 p1) (ball-pos b4 p5 p2) (ball-pos b4 p5 p3) (ball-pos b4 p5 p4) (ball-pos b4 p5 p5) (ball-pos b4 p5 p6) (ball-pos b4 p5 p7)
                   (ball-pos b4 p6 p1) (ball-pos b4 p6 p2) (ball-pos b4 p6 p3) (ball-pos b4 p6 p4) (ball-pos b4 p6 p5) (ball-pos b4 p6 p6) (ball-pos b4 p6 p7)
                   (ball-pos b4 p7 p1) (ball-pos b4 p7 p2) (ball-pos b4 p7 p3) (ball-pos b4 p7 p4) (ball-pos b4 p7 p5) (ball-pos b4 p7 p6) (ball-pos b4 p7 p7))
        (invariant (ball-at-spot b5)
                   (ball-pos b5 p1 p1) (ball-pos b5 p1 p2) (ball-pos b5 p1 p3) (ball-pos b5 p1 p4) (ball-pos b5 p1 p5) (ball-pos b5 p1 p6) (ball-pos b5 p1 p7)
                   (ball-pos b5 p2 p1) (ball-pos b5 p2 p2) (ball-pos b5 p2 p3) (ball-pos b5 p2 p4) (ball-pos b5 p2 p5) (ball-pos b5 p2 p6) (ball-pos b5 p2 p7)
                   (ball-pos b5 p3 p1) (ball-pos b5 p3 p2) (ball-pos b5 p3 p3) (ball-pos b5 p3 p4) (ball-pos b5 p3 p5) (ball-pos b5 p3 p6) (ball-pos b5 p3 p7)
                   (ball-pos b5 p4 p1) (ball-pos b5 p4 p2) (ball-pos b5 p4 p3) (ball-pos b5 p4 p4) (ball-pos b5 p4 p5) (ball-pos b5 p4 p6) (ball-pos b5 p4 p7)
                   (ball-pos b5 p5 p1) (ball-pos b5 p5 p2) (ball-pos b5 p5 p3) (ball-pos b5 p5 p4) (ball-pos b5 p5 p5) (ball-pos b5 p5 p6) (ball-pos b5 p5 p7)
                   (ball-pos b5 p6 p1) (ball-pos b5 p6 p2) (ball-pos b5 p6 p3) (ball-pos b5 p6 p4) (ball-pos b5 p6 p5) (ball-pos b5 p6 p6) (ball-pos b5 p6 p7)
                   (ball-pos b5 p7 p1) (ball-pos b5 p7 p2) (ball-pos b5 p7 p3) (ball-pos b5 p7 p4) (ball-pos b5 p7 p5) (ball-pos b5 p7 p6) (ball-pos b5 p7 p7))
        (invariant (ball-at-spot b6)
                   (ball-pos b6 p1 p1) (ball-pos b6 p1 p2) (ball-pos b6 p1 p3) (ball-pos b6 p1 p4) (ball-pos b6 p1 p5) (ball-pos b6 p1 p6) (ball-pos b6 p1 p7)
                   (ball-pos b6 p2 p1) (ball-pos b6 p2 p2) (ball-pos b6 p2 p3) (ball-pos b6 p2 p4) (ball-pos b6 p2 p5) (ball-pos b6 p2 p6) (ball-pos b6 p2 p7)
                   (ball-pos b6 p3 p1) (ball-pos b6 p3 p2) (ball-pos b6 p3 p3) (ball-pos b6 p3 p4) (ball-pos b6 p3 p5) (ball-pos b6 p3 p6) (ball-pos b6 p3 p7)
                   (ball-pos b6 p4 p1) (ball-pos b6 p4 p2) (ball-pos b6 p4 p3) (ball-pos b6 p4 p4) (ball-pos b6 p4 p5) (ball-pos b6 p4 p6) (ball-pos b6 p4 p7)
                   (ball-pos b6 p5 p1) (ball-pos b6 p5 p2) (ball-pos b6 p5 p3) (ball-pos b6 p5 p4) (ball-pos b6 p5 p5) (ball-pos b6 p5 p6) (ball-pos b6 p5 p7)
                   (ball-pos b6 p6 p1) (ball-pos b6 p6 p2) (ball-pos b6 p6 p3) (ball-pos b6 p6 p4) (ball-pos b6 p6 p5) (ball-pos b6 p6 p6) (ball-pos b6 p6 p7)
                   (ball-pos b6 p7 p1) (ball-pos b6 p7 p2) (ball-pos b6 p7 p3) (ball-pos b6 p7 p4) (ball-pos b6 p7 p5) (ball-pos b6 p7 p6) (ball-pos b6 p7 p7))
        (invariant (ball-at-spot b7)
                   (ball-pos b7 p1 p1) (ball-pos b7 p1 p2) (ball-pos b7 p1 p3) (ball-pos b7 p1 p4) (ball-pos b7 p1 p5) (ball-pos b7 p1 p6) (ball-pos b7 p1 p7)
                   (ball-pos b7 p2 p1) (ball-pos b7 p2 p2) (ball-pos b7 p2 p3) (ball-pos b7 p2 p4) (ball-pos b7 p2 p5) (ball-pos b7 p2 p6) (ball-pos b7 p2 p7)
                   (ball-pos b7 p3 p1) (ball-pos b7 p3 p2) (ball-pos b7 p3 p3) (ball-pos b7 p3 p4) (ball-pos b7 p3 p5) (ball-pos b7 p3 p6) (ball-pos b7 p3 p7)
                   (ball-pos b7 p4 p1) (ball-pos b7 p4 p2) (ball-pos b7 p4 p3) (ball-pos b7 p4 p4) (ball-pos b7 p4 p5) (ball-pos b7 p4 p6) (ball-pos b7 p4 p7)
                   (ball-pos b7 p5 p1) (ball-pos b7 p5 p2) (ball-pos b7 p5 p3) (ball-pos b7 p5 p4) (ball-pos b7 p5 p5) (ball-pos b7 p5 p6) (ball-pos b7 p5 p7)
                   (ball-pos b7 p6 p1) (ball-pos b7 p6 p2) (ball-pos b7 p6 p3) (ball-pos b7 p6 p4) (ball-pos b7 p6 p5) (ball-pos b7 p6 p6) (ball-pos b7 p6 p7)
                   (ball-pos b7 p7 p1) (ball-pos b7 p7 p2) (ball-pos b7 p7 p3) (ball-pos b7 p7 p4) (ball-pos b7 p7 p5) (ball-pos b7 p7 p6) (ball-pos b7 p7 p7))
        (invariant (ball-at-spot b8)
                   (ball-pos b8 p1 p1) (ball-pos b8 p1 p2) (ball-pos b8 p1 p3) (ball-pos b8 p1 p4) (ball-pos b8 p1 p5) (ball-pos b8 p1 p6) (ball-pos b8 p1 p7)
                   (ball-pos b8 p2 p1) (ball-pos b8 p2 p2) (ball-pos b8 p2 p3) (ball-pos b8 p2 p4) (ball-pos b8 p2 p5) (ball-pos b8 p2 p6) (ball-pos b8 p2 p7)
                   (ball-pos b8 p3 p1) (ball-pos b8 p3 p2) (ball-pos b8 p3 p3) (ball-pos b8 p3 p4) (ball-pos b8 p3 p5) (ball-pos b8 p3 p6) (ball-pos b8 p3 p7)
                   (ball-pos b8 p4 p1) (ball-pos b8 p4 p2) (ball-pos b8 p4 p3) (ball-pos b8 p4 p4) (ball-pos b8 p4 p5) (ball-pos b8 p4 p6) (ball-pos b8 p4 p7)
                   (ball-pos b8 p5 p1) (ball-pos b8 p5 p2) (ball-pos b8 p5 p3) (ball-pos b8 p5 p4) (ball-pos b8 p5 p5) (ball-pos b8 p5 p6) (ball-pos b8 p5 p7)
                   (ball-pos b8 p6 p1) (ball-pos b8 p6 p2) (ball-pos b8 p6 p3) (ball-pos b8 p6 p4) (ball-pos b8 p6 p5) (ball-pos b8 p6 p6) (ball-pos b8 p6 p7)
                   (ball-pos b8 p7 p1) (ball-pos b8 p7 p2) (ball-pos b8 p7 p3) (ball-pos b8 p7 p4) (ball-pos b8 p7 p5) (ball-pos b8 p7 p6) (ball-pos b8 p7 p7))
        (invariant (ball-at-spot b9)
                   (ball-pos b9 p1 p1) (ball-pos b9 p1 p2) (ball-pos b9 p1 p3) (ball-pos b9 p1 p4) (ball-pos b9 p1 p5) (ball-pos b9 p1 p6) (ball-pos b9 p1 p7)
                   (ball-pos b9 p2 p1) (ball-pos b9 p2 p2) (ball-pos b9 p2 p3) (ball-pos b9 p2 p4) (ball-pos b9 p2 p5) (ball-pos b9 p2 p6) (ball-pos b9 p2 p7)
                   (ball-pos b9 p3 p1) (ball-pos b9 p3 p2) (ball-pos b9 p3 p3) (ball-pos b9 p3 p4) (ball-pos b9 p3 p5) (ball-pos b9 p3 p6) (ball-pos b9 p3 p7)
                   (ball-pos b9 p4 p1) (ball-pos b9 p4 p2) (ball-pos b9 p4 p3) (ball-pos b9 p4 p4) (ball-pos b9 p4 p5) (ball-pos b9 p4 p6) (ball-pos b9 p4 p7)
                   (ball-pos b9 p5 p1) (ball-pos b9 p5 p2) (ball-pos b9 p5 p3) (ball-pos b9 p5 p4) (ball-pos b9 p5 p5) (ball-pos b9 p5 p6) (ball-pos b9 p5 p7)
                   (ball-pos b9 p6 p1) (ball-pos b9 p6 p2) (ball-pos b9 p6 p3) (ball-pos b9 p6 p4) (ball-pos b9 p6 p5) (ball-pos b9 p6 p6) (ball-pos b9 p6 p7)
                   (ball-pos b9 p7 p1) (ball-pos b9 p7 p2) (ball-pos b9 p7 p3) (ball-pos b9 p7 p4) (ball-pos b9 p7 p5) (ball-pos b9 p7 p6) (ball-pos b9 p7 p7))
        (invariant (ball-at-spot b10)
                   (ball-pos b10 p1 p1) (ball-pos b10 p1 p2) (ball-pos b10 p1 p3) (ball-pos b10 p1 p4) (ball-pos b10 p1 p5) (ball-pos b10 p1 p6) (ball-pos b10 p1 p7)
                   (ball-pos b10 p2 p1) (ball-pos b10 p2 p2) (ball-pos b10 p2 p3) (ball-pos b10 p2 p4) (ball-pos b10 p2 p5) (ball-pos b10 p2 p6) (ball-pos b10 p2 p7)
                   (ball-pos b10 p3 p1) (ball-pos b10 p3 p2) (ball-pos b10 p3 p3) (ball-pos b10 p3 p4) (ball-pos b10 p3 p5) (ball-pos b10 p3 p6) (ball-pos b10 p3 p7)
                   (ball-pos b10 p4 p1) (ball-pos b10 p4 p2) (ball-pos b10 p4 p3) (ball-pos b10 p4 p4) (ball-pos b10 p4 p5) (ball-pos b10 p4 p6) (ball-pos b10 p4 p7)
                   (ball-pos b10 p5 p1) (ball-pos b10 p5 p2) (ball-pos b10 p5 p3) (ball-pos b10 p5 p4) (ball-pos b10 p5 p5) (ball-pos b10 p5 p6) (ball-pos b10 p5 p7)
                   (ball-pos b10 p6 p1) (ball-pos b10 p6 p2) (ball-pos b10 p6 p3) (ball-pos b10 p6 p4) (ball-pos b10 p6 p5) (ball-pos b10 p6 p6) (ball-pos b10 p6 p7)
                   (ball-pos b10 p7 p1) (ball-pos b10 p7 p2) (ball-pos b10 p7 p3) (ball-pos b10 p7 p4) (ball-pos b10 p7 p5) (ball-pos b10 p7 p6) (ball-pos b10 p7 p7))
        (invariant (ball-at-spot b11)
                   (ball-pos b11 p1 p1) (ball-pos b11 p1 p2) (ball-pos b11 p1 p3) (ball-pos b11 p1 p4) (ball-pos b11 p1 p5) (ball-pos b11 p1 p6) (ball-pos b11 p1 p7)
                   (ball-pos b11 p2 p1) (ball-pos b11 p2 p2) (ball-pos b11 p2 p3) (ball-pos b11 p2 p4) (ball-pos b11 p2 p5) (ball-pos b11 p2 p6) (ball-pos b11 p2 p7)
                   (ball-pos b11 p3 p1) (ball-pos b11 p3 p2) (ball-pos b11 p3 p3) (ball-pos b11 p3 p4) (ball-pos b11 p3 p5) (ball-pos b11 p3 p6) (ball-pos b11 p3 p7)
                   (ball-pos b11 p4 p1) (ball-pos b11 p4 p2) (ball-pos b11 p4 p3) (ball-pos b11 p4 p4) (ball-pos b11 p4 p5) (ball-pos b11 p4 p6) (ball-pos b11 p4 p7)
                   (ball-pos b11 p5 p1) (ball-pos b11 p5 p2) (ball-pos b11 p5 p3) (ball-pos b11 p5 p4) (ball-pos b11 p5 p5) (ball-pos b11 p5 p6) (ball-pos b11 p5 p7)
                   (ball-pos b11 p6 p1) (ball-pos b11 p6 p2) (ball-pos b11 p6 p3) (ball-pos b11 p6 p4) (ball-pos b11 p6 p5) (ball-pos b11 p6 p6) (ball-pos b11 p6 p7)
                   (ball-pos b11 p7 p1) (ball-pos b11 p7 p2) (ball-pos b11 p7 p3) (ball-pos b11 p7 p4) (ball-pos b11 p7 p5) (ball-pos b11 p7 p6) (ball-pos b11 p7 p7))
        (invariant (ball-at-spot b12)
                   (ball-pos b12 p1 p1) (ball-pos b12 p1 p2) (ball-pos b12 p1 p3) (ball-pos b12 p1 p4) (ball-pos b12 p1 p5) (ball-pos b12 p1 p6) (ball-pos b12 p1 p7)
                   (ball-pos b12 p2 p1) (ball-pos b12 p2 p2) (ball-pos b12 p2 p3) (ball-pos b12 p2 p4) (ball-pos b12 p2 p5) (ball-pos b12 p2 p6) (ball-pos b12 p2 p7)
                   (ball-pos b12 p3 p1) (ball-pos b12 p3 p2) (ball-pos b12 p3 p3) (ball-pos b12 p3 p4) (ball-pos b12 p3 p5) (ball-pos b12 p3 p6) (ball-pos b12 p3 p7)
                   (ball-pos b12 p4 p1) (ball-pos b12 p4 p2) (ball-pos b12 p4 p3) (ball-pos b12 p4 p4) (ball-pos b12 p4 p5) (ball-pos b12 p4 p6) (ball-pos b12 p4 p7)
                   (ball-pos b12 p5 p1) (ball-pos b12 p5 p2) (ball-pos b12 p5 p3) (ball-pos b12 p5 p4) (ball-pos b12 p5 p5) (ball-pos b12 p5 p6) (ball-pos b12 p5 p7)
                   (ball-pos b12 p6 p1) (ball-pos b12 p6 p2) (ball-pos b12 p6 p3) (ball-pos b12 p6 p4) (ball-pos b12 p6 p5) (ball-pos b12 p6 p6) (ball-pos b12 p6 p7)
                   (ball-pos b12 p7 p1) (ball-pos b12 p7 p2) (ball-pos b12 p7 p3) (ball-pos b12 p7 p4) (ball-pos b12 p7 p5) (ball-pos b12 p7 p6) (ball-pos b12 p7 p7))
    )
    (:hidden
        (ball-pos b1 p5 p2) (ball-color b1 c1)
        (ball-pos b2 p7 p4) (ball-color b2 c1)
        (ball-pos b3 p1 p6) (ball-color b3 c1)
        (ball-pos b4 p2 p4) (ball-color b4 c1)
        (ball-pos b5 p1 p4) (ball-color b5 c1)
        (ball-pos b6 p7 p1) (ball-color b6 c1)
        (ball-pos b7 p1 p5) (ball-color b7 c1)
        (ball-pos b8 p6 p6) (ball-color b8 c1)
        (ball-pos b9 p5 p5) (ball-color b9 c1)
        (ball-pos b10 p3 p1) (ball-color b10 c1)
        (ball-pos b11 p3 p1) (ball-color b11 c1)
        (ball-pos b12 p7 p1) (ball-color b12 c4)
    )
    (:goal (and (ball-at-spot b1) (ball-at-spot b2) (ball-at-spot b3) (ball-at-spot b4) (ball-at-spot b5) (ball-at-spot b6) (ball-at-spot b7) (ball-at-spot b8) (ball-at-spot b9) (ball-at-spot b10) (ball-at-spot b11) (ball-at-spot b12)))
)
