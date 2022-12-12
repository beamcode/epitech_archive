import {View, Text} from 'react-native';

const RegisterSwitch = (props) => {

    return (
        <View style={{width: '80%', height: 30 , flexDirection: 'row', alignItems: 'center', alignSelf: 'center', marginLeft: 55}}>
            <Text style={{fontSize: 13, color: 'white'}}> Already have an account ? </Text>
            <Text style={{fontSize: 13, color: '#43D337', fontWeight: '800'}}
              onPress={() => props.log()}>
              Signin now ! 
            </Text>
        </View>
    )
}

export default RegisterSwitch
