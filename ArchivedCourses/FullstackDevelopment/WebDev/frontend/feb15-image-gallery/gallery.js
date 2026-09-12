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


let activeIndex = 0;
let lastSelected = previewImagesList[activeIndex];
lastSelected.style.border = '2px solid red';

// 1-time
// setTimeout

// forever
// slide-show
let slideShowInterval = setInterval(() => {
    console.log('hehe');
    
    activeIndex = (activeIndex + 1) % previewImages.length;

    mainImageImg.src = previewImages[activeIndex];
    lastSelected.style.border = '2px solid transparent';
    lastSelected = previewImagesList[activeIndex];
    lastSelected.style.border = '2px solid red';
}, 1000);


previewImagesList.forEach((imgElement, idx) => {
    imgElement.addEventListener('mouseenter', () => {
        mainImageImg.src = imgElement.src;
    
        // remove style of the old elements
        // for (const prevImgEl of previewImagesList) {
        //     prevImgEl.style.border = '2px solid transparent';
        // }

        lastSelected.style.border = '2px solid transparent';
        
        imgElement.style.border = '2px solid red';

        lastSelected = imgElement;

        // console.log('hovering on...', idx);
        activeIndex = idx;

        clearInterval(slideShowInterval);
    });

    imgElement.addEventListener('mouseleave', () => {
        slideShowInterval = setInterval(() => {
            activeIndex = (activeIndex + 1) % previewImages.length;

            mainImageImg.src = previewImages[activeIndex];
            lastSelected.style.border = '2px solid transparent';
            lastSelected = previewImagesList[activeIndex];
            lastSelected.style.border = '2px solid red';
        }, 1000);
    });
});

document.addEventListener('keydown', (event) => {
    // index++;
    // if over flow reset index

    // console.log(event.key);
    console.log('activeIndex', activeIndex);

    clearInterval(slideShowInterval);
    
    if (event.key === 'ArrowRight') {
        // cong len, reset sau
        // activeIndex++;
        // if (activeIndex > previewImages.length - 1) activeIndex = 0;

        // limit in range of modulous
        activeIndex = (activeIndex + 1) % previewImages.length;

    } else if (event.key === 'ArrowLeft') {
        activeIndex--;
        if (activeIndex < 0) activeIndex = previewImages.length - 1;

        // activeIndex = (activeIndex - 1) % previewImages.length;
    }

    // re-render
    mainImageImg.src = previewImages[activeIndex];
    lastSelected.style.border = '2px solid transparent';
    lastSelected = previewImagesList[activeIndex];
    lastSelected.style.border = '2px solid red';

    // setTimeout(() => {
    //     slideShowInterval = setInterval(() => {
    //         activeIndex = (activeIndex + 1) % previewImages.length;

    //         mainImageImg.src = previewImages[activeIndex];
    //         lastSelected.style.border = '2px solid transparent';
    //         lastSelected = previewImagesList[activeIndex];
    //         lastSelected.style.border = '2px solid red';
    //     }, 1000);
    // }, 2000);
});


