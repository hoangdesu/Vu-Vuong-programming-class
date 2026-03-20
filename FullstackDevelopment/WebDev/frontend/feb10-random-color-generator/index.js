const body = document.querySelector('body');
const generateBtn = document.querySelector('#generate-btn');
const rgbText = document.querySelector('#color-code');


const hexBtn = document.querySelector('#hex-btn');
const hexText = document.querySelector('#hex-text');


const hexChars = '0123456789abcdef';

// Dec -> Hex

// 255 / 16 = 15.9375
// => 1st char: 15 = f
// => 2nd char: 0.9375 * 16 = 15 = f

function convertDecToHex(r, g, b) {
    const rgbColorArray = [r, g, b];

    let hexStr = '#';
    for (const color of rgbColorArray) {
        const hexNum = color / 16;

        const firstNum = Math.trunc(hexNum);
        const secondNum = (hexNum - firstNum) * 16;

        // console.log(color, firstNum, secondNum);

        const colorHexChar = hexChars[firstNum] + hexChars[secondNum];
        hexStr += colorHexChar
    }

    // console.log(hexStr);
    return hexStr;
    
}

// Hex -> Dec
// ff = 255
// 09 = 9
// 0a = 010

// ff = 15*16 + 15 = 255
// bc = 11*16^1 + 12*16^0 = 176 + 12 = 176 + 12 = 188

// hex  1 d 3 a
//               <-
// 16^  3 2 1 0

// ->
// 10*16^0 + 3*16^1 + 13*16^2 + 1*16^3 = 7482

function convertHexToDec(hexColorStr) {
    console.log(hexColorStr);
    // let r, g, b; // undefined
    // console.log(r);

    // #c565c9

    // let rgb = 'rgb(';
    const rgb = [];
    let startIndex = 1;
    for (let i = 0; i < 3; i++) {
        let color = hexColorStr.substring(startIndex, startIndex + 2);
        console.log(color);

        // convert
        let dec = hexChars.indexOf(color[0]) * 16 + hexChars.indexOf(color[1]);
        // console.log(dec);
        rgb.push(dec);

        startIndex += 2;
    }

    return `rgb(${rgb[0]}, ${rgb[1]}, ${rgb[2]})`;
}


let rgbColor = 'rgb(255, 255, 255)';
generateBtn.addEventListener('click', () => {
    const r = parseInt(Math.random() * 256);
    const g = parseInt(Math.random() * 256);
    const b = parseInt(Math.random() * 256);
    
    rgbColor = `rgb(${r}, ${g}, ${b})`;
    // const newColor = '#aa99ff';
    body.style.backgroundColor = rgbColor;
    rgbText.textContent = rgbColor;

    hexText.textContent = convertDecToHex(r, g, b);
});

// binding using onclick ATTRIBUTE
rgbText.onclick = () => {
    console.log(rgbColor);

    // Navigator API: pretty new
    navigator.clipboard.writeText(rgbColor)
        .then(() => {
            alert(`Copied RGB color: ${rgbColor}`);
        })
        .catch((err) => {
            alert('Error copy RGB color code');
        });
};


// hex 0-9, a-f

// '#rrggbb'
// '#rgb' -> '#a9f' === '#aa99ff'

// string => array
// const hex = '0123456789abcdef';

// Math.random() -> pick 1 random index within the range of hex

// hex = ['0', '1', '2', '3', '4', ..., 'e', 'f']




let hexColor = '';
hexBtn.addEventListener('click', () => {
    hexColor = '#';

    for (let i = 0; i < 6; i++) {
        const randomIndex = parseInt(Math.random() * hexChars.length);
        hexColor += hexChars[randomIndex];
    }

    // console.log(hexColor);
    rgbText.textContent = convertHexToDec(hexColor);

    body.style.backgroundColor = hexColor;
    hexText.textContent = hexColor;
});


// Binding action using element's onclick attribute from HTML
function onHexTextClicked() {
    console.log('hex');
    navigator.clipboard.writeText(hexColor)
        .then(() => {
            alert(`Copied HEX color: ${hexColor}`);
        })
        .catch((err) => {
            alert('Error copy HEX color code');
        });
}


// Decimal vs Hexadecimal
// 0   0  
// 1   1
// 2   2
// 3   3
// 4   4
// 5   5
// 6   6
// 7   7
// 8   7
// 9   9
// 10  a
// 11  b
// 12  c
// 13  d
// 14  e
// 15  f

