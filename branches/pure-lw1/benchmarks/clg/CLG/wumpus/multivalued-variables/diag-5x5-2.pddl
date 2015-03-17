(define (domain diagonal-wumpus-5x5) 
    (:requirements :strips :typing)
    (:types pos)
    (:constants p1-1 p1-2 p1-3 p1-4 p1-5 p2-1 p2-2 p2-3 p2-4 p2-5 p3-1 p3-2 p3-3 p3-4 p3-5 p4-1 p4-2 p4-3 p4-4 p4-5 p5-1 p5-2 p5-3 p5-4 p5-5 - pos)
    (:predicates
        (adj ?p ?q - pos)
        (need-start)
        (at ?p - pos)
        (alive)
        (wumpus-at ?p - pos)
        (gold-at ?p - pos)
        (got-the-treasure)
        (stench ?p - pos)
        (glitter ?p - pos)
    )

    (:variable agent-pos (forall (?p - pos) (at ?p)))
    (:variable gold-pos (got-the-treasure) (forall (?p - pos) (gold-at ?p)))
    (:variable wumpus-1 (wumpus-at p2-3) (wumpus-at p3-2))
    (:variable wumpus-2 (wumpus-at p3-4) (wumpus-at p4-3))
    (:variable wumpus-3 (wumpus-at p4-5) (wumpus-at p5-4))
    (:obs-variable (stench-var ?p - pos) (stench ?p))
    (:obs-variable (glitter-var ?p - pos) (glitter ?p))

    (:action start
        :parameters (?j - pos)
        :precondition (and (need-start) (at ?j))
        :effect (not (need-start))
        :sensing-model
            (and (forall (?p - pos) (when (and (adj ?j ?p) (wumpus-at ?p)) (stench ?j)))
                 (when (gold-at ?j) (glitter ?j))
            )
    )

    (:action move
        :parameters (?i ?j - pos)
        :precondition (and (adj ?i ?j) (at ?i) (alive))
        :effect
            (and (not (at ?i)) (at ?j)
                 (when (wumpus-at ?j) (not (alive)))
            )
        :sensing-model
            (and (forall (?p - pos) (when (and (adj ?j ?p) (wumpus-at ?p)) (stench ?j)))
                 (when (forall (?p - pos) (or (not (adj ?p ?j)) (not (wumpus-at ?p)))) (not (stench ?j)))
                 (when (gold-at ?j) (glitter ?j))
            )
    )

    (:action grab
        :parameters (?i - pos)
        :precondition (and (at ?i) (gold-at ?i) (alive))
        :effect (and (got-the-treasure) (not (gold-at ?i)))
    )
)

