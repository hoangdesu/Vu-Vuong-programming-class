'use client';

import Image from 'next/image';
import VenueCard from './VenueCard';

import './home.css';
import { use, useContext, useEffect, useRef, useState } from 'react';
import { AppContext } from './store/ContextProvider';
import Venue from './types/Venue';
import { Button, FormControl, FormLabel, Input } from '@chakra-ui/react';

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
  const [allVenues, setAllVenues] = useState<Venue[]>([]);

  // fetch venue data from local storage
  useEffect(() => {
    const localStorageVenues = localStorage.getItem('vv_venues') || '[]';

    if (localStorageVenues) {
      setVenues(JSON.parse(localStorageVenues));

      setAllVenues(JSON.parse(localStorageVenues));

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

  const searchQueryRef = useRef(null);

  const onVenueSearch = (evt: React.SubmitEvent<HTMLFormElement>) => {
    evt.preventDefault();

    if (searchQueryRef.current) {
      const searchQuery = searchQueryRef.current.value;

      if (!searchQuery) {
        alert('You need to enter something to search');
        return;
      }

      const lsVenues = localStorage.getItem('vv_venues') || '[]';
      try {
        const allVenues = JSON.parse(lsVenues);
        const filteredVenues = allVenues.filter((dbVenue) =>
          dbVenue.name.toLowerCase().includes(searchQuery.toLowerCase()),
        );
        setVenues(filteredVenues);
      } catch {}

      // reset search query after done
      searchQueryRef.current.value = '';
    }
  };

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

        <div className='px-32'>
          <form onSubmit={onVenueSearch}>
            <FormControl className='flex flex-row items-center justify-center gap-2 mb-8'>
              <Input
                type='text'
                name='query'
                placeholder='Search venue...'
                ref={searchQueryRef}
              />
              <Button
                // mt={4}
                // colorScheme='blue'
                type='submit'
              >
                Search
              </Button>
              <Button onClick={() => setVenues(allVenues)}>Clear</Button>
            </FormControl>
          </form>
        </div>

        <div id='venues-container'>
          {venues.map((venue) => (
            <VenueCard key={venue.id} venue={venue} />
          ))}

          {venues.length === 0 && <>Venues empty</>}
        </div>
      </div>
    </div>
  );
}
