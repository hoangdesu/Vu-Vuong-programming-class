'use client'; // no need if only using react
// default: server component -> client component

import { useEffect, useState } from "react";
import VideoComponent from "./VideoComponent";

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
    
    // khi state thay doi, component se duoc re-render lai hoan toan
    setCount(count + 1); // async data change -> take time
    console.log('count (always lag behind 1 value):', count);
  };

  // display the value of "count" AFTER it has been updated
  useEffect(() => {
    console.log('count AFTER updated: ', count);
  }, [count]);

  console.log('component Home re-rendered');

  // Template (HTML): JSX
  return (
    <div>
      <h1>Hello NextJS</h1>

      <p>Num (pure JS var) = {num}</p>
      <p>Count (state) = {count}</p>

      {/* {}: JS evaluation -> inject data into template */}
      <p>{count % 5 === 0 ? `${count} is divisible by 5` : '...'}</p>

      {/* HTML: onclick */}
      <button>Decrease</button>
      <button onClick={increase}>Increase</button>
      

      {/* Home: parent
        -> VideoComponent: child component */}

      <div>
        {/* passing props to a component */}
        <VideoComponent title="Javascript" views={100} />
        <VideoComponent title="Go lang" views={200} />
        <VideoComponent title="Java" views={300} />
        <VideoComponent 
          title="Learn Python" 
          views={300} 
        />
      </div>
    </div>
  );
}
