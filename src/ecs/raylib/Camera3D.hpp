/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** Camera3D
*/

#ifndef CAMERA3D_HPP_
#define CAMERA3D_HPP_

#include "Raylib.hpp"

namespace Raylib {
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
            ~Camera3D() = default;

            /**
            * @brief Set camera position
            */
            void setPosition(float newX, float newY, float newZ);

            /**
            * @brief Get camera position
            */
            ::Vector3 getPosition() const;

            /**
            * @brief Set camera target
            */
            void setTarget(float newX, float newY, float newZ);

            /**
            * @brief Get camera target
            */
            ::Vector3 getTarget() const;

            /**
            * @brief Set camera up
            */
            void setUp(float newX, float newY, float newZ);

            /**
            * @brief Get camera up
            */
            ::Vector3 getUp() const;

            /**
            * @brief Set camera fovy
            */
            void setFovy(float newFovy);

            /**
            * @brief Get camera fovy
            */
            float getFovy() const;

            /**
            * @brief Set camera projection
            */
            void setProjection(int newProjection);

            /**
            * @brief Get camera projection
            */
            int getProjection() const;

            /**
            * @brief Initializes 3D mode with custom camera (3D)
            */
            void beginMode();

            /**
            * @brief Set camera mode (multiple camera modes available)
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
            ::Camera3D _camera;
    };
}

#endif /* !CAMERA3D_HPP_ */
