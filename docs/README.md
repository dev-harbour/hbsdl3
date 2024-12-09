
# hbsdl2 Installation Guide

`hbsdl3` is a library for integrating Harbour with SDL3. This guide explains how to install `hbsdl3` on Windows (using MSYS2) and Linux (Debian-based systems).

---

## Installation on Windows (MSYS2)

### Prerequisites
Ensure you are running the **MinGW 64-bit shell**.

1. Install required packages:
   ```bash
   pacman -S mingw-w64-x86_64-toolchain mingw-w64-x86_64-cmake
   ```

2. Install SDL3:
   ```bash
   git clone https://github.com/libsdl-org/SDL
   cd SDL
   mkdir build
   cd build
   cmake -G"MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/mingw64 ..
   mingw32-make -j$(nproc)
   mingw32-make install
   ```

3. Clone the `hbsdl3` repository:
   ```bash
   git clone https://github.com/dev-harbour/hbsdl3
   ```

4. Build the static library:
   ```bash
   cd hbsdl3
   hbmk2 hbsdl3.hbp
   ```

5. Run tests or examples:
   ```bash
   cd tests
   hbmk2 main.prg
   ```

---

## Installation on Linux (Debian-based systems)

### Prerequisites
Ensure you have development tools like `git`, `cmake`, and a Harbour compiler installed.

1. Install SDL3:
   ```bash
   git clone https://github.com/libsdl-org/SDL
   cd SDL
   mkdir build
   cd build
   cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/usr ..
   cmake --build . --config Release --parallel
   sudo cmake --install . --config Release
   ```

2. Clone the `hbsdl3` repository:
   ```bash
   git clone https://github.com/dev-harbour/hbsdl3
   ```

3. Build the static library:
   ```bash
   cd hbsdl3
   hbmk2 hbsdl3.hbp
   ```

4. Run tests or examples:
   ```bash
   cd tests
   hbmk2 main.prg
   ```

---

## Notes

- **SDL3 Installation**: Ensure SDL3 is properly installed in the expected directories. For Windows, use `/mingw64`, and for Linux, use `/usr`.
- **Testing**: Always verify that both SDL3 and `hbsdl3` are installed correctly by running the included test programs.
- **Parallel Compilation**: The `-j$(nproc)` flag in `make` optimizes the build process by using all available CPU cores.

---
