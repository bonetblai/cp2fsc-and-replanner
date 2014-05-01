(define (problem corner4x2)
  (:domain grid-A)
  (:objects x1 x2 x3 x4 - xpos y1 y2 - ypos)
  (:init
    (suc-x x1 x2) (suc-x x2 x3) (suc-x x3 x4)
    (suc-y y1 y2)
    (top-row y2) (bottom-row y1) (leftmost-col x1) (rightmost-col x4)
    (oneof (agent-x x1) (agent-x x2) (agent-x x3) (agent-x x4))
    (oneof (agent-y y1) (agent-y y2))
  )
  (:goal (and (agent-x x1) (agent-y y1)))
)

