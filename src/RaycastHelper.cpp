#include <iostream>
#include "RaycastHelper.hpp"

RaycastHelper::RaycastHelper()
{
}

bool RaycastHelper::raycast(ChunkManager &manager, 
							sf::Vector3f &source, 
							sf::Vector3f dir, 
							sf::Vector3i &selectCube, 
							sf::Vector3i &nextNorm)
{
	const float CX = Block::SIZE, CY = Block::SIZE, CZ = Block::SIZE;// -> const : taille cases
	const float Max_Dist_carre = 250;// -> const : distance max à regarder au carré
	
	float x=source.x, y=source.y, z=source.z;// ->  positions lanceur rayon
	float dx=dir.x, dy=dir.y, dz=dir.z;// -> direction rayon
	
	float Tan_beta = dy/dx;
	float Tan_gamma = dz/dy;
	
	//-- Distance entre deux touchés de faces selon x, y ou z
	
	float DeltaXy = CX * Tan_beta;
	float DeltaXz = DeltaXy * Tan_gamma;
	float DeltaX = DeltaXy*DeltaXy + DeltaXz*DeltaXz;// -- on travaille que avec des carrés de distances
	
	float DeltaYx = CY / Tan_beta;
	float DeltaYz = CY * Tan_gamma;
	float DeltaY = DeltaYx*DeltaYx + DeltaYz*DeltaYz;
	
	float DeltaZy = CZ / Tan_gamma;
	float DeltaZx = DeltaZy / Tan_beta;
	float DeltaZ = DeltaZy*DeltaZy + DeltaZx*DeltaZx;
	
//	-- si on regarde à droite on avance etc. ...
// !!
	float Sx = dx > 0 ? 1 : dx < 0 ? -1 : 0;
	float Sy = dy > 0 ? 1 : dy < 0 ? -1 : 0;
	float Sz = dz > 0 ? 1 : dz < 0 ? -1 : 0;
	
	if (dx == 0 && dy == 0 && dz == 0)
		return false;
	
	//-- coordonnées entières !
	int Px = int(x/CX);
	int Py = int(y/CY);
	int Pz = int(z/CZ);
	
	float Pfx, Pfy, Pfz;
	
	//-- distance pour les premiers points
	if( Sx > 0) { Pfx = (((Px + 1)*CX - x) * Tan_beta)*(((Px + 1)*CX - x) * Tan_beta) + DeltaXz*DeltaXz; }
	else { Pfx = ((x - Px*CX) * Tan_beta)*((x - Px*CX) * Tan_beta) + DeltaXz*DeltaXz; }
	
	if (Sy > 0) { Pfy = (((Py + 1)*CY - y) / Tan_beta)*
						(((Py + 1)*CY - y) / Tan_beta)+ (((Py + 1)*CY - y) * Tan_gamma)*
				(((Py + 1)*CY - y) * Tan_gamma);}
	else { Pfy = ((y - Py*CY) / Tan_beta)*((y - Py*CY) / Tan_beta)
				 + ((y - Py*CY) * Tan_gamma)*((y - Py*CY) * Tan_gamma); }
	
	if(Sz > 0 ){ Pfz = (((Pz + 1)*CZ - z) / Tan_gamma)*
					   (((Pz + 1)*CZ - z) / Tan_gamma)+ DeltaZx*DeltaZx;}
	else { Pfz = ((z - Pz*CZ) / Tan_gamma)*((z - Pz*CZ) / Tan_gamma) + DeltaZx*DeltaZx;}
	
	
	
	while ( Pfx + (x*CX)*(x*CX) < Max_Dist_carre)// et … )
	{
		if (Pfx < Pfy && Pfx < Pfz) { //le plus petit
			Pfx += DeltaX;
			Px += Sx;
		}
		else if (Pfy < Pfz) { //le plus petit
			Pfy += DeltaY;
			Py += Sy;
		}
		else {
			Pfz += DeltaZ;
			Pz += Sz;
		}
		
		BlockType type = manager.getBlockType(sf::Vector3i(Px,Py,Pz));
		std::cout << "BT "<<type<<std::endl;
		
		if (type > Block::Air) {
			
			selectCube.x = Px;
			selectCube.y = Py;
			selectCube.z = Pz;
			
			nextNorm.x = -Sx;
			nextNorm.y = -Sy;
			nextNorm.z = -Sz;
			
			return true;
		}
		//si case (Px, Py, Pz) solide -> return TRUE, (Px, Py, Pz), (-Sx, -Sy, -Sz)
	}
	return false ;//etc.
	
}
