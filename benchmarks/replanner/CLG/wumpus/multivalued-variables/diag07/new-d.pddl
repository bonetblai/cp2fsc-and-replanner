(define (domain diagonal-wumpus-7x7) 
    (:requirements :strips :typing)
    (:types pos)
    (:constants
        p1-1 p1-2 p1-3 p1-4 p1-5 p1-6 p1-7
        p2-1 p2-2 p2-3 p2-4 p2-5 p2-6 p2-7
        p3-1 p3-2 p3-3 p3-4 p3-5 p3-6 p3-7
        p4-1 p4-2 p4-3 p4-4 p4-5 p4-6 p4-7
        p5-1 p5-2 p5-3 p5-4 p5-5 p5-6 p5-7
        p6-1 p6-2 p6-3 p6-4 p6-5 p6-6 p6-7
        p7-1 p7-2 p7-3 p7-4 p7-5 p7-6 p7-7 - pos
    )
    (:predicates
        (adj ?p ?q - pos)
        (at ?p - pos)
        (wumpus-at ?p - pos)
        (gold-at ?p - pos)
        (got-the-treasure)
        (stench ?p - pos)
        ;(glitter ?p - pos)
        (safe ?p - pos)
    )

    (:variable agent-pos (forall (?p - pos) (at ?p)))
;;;;;(:variable gold-pos (got-the-treasure) (forall (?p - pos) (gold-at ?p)))
    (:variable wumpus-1 (wumpus-at p2-3) (wumpus-at p3-2))
    (:variable wumpus-2 (wumpus-at p3-4) (wumpus-at p4-3))
    (:variable wumpus-3 (wumpus-at p4-5) (wumpus-at p5-4))
    (:variable wumpus-4 (wumpus-at p5-6) (wumpus-at p6-5))
    (:variable wumpus-5 (wumpus-at p6-7) (wumpus-at p7-6))
    (:obs-variable (stench-var ?p - pos) (stench ?p))
;;;;;(:obs-variable (glitter-var ?p - pos) (glitter ?p))
    (:variable (is-safe ?p - pos) (safe ?p))

    (:action smell-wumpus
        :parameters (?i - pos)
        :precondition (at ?i)
        :sensing-model
            (and (forall (?p - pos) (when (and (adj ?i ?p) (wumpus-at ?p)) (stench ?i)))
                 (when (forall (?p - pos) (or (not (adj ?i ?p)) (not (wumpus-at ?p)))) (not (stench ?i)))
            )
    )

    (:action move
        :parameters (?i ?j - pos)
        :precondition (and (adj ?i ?j) (at ?i) (safe ?j))
        :effect (and (not (at ?i)) (at ?j))
    )

    (:action grab
        :parameters (?i - pos)
        :precondition (and (at ?i) (gold-at ?i))
        :effect (and (got-the-treasure) (not (gold-at ?i)))
    )

    (:action inference
        :parameters (?p - pos)
        :precondition (and (not (wumpus-at ?p)))
        :effect (safe ?p)
    )
)

