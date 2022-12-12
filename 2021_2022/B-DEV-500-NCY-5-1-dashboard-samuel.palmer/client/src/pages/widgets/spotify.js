import { useEffect, useState } from 'react'
import { widgetcss } from './widget_css'
import useInterval from '../refresh_func'
import logo from '../../assets/spotify.svg'

import svg_play from '../../assets/play.svg'
import svg_pause from '../../assets/pause.svg'
import svg_next from '../../assets/next.svg'
import svg_prev from '../../assets/previous.svg'

const CURRENTLY_PLAYING_ENDPOINT = "https://api.spotify.com/v1/me/player/currently-playing"
const PAUSE_ENDPOINT = "https://api.spotify.com/v1/me/player/pause"
const PLAY_ENDPOINT = "https://api.spotify.com/v1/me/player/play"
const PLAY_STATE_ENDPOINT = "https://api.spotify.com/v1/me/player"
const SKIP_PREVIOUS_ENDPOINT = "https://api.spotify.com/v1/me/player/previous"
const SKIP_NEXT_ENDPOINT = "https://api.spotify.com/v1/me/player/next"

const WidgetSpotify = () => {
  const [spotify_ids, set_spotify_ids] = useState({
    spotify_id: "",
    spotify_access_token: ""
  })
  const [now_playing, set_now_playing] = useState(null)
  const [is_playing, set_is_playing] = useState(false)

  useInterval(() => {
    get_now_playing()
    spotify_playstate()
  }, 2000);

  async function get_now_playing() {
    if (!spotify_ids.spotify_access_token)
      return
    try {
      const responce = await fetch(CURRENTLY_PLAYING_ENDPOINT, {
        method: "GET",
        headers: {
          "Content-Type": "application/json",
          Authorization: "Bearer " + spotify_ids.spotify_access_token,
        },
      })
      let json = null
      if (responce.ok) {
        json = await responce.json()
        set_now_playing(json)
      }
    } catch (error) {
      console.log("spotify api error")
    }
  }

  async function spotify_pause() {
    set_is_playing(false)
    if (!spotify_ids.spotify_access_token)
      return
    const responce = await fetch(PAUSE_ENDPOINT, {
      method: "PUT",
      headers: {
        "Content-Type": "application/json",
        Authorization: "Bearer " + spotify_ids.spotify_access_token,
      },
    })
  }

  async function spotify_play() {
    set_is_playing(true)
    if (!spotify_ids.spotify_access_token)
      return
    const responce = await fetch(PLAY_ENDPOINT, {
      method: "PUT",
      headers: {
        "Content-Type": "application/json",
        Authorization: "Bearer " + spotify_ids.spotify_access_token,
      },
    })
  }

  async function spotify_playstate() {
    if (!spotify_ids.spotify_access_token)
      return
    const responce = await fetch(PLAY_STATE_ENDPOINT, {
      method: "GET",
      headers: {
        "Content-Type": "application/json",
        Authorization: "Bearer " + spotify_ids.spotify_access_token,
      },
    })
    let json = null
    if (responce.ok) {
      json = await responce.json()
      set_is_playing(json.is_playing)
    }
  }
  
  async function spotify_next() {
    if (!spotify_ids.spotify_access_token)
      return
    const responce = await fetch(SKIP_NEXT_ENDPOINT, {
      method: "POST",
      headers: {
        "Content-Type": "application/json",
        Authorization: "Bearer " + spotify_ids.spotify_access_token,
      },
    })
  }

  async function spotify_previous() {
    if (!spotify_ids.spotify_access_token)
      return
    const responce = await fetch(SKIP_PREVIOUS_ENDPOINT, {
      method: "POST",
      headers: {
        "Content-Type": "application/json",
        Authorization: "Bearer " + spotify_ids.spotify_access_token,
      },
    })
  }

  useEffect(() => {
    async function fetchData() {
      try {
        const responce = await fetch("http://localhost:1337/api/spotify/get_ids", {
          method: "GET",
          headers: {
            "Content-Type": "application/json",
            "token": localStorage.getItem('token'),
          },
        })
        let json = null;
        if (responce.ok) {
          json = await responce.json()
          set_spotify_ids(json)
        }
      } catch {
        console.log("spotify api error")
      }
    }
    fetchData()
    get_now_playing()
    spotify_playstate()
  }, []);

  return (
    <div style={widgetcss.widgbox}>
      <div style={{width: "100%", display: "flex", justifyContent: "space-between", alignItems: "center"}}>
        <div style={widgetcss.widget_title}>
          <img src={logo} height="30" alt="logo"/>
          <p style={{fontSize: 20, fontWeight: "300", color: "white", marginLeft: 10}}>Spotify</p>
        </div>
      </div>
      <div style={styles.widget_content}>
        {now_playing ? (
        <div style={{display: "flex"}}>
          <img src={now_playing.item.album.images[0].url} height="210" alt="album cover"/>
          <div style={styles.content_section}>
            <p style={{color: "white", fontSize: 20, marginBottom: 10}}>Currently Playing:</p>
            <p style={{color: "white", fontSize: 20, marginBottom: 10}}>{now_playing ? (now_playing.item.name + " by " + now_playing.item.artists[0].name) : ("no data")}</p>
            
            <div>
              <button style={styles.player_buttons} onClick={() => {spotify_previous()}}><img src={svg_prev} height="20" alt="logo"/></button>
              {is_playing ?
                (<button style={styles.player_buttons} onClick={() => {spotify_pause()}}><img src={svg_pause} height="20" alt="logo"/></button>) :
                (<button style={styles.player_buttons} onClick={() => {spotify_play()}}><img src={svg_play} height="20" alt="logo"/></button>)
              }
              <button style={styles.player_buttons} onClick={() => {spotify_next()}}><img src={svg_next} height="20" alt="logo"/></button>
            </div>
          </div>
        </div>) : (<p>Loading...</p>)}
      </div>
    </div>
  )
}

const styles = {
  widget_content: {
    marginTop: 10,
    height: "100%",
    color: "white"
  },
  player_buttons: {
    borderRadius: 100,
    height: 55,
    width: 55,
    border: 0,
    margin: 5,
    padding: 17,
    cursor: "pointer",
  },
  content_section: {
    display: "flex",
    marginLeft: 25,
    height: "100%",
    justifyContent: "space-between",
    flexDirection: "column",
  },
}

export default WidgetSpotify;
