import { StyleSheet, View, Image, Text, TouchableOpacity, ImageBackground, ScrollView, TextInput } from 'react-native';
import React, { useState, useEffect } from 'react';

const OutlookButton = (props) => {
    const [active, setActive] = useState(false)
    
    const Pressed = async() => {
        setActive(true)
        props.log(true)
    }

    return (
        <View style={{flexDirection: 'row', marginBottom: 20}}>
            <TouchableOpacity style={{backgroundColor: '#2D7FDC', width: '70%', alignSelf: 'center', height: 40, borderRadius: 10, left: 50}}
                onPress={() => Pressed()}>
                 <Text style={{fontSize: 14, color: 'white', alignSelf: 'center', top: 10}}> Connect to Outlook</Text>
            </TouchableOpacity>
                <View style={{backgroundColor: active ? 'green' : 'red', width: 30, height: 30, borderRadius: 30, left: 65, top: 5}}></View>
        </View>
    )
}

export default OutlookButton