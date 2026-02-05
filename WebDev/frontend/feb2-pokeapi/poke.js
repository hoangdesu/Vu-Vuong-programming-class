// 1. input pokemon name or id
// 2. extract value from input
// 3. use pokeapi to search for new pokemon => need to construct the query for the fetch
// 4. once got the new data, replace the new pokemon data into the current card


const searchForm = document.querySelector('#search-form');
const pokemonCard = document.querySelector('.pokemon-card');

// document.getElementById('search-form');


// console.log(pokemonCard.children[1]);
// pokemonCard.children[1].textContent = 'hehehaha'


// global variable to keep track of the current poke ID
const backBtn = document.querySelector('#back-btn');
const nextBtn = document.querySelector('#next-btn');

let globalPokeId = 0;

function fetchAndReRender(pokemonQuery) {
    const POKE_API_ENDPOINT = 'https://pokeapi.co/api/v2/pokemon/';

    fetch(POKE_API_ENDPOINT + pokemonQuery)
        .then(res => res.json())
        .then(data => {
            // extract values from pokemon object
            const pokeName = data.name;
            const pokeId = data.id;
            const pokeImg = data.sprites.other['official-artwork'].front_default; // using both dot notation and bracket notation to access the image
            // data['sprites']['other']['official-artwork']['front_default']

            console.log(data);
            console.log(pokeId, pokeName, pokeImg);
            
            // cannot use sth like pokemonCard[0] because div is NOT a HTMLCollection by itself
            // must access child elements via .children attribute

            // img
            // wait for image to complete updating before updating other data
            const newImg = new Image();
            newImg.src = pokeImg;
            newImg.onload = () => {
                pokemonCard.children[0].src = pokeImg;
                pokemonCard.children[0].alt = pokeName;

                // id
                let formattedPokeId = '#';

                // if (pokeId >= 1 && pokeId <= 9) {
                //     formattedPokeId += '000';
                // } else if (pokeId >= 10 && pokeId <= 99) {
                //     formattedPokeId += '00';
                // } else if (pokeId >= 100 && pokeId <= 999) {
                //     formattedPokeId += '0';
                // }

                // another way to format the id
                let totalDigits = 4;
                let idLen = pokeId.toString().length;
                let zerosLen = totalDigits - idLen;

                for (let i = 0; i < zerosLen; i++) {
                    formattedPokeId += '0';
                }

                formattedPokeId += pokeId;
                pokemonCard.children[1].textContent = formattedPokeId;

                // name
                let formattedPokeName = pokeName[0].toUpperCase();
                formattedPokeName += pokeName.substring(1);
                pokemonCard.children[2].textContent = formattedPokeName;

                // let myname = 'vuong'; // type inferrence

                // save the current id
                globalPokeId = pokeId;

                // re-render buttons
                if (globalPokeId === 1) {
                    backBtn.disabled = true;
                } else if (globalPokeId === 1025) {
                    nextBtn.disabled = true;
                } else {
                    backBtn.disabled = false;
                    nextBtn.disabled = false;
                }
            }  
        })
        .catch(err => {
            pokemonCard.children[0].src = 'https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcTwNey01Qqt8jxo4-SzM-jONowC40zERZxnPg&s';
            pokemonCard.children[1].textContent = '#????';
            pokemonCard.children[2].textContent = 'Pokemon not found';

            globalPokeId = 0;
        });
}

searchForm.addEventListener('submit', (event) => {
    event.preventDefault();

    // searchForm: giống như 1 array (HTMLCollection)
    // - extract các element bên trong nó bằng index
    // - searchForm.children[0] or searchForm[0] để lấy input (index = 0)

    console.log(searchForm[0].value);

    const pokemonQuery = searchForm[0].value; // input.value
    
    fetchAndReRender(pokemonQuery);
});


const btnRandom = document.getElementById('btn-random');

btnRandom.addEventListener('click', (evt) => {
    const randomId = randomInt(1, 1025, true)
    fetchAndReRender(randomId);
});


nextBtn.addEventListener('click', () => {
    if (globalPokeId === 1025) return;
    globalPokeId++;
    fetchAndReRender(globalPokeId);
});

backBtn.addEventListener('click', () => {
    // lower bound
    if (globalPokeId === 1) return;

    globalPokeId--;

    // if (globalPokeId === 1) {
    //     backBtn.disabled = true;
    //     fetchAndReRender(globalPokeId);
    //     return;
    // }

    fetchAndReRender(globalPokeId);
});


// Add global keyboard input events on top of document
document.addEventListener('keydown', event => {
    console.log(event.code);
    
    switch (event.code) {
        case 'ArrowLeft':
            if (globalPokeId === 1) return;
            globalPokeId--;
            break
        case 'ArrowRight':
            if (globalPokeId === 1025) return;
            globalPokeId++;
            break
        case 'Space':
            globalPokeId = randomInt(1, 1025, true);
            break
    }

    fetchAndReRender(globalPokeId);
});


