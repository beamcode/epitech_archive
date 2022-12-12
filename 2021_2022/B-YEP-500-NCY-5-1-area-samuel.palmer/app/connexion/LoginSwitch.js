import {View, Text} from 'react-native';

const LoginSwitch = (props) => {

    return (
        <View style={{width: '80%', height: 30 , flexDirection: 'row', alignItems: 'center', alignSelf: 'center', marginLeft: 58}}>  
            <Text style={{fontSize: 13, color: 'white'}}> Don't have an account ? </Text>
            <Text style={{fontSize: 13, color: '#43D337', fontWeight: '800'}}
              onPress={() => props.reg()}>
              Signup now ! 
            </Text>
        </View>
    )
}

export default LoginSwitch