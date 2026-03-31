'use client';

import Image from 'next/image';
import VenueCard from './VenueCard';

import './home.css';
import { useEffect, useState } from 'react';

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
  
  const [venues, setVenues] = useState([]);

  // fetch venue data from local storage
  useEffect(() => {
    
    const localStorageVenues = localStorage.getItem('venues');

    if (localStorageVenues) {
      console.log('localStorageVenues', localStorageVenues);
      setVenues(JSON.parse(localStorageVenues));
      console.log(localStorageVenues[0]);
    } else {
      console.log('localStorageVenues is null');
    }
    
  }, []);

  // [{name: "Venue 2",imgSrc: "https://res.cloudinary.com/hoangdesu/image/upload/v1701769099/YelpCamp/apflkxajyzdt4sxjfajf.jpg"}]


  return (
    <div>
      <div>
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
            <VenueCard key={venue.name} venue={venue} />
          ))}
        </div>
      </div>
    </div>
  );
}
