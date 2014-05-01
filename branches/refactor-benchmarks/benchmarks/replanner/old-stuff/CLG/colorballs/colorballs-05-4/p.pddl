(define (problem colorballs-5-4)
(:domain colorballs)

 (:objects 
    o1
    o2
    o3
    o4

 - obj 
    p1-1
    p1-2
    p1-3
    p1-4
    p1-5
    p2-1
    p2-2
    p2-3
    p2-4
    p2-5
    p3-1
    p3-2
    p3-3
    p3-4
    p3-5
    p4-1
    p4-2
    p4-3
    p4-4
    p4-5
    p5-1
    p5-2
    p5-3
    p5-4
    p5-5

 - pos 
    red
    blue
    purple
    green

 - col 
    t1
    t2
    t3
    t4

 - gar 
    )
   (:init
    (and
     (at p3-3)
    (garbage-at t1 p1-1)
    (garbage-at t2 p1-5)
    (garbage-at t3 p5-1)
    (garbage-at t4 p5-5)
    (garbage-color t1 red)
    (garbage-color t2 blue)
    (garbage-color t3 green)
    (garbage-color t4 purple)

     (adj p1-1 p2-1)
     (adj p2-1 p1-1)

     (adj p1-2 p2-2)
     (adj p2-2 p1-2)

     (adj p1-3 p2-3)
     (adj p2-3 p1-3)

     (adj p1-4 p2-4)
     (adj p2-4 p1-4)

     (adj p1-5 p2-5)
     (adj p2-5 p1-5)

     (adj p2-1 p3-1)
     (adj p3-1 p2-1)

     (adj p2-2 p3-2)
     (adj p3-2 p2-2)

     (adj p2-3 p3-3)
     (adj p3-3 p2-3)

     (adj p2-4 p3-4)
     (adj p3-4 p2-4)

     (adj p2-5 p3-5)
     (adj p3-5 p2-5)

     (adj p3-1 p4-1)
     (adj p4-1 p3-1)

     (adj p3-2 p4-2)
     (adj p4-2 p3-2)

     (adj p3-3 p4-3)
     (adj p4-3 p3-3)

     (adj p3-4 p4-4)
     (adj p4-4 p3-4)

     (adj p3-5 p4-5)
     (adj p4-5 p3-5)

     (adj p4-1 p5-1)
     (adj p5-1 p4-1)

     (adj p4-2 p5-2)
     (adj p5-2 p4-2)

     (adj p4-3 p5-3)
     (adj p5-3 p4-3)

     (adj p4-4 p5-4)
     (adj p5-4 p4-4)

     (adj p4-5 p5-5)
     (adj p5-5 p4-5)


     (adj p1-1 p1-2)
     (adj p1-2 p1-1)

     (adj p2-1 p2-2)
     (adj p2-2 p2-1)

     (adj p3-1 p3-2)
     (adj p3-2 p3-1)

     (adj p4-1 p4-2)
     (adj p4-2 p4-1)

     (adj p5-1 p5-2)
     (adj p5-2 p5-1)

     (adj p1-2 p1-3)
     (adj p1-3 p1-2)

     (adj p2-2 p2-3)
     (adj p2-3 p2-2)

     (adj p3-2 p3-3)
     (adj p3-3 p3-2)

     (adj p4-2 p4-3)
     (adj p4-3 p4-2)

     (adj p5-2 p5-3)
     (adj p5-3 p5-2)

     (adj p1-3 p1-4)
     (adj p1-4 p1-3)

     (adj p2-3 p2-4)
     (adj p2-4 p2-3)

     (adj p3-3 p3-4)
     (adj p3-4 p3-3)

     (adj p4-3 p4-4)
     (adj p4-4 p4-3)

     (adj p5-3 p5-4)
     (adj p5-4 p5-3)

     (adj p1-4 p1-5)
     (adj p1-5 p1-4)

     (adj p2-4 p2-5)
     (adj p2-5 p2-4)

     (adj p3-4 p3-5)
     (adj p3-5 p3-4)

     (adj p4-4 p4-5)
     (adj p4-5 p4-4)

     (adj p5-4 p5-5)
     (adj p5-5 p5-4)


     (oneof
        (obj-at o1 p1-2)
        (obj-at o1 p1-3)
        (obj-at o1 p1-4)
        (obj-at o1 p2-1)
        (obj-at o1 p2-2)
        (obj-at o1 p2-3)
        (obj-at o1 p2-4)
        (obj-at o1 p2-5)
        (obj-at o1 p3-1)
        (obj-at o1 p3-2)
        (obj-at o1 p3-3)
        (obj-at o1 p3-4)
        (obj-at o1 p3-5)
        (obj-at o1 p4-1)
        (obj-at o1 p4-2)
        (obj-at o1 p4-3)
        (obj-at o1 p4-4)
        (obj-at o1 p4-5)
        (obj-at o1 p5-2)
        (obj-at o1 p5-3)
        (obj-at o1 p5-4)
     )
     (oneof
        (obj-at o2 p1-2)
        (obj-at o2 p1-3)
        (obj-at o2 p1-4)
        (obj-at o2 p2-1)
        (obj-at o2 p2-2)
        (obj-at o2 p2-3)
        (obj-at o2 p2-4)
        (obj-at o2 p2-5)
        (obj-at o2 p3-1)
        (obj-at o2 p3-2)
        (obj-at o2 p3-3)
        (obj-at o2 p3-4)
        (obj-at o2 p3-5)
        (obj-at o2 p4-1)
        (obj-at o2 p4-2)
        (obj-at o2 p4-3)
        (obj-at o2 p4-4)
        (obj-at o2 p4-5)
        (obj-at o2 p5-2)
        (obj-at o2 p5-3)
        (obj-at o2 p5-4)
     )
     (oneof
        (obj-at o3 p1-2)
        (obj-at o3 p1-3)
        (obj-at o3 p1-4)
        (obj-at o3 p2-1)
        (obj-at o3 p2-2)
        (obj-at o3 p2-3)
        (obj-at o3 p2-4)
        (obj-at o3 p2-5)
        (obj-at o3 p3-1)
        (obj-at o3 p3-2)
        (obj-at o3 p3-3)
        (obj-at o3 p3-4)
        (obj-at o3 p3-5)
        (obj-at o3 p4-1)
        (obj-at o3 p4-2)
        (obj-at o3 p4-3)
        (obj-at o3 p4-4)
        (obj-at o3 p4-5)
        (obj-at o3 p5-2)
        (obj-at o3 p5-3)
        (obj-at o3 p5-4)
     )
     (oneof
        (obj-at o4 p1-2)
        (obj-at o4 p1-3)
        (obj-at o4 p1-4)
        (obj-at o4 p2-1)
        (obj-at o4 p2-2)
        (obj-at o4 p2-3)
        (obj-at o4 p2-4)
        (obj-at o4 p2-5)
        (obj-at o4 p3-1)
        (obj-at o4 p3-2)
        (obj-at o4 p3-3)
        (obj-at o4 p3-4)
        (obj-at o4 p3-5)
        (obj-at o4 p4-1)
        (obj-at o4 p4-2)
        (obj-at o4 p4-3)
        (obj-at o4 p4-4)
        (obj-at o4 p4-5)
        (obj-at o4 p5-2)
        (obj-at o4 p5-3)
        (obj-at o4 p5-4)
     )

     (oneof
       (color o1 red)
       (color o1 blue)
       (color o1 green)
       (color o1 purple)
     )
     (oneof
       (color o2 red)
       (color o2 blue)
       (color o2 green)
       (color o2 purple)
     )
     (oneof
       (color o3 red)
       (color o3 blue)
       (color o3 green)
       (color o3 purple)
     )
     (oneof
       (color o4 red)
       (color o4 blue)
       (color o4 green)
       (color o4 purple)
     )


    )
    )
    (:goal (and     (trashed o1)
    (trashed o2)
    (trashed o3)
    (trashed o4)
)))
