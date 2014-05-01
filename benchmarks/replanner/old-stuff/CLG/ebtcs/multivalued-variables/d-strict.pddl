(define (domain btcs)
    (:types package bomb toilet)
    (:predicates
        (in ?p - package ?b - bomb)
        (defused ?b - bomb)
        (clogged ?t - toilet)
        (obs ?p - package ?b - bomb)
    )

    (:variable (bomb-loc ?b - bomb) (forall (?p - package) (in ?p ?b)))
    (:obs-variable (obs-at ?p - package ?b - bomb) (obs ?p ?b))

    (:action sense
        :parameters (?p - package ?b - bomb)
        :sensing-model
            (and (when (in ?p ?b) (obs ?p ?b))
                 (when (not (in ?p ?b)) (not (obs ?p ?b)))
            )
    )

    (:action dunk	
        :parameters (?p - package ?b - bomb ?t - toilet)
        :precondition (and (not (clogged ?t)) (in ?p ?b))
        :effect (and (defused ?b) (clogged ?t))
    )

    (:action flush	
        :parameters (?t - toilet)
        :effect (not (clogged ?t))
    )
)

