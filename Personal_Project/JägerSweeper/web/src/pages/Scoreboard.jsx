import { useState, useEffect } from 'react';
import { useNavigate } from 'react-router-dom';
import './Scoreboard.css';

function Scoreboard() {
    const navigate = useNavigate();
    const [leaderboard, setLeaderboard] = useState([]);
    const [loading, setLoading] = useState(true);
    const [error, setError] = useState('');

    useEffect(() => {
        fetchLeaderboard();
    }, []);

    const fetchLeaderboard = async () => {
        try {
            const response = await fetch('http://localhost:5000/api/scores/leaderboard');
            
            if (response.ok) {
                const data = await response.json();
                setLeaderboard(data);
            } else {
                setError('Erreur lors du chargement du classement');
            }
        } catch (error) {
            setError('Erreur de connexion au serveur');
        } finally {
            setLoading(false);
        }
    };

    const handleBack = () => {
        navigate('/');
    };

    if (loading) {
        return (
            <div className="scoreboard-container">
                <div className="scoreboard-box">
                    <div className="loading">Chargement...</div>
                </div>
            </div>
        );
    }

    return (
        <div className="scoreboard-container">
            <div className="scoreboard-box">
                <h1 className="scoreboard-title">🏆 Classement des Meilleurs Scores</h1>
                
                {error && <div className="error-message">{error}</div>}
                
                <div className="leaderboard">
                    {leaderboard.length === 0 ? (
                        <div className="no-scores">Aucun score enregistré pour le moment</div>
                    ) : (
                        <table className="leaderboard-table">
                            <thead>
                                <tr>
                                    <th>Position</th>
                                    <th>Joueur</th>
                                    <th>Meilleur Score</th>
                                </tr>
                            </thead>
                            <tbody>
                                {leaderboard.map((player, index) => (
                                    <tr key={index} className={index < 3 ? 'podium' : ''}>
                                        <td className="position">
                                            {index === 0 && '🥇'}
                                            {index === 1 && '🥈'}
                                            {index === 2 && '🥉'}
                                            {index > 2 && `#${index + 1}`}
                                        </td>
                                        <td className="username">{player.username}</td>
                                        <td className="score">{player.bestScore}</td>
                                    </tr>
                                ))}
                            </tbody>
                        </table>
                    )}
                </div>
                
                <div className="actions">
                    <button onClick={handleBack} className="back-button">
                        🏠 Retour à l'accueil
                    </button>
                </div>
            </div>
        </div>
    );
}

export default Scoreboard;
