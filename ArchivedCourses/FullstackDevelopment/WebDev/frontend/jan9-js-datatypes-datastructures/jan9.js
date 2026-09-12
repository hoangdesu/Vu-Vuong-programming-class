// variable: var vs let

// no need var or let or const

// ; optional
x = 1;
console.log(x);


let a = 1;
var b = 100;

if (true) {
    let a = 2;
    var b = 200; // overwrited b
}

console.log(a);
console.log(b);

// Scope: visibility of a variable

const c = 1;
// c = 2;

console.log(c);

// Object
//     - Python: dictionary
//     - Java: HashMap / HashTable


// 'laptop': 'a pc on the go'

// vietnam: ha noi,
// japan: tokyo

// Object: data structure that store data in key-value pairs

const vuong = {
    first: "Vuong",
    last: 'Nguyen',
    middle: 'Vu',
    birthYear: 2005,
    games: ['E33', 'Hades', 'Hollow Knight'],
    food: {
        'break-fast': ['bánh cuốn', 'cơm tấm'],
        'bữa trưa': 'cơm',
        big_dinner: {
            appetizer: 'soup',
            main_course: 'dimsum',
            desert: 'fruits'
        }
    },
    backToVN: false
};

// Access values in an object
console.log(vuong.last) // using dot notation
console.log('age:', 2026 - vuong['birthYear'])
console.log(vuong.games);
console.log('I just played ' + vuong.games[1]);

console.log(vuong.food['break-fast']); // bracket notation
console.log(vuong['food']['bữa trưa']);
console.log(vuong.food.big_dinner.main_course);


vuong.backToVN = !vuong.backToVN // NOT false = true

// vuong = 'Vu Vuong' // error

// Modify values inside an object
vuong.last = 'Nguyễn';
vuong.first = 'Vương';

// Add new entries
// vuong.fullname = vuong.first + ' ' + vuong.last; // string concatenation
vuong.fullname = `${vuong.last} Vũ ${vuong.first}`; // string template literal
vuong.drinks = ['matcha', 'tea'];
vuong.languages = {
    fav: ['js', 'py'],
    not_fav: ['c', 'c++']
};

// console.log(vuong);


console.log('laptop:', vuong.laptop); // undefined
console.log('first' in vuong);
console.log('ps5' in vuong);

// | no | keys  | values
// |  1 | first | 'Vuong'

console.log(Object.keys(vuong)); // get all the keys directly 1 layer below the obj
console.log(Object.values(vuong));

let counter = 1;

console.log('| no | keys\t|values\t|') // header
for (const [key, val] of Object.entries(vuong)) {
    console.log(`|  ${counter} | ${key}\t| ${val}\t|`);
    counter++;
}

let s = 1;
console.log(typeof s);

let t = 3.14;
console.log(typeof(t));

let u = 'u';
console.log(typeof u);

let v = 'this is a string';
console.log(typeof v);

let f = true;
console.log(typeof f);

console.log(typeof vuong.games); // Arrays are also objects in JS

console.log(typeof vuong);

function hi(sbName) {
    console.log(`Sup ${sbName}!!`);
}

hi('Vương');

console.log(typeof hi); // function

console.log(typeof null); // object

console.log(typeof undefined); // undefined




// DOM manipulation
// const obj = document.querySelector('#object');
// obj.innerHTML = vuong.food["break-fast"];





// 'string'
// "string"
// `string`: backtick -> string template literal


