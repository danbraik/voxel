#ifndef ANDLOGIC_HPP
#define ANDLOGIC_HPP

#include "../Block/ComplexBlock.hpp"
#include "SignalableBlock.hpp"

namespace Signal {

	class AndLogic : public SignalableBlock, public ComplexBlock
	{
		public:
			AndLogic();
			
			virtual void build(MeshVertexVector &vertices, const sf::Vector3f &pos, const Block &right, const Block &behind, const Block &left, const Block &front, const Block &top, const Block &bottom) const;
	};

}

#endif // ANDLOGIC_HPP
