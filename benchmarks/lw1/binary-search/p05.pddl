(define (problem bs-p5)
    (:domain binary-search)
    (:objects p0 p1 p2 p3 p4 - state)
    (:init
        (discover-not-yet-attempted)
        (lt p0 p1) (lt p0 p2) (lt p0 p3) (lt p0 p4)
        (lt p1 p2) (lt p1 p3) (lt p1 p4)
        (lt p2 p3) (lt p2 p4)
        (lt p3 p4)
    )
    (:goal (finish))
)

