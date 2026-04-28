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
    const foodList = menu.map(food => `<li>${food}</li>`);

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
    
    res.send(food);
    // res.html
    // res.json
});



// open the server
app.listen(port, () => {
  console.log(`App running at: http://localhost:${port}`)
})


// "node server.js" vs "npm run start"
