const express = require('express');
const bcrypt = require('bcryptjs');
const jwt = require('jsonwebtoken');
const db = require('../db');
const authMiddleware = require('../middleware/auth');
const router = express.Router();

// Register
router.post('/register', async (req, res) => {
    const { username, email, password } = req.body;

    if (!username || !email || !password) {
        return res.status(400).json({ message: 'Champs manquants' });
    }

    // Vérifie si l'utilisateur existe déjà
    db.get('SELECT * FROM users WHERE username = ? OR email = ?', [username, email], async (err, user) => {
        if (err) return res.status(500).json({ message: 'Erreur serveur' });
        if (user) return res.status(400).json({ message: 'Utilisateur déjà existant' });

        const hashedPassword = await bcrypt.hash(password, 12);

        db.run(
            'INSERT INTO users (username, email, password) VALUES (?, ?, ?)',
            [username, email, hashedPassword],
            function (err) {
                if (err) return res.status(500).json({ message: 'Erreur lors de l\'enregistrement' });

                const token = jwt.sign({ userId: this.lastID }, process.env.JWT_SECRET, { expiresIn: '7d' });
                res.status(201).json({ token, userId: this.lastID });
            }
        );
    });
});

// Login
router.post('/login', (req, res) => {
    const { username, password } = req.body;

    if (!username || !password)
        return res.status(400).json({ message: 'Champs manquants' });

    db.get('SELECT * FROM users WHERE username = ?', [username], async (err, user) => {
        if (err) return res.status(500).json({ message: 'Erreur serveur' });
        if (!user) return res.status(400).json({ message: 'Utilisateur non trouvé' });

        const valid = await bcrypt.compare(password, user.password);
        if (!valid) return res.status(401).json({ message: 'Mot de passe incorrect' });

        const token = jwt.sign({ userId: user.id }, process.env.JWT_SECRET, { expiresIn: '7d' });
        res.status(200).json({ token, userId: user.id });
    });
});

// Get user info
router.get('/user/:id', authMiddleware, (req, res) => {
    const userId = req.params.id;
    
    // Vérifier que l'utilisateur demande ses propres informations
    if (parseInt(userId) !== req.user.id) {
        return res.status(403).json({ message: 'Accès non autorisé' });
    }
    
    db.get('SELECT id, username, email FROM users WHERE id = ?', [userId], (err, user) => {
        if (err) return res.status(500).json({ message: 'Erreur serveur' });
        if (!user) return res.status(404).json({ message: 'Utilisateur non trouvé' });
        
        res.status(200).json(user);
    });
});

module.exports = router;
