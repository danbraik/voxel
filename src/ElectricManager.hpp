#ifndef ELECTRICMANAGER_HPP
#define ELECTRICMANAGER_HPP

#include "VoxelEngine.hpp"


class ElectricManager
{
	public:
//		class CBlock {
//		public:
//			 BlockType WireOff;
//			 BlockType WireOn;
//			 BlockType Power;
//		};
//		static CBlock Block;
		
		
		ElectricManager(VoxelEngine & voxel);
		
		void newPower(const BlockCoordinate & pos);
		void newWire(const BlockCoordinate & pos);
		
		void addSignal(const BlockCoordinate & pos);
		void addSignalToNeighbours(const BlockCoordinate & pos);
		
		void repulseSignal(const BlockCoordinate & pos);
		void repulseSignalFromNeighbours(const BlockCoordinate & pos);
		
		void rmPower(const BlockCoordinate & pos);
		void rmWireOn(const BlockCoordinate & pos);
		
		void rmSignal(const BlockCoordinate & pos);
		void rmSignalToNeighbours(const BlockCoordinate & pos);
		
		void update();
		
	private:
//		::Block wireOffBlk, wireOnBlk, powerBlk;
		
		ChunkManager & mManager;
		
		
		PositionVector mBlockToAddSignal;
		PositionVector mBlockToRepulseSignal;
		PositionVector mBlockToRmSignal;
};

#endif // ELECTRICMANAGER_HPP
