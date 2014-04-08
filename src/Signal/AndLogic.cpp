#include "AndLogic.hpp"
#include "SignalManager.hpp"
#include "../VectorTools.hpp"

using namespace VectorTools;
using namespace Signal;



AndLogic::AndLogic()
{
}


void AndLogic::build(MeshVertexVector &vertices, const sf::Vector3f &pos, const Block &right, const Block &behind, const Block &left, const Block &front, const Block &top, const Block &bottom) const
{
	float r,g,b,a;
	r=g=b=a=1.;
	

	{
		
		addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  3.33333E-01,  3.33333E-01));
		addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  6.66667E-01,  3.33333E-01));
		addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  6.66667E-01,  1.00000E-01));
		
		addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  6.66667E-01,  1.00000E-01));
		addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  3.33333E-01,  1.00000E-01));
		addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  3.33333E-01,  3.33333E-01));
		
		addVertex(vertices, sf::Vector3f( 9.19144E-01,  3.93921E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.99999E-01,  6.66667E-01,  7.99999E-01));
		addVertex(vertices, sf::Vector3f( 9.19144E-01,  3.93921E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.99999E-01,  6.66667E-01,  6.66666E-01));
		addVertex(vertices, sf::Vector3f( 9.19144E-01,  3.93921E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 7.99999E-01,  8.99999E-01,  6.66666E-01));
		
		addVertex(vertices, sf::Vector3f( 9.19144E-01,  3.93921E-01, -0.00000E+00), r, g, b, a, pos + sf::Vector3f( 7.99999E-01,  8.99999E-01,  6.66666E-01));
		addVertex(vertices, sf::Vector3f( 9.19144E-01,  3.93921E-01, -0.00000E+00), r, g, b, a, pos + sf::Vector3f( 7.99999E-01,  8.99999E-01,  8.99999E-01));
		addVertex(vertices, sf::Vector3f( 9.19144E-01,  3.93921E-01, -0.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.99999E-01,  6.66667E-01,  7.99999E-01));
		
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  3.33333E-01,  1.00000E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  6.66667E-01,  1.00000E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.99999E-01,  6.66667E-01,  1.00000E-01));
		
		addVertex(vertices, sf::Vector3f( 0.00000E+00, -0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.99999E-01,  6.66667E-01,  1.00000E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00, -0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.99999E-01,  3.33333E-01,  1.00000E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00, -0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  3.33333E-01,  1.00000E-01));
		
		addVertex(vertices, sf::Vector3f( 0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  1.00000E-01,  1.00000E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  1.00000E-01,  1.00000E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  1.00000E-01,  3.33333E-01));
		
		addVertex(vertices, sf::Vector3f(-0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  1.00000E-01,  3.33333E-01));
		addVertex(vertices, sf::Vector3f(-0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  1.00000E-01,  3.33333E-01));
		addVertex(vertices, sf::Vector3f(-0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  1.00000E-01,  1.00000E-01));
		
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  3.33333E-01,  1.00000E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  6.66667E-01,  1.00000E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  6.66667E-01,  1.00000E-01));
		
		addVertex(vertices, sf::Vector3f( 0.00000E+00, -0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  6.66667E-01,  1.00000E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00, -0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  3.33333E-01,  1.00000E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00, -0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  3.33333E-01,  1.00000E-01));
		
		addVertex(vertices, sf::Vector3f( 1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.99999E-01,  3.33333E-01,  6.66666E-01));
		addVertex(vertices, sf::Vector3f( 1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.99999E-01,  6.66667E-01,  6.66666E-01));
		addVertex(vertices, sf::Vector3f( 1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.99999E-01,  6.66667E-01,  7.99999E-01));
		
		addVertex(vertices, sf::Vector3f( 1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.99999E-01,  6.66667E-01,  7.99999E-01));
		addVertex(vertices, sf::Vector3f( 1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.99999E-01,  3.33333E-01,  7.99999E-01));
		addVertex(vertices, sf::Vector3f( 1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.99999E-01,  3.33333E-01,  6.66666E-01));
		
		addVertex(vertices, sf::Vector3f( 9.19144E-01,  3.93921E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.99999E-01,  6.66667E-01,  3.33333E-01));
		addVertex(vertices, sf::Vector3f( 9.19144E-01,  3.93921E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.99999E-01,  6.66667E-01,  1.00000E-01));
		addVertex(vertices, sf::Vector3f( 9.19144E-01,  3.93921E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 7.99999E-01,  8.99999E-01,  1.00000E-01));
		
		addVertex(vertices, sf::Vector3f( 9.19144E-01,  3.93921E-01, -0.00000E+00), r, g, b, a, pos + sf::Vector3f( 7.99999E-01,  8.99999E-01,  1.00000E-01));
		addVertex(vertices, sf::Vector3f( 9.19144E-01,  3.93921E-01, -0.00000E+00), r, g, b, a, pos + sf::Vector3f( 7.99999E-01,  8.99999E-01,  3.33333E-01));
		addVertex(vertices, sf::Vector3f( 9.19144E-01,  3.93921E-01, -0.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.99999E-01,  6.66667E-01,  3.33333E-01));
		
		addVertex(vertices, sf::Vector3f(-0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  1.00000E-01,  3.33333E-01));
		addVertex(vertices, sf::Vector3f(-0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  1.00000E-01,  3.33333E-01));
		addVertex(vertices, sf::Vector3f(-0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  1.00000E-01,  1.00000E-01));
		
		addVertex(vertices, sf::Vector3f( 0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  1.00000E-01,  1.00000E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  1.00000E-01,  1.00000E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  1.00000E-01,  3.33333E-01));
		
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  3.33333E-01,  1.00000E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  6.66667E-01,  1.00000E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  6.66667E-01,  1.00000E-01));
		
		addVertex(vertices, sf::Vector3f( 0.00000E+00, -0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  6.66667E-01,  1.00000E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00, -0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  3.33333E-01,  1.00000E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00, -0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  3.33333E-01,  1.00000E-01));
		
		addVertex(vertices, sf::Vector3f( 0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  1.00000E-01,  6.66666E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 7.99999E-01,  1.00000E-01,  6.66666E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 7.99999E-01,  1.00000E-01,  8.99999E-01));
		
		addVertex(vertices, sf::Vector3f(-0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 7.99999E-01,  1.00000E-01,  8.99999E-01));
		addVertex(vertices, sf::Vector3f(-0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  1.00000E-01,  8.99999E-01));
		addVertex(vertices, sf::Vector3f(-0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  1.00000E-01,  6.66666E-01));
		
		addVertex(vertices, sf::Vector3f( 9.19145E-01, -3.93920E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.99999E-01,  3.33333E-01,  3.33333E-01));
		addVertex(vertices, sf::Vector3f( 9.19145E-01, -3.93920E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 7.99999E-01,  1.00000E-01,  3.33333E-01));
		addVertex(vertices, sf::Vector3f( 9.19145E-01, -3.93920E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 7.99999E-01,  1.00000E-01,  1.00000E-01));
		
		addVertex(vertices, sf::Vector3f( 9.19145E-01, -3.93920E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 7.99999E-01,  1.00000E-01,  1.00000E-01));
		addVertex(vertices, sf::Vector3f( 9.19145E-01, -3.93920E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.99999E-01,  3.33333E-01,  1.00000E-01));
		addVertex(vertices, sf::Vector3f( 9.19145E-01, -3.93920E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.99999E-01,  3.33333E-01,  3.33333E-01));
		
		addVertex(vertices, sf::Vector3f( 0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  1.00000E-01,  3.33333E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  1.00000E-01,  1.00000E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 7.99999E-01,  1.00000E-01,  1.00000E-01));
		
		addVertex(vertices, sf::Vector3f( 0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 7.99999E-01,  1.00000E-01,  1.00000E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 7.99999E-01,  1.00000E-01,  3.33333E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  1.00000E-01,  3.33333E-01));
		
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.99999E-01,  6.66667E-01,  1.00000E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  6.66667E-01,  1.00000E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  8.99999E-01,  1.00000E-01));
		
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  8.99999E-01,  1.00000E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 7.99999E-01,  8.99999E-01,  1.00000E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.99999E-01,  6.66667E-01,  1.00000E-01));
		
		addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  6.66667E-01,  3.33333E-01));
		addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  6.66667E-01,  6.66666E-01));
		addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  8.99999E-01,  6.66666E-01));
		
		addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00, -0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  8.99999E-01,  6.66666E-01));
		addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00, -0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  8.99999E-01,  3.33333E-01));
		addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00, -0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  6.66667E-01,  3.33333E-01));
		
		addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  3.33333E-01,  6.66666E-01));
		addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  6.66667E-01,  6.66666E-01));
		addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  6.66667E-01,  3.33333E-01));
		
		addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  6.66667E-01,  3.33333E-01));
		addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  3.33333E-01,  3.33333E-01));
		addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  3.33333E-01,  6.66666E-01));
		
		addVertex(vertices, sf::Vector3f( 9.19144E-01,  3.93921E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.99999E-01,  6.66667E-01,  6.66666E-01));
		addVertex(vertices, sf::Vector3f( 9.19144E-01,  3.93921E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.99999E-01,  6.66667E-01,  3.33333E-01));
		addVertex(vertices, sf::Vector3f( 9.19144E-01,  3.93921E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 7.99999E-01,  8.99999E-01,  3.33333E-01));
		
		addVertex(vertices, sf::Vector3f( 9.19144E-01,  3.93921E-01, -0.00000E+00), r, g, b, a, pos + sf::Vector3f( 7.99999E-01,  8.99999E-01,  3.33333E-01));
		addVertex(vertices, sf::Vector3f( 9.19144E-01,  3.93921E-01, -0.00000E+00), r, g, b, a, pos + sf::Vector3f( 7.99999E-01,  8.99999E-01,  6.66666E-01));
		addVertex(vertices, sf::Vector3f( 9.19144E-01,  3.93921E-01, -0.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.99999E-01,  6.66667E-01,  6.66666E-01));
		
		addVertex(vertices, sf::Vector3f(-0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  1.00000E-01,  6.66666E-01));
		addVertex(vertices, sf::Vector3f(-0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  1.00000E-01,  6.66666E-01));
		addVertex(vertices, sf::Vector3f(-0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  1.00000E-01,  3.33333E-01));
		
		addVertex(vertices, sf::Vector3f( 0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  1.00000E-01,  3.33333E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  1.00000E-01,  3.33333E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  1.00000E-01,  6.66666E-01));
		
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  6.66667E-01,  8.99999E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  6.66667E-01,  8.99999E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  8.99999E-01,  8.99999E-01));
		
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  8.99999E-01,  8.99999E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  8.99999E-01,  8.99999E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  6.66667E-01,  8.99999E-01));
		
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  1.00000E-01,  3.33333E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  1.00000E-01,  3.33333E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  0.00000E+00,  3.33333E-01));
		
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  0.00000E+00,  3.33333E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  0.00000E+00,  3.33333E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  1.00000E-01,  3.33333E-01));
		
		addVertex(vertices, sf::Vector3f( 9.19145E-01, -3.93920E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.99999E-01,  3.33333E-01,  6.66666E-01));
		addVertex(vertices, sf::Vector3f( 9.19145E-01, -3.93920E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 7.99999E-01,  1.00000E-01,  6.66666E-01));
		addVertex(vertices, sf::Vector3f( 9.19145E-01, -3.93920E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 7.99999E-01,  1.00000E-01,  3.33333E-01));
		
		addVertex(vertices, sf::Vector3f( 9.19145E-01, -3.93920E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 7.99999E-01,  1.00000E-01,  3.33333E-01));
		addVertex(vertices, sf::Vector3f( 9.19145E-01, -3.93920E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.99999E-01,  3.33333E-01,  3.33333E-01));
		addVertex(vertices, sf::Vector3f( 9.19145E-01, -3.93920E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.99999E-01,  3.33333E-01,  6.66666E-01));
		
		addVertex(vertices, sf::Vector3f( 0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  1.00000E-01,  6.66666E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  1.00000E-01,  3.33333E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 7.99999E-01,  1.00000E-01,  3.33333E-01));
		
		addVertex(vertices, sf::Vector3f( 0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 7.99999E-01,  1.00000E-01,  3.33333E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 7.99999E-01,  1.00000E-01,  6.66666E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  1.00000E-01,  6.66666E-01));
		
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  6.66667E-01,  8.99999E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  6.66667E-01,  8.99999E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  8.99999E-01,  8.99999E-01));
		
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  8.99999E-01,  8.99999E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  8.99999E-01,  8.99999E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  6.66667E-01,  8.99999E-01));
		
		addVertex(vertices, sf::Vector3f( 0.00000E+00, -0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  3.33333E-01,  8.99999E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00, -0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  6.66667E-01,  8.99999E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00, -0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  6.66667E-01,  8.99999E-01));
		
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  6.66667E-01,  8.99999E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  3.33333E-01,  8.99999E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  3.33333E-01,  8.99999E-01));
		
		addVertex(vertices, sf::Vector3f( 0.00000E+00, -0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  3.33333E-01,  8.99999E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00, -0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  6.66667E-01,  8.99999E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00, -0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  6.66667E-01,  8.99999E-01));
		
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  6.66667E-01,  8.99999E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  3.33333E-01,  8.99999E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  3.33333E-01,  8.99999E-01));
		
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  3.33333E-01,  8.99999E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  1.00000E-01,  8.99999E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 7.99999E-01,  1.00000E-01,  8.99999E-01));
		
		addVertex(vertices, sf::Vector3f( 3.84304E-01,  2.19602E-01,  8.96708E-01), r, g, b, a, pos + sf::Vector3f( 7.99999E-01,  1.00000E-01,  8.99999E-01));
		addVertex(vertices, sf::Vector3f( 3.84304E-01,  2.19602E-01,  8.96708E-01), r, g, b, a, pos + sf::Vector3f( 8.99999E-01,  3.33333E-01,  7.99999E-01));
		addVertex(vertices, sf::Vector3f( 3.84304E-01,  2.19602E-01,  8.96708E-01), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  3.33333E-01,  8.99999E-01));
		
		addVertex(vertices, sf::Vector3f( 0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  1.00000E-01,  6.66666E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  1.00000E-01,  6.66666E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  1.00000E-01,  8.99999E-01));
		
		addVertex(vertices, sf::Vector3f(-0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  1.00000E-01,  8.99999E-01));
		addVertex(vertices, sf::Vector3f(-0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  1.00000E-01,  8.99999E-01));
		addVertex(vertices, sf::Vector3f(-0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  1.00000E-01,  6.66666E-01));
		
		addVertex(vertices, sf::Vector3f( 3.84304E-01, -2.19603E-01,  8.96708E-01), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  6.66667E-01,  8.99999E-01));
		addVertex(vertices, sf::Vector3f( 3.84304E-01, -2.19603E-01,  8.96708E-01), r, g, b, a, pos + sf::Vector3f( 8.99999E-01,  6.66667E-01,  7.99999E-01));
		addVertex(vertices, sf::Vector3f( 3.84304E-01, -2.19603E-01,  8.96708E-01), r, g, b, a, pos + sf::Vector3f( 7.99999E-01,  8.99999E-01,  8.99999E-01));
		
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 7.99999E-01,  8.99999E-01,  8.99999E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  8.99999E-01,  8.99999E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  6.66667E-01,  8.99999E-01));
		
		addVertex(vertices, sf::Vector3f( 0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  1.00000E-01,  6.66666E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  1.00000E-01,  6.66666E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  1.00000E-01,  8.99999E-01));
		
		addVertex(vertices, sf::Vector3f(-0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  1.00000E-01,  8.99999E-01));
		addVertex(vertices, sf::Vector3f(-0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  1.00000E-01,  8.99999E-01));
		addVertex(vertices, sf::Vector3f(-0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  1.00000E-01,  6.66666E-01));
		
		addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  6.66667E-01,  6.66666E-01));
		addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  6.66667E-01,  8.99999E-01));
		addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  8.99999E-01,  8.99999E-01));
		
		addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00, -0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  8.99999E-01,  8.99999E-01));
		addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00, -0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  8.99999E-01,  6.66666E-01));
		addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00, -0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  6.66667E-01,  6.66666E-01));
		
		addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  3.33333E-01,  6.66666E-01));
		addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  1.00000E-01,  6.66666E-01));
		addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  1.00000E-01,  8.99999E-01));
		
		addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  1.00000E-01,  8.99999E-01));
		addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  3.33333E-01,  8.99999E-01));
		addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  3.33333E-01,  6.66666E-01));
		
		addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  3.33333E-01,  1.00000E-01));
		addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  1.00000E-01,  1.00000E-01));
		addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  1.00000E-01,  3.33333E-01));
		
		addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  1.00000E-01,  3.33333E-01));
		addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  3.33333E-01,  3.33333E-01));
		addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  3.33333E-01,  1.00000E-01));
		
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  1.00000E-01,  1.00000E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  3.33333E-01,  1.00000E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.99999E-01,  3.33333E-01,  1.00000E-01));
		
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.99999E-01,  3.33333E-01,  1.00000E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 7.99999E-01,  1.00000E-01,  1.00000E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  1.00000E-01,  1.00000E-01));
		
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  1.00000E-01,  1.00000E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  3.33333E-01,  1.00000E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  3.33333E-01,  1.00000E-01));
		
		addVertex(vertices, sf::Vector3f( 0.00000E+00, -0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  3.33333E-01,  1.00000E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00, -0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  1.00000E-01,  1.00000E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00, -0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  1.00000E-01,  1.00000E-01));
		
		addVertex(vertices, sf::Vector3f( 9.19145E-01, -3.93920E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 7.99999E-01,  1.00000E-01,  6.66666E-01));
		addVertex(vertices, sf::Vector3f( 9.19145E-01, -3.93920E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.99999E-01,  3.33333E-01,  6.66666E-01));
		addVertex(vertices, sf::Vector3f( 9.19145E-01, -3.93920E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.99999E-01,  3.33333E-01,  7.99999E-01));
		
		addVertex(vertices, sf::Vector3f( 9.19145E-01, -3.93920E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.99999E-01,  3.33333E-01,  7.99999E-01));
		addVertex(vertices, sf::Vector3f( 9.19145E-01, -3.93920E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 7.99999E-01,  1.00000E-01,  8.99999E-01));
		addVertex(vertices, sf::Vector3f( 9.19145E-01, -3.93920E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 7.99999E-01,  1.00000E-01,  6.66666E-01));
		
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  1.00000E-01,  1.00000E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  3.33333E-01,  1.00000E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  3.33333E-01,  1.00000E-01));
		
		addVertex(vertices, sf::Vector3f( 0.00000E+00, -0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  3.33333E-01,  1.00000E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00, -0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  1.00000E-01,  1.00000E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00, -0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  1.00000E-01,  1.00000E-01));
		
		addVertex(vertices, sf::Vector3f( 1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.99999E-01,  6.66667E-01,  3.33333E-01));
		addVertex(vertices, sf::Vector3f( 1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.99999E-01,  3.33333E-01,  3.33333E-01));
		addVertex(vertices, sf::Vector3f( 1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.99999E-01,  3.33333E-01,  1.00000E-01));
		
		addVertex(vertices, sf::Vector3f( 1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.99999E-01,  3.33333E-01,  1.00000E-01));
		addVertex(vertices, sf::Vector3f( 1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.99999E-01,  6.66667E-01,  1.00000E-01));
		addVertex(vertices, sf::Vector3f( 1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.99999E-01,  6.66667E-01,  3.33333E-01));
		
		addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  1.00000E-01,  6.66666E-01));
		addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  3.33333E-01,  6.66666E-01));
		addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  3.33333E-01,  3.33333E-01));
		
		addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  3.33333E-01,  3.33333E-01));
		addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  1.00000E-01,  3.33333E-01));
		addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  1.00000E-01,  6.66666E-01));
		
		addVertex(vertices, sf::Vector3f( 0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.99999E-01,  3.33333E-01,  6.66666E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.99999E-01,  3.33333E-01,  3.33333E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 9.99999E-01,  3.33333E-01,  3.33333E-01));
		
		addVertex(vertices, sf::Vector3f( 0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 9.99999E-01,  3.33333E-01,  3.33333E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 9.99999E-01,  3.33333E-01,  6.66666E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.99999E-01,  3.33333E-01,  6.66666E-01));
		
		addVertex(vertices, sf::Vector3f( 0.00000E+00, -0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  1.00000E-01,  8.99999E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00, -0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  3.33333E-01,  8.99999E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00, -0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  3.33333E-01,  8.99999E-01));
		
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  3.33333E-01,  8.99999E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  1.00000E-01,  8.99999E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  1.00000E-01,  8.99999E-01));
		
		addVertex(vertices, sf::Vector3f( 0.00000E+00, -0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  1.00000E-01,  8.99999E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00, -0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  3.33333E-01,  8.99999E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00, -0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  3.33333E-01,  8.99999E-01));
		
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  3.33333E-01,  8.99999E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  1.00000E-01,  8.99999E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  1.00000E-01,  8.99999E-01));
		
		addVertex(vertices, sf::Vector3f( 3.93920E-01,  0.00000E+00,  9.19145E-01), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  6.66667E-01,  8.99999E-01));
		addVertex(vertices, sf::Vector3f( 3.93920E-01,  0.00000E+00,  9.19145E-01), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  3.33333E-01,  8.99999E-01));
		addVertex(vertices, sf::Vector3f( 3.93920E-01,  0.00000E+00,  9.19145E-01), r, g, b, a, pos + sf::Vector3f( 8.99999E-01,  3.33333E-01,  7.99999E-01));
		
		addVertex(vertices, sf::Vector3f( 3.93920E-01, -0.00000E+00,  9.19145E-01), r, g, b, a, pos + sf::Vector3f( 8.99999E-01,  3.33333E-01,  7.99999E-01));
		addVertex(vertices, sf::Vector3f( 3.93920E-01, -0.00000E+00,  9.19145E-01), r, g, b, a, pos + sf::Vector3f( 8.99999E-01,  6.66667E-01,  7.99999E-01));
		addVertex(vertices, sf::Vector3f( 3.93920E-01, -0.00000E+00,  9.19145E-01), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  6.66667E-01,  8.99999E-01));
		
		addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  6.66667E-01,  6.66666E-01));
		addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  3.33333E-01,  6.66666E-01));
		addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  3.33333E-01,  8.99999E-01));
		
		addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  3.33333E-01,  8.99999E-01));
		addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  6.66667E-01,  8.99999E-01));
		addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  6.66667E-01,  6.66666E-01));
		
		addVertex(vertices, sf::Vector3f(-0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  8.99999E-01,  3.33333E-01));
		addVertex(vertices, sf::Vector3f(-0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  8.99999E-01,  3.33333E-01));
		addVertex(vertices, sf::Vector3f(-0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  8.99999E-01,  1.00000E-01));
		
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  8.99999E-01,  1.00000E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  8.99999E-01,  1.00000E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  8.99999E-01,  3.33333E-01));
		
		addVertex(vertices, sf::Vector3f(-0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  8.99999E-01,  3.33333E-01));
		addVertex(vertices, sf::Vector3f(-0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  8.99999E-01,  3.33333E-01));
		addVertex(vertices, sf::Vector3f(-0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  8.99999E-01,  1.00000E-01));
		
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  8.99999E-01,  1.00000E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  8.99999E-01,  1.00000E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  8.99999E-01,  3.33333E-01));
		
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 7.99999E-01,  8.99999E-01,  6.66666E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  8.99999E-01,  6.66666E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  8.99999E-01,  8.99999E-01));
		
		addVertex(vertices, sf::Vector3f(-0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  8.99999E-01,  8.99999E-01));
		addVertex(vertices, sf::Vector3f(-0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 7.99999E-01,  8.99999E-01,  8.99999E-01));
		addVertex(vertices, sf::Vector3f(-0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 7.99999E-01,  8.99999E-01,  6.66666E-01));
		
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  8.99999E-01,  3.33333E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  8.99999E-01,  6.66666E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 7.99999E-01,  8.99999E-01,  6.66666E-01));
		
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 7.99999E-01,  8.99999E-01,  6.66666E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 7.99999E-01,  8.99999E-01,  3.33333E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  8.99999E-01,  3.33333E-01));
		
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  8.99999E-01,  3.33333E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  8.99999E-01,  3.33333E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  1.00000E+00,  3.33333E-01));
		
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  1.00000E+00,  3.33333E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  1.00000E+00,  3.33333E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  8.99999E-01,  3.33333E-01));
		
		addVertex(vertices, sf::Vector3f(-0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  8.99999E-01,  6.66666E-01));
		addVertex(vertices, sf::Vector3f(-0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  8.99999E-01,  6.66666E-01));
		addVertex(vertices, sf::Vector3f(-0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  8.99999E-01,  3.33333E-01));
		
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  8.99999E-01,  3.33333E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  8.99999E-01,  3.33333E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  8.99999E-01,  6.66666E-01));
		
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  8.99999E-01,  1.00000E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  8.99999E-01,  3.33333E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 7.99999E-01,  8.99999E-01,  3.33333E-01));
		
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 7.99999E-01,  8.99999E-01,  3.33333E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 7.99999E-01,  8.99999E-01,  1.00000E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  8.99999E-01,  1.00000E-01));
		
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  8.99999E-01,  6.66666E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  8.99999E-01,  6.66666E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  8.99999E-01,  8.99999E-01));
		
		addVertex(vertices, sf::Vector3f(-0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  8.99999E-01,  8.99999E-01));
		addVertex(vertices, sf::Vector3f(-0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  8.99999E-01,  8.99999E-01));
		addVertex(vertices, sf::Vector3f(-0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  8.99999E-01,  6.66666E-01));
		
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  8.99999E-01,  6.66666E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  8.99999E-01,  6.66666E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  8.99999E-01,  8.99999E-01));
		
		addVertex(vertices, sf::Vector3f(-0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  8.99999E-01,  8.99999E-01));
		addVertex(vertices, sf::Vector3f(-0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  8.99999E-01,  8.99999E-01));
		addVertex(vertices, sf::Vector3f(-0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  8.99999E-01,  6.66666E-01));
		
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  6.66667E-01,  1.00000E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  6.66667E-01,  1.00000E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  8.99999E-01,  1.00000E-01));
		
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  8.99999E-01,  1.00000E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  8.99999E-01,  1.00000E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  6.66667E-01,  1.00000E-01));
		
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  6.66667E-01,  1.00000E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  6.66667E-01,  1.00000E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  8.99999E-01,  1.00000E-01));
		
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  8.99999E-01,  1.00000E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  8.99999E-01,  1.00000E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  6.66667E-01,  1.00000E-01));
		
		addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  6.66667E-01,  1.00000E-01));
		addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  6.66667E-01,  3.33333E-01));
		addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  8.99999E-01,  3.33333E-01));
		
		addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00, -0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  8.99999E-01,  3.33333E-01));
		addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00, -0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  8.99999E-01,  1.00000E-01));
		addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00, -0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  6.66667E-01,  1.00000E-01));
		
		addVertex(vertices, sf::Vector3f(-0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  0.00000E+00,  6.66666E-01));
		addVertex(vertices, sf::Vector3f(-0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  0.00000E+00,  6.66666E-01));
		addVertex(vertices, sf::Vector3f(-0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  0.00000E+00,  3.33333E-01));
		
		addVertex(vertices, sf::Vector3f( 0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  0.00000E+00,  3.33333E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  0.00000E+00,  3.33333E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  0.00000E+00,  6.66666E-01));
		
		addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00, -0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  1.00000E-01,  6.66666E-01));
		addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00, -0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  1.00000E-01,  3.33333E-01));
		addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00, -0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  0.00000E+00,  3.33333E-01));
		
		addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  0.00000E+00,  3.33333E-01));
		addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  0.00000E+00,  6.66666E-01));
		addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  1.00000E-01,  6.66666E-01));
		
		addVertex(vertices, sf::Vector3f( 1.00000E+00,  0.00000E+00, -0.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  1.00000E-01,  3.33333E-01));
		addVertex(vertices, sf::Vector3f( 1.00000E+00,  0.00000E+00, -0.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  1.00000E-01,  6.66666E-01));
		addVertex(vertices, sf::Vector3f( 1.00000E+00,  0.00000E+00, -0.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  0.00000E+00,  6.66666E-01));
		
		addVertex(vertices, sf::Vector3f( 1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  0.00000E+00,  6.66666E-01));
		addVertex(vertices, sf::Vector3f( 1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  0.00000E+00,  3.33333E-01));
		addVertex(vertices, sf::Vector3f( 1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  1.00000E-01,  3.33333E-01));
		
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  1.00000E-01,  6.66666E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  1.00000E-01,  6.66666E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  0.00000E+00,  6.66666E-01));
		
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  0.00000E+00,  6.66666E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  0.00000E+00,  6.66666E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  1.00000E-01,  6.66666E-01));
		
		addVertex(vertices, sf::Vector3f( 1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 9.99999E-01,  6.66667E-01,  6.66666E-01));
		addVertex(vertices, sf::Vector3f( 1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 9.99999E-01,  3.33333E-01,  6.66666E-01));
		addVertex(vertices, sf::Vector3f( 1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 9.99999E-01,  3.33333E-01,  3.33333E-01));
		
		addVertex(vertices, sf::Vector3f( 1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 9.99999E-01,  3.33333E-01,  3.33333E-01));
		addVertex(vertices, sf::Vector3f( 1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 9.99999E-01,  6.66667E-01,  3.33333E-01));
		addVertex(vertices, sf::Vector3f( 1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 9.99999E-01,  6.66667E-01,  6.66666E-01));
		
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.99999E-01,  6.66667E-01,  6.66666E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.99999E-01,  3.33333E-01,  6.66666E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 9.99999E-01,  3.33333E-01,  6.66666E-01));
		
		addVertex(vertices, sf::Vector3f( 0.00000E+00, -0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 9.99999E-01,  3.33333E-01,  6.66666E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00, -0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 9.99999E-01,  6.66667E-01,  6.66666E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00, -0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.99999E-01,  6.66667E-01,  6.66666E-01));
		
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.99999E-01,  3.33333E-01,  3.33333E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.99999E-01,  6.66667E-01,  3.33333E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 9.99999E-01,  6.66667E-01,  3.33333E-01));
		
		addVertex(vertices, sf::Vector3f( 0.00000E+00, -0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 9.99999E-01,  6.66667E-01,  3.33333E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00, -0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 9.99999E-01,  3.33333E-01,  3.33333E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00, -0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.99999E-01,  3.33333E-01,  3.33333E-01));
		
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.99999E-01,  6.66667E-01,  3.33333E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.99999E-01,  6.66667E-01,  6.66666E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 9.99999E-01,  6.66667E-01,  6.66666E-01));
		
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 9.99999E-01,  6.66667E-01,  6.66666E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 9.99999E-01,  6.66667E-01,  3.33333E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.99999E-01,  6.66667E-01,  3.33333E-01));
		
		addVertex(vertices, sf::Vector3f(-0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  1.00000E+00,  6.66666E-01));
		addVertex(vertices, sf::Vector3f(-0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  1.00000E+00,  6.66666E-01));
		addVertex(vertices, sf::Vector3f(-0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  1.00000E+00,  3.33333E-01));
		
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  1.00000E+00,  3.33333E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  1.00000E+00,  3.33333E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  1.00000E+00,  6.66666E-01));
		
		addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  8.99999E-01,  3.33333E-01));
		addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  8.99999E-01,  6.66666E-01));
		addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  1.00000E+00,  6.66666E-01));
		
		addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00, -0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  1.00000E+00,  6.66666E-01));
		addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00, -0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  1.00000E+00,  3.33333E-01));
		addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00, -0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  8.99999E-01,  3.33333E-01));
		
		addVertex(vertices, sf::Vector3f( 1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  8.99999E-01,  6.66666E-01));
		addVertex(vertices, sf::Vector3f( 1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  8.99999E-01,  3.33333E-01));
		addVertex(vertices, sf::Vector3f( 1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  1.00000E+00,  3.33333E-01));
		
		addVertex(vertices, sf::Vector3f( 1.00000E+00,  0.00000E+00, -0.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  1.00000E+00,  3.33333E-01));
		addVertex(vertices, sf::Vector3f( 1.00000E+00,  0.00000E+00, -0.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  1.00000E+00,  6.66666E-01));
		addVertex(vertices, sf::Vector3f( 1.00000E+00,  0.00000E+00, -0.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  8.99999E-01,  6.66666E-01));
		
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  8.99999E-01,  6.66666E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  8.99999E-01,  6.66666E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  1.00000E+00,  6.66666E-01));
		
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  1.00000E+00,  6.66666E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  1.00000E+00,  6.66666E-01));
		addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  8.99999E-01,  6.66666E-01));
		
		
	}	
}

bool AndLogic::isAcceptable(SignalableBlock *him, int slot) const
{
	return slot == 4 || slot == 1 || slot == 0;
}

bool AndLogic::cycle(SignalManager &manager)
{
	set(0, isOn(4) && isOn(1));


	return false;	
}
