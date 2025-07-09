# ⚓ Navy_War - Bataille Navale

## 📋 Description / Description

**FR:** Navy_War est une implémentation complète du jeu de bataille navale jouable en réseau entre deux joueurs. Le jeu utilise les signaux UNIX pour la communication inter-processus et offre une expérience de jeu authentique en mode terminal.

**EN:** Navy_War is a complete implementation of the battleship game playable over network between two players. The game uses UNIX signals for inter-process communication and provides an authentic terminal-based gaming experience.

## 🚀 Technologies utilisées / Technologies Used
- **Langage / Language:** C
- **Communication:** Signaux UNIX / UNIX Signals  
- **IPC:** Inter-Process Communication
- **Networking:** Process synchronization

## 📦 Installation et exécution / Installation and Execution

```bash
# Navigate to project
cd Navy_War

# Compile the project
make

# Player 1 (host)
./navy pos1

# Player 2 (client) 
./navy pos2 [player1_pid]

# Clean build files
make clean
```

## 🎯 Fonctionnement / How it Works

**FR:**
1. Chaque joueur place ses navires selon un fichier de position
2. Les joueurs se connectent via leurs PIDs (Process IDs)
3. Tour par tour, ils attaquent les positions adverses
4. Communication via signaux UNIX (SIGUSR1, SIGUSR2)
5. Le premier à couler tous les navires gagne

**EN:**
1. Each player places their ships according to a position file
2. Players connect via their PIDs (Process IDs)
3. Turn by turn, they attack opponent positions
4. Communication via UNIX signals (SIGUSR1, SIGUSR2)
5. First to sink all ships wins

## 🚢 Format des fichiers de position / Position File Format

```
2:C3:C4
3:D5:F5
4:B7:B10
5:F1:J1
```

- Format: `taille:début:fin`
- Format: `size:start:end`

## 🎮 Gameplay

### 🎯 Commandes de jeu / Game Commands
- **Attaque / Attack:** `A1`, `B5`, `J10` (coordonnées)
- **Affichage / Display:** Grilles automatiquement mises à jour

### 🏆 Conditions de victoire / Win Conditions
- **Victoire / Victory:** Couler tous les navires adverses
- **Défaite / Defeat:** Tous vos navires coulés

## 📊 Fonctionnalités / Features

- ✅ Placement automatique des navires
- ✅ Communication réseau via signaux
- ✅ Interface utilisateur en mode texte
- ✅ Validation des positions et coups
- ✅ Gestion d'erreurs robuste
- ✅ Synchronisation des joueurs

## 🔧 Signaux utilisés / Signals Used

- **SIGUSR1:** Tir manqué / Miss
- **SIGUSR2:** Tir réussi / Hit  
- **Autres / Others:** Coordination du jeu

## 📝 Licence / License
Ce projet est sous licence MIT.
*This project is under MIT license.*
