#include "Piece.h"

std::pair<int, int> Piece::getPosition() {
    return std::make_pair(this->xPos, this->yPos);
}

sf::Sprite Piece::getSprite() {
    return this->sprite;
}
