#include "Field.h"
#include "../Pieces/Pawn.h"
#include <iostream>
using namespace sf;

void Field::arrangePiecesOnBoard() {
    float startDrawingPosX = 70.0f, startDrawingPosY = 177.0f;
    int piecePosX=1, piecePosY=0;
    for (int i=0;i<8;i++) {
        this->pieces.push_back(Pawn(PieceColor::BLACK, piecePosX, piecePosY));
        this->pieces.back().getSprite()->setPosition(startDrawingPosX, startDrawingPosY);
        this->pieces.push_back(Pawn(PieceColor::WHITE, piecePosX+6, piecePosY));
        this->pieces.back().getSprite()->setPosition(startDrawingPosX, startDrawingPosY+(Piece::pieceSizePx*5));
        piecePosY++;
        startDrawingPosX+=Piece::pieceSizePx;
    }
}

Field::Field() {
    this->window.create(VideoMode(1000,1000), "Chess", Style::Close);
    this->window.setPosition(Vector2i(450,0));

    this->boardTexture.loadFromFile("../Resources/board.png");
    this->boardSprite.setTexture(boardTexture);

    arrangePiecesOnBoard();

    while (window.isOpen()) {

        while(window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(boardSprite);
        for (auto piece:this->pieces)
            window.draw(*piece.getSprite());
        window.display();
    }
}