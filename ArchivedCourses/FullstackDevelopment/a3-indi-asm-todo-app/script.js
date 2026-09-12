fetch(URL)
    // .then(res => {
    //     // if (res.ok) reload page
    // })

    .then(res => res.json())
    .then(newTodoData => {
        old data = new data

        todoList = [td1, td2, ...]

        find which todo is old todo        
        update old todo with new todo data
    })