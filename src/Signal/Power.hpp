#ifndef POWER_HPP
#define POWER_HPP

#include "../Block/SimpleBlock.hpp"
#include "SignalableBlock.hpp"

namespace Signal {
	
	class Power : public SignalableBlock, public SimpleBlock
	{
		public:
			Power();
	};

}
	
#endif // POWER_HPP
