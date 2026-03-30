'use client';

import Image from 'next/image';
import {
  Accordion,
  AccordionItem,
  AccordionButton,
  AccordionPanel,
  AccordionIcon,
  Box,
} from '@chakra-ui/react';

// const VenueCard = (props) => {
//   return (...)
// }

export default function VenueCard(props) {
  // object destructure
  const { venue } = props;

  // props.venue.name
  // props.venue.img

  // => venue.name

  return (
    <div className='venue-card'>
      <img src={venue.imgSrc} alt={venue.name} draggable="false" />

      {/* <Image 
        src={venue.imgSrc} 
        alt={venue.name} 
        draggable="false" 
        width={300} 
        height={300} 
      /> */}

      <h2>{venue.name}</h2>
      
    </div>
  );
}
