import React from 'react'
import {decode, encode} from 'base-64'

if (!global.btoa) {
    global.btoa = encode;
}

if (!global.atob) {
    global.atob = decode;
}

global.postList = null;

global.userData = null;
global.swOBJ = null;
global.me = null;