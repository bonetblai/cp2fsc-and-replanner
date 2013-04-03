(define (problem wumpus_5_1_1_19371)
  (:domain wumpus)
  (:objects p_1_1 p_1_2 p_1_3 p_1_4 p_1_5 p_2_1 p_2_2 p_2_3 p_2_4 p_2_5 p_3_1 p_3_2 p_3_3 p_3_4 p_3_5 p_4_1 p_4_2 p_4_3 p_4_4 p_4_5 p_5_1 p_5_2 p_5_3 p_5_4 p_5_5 - pos
  )
  (:init
    ;; Known
    (at p_1_1)
    (alive)

    ;; Adjacencies
 (adj p_1_1 p_1_2) (adj p_1_1 p_2_1) (adj p_1_2 p_1_1) (adj p_1_2 p_1_3) (adj p_1_2 p_2_2) (adj p_1_3 p_1_2) (adj p_1_3 p_1_4) (adj p_1_3 p_2_3) (adj p_1_4 p_1_3) (adj p_1_4 p_1_5) (adj p_1_4 p_2_4) (adj p_1_5 p_1_4) (adj p_1_5 p_2_5) (adj p_2_1 p_1_1) (adj p_2_1 p_2_2) (adj p_2_1 p_3_1) (adj p_2_2 p_1_2) (adj p_2_2 p_2_1) (adj p_2_2 p_2_3) (adj p_2_2 p_3_2) (adj p_2_3 p_1_3) (adj p_2_3 p_2_2) (adj p_2_3 p_2_4) (adj p_2_3 p_3_3) (adj p_2_4 p_1_4) (adj p_2_4 p_2_3) (adj p_2_4 p_2_5) (adj p_2_4 p_3_4) (adj p_2_5 p_1_5) (adj p_2_5 p_2_4) (adj p_2_5 p_3_5) (adj p_3_1 p_2_1) (adj p_3_1 p_3_2) (adj p_3_1 p_4_1) (adj p_3_2 p_2_2) (adj p_3_2 p_3_1) (adj p_3_2 p_3_3) (adj p_3_2 p_4_2) (adj p_3_3 p_2_3) (adj p_3_3 p_3_2) (adj p_3_3 p_3_4) (adj p_3_3 p_4_3) (adj p_3_4 p_2_4) (adj p_3_4 p_3_3) (adj p_3_4 p_3_5) (adj p_3_4 p_4_4) (adj p_3_5 p_2_5) (adj p_3_5 p_3_4) (adj p_3_5 p_4_5) (adj p_4_1 p_3_1) (adj p_4_1 p_4_2) (adj p_4_1 p_5_1) (adj p_4_2 p_3_2) (adj p_4_2 p_4_1) (adj p_4_2 p_4_3) (adj p_4_2 p_5_2) (adj p_4_3 p_3_3) (adj p_4_3 p_4_2) (adj p_4_3 p_4_4) (adj p_4_3 p_5_3) (adj p_4_4 p_3_4) (adj p_4_4 p_4_3) (adj p_4_4 p_4_5) (adj p_4_4 p_5_4) (adj p_4_5 p_3_5) (adj p_4_5 p_4_4) (adj p_4_5 p_5_5) (adj p_5_1 p_4_1) (adj p_5_1 p_5_2) (adj p_5_2 p_4_2) (adj p_5_2 p_5_1) (adj p_5_2 p_5_3) (adj p_5_3 p_4_3) (adj p_5_3 p_5_2) (adj p_5_3 p_5_4) (adj p_5_4 p_4_4) (adj p_5_4 p_5_3) (adj p_5_4 p_5_5) (adj p_5_5 p_4_5) (adj p_5_5 p_5_4)

    ;; Unknows
    (at-least-one (wumpus p_1_1) (not (wumpus p_1_1)))
    (at-least-one (stench p_1_1) (not (stench p_1_1)))
    (at-least-one (pit p_1_1) (not (pit p_1_1)))
    (at-least-one (breeze p_1_1) (not (breeze p_1_1)))
    (at-least-one (glitter p_1_1) (not (glitter p_1_1)))
    (at-least-one (safe p_1_1) (not (safe p_1_1)))
    (at-least-one (wumpus p_1_2) (not (wumpus p_1_2)))
    (at-least-one (stench p_1_2) (not (stench p_1_2)))
    (at-least-one (pit p_1_2) (not (pit p_1_2)))
    (at-least-one (breeze p_1_2) (not (breeze p_1_2)))
    (at-least-one (glitter p_1_2) (not (glitter p_1_2)))
    (at-least-one (safe p_1_2) (not (safe p_1_2)))
    (at-least-one (wumpus p_1_3) (not (wumpus p_1_3)))
    (at-least-one (stench p_1_3) (not (stench p_1_3)))
    (at-least-one (pit p_1_3) (not (pit p_1_3)))
    (at-least-one (breeze p_1_3) (not (breeze p_1_3)))
    (at-least-one (glitter p_1_3) (not (glitter p_1_3)))
    (at-least-one (safe p_1_3) (not (safe p_1_3)))
    (at-least-one (wumpus p_1_4) (not (wumpus p_1_4)))
    (at-least-one (stench p_1_4) (not (stench p_1_4)))
    (at-least-one (pit p_1_4) (not (pit p_1_4)))
    (at-least-one (breeze p_1_4) (not (breeze p_1_4)))
    (at-least-one (glitter p_1_4) (not (glitter p_1_4)))
    (at-least-one (safe p_1_4) (not (safe p_1_4)))
    (at-least-one (wumpus p_1_5) (not (wumpus p_1_5)))
    (at-least-one (stench p_1_5) (not (stench p_1_5)))
    (at-least-one (pit p_1_5) (not (pit p_1_5)))
    (at-least-one (breeze p_1_5) (not (breeze p_1_5)))
    (at-least-one (glitter p_1_5) (not (glitter p_1_5)))
    (at-least-one (safe p_1_5) (not (safe p_1_5)))
    (at-least-one (wumpus p_2_1) (not (wumpus p_2_1)))
    (at-least-one (stench p_2_1) (not (stench p_2_1)))
    (at-least-one (pit p_2_1) (not (pit p_2_1)))
    (at-least-one (breeze p_2_1) (not (breeze p_2_1)))
    (at-least-one (glitter p_2_1) (not (glitter p_2_1)))
    (at-least-one (safe p_2_1) (not (safe p_2_1)))
    (at-least-one (wumpus p_2_2) (not (wumpus p_2_2)))
    (at-least-one (stench p_2_2) (not (stench p_2_2)))
    (at-least-one (pit p_2_2) (not (pit p_2_2)))
    (at-least-one (breeze p_2_2) (not (breeze p_2_2)))
    (at-least-one (glitter p_2_2) (not (glitter p_2_2)))
    (at-least-one (safe p_2_2) (not (safe p_2_2)))
    (at-least-one (wumpus p_2_3) (not (wumpus p_2_3)))
    (at-least-one (stench p_2_3) (not (stench p_2_3)))
    (at-least-one (pit p_2_3) (not (pit p_2_3)))
    (at-least-one (breeze p_2_3) (not (breeze p_2_3)))
    (at-least-one (glitter p_2_3) (not (glitter p_2_3)))
    (at-least-one (safe p_2_3) (not (safe p_2_3)))
    (at-least-one (wumpus p_2_4) (not (wumpus p_2_4)))
    (at-least-one (stench p_2_4) (not (stench p_2_4)))
    (at-least-one (pit p_2_4) (not (pit p_2_4)))
    (at-least-one (breeze p_2_4) (not (breeze p_2_4)))
    (at-least-one (glitter p_2_4) (not (glitter p_2_4)))
    (at-least-one (safe p_2_4) (not (safe p_2_4)))
    (at-least-one (wumpus p_2_5) (not (wumpus p_2_5)))
    (at-least-one (stench p_2_5) (not (stench p_2_5)))
    (at-least-one (pit p_2_5) (not (pit p_2_5)))
    (at-least-one (breeze p_2_5) (not (breeze p_2_5)))
    (at-least-one (glitter p_2_5) (not (glitter p_2_5)))
    (at-least-one (safe p_2_5) (not (safe p_2_5)))
    (at-least-one (wumpus p_3_1) (not (wumpus p_3_1)))
    (at-least-one (stench p_3_1) (not (stench p_3_1)))
    (at-least-one (pit p_3_1) (not (pit p_3_1)))
    (at-least-one (breeze p_3_1) (not (breeze p_3_1)))
    (at-least-one (glitter p_3_1) (not (glitter p_3_1)))
    (at-least-one (safe p_3_1) (not (safe p_3_1)))
    (at-least-one (wumpus p_3_2) (not (wumpus p_3_2)))
    (at-least-one (stench p_3_2) (not (stench p_3_2)))
    (at-least-one (pit p_3_2) (not (pit p_3_2)))
    (at-least-one (breeze p_3_2) (not (breeze p_3_2)))
    (at-least-one (glitter p_3_2) (not (glitter p_3_2)))
    (at-least-one (safe p_3_2) (not (safe p_3_2)))
    (at-least-one (wumpus p_3_3) (not (wumpus p_3_3)))
    (at-least-one (stench p_3_3) (not (stench p_3_3)))
    (at-least-one (pit p_3_3) (not (pit p_3_3)))
    (at-least-one (breeze p_3_3) (not (breeze p_3_3)))
    (at-least-one (glitter p_3_3) (not (glitter p_3_3)))
    (at-least-one (safe p_3_3) (not (safe p_3_3)))
    (at-least-one (wumpus p_3_4) (not (wumpus p_3_4)))
    (at-least-one (stench p_3_4) (not (stench p_3_4)))
    (at-least-one (pit p_3_4) (not (pit p_3_4)))
    (at-least-one (breeze p_3_4) (not (breeze p_3_4)))
    (at-least-one (glitter p_3_4) (not (glitter p_3_4)))
    (at-least-one (safe p_3_4) (not (safe p_3_4)))
    (at-least-one (wumpus p_3_5) (not (wumpus p_3_5)))
    (at-least-one (stench p_3_5) (not (stench p_3_5)))
    (at-least-one (pit p_3_5) (not (pit p_3_5)))
    (at-least-one (breeze p_3_5) (not (breeze p_3_5)))
    (at-least-one (glitter p_3_5) (not (glitter p_3_5)))
    (at-least-one (safe p_3_5) (not (safe p_3_5)))
    (at-least-one (wumpus p_4_1) (not (wumpus p_4_1)))
    (at-least-one (stench p_4_1) (not (stench p_4_1)))
    (at-least-one (pit p_4_1) (not (pit p_4_1)))
    (at-least-one (breeze p_4_1) (not (breeze p_4_1)))
    (at-least-one (glitter p_4_1) (not (glitter p_4_1)))
    (at-least-one (safe p_4_1) (not (safe p_4_1)))
    (at-least-one (wumpus p_4_2) (not (wumpus p_4_2)))
    (at-least-one (stench p_4_2) (not (stench p_4_2)))
    (at-least-one (pit p_4_2) (not (pit p_4_2)))
    (at-least-one (breeze p_4_2) (not (breeze p_4_2)))
    (at-least-one (glitter p_4_2) (not (glitter p_4_2)))
    (at-least-one (safe p_4_2) (not (safe p_4_2)))
    (at-least-one (wumpus p_4_3) (not (wumpus p_4_3)))
    (at-least-one (stench p_4_3) (not (stench p_4_3)))
    (at-least-one (pit p_4_3) (not (pit p_4_3)))
    (at-least-one (breeze p_4_3) (not (breeze p_4_3)))
    (at-least-one (glitter p_4_3) (not (glitter p_4_3)))
    (at-least-one (safe p_4_3) (not (safe p_4_3)))
    (at-least-one (wumpus p_4_4) (not (wumpus p_4_4)))
    (at-least-one (stench p_4_4) (not (stench p_4_4)))
    (at-least-one (pit p_4_4) (not (pit p_4_4)))
    (at-least-one (breeze p_4_4) (not (breeze p_4_4)))
    (at-least-one (glitter p_4_4) (not (glitter p_4_4)))
    (at-least-one (safe p_4_4) (not (safe p_4_4)))
    (at-least-one (wumpus p_4_5) (not (wumpus p_4_5)))
    (at-least-one (stench p_4_5) (not (stench p_4_5)))
    (at-least-one (pit p_4_5) (not (pit p_4_5)))
    (at-least-one (breeze p_4_5) (not (breeze p_4_5)))
    (at-least-one (glitter p_4_5) (not (glitter p_4_5)))
    (at-least-one (safe p_4_5) (not (safe p_4_5)))
    (at-least-one (wumpus p_5_1) (not (wumpus p_5_1)))
    (at-least-one (stench p_5_1) (not (stench p_5_1)))
    (at-least-one (pit p_5_1) (not (pit p_5_1)))
    (at-least-one (breeze p_5_1) (not (breeze p_5_1)))
    (at-least-one (glitter p_5_1) (not (glitter p_5_1)))
    (at-least-one (safe p_5_1) (not (safe p_5_1)))
    (at-least-one (wumpus p_5_2) (not (wumpus p_5_2)))
    (at-least-one (stench p_5_2) (not (stench p_5_2)))
    (at-least-one (pit p_5_2) (not (pit p_5_2)))
    (at-least-one (breeze p_5_2) (not (breeze p_5_2)))
    (at-least-one (glitter p_5_2) (not (glitter p_5_2)))
    (at-least-one (safe p_5_2) (not (safe p_5_2)))
    (at-least-one (wumpus p_5_3) (not (wumpus p_5_3)))
    (at-least-one (stench p_5_3) (not (stench p_5_3)))
    (at-least-one (pit p_5_3) (not (pit p_5_3)))
    (at-least-one (breeze p_5_3) (not (breeze p_5_3)))
    (at-least-one (glitter p_5_3) (not (glitter p_5_3)))
    (at-least-one (safe p_5_3) (not (safe p_5_3)))
    (at-least-one (wumpus p_5_4) (not (wumpus p_5_4)))
    (at-least-one (stench p_5_4) (not (stench p_5_4)))
    (at-least-one (pit p_5_4) (not (pit p_5_4)))
    (at-least-one (breeze p_5_4) (not (breeze p_5_4)))
    (at-least-one (glitter p_5_4) (not (glitter p_5_4)))
    (at-least-one (safe p_5_4) (not (safe p_5_4)))
    (at-least-one (wumpus p_5_5) (not (wumpus p_5_5)))
    (at-least-one (stench p_5_5) (not (stench p_5_5)))
    (at-least-one (pit p_5_5) (not (pit p_5_5)))
    (at-least-one (breeze p_5_5) (not (breeze p_5_5)))
    (at-least-one (glitter p_5_5) (not (glitter p_5_5)))
    (at-least-one (safe p_5_5) (not (safe p_5_5)))

    ;; Inference rules
    (at-least-one (not (wumpus p_1_1)) (stench p_1_2))
    (at-least-one (not (pit p_1_1)) (breeze p_1_2))
    (at-least-one (not (wumpus p_1_1)) (stench p_2_1))
    (at-least-one (not (pit p_1_1)) (breeze p_2_1))
    (at-least-one (not (wumpus p_1_1)) (not (at p_1_1)) (not (alive)))
    (at-least-one (not (pit p_1_1)) (not (at p_1_1)) (not (alive)))
    (at-least-one (wumpus p_1_1) (pit p_1_1) (safe p_1_1))
    (at-least-one (not (glitter p_1_1)) (gold p_1_1))
    (at-least-one (not (wumpus p_1_2)) (stench p_1_1))
    (at-least-one (not (pit p_1_2)) (breeze p_1_1))
    (at-least-one (not (wumpus p_1_2)) (stench p_1_3))
    (at-least-one (not (pit p_1_2)) (breeze p_1_3))
    (at-least-one (not (wumpus p_1_2)) (stench p_2_2))
    (at-least-one (not (pit p_1_2)) (breeze p_2_2))
    (at-least-one (not (wumpus p_1_2)) (not (at p_1_2)) (not (alive)))
    (at-least-one (not (pit p_1_2)) (not (at p_1_2)) (not (alive)))
    (at-least-one (wumpus p_1_2) (pit p_1_2) (safe p_1_2))
    (at-least-one (not (glitter p_1_2)) (gold p_1_2))
    (at-least-one (not (wumpus p_1_3)) (stench p_1_2))
    (at-least-one (not (pit p_1_3)) (breeze p_1_2))
    (at-least-one (not (wumpus p_1_3)) (stench p_1_4))
    (at-least-one (not (pit p_1_3)) (breeze p_1_4))
    (at-least-one (not (wumpus p_1_3)) (stench p_2_3))
    (at-least-one (not (pit p_1_3)) (breeze p_2_3))
    (at-least-one (not (wumpus p_1_3)) (not (at p_1_3)) (not (alive)))
    (at-least-one (not (pit p_1_3)) (not (at p_1_3)) (not (alive)))
    (at-least-one (wumpus p_1_3) (pit p_1_3) (safe p_1_3))
    (at-least-one (not (glitter p_1_3)) (gold p_1_3))
    (at-least-one (not (wumpus p_1_4)) (stench p_1_3))
    (at-least-one (not (pit p_1_4)) (breeze p_1_3))
    (at-least-one (not (wumpus p_1_4)) (stench p_1_5))
    (at-least-one (not (pit p_1_4)) (breeze p_1_5))
    (at-least-one (not (wumpus p_1_4)) (stench p_2_4))
    (at-least-one (not (pit p_1_4)) (breeze p_2_4))
    (at-least-one (not (wumpus p_1_4)) (not (at p_1_4)) (not (alive)))
    (at-least-one (not (pit p_1_4)) (not (at p_1_4)) (not (alive)))
    (at-least-one (wumpus p_1_4) (pit p_1_4) (safe p_1_4))
    (at-least-one (not (glitter p_1_4)) (gold p_1_4))
    (at-least-one (not (wumpus p_1_5)) (stench p_1_4))
    (at-least-one (not (pit p_1_5)) (breeze p_1_4))
    (at-least-one (not (wumpus p_1_5)) (stench p_2_5))
    (at-least-one (not (pit p_1_5)) (breeze p_2_5))
    (at-least-one (not (wumpus p_1_5)) (not (at p_1_5)) (not (alive)))
    (at-least-one (not (pit p_1_5)) (not (at p_1_5)) (not (alive)))
    (at-least-one (wumpus p_1_5) (pit p_1_5) (safe p_1_5))
    (at-least-one (not (glitter p_1_5)) (gold p_1_5))
    (at-least-one (not (wumpus p_2_1)) (stench p_1_1))
    (at-least-one (not (pit p_2_1)) (breeze p_1_1))
    (at-least-one (not (wumpus p_2_1)) (stench p_2_2))
    (at-least-one (not (pit p_2_1)) (breeze p_2_2))
    (at-least-one (not (wumpus p_2_1)) (stench p_3_1))
    (at-least-one (not (pit p_2_1)) (breeze p_3_1))
    (at-least-one (not (wumpus p_2_1)) (not (at p_2_1)) (not (alive)))
    (at-least-one (not (pit p_2_1)) (not (at p_2_1)) (not (alive)))
    (at-least-one (wumpus p_2_1) (pit p_2_1) (safe p_2_1))
    (at-least-one (not (glitter p_2_1)) (gold p_2_1))
    (at-least-one (not (wumpus p_2_2)) (stench p_1_2))
    (at-least-one (not (pit p_2_2)) (breeze p_1_2))
    (at-least-one (not (wumpus p_2_2)) (stench p_2_1))
    (at-least-one (not (pit p_2_2)) (breeze p_2_1))
    (at-least-one (not (wumpus p_2_2)) (stench p_2_3))
    (at-least-one (not (pit p_2_2)) (breeze p_2_3))
    (at-least-one (not (wumpus p_2_2)) (stench p_3_2))
    (at-least-one (not (pit p_2_2)) (breeze p_3_2))
    (at-least-one (not (wumpus p_2_2)) (not (at p_2_2)) (not (alive)))
    (at-least-one (not (pit p_2_2)) (not (at p_2_2)) (not (alive)))
    (at-least-one (wumpus p_2_2) (pit p_2_2) (safe p_2_2))
    (at-least-one (not (glitter p_2_2)) (gold p_2_2))
    (at-least-one (not (wumpus p_2_3)) (stench p_1_3))
    (at-least-one (not (pit p_2_3)) (breeze p_1_3))
    (at-least-one (not (wumpus p_2_3)) (stench p_2_2))
    (at-least-one (not (pit p_2_3)) (breeze p_2_2))
    (at-least-one (not (wumpus p_2_3)) (stench p_2_4))
    (at-least-one (not (pit p_2_3)) (breeze p_2_4))
    (at-least-one (not (wumpus p_2_3)) (stench p_3_3))
    (at-least-one (not (pit p_2_3)) (breeze p_3_3))
    (at-least-one (not (wumpus p_2_3)) (not (at p_2_3)) (not (alive)))
    (at-least-one (not (pit p_2_3)) (not (at p_2_3)) (not (alive)))
    (at-least-one (wumpus p_2_3) (pit p_2_3) (safe p_2_3))
    (at-least-one (not (glitter p_2_3)) (gold p_2_3))
    (at-least-one (not (wumpus p_2_4)) (stench p_1_4))
    (at-least-one (not (pit p_2_4)) (breeze p_1_4))
    (at-least-one (not (wumpus p_2_4)) (stench p_2_3))
    (at-least-one (not (pit p_2_4)) (breeze p_2_3))
    (at-least-one (not (wumpus p_2_4)) (stench p_2_5))
    (at-least-one (not (pit p_2_4)) (breeze p_2_5))
    (at-least-one (not (wumpus p_2_4)) (stench p_3_4))
    (at-least-one (not (pit p_2_4)) (breeze p_3_4))
    (at-least-one (not (wumpus p_2_4)) (not (at p_2_4)) (not (alive)))
    (at-least-one (not (pit p_2_4)) (not (at p_2_4)) (not (alive)))
    (at-least-one (wumpus p_2_4) (pit p_2_4) (safe p_2_4))
    (at-least-one (not (glitter p_2_4)) (gold p_2_4))
    (at-least-one (not (wumpus p_2_5)) (stench p_1_5))
    (at-least-one (not (pit p_2_5)) (breeze p_1_5))
    (at-least-one (not (wumpus p_2_5)) (stench p_2_4))
    (at-least-one (not (pit p_2_5)) (breeze p_2_4))
    (at-least-one (not (wumpus p_2_5)) (stench p_3_5))
    (at-least-one (not (pit p_2_5)) (breeze p_3_5))
    (at-least-one (not (wumpus p_2_5)) (not (at p_2_5)) (not (alive)))
    (at-least-one (not (pit p_2_5)) (not (at p_2_5)) (not (alive)))
    (at-least-one (wumpus p_2_5) (pit p_2_5) (safe p_2_5))
    (at-least-one (not (glitter p_2_5)) (gold p_2_5))
    (at-least-one (not (wumpus p_3_1)) (stench p_2_1))
    (at-least-one (not (pit p_3_1)) (breeze p_2_1))
    (at-least-one (not (wumpus p_3_1)) (stench p_3_2))
    (at-least-one (not (pit p_3_1)) (breeze p_3_2))
    (at-least-one (not (wumpus p_3_1)) (stench p_4_1))
    (at-least-one (not (pit p_3_1)) (breeze p_4_1))
    (at-least-one (not (wumpus p_3_1)) (not (at p_3_1)) (not (alive)))
    (at-least-one (not (pit p_3_1)) (not (at p_3_1)) (not (alive)))
    (at-least-one (wumpus p_3_1) (pit p_3_1) (safe p_3_1))
    (at-least-one (not (glitter p_3_1)) (gold p_3_1))
    (at-least-one (not (wumpus p_3_2)) (stench p_2_2))
    (at-least-one (not (pit p_3_2)) (breeze p_2_2))
    (at-least-one (not (wumpus p_3_2)) (stench p_3_1))
    (at-least-one (not (pit p_3_2)) (breeze p_3_1))
    (at-least-one (not (wumpus p_3_2)) (stench p_3_3))
    (at-least-one (not (pit p_3_2)) (breeze p_3_3))
    (at-least-one (not (wumpus p_3_2)) (stench p_4_2))
    (at-least-one (not (pit p_3_2)) (breeze p_4_2))
    (at-least-one (not (wumpus p_3_2)) (not (at p_3_2)) (not (alive)))
    (at-least-one (not (pit p_3_2)) (not (at p_3_2)) (not (alive)))
    (at-least-one (wumpus p_3_2) (pit p_3_2) (safe p_3_2))
    (at-least-one (not (glitter p_3_2)) (gold p_3_2))
    (at-least-one (not (wumpus p_3_3)) (stench p_2_3))
    (at-least-one (not (pit p_3_3)) (breeze p_2_3))
    (at-least-one (not (wumpus p_3_3)) (stench p_3_2))
    (at-least-one (not (pit p_3_3)) (breeze p_3_2))
    (at-least-one (not (wumpus p_3_3)) (stench p_3_4))
    (at-least-one (not (pit p_3_3)) (breeze p_3_4))
    (at-least-one (not (wumpus p_3_3)) (stench p_4_3))
    (at-least-one (not (pit p_3_3)) (breeze p_4_3))
    (at-least-one (not (wumpus p_3_3)) (not (at p_3_3)) (not (alive)))
    (at-least-one (not (pit p_3_3)) (not (at p_3_3)) (not (alive)))
    (at-least-one (wumpus p_3_3) (pit p_3_3) (safe p_3_3))
    (at-least-one (not (glitter p_3_3)) (gold p_3_3))
    (at-least-one (not (wumpus p_3_4)) (stench p_2_4))
    (at-least-one (not (pit p_3_4)) (breeze p_2_4))
    (at-least-one (not (wumpus p_3_4)) (stench p_3_3))
    (at-least-one (not (pit p_3_4)) (breeze p_3_3))
    (at-least-one (not (wumpus p_3_4)) (stench p_3_5))
    (at-least-one (not (pit p_3_4)) (breeze p_3_5))
    (at-least-one (not (wumpus p_3_4)) (stench p_4_4))
    (at-least-one (not (pit p_3_4)) (breeze p_4_4))
    (at-least-one (not (wumpus p_3_4)) (not (at p_3_4)) (not (alive)))
    (at-least-one (not (pit p_3_4)) (not (at p_3_4)) (not (alive)))
    (at-least-one (wumpus p_3_4) (pit p_3_4) (safe p_3_4))
    (at-least-one (not (glitter p_3_4)) (gold p_3_4))
    (at-least-one (not (wumpus p_3_5)) (stench p_2_5))
    (at-least-one (not (pit p_3_5)) (breeze p_2_5))
    (at-least-one (not (wumpus p_3_5)) (stench p_3_4))
    (at-least-one (not (pit p_3_5)) (breeze p_3_4))
    (at-least-one (not (wumpus p_3_5)) (stench p_4_5))
    (at-least-one (not (pit p_3_5)) (breeze p_4_5))
    (at-least-one (not (wumpus p_3_5)) (not (at p_3_5)) (not (alive)))
    (at-least-one (not (pit p_3_5)) (not (at p_3_5)) (not (alive)))
    (at-least-one (wumpus p_3_5) (pit p_3_5) (safe p_3_5))
    (at-least-one (not (glitter p_3_5)) (gold p_3_5))
    (at-least-one (not (wumpus p_4_1)) (stench p_3_1))
    (at-least-one (not (pit p_4_1)) (breeze p_3_1))
    (at-least-one (not (wumpus p_4_1)) (stench p_4_2))
    (at-least-one (not (pit p_4_1)) (breeze p_4_2))
    (at-least-one (not (wumpus p_4_1)) (stench p_5_1))
    (at-least-one (not (pit p_4_1)) (breeze p_5_1))
    (at-least-one (not (wumpus p_4_1)) (not (at p_4_1)) (not (alive)))
    (at-least-one (not (pit p_4_1)) (not (at p_4_1)) (not (alive)))
    (at-least-one (wumpus p_4_1) (pit p_4_1) (safe p_4_1))
    (at-least-one (not (glitter p_4_1)) (gold p_4_1))
    (at-least-one (not (wumpus p_4_2)) (stench p_3_2))
    (at-least-one (not (pit p_4_2)) (breeze p_3_2))
    (at-least-one (not (wumpus p_4_2)) (stench p_4_1))
    (at-least-one (not (pit p_4_2)) (breeze p_4_1))
    (at-least-one (not (wumpus p_4_2)) (stench p_4_3))
    (at-least-one (not (pit p_4_2)) (breeze p_4_3))
    (at-least-one (not (wumpus p_4_2)) (stench p_5_2))
    (at-least-one (not (pit p_4_2)) (breeze p_5_2))
    (at-least-one (not (wumpus p_4_2)) (not (at p_4_2)) (not (alive)))
    (at-least-one (not (pit p_4_2)) (not (at p_4_2)) (not (alive)))
    (at-least-one (wumpus p_4_2) (pit p_4_2) (safe p_4_2))
    (at-least-one (not (glitter p_4_2)) (gold p_4_2))
    (at-least-one (not (wumpus p_4_3)) (stench p_3_3))
    (at-least-one (not (pit p_4_3)) (breeze p_3_3))
    (at-least-one (not (wumpus p_4_3)) (stench p_4_2))
    (at-least-one (not (pit p_4_3)) (breeze p_4_2))
    (at-least-one (not (wumpus p_4_3)) (stench p_4_4))
    (at-least-one (not (pit p_4_3)) (breeze p_4_4))
    (at-least-one (not (wumpus p_4_3)) (stench p_5_3))
    (at-least-one (not (pit p_4_3)) (breeze p_5_3))
    (at-least-one (not (wumpus p_4_3)) (not (at p_4_3)) (not (alive)))
    (at-least-one (not (pit p_4_3)) (not (at p_4_3)) (not (alive)))
    (at-least-one (wumpus p_4_3) (pit p_4_3) (safe p_4_3))
    (at-least-one (not (glitter p_4_3)) (gold p_4_3))
    (at-least-one (not (wumpus p_4_4)) (stench p_3_4))
    (at-least-one (not (pit p_4_4)) (breeze p_3_4))
    (at-least-one (not (wumpus p_4_4)) (stench p_4_3))
    (at-least-one (not (pit p_4_4)) (breeze p_4_3))
    (at-least-one (not (wumpus p_4_4)) (stench p_4_5))
    (at-least-one (not (pit p_4_4)) (breeze p_4_5))
    (at-least-one (not (wumpus p_4_4)) (stench p_5_4))
    (at-least-one (not (pit p_4_4)) (breeze p_5_4))
    (at-least-one (not (wumpus p_4_4)) (not (at p_4_4)) (not (alive)))
    (at-least-one (not (pit p_4_4)) (not (at p_4_4)) (not (alive)))
    (at-least-one (wumpus p_4_4) (pit p_4_4) (safe p_4_4))
    (at-least-one (not (glitter p_4_4)) (gold p_4_4))
    (at-least-one (not (wumpus p_4_5)) (stench p_3_5))
    (at-least-one (not (pit p_4_5)) (breeze p_3_5))
    (at-least-one (not (wumpus p_4_5)) (stench p_4_4))
    (at-least-one (not (pit p_4_5)) (breeze p_4_4))
    (at-least-one (not (wumpus p_4_5)) (stench p_5_5))
    (at-least-one (not (pit p_4_5)) (breeze p_5_5))
    (at-least-one (not (wumpus p_4_5)) (not (at p_4_5)) (not (alive)))
    (at-least-one (not (pit p_4_5)) (not (at p_4_5)) (not (alive)))
    (at-least-one (wumpus p_4_5) (pit p_4_5) (safe p_4_5))
    (at-least-one (not (glitter p_4_5)) (gold p_4_5))
    (at-least-one (not (wumpus p_5_1)) (stench p_4_1))
    (at-least-one (not (pit p_5_1)) (breeze p_4_1))
    (at-least-one (not (wumpus p_5_1)) (stench p_5_2))
    (at-least-one (not (pit p_5_1)) (breeze p_5_2))
    (at-least-one (not (wumpus p_5_1)) (not (at p_5_1)) (not (alive)))
    (at-least-one (not (pit p_5_1)) (not (at p_5_1)) (not (alive)))
    (at-least-one (wumpus p_5_1) (pit p_5_1) (safe p_5_1))
    (at-least-one (not (glitter p_5_1)) (gold p_5_1))
    (at-least-one (not (wumpus p_5_2)) (stench p_4_2))
    (at-least-one (not (pit p_5_2)) (breeze p_4_2))
    (at-least-one (not (wumpus p_5_2)) (stench p_5_1))
    (at-least-one (not (pit p_5_2)) (breeze p_5_1))
    (at-least-one (not (wumpus p_5_2)) (stench p_5_3))
    (at-least-one (not (pit p_5_2)) (breeze p_5_3))
    (at-least-one (not (wumpus p_5_2)) (not (at p_5_2)) (not (alive)))
    (at-least-one (not (pit p_5_2)) (not (at p_5_2)) (not (alive)))
    (at-least-one (wumpus p_5_2) (pit p_5_2) (safe p_5_2))
    (at-least-one (not (glitter p_5_2)) (gold p_5_2))
    (at-least-one (not (wumpus p_5_3)) (stench p_4_3))
    (at-least-one (not (pit p_5_3)) (breeze p_4_3))
    (at-least-one (not (wumpus p_5_3)) (stench p_5_2))
    (at-least-one (not (pit p_5_3)) (breeze p_5_2))
    (at-least-one (not (wumpus p_5_3)) (stench p_5_4))
    (at-least-one (not (pit p_5_3)) (breeze p_5_4))
    (at-least-one (not (wumpus p_5_3)) (not (at p_5_3)) (not (alive)))
    (at-least-one (not (pit p_5_3)) (not (at p_5_3)) (not (alive)))
    (at-least-one (wumpus p_5_3) (pit p_5_3) (safe p_5_3))
    (at-least-one (not (glitter p_5_3)) (gold p_5_3))
    (at-least-one (not (wumpus p_5_4)) (stench p_4_4))
    (at-least-one (not (pit p_5_4)) (breeze p_4_4))
    (at-least-one (not (wumpus p_5_4)) (stench p_5_3))
    (at-least-one (not (pit p_5_4)) (breeze p_5_3))
    (at-least-one (not (wumpus p_5_4)) (stench p_5_5))
    (at-least-one (not (pit p_5_4)) (breeze p_5_5))
    (at-least-one (not (wumpus p_5_4)) (not (at p_5_4)) (not (alive)))
    (at-least-one (not (pit p_5_4)) (not (at p_5_4)) (not (alive)))
    (at-least-one (wumpus p_5_4) (pit p_5_4) (safe p_5_4))
    (at-least-one (not (glitter p_5_4)) (gold p_5_4))
    (at-least-one (not (wumpus p_5_5)) (stench p_4_5))
    (at-least-one (not (pit p_5_5)) (breeze p_4_5))
    (at-least-one (not (wumpus p_5_5)) (stench p_5_4))
    (at-least-one (not (pit p_5_5)) (breeze p_5_4))
    (at-least-one (not (wumpus p_5_5)) (not (at p_5_5)) (not (alive)))
    (at-least-one (not (pit p_5_5)) (not (at p_5_5)) (not (alive)))
    (at-least-one (wumpus p_5_5) (pit p_5_5) (safe p_5_5))
    (at-least-one (not (glitter p_5_5)) (gold p_5_5))

    (at-least-one (not (stench p_1_1)) (wumpus p_1_2) (wumpus p_2_1))
    (at-least-one (not (breeze p_1_1)) (pit p_1_2) (pit p_2_1))
    (at-least-one (not (stench p_1_2)) (wumpus p_1_1) (wumpus p_1_3) (wumpus p_2_2))
    (at-least-one (not (breeze p_1_2)) (pit p_1_1) (pit p_1_3) (pit p_2_2))
    (at-least-one (not (stench p_1_3)) (wumpus p_1_2) (wumpus p_1_4) (wumpus p_2_3))
    (at-least-one (not (breeze p_1_3)) (pit p_1_2) (pit p_1_4) (pit p_2_3))
    (at-least-one (not (stench p_1_4)) (wumpus p_1_3) (wumpus p_1_5) (wumpus p_2_4))
    (at-least-one (not (breeze p_1_4)) (pit p_1_3) (pit p_1_5) (pit p_2_4))
    (at-least-one (not (stench p_1_5)) (wumpus p_1_4) (wumpus p_2_5))
    (at-least-one (not (breeze p_1_5)) (pit p_1_4) (pit p_2_5))
    (at-least-one (not (stench p_2_1)) (wumpus p_1_1) (wumpus p_2_2) (wumpus p_3_1))
    (at-least-one (not (breeze p_2_1)) (pit p_1_1) (pit p_2_2) (pit p_3_1))
    (at-least-one (not (stench p_2_2)) (wumpus p_1_2) (wumpus p_2_1) (wumpus p_2_3) (wumpus p_3_2))
    (at-least-one (not (breeze p_2_2)) (pit p_1_2) (pit p_2_1) (pit p_2_3) (pit p_3_2))
    (at-least-one (not (stench p_2_3)) (wumpus p_1_3) (wumpus p_2_2) (wumpus p_2_4) (wumpus p_3_3))
    (at-least-one (not (breeze p_2_3)) (pit p_1_3) (pit p_2_2) (pit p_2_4) (pit p_3_3))
    (at-least-one (not (stench p_2_4)) (wumpus p_1_4) (wumpus p_2_3) (wumpus p_2_5) (wumpus p_3_4))
    (at-least-one (not (breeze p_2_4)) (pit p_1_4) (pit p_2_3) (pit p_2_5) (pit p_3_4))
    (at-least-one (not (stench p_2_5)) (wumpus p_1_5) (wumpus p_2_4) (wumpus p_3_5))
    (at-least-one (not (breeze p_2_5)) (pit p_1_5) (pit p_2_4) (pit p_3_5))
    (at-least-one (not (stench p_3_1)) (wumpus p_2_1) (wumpus p_3_2) (wumpus p_4_1))
    (at-least-one (not (breeze p_3_1)) (pit p_2_1) (pit p_3_2) (pit p_4_1))
    (at-least-one (not (stench p_3_2)) (wumpus p_2_2) (wumpus p_3_1) (wumpus p_3_3) (wumpus p_4_2))
    (at-least-one (not (breeze p_3_2)) (pit p_2_2) (pit p_3_1) (pit p_3_3) (pit p_4_2))
    (at-least-one (not (stench p_3_3)) (wumpus p_2_3) (wumpus p_3_2) (wumpus p_3_4) (wumpus p_4_3))
    (at-least-one (not (breeze p_3_3)) (pit p_2_3) (pit p_3_2) (pit p_3_4) (pit p_4_3))
    (at-least-one (not (stench p_3_4)) (wumpus p_2_4) (wumpus p_3_3) (wumpus p_3_5) (wumpus p_4_4))
    (at-least-one (not (breeze p_3_4)) (pit p_2_4) (pit p_3_3) (pit p_3_5) (pit p_4_4))
    (at-least-one (not (stench p_3_5)) (wumpus p_2_5) (wumpus p_3_4) (wumpus p_4_5))
    (at-least-one (not (breeze p_3_5)) (pit p_2_5) (pit p_3_4) (pit p_4_5))
    (at-least-one (not (stench p_4_1)) (wumpus p_3_1) (wumpus p_4_2) (wumpus p_5_1))
    (at-least-one (not (breeze p_4_1)) (pit p_3_1) (pit p_4_2) (pit p_5_1))
    (at-least-one (not (stench p_4_2)) (wumpus p_3_2) (wumpus p_4_1) (wumpus p_4_3) (wumpus p_5_2))
    (at-least-one (not (breeze p_4_2)) (pit p_3_2) (pit p_4_1) (pit p_4_3) (pit p_5_2))
    (at-least-one (not (stench p_4_3)) (wumpus p_3_3) (wumpus p_4_2) (wumpus p_4_4) (wumpus p_5_3))
    (at-least-one (not (breeze p_4_3)) (pit p_3_3) (pit p_4_2) (pit p_4_4) (pit p_5_3))
    (at-least-one (not (stench p_4_4)) (wumpus p_3_4) (wumpus p_4_3) (wumpus p_4_5) (wumpus p_5_4))
    (at-least-one (not (breeze p_4_4)) (pit p_3_4) (pit p_4_3) (pit p_4_5) (pit p_5_4))
    (at-least-one (not (stench p_4_5)) (wumpus p_3_5) (wumpus p_4_4) (wumpus p_5_5))
    (at-least-one (not (breeze p_4_5)) (pit p_3_5) (pit p_4_4) (pit p_5_5))
    (at-least-one (not (stench p_5_1)) (wumpus p_4_1) (wumpus p_5_2))
    (at-least-one (not (breeze p_5_1)) (pit p_4_1) (pit p_5_2))
    (at-least-one (not (stench p_5_2)) (wumpus p_4_2) (wumpus p_5_1) (wumpus p_5_3))
    (at-least-one (not (breeze p_5_2)) (pit p_4_2) (pit p_5_1) (pit p_5_3))
    (at-least-one (not (stench p_5_3)) (wumpus p_4_3) (wumpus p_5_2) (wumpus p_5_4))
    (at-least-one (not (breeze p_5_3)) (pit p_4_3) (pit p_5_2) (pit p_5_4))
    (at-least-one (not (stench p_5_4)) (wumpus p_4_4) (wumpus p_5_3) (wumpus p_5_5))
    (at-least-one (not (breeze p_5_4)) (pit p_4_4) (pit p_5_3) (pit p_5_5))
    (at-least-one (not (stench p_5_5)) (wumpus p_4_5) (wumpus p_5_4))
    (at-least-one (not (breeze p_5_5)) (pit p_4_5) (pit p_5_4))
  )
  (:hidden
    (gold p_3_2) (glitter p_3_2)
    (wumpus p_1_3) (stench p_1_2) (stench p_1_4) (stench p_2_3)
    (pit p_4_3) (breeze p_3_3) (breeze p_4_2) (breeze p_4_4) (breeze p_5_3)
    (safe p_1_1) (safe p_1_2) (safe p_1_4) (safe p_1_5) (safe p_2_1) (safe p_2_2) (safe p_2_3) (safe p_2_4) (safe p_2_5) (safe p_3_1) (safe p_3_2) (safe p_3_3) (safe p_3_4) (safe p_3_5) (safe p_4_1) (safe p_4_2) (safe p_4_4) (safe p_4_5) (safe p_5_1) (safe p_5_2) (safe p_5_3) (safe p_5_4) (safe p_5_5)
  )
  (:goal (have-gold))
)
