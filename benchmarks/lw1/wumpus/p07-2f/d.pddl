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
    (:variable (wumpus-at-cell ?p - pos) (wumpus-at ?p))                       ; binary variable
    ;;(:variable (pit-at-cell ?p - pos) (pit-at ?p))                             ; binary variable
    (:obs-variable (stench-var ?p - pos) (stench ?p))                          ; binary variable
    ;;(:obs-variable (breeze-var ?p - pos) (breeze ?p))                          ; binary variable
    (:obs-variable (glitter-var ?p - pos) (glitter ?p))                        ; binary variable

    (:action start
        :parameters (?j - pos)
        :precondition (and (need-start) (alive) (at ?j))
        :effect (not (need-start))
        :sensing
            (:model-for (stench-var ?j) (stench ?j) (exists (?p - pos) (and (adj ?j ?p) (wumpus-at ?p))))
            (:model-for (stench-var ?j) (not (stench ?j)) (forall (?p - pos) (or (not (adj ?j ?p)) (not (wumpus-at ?p)))))
            ;;(:model-for (breeze-var ?j) (breeze ?j) (exists (?p - pos) (and (adj ?j ?p) (pit-at ?p))))
            ;;(:model-for (breeze-var ?j) (not (breeze ?j)) (forall (?p - pos) (or (not (adj ?j ?p)) (not (pit-at ?p)))))
            (:model-for (glitter-var ?j) (glitter ?j) (gold-at ?j))
            (:model-for (glitter-var ?j)
                        (not (glitter ?j))
                        (or (got-the-treasure) (exists (?p - pos) (and (not (= ?p ?j)) (gold-at ?p))))
            )
    )

    (:action move
        :parameters (?i ?j - pos)
        :precondition (and (adj ?i ?j) (at ?i) (alive) (not (need-start)))
        :effect (and (not (at ?i)) (at ?j)
                     (when (wumpus-at ?j) (not (alive)))
                     ;;(when (pit-at ?j) (not (alive)))
                )
        :sensing
            (:model-for (stench-var ?j) (stench ?j) (exists (?p - pos) (and (adj ?j ?p) (wumpus-at ?p))))
            (:model-for (stench-var ?j) (not (stench ?j)) (forall (?p - pos) (or (not (adj ?j ?p)) (not (wumpus-at ?p)))))
            ;;(:model-for (breeze-var ?j) (breeze ?j) (exists (?p - pos) (and (adj ?j ?p) (pit-at ?p))))
            ;;(:model-for (breeze-var ?j) (not (breeze ?j)) (forall (?p - pos) (or (not (adj ?j ?p)) (not (pit-at ?p)))))
            (:model-for (glitter-var ?j) (glitter ?j) (gold-at ?j))
            (:model-for (glitter-var ?j)
                        (not (glitter ?j))
                        (or (got-the-treasure) (exists (?p - pos) (and (not (= ?p ?j)) (gold-at ?p))))
            )
    )

    (:action grab
        :parameters (?i - pos)
        :precondition (and (at ?i) (alive) (gold-at ?i))
        :effect (and (got-the-treasure) (not (gold-at ?i)))
    )
)

