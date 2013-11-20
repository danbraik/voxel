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
		void init(int rr,int gg,int bb, bool f) {
			r=rr;g=gg;b=bb;filled=f;
		}
		int r,g,b;
		bool filled;
};


class BlockList {
	
	public:
		
		BlockList() {
			mList[Block::NONE].init(255,0,0,false);
			mList[Block::Air].init(240,240,244,false);
			mList[Block::Dirt].init(64,192,64,true);
			mList[Block::Stone].init(128,128,128,true);
			mList[Block::Water].init(0,0,0,false);
		}
		
		Block get(BlockType type) {
			return mList[type];
		}
		
	private:
		Block mList[10];
	
};

#endif // BLOCK_HPP
