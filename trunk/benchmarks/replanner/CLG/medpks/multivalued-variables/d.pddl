(define (domain medical)
    (:types ILLNESS)
    (:predicates 
        (dead) (cured) (no-stain)
        (stain ?i - ILLNESS) 
        (ill ?i - ILLNESS)    
    )

    (:variable alive (dead))
    (:variable disease (cured) (forall (?i - ILLNESS) (ill ?i)))
    (:obs-variable result (no-stain) (forall (?i - ILLNESS) (stain ?i)))

    (:action medicate-for
        :parameters (?i - ILLNESS)
        :precondition (not (dead))
        :effect
            (and (forall (?j - ILLNESS)
                     (and (when (and (ill ?j) (= ?i ?j)) (cured))
                          (when (and (ill ?j) (not (= ?i ?j))) (dead))
                     )
                 )
            )
    )

    (:action do-test
        :precondition (not (dead))
        :sensing-model
            (and (when (cured) (no-stain))
                 (forall (?i - ILLNESS) (when (ill ?i) (stain ?i)))
            )
    )
)

