--import Data.HashMap
import qualified Data.Set as Set
import Data.Natural

atLeastLength :: [a] -> Natural -> Bool
atLeastLength xs 0 = True
atLeastLength [] len = False
atLeastLength (x:xs) len = atLeastLength xs (monus len 1)


checkForConjugates :: (Num a, Ord a) => [a] -> a -> Bool
--O(1)
checkForConjugates l m = atLeastLength haveConjugates 2
	where 
		--O(n log(n))
		hashed = Set.fromList l
		--O(n log(n))
		haveConjugates = filter (\x -> Set.member (m - x) hashed) l

main = do 
  let l = [-15, 12, 8, 2]
  let m = -1
  print $ checkForConjugates l m