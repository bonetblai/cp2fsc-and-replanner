(define (domain visual-marker)
  (:types xpos ypos)
  (:predicates (suc-x ?x1 ?x2 - xpos)
               (suc-y ?y1 ?y2 - ypos)
               (agent-x ?x - xpos)
               (agent-y ?y - ypos)
               (block ?x - xpos ?y - ypos)
               (green ?x - xpos ?y - ypos)
               (obs-not-table) (obs-table) (obs-clear) (obs-block) (obs-green)
               (marked)
     
  )
  (:constants y1 - ypos)

  (:action move-up
    :effect
      (forall (?y1 ?y2 - ypos)
        (when (and (suc-y ?y1 ?y2) (agent-y ?y1))
          (and (agent-y ?y2) (not (agent-y ?y1)))))
  )
  (:action move-down
    :effect
      (forall (?y1 ?y2 - ypos)
        (when (and (suc-y ?y1 ?y2) (agent-y ?y2))
          (and (agent-y ?y1) (not (agent-y ?y2)))))
  )
  (:action move-right
    :effect
      (forall (?x1 ?x2 - xpos)
        (when (and (suc-x ?x1 ?x2) (agent-x ?x1))
          (and (agent-x ?x2) (not (agent-x ?x1)))))
  )
  (:action move-left
    :effect
      (forall (?x1 ?x2 - xpos)
        (when (and (suc-x ?x1 ?x2) (agent-x ?x2))
          (and (agent-x ?x1) (not (agent-x ?x2)))))
  )
  (:action mark-green-block
    :effect
      (forall (?x - xpos ?y - ypos)
        (when (and (agent-x ?x) (agent-y ?y) (green ?x ?y))
          (marked)))
  )

  (:axiom set-table :body (agent-y y1) :head (obs-table))
  (:axiom set-not-table :body (not (agent-y y1)) :head (obs-not-table))
  (:axiom set-block
    :parameters (?x - xpos ?y - ypos)
    :body (and (agent-x ?x) (agent-y ?y) (block ?x ?y) (not (green ?x ?y)))
    :head (obs-block)
  )
  (:axiom set-green-block
    :parameters (?x - xpos ?y - ypos)
    :body (and (agent-x ?x) (agent-y ?y) (block ?x ?y) (green ?x ?y))
    :head (obs-green)
  )
  (:axiom set-clear
    :parameters (?x - xpos ?y - ypos)
    :body (and (agent-x ?x) (agent-y ?y) (not (block ?x ?y)))
    :head (obs-clear)
  )

  (:observable (obs-table) (obs-not-table) (obs-block) (obs-green) (obs-clear))
)

