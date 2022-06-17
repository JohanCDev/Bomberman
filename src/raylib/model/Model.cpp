/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** Model
*/

#include "Model.hpp"

::Model indie::raylib::Model::load(const char *fileName)
{
    return ::LoadModel(fileName);
}

::Model indie::raylib::Model::loadFromMesh(::Mesh mesh)
{
    return ::LoadModelFromMesh(mesh);
}

void indie::raylib::Model::updateModelAnimation(::Model model, ::ModelAnimation anim, int frame)
{
    ::UpdateModelAnimation(model, anim, frame);
}

void indie::raylib::Model::unloadModel(::Model model)
{
    ::UnloadModel(model);
}

void indie::raylib::Model::unloadTexture(::Texture2D texture)
{
    ::UnloadTexture(texture);
}

void indie::raylib::Model::unloadKeepMeshes(::Model model)
{
    ::UnloadModelKeepMeshes(model);
}

void indie::raylib::Model::draw(::Model model, ::Vector3 position, float scale, ::Color tint)
{
    ::DrawModel(model, position, scale, tint);
}

void indie::raylib::Model::drawEx(
    ::Model model, ::Vector3 position, ::Vector3 rotationAxis, float rotationAngle, ::Vector3 scale, ::Color tint)
{
    ::DrawModelEx(model, position, rotationAxis, rotationAngle, scale, tint);
}

void indie::raylib::Model::drawWires(::Model model, ::Vector3 position, float scale, ::Color tint)
{
    ::DrawModelWires(model, position, scale, tint);
}

void indie::raylib::Model::drawWiresEx(
    ::Model model, ::Vector3 position, ::Vector3 rotationAxis, float rotationAngle, ::Vector3 scale, ::Color tint)
{
    ::DrawModelWiresEx(model, position, rotationAxis, rotationAngle, scale, tint);
}
