#include "SimpleBlock.hpp"

#include "../VectorTools.hpp"
using namespace VectorTools;

SimpleBlock::SimpleBlock(float red, float green, float blue, float alpha) : Block(true, true),
	mRed(red), mGreen(green), mBlue(blue), mAlpha(alpha)
{
}

inline bool testBlock(const Block & block) {
	return ! block.isFilled();
}

void SimpleBlock::build(MeshVertexVector &vertices, const sf::Vector3f &pos, const Block &right, const Block &behind, const Block &left, const Block &front, const Block &top, const Block &bottom) const
{
	
	if (testBlock(front)) {
		// front
		
		addVertex(vertices,  -EYf,  pos, mRed, mGreen, mBlue, mAlpha);
		addVertex(vertices,  -EYf,  pos+EXf, mRed, mGreen, mBlue, mAlpha);
		addVertex(vertices,  -EYf,  pos+EXf+EZf,mRed, mGreen, mBlue, mAlpha);
		
		addVertex(vertices,  -EYf,  pos,mRed, mGreen,mBlue, mAlpha);
		addVertex(vertices,  -EYf,  pos+EXf+EZf,mRed, mGreen,mBlue,  mAlpha);
		addVertex(vertices,  -EYf,  pos+EZf,mRed, mGreen,mBlue, mAlpha);
		
	}
	if(testBlock(right)) {	
		// right
		
		addVertex(vertices,  EXf,  pos+EXf,mRed, mGreen,mBlue,  mAlpha);
		addVertex(vertices,  EXf,  pos+EXf+EYf,mRed, mGreen,mBlue, mAlpha);
		addVertex(vertices,  EXf,  pos+EXf+EYf+EZf,mRed, mGreen,mBlue, mAlpha);
		
		addVertex(vertices,  EXf,  pos+EXf,mRed, mGreen,mBlue, mAlpha);
		addVertex(vertices,  EXf,  pos+EXf+EYf+EZf,mRed, mGreen,mBlue, mAlpha);
		addVertex(vertices,  EXf,  pos+EXf+EZf,mRed, mGreen,mBlue, mAlpha);
	}
	if(testBlock(behind)) {
		// behind
		
		addVertex(vertices,  EYf,  pos+EXf+EYf,mRed, mGreen,mBlue, mAlpha);
		addVertex(vertices,  EYf,  pos+EYf,mRed, mGreen,mBlue, mAlpha);
		addVertex(vertices,  EYf,  pos+EYf+EZf,mRed, mGreen,mBlue, mAlpha);
		
		addVertex(vertices,  EYf,  pos+EXf+EYf,mRed, mGreen,mBlue, mAlpha);
		addVertex(vertices,  EYf,  pos+EYf+EZf,mRed, mGreen,mBlue, mAlpha);
		addVertex(vertices,  EYf,  pos+EXf+EYf+EZf,mRed, mGreen,mBlue, mAlpha);
	}
	if(testBlock(left)) {
		// left
		
		addVertex(vertices,  -EXf,  pos+EYf,mRed, mGreen,mBlue, mAlpha);
		addVertex(vertices,  -EXf,  pos,mRed, mGreen,mBlue, mAlpha);
		addVertex(vertices,  -EXf,  pos+EZf,mRed, mGreen,mBlue, mAlpha);
		
		addVertex(vertices,  -EXf,  pos+EYf,mRed, mGreen,mBlue, mAlpha);
		addVertex(vertices,  -EXf,  pos+EZf,mRed, mGreen,mBlue, mAlpha);
		addVertex(vertices,  -EXf,  pos+EYf+EZf,mRed, mGreen,mBlue, mAlpha);
	}
	if(testBlock(top)) {
		// top
		
		addVertex(vertices,  EZf,  pos+EZf,mRed, mGreen,mBlue, mAlpha);
		addVertex(vertices,  EZf,  pos+EZf+EXf,mRed, mGreen,mBlue, mAlpha);
		addVertex(vertices,  EZf,  pos+EZf+EXf+EYf,mRed, mGreen,mBlue, mAlpha);
		
		addVertex(vertices,  EZf,  pos+EZf,mRed, mGreen,mBlue, mAlpha);
		addVertex(vertices,  EZf,  pos+EZf+EXf+EYf,mRed, mGreen,mBlue, mAlpha);
		addVertex(vertices,  EZf,  pos+EZf+EYf,mRed, mGreen,mBlue, mAlpha);
	}
	if(testBlock(bottom)) {
		// bottom
		
		addVertex(vertices,  -EZf,  pos,mRed, mGreen,mBlue, mAlpha);
		addVertex(vertices,  -EZf,  pos+EYf,mRed, mGreen,mBlue, mAlpha);
		addVertex(vertices,  -EZf,  pos+EYf+EXf,mRed, mGreen,mBlue, mAlpha);
		
		addVertex(vertices,  -EZf,  pos,mRed, mGreen,mBlue, mAlpha);
		addVertex(vertices,  -EZf,  pos+EYf+EXf,mRed, mGreen,mBlue, mAlpha);
		addVertex(vertices,  -EZf,  pos+EXf,mRed, mGreen,mBlue, mAlpha);
	}
}
