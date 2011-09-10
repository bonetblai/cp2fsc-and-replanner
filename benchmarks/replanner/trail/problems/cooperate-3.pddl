;; dim=(25,9)
;; init=(9,4)
;; goal=(18,7)
;; @@@@@@@@@@@@@@@@@@@@@@@@@
;; @...........ssssssG.....@
;; @..@@@@@@@@@s@@@@@@@@@..@
;; @..@@@@@@@@@s@@@@@@@@@..@
;; @........Isss...........@
;; @..@@@@@@@@@.@@@@@@@@@..@
;; @..@@@@@@@@@.@@@@@@@@@..@
;; @.......................@
;; @@@@@@@@@@@@@@@@@@@@@@@@@

(define (problem cooperate)
    (:domain trail)
    (:objects p10 p11 p12 p13 p14 p15 p16 p19 p20 p21 p22 p23 p24 p25 p28 p31 p34 p37 p40 p43 p46 p49 p52 p55 p58 p61 p64 p67 p70 p73 p76 p79 p82 p85 p88 p91 p94 p97 p100 p103 p106 p109 p110 p111 p112 p113 p114 p115 p118 p121 p124 p127 p130 p133 p136 p139 p142 p145 p148 p151 p154 p157 p160 p163 p166 p169 p172 p175 p178 p181 p184 p187 p190 p193 p196 p199 p200 p201 p202 p203 p204 p205 p208 p209 p210 p211 p212 p213 p214 - pos)
    (:init
       (adj p10 p11)
       (adj p10 p19)
       (adj p11 p12)
       (adj p11 p20)
       (adj p11 p10)
       (adj p12 p13)
       (adj p12 p21)
       (adj p12 p11)
       (adj p13 p14)
       (adj p13 p22)
       (adj p13 p12)
       (adj p14 p15)
       (adj p14 p23)
       (adj p14 p13)
       (adj p15 p16)
       (adj p15 p24)
       (adj p15 p14)
       (adj p16 p25)
       (adj p16 p15)
       (adj p19 p20)
       (adj p19 p28)
       (adj p19 p10)
       (adj p20 p21)
       (adj p20 p19)
       (adj p20 p11)
       (adj p21 p22)
       (adj p21 p20)
       (adj p21 p12)
       (adj p22 p23)
       (adj p22 p31)
       (adj p22 p21)
       (adj p22 p13)
       (adj p23 p24)
       (adj p23 p22)
       (adj p23 p14)
       (adj p24 p25)
       (adj p24 p23)
       (adj p24 p15)
       (adj p25 p34)
       (adj p25 p24)
       (adj p25 p16)
       (adj p28 p37)
       (adj p28 p19)
       (adj p31 p40)
       (adj p31 p22)
       (adj p34 p43)
       (adj p34 p25)
       (adj p37 p46)
       (adj p37 p28)
       (adj p40 p49)
       (adj p40 p31)
       (adj p43 p52)
       (adj p43 p34)
       (adj p46 p55)
       (adj p46 p37)
       (adj p49 p58)
       (adj p49 p40)
       (adj p52 p61)
       (adj p52 p43)
       (adj p55 p64)
       (adj p55 p46)
       (adj p58 p67)
       (adj p58 p49)
       (adj p61 p70)
       (adj p61 p52)
       (adj p64 p73)
       (adj p64 p55)
       (adj p67 p76)
       (adj p67 p58)
       (adj p70 p79)
       (adj p70 p61)
       (adj p73 p82)
       (adj p73 p64)
       (adj p76 p85)
       (adj p76 p67)
       (adj p79 p88)
       (adj p79 p70)
       (adj p82 p91)
       (adj p82 p73)
       (adj p85 p94)
       (adj p85 p76)
       (adj p88 p97)
       (adj p88 p79)
       (adj p91 p100)
       (adj p91 p82)
       (adj p94 p103)
       (adj p94 p85)
       (adj p97 p106)
       (adj p97 p88)
       (adj p100 p109)
       (adj p100 p91)
       (adj p103 p112)
       (adj p103 p94)
       (adj p106 p115)
       (adj p106 p97)
       (adj p109 p110)
       (adj p109 p118)
       (adj p109 p100)
       (adj p110 p111)
       (adj p110 p109)
       (adj p111 p112)
       (adj p111 p110)
       (adj p112 p113)
       (adj p112 p121)
       (adj p112 p111)
       (adj p112 p103)
       (adj p113 p114)
       (adj p113 p112)
       (adj p114 p115)
       (adj p114 p113)
       (adj p115 p124)
       (adj p115 p114)
       (adj p115 p106)
       (adj p118 p127)
       (adj p118 p109)
       (adj p121 p130)
       (adj p121 p112)
       (adj p124 p133)
       (adj p124 p115)
       (adj p127 p136)
       (adj p127 p118)
       (adj p130 p139)
       (adj p130 p121)
       (adj p133 p142)
       (adj p133 p124)
       (adj p136 p145)
       (adj p136 p127)
       (adj p139 p148)
       (adj p139 p130)
       (adj p142 p151)
       (adj p142 p133)
       (adj p145 p154)
       (adj p145 p136)
       (adj p148 p157)
       (adj p148 p139)
       (adj p151 p160)
       (adj p151 p142)
       (adj p154 p163)
       (adj p154 p145)
       (adj p157 p166)
       (adj p157 p148)
       (adj p160 p169)
       (adj p160 p151)
       (adj p163 p172)
       (adj p163 p154)
       (adj p166 p175)
       (adj p166 p157)
       (adj p169 p178)
       (adj p169 p160)
       (adj p172 p181)
       (adj p172 p163)
       (adj p175 p184)
       (adj p175 p166)
       (adj p178 p187)
       (adj p178 p169)
       (adj p181 p190)
       (adj p181 p172)
       (adj p184 p193)
       (adj p184 p175)
       (adj p187 p196)
       (adj p187 p178)
       (adj p190 p199)
       (adj p190 p181)
       (adj p193 p202)
       (adj p193 p184)
       (adj p196 p205)
       (adj p196 p187)
       (adj p199 p200)
       (adj p199 p208)
       (adj p199 p190)
       (adj p200 p201)
       (adj p200 p209)
       (adj p200 p199)
       (adj p201 p202)
       (adj p201 p210)
       (adj p201 p200)
       (adj p202 p203)
       (adj p202 p211)
       (adj p202 p201)
       (adj p202 p193)
       (adj p203 p204)
       (adj p203 p212)
       (adj p203 p202)
       (adj p204 p205)
       (adj p204 p213)
       (adj p204 p203)
       (adj p205 p214)
       (adj p205 p204)
       (adj p205 p196)
       (adj p208 p209)
       (adj p208 p199)
       (adj p209 p210)
       (adj p209 p208)
       (adj p209 p200)
       (adj p210 p211)
       (adj p210 p209)
       (adj p210 p201)
       (adj p211 p212)
       (adj p211 p210)
       (adj p211 p202)
       (adj p212 p213)
       (adj p212 p211)
       (adj p212 p203)
       (adj p213 p214)
       (adj p213 p212)
       (adj p213 p204)
       (adj p214 p213)
       (adj p214 p205)

       (at p85)
       (invariant (stone p10) (not (stone p10)))
       (invariant (final-stone p10) (not (final-stone p10)))
       (invariant (stone p11) (not (stone p11)))
       (invariant (final-stone p11) (not (final-stone p11)))
       (invariant (stone p12) (not (stone p12)))
       (invariant (final-stone p12) (not (final-stone p12)))
       (invariant (stone p13) (not (stone p13)))
       (invariant (final-stone p13) (not (final-stone p13)))
       (invariant (stone p14) (not (stone p14)))
       (invariant (final-stone p14) (not (final-stone p14)))
       (invariant (stone p15) (not (stone p15)))
       (invariant (final-stone p15) (not (final-stone p15)))
       (invariant (stone p16) (not (stone p16)))
       (invariant (final-stone p16) (not (final-stone p16)))
       (invariant (stone p19) (not (stone p19)))
       (invariant (final-stone p19) (not (final-stone p19)))
       (invariant (stone p20) (not (stone p20)))
       (invariant (final-stone p20) (not (final-stone p20)))
       (invariant (stone p21) (not (stone p21)))
       (invariant (final-stone p21) (not (final-stone p21)))
       (invariant (stone p22) (not (stone p22)))
       (invariant (final-stone p22) (not (final-stone p22)))
       (invariant (stone p23) (not (stone p23)))
       (invariant (final-stone p23) (not (final-stone p23)))
       (invariant (stone p24) (not (stone p24)))
       (invariant (final-stone p24) (not (final-stone p24)))
       (invariant (stone p25) (not (stone p25)))
       (invariant (final-stone p25) (not (final-stone p25)))
       (invariant (stone p28) (not (stone p28)))
       (invariant (final-stone p28) (not (final-stone p28)))
       (invariant (stone p31) (not (stone p31)))
       (invariant (final-stone p31) (not (final-stone p31)))
       (invariant (stone p34) (not (stone p34)))
       (invariant (final-stone p34) (not (final-stone p34)))
       (invariant (stone p37) (not (stone p37)))
       (invariant (final-stone p37) (not (final-stone p37)))
       (invariant (stone p40) (not (stone p40)))
       (invariant (final-stone p40) (not (final-stone p40)))
       (invariant (stone p43) (not (stone p43)))
       (invariant (final-stone p43) (not (final-stone p43)))
       (invariant (stone p46) (not (stone p46)))
       (invariant (final-stone p46) (not (final-stone p46)))
       (invariant (stone p49) (not (stone p49)))
       (invariant (final-stone p49) (not (final-stone p49)))
       (invariant (stone p52) (not (stone p52)))
       (invariant (final-stone p52) (not (final-stone p52)))
       (invariant (stone p55) (not (stone p55)))
       (invariant (final-stone p55) (not (final-stone p55)))
       (invariant (stone p58) (not (stone p58)))
       (invariant (final-stone p58) (not (final-stone p58)))
       (invariant (stone p61) (not (stone p61)))
       (invariant (final-stone p61) (not (final-stone p61)))
       (invariant (stone p64) (not (stone p64)))
       (invariant (final-stone p64) (not (final-stone p64)))
       (invariant (stone p67) (not (stone p67)))
       (invariant (final-stone p67) (not (final-stone p67)))
       (invariant (stone p70) (not (stone p70)))
       (invariant (final-stone p70) (not (final-stone p70)))
       (invariant (stone p73) (not (stone p73)))
       (invariant (final-stone p73) (not (final-stone p73)))
       (invariant (stone p76) (not (stone p76)))
       (invariant (final-stone p76) (not (final-stone p76)))
       (invariant (stone p79) (not (stone p79)))
       (invariant (final-stone p79) (not (final-stone p79)))
       (invariant (stone p82) (not (stone p82)))
       (invariant (final-stone p82) (not (final-stone p82)))
       (invariant (stone p85) (not (stone p85)))
       (invariant (final-stone p85) (not (final-stone p85)))
       (invariant (stone p88) (not (stone p88)))
       (invariant (final-stone p88) (not (final-stone p88)))
       (invariant (stone p91) (not (stone p91)))
       (invariant (final-stone p91) (not (final-stone p91)))
       (invariant (stone p94) (not (stone p94)))
       (invariant (final-stone p94) (not (final-stone p94)))
       (invariant (stone p97) (not (stone p97)))
       (invariant (final-stone p97) (not (final-stone p97)))
       (invariant (stone p100) (not (stone p100)))
       (invariant (final-stone p100) (not (final-stone p100)))
       (invariant (stone p103) (not (stone p103)))
       (invariant (final-stone p103) (not (final-stone p103)))
       (invariant (stone p106) (not (stone p106)))
       (invariant (final-stone p106) (not (final-stone p106)))
       (invariant (stone p109) (not (stone p109)))
       (invariant (final-stone p109) (not (final-stone p109)))
       (invariant (stone p110) (not (stone p110)))
       (invariant (final-stone p110) (not (final-stone p110)))
       (invariant (stone p111) (not (stone p111)))
       (invariant (final-stone p111) (not (final-stone p111)))
       (invariant (stone p112) (not (stone p112)))
       (invariant (final-stone p112) (not (final-stone p112)))
       (invariant (stone p113) (not (stone p113)))
       (invariant (final-stone p113) (not (final-stone p113)))
       (invariant (stone p114) (not (stone p114)))
       (invariant (final-stone p114) (not (final-stone p114)))
       (invariant (stone p115) (not (stone p115)))
       (invariant (final-stone p115) (not (final-stone p115)))
       (invariant (stone p118) (not (stone p118)))
       (invariant (final-stone p118) (not (final-stone p118)))
       (invariant (stone p121) (not (stone p121)))
       (invariant (final-stone p121) (not (final-stone p121)))
       (invariant (stone p124) (not (stone p124)))
       (invariant (final-stone p124) (not (final-stone p124)))
       (invariant (stone p127) (not (stone p127)))
       (invariant (final-stone p127) (not (final-stone p127)))
       (invariant (stone p130) (not (stone p130)))
       (invariant (final-stone p130) (not (final-stone p130)))
       (invariant (stone p133) (not (stone p133)))
       (invariant (final-stone p133) (not (final-stone p133)))
       (invariant (stone p136) (not (stone p136)))
       (invariant (final-stone p136) (not (final-stone p136)))
       (invariant (stone p139) (not (stone p139)))
       (invariant (final-stone p139) (not (final-stone p139)))
       (invariant (stone p142) (not (stone p142)))
       (invariant (final-stone p142) (not (final-stone p142)))
       (invariant (stone p145) (not (stone p145)))
       (invariant (final-stone p145) (not (final-stone p145)))
       (invariant (stone p148) (not (stone p148)))
       (invariant (final-stone p148) (not (final-stone p148)))
       (invariant (stone p151) (not (stone p151)))
       (invariant (final-stone p151) (not (final-stone p151)))
       (invariant (stone p154) (not (stone p154)))
       (invariant (final-stone p154) (not (final-stone p154)))
       (invariant (stone p157) (not (stone p157)))
       (invariant (final-stone p157) (not (final-stone p157)))
       (invariant (stone p160) (not (stone p160)))
       (invariant (final-stone p160) (not (final-stone p160)))
       (invariant (stone p163) (not (stone p163)))
       (invariant (final-stone p163) (not (final-stone p163)))
       (invariant (stone p166) (not (stone p166)))
       (invariant (final-stone p166) (not (final-stone p166)))
       (invariant (stone p169) (not (stone p169)))
       (invariant (final-stone p169) (not (final-stone p169)))
       (invariant (stone p172) (not (stone p172)))
       (invariant (final-stone p172) (not (final-stone p172)))
       (invariant (stone p175) (not (stone p175)))
       (invariant (final-stone p175) (not (final-stone p175)))
       (invariant (stone p178) (not (stone p178)))
       (invariant (final-stone p178) (not (final-stone p178)))
       (invariant (stone p181) (not (stone p181)))
       (invariant (final-stone p181) (not (final-stone p181)))
       (invariant (stone p184) (not (stone p184)))
       (invariant (final-stone p184) (not (final-stone p184)))
       (invariant (stone p187) (not (stone p187)))
       (invariant (final-stone p187) (not (final-stone p187)))
       (invariant (stone p190) (not (stone p190)))
       (invariant (final-stone p190) (not (final-stone p190)))
       (invariant (stone p193) (not (stone p193)))
       (invariant (final-stone p193) (not (final-stone p193)))
       (invariant (stone p196) (not (stone p196)))
       (invariant (final-stone p196) (not (final-stone p196)))
       (invariant (stone p199) (not (stone p199)))
       (invariant (final-stone p199) (not (final-stone p199)))
       (invariant (stone p200) (not (stone p200)))
       (invariant (final-stone p200) (not (final-stone p200)))
       (invariant (stone p201) (not (stone p201)))
       (invariant (final-stone p201) (not (final-stone p201)))
       (invariant (stone p202) (not (stone p202)))
       (invariant (final-stone p202) (not (final-stone p202)))
       (invariant (stone p203) (not (stone p203)))
       (invariant (final-stone p203) (not (final-stone p203)))
       (invariant (stone p204) (not (stone p204)))
       (invariant (final-stone p204) (not (final-stone p204)))
       (invariant (stone p205) (not (stone p205)))
       (invariant (final-stone p205) (not (final-stone p205)))
       (invariant (stone p208) (not (stone p208)))
       (invariant (final-stone p208) (not (final-stone p208)))
       (invariant (stone p209) (not (stone p209)))
       (invariant (final-stone p209) (not (final-stone p209)))
       (invariant (stone p210) (not (stone p210)))
       (invariant (final-stone p210) (not (final-stone p210)))
       (invariant (stone p211) (not (stone p211)))
       (invariant (final-stone p211) (not (final-stone p211)))
       (invariant (stone p212) (not (stone p212)))
       (invariant (final-stone p212) (not (final-stone p212)))
       (invariant (stone p213) (not (stone p213)))
       (invariant (final-stone p213) (not (final-stone p213)))
       (invariant (stone p214) (not (stone p214)))
       (invariant (final-stone p214) (not (final-stone p214)))
    )
    (:hidden
       (stone p85)
       (stone p94)
       (stone p103)
       (stone p112)
       (stone p113)
       (stone p114)
       (stone p115)
       (stone p124)
       (stone p133)
       (stone p142)
       (stone p151)
       (stone p160)
       (stone p169)
       (final-stone p169)
    )
    (:goal (done))
)