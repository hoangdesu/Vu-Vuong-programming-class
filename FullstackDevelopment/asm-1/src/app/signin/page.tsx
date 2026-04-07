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
    const loginUser = Object.fromEntries(formData.entries());
    localStorage.setItem('vv_currentUser', JSON.stringify(loginUser));
    setCurrentUser(loginUser);
    
    router.push('/');
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
          <FormLabel>Username</FormLabel>
          <Input type='text' name='username' />
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
