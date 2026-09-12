'use client';

import { useEffect, useState } from 'react';
import TodoTableRow from './TodoTableRow';
import Todo from './types/Todo';

export default function Home() {
  const [todos, setTodos] = useState<Todo[]>([] as Todo[]);

  useEffect(() => {
    fetch('http://localhost:3999/api/todos')
      .then((res) => res.json())
      .then((todosData) => {
        setTodos(todosData);
      });
  }, []);

  return (
    <div>
      <h1>Todo App</h1>

      <form action=''></form>

      <table>
        <tbody>
          {todos.map((todo, idx) => (
            <TodoTableRow
              key={todo.id}
              todo={todo}
              index={idx}
              todos={todos}
              setTodos={setTodos}
            />
          ))}
        </tbody>
      </table>
    </div>
  );
}
