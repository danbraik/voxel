#ifndef BLOCKLIST_HPP
#define BLOCKLIST_HPP

#include "Block.hpp"
#include "NoBlock.hpp"

#include <vector>
#include <stdexcept>

typedef std::vector<const Block*> BlockPtrVector;

class BlockList {
	
	public:
		static NoBlock NO_BLOCK;
		
		
		BlockList();
//		const Block & get(BlockType type) const;
		
//		// return the id associeted to the new block
//		BlockType addBlock(const Block & newBlock);
		
	private:
//		void addBlock(BlockType type, float r, float g, float b, bool filled, float a = 1.0);
//		void addComplexBlock(BlockType type, float r, float g, float b, bool filled, float a = 1.0);
//		void addWireBlock(BlockType type, float r, float g, float b, bool filled, float a=1.0);
//		void addPowerBlock(BlockType type, float r, float g, float b, bool filled, float a=1.0);
//		void setBlock(BlockType type, Block * block);
		
		
		int mNextId;
		BlockPtrVector mBlocks;
		
	
};


#endif // BLOCKLIST_HPP
