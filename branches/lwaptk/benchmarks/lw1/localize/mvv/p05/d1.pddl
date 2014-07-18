(define (domain sliding-doors) 
    (:requirements :strips :typing :translation)
    (:types pos)
    (:predicates
        (wall-up-of ?p - pos)    ; static predicate
        (wall-right-of ?p - pos) ; static predicate
        (wall-down-of ?p - pos)  ; static predicate
        (wall-left-of ?p - pos)  ; static predicate
        (up-of ?p ?q - pos)      ; static predicate
        (right-of ?p ?q - pos)   ; static predicate
        (down-of ?p ?q - pos)    ; static predicate
        (left-of ?p ?q - pos)    ; static predicate
        (possible ?p - pos)      ; static predicate

        (need-start)
        (at ?i)
        (free-up)
        (free-down)
        (free-left)
        (free-right)
    )

    (:variable position (forall (?p - pos) (when (possible ?p) (at ?p))))
    (:obs-variable su (free-up))
    (:obs-variable sr (free-right))
    (:obs-variable sd (free-down))
    (:obs-variable sl (free-left))

    (:default-sensing-model
        (forall (?p - pos)
            (and (when (and (at ?p) (possible ?p) (wall-up-of ?p)) (not (free-up)))
                 (when (and (at ?p) (possible ?p) (not (wall-up-of ?p))) (free-up))
                 (when (and (at ?p) (possible ?p) (wall-right-of ?p)) (not (free-right)))
                 (when (and (at ?p) (possible ?p) (not (wall-right-of ?p))) (free-right))
                 (when (and (at ?p) (possible ?p) (wall-down-of ?p)) (not (free-down)))
                 (when (and (at ?p) (possible ?p) (not (wall-down-of ?p))) (free-down))
                 (when (and (at ?p) (possible ?p) (wall-left-of ?p)) (not (free-left)))
                 (when (and (at ?p) (possible ?p) (not (wall-left-of ?p))) (free-left))
            )
        )
    )

    (:action start
        :precondition (need-start)
        :effect (not (need-start))
    )
 
    (:action move-up
        :precondition (and (not (need-start)) (free-up))
        :effect
            (forall (?p ?q - pos) (when (and (at ?p) (up-of ?p ?q)) (and (at ?q) (not (at ?p)))))
    )

    (:action move-down
        :precondition (and (not (need-start)) (free-down))
        :effect
            (forall (?p ?q - pos) (when (and (at ?p) (down-of ?p ?q)) (and (at ?q) (not (at ?p)))))
    )

    (:action move-left
        :precondition (and (not (need-start)) (free-left))
        :effect
            (forall (?p ?q - pos) (when (and (at ?p) (left-of ?p ?q)) (and (at ?q) (not (at ?p)))))
    )

    (:action move-right
        :precondition (and (not (need-start)) (free-right))
        :effect
            (forall (?p ?q - pos) (when (and (at ?p) (right-of ?p ?q)) (and (at ?q) (not (at ?p)))))
    )
)

