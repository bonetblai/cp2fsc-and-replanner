(define (problem p12x12)
    (:domain mines)
    (:objects
        p1-1 p2-1 p3-1 p4-1 p5-1 p6-1 p7-1 p8-1 p9-1 p10-1 p11-1 p12-1
        p1-2 p2-2 p3-2 p4-2 p5-2 p6-2 p7-2 p8-2 p9-2 p10-2 p11-2 p12-2
        p1-3 p2-3 p3-3 p4-3 p5-3 p6-3 p7-3 p8-3 p9-3 p10-3 p11-3 p12-3
        p1-4 p2-4 p3-4 p4-4 p5-4 p6-4 p7-4 p8-4 p9-4 p10-4 p11-4 p12-4
        p1-5 p2-5 p3-5 p4-5 p5-5 p6-5 p7-5 p8-5 p9-5 p10-5 p11-5 p12-5
        p1-6 p2-6 p3-6 p4-6 p5-6 p6-6 p7-6 p8-6 p9-6 p10-6 p11-6 p12-6
        p1-7 p2-7 p3-7 p4-7 p5-7 p6-7 p7-7 p8-7 p9-7 p10-7 p11-7 p12-7
        p1-8 p2-8 p3-8 p4-8 p5-8 p6-8 p7-8 p8-8 p9-8 p10-8 p11-8 p12-8
        p1-9 p2-9 p3-9 p4-9 p5-9 p6-9 p7-9 p8-9 p9-9 p10-9 p11-9 p12-9
        p1-10 p2-10 p3-10 p4-10 p5-10 p6-10 p7-10 p8-10 p9-10 p10-10 p11-10 p12-10
        p1-11 p2-11 p3-11 p4-11 p5-11 p6-11 p7-11 p8-11 p9-11 p10-11 p11-11 p12-11
        p1-12 p2-12 p3-12 p4-12 p5-12 p6-12 p7-12 p8-12 p9-12 p10-12 p11-12 p12-12 - pos
    )
    (:init
        (need-start)

        (d4 p1-1 p2-1)
        (d6 p1-1 p1-2)
        (d7 p1-1 p2-2)
        (d3 p2-1 p1-1)
        (d4 p2-1 p3-1)
        (d5 p2-1 p1-2)
        (d6 p2-1 p2-2)
        (d7 p2-1 p3-2)
        (d3 p3-1 p2-1)
        (d4 p3-1 p4-1)
        (d5 p3-1 p2-2)
        (d6 p3-1 p3-2)
        (d7 p3-1 p4-2)
        (d3 p4-1 p3-1)
        (d4 p4-1 p5-1)
        (d5 p4-1 p3-2)
        (d6 p4-1 p4-2)
        (d7 p4-1 p5-2)
        (d3 p5-1 p4-1)
        (d4 p5-1 p6-1)
        (d5 p5-1 p4-2)
        (d6 p5-1 p5-2)
        (d7 p5-1 p6-2)
        (d3 p6-1 p5-1)
        (d4 p6-1 p7-1)
        (d5 p6-1 p5-2)
        (d6 p6-1 p6-2)
        (d7 p6-1 p7-2)
        (d3 p7-1 p6-1)
        (d4 p7-1 p8-1)
        (d5 p7-1 p6-2)
        (d6 p7-1 p7-2)
        (d7 p7-1 p8-2)
        (d3 p8-1 p7-1)
        (d4 p8-1 p9-1)
        (d5 p8-1 p7-2)
        (d6 p8-1 p8-2)
        (d7 p8-1 p9-2)
        (d3 p9-1 p8-1)
        (d4 p9-1 p10-1)
        (d5 p9-1 p8-2)
        (d6 p9-1 p9-2)
        (d7 p9-1 p10-2)
        (d3 p10-1 p9-1)
        (d4 p10-1 p11-1)
        (d5 p10-1 p9-2)
        (d6 p10-1 p10-2)
        (d7 p10-1 p11-2)
        (d3 p11-1 p10-1)
        (d4 p11-1 p12-1)
        (d5 p11-1 p10-2)
        (d6 p11-1 p11-2)
        (d7 p11-1 p12-2)
        (d3 p12-1 p11-1)
        (d5 p12-1 p11-2)
        (d6 p12-1 p12-2)
        (d1 p1-2 p1-1)
        (d2 p1-2 p2-1)
        (d4 p1-2 p2-2)
        (d6 p1-2 p1-3)
        (d7 p1-2 p2-3)
        (d0 p2-2 p1-1)
        (d1 p2-2 p2-1)
        (d2 p2-2 p3-1)
        (d3 p2-2 p1-2)
        (d4 p2-2 p3-2)
        (d5 p2-2 p1-3)
        (d6 p2-2 p2-3)
        (d7 p2-2 p3-3)
        (d0 p3-2 p2-1)
        (d1 p3-2 p3-1)
        (d2 p3-2 p4-1)
        (d3 p3-2 p2-2)
        (d4 p3-2 p4-2)
        (d5 p3-2 p2-3)
        (d6 p3-2 p3-3)
        (d7 p3-2 p4-3)
        (d0 p4-2 p3-1)
        (d1 p4-2 p4-1)
        (d2 p4-2 p5-1)
        (d3 p4-2 p3-2)
        (d4 p4-2 p5-2)
        (d5 p4-2 p3-3)
        (d6 p4-2 p4-3)
        (d7 p4-2 p5-3)
        (d0 p5-2 p4-1)
        (d1 p5-2 p5-1)
        (d2 p5-2 p6-1)
        (d3 p5-2 p4-2)
        (d4 p5-2 p6-2)
        (d5 p5-2 p4-3)
        (d6 p5-2 p5-3)
        (d7 p5-2 p6-3)
        (d0 p6-2 p5-1)
        (d1 p6-2 p6-1)
        (d2 p6-2 p7-1)
        (d3 p6-2 p5-2)
        (d4 p6-2 p7-2)
        (d5 p6-2 p5-3)
        (d6 p6-2 p6-3)
        (d7 p6-2 p7-3)
        (d0 p7-2 p6-1)
        (d1 p7-2 p7-1)
        (d2 p7-2 p8-1)
        (d3 p7-2 p6-2)
        (d4 p7-2 p8-2)
        (d5 p7-2 p6-3)
        (d6 p7-2 p7-3)
        (d7 p7-2 p8-3)
        (d0 p8-2 p7-1)
        (d1 p8-2 p8-1)
        (d2 p8-2 p9-1)
        (d3 p8-2 p7-2)
        (d4 p8-2 p9-2)
        (d5 p8-2 p7-3)
        (d6 p8-2 p8-3)
        (d7 p8-2 p9-3)
        (d0 p9-2 p8-1)
        (d1 p9-2 p9-1)
        (d2 p9-2 p10-1)
        (d3 p9-2 p8-2)
        (d4 p9-2 p10-2)
        (d5 p9-2 p8-3)
        (d6 p9-2 p9-3)
        (d7 p9-2 p10-3)
        (d0 p10-2 p9-1)
        (d1 p10-2 p10-1)
        (d2 p10-2 p11-1)
        (d3 p10-2 p9-2)
        (d4 p10-2 p11-2)
        (d5 p10-2 p9-3)
        (d6 p10-2 p10-3)
        (d7 p10-2 p11-3)
        (d0 p11-2 p10-1)
        (d1 p11-2 p11-1)
        (d2 p11-2 p12-1)
        (d3 p11-2 p10-2)
        (d4 p11-2 p12-2)
        (d5 p11-2 p10-3)
        (d6 p11-2 p11-3)
        (d7 p11-2 p12-3)
        (d0 p12-2 p11-1)
        (d1 p12-2 p12-1)
        (d3 p12-2 p11-2)
        (d5 p12-2 p11-3)
        (d6 p12-2 p12-3)
        (d1 p1-3 p1-2)
        (d2 p1-3 p2-2)
        (d4 p1-3 p2-3)
        (d6 p1-3 p1-4)
        (d7 p1-3 p2-4)
        (d0 p2-3 p1-2)
        (d1 p2-3 p2-2)
        (d2 p2-3 p3-2)
        (d3 p2-3 p1-3)
        (d4 p2-3 p3-3)
        (d5 p2-3 p1-4)
        (d6 p2-3 p2-4)
        (d7 p2-3 p3-4)
        (d0 p3-3 p2-2)
        (d1 p3-3 p3-2)
        (d2 p3-3 p4-2)
        (d3 p3-3 p2-3)
        (d4 p3-3 p4-3)
        (d5 p3-3 p2-4)
        (d6 p3-3 p3-4)
        (d7 p3-3 p4-4)
        (d0 p4-3 p3-2)
        (d1 p4-3 p4-2)
        (d2 p4-3 p5-2)
        (d3 p4-3 p3-3)
        (d4 p4-3 p5-3)
        (d5 p4-3 p3-4)
        (d6 p4-3 p4-4)
        (d7 p4-3 p5-4)
        (d0 p5-3 p4-2)
        (d1 p5-3 p5-2)
        (d2 p5-3 p6-2)
        (d3 p5-3 p4-3)
        (d4 p5-3 p6-3)
        (d5 p5-3 p4-4)
        (d6 p5-3 p5-4)
        (d7 p5-3 p6-4)
        (d0 p6-3 p5-2)
        (d1 p6-3 p6-2)
        (d2 p6-3 p7-2)
        (d3 p6-3 p5-3)
        (d4 p6-3 p7-3)
        (d5 p6-3 p5-4)
        (d6 p6-3 p6-4)
        (d7 p6-3 p7-4)
        (d0 p7-3 p6-2)
        (d1 p7-3 p7-2)
        (d2 p7-3 p8-2)
        (d3 p7-3 p6-3)
        (d4 p7-3 p8-3)
        (d5 p7-3 p6-4)
        (d6 p7-3 p7-4)
        (d7 p7-3 p8-4)
        (d0 p8-3 p7-2)
        (d1 p8-3 p8-2)
        (d2 p8-3 p9-2)
        (d3 p8-3 p7-3)
        (d4 p8-3 p9-3)
        (d5 p8-3 p7-4)
        (d6 p8-3 p8-4)
        (d7 p8-3 p9-4)
        (d0 p9-3 p8-2)
        (d1 p9-3 p9-2)
        (d2 p9-3 p10-2)
        (d3 p9-3 p8-3)
        (d4 p9-3 p10-3)
        (d5 p9-3 p8-4)
        (d6 p9-3 p9-4)
        (d7 p9-3 p10-4)
        (d0 p10-3 p9-2)
        (d1 p10-3 p10-2)
        (d2 p10-3 p11-2)
        (d3 p10-3 p9-3)
        (d4 p10-3 p11-3)
        (d5 p10-3 p9-4)
        (d6 p10-3 p10-4)
        (d7 p10-3 p11-4)
        (d0 p11-3 p10-2)
        (d1 p11-3 p11-2)
        (d2 p11-3 p12-2)
        (d3 p11-3 p10-3)
        (d4 p11-3 p12-3)
        (d5 p11-3 p10-4)
        (d6 p11-3 p11-4)
        (d7 p11-3 p12-4)
        (d0 p12-3 p11-2)
        (d1 p12-3 p12-2)
        (d3 p12-3 p11-3)
        (d5 p12-3 p11-4)
        (d6 p12-3 p12-4)
        (d1 p1-4 p1-3)
        (d2 p1-4 p2-3)
        (d4 p1-4 p2-4)
        (d6 p1-4 p1-5)
        (d7 p1-4 p2-5)
        (d0 p2-4 p1-3)
        (d1 p2-4 p2-3)
        (d2 p2-4 p3-3)
        (d3 p2-4 p1-4)
        (d4 p2-4 p3-4)
        (d5 p2-4 p1-5)
        (d6 p2-4 p2-5)
        (d7 p2-4 p3-5)
        (d0 p3-4 p2-3)
        (d1 p3-4 p3-3)
        (d2 p3-4 p4-3)
        (d3 p3-4 p2-4)
        (d4 p3-4 p4-4)
        (d5 p3-4 p2-5)
        (d6 p3-4 p3-5)
        (d7 p3-4 p4-5)
        (d0 p4-4 p3-3)
        (d1 p4-4 p4-3)
        (d2 p4-4 p5-3)
        (d3 p4-4 p3-4)
        (d4 p4-4 p5-4)
        (d5 p4-4 p3-5)
        (d6 p4-4 p4-5)
        (d7 p4-4 p5-5)
        (d0 p5-4 p4-3)
        (d1 p5-4 p5-3)
        (d2 p5-4 p6-3)
        (d3 p5-4 p4-4)
        (d4 p5-4 p6-4)
        (d5 p5-4 p4-5)
        (d6 p5-4 p5-5)
        (d7 p5-4 p6-5)
        (d0 p6-4 p5-3)
        (d1 p6-4 p6-3)
        (d2 p6-4 p7-3)
        (d3 p6-4 p5-4)
        (d4 p6-4 p7-4)
        (d5 p6-4 p5-5)
        (d6 p6-4 p6-5)
        (d7 p6-4 p7-5)
        (d0 p7-4 p6-3)
        (d1 p7-4 p7-3)
        (d2 p7-4 p8-3)
        (d3 p7-4 p6-4)
        (d4 p7-4 p8-4)
        (d5 p7-4 p6-5)
        (d6 p7-4 p7-5)
        (d7 p7-4 p8-5)
        (d0 p8-4 p7-3)
        (d1 p8-4 p8-3)
        (d2 p8-4 p9-3)
        (d3 p8-4 p7-4)
        (d4 p8-4 p9-4)
        (d5 p8-4 p7-5)
        (d6 p8-4 p8-5)
        (d7 p8-4 p9-5)
        (d0 p9-4 p8-3)
        (d1 p9-4 p9-3)
        (d2 p9-4 p10-3)
        (d3 p9-4 p8-4)
        (d4 p9-4 p10-4)
        (d5 p9-4 p8-5)
        (d6 p9-4 p9-5)
        (d7 p9-4 p10-5)
        (d0 p10-4 p9-3)
        (d1 p10-4 p10-3)
        (d2 p10-4 p11-3)
        (d3 p10-4 p9-4)
        (d4 p10-4 p11-4)
        (d5 p10-4 p9-5)
        (d6 p10-4 p10-5)
        (d7 p10-4 p11-5)
        (d0 p11-4 p10-3)
        (d1 p11-4 p11-3)
        (d2 p11-4 p12-3)
        (d3 p11-4 p10-4)
        (d4 p11-4 p12-4)
        (d5 p11-4 p10-5)
        (d6 p11-4 p11-5)
        (d7 p11-4 p12-5)
        (d0 p12-4 p11-3)
        (d1 p12-4 p12-3)
        (d3 p12-4 p11-4)
        (d5 p12-4 p11-5)
        (d6 p12-4 p12-5)
        (d1 p1-5 p1-4)
        (d2 p1-5 p2-4)
        (d4 p1-5 p2-5)
        (d6 p1-5 p1-6)
        (d7 p1-5 p2-6)
        (d0 p2-5 p1-4)
        (d1 p2-5 p2-4)
        (d2 p2-5 p3-4)
        (d3 p2-5 p1-5)
        (d4 p2-5 p3-5)
        (d5 p2-5 p1-6)
        (d6 p2-5 p2-6)
        (d7 p2-5 p3-6)
        (d0 p3-5 p2-4)
        (d1 p3-5 p3-4)
        (d2 p3-5 p4-4)
        (d3 p3-5 p2-5)
        (d4 p3-5 p4-5)
        (d5 p3-5 p2-6)
        (d6 p3-5 p3-6)
        (d7 p3-5 p4-6)
        (d0 p4-5 p3-4)
        (d1 p4-5 p4-4)
        (d2 p4-5 p5-4)
        (d3 p4-5 p3-5)
        (d4 p4-5 p5-5)
        (d5 p4-5 p3-6)
        (d6 p4-5 p4-6)
        (d7 p4-5 p5-6)
        (d0 p5-5 p4-4)
        (d1 p5-5 p5-4)
        (d2 p5-5 p6-4)
        (d3 p5-5 p4-5)
        (d4 p5-5 p6-5)
        (d5 p5-5 p4-6)
        (d6 p5-5 p5-6)
        (d7 p5-5 p6-6)
        (d0 p6-5 p5-4)
        (d1 p6-5 p6-4)
        (d2 p6-5 p7-4)
        (d3 p6-5 p5-5)
        (d4 p6-5 p7-5)
        (d5 p6-5 p5-6)
        (d6 p6-5 p6-6)
        (d7 p6-5 p7-6)
        (d0 p7-5 p6-4)
        (d1 p7-5 p7-4)
        (d2 p7-5 p8-4)
        (d3 p7-5 p6-5)
        (d4 p7-5 p8-5)
        (d5 p7-5 p6-6)
        (d6 p7-5 p7-6)
        (d7 p7-5 p8-6)
        (d0 p8-5 p7-4)
        (d1 p8-5 p8-4)
        (d2 p8-5 p9-4)
        (d3 p8-5 p7-5)
        (d4 p8-5 p9-5)
        (d5 p8-5 p7-6)
        (d6 p8-5 p8-6)
        (d7 p8-5 p9-6)
        (d0 p9-5 p8-4)
        (d1 p9-5 p9-4)
        (d2 p9-5 p10-4)
        (d3 p9-5 p8-5)
        (d4 p9-5 p10-5)
        (d5 p9-5 p8-6)
        (d6 p9-5 p9-6)
        (d7 p9-5 p10-6)
        (d0 p10-5 p9-4)
        (d1 p10-5 p10-4)
        (d2 p10-5 p11-4)
        (d3 p10-5 p9-5)
        (d4 p10-5 p11-5)
        (d5 p10-5 p9-6)
        (d6 p10-5 p10-6)
        (d7 p10-5 p11-6)
        (d0 p11-5 p10-4)
        (d1 p11-5 p11-4)
        (d2 p11-5 p12-4)
        (d3 p11-5 p10-5)
        (d4 p11-5 p12-5)
        (d5 p11-5 p10-6)
        (d6 p11-5 p11-6)
        (d7 p11-5 p12-6)
        (d0 p12-5 p11-4)
        (d1 p12-5 p12-4)
        (d3 p12-5 p11-5)
        (d5 p12-5 p11-6)
        (d6 p12-5 p12-6)
        (d1 p1-6 p1-5)
        (d2 p1-6 p2-5)
        (d4 p1-6 p2-6)
        (d6 p1-6 p1-7)
        (d7 p1-6 p2-7)
        (d0 p2-6 p1-5)
        (d1 p2-6 p2-5)
        (d2 p2-6 p3-5)
        (d3 p2-6 p1-6)
        (d4 p2-6 p3-6)
        (d5 p2-6 p1-7)
        (d6 p2-6 p2-7)
        (d7 p2-6 p3-7)
        (d0 p3-6 p2-5)
        (d1 p3-6 p3-5)
        (d2 p3-6 p4-5)
        (d3 p3-6 p2-6)
        (d4 p3-6 p4-6)
        (d5 p3-6 p2-7)
        (d6 p3-6 p3-7)
        (d7 p3-6 p4-7)
        (d0 p4-6 p3-5)
        (d1 p4-6 p4-5)
        (d2 p4-6 p5-5)
        (d3 p4-6 p3-6)
        (d4 p4-6 p5-6)
        (d5 p4-6 p3-7)
        (d6 p4-6 p4-7)
        (d7 p4-6 p5-7)
        (d0 p5-6 p4-5)
        (d1 p5-6 p5-5)
        (d2 p5-6 p6-5)
        (d3 p5-6 p4-6)
        (d4 p5-6 p6-6)
        (d5 p5-6 p4-7)
        (d6 p5-6 p5-7)
        (d7 p5-6 p6-7)
        (d0 p6-6 p5-5)
        (d1 p6-6 p6-5)
        (d2 p6-6 p7-5)
        (d3 p6-6 p5-6)
        (d4 p6-6 p7-6)
        (d5 p6-6 p5-7)
        (d6 p6-6 p6-7)
        (d7 p6-6 p7-7)
        (d0 p7-6 p6-5)
        (d1 p7-6 p7-5)
        (d2 p7-6 p8-5)
        (d3 p7-6 p6-6)
        (d4 p7-6 p8-6)
        (d5 p7-6 p6-7)
        (d6 p7-6 p7-7)
        (d7 p7-6 p8-7)
        (d0 p8-6 p7-5)
        (d1 p8-6 p8-5)
        (d2 p8-6 p9-5)
        (d3 p8-6 p7-6)
        (d4 p8-6 p9-6)
        (d5 p8-6 p7-7)
        (d6 p8-6 p8-7)
        (d7 p8-6 p9-7)
        (d0 p9-6 p8-5)
        (d1 p9-6 p9-5)
        (d2 p9-6 p10-5)
        (d3 p9-6 p8-6)
        (d4 p9-6 p10-6)
        (d5 p9-6 p8-7)
        (d6 p9-6 p9-7)
        (d7 p9-6 p10-7)
        (d0 p10-6 p9-5)
        (d1 p10-6 p10-5)
        (d2 p10-6 p11-5)
        (d3 p10-6 p9-6)
        (d4 p10-6 p11-6)
        (d5 p10-6 p9-7)
        (d6 p10-6 p10-7)
        (d7 p10-6 p11-7)
        (d0 p11-6 p10-5)
        (d1 p11-6 p11-5)
        (d2 p11-6 p12-5)
        (d3 p11-6 p10-6)
        (d4 p11-6 p12-6)
        (d5 p11-6 p10-7)
        (d6 p11-6 p11-7)
        (d7 p11-6 p12-7)
        (d0 p12-6 p11-5)
        (d1 p12-6 p12-5)
        (d3 p12-6 p11-6)
        (d5 p12-6 p11-7)
        (d6 p12-6 p12-7)
        (d1 p1-7 p1-6)
        (d2 p1-7 p2-6)
        (d4 p1-7 p2-7)
        (d6 p1-7 p1-8)
        (d7 p1-7 p2-8)
        (d0 p2-7 p1-6)
        (d1 p2-7 p2-6)
        (d2 p2-7 p3-6)
        (d3 p2-7 p1-7)
        (d4 p2-7 p3-7)
        (d5 p2-7 p1-8)
        (d6 p2-7 p2-8)
        (d7 p2-7 p3-8)
        (d0 p3-7 p2-6)
        (d1 p3-7 p3-6)
        (d2 p3-7 p4-6)
        (d3 p3-7 p2-7)
        (d4 p3-7 p4-7)
        (d5 p3-7 p2-8)
        (d6 p3-7 p3-8)
        (d7 p3-7 p4-8)
        (d0 p4-7 p3-6)
        (d1 p4-7 p4-6)
        (d2 p4-7 p5-6)
        (d3 p4-7 p3-7)
        (d4 p4-7 p5-7)
        (d5 p4-7 p3-8)
        (d6 p4-7 p4-8)
        (d7 p4-7 p5-8)
        (d0 p5-7 p4-6)
        (d1 p5-7 p5-6)
        (d2 p5-7 p6-6)
        (d3 p5-7 p4-7)
        (d4 p5-7 p6-7)
        (d5 p5-7 p4-8)
        (d6 p5-7 p5-8)
        (d7 p5-7 p6-8)
        (d0 p6-7 p5-6)
        (d1 p6-7 p6-6)
        (d2 p6-7 p7-6)
        (d3 p6-7 p5-7)
        (d4 p6-7 p7-7)
        (d5 p6-7 p5-8)
        (d6 p6-7 p6-8)
        (d7 p6-7 p7-8)
        (d0 p7-7 p6-6)
        (d1 p7-7 p7-6)
        (d2 p7-7 p8-6)
        (d3 p7-7 p6-7)
        (d4 p7-7 p8-7)
        (d5 p7-7 p6-8)
        (d6 p7-7 p7-8)
        (d7 p7-7 p8-8)
        (d0 p8-7 p7-6)
        (d1 p8-7 p8-6)
        (d2 p8-7 p9-6)
        (d3 p8-7 p7-7)
        (d4 p8-7 p9-7)
        (d5 p8-7 p7-8)
        (d6 p8-7 p8-8)
        (d7 p8-7 p9-8)
        (d0 p9-7 p8-6)
        (d1 p9-7 p9-6)
        (d2 p9-7 p10-6)
        (d3 p9-7 p8-7)
        (d4 p9-7 p10-7)
        (d5 p9-7 p8-8)
        (d6 p9-7 p9-8)
        (d7 p9-7 p10-8)
        (d0 p10-7 p9-6)
        (d1 p10-7 p10-6)
        (d2 p10-7 p11-6)
        (d3 p10-7 p9-7)
        (d4 p10-7 p11-7)
        (d5 p10-7 p9-8)
        (d6 p10-7 p10-8)
        (d7 p10-7 p11-8)
        (d0 p11-7 p10-6)
        (d1 p11-7 p11-6)
        (d2 p11-7 p12-6)
        (d3 p11-7 p10-7)
        (d4 p11-7 p12-7)
        (d5 p11-7 p10-8)
        (d6 p11-7 p11-8)
        (d7 p11-7 p12-8)
        (d0 p12-7 p11-6)
        (d1 p12-7 p12-6)
        (d3 p12-7 p11-7)
        (d5 p12-7 p11-8)
        (d6 p12-7 p12-8)
        (d1 p1-8 p1-7)
        (d2 p1-8 p2-7)
        (d4 p1-8 p2-8)
        (d6 p1-8 p1-9)
        (d7 p1-8 p2-9)
        (d0 p2-8 p1-7)
        (d1 p2-8 p2-7)
        (d2 p2-8 p3-7)
        (d3 p2-8 p1-8)
        (d4 p2-8 p3-8)
        (d5 p2-8 p1-9)
        (d6 p2-8 p2-9)
        (d7 p2-8 p3-9)
        (d0 p3-8 p2-7)
        (d1 p3-8 p3-7)
        (d2 p3-8 p4-7)
        (d3 p3-8 p2-8)
        (d4 p3-8 p4-8)
        (d5 p3-8 p2-9)
        (d6 p3-8 p3-9)
        (d7 p3-8 p4-9)
        (d0 p4-8 p3-7)
        (d1 p4-8 p4-7)
        (d2 p4-8 p5-7)
        (d3 p4-8 p3-8)
        (d4 p4-8 p5-8)
        (d5 p4-8 p3-9)
        (d6 p4-8 p4-9)
        (d7 p4-8 p5-9)
        (d0 p5-8 p4-7)
        (d1 p5-8 p5-7)
        (d2 p5-8 p6-7)
        (d3 p5-8 p4-8)
        (d4 p5-8 p6-8)
        (d5 p5-8 p4-9)
        (d6 p5-8 p5-9)
        (d7 p5-8 p6-9)
        (d0 p6-8 p5-7)
        (d1 p6-8 p6-7)
        (d2 p6-8 p7-7)
        (d3 p6-8 p5-8)
        (d4 p6-8 p7-8)
        (d5 p6-8 p5-9)
        (d6 p6-8 p6-9)
        (d7 p6-8 p7-9)
        (d0 p7-8 p6-7)
        (d1 p7-8 p7-7)
        (d2 p7-8 p8-7)
        (d3 p7-8 p6-8)
        (d4 p7-8 p8-8)
        (d5 p7-8 p6-9)
        (d6 p7-8 p7-9)
        (d7 p7-8 p8-9)
        (d0 p8-8 p7-7)
        (d1 p8-8 p8-7)
        (d2 p8-8 p9-7)
        (d3 p8-8 p7-8)
        (d4 p8-8 p9-8)
        (d5 p8-8 p7-9)
        (d6 p8-8 p8-9)
        (d7 p8-8 p9-9)
        (d0 p9-8 p8-7)
        (d1 p9-8 p9-7)
        (d2 p9-8 p10-7)
        (d3 p9-8 p8-8)
        (d4 p9-8 p10-8)
        (d5 p9-8 p8-9)
        (d6 p9-8 p9-9)
        (d7 p9-8 p10-9)
        (d0 p10-8 p9-7)
        (d1 p10-8 p10-7)
        (d2 p10-8 p11-7)
        (d3 p10-8 p9-8)
        (d4 p10-8 p11-8)
        (d5 p10-8 p9-9)
        (d6 p10-8 p10-9)
        (d7 p10-8 p11-9)
        (d0 p11-8 p10-7)
        (d1 p11-8 p11-7)
        (d2 p11-8 p12-7)
        (d3 p11-8 p10-8)
        (d4 p11-8 p12-8)
        (d5 p11-8 p10-9)
        (d6 p11-8 p11-9)
        (d7 p11-8 p12-9)
        (d0 p12-8 p11-7)
        (d1 p12-8 p12-7)
        (d3 p12-8 p11-8)
        (d5 p12-8 p11-9)
        (d6 p12-8 p12-9)
        (d1 p1-9 p1-8)
        (d2 p1-9 p2-8)
        (d4 p1-9 p2-9)
        (d6 p1-9 p1-10)
        (d7 p1-9 p2-10)
        (d0 p2-9 p1-8)
        (d1 p2-9 p2-8)
        (d2 p2-9 p3-8)
        (d3 p2-9 p1-9)
        (d4 p2-9 p3-9)
        (d5 p2-9 p1-10)
        (d6 p2-9 p2-10)
        (d7 p2-9 p3-10)
        (d0 p3-9 p2-8)
        (d1 p3-9 p3-8)
        (d2 p3-9 p4-8)
        (d3 p3-9 p2-9)
        (d4 p3-9 p4-9)
        (d5 p3-9 p2-10)
        (d6 p3-9 p3-10)
        (d7 p3-9 p4-10)
        (d0 p4-9 p3-8)
        (d1 p4-9 p4-8)
        (d2 p4-9 p5-8)
        (d3 p4-9 p3-9)
        (d4 p4-9 p5-9)
        (d5 p4-9 p3-10)
        (d6 p4-9 p4-10)
        (d7 p4-9 p5-10)
        (d0 p5-9 p4-8)
        (d1 p5-9 p5-8)
        (d2 p5-9 p6-8)
        (d3 p5-9 p4-9)
        (d4 p5-9 p6-9)
        (d5 p5-9 p4-10)
        (d6 p5-9 p5-10)
        (d7 p5-9 p6-10)
        (d0 p6-9 p5-8)
        (d1 p6-9 p6-8)
        (d2 p6-9 p7-8)
        (d3 p6-9 p5-9)
        (d4 p6-9 p7-9)
        (d5 p6-9 p5-10)
        (d6 p6-9 p6-10)
        (d7 p6-9 p7-10)
        (d0 p7-9 p6-8)
        (d1 p7-9 p7-8)
        (d2 p7-9 p8-8)
        (d3 p7-9 p6-9)
        (d4 p7-9 p8-9)
        (d5 p7-9 p6-10)
        (d6 p7-9 p7-10)
        (d7 p7-9 p8-10)
        (d0 p8-9 p7-8)
        (d1 p8-9 p8-8)
        (d2 p8-9 p9-8)
        (d3 p8-9 p7-9)
        (d4 p8-9 p9-9)
        (d5 p8-9 p7-10)
        (d6 p8-9 p8-10)
        (d7 p8-9 p9-10)
        (d0 p9-9 p8-8)
        (d1 p9-9 p9-8)
        (d2 p9-9 p10-8)
        (d3 p9-9 p8-9)
        (d4 p9-9 p10-9)
        (d5 p9-9 p8-10)
        (d6 p9-9 p9-10)
        (d7 p9-9 p10-10)
        (d0 p10-9 p9-8)
        (d1 p10-9 p10-8)
        (d2 p10-9 p11-8)
        (d3 p10-9 p9-9)
        (d4 p10-9 p11-9)
        (d5 p10-9 p9-10)
        (d6 p10-9 p10-10)
        (d7 p10-9 p11-10)
        (d0 p11-9 p10-8)
        (d1 p11-9 p11-8)
        (d2 p11-9 p12-8)
        (d3 p11-9 p10-9)
        (d4 p11-9 p12-9)
        (d5 p11-9 p10-10)
        (d6 p11-9 p11-10)
        (d7 p11-9 p12-10)
        (d0 p12-9 p11-8)
        (d1 p12-9 p12-8)
        (d3 p12-9 p11-9)
        (d5 p12-9 p11-10)
        (d6 p12-9 p12-10)
        (d1 p1-10 p1-9)
        (d2 p1-10 p2-9)
        (d4 p1-10 p2-10)
        (d6 p1-10 p1-11)
        (d7 p1-10 p2-11)
        (d0 p2-10 p1-9)
        (d1 p2-10 p2-9)
        (d2 p2-10 p3-9)
        (d3 p2-10 p1-10)
        (d4 p2-10 p3-10)
        (d5 p2-10 p1-11)
        (d6 p2-10 p2-11)
        (d7 p2-10 p3-11)
        (d0 p3-10 p2-9)
        (d1 p3-10 p3-9)
        (d2 p3-10 p4-9)
        (d3 p3-10 p2-10)
        (d4 p3-10 p4-10)
        (d5 p3-10 p2-11)
        (d6 p3-10 p3-11)
        (d7 p3-10 p4-11)
        (d0 p4-10 p3-9)
        (d1 p4-10 p4-9)
        (d2 p4-10 p5-9)
        (d3 p4-10 p3-10)
        (d4 p4-10 p5-10)
        (d5 p4-10 p3-11)
        (d6 p4-10 p4-11)
        (d7 p4-10 p5-11)
        (d0 p5-10 p4-9)
        (d1 p5-10 p5-9)
        (d2 p5-10 p6-9)
        (d3 p5-10 p4-10)
        (d4 p5-10 p6-10)
        (d5 p5-10 p4-11)
        (d6 p5-10 p5-11)
        (d7 p5-10 p6-11)
        (d0 p6-10 p5-9)
        (d1 p6-10 p6-9)
        (d2 p6-10 p7-9)
        (d3 p6-10 p5-10)
        (d4 p6-10 p7-10)
        (d5 p6-10 p5-11)
        (d6 p6-10 p6-11)
        (d7 p6-10 p7-11)
        (d0 p7-10 p6-9)
        (d1 p7-10 p7-9)
        (d2 p7-10 p8-9)
        (d3 p7-10 p6-10)
        (d4 p7-10 p8-10)
        (d5 p7-10 p6-11)
        (d6 p7-10 p7-11)
        (d7 p7-10 p8-11)
        (d0 p8-10 p7-9)
        (d1 p8-10 p8-9)
        (d2 p8-10 p9-9)
        (d3 p8-10 p7-10)
        (d4 p8-10 p9-10)
        (d5 p8-10 p7-11)
        (d6 p8-10 p8-11)
        (d7 p8-10 p9-11)
        (d0 p9-10 p8-9)
        (d1 p9-10 p9-9)
        (d2 p9-10 p10-9)
        (d3 p9-10 p8-10)
        (d4 p9-10 p10-10)
        (d5 p9-10 p8-11)
        (d6 p9-10 p9-11)
        (d7 p9-10 p10-11)
        (d0 p10-10 p9-9)
        (d1 p10-10 p10-9)
        (d2 p10-10 p11-9)
        (d3 p10-10 p9-10)
        (d4 p10-10 p11-10)
        (d5 p10-10 p9-11)
        (d6 p10-10 p10-11)
        (d7 p10-10 p11-11)
        (d0 p11-10 p10-9)
        (d1 p11-10 p11-9)
        (d2 p11-10 p12-9)
        (d3 p11-10 p10-10)
        (d4 p11-10 p12-10)
        (d5 p11-10 p10-11)
        (d6 p11-10 p11-11)
        (d7 p11-10 p12-11)
        (d0 p12-10 p11-9)
        (d1 p12-10 p12-9)
        (d3 p12-10 p11-10)
        (d5 p12-10 p11-11)
        (d6 p12-10 p12-11)
        (d1 p1-11 p1-10)
        (d2 p1-11 p2-10)
        (d4 p1-11 p2-11)
        (d6 p1-11 p1-12)
        (d7 p1-11 p2-12)
        (d0 p2-11 p1-10)
        (d1 p2-11 p2-10)
        (d2 p2-11 p3-10)
        (d3 p2-11 p1-11)
        (d4 p2-11 p3-11)
        (d5 p2-11 p1-12)
        (d6 p2-11 p2-12)
        (d7 p2-11 p3-12)
        (d0 p3-11 p2-10)
        (d1 p3-11 p3-10)
        (d2 p3-11 p4-10)
        (d3 p3-11 p2-11)
        (d4 p3-11 p4-11)
        (d5 p3-11 p2-12)
        (d6 p3-11 p3-12)
        (d7 p3-11 p4-12)
        (d0 p4-11 p3-10)
        (d1 p4-11 p4-10)
        (d2 p4-11 p5-10)
        (d3 p4-11 p3-11)
        (d4 p4-11 p5-11)
        (d5 p4-11 p3-12)
        (d6 p4-11 p4-12)
        (d7 p4-11 p5-12)
        (d0 p5-11 p4-10)
        (d1 p5-11 p5-10)
        (d2 p5-11 p6-10)
        (d3 p5-11 p4-11)
        (d4 p5-11 p6-11)
        (d5 p5-11 p4-12)
        (d6 p5-11 p5-12)
        (d7 p5-11 p6-12)
        (d0 p6-11 p5-10)
        (d1 p6-11 p6-10)
        (d2 p6-11 p7-10)
        (d3 p6-11 p5-11)
        (d4 p6-11 p7-11)
        (d5 p6-11 p5-12)
        (d6 p6-11 p6-12)
        (d7 p6-11 p7-12)
        (d0 p7-11 p6-10)
        (d1 p7-11 p7-10)
        (d2 p7-11 p8-10)
        (d3 p7-11 p6-11)
        (d4 p7-11 p8-11)
        (d5 p7-11 p6-12)
        (d6 p7-11 p7-12)
        (d7 p7-11 p8-12)
        (d0 p8-11 p7-10)
        (d1 p8-11 p8-10)
        (d2 p8-11 p9-10)
        (d3 p8-11 p7-11)
        (d4 p8-11 p9-11)
        (d5 p8-11 p7-12)
        (d6 p8-11 p8-12)
        (d7 p8-11 p9-12)
        (d0 p9-11 p8-10)
        (d1 p9-11 p9-10)
        (d2 p9-11 p10-10)
        (d3 p9-11 p8-11)
        (d4 p9-11 p10-11)
        (d5 p9-11 p8-12)
        (d6 p9-11 p9-12)
        (d7 p9-11 p10-12)
        (d0 p10-11 p9-10)
        (d1 p10-11 p10-10)
        (d2 p10-11 p11-10)
        (d3 p10-11 p9-11)
        (d4 p10-11 p11-11)
        (d5 p10-11 p9-12)
        (d6 p10-11 p10-12)
        (d7 p10-11 p11-12)
        (d0 p11-11 p10-10)
        (d1 p11-11 p11-10)
        (d2 p11-11 p12-10)
        (d3 p11-11 p10-11)
        (d4 p11-11 p12-11)
        (d5 p11-11 p10-12)
        (d6 p11-11 p11-12)
        (d7 p11-11 p12-12)
        (d0 p12-11 p11-10)
        (d1 p12-11 p12-10)
        (d3 p12-11 p11-11)
        (d5 p12-11 p11-12)
        (d6 p12-11 p12-12)
        (d1 p1-12 p1-11)
        (d2 p1-12 p2-11)
        (d4 p1-12 p2-12)
        (d0 p2-12 p1-11)
        (d1 p2-12 p2-11)
        (d2 p2-12 p3-11)
        (d3 p2-12 p1-12)
        (d4 p2-12 p3-12)
        (d0 p3-12 p2-11)
        (d1 p3-12 p3-11)
        (d2 p3-12 p4-11)
        (d3 p3-12 p2-12)
        (d4 p3-12 p4-12)
        (d0 p4-12 p3-11)
        (d1 p4-12 p4-11)
        (d2 p4-12 p5-11)
        (d3 p4-12 p3-12)
        (d4 p4-12 p5-12)
        (d0 p5-12 p4-11)
        (d1 p5-12 p5-11)
        (d2 p5-12 p6-11)
        (d3 p5-12 p4-12)
        (d4 p5-12 p6-12)
        (d0 p6-12 p5-11)
        (d1 p6-12 p6-11)
        (d2 p6-12 p7-11)
        (d3 p6-12 p5-12)
        (d4 p6-12 p7-12)
        (d0 p7-12 p6-11)
        (d1 p7-12 p7-11)
        (d2 p7-12 p8-11)
        (d3 p7-12 p6-12)
        (d4 p7-12 p8-12)
        (d0 p8-12 p7-11)
        (d1 p8-12 p8-11)
        (d2 p8-12 p9-11)
        (d3 p8-12 p7-12)
        (d4 p8-12 p9-12)
        (d0 p9-12 p8-11)
        (d1 p9-12 p9-11)
        (d2 p9-12 p10-11)
        (d3 p9-12 p8-12)
        (d4 p9-12 p10-12)
        (d0 p10-12 p9-11)
        (d1 p10-12 p10-11)
        (d2 p10-12 p11-11)
        (d3 p10-12 p9-12)
        (d4 p10-12 p11-12)
        (d0 p11-12 p10-11)
        (d1 p11-12 p11-11)
        (d2 p11-12 p12-11)
        (d3 p11-12 p10-12)
        (d4 p11-12 p12-12)
        (d0 p12-12 p11-11)
        (d1 p12-12 p12-11)
        (d3 p12-12 p11-12)

        (corner-ul p1-1)
        (edge-n p2-1)
        (edge-n p3-1)
        (edge-n p4-1)
        (edge-n p5-1)
        (edge-n p6-1)
        (edge-n p7-1)
        (edge-n p8-1)
        (edge-n p9-1)
        (edge-n p10-1)
        (edge-n p11-1)
        (corner-ur p12-1)
        (edge-w p1-2)
        (middle p2-2)
        (middle p3-2)
        (middle p4-2)
        (middle p5-2)
        (middle p6-2)
        (middle p7-2)
        (middle p8-2)
        (middle p9-2)
        (middle p10-2)
        (middle p11-2)
        (edge-e p12-2)
        (edge-w p1-3)
        (middle p2-3)
        (middle p3-3)
        (middle p4-3)
        (middle p5-3)
        (middle p6-3)
        (middle p7-3)
        (middle p8-3)
        (middle p9-3)
        (middle p10-3)
        (middle p11-3)
        (edge-e p12-3)
        (edge-w p1-4)
        (middle p2-4)
        (middle p3-4)
        (middle p4-4)
        (middle p5-4)
        (middle p6-4)
        (middle p7-4)
        (middle p8-4)
        (middle p9-4)
        (middle p10-4)
        (middle p11-4)
        (edge-e p12-4)
        (edge-w p1-5)
        (middle p2-5)
        (middle p3-5)
        (middle p4-5)
        (middle p5-5)
        (middle p6-5)
        (middle p7-5)
        (middle p8-5)
        (middle p9-5)
        (middle p10-5)
        (middle p11-5)
        (edge-e p12-5)
        (edge-w p1-6)
        (middle p2-6)
        (middle p3-6)
        (middle p4-6)
        (middle p5-6)
        (middle p6-6)
        (middle p7-6)
        (middle p8-6)
        (middle p9-6)
        (middle p10-6)
        (middle p11-6)
        (edge-e p12-6)
        (edge-w p1-7)
        (middle p2-7)
        (middle p3-7)
        (middle p4-7)
        (middle p5-7)
        (middle p6-7)
        (middle p7-7)
        (middle p8-7)
        (middle p9-7)
        (middle p10-7)
        (middle p11-7)
        (edge-e p12-7)
        (edge-w p1-8)
        (middle p2-8)
        (middle p3-8)
        (middle p4-8)
        (middle p5-8)
        (middle p6-8)
        (middle p7-8)
        (middle p8-8)
        (middle p9-8)
        (middle p10-8)
        (middle p11-8)
        (edge-e p12-8)
        (edge-w p1-9)
        (middle p2-9)
        (middle p3-9)
        (middle p4-9)
        (middle p5-9)
        (middle p6-9)
        (middle p7-9)
        (middle p8-9)
        (middle p9-9)
        (middle p10-9)
        (middle p11-9)
        (edge-e p12-9)
        (edge-w p1-10)
        (middle p2-10)
        (middle p3-10)
        (middle p4-10)
        (middle p5-10)
        (middle p6-10)
        (middle p7-10)
        (middle p8-10)
        (middle p9-10)
        (middle p10-10)
        (middle p11-10)
        (edge-e p12-10)
        (edge-w p1-11)
        (middle p2-11)
        (middle p3-11)
        (middle p4-11)
        (middle p5-11)
        (middle p6-11)
        (middle p7-11)
        (middle p8-11)
        (middle p9-11)
        (middle p10-11)
        (middle p11-11)
        (edge-e p12-11)
        (corner-ll p1-12)
        (edge-s p2-12)
        (edge-s p3-12)
        (edge-s p4-12)
        (edge-s p5-12)
        (edge-s p6-12)
        (edge-s p7-12)
        (edge-s p8-12)
        (edge-s p9-12)
        (edge-s p10-12)
        (edge-s p11-12)
        (corner-lr p12-12)

        (not (done-with p1-1))
        (not (done-with p2-1))
        (not (done-with p3-1))
        (not (done-with p4-1))
        (not (done-with p5-1))
        (not (done-with p6-1))
        (not (done-with p7-1))
        (not (done-with p8-1))
        (not (done-with p9-1))
        (not (done-with p10-1))
        (not (done-with p11-1))
        (not (done-with p12-1))
        (not (done-with p1-2))
        (not (done-with p2-2))
        (not (done-with p3-2))
        (not (done-with p4-2))
        (not (done-with p5-2))
        (not (done-with p6-2))
        (not (done-with p7-2))
        (not (done-with p8-2))
        (not (done-with p9-2))
        (not (done-with p10-2))
        (not (done-with p11-2))
        (not (done-with p12-2))
        (not (done-with p1-3))
        (not (done-with p2-3))
        (not (done-with p3-3))
        (not (done-with p4-3))
        (not (done-with p5-3))
        (not (done-with p6-3))
        (not (done-with p7-3))
        (not (done-with p8-3))
        (not (done-with p9-3))
        (not (done-with p10-3))
        (not (done-with p11-3))
        (not (done-with p12-3))
        (not (done-with p1-4))
        (not (done-with p2-4))
        (not (done-with p3-4))
        (not (done-with p4-4))
        (not (done-with p5-4))
        (not (done-with p6-4))
        (not (done-with p7-4))
        (not (done-with p8-4))
        (not (done-with p9-4))
        (not (done-with p10-4))
        (not (done-with p11-4))
        (not (done-with p12-4))
        (not (done-with p1-5))
        (not (done-with p2-5))
        (not (done-with p3-5))
        (not (done-with p4-5))
        (not (done-with p5-5))
        (not (done-with p6-5))
        (not (done-with p7-5))
        (not (done-with p8-5))
        (not (done-with p9-5))
        (not (done-with p10-5))
        (not (done-with p11-5))
        (not (done-with p12-5))
        (not (done-with p1-6))
        (not (done-with p2-6))
        (not (done-with p3-6))
        (not (done-with p4-6))
        (not (done-with p5-6))
        (not (done-with p6-6))
        (not (done-with p7-6))
        (not (done-with p8-6))
        (not (done-with p9-6))
        (not (done-with p10-6))
        (not (done-with p11-6))
        (not (done-with p12-6))
        (not (done-with p1-7))
        (not (done-with p2-7))
        (not (done-with p3-7))
        (not (done-with p4-7))
        (not (done-with p5-7))
        (not (done-with p6-7))
        (not (done-with p7-7))
        (not (done-with p8-7))
        (not (done-with p9-7))
        (not (done-with p10-7))
        (not (done-with p11-7))
        (not (done-with p12-7))
        (not (done-with p1-8))
        (not (done-with p2-8))
        (not (done-with p3-8))
        (not (done-with p4-8))
        (not (done-with p5-8))
        (not (done-with p6-8))
        (not (done-with p7-8))
        (not (done-with p8-8))
        (not (done-with p9-8))
        (not (done-with p10-8))
        (not (done-with p11-8))
        (not (done-with p12-8))
        (not (done-with p1-9))
        (not (done-with p2-9))
        (not (done-with p3-9))
        (not (done-with p4-9))
        (not (done-with p5-9))
        (not (done-with p6-9))
        (not (done-with p7-9))
        (not (done-with p8-9))
        (not (done-with p9-9))
        (not (done-with p10-9))
        (not (done-with p11-9))
        (not (done-with p12-9))
        (not (done-with p1-10))
        (not (done-with p2-10))
        (not (done-with p3-10))
        (not (done-with p4-10))
        (not (done-with p5-10))
        (not (done-with p6-10))
        (not (done-with p7-10))
        (not (done-with p8-10))
        (not (done-with p9-10))
        (not (done-with p10-10))
        (not (done-with p11-10))
        (not (done-with p12-10))
        (not (done-with p1-11))
        (not (done-with p2-11))
        (not (done-with p3-11))
        (not (done-with p4-11))
        (not (done-with p5-11))
        (not (done-with p6-11))
        (not (done-with p7-11))
        (not (done-with p8-11))
        (not (done-with p9-11))
        (not (done-with p10-11))
        (not (done-with p11-11))
        (not (done-with p12-11))
        (not (done-with p1-12))
        (not (done-with p2-12))
        (not (done-with p3-12))
        (not (done-with p4-12))
        (not (done-with p5-12))
        (not (done-with p6-12))
        (not (done-with p7-12))
        (not (done-with p8-12))
        (not (done-with p9-12))
        (not (done-with p10-12))
        (not (done-with p11-12))
        (not (done-with p12-12))
    )
    (:goal (and (done-with p1-1) (done-with p2-1) (done-with p3-1) (done-with p4-1) (done-with p5-1) (done-with p6-1) (done-with p7-1) (done-with p8-1) (done-with p9-1) (done-with p10-1) (done-with p11-1) (done-with p12-1) (done-with p1-2) (done-with p2-2) (done-with p3-2) (done-with p4-2) (done-with p5-2) (done-with p6-2) (done-with p7-2) (done-with p8-2) (done-with p9-2) (done-with p10-2) (done-with p11-2) (done-with p12-2) (done-with p1-3) (done-with p2-3) (done-with p3-3) (done-with p4-3) (done-with p5-3) (done-with p6-3) (done-with p7-3) (done-with p8-3) (done-with p9-3) (done-with p10-3) (done-with p11-3) (done-with p12-3) (done-with p1-4) (done-with p2-4) (done-with p3-4) (done-with p4-4) (done-with p5-4) (done-with p6-4) (done-with p7-4) (done-with p8-4) (done-with p9-4) (done-with p10-4) (done-with p11-4) (done-with p12-4) (done-with p1-5) (done-with p2-5) (done-with p3-5) (done-with p4-5) (done-with p5-5) (done-with p6-5) (done-with p7-5) (done-with p8-5) (done-with p9-5) (done-with p10-5) (done-with p11-5) (done-with p12-5) (done-with p1-6) (done-with p2-6) (done-with p3-6) (done-with p4-6) (done-with p5-6) (done-with p6-6) (done-with p7-6) (done-with p8-6) (done-with p9-6) (done-with p10-6) (done-with p11-6) (done-with p12-6) (done-with p1-7) (done-with p2-7) (done-with p3-7) (done-with p4-7) (done-with p5-7) (done-with p6-7) (done-with p7-7) (done-with p8-7) (done-with p9-7) (done-with p10-7) (done-with p11-7) (done-with p12-7) (done-with p1-8) (done-with p2-8) (done-with p3-8) (done-with p4-8) (done-with p5-8) (done-with p6-8) (done-with p7-8) (done-with p8-8) (done-with p9-8) (done-with p10-8) (done-with p11-8) (done-with p12-8) (done-with p1-9) (done-with p2-9) (done-with p3-9) (done-with p4-9) (done-with p5-9) (done-with p6-9) (done-with p7-9) (done-with p8-9) (done-with p9-9) (done-with p10-9) (done-with p11-9) (done-with p12-9) (done-with p1-10) (done-with p2-10) (done-with p3-10) (done-with p4-10) (done-with p5-10) (done-with p6-10) (done-with p7-10) (done-with p8-10) (done-with p9-10) (done-with p10-10) (done-with p11-10) (done-with p12-10) (done-with p1-11) (done-with p2-11) (done-with p3-11) (done-with p4-11) (done-with p5-11) (done-with p6-11) (done-with p7-11) (done-with p8-11) (done-with p9-11) (done-with p10-11) (done-with p11-11) (done-with p12-11) (done-with p1-12) (done-with p2-12) (done-with p3-12) (done-with p4-12) (done-with p5-12) (done-with p6-12) (done-with p7-12) (done-with p8-12) (done-with p9-12) (done-with p10-12) (done-with p11-12) (done-with p12-12)))
)

