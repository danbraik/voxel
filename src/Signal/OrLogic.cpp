#include "OrLogic.hpp"
#include "SignalManager.hpp"
#include "../VectorTools.hpp"

using namespace VectorTools;
using namespace Signal;



OrLogic::OrLogic()
{
}


void OrLogic::build(MeshVertexVector &vertices, const sf::Vector3f &pos, const Block &right, const Block &behind, const Block &left, const Block &front, const Block &top, const Block &bottom) const
{
	float r,g,b,a;
	r=g=b=a=1.;
	
	
	addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.00000E-01,  3.33333E-01,  3.33333E-01));
	addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.00000E-01,  6.66667E-01,  3.33333E-01));
	addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.00000E-01,  6.66667E-01,  1.00000E-01));
	
	addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.00000E-01,  6.66667E-01,  1.00000E-01));
	addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.00000E-01,  3.33333E-01,  1.00000E-01));
	addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.00000E-01,  3.33333E-01,  3.33333E-01));
	
	addVertex(vertices, sf::Vector3f( 9.19144E-01,  3.93921E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.99999E-01,  6.66667E-01,  8.99999E-01));
	addVertex(vertices, sf::Vector3f( 9.19144E-01,  3.93921E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.99999E-01,  6.66667E-01,  6.66666E-01));
	addVertex(vertices, sf::Vector3f( 9.19144E-01,  3.93921E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 7.99999E-01,  8.99999E-01,  6.66666E-01));
	
	addVertex(vertices, sf::Vector3f( 9.19144E-01,  3.93921E-01, -0.00000E+00), r, g, b, a, pos + sf::Vector3f( 7.99999E-01,  8.99999E-01,  6.66666E-01));
	addVertex(vertices, sf::Vector3f( 9.19144E-01,  3.93921E-01, -0.00000E+00), r, g, b, a, pos + sf::Vector3f( 7.99999E-01,  8.99999E-01,  8.99999E-01));
	addVertex(vertices, sf::Vector3f( 9.19144E-01,  3.93921E-01, -0.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.99999E-01,  6.66667E-01,  8.99999E-01));
	
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
	addVertex(vertices, sf::Vector3f( 1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.99999E-01,  6.66667E-01,  8.99999E-01));
	
	addVertex(vertices, sf::Vector3f( 1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.99999E-01,  6.66667E-01,  8.99999E-01));
	addVertex(vertices, sf::Vector3f( 1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.99999E-01,  3.33333E-01,  8.99999E-01));
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
	
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.00000E-01,  3.33333E-01,  1.00000E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.00000E-01,  6.66667E-01,  1.00000E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  6.66667E-01,  1.00000E-01));
	
	addVertex(vertices, sf::Vector3f( 0.00000E+00, -0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  6.66667E-01,  1.00000E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00, -0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  3.33333E-01,  1.00000E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00, -0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.00000E-01,  3.33333E-01,  1.00000E-01));
	
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
	
	addVertex(vertices, sf::Vector3f(-7.59255E-01, -6.50793E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.00000E-01,  6.66667E-01,  3.33333E-01));
	addVertex(vertices, sf::Vector3f(-7.59255E-01, -6.50793E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.00000E-01,  6.66667E-01,  6.66666E-01));
	addVertex(vertices, sf::Vector3f(-7.59255E-01, -6.50793E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  8.99999E-01,  6.66666E-01));
	
	addVertex(vertices, sf::Vector3f(-7.59255E-01, -6.50793E-01, -0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  8.99999E-01,  6.66666E-01));
	addVertex(vertices, sf::Vector3f(-7.59255E-01, -6.50793E-01, -0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  8.99999E-01,  3.33333E-01));
	addVertex(vertices, sf::Vector3f(-7.59255E-01, -6.50793E-01, -0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.00000E-01,  6.66667E-01,  3.33333E-01));
	
	addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.00000E-01,  3.33333E-01,  6.66666E-01));
	addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.00000E-01,  6.66667E-01,  6.66666E-01));
	addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.00000E-01,  6.66667E-01,  3.33333E-01));
	
	addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.00000E-01,  6.66667E-01,  3.33333E-01));
	addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.00000E-01,  3.33333E-01,  3.33333E-01));
	addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.00000E-01,  3.33333E-01,  6.66666E-01));
	
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
	
	addVertex(vertices, sf::Vector3f(-9.48684E-01,  0.00000E+00,  3.16225E-01), r, g, b, a, pos + sf::Vector3f( 3.00000E-01,  6.66667E-01,  7.99999E-01));
	addVertex(vertices, sf::Vector3f(-9.48684E-01,  0.00000E+00,  3.16225E-01), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  6.66667E-01,  8.99999E-01));
	addVertex(vertices, sf::Vector3f(-9.48684E-01,  0.00000E+00,  3.16225E-01), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  8.99999E-01,  8.99999E-01));
	
	addVertex(vertices, sf::Vector3f(-3.73219E-01, -3.19904E-01,  8.70844E-01), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  8.99999E-01,  8.99999E-01));
	addVertex(vertices, sf::Vector3f(-3.73219E-01, -3.19904E-01,  8.70844E-01), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  8.99999E-01,  7.99999E-01));
	addVertex(vertices, sf::Vector3f(-3.73219E-01, -3.19904E-01,  8.70844E-01), r, g, b, a, pos + sf::Vector3f( 3.00000E-01,  6.66667E-01,  7.99999E-01));
	
	addVertex(vertices, sf::Vector3f(-9.48684E-01,  0.00000E+00,  3.16225E-01), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  3.33333E-01,  8.99999E-01));
	addVertex(vertices, sf::Vector3f(-9.48684E-01,  0.00000E+00,  3.16225E-01), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  6.66667E-01,  8.99999E-01));
	addVertex(vertices, sf::Vector3f(-9.48684E-01,  0.00000E+00,  3.16225E-01), r, g, b, a, pos + sf::Vector3f( 3.00000E-01,  6.66667E-01,  7.99999E-01));
	
	addVertex(vertices, sf::Vector3f(-9.48684E-01,  0.00000E+00,  3.16225E-01), r, g, b, a, pos + sf::Vector3f( 3.00000E-01,  6.66667E-01,  7.99999E-01));
	addVertex(vertices, sf::Vector3f(-9.48684E-01,  0.00000E+00,  3.16225E-01), r, g, b, a, pos + sf::Vector3f( 3.00000E-01,  3.33333E-01,  7.99999E-01));
	addVertex(vertices, sf::Vector3f(-9.48684E-01,  0.00000E+00,  3.16225E-01), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  3.33333E-01,  8.99999E-01));
	
	addVertex(vertices, sf::Vector3f( 0.00000E+00, -0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  3.33333E-01,  8.99999E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00, -0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  6.66667E-01,  8.99999E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00, -0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  6.66667E-01,  8.99999E-01));
	
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  6.66667E-01,  8.99999E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  3.33333E-01,  8.99999E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  3.33333E-01,  8.99999E-01));
	
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  3.33333E-01,  8.99999E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  1.00000E-01,  8.99999E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 7.99999E-01,  1.00000E-01,  8.99999E-01));
	
	addVertex(vertices, sf::Vector3f( 0.00000E+00, -0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 7.99999E-01,  1.00000E-01,  8.99999E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00, -0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.99999E-01,  3.33333E-01,  8.99999E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00, -0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  3.33333E-01,  8.99999E-01));
	
	addVertex(vertices, sf::Vector3f( 0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  1.00000E-01,  6.66666E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  1.00000E-01,  6.66666E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  1.00000E-01,  8.99999E-01));
	
	addVertex(vertices, sf::Vector3f(-0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  1.00000E-01,  8.99999E-01));
	addVertex(vertices, sf::Vector3f(-0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  1.00000E-01,  8.99999E-01));
	addVertex(vertices, sf::Vector3f(-0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  1.00000E-01,  6.66666E-01));
	
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  6.66667E-01,  8.99999E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.99999E-01,  6.66667E-01,  8.99999E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 7.99999E-01,  8.99999E-01,  8.99999E-01));
	
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 7.99999E-01,  8.99999E-01,  8.99999E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  8.99999E-01,  8.99999E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  6.66667E-01,  8.99999E-01));
	
	addVertex(vertices, sf::Vector3f( 0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  1.00000E-01,  6.66666E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  1.00000E-01,  6.66666E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  1.00000E-01,  8.99999E-01));
	
	addVertex(vertices, sf::Vector3f( 0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  1.00000E-01,  8.99999E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  1.00000E-01,  7.99999E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  1.00000E-01,  6.66666E-01));
	
	addVertex(vertices, sf::Vector3f(-7.59255E-01, -6.50793E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.00000E-01,  6.66667E-01,  6.66666E-01));
	addVertex(vertices, sf::Vector3f(-7.59255E-01, -6.50793E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.00000E-01,  6.66667E-01,  7.99999E-01));
	addVertex(vertices, sf::Vector3f(-7.59255E-01, -6.50793E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  8.99999E-01,  7.99999E-01));
	
	addVertex(vertices, sf::Vector3f(-7.59255E-01, -6.50793E-01, -0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  8.99999E-01,  7.99999E-01));
	addVertex(vertices, sf::Vector3f(-7.59255E-01, -6.50793E-01, -0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  8.99999E-01,  6.66666E-01));
	addVertex(vertices, sf::Vector3f(-7.59255E-01, -6.50793E-01, -0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.00000E-01,  6.66667E-01,  6.66666E-01));
	
	addVertex(vertices, sf::Vector3f(-7.59256E-01,  6.50792E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.00000E-01,  3.33333E-01,  6.66666E-01));
	addVertex(vertices, sf::Vector3f(-7.59256E-01,  6.50792E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  1.00000E-01,  6.66666E-01));
	addVertex(vertices, sf::Vector3f(-7.59256E-01,  6.50792E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  1.00000E-01,  7.99999E-01));
	
	addVertex(vertices, sf::Vector3f(-7.59256E-01,  6.50792E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  1.00000E-01,  7.99999E-01));
	addVertex(vertices, sf::Vector3f(-7.59256E-01,  6.50792E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.00000E-01,  3.33333E-01,  7.99999E-01));
	addVertex(vertices, sf::Vector3f(-7.59256E-01,  6.50792E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.00000E-01,  3.33333E-01,  6.66666E-01));
	
	addVertex(vertices, sf::Vector3f(-7.59256E-01,  6.50792E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.00000E-01,  3.33333E-01,  1.00000E-01));
	addVertex(vertices, sf::Vector3f(-7.59256E-01,  6.50792E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  1.00000E-01,  1.00000E-01));
	addVertex(vertices, sf::Vector3f(-7.59256E-01,  6.50792E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  1.00000E-01,  3.33333E-01));
	
	addVertex(vertices, sf::Vector3f(-7.59256E-01,  6.50792E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  1.00000E-01,  3.33333E-01));
	addVertex(vertices, sf::Vector3f(-7.59256E-01,  6.50792E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.00000E-01,  3.33333E-01,  3.33333E-01));
	addVertex(vertices, sf::Vector3f(-7.59256E-01,  6.50792E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.00000E-01,  3.33333E-01,  1.00000E-01));
	
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
	addVertex(vertices, sf::Vector3f( 9.19145E-01, -3.93920E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.99999E-01,  3.33333E-01,  8.99999E-01));
	
	addVertex(vertices, sf::Vector3f( 9.19145E-01, -3.93920E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.99999E-01,  3.33333E-01,  8.99999E-01));
	addVertex(vertices, sf::Vector3f( 9.19145E-01, -3.93920E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 7.99999E-01,  1.00000E-01,  8.99999E-01));
	addVertex(vertices, sf::Vector3f( 9.19145E-01, -3.93920E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 7.99999E-01,  1.00000E-01,  6.66666E-01));
	
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  1.00000E-01,  1.00000E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.00000E-01,  3.33333E-01,  1.00000E-01));
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
	
	addVertex(vertices, sf::Vector3f(-7.59256E-01,  6.50792E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  1.00000E-01,  6.66666E-01));
	addVertex(vertices, sf::Vector3f(-7.59256E-01,  6.50792E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.00000E-01,  3.33333E-01,  6.66666E-01));
	addVertex(vertices, sf::Vector3f(-7.59256E-01,  6.50792E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.00000E-01,  3.33333E-01,  3.33333E-01));
	
	addVertex(vertices, sf::Vector3f(-7.59256E-01,  6.50792E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.00000E-01,  3.33333E-01,  3.33333E-01));
	addVertex(vertices, sf::Vector3f(-7.59256E-01,  6.50792E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  1.00000E-01,  3.33333E-01));
	addVertex(vertices, sf::Vector3f(-7.59256E-01,  6.50792E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  1.00000E-01,  6.66666E-01));
	
	addVertex(vertices, sf::Vector3f( 0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.99999E-01,  3.33333E-01,  6.66666E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.99999E-01,  3.33333E-01,  3.33333E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 9.99999E-01,  3.33333E-01,  3.33333E-01));
	
	addVertex(vertices, sf::Vector3f( 0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 9.99999E-01,  3.33333E-01,  3.33333E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 9.99999E-01,  3.33333E-01,  6.66666E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.99999E-01,  3.33333E-01,  6.66666E-01));
	
	addVertex(vertices, sf::Vector3f(-9.48684E-01,  0.00000E+00,  3.16225E-01), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  1.00000E-01,  8.99999E-01));
	addVertex(vertices, sf::Vector3f(-9.48684E-01,  0.00000E+00,  3.16225E-01), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  3.33333E-01,  8.99999E-01));
	addVertex(vertices, sf::Vector3f(-9.48684E-01,  0.00000E+00,  3.16225E-01), r, g, b, a, pos + sf::Vector3f( 3.00000E-01,  3.33333E-01,  7.99999E-01));
	
	addVertex(vertices, sf::Vector3f(-3.73219E-01,  3.19903E-01,  8.70844E-01), r, g, b, a, pos + sf::Vector3f( 3.00000E-01,  3.33333E-01,  7.99999E-01));
	addVertex(vertices, sf::Vector3f(-3.73219E-01,  3.19903E-01,  8.70844E-01), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  1.00000E-01,  7.99999E-01));
	addVertex(vertices, sf::Vector3f(-3.73219E-01,  3.19903E-01,  8.70844E-01), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  1.00000E-01,  8.99999E-01));
	
	addVertex(vertices, sf::Vector3f( 0.00000E+00, -0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  1.00000E-01,  8.99999E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00, -0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  3.33333E-01,  8.99999E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00, -0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  3.33333E-01,  8.99999E-01));
	
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  3.33333E-01,  8.99999E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  1.00000E-01,  8.99999E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  1.00000E-01,  8.99999E-01));
	
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  6.66667E-01,  8.99999E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  3.33333E-01,  8.99999E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.99999E-01,  3.33333E-01,  8.99999E-01));
	
	addVertex(vertices, sf::Vector3f( 0.00000E+00, -0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.99999E-01,  3.33333E-01,  8.99999E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00, -0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.99999E-01,  6.66667E-01,  8.99999E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00, -0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.66666E-01,  6.66667E-01,  8.99999E-01));
	
	addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.00000E-01,  6.66667E-01,  6.66666E-01));
	addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.00000E-01,  3.33333E-01,  6.66666E-01));
	addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.00000E-01,  3.33333E-01,  7.99999E-01));
	
	addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.00000E-01,  3.33333E-01,  7.99999E-01));
	addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.00000E-01,  6.66667E-01,  7.99999E-01));
	addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.00000E-01,  6.66667E-01,  6.66666E-01));
	
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
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  8.99999E-01,  7.99999E-01));
	
	addVertex(vertices, sf::Vector3f(-0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  8.99999E-01,  7.99999E-01));
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
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.00000E-01,  6.66667E-01,  1.00000E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  8.99999E-01,  1.00000E-01));
	
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  8.99999E-01,  1.00000E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  8.99999E-01,  1.00000E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.33333E-01,  6.66667E-01,  1.00000E-01));
	
	addVertex(vertices, sf::Vector3f(-7.59255E-01, -6.50794E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.00000E-01,  6.66667E-01,  1.00000E-01));
	addVertex(vertices, sf::Vector3f(-7.59255E-01, -6.50794E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.00000E-01,  6.66667E-01,  3.33333E-01));
	addVertex(vertices, sf::Vector3f(-7.59255E-01, -6.50794E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  8.99999E-01,  3.33333E-01));
	
	addVertex(vertices, sf::Vector3f(-7.59255E-01, -6.50794E-01, -0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  8.99999E-01,  3.33333E-01));
	addVertex(vertices, sf::Vector3f(-7.59255E-01, -6.50794E-01, -0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  8.99999E-01,  1.00000E-01));
	addVertex(vertices, sf::Vector3f(-7.59255E-01, -6.50794E-01, -0.00000E+00), r, g, b, a, pos + sf::Vector3f( 3.00000E-01,  6.66667E-01,  1.00000E-01));
	
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

bool OrLogic::isAcceptable(SignalableBlock *him, int slot) const
{
	return slot == 4 || slot == 1 || slot == 0;
}

bool OrLogic::cycle(SignalManager &manager)
{
	set(0, isOn(4) || isOn(1));


	return false;	
}
