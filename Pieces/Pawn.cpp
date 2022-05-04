#include "Pawn.h"

Pawn::Pawn(PieceColor color, int x, int y): Piece(color, x, y) {
    auto* texture = new sf::Texture();
    color==PieceColor::WHITE
        ? texture->loadFromFile("../Resources/white_pawn.png")
        : texture->loadFromFile("../Resources/black_pawn.png");
    this->sprite.setTexture(*texture);
    this->type = PieceType::PAWN;
}