import { useState } from 'react'
import reactLogo from './assets/react.svg'
import viteLogo from './assets/vite.svg'
import heroImg from './assets/hero.png'
// import './App.css'

// Components
// - functions return JSX

function App() {
  const [count, setCount] = useState(0)
  
  let name = 'Vuong';

  // HTML template
  return (
    <>
      <h1>Hello {name}</h1>
      <button onClick={() => alert('hey wassupppp')}>Click me</button>

      <form action="">
        <label htmlFor="">Username</label>
        <input type="text" />
        <label htmlFor="">Password</label>
        <input type="password" />

      </form>

    </>
  )
}

export default App
