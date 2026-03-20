// random: a -> b
// 10 -> 15 => range = 15 - 10 = 5

// default: not inclusive (means that b-1)

// inclusive: optional param, with default value = false

function randomInt(start, end, inclusive=false) {
    let range = end - start;
    if (inclusive) {
        range += 1;
    }
    return parseInt(start + Math.random() * range);
}

for (let i = 0; i < 10; i++) {
    // 0.00 -> 0.99

    // range = end - start
    // start + (Math.random() * range)

    // console.log(parseInt(10 + Math.random() * 5));
    console.log(randomInt(12, 15, true));
    
}


