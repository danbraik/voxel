#include <iostream>
#include <SFML/Graphics.hpp>
#include "Renderer.hpp"
#include "Chunk.hpp"
#include "Freeflycamera.h"

using namespace std;

int main(int argc, char ** argv) {

    cout << "Voxel " << __DATE__ << " à " << __TIME__ << endl;

	

    sf::RenderWindow window(
                sf::VideoMode(800, 600), "Title", sf::Style::Default,
				sf::ContextSettings(24));

    window.setVerticalSyncEnabled(true);
    // /* or */window.setFramerateLimit(60);

	Renderer renderer;
	
	
	
	BlockList list;
	
	Chunk chunk;
	chunk.init(4);
	
	chunk.update(renderer, list);

	FreeFlyCamera camera;
	
	//avoid event when move cursor
	bool mouseMoved =false;
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
				} else if (event.key.code == sf::Keyboard::Z) {
					camera.OnKeyboard(FreeFlyCamera::forward, true);
				} else if (event.key.code == sf::Keyboard::Q) {
					camera.OnKeyboard(FreeFlyCamera::strafe_left, true);
				} else if (event.key.code == sf::Keyboard::S) {
					camera.OnKeyboard(FreeFlyCamera::backward, true);
				} else if (event.key.code == sf::Keyboard::D) {
					camera.OnKeyboard(FreeFlyCamera::strafe_right, true);
				}
            }
            else if (event.type == sf::Event::KeyReleased) {
                if (event.key.code == sf::Keyboard::Up) {
                } else if (event.key.code == sf::Keyboard::Down) {
                } else if (event.key.code == sf::Keyboard::Left) {
                } else if (event.key.code == sf::Keyboard::Right) {
                } else if (event.key.code == sf::Keyboard::Z) {
					camera.OnKeyboard(FreeFlyCamera::forward, false);
				} else if (event.key.code == sf::Keyboard::Q) {
					camera.OnKeyboard(FreeFlyCamera::strafe_left, false);
				} else if (event.key.code == sf::Keyboard::S) {
					camera.OnKeyboard(FreeFlyCamera::backward, false);
				} else if (event.key.code == sf::Keyboard::D) {
					camera.OnKeyboard(FreeFlyCamera::strafe_right, false);
				}
            }
            else if (event.type == sf::Event::MouseMoved) {
                //event.mouseMove.x
                //event.mouseMove.y
				if (!mouseMoved){
					camera.OnMouseMotion(event.mouseMove.x-400, event.mouseMove.y-300);
					sf::Mouse::setPosition(sf::Vector2i(400,300), window);
				}
				mouseMoved=!mouseMoved;
            }
            else if (event.type == sf::Event::MouseWheelMoved) {
				camera.OnMouseButton(event.mouseWheel.delta > 0);	
            }
            else if (event.type == sf::Event::MouseButtonReleased) {
            }
        }

		camera.animate(10);
		
		
        renderer.clear();
		camera.look();
		
		chunk.draw(renderer);
		for(int i=0;i<10;++i){
			renderer.translate(-Chunk::SIZE*Block::SIZE,0,0);
			chunk.draw(renderer);
		}
		
		
		
        window.display();
		
    }

    return 0;
}

