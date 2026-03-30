import Image from 'next/image';
import VenueCard from './VenueCard';
import { ChakraProvider } from '@chakra-ui/react';

import './home.css';

export default function Home() {
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

  const venues = [
    {
      name: 'Venue 2',
      imgSrc:
        'https://res.cloudinary.com/hoangdesu/image/upload/v1701769099/YelpCamp/apflkxajyzdt4sxjfajf.jpg',
    },
    {
      name: 'Venue 1',
      imgSrc:
        'https://res.cloudinary.com/hoangdesu/image/upload/v1701713476/YelpCamp/c6jlzo2unpqch3tfctwb.png',
    },
        {
      name: 'Venue 2',
      imgSrc:
        'https://res.cloudinary.com/hoangdesu/image/upload/v1701769099/YelpCamp/apflkxajyzdt4sxjfajf.jpg',
    },
    {
      name: 'Venue 1',
      imgSrc:
        'https://res.cloudinary.com/hoangdesu/image/upload/v1701713476/YelpCamp/c6jlzo2unpqch3tfctwb.png',
    },
    {
      name: 'Venue 1',
      imgSrc:
        'https://res.cloudinary.com/hoangdesu/image/upload/v1701713476/YelpCamp/c6jlzo2unpqch3tfctwb.png',
    },
    {
      name: 'Venue 1',
      imgSrc:
        'https://res.cloudinary.com/hoangdesu/image/upload/v1701713476/YelpCamp/c6jlzo2unpqch3tfctwb.png',
    },
    {
      name: 'Venue 1',
      imgSrc:
        'https://res.cloudinary.com/hoangdesu/image/upload/v1701713476/YelpCamp/c6jlzo2unpqch3tfctwb.png',
    },
    {
      name: 'Venue 1',
      imgSrc:
        'https://res.cloudinary.com/hoangdesu/image/upload/v1701713476/YelpCamp/c6jlzo2unpqch3tfctwb.png',
    },
    {
      name: 'Venue 1',
      imgSrc:
        'https://res.cloudinary.com/hoangdesu/image/upload/v1701713476/YelpCamp/c6jlzo2unpqch3tfctwb.png',
    },
    {
      name: 'Venue 1',
      imgSrc:
        'https://res.cloudinary.com/hoangdesu/image/upload/v1701713476/YelpCamp/c6jlzo2unpqch3tfctwb.png',
    },
  ];

  return (
    <ChakraProvider>
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
          <div id="venues-container">
            {venues.map(venue => <VenueCard key={venue.name} venue={venue} />)}
          </div>

        </div>
      </div>
    </ChakraProvider>
  );
}
