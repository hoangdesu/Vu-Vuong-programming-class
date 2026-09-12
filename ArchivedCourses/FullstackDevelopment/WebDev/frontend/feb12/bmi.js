let num = 5.56789;
let n = num.toFixed(1);
console.log(n);


let currentWeight = 60;
let healthyWeight = 75;
let difference = currentWeight - healthyWeight // 5


let adviceMessage = `${healthyWeight > currentWeight ? 'Gain' : 'Lose'} ${Math.abs(difference)} kg to stay healthy`;
// adviceMessage.textContent = ...
console.log(adviceMessage);

