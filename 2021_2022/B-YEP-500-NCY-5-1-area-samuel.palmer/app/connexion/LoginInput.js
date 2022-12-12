import {View, Text, TouchableOpacity, TextInput } from 'react-native';
import React, { useState, useEffect } from 'react';
import '../global.js'
import GoogleLogin from 'react-google-login';

const LoginInput = (props) => {
  const [email, setEmail] = useState('')
  const [password, setPassword] = useState('')
  const emailChange = (e) => {setEmail(e)}
  const passwordChange = (e) => {setPassword(e)}
  const [error, setError] = useState(null)

    const signinUser = async() => {
        const responce = await fetch("http://172.20.10.2:3001/api/signin", {
          method: "POST",
          headers: {
          "Content-Type": "application/json",
          },
         body: JSON.stringify({email, password})
        })
        const data = await responce.json()
        if (data.token) {
          global.token = data.token
          props.co()
          setError(null)
        }
        else {
          if (data.error)
            setError(data.error)
          else
            setError('error')
        }
   }

    return (
        <>
          <View style={{alignItems: 'center', width: '100%', height: 40, marginBottom: 40}}>
            <Text style={{color: '#DBDBDB', fontSize: 12, alignSelf: 'flex-start', left: '10%'}}> Email</Text>
            <TextInput style={{backgroundColor: '#979797', width: '80%', height: 45, fontSize: 16, marginTop: 5, paddingLeft: 10, borderRadius: 10}}
            onChangeText={emailChange}>
            </TextInput>
          </View>
          <View style={{alignItems: 'center', width: '100%', height: 45, marginBottom: 40}}>
            <Text style={{color: '#DBDBDB', fontSize: 12, alignSelf: 'flex-start', left: '10%'}}> Password</Text>
            <TextInput
              style={{backgroundColor: '#979797', width: '80%', height: 45, fontSize: 16, marginTop: 5, paddingLeft: 10, borderRadius: 10}}
              onChangeText={passwordChange}>
            </TextInput>
          </View>

          {error ? (
              <View style={{alignSelf: 'center', width: '80%', height: 30, bottom: 10, marginTop: 10}}>
                <Text style={{color: 'red', fontSize: 14, alignSelf: 'center', top: 5}}> Error : {error}</Text>
              </View>
            ) : (
            <View style={{alignSelf: 'center', width: '80%', height: 0, bottom: 0}}></View>
            )}
          <TouchableOpacity style={{backgroundColor: '#177208', width: '40%', height: 45, alignSelf: 'center', borderRadius: 40, marginBottom: 10}}
            onPress={() => signinUser()}>
            <Text style={{fontSize: 16, color: '#D3D3D3', alignSelf: 'center', top: '25%'}}> Log In</Text>
          </TouchableOpacity>
        </>
    )
}
export default LoginInput
