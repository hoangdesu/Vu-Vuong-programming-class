// 1. input pokemon name or id
// 2. extract value from input
// 3. use pokeapi to search for new pokemon => need to construct the query for the fetch
// 4. once got the new data, replace the new pokemon data into the current card


const searchForm = document.querySelector('#search-form');
const pokemonCard = document.querySelector('.pokemon-card');

// console.log(pokemonCard.children[1]);
// pokemonCard.children[1].textContent = 'hehehaha'

searchForm.addEventListener('submit', (event) => {
    event.preventDefault();

    // searchForm: giống như 1 array (HTMLCollection)
    // - extract các element bên trong nó bằng index
    // - searchForm.children[0] or searchForm[0] để lấy input (index = 0)

    console.log(searchForm[0].value);

    const POKE_API_ENDPOINT = 'https://pokeapi.co/api/v2/pokemon/';
     
    const pokemonQuery = searchForm[0].value; // input.value

    fetch(POKE_API_ENDPOINT + pokemonQuery)
        .then(res => res.json())
        .then(data => {
            // extract values from pokemon object
            const pokeName = data.name;
            const pokeId = data.id;
            const pokeImg = data.sprites.other['official-artwork'].front_default; // using both dot notation and bracket notation to access the image

            console.log(data);
            console.log(pokeId, pokeName, pokeImg);
            
            // img
            pokemonCard.children[0].src = pokeImg;
            pokemonCard.children[0].alt = pokeName;

            // id
            let formattedPokeId = '#';
            if (pokeId >= 1 && pokeId <= 9) {
                formattedPokeId += '000';
            } else if (pokeId >= 10 && pokeId <= 99) {
                formattedPokeId += '00';
            } else if (pokeId >= 100 && pokeId <= 999) {
                formattedPokeId += '0';
            }
            formattedPokeId += pokeId;
            pokemonCard.children[1].textContent = formattedPokeId;

            // name
            let formattedPokeName = pokeName[0].toUpperCase();
            formattedPokeName += pokeName.substring(1);
            pokemonCard.children[2].textContent = formattedPokeName;
            
        })
        .catch(err => {
            pokemonCard.children[0].src = 'https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcTwNey01Qqt8jxo4-SzM-jONowC40zERZxnPg&s';
            pokemonCard.children[1].textContent = '#????';
            pokemonCard.children[2].textContent = 'Pokemon not found';
        });
})