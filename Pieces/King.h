#pragma once
#include "Piece.h"

class King : public Piece{
public:
    King(PieceColor, int, int);
    bool isMoveValid(int xEnd, int yEnd) override;
};
