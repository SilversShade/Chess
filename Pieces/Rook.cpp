#include "Rook.h"

Rook::Rook(PieceColor color, int x, int y) : Piece(color, x, y){
    auto* texture = new sf::Texture();
    color==PieceColor::WHITE
        ? texture->loadFromFile("../Resources/white_rook.png")
        : texture->loadFromFile("../Resources/black_rook.png");
    this->sprite.setTexture(*texture);
}
