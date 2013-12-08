#include <iostream>
#include <SFML/Graphics.hpp>
#include "Render/Renderer.hpp"
#include "Freeflycamera.h"
#include "Chunk/ChunkManager.hpp"
#include "WorldGenerator.hpp"
#include "Chunk/ChunkPersistence.hpp"
#include "RaycastHelper.hpp"
#include "ProfilTimer.hpp"
#include "VoxelEngine.hpp"
#include "Block/SimpleBlock.hpp"
#include "Block/BlockList.hpp"

#include "Signal/Wire.hpp"
#include "Signal/SignalManager.hpp"
#include "Signal/AndLogic.hpp"

using namespace std;

#define NONE "none"
#define GROUND "ground"
#define DIRT "dirt"
#define WIRE_UNIV "wire_univ"
#define WIRE_RED "wire_red"
#define WIRE_GREEN "wire_green"
#define POWER "power"
#define AND "and"

SimpleBlock ground, dirt(.0,1.,.0);

// TODO : a factory
Block & getNewBlock(const std::string & classname) {
	if (classname == NONE)
		return BlockList::NO_BLOCK;
	if (classname == GROUND)
		return ground;
	if (classname == DIRT)
		return dirt;
	if (classname == WIRE_UNIV)
		return *(new Signal::Wire(0));
	if (classname == WIRE_RED)
		return *(new Signal::Wire(1));
	if (classname == WIRE_GREEN)
		return *(new Signal::Wire(2));
	if (classname == POWER)
		return *(new Signal::Power());
	if (classname == AND)
		return *(new Signal::AndLogic());
	
	return BlockList::NO_BLOCK;
}


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
	window.setPosition(sf::Vector2i(0,0));
    window.setVerticalSyncEnabled(true);
	//window.setFramerateLimit(10);

	
	Renderer renderer;
	renderer.screen(SCREEN_WIDTH, SCREEN_HEIGHT);
	
	
	VoxelEngine voxel;
	
	WorldGenerator worldGenerator(voxel);
	worldGenerator.init();
	
	
	Signal::SignalManager signalManager(voxel);


	
	//	addWireBlock(Block::WireOff, );
	//	addWireBlock(Block::WireOn, );
		
	//	addPowerBlock(Block::Power, ;
	
	FreeFlyCamera camera(Vector3D(12,12,4));
	
	
	
	std::string currentBlock = WIRE_GREEN;
	
	
	ProfilTimer ptimer;
	
	//avoid event when move cursor
	bool mouseMoved = true;
	sf::Mouse::setPosition(sf::Vector2i(SCREEN_WIDTH/2, SCREEN_HEIGHT/2), window);
    
	long loop = 0;
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
					worldGenerator.makeBoard(bpos);
					
                } else if (event.key.code == sf::Keyboard::U) {
					const Vector3D & tpos = camera.getTargetPosition();
					BlockCoordinate bpos( tpos.X, tpos.Y,tpos.Z);
					//std::cout << tpos.X << " " << tpos.Y<<" "<<tpos.Z<<endl;
					//cout << bpos.x <<" "<<bpos.y<<" "<<bpos.z<<endl;
					
                } else if (event.key.code == sf::Keyboard::I) {
					const Vector3D & tpos = camera.getTargetPosition();
					ChunkCoordinate bpos( tpos.X, tpos.Y,tpos.Z);
					
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
				} else if (event.key.code == sf::Keyboard::Numpad0) {
					currentBlock = GROUND;					
				} else if (event.key.code == sf::Keyboard::Numpad1) {
					currentBlock = WIRE_RED;
				} else if (event.key.code == sf::Keyboard::Numpad2) {
					currentBlock = WIRE_GREEN;
				} else if (event.key.code == sf::Keyboard::Numpad3) {
					currentBlock = WIRE_UNIV;
				} else if (event.key.code == sf::Keyboard::Numpad4) {
					currentBlock = POWER;
				} else if (event.key.code == sf::Keyboard::Numpad5) {
					currentBlock = AND;
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
					
					if (voxel.raycast(src,dir,sel,next)) {
						cout << "Block (add) "<< sel.x <<" "<<sel.y<<" "<<sel.z<<endl;
						Block & block = getNewBlock(currentBlock);
						voxel.setBlock(sel+next, block);
						
						if (currentBlock==POWER)
							signalManager.addPower(block, sel+next);
						else if (currentBlock==WIRE_RED||
								 currentBlock==WIRE_GREEN||
								 currentBlock==WIRE_UNIV)
							signalManager.addWire(block , sel+next);
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
				
					
					if (voxel.raycast(src,dir,sel,next)) {
						const Block & block = voxel.getBlock(sel);
//						if (type == ElectricManager::Block.Power)
//							electricManager.rmPower(sel);
//						else if (type == ElectricManager::Block.WireOn)
//							electricManager.rmWireOn(sel);
						
						voxel.setBlock(sel, BlockList::NO_BLOCK);
						cout << "Block "<< sel.x <<" "<<sel.y<<" "<<sel.z<<endl;
					}
				} 	
            }
        }
		
		
		//signalManager.update();
		
		//if (loop % 50 == 0)
			voxel.update();
		
		camera.animate(10);
		
		
		sf::Vector3i selectedBlock;
		{
		const Vector3D & pos = camera.getPosition();
		const Vector3D & forw = camera.getForward();
		//cout << "Forward " << forw.X << " "<< forw.Y << " " << forw.Z<<endl;
		sf::Vector3i sel, next; 
		sf::Vector3f src(pos.X, pos.Y, pos.Z), dir(forw.X, forw.Y, forw.Z);
		
		
		if (voxel.raycast(src,dir,sel,next)) {
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
		
		
		voxel.draw(renderer);
		
//		ptimer.end();
//		ptimer.begin();
		
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
		
		++loop;
    }

    return 0;
}

