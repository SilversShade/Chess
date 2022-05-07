#pragma once
#include "../Pieces/Piece.h"
#include <vector>

/**
 * this class is designed to be graphic-only.
 * All the logic must be implemented through Piece class in ../Pieces folder
 */

class Field {
private:
    //SFML fields:
    sf::RenderWindow window;
    sf::Event event{};
    sf::Vector2f mousePos;
    sf::Texture boardTexture;
    sf::Sprite boardSprite;
    sf::Texture pawnWhite, pawnBlack;
    sf::Texture bishopWhite, bishopBlack;
    sf::Texture kingWhite, kingBlack;
    sf::Texture knightWhite, knightBlack;
    sf::Texture queenWhite, queenBlack;
    sf::Texture rookWhite, rookBlack;

    PieceColor turn = PieceColor::WHITE;
    static inline const float offset = 70.0f;
    //static inline const int field[8][8] = {
    //  -1,-2,-3,-4,-5,-3,-2,-1,
    //  -6,-6,-6,-6,-6,-6,-6,-6,
    //   0, 0, 0, 0, 0, 0, 0, 0,
    //   0, 0, 0, 0, 0, 0, 0, 0,
    //   0, 0, 0, 0, 0, 0, 0, 0,
    //   0, 0, 0, 0, 0, 0, 0, 0,
    //   6, 6, 6, 6, 6, 6, 6, 6,
    //   1, 2, 3, 4, 5, 3, 2, 1
    //};
    std::vector<Piece> pieces;
    //methods:
    void arrangePiecesOnBoard();
    void loadTextures();
    friend float placeWithOffset(int pieceOffset);
public:
    Field();
};