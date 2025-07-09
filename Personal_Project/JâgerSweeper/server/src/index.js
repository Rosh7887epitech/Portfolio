const express = require('express');
const cors = require('cors');
const dotenv = require('dotenv');
const http = require('http');
const { Server } = require('socket.io');
const authRoutes = require('./routes/auth');
const scoreRoutes = require('./routes/scores');
const db = require('./db');

dotenv.config();

const app = express();
const server = http.createServer(app);
const io = new Server(server, {
    cors: {
        origin: '*',
        methods: ['GET', 'POST']
    }
});

// Middleware
app.use(express.json());
app.use(cors());

// Routes REST
app.use('/api/auth', authRoutes);
app.use('/api/scores', scoreRoutes);

// WebSocket
io.on('connection', (socket) => {
    console.log('Un joueur connecté :', socket.id);

    socket.on('joinGame', (data) => {
        console.log(`${socket.id} a rejoint la partie`, data);
    });

    socket.on('disconnect', () => {
        console.log('Déconnexion :', socket.id);
    });
});

const PORT = process.env.PORT || 5000;
server.listen(PORT, () => {
    console.log(`✅ Serveur en écoute sur le port ${PORT}`);
});
