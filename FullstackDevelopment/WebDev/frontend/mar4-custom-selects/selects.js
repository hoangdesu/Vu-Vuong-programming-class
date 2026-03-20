const priceButtons = document.querySelectorAll('.btn-price'); 
// > returns a list of matched elements

// console.log(priceButtons); // list

// const oneDollarButton = priceButtons[0];

// console.log('classList:', oneDollarButton.classList);
// console.log('className', oneDollarButton.className);

// priceButtons[1].classList.add('selected');
// setTimeout(() => {
//     priceButtons[1].classList.remove('selected');
//     priceButtons[2].classList.add('selected');
// }, 2000);




// for (let i = 0; i < ...; i++)
// for (const eachElement in elementList)
// elementList.forEach(eachElement => {...}) => list method

let selectedButton = null;

priceButtons.forEach(btn => {
    btn.addEventListener('click', () => {
        // console.log('clicked');

        // caching the last selected button
        // if (selectedButton) {
        //     selectedButton.classList.remove('selected');
        // }

        // btn.classList.add('selected');
        // selectedButton = btn;


        // reset all styles
        priceButtons.forEach(btn1 => {
            btn1.classList.remove('selected');
        });

        btn.classList.add('selected');

    });
});

