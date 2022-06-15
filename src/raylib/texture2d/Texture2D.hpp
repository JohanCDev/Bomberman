/**
 * @file Texture2D.hpp
 * @author Simon Le Fourn (simon.le-fourn@epitech.eu)
 * @brief Texture2D encapsulation header file
 * @version 0.1
 * @date 2022-05-26
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef TEXTURE2D_HPP_
#define TEXTURE2D_HPP_

#include "../Raylib.hpp"

namespace indie
{
    namespace raylib
    {
        /// @brief Texture2d class encapsulation
        class Texture2D {
          public:
            /**
             * @brief Construct a new Texture 2 D object
             * 
             * @param id Texture ID
             * @param width Texture width
             * @param height Texture height
             * @param mipmaps Texture mipmaps
             * @param format Texture format
             */
            Texture2D(unsigned int id, int width, int height, int mipmaps, int format);
            /**
             * @brief Destroy the Texture 2 D object
             * 
             */
            ~Texture2D() = default;
            /**
             * @brief Get texture ID
             * 
             * @return int Texture ID
             */
            unsigned int getId() const;
            /**
             * @brief Set texture ID
             * 
             * @param id Texture ID
             */
            void setId(unsigned int id);
            /**
             * @brief Get texture width
             * 
             * @return int Texture width
             */
            int getWidth() const;
            /**
             * @brief Set texture width
             * 
             * @param width Texture width
             */
            void setWidth(int width);
            /**
             * @brief Get texture height
             * 
             * @return int Texture height
             */
            int getHeight() const;
            /**
             * @brief Set texture height
             * 
             * @param height Texture height
             */
            void setHeight(int height);
            /**
             * @brief Get texture mipmaps
             * 
             * @return int Texture mipmaps
             */
            int getMipmaps() const;
            /**
             * @brief Set texture mipmaps
             * 
             * @param mipmaps Texture mipmaps
             */
            void setMipmaps(int mipmaps);
            /**
             * @brief Get texture format
             * 
             * @return int Texture format
             */
            int getFormat() const;
            /**
             * @brief Set texture format
             * 
             * @param format Texture format
             */
            void setFormat(int format);
            /**
             * @brief Draw a Texture2D
             * 
             * @param posX Texture2D X position
             * @param posY Texture2D Y position
             * @param tint Texture2D color
             */
            void draw(int posX, int posY, ::Color tint);
            /**
             * @brief Draw a Texture2D
             * 
             * @param texture Texture object
             * @param posX Texture2D X position
             * @param posY Texture2D Y position
             * @param tint Texture2D color
             */
            static void draw(::Texture2D texture, int posX, int posY, ::Color tint);
            /**
             * @brief Draw a Texture2D with position defined as Vector2
             * 
             * @param position Texture2D position
             * @param tint Texture2D color
             */
            void drawV(::Vector2 position, ::Color tint);
            /**
             * @brief Draw a Texture2D with position defined as Vector2
             * 
             * @param texture Texture2D object
             * @param position Texture2D position
             * @param tint Texture2D color
             */
            static void drawV(::Texture2D texture, ::Vector2 position, ::Color tint);
            /**
             * @brief Draw a Texture2D with extended parameters
             * 
             * @param position Texture2D position
             * @param rotation Texture2D rotation
             * @param scale Texture2D scale
             * @param tint Texture2D color
             */
            void drawEx(::Vector2 position, float rotation, float scale, ::Color tint);
            /**
             * @brief Draw a Texture2D with extended parameters
             * 
             * @param texture Texture2D object
             * @param position Texture2D position
             * @param rotation Texture2D rotation
             * @param scale Texture2D scale
             * @param tint Texture2D color
             */
            static void drawEx(::Texture2D texture, ::Vector2 position, float rotation, float scale, ::Color tint);
            /**
             * @brief Draw a part of a texture defined by a rectangle
             * 
             * @param source Rectangle object
             * @param position Texture2D position
             * @param tint Texture2D color
             */
            void drawRec(::Rectangle source, ::Vector2 position, ::Color tint);
            /**
             * @brief Draw a part of a texture defined by a rectangle
             * 
             * @param texture Texture2D object
             * @param source Rectangle object
             * @param position Texture2D position
             * @param tint Texture2D color
             */
            static void drawRec(::Texture2D texture, ::Rectangle source, ::Vector2 position, ::Color tint);
            /**
             * @brief Draw texture quad with tiling and offset parameters
             * 
             * @param tiling Texture2D tiling
             * @param offset Texture2D offset
             * @param quad Texture2D quad
             * @param tint Texture2D color
             */
            void drawQuad(::Vector2 tiling, ::Vector2 offset, ::Rectangle quad, ::Color tint);
            /**
             * @brief Draw texture quad with tiling and offset parameters
             * 
             * @param texture Texture2D object
             * @param tiling Texture2D tiling
             * @param offset Texture2D offset
             * @param quad Texture2D quad
             * @param tint Texture2D color
             */
            static void drawQuad(
                ::Texture2D texture, ::Vector2 tiling, ::Vector2 offset, ::Rectangle quad, ::Color tint);
            /**
             * @brief Draw part of a texture (defined by a rectangle) with rotation and scale tiled into dest.
             * 
             * @param source Rectangle object
             * @param dest Rectangle object
             * @param origin Texture2D origin
             * @param rotation Texture2D rotation
             * @param scale Texture2D scale
             * @param tint Texture2D color
             */
            void drawTiled(
                ::Rectangle source, ::Rectangle dest, ::Vector2 origin, float rotation, float scale, ::Color tint);
            /**
             * @brief Draw part of a texture (defined by a rectangle) with rotation and scale tiled into dest.
             * 
             * @param texture Texture2D object
             * @param source Rectangle object
             * @param dest Rectangle object
             * @param origin Texture2D origin
             * @param rotation Texture2D rotation
             * @param scale Texture2D scale
             * @param tint Texture2D color
             */
            static void drawTiled(::Texture2D texture, ::Rectangle source, ::Rectangle dest, ::Vector2 origin,
                float rotation, float scale, ::Color tint);

            /**
             * @brief Draw a part of a texture defined by a rectangle with 'pro' parameters
             * 
             * @param source Rectangle object
             * @param dest Rectangle object
             * @param origin Texture2D origin
             * @param rotation Texture2D rotation
             * @param tint Texture2D color
             */
            void drawPro(::Rectangle source, ::Rectangle dest, ::Vector2 origin, float rotation, ::Color tint);
            /**
             * @brief Draw a part of a texture defined by a rectangle with 'pro' parameters
             * 
             * @param texture Texture2D object
             * @param source Rectangle object
             * @param dest Rectangle object
             * @param origin Texture2D origin
             * @param rotation Texture2D rotation
             * @param tint Texture2D color
             */
            static void drawPro(::Texture2D texture, ::Rectangle source, ::Rectangle dest, ::Vector2 origin,
                float rotation, ::Color tint);
            /**
             * @brief Draws a texture (or part of it) that stretches or shrinks nicely
             * 
             * @param nPatchInfo nPatchInfo object
             * @param dest Rectangle object
             * @param origin Texture2D origin
             * @param rotation Texture2D rotation
             * @param tint Texture2D color
             */
            void drawNPatch(::NPatchInfo nPatchInfo, ::Rectangle dest, ::Vector2 origin, float rotation, ::Color tint);
            /**
             * @brief Draws a texture (or part of it) that stretches or shrinks nicely
             * 
             * @param texture Texture2D object
             * @param nPatchInfo nPatchInfo object
             * @param dest Rectangle object
             * @param origin Texture2D origin
             * @param rotation Texture2D rotation
             * @param tint Texture2D color
             */
            static void drawNPatch(::Texture2D texture, ::NPatchInfo nPatchInfo, ::Rectangle dest, ::Vector2 origin,
                float rotation, ::Color tint);

            /**
             * @brief Draw a textured polygon
             * 
             * @param center Texture2D center
             * @param points Texture2D points
             * @param texcoords Texture2D coords
             * @param pointsCount Texture2D points count
             * @param tint Texture2D color
             */
            void drawPoly(::Vector2 center, ::Vector2 *points, ::Vector2 *texcoords, int pointsCount, ::Color tint);
            /**
             * @brief Draw a textured polygon
             * 
             * @param texture Texture2D object
             * @param center Texture2D center
             * @param points Texture2D points
             * @param texcoords Texture2D coords
             * @param pointsCount Texture2D points count
             * @param tint Texture2D color
             */
            static void drawPoly(::Texture2D texture, ::Vector2 center, ::Vector2 *points, ::Vector2 *texcoords,
                int pointsCount, ::Color tint);

            /**
             * @brief Load texture from file into GPU memory (VRAM)
             * 
             * @param fileName Filepath to the texture file
             * 
             * @return Texture2D The texture2D object
             */
            static ::Texture2D load(const char *fileName);

            /**
             * @brief Load texture from image data
             * 
             * @param image Image object
             * 
             * @return Texture2D The texture2D object
             */
            static ::Texture2D loadFromImage(::Image image);

            /**
             * @brief Unload texture from GPU memory (VRAM)
             */
            void unload(void);
            /**
             * @brief Unload texture from GPU memory (VRAM)
             * 
             * @param texture The texture2D object to unload
             */
            static void unload(::Texture2D texture);
            /**
             * @brief Update GPU texture with new data
             * 
             * @param pixels Pointer to data for update
             */
            void update(const void *pixels);
            /**
             * @brief Update GPU texture with new data
             * 
             * @param texture Texture2D object
             * @param pixels Pointer  to data for update
             */
            static void update(::Texture2D texture, const void *pixels);

          private:
            /**
             * @brief Texture2D object
             * 
             */
            ::Texture2D _texture;
        };
    } // namespace raylib
} // namespace indie

#endif /* !TEXTURE2D_HPP_ */
