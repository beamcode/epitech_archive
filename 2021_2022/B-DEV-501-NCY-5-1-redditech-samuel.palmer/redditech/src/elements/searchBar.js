import React from 'react';
import {SafeAreaView, StyleSheet, ScrollView, View, TouchableOpacity, Text, Button, TextInput} from 'react-native';
import AppButton from './appButton';
import { SearchBar } from 'react-native-elements';

const FeedSearchBar = () => {
  const [searchQuery, setSearchQuery] = React.useState('');

  const onChangeSearch = query => setSearchQuery(query);

  return (
    <View style={{backgroundColor: "black"}}>
      <SearchBar
        round
        darkTheme
        searchIcon={{ size: 20 }}
        onChangeText={{}}
        onClear={{}}
        placeholder="Search"
        value={""}/>
    </View>
  );
};

export default FeedSearchBar

const styles = StyleSheet.create({
  inputBar: {
    backgroundColor: "#949494",
    marginVertical: 10,
    marginHorizontal: 10,
    borderRadius: 10,
    height: 40,
  },
});
