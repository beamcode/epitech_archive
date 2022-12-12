const mongoose = require('mongoose')

const User = new mongoose.Schema({
    email: {type: String, required: true, unique: true},
    password: {type: String, required: true},
    twitter_token: {type: String},
    spotify_token: {type: String},
    reddit_token: {type: String},
    outlook_token: {type: String}
  },
  {
    collection: 'user-data',
    versionKey: false 
  }
)

const model = mongoose.model('UserData', User)

module.exports = model