#pragma once
#include <SFML/Graphics.hpp>

enum class PieceColor {
    BLACK,
    WHITE
};

class Piece {
protected:
    PieceColor color;
    int xPos;
    int yPos;
    bool isAlive = true;
    sf::Texture* texture;
    sf::Sprite sprite;
public:
    sf::Sprite getSprite();
    static inline const int pieceSizePx = 105; //define general proper piece size
    std::pair<int, int> getPosition(); // common method
    //virtual void move(int, int) = 0; // will be overridden by each type of pieces
};