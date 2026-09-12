import { useEffect, useState } from 'react'
import reactLogo from './assets/react.svg'
import viteLogo from '/vite.svg'
// import './App.css'

// jsx: js extensive / TS -> JS

function App() {
  // state variable: WILL trigger re-render when state changes
  // React hooks: functions to trigger UI re-render
  // use...

  const [count, setCount] = useState(0);

  // pure variable -> will NOT trigger re-render to update new UI
  // let num = 1;

  const increase = () => {
    // num++
    // console.log(num);

    setCount(count+1); // async
    console.log('chậm 1 count:', count);
    
  }


  useEffect(() => {
    console.log('current count:', count);
  }, [count]);


  return (
    <div>
      <h1>Hello React</h1>

      <p>Counter: {count}</p>

      <button onClick={increase}>Increase</button>
    </div>
  )
}

export default App
