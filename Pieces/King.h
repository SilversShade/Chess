#pragma once
#include "Piece.h"

class King : public Piece{
private:
    bool isSafeAt(int, int, std::vector<Piece*> &pieces);
    bool moved = false;
public:
    King(PieceColor, int, int);
    bool isMoveValid(int xEnd, int yEnd, std::vector<Piece*> &pieces) override;
    bool hasMoved() const;
};
