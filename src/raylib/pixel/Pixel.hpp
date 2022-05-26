/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** Pixel
*/

#ifndef PIXEL_HPP_
#define PIXEL_HPP_

#include "../Raylib.hpp"

namespace indie {
    namespace raylib {
        class Pixel {
            public:
                Pixel(::Vector2 position, ::Color color = BLACK);
                ~Pixel() = default;

                /**
                * @brief Get pixel position
                */
                ::Vector2 getPosition() const;

                /**
                * @brief Set pixel position
                */
                void setPosition(::Vector2 pos);

                /**
                * @brief Get pixel color
                */
                ::Color getColor() const;

                /**
                * @brief Set pixel color
                */
                void setColor(::Color color);

                /**
                * @brief Draw a pixel (Vector version)
                */
                void draw();

            private:
                ::Vector2 _position;
                ::Color _color;
        };
    }
}

#endif /* !PIXEL_HPP_ */
