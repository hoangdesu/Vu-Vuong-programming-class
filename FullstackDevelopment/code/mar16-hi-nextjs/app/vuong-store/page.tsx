'use client';
import ProductCard from "./ProductCard";

import './store.css';

 // directive

// must use this directive to use react hooks

const products = [
    {
        id: 1,
        name: 'Wooting 60he+ New edition',
        image: 'https://static1.anpoimages.com/wordpress/wp-content/uploads/2024/07/wooting-60-he-product-tag-image.jpg',
        price: 349,
        category: 'keyboard'
    },
    {   
        id: 2,
        name: 'Razer Viper V3 Pro2 2026' ,
        image: 'https://m.media-amazon.com/images/I/61r9g7VtZaL.jpg',
        price: 259,
        category: 'mouse'
    },
    {   
        id: 3,
        name: "Moondrop Kato In-Ear Monitor JUST DROPPED",
        image: 'https://gadgetstudiobd.com/wp-content/uploads/2022/11/Screenshot_1-7-800x800.png',
        price: 265,
        category: 'headphone'
    },
    {   
        id: 4,
        name: 'Flydigi Apex 5',
        image: 'https://flydigi.net/cdn/shop/files/Flydigi-Apex-5_7.jpg?v=1758152259',
        price: 240,
        category: 'controller'
    },
    {
        id: 5,
        name: 'Gamesir Cyclone 2',
        image: 'https://www.gamesir.hk/cdn/shop/files/2_74840206-c007-4f89-9990-ab3e1f70f319.png?v=1731058234&width=360',
        price: 89,
        category: 'controller'
    },
    {
        id: 6,
        name: 'Akko MU01',
        image: 'https://en.akkogear.com/wp-content/uploads/2024/04/MU01-Mountain-Seclusion.png',
        price: 185,
        category: 'keyboard'
    },
    {
        id: 7,
        name: 'Kamvas 13 (Gen 3)',
        image: 'https://store-img.huion.com.cn/e/652/huion-kamvas-13-gen-3-pen-display-01.webp?x-oss-process=image/resize,m_lfit,w_600',
        price: 359,
        category: 'monitor'
    },
    {
        id: 8,
        name: 'ROG Strix XG27UCG',
        image: 'https://dlcdnwebimgs.asus.com/gain/079E19C9-5231-4717-A4ED-CEEFCA7964A8/w717/h525/fwebp',
        price: 700,
        category: 'monitor'
    },
    {
        id: 9,
        name: 'Razer DeathAdder V4 Pro',
        image: "https://cdn.hstatic.net/products/200000722513/imgi_72_deathadder-v4-pro-black_a0935bec304f4233b4bd0b2bb429588a_master.png",
        price: 299.99,
        category: 'mouse'
    }
];

export default function VuongStore() {
    // const randNum = Math.random();
    return (
        <div>
            <h1>Vuong Store</h1>

            {/* Rendering Lists */}

            <h3>Rendering a list</h3>
            {products.map(p => {
                return <p key={p.id}>${p.price} - {p.name}</p>
            })}

            {/* => 
            [
                <p key="Wooting 60he+ New edition">Wooting 60he+ New edition</p>,
                <p key="Razer Viper V3 Pro2 2026">Razer Viper V3 Pro2 2026</p>,
                ...
            ] 
             */}

            <h3>Rendering components</h3>

            <div id="products-container">
                {products.map(product => {
                    return <ProductCard key={product.id} product={product} />
                })}
            </div>

            {/* <ProductCard product={products[0]} randomNum={1} />
            <ProductCard product={products[1]} /> */}

        </div>
    );
}

// JS array methods
// routing: app-router: folder-based routing
