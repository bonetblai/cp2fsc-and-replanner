(define (domain grid-A2)
  (:requirements :equality)
  (:types xpos ypos)
  (:predicates (suc-x ?x1 ?x2 - xpos)
               (suc-y ?y1 ?y2 - ypos)
               (agent-x ?x - xpos)
               (agent-y ?y - ypos)
               (prize-x ?x - xpos)
               (prize-y ?y - ypos)
               (got-it)
               (top-row ?y - ypos) (bottom-row ?y - ypos)
               (leftmost-col ?x - xpos) (rightmost-col ?x - xpos)
               (obs-t) (no-obs-t)
               (obs-b) (no-obs-b)
               (obs-l) (no-obs-l)
               (obs-r) (no-obs-r)
  )

  (:action Right
    :effect
      (forall (?x1 ?x2 - xpos)
        (when (and (suc-x ?x1 ?x2) (agent-x ?x1))
          (and (not (agent-x ?x1)) (agent-x ?x2))))
  )
  (:action Left
    :effect
      (forall (?x1 ?x2 - xpos)
        (when (and (suc-x ?x1 ?x2) (agent-x ?x2))
          (and (not (agent-x ?x2)) (agent-x ?x1))))
  )
  (:action Up
    :effect
      (forall (?y1 ?y2 - ypos)
        (when (and (suc-y ?y1 ?y2) (agent-y ?y1))
          (and (not (agent-y ?y1)) (agent-y ?y2))))
  )
  (:action Down
    :effect
      (forall (?y1 ?y2 - ypos)
        (when (and (suc-y ?y1 ?y2) (agent-y ?y2))
          (and (not (agent-y ?y2)) (agent-y ?y1))))
  )

  (:axiom get-prize
    :parameters (?x - xpos ?y - ypos)
    :body (and (agent-x ?x) (prize-x ?x) (agent-y ?y) (prize-y ?y))
    :head (got-it)
  )

  (:axiom set-obs-t
    :parameters (?y - ypos)
    :body (and (top-row ?y) (agent-y ?y))
    :head (obs-t))
  (:axiom set-no-obs-t
    :parameters (?y - ypos)
    :body (and (not (top-row ?y)) (agent-y ?y))
    :head (no-obs-t))
  (:axiom set-obs-b
    :parameters (?y - ypos)
    :body (and (bottom-row ?y) (agent-y ?y))
    :head (obs-b))
  (:axiom set-no-obs-b
    :parameters (?y - ypos)
    :body (and (not (bottom-row ?y)) (agent-y ?y))
    :head (no-obs-b))
  (:axiom set-obs-l
    :parameters (?x - xpos)
    :body (and (leftmost-col ?x) (agent-x ?x))
    :head (obs-l))
  (:axiom set-no-obs-l
    :parameters (?x - xpos)
    :body (and (not (leftmost-col ?x)) (agent-x ?x))
    :head (no-obs-l))
  (:axiom set-obs-r
    :parameters (?x - xpos)
    :body (and (rightmost-col ?x) (agent-x ?x))
    :head (obs-r))
  (:axiom set-no-obs-r
    :parameters (?x - xpos)
    :body (and (not (rightmost-col ?x)) (agent-x ?x))
    :head (no-obs-r))

  (:observable (obs-t) (no-obs-t) (obs-b) (no-obs-b) (obs-l) (no-obs-l) (obs-r) (no-obs-r))
  (:sticky (got-it))
)

