#include "VoxelEngine.hpp"

VoxelEngine::VoxelEngine() :
	mPersistence(),
	mList(),
	mManager(mList, mPersistence),
	mRaycast()
	
{
	mPersistence.setDirectory("/home/daniel/projects/c_cpp/voxel/world");	
}

ChunkId VoxelEngine::getChunkId(const ChunkCoordinate &cpos)
{
	mManager.getChunkId(cpos);
}

void VoxelEngine::needRebuild(const ChunkId &chunkId)
{
	mManager.needRebuild(chunkId);
}

ChunkManager &VoxelEngine::getChunkManager()
{
	return mManager;
}

BlockList &VoxelEngine::getBlockList()
{
	return mList;
}
