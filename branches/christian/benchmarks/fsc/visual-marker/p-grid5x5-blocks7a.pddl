(define (problem p-grid5x5-blocks7a)
  (:domain visual-marker)
  (:objects x1 x2 x3 x4 x5 - xpos y2 y3 y4 y5 - ypos)
  (:init
    (suc-x x1 x2) (suc-x x2 x3) (suc-x x3 x4) (suc-x x4 x5)
    (suc-y y1 y2) (suc-y y2 y3) (suc-y y3 y4) (suc-y y4 y5)
    (agent-x x1) (agent-y y1)

    (block x1 y1) (block x1 y2)
    (block x2 y1) (block x2 y2) (block x2 y3)
    (block x4 y1) (block x4 y2)

    (oneof (green x1 y1) (green x1 y2)
           (green x2 y1) (green x2 y2) (green x2 y3)
           (green x4 y1) (green x4 y2)
    )
  )
  (:goal (marked))
)

