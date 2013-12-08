#ifndef SIGNALABLEBLOCK_HPP
#define SIGNALABLEBLOCK_HPP

#include "../Block/ComplexBlock.hpp"
#include <iostream>

#define MAX_SLOTS 6


namespace Signal {
	
	
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
			virtual void welcomeToWorld(SignalableBlock * ne[]);
			
			virtual bool helloIwantToConnect(SignalableBlock * b, int from);
			
			virtual void send(int from);
			
			virtual ~SignalableBlock();
			
		protected:
			
			SignalableBlock * mNei[MAX_SLOTS];
			
			bool mHasSignal;
	};

}

#endif // SIGNALABLEBLOCK_HPP
