import React, { useState } from 'react';
import logo from '../assets/dash.png';
import { useNavigate } from 'react-router-dom'

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

function SignUp() {
  const navigate = useNavigate()
  const [email, setEmail] = useState('')
  const [password, setPassword] = useState('')
  const [cpassword, setCpassword] = useState('')
  const [match, setMatch] = useState(false)
  const [lengh, setLengh] = useState(false)
  const [sucess, setSucess] = useState(false)
  const [exist, setExist] = useState(false)

  const emailChange = (e) => {setEmail(e)}
  const passwordChange = (e) => {setPassword(e)}
  const cpasswordChange = (e) => {setCpassword(e)}

  async function registerUser(event) {
    event.preventDefault()
    setExist(false)
    setMatch(false)
    setLengh(false)
    if (password !== cpassword) {
      setMatch(true)
      return
    }
    if (password.length < 6) {
      setLengh(true)
      return
    }
    const responce = await fetch("http://localhost:1337/api/signup", {
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
    if (data.status === 'ok') {
      setSucess(true)
      setTimeout(function(){navigate('/');}, 1500);
		} else {
      setExist(true)
    }
  }

  return (
    <div style={styles.container1}>
      <div style={styles.auth_container}>
        <img src={logo} height="110" alt="logo"/>
        <span style={styles.name}>DASHY</span>
        {(sucess) ? (<p style={styles.messages}>• Successfully registered!</p>) : (
        <><div style={{ margin: 10 }}>
            {(match) ? (<p style={styles.warnings}>• password does not match</p>) : (<></>)}
            {(lengh) ? (<div><p style={styles.warnings}>• password must be minumum 6 characters</p></div>) : (<></>)}
            {(exist) ? (<div><p style={styles.warnings}>• email already exists!</p></div>) : (<></>)}
          </div>
          <form style={styles.form} onSubmit={registerUser} noValidate>
              <Input type='text'
                name='username'
                placeholder='email'
                value={email}
                onChange={emailChange} />
              <Input type='password'
                name='password'
                value={password}
                placeholder='password'
                onChange={passwordChange} />
              <Input type='password'
                name='password'
                value={cpassword}
                placeholder='confirm password'
                onChange={cpasswordChange} />
              <button style={styles.signin_button}>Register</button>
            </form><a style={styles.bottom_text} href='/'>go back</a></>
        )}
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
  messages: {
    color: "#36D13E",
    fontSize: 17,
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
    margin: "0px 0px 20px 0px",
    color: "white",
    fontWeight: "700",
  },
}

export default SignUp;