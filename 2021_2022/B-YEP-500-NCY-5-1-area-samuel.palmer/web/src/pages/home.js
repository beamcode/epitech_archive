import React, { useState, useEffect } from 'react';
import NavBar from '../components/navbar'
import Footer from '../components/footer'
import bg from '../assets/back3.jpg';

function Home() {
  const [link, setLinks] = useState(null)
  const [linksView, setLinksView] = useState(null)

  useEffect(() => {
    setTimeout(() => {
      getLinks()
      setLinksList()
    }, 1000)
  }, [link])

  const getLinks = async () => {
    const responce = await fetch("http://localhost:3001/api/getLinks", {
      method: "POST",
      headers: { "Content-Type": "application/json", },
    })
    const data = await responce.json()
    if (data)
      setLinks(data.links)
    else {
      if (data.error)
        console.log(data.error)
      else
        console.log('server error')
    }
  }

  const setLinksList = async () => {
    var li = []
    if (link) {
      for (let i = 0; i < link.length; i++) {
        li.push(
          <div key={i}>
            <p style={{ color: 'white', top: 5, fontSize: 18, alignSelf: 'center', marginTop: 10, fontWeight: 'bold' }}>Action </p>
            <div style={{ width: '100%' }}>
              <div style={{ flexDirection: 'row', alignSelf: 'center' }}>
                <p style={{ color: 'white', top: 5, fontSize: 15, alignSelf: 'center', marginTop: 10 }}>{link[i][0]}</p>
                <p style={{ color: 'white', top: 5, fontSize: 15, alignSelf: 'center', marginTop: 10 }}>{link[i][1]}</p>
              </div>
            </div>
            <p style={{ color: 'white', top: 5, fontSize: 18, alignSelf: 'center', marginTop: 10, fontWeight: 'bold' }}>Reaction </p>
            <div style={{ width: '80%', alignSelf: "center", alignItem: 'center', marginBottom: 40 }}>
              <div style={{ flexDirection: 'row', alignSelf: 'center' }}>
                <p style={{ color: 'white', top: 5, fontSize: 15, alignSelf: 'center', marginTop: 10 }}>{link[i][2]}</p>
                <p style={{ color: 'white', top: 5, fontSize: 15, alignSelf: 'center', marginTop: 10 }}>{link[i][3]}</p>
              </div>
            </div>
            <div style={{ backgroundColor: 'grey', width: '60%', height: 1, alignSelf: 'center' }}>
            </div>
            <div style={{ width: '80%', heigth: 50, marginTop: 20 }}>
            </div>
          </div>
        )
      }
    }
    setLinksView(li)
  }


  return (
    <>
      <NavBar />
      <div style={{ height: 'calc(100vh - (65px + 152px + 100px))', backgroundImage: `url(${bg})`, padding: '50px 0px 50px 0px' }}>
        <div style={{ backgroundColor: '#60686c', height: '100%' }}>
          <div style={{ backgroundColor: '#60686c', padding: '40px 60px 30px 60px' }}>
            <h1 style={{ fontSize: 20, color: 'white', fontWeight: '600' }}>- Your AREA List -</h1>
            <hr />
            {link ? (
              <>
                <div style={{ backgroundColor: 'grey', width: '60%', height: 1, alignSelf: 'center', marginBottom: 20 }}></div>
                {linksView}
                <div style={{ width: '80%', heigth: 50, marginTop: 50 }}></div>
              </>
            ) : (
              <>
                <p style={{ color: 'white', top: 5, fontSize: 16, alignSelf: 'center', marginTop: 10 }}>No links created</p>
              </>
            )}
          </div>
        </div>
      </div>
      <Footer />
    </>
  )
}

export default Home;