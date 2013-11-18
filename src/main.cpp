#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

int main(int argc, char ** argv) {

    cout << "Voxel " << __DATE__ << " à " << __TIME__ << endl;

	

    sf::RenderWindow window(
                sf::VideoMode(800, 600), "Title", sf::Style::Default, sf::ContextSettings(32));

    window.setVerticalSyncEnabled(true);
    // /* or */window.setFramerateLimit(60);


    // run the main loop
    bool running = true;
    while (running) {

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                running = false;
            }
            else if (event.type == sf::Event::Resized) {
            }
            else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape)
                    running = false;
                if (event.key.code == sf::Keyboard::Up) {
                } else if (event.key.code == sf::Keyboard::Down) {
                } else if (event.key.code == sf::Keyboard::Left) {
                } else if (event.key.code == sf::Keyboard::Right) {
                }
            }
            else if (event.type == sf::Event::KeyReleased) {
                if (event.key.code == sf::Keyboard::Up) {
                } else if (event.key.code == sf::Keyboard::Down) {
                } else if (event.key.code == sf::Keyboard::Left) {
                } else if (event.key.code == sf::Keyboard::Right) {
                }
            }
            else if (event.type == sf::Event::MouseMoved) {
                //event.mouseMove.x
                //event.mouseMove.y
            }
            else if (event.type == sf::Event::MouseButtonPressed) {
                //event.mouseButton.button == sf::Mouse::Left
            }
            else if (event.type == sf::Event::MouseButtonReleased) {
            }
        }

        window.clear();
        //window.draw();
        window.display();
    }

    return 0;
}

