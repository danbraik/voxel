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
				mSockets.push_back(spair);
				COUT "     co to " << spair.node END;
			}
		}
	}
	
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
		
		Socket sock(localSlot, convertSlot(localSlot), me);
		
		mSockets.push_back(sock);
		
		// send current signal
		sock.node->notify(sock.rslot, mOutSignals[sock.lslot]);
		manager.addToUpdate(sock.node);
		
		return true;
	}
	return false;
}

void SignalableBlock::sayByeToWorld(SignalManager &manager)
{
	COUT " quit the world" END;
	
	
	// disconnect
	for(SocketList::iterator it=mSockets.begin();
		it!=mSockets.end();++it) {
		
		Socket & pairNei = *it;
		
		COUT " deco from " << pairNei.node END;
		
		pairNei.node->byeIwantTodisconnect(pairNei.rslot, this);
		manager.addToUpdate(pairNei.node);
	}
	
	
	iAmGone(manager);
}

void SignalableBlock::byeIwantTodisconnect(InSlot lslot, SignalableBlock *me)
{
	Socket * s = getSocket(lslot);
	if (!s || s->node != me)
		return;
		
	mNeedUpdate = true;
	
	mInSignals[lslot] = false;
	
	// prevent Use after free
	s = 0;
	
	for(SocketList::iterator it=mSockets.begin();
		it != mSockets.end();++it) {
		
		Socket & sock = *it;
		if (sock.lslot == lslot && sock.node == me) {
			it = mSockets.erase(it);
			break;
		}
	}
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




void SignalableBlock::setState(OutSlot slot, bool state)
{
	mOutSignals[slot] = state;
}


void SignalableBlock::setOff(OutSlot slot)
{
	setState(slot, false);
}

Socket * SignalableBlock::getSocket(LSlot lslot)
{
	for(SocketList::iterator it=mSockets.begin();
		it!=mSockets.end();++it) {
		
		Socket sock = *it;
		
		if (sock.lslot == lslot)
			return &(*it);
	}
	
	return 0;
}



void SignalableBlock::setOn(OutSlot slot)
{
	setState(slot, true);
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
			if (s) {
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






