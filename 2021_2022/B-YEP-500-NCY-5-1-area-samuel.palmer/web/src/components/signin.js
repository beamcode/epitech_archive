import React, { useState } from 'react';
import { ReactComponent as Ggl } from '../assets/google.svg';
import { ReactComponent as Tw } from '../assets/twitter.svg';
import GoogleLogin from 'react-google-login';
import AuthInput from './auth_input';

function SignIn(props) {
  const [email, setEmail] = useState('')
  const [password, setPassword] = useState('')
  const [warning, setWarning] = useState('')

  const emailChange = (e) => {setEmail(e)}
  const passwordChange = (e) => {setPassword(e)}

  async function signinUser(event) {
    event.preventDefault()
    fetch('http://localhost:3001/api/signin', {
      method: 'POST',
      headers: {
        'Content-Type': 'application/json',
      },
      body: JSON.stringify({
        email,
        password,
      })
    })
      .then(response => response.json())
      .then(json => {
        const data = json
        if (data.token) {
          localStorage.removeItem('token')
          localStorage.setItem('token', data.token)
          window.location.href = '/home'
        } else {
          if (data.error)
            setWarning(data.error)
          else
            throw new Error()
        }
      })
      .catch(error => {
        if (!error.response)
          setWarning('Something went wrong. Please try again')
        else
          setWarning('Api error please contact an admin')
      })
  }

    // m
    const handleFailure = (result) => {
      alert(result);
    };
  
    // m
    const handleLogin = async (googleData) => {
      const res = await fetch('http://localhost:3001/api/google-login', {
        method: 'POST',
        body: JSON.stringify({
          token: googleData.tokenId,
        }),
        headers: {
          'Content-Type': 'application/json',
        },
      })
      const data = await res.json();
      window.location.href = '/home'
    };

  return (
    <div style={styles.container}>
      <div style={styles.auth_container}>
        <h3 style={{marginBottom: 20, textAlign: 'left', color: 'white'}}>Welcome Back!</h3>
        {(warning) ? (<p style={styles.warnings}>• {warning}</p>) : (null)}
        <form style={styles.form} onSubmit={signinUser} noValidate>
          <AuthInput type='text'
                name='username'
                placeholder='email'
                value={email}
                onChange={emailChange}/>
          <AuthInput type='password'
                name='password'
                placeholder='password'
                value={password}
                onChange={passwordChange}/>
          <a style={styles.reset_password} href='/'>Forgot password?</a>
          <button style={styles.signin_button}>Sign In</button>
        </form>
        <div style={{display: 'flex', flexDirection: 'column', width: '100%', height: 90}}>
          <h4 style={{paddingBottom: 10, color: 'white'}}>Quick access with</h4>
          
          <GoogleLogin
                clientId={process.env.REACT_APP_GOOGLE_CLIENT_ID} 
                buttonText="Log in with Google"
                theme='light'
                onSuccess={handleLogin}
                onFailure={handleFailure}
                cookiePolicy={'single_host_origin'}
          ></GoogleLogin>
          
        </div>
        <div style={{marginBottom: 7, width: '100%', textAlign: 'center', borderBottom: '1px solid #fff', lineHeight: '0.1em'}}>
          <strong>
            <span style={{background: '#fff', padding: '0 10px', backgroundColor: '#32363a', color: 'white'}}>Don’t have an account?</span>
          </strong>
        </div>
        <button style={styles.signup_button} onClick={() => {props.switch(true)}}>Sign up</button>
      </div>
    </div>
  )
}

const styles = {
  warnings: {
    color: 'red',
    fontSize: 13,
    margin: '0px 0px 20px 0px',
  },
  form: {
    paddingBottom: 10,
    display: 'flex',
    width: '100%',
    flexDirection: 'column',
  },
  searchBox: {
    outline: 'none',
    padding: 10,
    border: 0,
    borderRadius: 10,
    height: 40,
    width: '100%',
    boxSizing: 'border-box',
    color: 'white',
    backgroundColor: '#181a1b',
  },
  container: {
    display: 'flex',
    justifyContent: 'center',
    height: 'calc(100vh - 65px)',
    background: '#1a1c1d',
    alignItems: 'center',
  },
  auth_container: {
    display: 'flex',
    flexDirection: 'column',
    padding: 20,
    width: 300,
    backgroundColor: '#32363a',
    alignItems: 'center',
    borderRadius: 7,
    marginBottom: 200,
  },
  signin_button: {
    fontSize: 15,
    height: 40,
    borderRadius: 3,
    border: 0,
    margin: '20px 0px 30px 0px',
    color: 'white',
    backgroundColor: '#58a4b0',
    cursor: 'pointer',
  },
  signup_button: {
    width: '100%',
    height: 30,
    borderRadius: 3,
    border: 0,
    fontSize: 15,
    margin: '10px 0px 0px 0px',
    color: 'white',
    backgroundColor: '#2c5258',
    cursor: 'pointer',
    alignItems: 'center',
  },
  reset_password: {
    textAlign: 'right',
    color: 'white',
    fontSize: 13,
  },
  login_gl: {
    border: 0,
    width: '100%',
    height: 35,
    paddingTop: 5,
    margin: '0px 0px 20px 0px',
    borderRadius: 3,
    backgroundColor: '#db4733',
    cursor: 'pointer',
    alignItems: 'center',
  },
  login_tw: {
    border: 0,
    width: '100%',
    height: 35,
    paddingTop: 5,
    margin: '0px 0px 20px 0px',
    borderRadius: 3,
    backgroundColor: '#1DA1F2',
    cursor: 'pointer',
    alignItems: 'center',
  },
  name: {
    display: 'block',
    fontSize: 40,
    margin: 10,
    color: 'white',
    fontWeight: '700',
  },
}

export default SignIn;