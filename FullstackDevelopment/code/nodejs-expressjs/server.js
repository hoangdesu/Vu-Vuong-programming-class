const express = require('express')
const app = express()
const port = 3456

// route controller (handler)
app.get('/', (req, res) => {
  res.send('Hello ExpressJS and NodeJs! =D')
})


// Endpoints
app.get('/haha', (req, res) => {
    res.send('hahahahahhaa =))')
})


// https://www.youtube.com/watch?v=8mZbovnKCyE
// https://www.youtube.com/watch?v=MX4ADgHU2mo


const menu = ['pho', 'hu tiu', 'com tam', 'xiu mai', 'dim sum'];

app.get('/menu', (req, res) => {
    const foodList = menu.map((food, index) => `
        <li>
            <a href="${index+1}">${food}</a>
        </li>`
    );

    // server-side rendering
    const html = `
        <html>
            <body>
                <h1>Menu</h1>
                <ol>
                    ${foodList.join('')}
                </ol>
            </body
        </html>`;

    // res.send(menu);
    res.send(html);
    // res.json(menu);

    // res.send(menu.join()); // flexible

    // res.json(menu.join());
});


// dynamic routing
app.get('/menu/:foodNum', (req, res) => {
    const foodNum = req.params.foodNum; // path param
    const food = menu[foodNum - 1];

    // console.log(food);

    // breakpoints
    if (!food) {
        return res.send('Invalid food number');
    }
    
    return res.send(food);
    // res.html
    // res.json
});


// Query string
// https://www.youtube.com/results?search_query=nodejs

// https://youtu.be/ENrzD9HAZK4?
//     si=DBrzrn8l-85gljaB & 
//     t=263

app.get('/hello', (request, response) => {
    // response.send(request.query);

    const { country, age, name } = request.query;

    response.send(`Hi my name is ${name}, I am ${age} and I am living in ${country}`);
});


// Search
app.get('/search-food', (req, res) => {
    const { foodname } = req.query;

    if (!foodname) return res.send('Missing food name');

    if (menu.indexOf(foodname) === -1) {
        return res.send(`Sorry we don't have ${foodname}... :(`);
    }

    return res.send(`We have ${foodname} :D`);
});


// open the server
app.listen(port, () => {
  console.log(`App running at: http://localhost:${port}`)
})


// "node server.js" vs "npm run start"
