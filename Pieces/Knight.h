#pragma once
#include "Piece.h"

class Knight : public Piece {
public:
    Knight(PieceColor, int, int);
    bool isMoveValid(int xEnd, int yEnd) override;
};