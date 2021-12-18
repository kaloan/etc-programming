-- import           Data.Set

-- data Nat = Nat (Set Set)
--
-- zero :: Nat
-- zero = Nat empty
--
-- suc :: Nat -> Nat
-- suc (Nat x) = Nat $ union x (singleton x)

-- data Nat = Nat Set (Set Nat) deriving (Show, Eq, Ord)
--
-- zero :: Nat
-- zero = Nat empty
--
-- suc :: Nat -> Nat
-- suc (Nat x) = Nat $ union x (singleton x)

-- data Nat = Zero | Set [Nat] deriving (Show)
--
-- zero :: Nat
-- zero = Zero
--
-- suc :: Nat -> Nat
-- suc Zero       = Set [Zero]
-- suc x@(Set xs) = Set $ x : xs
--
-- add :: Nat -> Nat -> Nat
-- add Zero   x        = x
-- add x Zero          = x
-- add (Set []) y      = suc y
-- add (Set (x :xs)) y = add (Set xs) (suc y)

newtype Nat = Set [Nat] deriving (Show, Eq)

zero :: Nat
zero = Set []

suc :: Nat -> Nat
--suc (Set [])       = Set [Zero]
suc x@(Set xs) = Set $ x : xs

one :: Nat
one = suc zero

two :: Nat
two = suc one

add :: Nat -> Nat -> Nat
add (Set []) y      = y
add (Set (x :xs)) y = add (Set xs) (suc y)

mult :: Nat -> Nat -> Nat
mult (Set []) y      = zero
mult (Set (x :xs)) y = add (mult (Set xs) y) y

main :: IO ()
main = do
  print zero
  print one
  print two
  let four = suc $ suc two
  let twoPlusTwo = add two two
  let twoTimesTwo = mult two two
  print $ twoPlusTwo == four
  print $ twoTimesTwo == four
