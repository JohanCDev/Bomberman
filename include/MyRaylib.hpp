/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** MyRaylib
*/

#ifndef MYRAYLIB_HPP_
#define MYRAYLIB_HPP_

#include "Vec3.hpp"

#define RBLACK (rColor){ 0, 0, 0, 255 }
#define RRED (rColor){ 255, 0, 0, 255 }
#define RBLUE (rColor){ 0, 0, 255, 255 }
#define RGREEN (rColor){ 0, 255, 0, 255 }
#define RWHITE (rColor){ 255, 255, 255, 255 }

namespace indie
{
    namespace ray
    {

        typedef struct {
            unsigned char r;
            unsigned char g;
            unsigned char b;
            unsigned char a;
        } rColor;

        /**
         * @brief 3D Camera implementation
         */
        typedef struct RCamera3D {
            /**
             * @brief Camera position
             */
            indie::vec3u position;
            /**
             * @brief Camera target it looks at
             */
            indie::vec3u target;
            /**
             * @brief Camera up vector (rotation over its axis)
             */
            indie::vec3u up;
            /**
             * @brief Camera field-of-view apperture in Y (degrees) in perspective, used as near plane width in
             * orthographic
             */
            float fovy;
            /**
             * @brief Camera projection: CAMERA_PERSPECTIVE or CAMERA_ORTHOGRAPHIC
             */
            int projection;
        } RCamera3D;

        // Rectangle, 4 components
        typedef struct RRectangle {
            float x;      // Rectangle top-left corner position x
            float y;      // Rectangle top-left corner position y
            float width;  // Rectangle width
            float height; // Rectangle height
        } RRectangle;

        // Image, pixel data stored in CPU memory (RAM)
        typedef struct RImage {
            void *data;  // Image raw data
            int width;   // Image base width
            int height;  // Image base height
            int mipmaps; // Mipmap levels, 1 by default
            int format;  // Data format (PixelFormat type)
        } RImage;

        // Texture, tex data stored in GPU memory (VRAM)
        typedef struct RTexture {
            unsigned int id; // OpenGL texture id
            int width;       // Texture base width
            int height;      // Texture base height
            int mipmaps;     // Mipmap levels, 1 by default
            int format;      // Data format (PixelFormat type)
        } RTexture;

        // Texture2D, same as Texture
        typedef RTexture Texture2D;

        // TextureCubemap, same as Texture
        typedef RTexture TextureCubemap;

        // RenderTexture, fbo for texture rendering
        typedef struct RRenderTexture {
            unsigned int id;  // OpenGL framebuffer object id
            RTexture texture; // Color buffer attachment texture
            RTexture depth;   // Depth buffer attachment texture
        } RRenderTexture;
    } // namespace ray
} // namespace indie

#endif /* !MYRAYLIB_HPP_ */
