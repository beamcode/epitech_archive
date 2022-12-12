import {View, Text, TouchableOpacity, TextInput} from 'react-native';
import React, {useState} from 'react';

const RegisterInput = (props) => {
    const [email, setEmail] = useState('')
    const [password, setPassword] = useState('')
    const [cpassword, setCpassword] = useState('')
    const emailChange = (e) => {setEmail(e)}
    const passwordChange = (e) => {setPassword(e)}
    const cpasswordChange = (e) => {setCpassword(e)}
    const [error, setError] = useState(null)

    const signupUser = async() => {

      const responce = await fetch("http://172.20.10.2:3001/api/signup", {
        method: "POST",
        headers: {
        "Content-Type": "application/json",
        },
       body: JSON.stringify({email, password, cpassword})})
      const data = await responce.json()
      if (data.status === 'ok') {
        props.log()
        setError(null)
      }
      else {
        if (data.error)
          setError(data.error)
        else
          setError('Api error please contact an admin')
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
            <TextInput style={{backgroundColor: '#979797', width: '80%', height: 45, fontSize: 16, marginTop: 5, paddingLeft: 10, borderRadius: 10}}
              onChangeText={passwordChange}>
            </TextInput>
          </View>
          <View style={{alignItems: 'center', width: '100%', height: 45, marginBottom: 40}}>
            <Text style={{color: '#DBDBDB', fontSize: 12, alignSelf: 'flex-start', left: '10%'}}> Confirm Password</Text>
            <TextInput style={{backgroundColor: '#979797', width: '80%', height: 45, fontSize: 16, marginTop: 5, paddingLeft: 10, borderRadius: 10}}
              onChangeText={cpasswordChange}>
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
            onPress={() => signupUser()}>
            <Text style={{fontSize: 16, color: '#D3D3D3', alignSelf: 'center', top: '25%'}}> Register</Text>
          </TouchableOpacity>
        </>
    )
}
export default RegisterInput
