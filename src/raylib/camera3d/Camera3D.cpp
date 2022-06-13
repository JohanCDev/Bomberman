/**
 * @file Camera3D.cpp
 * @author Simon Le Fourn (simon.le-fourn@epitech.eu)
 * @brief Camera3d encapsulation source file
 * @version 0.1
 * @date 2022-05-24
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "Camera3D.hpp"

indie::raylib::Camera3D::Camera3D(::Vector3 position, ::Vector3 target, ::Vector3 up, float fovy, int projection)
{
    _camera.position = position;
    _camera.target = target;
    _camera.up = up;
    _camera.fovy = fovy;
    _camera.projection = projection;
}

void indie::raylib::Camera3D::setPosition(float newX, float newY, float newZ)
{
    _camera.position.x = newX;
    _camera.position.y = newY;
    _camera.position.z = newZ;
}

::Vector3 indie::raylib::Camera3D::getPosition() const
{
    return _camera.position;
}

void indie::raylib::Camera3D::setTarget(float newX, float newY, float newZ)
{
    _camera.target.x = newX;
    _camera.target.y = newY;
    _camera.target.z = newZ;
}

::Vector3 indie::raylib::Camera3D::getTarget() const
{
    return _camera.target;
}

void indie::raylib::Camera3D::setUp(float newX, float newY, float newZ)
{
    _camera.up.x = newX;
    _camera.up.y = newY;
    _camera.up.z = newZ;
}

::Vector3 indie::raylib::Camera3D::getUp() const
{
    return _camera.up;
}

void indie::raylib::Camera3D::setFovy(float newFovy)
{
    _camera.fovy = newFovy;
}

float indie::raylib::Camera3D::getFovy() const
{
    return _camera.fovy;
}

void indie::raylib::Camera3D::setProjection(int newProjection)
{
    _camera.projection = newProjection;
}

int indie::raylib::Camera3D::getProjection() const
{
    return _camera.projection;
}

void indie::raylib::Camera3D::beginMode()
{
    ::BeginMode3D(_camera);
}

void indie::raylib::Camera3D::setMode(int mode)
{
    ::SetCameraMode(_camera, mode);
}

void indie::raylib::Camera3D::endMode()
{
    ::EndMode3D();
}

void indie::raylib::Camera3D::update()
{
    ::UpdateCamera(&_camera);
}
