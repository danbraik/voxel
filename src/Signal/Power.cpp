#include "Power.hpp"

#include "SignalManager.hpp"
using namespace Signal;

Power::Power() : SignalableBlock(), SimpleBlock(1.,1.,1.)
{

}

void Power::iAmConnected(SignalManager & manager)
{
	
}



bool Power::cycle(SignalManager & manager)
{
	for(OutSlot i = 0; i < MAX_SLOTS; ++i)
		setOn(i);
	
	return false;
}

Power::~Power()
{
}
