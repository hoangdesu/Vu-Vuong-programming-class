'use client';

import Image from 'next/image';
import {
  Accordion,
  AccordionItem,
  AccordionButton,
  AccordionPanel,
  AccordionIcon,
  Box,
  Button,
} from '@chakra-ui/react';
import { useEffect, useEffectEvent, useState } from 'react';
import Link from 'next/link';
import Venue from './types/Venue';

// const VenueCard = (props) => {
//   return (...)
// }

export default function VenueCard(props: {
  venue: Venue
}) {
  // object destructure
  const { venue } = props;
  const [selected, setSelected] = useState(false);
  const [randNum, setRandNum] = useState(null);

  // props.venue.name
  // props.venue.img

  // => venue.name

  // // runs AFTER every single render of the component -> clean up
  // useEffect(() => {
  //   console.log('this useeffect runs after every single render of the component.');
  // });

  // console.log('component venuecard is re-rendered');

  // // empty dependency array: run the effect's code ONLY once after the initial render of the component
  // useEffect(() => {
  //   console.log(`[${venue.name}] fetching data from database...`)
    
  // }, []);


  // // run once after the initial render AND when state in dep array changes
  // useEffect(() => {
  //   console.log(venue.name, 'finished updating the selected state:', selected);
  // }, [selected]);


  // useEffect(callback function, dependency array)

  // useEffect(() => {
    
  //   setTimeout(() => {
  //     setRandNum(Math.random());
  //   }, 2000 + Math.random() * 5000);

  // }, []);


  return (
    <Link href={`/venues/${venue.id}`} className='venue-card'>
      <img src={venue.imgSrc} alt={venue.name} draggable="false" />

      {/* <Image 
        src={venue.imgSrc} 
        alt={venue.name} 
        draggable="false" 
        width={300} 
        height={300} 
      /> */}

      <h2>{venue.name}</h2>

      {/* <button onClick={() => {
        setSelected(!selected)
        console.log('selected inside onclick (DELAYED)', selected);
        
      }}>{selected ? 'Selected' : 'NOT selected'}</button> */}

      {/* <p>{!randNum ? 'Loading...' : randNum}</p> */}
      
    </Link>
  );
}
