#ifndef SIGNALABLEBLOCK_HPP
#define SIGNALABLEBLOCK_HPP

#include "../Block/ComplexBlock.hpp"

#include <list>
#include <iostream>

#define MAX_SLOTS 6



namespace Signal {

	class SignalManager;
	class SignalableBlock;
	
	typedef int InSlot;
	typedef int OutSlot;
	typedef int LSlot; // local
	typedef int RSlot; // remote
	
	struct Socket {
			OutSlot lslot;
			
			InSlot rslot;
			SignalableBlock * node;
			
			// local slot,
			// remote slot
			Socket(OutSlot lslot, InSlot rslot, SignalableBlock * node) {
				this->lslot = lslot;
				this->rslot = rslot;
				this->node = node;
			}
			
			Socket() {
				this->lslot = -1;
				this->rslot = -1;
				this->node = 0;
			}
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
			void welcomeToWorld(SignalManager &manager, std::vector<Socket> & nei);
			
			
			
			void sayByeToWorld(SignalManager &manage);
			
			
			void notify(InSlot slot, bool signal);
			
			
			// return if object has graphically changed
			bool update(SignalManager & manager);
			
			virtual ~SignalableBlock();
			
		protected:
			// true if connect was accepted, false otherwise
			bool helloIwantToConnect(SignalManager &manager,SignalableBlock * me, int localSlot);
			
			void byeIwantTodisconnect(InSlot lslot, SignalableBlock *me);
			virtual bool isAcceptable(SignalableBlock * him, int slot) const = 0;
			virtual void iAmConnected(SignalManager & manager);
			
			virtual void iAmGone(SignalManager &manager);
			
			virtual bool cycle(SignalManager & manager);
			
			
		
			
			bool isOn(InSlot slot) const;
			bool signal(InSlot slot) const;
			
			void setOn(OutSlot slot);
			void setOff(OutSlot slot);
			
			Socket * getSocket(LSlot lslot);
			
			typedef std::list<Socket> SocketList;
			
			SocketList mSockets;
			
			bool mInSignals[MAX_SLOTS];
			bool mOutSignals[MAX_SLOTS];
			
			bool mNeedUpdate;
		
		private:
			void setState(OutSlot slot, bool state);
	};

	
	
	
}

#endif // SIGNALABLEBLOCK_HPP
