import loginAuth from './auth'
import snowowrapFunc from './sw';
import {decode, encode} from 'base-64'
import './global'

if (!global.btoa) {
    global.btoa = encode;
}

if (!global.atob) {
    global.atob = decode;
}

export default async function authMe() {
  global.userData = await loginAuth();
  if (global.userData)
    global.swOBJ = snowowrapFunc(global.userData.refreshToken)
}