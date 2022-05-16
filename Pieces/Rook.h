#pragma once
#include "Piece.h"

class Rook : public Piece{
private:
    bool moved = false;
public:
    Rook(PieceColor, int, int);
    bool isMoveValid(int xEnd, int yEnd, std::vector<Piece*> &pieces) override;
    bool hasMoved() const;
};
