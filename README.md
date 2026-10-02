# discord-bot

A C++ discord bot for the Better-Cpp discord server

## Requirements

- GCC 16 for C++ 26
- CMake 3.30+
- Ninja
- Conan 2.x

## Build

One time setup:

```bash
canon profile detect
```

```bash
conan install . --build=missing \
    -s build_type=Release \
    -s compiler=gcc \
    -s compiler.version=16 \
    -s compiler.cppstd=26 \
    -c tools.build:compiler_executables="{'c': 'gcc-16', 'cpp': 'g++-16'}" \
    -c tools.cmake.cmaketoolchain:generator=Ninja
cmake --preset conan-release
cmake --build --preset conan-release
```
