import React, { useEffect } from 'react'
import jwt from 'jsonwebtoken'
import { useNavigate } from 'react-router-dom'
import WidgetSpotify from './widgets/spotify.js'
import WidgetWeather from './widgets/weather.js'
import WidgetReddit from './widgets/reddit.js'
import WidgetTwitch from './widgets/twitch.js'
import WidgetTwitter from './widgets/twitter.js'
import WidgetSteam from './widgets/steam.js'
import NavBar from './navbar.js'
import Background from '../assets/back3.jpg';

const MainPage = () => {
  const navigate = useNavigate()

  useEffect(() => {
		const token = localStorage.getItem('token')
		if (token) {
			const user = jwt.decode(token)
			if (!user) {
				localStorage.removeItem('token')
				navigate('/')
			}
		} else {navigate('/')}
	}, [navigate])

  return (
    <div>
      <NavBar/>
      <div style={styles.dash_container}>
        <div style={styles.widget_container}>
          <WidgetSpotify/>
          <WidgetWeather/>
          <WidgetTwitch/>
          <WidgetSteam/>
          <WidgetTwitter/>
          <WidgetReddit/>
        </div>
      </div>
    </div>
  );
}

const styles = {
  dash_container: {
    padding: 70,
    height: '100vh',
    display: 'flex',
    flexWrap: "wrap",
    justifyContent: "center",
    backgroundImage: `url(${Background})`,
    backgroundSize: "100% 100%"
  },
  widget_container: {
    display: "flex",
    flexWrap: "wrap",
    justifyContent: "center",
    height: "max-content",
  },
}

export default MainPage;
