// Server: serve - phục vụ
    // request - resonse

// Client
    // - laptop
    // - tablet
    // - mobile
    // - wearable devices - apple watch, garmin

// API - Application Programming Interface

// JSON - pure JS object vs JSON

// HTTP status codes:
//     - 200: OK
//     - 300: redirect
//     - 400: client errors
//     - 500: server errors

// Fetch API

// Promise


const agentsContainer = document.querySelector('#agents-container');

fetch('https://valorant-api.com/v1/agents')
    // .then(res => console.log(res))
    .then(res => res.json()) // convert response object to json
    .then(dataJson => {
        console.log('data from valorant api:', dataJson);

        const agents = dataJson.data;

        agents.forEach(agent => {
            console.log(agent.displayName);

            const agentHtmlTemplate = `
                <div class="agent-card">
                    <img src="${agent.fullPortraitV2}" alt="${agent.displayName}">
                    <h2>${agent.displayName}</h2>
                </div>
            `;

            agentsContainer.innerHTML += agentHtmlTemplate;
        });

    });


// https://pokeapi.co/api/v2/pokemon/{name}

