import { StyleSheet, View, Image, Text, TouchableOpacity, ImageBackground, ScrollView, TextInput } from 'react-native';
import React, { useState, useEffect } from 'react';
import { authorize } from 'react-native-app-auth';
import '../global.js'

const SpotifyButton = (props) => {
  const config = {
    clientId: '90521e89b5044c7fa06d687a0a271f8c', // available on the app page
    clientSecret: '6e4b8b6e0e4941398ce62a5576ac0f8a', // click "show client secret" to see this
    redirectUrl: 'com.app:/oauth', // the redirect you defined after creating the app
    scopes: [
      'user-read-currently-playing',
      'user-read-playback-state',
      'playlist-read-private',
      'user-modify-playback-state',
      'user-read-private',
      'user-read-playback-state',
      'app-remote-control'
    ], // the scopes you need to access
    serviceConfiguration: {
      authorizationEndpoint: 'https://accounts.spotify.com/authorize',
      tokenEndpoint: 'https://accounts.spotify.com/api/token',
    },
  }

  const [active, setActive] = useState(false)
  const [data, setData] = useState(false)

  const Pressed = async () => {
    setActive(true)
    props.log(true)
  }

  const getLocalToken = () => {
    return global.token
  }

  async function oauth() {
    const authState = await authorize(config);
  }

  async function getServices() {
    fetch("http://172.20.10.2:3001/api/services", {
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
        const data = json.result
        setData(data)
        setActive(data.Spotify.oauthmobile)
      })
      .catch(error => {
        console.log(error)
      })
  }
  
  useEffect(() => {
    getServices()
  }, [])

  return (
    <View style={{ flexDirection: 'row', marginBottom: 20 }}>
      <TouchableOpacity style={{ backgroundColor: '#158304', width: '70%', alignSelf: 'center', height: 40, borderRadius: 10, left: 50 }}
        onPress={() => { oauth() }}>
        <Text style={{ fontSize: 14, color: 'white', alignSelf: 'center', top: 10 }}> Connect to Spotify</Text>
      </TouchableOpacity>
      <View style={{ backgroundColor: active ? 'green' : 'red', width: 30, height: 30, borderRadius: 30, left: 65, top: 5 }}></View>
    </View>
  )
}

export default SpotifyButton