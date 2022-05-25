/*
** EPITECH PROJECT, 2022
** IndieStudio_Commun
** File description:
** Player
*/

#include "Component.hpp"

ecs::Player::Player()
{
}

ecs::Player::Player(std::string texture, float radius, Color color)
{
    this->_radius = radius;
    this->_color = color;
    this->_texture = texture;
}

ecs::Player::~Player()
{
}

ecs::compoType ecs::Player::getType()
{
    return (ecs::compoType::PLAYER);
}

void ecs::Player::draw(ecs::Transform transformCompo)
{
    Raylib raylib;
    Vector3 vec = {transformCompo.getX(), transformCompo.getY(), transformCompo.getZ()};
    raylib.drawSphere(vec, this->_radius, this->_color);
}

void ecs::Player::update(ecs::Transform transformCompo)
{
    (void)transformCompo;
}
