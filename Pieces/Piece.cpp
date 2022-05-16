#include "Piece.h"

Piece::Piece(PieceColor color, int x, int y) {
    this->type = PieceType::EMPTY;
    this->color = color;
    this->xPos = x;
    this->yPos = y;
}

sf::Sprite* Piece::getSprite() {
    return &this->sprite;
}

PieceType Piece::getType() {
    return this->type;
}

PieceColor Piece::getColor() {
    return this->color;
}

int Piece::getPosX() const{
    return this->xPos;
}

int Piece::getPosY() const{
    return this->yPos;
}

void Piece::setPosX(int newXPos) {
    this->xPos = newXPos;
}

void Piece::setPosY(int newYPos) {
    this->yPos = newYPos;
}

bool Piece::isMoveValid(int, int, std::vector<Piece*> &pieces) {
    return false;
}

bool Piece::isCellFreeAt(int x, int y, std::vector<Piece*> &pieces) {
    return std::all_of(pieces.begin(), pieces.end(), [x, y](Piece* piece) {
        return piece->getPosX() != x || piece->getPosY() != y;
    });
}

PieceColor Piece::checkColorAt(int x, int y, std::vector<Piece *> &pieces) {
    for (const auto& piece:pieces)
        if (piece->getPosX() == x && piece->getPosY() == y)
            return piece->getColor();
    return PieceColor::EMPTY;
}

PieceType Piece::checkTypeAt(int x, int y, std::vector<Piece *> &pieces) {
    for (const auto& piece:pieces)
        if (piece->getPosX() == x && piece->getPosY() == y)
            return piece->getType();
    return PieceType::EMPTY;
}
