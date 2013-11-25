#ifndef BLOCK_HPP
#define BLOCK_HPP

#include <SFML/System.hpp>
#include <iostream>

typedef sf::Int32 BlockType;
typedef sf::Vector3i ChunkCoordinate;
typedef sf::Vector3i BlockCoordinate;

class Block
{
	public:
		static const float SIZE = 1.f;
		
		// de-activated
		static const BlockType AIR = 0;//must be 0 (because of memset)
		// activated
		static const BlockType Patate = 1;
		static const BlockType Dirt = 2;
		static const BlockType Stone = 3;
		static const BlockType Water = 4;

	public:	
		Block();
		void init(float rr,float gg,float bb, bool f) {
			mR=rr;mG=gg;mB=bb;mFilled=f;
		}
		
		bool isFilled() const {
			return mFilled;
		}
		
		float r() const {
			return mR;
		}
		float g() const {
			return mG;
		}
		float b() const {
			return mB;
		}
		
	private:
		float mR,mG,mB;
		bool mFilled;
		
};


class BlockList {
	
	public:
		
		BlockList() {
			mList[Block::AIR].init(1.f,0,0,false);
			mList[Block::Patate].init(.9,.9,.9,false);
			mList[Block::Dirt].init(.25,.75,.25,true);
			mList[Block::Stone].init(.5,.5,.5,true);
			mList[Block::Water].init(0,0,0,false);
		}
		
		const Block & get(BlockType type) const;
		
	private:
		Block mList[5];
	
};


inline const Block & BlockList::get(BlockType type) const {
	return mList[type];
}

#endif // BLOCK_HPP
