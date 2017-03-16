isSubset [] _ = True
isSubset (x : xs) ys =
  let
    hasElement _ []  res = res
    hasElement x (y : xs) res = hasElement x xs (res || x == y)
  in
    hasElement x ys False && isSubset xs ys

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