/**
 * @file Texture2D.cpp
 * @author Simon Le Fourn (simon.le-fourn@epitech.eu)
 * @brief Texture2D encapsulation source file
 * @version 0.1
 * @date 2022-05-26
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "Texture2D.hpp"

indie::raylib::Texture2D::Texture2D(unsigned int id, int width, int height, int mipmaps, int format)
{
    _texture.id = id;
    _texture.width = width;
    _texture.height = height;
    _texture.mipmaps = mipmaps;
    _texture.format = format;
}

unsigned int indie::raylib::Texture2D::getId() const
{
    return _texture.id;
}

void indie::raylib::Texture2D::setId(unsigned int id)
{
    _texture.id = id;
}

int indie::raylib::Texture2D::getWidth() const
{
    return _texture.width;
}

void indie::raylib::Texture2D::setWidth(int width)
{
    _texture.width = width;
}

int indie::raylib::Texture2D::getHeight() const
{
    return _texture.height;
}

void indie::raylib::Texture2D::setHeight(int height)
{
    _texture.height = height;
}

int indie::raylib::Texture2D::getMipmaps() const
{
    return _texture.mipmaps;
}

void indie::raylib::Texture2D::setMipmaps(int mipmaps)
{
    _texture.mipmaps = mipmaps;
}

int indie::raylib::Texture2D::getFormat() const
{
    return _texture.format;
}

void indie::raylib::Texture2D::setFormat(int format)
{
    _texture.format;
}

void indie::raylib::Texture2D::draw(int posX, int posY, ::Color tint)
{
    ::DrawTexture(_texture, posX, posY, tint);
}

void indie::raylib::Texture2D::draw(::Texture2D texture, int posX, int posY, ::Color tint)
{
    ::DrawTexture(texture, posX, posY, tint);
}

void indie::raylib::Texture2D::drawV(::Vector2 position, ::Color tint)
{
    ::DrawTextureV(_texture, position, tint);
}

void indie::raylib::Texture2D::drawV(::Texture2D texture, ::Vector2 position, ::Color tint)
{
    ::DrawTextureV(texture, position, tint);
}

void indie::raylib::Texture2D::drawEx(::Vector2 position, float rotation, float scale, ::Color tint)
{
    ::DrawTextureEx(_texture, position, rotation, scale, tint);
}

void indie::raylib::Texture2D::drawEx(
    ::Texture2D texture, ::Vector2 position, float rotation, float scale, ::Color tint)
{
    ::DrawTextureEx(texture, position, rotation, scale, tint);
}

void indie::raylib::Texture2D::drawRec(::Rectangle source, ::Vector2 position, ::Color tint)
{
    ::DrawTextureRec(_texture, source, position, tint);
}

void indie::raylib::Texture2D::drawRec(::Texture2D texture, ::Rectangle source, ::Vector2 position, ::Color tint)
{
    ::DrawTextureRec(texture, source, position, tint);
}

void indie::raylib::Texture2D::drawQuad(::Vector2 tiling, ::Vector2 offset, ::Rectangle quad, ::Color tint)
{
    ::DrawTextureQuad(_texture, tiling, offset, quad, tint);
}

void indie::raylib::Texture2D::drawQuad(
    ::Texture2D texture, ::Vector2 tiling, ::Vector2 offset, ::Rectangle quad, ::Color tint)
{
    ::DrawTextureQuad(texture, tiling, offset, quad, tint);
}

void indie::raylib::Texture2D::drawTiled(
    ::Rectangle source, ::Rectangle dest, ::Vector2 origin, float rotation, float scale, ::Color tint)
{
    ::DrawTextureTiled(_texture, source, dest, origin, rotation, scale, tint);
}

void indie::raylib::Texture2D::drawTiled(::Texture2D texture, ::Rectangle source, ::Rectangle dest, ::Vector2 origin,
    float rotation, float scale, ::Color tint)
{
    ::DrawTextureTiled(texture, source, dest, origin, rotation, scale, tint);
}

void indie::raylib::Texture2D::drawPro(
    ::Rectangle source, ::Rectangle dest, ::Vector2 origin, float rotation, ::Color tint)
{
    ::DrawTexturePro(_texture, source, dest, origin, rotation, tint);
}

void indie::raylib::Texture2D::drawPro(
    ::Texture2D texture, ::Rectangle source, ::Rectangle dest, ::Vector2 origin, float rotation, ::Color tint)
{
    ::DrawTexturePro(texture, source, dest, origin, rotation, tint);
}

void indie::raylib::Texture2D::drawNPatch(
    ::NPatchInfo nPatchInfo, ::Rectangle dest, ::Vector2 origin, float rotation, ::Color tint)
{
    ::DrawTextureNPatch(_texture, nPatchInfo, dest, origin, rotation, tint);
}

void indie::raylib::Texture2D::drawNPatch(
    ::Texture2D texture, ::NPatchInfo nPatchInfo, ::Rectangle dest, ::Vector2 origin, float rotation, ::Color tint)
{
    ::DrawTextureNPatch(texture, nPatchInfo, dest, origin, rotation, tint);
}

void indie::raylib::Texture2D::drawPoly(
    ::Vector2 center, Vector2 *points, ::Vector2 *texcoords, int pointsCount, ::Color tint)
{
    ::DrawTexturePoly(_texture, center, points, texcoords, pointsCount, tint);
}

void indie::raylib::Texture2D::drawPoly(
    ::Texture2D texture, ::Vector2 center, Vector2 *points, ::Vector2 *texcoords, int pointsCount, ::Color tint)
{
    ::DrawTexturePoly(texture, center, points, texcoords, pointsCount, tint);
}

::Texture2D indie::raylib::Texture2D::load(const char *fileName)
{
    return ::LoadTexture(fileName);
}

::Texture2D indie::raylib::Texture2D::loadFromImage(::Image image)
{
    return ::LoadTextureFromImage(image);
}

void indie::raylib::Texture2D::unload()
{
    ::UnloadTexture(_texture);
}

void indie::raylib::Texture2D::unload(::Texture2D texture)
{
    ::UnloadTexture(texture);
}

void indie::raylib::Texture2D::update(const void *pixels)
{
    ::UpdateTexture(_texture, pixels);
}

void indie::raylib::Texture2D::update(::Texture2D texture, const void *pixels)
{
    ::UpdateTexture(texture, pixels);
}
