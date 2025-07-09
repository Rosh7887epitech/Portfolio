import { useState } from 'react';
import { useNavigate } from 'react-router-dom';
import './Login.css';

function Login() {
    const navigate = useNavigate();
    const [isLogin, setIsLogin] = useState(true);
    const [formData, setFormData] = useState({
        username: '',
        email: '',
        password: ''
    });
    const [error, setError] = useState('');

    const handleSubmit = async (e) => {
        e.preventDefault();
        setError('');
        
        const endpoint = isLogin ? '/api/auth/login' : '/api/auth/register';
        try {
            const response = await fetch(`http://localhost:5000${endpoint}`, {
                method: 'POST',
                headers: {
                    'Content-Type': 'application/json',
                },
                body: JSON.stringify(formData),
            });

            const data = await response.json();

            if (response.ok) {
                localStorage.setItem('token', data.token);
                localStorage.setItem('userId', data.userId);
                navigate('/game');
            } else {
                setError(data.message);
            }
        } catch (error) {
            setError('Erreur de connexion au serveur');
        }
    };

    return (
        <div className="login-container">
            <div className="login-box">
                <h2>{isLogin ? 'Connexion' : 'Inscription'}</h2>
                {error && <div className="error-message">{error}</div>}
                <form onSubmit={handleSubmit}>
                    <div className="form-group">
                        <input
                            type="text"
                            placeholder="Nom d'utilisateur"
                            value={formData.username}
                            onChange={(e) => setFormData({...formData, username: e.target.value})}
                            required
                        />
                    </div>
                    {!isLogin && (
                        <div className="form-group">
                            <input
                                type="email"
                                placeholder="Email"
                                value={formData.email}
                                onChange={(e) => setFormData({...formData, email: e.target.value})}
                                required
                            />
                        </div>
                    )}
                    <div className="form-group">
                        <input
                            type="password"
                            placeholder="Mot de passe"
                            value={formData.password}
                            onChange={(e) => setFormData({...formData, password: e.target.value})}
                            required
                        />
                    </div>
                    <button type="submit" className="submit-button">
                        {isLogin ? 'Se connecter' : "S'inscrire"}
                    </button>
                </form>
                <button 
                    className="toggle-button"
                    onClick={() => {
                        setIsLogin(!isLogin);
                        setError('');
                        setFormData({ username: '', email: '', password: '' });
                    }}
                >
                    {isLogin ? "Pas de compte ? S'inscrire" : 'Déjà un compte ? Se connecter'}
                </button>
            </div>
        </div>
    );
}

export default Login;
