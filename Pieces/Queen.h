#pragma once
#include "Piece.h"

class Queen : public Piece{
public:
    Queen(PieceColor, int, int);
    bool isMoveValid(int xEnd, int yEnd, std::vector<Piece*> &pieces) override;
};