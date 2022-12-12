function getLocalToken() {
  const tk = localStorage.getItem('token')
  if (tk)
    return tk
  else return null
}

export default getLocalToken;