# 💣 JägerSweeper - Modern Minesweeper

## 📋 Description / Description

**FR:** JägerSweeper est une version moderne et élégante du classique démineur. Cette application web full-stack offre une expérience de jeu fluide avec interface responsive, système de classement en ligne, sauvegarde de parties et fonctionnalités sociales.

**EN:** JägerSweeper is a modern and elegant version of the classic minesweeper. This full-stack web application offers a smooth gaming experience with responsive interface, online leaderboard, game saving, and social features.

## 🚀 Technologies utilisées / Technologies Used

### Frontend
- **HTML5** - Structure sémantique / Semantic structure
- **CSS3** - Animations et design moderne / Animations and modern design
- **JavaScript (ES6+)** - Logique de jeu interactive / Interactive game logic
- **Progressive Web App (PWA)** - Installation et mode hors-ligne / Installation and offline mode

### Backend
- **Node.js** - Serveur JavaScript / JavaScript server
- **Express.js** - Framework web rapide / Fast web framework
- **SQLite** - Base de données légère / Lightweight database
- **bcrypt** - Chiffrement des mots de passe / Password encryption
- **JWT** - Authentification sécurisée / Secure authentication

## 📦 Installation et exécution / Installation and Execution

### 🖥️ Serveur / Server
```bash
# Navigate to server
cd JägerSweeper/server

# Install dependencies
npm install

# Start development server
npm run dev

# Start production server
npm start

# Run database migrations
npm run migrate
```

### 🌐 Client Web / Web Client
```bash
# Navigate to web client
cd JägerSweeper/web

# Install dependencies
npm install

# Start development server
npm run dev

# Build for production
npm run build
```

## 🎯 Fonctionnalités / Features

### 🎮 Gameplay Classique / Classic Gameplay
- ✅ Grilles personnalisables (9x9, 16x16, 30x16)
- ✅ Niveaux de difficulté (Débutant, Intermédiaire, Expert)
- ✅ Système de flags et de révélation
- ✅ Minuteur et compteur de mines
- ✅ Mode première case sûre / First click safe mode

### 🎨 Interface Moderne / Modern Interface
- ✅ Design flat et minimaliste
- ✅ Animations fluides et feedback visuel
- ✅ Thèmes customisables (clair/sombre)
- ✅ Interface responsive (mobile, tablette, desktop)
- ✅ Effets sonores et vibrations

### 🏆 Système de Score / Scoring System
- ✅ Classement en temps réel
- ✅ Statistiques personnelles détaillées
- ✅ Historique des parties
- ✅ Achievements et badges
- ✅ Comparaison avec amis

### 👥 Fonctionnalités Sociales / Social Features
- ✅ Comptes utilisateurs sécurisés
- ✅ Profils et avatars personnalisables
- ✅ Partage de scores sur réseaux sociaux
- ✅ Défis entre joueurs
- ✅ Chat intégré (optionnel)

### 📊 Statistiques Avancées / Advanced Statistics
- ✅ Temps moyen par niveau
- ✅ Taux de réussite
- ✅ Graphiques de progression
- ✅ Analyse des patterns de jeu
- ✅ Export des données

## 🎮 Modes de jeu / Game Modes

### 🏃 Mode Classique / Classic Mode
**FR:** Le démineur traditionnel avec grilles standards et règles classiques.

**EN:** Traditional minesweeper with standard grids and classic rules.

### ⚡ Mode Speed / Speed Mode
**FR:** Défi contre la montre avec grilles pré-générées pour la compétition.

**EN:** Race against time with pre-generated grids for competition.

### 🧩 Mode Personnalisé / Custom Mode
**FR:** Créez vos propres grilles avec taille et densité de mines personnalisées.

**EN:** Create your own grids with custom size and mine density.

### 🏁 Mode Défi / Challenge Mode
**FR:** Grilles spéciales avec contraintes particulières et objectifs uniques.

**EN:** Special grids with particular constraints and unique objectives.

## 🏗️ Architecture / Architecture

### 📁 Structure du projet / Project Structure
```
JägerSweeper/
├── server/
│   ├── src/
│   │   ├── routes/      # API endpoints
│   │   ├── models/      # Database models
│   │   ├── middleware/  # Express middleware
│   │   ├── controllers/ # Business logic
│   │   └── utils/       # Helper functions
│   ├── database.sqlite  # SQLite database
│   └── package.json
├── web/
│   ├── src/
│   │   ├── js/          # Game logic
│   │   ├── css/         # Styles
│   │   ├── components/  # UI components
│   │   └── assets/      # Images, sounds
│   ├── index.html
│   └── manifest.json    # PWA manifest
└── README.md
```

### 🗄️ Base de données / Database Schema
```sql
-- Users table
CREATE TABLE users (
  id INTEGER PRIMARY KEY,
  username VARCHAR(50) UNIQUE,
  email VARCHAR(100) UNIQUE,
  password_hash TEXT,
  created_at DATETIME DEFAULT CURRENT_TIMESTAMP
);

-- Games table  
CREATE TABLE games (
  id INTEGER PRIMARY KEY,
  user_id INTEGER,
  difficulty VARCHAR(20),
  time_seconds INTEGER,
  status VARCHAR(20), -- 'won', 'lost', 'ongoing'
  grid_width INTEGER,
  grid_height INTEGER,
  mine_count INTEGER,
  created_at DATETIME DEFAULT CURRENT_TIMESTAMP
);

-- Leaderboard view
CREATE VIEW leaderboard AS
SELECT username, MIN(time_seconds) as best_time, difficulty
FROM games JOIN users ON games.user_id = users.id
WHERE status = 'won'
GROUP BY user_id, difficulty;
```

## 🎯 Algorithmes de jeu / Game Algorithms

### 💣 Génération de grilles / Grid Generation
```javascript
// Algorithme de placement aléatoire uniforme
function generateMineField(width, height, mineCount, safeX, safeY) {
  // Garantit que la première case cliquée est sûre
  // Ensures first clicked cell is safe
}
```

### 🔍 Révélation en cascade / Flood Fill Algorithm
```javascript
// Révélation automatique des cases vides adjacentes
function revealAdjacent(x, y) {
  // Algorithme de flood-fill optimisé
  // Optimized flood-fill algorithm
}
```

### 🧠 IA d'assistance / AI Assistance (Optional)
```javascript
// Suggestions intelligentes pour les joueurs débutants
function getHint(gameState) {
  // Analyse probabiliste des mines
  // Probabilistic mine analysis
}
```

## 🔒 Sécurité / Security

### 🛡️ Authentification / Authentication
- ✅ Hashage bcrypt pour mots de passe
- ✅ Tokens JWT avec expiration
- ✅ Protection CSRF
- ✅ Validation côté serveur
- ✅ Rate limiting sur APIs

### 🔐 Protection des données / Data Protection
- ✅ HTTPS obligatoire en production
- ✅ Validation et sanitisation des entrées
- ✅ Logs de sécurité
- ✅ Sauvegarde chiffrée des scores
- ✅ GDPR compliant

## 📱 Progressive Web App

### 🔄 Mode hors-ligne / Offline Mode
- ✅ Cache des ressources statiques
- ✅ Jeu disponible sans connexion
- ✅ Synchronisation des scores au retour en ligne
- ✅ Notifications push pour défis

### 📲 Installation / Installation
- ✅ Installable comme app native
- ✅ Icônes et splash screens personnalisées
- ✅ Support des raccourcis clavier
- ✅ Intégration système (partage, etc.)

## 🚀 Déploiement / Deployment

```bash
# Production build
cd web && npm run build
cd server && npm run build

# Docker deployment
docker-compose up -d

# Or manual deployment
pm2 start server/dist/app.js
nginx -s reload
```

## 🎊 Fonctionnalités avancées / Advanced Features

### 🎯 Machine Learning (Futur)
- Analyse des patterns de jeu des utilisateurs
- Suggestions intelligentes personnalisées
- Détection de triche automatisée
- Génération de grilles adaptatives

### 🌐 Multijoueur (Roadmap)
- Parties coopératives en temps réel
- Compétitions en ligne
- Tournois organisés
- Mode spectateur

## 📈 Métriques et Analytics / Metrics and Analytics

```javascript
// Tracking des performances de jeu
const analytics = {
  gameStarted: (difficulty, timestamp) => {},
  gameEnded: (result, time, moves) => {},
  userEngagement: (sessionDuration) => {},
  errorReporting: (error, context) => {}
};
```

## 📝 Licence / License
Ce projet est sous licence MIT.
*This project is under MIT license.*

---

**🎮 Jouez responsablement ! / Play responsibly!**
