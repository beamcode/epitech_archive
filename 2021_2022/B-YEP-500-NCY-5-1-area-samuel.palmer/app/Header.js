import { View, Image, ImageBackground } from 'react-native';

const Header = () => {
    return (
        <View style={{ width: '100%', maxHeight: 100 }}>
            <ImageBackground source={require('./assets/area.jpg')} style={{ height: 60, borderRadius: 50, flexDirection: 'row' }}>
                <Image source={require('./assets/logo1.png')} style={{ width: 150, height: 80, alignSelf: 'center', top: '8%', right: '8%' }}>
                </Image>
            </ImageBackground>
        </View>
    )
}

export default Header