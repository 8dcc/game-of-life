<div align="center">
	<h1>Game of life</h1>
	<b><a href="https://en.wikipedia.org/wiki/Conway's_Game_of_Life">Conway's game of life</a> made in C using <a href="https://www.libsdl.org/index.php">sdl2</a>.</b><br><br>
	<a href="https://github.com/8dcc/game-of-life/network/members"><img src="https://img.shields.io/github/forks/8dcc/game-of-life.svg?style=for-the-badge&logo=c&color=a8b9cc&logoColor=a8b9cc" alt="Forks"></a>
	<a href="https://github.com/8dcc/game-of-life/stargazers"><img src="https://img.shields.io/github/stars/8dcc/game-of-life.svg?style=for-the-badge&logo=c&color=a8b9cc&logoColor=a8b9cc" alt="Stars"></a>
</div>

# Table of contents
1. [Keys](https://github.com/8dcc/game-of-life#Keys)
2. [Configuration](https://github.com/8dcc/game-of-life#Configuration)
3. [Misc](https://github.com/8dcc/game-of-life#Misc)
4. [TODO](https://github.com/8dcc/game-of-life#TODO)

## Keys
Key               | Action
------------------|------------
<kbd>Esc</kbd>    | Exit.
<kbd>LMouse</kbd> | Change the cell's state individually.
<kbd>RMouse</kbd> | Change the cell's state (drag).
<kbd>Space</kbd>  | Hold to start the game of life simulation.
<kbd>H</kbd>      | Show help in console.
<kbd>G</kbd>      | Togge grid.
<kbd>S</kbd>      | Save current state.
<kbd>L</kbd>      | Load saved state.
<kbd>C</kbd>      | Clear (Set state of all cells to 0).
<kbd>R</kbd>      | Random state.

## Configuration
Name               | Description
-------------------|--------------
`WINDOW_H`         | Window height in pixels.
`WINDOW_W`         | Window width in pixels.
`CELL_SIZE`        | Cell size in pixels.
`BACKGROUND_COLOR` | Will be used as RGB value for the background.<br>For example `34 = RGB(34, 34, 34) = #222222`.
`CELL_COLOR`       | Will be used as RGB value for the living cells.
`GRID_COLOR`       | Will be used as RGB value for the grid.
`FPS`              | In ms. The program will wait 1000/FPS (1000 / 60 = 16ms between frames).
`DELAY`            | If the space is pressed the delay between frames will be switched to this.<br>(Instead of 16ms for example).
`DEBUG_PRINT`      | If 0, the program will print information about keypresses and cell interactions.

## Misc
- [SDL2 window template](https://gist.github.com/8dcc/a2fe5c689ebb7682f5d9c008df9cd17d)

## TODO
- [ ] Make saves independent on the array size (resolution)
