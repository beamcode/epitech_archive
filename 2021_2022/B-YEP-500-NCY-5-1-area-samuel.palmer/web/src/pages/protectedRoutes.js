import React from 'react'
import { Outlet, Navigate } from 'react-router'

const ProtectedRoutes = () => {
  // const logIn = JSON.parse(localStorage.getItem("token"));
  const logIn = true;

  return logIn ? <Outlet/> : <Navigate to='/'/>
}

export default ProtectedRoutes;
