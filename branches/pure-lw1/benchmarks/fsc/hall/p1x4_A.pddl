(define (problem p1x4)
  (:domain hall-A)
  (:objects x1 x2 x3 x4 - xpos y1 - ypos)
  (:init
    (suc-x x1 x2) (suc-x x2 x3) (suc-x x3 x4)
    (extreme-x x1) (extreme-x x4) (extreme-y y1)
    (agent-y y1)
    (oneof (agent-x x1) (agent-x x2) (agent-x x3))
    (corner x1 y1)
    (corner x4 y1)
  )
  (:goal (and (agent-x x1) (agent-y y1) (visited x1 y1) (visited x4 y1)))
)

