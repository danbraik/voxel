#include "NotLogic.hpp"
#include "SignalManager.hpp"
#include "../VectorTools.hpp"

using namespace VectorTools;
using namespace Signal;



NotLogic::NotLogic()
{
}


void NotLogic::build(MeshVertexVector &vertices, const sf::Vector3f &pos, const Block &right, const Block &behind, const Block &left, const Block &front, const Block &top, const Block &bottom) const
{
	float r,g,b,a;
	r=g=b=a=.7;
	
	addVertex(vertices, sf::Vector3f( 7.07107E-01,  7.07107E-01, -0.00000E+00), r, g, b, a, pos + sf::Vector3f( 7.68577E-01,  6.65559E-01,  8.20800E-01));
	addVertex(vertices, sf::Vector3f( 7.07107E-01,  7.07107E-01, -0.00000E+00), r, g, b, a, pos + sf::Vector3f( 7.68577E-01,  6.65559E-01,  9.79200E-01));
	addVertex(vertices, sf::Vector3f( 7.07107E-01,  7.07107E-01, -0.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.65559E-01,  5.68577E-01,  9.79200E-01));
	
	addVertex(vertices, sf::Vector3f( 7.07107E-01,  7.07107E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.65559E-01,  5.68577E-01,  9.79200E-01));
	addVertex(vertices, sf::Vector3f( 7.07107E-01,  7.07107E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.65559E-01,  5.68577E-01,  8.20800E-01));
	addVertex(vertices, sf::Vector3f( 7.07107E-01,  7.07107E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 7.68577E-01,  6.65559E-01,  8.20800E-01));
	
	addVertex(vertices, sf::Vector3f( 1.00000E+00,  0.00000E+00, -0.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.65559E-01,  5.68577E-01,  8.20800E-01));
	addVertex(vertices, sf::Vector3f( 1.00000E+00,  0.00000E+00, -0.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.65559E-01,  5.68577E-01,  9.79200E-01));
	addVertex(vertices, sf::Vector3f( 1.00000E+00,  0.00000E+00, -0.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.65559E-01,  4.31423E-01,  9.79200E-01));
	
	addVertex(vertices, sf::Vector3f( 1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.65559E-01,  4.31423E-01,  9.79200E-01));
	addVertex(vertices, sf::Vector3f( 1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.65559E-01,  4.31423E-01,  8.20800E-01));
	addVertex(vertices, sf::Vector3f( 1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.65559E-01,  5.68577E-01,  8.20800E-01));
	
	addVertex(vertices, sf::Vector3f( 7.07107E-01, -7.07107E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.65559E-01,  4.31423E-01,  8.20800E-01));
	addVertex(vertices, sf::Vector3f( 7.07107E-01, -7.07107E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.65559E-01,  4.31423E-01,  9.79200E-01));
	addVertex(vertices, sf::Vector3f( 7.07107E-01, -7.07107E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 7.68577E-01,  3.34441E-01,  9.79200E-01));
	
	addVertex(vertices, sf::Vector3f( 7.07107E-01, -7.07107E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 7.68577E-01,  3.34441E-01,  9.79200E-01));
	addVertex(vertices, sf::Vector3f( 7.07107E-01, -7.07107E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 7.68577E-01,  3.34441E-01,  8.20800E-01));
	addVertex(vertices, sf::Vector3f( 7.07107E-01, -7.07107E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.65559E-01,  4.31423E-01,  8.20800E-01));
	
	addVertex(vertices, sf::Vector3f( 0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 7.68577E-01,  3.34441E-01,  8.20800E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 7.68577E-01,  3.34441E-01,  9.79200E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.31423E-01,  3.34441E-01,  9.79200E-01));
	
	addVertex(vertices, sf::Vector3f( 0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.31423E-01,  3.34441E-01,  9.79200E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.31423E-01,  3.34441E-01,  8.20800E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 7.68577E-01,  3.34441E-01,  8.20800E-01));
	
	addVertex(vertices, sf::Vector3f(-7.07107E-01, -7.07107E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.31423E-01,  3.34441E-01,  8.20800E-01));
	addVertex(vertices, sf::Vector3f(-7.07107E-01, -7.07107E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.31423E-01,  3.34441E-01,  9.79200E-01));
	addVertex(vertices, sf::Vector3f(-7.07107E-01, -7.07107E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 5.34441E-01,  4.31423E-01,  9.79200E-01));
	
	addVertex(vertices, sf::Vector3f(-7.07107E-01, -7.07107E-01, -0.00000E+00), r, g, b, a, pos + sf::Vector3f( 5.34441E-01,  4.31423E-01,  9.79200E-01));
	addVertex(vertices, sf::Vector3f(-7.07107E-01, -7.07107E-01, -0.00000E+00), r, g, b, a, pos + sf::Vector3f( 5.34441E-01,  4.31423E-01,  8.20800E-01));
	addVertex(vertices, sf::Vector3f(-7.07107E-01, -7.07107E-01, -0.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.31423E-01,  3.34441E-01,  8.20800E-01));
	
	addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 5.34441E-01,  4.31423E-01,  8.20800E-01));
	addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 5.34441E-01,  4.31423E-01,  9.79200E-01));
	addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 5.34441E-01,  5.68577E-01,  9.79200E-01));
	
	addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00, -0.00000E+00), r, g, b, a, pos + sf::Vector3f( 5.34441E-01,  5.68577E-01,  9.79200E-01));
	addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00, -0.00000E+00), r, g, b, a, pos + sf::Vector3f( 5.34441E-01,  5.68577E-01,  8.20800E-01));
	addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00, -0.00000E+00), r, g, b, a, pos + sf::Vector3f( 5.34441E-01,  4.31423E-01,  8.20800E-01));
	
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.65559E-01,  5.68577E-01,  9.79200E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 7.68577E-01,  6.65559E-01,  9.79200E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.31423E-01,  6.65559E-01,  9.79200E-01));
	
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.65559E-01,  5.68577E-01,  9.79200E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.31423E-01,  6.65559E-01,  9.79200E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.65559E-01,  4.31423E-01,  9.79200E-01));
	
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.31423E-01,  6.65559E-01,  9.79200E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 5.34441E-01,  5.68577E-01,  9.79200E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.65559E-01,  4.31423E-01,  9.79200E-01));
	
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 5.34441E-01,  5.68577E-01,  9.79200E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 5.34441E-01,  4.31423E-01,  9.79200E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.65559E-01,  4.31423E-01,  9.79200E-01));
	
	addVertex(vertices, sf::Vector3f(-0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 5.34441E-01,  4.31423E-01,  9.79200E-01));
	addVertex(vertices, sf::Vector3f(-0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 7.68577E-01,  3.34441E-01,  9.79200E-01));
	addVertex(vertices, sf::Vector3f(-0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.65559E-01,  4.31423E-01,  9.79200E-01));
	
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 5.34441E-01,  4.31423E-01,  9.79200E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.31423E-01,  3.34441E-01,  9.79200E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 7.68577E-01,  3.34441E-01,  9.79200E-01));
	
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 7.68577E-01,  6.65559E-01,  9.79200E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 7.68577E-01,  6.65559E-01,  8.20800E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.31423E-01,  6.65559E-01,  8.20800E-01));
	
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.31423E-01,  6.65559E-01,  8.20800E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.31423E-01,  6.65559E-01,  9.79200E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 7.68577E-01,  6.65559E-01,  9.79200E-01));
	
	addVertex(vertices, sf::Vector3f(-7.07107E-01,  7.07107E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 5.34441E-01,  5.68577E-01,  8.20800E-01));
	addVertex(vertices, sf::Vector3f(-7.07107E-01,  7.07107E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 5.34441E-01,  5.68577E-01,  9.79200E-01));
	addVertex(vertices, sf::Vector3f(-7.07107E-01,  7.07107E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.31423E-01,  6.65559E-01,  9.79200E-01));
	
	addVertex(vertices, sf::Vector3f(-7.07107E-01,  7.07107E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.31423E-01,  6.65559E-01,  9.79200E-01));
	addVertex(vertices, sf::Vector3f(-7.07107E-01,  7.07107E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.31423E-01,  6.65559E-01,  8.20800E-01));
	addVertex(vertices, sf::Vector3f(-7.07107E-01,  7.07107E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 5.34441E-01,  5.68577E-01,  8.20800E-01));
	
	addVertex(vertices, sf::Vector3f(-0.00000E+00, -0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 7.68577E-01,  6.65559E-01,  8.20800E-01));
	addVertex(vertices, sf::Vector3f(-0.00000E+00, -0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.65559E-01,  5.68577E-01,  8.20800E-01));
	addVertex(vertices, sf::Vector3f(-0.00000E+00, -0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.31423E-01,  6.65559E-01,  8.20800E-01));
	
	addVertex(vertices, sf::Vector3f(-0.00000E+00, -0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.65559E-01,  5.68577E-01,  8.20800E-01));
	addVertex(vertices, sf::Vector3f(-0.00000E+00, -0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.65559E-01,  4.31423E-01,  8.20800E-01));
	addVertex(vertices, sf::Vector3f(-0.00000E+00, -0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.31423E-01,  6.65559E-01,  8.20800E-01));
	
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.65559E-01,  4.31423E-01,  8.20800E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 5.34441E-01,  5.68577E-01,  8.20800E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.31423E-01,  6.65559E-01,  8.20800E-01));
	
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.65559E-01,  4.31423E-01,  8.20800E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 5.34441E-01,  4.31423E-01,  8.20800E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 5.34441E-01,  5.68577E-01,  8.20800E-01));
	
	addVertex(vertices, sf::Vector3f(-0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 8.65559E-01,  4.31423E-01,  8.20800E-01));
	addVertex(vertices, sf::Vector3f(-0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 7.68577E-01,  3.34441E-01,  8.20800E-01));
	addVertex(vertices, sf::Vector3f(-0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 5.34441E-01,  4.31423E-01,  8.20800E-01));
	
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 7.68577E-01,  3.34441E-01,  8.20800E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 6.31423E-01,  3.34441E-01,  8.20800E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 5.34441E-01,  4.31423E-01,  8.20800E-01));
	
	addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  6.66667E-01,  3.33333E-01));
	addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  1.00000E+00,  3.33333E-01));
	addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  1.00000E+00,  1.00000E-01));
	
	addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  1.00000E+00,  1.00000E-01));
	addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  6.66667E-01,  1.00000E-01));
	addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  6.66667E-01,  3.33333E-01));
	
	addVertex(vertices, sf::Vector3f(-0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  1.00000E+00,  3.33333E-01));
	addVertex(vertices, sf::Vector3f(-0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 2.00000E-01,  1.00000E+00,  3.33333E-01));
	addVertex(vertices, sf::Vector3f(-0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 2.00000E-01,  1.00000E+00,  1.00000E-01));
	
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 2.00000E-01,  1.00000E+00,  1.00000E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  1.00000E+00,  1.00000E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  1.00000E+00,  3.33333E-01));
	
	addVertex(vertices, sf::Vector3f( 4.29933E-01, -9.02861E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 9.00000E-01,  3.33333E-01,  3.33333E-01));
	addVertex(vertices, sf::Vector3f( 4.29933E-01, -9.02861E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 2.00000E-01,  0.00000E+00,  3.33333E-01));
	addVertex(vertices, sf::Vector3f( 4.29933E-01, -9.02861E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 2.00000E-01,  0.00000E+00,  1.00000E-01));
	
	addVertex(vertices, sf::Vector3f( 4.29933E-01, -9.02861E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 2.00000E-01,  0.00000E+00,  1.00000E-01));
	addVertex(vertices, sf::Vector3f( 4.29933E-01, -9.02861E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 9.00000E-01,  3.33333E-01,  1.00000E-01));
	addVertex(vertices, sf::Vector3f( 4.29933E-01, -9.02861E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 9.00000E-01,  3.33333E-01,  3.33333E-01));
	
	addVertex(vertices, sf::Vector3f(-0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 2.00000E-01,  0.00000E+00,  3.33333E-01));
	addVertex(vertices, sf::Vector3f(-0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  0.00000E+00,  3.33333E-01));
	addVertex(vertices, sf::Vector3f(-0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  0.00000E+00,  1.00000E-01));
	
	addVertex(vertices, sf::Vector3f( 0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  0.00000E+00,  1.00000E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 2.00000E-01,  0.00000E+00,  1.00000E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 2.00000E-01,  0.00000E+00,  3.33333E-01));
	
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  6.66667E-01,  1.00000E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  1.00000E+00,  1.00000E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 2.00000E-01,  1.00000E+00,  1.00000E-01));
	
	addVertex(vertices, sf::Vector3f( 0.00000E+00, -0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 2.00000E-01,  1.00000E+00,  1.00000E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00, -0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 9.00000E-01,  6.66667E-01,  1.00000E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00, -0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  6.66667E-01,  1.00000E-01));
	
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 9.00000E-01,  6.66667E-01,  9.00000E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 2.00000E-01,  1.00000E+00,  9.00000E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  1.00000E+00,  9.00000E-01));
	
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  1.00000E+00,  9.00000E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  6.66667E-01,  9.00000E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 9.00000E-01,  6.66667E-01,  9.00000E-01));
	
	addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  0.00000E+00,  3.33333E-01));
	addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  3.33333E-01,  3.33333E-01));
	addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  3.33333E-01,  1.00000E-01));
	
	addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  3.33333E-01,  1.00000E-01));
	addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  0.00000E+00,  1.00000E-01));
	addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  0.00000E+00,  3.33333E-01));
	
	addVertex(vertices, sf::Vector3f( 1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 9.00000E-01,  6.66667E-01,  3.33333E-01));
	addVertex(vertices, sf::Vector3f( 1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 9.00000E-01,  3.33333E-01,  3.33333E-01));
	addVertex(vertices, sf::Vector3f( 1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 9.00000E-01,  3.33333E-01,  1.00000E-01));
	
	addVertex(vertices, sf::Vector3f( 1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 9.00000E-01,  3.33333E-01,  1.00000E-01));
	addVertex(vertices, sf::Vector3f( 1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 9.00000E-01,  6.66667E-01,  1.00000E-01));
	addVertex(vertices, sf::Vector3f( 1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 9.00000E-01,  6.66667E-01,  3.33333E-01));
	
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  0.00000E+00,  1.00000E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  3.33333E-01,  1.00000E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 9.00000E-01,  3.33333E-01,  1.00000E-01));
	
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 9.00000E-01,  3.33333E-01,  1.00000E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 2.00000E-01,  0.00000E+00,  1.00000E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  0.00000E+00,  1.00000E-01));
	
	addVertex(vertices, sf::Vector3f( 0.00000E+00, -0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 2.00000E-01,  0.00000E+00,  9.00000E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00, -0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 9.00000E-01,  3.33333E-01,  9.00000E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00, -0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  3.33333E-01,  9.00000E-01));
	
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  3.33333E-01,  9.00000E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  0.00000E+00,  9.00000E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 2.00000E-01,  0.00000E+00,  9.00000E-01));
	
	addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  3.33333E-01,  3.33333E-01));
	addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  6.66667E-01,  3.33333E-01));
	addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  6.66667E-01,  1.00000E-01));
	
	addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  6.66667E-01,  1.00000E-01));
	addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  3.33333E-01,  1.00000E-01));
	addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  3.33333E-01,  3.33333E-01));
	
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  3.33333E-01,  1.00000E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  6.66667E-01,  1.00000E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 9.00000E-01,  6.66667E-01,  1.00000E-01));
	
	addVertex(vertices, sf::Vector3f( 0.00000E+00, -0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 9.00000E-01,  6.66667E-01,  1.00000E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00, -0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 9.00000E-01,  3.33333E-01,  1.00000E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00, -0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  3.33333E-01,  1.00000E-01));
	
	addVertex(vertices, sf::Vector3f( 0.00000E+00, -0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 9.00000E-01,  3.33333E-01,  9.00000E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00, -0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 9.00000E-01,  6.66667E-01,  9.00000E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00, -0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  6.66667E-01,  9.00000E-01));
	
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  6.66667E-01,  9.00000E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  3.33333E-01,  9.00000E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 9.00000E-01,  3.33333E-01,  9.00000E-01));
	
	addVertex(vertices, sf::Vector3f( 4.29933E-01,  9.02861E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 2.00000E-01,  1.00000E+00,  3.33333E-01));
	addVertex(vertices, sf::Vector3f( 4.29933E-01,  9.02861E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 9.00000E-01,  6.66667E-01,  3.33333E-01));
	addVertex(vertices, sf::Vector3f( 4.29933E-01,  9.02861E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 9.00000E-01,  6.66667E-01,  1.00000E-01));
	
	addVertex(vertices, sf::Vector3f( 4.29933E-01,  9.02861E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 9.00000E-01,  6.66667E-01,  1.00000E-01));
	addVertex(vertices, sf::Vector3f( 4.29933E-01,  9.02861E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 2.00000E-01,  1.00000E+00,  1.00000E-01));
	addVertex(vertices, sf::Vector3f( 4.29933E-01,  9.02861E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 2.00000E-01,  1.00000E+00,  3.33333E-01));
	
	addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  6.66667E-01,  6.66667E-01));
	addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  1.00000E+00,  6.66667E-01));
	addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  1.00000E+00,  3.33333E-01));
	
	addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  1.00000E+00,  3.33333E-01));
	addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  6.66667E-01,  3.33333E-01));
	addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  6.66667E-01,  6.66667E-01));
	
	addVertex(vertices, sf::Vector3f(-0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  1.00000E+00,  6.66667E-01));
	addVertex(vertices, sf::Vector3f(-0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 2.00000E-01,  1.00000E+00,  6.66667E-01));
	addVertex(vertices, sf::Vector3f(-0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 2.00000E-01,  1.00000E+00,  3.33333E-01));
	
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 2.00000E-01,  1.00000E+00,  3.33333E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  1.00000E+00,  3.33333E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  1.00000E+00,  6.66667E-01));
	
	addVertex(vertices, sf::Vector3f( 4.29933E-01, -9.02861E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 9.00000E-01,  3.33333E-01,  6.66667E-01));
	addVertex(vertices, sf::Vector3f( 4.29933E-01, -9.02861E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 2.00000E-01,  0.00000E+00,  6.66667E-01));
	addVertex(vertices, sf::Vector3f( 4.29933E-01, -9.02861E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 2.00000E-01,  0.00000E+00,  3.33333E-01));
	
	addVertex(vertices, sf::Vector3f( 4.29933E-01, -9.02861E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 2.00000E-01,  0.00000E+00,  3.33333E-01));
	addVertex(vertices, sf::Vector3f( 4.29933E-01, -9.02861E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 9.00000E-01,  3.33333E-01,  3.33333E-01));
	addVertex(vertices, sf::Vector3f( 4.29933E-01, -9.02861E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 9.00000E-01,  3.33333E-01,  6.66667E-01));
	
	addVertex(vertices, sf::Vector3f(-0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 2.00000E-01,  0.00000E+00,  6.66667E-01));
	addVertex(vertices, sf::Vector3f(-0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  0.00000E+00,  6.66667E-01));
	addVertex(vertices, sf::Vector3f(-0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  0.00000E+00,  3.33333E-01));
	
	addVertex(vertices, sf::Vector3f( 0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  0.00000E+00,  3.33333E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 2.00000E-01,  0.00000E+00,  3.33333E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 2.00000E-01,  0.00000E+00,  6.66667E-01));
	
	addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  0.00000E+00,  6.66667E-01));
	addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  3.33333E-01,  6.66667E-01));
	addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  3.33333E-01,  3.33333E-01));
	
	addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  3.33333E-01,  3.33333E-01));
	addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  0.00000E+00,  3.33333E-01));
	addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  0.00000E+00,  6.66667E-01));
	
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 9.00000E-01,  6.66667E-01,  6.66667E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 9.00000E-01,  3.33333E-01,  6.66667E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E+00,  3.33333E-01,  6.66667E-01));
	
	addVertex(vertices, sf::Vector3f( 0.00000E+00, -0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E+00,  3.33333E-01,  6.66667E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00, -0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E+00,  6.66667E-01,  6.66667E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00, -0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 9.00000E-01,  6.66667E-01,  6.66667E-01));
	
	addVertex(vertices, sf::Vector3f( 0.00000E+00, -0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  3.33333E-01,  6.66667E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00, -0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  6.66667E-01,  6.66667E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00, -0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 0.00000E+00,  6.66667E-01,  6.66667E-01));
	
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 0.00000E+00,  6.66667E-01,  6.66667E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 0.00000E+00,  3.33333E-01,  6.66667E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00,  1.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  3.33333E-01,  6.66667E-01));
	
	addVertex(vertices, sf::Vector3f( 4.29933E-01,  9.02861E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 2.00000E-01,  1.00000E+00,  6.66667E-01));
	addVertex(vertices, sf::Vector3f( 4.29933E-01,  9.02861E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 9.00000E-01,  6.66667E-01,  6.66667E-01));
	addVertex(vertices, sf::Vector3f( 4.29933E-01,  9.02861E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 9.00000E-01,  6.66667E-01,  3.33333E-01));
	
	addVertex(vertices, sf::Vector3f( 4.29933E-01,  9.02861E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 9.00000E-01,  6.66667E-01,  3.33333E-01));
	addVertex(vertices, sf::Vector3f( 4.29933E-01,  9.02861E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 2.00000E-01,  1.00000E+00,  3.33333E-01));
	addVertex(vertices, sf::Vector3f( 4.29933E-01,  9.02861E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 2.00000E-01,  1.00000E+00,  6.66667E-01));
	
	addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  6.66667E-01,  9.00000E-01));
	addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  1.00000E+00,  9.00000E-01));
	addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  1.00000E+00,  6.66667E-01));
	
	addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  1.00000E+00,  6.66667E-01));
	addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  6.66667E-01,  6.66667E-01));
	addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  6.66667E-01,  9.00000E-01));
	
	addVertex(vertices, sf::Vector3f(-0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  1.00000E+00,  9.00000E-01));
	addVertex(vertices, sf::Vector3f(-0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 2.00000E-01,  1.00000E+00,  9.00000E-01));
	addVertex(vertices, sf::Vector3f(-0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 2.00000E-01,  1.00000E+00,  6.66667E-01));
	
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 2.00000E-01,  1.00000E+00,  6.66667E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  1.00000E+00,  6.66667E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  1.00000E+00,  9.00000E-01));
	
	addVertex(vertices, sf::Vector3f( 4.29933E-01, -9.02861E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 9.00000E-01,  3.33333E-01,  9.00000E-01));
	addVertex(vertices, sf::Vector3f( 4.29933E-01, -9.02861E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 2.00000E-01,  0.00000E+00,  9.00000E-01));
	addVertex(vertices, sf::Vector3f( 4.29933E-01, -9.02861E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 2.00000E-01,  0.00000E+00,  6.66667E-01));
	
	addVertex(vertices, sf::Vector3f( 4.29933E-01, -9.02861E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 2.00000E-01,  0.00000E+00,  6.66667E-01));
	addVertex(vertices, sf::Vector3f( 4.29933E-01, -9.02861E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 9.00000E-01,  3.33333E-01,  6.66667E-01));
	addVertex(vertices, sf::Vector3f( 4.29933E-01, -9.02861E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 9.00000E-01,  3.33333E-01,  9.00000E-01));
	
	addVertex(vertices, sf::Vector3f(-0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 2.00000E-01,  0.00000E+00,  9.00000E-01));
	addVertex(vertices, sf::Vector3f(-0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  0.00000E+00,  9.00000E-01));
	addVertex(vertices, sf::Vector3f(-0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  0.00000E+00,  6.66667E-01));
	
	addVertex(vertices, sf::Vector3f( 0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  0.00000E+00,  6.66667E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 2.00000E-01,  0.00000E+00,  6.66667E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 2.00000E-01,  0.00000E+00,  9.00000E-01));
	
	addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  0.00000E+00,  9.00000E-01));
	addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  3.33333E-01,  9.00000E-01));
	addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  3.33333E-01,  6.66667E-01));
	
	addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  3.33333E-01,  6.66667E-01));
	addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  0.00000E+00,  6.66667E-01));
	addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  0.00000E+00,  9.00000E-01));
	
	addVertex(vertices, sf::Vector3f( 1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 9.00000E-01,  6.66667E-01,  9.00000E-01));
	addVertex(vertices, sf::Vector3f( 1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 9.00000E-01,  3.33333E-01,  9.00000E-01));
	addVertex(vertices, sf::Vector3f( 1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 9.00000E-01,  3.33333E-01,  6.66667E-01));
	
	addVertex(vertices, sf::Vector3f( 1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 9.00000E-01,  3.33333E-01,  6.66667E-01));
	addVertex(vertices, sf::Vector3f( 1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 9.00000E-01,  6.66667E-01,  6.66667E-01));
	addVertex(vertices, sf::Vector3f( 1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 9.00000E-01,  6.66667E-01,  9.00000E-01));
	
	addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  3.33333E-01,  9.00000E-01));
	addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  6.66667E-01,  9.00000E-01));
	addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  6.66667E-01,  6.66667E-01));
	
	addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  6.66667E-01,  6.66667E-01));
	addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  3.33333E-01,  6.66667E-01));
	addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  3.33333E-01,  9.00000E-01));
	
	addVertex(vertices, sf::Vector3f( 4.29933E-01,  9.02861E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 2.00000E-01,  1.00000E+00,  9.00000E-01));
	addVertex(vertices, sf::Vector3f( 4.29933E-01,  9.02861E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 9.00000E-01,  6.66667E-01,  9.00000E-01));
	addVertex(vertices, sf::Vector3f( 4.29933E-01,  9.02861E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 9.00000E-01,  6.66667E-01,  6.66667E-01));
	
	addVertex(vertices, sf::Vector3f( 4.29933E-01,  9.02861E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 9.00000E-01,  6.66667E-01,  6.66667E-01));
	addVertex(vertices, sf::Vector3f( 4.29933E-01,  9.02861E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 2.00000E-01,  1.00000E+00,  6.66667E-01));
	addVertex(vertices, sf::Vector3f( 4.29933E-01,  9.02861E-01,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 2.00000E-01,  1.00000E+00,  9.00000E-01));
	
	addVertex(vertices, sf::Vector3f( 1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E+00,  6.66667E-01,  6.66667E-01));
	addVertex(vertices, sf::Vector3f( 1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E+00,  3.33333E-01,  6.66667E-01));
	addVertex(vertices, sf::Vector3f( 1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E+00,  3.33333E-01,  3.33333E-01));
	
	addVertex(vertices, sf::Vector3f( 1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E+00,  3.33333E-01,  3.33333E-01));
	addVertex(vertices, sf::Vector3f( 1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E+00,  6.66667E-01,  3.33333E-01));
	addVertex(vertices, sf::Vector3f( 1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E+00,  6.66667E-01,  6.66667E-01));
	
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 9.00000E-01,  6.66667E-01,  3.33333E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 9.00000E-01,  6.66667E-01,  6.66667E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E+00,  6.66667E-01,  6.66667E-01));
	
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E+00,  6.66667E-01,  6.66667E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E+00,  6.66667E-01,  3.33333E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 9.00000E-01,  6.66667E-01,  3.33333E-01));
	
	addVertex(vertices, sf::Vector3f( 0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 9.00000E-01,  3.33333E-01,  6.66667E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 9.00000E-01,  3.33333E-01,  3.33333E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E+00,  3.33333E-01,  3.33333E-01));
	
	addVertex(vertices, sf::Vector3f( 0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E+00,  3.33333E-01,  3.33333E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E+00,  3.33333E-01,  6.66667E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 9.00000E-01,  3.33333E-01,  6.66667E-01));
	
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 9.00000E-01,  3.33333E-01,  3.33333E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 9.00000E-01,  6.66667E-01,  3.33333E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E+00,  6.66667E-01,  3.33333E-01));
	
	addVertex(vertices, sf::Vector3f( 0.00000E+00, -0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E+00,  6.66667E-01,  3.33333E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00, -0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E+00,  3.33333E-01,  3.33333E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00, -0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 9.00000E-01,  3.33333E-01,  3.33333E-01));
	
	addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 0.00000E+00,  3.33333E-01,  6.66667E-01));
	addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 0.00000E+00,  6.66667E-01,  6.66667E-01));
	addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 0.00000E+00,  6.66667E-01,  3.33333E-01));
	
	addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 0.00000E+00,  6.66667E-01,  3.33333E-01));
	addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 0.00000E+00,  3.33333E-01,  3.33333E-01));
	addVertex(vertices, sf::Vector3f(-1.00000E+00,  0.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 0.00000E+00,  3.33333E-01,  6.66667E-01));
	
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  6.66667E-01,  6.66667E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  6.66667E-01,  3.33333E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 0.00000E+00,  6.66667E-01,  3.33333E-01));
	
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 0.00000E+00,  6.66667E-01,  3.33333E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 0.00000E+00,  6.66667E-01,  6.66667E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  6.66667E-01,  6.66667E-01));
	
	addVertex(vertices, sf::Vector3f( 0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  3.33333E-01,  3.33333E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  3.33333E-01,  6.66667E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 0.00000E+00,  3.33333E-01,  6.66667E-01));
	
	addVertex(vertices, sf::Vector3f( 0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 0.00000E+00,  3.33333E-01,  6.66667E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 0.00000E+00,  3.33333E-01,  3.33333E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00, -1.00000E+00,  0.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  3.33333E-01,  3.33333E-01));
	
	addVertex(vertices, sf::Vector3f( 0.00000E+00, -0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  6.66667E-01,  3.33333E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00, -0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  3.33333E-01,  3.33333E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00, -0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 0.00000E+00,  3.33333E-01,  3.33333E-01));
	
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 0.00000E+00,  3.33333E-01,  3.33333E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 0.00000E+00,  6.66667E-01,  3.33333E-01));
	addVertex(vertices, sf::Vector3f( 0.00000E+00,  0.00000E+00, -1.00000E+00), r, g, b, a, pos + sf::Vector3f( 1.00000E-01,  6.66667E-01,  3.33333E-01));
	
	
	
}

bool NotLogic::isAcceptable(SignalableBlock *him, int slot) const
{
	return slot == 0 || slot == 3;
}

bool NotLogic::cycle(SignalManager &manager)
{
	set(0, ! isOn(3));
	
	return false;	
}
