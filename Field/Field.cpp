#include "Field.h"
#include "../Pieces/Pawn.h"
#include "../Pieces/Rook.h"
#include "../Pieces/Knight.h"
#include "../Pieces/Bishop.h"
#include "../Pieces/King.h"
#include "../Pieces/Queen.h"
using namespace sf;

float placeWithOffset(int pieceOffset) {
    return Field::offset+static_cast<float>(Piece::pieceSizePx)*static_cast<float>(pieceOffset);
}

void Field::arrangePiecesOnBoard() {
    this->pieces.clear();
    float startDrawingPosX = Field::offset;
    int piecePosX=1, piecePosY=0;
    for (int i=0;i<8;i++) {
        this->pieces.push_back(Pawn(PieceColor::BLACK, piecePosX, piecePosY));
        this->pieces.back().getSprite()->setPosition(startDrawingPosX, Field::offset+107);
        this->pieces.back().getSprite()->setTexture(this->pawnBlack);
        this->pieces.push_back(Pawn(PieceColor::WHITE, piecePosX+5, piecePosY));
        this->pieces.back().getSprite()->setPosition(startDrawingPosX, placeWithOffset(5)+107);
        this->pieces.back().getSprite()->setTexture(this->pawnWhite);
        piecePosY++;
        startDrawingPosX+=Piece::pieceSizePx;
    }
    std::vector<std::pair<int, int> > coordinates = {{0,0}, {0,7}, {7,0},{7,7}};
    for (const auto &i:coordinates) {
        this->pieces.push_back(Rook(i.first == 0 ? PieceColor::BLACK : PieceColor::WHITE, i.first, i.second));
        this->pieces.back().getSprite()->setPosition(placeWithOffset(i.second), placeWithOffset(i.first));
        this->pieces.back().getSprite()->setTexture(i.first == 0 ? this->rookBlack : this->rookWhite);
    }
    coordinates = {{0,1}, {0,6}, {7,1}, {7,6}};
    for (const auto &i:coordinates) {
        this->pieces.push_back(Knight(i.first == 0 ? PieceColor::BLACK : PieceColor::WHITE, i.first, i.second));
        this->pieces.back().getSprite()->setPosition(placeWithOffset(i.second), placeWithOffset(i.first));
        this->pieces.back().getSprite()->setTexture(i.first == 0 ? this->knightBlack : this->knightWhite);
    }
    coordinates = {{0,2}, {0,5}, {7,2},{7,5}};
    for (const auto &i:coordinates) {
        this->pieces.push_back(Bishop(i.first == 0 ? PieceColor::BLACK : PieceColor::WHITE, i.first, i.second));
        this->pieces.back().getSprite()->setPosition(placeWithOffset(i.second), placeWithOffset(i.first));
        this->pieces.back().getSprite()->setTexture(i.first == 0 ? this->bishopBlack : this->bishopWhite);
    }
    coordinates = {{0,4}, {7,4}};
    for (const auto &i:coordinates) {
        this->pieces.push_back(King(i.first == 0 ? PieceColor::BLACK : PieceColor::WHITE, i.first, i.second));
        this->pieces.back().getSprite()->setPosition(placeWithOffset(i.second), placeWithOffset(i.first));
        this->pieces.back().getSprite()->setTexture(i.first == 0 ? this->kingBlack : this->kingWhite);
    }
    coordinates = {{0,3}, {7,3}};
    for (const auto &i:coordinates) {
        this->pieces.push_back(Queen(i.first == 0 ? PieceColor::BLACK : PieceColor::WHITE, i.first, i.second));
        this->pieces.back().getSprite()->setPosition(placeWithOffset(i.second), placeWithOffset(i.first));
        this->pieces.back().getSprite()->setTexture(i.first == 0 ? this->queenBlack : this->queenWhite);
    }
}

void Field::loadTextures() {
    this->boardTexture.loadFromFile("../Resources/board.png");
    this->boardSprite.setTexture(boardTexture);

    this->pawnWhite.loadFromFile("../Resources/white_pawn.png");
    this->pawnBlack.loadFromFile("../Resources/black_pawn.png");

    this->bishopWhite.loadFromFile("../Resources/white_bishop.png");
    this->bishopBlack.loadFromFile("../Resources/black_bishop.png");

    this->kingWhite.loadFromFile("../Resources/white_king.png");
    this->kingBlack.loadFromFile("../Resources/black_king.png");

    this->knightWhite.loadFromFile("../Resources/white_knight.png");
    this->knightBlack.loadFromFile("../Resources/black_knight.png");

    this->queenWhite.loadFromFile("../Resources/white_queen.png");
    this->queenBlack.loadFromFile("../Resources/black_queen.png");

    this->rookWhite.loadFromFile("../Resources/white_rook.png");
    this->rookBlack.loadFromFile("../Resources/black_rook.png");
}

Field::Field() {
    this->window.create(VideoMode(1000,1000), "Chess", Style::Close);
    this->window.setPosition(Vector2i(450,0));

    loadTextures();
    arrangePiecesOnBoard();

    while (window.isOpen()) {

        while(window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(boardSprite);
        for (auto piece:this->pieces)
            if (piece.isAlive())
                window.draw(*piece.getSprite());
        window.display();
    }
}