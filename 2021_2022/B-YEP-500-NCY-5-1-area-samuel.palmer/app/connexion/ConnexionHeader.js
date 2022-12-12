import {View, Image, Text} from 'react-native';

const ConnexionHeader = (props) => {

    return (
        <View style={{alignItems: 'center', marginBottom: 30}}>
            <Image source={require('../assets/logo1.png')} style={{width: 110, height: 80, alignSelf: 'center', top: '10%', left: 2}}></Image>
            <Text style={{color: '#43D337', fontSize: 26, fontWeight: 'bold'}}> AREA</Text>
            <Text style={{color: 'grey', fontSize: 18, fontWeight: 'bold', top: '15%'}}> {props.title}</Text>
        </View>
    )
}

export default ConnexionHeader