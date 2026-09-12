import { useState } from 'react';
import reactLogo from './assets/react.svg';
import viteLogo from './assets/vite.svg';
import heroImg from './assets/hero.png';
import { useEffect } from 'react';
// import './App.css'

function App() {
  // const [count, setCount] = useState(0);

  const [games, setGames] = useState([]);
  const [newGame, setNewGame] = useState('');

  // const games = ['hades', 'gi', 'pragmata', 'dota 2'];

  // run when component mounted
  useEffect(() => {
    fetch('http://localhost:3456/games')
      .then((res) => res.json())
      .then((gameList) => {
        console.log(gameList);
        setGames(gameList);
      })
      .catch((err) => {
        // display error to user
      });
  }, []);

  // let count = 1;

  // chờ
  // useEffect(() => {
  //   console.log(count);
  // }, [count]);

  // on form submit:
  //   fetch('ENDPOINT', {
  //     body: {

  //     },
  //     method: 'POST'
  //   })

  const onDeleteButtonClicked = (index) => {
    console.log('deleting...', index);

    fetch(`http://localhost:3456/games/${index}`, {
      method: 'delete',
    })
      .then((res) => {
        console.log(res);
        if (res.ok) {
          window.location.reload();
        }
      })
      .catch((err) => {});
  };

  const onNewGameSaved = (index) => {
    console.log('save...', index, newGame);

    if (!newGame) return;

    fetch('http://localhost:3456/games', {
      method: 'put',
      headers: {
        'Content-Type': 'application/json',
      },
      // body: {
      //   // index: index,
      //   // newGame: newGame

      //   index,
      //   newGame
      // }

      body: JSON.stringify({ index, newGame }),
    })
      .then((res) => {
        console.log(res);

        if (res.ok) {
          window.location.reload();
        }

        // res.json().then(data => console.log(data))
      })
      .catch((err) => {});
  };

  return (
    <div>
      <h1>Game Library</h1>

      <form method='post' action='http://localhost:3456/games/new'>
        <h2>Add new game</h2>
        <input type='text' name='newgame' />
        <button>Add</button>
      </form>

      <table>
        <tbody>
          {games.map((game, index) => (
            // <li key={game}>
            //   <a href={`https://www.google.com/search?q=${game}`} target='_blank'>
            //     {game}
            //   </a>

            //   {/* pass FUNCTION REFERENCE into ONCLICK */}
            //   <span style={{marginLeft: '16px'}} >
            //     <button onClick={() => onDeleteButtonClicked(index)}>Delete</button>
            //     <button>Edit</button>
            //   </span>

            //   {/* onWork={makeSushi}
            //   onWork={makeSushi()} */}
            // </li>

            // <TableRow game index />
            <tr key={game.id}>
              <td>{game.id}</td>
              <td>
                <a
                  href={`https://www.google.com/search?q=${game}`}
                  target='_blank'
                >
                  {game.name}
                </a>
              </td>
              <td>{game.rating}</td>
              <td>
                <button onClick={() => onDeleteButtonClicked(index)}>
                  Delete
                </button>
              </td>
              <td>
                {/* controlled component: 2-way binding */}
                <input
                  type='text'
                  placeholder='New name...'
                  value={newGame}
                  onChange={(evt) => setNewGame(evt.target.value)}
                />
              </td>
              <td>
                <button onClick={() => onNewGameSaved(index)}>Save</button>
              </td>
              
              {/* => <EditForm key={key} index={index} /> */}
            </tr>
          ))}
        </tbody>
      </table>

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
