(define (problem p-grid5x5-blocks10)
  (:domain visual-marker)
  (:objects x1 x2 x3 x4 x5 - xpos y2 y3 y4 y5 - ypos)
  (:init
    (suc-x x1 x2) (suc-x x2 x3) (suc-x x3 x4) (suc-x x4 x5)
    (suc-y y1 y2) (suc-y y2 y3) (suc-y y3 y4) (suc-y y4 y5)
    (agent-x x1) (agent-y y1)

    (block x1 y1) (block x1 y2) (block x1 y3)
    (block x2 y1)
    (block x3 y1) (block x3 y2) (block x3 y3) (block x3 y4)
    (block x5 y1) (block x5 y2)

    (oneof (green x1 y1) (green x1 y2) (green x1 y3)
           (green x2 y1)
           (green x3 y1) (green x3 y2) (green x3 y3) (green x3 y4)
           (green x5 y1) (green x5 y2)
    )
  )
  (:goal (marked))
)

