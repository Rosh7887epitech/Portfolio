# 🎯 Raytracer – B-OOP-400

🧠 **A CPU-powered raytracer written in C++** – built for the Epitech B-OOP-400 module.
Simulates the path of light to render a 3D scene into a 2D image, using a basic scene description file.

---

## 🚀 Getting Started

### 🛠 Requirements
- C++
- `make`
- `libconfig++` (for parsing `.cfg` scene files)

---

### ⚙️ Build

```bash
make
```

The binary will be generated at the root as:

```bash
./raytracer
```

To clean the project:

```bash
make clean     # Remove objects
make fclean    # Remove objects and binary
make re        # Rebuild everything
```

---

## 📂 Project Structure

```
.
├── src/               # Source code implementation + Header files (core, primitives, lights, utils)
├── plugins/           # .so dynamic plugins
├── scenes/            # Example scene configuration files (.cfg)
├── screenshots/       # Generated PPM images
├── tests/             # Optional: unit tests
├── Makefile           # Project build system
├── Main.cpp           # Program entry point
└── README.md          # This file
```

---

## 🎮 Usage

```bash
./raytracer <SCENE_FILE>
```

Example:

```bash
./raytracer scenes/demo_sphere.cfg
```

---

## 🧾 Scene File Format (`.cfg`)

Scene files describe what to render: camera, lights, objects.
They are parsed using [`libconfig++`](https://hyperrealm.github.io/libconfig/libconfig_manual.html).

```cfg
camera: {
  resolution = { width = 800; height = 600; };
  position = { x = 0; y = -100; z = 20; };
  rotation = { x = 0; y = 0; z = 0; };
  fieldOfView = 72.0;
};

primitives: {
  spheres = (
    { x = 0; y = 0; z = 40; r = 25; color = { r = 255; g = 0; b = 0; }; }
  );
  planes = (
    { axis = "Z"; position = -20; color = { r = 0; g = 0; b = 255; }; }
  );
};

lights: {
  ambient = 0.4;
  diffuse = 0.6;
  point = (
    { x = 400; y = 100; z = 500; }
  );
};
```

---

## ✅ Mandatory Features

- [x] Ray-sphere and ray-plane intersection
- [x] Flat color rendering
- [x] Directional & ambient lighting
- [x] Scene loaded from `.cfg` file
- [x] Output to `.ppm` image

---

## 🔜 Upcoming / Bonus Features (optional)

- [ ] Cylinder / Cone primitives
- [ ] Shadows
- [ ] Rotation & transformation matrix
- [ ] Reflections / Transparency
- [ ] OBJ mesh loader
- [ ] Multi-threading
- [ ] GUI preview or interactive rendering

---

## 📸 Screenshots

Images will be saved in the `./screenshots/` folder after rendering.

---

## 👨‍💻 Author

Made by Robin Schuffenecker, Titouan Bouillot-Bachelier & Evann Bloutin – 2nd year students at Epitech Nantes.
Feel free to fork, learn, or build upon it – no license required 😉.
