// get config vars
const dotenv = require('dotenv');
dotenv.config();

const express = require('express')
const app = express()
const app2 = express()
const cors = require("cors")
const mongoose = require('mongoose')
const User = require('./models/user.model')
const jwt = require('jsonwebtoken')
const bcrypt = require('bcryptjs');

// CONNECT TO MONGOOSE DB
mongoose.connect('mongodb://127.0.0.1:27017/dashboard_db').then(() => {
  console.log("Connected to Database");
}).catch((err) => {
  console.log("Not Connected to Database ERROR! FUCK YOU", err);
});

app.use(cors())
app.use(express.json())
 
// CLIENT SESSION CHECK
function authToken(req, res, next) {
  const token = req.headers.token

  if (token == null)
    return res.status(403).json({error: "token is null"})
  jwt.verify(token, process.env.TOKEN_SECRET, 
    (err, user) => {
      if (err)
        return res.status(403).json({error: "invalid token please re-login"})
      req.user = user
      next()
    })
  return
}

// SIGNUP API
app.post('/api/signup', async (req, res) => {
  try {
    //check email and password format here
    const newPassword = await bcrypt.hash(req.body.password, 10)
    await User.create({
      email: req.body.email,
      password: newPassword,
      spotify_id: "no id set", spotify_access_token: "no token set",
      reddit_id: "no id set", reddit_access_token: "no token set",
      twitch_id: "no id set", twitch_access_token: "no token set",
      youtube_id: "no id set", youtube_access_token: "no token set",
      weather_id: "no id set", weather_access_token: "no token set",
      steam_id: "no id set", steam_access_token: "no token set"
    })
    res.json({status: 'ok'})
  } catch (err) {
    res.status(203).json({error: "account already exists"})
  }
})

// SIGNIN API
app.post('/api/signin', async (req, res) => {
  const user = await User.findOne({
    email: req.body.email,
  })
  const isPasswordValid = await bcrypt.compare(req.body.password, user.password)

  if (isPasswordValid) {
    const token = jwt.sign(
      {email: user.email,},
      process.env.TOKEN_SECRET,
      {expiresIn: process.env.JWT_EXPIRES_IN}
    )
    return res.status(200).json({token: token})
  } else {
    res.status(404).json({error: "api error"})
  }
})

// TOKEN FETCHER API
app.get('/api/settings/getsettings', authToken, async (req, res) => {
  let user = await User.findOne({email: req.user.email})

  try {
    if (!user)
      throw error
    res.status(200).json({
      spotify_id: user.spotify_id, spotify_access_token: user.spotify_access_token,
      reddit_id: user.reddit_id, reddit_access_token: user.reddit_access_token,
      twitch_id: user.twitch_id, twitch_access_token: user.twitch_access_token,
      youtube_id: user.youtube_id, youtube_access_token: user.youtube_access_token,
      weather_id: user.weather_id, weather_access_token: user.weather_access_token,
      steam_id: user.steam_id, steam_access_token: user.steam_access_token,
    })
  } catch (err) {
    res.status(404).json({error: "api error"})
  }
})

// TOKEN AND ID SETTER API
app.post('/api/settings/setsettings', authToken, async (req, res) => {
  let user = await User.findOne({email: req.user.email})
  try {
    if (!user)
      throw error
    const body = req.body
    await User.findOneAndUpdate({email: user.email}, { $set: {
      spotify_id: body.spotify_id, spotify_access_token: body.spotify_access_token,
      reddit_id: body.reddit_id, reddit_access_token: body.reddit_access_token,
      twitch_id: body.twitch_id, twitch_access_token: body.twitch_access_token,
      youtube_id: body.youtube_id, youtube_access_token: body.youtube_access_token,
      weather_id: body.weather_id, weather_access_token: body.weather_access_token,
      steam_id: body.steam_id, steam_access_token: body.steam_access_token,
    }})
    res.status(200).json({status: "ok"})
  } catch (err) {
    res.status(404).json({error: "api error"})
  }
})


///////////////////////////////////////
// SPOTIFY API'S
///////////////////////////////////////

// GET GERNERATED OAUTH2 URL FOR SPOTIFY
app.get('/api/spotify/getauthurl', authToken, async (req, res) => {
  let user = await User.findOne({email: req.user.email})
  const SPOTIFY_AUTHORIZE_ENDPOINT = "https://accounts.spotify.com/authorize"
  const REDIRECT_URL_AFTER_LOGIN = "http://localhost:3000/settings"
  const SPACE_DELIMITER = "%20"
  const SCOPES = [
    "user-read-currently-playing",
    "user-read-playback-state",
    "playlist-read-private",
    "user-modify-playback-state",
    "user-read-private",
    "user-read-playback-state",
    "app-remote-control"
  ]
  const CLIENT_ID = user.spotify_id
  const SCOPES_URL_PARAM = SCOPES.join(SPACE_DELIMITER)
  const authURL = SPOTIFY_AUTHORIZE_ENDPOINT + "?client_id="
    + CLIENT_ID + "&redirect_uri=" + REDIRECT_URL_AFTER_LOGIN
    + "&scope=" + SCOPES_URL_PARAM + "&response_type=token&show_dialog=true"
  try {
    res.status(200).json({authURL: authURL})
  } catch (err) {
    res.status(404).json({error: "api error"})
  }
})

// DECODE AND STORE SPOTIFY TOKEN
app.post('/api/spotify/storetoken', authToken, async (req, res) => {
  let user = await User.findOne({email: req.user.email})
  const decodeResult = (hash) => {
    const stringAfterHashtag = hash.substring(1);
    const paramsInUrl = stringAfterHashtag.split("&");
    const paramsSplitUp = paramsInUrl.reduce((accumulater, currentValue) => {
      const [key, value] = currentValue.split("=");
      accumulater[key] = value;
      return accumulater;
    }, {});
    return paramsSplitUp;
  }
  try {
    const tmp = decodeResult(req.body.data).access_token
    if (!user.spotify_access_token)
      await User.findOneAndUpdate({email: user.email}, {$set: {spotify_access_token: tmp}})
    else 
      await User.findOneAndUpdate({email: user.email}, {spotify_access_token: tmp})
    user = await User.findOne({email: req.user.email})
    res.status(200).json({status: "ok"})
  } catch (err) {
    res.status(404).json({error: "api error"})
  }
})

app.get('/api/spotify/get_ids', authToken, async (req, res) => {
  let user = await User.findOne({email: req.user.email})
  try {
    res.status(200).json({
      spotify_access_token: user.spotify_access_token,
      spotify_id: user.spotify_id
    })
  } catch (err) {
    res.status(404).json({error: "api error"})
  }
})

app.get('/about.json', async (req, res) => {
    const time = new Date().getTime()
    res.status(200).json(
      {
        client: {
          host: req.hostname,
        },
        server: {
          current_time: time,
          services: [{
            name: "weather",
            widgets: [{
              name: "city_temperature",
            description: " Display temperature for a city" ,
            params: [{
              name: "city",
              type: "string"
            }]
          }]
        }, {
            name: "spotify",
            widgets: [{
              name: "spotify",
              description: "Displaying a interactive spotify player",
              params: [{
                name: "link",
                type: "string"
              }, {
                name: "number",
                type: "integer"
              }]
            }]
          }]
        }
      }
    )
})

///////////////////////////////////////
// WEATHER API'S
///////////////////////////////////////
app.get('/api/weather/get_ids', authToken, async (req, res) => {
  let user = await User.findOne({email: req.user.email})
  try {
    res.status(200).json({
      weather_access_token: user.weather_access_token,
      weather_id: user.weather_id
    })
  } catch (err) {
    res.status(404).json({error: "api error"})
  }
})

///////////////////////////////////////
// REDDIT API'S
///////////////////////////////////////
app.get('/api/reddit/getauthurl', authToken, async (req, res) => {
  let user = await User.findOne({email: req.user.email})
  const REDDIT_AUTHORIZE_ENDPOINT = "https://www.reddit.com/api/v1/authorize?"
  const REDIRECT_URI = "http://localhost:3000/settings"
  const SCOPES = [
    'identity',
    'account',
  ]
  const SPACE_DELIMITER = "+"
  const SCOPES_URL_PARAM = SCOPES.join(SPACE_DELIMITER)
  const CLIENT_ID = user.reddit_id
  const RESPONCE_TYPE = 'code'
  const UNIQUE_STRING = 'testing'
  const DURATION = 'temporary'

  const authURL = REDDIT_AUTHORIZE_ENDPOINT +
    "scope=" + SCOPES_URL_PARAM +
    "&redirect_uri=" + REDIRECT_URI +
    "&duration=" + DURATION +
    "&client_id=" + CLIENT_ID +
    "&respone_type=" + RESPONCE_TYPE

  try {
    res.status(200).json({authURL: authURL})
  } catch (err) {
    res.status(404).json({error: "api error"})
  }
})

app.get('/api/twitch/getauthurl', authToken, async (req, res) => {
  let user = await User.findOne({email: req.user.email})
  const TWITCH_AUTHORIZE_ENDPOINT = "https://id.twitch.tv/oauth2/authorize?"
  const REDIRECT_URI = "http://localhost:3000/settings"
  const SCOPES = [
    'viewing_activity_read',
  ]
  const SPACE_DELIMITER = "+"
  const SCOPES_URL_PARAM = SCOPES.join(SPACE_DELIMITER)
  const CLIENT_ID = user.twitch_id
  const RESPONCE_TYPE = 'token'

  const authURL = TWITCH_AUTHORIZE_ENDPOINT +
    "response_type=" + RESPONCE_TYPE +
    "&client_id=" + CLIENT_ID +
    "&redirect_uri=" + REDIRECT_URI +
    "&scope=" + SCOPES_URL_PARAM

  try {
    res.status(200).json({authURL: authURL})
  } catch (err) {
    res.status(404).json({error: "api error"})
  }
})

app.listen(1337, () => {
  console.log('server started on 1337')
})