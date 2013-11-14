(define (domain grid-R)
  (:requirements :equality)
  (:types xpos ypos dir)
  (:predicates (suc-x ?x1 ?x2 - xpos)
               (suc-y ?y1 ?y2 - ypos)
               (agent-x ?x - xpos)
               (agent-y ?y - ypos)
               (north) (east) (south) (west)
               (prize ?x - xpos ?y - ypos)
               (got-it)
               (leftmost-col ?x - xpos) (rightmost-col ?x - xpos)
               (top-row ?y - ypos) (bottom-row ?y - ypos)
               (wall) (nowall)
  )

  (:action Forward
    :effect
      (and (forall (?x1 ?x2 - xpos)
             (and (when (and (east) (suc-x ?x1 ?x2) (agent-x ?x1))
                    (and (not (agent-x ?x1)) (agent-x ?x2)))
                  (when (and (west) (suc-x ?x1 ?x2) (agent-x ?x2))
                    (and (not (agent-x ?x2)) (agent-x ?x1)))))
           (forall (?y1 ?y2 - ypos)
             (and (when (and (north) (suc-y ?y1 ?y2) (agent-y ?y1))
                    (and (not (agent-y ?y1)) (agent-y ?y2)))
                  (when (and (south) (suc-y ?y1 ?y2) (agent-y ?y2))
                    (and (not (agent-y ?y2)) (agent-y ?y1)))))
      )
  )
  (:action TurnRight
    :effect
      (and (when (north) (and (not (north)) (east)))
           (when (east) (and (not (east)) (south)))
           (when (south) (and (not (south)) (west)))
           (when (west) (and (not (west)) (north)))
      )
  )
  (:action TurnLeft
    :effect
      (and (when (north) (and (not (north)) (west)))
           (when (west) (and (not (west)) (south)))
           (when (south) (and (not (south)) (east)))
           (when (east) (and (not (east)) (north)))
      )
  )

  (:axiom get-prize
    :parameters (?x - xpos ?y - ypos)
    :body (and (agent-x ?x) (agent-y ?y) (prize ?x ?y))
    :head (got-it)
  )

  (:axiom set-wall-x1
    :parameters (?x - xpos)
    :body (and (leftmost-col ?x) (agent-x ?x) (west))
    :head (wall))
  (:axiom set-wall-x2
    :parameters (?x - xpos)
    :body (and (rightmost-col ?x) (agent-x ?x) (east))
    :head (wall))
  (:axiom set-wall-y1
    :parameters (?y - ypos)
    :body (and (top-row ?y) (agent-y ?y) (north))
    :head (wall))
  (:axiom set-wall-y2
    :parameters (?y - ypos)
    :body (and (bottom-row ?y) (agent-y ?y) (south))
    :head (wall))
 
  (:axiom set-nowall-inside
    :parameters (?x - xpos ?y - ypos)
    :body (and (not (leftmost-col ?x)) (not (rightmost-col ?x))
               (not (top-row ?y)) (not (bottom-row ?y))
               (agent-x ?x) (agent-y ?y))
    :head (nowall)
  )

  (:axiom set-nowall-corner1
    :parameters (?x - xpos ?y - ypos)
    :body (and (leftmost-col ?x) (bottom-row ?y)
               (agent-x ?x) (agent-y ?y) (north))
    :head (nowall)
  )
  (:axiom set-nowall-corner2
    :parameters (?x - xpos ?y - ypos)
    :body (and (leftmost-col ?x) (bottom-row ?y)
               (agent-x ?x) (agent-y ?y) (east))
    :head (nowall)
  )
  (:axiom set-nowall-corner3
    :parameters (?x - xpos ?y - ypos)
    :body (and (rightmost-col ?x) (bottom-row ?y)
               (agent-x ?x) (agent-y ?y) (north))
    :head (nowall)
  )
  (:axiom set-nowall-corner4
    :parameters (?x - xpos ?y - ypos)
    :body (and (rightmost-col ?x) (bottom-row ?y)
               (agent-x ?x) (agent-y ?y) (west))
    :head (nowall)
  )
  (:axiom set-nowall-corner5
    :parameters (?x - xpos ?y - ypos)
    :body (and (leftmost-col ?x) (top-row ?y)
               (agent-x ?x) (agent-y ?y) (south))
    :head (nowall)
  )
  (:axiom set-nowall-corner6
    :parameters (?x - xpos ?y - ypos)
    :body (and (leftmost-col ?x) (top-row ?y)
               (agent-x ?x) (agent-y ?y) (east))
    :head (nowall)
  )
  (:axiom set-nowall-corner7
    :parameters (?x - xpos ?y - ypos)
    :body (and (rightmost-col ?x) (top-row ?y)
               (agent-x ?x) (agent-y ?y) (south))
    :head (nowall)
  )
  (:axiom set-nowall-corner8
    :parameters (?x - xpos ?y - ypos)
    :body (and (rightmost-col ?x) (top-row ?y)
               (agent-x ?x) (agent-y ?y) (west))
    :head (nowall)
  )

  (:axiom set-nowall-border1
    :parameters (?x - xpos ?y - ypos)
    :body (and (not (leftmost-col ?x)) (not (rightmost-col ?x))
               (bottom-row ?y) (agent-x ?x) (agent-y ?y) (north))
    :head (nowall)
  )
  (:axiom set-nowall-border2
    :parameters (?x - xpos ?y - ypos)
    :body (and (not (leftmost-col ?x)) (not (rightmost-col ?x))
               (bottom-row ?y) (agent-x ?x) (agent-y ?y) (east))
    :head (nowall)
  )
  (:axiom set-nowall-border3
    :parameters (?x - xpos ?y - ypos)
    :body (and (not (leftmost-col ?x)) (not (rightmost-col ?x))
               (bottom-row ?y) (agent-x ?x) (agent-y ?y) (west))
    :head (nowall)
  )
  (:axiom set-nowall-border4
    :parameters (?x - xpos ?y - ypos)
    :body (and (not (leftmost-col ?x)) (not (rightmost-col ?x))
               (top-row ?y) (agent-x ?x) (agent-y ?y) (south))
    :head (nowall)
  )
  (:axiom set-nowall-border5
    :parameters (?x - xpos ?y - ypos)
    :body (and (not (leftmost-col ?x)) (not (rightmost-col ?x))
               (top-row ?y) (agent-x ?x) (agent-y ?y) (east))
    :head (nowall)
  )
  (:axiom set-nowall-border6
    :parameters (?x - xpos ?y - ypos)
    :body (and (not (leftmost-col ?x)) (not (rightmost-col ?x))
               (top-row ?y) (agent-x ?x) (agent-y ?y) (west))
    :head (nowall)
  )
  (:axiom set-nowall-border7
    :parameters (?x - xpos ?y - ypos)
    :body (and (leftmost-col ?x) (not (top-row ?y))
               (not (bottom-row ?y)) (agent-x ?x) (agent-y ?y) (north))
    :head (nowall)
  )
  (:axiom set-nowall-border8
    :parameters (?x - xpos ?y - ypos)
    :body (and (leftmost-col ?x) (not (top-row ?y))
               (not (bottom-row ?y)) (agent-x ?x) (agent-y ?y) (east))
    :head (nowall)
  )
  (:axiom set-nowall-border9
    :parameters (?x - xpos ?y - ypos)
    :body (and (leftmost-col ?x) (not (top-row ?y))
               (not (bottom-row ?y)) (agent-x ?x) (agent-y ?y) (south))
    :head (nowall)
  )
  (:axiom set-nowall-border10
    :parameters (?x - xpos ?y - ypos)
    :body (and (rightmost-col ?x) (not (top-row ?y))
               (not (bottom-row ?y)) (agent-x ?x) (agent-y ?y) (north))
    :head (nowall)
  )
  (:axiom set-nowall-border11
    :parameters (?x - xpos ?y - ypos)
    :body (and (rightmost-col ?x) (not (top-row ?y))
               (not (bottom-row ?y)) (agent-x ?x) (agent-y ?y) (west))
    :head (nowall)
  )
  (:axiom set-nowall-border12
    :parameters (?x - xpos ?y - ypos)
    :body (and (rightmost-col ?x) (not (top-row ?y))
               (not (bottom-row ?y)) (agent-x ?x) (agent-y ?y) (south))
    :head (nowall)
  )

  (:observable (wall) (nowall))
  (:sticky (got-it))
)

