findMaxSumEnds :: (Num a, Ord a) => [a] -> [(a, (Integer, Integer))]
findMaxSumEnds = scanl go (0, (-1, -1))
	where
		go (oldMax, (st, oldIndex)) x =
			if oldMax > 0
			then (x + oldMax, (st, succ oldIndex))
			else (x, (succ oldIndex, succ oldIndex))

main :: IO()
main = do
	let a = [1,5,-12,2,8,19,-5,6]
	let maxDiff = maximum $ findMaxSumEnds a
	print $ "Max diff is: " ++ (show $ fst maxDiff) ++ ", from " ++ (show $ fst $ snd maxDiff) ++ " to " ++ (show $ snd $ snd maxDiff) 
	