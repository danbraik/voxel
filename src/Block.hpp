#ifndef BLOCK_HPP
#define BLOCK_HPP

#include <SFML/System.hpp>

typedef sf::Int32 BlockType;


class Block
{
	public:
		static const float SIZE = 1.f;
		
		static const BlockType NONE = 0;
		static const BlockType Air = 1;
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
			mList[Block::NONE].init(1.f,0,0,false);
			mList[Block::Air].init(.9,.9,.9,false);
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
