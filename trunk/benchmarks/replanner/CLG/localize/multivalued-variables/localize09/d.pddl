(define (domain sliding-doors) 
    (:requirements :strips :typing :translation)
    (:types pos)
    (:predicates (need-start) (at ?i) (free-up) (free-down) (free-left) (free-right))
    (:constants
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

    (:variable position (forall (?p - pos) (at ?p)))
    (:obs-variable su (free-up))
    (:obs-variable sr (free-right))
    (:obs-variable sd (free-down))
    (:obs-variable sl (free-left))

    (:default-sensing-model
        (and (when (at p2-1) (and (free-left) (free-right) (not (free-up)) (not (free-down))))
             (when (at p3-1) (and (free-left) (free-right) (not (free-up)) (not (free-down))))
             (when (at p4-1) (and (free-left) (free-right) (not (free-up)) (not (free-down))))
             (when (at p5-1) (and (free-left) (free-right) (not (free-up)) (not (free-down))))
             (when (at p6-1) (and (free-left) (free-right) (not (free-up)) (not (free-down))))
             (when (at p7-1) (and (free-left) (free-right) (not (free-up)) (not (free-down))))
             (when (at p8-1) (and (free-left) (free-right) (not (free-up)) (not (free-down))))
             (when (at p2-3) (and (free-left) (free-right) (not (free-up)) (not (free-down))))
             (when (at p3-3) (and (free-left) (free-right) (not (free-up)) (not (free-down))))
             (when (at p4-3) (and (free-left) (free-right) (not (free-up)) (not (free-down))))
             (when (at p5-3) (and (free-left) (free-right) (not (free-up)) (not (free-down))))
             (when (at p6-3) (and (free-left) (free-right) (not (free-up)) (not (free-down))))
             (when (at p7-3) (and (free-left) (free-right) (not (free-up)) (not (free-down))))
             (when (at p8-3) (and (free-left) (free-right) (not (free-up)) (not (free-down))))
             (when (at p2-5) (and (free-left) (free-right) (not (free-up)) (not (free-down))))
             (when (at p3-5) (and (free-left) (free-right) (not (free-up)) (not (free-down))))
             (when (at p4-5) (and (free-left) (free-right) (not (free-up)) (not (free-down))))
             (when (at p5-5) (and (free-left) (free-right) (not (free-up)) (not (free-down))))
             (when (at p6-5) (and (free-left) (free-right) (not (free-up)) (not (free-down))))
             (when (at p7-5) (and (free-left) (free-right) (not (free-up)) (not (free-down))))
             (when (at p8-5) (and (free-left) (free-right) (not (free-up)) (not (free-down))))
             (when (at p2-7) (and (free-left) (free-right) (not (free-up)) (not (free-down))))
             (when (at p3-7) (and (free-left) (free-right) (not (free-up)) (not (free-down))))
             (when (at p4-7) (and (free-left) (free-right) (not (free-up)) (not (free-down))))
             (when (at p5-7) (and (free-left) (free-right) (not (free-up)) (not (free-down))))
             (when (at p6-7) (and (free-left) (free-right) (not (free-up)) (not (free-down))))
             (when (at p7-7) (and (free-left) (free-right) (not (free-up)) (not (free-down))))
             (when (at p8-7) (and (free-left) (free-right) (not (free-up)) (not (free-down))))
             (when (at p2-9) (and (free-left) (free-right) (not (free-up)) (not (free-down))))
             (when (at p3-9) (and (free-left) (free-right) (not (free-up)) (not (free-down))))
             (when (at p4-9) (and (free-left) (free-right) (not (free-up)) (not (free-down))))
             (when (at p5-9) (and (free-left) (free-right) (not (free-up)) (not (free-down))))
             (when (at p6-9) (and (free-left) (free-right) (not (free-up)) (not (free-down))))
             (when (at p7-9) (and (free-left) (free-right) (not (free-up)) (not (free-down))))
             (when (at p8-9) (and (free-left) (free-right) (not (free-up)) (not (free-down))))
             (when (at p1-2) (and (free-up) (free-down) (not (free-left)) (not (free-right))))
             (when (at p9-2) (and (free-up) (free-down) (not (free-left)) (not (free-right))))
             (when (at p1-3) (and (free-up) (free-right) (free-down) (not (free-left))))
             (when (at p9-3) (and (free-up) (free-left) (free-down) (not (free-right))))
             (when (at p1-4) (and (free-up) (free-down) (not (free-left)) (not (free-right))))
             (when (at p9-4) (and (free-up) (free-down) (not (free-left)) (not (free-right))))
             (when (at p1-5) (and (free-up) (free-right) (free-down) (not (free-left))))
             (when (at p9-5) (and (free-up) (free-left) (free-down) (not (free-right))))
             (when (at p1-6) (and (free-up) (free-down) (not (free-left)) (not (free-right))))
             (when (at p9-6) (and (free-up) (free-down) (not (free-left)) (not (free-right))))
             (when (at p1-7) (and (free-up) (free-right) (free-down) (not (free-left))))
             (when (at p9-7) (and (free-up) (free-left) (free-down) (not (free-right))))
             (when (at p1-8) (and (free-up) (free-down) (not (free-left)) (not (free-right))))
             (when (at p9-8) (and (free-up) (free-down) (not (free-left)) (not (free-right))))
             (when (at p1-1) (and (free-up) (free-right) (not (free-down)) (not (free-left))))
             (when (at p9-1) (and (free-up) (free-left) (not (free-down)) (not (free-right))))
             (when (at p1-9) (and (free-down) (free-right) (not (free-up)) (not (free-left))))
             (when (at p9-9) (and (free-down) (free-left) (not (free-up)) (not (free-right))))
        )
    )

    (:action start
        :precondition (need-start)
        :effect (not (need-start))
    )
 
    (:action move-up
        :precondition (and (not (need-start)) (free-up))
        :effect
            (and
                 (when (at p1-1) (and (at p1-2) (not (at p1-1))))
                 (when (at p9-1) (and (at p9-2) (not (at p9-1))))
                 (when (at p1-2) (and (at p1-3) (not (at p1-2))))
                 (when (at p9-2) (and (at p9-3) (not (at p9-2))))
                 (when (at p1-3) (and (at p1-4) (not (at p1-3))))
                 (when (at p9-3) (and (at p9-4) (not (at p9-3))))
                 (when (at p1-4) (and (at p1-5) (not (at p1-4))))
                 (when (at p9-4) (and (at p9-5) (not (at p9-4))))
                 (when (at p1-5) (and (at p1-6) (not (at p1-5))))
                 (when (at p9-5) (and (at p9-6) (not (at p9-5))))
                 (when (at p1-6) (and (at p1-7) (not (at p1-6))))
                 (when (at p9-6) (and (at p9-7) (not (at p9-6))))
                 (when (at p1-7) (and (at p1-8) (not (at p1-7))))
                 (when (at p9-7) (and (at p9-8) (not (at p9-7))))
                 (when (at p1-8) (and (at p1-9) (not (at p1-8))))
                 (when (at p9-8) (and (at p9-9) (not (at p9-8))))
            )
    )

    (:action move-down
        ;:precondition (free-down)
        :precondition (and (not (need-start)) (free-down))
        :effect
            (and
                 (when (at p1-2) (and (at p1-1) (not (at p1-2))))
                 (when (at p9-2) (and (at p9-1) (not (at p9-2))))
                 (when (at p1-3) (and (at p1-2) (not (at p1-3))))
                 (when (at p9-3) (and (at p9-2) (not (at p9-3))))
                 (when (at p1-4) (and (at p1-3) (not (at p1-4))))
                 (when (at p9-4) (and (at p9-3) (not (at p9-4))))
                 (when (at p1-5) (and (at p1-4) (not (at p1-5))))
                 (when (at p9-5) (and (at p9-4) (not (at p9-5))))
                 (when (at p1-6) (and (at p1-5) (not (at p1-6))))
                 (when (at p9-6) (and (at p9-5) (not (at p9-6))))
                 (when (at p1-7) (and (at p1-6) (not (at p1-7))))
                 (when (at p9-7) (and (at p9-6) (not (at p9-7))))
                 (when (at p1-8) (and (at p1-7) (not (at p1-8))))
                 (when (at p9-8) (and (at p9-7) (not (at p9-8))))
                 (when (at p1-9) (and (at p1-8) (not (at p1-9))))
                 (when (at p9-9) (and (at p9-8) (not (at p9-9))))
            )
    )

    (:action move-left
        ;:precondition (free-left)
        :precondition (and (not (need-start)) (free-left))
        :effect
            (and
                 (when (at p2-1) (and (at p1-1) (not (at p2-1))))
                 (when (at p3-1) (and (at p2-1) (not (at p3-1))))
                 (when (at p4-1) (and (at p3-1) (not (at p4-1))))
                 (when (at p5-1) (and (at p4-1) (not (at p5-1))))
                 (when (at p6-1) (and (at p5-1) (not (at p6-1))))
                 (when (at p7-1) (and (at p6-1) (not (at p7-1))))
                 (when (at p8-1) (and (at p7-1) (not (at p8-1))))
                 (when (at p9-1) (and (at p8-1) (not (at p9-1))))
                 (when (at p2-3) (and (at p1-3) (not (at p2-3))))
                 (when (at p3-3) (and (at p2-3) (not (at p3-3))))
                 (when (at p4-3) (and (at p3-3) (not (at p4-3))))
                 (when (at p5-3) (and (at p4-3) (not (at p5-3))))
                 (when (at p6-3) (and (at p5-3) (not (at p6-3))))
                 (when (at p7-3) (and (at p6-3) (not (at p7-3))))
                 (when (at p8-3) (and (at p7-3) (not (at p8-3))))
                 (when (at p9-3) (and (at p8-3) (not (at p9-3))))
                 (when (at p2-5) (and (at p1-5) (not (at p2-5))))
                 (when (at p3-5) (and (at p2-5) (not (at p3-5))))
                 (when (at p4-5) (and (at p3-5) (not (at p4-5))))
                 (when (at p5-5) (and (at p4-5) (not (at p5-5))))
                 (when (at p6-5) (and (at p5-5) (not (at p6-5))))
                 (when (at p7-5) (and (at p6-5) (not (at p7-5))))
                 (when (at p8-5) (and (at p7-5) (not (at p8-5))))
                 (when (at p9-5) (and (at p8-5) (not (at p9-5))))
                 (when (at p2-7) (and (at p1-7) (not (at p2-7))))
                 (when (at p3-7) (and (at p2-7) (not (at p3-7))))
                 (when (at p4-7) (and (at p3-7) (not (at p4-7))))
                 (when (at p5-7) (and (at p4-7) (not (at p5-7))))
                 (when (at p6-7) (and (at p5-7) (not (at p6-7))))
                 (when (at p7-7) (and (at p6-7) (not (at p7-7))))
                 (when (at p8-7) (and (at p7-7) (not (at p8-7))))
                 (when (at p9-7) (and (at p8-7) (not (at p9-7))))
                 (when (at p2-9) (and (at p1-9) (not (at p2-9))))
                 (when (at p3-9) (and (at p2-9) (not (at p3-9))))
                 (when (at p4-9) (and (at p3-9) (not (at p4-9))))
                 (when (at p5-9) (and (at p4-9) (not (at p5-9))))
                 (when (at p6-9) (and (at p5-9) (not (at p6-9))))
                 (when (at p7-9) (and (at p6-9) (not (at p7-9))))
                 (when (at p8-9) (and (at p7-9) (not (at p8-9))))
                 (when (at p9-9) (and (at p8-9) (not (at p9-9))))
            )
    )

    (:action move-right
        ;:precondition (free-right)
        :precondition (and (not (need-start)) (free-right))
        :effect
            (and
                 (when (at p1-1) (and (at p2-1) (not (at p1-1))))
                 (when (at p2-1) (and (at p3-1) (not (at p2-1))))
                 (when (at p3-1) (and (at p4-1) (not (at p3-1))))
                 (when (at p4-1) (and (at p5-1) (not (at p4-1))))
                 (when (at p5-1) (and (at p6-1) (not (at p5-1))))
                 (when (at p6-1) (and (at p7-1) (not (at p6-1))))
                 (when (at p7-1) (and (at p8-1) (not (at p7-1))))
                 (when (at p8-1) (and (at p9-1) (not (at p8-1))))
                 (when (at p1-3) (and (at p2-3) (not (at p1-3))))
                 (when (at p2-3) (and (at p3-3) (not (at p2-3))))
                 (when (at p3-3) (and (at p4-3) (not (at p3-3))))
                 (when (at p4-3) (and (at p5-3) (not (at p4-3))))
                 (when (at p5-3) (and (at p6-3) (not (at p5-3))))
                 (when (at p6-3) (and (at p7-3) (not (at p6-3))))
                 (when (at p7-3) (and (at p8-3) (not (at p7-3))))
                 (when (at p8-3) (and (at p9-3) (not (at p8-3))))
                 (when (at p1-5) (and (at p2-5) (not (at p1-5))))
                 (when (at p2-5) (and (at p3-5) (not (at p2-5))))
                 (when (at p3-5) (and (at p4-5) (not (at p3-5))))
                 (when (at p4-5) (and (at p5-5) (not (at p4-5))))
                 (when (at p5-5) (and (at p6-5) (not (at p5-5))))
                 (when (at p6-5) (and (at p7-5) (not (at p6-5))))
                 (when (at p7-5) (and (at p8-5) (not (at p7-5))))
                 (when (at p8-5) (and (at p9-5) (not (at p8-5))))
                 (when (at p1-7) (and (at p2-7) (not (at p1-7))))
                 (when (at p2-7) (and (at p3-7) (not (at p2-7))))
                 (when (at p3-7) (and (at p4-7) (not (at p3-7))))
                 (when (at p4-7) (and (at p5-7) (not (at p4-7))))
                 (when (at p5-7) (and (at p6-7) (not (at p5-7))))
                 (when (at p6-7) (and (at p7-7) (not (at p6-7))))
                 (when (at p7-7) (and (at p8-7) (not (at p7-7))))
                 (when (at p8-7) (and (at p9-7) (not (at p8-7))))
                 (when (at p1-9) (and (at p2-9) (not (at p1-9))))
                 (when (at p2-9) (and (at p3-9) (not (at p2-9))))
                 (when (at p3-9) (and (at p4-9) (not (at p3-9))))
                 (when (at p4-9) (and (at p5-9) (not (at p4-9))))
                 (when (at p5-9) (and (at p6-9) (not (at p5-9))))
                 (when (at p6-9) (and (at p7-9) (not (at p6-9))))
                 (when (at p7-9) (and (at p8-9) (not (at p7-9))))
                 (when (at p8-9) (and (at p9-9) (not (at p8-9))))
            )
    )
)

