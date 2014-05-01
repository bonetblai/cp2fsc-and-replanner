
(define (domain RockSample)
    (:types LOCATION ROCK HEIGHT)
    (:constants h0 h1 h2 - HEIGHT)
    (:predicates
        (rock-at ?r - ROCK ?loc - LOCATION)
        (agent-at ?loc - LOCATION)
        (adj ?loc1 ?loc2 - LOCATION)
        (good ?r - ROCK)
        (done ?r - ROCK)
        (antenna-height ?h - HEIGHT)
        (good-rocks-in-range ?loc - LOCATION ?h - HEIGHT)
        (in-range ?r - ROCK ?loc - LOCATION ?h - HEIGHT)
        (not-sensing)
        (sensing)
    )

    (:action move
        :parameters (?src ?dst - LOCATION)
        :precondition (and (not (sensing)) (agent-at ?src) (adj ?src ?dst) (antenna-height h0))
        :effect (and (agent-at ?dst) (not (agent-at ?src)))
    )

    (:action sample
        :parameters (?r - ROCK ?loc - LOCATION)
        :precondition (and (not (sensing)) (agent-at ?loc) (rock-at ?r ?loc) (good ?r))
        :effect (done ?r)
    )

    (:action skip
        :parameters (?r - ROCK)
        :precondition (and (not (sensing)) (not (good ?r)))
        :effect (done ?r)
    )

    (:action raise-antenna
        :precondition (not (sensing))
        :effect (and (when (antenna-height h0) (and (not (antenna-height h0)) (antenna-height h1)))
	             (when (antenna-height h1) (and (not (antenna-height h1)) (antenna-height h2)))
                )
    )

    (:action lower-antenna
        :precondition (not (sensing))
        :effect (and (when (antenna-height h1) (and (not (antenna-height h1)) (antenna-height h0)))
	             (when (antenna-height h2) (and (not (antenna-height h2)) (antenna-height h1)))
                )
    )

    (:action activate-sensor
        :precondition (not (sensing))
        :effect (sensing)
    )

    (:action deactivate-sensor
        :precondition (sensing)
        :effect (not (sensing))
    )

    (:sensor rock-sensor
        :parameters (?loc - LOCATION ?h - HEIGHT)
        :condition (and (sensing) (agent-at ?loc) (antenna-height ?h))
        :sense (good-rocks-in-range ?loc ?h)
    )
)

