# FDF 42
This project consists in graphically creating the schematic representation of a terrain in relief.

The subject can be fond here https://cdn.intra.42.fr/pdf/pdf/881/fdf.en.pdf in english and here https://cdn.intra.42.fr/pdf/pdf/19/fdf.fr.pdf in french

![screenshot](/fdf/screens/fdf_42.png?raw=true)

# Features

-Possibility to move, rotate the model and to reinitialize it.

-Display colors according to the elevation of the point.

-Possiblity to change the color directly in the file in this way: <height\>,0xRRGGBB

-Display a color gradient between a point in height and a neutral point.

-Dynamic management of elevation.

-Dynamic zoom management.

-Display of the FPS.

-Dynamic color management (with the mouse or mouse wheel).

-Line clipping.

-Anti-aliasing.

-Management of the 'button stayed pressed' utility.

# Usage

Run `make`. An executable will compile.

Run it with `./fdf [-bonus.fr] [-bonus.en] [-leaks] [-lcolor <hex color\>] [-ucolor <hex color\>] map`.

`-bonus.fr` and `-bonus.en` shows the bonus list, respectively in french and english.

`-leaks` activates an infinite loop before the end of the program.

`'-lcolor` ans `-ucolor` allows to choose the default color for respectively the lowest ans the highest point, by default it's FFFFFF and FF0000.

Some maps have been created in 'test_maps' folder.
