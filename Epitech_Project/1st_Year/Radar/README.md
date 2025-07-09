# 📡 Radar - Simulation de Détection

## 📋 Description / Description

**FR:** Radar est une simulation avancée de système de détection radar développée en C++. Le programme simule la détection d'objets en mouvement, le calcul de trajectoires, l'affichage en temps réel sur écran radar et la gestion de multiples cibles avec différents algorithmes de tracking.

**EN:** Radar is an advanced radar detection system simulation developed in C++. The program simulates moving object detection, trajectory calculation, real-time radar display, and multiple target management with different tracking algorithms.

## 🚀 Technologies utilisées / Technologies Used
- **Langage / Language:** C++
- **Graphiques / Graphics:** SFML (Simple and Fast Multimedia Library)
- **Mathématiques / Mathematics:** Calculs vectoriels et trigonométriques / Vector and trigonometric calculations
- **Configuration:** Fichiers de configuration personnalisés / Custom configuration files

## 📦 Installation et exécution / Installation and Execution

```bash
# Navigate to project
cd Radar

# Install SFML dependencies
sudo apt-get install libsfml-dev  # Ubuntu/Debian
# or
brew install sfml  # macOS

# Compile the simulation
make

# Run with default configuration
./radar

# Run with custom radar file
./radar test.rdr

# Generate sample radar data
python3 generator.py > sample.rdr

# Clean build files
make clean
```

## 🎯 Fonctionnalités / Features

### 📡 Système de Radar / Radar System
- ✅ **Balayage circulaire** - Rotation continue du faisceau / Continuous beam rotation
- ✅ **Portée variable** - Distance de détection ajustable / Adjustable detection range
- ✅ **Secteur d'observation** - Angle de balayage configurable / Configurable sweep angle
- ✅ **Résolution** - Précision de détection réglable / Adjustable detection precision
- ✅ **Atténuation** - Simulation de la perte de signal / Signal loss simulation

### 🎯 Détection d'objets / Object Detection
- ✅ **Objets multiples** - Gestion simultanée de plusieurs cibles / Simultaneous multi-target handling
- ✅ **Types variés** - Avions, navires, véhicules terrestres / Aircraft, ships, ground vehicles
- ✅ **Vitesses différentes** - Objets lents et rapides / Slow and fast objects
- ✅ **Signatures radar** - Intensité selon la taille / Intensity based on size
- ✅ **Interférences** - Bruit et fausses détections / Noise and false detections

### 📈 Calcul de trajectoires / Trajectory Calculation
- ✅ **Prédiction de mouvement** - Algorithmes de prédiction / Prediction algorithms
- ✅ **Vitesse instantanée** - Calcul vectoriel / Vector calculation
- ✅ **Accélération** - Détection des changements / Change detection
- ✅ **Trajectoire future** - Extrapolation de chemin / Path extrapolation
- ✅ **Zone de confiance** - Ellipse d'incertitude / Uncertainty ellipse

### 🖥️ Interface visuelle / Visual Interface
- ✅ **Écran radar** - Affichage circulaire traditionnel / Traditional circular display
- ✅ **Grille polaire** - Anneaux de distance / Distance rings
- ✅ **Traces de cibles** - Historique des positions / Position history
- ✅ **Informations temps réel** - Vitesse, cap, distance / Speed, heading, distance
- ✅ **Alertes visuelles** - Signalisation des menaces / Threat signaling

## 🎮 Utilisation / Usage

### 📄 Format de fichier radar / Radar File Format
```
# Fichier de configuration radar (.rdr)
A 150 200 5 10    # Avion: x, y, vx, vy
N 300 400 -3 7    # Navire: x, y, vx, vy  
T 450 100 8 -2    # Véhicule terrestre: x, y, vx, vy
```

### 🎛️ Contrôles / Controls
- **Souris** - Navigation et zoom / Navigation and zoom
- **Espace** - Pause/Reprendre / Pause/Resume
- **R** - Reset simulation / Reset simulation
- **+/-** - Zoom avant/arrière / Zoom in/out
- **Flèches** - Déplacement de la vue / View movement
- **F** - Mode plein écran / Fullscreen mode

### ⚙️ Paramètres configurables / Configurable Parameters
```cpp
// Configuration du radar / Radar configuration
struct RadarConfig {
    float range;              // Portée maximale / Maximum range
    float sweep_speed;        // Vitesse de balayage / Sweep speed
    float resolution;         // Résolution angulaire / Angular resolution
    int update_frequency;     // Fréquence de mise à jour / Update frequency
    bool show_trails;         // Afficher les traces / Show trails
    float fade_time;          // Temps de disparition / Fade time
};
```

## 🏗️ Architecture / Architecture

### 📁 Structure du projet / Project Structure
```
Radar/
├── src/
│   ├── radar/
│   │   ├── radar_system.cpp    # Système radar principal
│   │   ├── target_tracker.cpp  # Suivi de cibles
│   │   └── signal_processor.cpp # Traitement du signal
│   ├── objects/
│   │   ├── target.cpp          # Classe cible générique
│   │   ├── aircraft.cpp        # Avions
│   │   └── vessel.cpp          # Navires
│   ├── display/
│   │   ├── radar_display.cpp   # Affichage radar
│   │   ├── hud.cpp             # Interface utilisateur
│   │   └── graphics.cpp        # Rendu graphique
│   └── utils/
│       ├── math_utils.cpp      # Fonctions mathématiques
│       ├── file_parser.cpp     # Analyse de fichiers
│       └── config.cpp          # Configuration
├── include/                    # Headers C++
├── content/                    # Ressources (textures, sons)
└── generator.py               # Générateur de données test
```

### 🎯 Classes principales / Main Classes

```cpp
class RadarSystem {
public:
    void update(float deltaTime);
    void addTarget(Target* target);
    void removeTarget(int targetId);
    std::vector<Detection> getDetections();
private:
    float sweepAngle;
    float range;
    std::vector<Target*> targets;
};

class Target {
public:
    virtual void update(float deltaTime);
    virtual float getRadarCrossSection() const;
    Vector2f getPosition() const;
    Vector2f getVelocity() const;
protected:
    Vector2f position;
    Vector2f velocity;
    float rcs; // Radar Cross Section
};
```

## 🧮 Algorithmes / Algorithms

### 📡 Détection radar / Radar Detection
```cpp
// Algorithme de détection basé sur la géométrie
bool RadarSystem::detectTarget(const Target& target, float sweepAngle) {
    Vector2f targetPos = target.getPosition();
    float distance = magnitude(targetPos);
    float angle = atan2(targetPos.y, targetPos.x);
    
    // Vérification de la portée et de l'angle
    if (distance <= range && isInSweepBeam(angle, sweepAngle)) {
        // Calcul de l'intensité du signal
        float signal = target.getRadarCrossSection() / (distance * distance);
        return signal > detectionThreshold;
    }
    return false;
}
```

### 🎯 Suivi de cibles / Target Tracking
```cpp
// Filtre de Kalman simplifié pour prédiction
class KalmanFilter {
public:
    Vector2f predict(float deltaTime);
    void update(Vector2f measurement);
private:
    Vector2f state;      // Position et vitesse
    Matrix2f covariance; // Matrice de covariance
    float processNoise;  // Bruit du processus
    float measurementNoise; // Bruit de mesure
};
```

### 📊 Traitement du signal / Signal Processing
```cpp
// Suppression du bruit et amélioration du signal
float SignalProcessor::enhanceSignal(float rawSignal, Vector2f position) {
    // Filtrage passe-bas pour réduire le bruit
    float filtered = lowPassFilter(rawSignal);
    
    // Correction basée sur la distance
    float distanceCorrection = calculateDistanceAttenuation(position);
    
    // Amélioration adaptative
    return adaptiveEnhancement(filtered * distanceCorrection);
}
```

## 🎨 Affichage radar / Radar Display

### 🌟 Éléments visuels / Visual Elements
- **Balayage rotatif** - Ligne verte tournante / Rotating green line
- **Échos de cibles** - Points lumineux / Bright dots
- **Traces persistantes** - Historique avec fade / History with fade
- **Grille de référence** - Cercles concentriques / Concentric circles
- **Informations textuelles** - Données de cibles / Target data

### 🎯 Rendu temps réel / Real-time Rendering
```cpp
void RadarDisplay::render(sf::RenderWindow& window) {
    // Dessiner la grille de base
    drawGrid(window);
    
    // Afficher les traces anciennes (avec fade)
    drawTrails(window);
    
    // Dessiner les détections actuelles
    drawCurrentDetections(window);
    
    // Afficher le balayage radar
    drawSweepLine(window, currentSweepAngle);
    
    // Interface utilisateur
    drawHUD(window);
}
```

## 📊 Génération de données / Data Generation

### 🐍 Générateur Python / Python Generator
```python
# generator.py - Création de scénarios de test
import random
import math

def generate_aircraft(count, area_size):
    """Génère des avions avec trajectoires réalistes"""
    for i in range(count):
        x = random.uniform(0, area_size)
        y = random.uniform(0, area_size)
        speed = random.uniform(100, 300)  # km/h
        heading = random.uniform(0, 2 * math.pi)
        vx = speed * math.cos(heading)
        vy = speed * math.sin(heading)
        print(f"A {x:.1f} {y:.1f} {vx:.1f} {vy:.1f}")
```

## 🔧 Configuration avancée / Advanced Configuration

### ⚙️ Fichier de configuration / Configuration File
```ini
[radar]
range = 500.0
sweep_speed = 60.0  # degrés par seconde
resolution = 1.0    # degrés
update_rate = 30    # Hz

[display]
window_width = 1024
window_height = 768
fullscreen = false
show_grid = true
trail_length = 50

[simulation]
time_scale = 1.0
auto_generate = false
target_count = 10
noise_level = 0.1
```

## 🧪 Tests et validation / Testing and Validation

```bash
# Tests de performance
make benchmark

# Validation des algorithmes
make test-algorithms

# Tests de stress avec nombreuses cibles
./radar stress_test.rdr

# Profiling mémoire
valgrind --tool=memcheck ./radar
```

## 📈 Métriques de performance / Performance Metrics

- **FPS cible** : 60 FPS constant / Constant 60 FPS
- **Latence détection** : < 16ms / < 16ms detection latency  
- **Précision tracking** : ±1% / ±1% tracking accuracy
- **Mémoire max** : 100MB pour 1000 cibles / 100MB for 1000 targets

## 📝 Licence / License
Ce projet est sous licence MIT.
*This project is under MIT license.*
