(define (domain balls)
    (:requirements :typing :equality)
    (:types pos ball)
    (:predicates
        (suc ?x ?y - pos)
        (ball-at ?b - ball ?x ?y - pos)
        (ball-in-bag ?b)
        (at ?x ?y - pos)
    )

    (:action up
        :parameters (?x ?y1 ?y2 - pos)
        :precondition (and (at ?x ?y1) (suc ?y1 ?y2))
        :effect (and (not (at ?x ?y1)) (at ?x ?y2))
    )
    (:action down
        :parameters (?x ?y1 ?y2 - pos)
        :precondition (and (at ?x ?y1) (suc ?y2 ?y1))
        :effect (and (not (at ?x ?y1)) (at ?x ?y2))
    )
    (:action right
        :parameters (?x1 ?x2 ?y - pos)
        :precondition (and (at ?x1 ?y) (suc ?x1 ?x2))
        :effect (and (not (at ?x1 ?y)) (at ?x2 ?y))
    )
    (:action left
        :parameters (?x1 ?x2 ?y - pos)
        :precondition (and (at ?x1 ?y) (suc ?x2 ?x1))
        :effect (and (not (at ?x1 ?y)) (at ?x2 ?y))
    )
    (:action pick-up
        :parameters (?b - ball ?x ?y - pos)
        :precondition (and (at ?x ?y) (ball-at ?b ?x ?y))
        :effect (and (not (ball-at ?b ?x ?y)) (ball-in-bag ?b))
    )

    (:sensor ball-pos
        :parameters (?b - ball ?x ?y - pos)
        :condition (at ?x ?y)
        :sense (ball-at ?b ?x ?y)
    )
)

