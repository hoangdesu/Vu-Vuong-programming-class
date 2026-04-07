'use client';

import { createContext, useEffect, useState } from 'react';

export const AppContext = createContext({});

export default function ContextProvider({ children }) {
  const [currentUser, setCurrentUser] = useState(null);

  useEffect(() => {
    const lsUser = localStorage.getItem('vv_currentUser');
    if (lsUser) {
      const currUser = JSON.parse(lsUser);
      setCurrentUser(currUser);
    }
  }, []);

  const contextValue = {
    currentUser,
    setCurrentUser,
  };

  return <AppContext value={contextValue}>{children}</AppContext>;
}
