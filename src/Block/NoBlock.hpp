#ifndef NOBLOCK_HPP
#define NOBLOCK_HPP

#include "Block.hpp"

class NoBlock : public Block
{
	public:
		NoBlock();
		
		virtual void build(MeshVertexVector &vertices, const sf::Vector3f &pos, const Block &right, const Block &behind, const Block &left, const Block &front, const Block &top, const Block &bottom) const;
		
		virtual ~NoBlock();
};

#endif // NOBLOCK_HPP
