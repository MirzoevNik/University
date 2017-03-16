isSubset [] _ = True
isSubset (x : xs) ys =
  let
    hasElement _ [] = False
    hasElement x (y : xs)
      | x == y    = True
      | otherwise = hasElement x xs
  in
    hasElement x ys && isSubset xs ys

main = do
  let l1 = []
  let l2 = []
  putStrLn ((show l1) ++ " " ++ (show l2) ++ " -> " ++ (show (isSubset l1 l2)))
  let l1 = []
  let l2 = [1, 2]
  putStrLn ((show l1) ++ " " ++ (show l2) ++ " -> " ++ (show (isSubset l1 l2)))
  let l1 = [1]
  let l2 = [1, 2]
  putStrLn ((show l1) ++ " " ++ (show l2) ++ " -> " ++ (show (isSubset l1 l2)))
  let l1 = [1, 2]
  let l2 = [1, 2]
  putStrLn ((show l1) ++ " " ++ (show l2) ++ " -> " ++ (show (isSubset l1 l2)))
  let l1 = [1, 2, 3]
  let l2 = [1, 2]
  putStrLn ((show l1) ++ " " ++ (show l2) ++ " -> " ++ (show (isSubset l1 l2)))