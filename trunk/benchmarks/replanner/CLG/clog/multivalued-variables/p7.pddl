(define (problem att_log0) 
    (:domain logistics_conf)
    ;(:requirements :strips :equality :typing :conditional-effects :disjunctive-preconditions)			
    (:objects
        package1 package2 package3 - OBJ
        pgh_truck bos_truck phx_truck - TRUCK
        airplane1 - AIRPLANE
        bos_po pgh_po phx_po - LOCATION
        bos_airport pgh_airport phx_airport - AIRPORT
        pgh bos phx - CITY
    )
    (:init 
        (in_city_l bos_po bos)
        (in_city_a bos_airport bos)
        (in_city_l phx_po phx)
        (in_city_a phx_airport phx)
        (in_city_l pgh_po pgh)
        (in_city_a pgh_airport pgh)
        (in_city_t pgh_truck pgh)
        (in_city_t bos_truck bos)
        (in_city_t phx_truck phx)

        (at_tl bos_truck bos_po)
        (at_tl pgh_truck pgh_po)
        (at_tl phx_truck phx_po)
        (at_aa airplane1 pgh_airport)

        (not (at_oa package1 bos_airport))
        (not (at_oa package1 pgh_airport))
        (not (at_oa package1 phx_airport))
        (not (in_ot package1 pgh_truck))
        (not (in_ot package1 bos_truck))
        (not (in_ot package1 phx_truck))
        (not (in_oa package1 airplane1))

        (not (at_ol package2 phx_po))
        (not (at_oa package2 bos_airport))
        (not (at_oa package2 pgh_airport))
        (not (at_oa package2 phx_airport))
        (not (in_ot package2 pgh_truck))
        (not (in_ot package2 bos_truck))
        (not (in_ot package2 phx_truck))
        (not (in_oa package2 airplane1))

        (not (at_ol package3 pgh_po))
        (not (at_oa package3 bos_airport))
        (not (at_oa package3 pgh_airport))
        (not (at_oa package3 phx_airport))
        (not (in_ot package3 pgh_truck))
        (not (in_ot package3 bos_truck))
        (not (in_ot package3 phx_truck))
        (not (in_oa package3 airplane1))
    )
    (:goal (and (at_oa package1 bos_airport) (at_oa package2 phx_airport) (at_oa package3 pgh_airport)))
)

