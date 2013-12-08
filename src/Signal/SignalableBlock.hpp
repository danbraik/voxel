#ifndef SIGNALABLEBLOCK_HPP
#define SIGNALABLEBLOCK_HPP

#include "../Block/ComplexBlock.hpp"

namespace Signal {

	class SignalableBlock : public ComplexBlock
	{
		public:
			SignalableBlock();
			
			enum {WHITE/*universal*/, RED, GREEN, BLUE};			
			
			virtual int getColor() const {
				return WHITE;
			}
	};

}

#endif // SIGNALABLEBLOCK_HPP
