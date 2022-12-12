import {View} from 'react-native';
import GoogleButton from "./GoogleButton.js"
import ConnexionHeader from "./ConnexionHeader.js"
import RegisterSwitch from './RegisterSwitch.js';
import RegisterInput from './RegisterInput.js';

const Register = (props) => {

    return (
        <>
          <View style={{backgroundColor: 'black', width: '100%', marginBottom: 30}}></View>
          <ConnexionHeader title={"Register to Area"}></ConnexionHeader>         
          <RegisterInput co={props.co} log={props.log}></RegisterInput>       
          <RegisterSwitch log={props.log}></RegisterSwitch>
          <GoogleButton co = {props.co}></GoogleButton>
        </>
    )
}

export default Register