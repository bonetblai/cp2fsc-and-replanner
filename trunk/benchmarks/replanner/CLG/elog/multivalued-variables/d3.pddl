(define (domain logistics-conf)
    (:types OBJ TRUCK LOCATION AIRPLANE CITY AIRPORT)
    (:predicates
        (at-tl ?truck - TRUCK  ?loc - LOCATION)
        (at-ta ?truck - TRUCK  ?airport - AIRPORT)
        (at-aa ?airplane - AIRPLANE ?airport - AIRPORT)
        (at-ol ?obj - OBJ ?loc - LOCATION)
        (at-oa ?obj - OBJ ?airport - AIRPORT)
        (in-ot ?obj - OBJ ?truck - TRUCK)
        (in-oa ?obj - OBJ ?airplane - AIRPLANE)
        (in-city-l ?loc - LOCATION ?city - CITY)
        (in-city-a ?airport - AIRPORT ?city - CITY)
        (in-city-t ?truck - TRUCK ?city - CITY)
    )

    (:variable (obj-pos ?obj - OBJ)
        (forall (?l - LOCATION) (at-ol ?obj ?l))
        (forall (?a - AIRPORT) (at-oa ?obj ?a))
        (forall (?t - TRUCK) (in-ot ?obj ?t))
        (forall (?a - AIRPLANE) (in-oa ?obj ?a))
    )
    (:variable (truck-pos ?truck - TRUCK)
        (forall (?l - LOCATION) (at-tl ?truck ?l))
        (forall (?a - AIRPORT) (at-ta ?truck ?a))
    )
    (:variable (airplane-pos ?airplane - AIRPLANE)
        (forall (?a - AIRPORT) (at-aa ?airplane ?a))
    )

    (:action sense-loc-t
        :parameters (?loc - LOCATION ?truck - TRUCK)
        :precondition (at-tl ?truck ?loc)
        :sensing-model (forall (?obj - OBJ) (at-ol ?obj ?loc))
    )
    (:action sense-ap-t
        :parameters (?airport - AIRPORT ?truck - TRUCK)
        :precondition (at-ta ?truck ?airport)
        :sensing-model (forall (?obj - OBJ) (at-oa ?obj ?airport))
    )
    (:action sense-ap-a
        :parameters (?airport - AIRPORT ?airplane - AIRPLANE)
        :precondition (at-aa ?airplane ?airport)
        :sensing-model (forall (?obj - OBJ) (at-oa ?obj ?airport))
    )

    (:action LOAD-TRUCK-LOC
        :parameters (?obj - OBJ ?truck - TRUCK ?loc - LOCATION ?city - CITY)
        :precondition (and (at-tl ?truck ?loc) (in-city-t ?truck ?city) (in-city-l ?loc ?city) (at-ol ?obj ?loc))
        :effect (and (not (at-ol ?obj ?loc)) (in-ot ?obj ?truck))
    )

    (:action LOAD-TRUCK-AP
        :parameters (?obj - OBJ ?truck - TRUCK ?airport - AIRPORT ?city - CITY)
        :precondition (and (at-ta ?truck ?airport) (in-city-t ?truck ?city) (in-city-a ?airport ?city) (at-oa ?obj ?airport))
        :effect (and (not (at-oa ?obj ?airport)) (in-ot ?obj ?truck))
    )

    (:action LOAD-AIRPLANE
        :parameters (?obj - OBJ ?airplane - AIRPLANE ?airport - AIRPORT) 
        :precondition (and (at-aa ?airplane ?airport) (at-oa ?obj ?airport))
        :effect (and (not (at-oa ?obj ?airport)) (in-oa ?obj ?airplane))
    )

    (:action UNLOAD-TRUCK-LOC
        :parameters (?obj - OBJ ?truck - TRUCK ?loc - LOCATION ?city - CITY)
        :precondition (and (at-tl ?truck ?loc) (in-city-t ?truck ?city) (in-city-l ?loc ?city))
        :effect (when (in-ot ?obj ?truck) (and (not (in-ot ?obj ?truck)) (at-ol ?obj ?loc)))
    )

    (:action UNLOAD-TRUCK-AP
        :parameters (?obj - OBJ ?truck - TRUCK ?airport - AIRPORT ?city - CITY)
        :precondition (and (at-ta ?truck ?airport) (in-city-t ?truck ?city) (in-city-a ?airport ?city))
        :effect (when (in-ot ?obj ?truck) (and (not (in-ot ?obj ?truck)) (at-oa ?obj ?airport)))
    )

    (:action UNLOAD-AIRPLANE
        :parameters (?obj - OBJ ?airplane - AIRPLANE ?airport - AIRPORT)
        :precondition (at-aa ?airplane ?airport)
        :effect (when (in-oa ?obj ?airplane) (and (not (in-oa ?obj ?airplane)) (at-oa ?obj ?airport)))
    )

    (:action DRIVE-TRUCK-LOC-AP
        :parameters (?truck - TRUCK ?loc - LOCATION ?airport - AIRPORT ?city - CITY)
        :precondition (and (at-tl ?truck ?loc) (in-city-l ?loc ?city) (in-city-a ?airport ?city) (in-city-t ?truck ?city))
        :effect (and (not (at-tl ?truck ?loc)) (at-ta ?truck ?airport))
    )

    (:action DRIVE-TRUCK-AP-LOC
        :parameters (?truck - TRUCK ?airport - AIRPORT ?loc - LOCATION ?city - CITY)
        :precondition (and (at-ta ?truck ?airport) (in-city-a ?airport ?city) (in-city-l ?loc ?city) (in-city-t ?truck ?city))
        :effect (and (not (at-ta ?truck ?airport)) (at-tl ?truck ?loc))
    )

    (:action FLY-AIRPLANE
        :parameters (?airplane - AIRPLANE ?airport1 - AIRPORT ?airport2 - AIRPORT)
        :precondition (and (at-aa ?airplane ?airport1))
        :effect (and (not (at-aa ?airplane ?airport1)) (at-aa ?airplane ?airport2))
    )
)

