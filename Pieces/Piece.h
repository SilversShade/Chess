#pragma once
#include <SFML/Graphics.hpp>

class Piece {
private:
    int x;
    int y;
    sf::Texture texture;
    sf::Sprite sprite;
public:
    std::pair<int, int> getPosition(); // common method
    virtual void move(int, int) = 0; // will be overridden by each type of pieces

};