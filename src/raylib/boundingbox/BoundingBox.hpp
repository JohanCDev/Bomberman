/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** BoundingBox
*/

#ifndef BOUNDINGBOX_HPP_
#define BOUNDINGBOX_HPP_

#include "../Raylib.hpp"

namespace indie {
    namespace raylib {
        class BoundingBox {
            public:
                /**
                * @brief Draw bounding box (wires)
                */
                static void draw(::Vector3 min, ::Vector3 max, ::Color color);
                static void draw(::BoundingBox boundingBox, ::Color color);

                /**
                * @brief Check collision between this box and another bounding box
                */
                static bool checkCollisionBoxes(::BoundingBox box1, ::BoundingBox box2);
        };
    }
}

#endif /* !BOUNDINGBOX_HPP_ */
