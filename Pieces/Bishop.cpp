#include "Bishop.h"

Bishop::Bishop(PieceColor color, int x, int y) : Piece(color, x, y) {
    auto* texture = new sf::Texture();
    color==PieceColor::WHITE
        ? texture->loadFromFile("../Resources/white_bishop.png")
        : texture->loadFromFile("../Resources/black_bishop.png");
    this->sprite.setTexture(*texture);
    this->type = PieceType::BISHOP;
}