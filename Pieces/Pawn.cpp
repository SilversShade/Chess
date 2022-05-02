#include "Pawn.h"

Pawn::Pawn(PieceColor color, int x, int y) {
    this->color = color;
    color==PieceColor::WHITE
        ? this->texture->loadFromFile("../Resources/white_pawn.png")
        : this->texture->loadFromFile("../Resources/black_pawn.png");
    this->sprite.setTexture(*this->texture);
    this->xPos = x;
    this->yPos = y;
}