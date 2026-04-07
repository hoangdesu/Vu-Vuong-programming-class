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


export default function SignUpPage() {
  const router = useRouter();

  const onFormSubmit = (evt) => {
    evt.preventDefault();
    
    // console.log('submitting form...');

    const formData = new FormData(evt.currentTarget);

    // console.log(Array.from(formData.entries()).length);
    
    
    // if ( < 3) {
    //   alert('Missing data');
    //   return;
    // }

    const newUser = Object.fromEntries(formData.entries());
    console.log();


    // later with a real db
    // db.users.insert(newUser)

    // mimic using a real db
    const lsUsers = localStorage.getItem('vv_users') || '[]';
    try {
      const users = JSON.parse(lsUsers);

      const duplicatedUser = users.find(
        (user) => user.username === newUser.username,
      );
      // console.log(duplicatedUser);

      if (duplicatedUser) throw new Error('Duplicated user');

      users.push(newUser);
      localStorage.setItem('vv_users', JSON.stringify(users));

      router.push('/signin');
    } catch (e) {
      console.error(e);
      
    }
  };
  
  return (
    <div className='px-32'>
      <h1>Sign up</h1>

      <form onSubmit={onFormSubmit}>
        <FormControl>
          <FormLabel>Username</FormLabel>
          <Input type='text' name='username' />
          {/* <FormHelperText>We'll never share your email.</FormHelperText> */}
        </FormControl>
        <FormControl>
          <FormLabel>Email address</FormLabel>
          <Input type='email' name='email' />
          {/* <FormHelperText>We'll never share your email.</FormHelperText> */}
        </FormControl>
        <FormControl>
          <FormLabel>Password</FormLabel>
          <Input type='password' name='password' />
          {/* <FormHelperText>We'll never share your email.</FormHelperText> */}
        </FormControl>
        <Button
          mt={4}
          colorScheme='teal'
          // isLoading={props.isSubmitting}
          type='submit'
        >
          Sign Up
        </Button>
      </form>
    </div>
  );
}
