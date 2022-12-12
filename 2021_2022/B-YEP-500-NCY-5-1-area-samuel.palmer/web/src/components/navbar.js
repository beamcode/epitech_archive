import { useState } from 'react'
import useInterval from './refresh_func'
import logo from '../assets/dash.png';

const NavBar = () => {
  const [curTime, setcurTime] = useState(new Date().toLocaleString().split(','))

  function signOut() {
    localStorage.removeItem("token")
    window.location.href = "https://www.google.com/accounts/Logout?continue=https://appengine.google.com/_ah/logout?continue=http://localhost:3000/"
  }

  useInterval(() => {
    setcurTime(new Date().toLocaleString().split(','))
  }, 1000);

  return (
    <header style={styles.navbar_container}>
      <div style={{paddingBottom: 15, alignItems: "center", display: "flex"}}>
        <img src={logo} style={{maxHeight: "100%"}} alt='logo'/>
        <span style={styles.name}>REA</span>
        <div style={{borderStyle: "solid", borderWidth: 1, borderColor: "white", borderRadius: 5, padding: 5, textAlign: "center", margin: "0px 40px 0px 40px"}}>
          <p style={{color: "white", paddingBottom: 4, fontWeight: "500"}}>{curTime[0]}</p>
          <p style={{color: "white", fontWeight: "500"}}>{curTime[1]}</p>
        </div>
        <div style={{display: "flex"}}>
          <div style={styles.nav_button} onClick={() => {window.location.href = "/home"}}>
            <p style={styles.navbar_text}>Home</p>
          </div>
          <div style={styles.nav_button} onClick={() => {window.location.href = "/profile"}}>
            <p style={styles.navbar_text}>Profile</p>
          </div>
          <div style={styles.nav_button} onClick={() => {window.location.href = "/settings"}}>
            <p style={styles.navbar_text}>Settings</p>
          </div>
        </div>
      </div>
      <div style={{paddingBottom: 15}}>
        <button style={styles.button} onClick={signOut}>Sign Out</button>
      </div>
    </header>
  );
}

const styles = {
  name: {
    fontSize: 50,
    margin: "0px 0px 0px 0px",
    color: "white",
    fontWeight: "700",
  },
  navbar_container: {
    padding: "10px 10px 0px 25px",
    height: 55,
    backgroundColor: "#292c2f",
    display: "flex",
    justifyContent: "space-between",
  },
  button: {
    width: 100,
    height: "100%",
    borderRadius: 5,
    border: 0,
    fontSize: 15,
    color: "white",
    backgroundColor: "#58a4b0",
    cursor: "pointer",
  },
  nav_button: {
    margin: 10,
    display: "flex",
    alignItems: "center",
    cursor: "pointer",
    backgroundColor: "grey",
    borderRadius: 4,
    padding: 10,
  },
  navbar_text: {
    color: "white",
    fontWeight: "500",
  }
}

export default NavBar;
