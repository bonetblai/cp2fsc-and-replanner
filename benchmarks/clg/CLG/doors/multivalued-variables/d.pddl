(define (domain doors) 
   (:requirements :strips :typing)
   (:types col pos)
   (:predicates (adj ?i ?j - pos) (at ?i - pos)  (opened ?i - pos) (at-col ?c - col ?i - pos))

   (:variable (door-at ?c - col) (forall (?i - pos) (when (at-col ?c ?i) (opened ?i))))
                
   (:action sense
      :parameters (?i - pos)
      :precondition (at ?i)
      :sensing-model
          (forall (?j - pos ?c - col) (when (and (adj ?i ?j) (at-col ?c ?j)) (opened ?j)))
   )

   (:action move
      :parameters (?i - pos ?j - pos )
      :precondition (and (adj ?i ?j) (at ?i) (opened ?j))
      :effect (and (not (at ?i)) (at ?j)) 
      :sensing-model
          (forall (?k - pos ?c - col) (when (and (adj ?j ?k) (at-col ?c ?k)) (opened ?k)))
   )
)

