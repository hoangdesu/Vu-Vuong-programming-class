const express = require('express')
const app = express()
const port = 3456;

const users = [
    {
        username: 'vuong',
        password: 'hades'
    },
    {
        username: 'brian',
        password: 'idk'
    },
    {
        username: 'haha',
        password: 'hehe'
    }
];

// Middleware to parse form data
app.use(express.urlencoded({ extended: true }));

// middleware
app.use((req, res, next) => {
    // logging
    const now = new Date();
    console.log(`${req.method} - ${now.toLocaleTimeString()}`);
    return next();
});


// Route controllers / route handlers

app.get('/hi', (req, res) => {
    res.send('received GET request');
});

app.post('/login', (req, res) => {
    console.log('> body:', req.body);

    const { usrnm, pswd } = req.body;

    const foundUser = users.find(usr => usr.username === usrnm);
    console.log('foundUser:', foundUser);

    if (!foundUser) return res.send('No user');
    
    if (pswd !== foundUser.password) return res.send('Login failed');

    return res.send(`Welcome ${usrnm}!!`);
});

app.delete('/hi', (req, res) => {
    res.send('DELETE...');
});

// open the server
app.listen(port, () => {
  console.log(`App running at: http://localhost:${port}`)
})

