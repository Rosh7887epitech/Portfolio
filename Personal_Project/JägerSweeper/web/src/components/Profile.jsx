import { useState, useEffect } from 'react';
import './Profile.css';
import userIcon from '../assets/user.png';

function Profile() {
    const [isOpen, setIsOpen] = useState(false);
    const [userInfo, setUserInfo] = useState(null);
    const [isLoggedIn, setIsLoggedIn] = useState(false);

    useEffect(() => {
        const token = localStorage.getItem('token');
        const userId = localStorage.getItem('userId');
        
        if (token && userId) {
            setIsLoggedIn(true);
            // Récupérer les informations utilisateur depuis l'API
            fetchUserInfo(userId, token);
        }
    }, []);

    const fetchUserInfo = async (userId, token) => {
        try {
            const response = await fetch(`http://localhost:5000/api/auth/user/${userId}`, {
                headers: {
                    'Authorization': `Bearer ${token}`
                }
            });
            
            if (response.ok) {
                const data = await response.json();
                setUserInfo(data);
            }
        } catch (error) {
            console.error('Erreur lors de la récupération des infos utilisateur:', error);
        }
    };

    const handleLogout = () => {
        localStorage.removeItem('token');
        localStorage.removeItem('userId');
        setIsLoggedIn(false);
        setUserInfo(null);
        setIsOpen(false);
        window.location.reload();
    };

    if (!isLoggedIn) {
        return (
            <div className="profile-container">
                <button 
                    className="login-button"
                    onClick={() => window.location.href = '/login'}
                >
                    Se connecter
                </button>
            </div>
        );
    }

    return (
        <div className="profile-container">
            <button 
                className="profile-button"
                onClick={() => setIsOpen(!isOpen)}
            >
                <img src={userIcon} alt="Profile" style={{width: '24px', height: '24px'}} />
            </button>
            
            {isOpen && (
                <div className="profile-menu">
                    <div className="profile-header">
                        <h3>Profil</h3>
                    </div>
                    <div className="profile-info">
                        <p><strong>Nom d'utilisateur:</strong></p>
                        <p>{userInfo?.username || 'Chargement...'}</p>
                        {userInfo?.email && (
                            <>
                                <p><strong>Email:</strong></p>
                                <p>{userInfo.email}</p>
                            </>
                        )}
                    </div>
                    <div className="profile-actions">
                        <button 
                            className="logout-button"
                            onClick={handleLogout}
                        >
                            Se déconnecter
                        </button>
                    </div>
                </div>
            )}
        </div>
    );
}

export default Profile;
