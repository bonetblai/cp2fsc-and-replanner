(define (domain sliding-doors) 
    (:requirements :strips :typing :translation)
    (:types pos)
    (:predicates (need-start) (at ?i) (free-up) (free-down) (free-left) (free-right))
    (:constants
        p1-1 p1-2 p1-3 p1-4 p1-5
        p2-1 p2-2 p2-3 p2-4 p2-5
        p3-1 p3-2 p3-3 p3-4 p3-5
        p4-1 p4-2 p4-3 p4-4 p4-5
        p5-1 p5-2 p5-3 p5-4 p5-5 - pos
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
             (when (at p2-3) (and (free-left) (free-right) (not (free-up)) (not (free-down))))
             (when (at p3-3) (and (free-left) (free-right) (not (free-up)) (not (free-down))))
             (when (at p4-3) (and (free-left) (free-right) (not (free-up)) (not (free-down))))
             (when (at p2-5) (and (free-left) (free-right) (not (free-up)) (not (free-down))))
             (when (at p3-5) (and (free-left) (free-right) (not (free-up)) (not (free-down))))
             (when (at p4-5) (and (free-left) (free-right) (not (free-up)) (not (free-down))))
             (when (at p1-2) (and (free-up) (free-down) (not (free-left)) (not (free-right))))
             (when (at p5-2) (and (free-up) (free-down) (not (free-left)) (not (free-right))))
             (when (at p1-3) (and (free-up) (not (free-left)) (free-down) (free-right)))
             (when (at p5-3) (and (free-up) (not(free-right)) (free-down)  (free-left)))
             (when (at p1-4) (and (free-up) (free-down) (not (free-left)) (not (free-right))))
             (when (at p5-4) (and (free-up) (free-down) (not (free-left)) (not (free-right))))
             (when (at p1-1) (and (free-up) (free-right) (not (free-down)) (not (free-left))))
             (when (at p5-1) (and (free-up) (free-left) (not (free-down)) (not (free-right))))
             (when (at p1-5) (and (free-down) (free-right) (not (free-up)) (not (free-left))))
             (when (at p5-5) (and (free-down) (free-left) (not (free-up)) (not (free-right))))
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
                 (when (at p5-1) (and (at p5-2) (not (at p5-1))))
                 (when (at p1-2) (and (at p1-3) (not (at p1-2))))
                 (when (at p5-2) (and (at p5-3) (not (at p5-2))))
                 (when (at p1-3) (and (at p1-4) (not (at p1-3))))
                 (when (at p5-3) (and (at p5-4) (not (at p5-3))))
                 (when (at p1-4) (and (at p1-5) (not (at p1-4))))
                 (when (at p5-4) (and (at p5-5) (not (at p5-4))))
            )
    )

    (:action move-down
        :precondition (and (not (need-start)) (free-down))
        :effect
            (and
                 (when (at p1-2) (and (at p1-1) (not (at p1-2))))
                 (when (at p5-2) (and (at p5-1) (not (at p5-2))))
                 (when (at p1-3) (and (at p1-2) (not (at p1-3))))
                 (when (at p5-3) (and (at p5-2) (not (at p5-3))))
                 (when (at p1-4) (and (at p1-3) (not (at p1-4))))
                 (when (at p5-4) (and (at p5-3) (not (at p5-4))))
                 (when (at p1-5) (and (at p1-4) (not (at p1-5))))
                 (when (at p5-5) (and (at p5-4) (not (at p5-5))))
            )
    )

    (:action move-left
        :precondition (and (not (need-start)) (free-left))
        :effect
            (and
                 (when (at p2-1) (and (at p1-1) (not (at p2-1))))
                 (when (at p3-1) (and (at p2-1) (not (at p3-1))))
                 (when (at p4-1) (and (at p3-1) (not (at p4-1))))
                 (when (at p5-1) (and (at p4-1) (not (at p5-1))))
                 (when (at p2-3) (and (at p1-3) (not (at p2-3))))
                 (when (at p3-3) (and (at p2-3) (not (at p3-3))))
                 (when (at p4-3) (and (at p3-3) (not (at p4-3))))
                 (when (at p5-3) (and (at p4-3) (not (at p5-3))))
                 (when (at p2-5) (and (at p1-5) (not (at p2-5))))
                 (when (at p3-5) (and (at p2-5) (not (at p3-5))))
                 (when (at p4-5) (and (at p3-5) (not (at p4-5))))
                 (when (at p5-5) (and (at p4-5) (not (at p5-5))))
            )
    )

    (:action move-right
        :precondition (and (not (need-start)) (free-right))
        :effect
            (and
                 (when (at p1-1) (and (at p2-1) (not (at p1-1))))
                 (when (at p2-1) (and (at p3-1) (not (at p2-1))))
                 (when (at p3-1) (and (at p4-1) (not (at p3-1))))
                 (when (at p4-1) (and (at p5-1) (not (at p4-1))))
                 (when (at p1-3) (and (at p2-3) (not (at p1-3))))
                 (when (at p2-3) (and (at p3-3) (not (at p2-3))))
                 (when (at p3-3) (and (at p4-3) (not (at p3-3))))
                 (when (at p4-3) (and (at p5-3) (not (at p4-3))))
                 (when (at p1-5) (and (at p2-5) (not (at p1-5))))
                 (when (at p2-5) (and (at p3-5) (not (at p2-5))))
                 (when (at p3-5) (and (at p4-5) (not (at p3-5))))
                 (when (at p4-5) (and (at p5-5) (not (at p4-5))))
            )
    )
)

