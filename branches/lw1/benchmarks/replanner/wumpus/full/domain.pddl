(define (domain full-wumpus)
    (:requirements :typing :equality)
    (:types pos)
    (:predicates
        (adj ?p1 ?p2 - pos)
        (wumpus ?p - pos)
        (stench ?p - pos)
        (pit ?p - pos)
        (breeze ?p - pos)
        (gold ?p)
        (glitter ?p - pos)
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

    (:sensor sensor-for-breeze
        :parameters (?p - pos)
        :condition (at ?p)
        :sense (breeze ?p)
    )

    (:sensor sensor-for-glitter
        :parameters (?p - pos)
        :condition (at ?p)
        :sense (glitter ?p)
    )
)

