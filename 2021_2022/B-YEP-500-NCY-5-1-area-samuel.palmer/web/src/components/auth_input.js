import React from 'react';

const AuthInput = (props) => {
  return (
    <input style={styles.searchBox}
          type={props.type}
          name={props.name}
          value={props.value}
          placeholder={props.placeholder}
          required autoComplete='false'
          onChange={(e) => props.onChange(e.target.value)}/>
  )
}

const styles = {
  searchBox: {
    outline: "none",
    padding: 10,
    marginBottom: 10,
    border: 0,
    borderRadius: 3,
    height: 40,
    width: "100%",
    boxSizing: "border-box",
    color: "white",
    backgroundColor: "#181a1b",
  },
}

export default AuthInput;