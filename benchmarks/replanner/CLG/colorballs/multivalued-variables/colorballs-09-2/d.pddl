(define (domain colorballs) 
    (:types pos obj col gar)
    (:predicates
        (adj ?i ?j - pos)
        (color ?o - obj ?c - col)
        (garbage-at ?t - gar ?p - pos)
        (garbage-color ?t - gar ?c - col)
        (trashed ?o - obj)
        (at ?i - pos)
        (holding ?o - obj)
        (obj-at ?o - obj ?i - pos)
        (need-start)
    )

    (:variable agent-pos (forall (?p - pos) (at ?p)))
    (:variable (obj-pos ?o - obj) (holding ?o) (forall (?p - pos) (obj-at ?o ?p)))
    (:variable (obj-col ?o - obj) (forall (?c - col) (color ?o ?c)))
                
    (:action observe-color
        :parameters (?o - obj)
        :precondition (and (holding ?o) (not (need-start)))
        :sensing-model (forall (?c - col) (color ?o ?c))
    )
    
    (:action start-action
        :parameters (?p - pos)
        :precondition (and (at ?p) (need-start))
        :effect (not (need-start))
        :sensing-model (forall (?o - obj) (obj-at ?o ?p))
    )

    (:action move
        :parameters (?i ?j - pos)
        :precondition (and (adj ?i ?j) (at ?i) (not (need-start)))
        :effect (and (not (at ?i)) (at ?j))
        :sensing-model (forall (?o - obj) (obj-at ?o ?j))
    )

    (:action pickup
        :parameters (?o - obj ?i - pos)
        :precondition (and (at ?i) (obj-at ?o ?i) (not (need-start)))
        :effect (and (holding ?o) (not (obj-at ?o ?i)))
    )
    
    (:action trash
        :parameters (?o - obj ?c - col ?t - gar ?p - pos)
        :precondition (and (color ?o ?c) (holding ?o) (garbage-at ?t ?p) (at ?p) (not (need-start)))
        :effect (when (garbage-color ?t ?c) (trashed ?o))
    )
)

