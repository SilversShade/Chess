#include "Piece.h"

std::pair<int, int> Piece::getPosition() {
    return std::make_pair(this->xPos, this->yPos);
}

sf::Sprite* Piece::getSprite() {
    return &this->sprite;
}

Piece::Piece(PieceColor color, int x, int y) {
    this->color = color;
    this->xPos = x;
    this->yPos = y;
}

bool Piece::isAlive() {
    return this->alive;
}
