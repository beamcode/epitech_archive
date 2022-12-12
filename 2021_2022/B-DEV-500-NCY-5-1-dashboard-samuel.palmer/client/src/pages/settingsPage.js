import React, { useState, useEffect } from 'react'
import NavBar from './navbar.js'
import Background from '../assets/back3.jpg';

const authorize = "https://www.reddit.com/api/v1/authorize"
const access = "https://www.reddit.com/api/v1/access_token"

const Input = (props) => {
  return (
    <div style={styles.input_componenets}>
      <div style={{display: "flex", justifyContent: "space-between", alignItems: "center", marginBottom: 5}}>
        <p style={styles.field_lable}>{props.label}</p>
        <div style={{display: "flex", alignItems: "center"}}>
          <p style={{marginRight: 5, fontSize: 13, color: "white"}}>Token: {props.name}</p>
          <button type="button" onClick={props.login}>Login</button>
        </div>
      </div>
      <div style={{whiteSpace: "nowrap"}}>
        <input style={styles.searchBox}
                 type={props.type}
                 name={props.name}
                 value={props.data[props.name]}
                 required autoComplete='false'
                 onChange={(e) => props.onChange(e)}/>
      </div>
    </div>
  )
}

const SettingsPage = () => {
  const [show_warnings, set_show_warnings] = useState(false)
  const [api_responce, set_api_responce] = useState(false)
  const [user_ids, set_user_ids] = useState({
    spotify_id: "", spotify_access_token: "",
    weather_id: "", weather_access_token: "",
    steam_id: "", steam_access_token: "",
    reddit_id: "", reddit_access_token: "",
    twitch_id: "", twitch_access_token: "",
    youtube_id: "", youtube_access_token: "",
  });

  // SPOTIFY LOGIN
  async function loginSpotify() {
    localStorage.setItem('service', 'spotify')
    const responce = await fetch("http://localhost:1337/api/spotify/getauthurl", {
      method: "GET",
      headers: {
        "Content-Type": "application/json",
        "token": localStorage.getItem('token'),
      },
    })
    let json = null;
    if (responce.ok) {
      json = await responce.json()
      window.location = json.authURL
    }
  }

  // SPOTIFY STORE TOKEN FROM URL
  async function storeSpotifyToken(spotify_responce) {
    await fetch("http://localhost:1337/api/spotify/storetoken", {
      method: "POST",
      headers: {
        "Content-Type": "application/json",
        "token": localStorage.getItem('token'),
      },
      body: JSON.stringify({
        data: spotify_responce,
      })
    })
  }

  // LOGIN TWITCH
  async function loginTwitch() {
    localStorage.setItem('service', 'twitch')
    const responce = await fetch("http://localhost:1337/api/twitch/getauthurl", {
      method: "GET",
      headers: {
        "Content-Type": "application/json",
        "token": localStorage.getItem('token'),
      },
    })
    let json = null;
    if (responce.ok) {
      json = await responce.json()
      window.location = json.authURL
    }
  }

  // LOGIN REDDIT
  async function loginReddit() {
    localStorage.setItem('service', 'reddit')
    const responce = await fetch("http://localhost:1337/api/reddit/getauthurl", {
      method: "GET",
      headers: {
        "Content-Type": "application/json",
        "token": localStorage.getItem('token'),
      },
    })
    let json = null;
    if (responce.ok) {
      json = await responce.json()
      window.location = json.authURL
    }
  }

  // GET EXISTING DATA
  useEffect(() => {
    async function fetchData() {
      const responce = await fetch("http://localhost:1337/api/settings/getsettings", {
        method: "GET",
        headers: {
          "Content-Type": "application/json",
          "token": localStorage.getItem('token'),
        },
      })
      let json = null
      if (responce.ok) {
        json = await responce.json()
        set_user_ids(json)
      }
    }
    fetchData()
    if (window.location.hash) {
      if (localStorage.getItem('service') === "spotify") {
        storeSpotifyToken(window.location.hash)
      } else if (localStorage.getItem('service') === "reddit") {
        console.log("reddit")
      }
    }
    localStorage.removeItem('service')
  }, [])

  // STORE UPDATED SETTINGS
  async function submitSettings(event) {
    event.preventDefault()
    const responce = await fetch("http://localhost:1337/api/settings/setsettings", {
      method: "POST",
      headers: {
        "Content-Type": "application/json",
        "token": localStorage.getItem('token'),
      },
      body: JSON.stringify(user_ids)
    })
    if (responce.ok) {
      set_api_responce(true)
    } else {
      set_api_responce(false)
    }
    set_show_warnings(true)
  }

  const handleChange = (event) => {
    set_user_ids({ ...user_ids, [event.target.name]: event.target.value });
  };

  return (
    <div>
      <NavBar/>
      <div style={styles.content_container}>
        <div style={styles.settings_container}>
          <form onSubmit={submitSettings} noValidate>
            <Input type='text'
                   name='spotify_id'
                   label='Spotify Client ID'
                   data={user_ids}
                   login={loginSpotify}
                   onChange={handleChange}/>

            <Input type='text'
                   name='reddit_id'
                   label='Reddit Client ID'
                   data={user_ids}
                   login={loginReddit}
                   onChange={handleChange}/>

            <Input type='text'
                   name='weather_id'
                   label='WeatherAPI.com Key'
                   data={user_ids}
                   login={() => {}}
                   onChange={handleChange}/>

            <Input type='text'
                   name='steam_id'
                   label='Steam Client ID'
                   data={user_ids}
                   login={loginSpotify}
                   onChange={handleChange}/>

            <Input type='text'
                   name='twitch_id'
                   label='Twitch Client ID'
                   data={user_ids}
                   login={loginTwitch}
                   onChange={handleChange}/>

            <Input type='text'
                   name='youtube_id'
                   label='Youtube Client ID'
                   data={user_ids}
                   login={loginSpotify}
                   onChange={handleChange}/>

            <div style={{display: "flex", alignItems: "center", justifyContent: "space-between", marginTop: 30}}>
              <div>
                {show_warnings ? (<>{api_responce ? (<p style={{color: "#41F13E", fontWeight: "600"}}>Succesfully Updated!</p>) :
                (<p style={{color: "red", fontWeight: "600"}}>Failed to Update</p>)}</>) : (<></>)}
              </div>
              <button style={styles.apply_button}>Apply</button>
            </div>
          </form>
        </div>
      </div>
    </div>
  );
}

const styles = {
  content_container: {
    padding: 70,
    height: '100vh',
    display: 'flex',
    flexWrap: "wrap",
    justifyContent: "center",
    backgroundImage: `url(${Background})`,
    backgroundSize: "100% 100%"
  },
  settings_container: {
    height: "max-content",
    width: "max-content",
    padding: 25,
    display: 'flex',
    borderRadius: 10,
    alignItems: "center",
    justifyContent: "center",
    backgroundColor: "grey",
  },
  searchBox: {
    outline: "none",
    boxSizing: "border-box",
    width: 350,
  },
  apply_button: {
    width: 100,
    height: 30,
    borderRadius: 5,
    border: 0,
    fontSize: 15,
    color: "white",
    backgroundColor: "#58a4b0",
    cursor: "pointer",
  },
  input_componenets: {
    marginBottom: 30,
    display: "block",
    justifyContent: "space-between",
  },
  field_lable: {
    color: "white",
    fontWeight: 600,
    width: 140,
  }
}

export default SettingsPage;
