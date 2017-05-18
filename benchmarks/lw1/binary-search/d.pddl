(define (domain binary-search)
    (:types state)
    (:predicates (secret ?p - state) (lt ?p ?q - state) (less-than) (discover-not-yet-attempted) (finish))

    (:variable hidden-secret (forall (?p - state) (secret ?p)))
    (:obs-variable obs-test (less-than)) ; binary (sensed) variable

    (:action test
        :parameters (?p - state)
        :sensing (model-for obs-test (less-than) (exists (?q - state) (and (secret ?q) (lt ?q ?p))))
                 (model-for obs-test (not (less-than)) (or (secret ?p) (exists (?q - state) (and (secret ?q) (lt ?p ?q)))))
    )

    (:action discover	
        :parameters (?p - state)
        :precondition (discover-not-yet-attempted)
        :effect (and (not (discover-not-yet-attempted)) (when (secret ?p) (finish)))
    )
)

