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
        /// @brief Bounding box class encapsulation
        class BoundingBox {
          public:
            /**
             * @brief Construct a new Bounding Box object
             * 
             * @param min The min value for the object
             * @param max The max value for the object
             * @param color The color for the object
             */
            BoundingBox(::Vector3 min, ::Vector3 max, ::Color color = BLACK);
            /**
             * @brief Destroy the Bounding Box object
             * 
             */
            ~BoundingBox() = default;

            /**
             * @brief Get boundingBox
             * 
             * @return BoundingBox The BoundingBox object
             */
            ::BoundingBox getBoundingBox() const;
            /**
             * @brief Set boundingBox
             * 
             * @param min Min value
             * @param max Max value
             */
            void setBoundingBox(::Vector3 min, ::Vector3 max);
            /**
             * @brief Get box color
             * 
             * @return Color BoundingBox color
             */
            ::Color getColor() const;
            /**
             * @brief Set box color
             * 
             * @param color BoundingBox color
             */
            void setColor(::Color color);
            /**
             * @brief Draw bounding box
             */
            void draw();
            /**
             * @brief Draw Bounding Box 
             * 
             * @param color The color for the bounding box
             */
            void draw(Color color);
            /**
             * @brief Draw Bounding Box
             * 
             * @param min The min value for the Bounding Box
             * @param max The max value for the bounding Box
             * @param color The color for the Bounding Box
             */
            static void draw(::Vector3 min, ::Vector3 max, ::Color color);
            /**
             * @brief Draw Bounding Box
             * 
             * @param boundingBox The Object
             * @param color The color for the Bounding Box
             */
            static void draw(::BoundingBox boundingBox, ::Color color);
            /**
             * @brief Check collision on the box
             * 
             * @param box2 BoundingBox object
             * 
             * @return true There is a collision with the box
             * @return false There isn't a collision with the box
             */
            bool checkCollisionBoxes(::BoundingBox box2);
            /**
             * @brief Check collision between this box and another bounding box
             * 
             * @param box1 BoundingBox object
             * @param box2 BoundingBox object
             * 
             * @return true There is a collision with the box
             * @return false There isn't a collision with the box
             */
            static bool checkCollisionBoxes(::BoundingBox box1, ::BoundingBox box2);

            /**
             * @brief Check collision between box and sphere
             * 
             * @param center The center of the sphere
             * @param radius The radius of the sphere
             * 
             * @return true There is a collision with the box
             * @return false There isn't a collision with the box
             */
            bool checkCollisionBoxSphere(::Vector3 center, float radius);
            /**
             * @brief Check collision between box and sphere
             * 
             * @param box BoundingBox object
             * @param center The center of the sphere
             * @param radius The radius of the sphere
             * 
             * @return true There is a collision with the box
             * @return false There isn't a collision with the box
             */
            static bool checkCollisionBoxSphere(::BoundingBox box, ::Vector3 center, float radius);

            /**
            * @brief Compute model bounding box limits (considers all meshes)
            * 
            * @param model Model object
            * 
            * @return BoundingBox BoundingBox object
            */
            static ::BoundingBox getModelBox(::Model model);

            private:
                /**
                 * @brief The box object
                 * 
                 */
                ::BoundingBox _boundingBox;
                /**
                 * @brief The color object
                 * 
                 */
                ::Color _color;
        };
    } // namespace raylib
} // namespace indie

#endif /* !BOUNDINGBOX_HPP_ */
