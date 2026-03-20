console.log('hello from main.js');

const products = [
    {
        name: 'Wooting 60he+',
        image: 'https://static1.anpoimages.com/wordpress/wp-content/uploads/2024/07/wooting-60-he-product-tag-image.jpg',
        price: 349,
        category: 'keyboard'
    },
    {   
        name: 'Razer Viper V3 Pro' ,
        image: 'https://m.media-amazon.com/images/I/61r9g7VtZaL.jpg',
        price: 259,
        category: 'mouse'
    },
    {   
        name: "Moondrop Kato In-Ear Monitor",
        image: 'https://gadgetstudiobd.com/wp-content/uploads/2022/11/Screenshot_1-7-800x800.png',
        price: 265,
        category: 'headphone'
    },
    {   
        name: 'Flydigi Apex 5',
        image: 'https://flydigi.net/cdn/shop/files/Flydigi-Apex-5_7.jpg?v=1758152259',
        price: 240,
        category: 'controller'
    },
    {
        name: 'Gamesir Cyclone 2',
        image: 'https://www.gamesir.hk/cdn/shop/files/2_74840206-c007-4f89-9990-ab3e1f70f319.png?v=1731058234&width=360',
        price: 89,
        category: 'controller'
    },
    {
        name: 'Akko MU01',
        image: 'https://en.akkogear.com/wp-content/uploads/2024/04/MU01-Mountain-Seclusion.png',
        price: 185,
        category: 'keyboard'
    },
    {
        name: 'Kamvas 13 (Gen 3)',
        image: 'https://store-img.huion.com.cn/e/652/huion-kamvas-13-gen-3-pen-display-01.webp?x-oss-process=image/resize,m_lfit,w_600',
        price: 359,
        category: 'monitor'
    },
    {
        name: 'ROG Strix XG27UCG',
        image: 'https://dlcdnwebimgs.asus.com/gain/079E19C9-5231-4717-A4ED-CEEFCA7964A8/w717/h525/fwebp',
        price: 700,
        category: 'monitor'
    },
    {
        name: 'Razer DeathAdder V4 Pro',
        image: "https://cdn.hstatic.net/products/200000722513/imgi_72_deathadder-v4-pro-black_a0935bec304f4233b4bd0b2bb429588a_master.png",
        price: 299.99,
        category: 'mouse'
    }
];


// DOM manipulation
// DOM: Document Object Model


// Dynamic rendering
const productsContainer = document.querySelector('#products-container');

// this render runs on initial load => no need to reset because productsContainer.innerHTML == '';

// traditional for-loop
// for (let i = 0; i < products.length; i++) {
    // const product = products[i];

// for ... of
for (const product of products) {

    // build html template
    const productCardHtml = `
        <div class="product-card">
            <img src="${product.image}" alt="${product.name}">
            <h2>${product.name}</h2>
            <p>$${product.price}</p>
        </div>
    `;

    // modify container's original html
    productsContainer.innerHTML += productCardHtml;

    // 'single-quote ${}'
    // "double-quote ${}"
    // `string-template literal ${}`
}


// const searchBtn = document.getElementById('search-btn') // no need # for id
// console.log(searchBtn);

// new method
const searchForm = document.querySelector('#search-form'); // #id
const searchInput = document.querySelector('#search-input'); // 


// document.querySelector('#id')
// document.querySelector('.class')
// document.querySelector('element')


// form's event 'submit' include 2 other events:
//     - input's enter button
//     - search button onClick

// callback function:

searchForm.addEventListener('submit', (event) => {
    // prevent the form's default behavior of page reloading when submit
    event.preventDefault();

    // console.log('submitting the form...');

    // extract the search query from the input box
    // console.log('searching...', searchInput.value);
    const searchQuery = searchInput.value;


    // early return to catch special cases -> stop this function
    if (!searchQuery) {
        alert('Nothing to search!');
        return;
    }


    // compare search query to the names we have inside each object in the products array
    // using linear search algorithm    
    // let foundProduct = null;

    const foundProducts = [];

    for (const product of products) {
        // exact match -> not gonna work
        // if (searchQuery === product.name) {

        // partially match:
        // is searchQuery a substring of product.name?
        // must check both of them in the lowercase version
        if (product.name.toLowerCase().includes(searchQuery.toLowerCase())) {
            // console.log('Found:', product.name);
            // foundProduct = product; // this approach can only find 1 single product
            // break;

            foundProducts.push(product);
        } 
    }

    if (foundProducts.length > 0) {
        console.log('Found:', foundProducts);

        // Reflect changes back to UI / re-render the screen

        // clear the current products container
        productsContainer.innerHTML = '';

        for (const product of foundProducts) {

            // build html template
            const productCardHtml = `
                <div class="product-card">
                    <img src="${product.image}" alt="${product.name}">
                    <h2>${product.name}</h2>
                    <p>$${product.price}</p>
                </div>
            `;

            // modify container's original html
            productsContainer.innerHTML += productCardHtml;
        }

    } else {
        console.log('NOT found:', searchQuery);
        productsContainer.innerHTML = 'Nothing found...';
    }
    
    // clear search input
    // searchInput.value = '';
});


const title = document.querySelector('#title');
title.addEventListener('click', () => {
    // reset products container
    productsContainer.innerHTML = '';

    for (const product of products) {
        // build html template
        const productCardHtml = `
            <div class="product-card">
                <img src="${product.image}" alt="${product.name}">
                <h2>${product.name}</h2>
                <p>$${product.price}</p>
            </div>
        `;

        // modify container's original html
        productsContainer.innerHTML += productCardHtml;
    }

    // clear search input
    searchInput.value = '';
});


// let s1 = 'Gamesir Controller Cyclone 2'
// let s2 = 'Cycl'

// ? Check if s2 is a substring of s1


// Filters
const lowRangeSlider = document.querySelector('#low-range-slider');
const lowRangeOutput = document.querySelector('#low-range-output');

// input: 'change' vs 'input'
lowRangeSlider.addEventListener('input', (evt) => {
    // console.log('low range slider:', evt.target.value);
    lowRangeOutput.textContent = `Low: $${evt.target.value}`;
});


const highRangeSlider = document.querySelector('#high-range-slider');
const highRangeOutput = document.querySelector('#high-range-output');

highRangeSlider.addEventListener('input', (evt) => {
    // console.log('low range slider:', evt.target.value);
    highRangeOutput.textContent = `High: $${evt.target.value}`;
});


const priceFilterBtn = document.querySelector('#price-filter-btn');


// binding a function to an event
// - using addEventListener('click'): priceFilterBtn.addEventListener('click', () => {});
// - using .onclick attribute


priceFilterBtn.onclick = () => {
    // console.log('filtering...');

    const lowRange = parseFloat(lowRangeSlider.value); // str -> float (number)
    console.log('low range:', lowRange);
    
    // numbers will have blue color in browser console
    // console.log(123);
    // console.log(3.14);

    const highRange = Number(highRangeSlider.value); // str -> number
    console.log('high range:', highRange);
    
    // using array method. similar to for ... of
    // const filteredProducts = [];
    // products.forEach((prod) => {
    //     if (prod.price >= lowRange && prod.price <= highRange) {
    //         // console.log(`$${prod.price} - ${prod.name}`);
    //         filteredProducts.push(prod);
    //     }
    // });


    // using filter method
    const filteredProducts = products.filter(prod => prod.price >= lowRange && prod.price <= highRange);


    // update UI on the screen
    // reset products container
    productsContainer.innerHTML = '';

    for (const product of filteredProducts) {
        // build html template
        const productCardHtml = `
            <div class="product-card">
                <img src="${product.image}" alt="${product.name}">
                <h2>${product.name}</h2>
                <p>$${product.price}</p>
            </div>
        `;

        // cannot add event listener on a string
        // productCardHtml.addEventListener('click', () => {
        //     console.log('clicked on product card');
        // });

        // modify container's original html
        productsContainer.innerHTML += productCardHtml;
    }
};


// Dynamically render the category buttons
const categoriesFilters = document.querySelector('#category-filters');

const existedCategories = [];

products.forEach(prod => {
    if (!existedCategories.includes(prod.category)) {
        // remember the category that has appeared
        existedCategories.push(prod.category);

        // create element to show that category
        const categoryBtn = document.createElement('button');
        categoryBtn.textContent = prod.category;

        categoryBtn.addEventListener('click', () => {
            console.log(prod.category);

            const filteredProducts = products.filter(filteringProd => prod.category === filteringProd.category);
            console.log(filteredProducts);
            
            productsContainer.innerHTML = '';

            for (const product of filteredProducts) {
                // build html template
                const productCardHtml = `
                    <div class="product-card">
                        <img src="${product.image}" alt="${product.name}">
                        <h2>${product.name}</h2>
                        <p>$${product.price}</p>
                    </div>
                `;

                // modify container's original html
                productsContainer.innerHTML += productCardHtml;
            }
        });      

        categoriesFilters.append(categoryBtn);
    }
});



// Callback function

const btnClickme = document.querySelector('#btn-clickme');


// btnClickme.addEventListener('click', () => {
//     alert('Sup!')
// });

// function onBtnClickmeClicked() {
//     const name = prompt('Wats yo name doug');
//     alert(`Sup ${name}!`);
// }

// only pass in callback function / function reference
// btnClickme.addEventListener('click', onBtnClickmeClicked); // click -> onBtnClickmeClicked()


// arrow function === annonymous function === lambda function

btnClickme.addEventListener('click', () => {
    const name = prompt('Wats yo name doug');
    alert(`Sup ${name}!`);
});


// giao bai tap () {
//     1. bài A
//     2. bài C 
// }

// lesson ends -> lam bai tap
// khi có time => lam bai tap ()

// vuong.addEventListener('free time', doHomework);
