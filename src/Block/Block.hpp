#ifndef BLOCK_HPP
#define BLOCK_HPP

#include <SFML/System.hpp>
#include <iostream>

#include "../Render/Mesh.hpp"
#include "../Render/MeshVertex.hpp"

//#define DEV

#ifdef DEV
	class ChunkCoordinate : public sf::Vector3i {public:ChunkCoordinate(){}ChunkCoordinate(int x, int y, int z):sf::Vector3i(x,y,z){}};
	class BlockCoordinate : public sf::Vector3i {public:BlockCoordinate(){}BlockCoordinate(int x, int y, int z):sf::Vector3i(x,y,z){}};
#else	
	typedef sf::Vector3i ChunkCoordinate;
	typedef sf::Vector3i BlockCoordinate;
#endif

//typedef sf::Int32 BlockType;

class Block
{
	public:
		//static const float SIZE = 1.f;
		
		// de-activated
		//static const Block NONEblk;
		
//		static const BlockType AIR = 0;//must be 0 (because of memset)
//		static const BlockType NONE = 1;
//		// activated
//		static const BlockType ACTIVATED = 2;
//		static const BlockType Dirt = 10;
//		static const BlockType Stone = 11;
//		static const BlockType Water = 12;
//		static const BlockId WireOff = 20;
//		static const BlockId WireOn = 21;
//		static const BlockId Power = 22;

	public:	
		
//		Block();
		
		bool isActivated() const;
		bool isFilled() const;
		
		virtual void build(MeshVertexVector & vertices, const sf::Vector3f &pos,
				   const Block &right, const Block &behind,
				   const Block &left, const Block &front, const Block &top, 
						   const Block &bottom) const = 0;
		
		virtual ~Block();
		
	protected:
		Block(bool activated = false, bool filled = false);
		void setActivated(bool activated);
		
		void addVertex(MeshVertexVector & vertices,
					   const sf::Vector3f & norm,
					   float r, float g, float b, float a,
					   const sf::Vector3f & pos) const;
		void addVertex(MeshVertexVector & vertices,
					   const sf::Vector3f & norm,
					   const sf::Vector3f & pos,
					   float r, float g, float b, float a) const;
		
	private:
		bool mIsActivated;
		bool mIsFilled;
		
};


inline bool Block::isActivated() const {
	return mIsActivated;
}

inline void Block::setActivated(bool activated) {
	mIsActivated = activated;
}


inline bool Block::isFilled() const {
	return mIsFilled;
}


inline void Block::addVertex(MeshVertexVector & vertices, 
			   const sf::Vector3f & n,
			   float r, float g, float b, float a,
			   const sf::Vector3f & pos) const {
	vertices.push_back(MeshVertex(pos, n, r, g, b, a));
}

inline void Block::addVertex(MeshVertexVector &vertices, const sf::Vector3f &norm, const sf::Vector3f &pos, float r, float g, float b, float a) const
{
	addVertex(vertices, norm, r, g, b,a,pos);
}


#endif // BLOCK_HPP
