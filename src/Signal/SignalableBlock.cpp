#include "SignalableBlock.hpp"

using namespace Signal;

SignalableBlock::SignalableBlock() : mHasSignal(false), mNei()
{
}

void SignalableBlock::welcomeToWorld(SignalableBlock *nei[])
{
	
}

bool SignalableBlock::helloIwantToConnect(SignalableBlock *b, int from)
{
	if (b != 0) {
		mNei[from] = b;
		if (mHasSignal)
			mNei[from]->send((from+3)%MAX_SLOTS);
	
		return true;
	}
	return false;
}



void SignalableBlock::send(int from)
{
	mHasSignal = true;
}

SignalableBlock::~SignalableBlock()
{
}
