const express = require('express');
const db = require('../db');
const auth = require('../middleware/auth');
const router = express.Router();

// Enregistrement d'un score
router.post('/', auth, (req, res) => {
    const { score } = req.body;

    if (typeof score !== 'number') {
        return res.status(400).json({ message: 'Score invalide' });
    }

    db.run(
        'INSERT INTO scores (userId, score) VALUES (?, ?)',
        [req.user.id, score],
        function (err) {
            if (err) return res.status(500).json({ message: 'Erreur DB' });
            res.status(201).json({ message: 'Score enregistré' });
        }
    );
});

// Voir ses propres scores
router.get('/me', auth, (req, res) => {
    db.all(
        'SELECT score, date FROM scores WHERE userId = ? ORDER BY date DESC',
        [req.user.id],
        (err, rows) => {
            if (err) return res.status(500).json({ message: 'Erreur DB' });
            res.json(rows);
        }
    );
});

// Leaderboard global (top 10)
router.get('/leaderboard', (req, res) => {
    db.all(
        `SELECT u.username, MAX(s.score) as bestScore
         FROM scores s
         JOIN users u ON s.userId = u.id
         GROUP BY s.userId
         ORDER BY bestScore DESC
         LIMIT 10`,
        (err, rows) => {
            if (err) return res.status(500).json({ message: 'Erreur DB' });
            res.json(rows);
        }
    );
});

module.exports = router;
