# cub3d

### To run on wayland based distros:
`sudo dnf install libX11-devel libXext-devel libXrender-devel libbsd-devel`

### In minilibx_linux/Makefile.mk:4
The default compiler also needs to be changed in order to match the
prototyping requirement of school computers.
change to `CC	= clang`

your own files should also be compiled using clang
