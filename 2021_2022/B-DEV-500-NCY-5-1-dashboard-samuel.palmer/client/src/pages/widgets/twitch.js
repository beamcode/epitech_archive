import React from 'react'
import { widgetcss } from './widget_css'
import logo from '../../assets/twitch.png'

const WidgetTwitch = () => {
  return (
    <div style={widgetcss.widgbox}>
      <div style={widgetcss.widget_title}>
        <img src={logo} height="30" alt="logo"/>
        <p style={{fontSize: 20, fontWeight: "300", color: "white", marginLeft: 10}}>Twitch</p>
      </div>
      <div style={styles.widget_content}>
      </div>
    </div>
  );
}

const styles = {
  widget_content: {
    marginTop: 10,
    height: "100%",
    color: "white"
  }
}

export default WidgetTwitch;
