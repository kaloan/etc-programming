type Nat = "0" | {suc: Nat}

const zero : Nat = "0"
const one : Nat = {suc: zero}
const two : Nat = {suc: one}

const z : {a: 4} = {a: 4}

function plusOne(num: Nat) : Nat {
    return {suc : num};
}

function add(num1: Nat, num2: Nat) : Nat {
    if(num1 == "0") return num2;
    //if(num2 == "0") return num1;
    return {suc : add(num1.suc, num2)};
}

function printPrev(num: Nat) : void {
    switch(num){
        case "0": 
            console.log(""); 
            return;
        default: console.log(`${num.suc}`);
		//Can't deconstruct in switch-case :(
        //case {suc: prev}: console.log(`${prev}`);
    }
}

printPrev(zero);
printPrev(one);
console.log(add(two, one))

//Meme
//const zero = "0"
//const one = `suc ${zero}`
//const two = `suc ${one}`