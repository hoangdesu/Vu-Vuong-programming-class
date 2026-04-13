'use client';

import { AppContext } from '@/app/store/ContextProvider';
import Venue from '@/app/types/Venue';
import { Button } from '@chakra-ui/react';
import { notFound } from 'next/navigation';
import { use, useEffect, useState } from 'react';

export default function VenueDetailPage({
  params,
}: {
  params: Promise<{ id: string }>;
}) {
  const { id } = use(params); // path param

  const { currentUser } = use(AppContext);

  //   console.log(id, typeof id);

  const [venue, setVenue] = useState<Venue | null>(null);
  const [booked, setBooked] = useState(false);

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

  const addVenueToBookings = () => {
    const lsBookings = localStorage.getItem('vv_bookings') || '[]';

    try {
      const bookings = JSON.parse(lsBookings);

      const newBooking = {
        id: crypto.randomUUID(),
        hirer: currentUser,
        venue: venue,
        // TODO: replace later
        guests: 1,
        book_datetime: new Date().toISOString(),
        duration_hrs: 1,
      };

      bookings.push(newBooking);

      localStorage.setItem('vv_bookings', JSON.stringify(bookings));
      setBooked(true);
    } catch (err) {}
  };

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
      <img src={venue.imgSrc} alt='' />
      <p>ID: {id}</p>
      <h1>{venue.name}</h1>

      <Button onClick={addVenueToBookings} disabled={booked}>
        {!booked ? 'Book now!' : 'This venue has been booked'}
      </Button>
    </div>
  );
}
