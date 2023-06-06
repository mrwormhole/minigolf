# minigolf

[![Project Status: WIP – Initial development is in progress, but there has not yet been a stable, usable release suitable for the public.](https://www.repostatus.org/badges/latest/wip.svg)](https://www.repostatus.org/#wip)


3D minigolf in C(99) and Raylib(master).

Additionally [CONVENTIONS.md](https://github.com/mrwormhole/minigolf/blob/main/CONVENTIONS.md) is inherited from the creator of Raylib. And enforced for this repository. Please consider reading CONVENTIONS.md before opening a PR. Also ensure to run `valgrind` to avoid memory leaks on your code to increase confidence.

# Requirements

- Clang
- CMake
- Make

# How to Compile

```sh
    git clone https://github.com/mrwormhole/minigolf 
    mkdir build
    cd build
    cmake ..
    make minigolf && ./minigolf
```

# TODOs

- [X] create a ball
- [X] create a plane 
- [ ] add box collider to the meshe of plane
- [ ] add sphere collider to the mesh of ball
- [ ] add scene lightning, shaders and textures for models