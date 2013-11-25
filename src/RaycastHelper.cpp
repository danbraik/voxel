#include <iostream>
#include <cmath>
#include "RaycastHelper.hpp"

RaycastHelper::RaycastHelper()
{
}


inline float mod(float value) {
//	modulus *=1000000;
//	int vint = value*1000000;
	
//   return
//   ((vint % modulus + modulus) % modulus) /1000000.0;
	int q = static_cast<int>(value);
	if (q < 0)
		--q;
	return value - static_cast<float>(q);
}

float intbound(float s, float ds) {
  // Find the smallest positive t such that s+t*ds is an integer.
  if (ds < 0) {
    return intbound(-s, -ds);
  } else {
    s = mod(s); // mod(s,1)
    // problem is now s+t*ds = 1
    return (1-s)/ds;
  }
}

float signum(float x) {
  return x > 0 ? 1 : x < 0 ? -1 : 0;
}


bool RaycastHelper::raycast(ChunkManager &manager, 
							sf::Vector3f &origin, 
							sf::Vector3f &direction, 
							sf::Vector3i &selectCube, 
							sf::Vector3i &nextNorm)
{
	
		 // Cube containing origin point.
         float x = int(origin.x);
         float y = int(origin.y);
         float z = int(origin.z);
         // Break out direction vector.
         float dx = direction.x;
         float dy = direction.y;
         float dz = direction.z;
         // Direction to increment x,y,z when stepping.
         float stepX = signum(dx);
         float stepY = signum(dy);
         float stepZ = signum(dz);
         // See description above. The initial values depend on the fractional
         // part of the origin.
         float tMaxX = intbound(origin.x, dx);
         float tMaxY = intbound(origin.y, dy);
         float tMaxZ = intbound(origin.z, dz);
         // The change in t when taking a step (always positive).
         float tDeltaX = stepX/dx;
         float tDeltaY = stepY/dy;
         float tDeltaZ = stepZ/dz;
         // Buffer for reporting faces to the callback.
         sf::Vector3i face;
         
         // Avoids an infinite loop.
         if (dx == 0 && dy == 0 && dz == 0)
           return false;
         
         // Rescale from units of 1 cube-edge to units of 'direction' so we can
         // compare with 't'.
         float radius = 25 / std::sqrt(dx*dx+dy*dy+dz*dz);
         
		 int tour = 0;
		 
         while (tour++ < radius)
		 {
           
           // Invoke the callback, unless we are not *yet* within the bounds of the
           // world.
           
             //if (callback(x, y, z, blocks[x*wy*wz + y*wz + z], face))
               //break;
			 BlockType type = manager.getBlockType(BlockCoordinate(x,y,z));
			 //std::cout << "BT " << type << std::endl;
			 if (type > Block::Patate) {
				 selectCube = sf::Vector3i(x,y,z);
				 nextNorm = face;
				 //std::cout << "--" << std::endl;
				 return true;
			 }
           
           // tMaxX stores the t-value at which we cross a cube boundary along the
           // X axis, and similarly for Y and Z. Therefore, choosing the least tMax
           // chooses the closest cube boundary. Only the first case of the four
           // has been commented in detail.
           if (tMaxX < tMaxY) {
             if (tMaxX < tMaxZ) {
               if (tMaxX > radius) break;
               // Update which cube we are now in.
               x += stepX;
               // Adjust tMaxX to the next X-oriented boundary crossing.
               tMaxX += tDeltaX;
               // Record the normal vector of the cube face we entered.
               face.x = -stepX;
               face.y = 0;
               face.z = 0;
             } else {
               if (tMaxZ > radius) break;
               z += stepZ;
               tMaxZ += tDeltaZ;
               face.x = 0;
               face.y = 0;
               face.z = -stepZ;
             }
           } else {
             if (tMaxY < tMaxZ) {
               if (tMaxY > radius) break;
               y += stepY;
               tMaxY += tDeltaY;
               face.x = 0;
               face.y = -stepY;
               face.z = 0;
             } else {
               // Identical to the second case, repeated for simplicity in
               // the conditionals.
               if (tMaxZ > radius) break;
               z += stepZ;
               tMaxZ += tDeltaZ;
               face.x = 0;
               face.y = 0;
               face.z = -stepZ;
             }
           }
         }
		 
		 //std::cout << "--" << std::endl;
		 return false;
	
}
