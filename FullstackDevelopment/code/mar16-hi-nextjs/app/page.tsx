'use client';
import { useState } from "react";

 // no need if only using react

export default function Home() {

  // pure JS var -> only update inside memory => will NOT re-render on screen
  let num = 1;

  // React hook: useState
  // state: same as variable, but WILL trigger re-render when state changes
  // use + ... : useEffect, useCallback

  // useState -> state + state update function
  // js array destructuring to pull out 2 values

  const [count, setCount] = useState(1); // default value


  const increase = () => {
    num++;
    console.log('num = ', num);

    setCount(count + 1);
    console.log('count (always lag behind 1 value):', count);
  };

  return (
    <div>
      <h1>Hello NextJS</h1>

      <p>Num (pure JS var) = {num}</p>
      <p>Count (state) = {count}</p>

      {/* {}: JS evaluation -> inject data into template */}
      <p>{count % 5 === 0 ? `${count} is divisible by 5` : '...'}</p>

      <button onClick={increase}>Increase</button>
    </div>
  );
}
