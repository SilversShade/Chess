#include "King.h"

King::King(PieceColor color, int x, int y) : Piece(color, x, y){
    auto* texture = new sf::Texture();
    color==PieceColor::WHITE
        ? texture->loadFromFile("../Resources/white_king.png")
        : texture->loadFromFile("../Resources/black_king.png");
    this->sprite.setTexture(*texture);
    this->type = PieceType::KING;
}
