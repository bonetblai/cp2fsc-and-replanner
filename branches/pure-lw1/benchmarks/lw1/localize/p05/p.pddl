(define (problem loc05)
    (:domain localize)
    (:constants
        p1-1 p1-2 p1-3 p1-4 p1-5
        p2-1 p2-2 p2-3 p2-4 p2-5
        p3-1 p3-2 p3-3 p3-4 p3-5
        p4-1 p4-2 p4-3 p4-4 p4-5
        p5-1 p5-2 p5-3 p5-4 p5-5 - pos
    )
    (:init
        (wall-down-of p1-1) (wall-left-of p1-1)
        (wall-up-of p2-1) (wall-down-of p2-1)
        (wall-up-of p3-1) (wall-down-of p3-1)
        (wall-up-of p4-1) (wall-down-of p4-1)
        (wall-right-of p5-1) (wall-down-of p5-1)

        (wall-right-of p1-2) (wall-left-of p1-2)
        (wall-right-of p5-2) (wall-left-of p5-2)

        (wall-left-of p1-3)
        (wall-up-of p2-3) (wall-down-of p2-3)
        (wall-up-of p3-3) (wall-down-of p3-3)
        (wall-up-of p4-3) (wall-down-of p4-3)
        (wall-right-of p5-3)

        (wall-right-of p1-4) (wall-left-of p1-4)
        (wall-right-of p5-4) (wall-left-of p5-4)

        (wall-up-of p1-5) (wall-left-of p1-5)
        (wall-up-of p2-5) (wall-down-of p2-5)
        (wall-up-of p3-5) (wall-down-of p3-5)
        (wall-up-of p4-5) (wall-down-of p4-5)
        (wall-up-of p5-5) (wall-right-of p5-5)

        (up-of p1-1 p1-2) (right-of p1-1 p2-1)
        (right-of p2-1 p3-1) (left-of p2-1 p1-1)
        (right-of p3-1 p4-1) (left-of p3-1 p2-1)
        (right-of p4-1 p5-1) (left-of p4-1 p3-1)
        (up-of p5-1 p5-2) (left-of p5-1 p4-1)
        ;(up-of p1-1 p1-2) (right-of p1-1 p2-1)
        ;(up-of p2-1 p2-2) (right-of p2-1 p3-1) (left-of p2-1 p1-1)
        ;(up-of p3-1 p3-2) (right-of p3-1 p4-1) (left-of p3-1 p2-1)
        ;(up-of p4-1 p4-2) (right-of p4-1 p5-1) (left-of p4-1 p3-1)
        ;(up-of p5-1 p5-2) (left-of p5-1 p4-1)

        (up-of p1-2 p1-3) (down-of p1-2 p1-1)
        (up-of p5-2 p5-3) (down-of p5-2 p5-1)
        ;(up-of p1-2 p1-3) (right-of p1-2 p2-2) (down-of p1-2 p1-1)
        ;(up-of p2-2 p2-3) (right-of p2-2 p3-2) (down-of p2-2 p2-1) (left-of p2-2 p1-2)
        ;(up-of p3-2 p3-3) (right-of p3-2 p4-2) (down-of p3-2 p3-1) (left-of p3-2 p2-2)
        ;(up-of p4-2 p4-3) (right-of p4-2 p5-2) (down-of p4-2 p4-1) (left-of p4-2 p3-2)
        ;(up-of p5-2 p5-3) (down-of p5-2 p5-1) (left-of p5-2 p4-2)

        (up-of p1-3 p1-4) (right-of p1-3 p2-3) (down-of p1-3 p1-2)
        (right-of p2-3 p3-3) (left-of p2-3 p1-3)
        (right-of p3-3 p4-3) (left-of p3-3 p2-3)
        (right-of p4-3 p5-3) (left-of p4-3 p3-3)
        (up-of p5-3 p5-4) (down-of p5-3 p5-2) (left-of p5-3 p4-3)
        ;(up-of p1-3 p1-4) (right-of p1-3 p2-3) (down-of p1-3 p1-2)
        ;(up-of p2-3 p2-4) (right-of p2-3 p3-3) (down-of p2-3 p2-2) (left-of p2-3 p1-3)
        ;(up-of p3-3 p3-4) (right-of p3-3 p4-3) (down-of p3-3 p3-2) (left-of p3-3 p2-3)
        ;(up-of p4-3 p4-4) (right-of p4-3 p5-3) (down-of p4-3 p4-2) (left-of p4-3 p3-3)
        ;(up-of p5-3 p5-4) (down-of p5-3 p5-2) (left-of p5-3 p4-3)

        (up-of p1-4 p1-5) (down-of p1-4 p1-3)
        (up-of p5-4 p5-5) (down-of p5-4 p5-3)
        ;(up-of p1-4 p1-5) (right-of p1-4 p2-4) (down-of p1-4 p1-3)
        ;(up-of p2-4 p2-5) (right-of p2-4 p3-4) (down-of p2-4 p2-3) (left-of p2-4 p1-4)
        ;(up-of p3-4 p3-5) (right-of p3-4 p4-4) (down-of p3-4 p3-3) (left-of p3-4 p2-4)
        ;(up-of p4-4 p4-5) (right-of p4-4 p5-4) (down-of p4-4 p4-3) (left-of p4-4 p3-4)
        ;(up-of p5-4 p5-5) (down-of p5-4 p5-3) (left-of p5-4 p4-4)

        (right-of p1-5 p2-5) (down-of p1-5 p1-4)
        (right-of p2-5 p3-5) (left-of p2-5 p1-5)
        (right-of p3-5 p4-5) (left-of p3-5 p2-5)
        (right-of p4-5 p5-5) (left-of p4-5 p3-5)
        (down-of p5-5 p5-4) (left-of p5-5 p4-5)
        ;(right-of p1-5 p2-5) (down-of p1-5 p1-4)
        ;(right-of p2-5 p3-5) (down-of p2-5 p2-4) (left-of p2-5 p1-5)
        ;(right-of p3-5 p4-5) (down-of p3-5 p3-4) (left-of p3-5 p2-5)
        ;(right-of p4-5 p5-5) (down-of p4-5 p4-4) (left-of p4-5 p3-5)
        ;(down-of p5-5 p5-4) (left-of p5-5 p4-5)

        (possible p1-1) (possible p2-1) (possible p3-1) (possible p4-1) (possible p5-1)
        (possible p1-2)                                                 (possible p5-2)
        (possible p1-3) (possible p2-3) (possible p3-3) (possible p4-3) (possible p5-3)
        (possible p1-4)                                                 (possible p5-4)
        (possible p1-5) (possible p2-5) (possible p3-5) (possible p4-5) (possible p5-5)

        (need-start)
     )
    (:goal (at p5-5))
)

