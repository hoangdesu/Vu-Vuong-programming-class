import Image from "next/image";
import VenueCard from "./VenueCard";
import { ChakraProvider } from '@chakra-ui/react'

export default function Home() {
  
  const venue1 = {
    name: 'Venue 1',
    imgSrc: 'https://res.cloudinary.com/hoangdesu/image/upload/v1701713476/YelpCamp/c6jlzo2unpqch3tfctwb.png'
  };

  const venue2 = {
    name: 'Venue 2',
    imgSrc: 'https://res.cloudinary.com/hoangdesu/image/upload/v1701769099/YelpCamp/apflkxajyzdt4sxjfajf.jpg'
  };

  return (
    <ChakraProvider>
      <div>

        <div>
          {/* <VenueCard 
            name={name} 
            img={} 
            /> */}

          <VenueCard venue={venue1} />
          <VenueCard venue={venue2} />
          <VenueCard venue={venue2} />

        </div>
      </div>
    </ChakraProvider>
  );
}
