'use client';

import {
  FormControl,
  FormLabel,
  FormErrorMessage,
  FormHelperText,
  Input,
  Button,
  useToast,
} from '@chakra-ui/react';
import { useRouter } from 'next/navigation';
import { use, useState } from 'react';
import { AppContext } from '../store/ContextProvider';

export default function SignInPage() {
  //   const [username, setUsername] = useState('');

  console.log('signin page RERENDERED');
  const router = useRouter();

  const { currentUser, setCurrentUser } = use(AppContext);

  const onLogin = (evt) => {
    evt.preventDefault();

    const formData = new FormData(evt.currentTarget);

    const lsUsers = localStorage.getItem('vv_users') || '[]';
    try {
      const users = JSON.parse(lsUsers);

      const loginUser = Object.fromEntries(formData.entries());

      // check if user is in db
      const foundUser = users.find((usr) => usr.email === loginUser.email);
      // console.log(foundUser);
      if (!foundUser) throw new Error('Login failed');

      if (loginUser.password !== foundUser.password) throw new Error('Login failed');
      
      // const currUsr = {
      //   id: foundUser.id,
      //   name: foundUser.name,
      //   email: foundUser.email
      // };

      // remove password, keep everything the same in currUser
      const { password, ...currUser } = foundUser;

      localStorage.setItem('vv_currentUser', JSON.stringify(currUser));
      setCurrentUser(currUser);
      router.push('/');
    } catch(e) {
      console.error(e)
    }

  };

  return (
    <div className='px-32'>
      <h1>Sign in</h1>

      {/* Controlled component */}
      {/* <Input type="text" 
            // onChange={e => setUsername(e.target.value)} 
            />
            <button onClick={() => {console.log(username)}}>Show</button> */}

      <form onSubmit={onLogin}>
        <FormControl>
          <FormLabel>Email</FormLabel>
          <Input type='text' name='email' />
        </FormControl>
        <FormControl>
          <FormLabel>Password</FormLabel>
          <Input type='password' name='password' />
        </FormControl>
        <Button
          mt={4}
          colorScheme='blue'
          // isLoading={props.isSubmitting}
          type='submit'
        >
          Sign In
        </Button>
      </form>
    </div>
  );
}
