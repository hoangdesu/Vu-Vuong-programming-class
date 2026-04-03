'use client';

import { createContext, use, useEffect, useState } from 'react';

export const AppContext = createContext({});

export default function ContextProvider({ children }) {
  const [currentUser, setCurrentUser] = useState(null);
  
  const [appContext, setAppContext] = useState({
    currentUser,
    setCurrentUser,
  });

  useEffect(() => {
    const lsUser = localStorage.getItem('currentUser');
    if (lsUser) {
      const currUser = JSON.parse(lsUser);
      setCurrentUser(currUser);

      setAppContext((prev) => ({ ...prev, currentUser: currUser }));
    }
  }, []);

  return <AppContext value={appContext}>{children}</AppContext>;
}
