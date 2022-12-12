import {Image, Text, TouchableOpacity} from 'react-native';

const GoogleButton = (props) => {

    return (
        <TouchableOpacity style={{backgroundColor: '#ECECEC', width: '60%', height: 35, borderRadius: 10, alignSelf: 'center', marginTop: 30, flexDirection: 'row'}}
             onPress={() => props.co()}>
           <Image source={require('../assets/google.png')} style={{width: 25, height: 25, marginLeft: 15, marginTop: 5}}></Image>
           <Text style={{color: '#686868', fontSize: 13, marginLeft: 10, marginTop: 10, fontWeight: 'bold'}}> Continue with Google </Text>
        </TouchableOpacity>
    )
}

export default GoogleButton