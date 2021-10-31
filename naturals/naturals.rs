// Does not work due to referencing local values in functions
/*use std::fmt;

#[derive(Eq, Clone, Copy)]
enum Nat<'a> {
    Zero,
    Suc(&'a Nat<'a>)
}

impl PartialEq for Nat<'_> {
    fn eq<'a>(&self, other: &'a Nat<'_>) -> bool {
        match (*self, other) {
            (Nat::Zero, Nat::Zero) => true,
            (Nat::Zero, Nat::Suc(_)) => false,
            (Nat::Suc(_), Nat::Zero) => false,
            (Nat::Suc(ref l), Nat::Suc(ref r)) => l == r,
        }
    }
}

impl fmt::Display for Nat<'_> {
    fn fmt<'a>(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        match *self {
            Nat::Zero => write!(f, "zero"),
            Nat::Suc(ref p) => write!(f, "suc {}", p),
        }
    }
}

fn addOne<'a>(n: &'a Nat<'_>) -> Nat<'a>{
    return Nat::Suc(&n);
}

fn add<'a>(n: &'a Nat<'_>, m: &'a Nat<'_>) -> Nat<'a>{
    match n {
        Nat::Zero => *m,
        Nat::Suc(ref p) => add(p, &addOne(&m)),
    }
}

fn main() {
    let zero = Nat::Zero;
    let one = Nat::Suc(&zero);
    println!("{}", zero);
    println!("{}", one);
    println!("{}", addOne(&zero));
    println!("{}", one == addOne(&zero));
}*/

use std::fmt;
use std::boxed::Box;

#[derive(Eq, Clone)]
enum Nat {
    Zero,
    Suc(Box<Nat>)
}

impl fmt::Display for Nat {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        match *self {
            Nat::Zero => write!(f, "zero"),
            Nat::Suc(ref p) => write!(f, "suc {}", p),
        }
    }
}

impl PartialEq for Nat {
    fn eq(&self, other: &Nat) -> bool {
        match (self, other) {
            (Nat::Zero, Nat::Zero) => true,
            (Nat::Zero, Nat::Suc(_)) => false,
            (Nat::Suc(_), Nat::Zero) => false,
            (Nat::Suc(ref l), Nat::Suc(ref r)) => l == r,
        }
    }
}

fn leq(n: &Nat, m: &Nat) -> bool {
    match (n, m) {
        (Nat::Zero, _) => true,
        (Nat::Suc(_), Nat::Zero) => false,
        (Nat::Suc(ref l), Nat::Suc(ref r)) => leq(l, r),
    }
}

fn addOne(n: &Nat) -> Nat{
    return Nat::Suc(Box::new(n.clone()));
}

fn add(n: &Nat, m: &Nat) -> Nat {
    match n {
        Nat::Zero => m.clone(),
        Nat::Suc(ref p) => Nat::Suc(Box::new(add(p, m))),
    }
}

fn mult(n: &Nat, m: &Nat) -> Nat {
    match n {
        Nat::Zero => Nat::Zero,
        //Nat::Suc(Box<Nat::Zero>) => m.clone(),
        Nat::Suc(ref p) => add(&m, &mult(p, m)),
    }
}

fn main() {
    let zero = Nat::Zero;
    let one = Nat::Suc(Box::new(zero.clone()));
    let two = Nat::Suc(Box::new(one.clone()));
    
    println!("Zero: {}", zero);
    println!("One: {}", one);
    println!("Two: {}", two);
    
    println!("0+1 = {}", addOne(&zero));
    println!("1 == 0+1? {}", one == addOne(&zero));
    println!("2 == 1+1? {}", two == add(&one, &one));
    println!("2 >= 1? {}", leq(&two, &one));

    println!("2*2 = {}", mult(&two, &two));
    println!("1 <= 2*2? {}", leq(&two, &one));
}
