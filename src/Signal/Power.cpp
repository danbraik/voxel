#include "Power.hpp"

#include "SignalManager.hpp"
using namespace Signal;

Power::Power() : SignalableBlock(), SimpleBlock(1.,1.,1.)
{
	state = WILL_POWER;
	SignalW s = SignalW::newSignal();
	
	mSignals.push_back(s);
}

void Power::iAmConnected(SignalManager & manager)
{
	for(PairFromNeiList::iterator it = mNeig.begin();
		it!=mNeig.end();++it) {
		it->nei->notify(it->remoteSlot, mSignals.front());
		manager.addToUpdate(it->nei);
	}
}



bool Power::cycle(SignalManager & manager)
{
	return false;
}

Power::~Power()
{
}
