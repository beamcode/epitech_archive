import { stringify } from 'querystring';
import React, {useState, useContext} from 'react';
import {View, Image, Text, StyleSheet, TouchableOpacity} from 'react-native';
import Ionicon from 'react-native-vector-icons/Ionicons';
import '../connection/global.js'
import FastImage from 'react-native-fast-image'
import moment from 'react-moment';

const checkValidUrl = (url) => {
  var types = ['jpg','jpeg','tiff','png','gif','bmp'];
  var parts = url.split('.');
  var extension = parts[parts.length-1];

  if (types.indexOf(extension) !== -1) {
    return true;   
  }
  else {
    return false;
  }
}

const PostText = (props) => {
  return (
    <View style={{marginHorizontal: 10}}>
      <Text style={{color: "#c9c9c9"}}>{props.text}</Text>          
    </View>
  );
};

function PostImg(props) {
  const [loaded, setLoaded] = useState(false);


  return (
    <View>
      <Image style={{height: 350}} source={{uri: props.src}}/>
    </View>
  );
};

function isValidURL(string) {
  var res = string.match(/(http(s)?:\/\/.)?(www\.)?[-a-zA-Z0-9@:%._\+~#=]{2,256}\.[a-z]{2,6}\b([-a-zA-Z0-9@:%_\+.~#?&//=]*)/g);
  return (res !== null)
};

const PostObj = (props) => {
  var created = new Date(props.obj.created_utc * 1000);
  let thumbnail = null
  if (checkValidUrl(props.obj.thumbnail))
    thumbnail = true

  return (
    <View>
      <View style={{marginTop: 20, backgroundColor: "#343434",}}>
        <View style={{margin: 10}}>
          <View style={{flexDirection: "row"}}>
            { thumbnail ?
              (<Image style={{width: 25, height: 25, borderRadius: 30, marginRight: 7}} source={{uri: props.obj.thumbnail}}/>) :
              (<Image style={{width: 25, height: 25, borderRadius: 30, marginRight: 7}} source={require('../../assets/avatar.png')}/>)
            }
            <View>
              <View style={{flexDirection: "row"}}>
                <Text style={{fontSize: 11, color: "#f5f5f5"}}>r/</Text>
                <Text style={{fontSize: 11, fontWeight: "bold", color: "#f5f5f5"}}>{props.obj.subreddit.display_name}</Text>
              </View>
              <View style={{flexDirection: "row"}}>
                <Text style={{fontSize: 11, color: "#f5f5f5"}}>u/{props.obj.author.name}</Text>
                <Text style={{fontSize: 11, color: "#f5f5f5"}}> • </Text>
                <Text style={{fontSize: 11, color: "#f5f5f5"}}>{created.getHours()}h</Text>
                <Text style={{fontSize: 11, color: "#f5f5f5"}}> • </Text>
                <Text style={{fontSize: 11, color: "#f5f5f5"}}>{props.obj.domain}</Text>
              </View>
            </View>
          </View>
          <Text style={{fontSize: 15,fontWeight: "500", marginTop: 5, color: "#f5f5f5"}}>{props.obj.title}</Text>
        </View>
        <View>
          {
            checkValidUrl(props.obj.url) ? (<PostImg src={props.obj.url}/>) : (<PostText text={props.obj.selftext}/>)
          }
        </View>


        <View style={styles.socialBtnContainer}>
          <View style={{alignItems: 'center', flexDirection: "row"}}>
            <TouchableOpacity style={styles.socialBtn3}>
              <Ionicon name="arrow-up-circle" color="#dbdbdb" style={{fontSize: 20}}/>
              <Text style={{fontSize: 13, color: "#dbdbdb", marginLeft: 2}}>{props.obj.ups}</Text>
            </TouchableOpacity>
            <TouchableOpacity style={styles.socialBtn2}>
              <Ionicon name="arrow-down-circle-outline" color="#dbdbdb" style={{fontSize: 20}}/>
            </TouchableOpacity>
          </View>
          <View>
            <TouchableOpacity style={styles.socialBtn1}>
              <Ionicon name="chatbubble-outline" color="#dbdbdb" style={{fontSize: 20}}/>
              <Text style={{fontSize: 13, color: "#dbdbdb", marginLeft: 5}} >{props.obj.num_comments}</Text>
            </TouchableOpacity>
          </View>
          <View>
            <TouchableOpacity style={styles.socialBtn1}>
              <Ionicon name="share-outline" color="#dbdbdb" style={{fontSize: 20}}/>
              <Text style={{fontSize: 13, color: "#dbdbdb", marginLeft: 3}}>Share</Text>
            </TouchableOpacity>
          </View>
        </View>
      </View>
    </View>
  );
};

export default PostObj;

const styles = StyleSheet.create({
  socialBtn1: {
    alignItems: 'center',
    justifyContent: 'center',
    flexDirection: "row",
    width: 60,
    height: 45,
  },
  socialBtn2: {
    alignItems: 'center',
      flexDirection: "row",
      width: 40,
      height: 45,
  },
  socialBtn3: {
    alignItems: 'center',
    flexDirection: "row",
    width: 65,
    height: 45,
  },
  socialBtnContainer: {
    alignItems: 'center',
    marginLeft: 10,
    marginRight: 30,
    flexDirection: "row",
    justifyContent: "space-between",
  },

});

//{ isValidURL(props.obj.thumbnail) ? (<PostImg img={props.obj.thumbnail}/>) : (<View/>)}