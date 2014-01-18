(define (domain logistics)
    (:types OBJ TRUCK LOCATION AIRPLANE CITY AIRPORT)
    (:predicates
        (at_tl ?truck - TRUCK  ?loc - LOCATION)
        (at_ta ?truck - TRUCK  ?airport - AIRPORT)
        (at_aa ?airplane - AIRPLANE ?airport - AIRPORT)
        (at_ol ?obj - OBJ ?loc - LOCATION)
        (at_oa ?obj - OBJ ?airport - AIRPORT)
        (in_ot ?obj - OBJ ?truck - TRUCK)
        (in_oa ?obj - OBJ ?airplane - AIRPLANE)
        (in_city_l ?loc - LOCATION ?city - CITY)
        (in_city_a ?airport - AIRPORT ?city - CITY)
        (in_city_t ?truck - TRUCK ?city - CITY)
    )

    (:variable (obj-pos ?obj - OBJ)
        (forall (?l - LOCATION) (at_ol ?obj ?l))
        (forall (?a - AIRPORT) (at_oa ?obj ?a))
        (forall (?t - TRUCK) (in_ot ?obj ?t))
        (forall (?a - AIRPLANE) (in_oa ?obj ?a))
    )
    (:variable (truck-pos ?truck - TRUCK)
        (forall (?l - LOCATION) (at_tl ?truck ?l))
        (forall (?a - AIRPORT) (at_ta ?truck ?a))
    )
    (:variable (airplane-pos ?airplane - AIRPLANE)
        (forall (?a - AIRPORT) (at_aa ?airplane ?a))
    )

    (:action sense_package_loc_t
        :parameters (?obj - OBJ ?truck - TRUCK ?loc - LOCATION)
        :precondition (at_tl ?truck ?loc)
        :sensing-model (at_ol ?obj ?loc)
    )
    (:action sense_package_ap_t
        :parameters (?obj - OBJ ?truck - TRUCK ?airport - AIRPORT)
        :precondition (at_ta ?truck ?airport)
        :sensing-model (at_oa ?obj ?airport)
    )
    (:action sense_package_ap_a
        :parameters (?obj - OBJ ?airplane - AIRPLANE ?airport - AIRPORT)
        :precondition (at_aa ?airplane ?airport)
        :sensing-model (at_oa ?obj ?airport)
    )

    (:action LOAD_TRUCK_LOC
        :parameters (?obj - OBJ ?truck - TRUCK ?loc - LOCATION ?city - CITY)
        :precondition (and (at_tl ?truck ?loc) (in_city_t ?truck ?city) (in_city_l ?loc ?city) (at_ol ?obj ?loc))
        :effect (and (not (at_ol ?obj ?loc)) (in_ot ?obj ?truck))
    ) 

    (:action LOAD_TRUCK_AP
        :parameters (?obj - OBJ ?truck - TRUCK ?airport - AIRPORT ?city - CITY)
        :precondition (and (at_ta ?truck ?airport) (in_city_t ?truck ?city) (in_city_a ?airport ?city) (at_oa ?obj ?airport))
        :effect (and (not (at_oa ?obj ?airport)) (in_ot ?obj ?truck))
    )

    (:action LOAD_AIRPLANE
        :parameters (?obj - OBJ ?airplane - AIRPLANE ?airport - AIRPORT) 
        :precondition (and (at_aa ?airplane ?airport) (at_oa ?obj ?airport))
        :effect (and (not (at_oa ?obj ?airport)) (in_oa ?obj ?airplane))
    )

    (:action UNLOAD_TRUCK_LOC
        :parameters (?obj - OBJ ?truck - TRUCK ?loc - LOCATION ?city - CITY)
        :precondition (and (at_tl ?truck ?loc) (in_city_t ?truck ?city) (in_city_l ?loc ?city)(in_ot ?obj ?truck))
        :effect (and (not (in_ot ?obj ?truck)) (at_ol ?obj ?loc))
    )

    (:action UNLOAD_TRUCK_AP
        :parameters (?obj - OBJ ?truck - TRUCK ?airport - AIRPORT ?city - CITY)
        :precondition (and (at_ta ?truck ?airport) (in_city_t ?truck ?city) (in_city_a ?airport ?city) (in_ot ?obj ?truck))
        :effect (and (not (in_ot ?obj ?truck)) (at_oa ?obj ?airport))
    )

    (:action UNLOAD_AIRPLANE
        :parameters (?obj - OBJ ?airplane - AIRPLANE ?airport - AIRPORT)
        :precondition (and (at_aa ?airplane ?airport) (in_oa ?obj ?airplane))
        :effect (and (not (in_oa ?obj ?airplane)) (at_oa ?obj ?airport))
    )

    (:action DRIVE_TRUCK_LOC_AP
        :parameters (?truck - TRUCK ?loc - LOCATION ?airport - AIRPORT ?city - CITY)
        :precondition (and (at_tl ?truck ?loc) (in_city_l ?loc ?city) (in_city_a ?airport ?city) (in_city_t ?truck ?city))
        :effect (and (not (at_tl ?truck ?loc)) (at_ta ?truck ?airport))
    )

    (:action DRIVE_TRUCK_AP_LOC
        :parameters (?truck - TRUCK ?airport - AIRPORT ?loc - LOCATION ?city - CITY)
        :precondition (and (at_ta ?truck ?airport) (in_city_a ?airport ?city) (in_city_l ?loc ?city) (in_city_t ?truck ?city))
        :effect (and (not (at_ta ?truck ?airport)) (at_tl ?truck ?loc))
    )

    (:action FLY_AIRPLANE
        :parameters (?airplane - AIRPLANE ?airport1 - AIRPORT ?airport2 - AIRPORT)
        :precondition (and (at_aa ?airplane ?airport1))
        :effect (and (not (at_aa ?airplane ?airport1)) (at_aa ?airplane ?airport2))
    )
)

