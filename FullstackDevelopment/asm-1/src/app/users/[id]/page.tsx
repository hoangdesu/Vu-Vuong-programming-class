'use client';

import { AppContext } from '@/app/store/ContextProvider';
import { use, useEffect, useId, useState } from 'react';

import {
  FormControl,
  FormLabel,
  FormErrorMessage,
  FormHelperText,
  Input,
  Button,
  useToast,
} from '@chakra-ui/react';
import VenueCard from '@/app/VenueCard';

export default function UserPage({
  params,
}: {
  params: Promise<{ id: string }>;
}) {
  const { id } = use(params);

  const toast = useToast();
  const { currentUser, setCurrentUser } = use(AppContext);
  const [myBookings, setMyBookings] = useState<null | []>(null);

  const onSave = (evt) => {
    evt.preventDefault();

    const updatedUserFormData = Object.fromEntries(
      new FormData(evt.currentTarget).entries(),
    );

    const lsUsers = localStorage.getItem('vv_users') || '[]';
    try {
      const users = JSON.parse(lsUsers);

      const userIndex = users.findIndex((usr) => usr.id === currentUser.id);
      // if (!foundUser) throw new Error('User error');

      // update the info for the current user inside the users list
      const updatedUser = { ...users[userIndex], ...updatedUserFormData };
      users[userIndex] = updatedUser;

      // if (duplicatedUser) throw new Error('Duplicated user');

      // users.push(newUser);
      localStorage.setItem('vv_users', JSON.stringify(users));

      const { password, ...curUsr } = updatedUser;
      setCurrentUser(curUsr);
      localStorage.setItem('vv_currentUser', JSON.stringify(curUsr));

      toast({
        title: 'Updated info succesfully',
        // description: "We've created your account for you.",
        status: 'success',
        duration: 2000,
        isClosable: true,
      });
    } catch (e) {
      console.error(e);
    }
  };

  // extract only MY bookings from ALL bookings
  // must wait for currentUser to finish updating
  useEffect(() => {
    console.log('getting bookings');
    
    const lsBookings = localStorage.getItem('vv_bookings') || '[]';
    try {
      const bookings = JSON.parse(lsBookings);

      const myBookings = bookings.filter(
        (bk) => bk.hirer.id === currentUser.id,
      );

      console.log('my bookings:', myBookings);
      setMyBookings(myBookings);
    } catch (e) {}
  }, [currentUser]);

  if (!currentUser) {
    return <div>Loading...</div>;
  }

  return (
    <div className='px-32'>
      <form onSubmit={onSave}>
        <FormControl>
          <FormLabel>User ID</FormLabel>
          <Input type='text' name='id' disabled defaultValue={currentUser.id} />
        </FormControl>
        <FormControl>
          <FormLabel>Name</FormLabel>
          <Input type='text' name='name' defaultValue={currentUser.name} />
        </FormControl>
        <FormControl>
          <FormLabel>Email</FormLabel>
          <Input type='email' name='email' defaultValue={currentUser.email} />
        </FormControl>
        <FormControl>
          <FormLabel>Phone Number</FormLabel>
          <Input
            type='text'
            name='phoneNumber'
            defaultValue={currentUser.phoneNumber}
          />
        </FormControl>
        {/* <FormControl>
          <FormLabel>Password</FormLabel>
          <Input type='password' name='password' />
        </FormControl> */}
        <Button mt={4} colorScheme='blue' type='submit'>
          Save
        </Button>
      </form>

      <section>
        <h1>My Bookings</h1>
        <div>
          {myBookings?.map((booking) => (
            <VenueCard key={booking.venue.id} venue={booking.venue} />
          ))}
        </div>
      </section>
    </div>
  );
}
