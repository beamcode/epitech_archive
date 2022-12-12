import './App.css';
import { BrowserRouter, Routes, Route, Navigate } from 'react-router-dom';
import Login from './pages/login'
import Home from './pages/home'
import Profile from './pages/profile'
import Settings from './pages/settings';
import ProtectedRoutes from './pages/protectedRoutes';

const App = () => {
  return (
      <BrowserRouter>
        <Routes>
          <Route exact path="/login" element={<Login/>}/>
          <Route element={<ProtectedRoutes/>}>
            <Route exact path="/home" element={<Home/>}/>
            <Route exact path="/profile" element={<Profile/>}/>
            <Route exact path="/settings" element={<Settings/>}/>
          </Route>
        </Routes>

      </BrowserRouter>
  );
}

export default App;
