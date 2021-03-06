#ifndef POWER_HPP
#define POWER_HPP

#include "../Block/SimpleBlock.hpp"
#include "SignalableBlock.hpp"

namespace Signal {
	
	class Power : public SignalableBlock, public SimpleBlock
	{
		public:
			Power();
			
			virtual bool isAcceptable(SignalableBlock *him, int slot) const {return true;}
			
			virtual bool cycle(SignalManager & manager);
			
			~Power();
			
		private:
			enum {WILL_POWER, HAS_POWERED};
			int state;
	};

}
	
#endif // POWER_HPP
