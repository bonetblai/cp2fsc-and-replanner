(define (domain btcs)
    (:types package bomb toilet)
    (:predicates (in ?p - package ?b - bomb) (defused ?b - bomb) (clogged ?t - toilet) (sensed ?b - bomb ?p - package))

    (:variable (bomb-loc ?b - bomb) (forall (?p - package) (in ?p ?b)))
    (:obs-variable (bomb-in-package ?b - bomb ?p - package) (sensed ?p ?b)) ; binary (sensed) variable

    (:action sense
        :parameters (?p - package ?b - bomb)
        :sensing (model-for (bomb-in-package ?b ?p) (sensed ?p ?b) (in ?p ?b))
                 (model-for (bomb-in-package ?b ?p) (not (sensed ?p ?b)) (exists (?q - package) (and (not (= ?p ?q)) (in ?q ?b))))
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

