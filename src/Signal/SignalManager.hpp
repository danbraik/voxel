#ifndef SIGNALMANAGER_HPP
#define SIGNALMANAGER_HPP

#include "SignalableBlock.hpp"
#include "Wire.hpp"
#include "Power.hpp"
#include "../VoxelEngine.hpp"

namespace Signal {
	
	class SignalManager
	{
		public:
			SignalManager(VoxelEngine & voxel);
			
			void addPower(Block &block, const BlockCoordinate &bpos);
			void addWire(Block &block, const BlockCoordinate &bpos);
			
		private:
			VoxelEngine & mVoxel;
	};

}
	
#endif // SIGNALMANAGER_HPP
