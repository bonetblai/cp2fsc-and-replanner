(define (domain wumpus)
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
        :sensed (stench ?p)
    )

;   (:inference stench-wumpus
;       :parameters (?p1 ?p2 - pos)
;       :body (and (adj ?p1 ?p2) (at ?p1) (not (stench ?p1)))
;       :head (not (wumpus ?p2))
;   )
)

