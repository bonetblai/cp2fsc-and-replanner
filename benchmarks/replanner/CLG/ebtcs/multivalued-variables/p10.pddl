(define (problem btcs-10-1)
    (:domain btcs)
    (:objects 
        b0 - bomb
        p0 p1 p2 p3 p4 p5 p6 p7 p8 p9 - package
        t0 - toilet
    )
    (:init (not (clogged t0)))
    (:hidden (in p0 b0))
    (:hidden (in p1 b0))
    (:hidden (in p2 b0))
    (:hidden (in p3 b0))
    (:hidden (in p4 b0))
    (:hidden (in p5 b0))
    (:hidden (in p6 b0))
    (:hidden (in p7 b0))
    (:hidden (in p8 b0))
    (:hidden (in p9 b0))
    (:goal (defused b0))
)

