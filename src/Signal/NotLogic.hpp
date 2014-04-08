#ifndef NotLogic_HPP
#define NotLogic_HPP

#include "../Block/ComplexBlock.hpp"
#include "SignalableBlock.hpp"

namespace Signal {

	class NotLogic : public SignalableBlock, public ComplexBlock
	{
		public:
			NotLogic();
			
			virtual void build(MeshVertexVector &vertices, const sf::Vector3f &pos, const Block &right, const Block &behind, const Block &left, const Block &front, const Block &top, const Block &bottom) const;
			
			virtual bool isAcceptable(SignalableBlock *him, int slot) const;
			
			virtual bool cycle(SignalManager &manager);
	};

}

#endif // NotLogic_HPP
