cmake_minimum_required(VERSION 3.20)
project(Chess)

set(CMAKE_CXX_STANDARD 23)

add_executable(Chess main.cpp Pieces/Piece.cpp Pieces/Piece.h Field/Field.cpp Field/Field.h Pieces/King.cpp Pieces/King.h Pieces/Queen.cpp Pieces/Queen.h Pieces/Bishop.cpp Pieces/Bishop.h Pieces/Knight.cpp Pieces/Knight.h Pieces/Rook.cpp Pieces/Rook.h Pieces/Pawn.cpp Pieces/Pawn.h)

set(SFML_DIR "C:\\Users\\user\\CLionProjects\\lib\\sfml\\GCC 7.3.0 MinGW (SEH) - 64-bit\\SFML-2.5.1\\lib\\cmake\\SFML")

target_link_libraries(Chess sfml-graphics)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML 2.5 REQUIRED graphics network audio window system)