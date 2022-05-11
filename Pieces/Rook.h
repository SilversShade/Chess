#pragma once
#include "Piece.h"

class Rook : public Piece{
public:
    Rook(PieceColor, int, int);
    bool isMoveValid(int xEnd, int yEnd, std::vector<Piece*> &pieces) override;
};
