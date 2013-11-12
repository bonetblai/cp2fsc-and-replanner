(define (domain ctp)
    (:requirements :typing :equality)
    (:types vertex edge)
    (:predicates
        (adjacent ?x - vertex ?e - edge)
        (traversable ?e - edge)
        (at ?x - vertex)
    )

    (:action move-along
        :parameters (?x ?y - vertex ?e - edge)
        :precondition (and (at ?x) (adjacent ?x ?e) (adjacent ?y ?e) (traversable ?e))
        :effect (and (not (at ?x)) (at ?y))
    )

    (:sensor edge-obs
        :parameters (?x - vertex ?e - edge)
        :condition (and (at ?x) (adjacent ?x ?e))
        :sense (traversable ?e)
    )
)

