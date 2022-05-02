#include "Field.h"
#include "../Pieces/Pawn.h"
#include <iostream>
using namespace sf;

void Field::arrangePiecesOnBoard() {
    float startDrawingPosX = 72.0f, startDrawingPosY = 177.0f;
    int piecePosX=1, piecePosY=0;
    for (int i=0;i<8;i++) {
        Pawn newPawn(PieceColor::BLACK, piecePosX, piecePosY);
        newPawn.getSprite().setPosition(startDrawingPosX, startDrawingPosY);
        this->pieces.push_back(newPawn);
        piecePosY++;
        startDrawingPosX+=105.0f;
    }
}

Field::Field() {
    this->window.create(VideoMode(1000,1000), "Chess", Style::Close);

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
            window.draw(piece.getSprite());
        window.display();
    }
}