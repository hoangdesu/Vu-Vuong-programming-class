'use client';

import { useContext, useEffect, useState } from 'react';
import { AppContext } from './ContextProvider';

export default function Header() {
  //   const [currentUser, setCurrentUser] = useState(null);

  //   useEffect(() => {
  //     const lsUser = localStorage.getItem('currentUser');
  //     if (lsUser) {
  //       setCurrentUser(JSON.parse(lsUser));
  //     }
  //   }, []);

  const { currentUser } = useContext(AppContext);

  return (
    <div className='w-full bg-red-500 py-4 px-32 flex justify-between'>
      <div>
        <h1>Logo</h1>
      </div>

      {currentUser ? (
        <div>
          <p>{currentUser.username}</p>
          <button>Log out</button>
        </div>
      ) : (
        <div>
          <button>Sign up</button>
          <button>Sign in</button>
        </div>
      )}
    </div>
  );
}
