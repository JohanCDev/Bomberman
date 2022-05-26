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
    this->_drawType = ecs::drawableType::D3;
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
        Vector3 vec = {transformCompo.getX(), transformCompo.getY(), transformCompo.getZ()};
        raylib.drawRectangle3D(vec, this->_width, this->_height, (float)2.0, this->_color);
        raylib.drawCubeWires(vec, this->_width, this->_height, (float)2.0, WHITE);
    } else {
        Vector3 vec = {transformCompo.getX(), transformCompo.getY(), transformCompo.getZ()};
        raylib.drawCubeTexture(this->_texture, vec, this->_width, this->_height, (float)2.0, this->_color);
    }
}

bool ecs::Wall::isDrawable(ecs::drawableType drawType)
{
    if (this->_drawType == drawType) {
        return (true);
    } else {
        return (false);
    }
}