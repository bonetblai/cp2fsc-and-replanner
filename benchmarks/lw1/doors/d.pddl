(define (domain doors) 
    (:requirements :strips :typing)
    (:types row col pos)
    (:predicates
        (adj ?i ?j - pos)          ; static
        (at-col ?c - col ?i - pos) ; static
        (at-row ?r - row ?i - pos) ; static
        (opened ?i - pos)          ; hidden and static
        (obs ?i - pos)             ; observable
        (at ?i - pos)
        (need-start)
    )

    (:variable agent-pos (forall (?i - pos) (at ?i)))
    (:variable (door-at ?c - col) (forall (?i - pos) (when (at-col ?c ?i) (opened ?i))))
    (:obs-variable (obs-at ?c - col) (forall (?i - pos) (when (at-col ?c ?i) (obs ?i))))
                
    (:action start
        :parameters (?i - pos)
        :precondition (and (at ?i) (need-start))
        :effect (not (need-start))
        :sensing
            (forall (?j - pos ?c - col)
                (such-that
                    (at-col ?c ?j)
                    (:model-for (obs-at ?c) (obs ?j) (exists (?r - row) (and (adj ?i ?j) (at-row ?r ?i) (at-row ?r ?j) (opened ?j))))
                )
            )
    )

    (:action move
        :parameters (?i - pos ?j - pos )
        :precondition (and (adj ?i ?j) (at ?i) (opened ?j) (not (need-start)))
        :effect (and (not (at ?i)) (at ?j)) 
        :sensing
            (forall (?k - pos ?c - col)
                (such-that
                    (at-col ?c ?k)
                    (:model-for (obs-at ?c) (obs ?k) (exists (?r - row) (and (adj ?j ?k) (at-row ?r ?j) (at-row ?r ?k) (opened ?k))))
                )
            )
    )
)

