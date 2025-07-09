# 🐚 42sh - Advanced UNIX Shell

## 📋 Description / Description

**FR:** 42sh est une implémentation complète et avancée d'un shell UNIX en C. Ce projet reproduit les fonctionnalités principales de bash avec support des pipes, redirections, built-ins, gestion des signaux et bien plus encore.

**EN:** 42sh is a complete and advanced implementation of a UNIX shell in C. This project reproduces the main functionalities of bash with support for pipes, redirections, built-ins, signal handling and much more.

## 🚀 Technologies utilisées / Technologies Used
- **Langage / Language:** C
- **Système / System:** UNIX System Calls
- **Parsing:** Lexical and syntactic analysis
- **IPC:** Inter-Process Communication

## 📦 Installation et exécution / Installation and Execution

```bash
# Navigate to project
cd 42sh

# Compile the shell
make

# Run the shell
./42sh

# Run with script file
./42sh script.sh

# Clean build files
make clean
```

## 🎯 Fonctionnalités / Features

### 🔧 Commandes intégrées / Built-in Commands
- ✅ `cd` - Changement de répertoire / Directory change
- ✅ `echo` - Affichage de texte / Text display  
- ✅ `env` - Variables d'environnement / Environment variables
- ✅ `setenv/unsetenv` - Gestion des variables / Variable management
- ✅ `exit` - Sortie du shell / Shell exit
- ✅ `history` - Historique des commandes / Command history
- ✅ `alias/unalias` - Gestion des alias / Alias management

### 🔄 Redirections et Pipes / Redirections and Pipes
- ✅ `|` - Pipes simples / Simple pipes
- ✅ `>` - Redirection de sortie / Output redirection
- ✅ `>>` - Redirection en mode ajout / Append redirection
- ✅ `<` - Redirection d'entrée / Input redirection
- ✅ `<<` - Here document
- ✅ Pipes multiples / Multiple pipes

### 🎛️ Contrôle de processus / Process Control
- ✅ `Ctrl+C` - Interruption de processus / Process interruption
- ✅ `Ctrl+D` - EOF handling
- ✅ `Ctrl+Z` - Suspension de processus / Process suspension
- ✅ `&` - Exécution en arrière-plan / Background execution
- ✅ `jobs` - Liste des tâches / Job listing
- ✅ `fg/bg` - Gestion foreground/background / Foreground/background management

### 🧠 Fonctionnalités avancées / Advanced Features
- ✅ Expansion des variables / Variable expansion (`$VAR`)
- ✅ Expansion des tildes / Tilde expansion (`~`)
- ✅ Globbing / Wildcard expansion (`*`, `?`)
- ✅ Échappement de caractères / Character escaping
- ✅ Guillemets simples et doubles / Single and double quotes
- ✅ Commentaires / Comments (`#`)

## 🎮 Utilisation / Usage

### 💻 Exemples de commandes / Command Examples

```bash
# Commandes simples / Simple commands
ls -la
echo "Hello World"

# Pipes
ls | grep ".c" | wc -l

# Redirections
echo "test" > file.txt
cat < input.txt > output.txt

# Variables
export MY_VAR="value"
echo $MY_VAR

# Contrôle de jobs / Job control
sleep 100 &
jobs
fg %1
```

### 📝 Scripts
Le shell supporte l'exécution de scripts avec :
- Commentaires avec `#`
- Variables et expansions
- Structures de contrôle
- Fonctions

## 🏗️ Architecture / Architecture

```
42sh/
├── src/
│   ├── parsing/     # Analyseur lexical et syntaxique
│   ├── execution/   # Moteur d'exécution
│   ├── builtins/    # Commandes intégrées
│   ├── signals/     # Gestion des signaux
│   └── utils/       # Fonctions utilitaires
├── include/         # Headers
└── tests/           # Tests unitaires
```

## 🔍 Parsing Process / Processus d'analyse

**FR:**
1. **Lexical:** Tokenisation de la ligne de commande
2. **Syntaxique:** Construction de l'arbre syntaxique  
3. **Sémantique:** Validation et optimisation
4. **Exécution:** Lancement des processus

**EN:**
1. **Lexical:** Command line tokenization
2. **Syntactic:** Syntax tree construction
3. **Semantic:** Validation and optimization  
4. **Execution:** Process launching

## 🧪 Tests / Testing

```bash
# Run unit tests
make tests

# Test specific functionality
./tests/test_pipes.sh
./tests/test_redirections.sh
./tests/test_builtins.sh
```

## 📊 Compatibilité / Compatibility

- ✅ POSIX compliant
- ✅ Compatible bash pour la plupart des fonctionnalités
- ✅ Support des systèmes Linux/Unix
- ✅ Gestion robuste des erreurs

## 📝 Licence / License
Ce projet est sous licence MIT.
*This project is under MIT license.*
