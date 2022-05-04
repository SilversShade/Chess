#include "Queen.h"

Queen::Queen(PieceColor color, int x, int y) : Piece(color, x, y){
    auto* texture = new sf::Texture();
    color==PieceColor::WHITE
        ? texture->loadFromFile("../Resources/white_queen.png")
        : texture->loadFromFile("../Resources/black_queen.png");
    this->sprite.setTexture(*texture);
    this->type = PieceType::QUEEN;
}
