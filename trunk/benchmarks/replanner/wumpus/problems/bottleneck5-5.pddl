;; dim=(12,10)
;; init=(1,4)
;; goal=(1,5)
;; @@@@@@@@@@@@
;; @w..w......@
;; @..@@@@@@..@
;; @..@w..w...@
;; @G.@..w.@..@
;; @I.@.w..@..@
;; @.......@..@
;; @w.@@@@@@..@
;; @.ww...w...@
;; @@@@@@@@@@@@

(define (problem bottleneck5)
    (:domain wumpus)
    (:objects p11 p12 p13 p14 p15 p16 p17 p18 p21 p22 p23 p24 p25 p26 p27 p28 p31 p33 p38 p41 p43 p44 p45 p46 p48 p51 p53 p54 p55 p56 p58 p61 p63 p64 p65 p66 p68 p71 p73 p74 p75 p76 p78 p81 p86 p88 p91 p92 p93 p94 p95 p96 p97 p98 p101 p102 p103 p104 p105 p106 p107 p108 - pos)
    (:init
       (adj p11 p12)
       (adj p11 p21)
       (adj p12 p13)
       (adj p12 p22)
       (adj p12 p11)
       (adj p13 p14)
       (adj p13 p23)
       (adj p13 p12)
       (adj p14 p15)
       (adj p14 p24)
       (adj p14 p13)
       (adj p15 p16)
       (adj p15 p25)
       (adj p15 p14)
       (adj p16 p17)
       (adj p16 p26)
       (adj p16 p15)
       (adj p17 p18)
       (adj p17 p27)
       (adj p17 p16)
       (adj p18 p28)
       (adj p18 p17)
       (adj p21 p22)
       (adj p21 p31)
       (adj p21 p11)
       (adj p22 p23)
       (adj p22 p21)
       (adj p22 p12)
       (adj p23 p24)
       (adj p23 p33)
       (adj p23 p22)
       (adj p23 p13)
       (adj p24 p25)
       (adj p24 p23)
       (adj p24 p14)
       (adj p25 p26)
       (adj p25 p24)
       (adj p25 p15)
       (adj p26 p27)
       (adj p26 p25)
       (adj p26 p16)
       (adj p27 p28)
       (adj p27 p26)
       (adj p27 p17)
       (adj p28 p38)
       (adj p28 p27)
       (adj p28 p18)
       (adj p31 p41)
       (adj p31 p21)
       (adj p33 p43)
       (adj p33 p23)
       (adj p38 p48)
       (adj p38 p28)
       (adj p41 p51)
       (adj p41 p31)
       (adj p43 p44)
       (adj p43 p53)
       (adj p43 p33)
       (adj p44 p45)
       (adj p44 p54)
       (adj p44 p43)
       (adj p45 p46)
       (adj p45 p55)
       (adj p45 p44)
       (adj p46 p56)
       (adj p46 p45)
       (adj p48 p58)
       (adj p48 p38)
       (adj p51 p61)
       (adj p51 p41)
       (adj p53 p54)
       (adj p53 p63)
       (adj p53 p43)
       (adj p54 p55)
       (adj p54 p64)
       (adj p54 p53)
       (adj p54 p44)
       (adj p55 p56)
       (adj p55 p65)
       (adj p55 p54)
       (adj p55 p45)
       (adj p56 p66)
       (adj p56 p55)
       (adj p56 p46)
       (adj p58 p68)
       (adj p58 p48)
       (adj p61 p71)
       (adj p61 p51)
       (adj p63 p64)
       (adj p63 p73)
       (adj p63 p53)
       (adj p64 p65)
       (adj p64 p74)
       (adj p64 p63)
       (adj p64 p54)
       (adj p65 p66)
       (adj p65 p75)
       (adj p65 p64)
       (adj p65 p55)
       (adj p66 p76)
       (adj p66 p65)
       (adj p66 p56)
       (adj p68 p78)
       (adj p68 p58)
       (adj p71 p81)
       (adj p71 p61)
       (adj p73 p74)
       (adj p73 p63)
       (adj p74 p75)
       (adj p74 p73)
       (adj p74 p64)
       (adj p75 p76)
       (adj p75 p74)
       (adj p75 p65)
       (adj p76 p86)
       (adj p76 p75)
       (adj p76 p66)
       (adj p78 p88)
       (adj p78 p68)
       (adj p81 p91)
       (adj p81 p71)
       (adj p86 p96)
       (adj p86 p76)
       (adj p88 p98)
       (adj p88 p78)
       (adj p91 p92)
       (adj p91 p101)
       (adj p91 p81)
       (adj p92 p93)
       (adj p92 p102)
       (adj p92 p91)
       (adj p93 p94)
       (adj p93 p103)
       (adj p93 p92)
       (adj p94 p95)
       (adj p94 p104)
       (adj p94 p93)
       (adj p95 p96)
       (adj p95 p105)
       (adj p95 p94)
       (adj p96 p97)
       (adj p96 p106)
       (adj p96 p95)
       (adj p96 p86)
       (adj p97 p98)
       (adj p97 p107)
       (adj p97 p96)
       (adj p98 p108)
       (adj p98 p97)
       (adj p98 p88)
       (adj p101 p102)
       (adj p101 p91)
       (adj p102 p103)
       (adj p102 p101)
       (adj p102 p92)
       (adj p103 p104)
       (adj p103 p102)
       (adj p103 p93)
       (adj p104 p105)
       (adj p104 p103)
       (adj p104 p94)
       (adj p105 p106)
       (adj p105 p104)
       (adj p105 p95)
       (adj p106 p107)
       (adj p106 p105)
       (adj p106 p96)
       (adj p107 p108)
       (adj p107 p106)
       (adj p107 p97)
       (adj p108 p107)
       (adj p108 p98)

       (at p14)

       ; Invariants: (or wumpus(p) -wumpus(p))
       (invariant (wumpus p11) (not (wumpus p11)))
       (invariant (wumpus p12) (not (wumpus p12)))
       (invariant (wumpus p13) (not (wumpus p13)))
       (invariant (wumpus p15) (not (wumpus p15)))
       (invariant (wumpus p16) (not (wumpus p16)))
       (invariant (wumpus p17) (not (wumpus p17)))
       (invariant (wumpus p18) (not (wumpus p18)))
       (invariant (wumpus p21) (not (wumpus p21)))
       (invariant (wumpus p22) (not (wumpus p22)))
       (invariant (wumpus p23) (not (wumpus p23)))
       (invariant (wumpus p24) (not (wumpus p24)))
       (invariant (wumpus p25) (not (wumpus p25)))
       (invariant (wumpus p26) (not (wumpus p26)))
       (invariant (wumpus p27) (not (wumpus p27)))
       (invariant (wumpus p28) (not (wumpus p28)))
       (invariant (wumpus p31) (not (wumpus p31)))
       (invariant (wumpus p33) (not (wumpus p33)))
       (invariant (wumpus p38) (not (wumpus p38)))
       (invariant (wumpus p41) (not (wumpus p41)))
       (invariant (wumpus p43) (not (wumpus p43)))
       (invariant (wumpus p44) (not (wumpus p44)))
       (invariant (wumpus p45) (not (wumpus p45)))
       (invariant (wumpus p46) (not (wumpus p46)))
       (invariant (wumpus p48) (not (wumpus p48)))
       (invariant (wumpus p51) (not (wumpus p51)))
       (invariant (wumpus p53) (not (wumpus p53)))
       (invariant (wumpus p54) (not (wumpus p54)))
       (invariant (wumpus p55) (not (wumpus p55)))
       (invariant (wumpus p56) (not (wumpus p56)))
       (invariant (wumpus p58) (not (wumpus p58)))
       (invariant (wumpus p61) (not (wumpus p61)))
       (invariant (wumpus p63) (not (wumpus p63)))
       (invariant (wumpus p64) (not (wumpus p64)))
       (invariant (wumpus p65) (not (wumpus p65)))
       (invariant (wumpus p66) (not (wumpus p66)))
       (invariant (wumpus p68) (not (wumpus p68)))
       (invariant (wumpus p71) (not (wumpus p71)))
       (invariant (wumpus p73) (not (wumpus p73)))
       (invariant (wumpus p74) (not (wumpus p74)))
       (invariant (wumpus p75) (not (wumpus p75)))
       (invariant (wumpus p76) (not (wumpus p76)))
       (invariant (wumpus p78) (not (wumpus p78)))
       (invariant (wumpus p81) (not (wumpus p81)))
       (invariant (wumpus p86) (not (wumpus p86)))
       (invariant (wumpus p88) (not (wumpus p88)))
       (invariant (wumpus p91) (not (wumpus p91)))
       (invariant (wumpus p92) (not (wumpus p92)))
       (invariant (wumpus p93) (not (wumpus p93)))
       (invariant (wumpus p94) (not (wumpus p94)))
       (invariant (wumpus p95) (not (wumpus p95)))
       (invariant (wumpus p96) (not (wumpus p96)))
       (invariant (wumpus p97) (not (wumpus p97)))
       (invariant (wumpus p98) (not (wumpus p98)))
       (invariant (wumpus p101) (not (wumpus p101)))
       (invariant (wumpus p102) (not (wumpus p102)))
       (invariant (wumpus p103) (not (wumpus p103)))
       (invariant (wumpus p104) (not (wumpus p104)))
       (invariant (wumpus p105) (not (wumpus p105)))
       (invariant (wumpus p106) (not (wumpus p106)))
       (invariant (wumpus p107) (not (wumpus p107)))
       (invariant (wumpus p108) (not (wumpus p108)))

       ; Invariants: (or stench(p) -stench(p))
       (invariant (stench p11) (not (stench p11)))
       (invariant (stench p12) (not (stench p12)))
       (invariant (stench p13) (not (stench p13)))
       (invariant (stench p14) (not (stench p14)))
       (invariant (stench p15) (not (stench p15)))
       (invariant (stench p16) (not (stench p16)))
       (invariant (stench p17) (not (stench p17)))
       (invariant (stench p18) (not (stench p18)))
       (invariant (stench p21) (not (stench p21)))
       (invariant (stench p22) (not (stench p22)))
       (invariant (stench p23) (not (stench p23)))
       (invariant (stench p24) (not (stench p24)))
       (invariant (stench p25) (not (stench p25)))
       (invariant (stench p26) (not (stench p26)))
       (invariant (stench p27) (not (stench p27)))
       (invariant (stench p28) (not (stench p28)))
       (invariant (stench p31) (not (stench p31)))
       (invariant (stench p33) (not (stench p33)))
       (invariant (stench p38) (not (stench p38)))
       (invariant (stench p41) (not (stench p41)))
       (invariant (stench p43) (not (stench p43)))
       (invariant (stench p44) (not (stench p44)))
       (invariant (stench p45) (not (stench p45)))
       (invariant (stench p46) (not (stench p46)))
       (invariant (stench p48) (not (stench p48)))
       (invariant (stench p51) (not (stench p51)))
       (invariant (stench p53) (not (stench p53)))
       (invariant (stench p54) (not (stench p54)))
       (invariant (stench p55) (not (stench p55)))
       (invariant (stench p56) (not (stench p56)))
       (invariant (stench p58) (not (stench p58)))
       (invariant (stench p61) (not (stench p61)))
       (invariant (stench p63) (not (stench p63)))
       (invariant (stench p64) (not (stench p64)))
       (invariant (stench p65) (not (stench p65)))
       (invariant (stench p66) (not (stench p66)))
       (invariant (stench p68) (not (stench p68)))
       (invariant (stench p71) (not (stench p71)))
       (invariant (stench p73) (not (stench p73)))
       (invariant (stench p74) (not (stench p74)))
       (invariant (stench p75) (not (stench p75)))
       (invariant (stench p76) (not (stench p76)))
       (invariant (stench p78) (not (stench p78)))
       (invariant (stench p81) (not (stench p81)))
       (invariant (stench p86) (not (stench p86)))
       (invariant (stench p88) (not (stench p88)))
       (invariant (stench p91) (not (stench p91)))
       (invariant (stench p92) (not (stench p92)))
       (invariant (stench p93) (not (stench p93)))
       (invariant (stench p94) (not (stench p94)))
       (invariant (stench p95) (not (stench p95)))
       (invariant (stench p96) (not (stench p96)))
       (invariant (stench p97) (not (stench p97)))
       (invariant (stench p98) (not (stench p98)))
       (invariant (stench p101) (not (stench p101)))
       (invariant (stench p102) (not (stench p102)))
       (invariant (stench p103) (not (stench p103)))
       (invariant (stench p104) (not (stench p104)))
       (invariant (stench p105) (not (stench p105)))
       (invariant (stench p106) (not (stench p106)))
       (invariant (stench p107) (not (stench p107)))
       (invariant (stench p108) (not (stench p108)))

       ; Invariants: (or stench(p) -wumpus(p'))
       (invariant (stench p11) (not (wumpus p12)))
       (invariant (stench p11) (not (wumpus p21)))
       (invariant (stench p12) (not (wumpus p13)))
       (invariant (stench p12) (not (wumpus p22)))
       (invariant (stench p12) (not (wumpus p11)))
       (invariant (stench p13) (not (wumpus p14)))
       (invariant (stench p13) (not (wumpus p23)))
       (invariant (stench p13) (not (wumpus p12)))
       (invariant (stench p14) (not (wumpus p15)))
       (invariant (stench p14) (not (wumpus p24)))
       (invariant (stench p14) (not (wumpus p13)))
       (invariant (stench p15) (not (wumpus p16)))
       (invariant (stench p15) (not (wumpus p25)))
       (invariant (stench p15) (not (wumpus p14)))
       (invariant (stench p16) (not (wumpus p17)))
       (invariant (stench p16) (not (wumpus p26)))
       (invariant (stench p16) (not (wumpus p15)))
       (invariant (stench p17) (not (wumpus p18)))
       (invariant (stench p17) (not (wumpus p27)))
       (invariant (stench p17) (not (wumpus p16)))
       (invariant (stench p18) (not (wumpus p28)))
       (invariant (stench p18) (not (wumpus p17)))
       (invariant (stench p21) (not (wumpus p22)))
       (invariant (stench p21) (not (wumpus p31)))
       (invariant (stench p21) (not (wumpus p11)))
       (invariant (stench p22) (not (wumpus p23)))
       (invariant (stench p22) (not (wumpus p21)))
       (invariant (stench p22) (not (wumpus p12)))
       (invariant (stench p23) (not (wumpus p24)))
       (invariant (stench p23) (not (wumpus p33)))
       (invariant (stench p23) (not (wumpus p22)))
       (invariant (stench p23) (not (wumpus p13)))
       (invariant (stench p24) (not (wumpus p25)))
       (invariant (stench p24) (not (wumpus p23)))
       (invariant (stench p24) (not (wumpus p14)))
       (invariant (stench p25) (not (wumpus p26)))
       (invariant (stench p25) (not (wumpus p24)))
       (invariant (stench p25) (not (wumpus p15)))
       (invariant (stench p26) (not (wumpus p27)))
       (invariant (stench p26) (not (wumpus p25)))
       (invariant (stench p26) (not (wumpus p16)))
       (invariant (stench p27) (not (wumpus p28)))
       (invariant (stench p27) (not (wumpus p26)))
       (invariant (stench p27) (not (wumpus p17)))
       (invariant (stench p28) (not (wumpus p38)))
       (invariant (stench p28) (not (wumpus p27)))
       (invariant (stench p28) (not (wumpus p18)))
       (invariant (stench p31) (not (wumpus p41)))
       (invariant (stench p31) (not (wumpus p21)))
       (invariant (stench p33) (not (wumpus p43)))
       (invariant (stench p33) (not (wumpus p23)))
       (invariant (stench p38) (not (wumpus p48)))
       (invariant (stench p38) (not (wumpus p28)))
       (invariant (stench p41) (not (wumpus p51)))
       (invariant (stench p41) (not (wumpus p31)))
       (invariant (stench p43) (not (wumpus p44)))
       (invariant (stench p43) (not (wumpus p53)))
       (invariant (stench p43) (not (wumpus p33)))
       (invariant (stench p44) (not (wumpus p45)))
       (invariant (stench p44) (not (wumpus p54)))
       (invariant (stench p44) (not (wumpus p43)))
       (invariant (stench p45) (not (wumpus p46)))
       (invariant (stench p45) (not (wumpus p55)))
       (invariant (stench p45) (not (wumpus p44)))
       (invariant (stench p46) (not (wumpus p56)))
       (invariant (stench p46) (not (wumpus p45)))
       (invariant (stench p48) (not (wumpus p58)))
       (invariant (stench p48) (not (wumpus p38)))
       (invariant (stench p51) (not (wumpus p61)))
       (invariant (stench p51) (not (wumpus p41)))
       (invariant (stench p53) (not (wumpus p54)))
       (invariant (stench p53) (not (wumpus p63)))
       (invariant (stench p53) (not (wumpus p43)))
       (invariant (stench p54) (not (wumpus p55)))
       (invariant (stench p54) (not (wumpus p64)))
       (invariant (stench p54) (not (wumpus p53)))
       (invariant (stench p54) (not (wumpus p44)))
       (invariant (stench p55) (not (wumpus p56)))
       (invariant (stench p55) (not (wumpus p65)))
       (invariant (stench p55) (not (wumpus p54)))
       (invariant (stench p55) (not (wumpus p45)))
       (invariant (stench p56) (not (wumpus p66)))
       (invariant (stench p56) (not (wumpus p55)))
       (invariant (stench p56) (not (wumpus p46)))
       (invariant (stench p58) (not (wumpus p68)))
       (invariant (stench p58) (not (wumpus p48)))
       (invariant (stench p61) (not (wumpus p71)))
       (invariant (stench p61) (not (wumpus p51)))
       (invariant (stench p63) (not (wumpus p64)))
       (invariant (stench p63) (not (wumpus p73)))
       (invariant (stench p63) (not (wumpus p53)))
       (invariant (stench p64) (not (wumpus p65)))
       (invariant (stench p64) (not (wumpus p74)))
       (invariant (stench p64) (not (wumpus p63)))
       (invariant (stench p64) (not (wumpus p54)))
       (invariant (stench p65) (not (wumpus p66)))
       (invariant (stench p65) (not (wumpus p75)))
       (invariant (stench p65) (not (wumpus p64)))
       (invariant (stench p65) (not (wumpus p55)))
       (invariant (stench p66) (not (wumpus p76)))
       (invariant (stench p66) (not (wumpus p65)))
       (invariant (stench p66) (not (wumpus p56)))
       (invariant (stench p68) (not (wumpus p78)))
       (invariant (stench p68) (not (wumpus p58)))
       (invariant (stench p71) (not (wumpus p81)))
       (invariant (stench p71) (not (wumpus p61)))
       (invariant (stench p73) (not (wumpus p74)))
       (invariant (stench p73) (not (wumpus p63)))
       (invariant (stench p74) (not (wumpus p75)))
       (invariant (stench p74) (not (wumpus p73)))
       (invariant (stench p74) (not (wumpus p64)))
       (invariant (stench p75) (not (wumpus p76)))
       (invariant (stench p75) (not (wumpus p74)))
       (invariant (stench p75) (not (wumpus p65)))
       (invariant (stench p76) (not (wumpus p86)))
       (invariant (stench p76) (not (wumpus p75)))
       (invariant (stench p76) (not (wumpus p66)))
       (invariant (stench p78) (not (wumpus p88)))
       (invariant (stench p78) (not (wumpus p68)))
       (invariant (stench p81) (not (wumpus p91)))
       (invariant (stench p81) (not (wumpus p71)))
       (invariant (stench p86) (not (wumpus p96)))
       (invariant (stench p86) (not (wumpus p76)))
       (invariant (stench p88) (not (wumpus p98)))
       (invariant (stench p88) (not (wumpus p78)))
       (invariant (stench p91) (not (wumpus p92)))
       (invariant (stench p91) (not (wumpus p101)))
       (invariant (stench p91) (not (wumpus p81)))
       (invariant (stench p92) (not (wumpus p93)))
       (invariant (stench p92) (not (wumpus p102)))
       (invariant (stench p92) (not (wumpus p91)))
       (invariant (stench p93) (not (wumpus p94)))
       (invariant (stench p93) (not (wumpus p103)))
       (invariant (stench p93) (not (wumpus p92)))
       (invariant (stench p94) (not (wumpus p95)))
       (invariant (stench p94) (not (wumpus p104)))
       (invariant (stench p94) (not (wumpus p93)))
       (invariant (stench p95) (not (wumpus p96)))
       (invariant (stench p95) (not (wumpus p105)))
       (invariant (stench p95) (not (wumpus p94)))
       (invariant (stench p96) (not (wumpus p97)))
       (invariant (stench p96) (not (wumpus p106)))
       (invariant (stench p96) (not (wumpus p95)))
       (invariant (stench p96) (not (wumpus p86)))
       (invariant (stench p97) (not (wumpus p98)))
       (invariant (stench p97) (not (wumpus p107)))
       (invariant (stench p97) (not (wumpus p96)))
       (invariant (stench p98) (not (wumpus p108)))
       (invariant (stench p98) (not (wumpus p97)))
       (invariant (stench p98) (not (wumpus p88)))
       (invariant (stench p101) (not (wumpus p102)))
       (invariant (stench p101) (not (wumpus p91)))
       (invariant (stench p102) (not (wumpus p103)))
       (invariant (stench p102) (not (wumpus p101)))
       (invariant (stench p102) (not (wumpus p92)))
       (invariant (stench p103) (not (wumpus p104)))
       (invariant (stench p103) (not (wumpus p102)))
       (invariant (stench p103) (not (wumpus p93)))
       (invariant (stench p104) (not (wumpus p105)))
       (invariant (stench p104) (not (wumpus p103)))
       (invariant (stench p104) (not (wumpus p94)))
       (invariant (stench p105) (not (wumpus p106)))
       (invariant (stench p105) (not (wumpus p104)))
       (invariant (stench p105) (not (wumpus p95)))
       (invariant (stench p106) (not (wumpus p107)))
       (invariant (stench p106) (not (wumpus p105)))
       (invariant (stench p106) (not (wumpus p96)))
       (invariant (stench p107) (not (wumpus p108)))
       (invariant (stench p107) (not (wumpus p106)))
       (invariant (stench p107) (not (wumpus p97)))
       (invariant (stench p108) (not (wumpus p107)))
       (invariant (stench p108) (not (wumpus p98)))
    )
    (:hidden
       (wumpus p12) (stench p13) (stench p22) (stench p11)
       (wumpus p18) (stench p28) (stench p17)
       (wumpus p21) (stench p22) (stench p31) (stench p11)
       (wumpus p31) (stench p41) (stench p21)
       (wumpus p46) (stench p56) (stench p45)
       (wumpus p48) (stench p58) (stench p38)
       (wumpus p54) (stench p55) (stench p64) (stench p53) (stench p44)
       (wumpus p65) (stench p66) (stench p75) (stench p64) (stench p55)
       (wumpus p71) (stench p81) (stench p61)
       (wumpus p76) (stench p86) (stench p75) (stench p66)
    )
    (:goal (at p15))
)
