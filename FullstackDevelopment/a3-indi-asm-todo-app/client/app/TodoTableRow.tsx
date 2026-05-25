'use client';

import { Dispatch, SetStateAction, useRef, useState } from 'react';
import Todo from './types/Todo';
import './Todo.css';

interface TableRowType {
  todo: Todo;
  index: number;
  todos: Todo[];
  setTodos: Dispatch<SetStateAction<Todo[]>>;
}

export default function TodoTableRow(props: TableRowType) {
  const { todo, index, todos, setTodos } = props;
  
  const [isEditing, setIsEditing] = useState(false);
  const todoInputRef = useRef<null | HTMLInputElement>(null);

  const onCompletedChanged = (todoId: number) => {
    console.log(todoId);

    fetch(`http://localhost:3999/api/todos/update/${todoId}/completedStatus/`, {
      method: 'put',
    })
      .then((res) => res.json())
      .then((updatedTodo: Todo) => {
        console.log(updatedTodo);

        // const clonedTodos = [...todos]; // spread operator
        const clonedTodos = structuredClone(todos);

        const updatingTodo = clonedTodos.find(
          (todo) => updatedTodo.id === todo.id,
        );
        if (!updatingTodo) throw new Error('Error cannot find todo to update');

        updatingTodo.completed = !updatedTodo.completed;
        setTodos(clonedTodos);
      })
      .catch((err) => {
        console.error(err);
      });
  };

  const onTodoSaved = () => {
    fetch(`http://localhost:3999/api/todos/update/${todo.id}/title/`, {
      method: 'put',
      headers: {
        'Content-Type': 'application/json',
      },
      body: JSON.stringify({
        title: todoInputRef?.current?.value || '',
      }),
    }).then((res) => {
      if (res.ok) {
        const clonedTodos = structuredClone(todos);

        const updatingTodo = clonedTodos.find(
          (clonedTodo) => clonedTodo.id === todo.id,
        );
        if (!updatingTodo) throw new Error('Error cannot find todo to update');

        updatingTodo.title = todoInputRef?.current?.value || '';
        
        setTodos(clonedTodos);
        setIsEditing(false);
      }
    });
  };

  return (
    <tr>
      <td>{index + 1}</td>
      <td>
        <input
          type='checkbox'
          defaultChecked={todo.completed}
          onChange={() => onCompletedChanged(todo.id)}
        />
      </td>
      <td>
        {isEditing ? (
          <>
            <input
              type='text'
              defaultValue={todo.title}
              className='todo-input'
              ref={todoInputRef}
            />
            <button onClick={onTodoSaved}>Save</button>
          </>
        ) : (
          <span
            className='todo-title'
            // style={{ textDecoration: todo.completed ? 'line-through' : 'none' }}
            onClick={() => setIsEditing(true)}
          >
            {todo.title}
          </span>
        )}
      </td>
    </tr>
  );
}
