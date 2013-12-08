#ifndef MESHVERTEX_HPP
#define MESHVERTEX_HPP

#include <SFML/System.hpp>
#include <vector>

class MeshVertex;
typedef std::vector<MeshVertex> MeshVertexVector;



class MeshVertex
{
	public:
		MeshVertex();
		MeshVertex(sf::Vector3f pos, sf::Vector3f norm, 
				   float red, float green, float blue, float alpha = 1.0) {
			set(pos.x, pos.y,pos.z,norm.x, norm.y,norm.z,red,blue,green,alpha);
		}

		void set(float _x, float _y, float _z, 
				 float _nx, float _ny, float _nz,
				 float red, float green, float blue, float alpha = 1.0) {
			x=_x;
			y=_y;z=_z;
			nx=_nx;ny=_ny;nz=_nz;
			r=red;g=green;b=blue;a=alpha;
		}
	
	//private:
		float x,y,z,nx,ny,nz,r,g,b,a;
};

#endif // MESHVERTEX_HPP
