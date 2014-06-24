(define (domain hall-A)
  (:requirements :equality)
  (:types xpos ypos)
  (:predicates (suc-x ?x1 ?x2 - xpos)
               (suc-y ?y1 ?y2 - ypos)
               (agent-x ?x - xpos)
               (agent-y ?y - ypos)
               (corner ?x - xpos ?y - ypos)
               (at-corner ?x - xpos ?y - ypos)
               (visited ?x - xpos ?y - ypos)
               (null-obs)
               (extreme-x ?x - xpos)
               (extreme-y ?y - ypos)
  )

  (:action move-right
    :effect
      (forall (?x1 ?x2 - xpos ?y - ypos)
        (when (and (suc-x ?x1 ?x2) (extreme-y ?y) (agent-x ?x1) (agent-y ?y))
          (and (not (agent-x ?x1)) (agent-x ?x2))))
  )
  (:action move-left
    :effect
      (forall (?x1 ?x2 - xpos ?y - ypos)
        (when (and (suc-x ?x1 ?x2) (extreme-y ?y) (agent-x ?x2) (agent-y ?y))
          (and (not (agent-x ?x2)) (agent-x ?x1))))
  )
  (:action move-up
    :effect
      (forall (?y1 ?y2 - ypos ?x - xpos)
        (when (and (suc-y ?y1 ?y2) (extreme-x ?x) (agent-x ?x) (agent-y ?y1))
          (and (not (agent-y ?y1)) (agent-y ?y2))))
  )
  (:action move-down
    :effect
      (forall (?y1 ?y2 - ypos ?x - xpos)
        (when (and (suc-y ?y1 ?y2) (extreme-x ?x) (agent-x ?x) (agent-y ?y2))
          (and (not (agent-y ?y2)) (agent-y ?y1))))
  )

  (:axiom visit-corner
    :parameters (?x - xpos ?y - ypos)
    :body (and (agent-x ?x) (agent-y ?y) (corner ?x ?y))
    :head (and (visited ?x ?y) (at-corner ?x ?y))
  )
  (:axiom no-corner
    :parameters (?x - xpos ?y - ypos)
    :body (and (agent-x ?x) (agent-y ?y) (not (corner ?x ?y)))
    :head (null-obs)
  )

  (:observable (null-obs) (forall (?x - xpos ?y - ypos) (at-corner ?x ?y)))
  (:sticky (forall (?x - xpos ?y - ypos) (visited ?x ?y)))
)

