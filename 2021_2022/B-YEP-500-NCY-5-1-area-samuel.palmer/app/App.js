import {View} from 'react-native';
import React, {useState} from 'react';
import Connexion from "./Connexion.js"
import Navigation from "./Navigation.js"

export default function App() {
  const [connect, isConnected] = React.useState(false)

  const connectUser = async() => {
      isConnected(true)
  }
  
  return (
    <View style={{flex: 1, backgroundColor: 'black'}}>
      {connect ? (
        <>
          <Navigation></Navigation>
        </>
      ) : (
        <>
          <Connexion co={connectUser}></Connexion>
        </>
      )}
    </View>
  );
}
