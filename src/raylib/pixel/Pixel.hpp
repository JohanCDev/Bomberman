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
                * @brief Draw pixel
                */
                void draw();

            private:
                ::Vector2 _position;
                ::Color _color;
        };
    }
}

#endif /* !PIXEL_HPP_ */
