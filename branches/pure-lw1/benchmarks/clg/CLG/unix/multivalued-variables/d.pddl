(define (domain unix)
    (:types FILE DIR)
    (:predicates
        (file-in-dir ?file - FILE ?dir - DIR)
        (sub-dir ?par-dir - DIR ?child-dir - DIR)
        (is-cur-dir ?dir - DIR)
    )

    (:variable (file-location ?f - FILE) (forall (?d - DIR) (file-in-dir ?f ?d)))
 
    (:action cd-down
        :parameters (?cur-dir - DIR ?child-dir - DIR)
        :precondition (and (is-cur-dir ?cur-dir) (sub-dir ?cur-dir ?child-dir))
        :effect (and (is-cur-dir ?child-dir) (not (is-cur-dir ?cur-dir)))
    )
 

    (:action cd-up
        :parameters (?cur-dir - DIR ?par-dir - DIR)
        :precondition (and (is-cur-dir ?cur-dir) (sub-dir ?par-dir ?cur-dir))
        :effect (and (is-cur-dir ?par-dir) (not (is-cur-dir ?cur-dir)))
    )
 
    (:action ls
        :parameters (?cur-dir - DIR)
        :precondition (is-cur-dir ?cur-dir)
        :sensing-model (forall (?f - FILE) (file-in-dir ?f ?cur-dir))
    )
 
    (:action mv
        :parameters (?file - FILE ?cur-dir - DIR ?target-dir - DIR)
        :precondition (and (is-cur-dir ?cur-dir) (file-in-dir ?file ?cur-dir))
        :effect (and (not (file-in-dir ?file ?cur-dir)) (file-in-dir ?file ?target-dir))
    )
)
