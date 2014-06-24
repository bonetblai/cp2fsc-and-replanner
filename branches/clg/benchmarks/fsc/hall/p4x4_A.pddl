(define (problem p4x4)
  (:domain hall-A)
  (:objects x1 x2 x3 x4 - xpos y1 y2 y3 y4 - ypos)
  (:init
    (suc-x x1 x2) (suc-x x2 x3) (suc-x x3 x4)
    (suc-y y1 y2) (suc-y y2 y3) (suc-y y3 y4)
    (extreme-x x1) (extreme-x x4) (extreme-y y1) (extreme-y y4)
    (agent-y y1)
    (oneof (agent-x x1) (agent-x x2) (agent-x x3))
    (corner x1 y1)
    (corner x4 y1)
    (corner x1 y4)
    (corner x4 y4)
  )
  (:goal (and (agent-x x1) (agent-y y1) (visited x1 y1) (visited x4 y1) (visited x1 y4) (visited x4 y4)))
)

