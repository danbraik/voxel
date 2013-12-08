#ifndef POWER_HPP
#define POWER_HPP

#include "../Block/SimpleBlock.hpp"
#include "SignalableBlock.hpp"

namespace Signal {
	
	class Power : public SignalableBlock, public SimpleBlock
	{
		public:
			Power();
			
			virtual void welcomeToWorld(SignalableBlock *neid[]);
			
			void update();
			
			~Power();
	};

}
	
#endif // POWER_HPP
