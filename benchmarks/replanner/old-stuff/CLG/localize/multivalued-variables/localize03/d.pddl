(define (domain sliding-doors) 
    (:requirements :strips :typing :translation)
    (:types pos)
    (:predicates (need-start) (at ?i) (free-up) (free-down) (free-left) (free-right))
    (:constants p1-1 p1-2 p1-3 p2-1 p2-2 p2-3 p3-1 p3-2 p3-3 - pos)

    (:variable position (forall (?p - pos) (at ?p)))
    (:obs-variable su (free-up))
    (:obs-variable sr (free-right))
    (:obs-variable sd (free-down))
    (:obs-variable sl (free-left))

    (:default-sensing-model
        (and (when (at p2-1) (and (free-left) (free-right) (not (free-up)) (not (free-down))))
             (when (at p2-3) (and (free-left) (free-right) (not (free-up)) (not (free-down))))
             (when (at p1-2) (and (free-up) (free-down) (not (free-left)) (not (free-right))))
             (when (at p3-2) (and (free-up) (free-down) (not (free-left)) (not (free-right))))
             (when (at p1-1) (and (free-up) (free-right) (not (free-down)) (not (free-left))))
             (when (at p3-1) (and (free-up) (free-left) (not (free-down)) (not (free-right))))
             (when (at p1-3) (and (free-down) (free-right) (not (free-up)) (not (free-left))))
             (when (at p3-3) (and (free-down) (free-left) (not (free-up)) (not (free-right))))
        )
    )

    (:action start
        :precondition (need-start)
        :effect (not (need-start))
    )
 
    (:action move-up
        :precondition (and (not (need-start)) (free-up))
        :effect
            (and (when (at p1-1) (and (at p1-2) (not (at p1-1))))
                 (when (at p3-1) (and (at p3-2) (not (at p3-1))))
                 (when (at p1-2) (and (at p1-3) (not (at p1-2))))
                 (when (at p3-2) (and (at p3-3) (not (at p3-2))))
            )
    )

    (:action move-down
        :precondition (and (not (need-start)) (free-down))
        :effect
            (and (when (at p1-2) (and (at p1-1) (not (at p1-2))))
                 (when (at p3-2) (and (at p3-1) (not (at p3-2))))
                 (when (at p1-3) (and (at p1-2) (not (at p1-3))))
                 (when (at p3-3) (and (at p3-2) (not (at p3-3))))
            )
    )

    (:action move-left
        :precondition (and (not (need-start)) (free-left))
        :effect
            (and (when (at p2-1) (and (at p1-1) (not (at p2-1))))
                 (when (at p3-1) (and (at p2-1) (not (at p3-1))))
                 (when (at p2-3) (and (at p1-3) (not (at p2-3))))
                 (when (at p3-3) (and (at p2-3) (not (at p3-3))))
            )
    )

    (:action move-right
        :precondition (and (not (need-start)) (free-right))
        :effect
            (and (when (at p1-1) (and (at p2-1) (not (at p1-1))))
                 (when (at p2-1) (and (at p3-1) (not (at p2-1))))
                 (when (at p1-3) (and (at p2-3) (not (at p1-3))))
                 (when (at p2-3) (and (at p3-3) (not (at p2-3))))
            )
    )
)

