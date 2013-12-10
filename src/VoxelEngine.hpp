#ifndef VOXELENGINE_HPP
#define VOXELENGINE_HPP

#include <iostream>
#include <SFML/Graphics.hpp>

#include "Render/Renderer.hpp"
#include "Chunk/ChunkManager.hpp"
#include "Chunk/ChunkPersistence.hpp"
#include "RaycastHelper.hpp"

class VoxelEngine
{
	public:
		VoxelEngine();
		
		//test
		ChunkId getChunkId(const ChunkCoordinate & cpos);
		void needRebuild(const ChunkId & chunkId);
		
		ChunkManager & getChunkManager();
		BlockList & getBlockList();
		
		inline bool raycast(sf::Vector3f & source, sf::Vector3f &direction,
					 BlockCoordinate & selectCube, sf::Vector3i & nextNorm) const {
			return mRaycast.raycast(mManager, source, direction, selectCube, nextNorm);
		}
		
		inline void setBlock(const BlockCoordinate & absoluteBlockPosition, Block & block) {
			mManager.setBlock(absoluteBlockPosition, block);
		}
		
		inline Block & getBlock(const BlockCoordinate & absoluteBlockPosition) {
			return mManager.getBlock(absoluteBlockPosition);
		}		
		
		inline void update() {
			mManager.update();
		}
		
		inline void draw(Renderer & renderer) const {
			mManager.draw(renderer);
		}
		
//		inline BlockType addBlock(const Block & newBlock) {
//			return mList.addBlock(newBlock);
//		}
		
		
		
	private:
		
		ChunkPersistence mPersistence;
		
		BlockList mList;
		
		ChunkManager mManager;
		
		RaycastHelper mRaycast;
};

#endif // VOXELENGINE_HPP
