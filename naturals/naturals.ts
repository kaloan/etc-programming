interface Nat {
    zero?: "0";
    suc?: Nat;
}

const zero : Nat = {zero: "0"};
const one : Nat = {suc : zero}
const two : Nat = {suc : one}
console.log(zero);
console.log(one);
console.log(two);


type  ONat = {
    zero : "0";
    suc?: never;
} | {
    zero?: never; 
    suc: ONat;
}

const ozero : ONat = {zero: "0"};
const oone : ONat = {suc : ozero}
const otwo : ONat = {suc : oone}
console.log(ozero);
console.log(oone);
console.log(otwo);

function plusOne(num: ONat) : ONat{
    return {suc : num};
}

function add(num1: ONat, num2: ONat) : ONat{
    if(num1.zero !== undefined) return num2;
    //if(num2.zero !== undefined) return num1;
    return {suc : add(num1.suc, num2)};
}

function leq(num1: ONat, num2: ONat) : boolean {
    if(num1.zero !== undefined) return true;
    if(num2.zero !== undefined) return false;
    return leq(num1.suc, num2.suc);
}

function eq(num1: ONat, num2: ONat) : boolean {
    if(num1.zero !== undefined) {
        if(num2.zero !== undefined) return true;
        return false;
    }
    if(num2.zero !== undefined) return false;
    return eq(num1.suc, num2.suc);
}

function addCommut(num1: ONat, num2: ONat) : boolean {
    if(num1.zero !== undefined) return (eq(add(num1, num2), add(num2, num1)));
    if(num2.zero !== undefined) return (eq(add(num1, num2), add(num2, num1)));
    else return addCommut(num1.suc, plusOne(num2));
}

console.log(plusOne(ozero));
console.log(add(otwo, oone));
console.log(leq(otwo, oone));
console.log(leq(oone, otwo));
console.log(eq(otwo, oone));
console.log(eq(otwo, otwo));
console.log(addCommut(oone, ozero));

