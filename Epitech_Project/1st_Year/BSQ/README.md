# 🔍 BSQ - Biggest Square

## 📋 Description / Description

**FR:** BSQ est une implémentation optimisée de l'algorithme permettant de trouver le plus grand carré vide dans une carte contenant des obstacles. Le programme utilise la programmation dynamique pour une performance maximale.

**EN:** BSQ is an optimized implementation of the algorithm to find the biggest empty square in a map containing obstacles. The program uses dynamic programming for maximum performance.

## 🚀 Technologies utilisées / Technologies Used
- **Langage / Language:** C
- **Bibliothèques / Libraries:** stdio.h, stdlib.h
- **Algorithme / Algorithm:** Dynamic Programming

## 📦 Installation et exécution / Installation and Execution

```bash
# Clone and navigate
cd BSQ

# Compile the project
make

# Run with a map file
./bsq map_file.txt

# Clean build files
make clean
```

## 🎯 Fonctionnement / How it Works

**FR:** 
1. Le programme lit un fichier contenant une grille avec des obstacles
2. Analyse la grille ligne par ligne en utilisant la programmation dynamique
3. Détermine la position et la taille du plus grand carré vide possible
4. Affiche le résultat avec le carré marqué

**EN:**
1. The program reads a file containing a grid with obstacles
2. Analyzes the grid line by line using dynamic programming
3. Determines the position and size of the biggest possible empty square
4. Displays the result with the square marked

## 📄 Format du fichier / File Format

```
7...
....
..o.
....
....
..o.
....
```

- Première ligne : nombre de lignes + caractères (vide, obstacle, carré)
- First line: number of lines + characters (empty, obstacle, square)

## 🏆 Fonctionnalités / Features

- ✅ Lecture et validation de cartes
- ✅ Algorithme de programmation dynamique optimisé  
- ✅ Gestion d'erreurs robuste
- ✅ Affichage du résultat formaté
- ✅ Support de cartes de taille variable

## 📊 Complexité / Complexity

- **Temporelle / Time:** O(n×m) où n et m sont les dimensions de la grille
- **Spatiale / Space:** O(n×m) pour stocker la grille

## 📝 Licence / License
Ce projet est sous licence MIT.
*This project is under MIT license.*
