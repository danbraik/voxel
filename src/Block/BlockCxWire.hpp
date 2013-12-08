#ifndef BLOCKCXWIRE_HPP
#define BLOCKCXWIRE_HPP

#include "BlockCxElec.hpp".hpp"

class BlockCxWire : public BlockCxElec
{
	public:
		BlockCxWire();
		
		virtual void build(MeshVertexVector &vertices, 
					  const sf::Vector3f &pos, 
					  const Block &right, 
					  const Block &behind, 
					  const Block &left, 
					  const Block &front, 
					  const Block &top, 
					  const Block &bottom) const;
};

#endif // BLOCKCXWIRE_HPP
