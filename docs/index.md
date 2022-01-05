# YetAnotherChessGame
It is a chess game for the command-line.

## License
The Project is licensed under the General Public License V3.

## Build the Game

### Requirements
You need an active installation of the c++-Compiler gcc and make.

### Call Make to build the game
Call Make with the option -f to add the makefile in the root of the project as param and use .PHONY as target.<br> E.g. make -f [makefile] .PHONY

### Arguments
verbose=1 Enables the verbose-mode<br>
target_file=[file.exe] Path to the output of the build-process in this case file.exe. 
If not set, the File is called YetAnotherChessGame.exe and is in the project root.
