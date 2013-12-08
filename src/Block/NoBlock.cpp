#include "NoBlock.hpp"

NoBlock::NoBlock() : Block(false)
{
}

// to make NoBlock concrete class
void NoBlock::build(MeshVertexVector &vertices, const sf::Vector3f &pos, const Block &right, const Block &behind, const Block &left, const Block &front, const Block &top, const Block &bottom) const
{
	throw "NoBlock.build was called.";
}

NoBlock::~NoBlock()
{
}
