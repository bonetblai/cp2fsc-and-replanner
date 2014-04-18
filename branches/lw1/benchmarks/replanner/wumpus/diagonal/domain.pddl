(define (domain diagonal-wumpus)
    (:requirements :typing :equality)
    (:types pos)
    (:predicates
        (adj ?p1 ?p2 - pos)
        (wumpus ?p - pos)
        (stench ?p - pos)
        (gold ?p)
        (have-gold)
        (safe ?p2)
        (at ?p - pos)
        (alive)
    )

    (:action move
        :parameters (?p1 ?p2 - pos)
        :precondition (and (adj ?p1 ?p2) (at ?p1) (alive) (safe ?p2))
        :effect (and (not (at ?p1)) (at ?p2))
    )

    (:action grab-gold
        :parameters (?p - pos)
        :precondition (and (at ?p) (gold ?p) (alive))
        :effect (and (not (gold ?p)) (have-gold))
    )

    (:sensor sensor-for-stench
        :parameters (?p - pos)
        :condition (at ?p)
        :sense (stench ?p)
    )
)

