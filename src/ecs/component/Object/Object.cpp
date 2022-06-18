/**
 * @file Object.cpp
 * @author Johan Chrillesen (johan.chrillesen@epitech.eu)
 * @brief Object component source file
 * @version 0.1
 * @date 2022-06-01
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "Object.hpp"
#include "../IComponent.hpp"

indie::ecs::component::Object::Object(
    std::string const &texturePath, std::string const &objectPath, std::string const &animationsPath)
{
    this->_height = 0.0;
    this->_width = 0.0;
    this->_color = WHITE;
    this->_texturePath = texturePath;
    this->_texture = indie::raylib::Texture2D::load(texturePath.c_str());
    this->_modelPath = objectPath;
    this->_model = indie::raylib::Model::load(this->_modelPath.c_str());
    this->_animationsPath = objectPath;
    this->_compoType = indie::ecs::component::compoType::ANIMATED;
    this->_drawableType = indie::ecs::component::drawableType::OBJECT;
    this->_maxCounter = 0;
    this->_animationCounter = 0;
}

indie::ecs::component::Object::Object(std::string const &texturePath, std::string const &objectPath)
{
    this->_height = 0.0;
    this->_width = 0.0;
    this->_color = WHITE;
    this->_texturePath = texturePath;
    this->_texture = indie::raylib::Texture2D::load(texturePath.c_str());
    this->_modelPath = objectPath;
    this->_model = indie::raylib::Model::load(objectPath.c_str());
    indie::raylib::Model::setMaterialTexture(&this->_model.materials[0], MATERIAL_MAP_DIFFUSE, this->_texture);
    this->_animationsPath = "";
    this->_compoType = indie::ecs::component::compoType::MODEL;
    this->_drawableType = indie::ecs::component::drawableType::OBJECT;
    this->_maxCounter = 0;
    this->_animationCounter = 0;
    this->_scale.x = 0.0f;
    this->_scale.y = 0.0f;
    this->_scale.z = 0.0f;
}

indie::ecs::component::Object::Object(
    std::string const &texturePath, std::string const &objectPath, vec3f scaleVec, vec3f rotationVec, float orientation)
{
    this->_height = 0.0;
    this->_width = 0.0;
    this->_color = WHITE;
    this->_texturePath = texturePath;
    this->_texture = indie::raylib::Texture2D::load(texturePath.c_str());
    this->_modelPath = objectPath;
    this->_model = indie::raylib::Model::load(objectPath.c_str());
    indie::raylib::Model::setMaterialTexture(&this->_model.materials[0], MATERIAL_MAP_DIFFUSE, this->_texture);
    this->_animationsPath = "";
    this->_compoType = indie::ecs::component::compoType::MODEL;
    this->_drawableType = indie::ecs::component::drawableType::OBJECT;
    this->_maxCounter = 0;
    this->_animationCounter = 0;
    this->_scale = scaleVec;
    this->_rotationVec = rotationVec;
    this->_orientation = orientation;
}

indie::ecs::component::Object::~Object()
{
}

indie::ecs::component::compoType indie::ecs::component::Object::getType() const
{
    return (this->_compoType);
}

indie::ecs::component::drawableType indie::ecs::component::Object::getDrawType()
{
    return (this->_drawableType);
}

Color indie::ecs::component::Object::getColor()
{
    return (this->_color);
}

float indie::ecs::component::Object::getHeight()
{
    return (this->_height);
}

float indie::ecs::component::Object::getWidth()
{
    return (this->_width);
}

std::string indie::ecs::component::Object::getTexturePath() const
{
    return (this->_texturePath);
}

void indie::ecs::component::Object::setTexturePath(std::string texturePath)
{
    this->_texturePath = texturePath;
}

Texture2D indie::ecs::component::Object::getTexture() const
{
    return (this->_texture);
}

void indie::ecs::component::Object::setTexture(std::string texturePath)
{
    indie::raylib::Texture2D::unload(this->_texture);
    this->_texturePath = texturePath;
    this->_texture = indie::raylib::Texture2D::load(texturePath.c_str());
}

std::string indie::ecs::component::Object::getModelPath() const
{
    return (this->_modelPath);
}

void indie::ecs::component::Object::setModelPath(std::string modelPath)
{
    this->_modelPath = modelPath;
}

Model indie::ecs::component::Object::getModel() const
{
    return (this->_model);
}

void indie::ecs::component::Object::setModel(std::string modelPath)
{
    indie::raylib::Model::unload(this->_model);
    this->_modelPath = modelPath;
    this->_model = indie::raylib::Model::load(modelPath.c_str());
}

std::string indie::ecs::component::Object::getAnimationsPath() const
{
    return (this->_animationsPath);
}

void indie::ecs::component::Object::setAnimationsPath(std::string animationsPath)
{
    this->_animationsPath = animationsPath;
}

::ModelAnimation *indie::ecs::component::Object::getAnimations() const
{
    return (this->_modelAnimation);
}

void indie::ecs::component::Object::setAnimations(std::string animationsPath)
{
    indie::raylib::Model::unloadModelAnimations(this->_modelAnimation, this->_maxCounter);
    this->_animationsPath = animationsPath;
    this->_modelAnimation = indie::raylib::Model::loadAnimation(animationsPath.c_str(), &this->_maxCounter);
}

void indie::ecs::component::Object::setOrientation(indie::ecs::component::Object::ORIENTATION orientation)
{
    this->_orientation = orientation;
}

float indie::ecs::component::Object::getOrientation() const
{
    return this->_orientation;
}

indie::vec3f indie::ecs::component::Object::getScale() const
{
    return (this->_scale);
}

indie::vec3f indie::ecs::component::Object::getRotationVec() const
{
    return (this->_rotationVec);
}