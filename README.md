# Game of life
**Conway's game of life in C using sdl2.**

## Configuration
Name                     | Description
-------------------------|--------------
`int`-`WINDOW_H`         | Window height in pixels.
`int`-`WINDOW_W`         | Window width in pixels.
`int`-`CELL_SIZE`        | Cell size in pixels.
`int`-`BACKGROUND_COLOR` | Will be used as RGB value for the background.<br>For example `34 = RGB(34, 34, 34) = #222222`.
`int`-`CELL_COLOR`       | Will be used as RGB value for the living cells.
`int`-`GRID_COLOR`       | Will be used as RGB value for the grid.
`int`-`FPS`              | In ms. The program will wait 1000/FPS (1000 / 60 = 16ms between frames).
`int`-`DELAY`            | If the space is pressed the delay between frames will be switched to this.<br>(Instead of 16ms for example).
`int`-`DEBUG_PRINT`      | If 0, the program will print information about keypresses and cell interactions.
