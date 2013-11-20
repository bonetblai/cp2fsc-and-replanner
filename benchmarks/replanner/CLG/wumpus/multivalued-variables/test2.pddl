(define (domain wumpus) 
    (:requirements :strips :typing)
    (:types pos)
    (:predicates
        (adj ?p ?q - pos)
        (need-start)
        (at ?p - pos)
        (alive)
        ;(pit-at ?p - pos)
        (wumpus-at ?p - pos)
        (gold-at ?p - pos)
        (got-the-treasure)
        (stench ?p - pos)
        ;(breeze ?p - pos)
        ;(glitter ?p - pos)
    )

    (:variable agent-pos (forall (?p - pos) (at ?p)))
    (:variable gold-pos (got-the-treasure) (forall (?p - pos) (gold-at ?p)))
    (:variable (wumpus-var ?p - pos) (wumpus-at ?p))
    ;(:variable (pit-var ?p - pos) (pit-at ?p))
    (:obs-variable (stench-var ?p - pos) (stench ?p))
    ;(:obs-variable (breeze-var ?p - pos) (breeze ?p))
    ;(:obs-variable (glitter-var ?p - pos) (glitter ?p))

    (:action start
        :parameters (?j - pos)
        :precondition (and (need-start) (at ?j))
        :effect (not (need-start))
        :sensing-model
            ;(and (forall (?p ?q - pos) (when (and (at ?p) (adj ?p ?q) (wumpus-at ?q)) (stench ?p)))
            ;     ;(forall (?p ?q - pos) (when (and (at ?p) (adj ?p ?q) (pit-at ?q)) (breeze ?p)))
            ;     ;(forall (?p - pos) (when (and (at ?p) (gold-at ?p)) (glitter ?p)))
            ;)
            (and (forall (?p - pos) (when (and (at ?j) (adj ?j ?p) (wumpus-at ?p)) (stench ?j)))
            )
    )

    (:action move
        :parameters (?i ?j - pos)
        :precondition (and (adj ?i ?j) (at ?i) (alive))
        :effect
            (and (not (at ?i)) (at ?j)
                 (when (wumpus-at ?j) (not (alive)))
                 ;(when (pit-at ?j) (not (alive)))
            )
        :sensing-model
            ;(and (forall (?p ?q - pos) (when (and (at ?p) (adj ?p ?q) (wumpus-at ?q)) (stench ?p)))
            ;     ;(forall (?p ?q - pos) (when (and (at ?p) (adj ?p ?q) (pit-at ?q)) (breeze ?p)))
            ;     ;(forall (?p - pos) (when (and (at ?p) (gold-at ?p)) (glitter ?p)))
            ;)
            (and (forall (?p - pos) (when (and (at ?j) (adj ?j ?p) (wumpus-at ?p)) (stench ?j)))
            )
    )

    (:action grab
        :parameters (?i - pos)
        :precondition (and (at ?i) (gold-at ?i) (alive))
        :effect (and (got-the-treasure) (not (gold-at ?i)))
    )
)

