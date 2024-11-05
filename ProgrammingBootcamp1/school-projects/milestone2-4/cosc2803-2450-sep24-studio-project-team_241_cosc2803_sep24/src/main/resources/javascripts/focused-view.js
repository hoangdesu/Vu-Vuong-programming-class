// console.log('hello from file focused view');

const btnToggleTable = document.querySelector('#btn-toggle-table');
const dataTable = document.querySelector('#data-table');

let showTable = false;
// dataTable.style.display = 'none';

btnToggleTable.addEventListener('click', () => {
    if (showTable) {
        dataTable.style.display = 'none';
    } else {
        dataTable.style.display = 'block';
    }

    showTable = !showTable;
});


