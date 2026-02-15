console.log('hi');

const previewImages = [
    "https://down-vn.img.susercontent.com/file/vn-11134207-820l4-mehipkbxm1vq70.webp",
    "https://down-vn.img.susercontent.com/file/vn-11134207-820l4-mehipkcrm8li52.webp", 
    "https://down-vn.img.susercontent.com/file/vn-11134207-820l4-mehipkynturrdb.webp", 
    "https://down-vn.img.susercontent.com/file/vn-11134207-820l4-mehipkbxatc57c.webp", 
    "https://down-vn.img.susercontent.com/file/vn-11134207-820l4-mehipksar2mda5.webp", 
    "https://down-vn.img.susercontent.com/file/vn-11134207-820l4-mehipkep5clf1b.webp"
];


const mainImageImg = document.querySelector('#main-image');
const previewImagesDiv = document.querySelector('#preview-images');

previewImages.forEach(previewImg => {
    // using createElement instead of HTML string `<img>`
    const img = document.createElement('img');
    img.src = previewImg;
    previewImagesDiv.append(img);

    // // so that we can add event listener to the element
    // img.addEventListener('mouseenter', () => {
    //     console.log(img.src);
    //     mainImageImg.src = img.src;
    //     img.style.border = '2px solid red';
    // });

    // img.addEventListener('mouseleave', () => {
    //     // img.style.border = '2px solid transparent';
    // });
});


const previewImagesList = document.querySelectorAll('#preview-images img');
console.log(previewImagesList);

let lastSelected = previewImagesList[0];
lastSelected.style.border = '2px solid red';

previewImagesList.forEach(imgElement => {
    imgElement.addEventListener('mouseenter', () => {
        mainImageImg.src = imgElement.src;
    
        // remove style of the old elements
        // for (const prevImgEl of previewImagesList) {
        //     prevImgEl.style.border = '2px solid transparent';
        // }

        lastSelected.style.border = '2px solid transparent';
        
        imgElement.style.border = '2px solid red';

        lastSelected = imgElement;
    });
});
