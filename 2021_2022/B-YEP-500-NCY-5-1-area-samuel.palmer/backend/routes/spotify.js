const express = require('express')
const router = express.Router()
const User = require('../models/user.model')
const fetch = require("node-fetch-commonjs")

// DECODE AND STORE SPOTIFY TOKEN
async function store_token(user, token) {
  try {
    const decodeResult = (hash) => {
      const stringAfterHashtag = hash.substring(1);
      const paramsInUrl = stringAfterHashtag.split('&');
      const paramsSplitUp = paramsInUrl.reduce((accumulater, currentValue) => {
        const [key, value] = currentValue.split('=');
        accumulater[key] = value;
        return accumulater;
      }, {});
      return paramsSplitUp;
    }

    const tmp = decodeResult(token).access_token
    if (!user.spotify_token)
      await User.findOneAndUpdate({ email: user.email }, { $set: { spotify_token: tmp } })
    else
      await User.findOneAndUpdate({ email: user.email }, { spotify_token: tmp })
  } catch (err) {
    console.log(err)
  }
}

async function get_now_playing(token) {
  const CURRENTLY_PLAYING_ENDPOINT = "https://api.spotify.com/v1/me/player/currently-playing"
  if (!token)
    return
  try {
    const response = await fetch(CURRENTLY_PLAYING_ENDPOINT, {
      method: "GET",
      headers: {
        "Content-Type": "application/json",
        Authorization: "Bearer " + token,
      },
    })
  } catch (error) {
    console.log("spotify api error")
  }
}

async function pause(token) {
  const PAUSE_ENDPOINT = "https://api.spotify.com/v1/me/player/pause"
  set_is_playing(false)
  if (!token)
    return
  const response = await fetch(PAUSE_ENDPOINT, {
    method: "PUT",
    headers: {
      "Content-Type": "application/json",
      Authorization: "Bearer " + token,
    },
  })
}

async function play(token) {
  const PLAY_ENDPOINT = "https://api.spotify.com/v1/me/player/play"
  set_is_playing(true)
  if (!token)
    return
  const response = await fetch(PLAY_ENDPOINT, {
    method: "PUT",
    headers: {
      "Content-Type": "application/json",
      Authorization: "Bearer " + token,
    },
  })
}

async function get_playstate(token) {
  const PLAY_STATE_ENDPOINT = "https://api.spotify.com/v1/me/player"
  if (!token)
    return
  const response = await fetch(PLAY_STATE_ENDPOINT, {
    method: "GET",
    headers: {
      "Content-Type": "application/json",
      Authorization: "Bearer " + token,
    },
  })
  let json = null
  if (response.ok) {
    json = await response.json()
    return json.is_playing
  }
  return null
}

async function next_song(token) {
  const SKIP_NEXT_ENDPOINT = "https://api.spotify.com/v1/me/player/next"
  if (!token)
    return
  const response = await fetch(SKIP_NEXT_ENDPOINT, {
    method: "POST",
    headers: {
      "Content-Type": "application/json",
      Authorization: "Bearer " + token,
    },
  })
}

async function previous_song(token) {
  const SKIP_PREVIOUS_ENDPOINT = "https://api.spotify.com/v1/me/player/previous"
  if (!token)
    return
  const response = await fetch(SKIP_PREVIOUS_ENDPOINT, {
    method: "POST",
    headers: {
      "Content-Type": "application/json",
      Authorization: "Bearer " + token,
    },
  })
}


module.exports = router

module.exports.store_token = store_token;
module.exports.previous_song = previous_song;
module.exports.get_playstate = get_playstate;
module.exports.get_now_playing = get_now_playing;
module.exports.next_song = next_song;
module.exports.pause = pause;
module.exports.play = play;