# YetAnotherChessGame
It is a chess game for the command-line.

## Build the Game

### Requirements
You need an active installation of the c++-Compiler gcc and make.

### Call Make to build the game
Call Make with the option -f to add the makefile in the root of the project as param and use .PHONY as target.<br>
```makefile
make -f MAKEFILE .PHONY
```

### Arguments
verbose=1<br>Enables the verbose-mode<br>

target_file=[file.exe]<br>Path to the output of the build-process in this case file.exe. 
If not set, the File is called YetAnotherChessGame.exe and is in the project root.

## Documentation

### Main-Screen 
Press:<br>
 1: To start a new Game.<br>
 2: To load a Game.<br>
 S: To open the settings.<br>
 Q: To exit the Game.<br>

### Settings
Press:<br>
 1: To show Icons instead of the name of the figures. <br>They are only supported if the font in the Console supports the Unicode-Chess-figures.<br>
 2: To show the possible moves (For Beginners).<br>
 3-6: Modes for Time:
  3. No Time Mode
  4. Blitz-Mode<br>
     Time: 3min, for every move 2s extra time.
  5. Rapid-Mode<br>
     Time: 30min, for every move 10s extra time.
  6. Classical-Mode<br>
     Time: 2h 40 Moves, for every move 30s extra time.<br>
      then 1h for the rest of the game.
     
### The Game
A figure is described as the first letter of the color and the first letter of the name of the figure.<br>
Example: White Rook - wR <br>

When you start the game, you can save it, when you close the game with q. You will be asked if you are sure.<br>
After that you will be asked if you want to save the game. Then you have to enter a path to a file (csv).<br>

To change the position you have to enter the position of a valid figure. <br>
To do that enter as first Coordinate the horizontal Coordinate as letter and the second Coordinate as number.<br>
For Example: A1<br>
Then you have to enter a number of the list or the end coordinates.

## License
The Project is licensed under the General Public License V3.