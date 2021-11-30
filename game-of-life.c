#include <stdio.h>
#include "SDL.h"

#define WINDOW_W 1200		// Window width in pixels
#define WINDOW_H 750		// Window height in pixels
#define CELL_SIZE 15		// Cell size in pixels

#define BACKGROUND_COLOR 20		// Will be used as rgb. Yes, only gray because it is elegant.
#define CELL_COLOR 200			// Color to display cells
#define GRID_COLOR 75			// Color for the g grid.

#define FPS 60			// Will wait 1000ms/FPS between frames
#define DELAY 500		// Will set this as delay instead of the fps if the value is not 0 and the space is pressed

#define DEBUG_PRINT 1

int draw_grid(SDL_Renderer* renderer);

int main(int argc, char* argv[]) {
	int cell_grid[WINDOW_H/CELL_SIZE][WINDOW_W/CELL_SIZE];
	
	// Clear the array
	for (int y = 0; y < WINDOW_H/CELL_SIZE; y++) {
		for (int x = 0; x < WINDOW_W/CELL_SIZE; x++) {
			cell_grid[y][x] = 0;
		}
	}

	// Start SDL
	if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) != 0) {
		SDL_Log("Unable to start: %s\n", SDL_GetError());
		return 1;
	}
	printf("SLD started!\n");
	
	// Create window
	SDL_Window* fuckwindows = SDL_CreateWindow("Conway's game of life", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_W, WINDOW_H, 0); 
	if (!fuckwindows) {
		printf("Error creating a window: %s\n", SDL_GetError());
		SDL_Quit();
		return 1;
	}
	printf("Window created!\n");

	// Create renderer
	Uint32 render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
	SDL_Renderer* fuckrenderers = SDL_CreateRenderer(fuckwindows, -1, render_flags);
	if (!fuckrenderers) {
		printf("Error creating a renderer: %s\n", SDL_GetError());
		SDL_DestroyWindow(fuckwindows);
		SDL_Quit();
		return 1;
	}
	printf("Renderer created!\n");

	// Main loop
	int running = 0, draw_grid_active = 0, close_cell_count = 0;
	int space_pressed = 1;
	int mouse_pressed = 1, mouse_x, mouse_y;
	SDL_Rect current_cell;
	SDL_Event fuckevents;	// Create an event for the keys and shit
	while (running == 0) {
		// Events
		while (SDL_PollEvent(&fuckevents)) {
			switch (fuckevents.type) {
				// Window is closed?
				case SDL_QUIT:
					running = 1;
					break;
				case SDL_KEYDOWN:
					// Check the pressed key
					switch (fuckevents.key.keysym.scancode) {
						case SDL_SCANCODE_ESCAPE:
							running = 1;
							printf("Esc key pressed!\n");
							break;
						case SDL_SCANCODE_G:
							if (draw_grid_active == 0) {
								draw_grid_active = 1;
							} else {
								draw_grid_active = 0;
							}
							printf("G key pressed!\n");
							break;
						case SDL_SCANCODE_SPACE:
							space_pressed = 0;
							//printf("Space key pressed!\n");
							break;
						default:
							break;
					}
					break;
				case SDL_KEYUP:
					// Check the released key
					switch (fuckevents.key.keysym.scancode) {
						case SDL_SCANCODE_SPACE:
							space_pressed = 1;
							printf("Space key released!\n");
							break;
						default:
							break;
					}
					break;
				case SDL_MOUSEBUTTONDOWN:
					switch (fuckevents.button.button) {
						case SDL_BUTTON_LEFT:
							mouse_x = fuckevents.motion.x-2;
							mouse_y = fuckevents.motion.y-2;
							mouse_pressed = 0;
							printf("LMouse key pressed at %d %d!\n", mouse_x, mouse_y);
							break;
						default:
							break;
					}
					break;
				case SDL_MOUSEBUTTONUP:
					switch (fuckevents.button.button) {
						case SDL_BUTTON_LEFT:
							mouse_pressed = 1;
							if (cell_grid[mouse_y/CELL_SIZE][mouse_x/CELL_SIZE] == 1) {
								cell_grid[mouse_y/CELL_SIZE][mouse_x/CELL_SIZE] = 0;
							} else {
								cell_grid[mouse_y/CELL_SIZE][mouse_x/CELL_SIZE] = 1;
							}
							printf("LMouse key released! Setting cell [%d,%d] to %d.\n", mouse_y/CELL_SIZE, mouse_x/CELL_SIZE, cell_grid[mouse_y/CELL_SIZE][mouse_x/CELL_SIZE]);
							break;
						default:
							break;
					}
				default:
					break;
			}
		}

		// Clear window
		SDL_SetRenderDrawColor(fuckrenderers, BACKGROUND_COLOR, BACKGROUND_COLOR, BACKGROUND_COLOR, 255);
		SDL_RenderClear(fuckrenderers);
		// Actual game of life, if you find a better way to do this feel free to fork and push
		if (space_pressed == 0) {
			for (int y = 0; y < WINDOW_H/CELL_SIZE; y++) {
				for (int x = 0; x < WINDOW_W/CELL_SIZE; x++) {
					close_cell_count = 0;
					// Check the ammount of cells near and count. I am sure there is a better way
					if (y > 0 && x > 0 && cell_grid[y-1][x-1] == 1) {
						close_cell_count++;
					} if (y > 0 && cell_grid[y-1][x] == 1) {
						close_cell_count++;
					} if (y > 0 && x < WINDOW_W/CELL_SIZE-1 && cell_grid[y-1][x+1] == 1) {
						close_cell_count++;
					} if (x > 0 && cell_grid[y][x-1] == 1) {
						close_cell_count++;
					} if (x < WINDOW_W/CELL_SIZE-1 && cell_grid[y][x+1] == 1) {
						close_cell_count++;
					} if (y < WINDOW_H/CELL_SIZE-1 && x > 0 && cell_grid[y+1][x-1] == 1) {
						close_cell_count++;
					} if (y < WINDOW_H/CELL_SIZE-1 && cell_grid[y+1][x] == 1) {
						close_cell_count++;
					} if (y < WINDOW_H/CELL_SIZE-1 && x < WINDOW_W/CELL_SIZE-1 && cell_grid[y+1][x+1] == 1) {
						close_cell_count++;
					} 

					// Debug
					if (DEBUG_PRINT == 0) {
						if (close_cell_count > 0 && cell_grid[y][x] == 1) {
							printf("Position [%d,%d] has %d cells close.\n", y, x, close_cell_count);
						}
					}

					// Based on the close cells, apply rule
					if (cell_grid[y][x] == 1) {
						if (close_cell_count < 2 || close_cell_count > 4) {
							cell_grid[y][x] = 0;
						} else {
							cell_grid[y][x] = 1;
						}
					} else {
						if (close_cell_count == 3) {
							cell_grid[y][x] = 1;
						}
					}
				}
			}
		}
		// Draw cells depending on the array
		SDL_SetRenderDrawColor(fuckrenderers, CELL_COLOR, CELL_COLOR, CELL_COLOR, 255);
		for (int y = 0; y < WINDOW_H/CELL_SIZE; y++) {
			for (int x = 0; x < WINDOW_W/CELL_SIZE; x++) {
				if (cell_grid[y][x] == 1) {
					current_cell.x = x*CELL_SIZE;
					current_cell.y = y*CELL_SIZE;
					current_cell.w = CELL_SIZE;
					current_cell.h = CELL_SIZE;
					SDL_RenderFillRect(fuckrenderers, &current_cell);
				}
			}
		}
		// Draw grid if active (after clear)
		if (draw_grid_active == 0) {
			draw_grid(fuckrenderers);
		}
		// Send to window
		SDL_RenderPresent(fuckrenderers);
		if (space_pressed == 0 && DELAY != 0) {
			SDL_Delay(DELAY);  // Divide 1000ms to the frames in one seccond to know the wait time + delay
		} else {
			SDL_Delay(1000/FPS);  // Divide 1000ms to the frames in one seccond to know the wait time + delay
		}
	}

	// End of the program	
	printf("Reached end of the program!\n");
	SDL_DestroyRenderer(fuckrenderers);
	SDL_DestroyWindow(fuckwindows);
	SDL_Quit();

	return 0;
}

int draw_grid(SDL_Renderer* fuckrenderers) {
	SDL_SetRenderDrawColor(fuckrenderers, GRID_COLOR, GRID_COLOR, GRID_COLOR, 255);
	for (int x_grid = CELL_SIZE; x_grid < WINDOW_W; x_grid = x_grid + CELL_SIZE) {
		SDL_RenderDrawLine(fuckrenderers, x_grid, 0, x_grid, WINDOW_H);
	}
	for (int y_grid = CELL_SIZE; y_grid < WINDOW_H; y_grid = y_grid + CELL_SIZE) {
		SDL_RenderDrawLine(fuckrenderers, 0, y_grid, WINDOW_W, y_grid);
	}
	return 0;
}
