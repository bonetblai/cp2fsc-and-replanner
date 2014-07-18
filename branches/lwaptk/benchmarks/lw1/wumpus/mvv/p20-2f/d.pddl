(define (domain wumpus)
    (:requirements :strips :typing)
    (:types pos)
    (:predicates
        (adj ?p ?q - pos)
        (need-start)
        (at ?p - pos)
        (wumpus-at ?p - pos)
        ;;(pit-at ?p - pos)
        (gold-at ?p - pos)
        (got-the-treasure)
        (stench ?p - pos)
        ;;(breeze ?p - pos)
        (glitter ?p - pos)
        (alive)
    )

    (:variable agent-pos (forall (?p - pos) (at ?p)))
    (:variable gold-pos (got-the-treasure) (forall (?p - pos) (gold-at ?p)))
    (:variable (wumpus-at-cell ?p - pos) (wumpus-at ?p))
    ;;(:variable (pit-at-cell ?p - pos) (pit-at ?p))
    (:obs-variable (stench-var ?p - pos) (stench ?p))
    ;;(:obs-variable (breeze-var ?p - pos) (breeze ?p))
    (:obs-variable (glitter-var ?p - pos) (glitter ?p))

    (:action start
        :parameters (?j - pos)
        :precondition (and (need-start) (alive) (at ?j))
        :effect (not (need-start))
        :sensing-model
            (and (forall (?p - pos) (when (and (adj ?j ?p) (wumpus-at ?p)) (stench ?j)))
                 (when (forall (?p - pos) (or (not (adj ?j ?p)) (not (wumpus-at ?p)))) (not (stench ?j)))
                 ;;(forall (?p - pos) (when (and (adj ?j ?p) (pit-at ?p)) (breeze ?j)))
                 ;;(when (forall (?p - pos) (or (not (adj ?j ?p)) (not (pit-at ?p)))) (not (breeze ?j)))
                 (when (gold-at ?j) (glitter ?j))
                 (when (not (gold-at ?j)) (not (glitter ?j)))
            )
    )

    (:action move
        :parameters (?i ?j - pos)
        :precondition (and (adj ?i ?j) (at ?i) (alive) (not (need-start)))
        :effect (and (not (at ?i)) (at ?j)
                     (when (wumpus-at ?j) (not (alive)))
                     ;;(when (pit-at ?j) (not (alive)))
                )
        :sensing-model
            (and (forall (?p - pos) (when (and (adj ?j ?p) (wumpus-at ?p)) (stench ?j)))
                 (when (forall (?p - pos) (or (not (adj ?j ?p)) (not (wumpus-at ?p)))) (not (stench ?j)))
                 ;;(forall (?p - pos) (when (and (adj ?j ?p) (pit-at ?p)) (breeze ?j)))
                 ;;(when (forall (?p - pos) (or (not (adj ?j ?p)) (not (pit-at ?p)))) (not (breeze ?j)))
                 (when (gold-at ?j) (glitter ?j))
                 (when (not (gold-at ?j)) (not (glitter ?j)))
            )
    )

    (:action grab
        :parameters (?i - pos)
        :precondition (and (at ?i) (alive) (gold-at ?i))
        :effect (and (got-the-treasure)); (not (gold-at ?i)))
    )
)

