/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** MyRaylib
*/

#ifndef MYRAYLIB_HPP_
#define MYRAYLIB_HPP_

#include "Vec2.hpp"
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

        /**
         * @brief 2D Camera implementation
         */
        typedef struct RCamera2D {
            /**
             * @brief Camera offset (displacement from target)
             */
            indie::vec2u offset;
            /**
             * @brief Camera target (rotation and zoom origin)
             */
            indie::vec2u target;
            /**
             * @brief Camera rotation in degrees
             *
             */
            float rotation;
            /**
             * @brief Camera zoom (scaling), should be 1.0f by default
             */
            float zoom;
        } RCamera2D;

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

        // GlyphInfo, font characters glyphs info
        typedef struct RGlyphInfo {
            int value;              // Character value (Unicode)
            int offsetX;            // Character offset X when drawing
            int offsetY;            // Character offset Y when drawing
            int advanceX;           // Character advance position X
            RImage image;            // Character image data
        } RGlyphInfo;

        // Font, font texture and GlyphInfo array data
        typedef struct RFont {
            int baseSize;           // Base size (default chars height)
            int glyphCount;         // Number of glyph characters
            int glyphPadding;       // Padding around the glyph characters
            Texture2D texture;      // Texture atlas containing the glyphs
            RRectangle *recs;        // Rectangles in texture for the glyphs
            RGlyphInfo *glyphs;      // Glyphs info data
        } RFont;
    } // namespace ray
} // namespace indie

#endif /* !MYRAYLIB_HPP_ */
