import React from 'react';
import logo from '../assets/dash.png';

function AuthHeader() {
  return (
    <header style={styles.header}>
      <div style={styles.logo}>
        <img src={logo} height="35" alt="logo"/>
        <span style={styles.name}>REA</span>
      </div>
    </header>
  )
}

const styles = {
  header: {
    textAlign: 'center',
    backgroundColor: '#32363a',
    lineHeight: 'normal',
    padding: '15px 0px 15px 0px',
  },
  logo: {
    display: 'flex',
    flexDirection: 'row',
    justifyContent: 'center',
  },
  name: {
    color: 'white',
    fontSize: 43,
    alignSelf: 'flex-end',
    lineHeight: 0.8,
  }
}

export default AuthHeader;