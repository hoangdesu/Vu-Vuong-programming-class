import { useState } from 'react';
import reactLogo from './assets/react.svg';
import viteLogo from './assets/vite.svg';
import heroImg from './assets/hero.png';
import { useEffect } from 'react';
// import './App.css'

function App() {
  // const [count, setCount] = useState(0);

  const [games, setGames] = useState([]);

  // run when component mounted
  useEffect(() => {
    fetch('http://localhost:3456/games')
      .then(res => res.json())
      .then(gameList => {
        console.log(gameList);
        setGames(gameList);
      })
  }, []);


  // let count = 1;

  // chờ
  // useEffect(() => {
  //   console.log(count);
  // }, [count]);

  return (
    <div>
      <h1>Game Library</h1>

      <form method='post' action='http://localhost:3456/games/new'>
        <h2>Add new game</h2>
        <input type="text" name="newgame" />
        <button type='submit'>Add</button>
      </form>

      <ol>
        {games.map((game) => (
          <li key={game}>
            <a href={`https://www.google.com/search?q=${game}`} target='_blank'>
              {game}
            </a>
          </li>
        ))}
      </ol>

      {/* <div>
        <p>Count: {count}</p>
        <button
          onClick={() => {
            setCount(count + 1);
            // console.log(count);
          }}
        >
          Add
        </button>
      </div> */}
    </div>
  );
}

export default App;
