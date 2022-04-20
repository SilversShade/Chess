#include "Field.h"
using namespace sf;

void Field::arrangePiecesOnBoard() {

}

void Field::loadTextures() {
    this->boardTexture.loadFromFile("../Resources/board_to_resize.jpg");
    this->boardSprite.setTexture(boardTexture);
}

Field::Field() {
    this->window.create(VideoMode(800,800), "Chess", Style::Close);

    loadTextures();

    while (window.isOpen()) {

        while(window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(boardSprite);
        window.display();
    }
}