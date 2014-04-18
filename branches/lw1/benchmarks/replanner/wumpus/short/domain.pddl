(define (domain short-wumpus)
    (:requirements :typing :equality)
    (:types pos)
    (:predicates
        (adj ?p1 ?p2 - pos)
        (wumpus ?p - pos)
        (stench ?p - pos)
        (at ?p - pos)
    )

    (:action move
        :parameters (?p1 ?p2 - pos)
        :precondition (and (adj ?p1 ?p2) (at ?p1) (not (wumpus ?p2)))
        :effect (and (not (at ?p1)) (at ?p2))
    )

    (:sensor smell
        :parameters (?p - pos)
        :condition (at ?p)
        :sense (stench ?p)
    )
)

