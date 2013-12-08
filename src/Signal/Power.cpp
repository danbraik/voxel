#include "Power.hpp"

using namespace Signal;

Power::Power() : SignalableBlock(), SimpleBlock(1.,1.,1.)
{
	mHasSignal = true;
}

void Power::welcomeToWorld(SignalableBlock *nei[])
{
	for (int i=0;i<MAX_SLOTS;++i) {
		if(nei[i] && nei[i]->helloIwantToConnect(this, (i+3)%MAX_SLOTS)) {
			mNei[i] = nei[i];
		}
	}
}

void Power::update()
{
	for (int i=0;i<MAX_SLOTS;++i) {
		if (mNei[i])
			mNei[i]->send((i+3)%MAX_SLOTS);
	}
}

Power::~Power()
{
}
