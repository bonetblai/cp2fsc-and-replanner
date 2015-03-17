(define (problem unix-2)
    (:domain unix)
    (:objects
        root
        sub1 sub2
        sub11 sub12 sub21 sub22
        sub111 sub112 sub121 sub122 sub211 sub212 sub221 sub222 - DIR
        my-file - FILE
    )
    (:init
        (sub-dir root sub1)
        (sub-dir root sub2)
        (sub-dir sub1 sub11)
        (sub-dir sub1 sub12)
        (sub-dir sub2 sub21)
        (sub-dir sub2 sub22)
        (sub-dir sub11 sub111)
        (sub-dir sub11 sub112)
        (sub-dir sub21 sub211)
        (sub-dir sub21 sub212)
        (sub-dir sub12 sub121)
        (sub-dir sub12 sub122)
        (sub-dir sub22 sub221)
        (sub-dir sub22 sub222)
        (is-cur-dir root)
    )
    (:goal (file-in-dir my-file root))
)

