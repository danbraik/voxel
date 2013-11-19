#include <iostream>
#include <SFML/Graphics.hpp>
#include "Renderer.hpp"
#include "Chunk.hpp"

using namespace std;

int main(int argc, char ** argv) {

    cout << "Voxel " << __DATE__ << " à " << __TIME__ << endl;

	

    sf::RenderWindow window(
                sf::VideoMode(800, 600), "Title", sf::Style::Default);

    window.setVerticalSyncEnabled(true);
    // /* or */window.setFramerateLimit(60);

	Renderer renderer;
	renderer.lookAt(5,-5,5,0,0,0);
	float rot=0;
	
	Chunk chunk;
	chunk.update(renderer);

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

        renderer.clear();
		
		renderer.translate(rot,0,0);
		chunk.draw(renderer);
		for(int i=0;i<10;++i){
			renderer.translate(-Chunk::SIZE*BLOCK_SIZE,0,0);
			chunk.draw(renderer);
		}
		
        window.display();
		
		rot+=0.01;
    }

    return 0;
}

