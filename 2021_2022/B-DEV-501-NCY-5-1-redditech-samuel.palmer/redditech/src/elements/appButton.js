import React, { useState, useCallback, useMemo } from 'react';
import { StyleSheet, View, Text, Button, TouchableOpacity, Image } from 'react-native';

const AppButton = (props) => {
  return(
    <TouchableOpacity style={styles.button2} onPress={props.action}>
      <Text style={{ fontSize: 15, color: "white"}} >{props.text}</Text>
    </TouchableOpacity>
  )
};

export default AppButton

const styles = StyleSheet.create({
  button2: {
    alignItems: 'center',
    backgroundColor: '#787878',
    padding: 10,
    margin: 10,
    borderRadius: 10,
    width: 150,
    height: 40,
  },
});