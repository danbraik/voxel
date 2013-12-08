#include "BlockCxWire.hpp"
#include "../Render/MeshVertex.hpp"


#include "../VectorTools.hpp"

using namespace VectorTools;

BlockCxWire::BlockCxWire()
{
}



void BlockCxWire::build(MeshVertexVector &vertices, const sf::Vector3f &pos, 
						const Block &right, 
						const Block &behind, 
						const Block &left, 
						const Block &front, 
						const Block &top, const Block &bottom) const
{
	
	const BlockCxElec * wr = dynamic_cast<const BlockCxElec*>(&right);
	const BlockCxElec * wbe = dynamic_cast<const BlockCxElec*>(&behind);
	const BlockCxElec * wl = dynamic_cast<const BlockCxElec*>(&left);
	const BlockCxElec * wf = dynamic_cast<const BlockCxElec*>(&front);
	const BlockCxElec * wt = dynamic_cast<const BlockCxElec*>(&top);
	const BlockCxElec * wbo = dynamic_cast<const BlockCxElec*>(&bottom);
	
	
	if (wr) {
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
	
	
	if (wbe) {
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
	
	
	
	
	
	if (wl) {
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
	
	
	if (wf) {
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
	
	if (wt) {
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
	
	if (wbo) {
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
