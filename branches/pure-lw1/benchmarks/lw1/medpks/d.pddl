(define (domain medical)
    (:types ILLNESS)
    (:predicates 
        (dead) (cured) (no-stain)
        (stain ?i - ILLNESS) 
        (ill ?i - ILLNESS)    
    )

    (:variable alive (dead))
    (:variable disease (cured) (forall (?i - ILLNESS) (ill ?i)))
    (:obs-variable test-result (no-stain) (forall (?i - ILLNESS) (stain ?i)))

    (:action medicate-for
        :parameters (?i - ILLNESS)
        :precondition (not (dead))
        :effect
            (and (forall (?j - ILLNESS)
                     (and (when (and (ill ?j) (= ?i ?j)) (and (cured) (not (ill ?j))))
                          (when (and (ill ?j) (not (= ?i ?j))) (dead))
                     )
                 )
                 (when (cured) (dead))
            )
    )

    (:action do-test
        :precondition (not (dead))
        :sensing
            (model-for test-result (no-stain) (cured))
            (forall (?i - ILLNESS) (model-for test-result (stain ?i) (ill ?i)))
    )
)

