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
];


// DOM manipulation
// DOM: Document Object Model


// Dynamic rendering
const productsContainer = document.querySelector('#products-container');

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


// TODO
// const searchBtn = document.getElementById('search-btn') // no need # for id

// new method
const searchBtn = document.querySelector('#search-btn'); // #id

// document.querySelector('#id')
// document.querySelector('.class')
// document.querySelector('element')


console.log(searchBtn);
