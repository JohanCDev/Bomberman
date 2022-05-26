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
                BoundingBox(::Vector3 min, ::Vector3 max, ::Color color = BLACK);
                ~BoundingBox() = default;

                /**
                * @brief Get box color
                */
                ::Color getColor() const;

                /**
                * @brief Set box color
                */
                void setColor(::Color color);

                /**
                * @brief Draw bounding box (wires)
                */
                void draw();
                void draw(Color color);

                /**
                * @brief Check collision between this box and another bounding box
                */
                bool checkCollisionBoxes(::BoundingBox box2);

                // /**
                // * @brief Check collision between this box and a sphere
                // */
                // bool checkCollisionBoxSphere(Vector3 center, float radius);

            private:
                ::BoundingBox _boundingBox;
                ::Color _color;
        };
    }
}

#endif /* !BOUNDINGBOX_HPP_ */
