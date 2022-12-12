import {View, Text, TouchableOpacity} from 'react-native';
import React, {useState} from 'react';
import NavigationBar from './NavigationBar.js'
import Header from './Header.js'
import PickerServices from './PickerServices.js'
import PickerAREA from './PickerAREA.js'
import './global.js'

const Links = ({ navigation }) => {

    const [value, setValue] = useState(null);
    const [value2, setValue2] = useState(null);
    const [value3, setValue3] = useState(null);
    const [value4, setValue4] = useState(null);

    const [succes, isSucces] = useState(false)
    const [error, isError] = useState(false)

    const getLocalToken = () => {
        return global.token
    }

    const createLink = async() => {
        if (value == null || value2 == null || value3 == null || value4 == null) {
            isSucces(false)
            isError(true)
            return
        }
        isSucces(true)
        isError(false)
        const response = await fetch("http://172.20.10.2:3001/api/newLink", {
          method: "POST",
          headers: {
            "Content-Type": "application/json", 
            "token": getLocalToken()},
          body: JSON.stringify({
              value,
              value2,
              value3,
              value4,})
        })
        const data = await response.json();
    }

    return (
        <View style={{flex: 1, backgroundColor: 'black'}}>
                <Header></Header>
                <Text style={{color:'white', top: 5, fontSize: 20, alignSelf: 'center', marginTop: 50, fontWeight: 'bold'}}>Create Action - Reaction</Text>
                <View style={{backgroundColor: 'white', width: '30%', height: 1, alignSelf: 'center', top: 20, marginBottom: 15}}></View>
                <View style={{width: '100%', height: 30, marginTop: 30, flexDirection: 'row'}}>
                    <Text style={{color:'white', top: 5, fontSize: 16, left: 37}}>Service's action</Text>
                    <Text style={{color:'white', fontSize: 16, left: 105, top: 5}}>Service's Reaction</Text>
                </View>
                <View style={{width: '100%', height: 80, marginTop: 10, flexDirection: 'row', zIndex: 20}}>
                    <PickerServices val={value} val2={value2} setval={setValue} setval2={setValue2}></PickerServices>
                </View>
                <View style={{backgroundColor: 'white', width: '80%', height: 1, alignSelf: 'center'}}></View>
                <View style={{width: '100%', height: 80, marginTop: 10, zIndex: 10}}>
                    <PickerAREA val={value} val2={value2} val3={value3} setval3={setValue3} val4={value4} setval4={setValue4}></PickerAREA>
                    <TouchableOpacity style={{width: '30%', height: 50, backgroundColor: 'green', alignSelf: 'center', borderRadius: 30}}
                          onPress={() => createLink()}>
                         <Text style={{color:'white', top: 5, fontSize: 16, alignSelf: 'center', marginTop: 10}}>Create</Text>
                    </TouchableOpacity>
                    {succes && <Text style={{color:'green', top: 15, fontSize: 16,  alignSelf: 'center'}}>New link created succesfully !</Text>}
                    {error && <Text style={{color:'red', top: 15, fontSize: 16,  alignSelf: 'center'}}>Error : Invalid selection</Text>}
                </View>
            <NavigationBar nav={navigation} home={false} link={true} profile={false}></NavigationBar>
        </View>
    )
}

export default Links
