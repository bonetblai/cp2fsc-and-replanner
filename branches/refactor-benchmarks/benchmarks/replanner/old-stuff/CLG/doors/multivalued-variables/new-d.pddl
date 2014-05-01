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
        :sensing-model
            (forall (?j - pos ?r - row ?c - col) (when (and (adj ?i ?j) (at-col ?c ?j) (at-row ?r ?i) (at-row ?r ?j) (opened ?j)) (obs ?j)))
    )

    (:action move
        :parameters (?i - pos ?j - pos )
        :precondition (and (adj ?i ?j) (at ?i) (opened ?j) (not (need-start)))
        :effect (and (not (at ?i)) (at ?j)) 
        :sensing-model
            ;(forall (?k - pos ?c - col) (when (and (adj ?j ?k) (at-col ?c ?k) (opened ?k)) (obs ?k)))
            (forall (?k - pos ?r - row ?c - col) (when (and (adj ?j ?k) (at-col ?c ?k) (at-row ?r ?j) (at-row ?r ?k) (opened ?k)) (obs ?k)))
    )
)

