(define (problem btcs-10-1)
    (:domain btcs)
    (:objects 
        b0 - bomb
        p0 p1 p2 p3 p4 p5 p6 p7 p8 p9 - package
        t0 - toilet
    )
    (:init (not (clogged t0)))
    (:goal (defused b0))
)

