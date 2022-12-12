import {View} from 'react-native';
import GoogleButton from "./GoogleButton.js"
import ConnexionHeader from "./ConnexionHeader.js"
import LoginSwitch from './LoginSwitch.js'
import LoginInput from './LoginInput.js'


const Login = (props) => {

    return (
        <>
          <View style={{backgroundColor: 'black', width: '100%', height: 30, marginBottom: 30}}></View>
          <ConnexionHeader title={"Log in to Area"}></ConnexionHeader>
          <LoginInput co={props.co}></LoginInput>
          <LoginSwitch reg={props.reg}></LoginSwitch>
          <GoogleButton co = {props.co}></GoogleButton>
        </>
    )
}

export default Login