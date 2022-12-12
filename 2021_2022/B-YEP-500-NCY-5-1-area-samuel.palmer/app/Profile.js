import {View, Text, ImageBackground} from 'react-native';
import React, { useState, useEffect } from 'react';
import NavigationBar from './NavigationBar.js'
import YoutubeButton from './Services/Youtube.js'
import TwitterButton from './Services/Twitter.js'
import SpotifyButton from './Services/Spotify.js'
import RedditButton from './Services/Reddit.js'
import OutlookButton from './Services/Outlook.js'
import Header from './Header.js'

const Profile = ({ navigation }) => {
    const [logYoutube, isLoggedYoutube] = useState(false)
    const [logTwitter, isLoggedTwitter] = useState(false)
    const [logSpotify, isLoggedSpotify] = useState(false)
    const [logReddit, isLoggedReddit] = useState(false)
    const [logOutlook, isLoggedOutlook] = useState(false)

    useEffect(() => {
        updateSubscriptions()
    }, [logYoutube, logTwitter, logSpotify, logReddit, logOutlook]);

    const updateSubscriptions = async() => {
        const responce = await fetch("http://172.20.10.2:3001/api/services", {
            method: "POST",
            headers: {
            "Content-Type": "application/json", },
           body: JSON.stringify({logYoutube, logTwitter, logSpotify, logReddit, logOutlook,})
          })
          const data = await responce.json()
          if (data) {}
          else {
            if (data.error)
              console.log(data.error)
            else
              setError('Ferme ta gueule Samuel')
          }
    }

    const logToTwitter = async() => {isLoggedTwitter(true)}
    const logToSpotify = async() => {isLoggedSpotify(true)}
    const logToReddit = async() => {isLoggedReddit(true)}
    const logToOutlook = async() => {isLoggedOutlook(true)}

    return (
        <View style={{flex: 1, backgroundColor: 'black'}}>
            <Header></Header>
            <View style={{width:'30%', height: 100, left: '35%', marginTop: 20}}>
                <ImageBackground source={require('./assets/aberant.png')} style={{width:'100%', height: 100}}>
                </ImageBackground>
                <Text style={{color:'white', alignSelf: 'center', top: 10, fontSize: 20}}>Gerard</Text>
            </View>
            <View style={{backgroundColor: 'white', width: '30%', height: 1, alignSelf: 'center', top: 50}}></View>
            <View style={{width: '100%', height: 50, marginTop: 70}}>
                <Text style={{fontSize: 16, color: '#B7B7B7', alignSelf: 'center' }}> Connect to services you want to use</Text>
            </View>
            <TwitterButton log={logToTwitter}></TwitterButton>
            <SpotifyButton log={logToSpotify}></SpotifyButton>
            <RedditButton log={logToReddit}></RedditButton>
            <OutlookButton log={logToOutlook}></OutlookButton>
            <NavigationBar nav={navigation} home={false} link={false} profile={true}></NavigationBar>
        </View>
    )
}

export default Profile
