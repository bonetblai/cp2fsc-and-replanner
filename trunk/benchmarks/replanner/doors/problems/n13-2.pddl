(define (problem n13)
    (:domain colored-balls)
    (:objects p1 p2 p3 p4 p5 p6 p7 p8 p9 p10 p11 p12 p13 - pos)
    (:init
        (suc p1 p2) (suc p2 p3) (suc p3 p4) (suc p4 p5) (suc p5 p6) (suc p6 p7) (suc p7 p8) (suc p8 p9) (suc p9 p10) (suc p10 p11) (suc p11 p12) (suc p12 p13)
        (wall p2 p1) (wall p2 p2) (wall p2 p3) (wall p2 p4) (wall p2 p5) (wall p2 p6) (wall p2 p7) (wall p2 p8) (wall p2 p9) (wall p2 p10) (wall p2 p11) (wall p2 p12) (wall p2 p13)
        (wall p4 p1) (wall p4 p2) (wall p4 p3) (wall p4 p4) (wall p4 p5) (wall p4 p6) (wall p4 p7) (wall p4 p8) (wall p4 p9) (wall p4 p10) (wall p4 p11) (wall p4 p12) (wall p4 p13)
        (wall p6 p1) (wall p6 p2) (wall p6 p3) (wall p6 p4) (wall p6 p5) (wall p6 p6) (wall p6 p7) (wall p6 p8) (wall p6 p9) (wall p6 p10) (wall p6 p11) (wall p6 p12) (wall p6 p13)
        (wall p8 p1) (wall p8 p2) (wall p8 p3) (wall p8 p4) (wall p8 p5) (wall p8 p6) (wall p8 p7) (wall p8 p8) (wall p8 p9) (wall p8 p10) (wall p8 p11) (wall p8 p12) (wall p8 p13)
        (wall p10 p1) (wall p10 p2) (wall p10 p3) (wall p10 p4) (wall p10 p5) (wall p10 p6) (wall p10 p7) (wall p10 p8) (wall p10 p9) (wall p10 p10) (wall p10 p11) (wall p10 p12) (wall p10 p13)
        (wall p12 p1) (wall p12 p2) (wall p12 p3) (wall p12 p4) (wall p12 p5) (wall p12 p6) (wall p12 p7) (wall p12 p8) (wall p12 p9) (wall p12 p10) (wall p12 p11) (wall p12 p12) (wall p12 p13)
        (at p1 p7)
        (invariant (door p2 p1) (door p2 p2) (door p2 p3) (door p2 p4) (door p2 p5) (door p2 p6) (door p2 p7) (door p2 p8) (door p2 p9) (door p2 p10) (door p2 p11) (door p2 p12) (door p2 p13))
        (invariant (door p4 p1) (door p4 p2) (door p4 p3) (door p4 p4) (door p4 p5) (door p4 p6) (door p4 p7) (door p4 p8) (door p4 p9) (door p4 p10) (door p4 p11) (door p4 p12) (door p4 p13))
        (invariant (door p6 p1) (door p6 p2) (door p6 p3) (door p6 p4) (door p6 p5) (door p6 p6) (door p6 p7) (door p6 p8) (door p6 p9) (door p6 p10) (door p6 p11) (door p6 p12) (door p6 p13))
        (invariant (door p8 p1) (door p8 p2) (door p8 p3) (door p8 p4) (door p8 p5) (door p8 p6) (door p8 p7) (door p8 p8) (door p8 p9) (door p8 p10) (door p8 p11) (door p8 p12) (door p8 p13))
        (invariant (door p10 p1) (door p10 p2) (door p10 p3) (door p10 p4) (door p10 p5) (door p10 p6) (door p10 p7) (door p10 p8) (door p10 p9) (door p10 p10) (door p10 p11) (door p10 p12) (door p10 p13))
        (invariant (door p12 p1) (door p12 p2) (door p12 p3) (door p12 p4) (door p12 p5) (door p12 p6) (door p12 p7) (door p12 p8) (door p12 p9) (door p12 p10) (door p12 p11) (door p12 p12) (door p12 p13))
    )
    (:hidden (door p2 p7) (door p4 p5) (door p6 p5) (door p8 p12) (door p10 p1) (door p12 p5))
    (:goal (at p13 p7))
)
