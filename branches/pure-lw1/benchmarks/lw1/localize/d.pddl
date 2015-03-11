(define (domain localize) 
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
        (at ?p - pos)
        (free-up)
        (free-down)
        (free-left)
        (free-right)
    )

    (:variable (position) (forall (?p - pos) (when (possible ?p) (at ?p))))
    (:obs-variable obs-up (free-up))
    (:obs-variable obs-right (free-right))
    (:obs-variable obs-down (free-down))
    (:obs-variable obs-left (free-left))

    ; the following is abbreviation: it's equivalent to writing the same sensing at each action
    (:default-sensing
        (:model-for obs-up (free-up) (exists (?p - pos) (and (at ?p) (possible ?p) (not (wall-up-of ?p)))))
        (:model-for obs-up (not (free-up)) (exists (?p - pos) (and (at ?p) (possible ?p) (wall-up-of ?p))))
        (:model-for obs-right (free-right) (exists (?p - pos) (and (at ?p) (possible ?p) (not (wall-right-of ?p)))))
        (:model-for obs-right (not (free-right)) (exists (?p - pos) (and (at ?p) (possible ?p) (wall-right-of ?p))))
        (:model-for obs-down (free-down) (exists (?p - pos) (and (at ?p) (possible ?p) (not (wall-down-of ?p)))))
        (:model-for obs-down (not (free-down)) (exists (?p - pos) (and (at ?p) (possible ?p) (wall-down-of ?p))))
        (:model-for obs-left (free-left) (exists (?p - pos) (and (at ?p) (possible ?p) (not (wall-left-of ?p)))))
        (:model-for obs-left (not (free-left)) (exists (?p - pos) (and (at ?p) (possible ?p) (wall-left-of ?p))))
    )

    (:action start
        :precondition (need-start)
        :effect (not (need-start))
    )
    (:action move-up
        :precondition (and (not (need-start)) (free-up))
        :effect (forall (?p ?q - pos) (when (and (at ?p) (up-of ?p ?q)) (and (at ?q) (not (at ?p)))))
    )
    (:action move-down
        :precondition (and (not (need-start)) (free-down))
        :effect (forall (?p ?q - pos) (when (and (at ?p) (down-of ?p ?q)) (and (at ?q) (not (at ?p)))))
    )
    (:action move-left
        :precondition (and (not (need-start)) (free-left))
        :effect (forall (?p ?q - pos) (when (and (at ?p) (left-of ?p ?q)) (and (at ?q) (not (at ?p)))))
    )
    (:action move-right
        :precondition (and (not (need-start)) (free-right))
        :effect (forall (?p ?q - pos) (when (and (at ?p) (right-of ?p ?q)) (and (at ?q) (not (at ?p)))))
    )
)

