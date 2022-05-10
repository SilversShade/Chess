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
    sf::Sprite sprite;
    Piece(PieceColor, int, int);
public:
    //getters:
    sf::Sprite* getSprite();
    PieceType getType();
    PieceColor getColor();
    int getPosX() const;
    int getPosY() const;

    //setters:
    void setPosX(int);
    void setPosY(int);

    static inline const int pieceSize = 108; //define general proper piece size
    virtual bool isMoveValid(int, int); // will be overridden by each type of pieces
};