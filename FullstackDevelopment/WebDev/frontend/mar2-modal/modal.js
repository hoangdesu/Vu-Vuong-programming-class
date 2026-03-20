const btnOpenModal = document.querySelector('#btn-open-modal');
const modalOverlay = document.querySelector('#modal-overlay');

btnOpenModal.addEventListener('click', () => {
   modalOverlay.style.display = 'flex';
});

const btnCloseModal = document.querySelector('#btn-close-modal');

btnCloseModal.addEventListener('click', () => {
   modalOverlay.style.display = 'none';
});

modalOverlay.addEventListener('click', (evt) => {
    console.log('clicked on modal overlay');
    console.log('evt.target', evt.target); // what element the mouse is clicking on
    console.log('evt.currentTarget', evt.currentTarget); // the element that fires the event listener
    
    // prevent event bubbling
    if (evt.target === evt.currentTarget) {
        modalOverlay.style.display = 'none';
    }
});
