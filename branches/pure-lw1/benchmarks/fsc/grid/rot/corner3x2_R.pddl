(define (problem corner3x2)
  (:domain grid-R)
  (:objects x1 x2 x3 - xpos y1 y2 - ypos)
  (:init
    (suc-x x1 x2) (suc-x x2 x3)
    (suc-y y1 y2)
    (top-row y2) (bottom-row y1) (leftmost-col x1) (rightmost-col x3)
    (north)
    (oneof (agent-x x1) (agent-x x2) (agent-x x3))
    (oneof (agent-y y1) (agent-y y2))
  )
  (:goal (and (agent-x x1) (agent-y y1)))
)

