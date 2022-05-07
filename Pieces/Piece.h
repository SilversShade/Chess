#pragma once
#include <SFML/Graphics.hpp>

enum class PieceColor {
    BLACK,
    WHITE
};

enum class PieceType {
    NULLTYPE,
    PAWN,
    KING,
    QUEEN,
    BISHOP,
    KNIGHT,
    ROOK
};

class Piece {
protected:
    PieceType type;
    PieceColor color;
    int xPos;
    int yPos;
    bool alive = true;
    sf::Sprite sprite;
    Piece(PieceColor, int, int);
public:
    //getters:
    sf::Sprite* getSprite();
    PieceType* getType();
    PieceColor* getColor();
    int* getPosX();
    int* getPosY();
    bool* isAlive();

    //setters:
    void setPosX(int);
    void setPosY(int);
    void setIsAlive(bool);

    static inline const int pieceSizePx = 108; //define general proper piece size
    //virtual void move(int, int) = 0; // will be overridden by each type of pieces
};