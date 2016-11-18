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
        (neighborhood ?p ?q - pos)
    )

    (:variable agent-pos (forall (?p - pos) (at ?p)))
    (:variable gold-pos (forall (?p - pos) (gold-at ?p)))                      ; (got-treasure) cannot be added to variable for AC3 because then gold-pos isn't static
    (:variable (wumpus-at-cell ?p - pos) (wumpus-at ?p))                       ; binary variable
    ;;(:variable (pit-at-cell ?p - pos) (pit-at ?p))                             ; binary variable
    (:obs-variable (stench-var ?p - pos) (stench ?p))                          ; binary variable
    ;;(:obs-variable (breeze-var ?p - pos) (breeze ?p))                          ; binary variable
    (:obs-variable (glitter-var ?p - pos) (glitter ?p))                        ; binary variable

    (:var-group (wgroup ?p - pos) (forall (?q - pos) such-that (neighborhood ?p ?q) (wumpus-at-cell ?q)))
    ;;(:var-group (pgroup ?p - pos) (forall (?q - pos) such-that (neighborhood ?p ?q) (pit-at-cell ?q)))

    (:action start
        :parameters (?j - pos)
        :precondition (and (need-start) (alive) (at ?j))
        :effect (not (need-start))
        :sensing
            (model-for (stench-var ?j) (stench ?j) (exists (?p - pos) (and (adj ?j ?p) (wumpus-at ?p))))
            (model-for (stench-var ?j) (not (stench ?j)) (forall (?p - pos) (or (not (adj ?j ?p)) (not (wumpus-at ?p)))))
            ;;(model-for (breeze-var ?j) (breeze ?j) (exists (?p - pos) (and (adj ?j ?p) (pit-at ?p))))
            ;;(model-for (breeze-var ?j) (not (breeze ?j)) (forall (?p - pos) (or (not (adj ?j ?p)) (not (pit-at ?p)))))
            (model-for (glitter-var ?j) (glitter ?j) (gold-at ?j))
            (model-for (glitter-var ?j)
                       (not (glitter ?j))
                       (or (exists (?p - pos) (and (not (= ?p ?j)) (gold-at ?p))))
            )
    )

    (:action move
        :parameters (?i ?j - pos)
        :precondition (and (adj ?i ?j) (at ?i) (alive) (not (need-start)) (not (wumpus-at ?j)))
        :effect (and (not (at ?i)) (at ?j))
        :sensing
            (model-for (stench-var ?j) (stench ?j) (exists (?p - pos) (and (adj ?j ?p) (wumpus-at ?p))))
            (model-for (stench-var ?j) (not (stench ?j)) (forall (?p - pos) (or (not (adj ?j ?p)) (not (wumpus-at ?p)))))
            ;;(model-for (breeze-var ?j) (breeze ?j) (exists (?p - pos) (and (adj ?j ?p) (pit-at ?p))))
            ;;(model-for (breeze-var ?j) (not (breeze ?j)) (forall (?p - pos) (or (not (adj ?j ?p)) (not (pit-at ?p)))))
            (model-for (glitter-var ?j) (glitter ?j) (gold-at ?j))
            (model-for (glitter-var ?j)
                       (not (glitter ?j))
                       (or (exists (?p - pos) (and (not (= ?p ?j)) (gold-at ?p))))
            )
    )

    (:action grab
        :parameters (?i - pos)
        :precondition (and (at ?i) (alive) (gold-at ?i) (not (need-start)))
        :effect (got-the-treasure)
    )
)

