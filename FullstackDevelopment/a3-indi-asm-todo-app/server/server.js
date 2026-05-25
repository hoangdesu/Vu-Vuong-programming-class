import express from 'express';
import todoRouter from './routes/todo.js';

const app = express();
const port = 3999;

// app.get('/api', (req, res) => {
//   res.send('Hello World!')
// });

// GET /api/todos

// Router
app.use('/api/todos', todoRouter);


app.listen(port, () => {
  console.log(`Example app listening on port http://localhost:${port}`)
})