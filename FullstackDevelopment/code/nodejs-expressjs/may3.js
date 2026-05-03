const express = require('express')
const app = express()
const port = 3456;

// path params
// GET /add/:a/:b
// e.g: localhost:3456/add/5/9
// return string: "5 + 9 = 14"

// e.g: localhost:3456/add/haha/hehe
// return string "Error: path params a and b must be numbers"

// console.log(isNaN('a')) // true
// console.log(isNaN('1')) // false

// console.log(parseInt('a'))
// console.log(isNaN(parseInt('a')))
// console.log(parseInt('1'))

// if a is nan OR b is nan => error


app.get('/add/:a/:b', (req, res) => {
    // const a = req.params.a;
    // const b = req.params.b;

    const { a, b } = req.params;

    if (isNaN(parseInt(a)) || isNaN(parseInt(b))) return res.status(403).send('Error');

    return res.send(`${a} + ${b} = ${parseInt(a) + parseInt(b)}`)
});


// Query string
// ?key1=val1&key2=val2
// => produce an object:
// {
//     key1: val1,
//     key2: val2
// }


// GET /subtract
// query strings:
//     a: int
//     b: int
// e.g: 
// http://localhost:3456/subtract?b=1&a=2
// http://localhost:3456/subtract?a=2&b=1
// always return a - b
// e.g. 2 - 1 = 1

// validate inputs


// ---

const games = ['hades', 'gi', 'pragmata'];

1. GET /games
display a simple HTML page:

Game Library:
    1. <a href="https://www.google.com/search?q=hades" target="_blank">hades</a>
    2. link: gi
    3. link: pragmata


2. POST /games
input: body (JSON String / form url-encoded)
use Postman to construct body

input: "league"
add the game "league" into the games array
when post successful, return status 201


3. PUT /games (later)
e.g. /games/:index/:newGame (replace by index)
=> /games/1/genshinimpact
e.g. /games/:oldGame/:newGame (replace by value)
=> /games/gi/genshinimpact





// open the server
app.listen(port, () => {
  console.log(`App running at: http://localhost:${port}`)
})



