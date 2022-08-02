type DivisibleWords = [number, string][];

function fizzBuzz(n: number, divisibleWords: DivisibleWords){
    let res = "";
    for (const [num, word] of divisibleWords){
        if (n % num === 0) res  += word + " ";
    }
    return res.trim();
}

const stdFizzWords: DivisibleWords = [[3, "Fizz"], [5, "Buzz"]]; 
console.log(fizzBuzz(3, stdFizzWords));
console.log(fizzBuzz(5, stdFizzWords));
console.log(fizzBuzz(15, stdFizzWords));
console.log(fizzBuzz(4, stdFizzWords));