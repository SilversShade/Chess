#pragma once
#include "../Pieces/Piece.h"
#include <vector>

class Field {
private:
    sf::RenderWindow window;
    static inline int field[8][8] = {
      -1,-2,-3,-4,-5,-3,-2,-1,
      -6,-6,-6,-6,-6,-6,-6,-6,
       0, 0, 0, 0, 0, 0, 0, 0,
       0, 0, 0, 0, 0, 0, 0, 0,
       0, 0, 0, 0, 0, 0, 0, 0,
       0, 0, 0, 0, 0, 0, 0, 0,
       6, 6, 6, 6, 6, 6, 6, 6,
       1, 2, 3, 4, 5, 3, 2, 1
    };
    std::vector<Piece> pieces;
    static void destroyPieceAt(int, int);
public:
    Field();
};