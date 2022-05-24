/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** RCamera3D
*/

#include "Camera3D.hpp"

Raylib::Camera3D::Camera3D(::Vector3 position, ::Vector3 target, ::Vector3 up, float fovy, int type) : _position(position), _target(target),  _up(up),  _fovy(fovy),  _type(type) {}
