import './App.css';
import SignIn from './signin';
import SignUp from './signup';
import MainPage from './dashboardPage';
import SettingsPage from './settingsPage';
import GetAboutJson from './aboutjson';
import { BrowserRouter, Routes, Route } from 'react-router-dom';

const App = () => {
  return (
    <div>
      <BrowserRouter>
        <Routes>
          <Route exact path="/" element={<SignIn/>}/>
          <Route exact path="/signup" element={<SignUp/>}/>
          <Route exact path="/dashboard" element={<MainPage/>}/>
          <Route exact path="/settings" element={<SettingsPage/>}/>
          <Route exact path="/about.json" element={<GetAboutJson/>}/>
        </Routes>
      </BrowserRouter>
    </div>
  );
}

export default App;
