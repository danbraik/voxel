#include "ElectricManager.hpp"
#include "VectorTools.hpp"

using namespace VectorTools;

ElectricManager::ElectricManager(VoxelEngine & voxel)
	: mManager(voxel.getChunkManager()), mBlockToAddSignal(),
	  mBlockToRepulseSignal(), mBlockToRmSignal()
{
	BlockList & list = voxel.getBlockList();
	
	
	
//	wireOffBlk.init(.2,0,0,false);
//	wireOnBlk.init(1,0,0,false);
//	powerBlk.init(1,.25,.25,true);
//	Block.WireOff = voxel.addBlock(wireOffBlk);
//	Block.WireOn = voxel.addBlock(wireOnBlk); 
//	Block.Power = voxel.addBlock(powerBlk);
}



void ElectricManager::newPower(const BlockCoordinate &pos)
{
	addSignalToNeighbours(pos);
}

void ElectricManager::newWire(const BlockCoordinate &pos)
{
	repulseSignalFromNeighbours(pos);
}

void ElectricManager::addSignal(const BlockCoordinate &pos)
{
	mBlockToAddSignal.push_back(pos);
}

void ElectricManager::addSignalToNeighbours(const BlockCoordinate &pos)
{
	addSignal(pos + EXi);
	addSignal(pos + EYi);
	addSignal(pos - EXi);
	addSignal(pos - EYi);
	addSignal(pos + EZi);
	addSignal(pos - EZi);
}

void ElectricManager::repulseSignal(const BlockCoordinate &pos)
{
	mBlockToRepulseSignal.push_back(pos);
}

void ElectricManager::repulseSignalFromNeighbours(const BlockCoordinate &pos)
{
	repulseSignal(pos + EXi);
	repulseSignal(pos + EYi);
	repulseSignal(pos - EXi);
	repulseSignal(pos - EYi);
	repulseSignal(pos + EZi);
	repulseSignal(pos - EZi);
}

void ElectricManager::rmPower(const BlockCoordinate &pos)
{
	rmSignalToNeighbours(pos);
}

void ElectricManager::rmWireOn(const BlockCoordinate &pos)
{
	// for fun
	rmSignalToNeighbours(pos);
}

void ElectricManager::rmSignal(const BlockCoordinate &pos)
{
	mBlockToRmSignal.push_back(pos);
}

void ElectricManager::rmSignalToNeighbours(const BlockCoordinate &pos)
{
	rmSignal(pos + EXi);
	rmSignal(pos + EYi);
	rmSignal(pos - EXi);
	rmSignal(pos - EYi);
	rmSignal(pos + EZi);
	rmSignal(pos - EZi);
}


void ElectricManager::update()
{
//	PositionVector copy;
	
	
//	// treat signal
//	copy = mBlockToAddSignal;
//	mBlockToAddSignal.clear();
//	for (PositionVector::const_iterator it = copy.begin();
//		it != copy.end();++it)	{
//		const BlockCoordinate & pos = *it;
//		BlockType type = mManager.getBlockType(pos);
		
////		if (type == Block.WireOff) {		
////			mManager.setBlockType(pos, Block.WireOn);
////			addSignalToNeighbours(pos);
//	//	}
		
//	}
//	// end
	
	
//	// treat repulse
//	copy = mBlockToRepulseSignal;
//	mBlockToRepulseSignal.clear();
//	for (PositionVector::const_iterator it = copy.begin();
//		it != copy.end();++it)	{
//		const BlockCoordinate & pos = *it;
//		BlockType type = mManager.getBlockType(pos);
		
////		if (type == Block.Power)
////			addSignalToNeighbours(pos);
////		if (type == Block.WireOn)
////			addSignalToNeighbours(pos);
				
		
//	}
//	// end
	
	
	
	
	
	
	
	
//	// treat rm signal
//	copy = mBlockToRmSignal;
//	mBlockToRmSignal.clear();
//	for (PositionVector::const_iterator it = copy.begin();
//		it != copy.end();++it)	{
//		const BlockCoordinate & pos = *it;
//		BlockType type = mManager.getBlockType(pos);
		
////		if (type == Block.Power)//no sense, repulse
////			addSignalToNeighbours(pos);
				
////		else if (type == Block.WireOn) {
////			mManager.setBlockType(pos, Block.WireOff);
////			rmSignalToNeighbours(pos);
////		}
		
//	}
	// end
}
