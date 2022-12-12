import * as React from 'react';

import { SafeAreaView, ScrollView, StatusBar, StyleSheet, Text, useColorScheme, View, } from 'react-native';
import SettingsScreen from "./src/screens/settingsScreen"
import LoginScreen from "./src/screens/loginScreen"
import ProfileScreen from './src/screens/profilScreen';
import HomeScreen from './src/screens/homeScreen';

//Navigation
import { NavigationContainer } from '@react-navigation/native';
import { createBottomTabNavigator } from '@react-navigation/bottom-tabs';
import Ionicons from 'react-native-vector-icons/Ionicons';
import { createStackNavigator } from 'react-navigation-stack'

import DisplayHot from './src/screens/displayhot';
import DisplayBest from './src/screens/displaybest';
import DisplayNew from './src/screens/displaynew';

const Tab = createBottomTabNavigator();

//const screens = {}
//const boneStack = createStackNavigator({});

const AppContainer = () => {
  return (
    <NavigationContainer>
    <Tab.Navigator
      style={{backgroundColor: "black"}}
      initialRouteName="Best"
      screenOptions={{
        headerShown: false,
        tabBarActiveTintColor: 'white',
        tabBarInactiveTintColor: 'grey',
        tabBarStyle: {height: 60, paddingTop: 10, paddingBottom: 10, backgroundColor: "#121212"}
      }}
    >
      <Tab.Screen
        name="Profil"
        component={ProfileScreen}
        options={{
          tabBarIcon: ({ color, size }) => (
            <Ionicons name="person-circle" size={25} color={color} />
          ),
        }}
      />
      <Tab.Screen
        name="New"
        component={DisplayNew}
        options={{
          tabBarIcon: ({ color, size }) => (
            <Ionicons name="arrow-up" size={25} color="#5a9bdb" />
          ),
        }}
      />
      <Tab.Screen
        name="Best"
        component={DisplayBest}
        options={{
          tabBarIcon: ({ color, size }) => (
            <Ionicons name="star" size={25} color="#f5c000" />
          ),
        }}
      />
      <Tab.Screen
        name="Hot"
        component={DisplayHot}
        options={{
          tabBarIcon: ({ color, size }) => (
            <Ionicons name="flame" size={25} color="#db4942" />
          ),
        }}
      />
      <Tab.Screen
        name="Settings"
        component={SettingsScreen}
        options={{
          tabBarIcon: ({ color, size }) => (
            <Ionicons name="settings-outline" size={25} color={color} />
          ),
        }}
      />
    </Tab.Navigator>
    </NavigationContainer>
  );
};

export default AppContainer