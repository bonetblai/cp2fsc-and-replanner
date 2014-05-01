(define (domain RockSample)
    (:types location rock height)
    (:constants h0 - height)
    (:predicates
        (adj ?p ?q - location)
        (next-height ?h1 ?h2 - height)
        (in-sensing-range ?h - height ?p ?q - location)
        (rock-at ?r - rock ?p - location)
        (agent-at ?p - location)
        (good ?r - rock)
        (antenna-height ?h - height)
        ;(good-rocks-in-sensing-range)
        (good-rocks-in-sensing-range ?h - height ?p - location)
        ;(need-start)
    )

    (:variable (rock-status ?r - rock) (good ?r))
    (:obs-variable (rocks-in-range ?h - height ?p - location) (good-rocks-in-sensing-range ?h ?p))

    ;(:action start :precondition (need-start) :effect (not (need-start)))

    (:action move
        :parameters (?p ?q - location)
        :precondition (and (agent-at ?p) (adj ?p ?q) (antenna-height h0))
        ;:precondition (and (agent-at ?p) (adj ?p ?q) (antenna-height h0) (not (need-start)))
        :effect (and (agent-at ?q) (not (agent-at ?p)))
    )

    (:action sample
        :parameters (?r - rock ?p - location)
        :precondition (and (agent-at ?p) (rock-at ?r ?p) (good ?r))
        ;:precondition (and (agent-at ?p) (rock-at ?r ?p) (good ?r) (not (need-start)))
        :effect (not (good ?r)))

    (:action raise-antenna
        ;:precondition (not (need-start))
        :effect
            (forall (?h1 ?h2 - height)
                (when (and (antenna-height ?h1) (next-height ?h1 ?h2))  (and (not (antenna-height ?h1)) (antenna-height ?h2)))
            )
    )

    (:action lower-antenna
        ;:precondition (not (need-start))
        :effect
            (forall (?h1 ?h2 - height)
                (when (and (antenna-height ?h1) (next-height ?h2 ?h1)) (and (not (antenna-height ?h1)) (antenna-height ?h2)))
            )
    )

    (:action activate-sensor
        :parameters (?p - location ?h - height)
        :precondition (and (agent-at ?p) (antenna-height ?h))
        ;:precondition (and (agent-at ?p) (antenna-height ?h) (not (need-start)))
        :sensing-model
            (and (forall (?r - rock ?q - location)
                     (when (and (rock-at ?r ?q) (in-sensing-range ?h ?p ?q) (good ?r)) (good-rocks-in-sensing-range ?h ?p))
                 )
                 (when (forall (?r - rock ?q - location) (or (not (rock-at ?r ?q)) (not (in-sensing-range ?h ?p ?q)) (not (good ?r))))
                       (not (good-rocks-in-sensing-range ?h ?p))
                 )
            )
    )
)

