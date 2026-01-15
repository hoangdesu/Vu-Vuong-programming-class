console.log('hello from main.js');

const products = [
    {
        name: 'Wooting 60he+',
        image: 'https://static1.anpoimages.com/wordpress/wp-content/uploads/2024/07/wooting-60-he-product-tag-image.jpg',
        price: 349
    },
    {   
        name: 'Razer Viper V3 Pro' ,
        image: 'https://m.media-amazon.com/images/I/61r9g7VtZaL.jpg',
        price: 259
    },
    {   
        name: "Moondrop Kato In-Ear Monitor",
        image: 'https://gadgetstudiobd.com/wp-content/uploads/2022/11/Screenshot_1-7-800x800.png',
        price: 265
    },
    {   
        name: 'Flydigi Apex 5',
        image: 'https://flydigi.net/cdn/shop/files/Flydigi-Apex-5_7.jpg?v=1758152259',
        price: 240
    },
    {
        name: 'Gamesir Cyclone 2',
        image: 'https://www.gamesir.hk/cdn/shop/files/2_74840206-c007-4f89-9990-ab3e1f70f319.png?v=1731058234&width=360',
        price: 89
    },
    {
        name: 'Akko MU01',
        image: 'https://en.akkogear.com/wp-content/uploads/2024/04/MU01-Mountain-Seclusion.png',
        price: 185
    },
    {
        name: 'Kamvas 13 (Gen 3)',
        image: 'https://store-img.huion.com.cn/e/652/huion-kamvas-13-gen-3-pen-display-01.webp?x-oss-process=image/resize,m_lfit,w_600',
        price: 359
    },
    {
        name: 'ROG Strix XG27UCG',
        image: 'https://dlcdnwebimgs.asus.com/gain/079E19C9-5231-4717-A4ED-CEEFCA7964A8/w717/h525/fwebp',
        price: 700
    },
    {
        name: "Razer DeathAdder V4 Pro",
        image: "https://cdn.hstatic.net/products/200000722513/imgi_72_deathadder-v4-pro-black_a0935bec304f4233b4bd0b2bb429588a_master.png",
        price: 299.99
    }
];


// DOM manipulation
// DOM: Document Object Model



// Dynamic rendering
const productsContainer = document.querySelector('#products-container');

// this render runs on initial load => no need to reset because productsContainer.innerHTML == '';

// for ... of
for (const product of products) {
// for (let i = 0; i < products.length; i++) {
    // const product = products[i];

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