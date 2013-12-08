#ifndef WIRE_HPP
#define WIRE_HPP

#include "SignalableBlock.hpp"

namespace Signal {
	
	class Wire : public SignalableBlock
	{
		public:
			
			Wire(int color = RED);
			
			virtual int getColor() const {
				return mColor;
			}
			
			virtual void build(MeshVertexVector &vertices, 
						  const sf::Vector3f &pos, 
						  const Block &right, 
						  const Block &behind, 
						  const Block &left, 
						  const Block &front, 
						  const Block &top, 
						  const Block &bottom) const;
		
		protected:
			bool blockIsOk(const SignalableBlock * sb) const;
		private:
			bool hasSignal;
			int mColor;
	};
	

}

#endif // WIRE_HPP
