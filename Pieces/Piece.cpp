#include "Piece.h"

Piece::Piece(PieceColor color, int x, int y) {
    this->type = PieceType::NULLTYPE;
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

bool Piece::isMoveValid(int, int) {
    return false;
}