import React, { useState } from 'react';
import {View, SafeAreaView, StyleSheet, ScrollView } from 'react-native';
import {
  Avatar,
  Title,
  Caption,
  Text,
} from 'react-native-paper';

import Ionicons from 'react-native-vector-icons/Ionicons';
import PostObj from '../elements/postObj';
import '../connection/global.js'
import Moment from 'react-moment';

const ProfileScreen = () => {
  const [Loaded, setLoaded] = useState(false)
  let posts = null
  let cakeday = new Date()

  async function get_userData() {
    global.me = await global.swOBJ.getMe()
    //posts = await global.swOBJ.getSubmissions(global.me.name)
    cakeday = new Date(global.me.created_utc * 1000);
    setLoaded(true)
  }
  get_userData()

  return ( Loaded ? (
    <SafeAreaView style={styles.container}>
      <ScrollView>
        <View style={styles.userInfoSection}>
          <View style={{flexDirection: 'row', marginTop: 15}}>
            <Avatar.Image source={{uri: global.me.icon_img}} size={80}/>
            <View style={{marginLeft: 20}}>
              <Title style={styles.title}>{global.me.name}</Title>
              <Caption style={styles.caption}>u/{global.me.name}</Caption>
            </View>
          </View>
        </View>
        <View style={styles.userInfoSection}>
          <View style={styles.row}>
            <Ionicons name="reorder-three" color="#777777" size={25}/>
            <Text style={styles.profilDescription}>{global.me.subreddit.display_name.public_description}</Text>
          </View>
        </View>
        <View style={styles.profilStatsContainer}>
          <View style={{alignItems: "center"}}>
            <Caption style={{color: "#f5f5f5"}}>Karma</Caption>  
            <Title style={{fontSize: 19, color: "#f5f5f5"}}>{global.me.total_karma}</Title>
          </View>
          <View>
            <Caption style={{color: "#f5f5f5"}}>Followers</Caption>
            <Title style={{fontSize: 17, color: "#f5f5f5"}}>{global.me.num_friends}</Title>
          </View>
          <View>
            <Caption style={{color: "#f5f5f5"}}>Cake Day</Caption>
            <Title style={{fontSize: 17, color: "#f5f5f5"}}>{cakeday.toLocaleDateString()}</Title>
          </View>
        </View>
      </ScrollView>
    </SafeAreaView>)
    : (
    <View style={[styles.container, {justifyContent: "center", alignItems: "center"}]}>
      <Text style={{color: "white", fontSize: 18}}>Loading...</Text>
    </View>
    )
  );
};

export default ProfileScreen;

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: "#121212",
  },
  userInfoSection: {
    paddingHorizontal: 10,
    marginBottom: 15,
  },
  title: {
    fontSize: 24,
    fontWeight: 'bold',
    marginTop:10,
    marginBottom: 5,
    color: "#f5f5f5",
  },
  caption: {
    color: "#f5f5f5",
    fontSize: 14,
    lineHeight: 14,
    fontWeight: '500',
  },
  row: {
    flexDirection: 'row',
    marginBottom: 5,
  },
  infoBoxWrapper: {
    borderBottomColor: '#dddddd',
    borderBottomWidth: 1,
    borderTopColor: '#dddddd',
    borderTopWidth: 1,
    flexDirection: 'row',
    height: 70,
  },
  infoBox: {
    width: '50%',
    alignItems: 'center',
    justifyContent: 'center',
  },
  menuWrapper: {
    marginTop: 10,
  },
  menuItem: {
    flexDirection: 'row',
    paddingVertical: 15,
    paddingHorizontal: 30,
  },
  menuItemText: {
    color: '#777777',
    marginLeft: 20,
    fontWeight: '600',
    fontSize: 16,
    lineHeight: 26,
  },
  profilDescription: {
    color:"#777777",
    marginLeft: 20,
    marginRight: 40,
  },
  profilStatsContainer: {
    flexDirection: "row",
    justifyContent: "space-evenly",
    borderRightWidth: 10,
    borderLeftWidth: 10,
    borderColor: "#ED001C",
  }
});