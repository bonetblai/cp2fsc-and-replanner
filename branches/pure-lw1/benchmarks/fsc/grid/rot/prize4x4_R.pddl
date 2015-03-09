(define (problem prize4x4)
  (:domain grid-R)
  (:objects x1 x2 x3 x4 - xpos y1 y2 y3 y4 - ypos)
  (:init
    (suc-x x1 x2) (suc-x x2 x3) (suc-x x3 x4)
    (suc-y y1 y2) (suc-y y2 y3) (suc-y y3 y4)
    (top-row y4) (bottom-row y1) (leftmost-col x1) (rightmost-col x4)
    (agent-x x1) (agent-y y1) (north)
    (oneof (prize x1 y1) (prize x2 y1) (prize x3 y1) (prize x4 y1)
           (prize x1 y2) (prize x2 y2) (prize x3 y2) (prize x4 y2)
           (prize x1 y3) (prize x2 y3) (prize x3 y3) (prize x4 y3)
           (prize x1 y4) (prize x2 y4) (prize x3 y4) (prize x4 y4)
    )
  )
  (:goal (got-it))
)
