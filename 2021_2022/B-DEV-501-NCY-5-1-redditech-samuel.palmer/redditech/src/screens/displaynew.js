import React, {useState, useContext} from 'react';
import {SafeAreaView, StyleSheet, ScrollView, View, TouchableOpacity, Text} from 'react-native';
import PostObj from '../elements/postObj';
import FeedSearchBar from '../elements/searchBar';
import '../connection/global.js'

const FeedSelectionButton = (props) => {
  return (
    <TouchableOpacity style={styles.FeedSelectStyle}>
      <Text style={{fontSize: 14, color: "#949494", fontWeight: "400"}} >{props.text}</Text>
    </TouchableOpacity>
  );
};

const DisplayNew = () => {
  const [posts, setLoaded] = useState(null)

  async function get_userData() {
    let tmp = null
    if (!posts) {
      tmp = await global.swOBJ.getNew({limit: 60})
      setLoaded(tmp)
    }
  }
  get_userData()

  return (
    posts ? (
      <SafeAreaView style={{backgroundColor: "#121212"}}>
      <View>
        <FeedSearchBar/>
        <FeedSelectionButton text="New"/>
        <ScrollView>
            { posts.map((post, index) => {
                return (
                  <PostObj key={index} obj={post}/>
                )
              })
            }
        </ScrollView>
      </View>
      </SafeAreaView>
  ) : (
    <SafeAreaView style={{backgroundColor: "#121212"}}>
    <View>
      <FeedSearchBar/>
      <FeedSelectionButton text="New"/>
      <View style={styles.container}>
        <Text style={{color: "white", fontSize: 18}}>Loading New...</Text>
      </View>
    </View>
    </SafeAreaView>
  )
  );
};

export default DisplayNew;

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
    backgroundColor: "#121212",
    justifyContent: "center",
    alignItems: "center",
    height: "85%",
  },
});
