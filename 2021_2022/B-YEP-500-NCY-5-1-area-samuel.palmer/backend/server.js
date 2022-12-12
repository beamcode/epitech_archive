// get config vars
const dotenv = require('dotenv');
dotenv.config();
const express = require('express')
const app = express()
const cors = require('cors')
const User = require('./models/user.model')
const mongoose = require('mongoose')
const authToken = require('./routes/components/authToken')
const db_server = 'mongodb+srv://mathieu:blais@cluster0.pbrrt.mongodb.net/UserData?retryWrites=true&w=majority'
const oauth = require('./routes/oauthUrls')
const spotify = require('./routes/spotify')
const reddit = require('./routes/reddit.js')

const twitterItemsReaction = ['send a personal message']
const spotifyItemsReaction = ['next song']
const redditItemsReaction = ['Post im happy']
const outlookItemsReaction = ['send a mail']
const twitterItemsAction = ['Someone followed you']
const spotifyItemsAction = ['Music paused']
const redditItemsAction = ['Nsfw content allowed']
const outlookItemsAction = ['You received a new Mail']

var AREAList = []

//connect to db
mongoose.connect(db_server).then(() => {
  console.log('Connected to Database!');
}).catch((err) => {
  console.log('Not Connected to Database!', err);
});

app.use(cors())
app.use(express.json())

const timeoutScheduled = Date.now();
var state = true

const PausedNextSong = async (i) => {
  i++
  setTimeout(() => {
    if (mongoose.connection.readyState == 1) {
      User.collection.find({}).toArray(async function (err, data) {
        try {
          if (data[i].spotify_token) {
            var tmp = await spotify.get_playstate(data[i].spotify_token)
            if (state == true && tmp == false) {
              console.log("paused")
              spotify.next_song(data[i].spotify_token)
              state = false
            }
            if (state == false && tmp == true) {
              state = true
            }
          }
          PausedNextSong(i);
        } catch (err) {
          PausedNextSong(0);
        }
      })
    } else {

      PausedNextSong(0);
    }
  }, 500)
}

var state3 = true
const PausedPost = async (i) => {
  i++
  setTimeout(() => {
    if (mongoose.connection.readyState == 1) {
      User.collection.find({}).toArray(async function (err, data) {
        try {
          if (data[i].spotify_token && data[i].reddit_token) {
            var tmp = await spotify.get_playstate(data[i].spotify_token)
            if (state3 == true && tmp == false) {
              console.log("paused")
              reddit.post_imhappy(data[i].reddit_token)
              state3 = false
            }
            if (state3 == false && tmp == true) {
              state3 = true
            }
          }
          PausedPost(i);
        } catch (err) {
          PausedPost(0);
        }
      })
    } else {
      PausedPost(0);
    }
  }, 500)
}

var state2 = true
const NSFWNextsong = async (i) => {
  i++
  setTimeout(() => {
    if (mongoose.connection.readyState == 1) {
      User.collection.find({}).toArray(async function (err, data) {
        try {
          if (data[i].spotify_token && data[i].reddit_token) {
            var tmp = await reddit.get_nsfw(data[i].reddit_token)
            if (state2 == true && tmp == false) {
              console.log("allowed")
              spotify.next_song(data[i].spotify_token)
              state2 = false
            }
            if (state2 == false && tmp == true) {
              state2 = true
            }
          }
          NSFWNextsong(i);
        } catch (err) {
          NSFWNextsong(0);
        }
      })
    } else {
      NSFWNextsong(0);
    }
  }, 500)
}

var state4 = true
const NSFWNPost = async (i) => {
  i++
  setTimeout(() => {
    if (mongoose.connection.readyState == 1) {
      User.collection.find({}).toArray(async function (err, data) {
        try {
          if (data[i].reddit_token) {
            var tmp = await reddit.get_nsfw(data[i].reddit_token)
            if (state4 == true && tmp == false) {
              console.log("allowed")
              reddit.post_imhappy(data[i].reddit_token)
              state4 = false
            }
            if (state4 == false && tmp == true) {
              state4 = true
            }
          }
          NSFWNPost(i);
        } catch (err) {
          NSFWNPost(0);
        }
      })
    } else {
      NSFWNPost(0);
    }
  }, 500)
}


const loop = async (i) => {
  i++
  setTimeout(() => {
      loop(i)
      for (t=0; t < AREAList.length; t++) {
        if (AREAList[t][0].includes("Spotify") && AREAList[t][2].includes("Spotify")) {
          console.log(AREAList[t]) 
          PausedNextSong(0);
        }
        if (AREAList[t][0].includes("Reddit") && AREAList[t][2].includes("Reddit")) {
          console.log(AREAList[t]) 
          NSFWNPost(0);
        }
        if (AREAList[t][0].includes("Spotify") && AREAList[t][2].includes("Reddit")) {
          console.log(AREAList[t]) 
          PausedPost(0);
        }
        if (AREAList[t][0].includes("Reddit") && AREAList[t][2].includes("Spotify")) {
          console.log(AREAList[t]) 
          NSFWNextsong(0);
        }
      }
  }, 1500)

}

loop(0)


function check_token(user) {
  if (user.spotify_token)
    return true
  else
    return false
}

app.post('/api/services', authToken, async (req, res) => {
  try {
    let user = await User.findOne({ email: req.user.email })
    const servicesList = {
      Outlook: {
        service: 'Outlook',
        status: false,
        color: '#0072C6',
        reactions: outlookItemsReaction,
        actions: outlookItemsAction,
        oauth: oauth.outlook(),
        oauthmobile: null
      },
      Spotify: {
        service: 'Spotify',
        status: check_token(user),
        color: '#1DB954',
        reactions: spotifyItemsReaction,
        actions: spotifyItemsAction,
        oauth: oauth.spotify(),
        oauthmobile: oauth.spotify_mobile()
      },
      Reddit: {
        service: 'Reddit',
        status: check_token(user),
        color: '#FF5700',
        reactions: redditItemsReaction,
        actions: redditItemsAction,
        oauth: oauth.reddit(),
        oauthmobile: null
      },
      Twitter: {
        service: 'Twitter',
        status: false,
        color: '#1DA1F2',
        reactions: twitterItemsReaction,
        actions: twitterItemsAction,
        oauth: oauth.twitter(),
        oauthmobile: null
      }
    }
    res.status(200).json({ result: servicesList })
  } catch (err) {
    console.log(err)
    res.sendStatus(500)
  }
})

// action - reaction link sending
app.post('/api/getLinks', async (req, res) => {
  res.status(200).json({ links: AREAList })
})

// action - reaction link creation
app.post('/api/newLink', authToken, async (req, res) => {
  li = []
  if (req.body.value === 'Twitter')
    li.push('Twitter : ', req.body.value3)
  if (req.body.value === 'Reddit')
    li.push('Reddit : ', req.body.value3)
  if (req.body.value === 'Spotify')
    li.push('Spotify : ', req.body.value3)
  if (req.body.value === 'Outlook')
    li.push('Outlook : ', req.body.value3)
  if (req.body.value2 === 'Twitter')
    li.push('Twitter : ', req.body.value4)
  if (req.body.value2 === 'Reddit')
    li.push('Reddit : ', req.body.value4)
  if (req.body.value2 === 'Spotify')
    li.push('Spotify : ', req.body.value4)
  if (req.body.value2 === 'Outlook')
    li.push('Outlook : ', req.body.value4)
  AREAList.push(li)
  li = []
  res.status(200).json({ status: 'ok', message: 'Successfully created your Action-Reaction !' })
})

//get service list
app.post('/api/list', async (req, res) => {
  li = ["Twitter", "Spotify", "Reddit", "Outlook"]
  res.status(200).json({ list: li })
})

//reaction list
app.post('/api/reactions', async (req, res) => {
  res.status(200).json({ tw: twitterItemsReaction, sp: spotifyItemsReaction, red: redditItemsReaction, out: outlookItemsReaction })
})

//action list
app.post('/api/actions', async (req, res) => {
  res.status(200).json({ tw: twitterItemsAction, sp: spotifyItemsAction, red: redditItemsAction, out: outlookItemsAction })
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
          name: "spotify",
          actions: [{
            name: "Music paused",
            description: "This actions is triggered when music has been paused"
          }],
          reactions: [{
            name: "next song",
            description: "This reaction played the next song when called"
          }]
        }, {
          name: "twitter",
          actions: [{
            name: "aaa",
            description: "tttt"
          }],
          reactions: [{
            name: "aaa",
            description: "tttt"
          }]
        }, {
          name: "reddit",
          actions: [{
            name: "nsfw content allowed",
            description: "This actions is triggered when nswf content has been allowed"
          }],
          reactions: [{
            name: "Allow nsfw content",
            description: "This reaction allow nsfws content on Reddit parameters when called"
          }]
        }, {
          name: "outlook",
          actions: [{
            name: "You received a new Mail",
            description: "This action is triggered when you received a new mail"
          }],
          reactions: [{
            name: "Send a mail",
            description: "This reaction send a mail"
          }]
        }]
      }
    }
  )
})

//store service token
app.post('/api/storeservicetoken', authToken, async (req, res) => {
  try {
    let user = await User.findOne({ email: req.user.email })
    const service = req.body.service
    const token = req.body.token
    const href = req.body.href
    if (service === 'Spotify') {
      spotify.store_token(user, token)
    }
    if (service === 'Reddit') {
      reddit.store_token(user, href)
    }
    // if (service === 'Reddit')
    //   console.log(user + ' ' + token)
    // if (service === 'Outlook')
    //   console.log(user + ' ' + token)

    res.status(200).json({ status: 'ok' })
  } catch (err) {
    console.log(err)
    console.log('fuck')
    res.sendStatus(500)
  }
})

const signinRoutes = require('./routes/signin')
const signupRoutes = require('./routes/signup')
const spotifyRoutes = require('./routes/spotify')
const redditRoutes = require('./routes/reddit')

app.use('/api', signinRoutes)
app.use('/api', signupRoutes)
app.use('/api/spotify', spotifyRoutes)
app.use('/api/reddit', redditRoutes)

app.listen(3001, () => {
  console.log('server started on port 3001')
})
