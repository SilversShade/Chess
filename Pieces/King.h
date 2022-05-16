#pragma once
#include "Piece.h"

class King : public Piece{
private:
    bool isSafeAt(int, int, std::vector<Piece*> &pieces);
    bool isSafeFromPawn(int, int, std::vector<Piece*> &pieces);
    bool isSafeFromKnight(int, int, std::vector<Piece*> &pieces);
    bool isSafeFromRook(int, int, std::vector<Piece*> &pieces);
    bool isSafeFromBishop(int, int, std::vector<Piece*> &pieces);
    bool isSafeFromKing(int, int, std::vector<Piece*> &pieces);
    bool isSafeFromQueen(int, int, std::vector<Piece*> &pieces);
public:
    King(PieceColor, int, int);
    bool isMoveValid(int xEnd, int yEnd, std::vector<Piece*> &pieces) override;
};
