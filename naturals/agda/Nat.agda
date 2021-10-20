module Lib.Nat where

open import Lib.Eq
open import Lib.Zero
open import Lib.One
open import Lib.Sum

data Nat : Set where
  zero : Nat -- zero
  suc : Nat -> Nat -- 1+

-- allows us to write literals
-- also means that Nat will compile to Integer in hs
{-# BUILTIN NATURAL Nat #-}

_+N_ : Nat -> Nat -> Nat
zero +N m = m
suc n +N m = suc (n +N m)

infixr 15 _+N_

+N-right-zero : (n : Nat) -> n +N 0 == n
+N-right-zero zero = refl
+N-right-zero (suc n') = ap suc (+N-right-zero n')

+N-assoc : (n m k : Nat) -> (n +N m) +N k == n +N (m +N k)
+N-assoc zero m k = refl
+N-assoc (suc n) m k rewrite +N-assoc n m k = refl

data _<=_ : Nat -> Nat -> Set where
  ozero : {n : Nat} -> 0 <= n
  osuc : {n m : Nat} -> n <= m -> suc n <= suc m

infix 9 _<=_

<=-refl : (n : Nat) -> n <= n
<=-refl zero = ozero
<=-refl (suc x) = osuc (<=-refl x)

<=-trans : {n m k : Nat} -> n <= m -> m <= k -> n <= k
<=-trans ozero q = ozero
<=-trans (osuc p) (osuc q) = osuc (<=-trans p q)

<=-suc : (n : Nat) -> n <= suc n
<=-suc zero = ozero
<=-suc (suc n) = osuc (<=-suc n)

+N-right-suc : (n m : Nat) -> n +N suc m == suc (n +N m)
+N-right-suc zero m = refl
+N-right-suc (suc n) m = ap suc (+N-right-suc n m)

+N-commut : (n m : Nat) -> n +N m == m +N n
+N-commut zero m = ==-symm (+N-right-zero m)
+N-commut (suc n) m rewrite (+N-commut n m) = ==-symm (+N-right-suc m n)


<=-monoR-+N : (n m : Nat) -> n <= n +N m
<=-monoR-+N zero m = ozero
<=-monoR-+N (suc n) m = osuc (<=-monoR-+N n m)

<=-monoL-+N : (n m : Nat) -> n <= m +N n
<=-monoL-+N n m rewrite +N-commut m n = <=-monoR-+N n m

Lt : Nat -> Nat -> Set
Lt n zero = Zero
Lt zero (suc m) = One
Lt (suc n) (suc m) = Lt n m

even : Nat -> Set
even zero = One
even (suc zero) = Zero
even (suc (suc n)) = even n

odd : Nat -> Set
odd zero = Zero
odd (suc zero) = One
odd (suc (suc n)) = odd n

even-or-odd : (n : Nat) -> even n + odd n
even-or-odd zero = inl <>
even-or-odd (suc zero) = inr <>
even-or-odd (suc (suc n)) with even-or-odd n
... | inl n-even = inl n-even
... | inr n-odd = inr n-odd
