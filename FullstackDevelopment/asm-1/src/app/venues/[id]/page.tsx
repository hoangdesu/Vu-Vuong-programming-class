'use client';

import Venue from '@/app/types/Venue';
import { notFound } from 'next/navigation';
import { use, useEffect, useState } from 'react';

export default function VenueDetailPage({
  params,
}: {
  params: Promise<{ id: string }>;
}) {
  const { id } = use(params); // path param

  //   console.log(id, typeof id);

  const [venue, setVenue] = useState<Venue | null>(null);

  useEffect(() => {
    const lsVenues = localStorage.getItem('vv_venues') || '[]';

    try {
      const venues = JSON.parse(lsVenues);
      // console.log(venues);

      const vn = venues.find((v) => v.id === Number(id));
      console.log(vn);

      if (!vn) throw new Error('Invalid venue ID');

      setVenue(vn);
    } catch (err) {
      console.error(err);
      notFound();
    }
  }, []);

  //   Loading UI
  if (!venue) {
    return (
      <div className='px-32'>
        <h1>Loading...</h1>
      </div>
    );
  }

  return (
    <div className='px-32 mt-16'>

      <img src={venue.imgSrc} alt="" />
      <p>ID: {id}</p>
      <h1>{venue.name}</h1>

    </div>
  );
}
