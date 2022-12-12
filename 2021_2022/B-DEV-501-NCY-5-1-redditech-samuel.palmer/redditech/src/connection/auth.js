import { authorize } from 'react-native-app-auth'
import './global'

const config = {
    redirectUrl: 'com.rapp://oauth2redirect/reddit',
    clientId: 'uB05xEpK8L7R3aj30y-eNA',
    clientSecret: '', // empty string - needed for iOS
    scopes: ['identity', 'account', 'edit', 'flair', 'history', 'modconfig', 'modflair', 'modlog', 'modposts', 'modwiki', 'mysubreddits', 'privatemessages', 'read', 'report', 'save', 'submit', 'subscribe', 'vote', 'wikiedit', 'wikiread'],
    serviceConfiguration: {
      authorizationEndpoint: 'https://www.reddit.com/api/v1/authorize.compact',
      tokenEndpoint: 'https://www.reddit.com/api/v1/access_token',
    },
    customHeaders: {
      token: {
        Authorization: 'Basic dUIwNXhFcEs4TDdSM2FqMzB5LWVOQQ==',
      },
    },
    additionalParameters: {
      duration: 'permanent'
    },
  };

export default async function loginAuth() {
    try {
      const authState = await authorize(config);
      return authState;
    } catch(error) {
      console.log(error)
      return null;
    }
};

