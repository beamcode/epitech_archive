import React, { useState, useEffect } from 'react';
import NavBar from '../components/navbar'
import Footer from '../components/footer'
import profilepic from '../assets/profile.jpg';
import bg from '../assets/back3.jpg';
import { useNavigate } from 'react-router-dom'
import getLocalToken from '../components/getToken'

function ServiceButton(props) {
  let statusColor = props.status ? { backgroundColor: '#21d817' } : { backgroundColor: 'red' }
  return (
    <div style={{ display: 'flex', justifyContent: 'space-between', height: 30, alignItems: 'center' }}>
      <span style={{ ...styles.dot, ...statusColor }}></span>
      <hr style={{ width: 70, height: 0 }} />
      <button style={{ ...styles.button, backgroundColor: props.color }} onClick={() => {localStorage.setItem('service', props.service); props.onClick() }}>{props.text}</button>
    </div>
  )
}

function Profile() {
  const navigate = useNavigate()
  const [warning, setWarning] = useState(null)
  const [message, setMessage] = useState(null)
  const [services, setServices] = useState(null)

  async function getServices() {
    fetch("http://localhost:3001/api/services", {
      method: "POST",
      headers: {
        "Content-Type": "application/json",
        "token": getLocalToken()
      }
    })
      .then(response => {
        if (response) 
          return response.json()
        else
          throw new Error(response)
      })
      .then(json => {
        const data = json
        if (data.result) {
          setServices(data.result)
          //console.log(data.result)
        } else {
          if (data.error)
            setWarning(data.error)
          else
            throw new Error()
        }
      })
      .catch(error => {
        console.log(error)
        setWarning('Something went wrong. Please reload')
      })
  }

  async function storetoken(tokenData) {
    fetch("http://localhost:3001/api/storeservicetoken", {
      method: "POST",
      headers: {
        "Content-Type": "application/json",
        "token": getLocalToken()
      },
      body: JSON.stringify(tokenData)
    })
      .then(response => {
        if (response.statusText == 'OK')
          return
        else
          throw new Error()
      })
      .catch(error => {
        console.log(error)
        setWarning('Something went wrong. Please reload')
      })
  }

  useEffect(() => {
    if (window.location.hash) {
      const tokendata = {
        service: localStorage.getItem('service'),
        token: window.location.hash,
        href: window.location.href
      }
      storetoken(tokendata)
      window.location.href = '/profile'
      localStorage.removeItem('service')
    }
    getServices()
  }, [])

  return (
    <>
      <NavBar />
      <div style={{ height: 'calc(100vh - (65px + 152px + 100px))', backgroundImage: `url(${bg})`, padding: '50px 0px 50px 0px' }}>
        <div style={{ backgroundColor: '#60686c', height: '100%' }}>
          <div style={{ backgroundColor: '#60686c', padding: '40px 60px 30px 60px' }}>
            {(message) ? (<p style={styles.messages}>• {message}</p>) : (null)}
            {(warning) ? (<p style={styles.warnings}>• {warning}</p>) : (null)}
            <div style={{ display: 'flex', paddingBottom: 20 }}>
              <img style={{ height: 100, borderRadius: 100 }} src={profilepic} alt='profile' />
              <h1 style={{ margin: '20px 20px 0px 20px', fontSize: 20, fontWeight: 550, color: 'white' }}>Manu Macaron</h1>
            </div>
            <hr />
            <div style={{ height: 300, width: 400, marginTop: 20, display: 'flex', flexDirection: 'column', justifyContent: 'space-between' }}>
              <p style={{ marginBottom: 20, fontSize: 20, color: 'white' }}>Connect to the services you want to use</p>
              {!services ? (
                <h3 style={{ color: 'white' }}>LOADING...</h3>
              ) : (
                Object.values(services).map((val, index) => 
                  <ServiceButton key={index} status={val.status} color={val.color} text={'Connect to ' + val.service} service={val.service} onClick={() => { window.location = val.oauth }} />)
              )}
            </div>
          </div>
        </div>
      </div>
      <Footer />
    </>
  )
}

const styles = {
  button: {
    width: 250,
    height: 40,
    borderRadius: 5,
    border: 0,
    fontSize: 15,
    color: 'white',
    cursor: 'pointer',
  },
  dot: {
    height: 40,
    width: 40,
    borderRadius: '50%',
    display: 'inline-block',
    border: '2px solid grey'
  },
  warnings: {
    color: 'red',
    fontSize: 13,
    margin: '0px 0px 20px 0px',
  },
  messages: {
    color: '#36D13E',
    fontSize: 13,
    margin: '0px 0px 20px 0px',
  },
}

export default Profile;