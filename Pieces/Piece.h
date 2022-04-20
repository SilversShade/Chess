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
    sf::Texture texture;
    sf::Sprite sprite;
public:
    static inline const int pieceSizePx = -1; //define general proper piece size
    std::pair<int, int> getPosition(); // common method
    virtual void move(int, int) = 0; // will be overridden by each type of pieces
};