import React, { useState, useEffect } from 'react'
import NavBar from '../components/navbar.js'
import Footer from '../components/footer.js'
import bg from '../assets/back3.jpg';
import getLocalToken from '../components/getToken'

const SelectTag = (props) => {
  return (
    <div style={{ display: 'flex', flexDirection: 'column', alignItems: 'center', margin: 10 }}>
      <label style={{ color: 'white', marginBottom: 10 }}>{props.label}</label>
      <select style={{ padding: 10, borderRadius: 10, border: '3px grey solid', width: 300, outline: 'none' }} 
        onChange={(e) => {
          props.setter(e.target.value)
        }}>
        {props.list.map((val, index) =>
          <option key={index}>{val}</option>)}
      </select>
    </div>
  )
}

const SettingsPage = () => {
  const [warning, setWarning] = useState(null)
  const [message, setMessage] = useState(null)
  const [servicesData, setServicesData] = useState(null)
  const [serviceList, setServiceList] = useState(null)

  const [service1, setService1] = useState(null)
  const [service2, setService2] = useState(null)
  const [action, setAction] = useState(null)
  const [reaction, setReaction] = useState(null)

  function updateservice1(service) {
    setService1(service)
    setAction(servicesData[service].actions[0])
  }

  function updateservice2(service) {
    setService2(service)
    setReaction(servicesData[service].reactions[0])
  }

  async function getServices() {
    fetch("http://localhost:3001/api/services", {
      method: "POST",
      headers: {
        "Content-Type": "application/json",
        "token": getLocalToken()
      },
    })
      .then(response => {
        if (response.ok)
          return response.json()
        else
          throw new Error(response)
      })
      .then(json => {
        const data = json

        if (data.result) {
          const tmp = Object.values(data.result)
          let tmp2 = []
          for (let i = 0; i < tmp.length; i++)
            tmp2.push(tmp[i].service)
          setServiceList(tmp2)
          setService1(tmp[0].service)
          setService2(tmp[0].service)
          setAction(tmp[0].actions[0])
          setReaction(tmp[0].reactions[0])
          setServicesData(data.result)
        } else {
          if (data.error)
            setWarning(data.error)
          else
            throw new Error()
        }
      })
      .catch(error => {
        setWarning('Something went wrong. Please reload')
      })
  }

  async function createLink() {
    fetch("http://localhost:3001/api/newLink", {
      method: "POST",
      headers: {
        "Content-Type": "application/json",
        "token": getLocalToken()
      },
      body: JSON.stringify({
        value: service1,
        value2: service2,
        value3: action,
        value4: reaction
      })
    })
      .then(response => {
        if (!response)
          throw new Error(response)
        else
          return response.json()
      })
      .then(json => {
        const data = json
        if (data.message) {
          setMessage(data.message)
        } else {
          if (data.error)
            setWarning(data.error)
          else
            throw new Error()
        }
      })
      .catch(error => {
        setWarning('Something went wrong. Please reload')
      })
  }

  useEffect(() => {
    getServices()
  }, [])

  return (
    <>
      <NavBar />
      <div style={styles.main}>
        <div style={styles.content}>
          <div>
            <p style={{ fontSize: 20, color: 'white', fontWeight: '600' }}>Create Action - Reaction</p>
            {(message) ? (<p style={styles.messages}>• {message}</p>) : (null)}
            {(warning) ? (<p style={styles.warnings}>• {warning}</p>) : (null)}
            <hr />
            {(!servicesData || !service1 || !service2) ? (
              <h3 style={{ color: 'white' }}>LOADING...</h3>
            ) : (
              <div style={{ display: 'flex' }}>
                <SelectTag label='Service Action' list={serviceList} setter={updateservice1} />
                <SelectTag label='Service Reaction' list={serviceList} setter={updateservice2} />
              </div>
            )}
            <hr />
            {(!servicesData || !service1 || !service2) ? (
              <h3 style={{ color: 'white' }}>LOADING...</h3>
            ) : (
              <div style={{ display: 'flex' }}>
                <SelectTag label='Action Type' list={servicesData[service1].actions} setter={setAction} />
                <SelectTag label='Reaction Type' list={servicesData[service2].reactions} setter={setReaction} />
              </div>
            )}
          </div>
          <button style={styles.button} onClick={createLink}>Create</button>
        </div>
      </div>
      <Footer />
    </>
  );
}

const styles = {
  main: {
    minHeight: 470,
    height: 'calc(100vh - (65px + 152px + 100px))',
    backgroundImage: `url(${bg})`,
    padding: '50px 0px 50px 0px',
  },
  content: {
    padding: '40px 60px 30px 60px',
    height: '89%',
    minHeight: 370,
    display: 'flex',
    flexDirection: 'column',
    justifyContent: 'space-between',
    backgroundColor: '#60686c',
  },
  selectdiv: {
    background: 'transparent',
    width: 150,
    fontSize: 16,
    border: '1px solid #CCC',
    height: 34,
  },
  button: {
    width: 100,
    height: 40,
    borderRadius: 5,
    border: 0,
    fontSize: 15,
    color: "white",
    backgroundColor: "#58a4b0",
    cursor: "pointer",
  },
  warnings: {
    color: 'red',
    fontSize: 13,
    margin: '20px 0px 20px 0px',
  },
  messages: {
    color: '#36D13E',
    fontSize: 13,
    margin: '20px 0px 20px 0px',
  },
}

export default SettingsPage;
