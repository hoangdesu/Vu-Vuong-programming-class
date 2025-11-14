console.log('hello from ig.js');

const followBtn = document.querySelector('#follow-btn');

let isFollowing = false;

let followersCount = 900;
const followersCountSpan = document.querySelector('#followers-count');
followersCountSpan.textContent = followersCount;

followBtn.addEventListener('click', () => {
    if (!isFollowing) {
        followBtn.textContent = 'Following';
        followersCount++;
    } else {
        followBtn.textContent = 'Follow';
        followersCount--;
    }

    // reflect new followers count on UI
    followersCountSpan.textContent = followersCount;

    // toggle
    isFollowing = !isFollowing;
    console.log(followersCount);
    

});
