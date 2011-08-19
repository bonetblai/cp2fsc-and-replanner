(define (problem corner2x2)
  (:domain grid-R)
  (:objects x1 x2 - xpos y1 y2 - ypos)
  (:init
    (suc-x x1 x2)
    (suc-y y1 y2)
    (top-row y2) (bottom-row y1) (leftmost-col x1) (rightmost-col x2)
    (north)
    (oneof (agent-x x1) (agent-x x2))
    (oneof (agent-y y1) (agent-y y2))
  )
  (:goal (and (agent-x x1) (agent-y y1)))
)

