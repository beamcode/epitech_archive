import React, { useState } from 'react';
import { useNavigate } from 'react-router-dom'
import AuthInput from './auth_input';

function SignUp(props) {
  const navigate = useNavigate()
  const [email, setEmail] = useState('')
  const [password, setPassword] = useState('')
  const [cpassword, setCpassword] = useState('')
  const [sucess, setSucess] = useState(false)
  const [warning, setWarning] = useState('')

  const emailChange = (e) => {setEmail(e)}
  const passwordChange = (e) => {setPassword(e)}
  const cpasswordChange = (e) => {setCpassword(e)}

  async function createUser(event) {
    event.preventDefault()
    fetch('http://localhost:3001/api/signup', {
      method: "POST",
      headers: {
        "Content-Type": "application/json",
      },
      body: JSON.stringify({
        email,
        password,
        cpassword,
      })
    })
      .then(response => response.json())
      .then(json => {
        const data = json
        if (data.status === 'ok') {
          setSucess(true)
          setTimeout(function() {navigate('/');}, 1300);
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

  return (
    <div style={styles.container}>
      <div style={styles.auth_container}>
        <h3 style={{marginBottom: 20, textAlign: 'left', color: 'white'}}>Welcome to AREA!</h3>
        {(sucess) ? (
          <>
            <p style={styles.messages}>Successfully registered !</p>
            <p style={styles.messages}>Please wait...</p>
          </>
        ) : (
          <>
            {(warning) ? (<p style={styles.warnings}>• {warning}</p>) : (null)}
            <form style={styles.form} onSubmit={createUser} noValidate>
              <AuthInput type='text'
                name='username'
                placeholder='email'
                value={email}
                onChange={emailChange} />
              <AuthInput type='password'
                name='password'
                value={password}
                placeholder='password'
                onChange={passwordChange} />
              <AuthInput type='password'
                name='password'
                value={cpassword}
                placeholder='confirm password'
                onChange={cpasswordChange} />
              <button style={styles.signin_button}>Create account</button>
            </form>
            <button style={styles.small_button} onClick={() => {props.switch(false)}}>back to Login</button>
          </>
        )}
      </div>
    </div>
  )
}

const styles = {
  warnings: {
    color: "red",
    fontSize: 13,
    margin: "0px 0px 20px 0px",
  },
  messages: {
    color: "#36D13E",
    fontSize: 17,
    marginTop: 10,
    margin: "2px 0px 2px 0px",
  },
  form: {
    paddingBottom: 10,
    display: "flex",
    width: "100%",
    flexDirection: "column",
    alignItems: "center",
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
    width: 150,
    height: 40,
    borderRadius: 3,
    border: 0,
    fontSize: 15,
    margin: "10px 0px 0px 0px",
    color: "white",
    backgroundColor: "#58a4b0",
    cursor: "pointer",
  },
  small_button: {
    width: 150,
    height: 30,
    borderRadius: 3,
    border: 0,
    fontSize: 15,
    marginTop: 10,
    color: "white",
    backgroundColor: "grey",
    cursor: "pointer",
  },
  name: {
    display: "block",
    fontSize: 40,
    margin: 10,
    color: "white",
    fontWeight: "700",
  },
}

export default SignUp;