import React, { useState } from 'react';
import logo from '../assets/dash.png';
import { ReactComponent as Ggl } from '../assets/google.svg';
import { ReactComponent as Tw } from '../assets/twitter.svg';

const Input = (props) => {
  return (
    <div style={{paddingBottom: 10, width: "100%"}}>
      <input style={styles.searchBox}
             type={props.type}
             name={props.name}
             value={props.value}
             placeholder={props.placeholder}
             required autoComplete='false'
             onChange={(e) => props.onChange(e.target.value)}/>
    </div>
  )
}

function SignIn() {
  const [email, setEmail] = useState('')
  const [password, setPassword] = useState('')
  const [failedlogin, setFailMessage] = useState(false)

  const emailChange = (e) => {setEmail(e)}
  const passwordChange = (e) => {setPassword(e)}

  async function signinUser(event) {
    event.preventDefault()
    const responce = await fetch("http://localhost:1337/api/signin", {
      method: "POST",
      headers: {
        "Content-Type": "application/json",
      },
      body: JSON.stringify({
        email,
        password,
      })
    })
    const data = await responce.json()
    if (responce.ok) {
      localStorage.removeItem("token")
      localStorage.setItem('token', data.token)
      window.location.href = "/dashboard"
    } else {
      setFailMessage(true)
    }
  }

  return (
    <div style={styles.container1}>
      <div style={styles.auth_container}>
        <img src={logo} height="110" alt="logo"/>
        <span style={styles.name}>DASHY</span>
        <div style={{margin: 10}}>
          {(failedlogin) ? (<p style={styles.warnings}>• invalid credentials</p>) : (<></>)}
        </div>
        <form style={styles.form} onSubmit={signinUser} noValidate>
          <Input type='text'
                 name='username'
                 placeholder='email'
                 value={email}
                 onChange={emailChange}/>
          <Input type='password'
                 name='password'
                 placeholder='password'
                 value={password}
                 onChange={passwordChange}/>
          <button style={styles.signin_button}>Sign In</button>
        </form>
        <button style={styles.signup_button} onClick={() => document.location='signup'}>Sign up</button>
        <div>
          <button style={styles.login_gl} onClick={() => {}}>
            <Ggl fill="white" height="18"/>
          </button>
          <button style={styles.login_tw} onClick={() => {}}>
            <Tw fill="white" height="18"/>
          </button>
        </div>
        <a style={styles.bottom_text} href='/'>forgot password</a>
      </div>
    </div>
  )
}

const styles = {
  warnings: {
    color: "red",
    fontSize: 13,
    marginTop: 10,
    margin: "2px 0px 2px 0px",
  },
  form: {
    margin: 10,
  },
  searchBox: {
    outline: "none",
    padding: 10,
    border: 0,
    borderRadius: 10,
    height: 40,
    width: "100%",
    boxSizing: "border-box",
    color: "white",
    backgroundColor: "#181a1b",
  },
  container1: {
    display: "flex",
    height: "100vh",
    textAlign: "center",
    background: "#1a1c1d",
  },
  auth_container: {
    margin: "auto",
    padding: 20,
    maxWidth: 200,
    textAlign: "center",
    backgroundColor: "#32363a",
    borderRadius: 10,
    display: "inline-block",
  },
  signin_button: {
    width: 150,
    height: 40,
    borderRadius: 5,
    border: 0,
    fontSize: 15,
    margin: "5px 0px 0px 0px",
    color: "white",
    backgroundColor: "#58a4b0",
    cursor: "pointer",
  },
  signup_button: {
    width: 150,
    height: 30,
    borderRadius: 5,
    border: 0,
    fontSize: 15,
    margin: "0px 0px 10px 0px",
    color: "white",
    backgroundColor: "#2c5258",
    cursor: "pointer",
  },
  bottom_text: {
    display: "block",
    color: "white",
    fontSize: 13,
    marginTop: 15,
  },
  name: {
    display: "block",
    fontSize: 40,
    margin: 10,
    color: "white",
    fontWeight: "700",
  },
  login_gl: {
    border: 0,
    width: 70,
    height: 35,
    paddingTop: 5,
    margin: "0px 5px 5px 0px",
    borderRadius: 5,
    backgroundColor: "#db4733",
    cursor: "pointer",
  },
  login_tw: {
    border: 0,
    width: 70,
    height: 35,
    paddingTop: 5,
    margin: "0px 0px 5px 5px",
    borderRadius: 5,
    backgroundColor: "#1DA1F2",
    cursor: "pointer",
  },
}

export default SignIn;