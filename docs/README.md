
# hbsdl3 Installation Guide

`hbsdl3` is a library for integrating Harbour with SDL3. This guide explains how to install `hbsdl3` on Windows (using MSYS2) and Linux (Debian-based systems).

## Installation on Windows (MSYS2)

Ensure you are running the **MinGW 64-bit shell**.

- Install required packages:
   ```bash
   pacman -S mingw-w64-x86_64-toolchain mingw-w64-x86_64-cmake
   ```

- Install SDL3:
   ```bash
   git clone https://github.com/libsdl-org/SDL
   cd SDL
   mkdir build
   cd build
   cmake -G"MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/mingw64 ..
   mingw32-make -j$(nproc)
   mingw32-make install
   ```

- Clone the `hbsdl3` repository:
   ```bash
   git clone https://github.com/dev-harbour/hbsdl3
   ```

- Build the static library:
   ```bash
   cd hbsdl3
   hbmk2 hbsdl3.hbp
   ```

- Run tests or examples:
   ```bash
   cd tests
   hbmk2 main.prg
   ```

## Installation on Linux (Debian-based systems)

Ensure you have development tools like `git`, `cmake`, and a Harbour compiler installed.

- Install SDL3:
   ```bash
   git clone https://github.com/libsdl-org/SDL
   cd SDL
   mkdir build
   cd build
   cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/usr ..
   cmake --build . --config Release --parallel
   sudo cmake --install . --config Release
   ```

   ```bash
   git clone https://github.com/libsdl-org/SDL_ttf
   cd SDL_ttf
   # as above
   ```


- Clone the `hbsdl3` repository:
   ```bash
   git clone https://github.com/dev-harbour/hbsdl3
   ```

- Build the static library:
   ```bash
   cd hbsdl3
   hbmk2 hbsdl3.hbp
   ```

- Run tests or examples:
   ```bash
   cd tests
   hbmk2 main.prg
   ```
