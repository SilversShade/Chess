#include "Knight.h"

Knight::Knight(PieceColor color, int x, int y) : Piece(color, x, y){
    auto* texture = new sf::Texture();
    color==PieceColor::WHITE
        ? texture->loadFromFile("../Resources/white_knight.png")
        : texture->loadFromFile("../Resources/black_knight.png");
    this->sprite.setTexture(*texture);
}
