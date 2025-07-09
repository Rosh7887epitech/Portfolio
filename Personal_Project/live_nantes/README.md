# 🌍 Live Nantes - Interactive City Explorer

## 📋 Description / Description

**FR:** Live Nantes est une application web interactive pour découvrir et explorer la ville de Nantes en temps réel. Elle affiche des données en direct sur les transports, la météo, les événements locaux et propose une carte interactive pour une expérience utilisateur moderne et immersive.

**EN:** Live Nantes is an interactive web application to discover and explore the city of Nantes in real-time. It displays live data on transport, weather, local events and provides an interactive map for a modern and immersive user experience.

## 🚀 Technologies utilisées / Technologies Used

### Frontend
- **React** - Modern UI framework
- **Vite** - Fast build tool and development server
- **JavaScript (ES6+)** - Modern JavaScript features
- **CSS3** - Styling and animations
- **HTML5** - Semantic markup

### APIs et Services / APIs and Services
- **Nantes Open Data API** - Transport et données publiques / Transport and public data
- **Weather API** - Informations météorologiques / Weather information
- **Maps API** - Carte interactive / Interactive map
- **Event APIs** - Événements locaux / Local events

## 📦 Installation et exécution / Installation and Execution

```bash
# Clone the repository
git clone [repository-url]
cd live_nantes

# Install dependencies
npm install

# Start development server
npm run dev

# Build for production
npm run build

# Preview production build
npm run preview

# Run linting
npm run lint
```

## 🎯 Fonctionnalités / Features

### 🗺️ Carte Interactive / Interactive Map
- ✅ Carte de Nantes avec navigation fluide
- ✅ Marqueurs pour points d'intérêt
- ✅ Géolocalisation utilisateur
- ✅ Couches d'information superposées
- ✅ Zoom et navigation tactile

### 🚊 Transports en Temps Réel / Real-time Transport
- ✅ Horaires TAN (bus, tram) en direct
- ✅ Perturbations et retards
- ✅ Stations à proximité
- ✅ Itinéraires optimisés
- ✅ Notifications de service

### 🌤️ Météo Locale / Local Weather
- ✅ Conditions météo actuelles
- ✅ Prévisions sur 7 jours
- ✅ Alertes météorologiques
- ✅ Données de qualité de l'air
- ✅ Index UV et vent

### 🎉 Événements et Culture / Events and Culture
- ✅ Événements en cours et à venir
- ✅ Agenda culturel nantais
- ✅ Lieux et horaires
- ✅ Catégories et filtres
- ✅ Partage social

### 📱 Interface Responsive / Responsive Interface
- ✅ Design mobile-first
- ✅ Navigation adaptative
- ✅ Mode sombre/clair
- ✅ Accessibilité optimisée
- ✅ Performance optimisée

## 🎮 Utilisation / Usage

### 🏠 Page d'accueil / Home Page
- Vue d'ensemble avec widgets principaux
- Météo, transports et événements du jour
- Accès rapide aux fonctionnalités

### 🗺️ Vue Carte / Map View
```javascript
// Navigation sur la carte
- Clic/tap pour sélectionner
- Pinch pour zoomer
- Swipe pour naviguer
- Boutons pour centrer
```

### 🚊 Section Transports / Transport Section
```javascript
// Recherche d'itinéraires
- Point de départ
- Destination  
- Heure de départ/arrivée
- Options de transport
```

## 🏗️ Structure du projet / Project Structure

```
live_nantes/
├── public/              # Assets statiques / Static assets
├── src/
│   ├── components/      # Composants React / React components
│   ├── pages/          # Pages de l'application / App pages
│   ├── services/       # Services API / API services
│   ├── utils/          # Fonctions utilitaires / Utility functions
│   ├── styles/         # Styles CSS / CSS styles
│   └── assets/         # Ressources / Resources
├── js_funct/           # Fonctions JavaScript / JavaScript functions
├── nantes-map/         # Configuration carte / Map configuration
└── vite.config.js      # Configuration Vite / Vite configuration
```

## 🔧 Configuration / Configuration

### 🌐 Variables d'environnement / Environment Variables
```env
VITE_WEATHER_API_KEY=your_weather_api_key
VITE_NANTES_API_KEY=your_nantes_api_key
VITE_MAPS_API_KEY=your_maps_api_key
```

### ⚙️ Configuration Vite / Vite Configuration
```javascript
// vite.config.js
export default {
  server: {
    port: 3000,
    host: true
  },
  build: {
    outDir: 'dist'
  }
}
```

## 🎨 Design et UX / Design and UX

**FR:**
- Interface moderne et intuitive
- Couleurs inspirées de l'identité nantaise
- Animations fluides et transitions
- Accessibilité WCAG 2.1 AA
- Performance optimisée (< 3s de chargement)

**EN:**
- Modern and intuitive interface
- Colors inspired by Nantes identity
- Smooth animations and transitions
- WCAG 2.1 AA accessibility
- Optimized performance (< 3s loading)

## 📊 Données en Temps Réel / Real-time Data

- 🔄 **Mise à jour automatique** toutes les 30 secondes
- 📡 **WebSocket** pour les données critiques
- 💾 **Cache intelligent** pour les performances
- 🔒 **Sécurité** et validation des données

## 🚀 Déploiement / Deployment

```bash
# Build production
npm run build

# Deploy to static hosting
# (Netlify, Vercel, GitHub Pages)

# Or use Docker
docker build -t live-nantes .
docker run -p 3000:3000 live-nantes
```

## 📈 Roadmap

### 🎯 Prochaines fonctionnalités / Upcoming Features
- [ ] Mode hors-ligne / Offline mode
- [ ] Notifications push / Push notifications  
- [ ] Partage d'itinéraires / Route sharing
- [ ] Favoris et préférences / Favorites and preferences
- [ ] Widget de bureau / Desktop widget

## 📝 Licence / License
Ce projet est sous licence MIT.
*This project is under MIT license.*
