/*
** EPITECH PROJECT, 2022
** IndieStudio_Commun
** File description:
** Wall
*/

#include "Component.hpp"

ecs::Wall::Wall()
{
}

ecs::Wall::Wall(std::string texture, float height, float width, Color color)
{
    this->_height = height;
    this->_width = width;
    this->_color = color;
    this->_texture_path = texture;
    this->_texture = LoadTexture(this->_texture_path.c_str());
}

ecs::Wall::~Wall()
{
}

ecs::compoType ecs::Wall::getType()
{
    return (ecs::compoType::WALL);
}

void ecs::Wall::draw(ecs::Transform transformCompo)
{
    Raylib raylib;
    if (this->_texture_path == "") {
        Vector3 vec = (Vector3){transformCompo.getX(), transformCompo.getY(), transformCompo.getZ()};
        raylib.drawRectangle3D(vec, this->_width, this->_height, (float)2.0, this->_color);
    } else {
        // draw 3d rectangle with texture
    }
}
