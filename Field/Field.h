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
    sf::Vector2i mousePos;
    sf::Texture boardTexture;
    sf::Sprite boardSprite;
    sf::Texture pawnWhite, pawnBlack;
    sf::Texture bishopWhite, bishopBlack;
    sf::Texture kingWhite, kingBlack;
    sf::Texture knightWhite, knightBlack;
    sf::Texture queenWhite, queenBlack;
    sf::Texture rookWhite, rookBlack;

    PieceColor turn = PieceColor::WHITE;
    static inline const int offsetX = 72;
    static inline const int offsetY = 68;
    float posX = 0, posY = 0;
    float initialPosX = 0, initialPosY = 0;
    int xEnd = 0, yEnd = 0;
    bool isPieceMoving = false;
    int chosenPieceNumber = -1;

    std::vector<Piece*> pieces;
    //methods:
    void arrangePiecesOnBoard();
    void loadTextures();
    void leftMouseButtonPressed();
    void leftMouseButtonReleased();
    void changeTurn();
    void checkAndDestroy();
    void adjustPlacement();
    bool checkOutOfBorders() const;
    void checkForWinner();
    friend float placeWithOffset(int, char);
public:
    Field();
    ~Field();
};