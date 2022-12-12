import {View, Image, TouchableOpacity} from 'react-native';

const NavigationBar = (props) => {

    return (
        <View style={{backgroundColor: 'grey', width: '100%', height: 50, position: 'absolute', bottom: 0, left: 0, flexDirection: 'row'}}>                
            <TouchableOpacity style={{width: 40, height: 40, alignSelf: 'center', marginLeft: 30}}
                onPress={() => props.nav.navigate('Links')}>
                {!props.link == true ? (
                    <Image source={require('./assets/link.png')} style={{width: 30, height: 30, alignSelf: 'center', right: '8%', top: 5}}></Image>
                ) : (
                    <Image source={require('./assets/link2.png')} style={{width: 30, height: 30, alignSelf: 'center', right: '8%', top: 5}}></Image>
                )}
            </TouchableOpacity>
            <TouchableOpacity style={{width: 40, height: 40, alignSelf: 'center', marginLeft: 100}}
                onPress={() => props.nav.navigate('Home')}>
                {!props.home == true ? (
                    <Image source={require('./assets/h.png')} style={{width: 30, height: 30, alignSelf: 'center', right: '8%', top: 5}}></Image>
                ) : (
                    <Image source={require('./assets/h2.png')} style={{width: 30, height: 30, alignSelf: 'center', right: '8%', top: 5}}></Image>
                )}
            </TouchableOpacity>
            <TouchableOpacity style={{width: 40, height: 40, alignSelf: 'center', marginLeft: 100}}
                onPress={() => props.nav.navigate('Profile')}>
                {!props.profile == true ? (
                    <Image source={require('./assets/pro.png')} style={{width: 30, height: 30, alignSelf: 'center', top: 5}}></Image>
                ) : (
                    <Image source={require('./assets/pro2.png')} style={{width: 38, height: 38, alignSelf: 'center', top: 1}}></Image>
                )}
            </TouchableOpacity>
        </View>
    )
}

export default NavigationBar