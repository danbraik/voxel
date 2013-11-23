#include <iostream>
#include <SFML/Graphics.hpp>
#include "Renderer.hpp"
#include "Chunk.hpp"
#include "Freeflycamera.h"
#include "ChunkManager.hpp"

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
	
	ChunkManager manager(list, renderer);
	manager.init();
	
	
//	Chunk chunk;
//	chunk.init(4);
//	chunk.update(renderer, manager);

	FreeFlyCamera camera(Vector3D(12,-12,12));
	
	//avoid event when move cursor
	bool mouseMoved = true;
	sf::Mouse::setPosition(sf::Vector2i(400,600), window);
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
				} else if (event.key.code == sf::Keyboard::LShift) {
					camera.OnKeyboard(FreeFlyCamera::boost, true);
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
                } else if (event.key.code == sf::Keyboard::U) {
					const Vector3D & tpos = camera.getTargetPosition();
					sf::Vector3i bpos( tpos.X / Block::SIZE,
									   tpos.Y / Block::SIZE,
									   tpos.Z / Block::SIZE);
					//std::cout << tpos.X << " " << tpos.Y<<" "<<tpos.Z<<endl;
					//cout << bpos.x <<" "<<bpos.y<<" "<<bpos.z<<endl;
					manager.deleteChunk(bpos);
                } else if (event.key.code == sf::Keyboard::I) {
					manager.reinit();
                } else if (event.key.code == sf::Keyboard::LShift) {
					camera.OnKeyboard(FreeFlyCamera::boost, false);
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
				if (event.mouseButton.button == sf::Mouse::Left) {
					
					const Vector3D & tpos = camera.getTargetPosition();
					sf::Vector3i bpos( tpos.X / Block::SIZE,
									   tpos.Y / Block::SIZE,
									   tpos.Z / Block::SIZE);
					std::cout << tpos.X << " " << tpos.Y<<" "<<tpos.Z<<endl;
					cout << bpos.x <<" "<<bpos.y<<" "<<bpos.z<<endl;
					manager.setBlockType(bpos, Block::Dirt);
				} else if (event.mouseButton.button == sf::Mouse::Right) {
					
					const Vector3D & tpos = camera.getTargetPosition();
					sf::Vector3i bpos( tpos.X / Block::SIZE,
									   tpos.Y / Block::SIZE,
									   tpos.Z / Block::SIZE);
					std::cout << tpos.X << " " << tpos.Y<<" "<<tpos.Z<<endl;
					cout << bpos.x <<" "<<bpos.y<<" "<<bpos.z<<endl;
					manager.setBlockType(bpos, Block::Air);
				} 
						
            }
        }
		const Vector3D & tpos = camera.getPosition();
		sf::Vector3i bpos( tpos.X / Chunk::SIZE,
						   tpos.Y / Chunk::SIZE,
						   tpos.Z / Chunk::SIZE);
		manager.visible(bpos);
		
		manager.update();
		
		camera.animate(10);
		
		
		
        renderer.clear();
		camera.look();
		
		glBegin(GL_LINES);
			glVertex3f(0,0,0);glVertex3f(1,0,0);
			glVertex3f(0,0,0);glVertex3f(0,1,0);
			glVertex3f(0,0,0);glVertex3f(0,0,1);
		glEnd();
		
//		chunk.draw(renderer);
//		for(int i=0;i<10;++i){
//			renderer.translate(-Chunk::SIZE*Block::SIZE,0,0);
//			chunk.draw(renderer);
//		}
		
		manager.draw(renderer);
		
		
		
        window.display();
		
    }

    return 0;
}

