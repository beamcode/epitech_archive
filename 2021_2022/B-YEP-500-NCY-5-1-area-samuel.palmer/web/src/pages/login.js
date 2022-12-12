import React, { useState } from 'react';
import Signin from '../components/signin'
import Signup from '../components/signup'
import AuthHeader from '../components/auth_header';

function Login() {
  const [SignUp, setSignup] = useState(false)

  return (
    <>
      <AuthHeader/>
      {SignUp ? (<Signup switch={setSignup}/>) : (<Signin switch={setSignup}/>)}
    </>
  )
}

export default Login;