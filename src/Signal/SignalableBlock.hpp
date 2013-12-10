#ifndef SIGNALABLEBLOCK_HPP
#define SIGNALABLEBLOCK_HPP

#include "../Block/ComplexBlock.hpp"
#include "SignalW.hpp"
#include <iostream>

#define MAX_SLOTS 6


namespace Signal {

	class SignalManager;
	class SignalableBlock;
	
	struct PairFromNei {
			int localSlot;
			int remoteSlot;
			SignalableBlock * nei;
	};	
	
	class SignalableBlock
	{
		public:
			SignalableBlock();
			
			
			
			enum {WHITE/*universal*/, RED, GREEN, BLUE};			
			enum {X,Y,Z,_X,_Y,_Z};
			
			virtual int getColor() const {
				return WHITE;
			}
			
			// init a component and pass him his neighbours
			void welcomeToWorld(SignalManager &manager, std::vector<PairFromNei> & nei);
			
			
			
			void sayByeToWorld(SignalManager &manage);
			
			
			virtual void notify(int slot, SignalW signal);
			
			
			// return if object has graphically changed
			bool update(SignalManager & manager);
			
			virtual ~SignalableBlock();
			
		protected:
			// true if connect was accepted, false otherwise
			bool helloIwantToConnect(SignalManager &manager,SignalableBlock * me, int localSlot);
			
			void byeIwantTodisconnect(SignalableBlock * me);
			virtual bool isAcceptable(SignalableBlock * him) const = 0;
			virtual void iAmConnected(SignalManager & manager);
			
			virtual void iAmGone(SignalManager &manager);
			
			virtual bool cycle(SignalManager & manager);
			void sendToNeighboursExceptOne(int exceptSlot, const SignalW & signal) const;
			
			
			
			typedef std::list<PairFromNei> PairFromNeiList;
			
			PairFromNeiList mNeig;
			
			SignalList mSignals;
			SlotSignalQueue mToTreat;
			
			
			
	};

	
	
	
}

#endif // SIGNALABLEBLOCK_HPP
