(define (domain doors) 
    (:requirements :strips :typing)
    (:types row col pos)
    (:predicates
        (adj ?i ?j - pos)              ; (static) vertical and right-horizontal adjacency of positions
        (at-col ?c - col ?i - pos)     ; (static) column for given position
        (at-row ?r - row ?i - pos)     ; (static) row for given position
        (right-col ?c - col ?i - pos)  ; (static) column to the right of given position
        (even ?c - col)                ; (static) even-numbered columns
        (need-start)
        (at ?i - pos)                  ; current position
        (opened ?i - pos)              ; hidden and static
        (obs-open ?i - pos)            ; observable
    )

    (:variable agent-pos (forall (?i - pos) (at ?i)))
    (:variable (door-at ?c - col) such-that (even ?c) (forall (?i - pos) (when (at-col ?c ?i) (opened ?i))))
    (:obs-variable (obs-at ?i - pos) (obs-open ?i))
                
    (:action start
        :parameters (?i - pos)
        :precondition (and (at ?i) (need-start))
        :effect (not (need-start))
        :sensing
            (forall (?r - row ?c - col) such-that (and (at-row ?r ?i) (right-col ?c ?i))
                (model-for (obs-at ?i) (obs-open ?i) (exists (?y - pos) (and (at-col ?c ?y) (at-row ?r ?y) (opened ?y))))
                (model-for (obs-at ?i) (not (obs-open ?i)) (exists (?y - pos) (and (at-col ?c ?y) (not (at-row ?r ?y)) (opened ?y))))
            )
    )

    (:action move
        :parameters (?i - pos ?j - pos)
        :precondition (and (adj ?i ?j) (at ?i) (opened ?j) (not (need-start)))
        :effect (and (not (at ?i)) (at ?j)) 
        :sensing
            (forall (?r - row ?c - col) such-that (and (at-row ?r ?j) (right-col ?c ?j))
                (model-for (obs-at ?j) (obs-open ?j) (exists (?y - pos) (and (at-col ?c ?y) (at-row ?r ?y) (opened ?y))))
                (model-for (obs-at ?j) (not (obs-open ?j)) (exists (?y - pos) (and (at-col ?c ?y) (not (at-row ?r ?y)) (opened ?y))))
            )
    )
)

