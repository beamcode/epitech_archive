// GET GERNERATED OAUTH2 URL FOR SPOTIFY
function spotify() {
  const SCOPES = [
    'user-read-currently-playing',
    'user-read-playback-state',
    'playlist-read-private',
    'user-modify-playback-state',
    'user-read-private',
    'user-read-playback-state',
    'app-remote-control'
  ]
  const SPOTIFY_AUTHORIZE_ENDPOINT = 'https://accounts.spotify.com/authorize'
  const REDIRECT_URL_AFTER_LOGIN = 'http://localhost:3000/profile'
  const SPACE_DELIMITER = '%20'

  const CLIENT_ID = '90521e89b5044c7fa06d687a0a271f8c'
  const SCOPES_URL_PARAM = SCOPES.join(SPACE_DELIMITER)
  const authURL = SPOTIFY_AUTHORIZE_ENDPOINT + '?client_id='
    + CLIENT_ID + '&redirect_uri=' + REDIRECT_URL_AFTER_LOGIN
    + '&scope=' + SCOPES_URL_PARAM + '&response_type=token&show_dialog=true'
  return authURL
}

function spotify_mobile() {
  const config = {
    clientId: '90521e89b5044c7fa06d687a0a271f8c', // available on the app page
    clientSecret: '6e4b8b6e0e4941398ce62a5576ac0f8a', // click "show client secret" to see this
    redirectUrl: 'com.myapp:/oauth', // the redirect you defined after creating the app
    scopes: [
      'user-read-currently-playing',
      'user-read-playback-state',
      'playlist-read-private',
      'user-modify-playback-state',
      'user-read-private',
      'user-read-playback-state',
      'app-remote-control'
    ], // the scopes you need to access
    serviceConfiguration: {
      authorizationEndpoint: 'https://accounts.spotify.com/authorize',
      tokenEndpoint: 'https://accounts.spotify.com/api/token',
    },
  }
  return config
}

// GET GERNERATED OAUTH2 URL FOR REDDIT
function reddit() {
  const REDDIT_AUTHORIZE_ENDPOINT = "https://ssl.reddit.com/api/v1/authorize?"
  const REDIRECT_URI = "http://localhost:3000/profile"
  const SCOPES = ['identity', 'account', 'edit', 'flair', 'history', 'modconfig', 'modflair', 'modlog', 'modposts', 'modwiki', 'mysubreddits', 'privatemessages', 'read', 'report', 'save', 'submit', 'subscribe', 'vote', 'wikiedit', 'wikiread']
  const SPACE_DELIMITER = "+"
  const SCOPES_URL_PARAM = SCOPES.join(SPACE_DELIMITER)
  const CLIENT_ID = 'b7C7hkvPnTq8jNO8xDHMyQ'
  const RESPONCE_TYPE = 'code'
  const DURATION = 'permanent'

  const authURL = REDDIT_AUTHORIZE_ENDPOINT +
    "client_id=" + CLIENT_ID +
    "&response_type=" + RESPONCE_TYPE +
    "&state=" + 'ok' +
    "&redirect_uri=" + REDIRECT_URI +
    "&duration=" + DURATION +
    "&scope=" + SCOPES_URL_PARAM
  return authURL
}

// GET GERNERATED OAUTH2 URL FOR TWITTER
function twitter() {
  return 'empty'
}

// GET GERNERATED OAUTH2 URL FOR OUTLOOK
function outlook() {
  return 'empty'
}

module.exports.spotify = spotify;
module.exports.spotify_mobile = spotify_mobile;
module.exports.reddit = reddit;
module.exports.twitter = twitter;
module.exports.outlook = outlook;
