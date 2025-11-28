console.log('hehe');

// 2 basic steps:
//     1. select the element
//     2. add event listener to the selected element

let counter = 1;

// 1.
const plusBtn = document.querySelector('#plus-btn');
const num = document.querySelector('#num');
const minusBtn = document.querySelector('#minus-btn');

// console.log(plusBtn);

// initial render
num.textContent = counter;

// 2.
plusBtn.addEventListener('click', () => {
    console.log('clicked on + button');
    
    counter++;
    console.log('new counter', counter);
    
    // re-render on the screen
    num.textContent = counter;

    if (counter === 1) {
        minusBtn.disabled = false;
    }
});


minusBtn.addEventListener('mouseleave', () => {
    // if (counter > 0) {
    //     counter--;
    //     num.textContent = counter;
    // }

    counter--;
    num.textContent = counter;

    if (counter === 0) {
        minusBtn.disabled = true;
    }
});
