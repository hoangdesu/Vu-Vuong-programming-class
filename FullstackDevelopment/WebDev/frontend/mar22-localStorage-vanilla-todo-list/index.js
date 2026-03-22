const todoForm = document.querySelector('#todo-form');
const todoListContainer = document.querySelector('#todo-list-container');
// let todoList = [];

// // check if we already have a todo list inside local storage on page load
// const localStorageList = localStorage.getItem('todoList');
// if (localStorageList) {
//     // JSON string -> JS objects
//     todoList = JSON.parse(localStorageList);
// }

// console.log(typeof todoList); // "["aaa","bbb","ccc"]"


// short-hand syntax for the above
const localStorageList = localStorage.getItem('todoList');
let todoList = JSON.parse(localStorageList) || [];

const renderTodoElement = (todoElement) => {
    const span = document.createElement('span');
    span.textContent = todoElement.name;

    const delBtn = document.createElement('button');
    delBtn.textContent = '🗑️';

    delBtn.addEventListener('click', () => {
        console.log('id:', todoElement.id);

        // todoList.splice(index, 1);
        // console.log('current index:', index);

        todoList = todoList.filter(todo => todo.id != todoElement.id);
        console.log(todoList);
        
        const todoListJsonString = JSON.stringify(todoList);
        localStorage.setItem('todoList', todoListJsonString);
    
        // self-remove
        // document.querySelector(`#todo-${index}`).remove();

        // remove child from parent
        todoListContainer.removeChild(document.querySelector(`li[data-todo-id="todo-${todoElement.id}"]`));
    });

    const div = document.createElement('div');
    div.className = 'todo-element';
    div.append(span);
    div.append(delBtn);
    
    const li = document.createElement('li');
    li.append(div);
    // li.id = `todo-${todoElement.id}`;
    li.dataset.todoId = `todo-${todoElement.id}`;
    todoListContainer.append(li);
}

// array methods
todoList.forEach((todoElement) => {
    renderTodoElement(todoElement);
});


todoForm.addEventListener('submit', (evt) => {
    evt.preventDefault(); // no more reload

    // console.log(todoForm[0].value); // index

    const inputValue = todoForm['todo-input'].value;
    console.log(inputValue); // get by key (name attribute)

    // input validation
    if (!inputValue) {
        alert('You must enter something for todo');
        return; // early return
    }

    if (inputValue.length < 3) {
        alert('Todo must have at least 3 characters');
        return;
    }

    // todoList.push(inputValue);

    const newTodo = {
        id: Math.random() * Math.random(),
        name: inputValue
    };

    todoList.push(newTodo);

    console.log(todoList);

    // store new todo in local storage
    // JS list -> JSON string
    const todoListJsonString = JSON.stringify(todoList);
    localStorage.setItem('todoList', todoListJsonString);
    
    // render new todo on screen
    renderTodoElement(newTodo);
    
    // clear input
    todoForm['todo-input'].value = '';
});


// object: dictionary / hashmap: key-value pairs
