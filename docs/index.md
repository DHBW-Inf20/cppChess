# YetAnotherChessGame
YetAnotherChessGame is a chess game for the command-line.

## Build the Game

### Requirements
You need an active installation of the C++-Compiler gcc and make.

### Call Make to build the game
Call Make with the option -f to add the makefile in the root of the project as param and use .PHONY as target.<br>
```makefile
make -f MAKEFILE .PHONY
```

### Arguments
verbose=1<br>Enables the verbose-mode<br>

target_file=[file.exe]<br>Path to the output of the build-process - in this case file.exe. 
If not set, the File is called YetAnotherChessGame.exe and is saved the project root.

## Documentation

### Main-Screen 
Press:<br>
 1: Start a new Game.<br>
 2: Load a Game.<br>
 S: Open the settings.<br>
 Q: Quit the Game.<br>

### Settings
Press:<br>
1: Show figure icons instead of the figure names. The icons are only displayed correnctly, if the font in the console supports the Unicode chess figures. <br>
2: Show the possible moves after selecting a figure. This is recommended for beginners.<br>
3: Enable UI clearing after every move. <br>
4-7: Time control modes: <br>
&nbsp;4. None: Both players have as much time as they want. <br>
&nbsp;5. Blitz: 3min per player, 2s increment per move. <br>
&nbsp;6. Rapid: 30min per player, 10s increment per move. <br>
&nbsp;7. Classical: 2h per player for 40 moves, 30s increment per move. Then 1h for the rest of the game, no increment. <br>

### Input & Output
It is possible to save and load chess games. <br> 
To save a game in progress, first press "Q" and "Y" to exit the game. Then you will be asked, if you want to save the current position. If yes, you can enter a path where the CSV file will be saved. The path should be based on the relative location of the exe file. <br>
To load a game, press "2" in the main menu. You can enter the file path based on the relative location of the exe file. <br>

   
### The Game
A figure is described as the first letter of the color and the first letter of the name of the figure (white Rook -> wR). <br>

Depending on your selection in the settings menu, moving your figures works in different ways. If you enable the output of the possible moves, you have to enter the coordinate (f.E. E2) of the figure you want to move. Then you get a numbered list of possible moves. To select a move, enter the index of respective move. If the output of the possible moves is disabled, you first have to enter the coordinate of the figure to select it. Then you have to enter another coordinate of the square, you want the figure to move to. <br>

There is always the option to view the current material comparison. Each figure has a material value in pawn units. Therefore a pawn is worth 1 point, while bishop and knight are worth 3 points, rooks 5 points and queens 9 points. The material comparison tells you, whether you are up or down how many points of material on the board. <br>

The orientation of the board adapts to the player, who has the move. Therefore, the board rotates after every move. The players get a notification when they are in check. If a checkmate or stalemate is on the board, the game ends and the result is announced. <br>

## License
The Project is licensed under the General Public License V3.