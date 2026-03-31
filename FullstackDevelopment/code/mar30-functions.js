// Implicit return vs Explicit

// Traditional *
function add(a, b) {
    // console.log(a + b);
    return a + b;
}

console.log(add(2, 3));

let c = add(1, 2); // c contains the return value of add() function
console.log('2 c = ', c * 2)
console.log(add(5, 4));


// Arrow function **
// Explicit: include the "return" keyword in the function
// no need () for 1 param
const times2 = a => {
    // return 123456;
    return a * 2;
}

console.log(times2(4));

// Implicit return: no need to include the "return" keyword
const times2_implicit = a => a * 2;
console.log('times 2 implicit return:', times2_implicit(8));


const multiply_implicit = (a, b) => (a * b);
console.log(multiply_implicit(4, 5)); // 20


// function expression
// times2_expression = num => {
//     ...
// }
const times2_expression = function(num) {
    return num * 2;
}

console.log(times2_expression(5));






