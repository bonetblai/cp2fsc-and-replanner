(define (problem p01)
    (:domain rocksample)
    (:objects p1 p2 p3 p4 p5 - pos r1 r2 - rock)
    (:init
        (suc p1 p2) (suc p2 p3) (suc p3 p4) (suc p4 p5)
        (at p1 p1)
        (rock-pos r1 p2 p3)
        (rock-pos r2 p1 p4)
        (invariant (good r1) (not (good r1)))
        (invariant (good r2) (not (good r2)))

        (no-sensing)
        (no-need-calibration)

        (nearby p1 p1) (nearby p2 p2) (nearby p3 p3) (nearby p4 p4) (nearby p5 p5)
        (nearby p1 p2) (nearby p1 p3) (nearby p1 p4)

        ;(invariant (nearby p1 p2) (not (nearby p1 p2)))
        ;(invariant (nearby p1 p3) (not (nearby p1 p3)))
        ;(invariant (nearby p1 p4) (not (nearby p1 p4)))
        (invariant (nearby p1 p5) (not (nearby p1 p5)))

        (invariant (nearby p2 p1) (not (nearby p2 p1)))
        (invariant (nearby p2 p3) (not (nearby p2 p3)))
        (invariant (nearby p2 p4) (not (nearby p2 p4)))
        (invariant (nearby p2 p5) (not (nearby p2 p5)))

        (invariant (nearby p3 p1) (not (nearby p3 p1)))
        (invariant (nearby p3 p2) (not (nearby p3 p2)))
        (invariant (nearby p3 p4) (not (nearby p3 p4)))
        (invariant (nearby p3 p5) (not (nearby p3 p5)))

        (invariant (nearby p4 p1) (not (nearby p4 p1)))
        (invariant (nearby p4 p2) (not (nearby p4 p2)))
        (invariant (nearby p4 p3) (not (nearby p4 p3)))
        (invariant (nearby p4 p5) (not (nearby p4 p5)))

        (invariant (nearby p5 p1) (not (nearby p5 p1)))
        (invariant (nearby p5 p2) (not (nearby p5 p2)))
        (invariant (nearby p5 p3) (not (nearby p5 p3)))
        (invariant (nearby p5 p4) (not (nearby p5 p4)))
    )
    (:hidden
        (good r2)
        (nearby p1 p2) (nearby p2 p1)
        (nearby p2 p3) (nearby p3 p2)
        (nearby p3 p4) (nearby p4 p3)
        (nearby p4 p5) (nearby p5 p4)
        (nearby p1 p3) (nearby p3 p1)
        (nearby p2 p4) (nearby p4 p2)
    )
    (:goal (and (sampled r1) (sampled r2)))
)

