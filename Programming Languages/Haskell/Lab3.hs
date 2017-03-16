
-- Шаблон для выполнения заданий Лабораторной работы №3 

-- ниеже перечисляются имена, доступные после загрузки данного модуля
-- (например в файле с тестами)
-- по мере реализации решений заданий снимайте комментарий 
-- с соответствующей функции
module Lab3 
  ( epsilon
  , epsilon'
  , epsilon''
  , nat
  , fibonacci
  , factorial
  , powerSeq
  , findCloseEnough
  , streamSum
  , expSummands
  , expStream
  , expSummands
  , expStream
  , expAppr
  , derivationAppr
  , derivationStream
  , derivation
  --, funAkStream 
  --, invF
  , average
  , averageDump
  , newtonTransform
  , eitken
  , fixedPoint
  , fixedPointOfTransform
  , sqrt1
  , sqrCube1
  , sqrt2
  , sqrCube2
  --, extremum
  , myPi
  ) where
--------------------------------------------------------------------------------
-- Вспомогательные определения
--------------------------------------------------------------------------------
import Data.List
epsilon  = 0.001
epsilon' = 0.00001
epsilon'' = 0.00000001
--------------------------------------------------------------------------------

-- Задание 1 nat
nat = [1..]

-- Задание 2 fibonacci 
fibonacci = 0 : 1 : zipWith (+) fibonacci (tail fibonacci)

-- Задание 3 factorial 
factorial = 1 : zipWith (*) factorial nat 

-- Задание 4 powerSeq 
powerSeq x = 1 : map (\ y -> y * x) (powerSeq x)

-- Задание 5 findCloseEnough 
findCloseEnough eps stream =
  let 
    alterList [] = []
    alterList [_] = []
    alterList (x : y : xs) = (x, y) : alterList xs

    Just (_, res) = find (\ (x, y) -> abs (y - x) <= eps) (alterList stream)
  in
    res

-- Задание 6 streamSum 
streamSum stream = 0 : zipWith (+) (streamSum stream) stream

-- Задание 7 expSummands 
expSummands x = zipWith (/) (powerSeq x) 
                            (map (\ x -> fromIntegral x) factorial)

-- Задание 8 expStream
expStream x = streamSum (expSummands x)

-- Задание 9 expAppr 
expAppr eps = \ x -> (findCloseEnough eps (expStream x))

-- Задание 10 derivationAppr 
derivationAppr f dx = \ x -> (f (x + dx) - f x ) / dx

-- Задание 11 derivationStream 
derivationStream f = map (\ x -> derivationAppr f x) 
                         (iterate (\ x -> x / 2) 1)

-- Задание 12 derivation 
derivation f = \ x -> findCloseEnough epsilon' 
            (map (\ t -> t x) (derivationStream f))

-- Задание 13 funAkStream и invF     

-- Задание 14 average 
average x y = (x + y) / 2

-- Задание 15 averageDump 
averageDump f = \ x -> (x + f x) / 2

-- Задание 16 newtonTransform 
newtonTransform g = \ x -> x - (g x) / (derivation g x)

-- Задание 17 eitken 
eitken [] = []
eitken (x : y : z : xs) = (z * x - y * y) / (z - 2.0 * y + x) : (eitken xs)

-- Задание 18 fixedPoint
fixedPoint f x0 = iterate f x0

-- Задание 19 fixedPointOfTransform 
fixedPointOfTransform f transform x0 = findCloseEnough epsilon'
                                      (fixedPoint (transform f) x0)

-- Задание 20 sqrt1 
sqrt1 x = fixedPointOfTransform (\ y -> x / y) averageDump 1.0

-- Задание 21 sqrCube1 
sqrCube1 x = fixedPointOfTransform (\ y -> x / (y * y)) averageDump 1.0

-- Задание 22 sqrt2 
sqrt2 x = fixedPointOfTransform (\ y -> y * y - x) newtonTransform 1.0

-- Задание 23 sqrCube2 
sqrCube2 x = fixedPointOfTransform (\ y -> y * y * y - x) newtonTransform 1.0

-- Задание 24 extremum 

-- Задание 25 myPi 
myPi = 4 * findCloseEnough epsilon'' (eitken (streamSum 
      (iterate (\ x -> - x / ((abs x) * (2 + abs (1 / x)))) 1)))