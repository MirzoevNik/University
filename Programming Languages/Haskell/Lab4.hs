
-- Шаблон для выполнения заданий Лабораторной работы №4 
-- ВСЕ КОММЕНТАРИИ ПРИВЕДЕННЫЕ В ДАННОМ ФАЙЛЕ ДОЛЖНЫ ОСТАТЬСЯ НА СВОИХ МЕСТАХ
-- предыдущее замечание относится к тем комментариям, которые
-- не предполагают раскомментирование
-- НЕЛЬЗЯ ПЕРЕСТАВЛЯТЬ МЕСТАМИ КАКИЕ-ЛИБО БЛОКИ ДАННОГО ФАЙЛА
-- решения заданий должны быть вписаны в отведенные для этого позиции 

-- ниеже перечисляются имена, доступные после загрузки данного модуля
-- (например в файле с тестами)
-- по мере реализации решений заданий снимайте комментарий 
-- с соответствующей функции
module Lab4(
  Expr ( Var, IntNum, Add, IfGreater, Fun, Call, Let
       , Pair, Head, Tail, Unit, IsAUnit, Closure )
  , valOfIntNum
  , funName
  , funArg
  , funBody
  , pairHead
  , pairTail
  , closureFun
  , closureEnv
  , convertListToMUPL
  , convertListFromMUPL
  , envLookUp
  , evalExp
  , evalUnderEnv
  --, ifAUnit
  --, mLet
  --, ifEq
  --, mMap
  --, mMapAddN
  --, fact
  )
  where
--------------------------------------------------------------------------------
-- Вспомогательные определения
-- нельзя вносить изменения в следующий блок
--------------------------------------------------------------------------------
data Expr = Var String
          | IntNum Integer
          | Add Expr Expr
          | IfGreater Expr Expr Expr Expr
          | Fun String String Expr
          | Call Expr Expr
          | Let (String, Expr) Expr
          | Pair Expr Expr
          | Head Expr
          | Tail Expr
          | Unit 
          | IsAUnit Expr
          | Closure [(String, Expr)] Expr
  deriving (Show, Eq) 

valOfIntNum (IntNum n) = n
valOfIntNum e          = error $ "The expression " 
                                 ++ show (e) 
                                 ++ " is not a number"
--------------------------------------------------------------------------------
-- Задание 1 funName 
funName (Fun s _ _) = s
funName e          = error $ "The expression " 
                                 ++ show (e) 
                                 ++ " is not a function"

-- Задание 2 funArg 
funArg (Fun _ s _) = s
funArg e          = error $ "The expression " 
                                 ++ show (e) 
                                 ++ " is not a function"

-- Задание 3 funBody 
funBody (Fun _ _ b) = b
funBody e          = error $ "The expression " 
                                 ++ show (e) 
                                 ++ " is not a function"

-- Задание 4 pairHead 
pairHead (Pair h _) = h
pairHead e          = error $ "The expression " 
                                 ++ show (e) 
                                 ++ " is not a pair"

-- Задание 5 pairTail 
pairTail (Pair _ t) = t
pairTail e          = error $ "The expression " 
                                 ++ show (e) 
                                 ++ " is not a pair"

-- Задание 6 closureFun 
closureFun (Closure _ f) = f
closureFun e          = error $ "The expression " 
                                 ++ show (e) 
                                 ++ " is not a closure"

-- Задание 7 closureEnv 
closureEnv (Closure e _) = e
closureEnv e          = error $ "The expression " 
                                 ++ show (e) 
                                 ++ " is not a closure"

-- Задание 8 convertListToMUPL 
convertListToMUPL [] = Unit
convertListToMUPL (x : xs) = Pair x (convertListToMUPL xs)

-- Задание 9 convertListFromMUPL 
convertListFromMUPL Unit = []
convertListFromMUPL l = pairHead : convertListFromMUPL (pairTail l)

--------------------------------------------------------------------------------
-- Вспомогательные определения
-- нельзя вносить изменения в следующий блок
--------------------------------------------------------------------------------
envLookUp [] str = error $ "Unbound variable " ++ str
envLookUp ((var, expr) : xs) str 
  | var == str = expr
  | otherwise  = envLookUp xs str

evalExp e = evalUnderEnv e []
--------------------------------------------------------------------------------
-- Задание 10 evalUnderEnv 
-- Заданную строку определения изменять нельзя
-- необходимо дополнить определение функции
evalUnderEnv (Var name) env = envLookUp env name

--------------------------------------------------------------------------------
-- Последующие решения связывают переменные Haskellа с выражениями на MUPL
-- (определяют макросы языка MUPL)
-- Задание 11 ifAUnit 

-- Задание 12 mLet 

-- Задание 14 mMap 

-- Задание 15 mMapAddN 

-- Задание 16 fact 
