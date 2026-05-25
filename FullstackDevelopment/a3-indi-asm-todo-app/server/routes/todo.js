import express from 'express';
import { getTodoById } from '../controller/todoController';

const todoRouter = express.Router();

const todos = [
    { id: Math.random(), title: 'setup expressJS', completed: false },
    { id: Math.random(), title: 'connect nextJS with expressJS', completed: false },
];

todoRouter.get('/', (req, res) => {
  res.json(todos);
});

todoRouter.get('/:id', getTodoById);

todoRouter.post()

export default todoRouter;