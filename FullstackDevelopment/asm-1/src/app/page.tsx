'use client';

import Image from 'next/image';
import VenueCard from './VenueCard';

import './home.css';
import { use, useContext, useEffect, useState } from 'react';
import { AppContext } from './store/ContextProvider';
import Venue from './types/Venue';

// type Venue = {

// }

export default function HomePage() {
  // const venue1 = {
  //   name: 'Venue 1',
  //   imgSrc:
  //     'https://res.cloudinary.com/hoangdesu/image/upload/v1701713476/YelpCamp/c6jlzo2unpqch3tfctwb.png',
  // };

  // const venue2 = {
  //   name: 'Venue 2',
  //   imgSrc:
  //     'https://res.cloudinary.com/hoangdesu/image/upload/v1701769099/YelpCamp/apflkxajyzdt4sxjfajf.jpg',
  // };

  // console.log('component HomePage renders');

  // const appContext = use(AppContext);
  const { currentUser } = use(AppContext);

  // {
  //   "id": 2,
  //   "name": "Ocean Breeze",
  //   "imgSrc": "https://picsum.photos/id/1015/600/400"
  // }
  
  const [venues, setVenues] = useState<Venue[]>([]);

  // fetch venue data from local storage
  useEffect(() => {
    
    const localStorageVenues = localStorage.getItem('vv_venues') || '[]';

    if (localStorageVenues) {
      setVenues(JSON.parse(localStorageVenues));

      // console.log('localStorageVenues', localStorageVenues);
      // console.log(localStorageVenues[0]);
    } else {
      console.log('localStorageVenues is null');
    }
    
  }, []);

  // [{name: "Venue 2",imgSrc: "https://res.cloudinary.com/hoangdesu/image/upload/v1701769099/YelpCamp/apflkxajyzdt4sxjfajf.jpg"}]

  //   const [currentUser, setCurrentUser] = useState(null);

  // useEffect(() => {
  //   const lsUser = localStorage.getItem('currentUser');
  //   if (lsUser) {
  //     setCurrentUser(JSON.parse(lsUser));
  //   }
  // }, []);



  return (
    <div>
      <div>
        <h1>Home</h1>
        {/* <p>Current user: {appContext.currentUser?.username}</p> */}
        <p>Current user: {currentUser?.usernam || 'Not logged in'}</p>

        {/* <VenueCard 
            name={name} 
            img={}
            /> */}

        {/* <VenueCard venue={venue1} />
          <VenueCard venue={venue2} />
          <VenueCard venue={venue2} /> */}

        {/* {venues.map(venue => {
            return <VenueCard key={venue.name} venue={venue} />
            })} */}

        <h1>Venues</h1>
        <div id='venues-container'>
          {venues.map((venue) => (
            <VenueCard key={venue.id} venue={venue} />
          ))}
        </div>
      </div>
    </div>
  );
}
