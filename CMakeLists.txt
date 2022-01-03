cmake_minimum_required(VERSION 3.21)
project(YetAnotherChessGame)

set(CMAKE_CXX_STANDARD 14)

include_directories(gui)
include_directories(model)
include_directories(model/figures)

add_executable(YetAnotherChessGame
        gui/resources.hpp
        model/figures/Bishop.cpp
        model/figures/Bishop.hpp
        model/figures/King.cpp
        model/figures/King.hpp
        model/figures/Knight.cpp
        model/figures/Knight.hpp
        model/figures/Pawn.cpp
        model/figures/Pawn.hpp
        model/figures/Queen.cpp
        model/figures/Queen.hpp
        model/figures/Rook.cpp
        model/figures/Rook.hpp
        model/moves/Capture.cpp
        model/moves/Capture.hpp
        model/moves/Castle.cpp
        model/moves/Capture.hpp
        model/moves/Move.cpp
        model/moves/Move.hpp
        model/ChessField.cpp
        model/ChessField.hpp
        model/Figure.cpp
        model/Figure.hpp
        model/MoveController.cpp
        model/MoveController.hpp
        model/Player.cpp
        model/Player.hpp
        main.cpp)
