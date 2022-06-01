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
    if (this->_texture_path == "") {
        Vector3 vec = {transformCompo.getX(), transformCompo.getY(), transformCompo.getZ()};
        indie::raylib::Cube cube(transformCompo.getX(), transformCompo.getY(), transformCompo.getZ(), this->_width, this->_height, (float)2.0, WHITE);

        cube.draw();
        cube.drawWires();
    } else {
        Vector3 vec = {transformCompo.getX(), transformCompo.getY(), transformCompo.getZ()};
        indie::raylib::Cube cube(transformCompo.getX(), transformCompo.getY(), transformCompo.getZ(), this->_width, this->_height, (float)2.0, WHITE);
        cube.drawTexture(this->_texture, this->_width, this->_height, (float)2.0);
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
