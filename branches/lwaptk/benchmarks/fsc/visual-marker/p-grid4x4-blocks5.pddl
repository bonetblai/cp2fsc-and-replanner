(define (problem p-grid4x4-blocks5)
  (:domain visual-marker)
  (:objects x1 x2 x3 x4 - xpos y2 y3 y4 - ypos)
  (:init
    (suc-x x1 x2) (suc-x x2 x3) (suc-x x3 x4)
    (suc-y y1 y2) (suc-y y2 y3) (suc-y y3 y4)
    (agent-x x1) (agent-y y1)

    (block x1 y1) (block x1 y2)
    (block x3 y1) (block x3 y2) (block x3 y3)

    (oneof (green x1 y1) (green x1 y2)
           (green x3 y1) (green x3 y2) (green x3 y3)
    )
  )
  (:goal (marked))
)

