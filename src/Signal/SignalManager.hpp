#ifndef SIGNALMANAGER_HPP
#define SIGNALMANAGER_HPP

#include "SignalableBlock.hpp"
#include "Wire.hpp"
#include "Power.hpp"
#include "../VoxelEngine.hpp"

#include <queue>

namespace Signal {
	
	typedef std::queue<SignalableBlock*> SignalableQueue;
	
	class SignalManager
	{
		public:
			SignalManager(VoxelEngine & voxel);
			
			void addSignalable(Block &block, const BlockCoordinate &bpos);
			void rmSignalable(Block &block, const BlockCoordinate &bpos);
			
			void update();
			
			void addToUpdate(Block &block);
			void addToUpdate(SignalableBlock * block);
			
		private:
			VoxelEngine & mVoxel;
			
			SignalableQueue mToUpdate;
	};

}
	
#endif // SIGNALMANAGER_HPP
