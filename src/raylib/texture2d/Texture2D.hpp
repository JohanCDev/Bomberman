/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** Texture2d
*/

#ifndef TEXTURE2D_HPP_
#define TEXTURE2D_HPP_

#include "../Raylib.hpp"

namespace indie {
    namespace raylib {
        class Texture2D {
            public:
                Texture2D(unsigned int id, int width, int height, int mipmaps, int format);
                ~Texture2D() = default;

                /**
                * @brief Get id
                */
                unsigned int getId() const;

                /**
                * @brief Set id
                */
                void setId(unsigned int id);

                /**
                * @brief Get width
                */
                int getWidth() const;

                /**
                * @brief Set width
                */
                void setWidth(int width);

                /**
                * @brief Get height
                */
                int getHeight() const;

                /**
                * @brief Set height
                */
                void setHeight(int height);

                /**
                * @brief Get mipmaps
                */
                int getMipmaps() const;

                /**
                * @brief Set mipmaps
                */
                void setMipmaps(int mipmaps);

                /**
                * @brief Get format@
                */
                int getFormat() const;

                /**
                * @brief Set format
                */
                void setFormat(int format);

                /**
                * @brief Draw a Texture2D
                */
                void draw(int posX, int posY, ::Color tint);
                static void draw(::Texture2D texture, int posX, int posY, ::Color tint);

                /**
                * @brief Draw a Texture2D with position defined as Vector2
                */
                void drawV(::Vector2 position, ::Color tint);
                static void drawV(::Texture2D texture, ::Vector2 position, ::Color tint);

                /**
                * @brief Draw a Texture2D with extended parameters
                */
                void drawEx(::Vector2 position, float rotation, float scale, ::Color tint);
                static void drawEx(::Texture2D texture, ::Vector2 position, float rotation, float scale, ::Color tint);

                /**
                * @brief Draw a part of a texture defined by a rectangle
                */
                void drawRec(::Rectangle source, ::Vector2 position, ::Color tint);
                static void drawRec(::Texture2D texture, ::Rectangle source, ::Vector2 position, ::Color tint);

                /**
                * @brief Draw texture quad with tiling and offset parameters
                */
                void drawQuad(::Vector2 tiling, ::Vector2 offset, ::Rectangle quad, ::Color tint);
                static void drawQuad(::Texture2D texture, ::Vector2 tiling, ::Vector2 offset, ::Rectangle quad, ::Color tint);

                /**
                * @brief Draw part of a texture (defined by a rectangle) with rotation and scale tiled into dest.
                */
                void drawTiled(::Rectangle source, ::Rectangle dest, ::Vector2 origin, float rotation, float scale, ::Color tint);
                static void drawTiled(::Texture2D texture, ::Rectangle source, ::Rectangle dest, ::Vector2 origin, float rotation, float scale, ::Color tint);

                /**
                * @brief Draw a part of a texture defined by a rectangle with 'pro' parameters
                */
                void drawPro(::Rectangle source, ::Rectangle dest, ::Vector2 origin, float rotation, ::Color tint);
                static void drawPro(::Texture2D texture, ::Rectangle source, ::Rectangle dest, ::Vector2 origin, float rotation, ::Color tint);

                /**
                * @brief Draws a texture (or part of it) that stretches or shrinks nicely
                */
                void drawNPatch(::NPatchInfo nPatchInfo, ::Rectangle dest, ::Vector2 origin, float rotation, ::Color tint);
                static void drawNPatch(::Texture2D texture, ::NPatchInfo nPatchInfo, ::Rectangle dest, ::Vector2 origin, float rotation, ::Color tint);

                /**
                * @brief Draw a textured polygon
                */
                void drawPoly(::Vector2 center, ::Vector2 *points, ::Vector2 *texcoords, int pointsCount, ::Color tint);
                static void drawPoly(::Texture2D texture, ::Vector2 center, ::Vector2 *points, ::Vector2 *texcoords, int pointsCount, ::Color tint);

                /**
                * @brief Load texture from file into GPU memory (VRAM)
                */
                static ::Texture2D load(const char *fileName);

                /**
                * @brief Load texture from image data
                */
                static ::Texture2D loadFromImage(::Image image);

                /**
                * @brief Unload texture from GPU memory (VRAM)
                */
                void unload(void);
                static void unload(::Texture2D texture);

                /**
                * @brief Update GPU texture with new data
                */
                void update(const void *pixels);
                static void update(::Texture2D texture, const void *pixels);

            private:
                ::Texture2D _texture;
        };
    }
}

#endif /* !TEXTURE2D_HPP_ */
