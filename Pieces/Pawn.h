#pragma once
#include "Piece.h"

class Pawn : public Piece {
private:
    bool atStartingPos;
    bool enPassantCondition = false;
    bool enPassantConditionAt(int, int, std::vector<Piece*> &pieces);
public:
    Pawn(PieceColor, int, int);
    bool isMoveValid(int xEnd, int yEnd, std::vector<Piece*> &pieces) override;
    void setEnPassantCondition(bool);
};