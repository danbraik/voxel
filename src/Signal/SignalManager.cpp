#include "SignalManager.hpp"

using namespace Signal;

#include "../VectorTools.hpp"
using namespace VectorTools;

SignalManager::SignalManager(VoxelEngine & voxel) : mVoxel(voxel)
{
	
}

bool add(Socket & pair, int localSlot, SignalableBlock * block) {
	if (block == 0) {
		pair.node = 0;
		return false;
	}
	pair.lslot = localSlot;
	pair.node = block;
	return true;
}

void SignalManager::addSignalable(Block & block, const BlockCoordinate &bpos)
{
	SignalableBlock * sblock = dynamic_cast<SignalableBlock*>(&(block));
	if(!sblock)
		return;
	
	std::vector<Socket> pairvec;
	
	Socket pair;
	
	if (add(pair, SignalableBlock::X, dynamic_cast<SignalableBlock*>(&(mVoxel.getBlock(bpos+EXi)))))
		pairvec.push_back(pair);
	if (add(pair, SignalableBlock::Y, dynamic_cast<SignalableBlock*>(&(mVoxel.getBlock(bpos+EYi)))))
		pairvec.push_back(pair);
	if (add(pair, SignalableBlock::Z, dynamic_cast<SignalableBlock*>(&(mVoxel.getBlock(bpos+EZi)))))
		pairvec.push_back(pair);
	if (add(pair, SignalableBlock::_X, dynamic_cast<SignalableBlock*>(&(mVoxel.getBlock(bpos-EXi)))))
		pairvec.push_back(pair);
	if (add(pair, SignalableBlock::_Y, dynamic_cast<SignalableBlock*>(&(mVoxel.getBlock(bpos-EYi)))))
		pairvec.push_back(pair);
	if (add(pair, SignalableBlock::_Z, dynamic_cast<SignalableBlock*>(&(mVoxel.getBlock(bpos-EZi)))))
		pairvec.push_back(pair);
	
	sblock->welcomeToWorld(*this, pairvec);
	
	mToUpdate.push(sblock);
	
	for(std::vector<Socket>::iterator it = pairvec.begin();
		it != pairvec.end();++it)
		mToUpdate.push(it->node);
	
}

void SignalManager::rmSignalable(Block &block, const BlockCoordinate &bpos)
{
	SignalableBlock * sblock = dynamic_cast<SignalableBlock*>(&(block));
	if(!sblock)
		return;
	
	sblock->sayByeToWorld(*this);
}


void SignalManager::update()
{
	SignalableQueue copy = mToUpdate;
	// clear
	while (!mToUpdate.empty()) mToUpdate.pop();
	
	while(!copy.empty()) {
		SignalableBlock * sb = copy.front();
		copy.pop();
		
		if (sb->update(*this)) {
			//test
			
			mVoxel.needRebuild(mVoxel.getChunkId(ChunkCoordinate(0,0,0)));
		}
			
	}
}



void SignalManager::addToUpdate(SignalableBlock *block)
{
	mToUpdate.push(block);
}

void SignalManager::addToUpdate(Block & block)
{
	SignalableBlock * sb =
			dynamic_cast<SignalableBlock*>(&block);
	if (sb)
		addToUpdate(sb);
}
