import React, { useState, setState } from 'react';
import './src/connection/global'
import AppContainer from './Container'
import LoginScreen from './src/screens/loginScreen';
import {SafeAreaView, StyleSheet, ScrollView, View, TouchableOpacity, Text} from 'react-native';

const App = () => {
  const [isSignedIn, check_login] = useState(false)

  function is_loggedin() {
    if (global.userData != null && isSignedIn == false)
        check_login(true);
  }
  is_loggedin()

  return (
    isSignedIn ? (
      <AppContainer/>
    ) : (
      <LoginScreen checklogin={is_loggedin}/>
    )
  );
};

export default App