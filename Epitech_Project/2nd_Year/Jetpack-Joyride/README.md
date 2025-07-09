# Jetpack - Fly to the Networking World

## Description
Jetpack is a multiplayer game inspired by **Jetpack Joyride**, developed in **C/C++**, with a **client-server architecture**.
Players compete by collecting coins and avoiding electric obstacles.

## 📌 Main Features
- **Multiplayer networking** via **TCP** (using `poll(2)`).
- **Client-server**: The server manages the game, and clients display it.
- **Custom network protocol** to be designed and documented.
- **Collision and scoring system**.
- **Multithreading**: one thread for network communication and another for rendering.

## 🛠️ Technologies Used
- **Languages**: C / C++
- **Networking**: `poll(2)`, TCP
- **Graphics**: SFML, SDL, CSFML, or others
- **Build system**: `Makefile`

## 📝 Coding Standards
This project follows the [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html) for consistent code formatting, naming conventions, and best practices.

## 📦 Installation
1. Clone the repository:
   ```bash
   git clone git@github.com:EpitechPromo2028/B-NWP-400-NAN-4-1-jetpack-romain.berard.git Jetpack
   cd Jetpack
   ```
2. Build the project:
   ```bash
   make all
   ```

## 🚀 Running the Server
```bash
./jetpack_server -p <port> -m <map> [-d]
```
- `-p <port>`: Sets the listening port.
- `-m <map>`: Loads a specific map.
- `-d` (optional): Debug mode.

## 🎮 Running the Client
```bash
./jetpack_client -h <ip> -p <port> [-d]
```
- `-h <ip>`: Server IP address.
- `-p <port>`: Server port.
- `-d` (optional): Debug mode.

## 📜 Documentation
A **RFC-formatted** document (`doc.txt`) describes the network protocol and map format.
