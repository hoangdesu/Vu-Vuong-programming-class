// window: global obj -> window.localStorage

const user = localStorage.getItem('user'); // key='user'

const mainContent = document.querySelector('main');

// if (user) {
//     mainContent.innerHTML = `
//         <p>Welcome, ${user}!<p>
//         <button>Log out</button>
//     `;
// } else {
//     mainContent.innerHTML = `
//         <p>You are not logged in<p>
//         <button>Login</button>
//     `;
// }


if (!user) {
    // re-direct to login page
    window.location = '/login.html';
} else {
    mainContent.innerHTML = `
        <p>Welcome, ${user}!<p>
        <button id="logout-btn">Log out</button>
    `;
}

const logoutBtn = document.querySelector('#logout-btn');

logoutBtn.addEventListener('click', () => {
    localStorage.removeItem('user');
    window.location = '/';
});


