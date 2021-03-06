#include "LocalChunkSystem.hpp"
#include "ChunkManager.hpp"
#include "../VectorTools.hpp"

using namespace VectorTools;

LocalChunkSystem::LocalChunkSystem(const ChunkManager &manager, 
								   /*const*/ Chunk * chunk) :
	mManager(manager), c(chunk),
	cx(0),cmx(0),cy(0),cmy(0),cz(0),cmz(0),cxy(0),cmxy(0),cmxmy(0),cxmy(0),
	cxyz(0),cmxyz(0),cmxmyz(0),cxmyz(0), 
	cxymz(0),cmxymz(0),cmxmymz(0),cxmymz(0)
{
	const sf::Vector3i & chunkPosition = c->getPosition();
	/*const*/ Chunk * nearChunk = 0;
	
	if (manager.isChunkLoaded(chunkPosition+EXi, nearChunk))
		cx = nearChunk;
	if (manager.isChunkLoaded(chunkPosition+EYi, nearChunk))
		cy = nearChunk;
	
	if (manager.isChunkLoaded(chunkPosition-EXi, nearChunk))
		cmx = nearChunk;
	if (manager.isChunkLoaded(chunkPosition-EYi, nearChunk))
		cmy = nearChunk;
	if (manager.isChunkLoaded(chunkPosition+EZi, nearChunk))
		cz = nearChunk;
	if (manager.isChunkLoaded(chunkPosition-EZi, nearChunk))
		cmz = nearChunk;
	
//	if (manager.isChunkLoaded(chunkPosition+E, nearChunk))
//		c = nearChunk;
//	if (manager.isChunkLoaded(chunkPosition+E, nearChunk))
//		c = nearChunk;
//	if (manager.isChunkLoaded(chunkPosition+E, nearChunk))
//		c = nearChunk;
//	if (manager.isChunkLoaded(chunkPosition+E, nearChunk))
//		c = nearChunk;
//	if (manager.isChunkLoaded(chunkPosition+E, nearChunk))
//		c = nearChunk;
//	if (manager.isChunkLoaded(chunkPosition+E, nearChunk))
//		c = nearChunk;
//	if (manager.isChunkLoaded(chunkPosition+E, nearChunk))
//		c = nearChunk;
//	if (manager.isChunkLoaded(chunkPosition+E, nearChunk))
//		c = nearChunk;
	
//	if (manager.isChunkLoaded(chunkPosition+E, nearChunk))
//		c = nearChunk;
//	if (manager.isChunkLoaded(chunkPosition+E, nearChunk))
//		c = nearChunk;
//	if (manager.isChunkLoaded(chunkPosition+E, nearChunk))
//		c = nearChunk;
//	if (manager.isChunkLoaded(chunkPosition+E, nearChunk))
//		c = nearChunk;
//	if (manager.isChunkLoaded(chunkPosition+E, nearChunk))
//		c = nearChunk;
//	if (manager.isChunkLoaded(chunkPosition+E, nearChunk))
//		c = nearChunk;
//	if (manager.isChunkLoaded(chunkPosition+E, nearChunk))
//		c = nearChunk;
//	if (manager.isChunkLoaded(chunkPosition+E, nearChunk))
//		c = nearChunk;
//	if (manager.isChunkLoaded(chunkPosition+E, nearChunk))
//		c = nearChunk;
//	if (manager.isChunkLoaded(chunkPosition+E, nearChunk))
//		c = nearChunk;
	
}



inline const Block & LocalChunkSystem::getInsideChunk(const Chunk * chunk, 
											   const BlockCoordinate & insideBlockPosition) const {
	if (chunk != 0)
		return chunk->get(insideBlockPosition);
	return mManager.getNoBlock();
}

const Block & LocalChunkSystem::getRelativeBlock(const sf::Vector3i & relativeBlockPosition) const
{
	BlockCoordinate bkPos(relativeBlockPosition);
	
	if (bkPos.x >= 0) {										
		if (bkPos.x < Chunk::SIZE) {
			if (bkPos.y >= 0) {
				if (bkPos.y < Chunk::SIZE) {
					if (bkPos.z >= 0) {
						if (bkPos.z < Chunk::SIZE) {
							return getInsideChunk(c, bkPos);
						} else {
							bkPos.z -= Chunk::SIZE;
							return getInsideChunk(cz, bkPos);
						}
					} else {
						bkPos.z += Chunk::SIZE;
						return getInsideChunk(cmz, bkPos);
					}
				} else {
					bkPos.y -= Chunk::SIZE;
					if (bkPos.z >= 0) {
						if (bkPos.z < Chunk::SIZE) {
							return getInsideChunk(cy, bkPos);
						} else {
							bkPos.z -= Chunk::SIZE;
							return getInsideChunk(cyz, bkPos);
						}
					} else {
						bkPos.z += Chunk::SIZE;
						return getInsideChunk(cymz, bkPos);
					}
				}
			} else {
				bkPos.y += Chunk::SIZE;
				
				if (bkPos.z >= 0) {
					if (bkPos.z < Chunk::SIZE) {
						return getInsideChunk(cmy, bkPos);
					} else {
						bkPos.z -= Chunk::SIZE;
						return getInsideChunk(cmyz, bkPos);
					}
				} else {
					bkPos.z += Chunk::SIZE;
					return getInsideChunk(cmymz, bkPos);
				}
			}
		
		}
		else { // x >= Size
			bkPos.x -= Chunk::SIZE;
			
			if (bkPos.y >= 0) {
				if (bkPos.y < Chunk::SIZE) {
					if (bkPos.z >= 0) {
						if (bkPos.z < Chunk::SIZE) {
							return getInsideChunk(cx, bkPos);
						} else {
							bkPos.z -= Chunk::SIZE;
							return getInsideChunk(cxz, bkPos);
						}
					} else {
						bkPos.z += Chunk::SIZE;
						return getInsideChunk(cxmz, bkPos);
					}
				} else {
					bkPos.y -= Chunk::SIZE;
					
					if (bkPos.z >= 0) {
						if (bkPos.z < Chunk::SIZE) {
							return getInsideChunk(cxy, bkPos);
						} else {
							bkPos.z -= Chunk::SIZE;
							return getInsideChunk(cxyz, bkPos);
						}
					} else {
						bkPos.z += Chunk::SIZE;
						return getInsideChunk(cxymz, bkPos);
					}
				}
			} else {
				bkPos.y += Chunk::SIZE;
				
				if (bkPos.z >= 0) {
					if (bkPos.z < Chunk::SIZE) {
						return getInsideChunk(cxmy, bkPos);
					} else {
						bkPos.z -= Chunk::SIZE;
						return getInsideChunk(cxmyz, bkPos);
					}
				} else {
					bkPos.z += Chunk::SIZE;
					return getInsideChunk(cxmymz, bkPos);
				}
			}
			
			
		}
	} else { // x < 0
		
		bkPos.x += Chunk::SIZE;
		
		if (bkPos.y >= 0) {
			if (bkPos.y < Chunk::SIZE) {
				if (bkPos.z >= 0) {
					if (bkPos.z < Chunk::SIZE) {
						return getInsideChunk(cmx, bkPos);
					} else {
						bkPos.z -= Chunk::SIZE;
						return getInsideChunk(cmxz, bkPos);
					}
				} else {
					bkPos.z += Chunk::SIZE;
					return getInsideChunk(cmxmz, bkPos);
				}
			} else {
				bkPos.y -= Chunk::SIZE;
				
				if (bkPos.z >= 0) {
					if (bkPos.z < Chunk::SIZE) {
						return getInsideChunk(cmxy, bkPos);
					} else {
						bkPos.z -= Chunk::SIZE;
						return getInsideChunk(cmxyz, bkPos);
					}
				} else {
					bkPos.z += Chunk::SIZE;
					return getInsideChunk(cmxymz, bkPos);
				}
			}
		} else {
			bkPos.y += Chunk::SIZE;
			
			if (bkPos.z >= 0) {
				if (bkPos.z < Chunk::SIZE) {
					return getInsideChunk(cmxmy, bkPos);
				} else {
					bkPos.z -= Chunk::SIZE;
					return getInsideChunk(cmxmyz, bkPos);
				}
			} else {
				bkPos.z += Chunk::SIZE;
				return getInsideChunk(cmxmymz, bkPos);
			}
		}
		
	}
	
	return mManager.getNoBlock();
}
