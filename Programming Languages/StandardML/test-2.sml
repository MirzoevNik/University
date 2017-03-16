(* Задание 1. getNth *)
val testGetNth1 = getNth ([0, 1, 2, 3, 4], 2) = 2
val testGetNth2 = getNth (["0", "1", "2", "3", "4"], 2) = "2"
val testGetNth3 = getNth ([0, 1, 2, 3, 4], 5) = 5
                        handle List.Empty => true
(* Задание 2. REVERSEAppend *)
val testReverseAppend1 = reverseAppend ([0, 1, 2, 3], [4, 5, 6]) 
                            = [3, 2, 1, 0, 4, 5, 6]
val testReverseAppend2 = reverseAppend ([0], [1]) 
                            = [0, 1]
val testReverseAppend3 = reverseAppend ([1, 2], []) 
                            = [2, 1]
val testReverseAppend4 = reverseAppend ([], [1, 2]) 
                            = [1, 2]

(* Задание 3. cardValue *)
val testCardValue1 = cardValue (RED, NUM 9) = 9
val testCardValue2 = cardValue (BLACK, WILD) = 50
val testCardValue3 = cardValue (BLACK, WILD_DRAW_FOUR) = 50
val testCardValue4 = cardValue (BLUE, SKIP) = 20

(* Задание 4. cardCount *)
val testCardCount1 = cardCount (RED, NUM 0) = 1
val testCardCount2 = cardCount (BLUE, NUM 2) = 2
val testCardCount3 = cardCount (BLACK, WILD) = 4
val testCardCount4 = cardCount (GREEN, DRAW_TWO) = 2

(* Задание 5. rankColors *)
val testRankColors1 = rankColors WILD = [BLACK]
val testRankColors2 = rankColors (NUM 5) = [RED, GREEN, BLUE, YELLOW]
val testRankColors3 = rankColors REVERSE = [RED, GREEN, BLUE, YELLOW]

(* Задание 6. sumCards *)
val testSumCards1 = sumCards [(BLACK, WILD), (RED, NUM 0)] = 50
val testSumCards2 = sumCards [(BLACK, WILD_DRAW_FOUR), (GREEN, SKIP)] = 70
val testSumCards3 = sumCards [(RED, NUM 5)] = 5
val testSumCards4 = sumCards [(RED, NUM 0)] = 0
val testSumCards5 = sumCards [] = 0

(* Задание 7. removeNth *)
val testRemoveNth1 = removeNth ([0, 1, 2, 3, 4], 2) = [0, 1, 3, 4]
val testRemoveNth2 = removeNth (["0", "1", "2", "3", "4"], 2) 
                     = ["0", "1", "3", "4"]
val testRemoveNth3 = removeNth ([0, 1, 2, 3, 4], 5) = []
                          handle List.Empty => true
val testRemoveNth4 = removeNth ([2], 0) = []
val testRemoveNth5 = removeNth ([1], ~1) = []
                          handle List.Empty => true

(* Задание 8. removeCard *)
val testRemoveCard1 = removeCard ([], (BLUE, NUM 2), List.Empty) = []
                            handle List.Empty => true
val testRemoveCard2 = 
    removeCard ([(BLUE, NUM 2)], (BLUE, NUM 2), List.Empty) = []
val testRemoveCard3 = 
    removeCard ([(BLUE, NUM 2), (GREEN, SKIP), (BLACK, WILD_DRAW_FOUR)], 
                 (GREEN, SKIP), List.Empty) = [(BLUE, NUM 2), (BLACK, WILD_DRAW_FOUR)]

(* Задание 9. insertElem *)
val testInsertElem1 = insertElem ([], 2, 0) = [2]
val testInsertElem2 = insertElem ([], 2, 1) = [2]
                            handle List.Empty => true
val testInsertElem3 = insertElem ([1], 2, 0) = [2, 1]
val testInsertElem4 = insertElem ([1, 3], 2, 1) = [1, 2, 3]
val testInsertElem5 = insertElem ([1], 2, 1) = [1, 2]
val testInsertElem6 = insertElem ([1], 2, ~1) = [1, 2]
                            handle List.Empty => true

(* Задание 10. interchange *)
val testInterchange1 = interchange ([0, 1, 2, 3], 1, 3) = [0, 3, 2, 1]
val testInterchange2 = interchange ([0, 1, 2, 3], 3, 1) = [0, 3, 2, 1]
val testInterchange3 = interchange ([0, 1, 2, 3], 2, 2) = [0, 1, 2, 3]

(* Задание 11. shuffleList *)
(* ТЕСТЫ НЕ ТРЕБУЮТСЯ *)

(* Задание 12. allRankColors *)
val testAllRankColors1 = allRankColors WILD = [(BLACK, WILD)]
val testAllRankColors2 = allRankColors REVERSE = [(RED, REVERSE), 
                                                  (GREEN, REVERSE), 
                                                  (BLUE, REVERSE),
                                                  (YELLOW, REVERSE)]

(* Задание 13. copyCardNTimes *)
val testCopyCardNTimes1 = 
      copyCardNTimes (RED, NUM 0) = [(RED, NUM 0)]
val testCopyCardNTimes2 = 
      copyCardNTimes (BLUE, NUM 2) = [(BLUE, NUM 2), (BLUE, NUM 2)]
val testCopyCardNTimes3 = 
      copyCardNTimes (BLACK, WILD) = [(BLACK, WILD), (BLACK, WILD), (BLACK, WILD), (BLACK, WILD)]

(* Задание 14. deck *)
val testDeck1 = List.length deck = 108

(* Задание 15. getSameRank *)
val testGetSameRank1 = 
      getSameRank (WILD, [(BLACK, WILD), (GREEN, NUM 0)]) = [(BLACK, WILD)]
val testGetSameRank2 = 
      getSameRank ((NUM 0), [(BLUE, NUM 0), (BLACK, WILD), (GREEN, NUM 0)]) = [(BLUE, NUM 0), (GREEN, NUM 0)]
val testGetSameRank3 =
      getSameRank (WILD, [(GREEN, SKIP)]) = []

(* Задание 16. getSameColor *)
val testGetSameColor1 = 
      getSameColor (BLACK, [(BLACK, WILD), (GREEN, NUM 0)]) = [(BLACK, WILD)]
val testGetSameColor2 = 
      getSameColor (BLACK, [(BLACK, WILD), (BLACK, WILD_DRAW_FOUR), (GREEN, NUM 0)]) = [(BLACK, WILD), (BLACK, WILD_DRAW_FOUR)]
val testGetSameColor3 =
      getSameColor (BLACK, [(GREEN, SKIP)]) = []

(* Задание 17. hasRank *)
val testHasRank1 = 
      hasRank (WILD, [(BLACK, WILD), (GREEN, NUM 0)]) = true
val testHasRank2 = 
      hasRank (NUM 5, [(BLACK, WILD), (GREEN, NUM 0)]) = false

(* Задание 18. hasColor *)
val testHasColor1 = 
      hasColor (BLACK, [(BLACK, WILD), (GREEN, NUM 0)]) = true
val testHasColor2 = 
      hasColor (RED, [(BLACK, WILD), (GREEN, NUM 0)]) = false

(* Задание 19. hasCard *)
val testHasCard1 = 
      hasCard ((BLACK, WILD), [(BLACK, WILD), (GREEN, NUM 0)]) = true
val testHasCard2 = 
      hasCard ((RED, NUM 5), [(BLACK, WILD), (GREEN, NUM 0)]) = false

(* Задание 20. countColor *)
val testCountColor1 = 
      countColor (BLACK, [(RED, NUM 5), (BLACK, WILD), (GREEN, NUM 0)]) = 1
val testCountColor2 = 
      countColor (BLUE, [(RED, NUM 5), (BLACK, WILD), (GREEN, NUM 0)]) = 0

(* Задание 21. maxColor *)
val testMaxColor1 = 
      maxColor [(GREEN, NUM 5), (BLACK, WILD), (GREEN, NUM 0)] = GREEN
val testMaxColor2 = maxColor [] = RED

(* Задание 22. deal *)
(* ТЕСТЫ НЕ ТРЕБУЮТСЯ *)

(* Вспомогательная функция для сравнения двух игроков 
 * в элементе типа player присутствует функция, а функции 
 * на равенство не сравниваются, поэтому сравнивать на равенство 
 * двух игроков напрямую нельзя,
 * нужно сравнивать только сравнимые элементы *)
fun isSamePlayer ( { name = n1, cards = cs1, ...} : player
                 , { name = n2, cards = cs2, ...} : player ) =
      n1 = n2 andalso cs1 = cs2

(* Вспомогательная функция для тестирования
 * выдает true, когда элемент a присутствует в списке l 
 * иначе выдает false *)
fun member (_, []) = false
  | member (a, c :: cs) = (a = c) orelse member (a, cs)


(* Задание 23. getPlayersFirst *)
val testGetPlayersFirst1 = 
  let 
    val tmp = getPlayersFirst { players = [ { name = "Anton"
                                            , cards = []
                                            , strat = falseStrategy 
                                            }
                                          , { name = "Andrew"
                                            , cards = []
                                            , strat = falseStrategy 
                                            }
                                          ]
                              , pile = []
                              , deck = []
                              , state = PROCEED
                              }
  in
    isSamePlayer (tmp, {name = "Anton", cards = [], strat = falseStrategy})
  end

(* Задание 24. getPileTop *)
val testGetPileTop1 = 
      getPileTop { players = []
                 , pile = [(BLACK, WILD), (RED, NUM 0)]
                 , deck = []
                 , state = PROCEED
                 }
      = (BLACK, WILD)

(* Задание 25. nextPlayer *)
val testNextPlayer1 = 
  let 
    val tmp = nextPlayer { players = [ { name = "Anton"
                                       , cards = []
                                       , strat = falseStrategy 
                                       }
                                     , { name = "Andrew"
                                       , cards = []
                                       , strat = falseStrategy 
                                       }
                                     ]
                         , pile = []
                         , deck = []
                         , state = PROCEED
                         }
    val tmp1 = getPlayersFirst tmp
  in
    isSamePlayer (tmp1, {name = "Andrew", cards = [], strat = falseStrategy})
  end

(* Задание 26. changeDirection *)
val testChangeDirection1 = 
  let 
    val tmp = changeDirection { players = [ { name = "Anton"
                                            , cards = []
                                            , strat = falseStrategy 
                                            }
                                          , { name = "Andrew"
                                            , cards = []
                                            , strat = falseStrategy 
                                            }
                                          , { name = "Alexey"
                                            , cards = []
                                            , strat = falseStrategy 
                                            }
                                          ]
                              , pile = []
                              , deck = []
                              , state = PROCEED
                              }
    val tmp1 = nextPlayer tmp
    val tmp1player = getPlayersFirst tmp1
    val tmp2 = nextPlayer tmp1
    val tmp2player = getPlayersFirst tmp2
  in
    isSamePlayer ( tmp1player
                 , {name = "Alexey", cards = [], strat = falseStrategy} )
    andalso
    isSamePlayer ( tmp2player
                 , {name = "Andrew", cards = [], strat = falseStrategy})
  end

(* Задание 27. start *)
(* ДЛЯ СЛУЧАЯ, когда первая карта в колоде pile 
 * - черная карта, ТЕСТЫ НЕ ТРЕБУЮТСЯ *)
val testStart1 =
  let 
    val tmp = start { players = [ { name = "Anton"
                                  , cards = []
                                  , strat = falseStrategy 
                                  }
                                , { name = "Andrew"
                                  , cards = []
                                  , strat = falseStrategy 
                                  }
                                , { name = "Alexey"
                                  , cards = []
                                  , strat = falseStrategy 
                                  }
                                ]
                    , pile = [(RED, REVERSE)]
                    , deck = []
                    , state = PROCEED
                    }
    val tmp1 = nextPlayer tmp
    val tmp1player = getPlayersFirst tmp1
    val tmp2 = nextPlayer tmp1
    val tmp2player = getPlayersFirst tmp2
  in
    isSamePlayer ( tmp1player
                 , {name = "Alexey", cards = [], strat = falseStrategy} )
    andalso
    isSamePlayer ( tmp2player
                 , {name = "Andrew", cards = [], strat = falseStrategy})
  end

(* Задание 28. take1 *)
val testTake11 =
  let 
    val tmp = take_1 { players = [ { name = "Anton"
                                   , cards = []
                                   , strat = falseStrategy 
                                   }
                                 , { name = "Andrew"
                                   , cards = []
                                   , strat = falseStrategy 
                                   }
                                 , { name = "Alexey"
                                   , cards = []
                                   , strat = falseStrategy 
                                   }
                                 ]
                     , pile = [(RED, REVERSE)]
                     , deck = [(BLACK, WILD)]
                     , state = PROCEED
                     }
    val tmpplayer = getPlayersFirst tmp
    val tmpdeck = getDeskDeck tmp
  in
    isSamePlayer ( tmpplayer
                 , { name = "Anton"
                   , cards = [(BLACK, WILD)]
                   , strat = falseStrategy } )
    andalso null tmpdeck
  end

(* Задание 29. take2 *)
val testTake21 =
  let 
    val tmp = take_2 { players = [ { name = "Anton"
                                   , cards = []
                                   , strat = falseStrategy 
                                   }
                                 , { name = "Andrew"
                                   , cards = []
                                   , strat = falseStrategy 
                                   }
                                 , { name = "Alexey"
                                   , cards = []
                                   , strat = falseStrategy 
                                   }
                                 ]
                     , pile = [(RED, REVERSE)]
                     , deck = [(BLACK, WILD), (RED, NUM 5), (GREEN, DRAW_TWO)]
                     , state = PROCEED
                     }
    val tmpplayer = getPlayersFirst tmp
    val tmpdeck = getDeskDeck tmp    
  in
    isSamePlayer ( tmpplayer
                  , { name = "Anton"
                    , cards = [(RED, NUM 5), (BLACK, WILD)]
                    , strat = falseStrategy } )
    andalso tmpdeck = [(GREEN, DRAW_TWO)]
  end

(* Задание 30. take4 *)
val testTake41 =
  let 
    val tmp = take_4 { players = [ { name = "Anton"
                                   , cards = []
                                   , strat = falseStrategy 
                                   }
                                 , { name = "Andrew"
                                   , cards = []
                                   , strat = falseStrategy 
                                   }
                                 , { name = "Alexey"
                                   , cards = []
                                   , strat = falseStrategy 
                                   }
                                 ]
                     , pile = [(RED, REVERSE)]
                     , deck = [ (BLACK, WILD), (RED, NUM 5), (GREEN, DRAW_TWO)
                              , (RED, NUM 7), (BLUE, SKIP) ]
                     , state = PROCEED
                     }
    val tmpplayer = getPlayersFirst tmp
    val tmpdeck = getDeskDeck tmp    
  in
    isSamePlayer ( tmpplayer
                 , { name = "Anton"
                   , cards = [ (RED, NUM 7), (GREEN, DRAW_TWO), (RED, NUM 5)
                             , (BLACK, WILD)]
                   , strat = falseStrategy } )
    andalso tmpdeck = [(BLUE, SKIP)]
  end

(* Задание 31. pass *)
val testPass1 =
  let 
    val tmp = pass { players = [ { name = "Anton"
                                 , cards = []
                                 , strat = falseStrategy 
                                 }
                               , { name = "Andrew"
                                 , cards = []
                                 , strat = falseStrategy 
                                 }
                               , { name = "Alexey"
                                 , cards = []
                                 , strat = falseStrategy 
                                 }
                               ]
                   , pile = [(RED, REVERSE)]
                   , deck = []
                   , state = PROCEED
                   }
    val tmpplayer = getPlayersFirst tmp
    val tmp1 = nextPlayer tmp
    val tmp1player = getPlayersFirst tmp1
    val tmp2 = nextPlayer tmp1
    val tmp2player = getPlayersFirst tmp2
  in
    isSamePlayer ( tmpplayer
                 , {name = "Andrew", cards = [], strat = falseStrategy} )
    andalso
    isSamePlayer ( tmp1player
                 , {name = "Alexey", cards = [], strat = falseStrategy})
    andalso
    isSamePlayer ( tmp2player
                 , {name = "Anton", cards = [], strat = falseStrategy})    
  end

(* Задание 32. requiREDColor *)
val testRequiredColor1 = requiredColor { players = []
                                       , pile = [(RED, REVERSE)]
                                       , deck = []
                                       , state = PROCEED
                                       }
                         = RED
val testRequiredColor2 = requiredColor { players = []
                                       , pile = [(RED, REVERSE)]
                                       , deck = []
                                       , state = GIVE GREEN
                                       }
                         = GREEN

(* Задание 33. playableCards *)
val testPlayableCards1 =
  let 
    val tmp = playableCards { players = [ { name = "Anton"
                                          , cards = [ (BLACK, WILD)
                                                    , (RED, NUM 5)
                                                    , (GREEN, DRAW_TWO)
                                                    , (RED, NUM 7)
                                                    , (BLUE, SKIP) ]
                                          , strat = falseStrategy 
                                          }
                                        ]
                            , pile = [(RED, REVERSE)]
                            , deck = []
                            , state = PROCEED
                            }
  in
    member ((BLACK, WILD), tmp)
    andalso member ((RED, NUM 5), tmp)
    andalso member ((RED, NUM 7), tmp)
    andalso length tmp = 3
  end


(* Задание 34. countCards *)
val testCountCards1 =
  countCards { players = [ { name = "Anton"
                           , cards = []
                           , strat = falseStrategy 
                           }
                         , { name = "Andrew"
                           , cards = [ (BLACK, WILD)
                                     , (RED, NUM 5)
                                     , (GREEN, DRAW_TWO)
                                     , (RED, NUM 7)
                                     , (BLUE, SKIP) ]
                           , strat = falseStrategy 
                           }
                         , { name = "Alexey"
                           , cards = [ (BLACK, WILD)
                                     , (RED, NUM 5) ]
                           , strat = falseStrategy 
                           }
                         ]
             , pile = []
             , deck = []
             , state = PROCEED
             }
  = [0, 5, 2]

(* Задание 35. hasNoCards *)
val testHasNoCards1 =
  hasNoCards {name = "Anton", cards = [], strat = falseStrategy} = true
val testHasNoCards2 = hasNoCards { name = "Alexey"
                                 , cards = [ (BLACK, WILD)
                                           , (RED, NUM 5) ]
                                 , strat = falseStrategy 
                                 } = false

(* Задание 36. countLoss *)
val testCountLoss1 =
  countLoss [ { name = "Anton"
              , cards = []
              , strat = falseStrategy 
              }
            , { name = "Andrew"
              , cards = [ (BLACK, WILD)
                        , (RED, NUM 5)
                        , (GREEN, DRAW_TWO)
                        , (RED, NUM 7)
                        , (BLUE, SKIP) ]
              , strat = falseStrategy 
              }
            , { name = "Alexey"
              , cards = [ (BLACK, WILD)
                        , (RED, NUM 5) ]
              , strat = falseStrategy 
              }
            ]
  = [("Anton", 0), ("Andrew", 102), ("Alexey", 55)]

(* Задание 37. naiveStrategy *)
val testNaiveStrategy1 = naiveStrategy ( EXECUTE
                                       , [ (BLACK, WILD)
                                         , (RED, NUM 5)
                                         , (GREEN, DRAW_TWO)
                                         , (RED, NUM 7)
                                         , (BLUE, SKIP) ]
                                       , (RED, SKIP)
                                       , [] )
                         = ((BLUE, SKIP), RED)
val testNaiveStrategy2 = 
  let 
    val tmp = naiveStrategy ( GIVE RED
                            , [ (BLACK, WILD)
                              , (RED, NUM 5)
                              , (GREEN, DRAW_TWO)
                              , (RED, NUM 7)
                              , (BLUE, SKIP) ]
                            , (BLACK, WILD_DRAW_FOUR)
                            , [] )
  in #1 tmp = (RED, NUM 7)
  end
val testNaiveStrategy3 = 
  let 
    val tmp = naiveStrategy ( PROCEED
                            , [ (BLACK, WILD)
                              , (RED, NUM 5)
                              , (GREEN, DRAW_TWO)
                              , (RED, NUM 7)
                              , (BLUE, SKIP) ]
                            , (RED, NUM 1)
                            , [] )
  in #1 tmp = (RED, NUM 7)
  end

(* Задание 38. play *)
val testPlay1 =
  let 
    val dsk = { players = [ { name = "Anton"
                            , cards = [(GREEN, NUM 5)]
                            , strat = falseStrategy 
                            }
                          , { name = "Andrew"
                            , cards = []
                            , strat = falseStrategy 
                            }
                          , { name = "Alexey"
                            , cards = []
                            , strat = falseStrategy 
                            }
                          ]
              , pile = [(GREEN, NUM 9)]
              , deck = [(BLUE, NUM 4)]
              , state = PROCEED
              }
    val playcards = playableCards dsk
    val tmp = play (dsk, playcards)
    val tmpplayer = getPlayersFirst tmp
    val tmppile = getDeskPile tmp
    val tmpstate = getDeskState tmp
  in 
    isSamePlayer (tmpplayer, { name = "Andrew"
                             , cards = []
                             , strat = falseStrategy })
    andalso tmppile = [(GREEN, NUM 5), (GREEN, NUM 9)]
    andalso tmpstate = PROCEED
  end
val testPlay2 =
  let 
    val dsk = { players = [ { name = "Anton"
                            , cards = [(GREEN, NUM 5)]
                            , strat = falseStrategy 
                            }
                          , { name = "Andrew"
                            , cards = []
                            , strat = falseStrategy 
                            }
                          , { name = "Alexey"
                            , cards = []
                            , strat = falseStrategy 
                            }
                          ]
              , pile = [(BLUE, NUM 9)]
              , deck = [(BLUE, NUM 4)]
              , state = PROCEED
              }
    val playcards = playableCards dsk
    val tmp = play (dsk, playcards)
  in 
    false
  end
  handle IllegalMove "Anton" => true

(* Задание 39. gameStep *)
val testGameStep1 =
  let 
    val dsk = { players = [ { name = "Anton"
                            , cards = [(GREEN, NUM 5)]
                            , strat = falseStrategy 
                            }
                          , { name = "Andrew"
                            , cards = []
                            , strat = falseStrategy 
                            }
                          , { name = "Alexey"
                            , cards = []
                            , strat = falseStrategy 
                            }
                          ]
              , pile = [(GREEN, NUM 9)]
              , deck = [(BLUE, NUM 4)]
              , state = PROCEED
              }
    val tmp = gameStep dsk
    val tmpplayer = getPlayersFirst tmp
    val tmppile = getDeskPile tmp
    val tmpstate = getDeskState tmp
  in 
    isSamePlayer (tmpplayer, { name = "Andrew"
                             , cards = []
                             , strat = falseStrategy })
    andalso tmppile = [(GREEN, NUM 5), (GREEN, NUM 9)]
    andalso tmpstate = PROCEED
  end

(* Задание 40. game *)
val testGame1 =
  let 
    val dsk = { players = [ { name = "Alexey"
                            , cards = [ (BLACK, WILD)
                                      , (RED, NUM 5) ]
                            , strat = falseStrategy 
                            }
                          , { name = "Anton"
                            , cards = [(GREEN, NUM 5)]
                            , strat = falseStrategy 
                            }
                          , { name = "Andrew"
                            , cards = [ (BLACK, WILD)
                                      , (RED, NUM 5)
                                      , (GREEN, DRAW_TWO)
                                      , (RED, NUM 7)
                                      , (BLUE, SKIP) ]
                            , strat = falseStrategy 
                            }
                          ]
              , pile = [(GREEN, NUM 9)]
              , deck = [(BLUE, NUM 4)]
              , state = PROCEED
              }
    val tmp = game dsk
  in 
    tmp = ("Anton", [("Andrew", 102), ("Alexey", 55), ("Anton", 0)])
  end
val testGame2 =
  let 
    val dsk = { players = [ { name = "Anton"
                            , cards = [(GREEN, NUM 5)]
                            , strat = falseStrategy 
                            }
                          , { name = "Andrew"
                            , cards = [ (BLACK, WILD)
                                      , (RED, NUM 5)
                                      , (GREEN, DRAW_TWO)
                                      , (RED, NUM 7)
                                      , (BLUE, SKIP) ]
                            , strat = falseStrategy 
                            }
                          , { name = "Alexey"
                            , cards = [ (BLACK, WILD)
                                      , (RED, NUM 5) ]
                            , strat = falseStrategy 
                            }
                          ]
              , pile = [(GREEN, REVERSE)]
              , deck = [(BLUE, NUM 4)]
              , state = PROCEED
              }
    val tmp = game dsk
  in 
    tmp = ("Anton", [("Alexey", 55), ("Andrew", 102), ("Anton", 0)])
  end