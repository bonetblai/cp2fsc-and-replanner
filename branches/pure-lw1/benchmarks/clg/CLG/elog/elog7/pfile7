;;; a three step plan works
(define (problem att-log0) 
  (:domain logistics-conf)
;;  (:requirements :strips :equality :typing :conditional-effects :disjunctive-preconditions)			
  (:objects 	package1 - OBJ
		package2 - OBJ
		package3 - OBJ
		pgh-truck - TRUCK
		bos-truck - TRUCK
		phx-truck - TRUCK
		airplane1 - AIRPLANE
		bos-po - LOCATION
		pgh-po - LOCATION
		phx-po - LOCATION
		bos-airport - AIRPORT 
		pgh-airport - AIRPORT 
		phx-airport - AIRPORT
		pgh - CITY
		bos - CITY
 		phx - CITY
	)
 (:init 

(unknown (at-ol package1 pgh-po))
(unknown (at-ol package1 phx-po))
(unknown (at-ol package1 bos-po))

	(oneof
	 (at-ol package1 pgh-po)
	 (at-ol package1 phx-po)
	 (at-ol package1 bos-po)
	)

(unknown (at-ol package2 pgh-po))
(unknown (at-ol package2 bos-po))


	(oneof
	(at-ol package2 pgh-po)
	(at-ol package2 bos-po)
	)


(unknown (at-ol package3 phx-po))
(unknown (at-ol package3 bos-po))

	(oneof
	 (at-ol package3 bos-po)
	 (at-ol package3 phx-po)
	 )



 	 (at-aa airplane1 pgh-airport)
	 (at-tl bos-truck bos-po)

	 (at-tl pgh-truck pgh-po)

	 (at-tl phx-truck phx-po)

	 (in-city-l bos-po bos)
	 (in-city-a bos-airport bos)
	 (in-city-l phx-po phx)
	 (in-city-a phx-airport phx)
	 (in-city-l pgh-po pgh)
	 (in-city-a pgh-airport pgh)
	 (in-city-t pgh-truck pgh)
	 (in-city-t bos-truck bos)
	 (in-city-t phx-truck phx)
)
(:goal
  (and 
	(at-oa package1 bos-airport)
	(at-oa package2 phx-airport)
	(at-oa package3 pgh-airport)
	)	
  )
)
