import React, {useState, useContext} from 'react';
import {SafeAreaView, StyleSheet, ScrollView, View, TouchableOpacity, Text} from 'react-native';
import '../connection/global.js'

import DisplayHot from './displayhot';
import DisplayBest from './displaybest';
import DisplayNew from './displaynew';

import FeedSearchBar from '../elements/searchBar'

import { createBottomTabNavigator } from '@react-navigation/bottom-tabs';
import { NavigationContainer } from '@react-navigation/native';

const HomeScreen = () => {
  return (
    <SafeAreaView style={{backgroundColor: "#121212"}}>
      <DisplayBest/>
    </SafeAreaView>
  );
};

export default HomeScreen;

const styles = StyleSheet.create({
  FeedSelectStyle: {
    alignItems: 'center',
    justifyContent: 'center',
    flexDirection: "row",
    flexGrow: 1,
    backgroundColor: "#2b2b2b",
    height: 30,
  },
  container: {
    flex: 1,
    backgroundColor: "#121212",
  },
});
