<div align="center">
	<h1>Game of life</h1>
	<b><a href="https://en.wikipedia.org/wiki/Conway's_Game_of_Life">Conway's game of life</a> made in C using <a href="https://www.libsdl.org/index.php">sdl2</a>.</b><br><br>
	<a href="https://github.com/r4v10l1/game-of-life/network/members"><img src="https://img.shields.io/github/forks/r4v10l1/game-of-life.svg?style=for-the-badge&logo=c&color=a8b9cc&logoColor=a8b9cc" alt="Forks"></a>
	<a href="https://github.com/r4v10l1/game-of-life/stargazers"><img src="https://img.shields.io/github/stars/r4v10l1/game-of-life.svg?style=for-the-badge&logo=c&color=a8b9cc&logoColor=a8b9cc" alt="Stars"></a>
</div>

# Table of contents
1. [Keys](https://github.com/r4v10l1/game-of-life#Keys)
1. [Configuration](https://github.com/r4v10l1/game-of-life#Configuration)

## Keys
Key      | Action
---------|------------
`Esc`    | Exit.
`LMouse` | Change the cell's state.
`Space`  | Hold to start the game of life simulation.
`G`      | Togge grid.
`S`      | Save current state.
`L`      | Load current state.
`C`      | Clear (Set state of all cells to 0).
`R`      | Random state (Not yet implemented).

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
