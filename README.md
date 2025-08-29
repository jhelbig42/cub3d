# cub3d

Cub3D is a simple raycasting 3D engine inspired by Wolfenstein 3D and Doom.  
It was built for the 42/School project requirements using minilibX.  
The player can explore a 2.5D maze, open doors, and navigate with WASD-style movement.  

---

## 📸 Demo

(Add gameplay GIFs here — recorded with peek or ScreenToGif for example.)  

- Gameplay:  
  [Demo](images/skin_julia.gif)  

  [Demo_2](images/skin_urs.gif)  

- Minimap:  
  ![Demo_3](images/minimap.gif)  

---

## ⚙️ Requirements

- clang compiler  
- make  
- minilibX  
- X11 libraries (for Linux)  

---

## 🖥️ Installation

Clone the repository:  
### To run on wayland based distros:
`sudo dnf install libX11-devel libXext-devel libXrender-devel libbsd-devel`

### In minilibx_linux/Makefile.mk:4
The default compiler also needs to be changed in order to match the
prototyping requirement of school computers.
change to `CC	= clang`

your own files should also be compiled using clang
