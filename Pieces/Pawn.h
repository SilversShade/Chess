#pragma once
#include "Piece.h"

class Pawn : public Piece {
private:
    bool atStartingPos;
public:
    Pawn(PieceColor, int, int);
    bool isMoveValid(int xEnd, int yEnd, std::vector<Piece*> &pieces) override;
};