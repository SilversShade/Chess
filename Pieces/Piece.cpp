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

bool* Piece::isAlive() {
    return &this->alive;
}

PieceType Piece::getType() {
    return this->type;
}

PieceColor Piece::getColor() {
    return this->color;
}

int *Piece::getPosX() {
    return &this->xPos;
}

int *Piece::getPosY() {
    return &this->yPos;
}

void Piece::setPosX(int newXPos) {
    this->xPos = newXPos;
}

void Piece::setPosY(int newYPos) {
    this->yPos = newYPos;
}

void Piece::setIsAlive(bool isAlive) {
    this->alive = isAlive;
}

bool Piece::isMoveValid(int, int) {
    return false;
}