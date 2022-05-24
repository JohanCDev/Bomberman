/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** RCamera3D
*/

#include "Camera3D.hpp"

Raylib::Camera3D::Camera3D(::Vector3 position, ::Vector3 target, ::Vector3 up, float fovy, int projection)
{
    _camera.position = position;
    _camera.target = target;
    _camera.up = up;
    _camera.fovy = fovy;
    _camera.projection = projection;
}

void Raylib::Camera3D::setPosition(float newX, float newY, float newZ)
{
    _camera.position.x = newX;
    _camera.position.y = newY;
    _camera.position.z = newZ;
}

::Vector3 Raylib::Camera3D::getPosition() const
{
    return _camera.position;
}

void Raylib::Camera3D::setTarget(float newX, float newY, float newZ)
{
    _camera.target.x = newX;
    _camera.target.y = newY;
    _camera.target.z = newZ;
}

::Vector3 Raylib::Camera3D::getTarget() const
{
    return _camera.target;
}

void Raylib::Camera3D::setUp(float newX, float newY, float newZ)
{
    _camera.up.x = newX;
    _camera.up.y = newY;
    _camera.up.z = newZ;
}

::Vector3 Raylib::Camera3D::getUp() const
{
    return _camera.up;
}

void Raylib::Camera3D::setFovy(float newFovy)
{
    _camera.fovy = newFovy;
}

float Raylib::Camera3D::getFovy() const
{
    return _camera.fovy;
}

void Raylib::Camera3D::setProjection(int newProjection)
{
    _camera.projection = newProjection;
}

int Raylib::Camera3D::getProjection() const
{
    return _camera.projection;
}

// void Raylib::Camera3D::BeginMode()
// {
//     ::BeginMode3D(_camera);
// }
