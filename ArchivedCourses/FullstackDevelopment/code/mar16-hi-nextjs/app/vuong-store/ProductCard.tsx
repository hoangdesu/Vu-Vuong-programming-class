'use client';

import { useState } from 'react';

export default function ProductCard(props) {
  //   JS object destructuring
  // props.product or props.randomNum
  const { product } = props;

  //   internal & separated state
  const [addedToCart, setAddedToCart] = useState(false);

  //   onBtnAddToCartClickHandler
  const onAddToCartButtonClicked = () => {
      // addedToCart = true; // wrong
    setAddedToCart(!addedToCart);
  };

  return (
    // <div key={props.product.id}>
    //   <img src={props.product.image} alt='' />
    //   <p>{props.product.name}</p>
    //   <p>${props.product.price}</p>

    //   <p>Random num: {props.randomNum}</p>
    // </div>

    <div className='product-card'>
      <img src={product.image} alt={product.name} />
      <p>{props.name}</p>
      <p>${product.price}</p>

      {/* <p>Random num: {randomNum}</p> */}

      <button onClick={onAddToCartButtonClicked}>
        {addedToCart ? 'Added to cart!! ✅' : 'Add to cart 🛒'}
      </button>
    </div>
  );
}

// params: inputs for a function
// props: inputs for a component

// conditional rendering
// ternary

