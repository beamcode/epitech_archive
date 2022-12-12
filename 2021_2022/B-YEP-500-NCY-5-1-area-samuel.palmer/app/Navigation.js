import { NavigationContainer } from '@react-navigation/native';
import { createNativeStackNavigator } from '@react-navigation/native-stack';
import HomePage from './HomePage.js'
import Profile from './Profile.js'
import Links from './Links.js'

const Stack = createNativeStackNavigator();

const Navigation = (props) => {

    return (
      <NavigationContainer>
        <Stack.Navigator screenOptions={{headerShown: false, animation: 'none'}}>
          <Stack.Screen name="Home" component={HomePage}/>
          <Stack.Screen name="Profile" component={Profile}/>
          <Stack.Screen name="Links" component={Links}/>
        </Stack.Navigator>
      </NavigationContainer>
    )
}

export default Navigation