;; dim=(12,10)
;; init=(11,9)
;; goal=(5,4)
;; @@@@@@@@@@@@
;; @.........I@
;; @..@@@@@@..@
;; @..@.......@
;; @..@....@..@
;; @..@....@..@
;; @...G...@..@
;; @..@@@@@@..@
;; @..........@
;; @@@@@@@@@@@@

(define (problem map-bottleneck5)
    (:domain freespace)
    (:objects
        x1 x2 x3 x4 x5 x6 x7 x8 x9 x10 x11 x12 - xpos
        y1 y2 y3 y4 y5 y6 y7 y8 y9 y10 - ypos)
    (:init
        (suc-x x1 x2) (suc-x x2 x3) (suc-x x3 x4) (suc-x x4 x5) (suc-x x5 x6) (suc-x x6 x7) (suc-x x7 x8) (suc-x x8 x9) (suc-x x9 x10) (suc-x x10 x11) (suc-x x11 x12)
        (suc-y y1 y2) (suc-y y2 y3) (suc-y y3 y4) (suc-y y4 y5) (suc-y y5 y6) (suc-y y6 y7) (suc-y y7 y8) (suc-y y8 y9) (suc-y y9 y10)
       (at x11 y9)
       (invariant (wall x1 y1) (not (wall x1 y1)))
       (invariant (wall x1 y2) (not (wall x1 y2)))
       (invariant (wall x1 y3) (not (wall x1 y3)))
       (invariant (wall x1 y4) (not (wall x1 y4)))
       (invariant (wall x1 y5) (not (wall x1 y5)))
       (invariant (wall x1 y6) (not (wall x1 y6)))
       (invariant (wall x1 y7) (not (wall x1 y7)))
       (invariant (wall x1 y8) (not (wall x1 y8)))
       (invariant (wall x1 y9) (not (wall x1 y9)))
       (invariant (wall x1 y10) (not (wall x1 y10)))
       (invariant (wall x2 y1) (not (wall x2 y1)))
       (invariant (wall x2 y2) (not (wall x2 y2)))
       (invariant (wall x2 y3) (not (wall x2 y3)))
       (invariant (wall x2 y4) (not (wall x2 y4)))
       (invariant (wall x2 y5) (not (wall x2 y5)))
       (invariant (wall x2 y6) (not (wall x2 y6)))
       (invariant (wall x2 y7) (not (wall x2 y7)))
       (invariant (wall x2 y8) (not (wall x2 y8)))
       (invariant (wall x2 y9) (not (wall x2 y9)))
       (invariant (wall x2 y10) (not (wall x2 y10)))
       (invariant (wall x3 y1) (not (wall x3 y1)))
       (invariant (wall x3 y2) (not (wall x3 y2)))
       (invariant (wall x3 y3) (not (wall x3 y3)))
       (invariant (wall x3 y4) (not (wall x3 y4)))
       (invariant (wall x3 y5) (not (wall x3 y5)))
       (invariant (wall x3 y6) (not (wall x3 y6)))
       (invariant (wall x3 y7) (not (wall x3 y7)))
       (invariant (wall x3 y8) (not (wall x3 y8)))
       (invariant (wall x3 y9) (not (wall x3 y9)))
       (invariant (wall x3 y10) (not (wall x3 y10)))
       (invariant (wall x4 y1) (not (wall x4 y1)))
       (invariant (wall x4 y2) (not (wall x4 y2)))
       (invariant (wall x4 y3) (not (wall x4 y3)))
       (invariant (wall x4 y4) (not (wall x4 y4)))
       (invariant (wall x4 y5) (not (wall x4 y5)))
       (invariant (wall x4 y6) (not (wall x4 y6)))
       (invariant (wall x4 y7) (not (wall x4 y7)))
       (invariant (wall x4 y8) (not (wall x4 y8)))
       (invariant (wall x4 y9) (not (wall x4 y9)))
       (invariant (wall x4 y10) (not (wall x4 y10)))
       (invariant (wall x5 y1) (not (wall x5 y1)))
       (invariant (wall x5 y2) (not (wall x5 y2)))
       (invariant (wall x5 y3) (not (wall x5 y3)))
       (invariant (wall x5 y4) (not (wall x5 y4)))
       (invariant (wall x5 y5) (not (wall x5 y5)))
       (invariant (wall x5 y6) (not (wall x5 y6)))
       (invariant (wall x5 y7) (not (wall x5 y7)))
       (invariant (wall x5 y8) (not (wall x5 y8)))
       (invariant (wall x5 y9) (not (wall x5 y9)))
       (invariant (wall x5 y10) (not (wall x5 y10)))
       (invariant (wall x6 y1) (not (wall x6 y1)))
       (invariant (wall x6 y2) (not (wall x6 y2)))
       (invariant (wall x6 y3) (not (wall x6 y3)))
       (invariant (wall x6 y4) (not (wall x6 y4)))
       (invariant (wall x6 y5) (not (wall x6 y5)))
       (invariant (wall x6 y6) (not (wall x6 y6)))
       (invariant (wall x6 y7) (not (wall x6 y7)))
       (invariant (wall x6 y8) (not (wall x6 y8)))
       (invariant (wall x6 y9) (not (wall x6 y9)))
       (invariant (wall x6 y10) (not (wall x6 y10)))
       (invariant (wall x7 y1) (not (wall x7 y1)))
       (invariant (wall x7 y2) (not (wall x7 y2)))
       (invariant (wall x7 y3) (not (wall x7 y3)))
       (invariant (wall x7 y4) (not (wall x7 y4)))
       (invariant (wall x7 y5) (not (wall x7 y5)))
       (invariant (wall x7 y6) (not (wall x7 y6)))
       (invariant (wall x7 y7) (not (wall x7 y7)))
       (invariant (wall x7 y8) (not (wall x7 y8)))
       (invariant (wall x7 y9) (not (wall x7 y9)))
       (invariant (wall x7 y10) (not (wall x7 y10)))
       (invariant (wall x8 y1) (not (wall x8 y1)))
       (invariant (wall x8 y2) (not (wall x8 y2)))
       (invariant (wall x8 y3) (not (wall x8 y3)))
       (invariant (wall x8 y4) (not (wall x8 y4)))
       (invariant (wall x8 y5) (not (wall x8 y5)))
       (invariant (wall x8 y6) (not (wall x8 y6)))
       (invariant (wall x8 y7) (not (wall x8 y7)))
       (invariant (wall x8 y8) (not (wall x8 y8)))
       (invariant (wall x8 y9) (not (wall x8 y9)))
       (invariant (wall x8 y10) (not (wall x8 y10)))
       (invariant (wall x9 y1) (not (wall x9 y1)))
       (invariant (wall x9 y2) (not (wall x9 y2)))
       (invariant (wall x9 y3) (not (wall x9 y3)))
       (invariant (wall x9 y4) (not (wall x9 y4)))
       (invariant (wall x9 y5) (not (wall x9 y5)))
       (invariant (wall x9 y6) (not (wall x9 y6)))
       (invariant (wall x9 y7) (not (wall x9 y7)))
       (invariant (wall x9 y8) (not (wall x9 y8)))
       (invariant (wall x9 y9) (not (wall x9 y9)))
       (invariant (wall x9 y10) (not (wall x9 y10)))
       (invariant (wall x10 y1) (not (wall x10 y1)))
       (invariant (wall x10 y2) (not (wall x10 y2)))
       (invariant (wall x10 y3) (not (wall x10 y3)))
       (invariant (wall x10 y4) (not (wall x10 y4)))
       (invariant (wall x10 y5) (not (wall x10 y5)))
       (invariant (wall x10 y6) (not (wall x10 y6)))
       (invariant (wall x10 y7) (not (wall x10 y7)))
       (invariant (wall x10 y8) (not (wall x10 y8)))
       (invariant (wall x10 y9) (not (wall x10 y9)))
       (invariant (wall x10 y10) (not (wall x10 y10)))
       (invariant (wall x11 y1) (not (wall x11 y1)))
       (invariant (wall x11 y2) (not (wall x11 y2)))
       (invariant (wall x11 y3) (not (wall x11 y3)))
       (invariant (wall x11 y4) (not (wall x11 y4)))
       (invariant (wall x11 y5) (not (wall x11 y5)))
       (invariant (wall x11 y6) (not (wall x11 y6)))
       (invariant (wall x11 y7) (not (wall x11 y7)))
       (invariant (wall x11 y8) (not (wall x11 y8)))
       (invariant (wall x11 y9) (not (wall x11 y9)))
       (invariant (wall x11 y10) (not (wall x11 y10)))
       (invariant (wall x12 y1) (not (wall x12 y1)))
       (invariant (wall x12 y2) (not (wall x12 y2)))
       (invariant (wall x12 y3) (not (wall x12 y3)))
       (invariant (wall x12 y4) (not (wall x12 y4)))
       (invariant (wall x12 y5) (not (wall x12 y5)))
       (invariant (wall x12 y6) (not (wall x12 y6)))
       (invariant (wall x12 y7) (not (wall x12 y7)))
       (invariant (wall x12 y8) (not (wall x12 y8)))
       (invariant (wall x12 y9) (not (wall x12 y9)))
       (invariant (wall x12 y10) (not (wall x12 y10)))
    )
    (:hidden
       (wall x1 y1) (wall x1 y2) (wall x1 y3) (wall x1 y4) (wall x1 y5) (wall x1 y6)
       (wall x1 y7) (wall x1 y8) (wall x1 y9) (wall x1 y10) (wall x2 y1) (wall x2 y10)
       (wall x3 y1) (wall x3 y10) (wall x4 y1) (wall x4 y3) (wall x4 y5) (wall x4 y6)
       (wall x4 y7) (wall x4 y8) (wall x4 y10) (wall x5 y1) (wall x5 y3) (wall x5 y8)
       (wall x5 y10) (wall x6 y1) (wall x6 y3) (wall x6 y8) (wall x6 y10) (wall x7 y1)
       (wall x7 y3) (wall x7 y8) (wall x7 y10) (wall x8 y1) (wall x8 y3) (wall x8 y8)
       (wall x8 y10) (wall x9 y1) (wall x9 y3) (wall x9 y4) (wall x9 y5) (wall x9 y6)
       (wall x9 y8) (wall x9 y10) (wall x10 y1) (wall x10 y10) (wall x11 y1) (wall x11 y10)
       (wall x12 y1) (wall x12 y2) (wall x12 y3) (wall x12 y4) (wall x12 y5) (wall x12 y6)
       (wall x12 y7) (wall x12 y8) (wall x12 y9) (wall x12 y10)    )
    (:goal (at x5 y4))
)
