#include "SignalableBlock.hpp"

#include "SignalManager.hpp"

using namespace Signal;

#define COUT std::cout<<this<<
#define END <<std::endl


SignalableBlock::SignalableBlock() : mNeig()
{
}



inline int convertSlot(int slot) {
	return (slot+3)%MAX_SLOTS;
}



void SignalableBlock::welcomeToWorld(SignalManager & manager, std::vector<PairFromNei> & nei)
{
	COUT " borned" END;
	
	for(std::vector<PairFromNei>::iterator it = nei.begin();
		it != nei.end(); ++it) 
	 {
		PairFromNei & spair = *it;
		if (isAcceptable(spair.nei)) {
			spair.remoteSlot = convertSlot(spair.localSlot);
			if(spair.nei->helloIwantToConnect(manager, this, spair.remoteSlot)) {
				mNeig.push_back(spair);
				COUT "     co to " << spair.nei END;
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
	for(PairFromNeiList::const_iterator it = mNeig.begin();
		it != mNeig.end(); ++it)
		if ((*it).localSlot == localSlot){
			std::cerr << "Slot already taken : "<<localSlot<<std::endl;
			return false;
		}
	
	if (isAcceptable(me)) {// strategy part of the algo
		// acceptability depends on real type
		
		PairFromNei pair;
		pair.localSlot = localSlot;
		pair.remoteSlot = convertSlot(localSlot);
		pair.nei = me;
		mNeig.push_back(pair);
		
		// send signals
		for (SignalList::const_iterator it=mSignals.begin();
		it != mSignals.end(); ++it) {
			SignalW s;
			s.id = it->id;
			s.force = it->force-1;
			
			if (mNeig.size() <= 2)
				me->notify(pair.remoteSlot, s);
			else {
				//s.id += pair.localSlot;
				me->notify(pair.remoteSlot, s);
			}
		}
		return true;
	}
	return false;
}

void SignalableBlock::sayByeToWorld(SignalManager &manager)
{
	// send no more signal
	// disconnect
	for(PairFromNeiList::iterator it=mNeig.begin();
		it!=mNeig.end();++it) {
		
		PairFromNei & pairNei = *it;
		
//		for(SignalList::iterator its = mSignals.begin();
//			its!=mSignals.end(); ++its) {
			
//			SignalW s = *its;
//			s.id = s.id + pairNei.localSlot;
//			s.force = 0;
			
//			if (s.slotFrom != pairNei.localSlot) {
//				pairNei.nei->notify(pairNei.remoteSlot, s);
//			}
//		}
		
		
		pairNei.nei->byeIwantTodisconnect(this);
		manager.addToUpdate(pairNei.nei);
	}
	COUT " quit the world" END;
	
	iAmGone(manager);
}

void SignalableBlock::byeIwantTodisconnect(SignalableBlock *me)
{
	int localSlot = -1;
	for(PairFromNeiList::iterator it=mNeig.begin();
		it!=mNeig.end();) {
		
		PairFromNei pair = *it;
		
		if (pair.nei == me) {
			it = mNeig.erase(it);
			localSlot = pair.localSlot;
			
			
			
			break;
		}
		else
			++it;
	}
	if (localSlot < 0)
		return;
	
	for (SignalList::iterator it=mSignals.begin();
		 it != mSignals.end();++it) {
		
		SignalW s = *it;
		
		if (s.slotFrom == localSlot) {
			it = mSignals.erase(it); --it;
			
			// send no more sign
			for(PairFromNeiList::iterator itp=mNeig.begin();
				itp!=mNeig.end();++itp) {
				PairFromNei pair = *itp;
				
				s.force = 0;
				pair.nei->notify(pair.remoteSlot, s);
				
			}
		}
		
	}
}



void SignalableBlock::notify(int slot, SignalW signal)
{
	
	std::cout << this << " notified        (" << signal.id << ", "<<signal.force
			  << ")" << std::endl;
	
	PairSlotSignalW pss;
	pss.localSlot = slot;
	pss.signal = signal;
	pss.signal.slotFrom = slot;
	mToTreat.push(pss);
		
}

void SignalableBlock::sendToNeighboursExceptOne(int exceptSlot, const SignalW &signal) const
{
}




bool SignalableBlock::update(SignalManager & manager)
{
	while (!mToTreat.empty()) {
	
		PairSlotSignalW pss = mToTreat.front();
		const int & slot = pss.localSlot;
		SignalW & signal = pss.signal;
		
		if (signal.force == 0) {// have to delete
			for (SignalList::iterator it = mSignals.begin();
				 it != mSignals.end();) {
				if (/*(*it).id == signal.id &&*/ it->slotFrom == slot) // test origin
					it = mSignals.erase(it);
				else
					++it;
			}
			
		} else {// test if already have?
			mSignals.push_back(signal);
			signal.force--;
		}
		
		//notify others
		switch(mNeig.size()) {
			case 0:
			case 1:
				if (signal.force == 0) {
					PairFromNei & pair = mNeig.front();
					if (pair.localSlot != signal.slotFrom) {
						pair.nei->notify(pair.remoteSlot, signal);
						manager.addToUpdate(pair.nei);
					}
				}
				break;
			case 2:
				for(PairFromNeiList::const_iterator it=mNeig.begin();
					it!=mNeig.end();++it) {
					const PairFromNei & pair = *it;
					if (pair.localSlot != slot) {
						pair.nei->notify(pair.remoteSlot, signal);
						manager.addToUpdate(pair.nei);
						break;
					}
				}
				break;
			default:{
				for(PairFromNeiList::const_iterator it=mNeig.begin();
					it!=mNeig.end();++it) {
					const PairFromNei & pair = *it;
					
					if (pair.localSlot != slot) {
						SignalW si;
						si.id = signal.id;// + pair.localSlot;
						si.force = signal.force;
						si.slotFrom = pair.localSlot;
					
						pair.nei->notify(pair.remoteSlot, si);// bug : collision id?
						manager.addToUpdate(pair.nei);
					}
				}
			}
		}
		
		mToTreat.pop();
	}
	
	return cycle(manager);
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


