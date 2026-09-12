// require('reflect-metadata')
// const express = require('express')
// const cors = require('cors')

import 'reflect-metadata';
import express from 'express';
import cors from 'cors';
import { MyDataSource } from './dataSource.js';
import Game from './entity/Game.js';

const app = express();
const port = 3456;

// CORS middleware
// app.use(cors()); // allow all

// Datasource

app.use(
  cors({
    origin: ['http://localhost:5173', 'http://localhost:5174'],
  }),
);

app.use(express.urlencoded({ extended: true })); // form data
app.use(express.json());

// const games = ['hades', 'gi', 'pragmata', 'dota 2'];

// 1. GET /games
// display a simple HTML page:

// Game Library:
//     1. <a href="https://www.google.com/search?q=hades" target="_blank">hades</a>
//     2. link: gi
//     3. link: pragmata

app.get('/games', async (req, res) => {
  const gameRepo = MyDataSource.getRepository(Game);
  const games = await gameRepo.find();
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

  // rename object after destruct
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

// route handler: app.post(ENDPOINT, controller)
// route handler: app.get(ENDPOINT, controller)

// DELETE /games
// Params:
//     1. req.body (delete by name): post body JSON => OK
//     2. query string (delete by int [num|index|id]): /games?name=forza horizon => X, /games?num=3 (OK)
//     3. path param (delete by int [num|index|id]): /games/forza horizon (NO), /games/4 (OK)

app.delete('/games/:index', (req, res) => {
  // console.log(req.params);
  const { index } = req.params;

  const i = parseInt(index);

  console.log('deleting...', games[i], ', index = ', i);
  games.splice(i, 1);

  res.send('OK');
});

app.put('/games', (req, res) => {
  console.log(req.body);

  const { index, newGame } = req.body;
  games[index] = newGame; // in-place replacement

  res.send('OK'); // status === 200
});

MyDataSource.initialize().then(() => {
  // open the server
  app.listen(port, () => {
    console.log(`App running at: http://localhost:${port}`);
  });
});
