// Hex -> Dec
// ff = 255
// 09 = 9
// 0a = 010

// ff = 15*16 + 15 = 255
// bc = 11*16^1 + 12*16^0 = 176 + 12 = 176 + 12 = 188

// hex  1 d 3 a
//               <-
// 16^  3 2 1 0

// 10*16^0 + 3*16^1 + 13*16^2 + 1*16^3 = 7482

const hexChars = '0123456789abcdef';

function convertHexToDec(hexStr) {
    let dec = 0;
    let exp = 0;
    for (let i = hexStr.length - 1; i >= 0; i--) {
        // using str.indexOf
        // console.log(hexStr[i], hexChars.indexOf(hexStr[i]));

        // using nested for loop to extract the index
        for (let j = 0; j < hexChars.length; j++) {
            if (hexStr[i] === hexChars[j]) {
                console.log(hexStr[i], j);
                dec += j * Math.pow(16, exp); // 10 * 16^0
                exp++;
            }
        }
    }

    return dec;
}

console.log(convertHexToDec('1d3a'));