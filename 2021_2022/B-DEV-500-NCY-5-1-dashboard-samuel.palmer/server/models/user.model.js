const mongoose = require('mongoose')

const User = new mongoose.Schema(
  {
    email: {type: String, required: true, unique: true},
    password: {type: String, required: true},
    //random
    defined_widgets: {type: String},
    // spotify
    spotify_id: {type: String},
    spotify_access_token: {type: String},
    // reddit
    reddit_id: {type: String},
    reddit_access_token: {type: String},
    // twitch
    twitch_id: {type: String},
    twitch_access_token: {type: String},
    // youtube
    youtube_id: {type: String},
    youtube_access_token: {type: String},
    // weather
    weather_id: {type: String},
    weather_access_token: {type: String},
    // steam
    steam_id: {type: String},
    steam_access_token: {type: String},
  },
  { collection: 'user-data' }
)

const model = mongoose.model('UserData', User)
module.exports = model