(define (domain trail)
    (:requirements :typing :equality)
    (:types pos)
    (:predicates
        (adj ?p1 ?p2 - pos)
        (stone ?p - pos)
        (final-stone ?p - pos)
        (visited ?p - pos)
        (at ?p - pos)
        (done)
    )

    (:action move
        :parameters (?p1 ?p2 - pos)
        :precondition (and (adj ?p1 ?p2) (at ?p1) (stone ?p2) (not (visited ?p2)))
        :effect (and (not (at ?p1)) (at ?p2) (visited ?p2))
    )
    (:action finish
        :parameters (?p - pos)
        :precondition (and (at ?p) (final-stone ?p))
        :effect (done)
    )

    (:sensor adj-stone
        :parameters (?p1 ?p2 - pos)
        :condition (and (adj ?p1 ?p2) (at ?p1))
        :sense (stone ?p2)
    )
    (:sensor final
        :parameters (?p - pos)
        :condition (at ?p)
        :sense (final-stone ?p)
    )
)

