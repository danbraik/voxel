#include "Wire.hpp"


#include "../VectorTools.hpp"

using namespace VectorTools;

using namespace Signal;

Wire::Wire(int color) : SignalableBlock(),
	hasSignal(false),
	mColor(color)
{
}


inline bool Wire::blockIsOk(const SignalableBlock * sb) const {
	// connect if block has same color, or it's white (== universal)
	// or if itself is white
	return (sb == 0) ? false : 
					   mColor == WHITE || 
					   sb->getColor() == WHITE || 
					   sb->getColor() == mColor;
}


void Wire::build(MeshVertexVector &vertices, const sf::Vector3f &pos, 
						const Block &right, 
						const Block &behind, 
						const Block &left, 
						const Block &front, 
						const Block &top, const Block &bottom) const
{
	float r=.0,g=.0,b=.0,a=1.;
	switch(mColor) {
		case RED:
			r =.6;
			break;
		case GREEN:
			g=.6;
			break;
		case BLUE:
			b=.6;
			break;
		case WHITE:
			r = .6; g =.6 ; b =.6 ;
			break;
	}
	if (hasSignal) {
		r*=1.6;g*=1.6;b*=1.6;
	}
	const SignalableBlock * wr = dynamic_cast<const SignalableBlock*>(&right);
	const SignalableBlock * wbe = dynamic_cast<const SignalableBlock*>(&behind);
	const SignalableBlock * wl = dynamic_cast<const SignalableBlock*>(&left);
	const SignalableBlock * wf = dynamic_cast<const SignalableBlock*>(&front);
	const SignalableBlock * wt = dynamic_cast<const SignalableBlock*>(&top);
	const SignalableBlock * wbo = dynamic_cast<const SignalableBlock*>(&bottom);
	
	
	if (blockIsOk(wr)) {
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 1.000000,0.666667,0.333333));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 1.000000,0.333333,0.333333));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.666667,0.333334,0.333333));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.666667,0.333334,0.333333));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.666667,0.666667,0.333333));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 1.000000,0.666667,0.333333));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 1.000000,0.666666,0.666667));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.666667,0.666667,0.666667));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.666666,0.333334,0.666667));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.666666,0.333334,0.666667));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.999999,0.333333,0.666667));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 1.000000,0.666666,0.666667));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 1.000000,0.333333,0.333333));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.999999,0.333333,0.666667));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.666666,0.333334,0.666667));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.666666,0.333334,0.666667));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.666667,0.333334,0.333333));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 1.000000,0.333333,0.333333));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 1.000000,0.666666,0.666667));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 1.000000,0.666667,0.333333));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.666667,0.666667,0.333333));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.666667,0.666667,0.333333));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.666667,0.666667,0.666667));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 1.000000,0.666666,0.666667));		
	} else {
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.666667,0.666667,0.333333));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.666667,0.666666,0.666667));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.666666,0.333333,0.666667));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.666666,0.333333,0.666667));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.666667,0.333333,0.333333));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.666667,0.666667,0.333333));
	}
	
	
	if (blockIsOk(wbe)) {
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.333333,1.000000,0.333333));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.666667,1.000000,0.333333));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.666667,0.666667,0.333333));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.666667,0.666667,0.333333));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.333333,0.666667,0.333333));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.333333,1.000000,0.333333));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.333334,1.000000,0.666667));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.333333,0.666667,0.666667));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.666666,0.666666,0.666667));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.666666,0.666666,0.666667));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.666667,0.999999,0.666667));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.333334,1.000000,0.666667));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.666667,1.000000,0.333333));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.666667,0.999999,0.666667));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.666666,0.666666,0.666667));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.666666,0.666666,0.666667));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.666667,0.666667,0.333333));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.666667,1.000000,0.333333));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.333334,1.000000,0.666667));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.333333,1.000000,0.333333));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.333333,0.666667,0.333333));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.333333,0.666667,0.333333));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.333333,0.666667,0.666667));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.333334,1.000000,0.666667));
		
	} else {
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.666667,0.666666,0.666667));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.666667,0.666667,0.333333));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.333334,0.666667,0.333333));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.333334,0.666667,0.333333));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.333333,0.666667,0.666667));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.666667,0.666666,0.666667));
				
	}
	
	
	
	
	
	if (blockIsOk(wl)) {
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.000001,0.333333,0.333333));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.000000,0.666666,0.333333));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.333333,0.666667,0.333333));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.333333,0.666667,0.333333));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.333333,0.333333,0.333333));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.000001,0.333333,0.333333));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.000000,0.333334,0.666667));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.333333,0.333333,0.666667));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.333334,0.666666,0.666667));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.333334,0.666666,0.666667));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.000001,0.666667,0.666667));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.000000,0.333334,0.666667));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.000000,0.666666,0.333333));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.000001,0.666667,0.666667));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.333334,0.666666,0.666667));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.333334,0.666666,0.666667));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.333333,0.666667,0.333333));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.000000,0.666666,0.333333));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.000000,0.333334,0.666667));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.000001,0.333333,0.333333));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.333333,0.333333,0.333333));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.333333,0.333333,0.333333));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.333333,0.333333,0.666667));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.000000,0.333334,0.666667));
				
	} else {
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.333333,0.333334,0.333333));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.333333,0.333334,0.666667));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.333333,0.666667,0.666667));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.333333,0.666667,0.666667));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.333334,0.666667,0.333333));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.333333,0.333334,0.333333));
				
	}
	
	
	if (blockIsOk(wf)) {
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.666667,0.000000,0.333333));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.333333,0.000000,0.333333));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.333333,0.333333,0.333333));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.333333,0.333333,0.333333));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.666667,0.333333,0.333333));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.666667,0.000000,0.333333));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.666666,0.000000,0.666667));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.666667,0.333333,0.666667));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.333334,0.333334,0.666667));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.333334,0.333334,0.666667));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.333333,0.000001,0.666667));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.666666,0.000000,0.666667));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.333333,0.000000,0.333333));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.333333,0.000001,0.666667));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.333334,0.333334,0.666667));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.333334,0.333334,0.666667));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.333333,0.333333,0.333333));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.333333,0.000000,0.333333));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.666666,0.000000,0.666667));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.666667,0.000000,0.333333));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.666667,0.333333,0.333333));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.666667,0.333333,0.333333));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.666667,0.333333,0.666667));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.666666,0.000000,0.666667));
		
	} else {
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.666667,0.333333,0.333333));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.666666,0.333333,0.666667));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.333333,0.333334,0.666667));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.333333,0.333334,0.666667));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.333333,0.333334,0.333333));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.666667,0.333333,0.333333));
				
	}
	
	if (blockIsOk(wt)) {
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.666667,0.666666,0.999999));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.666667,0.333333,0.999999));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.666666,0.333333,0.666666));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.666666,0.333333,0.666666));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.666666,0.666667,0.666667));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.666667,0.666666,0.999999));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.333334,0.666666,1.000000));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.333333,0.666667,0.666667));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.333333,0.333334,0.666667));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.333333,0.333334,0.666667));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.333334,0.333333,1.000000));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.333334,0.666666,1.000000));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.666667,0.333333,0.999999));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.333334,0.333333,1.000000));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.333333,0.333334,0.666667));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.333333,0.333334,0.666667));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.666666,0.333333,0.666666));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.666667,0.333333,0.999999));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.333334,0.666666,1.000000));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.666667,0.666666,0.999999));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.666666,0.666667,0.666667));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.666666,0.666667,0.666667));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.333333,0.666667,0.666667));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.333334,0.666666,1.000000));
		
	} else {
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.666667,0.666666,0.666667));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.333333,0.666667,0.666667));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.333333,0.333334,0.666667));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.333333,0.333334,0.666667));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.666666,0.333333,0.666667));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.666667,0.666666,0.666667));
				
	}
	
	if (blockIsOk(wbo)) {
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.333333,0.666667,0.000000));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.333334,0.333334,0.000000));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.333333,0.333334,0.333333));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.333333,0.333334,0.333333));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.333333,0.666667,0.333333));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.333333,0.666667,0.000000));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.666667,0.666667,0.000000));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.666666,0.666667,0.333333));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.666667,0.333334,0.333334));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.666667,0.333334,0.333334));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.666667,0.333333,0.000001));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.666667,0.666667,0.000000));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.333334,0.333334,0.000000));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.666667,0.333333,0.000001));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.666667,0.333334,0.333334));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.666667,0.333334,0.333334));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.333333,0.333334,0.333333));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.333334,0.333334,0.000000));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.666667,0.666667,0.000000));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.333333,0.666667,0.000000));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.333333,0.666667,0.333333));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.333333,0.666667,0.333333));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.666666,0.666667,0.333333));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.666667,0.666667,0.000000));
	} else {
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.666667,0.666667,0.333333));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.666667,0.333333,0.333333));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.333333,0.333334,0.333333));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.333333,0.333334,0.333333));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.333334,0.666667,0.333333));
		addVertex(vertices, EXf, r, g, b, a, pos + sf::Vector3f( 0.666667,0.666667,0.333333));				
	}
	
}