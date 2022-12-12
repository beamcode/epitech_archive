import {Text} from 'react-native';
import React, { useState, useEffect } from 'react';
import DropDownPicker from 'react-native-dropdown-picker';

const PickerServices = (props) => {

    const [open, setOpen] = useState(false);
    const [open2, setOpen2] = useState(false);
    const [servicesList, setServicesList] = useState(null);
    const [items, setItems] = useState([{label: null, value: null},{label: null, value: null},{label: null, value: null},{label: null, value: null}]);
    const [items2, setItems2] = useState([{label: null, value: null},{label: null, value: null},{label: null, value: null},{label: null, value: null}]);

    useEffect(() => {
        getServices()
    }, [])

    const refreshData = () => {
        setItems([{label: servicesList.list[0], value: 'Twitter'},{label: servicesList.list[1], value: 'Spotify'},{label: servicesList.list[2], value: 'Reddit'},{label: servicesList.list[3], value: 'Outlook'}]);
        setItems2([{label: servicesList.list[0], value: 'Twitter'},{label: servicesList.list[1], value: 'Spotify'},{label: servicesList.list[2], value: 'Reddit'},{label: servicesList.list[3], value: 'Outlook'}]);
    }

    const getServices = async() => {
        const responce = await fetch("http://172.20.10.2:3001/api/list", {
          method: "POST",
          headers: {"Content-Type": "application/json",},
        })
        const data = await responce.json()
        if (data) {setServicesList(data)}
        else {
          if (data.error)
            console.log(data.error)
          else
            console.log('server error')
        }
    }

    return (
        <>
            {!servicesList ? (
                <Text style={{color:'white', top: 5, fontSize: 16, alignSelf: 'center', marginTop: 10}}>Loading</Text>
            ) : (
            <>
                <DropDownPicker
                    open={open}
                    value={props.val}
                    items={items}
                    setOpen={setOpen}
                    setValue={props.setval}
                    setItems={setItems}
                    onPress={() => refreshData()}
                    style={{width: '100%', height: 40, zIndex: 1}}
                    containerStyle={{width: '40%', left: 20, zIndex: 1}}/>
                <DropDownPicker
                    open={open2}
                    value={props.val2}
                    items={items2}
                    setOpen={setOpen2}
                    setValue={props.setval2}
                    setItems={setItems}
                    onPress={() => refreshData()}
                    style={{width: '100%', height: 40, zIndex: -1}}
                    containerStyle={{width: '40%', left: 60, zIndex: -1}}/>
            </>
            )}
        </>
    )
}

export default PickerServices
