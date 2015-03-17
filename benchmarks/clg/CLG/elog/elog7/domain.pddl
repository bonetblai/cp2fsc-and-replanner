
(define (domain logistics-conf)
  (:types OBJ TRUCK LOCATION AIRPLANE CITY AIRPORT )
  (:predicates 	(at-tl ?obj - TRUCK  ?loc - LOCATION)
		(at-ta ?obj - TRUCK  ?loc - AIRPORT)
		(at-aa ?obj - AIRPLANE ?loc - AIRPORT)
		(at-ol ?obj - OBJ ?loc - LOCATION)
		(at-oa ?obj - OBJ ?loc - AIRPORT)
		(in-ot ?obj1 - OBJ ?obj2 - TRUCK)
		(in-oa ?obj1 - OBJ ?obj2 - AIRPLANE)
		(in-city-l ?loc - LOCATION ?city - CITY)
		(in-city-a ?loc - AIRPORT ?city - CITY)
		(in-city-t ?loc - TRUCK ?city - CITY))

 
(:action sense-package-loc-t
 :parameters (?obj - OBJ ?loc - LOCATION ?truck - TRUCK)
 :precondition (at-tl ?truck ?loc)
 :observe (at-ol ?obj ?loc))

(:action sense-package-ap-t
 :parameters (?obj - OBJ ?loc - AIRPORT ?truck - TRUCK)
 :precondition (at-ta ?truck ?loc)
 :observe (at-oa ?obj ?loc))

(:action sense-package-ap-a
 :parameters (?obj - OBJ ?loc - AIRPORT ?airplane - AIRPLANE)
 :precondition (at-aa ?airplane ?loc)
 :observe (at-oa ?obj ?loc))


(:action LOAD-TRUCK-LOC
  :parameters
   (?obj - OBJ
    ?truck - TRUCK
    ?loc - LOCATION 
    ?city - CITY)
  :precondition
   (and 
	(at-tl ?truck ?loc) 
 	(in-city-t ?truck ?city)
	(in-city-l ?loc ?city)
  	(at-ol ?obj ?loc)
   )
  :effect
   (and (not (at-ol ?obj ?loc)) 
	  (in-ot ?obj ?truck)))

(:action LOAD-TRUCK-AP
  :parameters
   (?obj - OBJ
    ?truck - TRUCK
    ?loc - AIRPORT
    ?city - CITY)
  :precondition
   (and 
	(at-ta ?truck ?loc) 
 	(in-city-t ?truck ?city)
	(in-city-a ?loc ?city)
	(at-oa ?obj ?loc) 
  
   )
  :effect (and (not (at-oa ?obj ?loc)) 
	  (in-ot ?obj ?truck)))

(:action LOAD-AIRPLANE
  :parameters
   (?obj - OBJ ?airplane - AIRPLANE ?loc - AIRPORT) 
  :precondition
   (and (at-aa ?airplane ?loc) (at-oa ?obj ?loc))
  :effect
   (and (not (at-oa ?obj ?loc)) 
              (in-oa ?obj ?airplane)))

(:action UNLOAD-TRUCK-LOC
  :parameters
   (?obj - OBJ
    ?truck - TRUCK
    ?loc - LOCATION
    ?city - CITY)
  :precondition
   (and 
	(at-tl ?truck ?loc) 
	(in-city-t ?truck ?city)
	(in-city-l ?loc ?city)
        ;(not (at-ol ?obj ?loc))
   )
  :effect
   (when (in-ot ?obj ?truck) 
	 (and (not (in-ot ?obj ?truck)) 
              (at-ol ?obj ?loc))))

(:action UNLOAD-TRUCK-AP
  :parameters
   (?obj - OBJ
    ?truck - TRUCK
    ?loc - AIRPORT
    ?city - CITY)
  :precondition
   (and 
	(at-ta ?truck ?loc) 
	(in-city-t ?truck ?city)
	(in-city-a ?loc ?city)
        ;(not (at-ol ?obj ?loc))
   )
  :effect
   (when (in-ot ?obj ?truck) 
	 (and (not (in-ot ?obj ?truck)) 
              (at-oa ?obj ?loc))))

(:action UNLOAD-AIRPLANE
  :parameters
   (?obj - OBJ
    ?airplane - AIRPLANE
    ?loc - AIRPORT)
  :precondition
   (at-aa ?airplane ?loc)	
  :effect
   (when (in-oa ?obj ?airplane)   
	 (and (not (in-oa ?obj ?airplane)) 
              (at-oa ?obj ?loc))))

(:action DRIVE-TRUCK-LOC-AP
  :parameters
   (?truck - TRUCK
    ?loc1 - LOCATION
    ?loc2 - AIRPORT
    ?city - CITY)
  :precondition
   (and (at-tl ?truck ?loc1)
        (in-city-l ?loc1 ?city)
        (in-city-a ?loc2 ?city)
	(in-city-t ?truck ?city)
	;(not (at-ta ?truck ?loc2))
   )
  :effect
   (and (not (at-tl ?truck ?loc1)) 
        (at-ta ?truck ?loc2)))

(:action DRIVE-TRUCK-AP-LOC
  :parameters
   (?truck - TRUCK
    ?loc1 - AIRPORT
    ?loc2 - LOCATION 
    ?city - CITY)
    :precondition
   (and (at-ta ?truck ?loc1)
        (in-city-a ?loc1 ?city)
        (in-city-l ?loc2 ?city)
	(in-city-t ?truck ?city)
	;(not (at-tl ?truck ?loc2))
   )
  :effect
   (and (not (at-ta ?truck ?loc1)) 
        (at-tl ?truck ?loc2)))

(:action FLY-AIRPLANE
  :parameters
   (?airplane - AIRPLANE
    ?loc1 - AIRPORT
    ?loc2 - AIRPORT)
  :precondition
  (and  
	(at-aa ?airplane ?loc1)
	;(not (at ?airplane ?loc2) 
  )
  :effect
   (and (not (at-aa ?airplane ?loc1) )
        (at-aa ?airplane ?loc2 )))
)




 
