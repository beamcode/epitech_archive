import {decode, encode} from 'base-64'
'use strict';

if (!global.btoa) {
    global.btoa = encode;
}

if (!global.atob) {
    global.atob = decode;
}

const snoowrap = require('snoowrap');

export default function snowowrapFunc(refreshToken) {
  const r = new snoowrap({
    userAgent: 'whatever',
    clientId: 'uB05xEpK8L7R3aj30y-eNA',
    clientSecret: '',
    refreshToken: refreshToken,
  });
  r._nextRequestTimestamp = -1;
  r.config({debug: true, proxies: false});
  return r;
}