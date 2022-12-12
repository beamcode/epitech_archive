const express = require('express')
const router = express.Router()

const User = require('../models/user.model')
const bcrypt = require('bcryptjs');

//signup api
router.post('/signup', async (req, res) => {
  try {
    if (req.body.email === '' || req.body.password === '' || req.body.cpassword === '')
      throw {status: 400, message: "Please check you have filled all fields"}
    let user = await User.findOne({email: req.body.email})
    if (user)
      throw {status: 400, message: "You already have an account, please login or reset your password"}
    if (req.body.password != req.body.cpassword)
      throw {status: 400, message: "Passwords do not match!"}
    if (req.body.email.length > 254)
      throw {status: 400, message: "Email address is too long"}
    //test email syntax
    //var re = /\S+@\S+\.\S+/;
    //if (!re.test(req.body.email)) 
    //  throw {status: 400, message: "Invalid email address"}
    if (req.body.password.length > 30)
      throw {status: 400, message: "Password is too long"}
    const newPassword = await bcrypt.hash(req.body.password, 10)
    await User.create({
      email: req.body.email,
      password: newPassword
    })
    res.status(200).json({status: 'ok'})
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