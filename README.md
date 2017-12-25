# FDF 42
This project consists in graphically creating the schematic representation of a terrain in relief.

![screenshot](/fdf/screens/fdf_42.png?raw=true)

# Features

-Possibility to move, rotate the image and to reinitialize it.

-Display colors according to the elevation of the point.

-Display a color gradient between a point in height and a neutral point.

-Dynamic management of elevation.

-Dynamic zoom management.

-Display of the FPS.

-Dynamic color management (with the mouse or mouse wheel).

-Line clipping

# Usage

Run `make`. An executable will compile. Currently only tested on OS X.

Run it with `./fdf [-bonus.fr] [-bonus.en] [map.fdf]`.
The flags `-bonus.fr` shows the bonus list.
Some maps have been created in 'test_maps' folder.
