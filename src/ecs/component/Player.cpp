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
    this->_drawType = ecs::drawableType::D3;
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
    Vector3 vec = {transformCompo.getX(), transformCompo.getY(), transformCompo.getZ()};
    indie::raylib::Sphere sphere(vec, this->_radius, this->_color);
    sphere.draw();
    // indie::raylib::drawSphere(vec, this->_radius, this->_color);
}

void ecs::Player::update(ecs::Transform transformCompo)
{
    (void)transformCompo;
}

bool ecs::Player::isDrawable(ecs::drawableType drawType)
{
    if (this->_drawType == drawType) {
        return (true);
    } else {
        return (false);
    }
}
