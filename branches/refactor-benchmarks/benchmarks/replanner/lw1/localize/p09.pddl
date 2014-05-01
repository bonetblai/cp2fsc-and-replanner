(define (problem sd-9)
    (:domain sliding-doors)
    (:objects
        p1-1 p1-2 p1-3 p1-4 p1-5 p1-6 p1-7 p1-8 p1-9
        p2-1 p2-2 p2-3 p2-4 p2-5 p2-6 p2-7 p2-8 p2-9
        p3-1 p3-2 p3-3 p3-4 p3-5 p3-6 p3-7 p3-8 p3-9
        p4-1 p4-2 p4-3 p4-4 p4-5 p4-6 p4-7 p4-8 p4-9
        p5-1 p5-2 p5-3 p5-4 p5-5 p5-6 p5-7 p5-8 p5-9
        p6-1 p6-2 p6-3 p6-4 p6-5 p6-6 p6-7 p6-8 p6-9
        p7-1 p7-2 p7-3 p7-4 p7-5 p7-6 p7-7 p7-8 p7-9
        p8-1 p8-2 p8-3 p8-4 p8-5 p8-6 p8-7 p8-8 p8-9
        p9-1 p9-2 p9-3 p9-4 p9-5 p9-6 p9-7 p9-8 p9-9 - pos
    )
    (:init
        (wall-down-of p1-1) (wall-left-of p1-1)
        (wall-up-of p2-1) (wall-down-of p2-1)
        (wall-up-of p3-1) (wall-down-of p3-1)
        (wall-up-of p4-1) (wall-down-of p4-1)
        (wall-up-of p5-1) (wall-down-of p5-1)
        (wall-up-of p6-1) (wall-down-of p6-1)
        (wall-up-of p7-1) (wall-down-of p7-1)
        (wall-up-of p8-1) (wall-down-of p8-1)
        (wall-right-of p9-1) (wall-down-of p9-1)

        (wall-right-of p1-2) (wall-left-of p1-2)
        (wall-right-of p9-2) (wall-left-of p9-2)

        (wall-left-of p1-3)
        (wall-up-of p2-3) (wall-down-of p2-3)
        (wall-up-of p3-3) (wall-down-of p3-3)
        (wall-up-of p4-3) (wall-down-of p4-3)
        (wall-up-of p5-3) (wall-down-of p5-3)
        (wall-up-of p6-3) (wall-down-of p6-3)
        (wall-up-of p7-3) (wall-down-of p7-3)
        (wall-up-of p8-3) (wall-down-of p8-3)
        (wall-right-of p9-3)

        (wall-right-of p1-4) (wall-left-of p1-4)
        (wall-right-of p9-4) (wall-left-of p9-4)

        (wall-left-of p1-5)
        (wall-up-of p2-5) (wall-down-of p2-5)
        (wall-up-of p3-5) (wall-down-of p3-5)
        (wall-up-of p4-5) (wall-down-of p4-5)
        (wall-up-of p5-5) (wall-down-of p5-5)
        (wall-up-of p6-5) (wall-down-of p6-5)
        (wall-up-of p7-5) (wall-down-of p8-5)
        (wall-up-of p8-5) (wall-down-of p8-5)
        (wall-right-of p9-5)

        (wall-right-of p1-6) (wall-left-of p1-6)
        (wall-right-of p9-6) (wall-left-of p9-6)

        (wall-left-of p1-7)
        (wall-up-of p2-7) (wall-down-of p2-7)
        (wall-up-of p3-7) (wall-down-of p3-7)
        (wall-up-of p4-7) (wall-down-of p4-7)
        (wall-up-of p5-7) (wall-down-of p5-7)
        (wall-up-of p6-7) (wall-down-of p6-7)
        (wall-up-of p7-7) (wall-down-of p8-7)
        (wall-up-of p8-7) (wall-down-of p8-7)
        (wall-right-of p9-7)

        (wall-right-of p1-8) (wall-left-of p1-8)
        (wall-right-of p9-8) (wall-left-of p9-8)

        (wall-up-of p1-9) (wall-left-of p1-9)
        (wall-up-of p2-9) (wall-down-of p2-9)
        (wall-up-of p3-9) (wall-down-of p3-9)
        (wall-up-of p4-9) (wall-down-of p4-9)
        (wall-up-of p5-9) (wall-down-of p5-9)
        (wall-up-of p6-9) (wall-down-of p6-9)
        (wall-up-of p7-9) (wall-down-of p7-9)
        (wall-up-of p8-9) (wall-down-of p8-9)
        (wall-up-of p9-9) (wall-right-of p9-9)

        (up-of p1-1 p1-2) (right-of p1-1 p2-1)
        (right-of p2-1 p3-1) (left-of p2-1 p1-1)
        (right-of p3-1 p4-1) (left-of p3-1 p2-1)
        (right-of p4-1 p5-1) (left-of p4-1 p3-1)
        (right-of p5-1 p6-1) (left-of p5-1 p4-1)
        (right-of p6-1 p7-1) (left-of p6-1 p5-1)
        (right-of p7-1 p8-1) (left-of p7-1 p6-1)
        (right-of p8-1 p9-1) (left-of p8-1 p7-1)
        (up-of p9-1 p9-2) (left-of p9-1 p8-1)

        (up-of p1-2 p1-3) (down-of p1-2 p1-1)
        (up-of p9-2 p9-3) (down-of p9-2 p9-1)

        (up-of p1-3 p1-4) (right-of p1-3 p2-3) (down-of p1-3 p1-2)
        (right-of p2-3 p3-3) (left-of p2-3 p1-3)
        (right-of p3-3 p4-3) (left-of p3-3 p2-3)
        (right-of p4-3 p5-3) (left-of p4-3 p3-3)
        (right-of p5-3 p6-3) (left-of p5-3 p4-3)
        (right-of p6-3 p7-3) (left-of p6-3 p5-3)
        (right-of p7-3 p8-3) (left-of p7-3 p6-3)
        (right-of p8-3 p9-3) (left-of p8-3 p7-3)
        (up-of p9-3 p9-4) (down-of p9-3 p9-2) (left-of p9-3 p8-3)

        (up-of p1-4 p1-5) (down-of p1-4 p1-3)
        (up-of p9-4 p9-5) (down-of p9-4 p9-3)

        (up-of p1-5 p1-6) (right-of p1-5 p2-5) (down-of p1-5 p1-4)
        (right-of p2-5 p3-5) (left-of p2-5 p1-5)
        (right-of p3-5 p4-5) (left-of p3-5 p2-5)
        (right-of p4-5 p5-5) (left-of p4-5 p3-5)
        (right-of p5-5 p6-5) (left-of p5-5 p4-5)
        (right-of p6-5 p7-5) (left-of p6-5 p5-5)
        (right-of p7-5 p8-5) (left-of p7-5 p6-5)
        (right-of p8-5 p9-5) (left-of p8-5 p7-5)
        (up-of p9-5 p9-6) (down-of p9-5 p9-4) (left-of p9-5 p8-5)

        (up-of p1-6 p1-7) (down-of p1-6 p1-5)
        (up-of p9-6 p9-7) (down-of p9-6 p9-5)

        (up-of p1-7 p1-8) (right-of p1-7 p2-7) (down-of p1-7 p1-6)
        (right-of p2-7 p3-7) (left-of p2-7 p1-7)
        (right-of p3-7 p4-7) (left-of p3-7 p2-7)
        (right-of p4-7 p5-7) (left-of p4-7 p3-7)
        (right-of p5-7 p6-7) (left-of p5-7 p4-7)
        (right-of p6-7 p7-7) (left-of p6-7 p5-7)
        (right-of p7-7 p8-7) (left-of p7-7 p6-7)
        (right-of p8-7 p9-7) (left-of p8-7 p7-7)
        (up-of p9-7 p9-8) (down-of p9-7 p9-6) (left-of p9-7 p8-7)

        (up-of p1-8 p1-9) (down-of p1-8 p1-7)
        (up-of p9-8 p9-9) (down-of p9-8 p9-7)

        (right-of p1-9 p2-9) (down-of p1-9 p1-8)
        (right-of p2-9 p3-9) (left-of p2-9 p1-9)
        (right-of p3-9 p4-9) (left-of p3-9 p2-9)
        (right-of p4-9 p5-9) (left-of p4-9 p3-9)
        (right-of p5-9 p6-9) (left-of p5-9 p4-9)
        (right-of p6-9 p7-9) (left-of p6-9 p5-9)
        (right-of p7-9 p8-9) (left-of p7-9 p6-9)
        (right-of p8-9 p9-9) (left-of p8-9 p7-9)
        (down-of p9-9 p9-8) (left-of p9-9 p8-9)

        (possible p1-1) (possible p2-1) (possible p3-1) (possible p4-1) (possible p5-1) (possible p6-1) (possible p7-1) (possible p8-1) (possible p9-1)
        (possible p1-2)                                                                                                                 (possible p9-2)
        (possible p1-3) (possible p2-3) (possible p3-3) (possible p4-3) (possible p5-3) (possible p6-3) (possible p7-3) (possible p8-3) (possible p9-3)
        (possible p1-4)                                                                                                                 (possible p9-4)
        (possible p1-5) (possible p2-5) (possible p3-5) (possible p4-5) (possible p5-5) (possible p6-5) (possible p7-5) (possible p8-5) (possible p9-5)
        (possible p1-6)                                                                                                                 (possible p9-6)
        (possible p1-7) (possible p2-7) (possible p3-7) (possible p4-7) (possible p5-7) (possible p6-7) (possible p7-7) (possible p8-7) (possible p9-7)
        (possible p1-8)                                                                                                                 (possible p9-8)
        (possible p1-9) (possible p2-9) (possible p3-9) (possible p4-9) (possible p5-9) (possible p6-9) (possible p7-9) (possible p8-9) (possible p9-9)

        (need-start)
    )
    (:goal (at p9-9))
)

