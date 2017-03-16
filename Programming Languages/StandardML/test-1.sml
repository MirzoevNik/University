(* Первоначальный набор тестов для лабораторной работы №1 *)

(* Задание 1 *)
val testIsLeapYear1 = isLeapYear 2000 = true 
val testIsLeapYear2 = isLeapYear 2015 = false
val testIsLeapYear3 = isLeapYear 2016 = true
val testIsLeapYear4 = isLeapYear 1 = false
val testIsLeapYear5 = isLeapYear 6999 = false
val testIsLeapYear6 = isLeapYear 700 = false

(* Задание 2 *)
val testIsCorrectDate1 = isCorrectDate (1, 9, 2016) = true
val testIsCorrectDate2 = isCorrectDate (21, 13, 1900) = false
val testIsCorrectDate3 = isCorrectDate (~12, 3, 1857) = false
val testIsCorrectDate4 = isCorrectDate (1, 3, ~1857) = false
val testIsCorrectDate5 = isCorrectDate (1, ~3, 1857) = false
val testIsCorrectDate6 = isCorrectDate (29, 2, 2016) = true
val testIsCorrectDate7 = isCorrectDate (29, 2, 2015) = false
val testIsCorrectDate8 = isCorrectDate (31, 9, 2016) = false

(* Задание 3 *)
val testNewStyleCorrection1 = newStyleCorrection (1, 3, 2016) = 13
val testNewStyleCorrection2 = newStyleCorrection (28, 2, 1700) = 10
val testNewStyleCorrection3 = newStyleCorrection (1, 1, 201) = 0
val testNewStyleCorrection4 = newStyleCorrection (2, 1, 301) = 1

(* Задание 4 *)
val testGetNthInt1 = 
  let val tmp = getNthInt ([25, ~615, 834, ~38, 0], 3) 
  in tmp = ~38
  end
val testGetNthInt2 = 
  let val tmp = getNthInt ([25, ~615, 834, ~38, 0], 0) 
  in tmp = 25
  end
val testGetNthInt3 = 
  let val tmp = getNthInt ([25, ~615, 834, ~38, 0], 4) 
  in tmp = 0
  end
val testGetNthInt4 = 
  let val tmp = getNthInt ([25], 0) 
  in tmp = 25
  end

(* Задание 5 *)
val testGetNthStr1 = 
  getNthStr (["hi", "there", "how", "are", "you"], 2) = "how"
val testGetNthStr2 = 
  getNthStr (["hi", "there", "how", "are", "you"], 0) = "hi"
val testGetNthStr3 = 
  getNthStr (["hi", "there", "how", "are", "you"], 4) = "you"
val testGetNthStr4 = 
  getNthStr (["hi"], 0) = "hi"

(* Задание 6 *)
val testLastSmaller1 = lastSmaller (3654, [0, 25, 834, 3800]) = 834 
val testLastSmaller2 = lastSmaller (3800, [0, 25, 834, 3800]) = 834 
val testLastSmaller3 = lastSmaller (3801, [0, 25, 834, 3800]) = 3800
val testLastSmaller4 = lastSmaller (3, [5, 25, 834, 3800]) = 0
val testLastSmaller5 = lastSmaller (3, [3, 25, 834, 3800]) = 0
val testLastSmaller6 = lastSmaller (3, [2, 25, 834, 3800]) = 2

(* Задание 7 *)
val testFirstNewMoonInt1 = firstNewMoonInt (1, 1, 201) = SOME 2210000
val testFirstNewMoonInt2 = firstNewMoonInt (1, 9, 2016) = SOME 170823
val testFirstNewMoonInt3 = firstNewMoonInt (1, 1, 203) = SOME 3040000

(* Задание 8 *)
val testFirstNewMoon1  = firstNewMoon (1, 1, 201) = SOME (22,1,201)
val testFirstNewMoon2  = firstNewMoon (1, 9, 2016) = SOME (1, 9, 2016)
val testFirstNewMoon3  = firstNewMoon (1, 1, 203) = SOME (30,1,203)

(* Задание 9 *)
val testDateToString1  = dateToString (5, 5, 1980) = "May 5, 1980"
val testDateToString2  = dateToString (1, 9, 2016) = "September 1, 2016"
val testDateToString3  = dateToString (1, 1, 201) = "January 1, 201"

(* Задание 10 *)
val testIsOlder1 = isOlder ((1, 2, 3), (2, 3, 4)) = true
val testIsOlder2 = isOlder ((2, 3, 4), (1, 2, 3)) = false
val testIsOlder3 = isOlder ((1, 1, 201), (1, 1, 201)) = false

(* Задание 11 *)
val testWinterSolstice1 = winterSolstice 0 = 22
val testWinterSolstice2 = winterSolstice 3 = 23
val testWinterSolstice3 = winterSolstice 2014 = 22
val testWinterSolstice4 = winterSolstice 201 = 23
val testWinterSolstice5 = winterSolstice 2999 = 21
val testWinterSolstice6 = winterSolstice 2016 = 21
val testWinterSolstice7 = winterSolstice 2025 = 21

(* Задание 12 *)
val testChineseNewYear1 = chineseNewYear 2016 = (8, 2, 2016)
val testChineseNewYear2 = chineseNewYear 201 = (20, 2, 201)
val testChineseNewYear3 = chineseNewYear 2999 = (7, 2, 2999)
val testChineseNewYear4 = chineseNewYear 2007 = (17, 2, 2007)
val testChineseNewYear5 = chineseNewYear 2025 = (29, 1, 2025)

(* Задание 13 *)
val testChineseYear1 = 
  chineseYear 1980 = ("Geng-Shen", "White", "Monkey", "Metal")
val testChineseYear2 = 
  chineseYear 2015 = ("Yi-Wei", "Green", "Sheep", "Cut timber")
val testChineseYear3 =
  chineseYear 201 = ("Xin-Si", "White", "Snake", "Wrought metal")
val testChineseYear4 =
  chineseYear 2999 = ("Ji-Wei", "Brown", "Sheep", "Earthenware")

(* Задание 14 *)
val testDateToChineseYear1 = 
  dateToChineseYear (1, 9, 1980) = ("Geng-Shen", "White", "Monkey", "Metal")
val testDateToChineseYear2 = 
  dateToChineseYear (1, 9, 2016) = ("Bing-Shen", "Red", "Monkey", "Natural fire")
val testDateToChineseYear3 = 
  dateToChineseYear (1, 1, 201) = ("Xin-Si", "White", "Snake", "Wrought metal")
val testDateToChineseYear4 = 
  dateToChineseYear (1, 1, 2999) = ("Ji-Wei", "Brown", "Sheep", "Earthenware")

(* Задание 15 *)
val testDateToAnimal1 = 
  dateToAnimal (1, 9, 1980) = "Monkey"
val testDateToAnimal2 = 
  dateToAnimal (1, 9, 2016) = "Monkey"
val testDateToAnimal3 = 
  dateToAnimal (1, 9, 201) = "Snake"

(* Задание 16 *)
val testAnimal1 = 
  animal ("Ivan", (1, 9, 1980)) = "Monkey"
val testAnimal2 = 
  animal ("Svetlana", (1, 9, 2016)) = "Monkey"
val testAnimal3 = 
  animal ("Svetlana", (1, 9, 201)) = "Snake"

(* Вспомогательная функция для тестирования заданий 17 и 18
 * выдает true, когда элемент a присутствует в списке l 
 * иначе выдает false *)
fun member ( a : string * (int * int * int)
           , l : (string * (int * int * int)) list
           ) : bool =
  if null l then false
  else a = hd l orelse member (a, tl l)

(* Задание 17 *)
val testExtractAnimal1 = 
  extractAnimal ( [ ("Ivan", (1,9,1980))
                   , ("Svetlana", (1,9,2015)) ]
                 , "Monkey" ) 
  = [("Ivan", (1, 9, 1980))]
val testExtractAnimal2 = 
  let val tmp = extractAnimal ( [ ("Ivan", (1,9,1980))
                                 , ("Svetlana", (1,9,2015))
                                 , ("Alex", (1,9,1955)) 
                                 ]
                               , "Sheep" )
  in
    member (("Svetlana", (1,9,2015)), tmp)
    andalso member (("Alex", (1,9,1955)), tmp)
    andalso length tmp = 2
  end 

(* Задание 18 *)
val testExtractAnimals1 = 
  extractAnimals ( [ ("Ivan", (1,9,1980))
                    , ("Svetlana", (1,9,2015)) ]
                  , ["Monkey"] ) 
  = [("Ivan", (1,9,1980))]
val testExtractAnimals2 = 
  let val tmp = extractAnimals ( [ ("Ivan", (1,9,1980))
                                  , ("Svetlana", (1,9,2015)) 
                                  , ("Alex", (1,9,1955)) 
                                  ]
                                , ["Monkey", "Sheep"] )
  in
    member (("Svetlana", (1,9,2015)), tmp)
    andalso member (("Alex", (1,9,1955)), tmp)
    andalso member (("Ivan", (1,9,1980)), tmp)
    andalso length tmp = 3
  end

(* Задание 19 *)
val testOldest1 = 
  oldest [ ("Ivan", (1,9,1980))
         , ("Svetlana", (1,9,2015))
         , ("Alex", (1,9,1955)) ] 
  = SOME "Alex"

(* Задание 20 *)
val testOldestFromAnimals1 = 
  oldestFromAnimals ( [ ("Ivan", (1,9,1980))
                        , ("Svetlana", (1,9,2015)) 
                        , ("Alex", (1,9,1955)) 
                        ]
                      , ["Monkey", "Sheep"] ) 
  = SOME "Alex"
