#include "Freeflycamera.h"

#include <cmath>
#include <GL/glu.h>

FreeFlyCamera::FreeFlyCamera(const Vector3D & position)
{
    _position = position;
    _phi = 0;
    _theta = 0;
    VectorsFromAngles();

    _speed = 0.01;
    _sensivity = 0.2;
    _verticalMotionActive = false;
    
    _keystates[forward] = false;
    _keystates[backward] = false;
    _keystates[strafe_left] = false;
    _keystates[strafe_right] = false;
    _keystates[boost] = false;
}

void FreeFlyCamera::OnMouseMotion(int xrel, int yrel)
{
    _theta -= xrel*_sensivity;
    _phi -= yrel*_sensivity;
    VectorsFromAngles();
}

void FreeFlyCamera::OnMouseButton(bool wheelup)
{
    if (wheelup) //coup de molette vers le haut
    {
        _verticalMotionActive = true;
        _timeBeforeStoppingVerticalMotion = 250;
        _verticalMotionDirection = 1;

    }
    else //coup de molette vers le bas
    {
        _verticalMotionActive = true;
        _timeBeforeStoppingVerticalMotion = 250;
        _verticalMotionDirection = -1;
    }
}

void FreeFlyCamera::OnKeyboard(int key, bool state)
{
    _keystates[key] = state;
}

void FreeFlyCamera::animate(sf::Int32 timestep)
{
    double realspeed = (_keystates[boost])?10*_speed:_speed;
    if (_keystates[forward])
        _position += _forward * (realspeed * timestep);
    if (_keystates[backward])
        _position -= _forward * (realspeed * timestep);
    if (_keystates[strafe_left])
        _position += _left * (realspeed * timestep);
    if (_keystates[strafe_right])
        _position -= _left * (realspeed * timestep);
    if (_verticalMotionActive)
    {
        if (timestep > _timeBeforeStoppingVerticalMotion)
            _verticalMotionActive = false;
        else
            _timeBeforeStoppingVerticalMotion -= timestep;
        _position += Vector3D(0,0,_verticalMotionDirection*realspeed*timestep);
    }
    _target = _position + _forward;

}

void FreeFlyCamera::setSpeed(double speed)
{
    _speed = speed;
}

void FreeFlyCamera::setSensivity(double sensivity)
{
    _sensivity = sensivity;
}

void FreeFlyCamera::setPosition(const Vector3D & position)
{
    _position = position;
    _target = _position + _forward;
}

void FreeFlyCamera::VectorsFromAngles()
{
    static const Vector3D up(0,0,1);
    if (_phi > 89)
        _phi = 89;
    else if (_phi < -89)
        _phi = -89;
    double r_temp = std::cos(_phi*M_PI/180);
    _forward.Z = std::sin(_phi*M_PI/180);
    _forward.X = r_temp*std::cos(_theta*M_PI/180);
    _forward.Y = r_temp*std::sin(_theta*M_PI/180);

    _left = up.crossProduct(_forward);
    _left.normalize();

    _target = _position + _forward;
}

void FreeFlyCamera::look()
{
    gluLookAt(_position.X,_position.Y,_position.Z,
              _target.X,_target.Y,_target.Z,
              0,0,1);
}

FreeFlyCamera::~FreeFlyCamera()
{
 
}
