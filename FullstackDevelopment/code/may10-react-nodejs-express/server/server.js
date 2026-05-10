const express = require('express')
const cors = require('cors')
const app = express()
const port = 3456;

// CORS middleware
app.use(cors());
app.use(express.urlencoded({ extended: true })); // form data

const games = ['hades', 'gi', 'pragmata', 'dota 2'];

// 1. GET /games
// display a simple HTML page:

// Game Library:
//     1. <a href="https://www.google.com/search?q=hades" target="_blank">hades</a>
//     2. link: gi
//     3. link: pragmata

app.get('/games', (req, res) => {
    res.json(games);
});


// 2. POST /games/new
// input: body (JSON String / form url-encoded)
// use Postman to construct body

// input: "league"
// add the game "league" into the games array
// when post successful, return status 201


app.post('/games/new', (req, res) => {
    // const body = req.body;
    
    const { newgame: newGame } = req.body;

    games.push(newGame);

    // res.sendStatus(201);

    // auto client refresh
    res.redirect(req.get('referer'));
    
});


// 3. PUT /games (later)
// e.g. /games/:index/:newGame (replace by index)
// => /games/1/genshinimpact
// e.g. /games/:oldGame/:newGame (replace by value)
// => /games/gi/genshinimpact


// open the server
app.listen(port, () => {
  console.log(`App running at: http://localhost:${port}`)
})

