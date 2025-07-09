# 📋 Organized - File Organization System

## 📋 Description / Description

**FR:** Organized est un système intelligent d'organisation et de gestion de fichiers. Il permet de trier automatiquement des fichiers selon différents critères, d'effectuer des recherches avancées et de maintenir une structure organisée de vos données.

**EN:** Organized is an intelligent file organization and management system. It allows automatic file sorting according to different criteria, advanced searches, and maintaining an organized structure of your data.

## 🚀 Technologies utilisées / Technologies Used
- **Langage / Language:** C
- **Système / System:** UNIX File System APIs
- **Interface / Interface:** Terminal-based UI
- **Parsing:** Command line argument parsing

## 📦 Installation et exécution / Installation and Execution

```bash
# Navigate to project
cd Organized

# Compile the project
make

# Run the organizer
./organized [options] [directory]

# Examples
./organized -s date ~/Documents
./organized -f "*.pdf" -d ~/Downloads

# Clean build files
make clean
```

## 🎯 Fonctionnalités / Features

### 📁 Organisation automatique / Automatic Organization
- ✅ Tri par type de fichier / Sort by file type
- ✅ Tri par date de création/modification / Sort by creation/modification date
- ✅ Tri par taille / Sort by size
- ✅ Tri alphabétique / Alphabetical sort
- ✅ Création de dossiers automatique / Automatic folder creation

### 🔍 Recherche avancée / Advanced Search
- ✅ Recherche par nom / Search by name
- ✅ Recherche par extension / Search by extension
- ✅ Recherche par taille / Search by size
- ✅ Recherche par date / Search by date
- ✅ Expressions régulières / Regular expressions
- ✅ Filtres combinés / Combined filters

### 📊 Statistiques / Statistics
- ✅ Nombre de fichiers par type / File count by type
- ✅ Taille totale par catégorie / Total size by category
- ✅ Distribution des tailles / Size distribution
- ✅ Fichiers les plus volumineux / Largest files
- ✅ Fichiers récents / Recent files

### 🔧 Gestion des doublons / Duplicate Management
- ✅ Détection de doublons / Duplicate detection
- ✅ Comparaison par hash MD5 / MD5 hash comparison
- ✅ Suppression intelligente / Smart deletion
- ✅ Sauvegarde avant suppression / Backup before deletion

## 🎮 Utilisation / Usage

### 💻 Options de ligne de commande / Command Line Options

```bash
# Tri par type / Sort by type
./organized -t ~/Downloads

# Tri par date / Sort by date  
./organized -d ~/Documents

# Recherche de fichiers / File search
./organized -f "*.jpg" ~/Pictures

# Statistiques / Statistics
./organized -s ~/

# Mode verbose / Verbose mode
./organized -v -t ~/Downloads

# Aide / Help
./organized -h
```

## 🏗️ Structure du projet / Project Structure

```
Organized/
├── src/
│   ├── core/        # Moteur principal / Core engine
│   ├── sorting/     # Algorithmes de tri / Sorting algorithms
│   ├── search/      # Moteur de recherche / Search engine
│   ├── stats/       # Calcul de statistiques / Statistics calculation
│   └── ui/          # Interface utilisateur / User interface
├── include/         # Headers
├── shell/           # Scripts shell / Shell scripts
└── basic/           # Fonctions de base / Basic functions
```

## 🔄 Algorithmes de tri / Sorting Algorithms

**FR:**
1. **Par type:** Analyse de l'extension et du contenu
2. **Par date:** Tri chronologique avec préservation
3. **Par taille:** Organisation par tranche de taille
4. **Intelligent:** Combinaison de plusieurs critères

**EN:**
1. **By type:** Extension and content analysis
2. **By date:** Chronological sorting with preservation
3. **By size:** Organization by size range
4. **Intelligent:** Combination of multiple criteria

## 📊 Exemples de sortie / Output Examples

```
=== Organized Statistics ===
📁 Total files: 1,234
📂 Total directories: 56
💾 Total size: 2.3 GB

📋 By file type:
- Documents (PDF, DOC): 456 files (1.2 GB)
- Images (JPG, PNG): 321 files (890 MB)  
- Videos (MP4, AVI): 89 files (200 MB)
- Others: 368 files (10 MB)

🕒 By modification date:
- Last week: 123 files
- Last month: 456 files
- Older: 655 files
```

## 🔒 Sécurité / Security

- ✅ Sauvegarde automatique avant modifications
- ✅ Validation des chemins d'accès
- ✅ Permissions de fichiers préservées
- ✅ Journal des opérations / Operation logging
- ✅ Mode simulation (dry-run)

## 📝 Licence / License
Ce projet est sous licence MIT.
*This project is under MIT license.*
Ce projet est sous licence MIT.
