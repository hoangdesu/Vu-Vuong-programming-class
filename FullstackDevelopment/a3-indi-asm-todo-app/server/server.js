import express from 'express';
import todoRouter from './routes/todo.js';
import cors from 'cors';

const app = express();
const port = 3999;

app.use(cors());
app.use(express.json());
app.use(express.urlencoded({ extended: true }));


// app.get('/api', (req, res) => {
//   res.send('Hello World!')
// });

// GET /api/todos

// Router
app.use('/api/todos', todoRouter);


app.listen(port, () => {
  console.log(`Server listening on port http://localhost:${port}`)
})