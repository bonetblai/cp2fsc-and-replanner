
(define (domain sliding-doors) 

   (:requirements :strips :typing)
   (:types pos )
   (:predicates (ok) ( at ?i ) (free-up) (free-down) (free-left) (free-right) )
   (:constants p1-1 p1-2 p1-3 p2-1 p2-2 p2-3 p3-1 p3-2 p3-3 - pos

 )
 
    (:action sense-up
      :observe (free-up) )

   (:action sense-down
     :observe (free-down) )

   (:action sense-left
     :observe (free-left) )

   (:action sense-right
     :observe (free-right) )

   (:action move-up
     :precondition (and (ok) (free-up))
     :effect (and (not (ok)) 
       (when (and  (at p1-1)) (and (at p1-2) (not (at  p1-1))))
       (when (and  (at p3-1)) (and (at p3-2) (not (at  p3-1))))
       (when (and  (at p1-2)) (and (at p1-3) (not (at  p1-2))))
       (when (and  (at p3-2)) (and (at p3-3) (not (at  p3-2))))
   ))
  (:action move-down
     :precondition (and (ok) (free-down))
     :effect (and (not (ok)) 
       (when (and  (at p1-2)) (and (at p1-1) (not (at  p1-2))))
       (when (and  (at p3-2)) (and (at p3-1) (not (at  p3-2))))
       (when (and  (at p1-3)) (and (at p1-2) (not (at  p1-3))))
       (when (and  (at p3-3)) (and (at p3-2) (not (at  p3-3))))
   ))
 (:action move-left
     :precondition (and (ok) (free-left))
     :effect (and (not (ok)) 
       (when (and  (at p2-1)) (and  (at p1-1) (not (at  p2-1))))
       (when (and  (at p3-1)) (and  (at p2-1) (not (at  p3-1))))
       (when (and  (at p2-3)) (and  (at p1-3) (not (at  p2-3))))
       (when (and  (at p3-3)) (and  (at p2-3) (not (at  p3-3))))
   ))
(:action move-right
     :precondition (and (ok) (free-right))
     :effect (and (not (ok)) 
       (when (and  (at p1-1)) (and (at p2-1) (not (at  p1-1))))
       (when (and  (at p2-1)) (and (at p3-1) (not (at  p2-1))))
       (when (and  (at p1-3)) (and (at p2-3) (not (at  p1-3))))
       (when (and  (at p2-3)) (and (at p3-3) (not (at  p2-3))))
   ))
   (:action checking
     :parameters ()
     :effect (and (ok)

       (when (and  (not (ok)) (at p2-1)) (and (free-left) (free-right) (not (free-up)) (not (free-down))))
       (when (and  (not (ok)) (at p2-3)) (and (free-left) (free-right) (not (free-up)) (not (free-down))))
       (when (and  (not (ok)) (at p1-2)) (and (free-up) (free-down) (not (free-left)) (not (free-right))))
       (when (and  (not (ok)) (at p3-2)) (and (free-up) (free-down) (not (free-left)) (not (free-right))))
       (when (and  (not (ok)) (at p1-1)) (and (free-up) (free-right) (not (free-down)) (not (free-left))))
       (when (and  (not (ok)) (at p3-1)) (and (free-up) (free-left) (not (free-down)) (not (free-right))))
       (when (and  (not (ok)) (at p1-3)) (and (free-down) (free-right) (not (free-up)) (not (free-left))))
       (when (and  (not (ok)) (at p3-3)) (and (free-down) (free-left) (not (free-up)) (not (free-right))))
 )) )
