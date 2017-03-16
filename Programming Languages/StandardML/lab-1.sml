(* Шаблон для выполнения заданий лабораторной работы №1 *)

(* Задание 1 isLeapYear *)
fun isLeapYear (year : int) : bool = 
  year mod 400 = 0 orelse year mod 4 = 0 
                  andalso year mod 100 <> 0

(* Задание 2 isCorrectDate *)
fun isCorrectDate (date : int * int * int) : bool = 
  let
    val day = #1 date
    val month = #2 date
    val year = #3 date
  in
    if day <= 0 orelse month <= 0 orelse year <= 0 then 
      false
    else
      case (day, month, year)
        of (_, 1, _) => day <= 31
         | (_, 2, _) => if isLeapYear year then 
                          day <= 29
                        else
                          day <= 28
         | (_, 3, _) => day <= 31
         | (_, 4, _) => day <= 30
         | (_, 5, _) => day <= 31
         | (_, 6, _) => day <= 30
         | (_, 7, _) => day <= 31
         | (_, 8, _) => day <= 31
         | (_, 9, _) => day <= 30
         | (_, 10, _) => day <= 31
         | (_, 11, _) => day <= 30
         | (_, 12, _) => day <= 31
         | (_, _, _) => false
  end

(* Задание 3 newStyleCorrection *)
fun newStyleCorrection (date : int * int * int) : int =
  let
    val month = #2 date
    val year = #3 date
    fun count (y, sum) =
      if y = year then 
        sum
      else
        if y mod 100 = 0 andalso y mod 400 <> 0 then
          count (y + 1, sum + 1)
        else
          count (y + 1, sum)
  in
    if year mod 100 = 0 andalso year mod 400 <> 0 andalso month > 2 then
      count (1, 0) - 1
    else
      count (1, 0) - 2
  end

(* Задание 4 getNthInt *)
fun getNthInt (l : int list, n : int) : int =
  if n = 0 then
    hd l
  else
    getNthInt (tl l, n - 1)


(* Задание 5 getNthStr *)
fun getNthStr (l : string list, n : int) : string =
  if n = 0 then
    hd l
  else
    getNthStr (tl l, n - 1)

(* Задание 6 lastSmaller *)
fun lastSmaller (amount : int, lst : int list) : int =
  let
    fun findLast (rez, l) = 
      if l = [] orelse hd l >= amount then
        rez
      else
        findLast (hd l, tl l)
  in
    findLast (0, lst)
  end

(* Списки для выполнения задания 8 (списки поправок) *)
(* поправка на тысячи года *)
val thousandCorrection = [ 0, 1390000, 2770000, 1210000, 2590000
                          , 1030000, 2420000 ]
(* поправка на сотни года *)
val hundredCorrection  = [ 0, 430000, 870000, 1300000, 1740000
                          , 2170000, 2600000, 80000, 520000, 950000 ]
(* поправка на десятки года *)
val decadeCorrection   = [ 0, 930000, 1860000, 2790000, 760000
                          , 1690000, 2620000, 600000, 1530000, 2460000 ]
(* поправка на единицы года *)
val yearCorrection     = [ 0, 1860000, 780000, 2640000, 1550000
                          , 460000, 2330000, 1240000, 150000, 2020000 ]
(* поправка на месяц *)
val monthCorrection    = [ 1340000, 1190000, 2420000, 2260000, 2200000
                          , 2060000, 2000000, 1840000, 1700000, 1660000
                          , 1510000, 1480000 ]
(* календарная поправка *)
val calendarCorrection = [0, 20000, 50000, 80000]
(* поправка для нормализации дня месяца *)
val reductions = [2953059, 5906118, 8859177, 11812236, 14765295, 17718354] 

(* Задание 7 firstNewMoonInt *)
fun firstNewMoonInt (date : int * int * int) : int option =
  let
    val year = #3 date
    val month = #2 date
    val corYear = if month < 3 then
                    year - 1
                  else
                    year
    val sum = 100000 * newStyleCorrection (#1 date, month, year) 
      + getNthInt (thousandCorrection, corYear div 1000)
      + getNthInt (hundredCorrection, corYear mod 1000 div 100)
      + getNthInt (decadeCorrection, corYear mod 100 div 10)
      + getNthInt (yearCorrection, corYear mod 10)
      + getNthInt (monthCorrection, month - 1)
      + getNthInt (calendarCorrection, corYear mod 4)
    val result = sum - lastSmaller (sum - 100000, reductions)
  in
     if month = 2 andalso result div 100000 > (if isLeapYear year then 29 else 28) then
      NONE
    else
      SOME result
  end

(* Задание 8 firstNewMoon *)
fun firstNewMoon (date : int * int * int) : (int * int * int) option = 
  let
    val res = firstNewMoonInt date
  in
    if isSome res then
      SOME (valOf res div 100000, #2 date, #3 date)
    else
      NONE
  end


(* Задание 9 dateToString *)
fun dateToString (date : int * int * int) : string =
  getNthStr(["January", "February", "March", "April", "May", 
             "June",  "July", "August", "September", "October", 
             "November", "December"], #2 date - 1) 
  ^ " " ^ Int.toString (#1 date) ^ ", " ^ Int.toString (#3 date)


(* Задание 10 isOlder *)
fun isOlder (date : int * int * int, date2 : int * int * int) : bool = 
  let
    val year = #3 date
    val year2 = #3 date2
    val month = #2 date
    val month2 = #2 date2
  in
    if year < year2 
       orelse year = year2 andalso month < month2
       orelse year = year2 andalso month = month2 
              andalso #1 date < #1 date2 then
      true
    else 
      false
  end

(* Задание 11 winterSolstice *)
fun winterSolstice (year : int) : int = 
  let
    fun countLeapYears (curYear : int, count : int) : int =
      if curYear = year + 1 then
        count
      else
        if isLeapYear curYear then
          countLeapYears (curYear + 1, count + 1)
        else
          countLeapYears (curYear + 1, count)
  in
    (2250000 + year * 24220 
             - countLeapYears (1, 0) * 100000 ) 
      div 100000
  end

(* Задание 12 chineseNewYear *)
fun chineseNewYear (year : int) : int * int * int =
  let
    val lastYear = year - 1
    val newMoonDay = valOf (firstNewMoonInt (1, 12, lastYear)) div 100000
    val newMoonDate = (newMoonDay, 12, lastYear)
    fun nextDate (date : int *  int * int, days : int) : int * int * int =
      let 
        val dif = days div 100000 - 31 + #1 date
      in
        if dif < 32 then 
          (dif, 1, year)
        else
          (dif - 31, 2, year)
      end
  in
    if 100000 * winterSolstice lastYear < newMoonDay then
      nextDate (newMoonDate, 2953059)
    else
      nextDate (newMoonDate, 5906118)
  end

(* Списки для выполнения задания 13 *)
(* список небесных стихий (по-китайски) *)
val celestialChi   = [ "Jia", "Yi", "Bing", "Ding", "Wu"
                      , "Ji", "Geng", "Xin", "Ren", "Gui" ] 
(* список небесных стихий (по-английски) *)
val celestialEng   = [ "Growing wood", "Cut timber", "Natural fire"
                      , "Artificial fire", "Earth", "Earthenware"
                      , "Metal", "Wrought metal", "Running water"
                      , "Standing water" ]
(* цвета, соответствующие небесным стихиям *)
val celestialColor = ["Green", "Red", "Brown", "White", "Black"] 
(* список земных стихий (по-китайски) *)
val terrestrialChi = [ "Zi", "Chou", "Yin", "Mao"
                      , "Chen", "Si", "Wu", "Wei"
                      , "Shen", "You", "Xu", "Hai" ]
(* список земных стихий (по-английски) *)
val terrestrialEng = [ "Rat", "Cow", "Tiger", "Rabbit"
                      , "Dragn", "Snake", "Horse", "Sheep"
                      , "Monkey", "Chicken", "Dog", "Pig" ]

(* Задание 13 chineseYear *)
fun chineseYear (year : int) : string * string * string * string = 
  let
    val serialNum = (year + 2396) mod 60
    val celestial = serialNum mod 10
    val terrestrial = serialNum mod 12
  in
    (getNthStr (celestialChi, celestial) ^ "-" ^ getNthStr (terrestrialChi, terrestrial),
      getNthStr (celestialColor, celestial div 2),
      getNthStr (terrestrialEng, terrestrial),
      getNthStr (celestialEng, celestial))
  end

(* Задание 14 dateToChineseYear *)
fun dateToChineseYear (date : int * int * int) : string * string * string * string  =
  chineseYear (#3 (chineseNewYear (#3 date)))

(* Задание 15 dateToAnimal *)
fun dateToAnimal (date : int * int * int) : string =
  #3 (dateToChineseYear (date))

(* Задание 16 animal *)
fun animal (student : string * (int * int * int)) : string =
  dateToAnimal (#2 student)

(* Задание 17 extractAnimal *)
fun extractAnimal (students : (string * (int * int * int)) list, animalName : string) : (string * (int * int * int)) list =
  if null students then
    []
  else if animal (hd students) = animalName then
         [hd students] @ extractAnimal (tl students, animalName)
       else
         extractAnimal (tl students, animalName)

(* Задание 18 extractAnimals *)
fun extractAnimals (students : (string * (int * int * int)) list, animals : string list) : (string * (int * int * int)) list =
  if null animals then
    []
  else
    extractAnimal (students, hd animals) @ extractAnimals (students, tl animals)

(* Задание 19 oldest *)
fun oldest (studentsList : (string * (int * int * int)) list) : string option =
  let
    fun oldestStudent (students : (string * (int * int * int)) list) : (string * (int * int * int)) option =
      let
        val oldStudent = if null students then 
                           NONE
                         else
                           oldestStudent (tl students)
      in
        if null students then
          NONE
        else if isSome oldStudent andalso isOlder (#2 (valOf oldStudent), #2 (hd students)) then
               oldStudent
             else
               SOME (hd students)
      end
    val result = oldestStudent studentsList
  in
    if isSome result then
      SOME (#1 (valOf result))
    else
      NONE
  end

(* Задание 20 oldestFromAnimals *)
fun oldestFromAnimals (students : (string * (int * int * int)) list, animals : string list) : string option =
  oldest (extractAnimals (students, animals))