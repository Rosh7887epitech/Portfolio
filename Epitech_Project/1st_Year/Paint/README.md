# 🎨 Paint - 2D Drawing Software

## 📋 Description / Description

**FR:** Paint est un logiciel de dessin 2D complet développé en C avec la bibliothèque CSFML. Il offre une interface graphique intuitive avec des outils de dessin variés, gestion des couleurs, formes géométriques et sauvegarde au format personnalisé.

**EN:** Paint is a complete 2D drawing software developed in C with the CSFML library. It provides an intuitive graphical interface with various drawing tools, color management, geometric shapes, and custom format saving.

## 🚀 Technologies utilisées / Technologies Used
- **Langage / Language:** C
- **Graphiques / Graphics:** CSFML (Simple and Fast Multimedia Library)
- **Interface / Interface:** Event-driven GUI
- **Format / Format:** Custom image format

## 📦 Installation et exécution / Installation and Execution

```bash
# Navigate to project
cd Paint

# Install CSFML dependencies
sudo apt-get install libcsfml-dev  # Ubuntu/Debian
# or
brew install csfml  # macOS

# Compile the project
make

# Run the drawing software
./my_paint

# Clean build files
make clean
```

## 🎯 Fonctionnalités / Features

### 🖌️ Outils de dessin / Drawing Tools
- ✅ **Pinceau** - Trait libre avec épaisseur variable / Free drawing with variable thickness
- ✅ **Crayon** - Trait fin et précis / Fine and precise line
- ✅ **Gomme** - Effacement avec taille ajustable / Erasing with adjustable size
- ✅ **Pot de peinture** - Remplissage par zone / Flood fill
- ✅ **Pipette** - Sélection de couleur / Color picker
- ✅ **Aérographe** - Effet de vaporisation / Spray effect

### 🔷 Formes géométriques / Geometric Shapes
- ✅ **Rectangle** - Avec ou sans remplissage / With or without fill
- ✅ **Cercle/Ellipse** - Formes circulaires parfaites / Perfect circular shapes
- ✅ **Ligne** - Droites avec épaisseur / Straight lines with thickness
- ✅ **Polygone** - Formes personnalisées / Custom shapes
- ✅ **Texte** - Insertion de texte avec polices / Text insertion with fonts

### 🎨 Gestion des couleurs / Color Management
- ✅ **Palette** - 256 couleurs prédéfinies / 256 predefined colors
- ✅ **Sélecteur RGB** - Choix de couleur personnalisé / Custom color picker
- ✅ **Transparence** - Support canal alpha / Alpha channel support
- ✅ **Dégradés** - Effets de dégradé / Gradient effects
- ✅ **Motifs** - Textures et patterns / Textures and patterns

### 💾 Fichiers / File Management
- ✅ **Nouveau** - Création de canevas vierge / Create blank canvas
- ✅ **Ouvrir** - Chargement de fichiers / Load files
- ✅ **Sauvegarder** - Format propriétaire / Proprietary format
- ✅ **Exporter** - Formats standard (PNG, BMP) / Standard formats
- ✅ **Historique** - Annuler/Refaire / Undo/Redo

## 🎮 Interface utilisateur / User Interface

### 🗂️ Disposition / Layout
```
╔══════════════════════════════════════════╗
║  [File] [Edit] [Tools] [View] [Help]     ║
╠══════════════════════════════════════════╣
║ 🎨 │ 🖌️ │ ✏️ │ 🔲 │ ⭕ │ 📝 │ 🎯      ║
║ Palette │ Tools │ Shapes │ Options      ║
╠════════════════════════╤═════════════════╣
║                        │                 ║
║                        │   Color Picker  ║
║     Canvas Area        │                 ║
║                        │   Tool Options  ║
║                        │                 ║
║                        │   Layers Panel  ║
╚════════════════════════╧═════════════════╝
```

### 🖱️ Contrôles / Controls
- **Clic gauche** - Dessiner/Sélectionner / Draw/Select
- **Clic droit** - Menu contextuel / Context menu
- **Ctrl+Z** - Annuler / Undo
- **Ctrl+Y** - Refaire / Redo
- **Ctrl+S** - Sauvegarder / Save
- **Ctrl+O** - Ouvrir / Open
- **Molette** - Zoom / Zoom
- **Espace+Glisser** - Déplacer la vue / Pan view

## 🏗️ Architecture / Architecture

### 📁 Structure du projet / Project Structure
```
Paint/
├── src/
│   ├── core/
│   │   ├── engine.c         # Moteur principal / Main engine
│   │   ├── canvas.c         # Gestion du canevas / Canvas management
│   │   └── window.c         # Fenêtre et événements / Window and events
│   ├── tools/
│   │   ├── brush.c          # Outil pinceau / Brush tool
│   │   ├── shapes.c         # Formes géométriques / Geometric shapes
│   │   └── color.c          # Gestion couleurs / Color management
│   ├── ui/
│   │   ├── interface.c      # Interface utilisateur / User interface
│   │   ├── menus.c          # Menus et dialogs / Menus and dialogs
│   │   └── panels.c         # Panneaux latéraux / Side panels
│   └── io/
│       ├── file_manager.c   # Gestion fichiers / File management
│       ├── formats.c        # Formats d'image / Image formats
│       └── serialization.c  # Sérialisation données / Data serialization
├── include/                 # Headers
├── assets/                  # Ressources (icônes, polices)
└── Makefile
```

### 🎨 Structure du Canvas / Canvas Structure
```c
typedef struct canvas_s {
    sfTexture *texture;          // Texture SFML
    sfSprite *sprite;            // Sprite d'affichage
    sfUint8 *pixels;            // Données de pixels
    int width, height;          // Dimensions
    int zoom_level;             // Niveau de zoom
    sfVector2f offset;          // Décalage de vue
    layer_t *layers;            // Système de calques
    history_t *history;         // Historique des actions
} canvas_t;
```

## 🎭 Système de calques / Layer System

### 📚 Gestion des calques / Layer Management
```c
typedef struct layer_s {
    sfTexture *texture;         // Contenu du calque
    char name[64];              // Nom du calque
    float opacity;              // Opacité (0.0 - 1.0)
    bool visible;               // Visibilité
    blend_mode_t blend_mode;    // Mode de fusion
    struct layer_s *next;       // Calque suivant
} layer_t;
```

### 🔄 Modes de fusion / Blend Modes
- ✅ **Normal** - Superposition standard
- ✅ **Multiply** - Multiplication des couleurs
- ✅ **Screen** - Éclaircissement
- ✅ **Overlay** - Superposition conditionnelle
- ✅ **Soft Light** - Lumière douce
- ✅ **Hard Light** - Lumière dure

## 🧠 Algorithmes / Algorithms

### 🖌️ Algorithme de trait / Line Drawing Algorithm
```c
// Implémentation de Bresenham pour traits lisses
void draw_line(canvas_t *canvas, sfVector2i start, sfVector2i end, sfColor color) {
    // Algorithme de Bresenham optimisé
    // Anti-aliasing pour qualité supérieure
}
```

### 🔴 Remplissage par diffusion / Flood Fill Algorithm
```c
// Remplissage récursif optimisé avec pile
void flood_fill(canvas_t *canvas, int x, int y, sfColor new_color, sfColor target_color) {
    // Stack-based flood fill pour éviter dépassement pile
    // Optimisations pour grandes zones
}
```

### 🎨 Filtres et effets / Filters and Effects
```c
// Convolution pour filtres (blur, sharpen, edge detection)
void apply_filter(canvas_t *canvas, float kernel[3][3]) {
    // Convolution matricielle
    // Gestion des bords et optimisations SIMD
}
```

## 📄 Format de fichier propriétaire / Proprietary File Format

### 🗂️ Structure du fichier .mypaint / .mypaint File Structure
```
Header (64 bytes):
- Magic number: "MYPAINT1"
- Version: uint32
- Width, Height: uint32
- Layer count: uint32
- Compression: uint8
- Reserved: bytes

Layer Data:
- Layer info (name, opacity, blend mode)
- Compressed pixel data (zlib)
- Metadata (timestamps, tools used)
```

## 🎯 Optimisations / Optimizations

### ⚡ Performance / Performance
- ✅ **Dirty rectangles** - Redessinage partiel / Partial redrawing
- ✅ **Texture pooling** - Réutilisation mémoire / Memory reuse
- ✅ **Background rendering** - Rendu asynchrone / Async rendering
- ✅ **Cache intelligent** - Mise en cache des opérations / Operation caching

### 🧠 Mémoire / Memory
- ✅ **Compression** - RLE pour zones uniformes / RLE for uniform areas
- ✅ **Streaming** - Chargement progressif / Progressive loading
- ✅ **Garbage collection** - Nettoyage automatique / Automatic cleanup

## 🎊 Fonctionnalités avancées / Advanced Features

### 🎬 Animation (Extension)
- Timeline pour frames multiples
- Onion skinning (transparence des frames)
- Export en GIF animé
- Contrôles de lecture

### 🔌 Plugins (Futur)
- API pour extensions tierces
- Scripts Lua pour automatisation
- Filtres personnalisés
- Outils communautaires

## 🧪 Tests / Testing

```bash
# Tests unitaires pour algorithmes critiques
make test

# Tests d'interface avec validation visuelle
make test-ui

# Tests de performance et mémoire
make benchmark
```

## 📝 Licence / License
Ce projet est sous licence MIT.
*This project is under MIT license.*
