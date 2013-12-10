#ifndef SIGNALW_HPP
#define SIGNALW_HPP

#include <list>
#include <queue>

namespace Signal {
	
	
	class SignalW
	{
			
			static int nextId;
		public:
			static SignalW newSignal() {
				nextId += 7;
				nextId *= 11;
				return SignalW(nextId);
			}
			SignalW(int id = -1, int force = 12);
			int id;
			
			int force;
			
			int slotFrom;
	};
	
	struct PairSlotSignalW {
			SignalW signal;
			int localSlot;
	};
	
	
	typedef std::list<SignalW> SignalList;
	typedef std::queue<PairSlotSignalW> SlotSignalQueue;

}

#endif // SIGNAL_HPP
