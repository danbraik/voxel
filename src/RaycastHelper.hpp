#ifndef RAYCASTHELPER_HPP
#define RAYCASTHELPER_HPP

#include <SFML/System.hpp>
#include "Chunk/ChunkManager.hpp"

class RaycastHelper
{
	public:
		RaycastHelper();
		bool raycast(const ChunkManager & manager, const sf::Vector3f & source, const sf::Vector3f &direction,
					 sf::Vector3i & selectCube, sf::Vector3i & nextNorm) const;
};

#endif // RAYCASTHELPER_HPP
