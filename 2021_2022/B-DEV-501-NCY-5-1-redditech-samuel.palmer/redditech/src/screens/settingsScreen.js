import React, { useState } from 'react';
import { Text, View, Switch, StyleSheet } from 'react-native';
import { ScrollView } from 'react-native-gesture-handler';
import { List } from 'react-native-paper';
import ToggleSwitch from 'toggle-switch-react-native';
import AppButton from '../elements/appButton';
import authMe from '../connection/asyncAuth';

const SettingToggle = (props) => {
  const [isEnabled, setIsEnabled] = useState(props.current);
  const toggleSwitch = () => setIsEnabled(previousState => !previousState);

  return (
    <View style={styles.settingsCont}>
      <View style={{flexGrow: 1}}>
        <Text style={{fontSize: 17, color: "#f5f5f5", maxWidth: 270}}>{props.label}</Text>
      </View>
      <View>
        <ToggleSwitch size="Large" isOn={isEnabled} onToggle={async () => {

          await global.swOBJ.updatePreferences(isEnabled ? (props.off) : (props.on)); 

          {isEnabled ? (setIsEnabled(false)) : (setIsEnabled(true))}} }/>
      </View>
    </View>
  )
}

const SettingsScreen = () => {
  const [settings, setLoaded] = useState(null)

  async function get_userSettings() {
    let tmp = null
    if (!settings) {
      tmp = await global.swOBJ.getPreferences()
      setLoaded(tmp)
      console.log(tmp.hide_from_robots)
    }
  }
  get_userSettings()

  return ( settings ? (
    <ScrollView style={{backgroundColor: "#121212"}}>
        <View style={{flex: 1, alignItems: 'center', margin: 10, justifyContent: "space-around"}}>
          <SettingToggle label="Show up in search results"
                        on={{"hide_from_robots": false}}
                        off={{"hide_from_robots": true}}
                        current={settings.hide_from_robots ? (false) : (true)}/>
          <SettingToggle label="Personalize all of Reddit based on the outbound links you click on"
                        on={{"allow_clicktracking": true}}
                        off={{"allow_clicktracking": false}}
                        current={settings.allow_clicktracking}/>

          <SettingToggle label="Personalize ads based on information from our partners"
                        on={{"third_party_data_personalized_ads": true}}
                        off={{"third_party_data_personalized_ads": false}}
                        current={settings.third_party_data_personalized_ads}/>

          <SettingToggle label="Personalize ads based on your activity with our partners"
                        on={{"third_party_site_data_personalized_ads": true}}
                        off={{"third_party_site_data_personalized_ads": false}}
                        current={settings.third_party_site_data_personalized_ads}/>
          
          <SettingToggle label="Personalize recommendations based on your general location"
                        on={{"show_location_based_recommendations": true}}
                        off={{"show_location_based_recommendations": false}}
                        current={settings.show_location_based_recommendations}/>

          <SettingToggle label="Personalize recommendations based on your activity with our partners"
                        on={{"third_party_site_data_personalized_content": true}}
                        off={{"third_party_site_data_personalized_content": false}}
                        current={settings.third_party_site_data_personalized_content}/>
      </View>
    </ScrollView>
    ) : (
      <View style={{flex: 1, backgroundColor: "#121212", justifyContent: "center", alignItems: "center"}}>
        <Text style={{color: "white", fontSize: 18}}>Loading...</Text>
      </View>
    )
  );
}

export default SettingsScreen;

const styles = StyleSheet.create({
  settingsCont: {
    paddingVertical: 10,
    flexDirection: "row",
    alignItems: "center",
    width: "100%",
    borderBottomWidth: 2,
    borderColor: "grey",
  },
  
});