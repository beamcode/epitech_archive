const express = require('express')
const router = express.Router()

const User = require('../models/user.model')
const jwt = require('jsonwebtoken')
const bcrypt = require('bcryptjs');

const path = require('path');
const { OAuth2Client } = require('google-auth-library');
const client = new OAuth2Client("346755586920-ph8of024l77004fhp1p5je577efjtpif.apps.googleusercontent.com");

// m
router.post('/google-login', async (req, res) => {
  const { token } = req.body;
  const ticket = await client.verifyIdToken({
    idToken: token,
    audience: process.env.CLIENT_ID,
  });
  const { name, email, picture } = ticket.getPayload();

  res.status(200).json({status: 'ok'});
});

router.post('/signin', async (req, res) => {
  try {
    const user = await User.findOne({email: req.body.email})
    if (!user)
      throw {status: 400, message: "Wrong email or password!"}
    const isPasswordValid = await bcrypt.compare(req.body.password, user.password)
    if (isPasswordValid) {
      const token = jwt.sign(
        {email: user.email,},
        process.env.TOKEN_SECRET,
        {expiresIn: process.env.JWT_EXPIRES_IN}
      )
      return res.status(200).json({token: token})
    } else {
      throw {status: 400, message: "Wrong email or password!"}
    }
  } catch (err) {
    if (!err.status || !err.message) {
      console.log(err)
      res.sendStatus(500)
    } else {
      res.status(err.status).json({error: err.message})
    }
  }
})

module.exports = router