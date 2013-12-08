#ifndef BLOCKCXELEC_HPP
#define BLOCKCXELEC_HPP

#include "ComplexBlock.hpp"

class BlockCxElec : public ComplexBlock
{
	public:
		BlockCxElec();
		
		
	protected:
		float r,g,b,a;
};

#endif // BLOCKCXELEC_HPP
