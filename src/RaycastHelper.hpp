#ifndef RAYCASTHELPER_HPP
#define RAYCASTHELPER_HPP

#include <SFML/System.hpp>
#include "ChunkManager.hpp"

class RaycastHelper
{
	public:
		RaycastHelper();
		bool raycast(ChunkManager & manager, sf::Vector3f & source, sf::Vector3f dir,
					 sf::Vector3i & selectCube, sf::Vector3i & nextCube);
};

#endif // RAYCASTHELPER_HPP
