const counter = document.querySelector('#counter');
const btnIncrease = document.querySelector('#btn-increase');

let num = 1;

btnIncrease.addEventListener('click', () => {
    num++;
    console.log(num);
    
    // re-render UI
    counter.textContent = num;
});
