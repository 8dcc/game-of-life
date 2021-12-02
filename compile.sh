#!/bin/sh

# Check if sdl2 is installed
if [[ $(command -v sdl2-config) == "" ]]; then
	echo "Cant' find sdl2. Exiting..."
	exit 1;
fi

SDL_FLAGS=$(sdl2-config --cflags --libs)
OUTPUT_FILE="game-of-life.o"

if [[ $1 == "" ]]; then
	echo "No arguments. Please enter a file. Exiting..."
	exit 1;
fi

# Compile the file
gcc -o $OUTPUT_FILE $1 $SDL_FLAGS

if [[ $2 == "comp" ]]; then
	echo "Compiled! Running..."
	./$OUTPUT_FILE
fi
