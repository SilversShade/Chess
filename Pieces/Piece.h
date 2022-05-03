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
    sf::Sprite sprite;
    Piece(PieceColor, int, int);
public:
    sf::Sprite* getSprite();
    static inline const int pieceSizePx = 108; //define general proper piece size
    std::pair<int, int> getPosition(); // common method
    //virtual void move(int, int) = 0; // will be overridden by each type of pieces
};