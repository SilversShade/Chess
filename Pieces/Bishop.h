#pragma once
#include "Piece.h"

class Bishop : public Piece{
public:
    Bishop(PieceColor, int, int);
    bool isMoveValid(int xEnd, int yEnd, std::vector<Piece*> &pieces) override;
};