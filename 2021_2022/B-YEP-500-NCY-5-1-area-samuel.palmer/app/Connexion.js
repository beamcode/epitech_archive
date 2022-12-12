import React, {useState} from 'react';
import Login from "./connexion/Login.js"
import Register from "./connexion/Register.js"

const Connexion = (props) => {
    const [login, onLogin] = React.useState(true)

    const displayRegisterPage = () => {
        onLogin(false)
    }

    const displayLoginPage = () => {
        onLogin(true)
    }

    return (
        <>
            {login ? (
                <Login reg={displayRegisterPage} co={props.co}></Login>
            ) : (
                <Register log={displayLoginPage} co={props.co}></Register>
            )}
        </>
    )
}

export default Connexion