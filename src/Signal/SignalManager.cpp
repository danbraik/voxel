#include "SignalManager.hpp"

using namespace Signal;

#include "../VectorTools.hpp"
using namespace VectorTools;

SignalManager::SignalManager(VoxelEngine & voxel) : mVoxel(voxel)
{
	
}

void SignalManager::addPower(Block & block, const BlockCoordinate &bpos)
{
	Power * power = dynamic_cast<Power*>(&(block));
	if(!power)
		return;
	
	SignalableBlock * nei[MAX_SLOTS];
	nei[SignalableBlock::X] = dynamic_cast<SignalableBlock*>(&(mVoxel.getBlock(bpos+EXi)));
	nei[SignalableBlock::Y] = dynamic_cast<SignalableBlock*>(&(mVoxel.getBlock(bpos+EYi)));
	nei[SignalableBlock::Z] = dynamic_cast<SignalableBlock*>(&(mVoxel.getBlock(bpos+EZi)));
	nei[SignalableBlock::_X] = dynamic_cast<SignalableBlock*>(&(mVoxel.getBlock(bpos-EXi)));
	nei[SignalableBlock::_Y] = dynamic_cast<SignalableBlock*>(&(mVoxel.getBlock(bpos-EYi)));
	nei[SignalableBlock::_Z] = dynamic_cast<SignalableBlock*>(&(mVoxel.getBlock(bpos-EZi)));
	
	power->welcomeToWorld(nei);
	
	power->update();
}

void SignalManager::addWire(Block &block, const BlockCoordinate &bpos)
{
	Wire * wire = dynamic_cast<Wire*>(&(block));
	if(!wire)
		return;
	
	SignalableBlock * nei[MAX_SLOTS];
	nei[SignalableBlock::X] = dynamic_cast<SignalableBlock*>(&(mVoxel.getBlock(bpos+EXi)));
	nei[SignalableBlock::Y] = dynamic_cast<SignalableBlock*>(&(mVoxel.getBlock(bpos+EYi)));
	nei[SignalableBlock::Z] = dynamic_cast<SignalableBlock*>(&(mVoxel.getBlock(bpos+EZi)));
	nei[SignalableBlock::_X] = dynamic_cast<SignalableBlock*>(&(mVoxel.getBlock(bpos-EXi)));
	nei[SignalableBlock::_Y] = dynamic_cast<SignalableBlock*>(&(mVoxel.getBlock(bpos-EYi)));
	nei[SignalableBlock::_Z] = dynamic_cast<SignalableBlock*>(&(mVoxel.getBlock(bpos-EZi)));

	wire->welcomeToWorld(nei);
	
}
