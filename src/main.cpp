#include <iostream>
#include <SFML/Graphics.hpp>
#include "Renderer.hpp"
#include "Chunk.hpp"
#include "Freeflycamera.h"
#include "ChunkManager.hpp"
#include "WorldGenerator.hpp"
#include "ChunkPersistence.hpp"
#include "RaycastHelper.hpp"

using namespace std;



int main(int argc, char ** argv) {

    cout << "Voxel " << __DATE__ << " à " << __TIME__ << endl;


    sf::RenderWindow window(
                sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Title",
#if 1
				sf::Style::Default
#else
				sf::Style::Fullscreen
#endif
				,sf::ContextSettings(24));
	
    window.setVerticalSyncEnabled(true);
	//window.setFramerateLimit(10);

	Renderer renderer;
	renderer.screen(SCREEN_WIDTH, SCREEN_HEIGHT);
	
	ChunkPersistence persistence;
	persistence.setDirectory("/home/daniel/projects/c_cpp/voxel/world");
	
	BlockList list;
	
	ChunkManager manager(list, persistence);
	
	WorldGenerator worldGenerator(manager);
	worldGenerator.init();
	
	
	FreeFlyCamera camera(Vector3D(12,-12,12));
	
	RaycastHelper rh;
	
	int currentBlock = Block::Dirt;
	
	//avoid event when move cursor
	bool mouseMoved = true;
	sf::Mouse::setPosition(sf::Vector2i(SCREEN_WIDTH/2, SCREEN_HEIGHT/2), window);
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
				} else if (event.key.code == sf::Keyboard::Space) {
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)) {
						camera.OnKeyboard(FreeFlyCamera::down, true);
						camera.OnKeyboard(FreeFlyCamera::up, false);
					} else {
						camera.OnKeyboard(FreeFlyCamera::up, true);
						camera.OnKeyboard(FreeFlyCamera::down, false);
					}
				}
            }
            else if (event.type == sf::Event::KeyReleased) {
                if (event.key.code == sf::Keyboard::Up) {
                } else if (event.key.code == sf::Keyboard::L) {
					const Vector3D & tpos = camera.getPosition();
					BlockCoordinate bpos( tpos.X,tpos.Y,tpos.Z);
					worldGenerator.makeIsland(bpos);
					
                } else if (event.key.code == sf::Keyboard::U) {
					const Vector3D & tpos = camera.getTargetPosition();
					BlockCoordinate bpos( tpos.X, tpos.Y,tpos.Z);
					//std::cout << tpos.X << " " << tpos.Y<<" "<<tpos.Z<<endl;
					//cout << bpos.x <<" "<<bpos.y<<" "<<bpos.z<<endl;
					manager.deleteChunk(bpos);
                } else if (event.key.code == sf::Keyboard::I) {
					const Vector3D & tpos = camera.getTargetPosition();
					ChunkCoordinate bpos( tpos.X, tpos.Y,tpos.Z);
					manager.resetChunk(bpos);
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
				} else if (event.key.code == sf::Keyboard::Space) {
						camera.OnKeyboard(FreeFlyCamera::up, false);
						camera.OnKeyboard(FreeFlyCamera::down, false);
				}
				
				
            }
            else if (event.type == sf::Event::MouseMoved) {
                //event.mouseMove.x
                //event.mouseMove.y
				if (!mouseMoved){
					camera.OnMouseMotion(event.mouseMove.x-SCREEN_WIDTH/2,
										 event.mouseMove.y-SCREEN_HEIGHT/2);
					sf::Mouse::setPosition(sf::Vector2i(SCREEN_WIDTH/2,SCREEN_HEIGHT/2), window);
					
					
				}
				mouseMoved=!mouseMoved;
            }
            else if (event.type == sf::Event::MouseWheelMoved) {
//				if (event.mouseWheel.delta > 0) {
//					currentBlock++;
//				} else
//					currentBlock--;
            }
            else if (event.type == sf::Event::MouseButtonReleased) {
				if (event.mouseButton.button == sf::Mouse::Left) {
					
//					const Vector3D & tpos = camera.getTargetPosition();
//					sf::Vector3i bpos( tpos.X / Block::SIZE,
//									   tpos.Y / Block::SIZE,
//									   tpos.Z / Block::SIZE);
//					std::cout << tpos.X << " " << tpos.Y<<" "<<tpos.Z<<endl;
					//cout << bpos.x <<" "<<bpos.y<<" "<<bpos.z<<endl;
//					manager.setBlockType(bpos, Block::Dirt);
					
					
					const Vector3D & pos = camera.getPosition();
					const Vector3D & forw = camera.getForward();
					
					sf::Vector3i sel, next; 
					sf::Vector3f src(pos.X, pos.Y, pos.Z), dir(forw.X, forw.Y, forw.Z);
					
					if (rh.raycast(manager,src,dir,sel,next)) {
						cout << "Block (add) "<< sel.x <<" "<<sel.y<<" "<<sel.z<<endl;
						manager.setBlockType(sel+next, currentBlock);		
					}
					
					
				} else if (event.mouseButton.button == sf::Mouse::Right) {
					
//					const Vector3D & tpos = camera.getTargetPosition();
//					sf::Vector3i bpos( tpos.X / Block::SIZE,
//									   tpos.Y / Block::SIZE,
//									   tpos.Z / Block::SIZE);
					//std::cout << tpos.X << " " << tpos.Y<<" "<<tpos.Z<<endl;
					//cout << bpos.x <<" "<<bpos.y<<" "<<bpos.z<<endl;
//					manager.setBlockType(bpos, Block::Air);
					
					const Vector3D & pos = camera.getPosition();
					const Vector3D & forw = camera.getForward();
					
					sf::Vector3i sel, next; 
					sf::Vector3f src(pos.X, pos.Y, pos.Z), dir(forw.X, forw.Y, forw.Z);
				
					
					if (rh.raycast(manager,src,dir,sel,next)) {
						manager.setBlockType(sel, Block::AIR);
						cout << "Block "<< sel.x <<" "<<sel.y<<" "<<sel.z<<endl;
					}
					
				} 
						
            }
        }
		
		
		manager.update();
		
		camera.animate(10);
		
		
		sf::Vector3i selectedBlock;
		{
		const Vector3D & pos = camera.getPosition();
		const Vector3D & forw = camera.getForward();
		//cout << "Forward " << forw.X << " "<< forw.Y << " " << forw.Z<<endl;
		sf::Vector3i sel, next; 
		sf::Vector3f src(pos.X, pos.Y, pos.Z), dir(forw.X, forw.Y, forw.Z);
		
		
		if (rh.raycast(manager,src,dir,sel,next)) {
			//cout << "Block "<< sel.x <<" "<<sel.y<<" "<<sel.z<<endl;
			//cout << " Next "<< next.x <<" "<<next.y<<" "<<next.z<<endl;
			selectedBlock = sel;
		}
		}
		
		
		
        renderer.clear();
		camera.look();
		
		glBegin(GL_LINES);
			glColor3f(1,1,1);
			glVertex3f(0,0,0);glVertex3f(1,0,0);
			glVertex3f(0,0,0);glVertex3f(0,1,0);
			glVertex3f(0,0,0);glVertex3f(0,0,1);
		glEnd();
		
		glPushMatrix();
		
		
		manager.draw(renderer);
		
		glPopMatrix();
		

		// render selected block		
		renderer.translate(selectedBlock.x,
						   selectedBlock.y,
						   selectedBlock.z);
		glLineWidth(1);
		//glDisable(GL_DEPTH_TEST);
		glBegin(GL_LINES);
			glColor3f(1,0,0);
			glVertex3f(0,0,0);glVertex3f(1,0,0);
			glVertex3f(0,0,0);glVertex3f(0,1,0);
			glVertex3f(0,0,0);glVertex3f(0,0,1);
			
			glVertex3f(1,1,1);glVertex3f(1,0,1);
			glVertex3f(1,1,1);glVertex3f(0,1,1);
			glVertex3f(1,1,1);glVertex3f(1,1,0);
			
			glVertex3f(1,0,0);glVertex3f(1,1,0);
			glVertex3f(1,0,0);glVertex3f(1,0,1);
			glVertex3f(1,0,1);glVertex3f(0,0,1);
			
			glVertex3f(0,1,0);glVertex3f(1,1,0);
			glVertex3f(0,1,0);glVertex3f(0,1,1);
			glVertex3f(0,1,1);glVertex3f(0,0,1);
		glEnd();
		//glEnable(GL_DEPTH_TEST);
		
        window.display();
		
    }

    return 0;
}

