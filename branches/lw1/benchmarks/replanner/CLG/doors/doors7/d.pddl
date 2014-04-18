
(define (domain doors) 

   (:requirements :strips :typing)
   (:types pos )
   (:predicates (adj ?i ?j) (at ?i)  (opened ?i) )
                
   (:action sense-door
      :parameters (?i - pos ?j - pos )
      :precondition   (and (at ?i) (adj ?i ?j))
      :observe (opened ?j) )

   (:action move
      :parameters (?i - pos ?j - pos )
      :precondition (and (adj ?i ?j) (at ?i) (opened ?j))
      :effect  (and (not (at ?i)) (at ?j)) 
      )
)

