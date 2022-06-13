/**
 * @file BoundingBox.hpp
 * @author Simon Le Fourn (simon.le-fourn@epitech.eu)
 * @brief Bounding Box encapsulation header file
 * @version 0.1
 * @date 2022-05-26
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef BOUNDINGBOX_HPP_
#define BOUNDINGBOX_HPP_

#include "../Raylib.hpp"

namespace indie
{
    namespace raylib
    {
        /// Bounding box class encapsulation
        class BoundingBox {
          public:
            BoundingBox(::Vector3 min, ::Vector3 max, ::Color color = BLACK);
            ~BoundingBox() = default;

            /**
             * @brief Get boundingBox
             */
            ::BoundingBox getBoundingBox() const;

            /**
             * @brief Set boundingBox
             */
            void setBoundingBox(::Vector3 min, ::Vector3 max);

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
            static void draw(::Vector3 min, ::Vector3 max, ::Color color);
            static void draw(::BoundingBox boundingBox, ::Color color);

            /**
             * @brief Check collision between this box and another bounding box
             */
            bool checkCollisionBoxes(::BoundingBox box2);
            static bool checkCollisionBoxes(::BoundingBox box1, ::BoundingBox box2);

            /**
             * @brief Check collision between box and sphere
             */
            bool checkCollisionBoxSphere(::Vector3 center, float radius);
            static bool checkCollisionBoxSphere(::BoundingBox box, ::Vector3 center, float radius);

          private:
            ::BoundingBox _boundingBox;
            ::Color _color;
        };
    } // namespace raylib
} // namespace indie

#endif /* !BOUNDINGBOX_HPP_ */
