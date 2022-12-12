import React from 'react';
import './footer.css';

function Footer() {
  return (
    <footer className="footer-distributed">
      <div className="footer-left">
        <p className="footer-links">
          <a className="link-1" href="/home">Home</a>
          <a href="/home">About</a>
          <a href="/home">Faq</a>
          <a href="/home">Contact</a>
        </p>
        <p>AREA &copy; 2022</p>
      </div>
    </footer>
  );
}

export default Footer;