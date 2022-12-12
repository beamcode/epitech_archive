import { useEffect, useState } from 'react'
import { widgetcss } from './widget_css'
import logo from '../../assets/weather.png'
import useInterval from '../refresh_func';

const WEATHER_ENDPOINT = "http://api.weatherapi.com/v1/current.json?key="

const WidgetWeather = () => {
  const [weather_ids, set_weather_ids] = useState({
    weather_id: "",
    weather_access_token: ""
  })
  const [city, set_city] = useState('paris')
  const [weather, set_weather] = useState('')

  useInterval(() => {
    if (weather_ids.weather_id)
      getWeather()
  }, 10000);

  async function getWeather() {
    if (!weather_ids.weather_id)
      return
    const combined_endpoint = WEATHER_ENDPOINT + weather_ids.weather_id + "&q=" + city + "&aqi=no"
    const responce = await fetch(combined_endpoint, {
      method: "GET",
      headers: {
        "Content-Type": "application/json",
      },
    })
    let json = null
    if (responce.ok) {
      json = await responce.json()
      set_weather(json)
    }
  }

  useEffect(() => {
    async function fetchData() {
      const responce = await fetch("http://localhost:1337/api/weather/get_ids", {
        method: "GET",
        headers: {
          "Content-Type": "application/json",
          "token": localStorage.getItem('token'),
        },
      })
      let json = null;
      if (responce.ok) {
        json = await responce.json()
        set_weather_ids(json)
      }
    }
    fetchData()
    getWeather()
  }, []);

  const handleInput= (event) => {
    set_city(event.target.value);
  };

  const handleChangeCity = (event) => {
    event.preventDefault()
    getWeather()
  };

  return (
    <div style={widgetcss.widgbox}>
      <div style={widgetcss.widget_title}>
        <img src={logo} height="30" alt="logo"/>
        <p style={{fontSize: 20, fontWeight: "300", color: "white", marginLeft: 10}}>Weather</p>
      </div>
      <div style={styles.widget_content}>
        {weather ? (<>
          <div style={{}}>
            <img src={"https:" + weather.current.condition.icon} style={styles.weather_icon} height="210" alt="weather icon"/>
          </div>
          <div style={styles.content_section}>
            <div>
              <p style={{fontSize: 40, marginBottom: 10}}>{weather.location.name}</p>
              <p style={{fontSize: 20, marginBottom: 5}}>Temp: {weather.current.temp_c} °c</p>
              <p style={{fontSize: 20, marginBottom: 5}}>Wind: {weather.current.wind_kph} km/h</p>
              <p style={{fontSize: 20, marginBottom: 5}}>Humidity: {weather.current.humidity}%</p>
            </div>
            <form style={{}} onSubmit={handleChangeCity}>
              <input style={styles.searchBox}
                    type="text"
                    name="city"
                    value={city}
                    required autoComplete='false'
                    onChange={(e) => handleInput(e)}/>
              <button style={styles.weather_button}>Done</button>
            </form>
          </div>
        </>) : (<p>Loading...</p>)}
        
      </div>
    </div>
  );
}

const styles = {
  widget_content: {
    display: "flex",
    marginTop: 10,
    height: "100%",
    color: "white"
  },
  searchBox: {
    outline: "none",
    padding: 16,
    border: 0,
    borderRadius: 5,
    height: 30,
    width: 125,
    boxSizing: "border-box",
    color: "white",
    backgroundColor: "#181a1b",
  },
  weather_button: {
    marginLeft: 10,
    width: 60,
    height: 30,
    borderRadius: 5,
    border: 0,
    fontSize: 15,
    color: "white",
    backgroundColor: "#58a4b0",
    cursor: "pointer",
  },
  content_section: {
    display: "flex",
    marginLeft: 25,
    height: "100%",
    justifyContent: "space-between",
    flexDirection: "column",
  },
  weather_icon: {
    borderStyle: "solid",
    borderWidth: 1,
    borderColor: "white",
    borderRadius: 20,
    backgroundColor: "white",
  }
}

export default WidgetWeather;
