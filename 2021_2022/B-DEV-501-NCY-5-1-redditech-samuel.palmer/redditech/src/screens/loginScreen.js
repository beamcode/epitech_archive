import React, { useState, useCallback, useMemo } from 'react';
import { StyleSheet, View, Text, Image } from 'react-native';
import loginAuth from '../connection/auth';
import AppButton from '../elements/appButton';
import '../connection/global.js'
import authMe from '../connection/asyncAuth';

const LoginScreen = (props) => {
  const [tokenString, setValue] = useState("");
  return (
    <View style={styles.global}>
      <View style={styles.logo}>
        <Image
          source={require('../../assets/reddit.png')} 
          style={{ width: 50, height: 50}}/>
        <Text style={styles.title}>Reddit</Text>
      </View>
      <View>
        <Text style={{maxWidth: 200,fontSize: 15, marginTop: 10, color: "white"}}>༼ つ ◕_◕ ༽つ</Text>
      </View>
      <View>
        <AppButton text="Login" action={async () => {await authMe(); props.checklogin()}}/>
      </View>
    </View>
  );
};

export default LoginScreen;

const styles = StyleSheet.create({
  title: {
    color: "#bf0003",
    fontSize: 26,
    fontWeight: 'bold',
    margin: 15
  },
  global: {
    flex: 1,
    backgroundColor: "#343434",
    alignItems: 'center',
    paddingVertical: 50,
    justifyContent: "space-between"
  },
  logo: {
    flexDirection: "row",
    alignItems: "center",
  }
});