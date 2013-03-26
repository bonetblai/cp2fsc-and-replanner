(define (domain rocksample)
    (:requirements :typing :equality)
    (:types pos rock)
    (:predicates
        (suc ?x ?y - pos)
        (at ?x ?y - pos)
        (rock-pos ?r - rock ?x ?y - pos)
        (good ?r - rock)
        (sampled ?r - rock)
        (not-sensing)
        (sensing ?r - rock)
        (nearby ?p1 ?p2 - pos)
    )

    (:action move-east
        :parameters (?x ?y1 ?y2 - pos)
        :precondition (and (not-sensing) (at ?x ?y1) (suc ?y1 ?y2))
        :effect (and (not (at ?x ?y1)) (at ?x ?y2))
    )
    (:action move-west
        :parameters (?x ?y1 ?y2 - pos)
        :precondition (and (not-sensing) (at ?x ?y1) (suc ?y2 ?y1))
        :effect (and (not (at ?x ?y1)) (at ?x ?y2))
    )
    (:action move-north
        :parameters (?x1 ?x2 ?y - pos)
        :precondition (and (not-sensing) (at ?x1 ?y) (suc ?x1 ?x2))
        :effect (and (not (at ?x1 ?y)) (at ?x2 ?y))
    )
    (:action move-down
        :parameters (?x1 ?x2 ?y - pos)
        :precondition (and (not-sensing) (at ?x1 ?y) (suc ?x2 ?x1))
        :effect (and (not (at ?x1 ?y)) (at ?x2 ?y))
    )
    (:action sample
        :parameters (?r - rock ?x ?y - pos)
        :precondition (and (not-sensing) (at ?x ?y) (rock-pos ?r ?x ?y) (good ?r))
        :effect (sampled ?r)
    )
    (:action fake-sample
        :parameters (?r - rock) ; ?x ?y - pos)
        :precondition (and (not-sensing)) ; (at ?x ?y) (rock-pos ?r ?x ?y))
        :effect (when (and (not (good ?r))) (sampled ?r))
    )
    (:action activate-sensor
        :parameters (?r - rock)
        :precondition (not-sensing)
        :effect (and (sensing ?r) (not (not-sensing)))
    )
    (:action deactivate-sensor
        :parameters (?r - rock)
        :precondition (sensing ?r)
        :effect (and (not-sensing) (not (sensing ?r)))
    )

    (:sensor rock-sensor
        :parameters (?r - rock ?x ?y ?rx ?ry - pos)
        :condition (and (sensing ?r) (at ?x ?y) (rock-pos ?r ?rx ?y) (nearby ?x ?rx) (nearby ?y ?ry))
        :sensed (good ?r)
    )
)

