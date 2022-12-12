import {View, Text, ScrollView} from 'react-native';
import React, { useState, useEffect } from 'react';
import NavigationBar from './NavigationBar.js'
import Header from './Header.js'


const HomePage = ({ navigation }) => {

    const [link, setLinks] = useState(null)
    const [linksView, setLinksView] = useState(null)
    useEffect(() => {
        setTimeout(()=>{
            getLinks()
            setLinksList()
        }, 1000)
    }, [link])

    const getLinks = async() => {
        const responce = await fetch("http://172.20.10.2:3001/api/getLinks", {
            method: "POST",
          headers: {"Content-Type": "application/json",},
        })
        const data = await responce.json()
        if (data) {
            setLinks(data.links)
        }
        else {
            if (data.error)
                console.log(data.error)
            else
                console.log('server error')
        }
    }

    const setLinksList = async() => {
        var li = []
        if (link) {
            for (let i = 0; i < link.length; i++) {
                li.push(
                    <View key={i}>
                            <Text style={{color:'white', top: 5, fontSize: 18, alignSelf: 'center', marginTop: 10, fontWeight: 'bold'}}>Action </Text>
                        <View style={{width: '80%', alignSelf: "center", alignItem: 'center'}}>
                            <View style={{flexDirection: 'row', alignSelf: 'center'}}>
                                <Text style={{color:'white', top: 5, fontSize: 15, alignSelf: 'center', marginTop: 10}}>{link[i][0]}</Text>
                                <Text style={{color:'white', top: 5, fontSize: 15, alignSelf: 'center', marginTop: 10}}>{link[i][1]}</Text>
                            </View>
                        </View>
                            <Text style={{color:'white', top: 5, fontSize: 18, alignSelf: 'center', marginTop: 10, fontWeight: 'bold'}}>Reaction </Text>
                        <View style={{width: '80%', alignSelf: "center", alignItem: 'center', marginBottom: 40}}>
                            <View style={{flexDirection: 'row', alignSelf: 'center'}}>
                                <Text style={{color:'white', top: 5, fontSize: 15, alignSelf: 'center', marginTop: 10}}>{link[i][2]}</Text>
                                <Text style={{color:'white', top: 5, fontSize: 15, alignSelf: 'center', marginTop: 10}}>{link[i][3]}</Text>
                            </View>
                        </View>
                        <View style={{backgroundColor: 'grey', width: '60%', height: 1, alignSelf: 'center'}}></View>
                        <View style={{width: '80%', heigth: 50, marginTop: 20}}></View>
                    </View>
                )
            }
        }
        setLinksView(li)
    }

    return (
        <View style={{flex: 1, backgroundColor: 'black'}}>
            <Header></Header>
            {link ? (
                <>
                    <Text style={{color:'white', fontSize: 22, alignSelf: 'center', marginTop: 30, marginBottom: 20, fontWeight: 'bold'}}>- Your AREA List -</Text>
                    <View style={{backgroundColor: 'grey', width: '60%', height: 1, alignSelf: 'center', marginBottom: 20}}></View>
                    <ScrollView>{linksView}</ScrollView>
                    <View style={{width: '80%', heigth: 50, marginTop: 50}}></View>
                </>
            ) : (
                <>
                    <Text style={{color:'white', top: 5, fontSize: 16, alignSelf: 'center', marginTop: 10}}>No links created</Text>
                </>
            )}
            <NavigationBar nav={navigation} home={true} link={false} profile={false}></NavigationBar>
        </View>
    )
}

export default HomePage
