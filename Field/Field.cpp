#include "Field.h"
#include "../Pieces/Pawn.h"
#include "../Pieces/Rook.h"
#include "../Pieces/Knight.h"
#include "../Pieces/Bishop.h"
#include "../Pieces/King.h"
#include "../Pieces/Queen.h"
#include <iostream>
#include <cmath>
using namespace sf;

float placeWithOffset(int pieceOffset, char axis) {
    float offset;
    axis == 'x' ? offset = Field::offsetX : offset = Field::offsetY;
    return offset + static_cast<float>(Piece::pieceSize) * static_cast<float>(pieceOffset);
}

void Field::arrangePiecesOnBoard() {
    this->pieces.clear();
    float startDrawingPosX = Field::offsetX;
    int piecePosX=0, piecePosY=1;
    for (int i=0;i<8;i++) {
        this->pieces.push_back(new Pawn(PieceColor::BLACK, piecePosX, piecePosY));
        this->pieces.back()->getSprite()->setPosition(startDrawingPosX, Field::offsetY+Piece::pieceSize);
        this->pieces.back()->getSprite()->setTexture(this->pawnBlack);
        this->pieces.push_back(new Pawn(PieceColor::WHITE, piecePosX, piecePosY+5));
        this->pieces.back()->getSprite()->setPosition(startDrawingPosX, placeWithOffset(5, 'y')+Piece::pieceSize);
        this->pieces.back()->getSprite()->setTexture(this->pawnWhite);
        piecePosX++;
        startDrawingPosX+=Piece::pieceSize;
    }
    std::vector<std::pair<int, int> > coordinates = {{0,0}, {0,7}, {7,0},{7,7}};
    for (const auto &i:coordinates) {
        this->pieces.push_back(new Rook(i.first == 0 ? PieceColor::BLACK : PieceColor::WHITE, i.second, i.first));
        this->pieces.back()->getSprite()->setPosition(placeWithOffset(i.second, 'x'), placeWithOffset(i.first, 'y'));
        this->pieces.back()->getSprite()->setTexture(i.first == 0 ? this->rookBlack : this->rookWhite);
    }
    coordinates = {{0,1}, {0,6}, {7,1}, {7,6}};
    for (const auto &i:coordinates) {
        this->pieces.push_back(new Knight(i.first == 0 ? PieceColor::BLACK : PieceColor::WHITE, i.second, i.first));
        this->pieces.back()->getSprite()->setPosition(placeWithOffset(i.second, 'x'), placeWithOffset(i.first, 'y'));
        this->pieces.back()->getSprite()->setTexture(i.first == 0 ? this->knightBlack : this->knightWhite);
    }
    coordinates = {{0,2}, {0,5}, {7,2},{7,5}};
    for (const auto &i:coordinates) {
        this->pieces.push_back(new Bishop(i.first == 0 ? PieceColor::BLACK : PieceColor::WHITE, i.second, i.first));
        this->pieces.back()->getSprite()->setPosition(placeWithOffset(i.second, 'x'), placeWithOffset(i.first, 'y'));
        this->pieces.back()->getSprite()->setTexture(i.first == 0 ? this->bishopBlack : this->bishopWhite);
    }
    coordinates = {{0,4}, {7,4}};
    for (const auto &i:coordinates) {
        this->pieces.push_back(new King(i.first == 0 ? PieceColor::BLACK : PieceColor::WHITE, i.second, i.first));
        this->pieces.back()->getSprite()->setPosition(placeWithOffset(i.second, 'x'), placeWithOffset(i.first, 'y'));
        this->pieces.back()->getSprite()->setTexture(i.first == 0 ? this->kingBlack : this->kingWhite);
    }
    coordinates = {{0,3}, {7,3}};
    for (const auto &i:coordinates) {
        this->pieces.push_back(new Queen(i.first == 0 ? PieceColor::BLACK : PieceColor::WHITE, i.second, i.first));
        this->pieces.back()->getSprite()->setPosition(placeWithOffset(i.second, 'x'), placeWithOffset(i.first, 'y'));
        this->pieces.back()->getSprite()->setTexture(i.first == 0 ? this->queenBlack : this->queenWhite);
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

void Field::changeTurn() {
    if (this->pieces[this->chosenPieceNumber]->getPosX() == this->xEnd && this->pieces[this->chosenPieceNumber]->getPosY() == this->yEnd)
        return;
    this->turn == PieceColor::WHITE ? this->turn = PieceColor::BLACK : this->turn = PieceColor::WHITE;
}

void Field::leftMouseButtonPressed() {
    if (this->event.type == Event::MouseButtonPressed && this->event.mouseButton.button == Mouse::Left) {
        for (int i=0;i<32;i++) {
            if (this->pieces[i]->getSprite()->getGlobalBounds().contains(static_cast<float>(this->mousePos.x), static_cast<float>(this->mousePos.y)) && pieces[i]->getColor() == this->turn) {
                this->chosenPieceNumber = i;
                this->initialPosX = this->pieces[i]->getSprite()->getPosition().x;
                this->initialPosY = this->pieces[i]->getSprite()->getPosition().y;
                this->posX = static_cast<float>(this->mousePos.x) - pieces[i]->getSprite()->getPosition().x;
                this->posY = static_cast<float>(this->mousePos.y) - pieces[i]->getSprite()->getPosition().y;
                this->isPieceMoving = true;
            }
        }
    }
}

void Field::checkAndDestroy() {
    for (int i=0;i<32;i++)
        if (this->pieces[i]->getPosX() == this->xEnd && this->pieces[i]->getPosY() == this->yEnd && i != this->chosenPieceNumber) {
            this->pieces[i]->getSprite()->setPosition(-100, -100);
            this->pieces[i]->setPosX(-1);
            this->pieces[i]->setPosY(-1);
        }
}

void Field::adjustPlacement() {
        Vector2f p = this->pieces[this->chosenPieceNumber]->getSprite()->getPosition() + Vector2f(static_cast<float>(Piece::pieceSize)/2, static_cast<float>(Piece::pieceSize)/2);
        this->pieces[this->chosenPieceNumber]->getSprite()->setPosition(
                Vector2f((static_cast<float>((Piece::pieceSize)*(static_cast<int>(p.x-Field::offsetX)/Piece::pieceSize) + Field::offsetX)),
                         (static_cast<float>((Piece::pieceSize)*(static_cast<int>(p.y-Field::offsetY)/Piece::pieceSize) + Field::offsetY))));
}

bool Field::checkOutOfBorders() const{
    return this->xEnd>7 || this->xEnd<0 || this->yEnd>7 || this->yEnd<0;
}

void Field::leftMouseButtonReleased() {
    if (this->event.type == Event::MouseButtonReleased && this->event.mouseButton.button == Mouse::Left && this->isPieceMoving) {
        this->isPieceMoving = false;
        adjustPlacement();
        this->xEnd = static_cast<int>(std::round((this->pieces[this->chosenPieceNumber]->getSprite()->getPosition().x - Field::offsetX)/Piece::pieceSize));
        this->yEnd = static_cast<int>(std::round((this->pieces[this->chosenPieceNumber]->getSprite()->getPosition().y - Field::offsetY)/Piece::pieceSize));

        //std::cout << this->xEnd << " " << this->yEnd << "\n";
        if (!this->pieces[this->chosenPieceNumber]->isMoveValid(this->xEnd, this->yEnd, this->pieces) || checkOutOfBorders()) {
            this->pieces[this->chosenPieceNumber]->getSprite()->setPosition(this->initialPosX, this->initialPosY);
            return;
        }
        changeTurn();
        checkAndDestroy();
        this->pieces[this->chosenPieceNumber]->setPosX(this->xEnd);
        this->pieces[this->chosenPieceNumber]->setPosY(this->yEnd);
    }
}

Field::Field() {
    this->window.create(VideoMode(1000,1000), "Chess", Style::Close);
    this->window.setPosition(Vector2i(450,0));

    loadTextures();
    arrangePiecesOnBoard();

    while (this->window.isOpen()) {

        this->mousePos = Mouse::getPosition(this->window);

        while(this->window.pollEvent(this->event)) {
            if (this->event.type == Event::Closed)
                this->window.close();
            leftMouseButtonPressed();
            leftMouseButtonReleased();
        }

        if (this->isPieceMoving)
            this->pieces[this->chosenPieceNumber]->getSprite()->setPosition(static_cast<float>(this->mousePos.x) - this->posX, static_cast<float>(this->mousePos.y) - this->posY);
        this->window.clear();
        this->window.draw(this->boardSprite);
        for (auto piece:this->pieces)
            this->window.draw(*piece->getSprite());
        this->window.display();
    }
}

Field::~Field() {
    for (int i=0;i<32;i++)
        delete this->pieces[i];
}
