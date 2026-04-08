'use client';

import { useContext, useEffect, useState } from 'react';
import { AppContext } from './store/ContextProvider';
import Link from 'next/link';
import { useRouter } from 'next/navigation';

export default function Header() {
  //   const [currentUser, setCurrentUser] = useState(null);

  //   useEffect(() => {
  //     const lsUser = localStorage.getItem('currentUser');
  //     if (lsUser) {
  //       setCurrentUser(JSON.parse(lsUser));
  //     }
  //   }, []);

  const router = useRouter();
  const { currentUser, setCurrentUser } = useContext(AppContext);

  const handleSignOut = () => {
    localStorage.removeItem('vv_currentUser');
    setCurrentUser(null);
    // router.refresh();
  };

  return (
    <div className='w-full bg-red-500 py-4 px-32 flex justify-between'>
      <div>
        {/* <h1>Logo</h1> */}
        <Link href="/">Home</Link>

      </div>

      {currentUser ? (
        <div>
          {/* <p>{currentUser.name}</p> */}
          <Link href={`/users/${currentUser.id}`}>{currentUser.name}</Link >
          <button
          onClick={handleSignOut}
          >
            Log out
          </button>
        </div>
      ) : (
        <div>
          {/* <a href='/signup'>Sign up</a> */}
          {/* <Link href="/signup">Sign up</Link> */}
          {/* <button>Sign in</button> */}

          <Link href="/signup">Sign up</Link>
          <Link href="/signin">Sign in</Link>
        </div>
      )}
    </div>
  );
}
