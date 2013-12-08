#ifndef SIMPLEBLOCK_HPP
#define SIMPLEBLOCK_HPP

#include "Block.hpp"

class SimpleBlock : public Block
{
	public:
		SimpleBlock(float red = .5f, 
					float green = .5f, 
					float blue = .5f, 
					float alpha = 1.0);
		
		virtual void build(MeshVertexVector &vertices, const sf::Vector3f &pos, const Block &right, const Block &behind, const Block &left, const Block &front, const Block &top, const Block &bottom) const;
		
	protected:
		float mRed, mGreen, mBlue, mAlpha;
};

#endif // SIMPLEBLOCK_HPP
