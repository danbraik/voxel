#ifndef FREEFLYCAMERA_H
#define FREEFLYCAMERA_H

#include <SFML/System.hpp>
#include "Vector3d.h"
#include <map>
#include <string>

class FreeFlyCamera
{
public:
    FreeFlyCamera(const Vector3D & position = Vector3D(0,0,0));

    virtual void OnMouseMotion(int xrel, int yrel);
    virtual void OnMouseButton(bool wheelup); // false = wheeldown
    virtual void OnKeyboard(int key, bool state);

    virtual void animate(sf::Int32 timestep);
    virtual void setSpeed(double speed);
    virtual void setSensivity(double sensivity);

    virtual void setPosition(const Vector3D & position);
	virtual const Vector3D & getTargetPosition();

    virtual void look();

    virtual ~FreeFlyCamera();
	
	enum { forward, 
		   backward, 
		   strafe_left,
		   strafe_right,
		   boost};
protected:
    double _speed;
    double _sensivity;

    //vertical motion stuffs
    sf::Int32 _timeBeforeStoppingVerticalMotion;
    bool _verticalMotionActive;
    int _verticalMotionDirection;

	bool _keystates[5];
    

    Vector3D _position;
    Vector3D _target;
    Vector3D _forward;
    Vector3D _left;
    double _theta;
    double _phi;

    void VectorsFromAngles();
    //void Init();
};

#endif //FREEFLYCAMERA_H
