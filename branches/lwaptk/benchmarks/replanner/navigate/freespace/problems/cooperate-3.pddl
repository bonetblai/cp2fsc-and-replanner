;; dim=(25,9)
;; init=(22,8)
;; goal=(23,2)
;; @@@@@@@@@@@@@@@@@@@@@@@@@
;; @....................I..@
;; @..@@@@@@@@@.@@@@@@@@@..@
;; @..@@@@@@@@@.@@@@@@@@@..@
;; @.......................@
;; @..@@@@@@@@@.@@@@@@@@@..@
;; @..@@@@@@@@@.@@@@@@@@@..@
;; @.....................G.@
;; @@@@@@@@@@@@@@@@@@@@@@@@@

(define (problem map-cooperate)
    (:domain freespace)
    (:objects
        x1 x2 x3 x4 x5 x6 x7 x8 x9 x10 x11 x12 x13 x14 x15 x16 x17 x18 x19 x20 x21 x22 x23 x24 x25 - xpos
        y1 y2 y3 y4 y5 y6 y7 y8 y9 - ypos)
    (:init
        (suc-x x1 x2) (suc-x x2 x3) (suc-x x3 x4) (suc-x x4 x5) (suc-x x5 x6) (suc-x x6 x7) (suc-x x7 x8) (suc-x x8 x9) (suc-x x9 x10) (suc-x x10 x11) (suc-x x11 x12) (suc-x x12 x13) (suc-x x13 x14) (suc-x x14 x15) (suc-x x15 x16) (suc-x x16 x17) (suc-x x17 x18) (suc-x x18 x19) (suc-x x19 x20) (suc-x x20 x21) (suc-x x21 x22) (suc-x x22 x23) (suc-x x23 x24) (suc-x x24 x25)
        (suc-y y1 y2) (suc-y y2 y3) (suc-y y3 y4) (suc-y y4 y5) (suc-y y5 y6) (suc-y y6 y7) (suc-y y7 y8) (suc-y y8 y9)
       (at x22 y8)
       (invariant (wall x1 y1) (not (wall x1 y1)))
       (invariant (wall x1 y2) (not (wall x1 y2)))
       (invariant (wall x1 y3) (not (wall x1 y3)))
       (invariant (wall x1 y4) (not (wall x1 y4)))
       (invariant (wall x1 y5) (not (wall x1 y5)))
       (invariant (wall x1 y6) (not (wall x1 y6)))
       (invariant (wall x1 y7) (not (wall x1 y7)))
       (invariant (wall x1 y8) (not (wall x1 y8)))
       (invariant (wall x1 y9) (not (wall x1 y9)))
       (invariant (wall x2 y1) (not (wall x2 y1)))
       (invariant (wall x2 y2) (not (wall x2 y2)))
       (invariant (wall x2 y3) (not (wall x2 y3)))
       (invariant (wall x2 y4) (not (wall x2 y4)))
       (invariant (wall x2 y5) (not (wall x2 y5)))
       (invariant (wall x2 y6) (not (wall x2 y6)))
       (invariant (wall x2 y7) (not (wall x2 y7)))
       (invariant (wall x2 y8) (not (wall x2 y8)))
       (invariant (wall x2 y9) (not (wall x2 y9)))
       (invariant (wall x3 y1) (not (wall x3 y1)))
       (invariant (wall x3 y2) (not (wall x3 y2)))
       (invariant (wall x3 y3) (not (wall x3 y3)))
       (invariant (wall x3 y4) (not (wall x3 y4)))
       (invariant (wall x3 y5) (not (wall x3 y5)))
       (invariant (wall x3 y6) (not (wall x3 y6)))
       (invariant (wall x3 y7) (not (wall x3 y7)))
       (invariant (wall x3 y8) (not (wall x3 y8)))
       (invariant (wall x3 y9) (not (wall x3 y9)))
       (invariant (wall x4 y1) (not (wall x4 y1)))
       (invariant (wall x4 y2) (not (wall x4 y2)))
       (invariant (wall x4 y3) (not (wall x4 y3)))
       (invariant (wall x4 y4) (not (wall x4 y4)))
       (invariant (wall x4 y5) (not (wall x4 y5)))
       (invariant (wall x4 y6) (not (wall x4 y6)))
       (invariant (wall x4 y7) (not (wall x4 y7)))
       (invariant (wall x4 y8) (not (wall x4 y8)))
       (invariant (wall x4 y9) (not (wall x4 y9)))
       (invariant (wall x5 y1) (not (wall x5 y1)))
       (invariant (wall x5 y2) (not (wall x5 y2)))
       (invariant (wall x5 y3) (not (wall x5 y3)))
       (invariant (wall x5 y4) (not (wall x5 y4)))
       (invariant (wall x5 y5) (not (wall x5 y5)))
       (invariant (wall x5 y6) (not (wall x5 y6)))
       (invariant (wall x5 y7) (not (wall x5 y7)))
       (invariant (wall x5 y8) (not (wall x5 y8)))
       (invariant (wall x5 y9) (not (wall x5 y9)))
       (invariant (wall x6 y1) (not (wall x6 y1)))
       (invariant (wall x6 y2) (not (wall x6 y2)))
       (invariant (wall x6 y3) (not (wall x6 y3)))
       (invariant (wall x6 y4) (not (wall x6 y4)))
       (invariant (wall x6 y5) (not (wall x6 y5)))
       (invariant (wall x6 y6) (not (wall x6 y6)))
       (invariant (wall x6 y7) (not (wall x6 y7)))
       (invariant (wall x6 y8) (not (wall x6 y8)))
       (invariant (wall x6 y9) (not (wall x6 y9)))
       (invariant (wall x7 y1) (not (wall x7 y1)))
       (invariant (wall x7 y2) (not (wall x7 y2)))
       (invariant (wall x7 y3) (not (wall x7 y3)))
       (invariant (wall x7 y4) (not (wall x7 y4)))
       (invariant (wall x7 y5) (not (wall x7 y5)))
       (invariant (wall x7 y6) (not (wall x7 y6)))
       (invariant (wall x7 y7) (not (wall x7 y7)))
       (invariant (wall x7 y8) (not (wall x7 y8)))
       (invariant (wall x7 y9) (not (wall x7 y9)))
       (invariant (wall x8 y1) (not (wall x8 y1)))
       (invariant (wall x8 y2) (not (wall x8 y2)))
       (invariant (wall x8 y3) (not (wall x8 y3)))
       (invariant (wall x8 y4) (not (wall x8 y4)))
       (invariant (wall x8 y5) (not (wall x8 y5)))
       (invariant (wall x8 y6) (not (wall x8 y6)))
       (invariant (wall x8 y7) (not (wall x8 y7)))
       (invariant (wall x8 y8) (not (wall x8 y8)))
       (invariant (wall x8 y9) (not (wall x8 y9)))
       (invariant (wall x9 y1) (not (wall x9 y1)))
       (invariant (wall x9 y2) (not (wall x9 y2)))
       (invariant (wall x9 y3) (not (wall x9 y3)))
       (invariant (wall x9 y4) (not (wall x9 y4)))
       (invariant (wall x9 y5) (not (wall x9 y5)))
       (invariant (wall x9 y6) (not (wall x9 y6)))
       (invariant (wall x9 y7) (not (wall x9 y7)))
       (invariant (wall x9 y8) (not (wall x9 y8)))
       (invariant (wall x9 y9) (not (wall x9 y9)))
       (invariant (wall x10 y1) (not (wall x10 y1)))
       (invariant (wall x10 y2) (not (wall x10 y2)))
       (invariant (wall x10 y3) (not (wall x10 y3)))
       (invariant (wall x10 y4) (not (wall x10 y4)))
       (invariant (wall x10 y5) (not (wall x10 y5)))
       (invariant (wall x10 y6) (not (wall x10 y6)))
       (invariant (wall x10 y7) (not (wall x10 y7)))
       (invariant (wall x10 y8) (not (wall x10 y8)))
       (invariant (wall x10 y9) (not (wall x10 y9)))
       (invariant (wall x11 y1) (not (wall x11 y1)))
       (invariant (wall x11 y2) (not (wall x11 y2)))
       (invariant (wall x11 y3) (not (wall x11 y3)))
       (invariant (wall x11 y4) (not (wall x11 y4)))
       (invariant (wall x11 y5) (not (wall x11 y5)))
       (invariant (wall x11 y6) (not (wall x11 y6)))
       (invariant (wall x11 y7) (not (wall x11 y7)))
       (invariant (wall x11 y8) (not (wall x11 y8)))
       (invariant (wall x11 y9) (not (wall x11 y9)))
       (invariant (wall x12 y1) (not (wall x12 y1)))
       (invariant (wall x12 y2) (not (wall x12 y2)))
       (invariant (wall x12 y3) (not (wall x12 y3)))
       (invariant (wall x12 y4) (not (wall x12 y4)))
       (invariant (wall x12 y5) (not (wall x12 y5)))
       (invariant (wall x12 y6) (not (wall x12 y6)))
       (invariant (wall x12 y7) (not (wall x12 y7)))
       (invariant (wall x12 y8) (not (wall x12 y8)))
       (invariant (wall x12 y9) (not (wall x12 y9)))
       (invariant (wall x13 y1) (not (wall x13 y1)))
       (invariant (wall x13 y2) (not (wall x13 y2)))
       (invariant (wall x13 y3) (not (wall x13 y3)))
       (invariant (wall x13 y4) (not (wall x13 y4)))
       (invariant (wall x13 y5) (not (wall x13 y5)))
       (invariant (wall x13 y6) (not (wall x13 y6)))
       (invariant (wall x13 y7) (not (wall x13 y7)))
       (invariant (wall x13 y8) (not (wall x13 y8)))
       (invariant (wall x13 y9) (not (wall x13 y9)))
       (invariant (wall x14 y1) (not (wall x14 y1)))
       (invariant (wall x14 y2) (not (wall x14 y2)))
       (invariant (wall x14 y3) (not (wall x14 y3)))
       (invariant (wall x14 y4) (not (wall x14 y4)))
       (invariant (wall x14 y5) (not (wall x14 y5)))
       (invariant (wall x14 y6) (not (wall x14 y6)))
       (invariant (wall x14 y7) (not (wall x14 y7)))
       (invariant (wall x14 y8) (not (wall x14 y8)))
       (invariant (wall x14 y9) (not (wall x14 y9)))
       (invariant (wall x15 y1) (not (wall x15 y1)))
       (invariant (wall x15 y2) (not (wall x15 y2)))
       (invariant (wall x15 y3) (not (wall x15 y3)))
       (invariant (wall x15 y4) (not (wall x15 y4)))
       (invariant (wall x15 y5) (not (wall x15 y5)))
       (invariant (wall x15 y6) (not (wall x15 y6)))
       (invariant (wall x15 y7) (not (wall x15 y7)))
       (invariant (wall x15 y8) (not (wall x15 y8)))
       (invariant (wall x15 y9) (not (wall x15 y9)))
       (invariant (wall x16 y1) (not (wall x16 y1)))
       (invariant (wall x16 y2) (not (wall x16 y2)))
       (invariant (wall x16 y3) (not (wall x16 y3)))
       (invariant (wall x16 y4) (not (wall x16 y4)))
       (invariant (wall x16 y5) (not (wall x16 y5)))
       (invariant (wall x16 y6) (not (wall x16 y6)))
       (invariant (wall x16 y7) (not (wall x16 y7)))
       (invariant (wall x16 y8) (not (wall x16 y8)))
       (invariant (wall x16 y9) (not (wall x16 y9)))
       (invariant (wall x17 y1) (not (wall x17 y1)))
       (invariant (wall x17 y2) (not (wall x17 y2)))
       (invariant (wall x17 y3) (not (wall x17 y3)))
       (invariant (wall x17 y4) (not (wall x17 y4)))
       (invariant (wall x17 y5) (not (wall x17 y5)))
       (invariant (wall x17 y6) (not (wall x17 y6)))
       (invariant (wall x17 y7) (not (wall x17 y7)))
       (invariant (wall x17 y8) (not (wall x17 y8)))
       (invariant (wall x17 y9) (not (wall x17 y9)))
       (invariant (wall x18 y1) (not (wall x18 y1)))
       (invariant (wall x18 y2) (not (wall x18 y2)))
       (invariant (wall x18 y3) (not (wall x18 y3)))
       (invariant (wall x18 y4) (not (wall x18 y4)))
       (invariant (wall x18 y5) (not (wall x18 y5)))
       (invariant (wall x18 y6) (not (wall x18 y6)))
       (invariant (wall x18 y7) (not (wall x18 y7)))
       (invariant (wall x18 y8) (not (wall x18 y8)))
       (invariant (wall x18 y9) (not (wall x18 y9)))
       (invariant (wall x19 y1) (not (wall x19 y1)))
       (invariant (wall x19 y2) (not (wall x19 y2)))
       (invariant (wall x19 y3) (not (wall x19 y3)))
       (invariant (wall x19 y4) (not (wall x19 y4)))
       (invariant (wall x19 y5) (not (wall x19 y5)))
       (invariant (wall x19 y6) (not (wall x19 y6)))
       (invariant (wall x19 y7) (not (wall x19 y7)))
       (invariant (wall x19 y8) (not (wall x19 y8)))
       (invariant (wall x19 y9) (not (wall x19 y9)))
       (invariant (wall x20 y1) (not (wall x20 y1)))
       (invariant (wall x20 y2) (not (wall x20 y2)))
       (invariant (wall x20 y3) (not (wall x20 y3)))
       (invariant (wall x20 y4) (not (wall x20 y4)))
       (invariant (wall x20 y5) (not (wall x20 y5)))
       (invariant (wall x20 y6) (not (wall x20 y6)))
       (invariant (wall x20 y7) (not (wall x20 y7)))
       (invariant (wall x20 y8) (not (wall x20 y8)))
       (invariant (wall x20 y9) (not (wall x20 y9)))
       (invariant (wall x21 y1) (not (wall x21 y1)))
       (invariant (wall x21 y2) (not (wall x21 y2)))
       (invariant (wall x21 y3) (not (wall x21 y3)))
       (invariant (wall x21 y4) (not (wall x21 y4)))
       (invariant (wall x21 y5) (not (wall x21 y5)))
       (invariant (wall x21 y6) (not (wall x21 y6)))
       (invariant (wall x21 y7) (not (wall x21 y7)))
       (invariant (wall x21 y8) (not (wall x21 y8)))
       (invariant (wall x21 y9) (not (wall x21 y9)))
       (invariant (wall x22 y1) (not (wall x22 y1)))
       (invariant (wall x22 y2) (not (wall x22 y2)))
       (invariant (wall x22 y3) (not (wall x22 y3)))
       (invariant (wall x22 y4) (not (wall x22 y4)))
       (invariant (wall x22 y5) (not (wall x22 y5)))
       (invariant (wall x22 y6) (not (wall x22 y6)))
       (invariant (wall x22 y7) (not (wall x22 y7)))
       (invariant (wall x22 y8) (not (wall x22 y8)))
       (invariant (wall x22 y9) (not (wall x22 y9)))
       (invariant (wall x23 y1) (not (wall x23 y1)))
       (invariant (wall x23 y2) (not (wall x23 y2)))
       (invariant (wall x23 y3) (not (wall x23 y3)))
       (invariant (wall x23 y4) (not (wall x23 y4)))
       (invariant (wall x23 y5) (not (wall x23 y5)))
       (invariant (wall x23 y6) (not (wall x23 y6)))
       (invariant (wall x23 y7) (not (wall x23 y7)))
       (invariant (wall x23 y8) (not (wall x23 y8)))
       (invariant (wall x23 y9) (not (wall x23 y9)))
       (invariant (wall x24 y1) (not (wall x24 y1)))
       (invariant (wall x24 y2) (not (wall x24 y2)))
       (invariant (wall x24 y3) (not (wall x24 y3)))
       (invariant (wall x24 y4) (not (wall x24 y4)))
       (invariant (wall x24 y5) (not (wall x24 y5)))
       (invariant (wall x24 y6) (not (wall x24 y6)))
       (invariant (wall x24 y7) (not (wall x24 y7)))
       (invariant (wall x24 y8) (not (wall x24 y8)))
       (invariant (wall x24 y9) (not (wall x24 y9)))
       (invariant (wall x25 y1) (not (wall x25 y1)))
       (invariant (wall x25 y2) (not (wall x25 y2)))
       (invariant (wall x25 y3) (not (wall x25 y3)))
       (invariant (wall x25 y4) (not (wall x25 y4)))
       (invariant (wall x25 y5) (not (wall x25 y5)))
       (invariant (wall x25 y6) (not (wall x25 y6)))
       (invariant (wall x25 y7) (not (wall x25 y7)))
       (invariant (wall x25 y8) (not (wall x25 y8)))
       (invariant (wall x25 y9) (not (wall x25 y9)))
    )
    (:hidden
       (wall x1 y1) (wall x1 y2) (wall x1 y3) (wall x1 y4) (wall x1 y5) (wall x1 y6)
       (wall x1 y7) (wall x1 y8) (wall x1 y9) (wall x2 y1) (wall x2 y9) (wall x3 y1)
       (wall x3 y9) (wall x4 y1) (wall x4 y3) (wall x4 y4) (wall x4 y6) (wall x4 y7)
       (wall x4 y9) (wall x5 y1) (wall x5 y3) (wall x5 y4) (wall x5 y6) (wall x5 y7)
       (wall x5 y9) (wall x6 y1) (wall x6 y3) (wall x6 y4) (wall x6 y6) (wall x6 y7)
       (wall x6 y9) (wall x7 y1) (wall x7 y3) (wall x7 y4) (wall x7 y6) (wall x7 y7)
       (wall x7 y9) (wall x8 y1) (wall x8 y3) (wall x8 y4) (wall x8 y6) (wall x8 y7)
       (wall x8 y9) (wall x9 y1) (wall x9 y3) (wall x9 y4) (wall x9 y6) (wall x9 y7)
       (wall x9 y9) (wall x10 y1) (wall x10 y3) (wall x10 y4) (wall x10 y6) (wall x10 y7)
       (wall x10 y9) (wall x11 y1) (wall x11 y3) (wall x11 y4) (wall x11 y6) (wall x11 y7)
       (wall x11 y9) (wall x12 y1) (wall x12 y3) (wall x12 y4) (wall x12 y6) (wall x12 y7)
       (wall x12 y9) (wall x13 y1) (wall x13 y9) (wall x14 y1) (wall x14 y3) (wall x14 y4)
       (wall x14 y6) (wall x14 y7) (wall x14 y9) (wall x15 y1) (wall x15 y3) (wall x15 y4)
       (wall x15 y6) (wall x15 y7) (wall x15 y9) (wall x16 y1) (wall x16 y3) (wall x16 y4)
       (wall x16 y6) (wall x16 y7) (wall x16 y9) (wall x17 y1) (wall x17 y3) (wall x17 y4)
       (wall x17 y6) (wall x17 y7) (wall x17 y9) (wall x18 y1) (wall x18 y3) (wall x18 y4)
       (wall x18 y6) (wall x18 y7) (wall x18 y9) (wall x19 y1) (wall x19 y3) (wall x19 y4)
       (wall x19 y6) (wall x19 y7) (wall x19 y9) (wall x20 y1) (wall x20 y3) (wall x20 y4)
       (wall x20 y6) (wall x20 y7) (wall x20 y9) (wall x21 y1) (wall x21 y3) (wall x21 y4)
       (wall x21 y6) (wall x21 y7) (wall x21 y9) (wall x22 y1) (wall x22 y3) (wall x22 y4)
       (wall x22 y6) (wall x22 y7) (wall x22 y9) (wall x23 y1) (wall x23 y9) (wall x24 y1)
       (wall x24 y9) (wall x25 y1) (wall x25 y2) (wall x25 y3) (wall x25 y4) (wall x25 y5)
       (wall x25 y6) (wall x25 y7) (wall x25 y8) (wall x25 y9)    )
    (:goal (at x23 y2))
)
