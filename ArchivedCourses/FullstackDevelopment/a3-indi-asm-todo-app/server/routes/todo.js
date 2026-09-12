import express from 'express';
import { getTodoById } from '../controller/todoController.js';

const todoRouter = express.Router();

const todos = [
  { id: Math.random(), title: 'setup expressJS', completed: false },
  {
    id: Math.random(),
    title: 'connect nextJS with expressJS',
    completed: false,
  },
];

todoRouter.get('/', (req, res) => {
  res.json(todos);
});

todoRouter.get('/:id', getTodoById);

todoRouter.put('/update/:todoId/completedStatus', (req, res) => {
  const { todoId } = req.params;
  // console.log(todoId);
  // console.log(Number(todoId));

  const currentTodo = todos.find((todo) => todo.id === Number(todoId));

  console.log(currentTodo);

  if (!currentTodo) return res.status(404).send('Invalid ID');

  currentTodo.completed = !currentTodo.completed;

  res.json(currentTodo);
});

todoRouter.put('/update/:todoId/title', (req, res) => {
  const { todoId } = req.params;
  const { title } = req.body;
  console.log(todoId, title);

  const currentTodo = todos.find((todo) => todo.id === Number(todoId));

  console.log(currentTodo);

  if (!currentTodo) return res.status(404).send('Invalid ID');

  currentTodo.title = title;

  console.log(todos);
  
  res.sendStatus(200);
});

// todoRouter.post()

export default todoRouter;
