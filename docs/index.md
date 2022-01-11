# YetAnotherChessGame
YetAnotherChessGame is a chess game for the command-line. <br>
Project participants: Dominic Joas & Jannik Dürr

## Build the Game

### Requirements
You need an active installation of the C++ compiler gcc and make.

### Call Make to build the game
Call make with the option -f to add the makefile in the root of the project as param and use .PHONY as target.<br>
```makefile
make -f MAKEFILE .PHONY
```

### Arguments
verbose=1<br>Enables the verbose-mode<br>

target_file=[file.exe]<br>Path to the output of the build-process - in this case file.exe. 
If not set, the file is called YetAnotherChessGame.exe and is saved the project root.

## Documentation

### Start Menu 
Press:<br>
 1: Start a new game.<br>
 2: Load a game.<br>
 S: Open the settings.<br>
 Q: Quit the game.<br>

### Settings
Press:<br>
1: Show figure icons instead of the figure names. The icons are only displayed correnctly, if the font in the console supports the Unicode chess figures. <br>
2: Show the possible moves after selecting a figure. This is recommended for beginners.<br>
3: Enable UI clearing after every move. <br>
4-7: Time control modes: <br>
* (4) None: Both players have as much time as they want. <br>
* (5) Blitz: 3min per player, 2s increment per move. <br>
* (6) Rapid: 30min per player, 10s increment per move. <br>
* (7) Classical: 2h per player for 40 moves, 30s increment per move. Then 1h for the rest of the game, no increment. <br>

### Input & Output
It is possible to save and load chess games. <br> 
To save a game in progress, first press "Q" and "Y" to exit the game. Then you will be asked, if you want to save the current position. If yes, you can enter a path where the CSV file will be saved. The path should be based on the relative location of the exe file. <br>
To load a game, press "2" in the main menu. You can enter the file path based on the relative location of the exe file. <br>

   
### The Game
A figure is described as the first letter of the color and the first letter of the name of the figure (white Rook -> wR). <br>

Depending on your selection in the settings menu, moving your figures works in different ways. If you enable the output of the possible moves, you have to enter the coordinate (f.E. E2) of the figure you want to move. Then you get a numbered list of possible moves. To select a move, enter the index of respective move. If the output of the possible moves is disabled, you first have to enter the coordinate of the figure to select it. Then you have to enter another coordinate of the square, you want the figure to move to. <br>

There is always the option to view the current material comparison. Each figure has a material value in pawn units. Therefore a pawn is worth 1 point, while bishops and knights are worth 3 points, rooks 5 points and queens 9 points. The material comparison tells you, whether you are up or down how many points of material on the board. <br>

The orientation of the board adapts to the player, who has the move. Therefore, the board rotates after every move. The players get a notification when they are in check. If a checkmate or stalemate is on the board, the game ends and the result is announced. <br>

## Development and Modeling
The source code is divided into three packages: model, gui and helper. <br>
* model: The different types of chess figures (pawn, bishop, knight, rook, queen, king) are modeled by different classes, which all derive from the base class "Figure". All figure classes are gathered in the folder "figures". The different types of moves (move, capture, castle, en passant) are also modeled by different classes, which all derive from the base class "Move". They are gathered in the folder "moves". The class "MoveController" calculates all the pseudo-legal moves for a figure. Pseudo-legal moves are moves, which would be legal, if there was no restriction to keeping the king out of check. The class "CheckController" determines, whether a move is really valid by calculating, if the king would be in check after the move was played. The class "Player" holds references to all its figures and also stores information about the player like colour and time left. The class "ChessField" holds the information, which player has the turn. Its also needed to repaint the chess board. <br>
* gui: The class "Gui" is responsible for communicating with the users. It calls the repaint method and prints various menus like the start menu and the settings menu. It can also clear the console. <br>
* helper: The class "Converter" is needed to convert alphabetic inputs ("A2") into numbers ("12"). The class "Settings" saves all the decisions made in the settings menu. The class "ImportExport" is needed to import and export chess games. <br>

## License
The project is licensed under the General Public License V3.