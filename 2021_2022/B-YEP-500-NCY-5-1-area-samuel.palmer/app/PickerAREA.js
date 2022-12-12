import {View, Text} from 'react-native';
import React, { useState, useEffect } from 'react';
import DropDownPicker from 'react-native-dropdown-picker';

const PickerAREA = (props) => {

    const [actionList, setActionList] = useState(null)
    const [reactionList, setReactionList] = useState(null)
    const [open3, setOpen3] = useState(false);
    const [open4, setOpen4] = useState(false);
    const [twitterItemsAction, setTwitterItemsAction] = useState([{label: null, value: null}]);
    const [spotifyItemsAction, setSpotifyItemsAction] = useState([{label: null, value: null}]);
    const [redditItemsAction, setRedditItemsAction] = useState([{label: null, value: null}]);
    const [outlookItemsAction, setOutlookItemsAction] = useState([{label: null, value: null}]);
    const [twitterItemsReaction, setTwitterItemsReaction] = useState([{label: null, value: null}]);
    const [spotifyItemsReaction, setSpotifyItemsReaction] = useState([{label: null, value: null}]);
    const [redditItemsReaction, setRedditItemsReaction] = useState([{label: null, value: null}]);
    const [outlookItemsReaction, setOutlookItemsReaction] = useState([{label: null, value: null}]);

    useEffect(() => {
          setupActions()
          setupReactions()
    }, [])

    const refreshData = () => {
        setOutlookItemsReaction([{label: reactionList == null ? "loading" : reactionList.out[0], value: reactionList == null ? "loading" : reactionList.out[0]}])
        setRedditItemsReaction([{label: reactionList == null ? "loading" : reactionList.red[0], value: reactionList == null ? "loading" : reactionList.red[0]}])
        setSpotifyItemsReaction([{label: reactionList == null ? "loading" : reactionList.sp[0], value: reactionList == null ? "loading" : reactionList.sp[0]}])
        setTwitterItemsReaction([{label: reactionList == null ? "loading" : reactionList.tw[0], value: reactionList == null ? "loading" : reactionList.tw[0]}])
        setTwitterItemsAction([{label: actionList == null ? "loading" : actionList.tw[0], value: actionList == null ? "loading" : actionList.tw[0]}])
        setSpotifyItemsAction([{label: actionList == null ? "loading" : actionList.sp[0], value: actionList == null ? "loading" : actionList.sp[0]}])
        setRedditItemsAction([{label: actionList == null ? "loading" : actionList.red[0], value: actionList == null ? "loading" : actionList.red[0]}])
        setOutlookItemsAction([{label: actionList == null ? "loading" : actionList.out[0], value: actionList == null ? "loading" : actionList.out[0]}])
    }

    const setupActions = async() => {
        const responce = await fetch("http://172.20.10.2:3001/api/actions", {
          method: "POST",
          headers: {"Content-Type": "application/json",},
        })
        const data = await responce.json()
        if (data) {setActionList(data)}
        else {
          if (data.error)
            console.log(data.error)
          else
            console.log('server error')
        }
    }

    const setupReactions = async() => {
        const responce = await fetch("http://172.20.10.2:3001/api/reactions", {
          method: "POST",
          headers: {"Content-Type": "application/json",},
        })
        const data = await responce.json()
        if (data) {setReactionList(data)}
        else {
          if (data.error)
            console.log(data.error)
          else
            console.log('a')
        }
    }

    return (
        <>
        {!actionList && !reactionList ? (
            <Text style={{color:'white', top: 5, fontSize: 16, alignSelf: 'center', marginTop: 10}}>Loading</Text>
            ) : (
            <>
                <View style={{zIndex: 9}}>
                    <Text style={{color:'white', top: 5, fontSize: 16, alignSelf: 'center', marginBottom: 20}}>Action Type</Text>
                         <DropDownPicker
                            open={open3}
                            value={props.val3}
                            items={props.val == 'Twitter' ? twitterItemsAction: props.val == 'Spotify' ? spotifyItemsAction: props.val == 'Reddit' ? redditItemsAction: outlookItemsAction}
                            setOpen={setOpen3}
                            setValue={props.setval3}
                            setItems={props.val == 'Twitter' ? setTwitterItemsAction: props.val == 'Spotify' ? setSpotifyItemsAction: props.val == 'Reddit' ? setRedditItemsAction: setOutlookItemsAction}
                            onPress={() => refreshData()}
                            style={{width: '100%', height: 40, zIndex: -1}}
                            containerStyle={{width: '80%', left: 40, zIndex: -1}}/>
                </View>
                <View style={{zIndex: 8, marginBottom: 50}}>
                    <Text style={{color:'white', top: 5, fontSize: 16, alignSelf: 'center', marginTop: 10, marginBottom: 20}}>Reaction Type</Text>
                        <DropDownPicker
                            dropDownDirection="BOTTOM"
                            open={open4}
                            value={props.val4}
                            items={props.val2 == 'Twitter' ? twitterItemsReaction: props.val2 == 'Spotify' ? spotifyItemsReaction: props.val2 == 'Reddit' ? redditItemsReaction: outlookItemsReaction}
                            setOpen={setOpen4}
                            setValue={props.setval4}
                            setItems={props.val2 == 'Twitter' ? setTwitterItemsReaction: props.val2 == 'Spotify' ? setSpotifyItemsReaction: props.val2 == 'Reddit' ? setRedditItemsReaction: setOutlookItemsReaction}
                            onPress={() => refreshData()}
                            style={{width: '100%', height: 40}}
                            containerStyle={{width: '80%', left: 40}}/>
                </View>
            </>
        )}
        </>
    )
}

export default PickerAREA
