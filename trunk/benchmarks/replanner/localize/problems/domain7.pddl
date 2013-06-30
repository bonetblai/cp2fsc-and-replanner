(define (domain localize-7)
    (:requirements :strips :typing)
    (:types pos)
    (:predicates (ok) (at ?p - pos) (free-up) (free-down) (free-left) (free-right))
    (:constants p1-1 p1-2 p1-3 p1-4 p1-5 p1-6 p1-7 p2-1 p2-2 p2-3 p2-4 p2-5 p2-6 p2-7 p3-1 p3-2 p3-3 p3-4 p3-5 p3-6 p3-7 p4-1 p4-2 p4-3 p4-4 p4-5 p4-6 p4-7 p5-1 p5-2 p5-3 p5-4 p5-5 p5-6 p5-7 p6-1 p6-2 p6-3 p6-4 p6-5 p6-6 p6-7 p7-1 p7-2 p7-3 p7-4 p7-5 p7-6 p7-7 - pos)

    (:action move-up
        :precondition (and (ok) (free-up))
        :effect
            (and (not (ok)) (not (free-up)) (not (free-right)) (not (free-down)) (not (free-left))
                 (when (at p1-1) (and (at p1-2) (not (at p1-1))))
                 (when (at p1-2) (and (at p1-3) (not (at p1-2))))
                 (when (at p1-3) (and (at p1-4) (not (at p1-3))))
                 (when (at p1-4) (and (at p1-5) (not (at p1-4))))
                 (when (at p1-5) (and (at p1-6) (not (at p1-5))))
                 (when (at p1-6) (and (at p1-7) (not (at p1-6))))
                 (when (at p7-1) (and (at p7-2) (not (at p7-1))))
                 (when (at p7-2) (and (at p7-3) (not (at p7-2))))
                 (when (at p7-3) (and (at p7-4) (not (at p7-3))))
                 (when (at p7-4) (and (at p7-5) (not (at p7-4))))
                 (when (at p7-5) (and (at p7-6) (not (at p7-5))))
                 (when (at p7-6) (and (at p7-7) (not (at p7-6))))
                 (not (at p1-1))
                 (when (and (not (at p1-1))) (not (at p1-2)))
                 (when (and (not (at p1-1)) (not (at p1-2))) (not (at p1-3)))
                 (when (and (not (at p1-1)) (not (at p1-2)) (not (at p1-3))) (not (at p1-4)))
                 (when (and (not (at p1-1)) (not (at p1-2)) (not (at p1-3)) (not (at p1-4))) (not (at p1-5)))
                 (when (and (not (at p1-1)) (not (at p1-2)) (not (at p1-3)) (not (at p1-4)) (not (at p1-5))) (not (at p1-6)))
                 (not (at p2-1))
                 (not (at p3-1))
                 (not (at p4-1))
                 (not (at p5-1))
                 (not (at p6-1))
                 (not (at p7-1))
                 (when (and (not (at p7-1))) (not (at p7-2)))
                 (when (and (not (at p7-1)) (not (at p7-2))) (not (at p7-3)))
                 (when (and (not (at p7-1)) (not (at p7-2)) (not (at p7-3))) (not (at p7-4)))
                 (when (and (not (at p7-1)) (not (at p7-2)) (not (at p7-3)) (not (at p7-4))) (not (at p7-5)))
                 (when (and (not (at p7-1)) (not (at p7-2)) (not (at p7-3)) (not (at p7-4)) (not (at p7-5))) (not (at p7-6)))
            )
    )

    (:action move-right
        :precondition (and (ok) (free-right))
        :effect
            (and (not (ok)) (not (free-up)) (not (free-right)) (not (free-down)) (not (free-left))
                 (when (at p1-1) (and (at p2-1) (not (at p1-1))))
                 (when (at p1-3) (and (at p2-3) (not (at p1-3))))
                 (when (at p1-5) (and (at p2-5) (not (at p1-5))))
                 (when (at p1-7) (and (at p2-7) (not (at p1-7))))
                 (when (at p2-1) (and (at p3-1) (not (at p2-1))))
                 (when (at p2-3) (and (at p3-3) (not (at p2-3))))
                 (when (at p2-5) (and (at p3-5) (not (at p2-5))))
                 (when (at p2-7) (and (at p3-7) (not (at p2-7))))
                 (when (at p3-1) (and (at p4-1) (not (at p3-1))))
                 (when (at p3-3) (and (at p4-3) (not (at p3-3))))
                 (when (at p3-5) (and (at p4-5) (not (at p3-5))))
                 (when (at p3-7) (and (at p4-7) (not (at p3-7))))
                 (when (at p4-1) (and (at p5-1) (not (at p4-1))))
                 (when (at p4-3) (and (at p5-3) (not (at p4-3))))
                 (when (at p4-5) (and (at p5-5) (not (at p4-5))))
                 (when (at p4-7) (and (at p5-7) (not (at p4-7))))
                 (when (at p5-1) (and (at p6-1) (not (at p5-1))))
                 (when (at p5-3) (and (at p6-3) (not (at p5-3))))
                 (when (at p5-5) (and (at p6-5) (not (at p5-5))))
                 (when (at p5-7) (and (at p6-7) (not (at p5-7))))
                 (when (at p6-1) (and (at p7-1) (not (at p6-1))))
                 (when (at p6-3) (and (at p7-3) (not (at p6-3))))
                 (when (at p6-5) (and (at p7-5) (not (at p6-5))))
                 (when (at p6-7) (and (at p7-7) (not (at p6-7))))
                 (not (at p1-1))
                 (not (at p1-2))
                 (not (at p1-3))
                 (not (at p1-4))
                 (not (at p1-5))
                 (not (at p1-6))
                 (not (at p1-7))
                 (when (and (not (at p1-1))) (not (at p2-1)))
                 (when (and (not (at p1-3))) (not (at p2-3)))
                 (when (and (not (at p1-5))) (not (at p2-5)))
                 (when (and (not (at p1-7))) (not (at p2-7)))
                 (when (and (not (at p1-1)) (not (at p2-1))) (not (at p3-1)))
                 (when (and (not (at p1-3)) (not (at p2-3))) (not (at p3-3)))
                 (when (and (not (at p1-5)) (not (at p2-5))) (not (at p3-5)))
                 (when (and (not (at p1-7)) (not (at p2-7))) (not (at p3-7)))
                 (when (and (not (at p1-1)) (not (at p2-1)) (not (at p3-1))) (not (at p4-1)))
                 (when (and (not (at p1-3)) (not (at p2-3)) (not (at p3-3))) (not (at p4-3)))
                 (when (and (not (at p1-5)) (not (at p2-5)) (not (at p3-5))) (not (at p4-5)))
                 (when (and (not (at p1-7)) (not (at p2-7)) (not (at p3-7))) (not (at p4-7)))
                 (when (and (not (at p1-1)) (not (at p2-1)) (not (at p3-1)) (not (at p4-1))) (not (at p5-1)))
                 (when (and (not (at p1-3)) (not (at p2-3)) (not (at p3-3)) (not (at p4-3))) (not (at p5-3)))
                 (when (and (not (at p1-5)) (not (at p2-5)) (not (at p3-5)) (not (at p4-5))) (not (at p5-5)))
                 (when (and (not (at p1-7)) (not (at p2-7)) (not (at p3-7)) (not (at p4-7))) (not (at p5-7)))
                 (when (and (not (at p1-1)) (not (at p2-1)) (not (at p3-1)) (not (at p4-1)) (not (at p5-1))) (not (at p6-1)))
                 (when (and (not (at p1-3)) (not (at p2-3)) (not (at p3-3)) (not (at p4-3)) (not (at p5-3))) (not (at p6-3)))
                 (when (and (not (at p1-5)) (not (at p2-5)) (not (at p3-5)) (not (at p4-5)) (not (at p5-5))) (not (at p6-5)))
                 (when (and (not (at p1-7)) (not (at p2-7)) (not (at p3-7)) (not (at p4-7)) (not (at p5-7))) (not (at p6-7)))
            )
    )

    (:action move-down
        :precondition (and (ok) (free-down))
        :effect
            (and (not (ok)) (not (free-up)) (not (free-right)) (not (free-down)) (not (free-left))
                 (when (at p1-2) (and (at p1-1) (not (at p1-2))))
                 (when (at p1-3) (and (at p1-2) (not (at p1-3))))
                 (when (at p1-4) (and (at p1-3) (not (at p1-4))))
                 (when (at p1-5) (and (at p1-4) (not (at p1-5))))
                 (when (at p1-6) (and (at p1-5) (not (at p1-6))))
                 (when (at p1-7) (and (at p1-6) (not (at p1-7))))
                 (when (at p7-2) (and (at p7-1) (not (at p7-2))))
                 (when (at p7-3) (and (at p7-2) (not (at p7-3))))
                 (when (at p7-4) (and (at p7-3) (not (at p7-4))))
                 (when (at p7-5) (and (at p7-4) (not (at p7-5))))
                 (when (at p7-6) (and (at p7-5) (not (at p7-6))))
                 (when (at p7-7) (and (at p7-6) (not (at p7-7))))
                 (when (and (not (at p1-7)) (not (at p1-6)) (not (at p1-5)) (not (at p1-4)) (not (at p1-3))) (not (at p1-2)))
                 (when (and (not (at p1-7)) (not (at p1-6)) (not (at p1-5)) (not (at p1-4))) (not (at p1-3)))
                 (when (and (not (at p1-7)) (not (at p1-6)) (not (at p1-5))) (not (at p1-4)))
                 (when (and (not (at p1-7)) (not (at p1-6))) (not (at p1-5)))
                 (when (and (not (at p1-7))) (not (at p1-6)))
                 (not (at p1-7))
                 (not (at p2-7))
                 (not (at p3-7))
                 (not (at p4-7))
                 (not (at p5-7))
                 (not (at p6-7))
                 (when (and (not (at p7-7)) (not (at p7-6)) (not (at p7-5)) (not (at p7-4)) (not (at p7-3))) (not (at p7-2)))
                 (when (and (not (at p7-7)) (not (at p7-6)) (not (at p7-5)) (not (at p7-4))) (not (at p7-3)))
                 (when (and (not (at p7-7)) (not (at p7-6)) (not (at p7-5))) (not (at p7-4)))
                 (when (and (not (at p7-7)) (not (at p7-6))) (not (at p7-5)))
                 (when (and (not (at p7-7))) (not (at p7-6)))
                 (not (at p7-7))
            )
    )

    (:action move-left
        :precondition (and (ok) (free-left))
        :effect
            (and (not (ok)) (not (free-up)) (not (free-right)) (not (free-down)) (not (free-left))
                 (when (at p2-1) (and (at p1-1) (not (at p2-1))))
                 (when (at p2-3) (and (at p1-3) (not (at p2-3))))
                 (when (at p2-5) (and (at p1-5) (not (at p2-5))))
                 (when (at p2-7) (and (at p1-7) (not (at p2-7))))
                 (when (at p3-1) (and (at p2-1) (not (at p3-1))))
                 (when (at p3-3) (and (at p2-3) (not (at p3-3))))
                 (when (at p3-5) (and (at p2-5) (not (at p3-5))))
                 (when (at p3-7) (and (at p2-7) (not (at p3-7))))
                 (when (at p4-1) (and (at p3-1) (not (at p4-1))))
                 (when (at p4-3) (and (at p3-3) (not (at p4-3))))
                 (when (at p4-5) (and (at p3-5) (not (at p4-5))))
                 (when (at p4-7) (and (at p3-7) (not (at p4-7))))
                 (when (at p5-1) (and (at p4-1) (not (at p5-1))))
                 (when (at p5-3) (and (at p4-3) (not (at p5-3))))
                 (when (at p5-5) (and (at p4-5) (not (at p5-5))))
                 (when (at p5-7) (and (at p4-7) (not (at p5-7))))
                 (when (at p6-1) (and (at p5-1) (not (at p6-1))))
                 (when (at p6-3) (and (at p5-3) (not (at p6-3))))
                 (when (at p6-5) (and (at p5-5) (not (at p6-5))))
                 (when (at p6-7) (and (at p5-7) (not (at p6-7))))
                 (when (at p7-1) (and (at p6-1) (not (at p7-1))))
                 (when (at p7-3) (and (at p6-3) (not (at p7-3))))
                 (when (at p7-5) (and (at p6-5) (not (at p7-5))))
                 (when (at p7-7) (and (at p6-7) (not (at p7-7))))
                 (when (and (not (at p7-1)) (not (at p6-1)) (not (at p5-1)) (not (at p4-1)) (not (at p3-1))) (not (at p2-1)))
                 (when (and (not (at p7-3)) (not (at p6-3)) (not (at p5-3)) (not (at p4-3)) (not (at p3-3))) (not (at p2-3)))
                 (when (and (not (at p7-5)) (not (at p6-5)) (not (at p5-5)) (not (at p4-5)) (not (at p3-5))) (not (at p2-5)))
                 (when (and (not (at p7-7)) (not (at p6-7)) (not (at p5-7)) (not (at p4-7)) (not (at p3-7))) (not (at p2-7)))
                 (when (and (not (at p7-1)) (not (at p6-1)) (not (at p5-1)) (not (at p4-1))) (not (at p3-1)))
                 (when (and (not (at p7-3)) (not (at p6-3)) (not (at p5-3)) (not (at p4-3))) (not (at p3-3)))
                 (when (and (not (at p7-5)) (not (at p6-5)) (not (at p5-5)) (not (at p4-5))) (not (at p3-5)))
                 (when (and (not (at p7-7)) (not (at p6-7)) (not (at p5-7)) (not (at p4-7))) (not (at p3-7)))
                 (when (and (not (at p7-1)) (not (at p6-1)) (not (at p5-1))) (not (at p4-1)))
                 (when (and (not (at p7-3)) (not (at p6-3)) (not (at p5-3))) (not (at p4-3)))
                 (when (and (not (at p7-5)) (not (at p6-5)) (not (at p5-5))) (not (at p4-5)))
                 (when (and (not (at p7-7)) (not (at p6-7)) (not (at p5-7))) (not (at p4-7)))
                 (when (and (not (at p7-1)) (not (at p6-1))) (not (at p5-1)))
                 (when (and (not (at p7-3)) (not (at p6-3))) (not (at p5-3)))
                 (when (and (not (at p7-5)) (not (at p6-5))) (not (at p5-5)))
                 (when (and (not (at p7-7)) (not (at p6-7))) (not (at p5-7)))
                 (when (and (not (at p7-1))) (not (at p6-1)))
                 (when (and (not (at p7-3))) (not (at p6-3)))
                 (when (and (not (at p7-5))) (not (at p6-5)))
                 (when (and (not (at p7-7))) (not (at p6-7)))
                 (not (at p7-1))
                 (not (at p7-2))
                 (not (at p7-3))
                 (not (at p7-4))
                 (not (at p7-5))
                 (not (at p7-6))
                 (not (at p7-7))
            )
    )

    (:action checking
        :precondition (not (ok))
        :effect
            (and (ok)
                 (when (at p1-1) (and (free-up) (free-right) (not (free-down)) (not (free-left))))
                 (when (at p1-2) (and (free-up) (not (free-right)) (free-down) (not (free-left))))
                 (when (at p1-3) (and (free-up) (free-right) (free-down) (not (free-left))))
                 (when (at p1-4) (and (free-up) (not (free-right)) (free-down) (not (free-left))))
                 (when (at p1-5) (and (free-up) (free-right) (free-down) (not (free-left))))
                 (when (at p1-6) (and (free-up) (not (free-right)) (free-down) (not (free-left))))
                 (when (at p1-7) (and (not (free-up)) (free-right) (free-down) (not (free-left))))
                 (when (at p2-1) (and (not (free-up)) (free-right) (not (free-down)) (free-left)))
                 (when (at p2-3) (and (not (free-up)) (free-right) (not (free-down)) (free-left)))
                 (when (at p2-5) (and (not (free-up)) (free-right) (not (free-down)) (free-left)))
                 (when (at p2-7) (and (not (free-up)) (free-right) (not (free-down)) (free-left)))
                 (when (at p3-1) (and (not (free-up)) (free-right) (not (free-down)) (free-left)))
                 (when (at p3-3) (and (not (free-up)) (free-right) (not (free-down)) (free-left)))
                 (when (at p3-5) (and (not (free-up)) (free-right) (not (free-down)) (free-left)))
                 (when (at p3-7) (and (not (free-up)) (free-right) (not (free-down)) (free-left)))
                 (when (at p4-1) (and (not (free-up)) (free-right) (not (free-down)) (free-left)))
                 (when (at p4-3) (and (not (free-up)) (free-right) (not (free-down)) (free-left)))
                 (when (at p4-5) (and (not (free-up)) (free-right) (not (free-down)) (free-left)))
                 (when (at p4-7) (and (not (free-up)) (free-right) (not (free-down)) (free-left)))
                 (when (at p5-1) (and (not (free-up)) (free-right) (not (free-down)) (free-left)))
                 (when (at p5-3) (and (not (free-up)) (free-right) (not (free-down)) (free-left)))
                 (when (at p5-5) (and (not (free-up)) (free-right) (not (free-down)) (free-left)))
                 (when (at p5-7) (and (not (free-up)) (free-right) (not (free-down)) (free-left)))
                 (when (at p6-1) (and (not (free-up)) (free-right) (not (free-down)) (free-left)))
                 (when (at p6-3) (and (not (free-up)) (free-right) (not (free-down)) (free-left)))
                 (when (at p6-5) (and (not (free-up)) (free-right) (not (free-down)) (free-left)))
                 (when (at p6-7) (and (not (free-up)) (free-right) (not (free-down)) (free-left)))
                 (when (at p7-1) (and (free-up) (not (free-right)) (not (free-down)) (free-left)))
                 (when (at p7-2) (and (free-up) (not (free-right)) (free-down) (not (free-left))))
                 (when (at p7-3) (and (free-up) (not (free-right)) (free-down) (free-left)))
                 (when (at p7-4) (and (free-up) (not (free-right)) (free-down) (not (free-left))))
                 (when (at p7-5) (and (free-up) (not (free-right)) (free-down) (free-left)))
                 (when (at p7-6) (and (free-up) (not (free-right)) (free-down) (not (free-left))))
                 (when (at p7-7) (and (not (free-up)) (not (free-right)) (free-down) (free-left)))
            )
    )

    (:sensor sense
        :sensed (free-up) (free-right) (free-down) (free-left)
    )
)

