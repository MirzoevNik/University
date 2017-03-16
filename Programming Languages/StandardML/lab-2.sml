(* Шаблон для выполнения заданий лабораторной работы №2 
 * НЕ СЛЕДУЕТ УДАЛЯТЬ ИЛИ ПЕРЕСТАВЛЯТЬ МЕСТАМИ ЭЛЕМЕНТЫ, 
 * ПРЕДСТАВЛЕННЫЕ В ШАБЛОНЕ (ВКЛЮЧАЯ КОММЕНТАРИИ). 
 * ЭЛЕМЕНТЫ РЕШЕНИЯ СЛЕДУЕТ ВПИСЫВАТЬ В ПРОМЕЖУТКИ,
 * ОПРЕДЕЛЕННЫЕ КОММЕНТАРИЯМИ.
 * Можно (а иногда и нужно) вставлять пустые строки в промежутки, 
 * предназначенные для решения. *)

(****************************************************************************** 
                    Вспомогательные функции и определения
 ******************************************************************************)
(* Выдает "случайное" целое число, на основе текущего времени *)
fun seed () = 
  IntInf.toInt (Time.toMilliseconds (Time.now ()) mod 1000) + 100

(* Превращает некаррированную функцию двух аргументов в каррированную *)
fun curry_2 f x y = f (x, y)

(* Тип данных color для цвета (масти) карт *)
datatype color = RED | GREEN | BLUE | YELLOW | BLACK

(* Тип данных rank для значения карт *)
datatype rank = SKIP 
              | DRAW_TWO 
              | REVERSE 
              | WILD 
              | WILD_DRAW_FOUR 
              | NUM of int 

(* Тип данных card для карты *)
type card = color * rank

(* Тип данных move для состояния очередного хода *)
datatype move = PROCEED | EXECUTE | GIVE of color 

(* Тип strategy для функции, определяющей стратегию игрока *)
type strategy = move * card list * card * int list -> card * color

(* Тип данных player для игрока *)
type player = {name : string, cards : card list, strat : strategy}

(* Тип данных desk для конфигурации игры *)
type desk = { players : player list
            , pile    : card list
            , deck    : card list
            , state   : move
            }

(* Исключение "Недозволенная игра" *)
exception IllegalGame
(* Исключение "Недозволенный ход". Аргумент - имя игрока, сделавшего ход *)
exception IllegalMove of string 

(* Функции сравнения на равенство значений карт, мастей карт и карт *)
fun isSameRank  (r1 : rank, r2 : rank) = r1 = r2
fun isSameColor (col1 : color, col2 : color) = col1 = col2
fun isSameCard  (c1 : card, c2 : card) = c1 = c2

(* Список всевозможных значений карт *)
val ranks = [ NUM 0, NUM 1, NUM 2, NUM 3, NUM 4
            , NUM 5, NUM 6, NUM 7, NUM 8, NUM 9
            , SKIP, DRAW_TWO, REVERSE, WILD, WILD_DRAW_FOUR 
            ]

(* Конструктор значения типа player (игрок) 
 * аргументы имя, список карт и функция стратегии *)
fun makePlayer (n, cs, f) : player = {name= n, cards = cs, strat = f}

(* Селекторы для игрока *)
fun getPlayerName ({name = n, ...} : player) = n
fun getPlayerCards ({cards = cs, ...} : player) = cs
fun getPlayerStrategy ({strat = f, ...} : player) = f 

(* Функция замены набора карт игрока *)
fun setPlayerCards (p, newCs) =
  makePlayer (getPlayerName p, newCs, getPlayerStrategy p)

(* Конструктор конфигурации игры *)
fun makeDesk (ps, cs, ds, st) : desk = 
  {players = ps, pile = cs, deck = ds, state = st}

(* Селекторы для конфигурации игры *)
fun getDeskPlayers ({players = ps, ...} : desk) = ps
fun getDeskPile ({pile = cs, ...} : desk) = cs
fun getDeskDeck ({deck = ds, ...} : desk) = ds
fun getDeskState ({state = st, ...} : desk) = st

(* Функция замены списка игроков в конфигурации игры *)
fun setDeskPlayers (dsk, newPlayers) =
  makeDesk ( newPlayers
           , getDeskPile dsk
           , getDeskDeck dsk
           , getDeskState dsk
           )

(* Функция замены состояния очередного хода в конфигурации игры *)
fun setDeskState (dsk, newState) =
  makeDesk ( getDeskPlayers dsk
           , getDeskPile dsk
           , getDeskDeck dsk
           , newState
           )

(* Функция - фальшивая стратегия игрока: какой бы не был ход, всегда 
 * выкладывается первая карта из списка карт игрока и заказывается 
 * зеленый цвет.
 * Это вспомогательная функция для отладки и тестирования *)
fun falseStrategy (_ : move, (c :: _) : card list, _ : card, _ : int list) = 
      (c, GREEN)
  | falseStrategy _ = raise IllegalGame
(******************************************************************************
 ******************************************************************************)

(* Задание 1. getNth *)
fun getNth (x :: _, 0) = x
  | getNth (_ :: xs, n) = getNth (xs, n - 1)
  | getNth (_, _) = raise List.Empty

(* Задание 2. reverseAppend *)
fun reverseAppend ([], lst) = lst
  | reverseAppend (x :: xs, lst) = reverseAppend (xs, x :: lst)

(* Задание 3. cardValue *)
fun cardValue curCard = 
  case curCard
    of (_, NUM n) => n
     | (_, WILD) => 50
     | (_, WILD_DRAW_FOUR) => 50
     | (_, _) => 20

(* Задание 4. cardCount *)
fun cardCount curCard = 
  case curCard
    of (_, NUM 0) => 1
     | (_, WILD) => 4
     | (_, WILD_DRAW_FOUR) => 4
     | (_, _) => 2

(* Задание 5. rankColors *)
fun rankColors curRank =
  case curRank
    of WILD => [BLACK]
     | WILD_DRAW_FOUR => [BLACK]
     | _ => [RED, GREEN, BLUE, YELLOW]

(* Задание 6. sumCards *)
fun sumCards cards = 
  let
    fun helper ([], acc) = acc
      | helper (card :: cardList, acc) = 
            helper (cardList, acc + cardValue card)
  in
    helper (cards, 0)
  end

(* Задание 7. removeNth *)
fun removeNth (lst, n) = 
  let
    fun helper ([], _, _) = raise List.Empty
      | helper (_ :: l, 0, accList) =
          reverseAppend (accList, l)
      | helper (x :: l, accVal, accList) =
          helper (l, accVal - 1, x :: accList)
  in
    if n < 0 then
      raise List.Empty
    else
      helper (lst, n, [])
  end 

(* Задание 8. removeCard *)
fun removeCard (cs, c, e) = 
  let
    fun helper ([], _) =
          raise e
      | helper (x :: xs, accList) = 
          if isSameCard (x, c) then
            reverseAppend (accList, xs)
          else
            helper (xs, x :: accList)
  in
    helper (cs, [])
  end

(* Задание 9. insertElem *)
fun insertElem (cs, c, n) =
  let 
    fun helper ([], 0, accList) = 
          reverseAppend (accList, [c])
      | helper ([], _, _) = raise List.Empty
      | helper (xs, 0, accList) = 
          reverseAppend (accList, c :: xs)
      | helper (x :: xs, accVal, accList) =
          helper (xs, accVal - 1, x :: accList)
  in
    if n < 0 then
      raise List.Empty
    else
      helper (cs, n, [])
  end

(* Задание 10. interchange *)
fun interchange (cs, i, j) =
  let
    fun helper (hI, hJ) =
      let
        val vI = getNth (cs, hI)
        val vJ = getNth (cs, hJ)
      in
        insertElem (insertElem (removeNth (removeNth (cs, hJ), 
                                        hI), vJ, hI), vI, hJ)
      end
  in
    if i > j then
      helper (j, i)
    else if i < j then
           helper (i, j)
         else
           cs
  end

(* Задание 11. shuffleList *)
fun shuffleList lst =
  let
    val hSize = List.length lst - 1
    fun helper (hList, 0) = hList
      | helper (hList, i) = 
          let
            val randVal = seed ()
          in
            helper (interchange (hList, i, 
                        Random.randRange (0, hSize) 
                            (Random.rand (randVal, 
                                  randVal mod 67))
                   ), i - 1)
          end
  in
    helper (lst, hSize)
  end

(* Задание 12. allRankColors *)
fun allRankColors r =
  map (fn x => (x, r)) (rankColors r)

(* Задание 13. copyCardNTimes *)
fun copyCardNTimes c = 
  let
    fun helper (res, 1) = res
      | helper (res, acc) = helper (c :: res, acc - 1)
  in
    helper ([c], cardCount c)
  end

(* Задание 14. deck *)
val deck = foldr (op @) [] (map (fn x => copyCardNTimes x)
             (foldr (op @) [] (map (fn x => allRankColors x) ranks)))

(* Задание 15. getSameRank *)
fun getSameRank (r, cs) = 
  List.filter (fn (_, x) => isSameRank (x, r)) cs

(* Задание 16. getSameColor *)
fun getSameColor (col, cs) = 
  List.filter (fn (x, _) => isSameColor (x, col)) cs

(* Задание 17. hasRank *)
fun hasRank (r, cs) = 
  isSome (List.find (fn (_, x) => isSameRank (x, r)) cs)

(* Задание 18. hasColor *)
fun hasColor (col, cs) = 
  isSome (List.find (fn (x, _) => isSameColor (x, col)) cs)

(* Задание 19. hasCard *)
fun hasCard (c, cs) = 
  isSome (List.find (fn x => curry_2 isSameCard x c) cs)

(* Задание 20. countColor *)
fun countColor (col, cs) =
  List.length (getSameColor (col, cs))

(* Задание 21. maxColor *)
fun maxColor cs =
  let
    fun colorsCount (_, [], count) = count
      | colorsCount (color, (c, _) :: lst, count) =
          if isSameColor (c, color) then
            colorsCount (color, lst, count + 1)
          else
            colorsCount (color, lst, count)

    fun maxCount ([], _, curRes) = curRes
      | maxCount (color :: colors, max, curRes) =
          let
            val count = colorsCount (color, cs, 0)
          in
            if count > max then
              maxCount (colors, count, color)
            else
              maxCount (colors, max, curRes)
          end
  in
    maxCount ([RED, GREEN, BLUE, YELLOW], 0, RED)
  end

(* Задание 22. deal *)
fun deal playersList =
  let
    fun helper ([], cs, res) = (cs, res)
      | helper ((name, st) :: ps, cs, res) =
          let
            val playerCards = List.take (cs, 7)
          in
            helper (ps, (List.drop (cs, 7)), 
                    (makePlayer (name, playerCards, st)) :: res)
          end

    val (cs, ps) = helper (playersList, (shuffleList deck), [])
    val p = List.take (cs, 1)
  in
    makeDesk (ps, p, (List.drop (cs, 1)), PROCEED)
  end

(* Задание 23. getPlayersFirst *)
fun getPlayersFirst dsk = 
  let
    val first :: _ = getDeskPlayers dsk
  in
    first
  end

(* Задание 24. getPileTop *)
fun getPileTop dsk =
  let
     val first :: _ = getDeskPile dsk
   in
     first
   end

(* Задание 25. nextPlayer *)
fun nextPlayer dsk =
  let
    val first :: tail = getDeskPlayers dsk
  in
    setDeskPlayers (dsk, tail @ [first])
  end

(* Задание 26. changeDirection *)
fun changeDirection dsk =
  let
    val first :: tail = getDeskPlayers dsk
  in
    setDeskPlayers (dsk, [first] @ reverseAppend (tail, []))
  end

(* Задание 27. start *)
fun start dsk =
  let
    val deskPile = getPileTop dsk
    val deskAfterNextPlayer = nextPlayer dsk
    val newPile :: newDeck = shuffleList (deskPile :: getDeskDeck dsk)
  in
    case deskPile
      of (BLACK, _) => start (makeDesk (getDeskPlayers dsk, [newPile], newDeck, getDeskState dsk))
       | (_, REVERSE) => changeDirection dsk
       | (_, SKIP) => setDeskState (deskAfterNextPlayer, EXECUTE)
       | (_, DRAW_TWO) => setDeskState (deskAfterNextPlayer, EXECUTE)
       | (_, _) => deskAfterNextPlayer
  end

(* Задание 28. take_1 *)
fun take_1 dsk = 
  let
    val headPlayers :: tailPlayers = getDeskPlayers dsk
    val headPiles :: tailPiles = getDeskPile dsk
    val deskState = getDeskState dsk
  in
    case getDeskDeck dsk
      of [] => take_1 (makeDesk (headPlayers :: tailPlayers, [headPiles],
                                 shuffleList tailPiles, deskState))
       | c :: newDeck => makeDesk (setPlayerCards (headPlayers, 
                                                   c :: getPlayerCards headPlayers)
                                      :: tailPlayers, 
                                   headPiles :: tailPiles, newDeck, deskState)
  end

(* Задание 29. take_2 *)
fun take_2 dsk = (take_1 o take_1) dsk

(* Задание 30. take_4 *)
fun take_4 dsk = (take_2 o take_2) dsk

(* Задание 31. pass *)
fun pass dsk =
  let
    val (_, cardVal) = getPileTop dsk
    val st = getDeskState dsk
  in
    case (cardVal, st)
      of (SKIP, EXECUTE) => 
              setDeskState (nextPlayer dsk, PROCEED)
       | (DRAW_TWO, EXECUTE) => 
              setDeskState ((nextPlayer o take_2) dsk, PROCEED)
       | (_, _) => nextPlayer dsk
  end

(* Задание 32. requiredColor *)
fun requiredColor dsk =
  let
    val (c, _) = getPileTop dsk
  in
    case getDeskState dsk
      of GIVE col => col
       | _ => c
  end

(* Задание 33. playableCards *)
fun playableCards dsk =
  let
    val cs = (getPlayerCards o getPlayersFirst) dsk
    val (pileColor, pileRank) = getPileTop dsk
  in
    case getDeskState dsk
      of GIVE col => List.filter (fn (c, _) =>
                        isSameColor (col, c) 
                          orelse isSameColor (BLACK, c)) cs
       | EXECUTE => List.filter (fn (_, r) =>
                        isSameRank (pileRank, r)) cs
       | PROCEED => List.filter (fn (c, r) =>
                        isSameColor (BLACK, c)
                          orelse isSameColor (pileColor, c)
                          orelse isSameRank (pileRank, r)) cs
  end

(* Задание 34. countCards *)
fun countCards dsk = 
  map (fn x => (List.length o getPlayerCards) x) (getDeskPlayers dsk)

(* Задание 35. hasNoCards *)
fun hasNoCards p = (null o getPlayerCards) p

(* Задание 36. countLoss *)
fun countLoss ps = 
  map (fn x => (getPlayerName x, (sumCards o getPlayerCards) x)) ps

(* Задание 37. naiveStrategy *)
fun naiveStrategy (playState, playerCs, (colorTop, rankTop), _) =
  let
    val maxPlayerColor = maxColor playerCs

    fun maxValue ([], _, curRes) = curRes
      | maxValue (c :: cs, max, curRes) =
          let
            val value = cardValue c
          in
            if value > max then
              maxValue (cs, value, c)
            else
              maxValue (cs, max, curRes)
          end

  in
    case playState
      of GIVE col => if hasColor (col, playerCs) 
                            andalso hasRank (WILD, playerCs) 
                            andalso not (isSameColor (maxPlayerColor, col)) then
                        ((BLACK, WILD), maxPlayerColor)
                     else 
                      if not (hasColor (col, playerCs)) then
                        if hasRank (WILD_DRAW_FOUR, playerCs) then
                          ((BLACK, WILD_DRAW_FOUR), maxPlayerColor)
                        else
                          ((BLACK, WILD), maxPlayerColor)
                      else
                        (maxValue (getSameColor (col, playerCs), 0, (col, NUM 0)), colorTop)
       | EXECUTE => let
                      val samePlayerCardByRank :: _ = getSameRank (rankTop, playerCs)
                    in
                      (samePlayerCardByRank, colorTop)
                   end
       | PROCEED => if hasColor (colorTop, playerCs)
                          orelse hasRank (rankTop, playerCs) then
                      (maxValue (getSameColor (colorTop, playerCs) 
                                  @ getSameRank (rankTop, playerCs), 
                                 0, (colorTop, NUM 0)), colorTop)
                    else
                      if hasRank (WILD_DRAW_FOUR, playerCs) then
                          ((BLACK, WILD_DRAW_FOUR), maxPlayerColor)
                        else
                          ((BLACK, WILD), maxPlayerColor)
  end

(* Задание 38. play *)
fun play (dsk, playCards) = 
  let
    val (requiredColor, _) = getPileTop dsk
    val curPlayer = getPlayersFirst dsk
    val cardsCurPlayer = getPlayerCards curPlayer
    val (stCard, stColor) = getPlayerStrategy curPlayer 
                              (getDeskState dsk, cardsCurPlayer, getPileTop dsk, countCards dsk)
    val newCurPlayerCards = removeCard (playCards, stCard, IllegalMove (getPlayerName curPlayer))
    val newPile = stCard :: getDeskPile dsk
    val _ :: tailPlayers = getDeskPlayers dsk
    val newDesk = makeDesk (setPlayerCards (curPlayer, newCurPlayerCards) :: tailPlayers, 
                            newPile, getDeskDeck dsk, getDeskState dsk)
  in
    case stCard
      of (_, WILD_DRAW_FOUR) => if hasColor (requiredColor, cardsCurPlayer) then
                                  (nextPlayer o take_4 o setDeskState) (newDesk, GIVE stColor)
                                else
                                  (nextPlayer o take_4 o nextPlayer o setDeskState) (newDesk, GIVE stColor)
       | (_, WILD) => (nextPlayer o setDeskState) (newDesk, GIVE stColor)
       | (_, NUM _) => (nextPlayer o setDeskState) (newDesk, PROCEED)
       | (_, REVERSE) => (nextPlayer o changeDirection o setDeskState) (newDesk, PROCEED)
       | _ => (nextPlayer o setDeskState) (newDesk, EXECUTE)
  end

(* Задание 39. gameStep *)
fun gameStep dsk =
  let
    val takeResult = take_1 dsk
    val playableResult = playableCards takeResult
  in
    case playableCards dsk
      of [] => (case getDeskState dsk
                 of EXECUTE => pass dsk
                  | _ => (case playableResult
                           of [] => pass takeResult
                            | _ => play (takeResult, playableResult)))
       | playCards => play (dsk, playCards)
  end

(* Задание 40. game *)
fun game dsk =
  let
    fun helper curDsk =
      case List.find (fn x => hasNoCards x) (getDeskPlayers curDsk)
        of NONE => (helper o gameStep) curDsk
         | SOME winner => (winner, curDsk)

    val (winnerPlayer, resultDsk) = (helper o gameStep o start) dsk
  in
    (getPlayerName winnerPlayer, (countLoss o getDeskPlayers) resultDsk)
  end