#ifndef BLOCK_HPP
#define BLOCK_HPP

#include <SFML/System.hpp>
#include <iostream>

//#define DEV

#ifdef DEV
	class ChunkCoordinate : public sf::Vector3i {public:ChunkCoordinate(){}ChunkCoordinate(int x, int y, int z):sf::Vector3i(x,y,z){}};
	class BlockCoordinate : public sf::Vector3i {public:BlockCoordinate(){}BlockCoordinate(int x, int y, int z):sf::Vector3i(x,y,z){}};
#else	
	typedef sf::Vector3i ChunkCoordinate;
	typedef sf::Vector3i BlockCoordinate;
#endif

typedef sf::Int32 BlockType;

class Block
{
	public:
		//static const float SIZE = 1.f;
		
		// de-activated
		
		static const BlockType AIR = 0;//must be 0 (because of memset)
		static const BlockType NONE = 1;
		// activated
		static const BlockType ACTIVATED = 2;
		static const BlockType Dirt = 10;
		static const BlockType Stone = 11;
		static const BlockType Water = 12;

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
			mList[Block::AIR].init(1.f,1,1,false);
			mList[Block::NONE].init(1.f,0,0,true);
			
			mList[Block::Dirt].init(.25,.75,.25,true);
			mList[Block::Stone].init(.5,.5,.5,true);
			mList[Block::Water].init(0,0,0,false);
		}
		
		const Block & get(BlockType type) const;
		
	private:
		Block mList[50];
	
};


inline const Block & BlockList::get(BlockType type) const {
	return mList[type];
}

#endif // BLOCK_HPP
