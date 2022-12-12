import React, { useEffect, useState } from 'react'

const GetAboutJson = () => {
  const [aboutjson, set_aboutjson] = useState('')

  useEffect(() => {
    async function fetchData() {
      const responce = await fetch("http://localhost:1337/about.json", {
        method: "GET",
        headers: {
          "Content-Type": "application/json",
        },
      })
      let json = null
      if (responce.ok) {
        json = await responce.json()
        set_aboutjson(JSON.stringify(json))
      }
    }
    fetchData()
  }, [])

  return (
    <>
      {aboutjson ? (<>{aboutjson}</>) : (<></>)}
    </>
  )
}

export default GetAboutJson;
