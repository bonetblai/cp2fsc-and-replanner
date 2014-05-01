(define (domain freespace)
    (:requirements :typing :equality)
    (:types xpos ypos)
    (:predicates
        (suc-x ?x1 ?x2 - xpos)
        (suc-y ?y1 ?y2 - ypos)
        (wall ?x - xpos ?y - ypos)
        (at ?x - xpos ?y - ypos)
    )

    (:action up
        :parameters (?x - xpos ?y1 ?y2 - ypos)
        :precondition (and (at ?x ?y1) (suc-y ?y1 ?y2) (not (wall ?x ?y2)))
        :effect (and (not (at ?x ?y1)) (at ?x ?y2))
    )
    (:action down
        :parameters (?x - xpos ?y1 ?y2 - ypos)
        :precondition (and (at ?x ?y1) (suc-y ?y2 ?y1) (not (wall ?x ?y2)))
        :effect (and (not (at ?x ?y1)) (at ?x ?y2))
    )
    (:action right
        :parameters (?x1 ?x2 - xpos ?y - ypos)
        :precondition (and (at ?x1 ?y) (suc-x ?x1 ?x2) (not (wall ?x2 ?y)))
        :effect (and (not (at ?x1 ?y)) (at ?x2 ?y))
    )
    (:action left
        :parameters (?x1 ?x2 - xpos ?y - ypos)
        :precondition (and (at ?x1 ?y) (suc-x ?x2 ?x1) (not (wall ?x2 ?y)))
        :effect (and (not (at ?x1 ?y)) (at ?x2 ?y))
    )

    (:sensor north-wall
        :parameters (?x - xpos ?y1 ?y2 - ypos)
        :condition (and (at ?x ?y1) (suc-y ?y1 ?y2))
        :sense (wall ?x ?y2)
    )
    (:sensor south-wall
        :parameters (?x - xpos ?y1 ?y2 - ypos)
        :condition (and (at ?x ?y1) (suc-y ?y2 ?y1))
        :sense (wall ?x ?y2)
    )
    (:sensor east-wall
        :parameters (?x1 ?x2 - xpos ?y - ypos)
        :condition (and (at ?x1 ?y) (suc-x ?x1 ?x2))
        :sense (wall ?x2 ?y)
    )
    (:sensor west-wall
        :parameters (?x1 ?x2 - xpos ?y - ypos)
        :condition (and (at ?x1 ?y) (suc-x ?x2 ?x1))
        :sense (wall ?x2 ?y)
    )
)

