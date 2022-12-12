const express = require('express')
const router = express.Router()
const User = require('../models/user.model')
const fetch = require("node-fetch-commonjs");
const { Code } = require('mongodb');
const snoowrap = require('snoowrap');
const { json } = require('express');
const Reddit = require('reddit')

// DECODE AND STORE REDDIT TOKEN
async function store_token(user, urlcode) {
  try {
    var params = new URLSearchParams(urlcode);
    const extractedcode = params.get('code').split('#')[0]
    const clientID = 'b7C7hkvPnTq8jNO8xDHMyQ'
    const clientSecret = 'bRutF-ZRsaHQo1scO8SQdjMHS--J2g'
    let token = null

    const credentials = Buffer.from(`${clientID}:${clientSecret}`).toString("base64")
    const form = new URLSearchParams({
      grant_type: "authorization_code",
      code: extractedcode,
      redirect_uri: "http://localhost:3000/profile"
    })
    await fetch('https://www.reddit.com/api/v1/access_token', {
      method: "POST",
      headers: {
        Authorization: `Basic ${credentials}`
      },
      body: form
    })
      .then(response => {
        if (response)
          return response.json()
        else
          throw new Error(response)
      })
      .then(json => {
        if (json.access_token) {
          token = json.access_token
        }
        else
          throw new Error('no token found')
      })
      .catch(error => {
        console.log(error)
      })
    if (token) {
      if (!user.reddit_token)
        await User.findOneAndUpdate({ email: user.email }, { $set: { reddit_token: token } })
      else
        await User.findOneAndUpdate({ email: user.email }, { reddit_token: token })
    } else {
      throw "i don't get payed for this shit"
    }
  } catch (error) {
    console.log(error)
  }
}


async function post_imhappy(token, bool) {
  if (!token)
    return

  const reddit = new Reddit({
    username: 'u0k1',
    password: 'damnson40',
    appId: 'rNDglPAdtvSKFGoWdDVVcQ',
    appSecret: 'MU7bpd5vU0Mr8m8JnSY076L_SvqWYQ',
    userAgent: 'MyApp/1.0.0 (http://example.com)'
  })

  try {
    const res = await reddit.post('/api/submit', {
      sr: 'myweetest',
      kind: 'link',
      resubmit: true,
      title: 'its happy time',
      text: 'im so happy right now its amazing',
      url: 'epitech.eu'
    })
  } catch (err) {
    console.log(err)
  }


    // try {
    //   fetch('https://oauth.reddit.com/api/v1/me/prefs', {
    //     method: 'POST',
    //     headers: {
    //       "Content-Type": "application/json",
    //       'Authorization': 'bearer ' + token
    //     },
    //     body: {
    //       "allow_clicktracking": false
    //     }
    //   })
    //     .then(response => {
    //       if (response)
    //         console.log(response)
    //       //return response.json()
    //       else
    //         throw new Error(response)
    //     })
    //   // .then(json => console.log(json))
    //   // .catch(error => {
    //   //   console.log(error)
    //   // })
    // } catch (error) {
    //   console.log(error)
    // }
  }

async function get_nsfw(token, bool) {
    if (!token)
      return null
    let value = null
    const NSFW_STATUS_ENDPOINT = "https://oauth.reddit.com/api/v1/me/prefs"
    try {
      const response = await fetch(NSFW_STATUS_ENDPOINT, {
        method: "GET",
        headers: {
          Authorization: "bearer " + token,
        },
      })
        .then(response => {
          console.log(response)
          // if (response)
          //   return response.json()
          // else
          //   throw new Error(response)
        })
        // .then(json => {
        //   value = json.label_nsfw
        // })
        // .catch(error => {
        //   console.log(error)
        //   return null
        // })
    } catch (error) {
      console.log(error)
      return null
    }
    return value
  }

  module.exports = router
  module.exports.store_token = store_token;
  module.exports.post_imhappy = post_imhappy;
  module.exports.get_nsfw = get_nsfw;
