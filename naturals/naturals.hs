data Nat = Zero | Suc Nat

eq :: Nat -> Nat -> Bool
eq Zero Zero = True
eq Zero (Suc m) = False
eq (Suc n) Zero = False
eq (Suc n) (Suc m) = eq n m

leq :: Nat -> Nat -> Bool
leq Zero _ = True
leq _ Zero = False
leq (Suc n) (Suc m) = leq n m

plusOne :: Nat -> Nat
plusOne n = Suc n

add :: Nat -> Nat -> Nat
add Zero m = m
add n Zero = n
add n (Suc m) = add (Suc n) m

mult :: Nat -> Nat -> Nat
mult Zero _ = Zero
mult _ Zero = Zero
mult n (Suc m) = add n (mult n m) 

showsNat :: Nat -> String -> String
showsNat Zero s = show $ s ++ "zero"
showsNat (Suc n) s = showsNat n (s ++ "suc ")

instance Show Nat where
	showsPrec _ n = showsNat n
	
zero :: Nat
zero = Zero

one :: Nat
one = Suc zero

two :: Nat
two = Suc one