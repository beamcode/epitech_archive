const jwt = require('jsonwebtoken')

//check session token on every api call
function authToken(req, res, next) {
  const token = req.headers.token

  if (!token)
    return res.status(403).json({error: 'Invalid token, please re-login'})
  jwt.verify(token, process.env.TOKEN_SECRET, 
    (err, user) => {
      if (err)
        return res.status(403).json({error: 'Invalid token, please re-login'})
      req.user = user
      next()
    })
  return
}

module.exports = authToken;