#include "VoxelEngine.hpp"

VoxelEngine::VoxelEngine() :
	mPersistence(),
	mList(),
	mManager(mList, mPersistence),
	mRaycast()
	
{
	mPersistence.setDirectory("/home/daniel/projects/c_cpp/voxel/world");	
}

ChunkManager &VoxelEngine::getChunkManager()
{
	return mManager;
}

BlockList &VoxelEngine::getBlockList()
{
	return mList;
}
