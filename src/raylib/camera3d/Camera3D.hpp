/**
 * @file Camera3D.hpp
 * @author Simon Le Fourn (simon.le-fourn@epitech.eu)
 * @brief Camera3d encapsulation header file
 * @version 0.1
 * @date 2022-05-24
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef CAMERA3D_HPP_
#define CAMERA3D_HPP_

#include "../Raylib.hpp"

namespace indie
{
    namespace raylib
    {
        /// @brief Camera3D class encapsulation
        class Camera3D {
          public:
            /**
             * Create a new Camera3D.
             *
             * @param position Camera position
             * @param target Camera target it looks-at
             * @param up Camera up vector (rotation over its axis)
             * @param fovy Camera field-of-view apperture in Y (degrees) in perspective, used as near plane width in orthographic
             * @param projection Camera projection: CAMERA_PERSPECTIVE or CAMERA_ORTHOGRAPHIC
             */
            Camera3D(::Vector3 position, ::Vector3 target, ::Vector3 up, float fovy, int projection);
            /**
             * @brief Destroy the Camera 3 D object
             * 
             */
            ~Camera3D() = default;
            /**
             * @brief Set the Camera position
             * 
             * @param newX X value for pos
             * @param newY Y value for pos
             * @param newZ Z value for pos
             */
            void setPosition(float newX, float newY, float newZ);

            /**
             * @brief Get the Position object
             * 
             * @return Vector3 Camera position
             */
            ::Vector3 getPosition() const;

            /**
             * @brief Set the Camera target
             * 
             * @param newX X value for target
             * @param newY Y value for target
             * @param newZ Z value for target
             */
            void setTarget(float newX, float newY, float newZ);

            /**
             * @brief Get the Target object
             * 
             * @return Vector3 The Camera target
             */
            ::Vector3 getTarget() const;

            /**
             * @brief Set the Camera UP
             * 
             * @param newX X value for up
             * @param newY Y value for up
             * @param newZ Z value for up
             */
            void setUp(float newX, float newY, float newZ);

            /**
             * @brief Get the Camera Up
             * 
             * @return Vector3 The Camera Up
             */
            ::Vector3 getUp() const;

            /**
             * @brief Set the Camera Fovy
             * 
             * @param newFovy Fovy value
             */
            void setFovy(float newFovy);

            /**
             * @brief Get the Camera fovy
             * 
             * @return float Camera fovy value
             */
            float getFovy() const;

            /**
             * @brief Set the Camera Projection
             * 
             * @param newProjection Camera projection
             */
            void setProjection(int newProjection);
            /**
             * @brief Get camera projection
             * 
             * @return int The Camera projection
             */
            int getProjection() const;

            /**
             * @brief Initializes 3D mode with custom camera (3D)
             */
            void beginMode();

            /**
             * @brief Set camera mode (multiple camera modes available)
             * 
             * @param mode The Camera mode
             */
            void setMode(int mode);

            /**
             * @brief Ends 3D mode and returns to default 2D orthographic mode
             */
            void endMode();

            /**
             * @brief Update camera position for selected mode
             */
            void update();

          private:
            /**
             * @brief The 3D Camera object
             * 
             */
            ::Camera3D _camera;
        };
    } // namespace raylib
} // namespace indie

#endif /* !CAMERA3D_HPP_ */
