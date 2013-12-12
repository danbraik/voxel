#include "SignalableBlock.hpp"

#include "SignalManager.hpp"

using namespace Signal;

#define COUT std::cout<<this<<" "<<
#define END <<std::endl


SignalableBlock::SignalableBlock() : mSockets(), mInSignals(), mNeedUpdate(true)
{
	for(int i=0;i<MAX_SLOTS;++i){
		mInSignals[i]=false;
		mOutSignals[i]=false;
	}
}



inline int convertSlot(int slot) {
	return (slot+3)%MAX_SLOTS;
}



void SignalableBlock::welcomeToWorld(SignalManager & manager, std::vector<Socket> & nei)
{
	COUT " borned" END;
	
	for(std::vector<Socket>::iterator it = nei.begin();
		it != nei.end(); ++it) {
		
		Socket & spair = *it;
		if (isAcceptable(spair.node, spair.lslot)) {
			spair.rslot = convertSlot(spair.lslot);
			if(spair.node->helloIwantToConnect(manager, this, spair.rslot)) {
				mSockets[spair.lslot].reset(spair.lslot, spair.rslot, spair.node);
				
				COUT "     co to " << spair.node END;
			}
		}
	}
	
	COUT "   co s" END;
	for(int i=0;i<MAX_SLOTS;++i)
		COUT "    [" <<i<<"] = "<<mSockets[i].isValid END;
	
	iAmConnected(manager);
}


bool SignalableBlock::helloIwantToConnect(SignalManager &manager,SignalableBlock *me, int localSlot)
{
	if (me == 0)
		return false;
	if (localSlot >= MAX_SLOTS)
		return false;
	// test if slot is taken
	if (getSocket(localSlot) != 0) {
		std::cerr << "Slot already taken : "<<localSlot<<std::endl;
		return false;
	}
	
	if (isAcceptable(me, localSlot)) {// strategy part of the algo
		// acceptability depends on real type
		
		mSockets[localSlot].reset(localSlot, convertSlot(localSlot), me);
		
		// send current signal
		me->notify(mSockets[localSlot].rslot, mOutSignals[localSlot]);
		manager.addToUpdate(me);
		
		return true;
	}
	return false;
}

void SignalableBlock::sayByeToWorld(SignalManager &manager)
{
	COUT " quit the world" END;
	
	
	// disconnect
	for(int i=0;i<MAX_SLOTS;++i) {
		if (mSockets[i].isValid) {
			Socket & pairNei = mSockets[i];
			
			COUT " deco from " << pairNei.node END;
			
			pairNei.node->byeIwantTodisconnect(pairNei.rslot, this);
			manager.addToUpdate(pairNei.node);
		}
	}
	
	
	iAmGone(manager);
}

void SignalableBlock::byeIwantTodisconnect(InSlot lslot, SignalableBlock *me)
{
	mInSignals[lslot] = false;
	
	Socket * s = getSocket(lslot);
	if (!s || s->node != me) {
		std::cerr << "Error from disconnect" << std::endl;
		return;
	}
		
	mNeedUpdate = true;
	
	
	
	// prevent Use after free
	s = 0;
	
	mSockets[lslot].isValid = false;
}




void SignalableBlock::notify(InSlot slot, bool signal)
{
	COUT " notified from " << slot << " = " << signal END;
	
	mInSignals[slot] = signal;
	
	mNeedUpdate = true;
}




bool SignalableBlock::isOn(InSlot slot) const
{
	return mInSignals[slot];
}

bool SignalableBlock::signal(InSlot slot) const
{
	return mInSignals[slot];
}




void SignalableBlock::set(OutSlot slot, bool state)
{
	mOutSignals[slot] = state;
}


void SignalableBlock::setOff(OutSlot slot)
{
	set(slot, false);
}

Socket * SignalableBlock::getSocket(LSlot lslot)
{
	if (mSockets[lslot].isValid)
		return &mSockets[lslot];
	return 0;
}

bool SignalableBlock::hasNeighbour(LSlot lslot) const
{
	return mSockets[lslot].isValid;
}



void SignalableBlock::setOn(OutSlot slot)
{
	set(slot, true);
}





bool SignalableBlock::update(SignalManager & manager)
{
//	if (!mNeedUpdate)
//		return false;
	
	COUT "update" END;
	
	bool mOldOutSignals[MAX_SLOTS];
	for(int i=0;i<MAX_SLOTS;++i) {
		mOldOutSignals[i] = mOutSignals[i];
		mOutSignals[i] = false;
		COUT "IN slot(" << i << ") = " << mInSignals[i] END;
	}
	
	bool retcycle = cycle(manager);
	
	
	for(int i=0;i<MAX_SLOTS;++i) {
		COUT "OUT slot(" << i << ") = " << mOldOutSignals[i] << " -> " <<  mOutSignals[i] END;
	}
	
	for(int i=0;i<MAX_SLOTS;++i) {
		if (mOldOutSignals[i] != mOutSignals[i]) { // new output
			Socket * s = getSocket(i);
			if (s && s->isValid) {
				s->node->notify(s->rslot, mOutSignals[i]);
				manager.addToUpdate(s->node);
			}
		}
	}
	
	
	mNeedUpdate = false;
	
	return retcycle;
}

SignalableBlock::~SignalableBlock()
{
}

void SignalableBlock::iAmConnected(SignalManager &manager)
{
}

void SignalableBlock::iAmGone(SignalManager &manager)
{
}

bool SignalableBlock::cycle(SignalManager &manager)
{
}






