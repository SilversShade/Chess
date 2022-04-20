#include "Field.h"
using namespace sf;


void Field::destroyPieceAt(int x, int y) {

}

Field::Field() {
    RenderWindow window(VideoMode(800, 800), "Chess", Style::Close);
    while (window.isOpen()) {

        Event event{};
        while(window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }
        window.clear();
        window.display();
    }
}