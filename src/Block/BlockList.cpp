#include "BlockList.hpp"

#include "ComplexBlock.hpp"
#include "BlockCxPower.hpp"


NoBlock BlockList::NO_BLOCK;


BlockList::BlockList() :
	mNextId(10),
	mBlocks()
{
//	mBlockNONE.init(1.f,0,0,false);
	
//	for(int i =0;i < 50;++i)
//		mBlocks.push_back(&mBlockNONE);
	
//	addBlock(Block::AIR, 1.f,1,1,false);
//	addBlock(Block::NONE, 1.f,0,0,false);
	
//	addBlock(Block::Dirt, .25,.75,.25,true, .5);
//	addBlock(Block::Stone, .5,.5,.5,true);
//	addBlock(Block::Water, 0,0,0,false);
	
//	addWireBlock(Block::WireOff, .2,0,0,false);
//	addWireBlock(Block::WireOn, 1,0,0,false);
	
//	addPowerBlock(Block::Power, 1,.25,.25,true);
}

//const Block & BlockList::get(BlockType type) const {
//	try {
//		return *mBlocks.at(type);
//	} catch (std::out_of_range & e) {
//		return mBlockNONE;
//	}
//}

//BlockType BlockList::addBlock(const Block &newBlock)
//{
//	mBlocks.push_back(&newBlock);
//	return mNextId++;
//}

//void BlockList::addBlock(BlockType type, float r, float g, float b, bool filled, float a)
//{
//	Block * block = new Block();
//	block->init(r,g,b,filled,a);
//	setBlock(type, block);
//}

//void BlockList::addComplexBlock(BlockType type, float r, float g, float b, bool filled, float a)
//{
//	Block * block = new BlockComplex();
//	block->init(r,g,b,filled,a);
//	setBlock(type, block);
//}

//void BlockList::addWireBlock(BlockType type, float r, float g, float b, bool filled, float a)
//{
//	Block * block = new BlockCxWire();
//	block->init(r,g,b,filled,a);
//	setBlock(type, block);
//}

//void BlockList::addPowerBlock(BlockType type, float r, float g, float b, bool filled, float a)
//{
//	Block * block = new BlockCxPower();
//	block->init(r,g,b,filled,a);
//	setBlock(type, block);
//}



//void BlockList::setBlock(BlockType type, Block *block)
//{
//	mBlocks[type] = block;
//}
